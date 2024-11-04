#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <string>
#include <sstream>
#include <math.h>
#include <fstream>

#include <unordered_map>
#include <unordered_set>


using namespace std;

void read_input(vector<int>& a, vector<int>& query_left, vector<int>& query_right) {
    int n, m; scanf("%d %d\n", &n, &m);
    a.resize(n);
    query_left.resize(m);
    query_right.resize(m);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &query_left[i], &query_right[i]);
    }
}

class VitSolver {
public:

    static const int INF = 1e9 + 5;

    class SegmentTree {

        vector<int> t;
        int fake_sz;

        int get_min(int at, int left, int right, int need_left, int need_right) const {

            if (need_right < left || need_left > right) {
                return INF;
            }

            if (need_left <= left && right <= need_right) {
                return t[at];
            }

            int m = (left + right) / 2;

            return min(get_min(2 * at, left, m, need_left, need_right),
                get_min(2 * at + 1, m + 1, right, need_left, need_right));
        }

    public:
        SegmentTree(const vector<int>& a) {
            int real_sz = a.size();
            for (int i = 0;; ++i) {
                if ((1 << i) >= real_sz) {
                    fake_sz = (1 << i);
                    break;
                }
            }

            t.resize(2 * fake_sz);

            for (int i = fake_sz; i < 2 * fake_sz; ++i) {
                if (i - fake_sz < a.size()) {
                    t[i] = a[i - fake_sz];
                }
                else {
                    t[i] = INF;
                }
            }

            for (int i = fake_sz - 1; i > 0; --i) {
                t[i] = min(t[2 * i], t[2 * i + 1]);
            }
        }

        int get_min(int from, int to) const {

            if (to < from) return INF;

            return get_min(1, 0, fake_sz - 1, from, to);
        }
    };

    VitSolver() {}

    struct Segment {
        int from, to;
        Segment() {}
        Segment(int from, int to) : from(from), to(to) {}

        bool operator < (const Segment& other) const {
            if (from != other.from) return from < other.from;
            return to < other.to;
        }

        int length() const {
            return to - from;
        }
    };

    vector<Segment> get_segments(const vector<int>& a) {
        vector<Segment> result;
        map<int, int> last;

        for (int i = 0; i < a.size(); ++i) {
            if (last.count(a[i])) {
                result.push_back(Segment(last[a[i]], i));
            }
            last[a[i]] = i;
        }

        return result;
    }

    struct Event {
        int at;
        bool start;
        int id;

        Event() {}
        Event(int at, bool start, int id) : at(at), start(start), id(id) {}

        bool operator < (const Event& other) const {
            if (at != other.at) return at < other.at;
            if (start != other.start) return start > other.start;
            return id < other.id;
        }
    };

    vector<Segment> remove_cover_segments(const vector<Segment>& segments) {
        vector<int> removed(segments.size(), 0);

        vector<Event> events;
        for (int i = 0; i < segments.size(); ++i) {
            events.push_back(Event(segments[i].from, true, i));
            events.push_back(Event(segments[i].to, false, i));
        }

        sort(events.begin(), events.end());

        vector<Segment> answer;

        queue< int > opened;

        for (int i = 0; i < events.size(); ++i) {
            if (events[i].start) {
                opened.push(events[i].id);
            }
            else {
                if (removed[events[i].id]) {
                    continue;
                }
                else {
                    while (opened.front() != events[i].id) {
                        removed[opened.front()] = 1;
                        opened.pop();
                    }
                    opened.pop();

                    answer.push_back(segments[events[i].id]);
                }
            }
        }

        return answer;
    }

    static bool cmp_left(const Segment& s, int v) {
        return s.from < v;
    }

    static bool cmp_right(const Segment& s, int v) {
        return s.to < v;
    }

    vector<int> solve(const vector<int>& a, const vector<int>& query_left, const vector<int>& query_right) {

        vector<Segment> segments = get_segments(a);
        segments = remove_cover_segments(segments);

        sort(segments.begin(), segments.end());

        vector<int> dist(segments.size());
        for (int i = 0; i < segments.size(); ++i) {
            dist[i] = segments[i].length();
        }

        SegmentTree tree(dist);
        int m = query_left.size();
        vector<int> answer(m);

        for (int i = 0; i < m; ++i) {
            int q_left = query_left[i] - 1;
            int q_right = query_right[i] - 1;

            int left = lower_bound(segments.begin(), segments.end(), q_left, cmp_left) - segments.begin();
            int right = lower_bound(segments.begin(), segments.end(), q_right + 1, cmp_right) - segments.begin();
            --right;

            int ans = tree.get_min(left, right);
            if (ans == INF) ans = -1;

            answer[i] = ans;
        }

        return answer;
    }
};

