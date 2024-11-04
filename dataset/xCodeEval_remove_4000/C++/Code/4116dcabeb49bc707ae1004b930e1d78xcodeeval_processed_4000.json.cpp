

using namespace std;
typedef long long ll; 
typedef pair<int, int> pii;
typedef vector<int> vi;








  __asm__ ("addl %8,%k2\n\tadcl %6,%k1\n\tadcl %4,%k0"     \
       : "=r" (sh), "=r" (sm), "=&r" (sl)                  \
       : "0"  ((id0)(ah)), "g" ((id0)(bh)),    \
         "1"  ((id0)(am)), "g" ((id0)(bm)),    \
         "2"  ((id0)(al)), "g" ((id0)(bl)))    \


  __asm__ ("addl %5,%k1\n\tadcl %3,%k0"                  \
       : "=r" (sh), "=&r" (sl)                           \
       : "0"  ((id0)(ah)), "g" ((id0)(bh)),  \
         "%1" ((id0)(al)), "g" ((id0)(bl)))


  __asm__ ("subl %5,%k1\n\tsbbl %3,%k0"                 \
       : "=r" (sh), "=&r" (sl)                          \
       : "0" ((id0)(ah)), "g" ((id0)(bh)),  \
         "1" ((id0)(al)), "g" ((id0)(bl)))


  __asm__ ("mull %3"                                    \
       : "=a" (w0), "=d" (w1)                           \
       : "%0" ((id0)(u)), "rm" ((id0)(v)))


  __asm__ ("divl %4"                                                            \
       : "=a" (q), "=d" (r)                                                     \
       : "0" ((id0)(n0)), "1" ((id0)(n1)), "rm" ((id0)(dx)))


  __asm__ ("idivl %4"                                                           \
       : "=a" (q), "=d" (r)                                                     \
       : "0" ((id0)(n0)), "1" ((id0)(n1)), "rm" ((id0)(dx)))


  do {                                                                \
    id0 id2;                                                \
    __asm__ ("bsrl %1,%0" : "=r" (id2) : "rm" ((id0)(x)));  \
    (count) = id2 ^ (id0) 31;                               \
  } while (0)


  do {                                                              \
    __asm__ ("bsfl %1,%0" : "=r" (count) : "rm" ((id0)(x)));  \
  } while (0)


  do {                                                               \
    __asm__("bswap %0" : "=r"(x) : "0"(x));                          \
  } while (0)


