










using namespace std;

struct SingleNode {
    string key;
    SingleNode* prev;
    SingleNode* next;
    SingleNode(string key): key(key), prev(NULL), next(NULL) {}
};

struct BatchNode {
    int cnt;
    SingleNode* head;
    SingleNode* tail;
    BatchNode* prev;
    BatchNode* next;
    unordered_map<string, SingleNode*> mp;
    BatchNode(int cnt): cnt(cnt), head(NULL), tail(NULL), prev(NULL), next(NULL) {}
};

struct QuickNode {
    BatchNode* head;
    BatchNode* tail;
    unordered_map<string, BatchNode*> mp;
    QuickNode(): head(NULL), tail(NULL) {}
};


class AllOne {
public:
    
    QuickNode* qn;
    AllOne() {
        qn = new QuickNode();
    }

    SingleNode* findSingleNode(BatchNode* bn, string key) {
        if (bn->mp.find(key) == bn->mp.end()) return NULL;
        return bn->mp[key];
    }

    BatchNode* findBatchNode(QuickNode* qn, string key) {
        if (qn->mp.find(key) == qn->mp.end()) return NULL;
        return qn->mp[key];
    }

    BatchNode* popBatchNode(QuickNode* qn, string key) {
        if (qn->mp.find(key) == qn->mp.end()) return NULL;
        BatchNode* bn = qn->mp[key];
        BatchNode* bnPrev = bn->prev;
        BatchNode* bnNext = bn->next;
        bn->prev = NULL;
        bn->next = NULL;
        if (bnPrev != NULL) bnPrev->next = bnNext;
        if (bnNext != NULL) bnNext->prev = bnPrev;
        if (bnPrev == NULL) qn->head = bnNext;
        if (bnNext == NULL) qn->tail = bnPrev;
        return bn;
    }

    void removeBatchNode(QuickNode* qn, BatchNode* bn) {
        BatchNode* bnPrev = bn->prev;
        BatchNode* bnNext = bn->next;
        bn->prev = NULL;
        bn->next = NULL;
        if (bnPrev != NULL) bnPrev->next = bnNext;
        if (bnNext != NULL) bnNext->prev = bnPrev;
        if (bnPrev == NULL) qn->head = bnNext;
        if (bnNext == NULL) qn->tail = bnPrev;
    }

    SingleNode* popSingleNode(BatchNode* bn, string key) {
        if (bn->mp.find(key) == bn->mp.end()) return NULL;
        SingleNode* sn = bn->mp[key];
        SingleNode* snPrev = sn->prev;
        SingleNode* snNext = sn->next;
        sn->next = sn->prev = NULL;
        if (snPrev != NULL) snPrev->next = snNext;
        if (snNext != NULL) snNext->prev = snPrev;
        if (snPrev == NULL) bn->head = snNext;
        if (snNext == NULL) bn->tail = snPrev;
        bn->mp.erase(key);
        return sn;
    }

    void pushSingleNode(BatchNode* bn, SingleNode* sn) {
        if (bn == NULL || sn == NULL) return;
        if (bn->head == NULL && bn->tail == NULL) {
            bn->head = bn->tail = sn;
            sn->prev = NULL;
            sn->next = NULL;
        } else {
            bn->tail->next = sn;
            sn->prev = bn->tail;
            sn->next = NULL;
            bn->tail = sn;
        }
        bn->mp[sn->key] = sn;
    }

    void syncKeyToQuickNode(QuickNode* qn, BatchNode* bn) {
        for (unordered_map<string, SingleNode*>::iterator it = bn->mp.begin(); it != bn->mp.end(); it++) {
            qn->mp[it->first] = bn;
        }
    }

    void pushAboveBatchNode(QuickNode* qn, BatchNode* ground, BatchNode* bn) {
        if (qn->head == ground) {
            bn->prev = NULL;
            bn->next = ground;
            ground->prev = bn;
            qn->head = bn;
        } else {
            BatchNode* groundPrev = ground->prev;
            groundPrev->next = bn;
            bn->prev = groundPrev;
            bn->next = ground;
            ground->prev = bn;
        }
        syncKeyToQuickNode(qn, bn);
    }

    void pushBelowBatchNode(QuickNode* qn, BatchNode* ground, BatchNode* bn) {
        if (qn->tail == ground) {
            ground->next = bn;
            bn->prev = ground;
            bn->next = NULL;
            qn->tail = bn;
        } else {
            BatchNode* groundNext = ground->next;
            ground->next = bn;
            bn->prev = ground;
            bn->next = groundNext;
            groundNext->prev = bn;
        }
        syncKeyToQuickNode(qn, bn);
    }
    
    void pushTailBatchNode(QuickNode* qn, BatchNode* bn) {
        if (qn->tail == NULL && qn->head == NULL) {
            qn->head = qn->tail = bn;
            bn->prev = NULL;
            bn->next = NULL;
        } else {
            qn->tail->next = bn;
            bn->prev = qn->tail;
            bn->next = NULL;
            qn->tail = bn;
        }
        syncKeyToQuickNode(qn, bn);
    }

    void print(BatchNode* bn) {
        cout << "   ** bn ** (cnt:" << bn->cnt << ")" << endl;
        cout << "   [bn->mp]" << endl;
        cout << "   ";
        for (unordered_map<string, SingleNode*>::iterator it = bn->mp.begin(); it != bn->mp.end(); it++) {
            cout << it->first << " ";
        }
        cout << endl;
        cout << "   [bn->head to tail]" << endl;
        cout << "   ";
        for (SingleNode* sn = bn->head; sn != NULL; sn = sn->next) {
            cout << sn->key << " -> ";
        }
        cout << endl;
    }

