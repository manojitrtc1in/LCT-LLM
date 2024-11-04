#include <vector>
#include <map>
#include <iostream>
#include <ios>
#include <type_traits>
#include <algorithm>
#include <array>
#include <string.h>
#include <stddef.h>
#include <utility>
#include <atomic>
#include <iomanip>
#include <Windows.h>
#undef min
#undef max

#ifdef _WIN32
#define getchar_unlocked getchar
#endif
#define II (read32())
#define IU (readu32())
#define IL (read64())
#define IUL (readu64())
uint32_t readu32() { int c; while ((c = getchar_unlocked()) < '0'); uint32_t n = c & 15U; while ((c = getchar_unlocked()) >= '0') n = n * 10 + (c & 15U); return n; } uint64_t readu64() { int c; while ((c = getchar_unlocked()) < '0'); uint64_t n = c & 15U; while ((c = getchar_unlocked()) >= '0') n = n * 10 + (c & 15U); return n; } int32_t read32() { int c; while ((c = getchar_unlocked()) < '-'); bool neg = c == '-'; if (neg) c = getchar_unlocked(); uint32_t n = c & 15U; while ((c = getchar_unlocked()) >= '0') n = n * 10 + (c & 15U); return neg ? -(int32_t)n : n; } int64_t read64() { int c; while ((c = getchar_unlocked()) < '-'); bool neg = c == '-'; if (neg) c = getchar_unlocked(); uint64_t n = c & 15; while ((c = getchar_unlocked()) >= '0') n = n * 10 + (c & 15U); return neg ? -(int64_t)n : n; }
template<typename I = int, typename V = bool> struct segmap { std::map<I, V> tr; struct seg { I l, r; V v; }; struct iter { I a, b; typename std::map<I, V>::const_iterator i; seg operator*() { auto i2 = i; ++i2; return{ std::max(a,i->first),std::min(b,i2->first),i->second }; } iter& operator--() { --i; return *this; } iter& operator++() { ++i; return *this; } bool operator!=(const iter&o) { return i != o.i; } }; struct range_s { std::map<I, V> &tr; I a, b; iter begin() { return{ a, b, --tr.upper_bound(a) }; } iter end() { return{ a, b, tr.lower_bound(b) }; } }; range_s range(I a, I b) { return range_s{ tr, a, b }; } iter begin() { auto beg = tr.begin(); return{ beg->first, tr.rbegin()->first, beg }; } iter end() { auto e = --tr.end(); return{ tr.begin()->first, e->first, e }; } void init(I min, I max, V v = {}) { tr.clear(); tr.insert({ min, v }); tr.insert({ max, v }); } segmap(I min, I max, V v = {}) { init(min, max, v); } segmap() {} segmap(const segmap& o) : tr(o.tr) {} const V& operator[](I i) { auto it = tr.upper_bound(i); --it; return it->second; } seg get(I x) { auto it = tr.upper_bound(x); I r = it->first; --it; return{ it->first, r, it->second }; } void set(I a, I b, V v) { if (!(b > a)) return; I l, r; V lv, rv; auto il = tr.lower_bound(a), ir = tr.lower_bound(b); if (il == tr.begin()) { l = a; } else { --il; l = il->first; lv = il->second; } r = ir->first; if (r == b) { rv = ir->second; } else { auto rp = ir; --rp; rv = rp->second; } if (l != a) ++il; if (r == b && rv == v) { ++ir; if (ir == tr.end()) --ir; } tr.erase(il, ir); if (!(l != a && lv == v)) tr.insert({ a, v }); if (r != b && !(rv == v)) tr.insert({ b, rv }); } void swap(segmap& o) { std::swap(tr, o.tr); } };
template<unsigned k, typename I = int, typename V = void> struct kds { struct pt_void { std::array<I, k> ixs; }; struct pt_tag { std::array<I, k> ixs; V v; }; using pt = typename std::conditional<std::is_same<V, void>::value, pt_void, pt_tag>::type; size_t size; pt* dat = nullptr; ~kds() { delete dat; } struct cyclic_lt { unsigned i; bool operator()(const pt* a, const pt* b) { for (unsigned j = 0; j < k; j++) { unsigned d = (i + j) % k; if (a->ixs[d] != b->ixs[d]) return a->ixs[d] < b->ixs[d]; } return a < b; } }; template<typename It> void init(It a, It b) { size = std::distance(a, b); if (!size) return; pt** z = new pt*[size * (k + 1)]; for (size_t i = 0; i < size; i++) { z[i] = &*a; ++a; } for (unsigned i = 1; i < k; i++) memcpy(z + i * size, z, size * sizeof(*z)); for (unsigned i = 0; i < k; i++) std::sort(z + size * i, z + size * (i + 1), cyclic_lt{ i }); dat = new pt[size]; std::array<pt**, k + 1> ars; for (unsigned i = 0; i <= k; i++) ars[i] = z + i * size; _fill<0>(size, ars); dat -= size; delete[] z; } template<unsigned dim> void _fill(size_t n, std::array<pt**, k + 1> ars) { size_t med = n / 2; pt* pmed = ars[dim][med]; *dat++ = *pmed; if (n > 1) { for (unsigned i = 0; i < k; i++) { if (i == dim) continue; pt** l = ars[k], ** h = ars[k] + med + 1; cyclic_lt cmp{ dim }; for (size_t j = 0; j < n; j++) { if (ars[i][j] != pmed) *(cmp(ars[i][j], pmed) ? l : h)++ = ars[i][j]; } std::swap(ars[i], ars[k]); } } if (n > 1) _fill<(dim + 1) % k>(med, ars); if (n > 2) { for (unsigned i = 0; i < k; i++) ars[i] += med + 1; _fill<(dim + 1) % k>(n - med - 1, ars); } } template<typename F> void apply_range(F f, std::array<std::pair<I, I>, k> b) { if (!size) return; _apply_range<F, 0>(f, b, size, dat); } template<typename F, unsigned dim> void _apply_range(F f, std::array<std::pair<I, I>, k> b, size_t n, pt* p) { bool le = true, ge = true; for (unsigned i = 0; i < k; i++) { int j = (i + dim) % k; if (b[j].first > p->ixs[j]) le = false; if (b[j].first != p->ixs[j]) break; } for (unsigned i = 0; i < k; i++) { int j = (i + dim) % k; if (b[j].second < p->ixs[j]) ge = false; if (b[j].second != p->ixs[j]) break; } if (le && ge) { bool inrange = true; for (unsigned i = 0; i < k; i++) { if (!(p->ixs[i] >= b[i].first && p->ixs[i] <= b[i].second)) { inrange = false; break; } } if (inrange) f(*p); } if (le && n > 1) _apply_range<F, (dim + 1) % k>(f, b, n / 2, p + 1); if (ge && n > 2) _apply_range<F, (dim + 1) % k>(f, b, (n - 1) / 2, p + n / 2 + 1); } template<typename F> void apply_range2(F f, std::array<std::pair<I, I>, k> b) { if (!size) return; struct sg { size_t n; pt* p; unsigned dim; }; std::vector<sg> v; v.push_back({ size, dat, 0 }); while (!v.empty()) { sg s = v.back(); v.pop_back(); size_t n = s.n; pt* p = s.p; unsigned dim = s.dim; bool le = true, ge = true; for (unsigned i = 0; i < k; i++) { int j = (i + dim) % k; if (b[j].first > p->ixs[j]) le = false; if (b[j].first != p->ixs[j]) break; } for (unsigned i = 0; i < k; i++) { int j = (i + dim) % k; if (b[j].second < p->ixs[j]) ge = false; if (b[j].second != p->ixs[j]) break; } if (le && ge) { bool inrange = true; for (unsigned i = 0; i < k; i++) { if (!(p->ixs[i] >= b[i].first && p->ixs[i] <= b[i].second)) { inrange = false; break; } } if (inrange) f(*p); } if (le && n > 1) v.push_back({ n / 2, p + 1, (dim + 1) % k }); if (ge && n > 2) v.push_back({ (n - 1) / 2, p + n / 2 + 1, (dim + 1) % k }); } } };