static const int rec_word_tab[512] = {
   32737, 32673, 32609, 32546, 32483, 32420, 32357, 32295, 32233, 32171, 32109, 32048, 31987, 31926, 31865, 31805,
   31744, 31684, 31625, 31565, 31506, 31447, 31388, 31329, 31271, 31212, 31154, 31097, 31039, 30982, 30924, 30868,
   30811, 30754, 30698, 30642, 30586, 30530, 30475, 30419, 30364, 30309, 30255, 30200, 30146, 30092, 30038, 29984,
   29930, 29877, 29824, 29771, 29718, 29666, 29613, 29561, 29509, 29457, 29405, 29354, 29303, 29251, 29200, 29150,
   29099, 29049, 28998, 28948, 28898, 28849, 28799, 28750, 28700, 28651, 28602, 28554, 28505, 28457, 28409, 28360,
   28313, 28265, 28217, 28170, 28123, 28075, 28029, 27982, 27935, 27889, 27842, 27796, 27750, 27704, 27658, 27613,
   27568, 27522, 27477, 27432, 27387, 27343, 27298, 27254, 27209, 27165, 27121, 27078, 27034, 26990, 26947, 26904,
   26861, 26818, 26775, 26732, 26690, 26647, 26605, 26563, 26521, 26479, 26437, 26395, 26354, 26312, 26271, 26230,
   26189, 26148, 26108, 26067, 26026, 25986, 25946, 25906, 25866, 25826, 25786, 25747, 25707, 25668, 25628, 25589,
   25550, 25511, 25473, 25434, 25395, 25357, 25319, 25281, 25242, 25205, 25167, 25129, 25091, 25054, 25016, 24979,
   24942, 24905, 24868, 24831, 24794, 24758, 24721, 24685, 24649, 24612, 24576, 24540, 24504, 24469, 24433, 24397,
   24362, 24327, 24291, 24256, 24221, 24186, 24151, 24117, 24082, 24047, 24013, 23979, 23944, 23910, 23876, 23842,
   23808, 23774, 23741, 23707, 23674, 23640, 23607, 23574, 23541, 23508, 23475, 23442, 23409, 23377, 23344, 23312,
   23279, 23247, 23215, 23183, 23151, 23119, 23087, 23055, 23023, 22992, 22960, 22929, 22898, 22866, 22835, 22804,
   22773, 22742, 22711, 22681, 22650, 22619, 22589, 22559, 22528, 22498, 22468, 22438, 22408, 22378, 22348, 22318,
   22289, 22259, 22229, 22200, 22171, 22141, 22112, 22083, 22054, 22025, 21996, 21967, 21938, 21910, 21881, 21853,
   21824, 21796, 21767, 21739, 21711, 21683, 21655, 21627, 21599, 21571, 21544, 21516, 21488, 21461, 21433, 21406,
   21379, 21352, 21324, 21297, 21270, 21243, 21216, 21190, 21163, 21136, 21110, 21083, 21056, 21030, 21004, 20977,
   20951, 20925, 20899, 20873, 20847, 20821, 20795, 20769, 20744, 20718, 20693, 20667, 20642, 20616, 20591, 20566,
   20540, 20515, 20490, 20465, 20440, 20415, 20390, 20366, 20341, 20316, 20292, 20267, 20243, 20218, 20194, 20170,
   20145, 20121, 20097, 20073, 20049, 20025, 20001, 19977, 19953, 19930, 19906, 19882, 19859, 19835, 19812, 19789,
   19765, 19742, 19719, 19696, 19672, 19649, 19626, 19603, 19581, 19558, 19535, 19512, 19489, 19467, 19444, 19422,
   19399, 19377, 19354, 19332, 19310, 19288, 19265, 19243, 19221, 19199, 19177, 19155, 19133, 19112, 19090, 19068,
   19046, 19025, 19003, 18982, 18960, 18939, 18917, 18896, 18875, 18854, 18832, 18811, 18790, 18769, 18748, 18727,
   18706, 18686, 18665, 18644, 18623, 18603, 18582, 18561, 18541, 18520, 18500, 18479, 18459, 18439, 18419, 18398,
   18378, 18358, 18338, 18318, 18298, 18278, 18258, 18238, 18218, 18199, 18179, 18159, 18139, 18120, 18100, 18081,
   18061, 18042, 18022, 18003, 17984, 17964, 17945, 17926, 17907, 17888, 17869, 17850, 17831, 17812, 17793, 17774,
   17755, 17736, 17718, 17699, 17680, 17662, 17643, 17624, 17606, 17587, 17569, 17551, 17532, 17514, 17496, 17477,
   17459, 17441, 17423, 17405, 17387, 17369, 17351, 17333, 17315, 17297, 17279, 17261, 17244, 17226, 17208, 17191,
   17173, 17155, 17138, 17120, 17103, 17085, 17068, 17051, 17033, 17016, 16999, 16982, 16964, 16947, 16930, 16913,
   16896, 16879, 16862, 16845, 16828, 16811, 16794, 16778, 16761, 16744, 16727, 16711, 16694, 16677, 16661, 16644,
   16628, 16611, 16595, 16578, 16562, 16546, 16529, 16513, 16497, 16481, 16464, 16448, 16432, 16416, 16400, 16384
};


   do {                                                           \
      id0 _v0, _v1, _v2, _d21, _e, _m0;                     \
      _v0 = rec_word_tab[((d) >> 22) & 0x1FF];                    \
      _d21 = ((d) >> 11) + 1;                                     \
      _m0 = _v0*_v0;                                              \
      umul_ppmm(_v1, _e, _m0, _d21);                              \
      _v1 = (_v0 << 4) - _v1 - 1;                                 \
      _e = -_v1*((d) >> 1);                                       \
      _m0 = -((d) & (id0) 1);                               \
      _e -= ((_v1 - (_v1 >> 1)) & _m0);                           \
      umul_ppmm(_v2, _m0, _v1, _e);                               \
      _v2 = (_v1 << 15) + (_v2 >> 1);                             \
      umul_ppmm(_v0, _d21, _v2, (d));                             \
      add_ssaaaa(_v0, _d21, _v0, _d21, (id0) 0, (d));       \
      (dinv) = _v2 - (_v0 + (d));                                 \
   } while(0)