    void print() {
        cout << "********* qn *********" << endl;
        cout << "[qn->mp]" << endl;
        for (unordered_map<string, BatchNode*>::iterator it = qn->mp.begin(); it != qn->mp.end(); it++) {
            cout << "" << it->first << ":" << it->second->cnt << endl;
        }
        cout << "[qn->head to tail]" << endl;
        for (BatchNode* bn = qn->head; bn != NULL; bn = bn->next) {
            print(bn);
        }
        cout << "********* end *********" << endl;
    }

    
    void inc(string key) {
        if (qn->mp.find(key) == qn->mp.end()) {
            BatchNode *bn = NULL;
            SingleNode* sn = new SingleNode(key);
            if (qn->tail != NULL && qn->tail->cnt == 1) {
                bn = qn->tail;
                pushSingleNode(bn, sn);
                syncKeyToQuickNode(qn, bn);
            } else {
                bn = new BatchNode(1);
                pushSingleNode(bn, sn);
                pushTailBatchNode(qn, bn);
            }
        } else {
            BatchNode* bn = findBatchNode(qn, key);
            SingleNode* sn = popSingleNode(bn, key);
            if (bn->prev != NULL && bn->prev->cnt == bn->cnt + 1) {
                pushSingleNode(bn->prev, sn);
                syncKeyToQuickNode(qn, bn->prev);
            } else {
                BatchNode* plusOneBn = new BatchNode(bn->cnt + 1);
                pushSingleNode(plusOneBn, sn);
                pushAboveBatchNode(qn, bn, plusOneBn);
            }
            if (bn->mp.size() == 0) removeBatchNode(qn, bn);
        }
    }
    
    
    
    void dec(string key) {
        if (qn->mp.find(key) == qn->mp.end()) return;
        BatchNode* bn = findBatchNode(qn, key);
        SingleNode* sn = popSingleNode(bn, key);
        if (bn->next != NULL && bn->next->cnt == bn->cnt - 1) {
            pushSingleNode(bn->next, sn);
            syncKeyToQuickNode(qn, bn->next);
        } else if (bn->cnt - 1 > 0) {
            BatchNode* minusOneBn = new BatchNode(bn->cnt - 1);
            pushSingleNode(minusOneBn, sn);
            pushBelowBatchNode(qn, bn, minusOneBn);
        } else {
            qn->mp.erase(key);
        }
        if (bn->mp.size() == 0) removeBatchNode(qn, bn);
    }
    
    
    string getMaxKey() {
        if (qn->head != NULL) return qn->head->head->key;
        return "";
    }
    
    
    string getMinKey() {
        if (qn->tail != NULL) return qn->tail->tail->key;
        return "";
    }

};


class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

struct id27 {
    int v;
    int num;
    id27 *left;
    id27 *right;
    id27 (int v): v(v), num(0), left(NULL), right(NULL) {}
};


static bool myCompare(const vector<int> &v1, const vector<int> &v2) {
    if (v1[0] == v2[0]) return v1[1] > v2[1];
    return v1[0] <= v2[0];
}

struct id17 {
    int height;
    int x;
    int y;
    id17(int h, int x, int y): height(h), x(x), y(y) {}
};