class DimaSolver
{
    class Segment
    {
    public:
        struct SegmentEvent
        {
            bool start;
            int index, owner;

            SegmentEvent(int owner, int index, bool start) :
                start(start),
                index(index),
                owner(owner)
            {}
            bool operator < (const SegmentEvent &se) const
            {
                if (index == se.index)
                {
                    if (start == se.start)
                    {
                        throw logic_error("The point cannot be both the start and the finish.");
                    }
                    return !start;
                }
                else
                {
                    return index < se.index;
                }
            }
        };
    private:
        int left, right;
    public:
        Segment(int left, int right) :
            left(left),
            right(right)
        {}

        int getLeft() const
        {
            return left;
        }

        int getRight() const
        {
            return right;
        }

        bool operator < (const Segment &segment) const
        {
            if (left == segment.left)
            {
                return right < segment.right;
            }
            else
            {
                return left < segment.left;
            }
        }

        int getDistance() const
        {
            return right - left;
        }
    };
    class SegmentTree
    {
        int n;
        vector<int> tree;
    public:
        SegmentTree(int n) :
            n(n)
        {
            tree.resize(4 * n + 5, INF);
        }

        void set(int index, int value)
        {
            set(1, 0, n - 1, index, value);
        }

        int getMin(int left, int right)
        {
            return getMin(1, 0, n - 1, left, right);
        }
    private:
        void set(int v, int tl, int tr, int index, int value)
        {
            if (tl == tr)
            {
                tree[v] = value;
            }
            else
            {
                int tm = (tl + tr) / 2;
                if (index <= tm)
                {
                    set(2 * v, tl, tm, index, value);
                }
                else
                {
                    set(2 * v + 1, tm + 1, tr, index, value);
                }
                tree[v] = min(tree[2 * v], tree[2 * v + 1]);
            }
        }

        int getMin(int v, int tl, int tr, int left, int right)
        {
            if (left > right)
            {
                return INF;
            }

            if (left == tl && right == tr)
            {
                return tree[v];
            }

            int tm = (tl + tr) / 2;
            return min(getMin(2 * v, tl, tm, left, min(right, tm)),
                getMin(2 * v + 1, tm + 1, tr, max(left, tm + 1), right)
                );
        }
    };

    static const int INF;
public:
    vector<int> solve(const vector<int>& a, const vector<int>& query_left, const vector<int>& query_right)
    {
        vector<Segment> segments = parseSegments(a);

        sort(segments.begin(), segments.end());

        segments = dropCoverSegments(segments);

        SegmentTree segmentTree(segments.size());
        for (size_t i = 0; i < segments.size(); ++i)
        {
            segmentTree.set(i, segments[i].getDistance());
        }

        


        vector<int> ans;
        for (size_t query = 0; query < query_left.size(); ++query)
        {
            auto left_border = lower_bound(segments.begin(), segments.end(), query_left[query] - 1,
                [](const Segment &segment, int left)
            {
                return segment.getLeft() < left;
            });

            auto right_border = lower_bound(segments.begin(), segments.end(), query_right[query],
                [](const Segment &segment, int right)
            {
                return segment.getRight() < right;
            });

            int left_index = left_border - segments.begin(),
                right_index = right_border - segments.begin() - 1;

            if (left_index > right_index)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(segmentTree.getMin(left_index, right_index));
            }
        }
        return ans;
    }

    static vector<Segment> parseSegments(const vector<int> &a)
    {
        vector<Segment> segments;
        unordered_map<int, int> lastIndex;
        for (size_t i = 0; i < a.size(); ++i)
        {
            if (lastIndex.find(a[i]) != lastIndex.end())
            {
                segments.push_back(Segment(lastIndex[a[i]], i));
            }
            lastIndex[a[i]] = i;
        }
        return segments;
    }

    static vector<Segment> dropCoverSegments(const vector<Segment> &segments)
    {
        vector<Segment::SegmentEvent> events;
        for (size_t i = 0; i < segments.size(); ++i)
        {
            events.push_back(Segment::SegmentEvent(i, segments[i].getLeft(), true));
            events.push_back(Segment::SegmentEvent(i, segments[i].getRight(), false));
        }

        sort(events.begin(), events.end());

        queue<int> scanLine;
        unordered_set<int> currentSegments;
        vector<Segment> dropped;
        for (const Segment::SegmentEvent &event : events)
        {
            if (event.start)
            {
                scanLine.push(event.owner);
                currentSegments.insert(event.owner);
            }
            else
            {
                if (currentSegments.find(event.owner) == currentSegments.end())
                {
                    continue;
                }

                while (scanLine.front() != event.owner)
                {
                    currentSegments.erase(scanLine.front());
                    scanLine.pop();                    
                }
                scanLine.pop();
                currentSegments.erase(event.owner);
                dropped.push_back(segments[event.owner]);
            }
        }
        return dropped;
    }
};
const int DimaSolver::INF = 10000007;