using namespace std;

#define N 100000

struct pt { int x, y; };
kds<2, int, int> k;
decltype(k)::pt p1[N];
pt p2[N];
int pre[N];
void* kdat;

atomic<int> place;


LONG __stdcall crashed(_EXCEPTION_POINTERS* ) {
    cout << kdat << '\n';
    
    exit(0);
}

int main()
{
    place = 0;
    SetUnhandledExceptionFilter(crashed);
    ios_base::sync_with_stdio(0);

    int n = IU;
    for(int i=0; i<n; i++) {
        p1[i].ixs[0] = IU;
        p1[i].ixs[1] = IU;
        p1[i].v = i;
        p2[i].x = IU;
        p2[i].y = IU;
    }
    place = 1;
    segmap<int, int> b(0, 1000000001, -1);
    b.set(0, 1, 0);
    place = 2;
    k.init(p1, p1 + n);
    kdat = k.dat;
    place = 3;
    vector<int> cur, nex;
    for (int i = 0; i<n; i++) {
        if (p1[i].ixs[0] == 0 && p1[i].ixs[1] == 0)
            cur.push_back(i);
    }
    int goal = n - 1;
    for (int t = 1; !cur.empty(); t++) {
        place = 4;
        if (find(cur.begin(), cur.end(), goal) != cur.end()) {
            printf("%d\n", t);
            vector<int> out;
            for (int v = goal; t--; v = pre[v])
                out.push_back(v + 1);
            for (auto i = out.rbegin(); i != out.rend(); ++i)
                printf("%d ", *i);
            return 0;
        }
        for (int v : cur) {
            place = 5;
            int x = -1;
            for (auto s : b.range(0, p2[v].x + 1)) {
                place = 10;
                if (s.v >= p2[v].y) continue;
                if (!~x) x = s.l;
                place = 6;
                k.apply_range2([&nex, v](decltype(k)::pt& p) {
                    nex.push_back(p.v);
                    pre[p.v] = v;
                }, { pair<int,int>{s.l, s.r - 1}, pair<int,int>{s.v + 1, p2[v].y} });
                place = 7;
            }
            if (~x) {
                place = 8;
                b.set(x, p2[v].x + 1, p2[v].y);
            }
        }
        place = 9;
        cur.clear();
        swap(cur, nex);
    }
    cout << -1;
    return 0;
}