typedef long mp_limb_signed_t;
typedef unsigned long id0;
typedef unsigned long ulong;
typedef long slong;
typedef unsigned int mp_bitcnt_t;
typedef id0 *mp_ptr;
typedef mp_ptr mp_srcptr;




 extern "C" {


typedef struct
{
   id0 n;
   id0 ninv;
   mp_bitcnt_t norm;
} nmod_t;


     ((shift == 32) ? WORD(0) : ((in) >> (shift)))


   do { \
      id0 q0, q1, r1; \
      const id0 u1 = ((a_hi)<<(mod).norm) + r_shift((a_lo), 32 - (mod).norm); \
      const id0 u0 = ((a_lo)<<(mod).norm); \
      const id0 nxx = ((mod).n<<(mod).norm); \
      umul_ppmm(q1, q0, (mod).ninv, u1); \
      add_ssaaaa(q1, q0, q1, q0, u1, u0); \
      r1 = (u0 - (q1 + 1)*nxx); \
      if (r1 > q0) r1 += nxx; \
      if (r1 < nxx) r = (r1>>(mod).norm); \
      else r = ((r1 - nxx)>>(mod).norm); \
   } while (0)


   do { \
      NMOD_RED2(r, 0, a, mod); \
   } while (0)


    do { \
       id0 v_hi;  \
       NMOD_RED(v_hi, a_hi, mod); \
       NMOD_RED2(r, v_hi, a_lo, mod); \
    } while (0)


    do { \
       id0 v_hi;  \
       NMOD_RED2(v_hi, a_hi, a_me, mod); \
       NMOD_RED2(r, v_hi, a_lo, mod); \
    } while (0)


    do                                                                      \
    {                                                                       \
        id0 s0, s1, s2, t0, t1;                                       \
        s0 = s1 = s2 = UWORD(0);                                                 \
        switch (id4)                                                     \
        {                                                                   \
            case 1:                                                         \
                for (i = 0; i < len; i++)                                   \
                {                                                           \
                    s0 += (expr1) * (expr2);                                \
                }                                                           \
                NMOD_RED(s0, s0, mod);                                      \
                break;                                                      \
            case 2:                                                         \
                if (mod.n <= (UWORD(1) << (32 / 2)))                     \
                {                                                           \
                    for (i = 0; i < len; i++)                               \
                    {                                                       \
                        t0 = (expr1) * (expr2);                             \
                        add_ssaaaa(s1, s0, s1, s0, 0, t0);                  \
                    }                                                       \
                }                                                           \
                else                                                        \
                {                                                           \
                    for (i = 0; i < len; i++)                               \
                    {                                                       \
                        umul_ppmm(t1, t0, (expr1), (expr2));                \
                        add_ssaaaa(s1, s0, s1, s0, t1, t0);                 \
                    }                                                       \
                }                                                           \
                NMOD2_RED2(s0, s1, s0, mod);                                \
                break;                                                      \
            default:                                                        \
                for (i = 0; i < len; i++)                                   \
                {                                                           \
                    umul_ppmm(t1, t0, (expr1), (expr2));                    \
                    add_sssaaaaaa(s2, s1, s0, s2, s1, s0, 0, t1, t0);       \
                }                                                           \
                NMOD_RED(s2, s2, mod);                                      \
                NMOD_RED3(s0, s2, s1, s0, mod);                             \
                break;                                                      \
        }                                                                   \
        res = s0;                                                           \
    } while (0);

id0
id1(mp_srcptr vec1, mp_srcptr vec2, slong len, nmod_t mod, int id4)
{
    id0 res;
    slong i;
    NMOD_VEC_DOT(res, i, len, vec1[i], vec2[i], mod, id4);
    return res;
}


}