vector<int> brute_solve(const vector<int>& a, const vector<int>& query_left, const vector<int>& query_right) {
    vector<int> answer(query_left.size());
    for (int i = 0; i < query_left.size(); ++i) {

        int ans = 1e9;
        map<int, int> last;

        for (int j = query_left[i] - 1; j <= query_right[i] - 1; ++j) {
            if (last.count(a[j])) {
                ans = min(ans, j - last[a[j]]);
            }
            last[a[j]] = j;
        }

        if (ans == 1e9) {
            ans = -1;
        }
        answer[i] = ans;
    }

    return answer;
}

long long rand(long long from, long long to) {
    long long r = 0;
    for (int i = 0; i < 4; ++i) {
        r += static_cast<long long>(rand()) << (64 / 4 * i);
    }

    long long mod = (to - from + 1);
    r %= mod;
    if (r < 0) r += mod;

    return from + r;
}


void generate_random_test(int n, int m, vector<int>& a, vector<int>& l, vector<int>& r,
    int min_a = -1e9, int max_a = 1e9,
    int min_l = 1, int max_l = -1,
    int min_r = 1, int max_r = -1) {
    if (max_l == -1) {
        max_l = n;
    }
    if (max_r == -1) {
        max_r = n;
    }

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i] = rand(min_a, max_a);
    }

    l.resize(m);
    r.resize(m);

    for (int i = 0; i < m; ++i) {
        int left = rand(min_l, max_l);
        int right = rand(max(left, min_r), max_r);

        l[i] = left;
        r[i] = right;
    }
}

const double TL = 2.0;

void save_test(const vector<int>& a, const vector<int>& l, const vector<int>& r) {
    ofstream out("test.txt");
    out << a.size() << " " << l.size() << endl;
    for (int i = 0; i < a.size(); ++i) {
        out << a[i] << " ";
    }
    out << endl;
    for (int i = 0; i < l.size(); ++i) {
        out << l[i] << " " << r[i] << endl;
    }
    out.close();
}

double max_vit_time;
double max_dima_time;

void run_test(const vector<int>& a, const vector<int>& l, const vector<int>& r, bool bruteforce) {
    vector<int> vit_answer, dima_answer;

    int start_time = clock();
    VitSolver vitSolver;
    vit_answer = vitSolver.solve(a, l, r);
    double vit_time = static_cast<double>(clock() - start_time) / CLOCKS_PER_SEC;

    start_time = clock();
    DimaSolver dimaSolver;
    dima_answer = dimaSolver.solve(a, l, r);
    double dima_time = static_cast<double>(clock() - start_time) / CLOCKS_PER_SEC;

    if (vit_time > TL) {
        cout << "TL vitSolver" << endl;
        save_test(a, l, r);
        exit(1);
    }

    if (vit_time > max_vit_time) {
        max_vit_time = vit_time;
    }

    if (dima_time > TL) {
        cout << "TL DimaSolver" << endl;
        save_test(a, l, r);
        exit(1);
    }

    if (dima_time > max_dima_time) {
        max_dima_time = dima_time;
    }

    if (dima_answer != vit_answer) {
        cout << "WA dimaSolver disagrees with vitSolver" << endl;
        save_test(a, l, r);
        exit(1);
    }

    if (bruteforce) {
        vector<int> brute_answer = brute_solve(a, l, r);

        if (brute_answer != vit_answer) {
            cout << "WA vitSolver disagrees with bruteforce" << endl;
            save_test(a, l, r);
            exit(1);
        }

        if (brute_answer != dima_answer) {
            cout << "WA dimaSolver disagrees with bruteforce " << endl;
            save_test(a, l, r);
            exit(1);
        }


    }
}