struct TwoDNodeSort {
    bool operator() (const id17 &t1, const id17 &t2) {
        return t1.height > t2.height;
    }
};

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        vector<bool> led(10, false);
        fillAndEvaluate(led, num, 0, ret);
        return ret;
    }

    void print(vector<string> v) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << "->";
        }
        cout << endl;
    }

    void print(vector<int> v) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << "->";
        }
        cout << endl;
    }

    void fillAndEvaluate(vector<bool> &led, int id28, int startIndex, vector<string> &ret) {
        if (id28 == 0) {
            

            int h = 0; int m = 0;
            for (int i = 0; i < 6; i++) {
                m += led[i] * (1 << i);
            }
            for (int i = 6; i < led.size(); i++) {
                h += led[i] * (1 << (i-6));
            }
            if (h >= 0 && h < 24 && m >= 0 && m < 60) {
                ret.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
            }
        } else {
            for (int i = startIndex; i <= led.size() - id28; i++) {
                led[i] = true;
                fillAndEvaluate(led, id28-1, i+1, ret);
                led[i] = false;
            }
        }
    }

    void removeTrailingZero(string &ret) {
        int zeroIdx = 0;
        while (zeroIdx < ret.size() && ret[zeroIdx] == '0') zeroIdx++;
        ret.erase(0, zeroIdx);
    }

    void print(vector<bool> v) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    void print(set<int> s) {
        for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k >= n) return "0";
        string ret = num;
        while (k > 0) {
            removeTrailingZero(ret);

            int startIdx = 0;
            while (startIdx + 1 <= ret.size() - 1 && ret[startIdx] <= ret[startIdx+1]) startIdx++;
            ret.erase(startIdx, 1);
            k--;
            cout << "
        }
        removeTrailingZero(ret);
        return ret == "" ? "0" : ret;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (n < 1) return true;

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) mp[stones[i]] = i;

        vector<set<long> > dp(n, set<long>());
        dp[0].insert(0);
        for (int i = 0; i < n; i++) {
            for (set<long>::iterator it = dp[i].begin(); it != dp[i].end(); it++) {
                for (long step = *it - 1; step <= *it + 1; step++) {
                    if (mp.find(stones[i] + step) != mp.end()) dp[mp[stones[i]+step]].insert(step);
                }
            }
        }
        return dp[n-1].size() > 0;
    }

    void print(vector<vector<int> > v) {
        for (int i = 0; i < v.size(); i++) print(v[i]);
    }
    
    vector<vector<int> > id29(vector<vector<int> >& people) {
        sort(people.begin(), people.end(), myCompare);
        int n = people.size();
        vector<vector<int> > ret(n);
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int idx = 0; idx < n; idx++) {
                if (ret[idx].size() == 0) {
                    cnt++;
                    if (cnt == people[i][1] + 1) {
                        ret[idx] = people[i];
                        break;
                    }
                }
            }
        }
        print (ret);
        return ret;
    }

    int id19(vector<vector<int> >& heightMap) {
        priority_queue<id17, vector<id17>, TwoDNodeSort> pq;
        int n = heightMap.size();
        if (n <= 0) return 0;
        int m = heightMap[0].size();
        vector<vector<bool> > flag(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                    if (!flag[i][j]) {
                        flag[i][j] = true;
                        pq.push(id17(heightMap[i][j], i, j));
                    }
                }
            }
        }
        int minH = 0;
        int ans = 0;
        int dir[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        while (pq.size() > 0) {
            id17 t = pq.top();
            pq.pop();
            if (t.height < minH) ans += minH - t.height;
            else minH = t.height;

            


            for (int i = 0; i < 4; i++) {
                int nextX = t.x + dir[i][0];
                int nextY = t.y + dir[i][1];
                if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && !flag[nextX][nextY]) {
                    flag[nextX][nextY] = true;
                    pq.push(id17(heightMap[nextX][nextY], nextX, nextY));
                }
            }
        }
        return ans;
    }

    void print(vector<char> v) {
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;
    }
    
    int id23(string s) {
        int n = s.size();
        vector<char> id16(2*n+1, '
        vector<int> p(2*n+1, 0);
        int maxReach = 0;
        int maxIdx = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            id16[2*i+1] = s[i];
        } 
        print (id16);
        
        for (int i = 1; i < 2*n+1; i++) {
            if (maxReach > i) {
                if (i + p[2*maxIdx-i] > maxReach) p[i] = maxReach - i;
                else p[i] = p[2*maxIdx-i];
            }
            while (i+p[i]+1 < 2*n+1 && i-p[i]-1 >= 0 && id16[i+p[i]+1] == id16[i-p[i]-1]) p[i]++;
            if (i + p[i] > maxReach) {
                maxReach = i + p[i];
                maxIdx = i;
            }
            cout << "i:" << i << " p[i]:" << p[i] << endl;
            ans = max(ans, p[i]);
        }
        return ans;
    }

    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int>(m+1, -1));
        for (int j = 0; j <= m; j++) {
            for (int i = 0; i < n; i++) {
                

                if (j == 0) {
                    if (i == 0) dp[i][j] = nums[i];
                    else dp[i][j] = dp[i-1][j] + nums[i];
                    continue;
                }

                int s = 0;
                for (int k = 1; k <= i; k++) {
                    if (i-k+1 < 0 || i-k < 0 || j-1 < 0 || j-1 > i-k) continue;

                    s += nums[i-k+1];
                    if (dp[i-k][j-1] != -1) {
                        if (dp[i][j] == -1) dp[i][j] = max(dp[i-k][j-1], s);
                        else dp[i][j] = min(dp[i][j], max(dp[i-k][j-1], s));
                    }
                }
            }
        }
        print(dp);
        return dp[n-1][m-1];
    }

    vector<string> id15(int n) {
        vector<string> ret;
        for (int i = 0; i < n; i++) {
            if (i % 3 == 0 && i % 5 == 0) ret.push_back("FizzBuzz");
            else if (i % 3 == 0) ret.push_back("Fizz");
            else if (i % 5 == 0) ret.push_back("Buzz");
            else {
                ret.push_back(to_string(i));
            }
        }
        return ret;
    }

    int id0(vector<int>& A) {
        int n = A.size();
        int prevDelta = 0;
        long cnt = 0;
        long ans = 0;
        for (int i = 1; i < n; i++) {
            if (i == 1 || A[i]-A[i-1] != prevDelta) {
                if (cnt >= 2) {
                    ans += cnt * (cnt-1) / 2;
                }
                prevDelta = A[i] - A[i-1];
                cnt = 1;
            } else {
                cnt++;
            }
            

        }
        if (cnt >= 2) ans += cnt * (cnt-1) / 2;
        return ans;
    }
    int thirdMax(vector<int>& nums) {
        priority_queue<long> pq;
        set<long> s;
        for (int i = 0; i < nums.size(); i++) {
            long t = nums[i];
            if ((pq.size() < 3 || nums[i] > -pq.top()) && s.find(-t) == s.end()) {
                pq.push(-t);
                s.insert(-t);
                cout << "i:" << i << " top:" << -pq.top() << " size:" << pq.size() << endl;
            }
            while (pq.size() > 3) {
                s.erase(-pq.top());
                pq.pop();
            }
        }
        if (pq.size() == 1) {
            return -pq.top();
        } else if (pq.size() == 2) {
            pq.pop();
            return -pq.top();
        } else {
            return -pq.top();
        }
    }
    vector<vector<int> > id2(vector<vector<int> >& matrix) {
        int n = matrix.size();
        vector<vector<int> > ret;
        if (n == 0) return ret;
        int m = matrix[0].size();        
        vector<vector<bool> > pacific(n, vector<bool>(m, false));
        vector<vector<bool> > atlantic(n, vector<bool>(m, false));
        queue<pair<int,int> > q1;
        queue<pair<int,int> > q2;
        for (int i = 0; i < n; i++) {
            pacific[i][0] = true;
            q1.push(make_pair(i, 0));
            atlantic[i][m-1] = true;
            q2.push(make_pair(i,m-1));
        }
        for (int i = 0; i < m; i++) {
            pacific[0][i] = true;
            q1.push(make_pair(0, i));
            atlantic[n-1][i] = true;
            q2.push(make_pair(n-1,i));
        }
        
        int dir[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        while (q1.size() > 0) {
            pair<int,int> pr = q1.front(); q1.pop();
            for (int d = 0; d < 4; d++) {
                int nextI = pr.first + dir[d][0];
                int nextJ = pr.second + dir[d][1];
                if (nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m &&
                    !pacific[nextI][nextJ] && 
                    matrix[nextI][nextJ] >= matrix[pr.first][pr.second]) {
                    q1.push(make_pair(nextI, nextJ));
                    pacific[nextI][nextJ] = true;
                }
            }
        }
        while (q2.size() > 0) {
            pair<int,int> pr = q2.front(); q2.pop();
            for (int d = 0; d < 4; d++) {
                int nextI = pr.first + dir[d][0];
                int nextJ = pr.second + dir[d][1];
                if (nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m &&
                    !atlantic[nextI][nextJ] && 
                    matrix[nextI][nextJ] >= matrix[pr.first][pr.second]) {
                    q2.push(make_pair(nextI, nextJ));
                    atlantic[nextI][nextJ] = true;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    vector<int> v; v.push_back(i); v.push_back(j);
                    ret.push_back(v);
                }
            }
        }
        
        return ret;
        
    }
    void id11(id27* root, int num, int bitIdx) {
        id27 *curr = root;
        for (int i = bitIdx; i >= 0; i--) {
            int v = (num & (1<<i)) ? 1 : 0;
            if (v) {
                if (curr->right == NULL) curr->right = new id27(1);
                curr = curr->right;
            } else {
                if (curr->left == NULL) curr->left = new id27(0);
                curr = curr->left;
            }
            if (i == 0) curr->num = num;
        }
    }

    int id14(id27 *root, int num, int bitIdx) {
        id27 *curr = root;
        int numxor = (~num) & 0x7fffffff;
        cout << "num: " << num << " numxor:" << (num & 0xff) << endl;
        for (int i = bitIdx; i >= 0; i--) {
            int v = (numxor & (1<<i)) ? 1 : 0;
            id27 *targetNext = v ? curr->right : curr->left;
            id27 *id5 = v ? curr->left : curr->right;
            if (targetNext == NULL) curr = id5;
            else curr = targetNext;
            cout << "i:" << i << " path:" << curr->v << " targetIsNULL?" << (targetNext==NULL) << endl;
        }
        cout << "num:" << num << " curr->num:" << curr->num << endl;
        return (curr->num) ^ num;
    }

    int id7(vector<int>& nums) {
        

        id27 *root = new id27(0);
        for (int i = 0; i < nums.size(); i++) {
            id11(root, nums[i], 30); 
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, id14(root, nums[i], 30));
        }
        return ans;
    }

    void swap(vector<int> &nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    int partition(vector<int>& nums, int startIdx, int endIdx, int bitIdx) {
        if (bitIdx < 0) {
            cout << "********* Error **********" << endl;
            return -1;
        }
        if (endIdx <= startIdx) return -1;
        int midIdx = startIdx;
        int p = endIdx;
        while (midIdx < p) {
            if (nums[midIdx] & (1<<bitIdx)) swap(nums, midIdx, --p);
            else midIdx++;
        }
        return midIdx;
    }

    void swapRange(vector<int> &nums, int s, int e) {
        for (int i = s, j = e-1; i <= j; i++, j--) swap(nums, i, j);
    }

    int id8(vector<int>& nums, int s0, int e0, int s1, int e1, int bitIdx) {
        

        if (e0 < s0 || e1 < s1 || bitIdx < 0) return -1;
        if (bitIdx == 0) {
            int ans = 0;
            int iFrom = 0, iTo = 0, jFrom = 0, jTo = 0;
            if (e0-s0 > 0 && e1-s1 > 0) {
                iFrom = s0; iTo = e0; jFrom = s1; jTo = e1;
            } else if (e0-s0 > 0) {
                iFrom = s0; iTo = e0; jFrom = s0; jTo = e0;
            } else if (e1-s1 > 0) {
                iFrom = jFrom = s1; iTo = jTo = e1;
            }
            for (int i = iFrom; i < iTo; i++) for (int j = jFrom; j < jTo; j++) ans = max(ans, nums[i] ^ nums[j]);
            return ans;
        }
        if (s0 == e0) {
            int midIdx = partition(nums, s1, e1, bitIdx-1);
            return id8(nums, s1, midIdx, midIdx, e1, bitIdx-1);
        } else if (s1 == e1) {
            int midIdx = partition(nums, s0, e0, bitIdx-1);
            return id8(nums, s0, midIdx, midIdx, e0, bitIdx-1);
        }
        if (e0 == s0+1 || e1 == s1+1) {
            int ans = 0;
            for (int i = s0; i < e0; i++) for (int j = s1; j < e1; j++) ans = max(ans, nums[i] ^ nums[j]);
            return ans;
        }
        int id13 = partition(nums, s0, e0, bitIdx-1);
        int id6 = partition(nums, s1, e1, bitIdx-1);
        int ans = 0;
        if (id13-s0 > 0 && e1-id6 > 0) ans = max(ans, id8(nums, s0, id13, id6, e1, bitIdx-1));
        if (e0-id13 > 0 && id6-s1 > 0) ans = max(ans, id8(nums, s1, id6, id13, e0, bitIdx-1));
        if ((id13 == e0 && id6 == e1) || (id13 == s0 && id6 == s1)) {
            ans = max(ans, id8(nums, s0, e0, s1, e1, bitIdx-1));
        }
        return ans;
    }

    int id12(vector<int>& nums) {
        int m = partition(nums, 0, nums.size(), 30);
        return id8(nums, 0, m, m, nums.size(), 30);
    }

    int standardAns(vector<int> &nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ans = max(ans, nums[i] ^ nums[j]);
        return ans;
    }

    string originalDigits(string s) {
        string words[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        vector<int> cnt(26, 0);
        for (int i = 0; i < s.size(); i++) cnt[s[i]-'a']++;
        vector<int> digit(10, 0);
        digit[0] = cnt['z'-'a'];
        digit[2] = cnt['w'-'a'];
        digit[4] = cnt['u'-'a'];
        digit[6] = cnt['x'-'a'];
        digit[8] = cnt['g'-'a'];
        digit[5] = cnt['f'-'a'] - cnt['u'-'a'];
        digit[3] = cnt['h'-'a'] - cnt['g'-'a'];
        digit[7] = cnt['s'-'a'] - cnt['x'-'a'];
        digit[9] = cnt['i'-'a'] - digit[5] - digit[6] - digit[8];
        digit[1] = cnt['o'-'a'] - digit[0] - digit[2] - digit[4];
        string ret;
        for (int i = 0; i < digit.size(); i++) {
            for (int j = 0; j < digit[i]; j++) ret += words[i];
        }
        return ret;
    }

    int characterReplacement(string s, int k) {
        set<char> uniqueChars;
        for (int i = 0; i < s.size(); i++) uniqueChars.insert(s[i]);
        int ans = 0;
        for (char to = 'A'; to <= 'Z'; to++) {
            if (uniqueChars.find(to) == uniqueChars.end()) continue;
            queue<int> q;
            int qSum = 0;
            int id22 = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == to) {
                    id22++;
                    ans = max(ans, id22 + qSum + (int) q.size());
                } else {
                    q.push(id22);
                    qSum += id22;
                    id22 = 0;
                    while (q.size() > k) {
                        qSum -= q.front();
                        q.pop();
                    }
                    ans = max(ans, id22 + qSum + (int) q.size());
                }
            }
            cout << "to:" << to << " ans:" << ans << endl;
        }
        return ans;
    }

    Node* construct(vector<vector<int> >& grid) {
        int n = grid.size();
        vector<vector<int> > area(n+1, vector<int>(n+1, 0));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) continue;
                if (i == 1) area[i][j] = area[i][j-1] + grid[i-1][j-1];
                else if (j == 1) area[i][j] = area[i-1][j] + grid[i-1][j-1];
                else area[i][j] = area[i-1][j] + area[i][j-1] - area[i-1][j-1] + grid[i-1][j-1];
            }
        }
        return build(grid, area, 0, 0, n-1, n-1);
    }

    int getArea(vector<vector<int> > &area, int i1, int j1, int i2, int j2) {
        return area[i2+1][j2+1] + area[i1][j1] - area[i2+1][j1] - area[i1][j2+1];
    }

    Node* build(vector<vector<int> > &grid, vector<vector<int> > &area, int i1, int j1, int i2, int j2) {
        cout << "[
        Node *n = NULL;
        if (i1 == i2 && j1 == j2) {
            n = new Node(grid[i1][j1]==1, true, NULL, NULL, NULL, NULL);
        } else if (getArea(area, i1, j1, i2, j2) == (i2-i1+1)*(j2-j1+1)) n = new Node(true, true, NULL, NULL, NULL, NULL);
        else if (getArea(area, i1, j1, i2, j2) == 0) n = new Node(false, true, NULL, NULL, NULL, NULL);
        else {
            n = new Node(false, false, NULL, NULL, NULL, NULL);
            n->topLeft = build(grid, area, i1, j1, (i1+i2)/2, (j1+j2)/2);
            n->topRight = build(grid, area, i1, (j1+j2)/2+1, (i1+i2)/2, j2);
            n->bottomLeft = build(grid, area, (i1+i2)/2+1, j1, i2, (j1+j2)/2);
            n->bottomRight = build(grid, area, (i1+i2)/2+1, (j1+j2)/2+1, i2, j2);
        }
        cout << "i1:" << i1 << " j1:" << j1 << " i2:" << i2 << " j2:" << j2 << " n->val:" << n->val << " n->isLeaf:" << n->isLeaf << endl;
        return n;
    }

    bool isAdj(string &s1, string &s2) {
        int diffCnt = 0;
        if (s1.size() == s2.size()) {
            for (int i = 0; i < s1.size(); i++) if (s1[i] != s2[i]) diffCnt++;
            return diffCnt==1;
        }
        return false;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        int n = bank.size();
        vector<vector<int> > edges(n+1);
        vector<string> bankCopy;
        bankCopy.push_back(start);
        for (int i = 0; i < bank.size(); i++) bankCopy.push_back(bank[i]);
        for (int i = 0; i < n+1; i++) {
            for (int j = 0; j < n+1; j++) {
                if (isAdj(bankCopy[i], bankCopy[j])) {
                    edges[i].push_back(j);
                }
            }
        }
        vector<bool> flag(n+1, false);
        queue<pair<int,int> > q;
        q.push(make_pair(0,0)); flag[0] = true;
        while (q.size() > 0) {
            pair<int,int> t = q.front(); q.pop();
            if (bankCopy[t.first] == end) return t.second;
            for (int i = 0; i < edges[t.first].size(); i++) {
                if (!flag[edges[t.first][i]]) {
                    flag[edges[t.first][i]] = true;
                    q.push(make_pair(edges[t.first][i], t.second+1));
                }
            }
        }
        return -1;
    }

    int id3(vector<vector<int> >& intervals) {
        sort(intervals.begin(), intervals.end(), myCompare);
        deque<vector<int> > dq;
        for (int i = 0; i < intervals.size(); i++) {
            while (dq.size() > 0 && intervals[i][1] < dq.back()[1]) dq.pop_back();
            if (dq.size() == 0 || intervals[i][0] >= dq.back()[1]) dq.push_back(intervals[i]);
        }
        return intervals.size() - dq.size(); 
    }

    vector<int> id10(string s, string p) {
        int mark = 0;
        int N = 26;
        vector<int> ret;
        vector<int> target(N, 0);
        vector<int> curr(N, 0);
        for (int i = 0; i < p.size(); i++) {
            target[p[i]-'a']++;
        }
        for (int i = 0; i < target.size(); i++) if (target[i] == 0) mark = (1<<i) | mark;
        for (int i = 0; i < s.size(); i++) {
            curr[s[i]-'a']++;
            if (curr[s[i]-'a'] == target[s[i]-'a']) mark = (1<<(s[i]-'a')) | mark;
            else mark = (~(1<<(s[i]-'a'))) & mark;
            if (i >= p.size()) {
                curr[s[i-p.size()]-'a']--;
                if (curr[s[i-p.size()]-'a'] == target[s[i-p.size()]-'a']) {
                    mark = (1<<(s[i-p.size()]-'a')) | mark;
                } else {
                    mark = (~(1<<(s[i-p.size()]-'a'))) & mark;
                }
            }
            

            if (mark == 0x03ffffff) ret.push_back(i+1-p.size());
        }
        print (ret);
        return ret;
    }
    int id9(int n, int k) {
        long prefix = 0;
        while (k > 0) {
            

            if (prefix > 0) {
                k -= 1;
            }
            if (k == 0) break;
            for (int i = prefix==0?1:0; i < 10; i++) {
                long cnt = id33(prefix*10+i, n);
                

                if (k - cnt > 0) k -= cnt;
                else {
                    prefix = prefix * 10 + i;
                    break;
                }
            }
        }
        return prefix;
    }

    long pow(int q, int n) {
        if (n == 0) return 1;
        long h = pow(q, n>>1);
        return h * h * ((n&1) ? q : 1);
    }

    int id33(long prefix, long n) {
        string pStr = prefix == 0 ? "" : to_string(prefix);
        string nStr = to_string(n);
        int deltaSize = (int) nStr.size() - (int) pStr.size();
        if (deltaSize < 0 || (deltaSize == 0 && pStr > nStr)) return 0;
        int ans = 0;
        for (int i = 0; i < deltaSize; i++) ans += pow(10, i);
        if (pStr < nStr.substr(0, pStr.size())) {
            ans += pow(10, deltaSize);
        } else if (pStr == nStr.substr(0, pStr.size())) {
            ans += (n % pow(10, deltaSize)) + 1;
        }
        return ans;
    }

    int id30(long prefix, long n) {
        cout << "prefix:" << prefix << endl;
        string pStr = prefix == 0 ? "" : to_string(prefix);
        string nStr = to_string(n);
        if (pStr.size() > nStr.size()) return 0;
        if (pStr < nStr.substr(0, pStr.size())) {
            

            return (pow(10, (int) nStr.size() - (int) pStr.size() + 1) - 1) / 9;
        } else {
            int ans = 0;
            if (prefix <= n && prefix > 0) ans++;
            for (int i = prefix==0?1:0; i < 10; i++) {
                if (pStr.size() < nStr.size()) {
                    ans += id30(prefix*10+i, n);
                }
            }
            return ans;
        }
    }
    int id26(vector<int>& A) {
        int n = A.size();
        vector<unordered_map<long,int> > v(n);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long diff = (long) A[i] - A[j];
                if (v[j].find(diff) == v[j].end()) {
                    putRecord(v, i, diff, 1);
                } else {
                    ans += v[j][diff];
                    putRecord(v, i, diff, v[j][diff] + 1);
                }
            }
        }
        return ans;
    }

    void putRecord(vector<unordered_map<long, int> > &v, int i, long diff, int cnt) {
        if (v[i].find(diff) == v[i].end()) {
            v[i][diff] = cnt;
        } else {
            v[i][diff] += cnt;
        }
    }

    bool makesquare(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (sum % 4 != 0 || nums.size() < 4) return false;
        int target = sum >> 2;
        vector<int> accu(4, 0);
        return squareTraverse(nums, nums.size()-1, accu, target);
    }

    bool squareTraverse(vector<int> &nums, int idx, vector<int> accu, int target) {
        if (idx == -1) {
            for (int i = 0; i < accu.size(); i++) if (target != accu[i]) return false;
            return true;
        }

        bool ret = false;
        int firstPass = -1;
        for (int i = 0; i < accu.size(); i++) {
            if (accu[i] + nums[idx] > target) continue;
            if (firstPass != -1 && accu[i] == accu[firstPass]) continue;
            accu[i] += nums[idx];
            ret = ret || squareTraverse(nums, idx-1, accu, target);
            firstPass = i;
            accu[i] -= nums[idx];
        }
        return ret;
    }

    void id25(map<int, map<int,int> > &m, int i1, int i2) {
        if (m.find(i1) == m.end()) m[i1] = map<int,int>();
        if (m[i1].find(i2) == m[i1].end()) m[i1][i2] = 0;
        m[i1][i2]++;
    }

    void id4(map<int, map<int, int> > &m, int i1, int i2) {
        m[i1][i2]--;
        if (m[i1][i2] == 0) {
            m[i1].erase(i2);
        }
        if (m[i1].size() == 0) {
            m.erase(i1);
        }
    }
    
    int id32(vector<string>& strs, int m, int n) {
        vector<vector<int> > v(m+1, vector<int>(n+1, 0));
        vector<vector<int> > cnt(strs.size());
        for (int i = 0; i < strs.size(); i++) {
            int n0 = 0, n1 = 0;
            for (int j = 0; j < strs[i].size(); j++) {
                n0 += strs[i][j] == '0';
                n1 += strs[i][j] == '1';
            }
            vector<int> t; t.push_back(n0); t.push_back(n1);
            cnt[i] = t;
        }
        

        for (int i = 0; i < strs.size(); i++) {
            for (int j = m; j >= 0; j--) {
                for (int k = n; k >= 0; k--) {
                    

                    if (i == 0) {
                        v[j][k] = (cnt[i][0] <= j && cnt[i][1] <= k);
                    } else {
                        if (j >= cnt[i][0] && k >= cnt[i][1]) v[j][k] = max(v[j][k], v[j-cnt[i][0]][k-cnt[i][1]]+1);
                    }
                }
            }
            

        }
        return v[m][n];
    }

    int id18(string s) {
        int n = s.size();
        int ans = 0;
        vector<vector<int> > v(n, vector<int>(n, 0));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; len + i - 1 < n; i++) {
                if (len == 1) {
                    v[i][i] = 1;
                    continue;
                }
                v[i][i+len-1] = max(v[i][i+len-2], v[i+1][i+len-1]);
                if (s[i] == s[i+len-1]) v[i][i+len-1] = 2 + v[i+1][i+len-2];
                ans = max(ans, v[i][i+len-1]);
            }
        }
        return ans;
    }

    int id20(vector<int>& machines) {
        int n = machines.size();            
        int sum = 0;
        vector<int> cap(n, 0);
        for (int i = 0; i < n; i++) sum += machines[i];
        if (sum % n != 0) return -1;
        if (sum == 0) return 0;
        for (int i = 0; i < n; i++) cap[i] = machines[i] - sum/n;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int posIdx = -1, negIdx = -1;
        for (int i = n-1; i >= 0; i--) {
            if (cap[i] < 0) negIdx = i;
            else if (cap[i] > 0) posIdx = i;
        }
        while (posIdx < n || negIdx < n) {
            int delta = min(cap[posIdx], -1*cap[negIdx]);
            cap[posIdx] -= delta;
            cap[negIdx] += delta;

            if (posIdx > negIdx) left[posIdx] += delta;
            else right[posIdx] += delta;

            while (posIdx < n && cap[posIdx] <= 0) posIdx++;
            while (negIdx < n && cap[negIdx] >= 0) negIdx++;
        }
        cout << "here" << endl;
        print (left);
        print (right);
        int beginIdx = 0;
        int ans = 0;
        while (beginIdx < n) {
            int singleCost = 0;
            int endIdx = beginIdx;
            int y1 = 0, y2 = 0, x1 = 0, x2 = 0;
            while (endIdx < n && left[endIdx] + right[endIdx] > 0) {
                if (left[endIdx] > 0 && right[endIdx] == 0) {
                    x1 += left[endIdx];
                } else if (left[endIdx] == 0 && right[endIdx] > 0) {
                    y2 += right[endIdx];
                } else {
                    x2 += left[endIdx];
                    y1 += right[endIdx];
                }

                endIdx++;
            }

            if (y1 > 0 && x2 > 0) {
                int idea1 = x2<y2 ? x2+max(x1,y1+y2+x2) : (x1<y1?x2+y1:x1+x2);
                int idea2 = x1>y1 ? y1+max(x1+x2-y1,y2) : (y2<x2?x2+y1:y1+y2);
                singleCost = min(idea1, idea2);
            } else {
                singleCost = max(x1, y2);
            }
            ans = max(ans, singleCost);

            beginIdx = endIdx + 1;
        }
        return ans;
    }

    void id24(long long n, long long m) {
       vector<int> ret(n, 0);
       int beginIdx = 0, endIdx = n-1, remainStart = 1;
       fill(ret, m, beginIdx, endIdx, remainStart);
       

       for (int i = 0; i < ret.size(); i++) cout << ret[i] << " ";
       cout << endl;
    }

    void fill(vector<int> &ret, long long m, int beginIdx, int endIdx, int remainStart) {
        if (beginIdx > endIdx) return;
        

        

        int n = ret.size();
        int id31 = endIdx - beginIdx + 1;
        long long order = 0;
        int orderP = id31-2;
        long long lastOrder = 0;
        for (int start = remainStart; start < remainStart + id31; start++) {
            lastOrder = order;
            order += 1LL<<max(0, orderP--);
            if (order >= m) {
                ret[beginIdx] = start;
                for (int j = endIdx-start+remainStart+1; j <= endIdx; j++) ret[j] = --start;
                fill(ret, m-lastOrder, beginIdx+1, endIdx-ret[beginIdx]+remainStart, ret[beginIdx]+1);
                break;
            }
        }
    }
    void simulateFunc(vector<vector<int> > funcs, int entry) {
        int n = funcs.size();
        if (entry <= 0 || entry > n) return;
        stack<pair<int, int> > stk;
        vector<int> flag(n, 0);
        stk.push(make_pair(entry-1, 0));
        flag[entry-1] = 1;
        while (stk.size() > 0) {
            pair<int,int> t = stk.top(); stk.pop();
            cout << "curr: " << t.first << " " << t.second << endl;
            if (funcs[t.first][t.second] == 0) {
            } else if (funcs[t.first][t.second] == -1) {
                cout << t.first+1 << " ";
                while (stk.size() > 0) {
                    t = stk.top(); stk.pop();
                    cout << t.first+1 << " ";
                }
                cout << endl;
                return;
            } else {
                stk.push(make_pair(t.first, t.second+1));
                if (flag[funcs[t.first][t.second]-1] == 1) {
                    cout << "E" << endl;
                    return;
                }
                stk.push(make_pair(funcs[t.first][t.second]-1, 0));
                flag[funcs[t.first][t.second]-1] = 1;
            }
        }
        cout << "R" << endl;
    }

    void id21(int n, int k) {
        if (k == 0) {
            if (n == 1) cout << "0 0" << endl;
            else cout << "-1 -1" << endl;
            return;
        } else if (k > n*9) {
            cout << "-1 -1" << endl;
            return;
        }


        int remain = k;

        vector<int> small(n, 0);
        small[0] = 1;
        remain -= 1;
        for (int i = n-1; i >= 0; i--) {
            int delta = min(remain, 9-small[i]);
            remain -= delta;
            small[i] += delta;
        }

        remain = k;
        vector<int> large(n, 0);
        for (int i = 0; i < n; i++) {
            int delta = min(remain, 9-large[i]);
            remain -= delta;
            large[i] += delta;
        }

        for (int i = 0; i < n; i++) cout << small[i];
        cout << " ";
        for (int i = 0; i < n; i++) cout << large[i];
        cout << endl;
    }

    void matrixCount(vector<string> matrix, int n, int mod) {
        int rowCnt = matrix.size();
        vector<vector<long long> > dp(n+1, vector<long long>(n+1, -1));
        vector<int> cnt(n, 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                cnt[j] += matrix[i][j] == '1';
            }
        }
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < cnt.size(); i++) {
            cnt0 += cnt[i] == 0;
            cnt1 += cnt[i] == 1;
            cnt2 += cnt[i] == 2;
        }
        int ret = getAns(dp, cnt1, cnt0, mod);
        cout << ret << endl;
    }

    long long getAns(vector<vector<long long> > &dp, int remain1, int remain2, int mod) {
        

        if (dp[remain1][remain2] != -1) return dp[remain1][remain2];
        if (remain1 == 0 && remain2 == 0) return dp[remain1][remain2] = 1;
        long long ret = 0;
        if (remain2 >= 2) ret += getAns(dp, remain1+2, remain2-2, mod)*((remain2-1)*remain2/2) % mod;
        if (remain2 >= 1 && remain1 >= 1) ret += (getAns(dp, remain1, remain2-1, mod)*remain1 % mod)*remain2 % mod;
        if (remain1 >= 2) ret += getAns(dp, remain1-2, remain2, mod)*((remain1-1)*remain1/2) % mod;
        return dp[remain1][remain2] = ret % mod;
    }
};


