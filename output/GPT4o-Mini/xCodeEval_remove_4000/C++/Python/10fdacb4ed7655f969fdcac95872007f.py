import sys
from collections import defaultdict
from math import acos

MOD = 10**9 + 7
N = 100100
maxq = 5010

class SegmentNode:
    def __init__(self):
        self.be = 0
        self.en = 0
        self.maxv = 0
        self.add = 0
        self.sum = 0

class SegmentTree:
    def __init__(self):
        self.l = 0
        self.tree = [SegmentNode() for _ in range(N * 4)]

    def gleft(self, no):
        return no << 1

    def gright(self, no):
        return (no << 1) + 1

    def gfa(self, no):
        return no >> 1

    def build(self, no, l, r, orig=0, a=None):
        if l > r:
            r = l
        if l == r:
            self.tree[no].be = self.tree[no].en = l
            self.tree[no].add = 0
            self.tree[no].maxv = orig if a is None else a[l]
            self.tree[no].sum = self.tree[no].maxv
            return
        self.tree[no].be = l
        self.tree[no].en = r
        mid = (l + r) // 2
        self.build(self.gleft(no), l, mid, orig, a)
        self.build(self.gright(no), mid + 1, r, orig, a)
        self.tree[no].sum = self.tree[self.gleft(no)].sum + self.tree[self.gright(no)].sum
        self.tree[no].add = 0
        self.tree[no].maxv = max(self.tree[self.gleft(no)].maxv, self.tree[self.gright(no)].maxv)

    def relax(self, no):
        le = self.gleft(no)
        ri = self.gright(no)
        self.tree[le].add += self.tree[no].add
        self.tree[le].sum += self.tree[no].add * (self.tree[le].en - self.tree[le].be + 1)
        self.tree[le].maxv += self.tree[no].add
        self.tree[ri].add += self.tree[no].add
        self.tree[ri].sum += self.tree[no].add * (self.tree[ri].en - self.tree[ri].be + 1)
        self.tree[ri].maxv += self.tree[no].add
        self.tree[no].add = 0

    def down(self, l, r, no, ranadd):
        if l <= self.tree[no].be and r >= self.tree[no].en:
            self.tree[no].add += ranadd
            self.tree[no].sum += ranadd * (self.tree[no].en - self.tree[no].be + 1)
            self.tree[no].maxv += ranadd
            return
        if self.tree[no].add and self.tree[no].be != self.tree[no].en:
            self.relax(no)
        mid = (self.tree[no].be + self.tree[no].en) >> 1
        if r >= self.tree[no].be and l <= mid:
            self.down(l, r, self.gleft(no), ranadd)
        if r >= mid + 1 and l <= self.tree[no].en:
            self.down(l, r, self.gright(no), ranadd)
        self.tree[no].sum = self.tree[self.gleft(no)].sum + self.tree[self.gright(no)].sum
        self.tree[no].maxv = max(self.tree[self.gleft(no)].maxv, self.tree[self.gright(no)].maxv)

    def getmax(self, l, r, no):
        if l > r:
            return 0
        if l <= self.tree[no].be and r >= self.tree[no].en:
            return self.tree[no].maxv
        if self.tree[no].add and self.tree[no].be != self.tree[no].en:
            self.relax(no)
        ans = 0
        mid = (self.tree[no].be + self.tree[no].en) >> 1
        if r >= self.tree[no].be and l <= mid:
            ans = max(ans, self.getmax(l, r, self.gleft(no)))
        if r >= mid + 1 and l <= self.tree[no].en:
            ans = max(ans, self.getmax(l, r, self.gright(no)))
        return ans

def abs1(a):
    return -a if a < 0 else a

def max1(*args):
    return max(args)

def min1(*args):
    return min(args)

def jud(a, b):
    if abs(a) < eps and abs(b) < eps:
        return 0
    elif abs1(a - b) / abs1(a) < eps:
        return 0
    return -1 if a < b else 1