void run_tests() {
    srand(123);
    vector<int> a, l, r;


    cerr << "Very small sparse tests (bruteforce)" << endl;
    for (int i = 0; i < 10000; ++i) {
        generate_random_test(rand(1, 10), 100, a, l, r);
        run_test(a, l, r, true);
    }

    cerr << "Very small dense tests (bruteforce)" << endl;
    for (int i = 0; i < 10000; ++i) {
        generate_random_test(rand(1, 10), 100, a, l, r, 0, 3);
        run_test(a, l, r, true);
    }

    cerr << "Small sparse tests (bruteforce)" << endl;
    for (int i = 0; i < 10000; ++i) {
        generate_random_test(rand(11, 100), 100, a, l, r);
        run_test(a, l, r, true);
    }

    cerr << "Small dense tests (bruteforce)" << endl;
    for (int i = 0; i < 10000; ++i) {
        generate_random_test(rand(11, 100), 100, a, l, r, 0, 3);
        run_test(a, l, r, true);
    }

    cerr << "Huge sparse tests" << endl;
    for (int i = 0; i < 30; ++i) {
        generate_random_test(5e5, 5e5, a, l, r);
        run_test(a, l, r, false);
        cerr << i << "\r";
    }


    cerr << "Huge dense tests" << endl;
    for (int i = 0; i < 30; ++i) {
        generate_random_test(5e5, 5e5, a, l, r, 0, 3);
        run_test(a, l, r, false);
        cerr << i << "\r";
    }

    cerr << "Huge extremly dense tests" << endl;
    for (int i = 0; i < 30; ++i) {
        generate_random_test(5e5, 5e5, a, l, r, 0, 0);
        run_test(a, l, r, false);
        cerr << i << "\r";
    }

    cerr << "Huge dense test (wide queries)" << endl;
    for (int i = 0; i < 2; ++i) {
        generate_random_test(5e5, 5e5, a, l, r, 0, 3, 1, 100, 500000 - 100, 5e5);
        run_test(a, l, r, false);
        cerr << i << "\r";
    }

    cerr << "Huge extremly dense test (wide queries)" << endl;
    for (int i = 0; i < 2; ++i) {
        generate_random_test(5e5, 5e5, a, l, r, 0, 0, 1, 100, 500000 - 100, 5e5);
        run_test(a, l, r, false);
        cerr << i << "\r";
    }


    cerr << "Random (n * m < 1e6 -> bruteforce)" << endl;
    long long n, m;
    for (int i = 0;; ++i) {
        n = rand(1, 5e5);
        m = rand(1, min(10 * n * n, (long long)5e5));

        generate_random_test(n, m, a, l, r);
        run_test(a, l, r, n * m < 1e6);


        n = rand(1, 5e5);
        m = rand(1, min(10 * n * n, (long long)5e5));

        generate_random_test(n, m, a, l, r, 0, rand(0, 10));
        run_test(a, l, r, n * m < 1e6);

        n = rand(1, 5e5);
        m = rand(1, min(10 * n * n, (long long)5e5));

        generate_random_test(n, m, a, l, r, 0, rand(0, 100));
        run_test(a, l, r, n * m < 1e6);


        n = rand(1, 5e5);
        m = rand(1, min(10 * n * n, (long long)5e5));

        generate_random_test(n, m, a, l, r, 0, rand(0, 100), 1, rand(1, min(100ll, n)));
        run_test(a, l, r, n * m < 1e6);

        cerr << i * 4 << "\r";
    }
}

int main(int argc, char* argv[])
{
    

    


    std::ios_base::sync_with_stdio(0);

    


    vector<int> a, l, r;
    read_input(a, l, r);

    

    DimaSolver solver;
    vector<int> answer = solver.solve(a, l, r);

    for (int ans : answer)
    {
        cout << ans << "\n";
    }
    
    

    

    

    

    

    

    

    


    return 0;
}

