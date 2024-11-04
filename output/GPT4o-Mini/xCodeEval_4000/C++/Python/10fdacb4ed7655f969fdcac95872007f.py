import sys
import math
from collections import defaultdict
from functools import reduce

MOD = 1000000007
maxq = 5010
maxn = 100100
N = 200100

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
        mid = (self.tree[no].be + self.tree[no].en) // 2
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
        mid = (self.tree[no].be + self.tree[no].en) // 2
        if r >= self.tree[no].be and l <= mid:
            ans = max(ans, self.getmax(l, r, self.gleft(no)))
        if r >= mid + 1 and l <= self.tree[no].en:
            ans = max(ans, self.getmax(l, r, self.gright(no)))
        return ans

sgt = SegmentTree()
son = defaultdict(list)
arr = [0] * maxn
fa = [-1] * maxq
dp = [list() for _ in range(maxq)]
que = [None] * maxq

class Query:
    def __init__(self, l, r, p):
        self.l = l
        self.r = r
        self.maxv = 0
        self.deep = 0
        self.p = p

def dfs(no, deep=0):
    que[no].maxv = sgt.getmax(que[no].l, que[no].r, 1)
    global be, en
    be = max(be, que[no].maxv)
    en = max(en, que[no].maxv + deep + 1)
    que[no].deep = deep
    for i in son[no]:
        dfs(i, deep + 1)

def dfsdp(no):
    dp[no].append((1, que[no].maxv))
    for rno in son[no]:
        dfsdp(rno)
        rdp = []
        rdp1 = []
        sum1 = dp[no][0][0]
        sum2 = dp[rno][0][0]
        p = que[rno].p
        link1 = link2 = 0
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
                rdp[rsz - 1] = (rdp[rsz - 1][0] + rdp[i][0], rdp[i][1])
            else:
                rdp[rsz] = rdp[i]
                rsz += 1
        rdp = rdp[:rsz]

        sum1 = dp[no][0][0]
        sum2 = dp[rno][0][0]
        link1 = link2 = 0
        while link1 < len(dp[no]) or link2 < len(dp[rno]):
            if sum1 * sum2 > 1e-10:
                rdp1.append((sum1 * sum2 * p, max(dp[no][link1][1], dp[rno][link2][1] + 1)))
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

        for i in range(len(rdp1) - 1, 0, -1):
            rdp1[i] = (rdp1[i][0] - rdp1[i - 1][0], rdp1[i][1])
        
        rsz = 1
        for i in range(1, len(rdp1)):
            if rdp1[i][1] == rdp1[i - 1][1]:
                rdp1[rsz - 1] = (rdp1[rsz - 1][0] + rdp1[i][0], rdp1[i][1])
            else:
                rdp1[rsz] = rdp1[i]
                rsz += 1
        rdp1 = rdp1[:rsz]

        dp[no].clear()
        link1 = link2 = 0
        while link1 < len(rdp) or link2 < len(rdp1):
            if link2 == len(rdp1):
                dp[no].append(rdp[link1])
                link1 += 1
            elif link1 == len(rdp):
                dp[no].append(rdp1[link2])
                link2 += 1
            elif rdp[link1][1] > rdp1[link2][1]:
                dp[no].append(rdp1[link2])
                link2 += 1
            elif rdp[link1][1] == rdp1[link2][1]:
                dp[no].append((rdp[link1][0] + rdp1[link2][0], rdp[link1][1]))
                link2 += 1
                link1 += 1
            else:
                dp[no].append(rdp[link1])
                link1 += 1

def main():
    global be, en
    be = en = 0
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    nq = int(data[1])
    idx = 2
    for i in range(n):
        arr[i] = int(data[idx])
        idx += 1
    for i in range(nq):
        l = int(data[idx]) - 1
        r = int(data[idx + 1]) - 1
        p = float(data[idx + 2])
        que[i] = Query(l, r, p)
        idx += 3

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

    que[nq] = Query(0, n - 1, 0)
    sgt.build(1, 0, n - 1, 0, arr)

    dfs(nq)
    dfsdp(nq)
    ans = sum(dp[nq][i][0] * dp[nq][i][1] for i in range(len(dp[nq])))
    print(f"{ans:.10f}")

if __name__ == "__main__":
    main()