def find(val, a, na, f_small=True, f_lb=True):
    be, en = 0, na - 1
    if a[0] <= a[na - 1]:
        if not f_lb:
            while be < en:
                mid = (be + en + 1) // 2
                if jud(a[mid], val) != 1:
                    be = mid
                else:
                    en = mid - 1
        else:
            while be < en:
                mid = (be + en) // 2
                if jud(a[mid], val) != -1:
                    en = mid
                else:
                    be = mid + 1
        if f_small and jud(a[be], val) == 1:
            be -= 1
        if not f_small and jud(a[be], val) == -1:
            be += 1
    else:
        if f_lb:
            while be < en:
                mid = (be + en + 1) // 2
                if jud(a[mid], val) != -1:
                    be = mid
                else:
                    en = mid - 1
        else:
            while be < en:
                mid = (be + en) // 2
                if jud(a[mid], val) != 1:
                    en = mid
                else:
                    be = mid + 1
        if not f_small and jud(a[be], val) == -1:
            be -= 1
        if f_small and jud(a[be], val) == 1:
            be += 1
    return be

def lowb(num):
    return num & (-num)

def bitnum(nValue):
    return bin(nValue).count('1')

def id2(a):
    if a == 0:
        return 0
    return 32 - (a.bit_length() - 1)

def pow(n, m, mod=0):
    if m < 0:
        return 0
    ans = 1
    k = n
    while m:
        if m & 1:
            ans *= k
            if mod:
                ans %= mod
        k *= k
        if mod:
            k %= mod
        m >>= 1
    return ans

def add(a, b, mod=-1):
    if mod == -1:
        mod = MOD
    a += b
    while a >= mod:
        a -= mod
    while a < 0:
        a += mod

def output1(arr):
    for i in range(len(arr)):
        sys.stderr.write(f"{arr[i][0]}|{arr[i][1]} ")
    sys.stderr.write("\n")

def output2(arr):
    for i in range(len(arr)):
        output1(arr[i])

eps = 1e-10
pi = acos(0.0) * 2.0

sgt = SegmentTree()
son = defaultdict(list)
arr = [0] * maxn
fa = [-1] * maxq
dp = [list() for _ in range(maxq)]
n, nq, be, en = 0, 0, 0, 0

class Query:
    def __init__(self):
        self.l = 0
        self.r = 0
        self.maxv = 0
        self.deep = 0
        self.p = 0.0

que = [Query() for _ in range(maxq)]

def dfs(no, deep=0):
    global be, en
    que[no].maxv = sgt.getmax(que[no].l, que[no].r, 1)
    be = max(be, que[no].maxv)
    en = max(en, que[no].maxv + deep + 1)
    que[no].deep = deep
    for i in range(len(son[no])):
        dfs(son[no][i], deep + 1)