vector<int> genVector1() {
    vector<int> stones;
    int sz[] = {0,0,4,0,5,0,5,0,4};
    for (int i = 0; i < sizeof(sz)/sizeof(int); i++) stones.push_back(sz[i]);
    return stones;
}

vector<string> genStrVector1() {
    vector<string> v;
    string sz[] = {"10","0001","111001","1","0"};
    for (int i = 0; i < sizeof(sz)/sizeof(string); i++) v.push_back(sz[i]);
    return v;
}

vector<vector<int> > genVector2() {
    vector<vector<int> > v2;
    const int m = 2;
    int sz[][m] = {
        {1,2}, {2,3}, {3,4}, {1,3}
        

    };

    for (int i = 0; i < sizeof(sz)/sizeof(int)/m; i++) {
        vector<int> v1;
        for (int j = 0; j < m; j++) v1.push_back(sz[i][j]);
        v2.push_back(v1);
    }
    return v2;
}

void testAllOne() {
    AllOne* obj = new AllOne();
    obj->inc("a");
    obj->inc("b");
    obj->inc("c");
    obj->inc("d");
    obj->inc("a");
    obj->inc("b");
    obj->inc("c");
    obj->inc("d");
    obj->print();
    obj->dec("c");
    obj->inc("d");
    obj->inc("d");
    obj->inc("a");
    cout << obj->getMinKey() << endl;;
}

void codeforce() {
    Solution solution;
    string line;
    int n, k, mod;
    scanf("%d%d%d", &n, &k, &mod);
    

    vector<string> v;
    for (int i = 0; i < k; i++) {
        cin >> line;
        v.push_back(line);
    }
    solution.matrixCount(v, n, mod);
}

int main() {
    Solution solution;
    vector<vector<int> > v2 = genVector2();
    vector<int> v1 = genVector1();
    

    

    vector<string> id1 = genStrVector1();
    

    

    

    

    

    

    

    

    codeforce();
    return 0;
}