const int MAX = 100005;
const unsigned int MOD = 1000000007;
const ll MOD2 = (ll)MOD*MOD;

int red(int a) { while (a >= MOD) { a -= MOD; } return a; }
int add(int a, int b) { return red(a+b); }
int sub(int a, int b) { return red(a-b+MOD); }
int mult(int a, int b) { return ((ll)a*b)%MOD; }

int expo(int a, int b) {
    int ret=1;
    for(; b>0; b/=2) {
        if(b&1) { ret=mult(ret, a); }
        a=mult(a, a);
    }
    return ret;
}
int f[2*MAX];
int inv[2*MAX];
int fi[2*MAX];
int c(int n, int k) {
    if (n<k) { return 0; }
    return mult(f[n], mult(fi[k], fi[n-k]));
}

vector<pii> bad;
int paths(int a, int b) {
    int u = bad[b].f - bad[a].f;
    int d = bad[b].s - bad[a].s;
    if (u >= 0 && d >= 0) { return c(u+d, u); }
    else { return 0; }
}

int dp[2005][25];
int pth[2005][2005];
vi vals;

id0 vec1[2005];
id0 vec2[2005];

void solve() {
    nmod_t mod;
    mod.n = MOD;
    count_leading_zeros(mod.norm, MOD);
    invert_limb(mod.ninv, MOD << mod.norm);

    f[0] = fi[0] = 1; FOR(i, 1, 2*MAX) { f[i] = mult(f[i-1], i); }
    inv[1] = 1; FOR(i, 2, 2*MAX) { inv[i] = sub(0, mult(MOD/i, inv[MOD%i])); }
    FOR(i, 1, 2*MAX) { fi[i] = mult(fi[i-1], inv[i]); }
    int n, m, k, ch; scanf("%d %d %d %d", &n, &m, &k, &ch);
    while (ch > 1) {
        vals.pb(ch);
        ch = (ch+1)/2;
    }
    vals.pb(1); vals.pb(1); vals.pb(1); vals.pb(1);
    bool st = false; bool en = false;
    id3(i, k) {
        int r, c; scanf("%d %d", &r, &c);
        bad.pb({r, c});
        if (r == 1 && c == 1) { st = true; }
        if (r == n && c == m) { en = true; }
    }
    if (n == 1 && m == 1) {
        if (k == 0) { printf("%d\n", ch); }
        else { printf("%d\n", (ch+1)/2); }
        return;
    }
    if (!st) { bad.pb({1, 1}); }
    if (!en) { bad.pb({n, m}); }
    sort(bad.begin(), bad.end());
    dp[0][1] = 1;
    int num = bad.size();

    FOR(s, 1, num) {
        FOR(i, 0, s) {
            pth[i][s] = paths(i,s);
        }
    }

    FOR(s, 1, num) {
        FOR(i, 0, s) vec1[i] = pth[i][s];

        FOR(b, 2, 25) {
            long long tot = 0;
            FOR(i, 0, s) {
                int v = (dp[i][b-1] - dp[i][b]);
                if (v < 0) v += MOD;
                vec2[i] = v;
            }

            dp[s][b] = id1(vec1, vec2, s, mod, 3);
        }
    }
    int subtract = 0; if (!st) { subtract++; } if (!en) { subtract++; }
    int totpath = paths(0, num-1);
    int denom = expo(totpath, MOD-2);
    int ans = 0;
    FOR(i, subtract, vals.size()) {
        totpath = sub(totpath, dp[num-1][i]);
        ans = add(ans, mult(vals[i-subtract], dp[num-1][i]));
    }
    ans = add(totpath, ans);
    printf("%d\n", mult(ans, denom));
}


int main() {
    solve();
}