def dfsdp(no):
    dp[no].append((1, que[no].maxv))
    for i in range(len(son[no])):
        rno = son[no][i]
        dfsdp(rno)
        rdp, id1 = [], []
        sum1 = dp[no][0][0]
        sum2 = dp[rno][0][0]
        p = que[rno].p
        link1, link2 = 0, 0
        while link1 < len(dp[no]) or link2 < len(dp[rno]):
            rdp.append((sum1 * sum2 * (1 - p), max(dp[no][link1][1], dp[rno][link2][1])))
            if link1 == len(dp[no]) - 1:
                link2 += 1
                if link2 == len(dp[rno]):
                    break
                sum2 += dp[rno][link2][0]
            elif link2 == len(dp[rno]) - 1:
                link1 += 1
                sum1 += dp[no][link1][0]
            elif dp[no][link1 + 1][1] > dp[rno][link2 + 1][1]:
                link2 += 1
                sum2 += dp[rno][link2][0]
            else:
                link1 += 1
                sum1 += dp[no][link1][0]

        for i in range(len(rdp) - 1, 0, -1):
            rdp[i] = (rdp[i][0] - rdp[i - 1][0], rdp[i][1])
        rsz = 1
        for i in range(1, len(rdp)):
            if rdp[i][1] == rdp[i - 1][1]:
                rdp[rsz - 1] = (rdp[rsz - 1][0] + rdp[i][0], rdp[rsz - 1][1])
            else:
                rdp[rsz] = rdp[i]
                rsz += 1
        rdp = rdp[:rsz]

        sum1 = dp[no][0][0]
        sum2 = dp[rno][0][0]
        link1, link2 = 0, 0
        while link1 < len(dp[no]) or link2 < len(dp[rno]):
            if sum1 * sum2 > eps:
                id1.append((sum1 * sum2 * p, max(dp[no][link1][1], dp[rno][link2][1] + 1)))
            if link1 == len(dp[no]) - 1:
                link2 += 1
                if link2 == len(dp[rno]):
                    break
                sum2 += dp[rno][link2][0]
            elif link2 == len(dp[rno]) - 1:
                link1 += 1
                sum1 += dp[no][link1][0]
            elif dp[no][link1 + 1][1] > dp[rno][link2 + 1][1] + 1:
                link2 += 1
                sum2 += dp[rno][link2][0]
            else:
                link1 += 1
                sum1 += dp[no][link1][0]

        for i in range(len(id1) - 1, 0, -1):
            id1[i] = (id1[i][0] - id1[i - 1][0], id1[i][1])
        rsz = 1
        for i in range(1, len(id1)):
            if id1[i][1] == id1[i - 1][1]:
                id1[rsz - 1] = (id1[rsz - 1][0] + id1[i][0], id1[rsz - 1][1])
            else:
                id1[rsz] = id1[i]
                rsz += 1
        id1 = id1[:rsz]

        dp[no].clear()
        link1, link2 = 0, 0
        while link1 < len(rdp) or link2 < len(id1):
            if link2 == len(id1):
                dp[no].append(rdp[link1])
                link1 += 1
            elif link1 == len(rdp):
                dp[no].append(id1[link2])
                link2 += 1
            elif rdp[link1][1] > id1[link2][1]:
                dp[no].append(id1[link2])
                link2 += 1
            elif rdp[link1][1] == id1[link2][1]:
                dp[no].append((rdp[link1][0] + id1[link2][0], rdp[link1][1]))
                link2 += 1
                link1 += 1
            else:
                dp[no].append(rdp[link1])
                link1 += 1

def main():
    global n, nq
    sys.stdin = open("input.txt", "r")
    n, nq = map(int, sys.stdin.readline().split())
    arr[:n] = list(map(int, sys.stdin.readline().split()))
    for i in range(nq):
        l, r, p = map(float, sys.stdin.readline().split())
        que[i].l = int(l) - 1
        que[i].r = int(r) - 1
        que[i].p = p

    for i in range(nq):
        for j in range(i):
            if j != i:
                if que[j].r - que[j].l == que[i].r - que[i].l and que[j].r == que[i].r:
                    fa[i] = j
        if fa[i] != -1:
            continue
        for j in range(nq):
            if j != i:
                if que[j].r - que[j].l == que[i].r - que[i].l:
                    continue
                if que[j].l <= que[i].l and que[j].r >= que[i].r:
                    if fa[i] == -1:
                        fa[i] = j
                        continue
                    if que[j].r - que[j].l <= que[fa[i]].r - que[fa[i]].l:
                        fa[i] = j
                        continue

    for i in range(nq):
        if fa[i] != -1:
            son[fa[i]].append(i)
        else:
            fa[i] = nq
            son[nq].append(i)

    que[nq].l = 0
    que[nq].r = n - 1
    sgt.build(1, 0, n - 1, 0, arr)

    dfs(nq)
    dfsdp(nq)
    ans = 0
    for i in range(len(dp[nq])):
        ans += dp[nq][i][0] * dp[nq][i][1]
    print(f"{ans:.10f}")

if __name__ == "__main__":
    main()
