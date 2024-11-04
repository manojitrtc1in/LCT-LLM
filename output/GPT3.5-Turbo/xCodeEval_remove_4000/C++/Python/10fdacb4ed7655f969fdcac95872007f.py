import math

class segment_node:
    def __init__(self):
        self.be = 0
        self.en = 0
        self.maxv = 0
        self.add = 0
        self.sum = 0

class segment_tree:
    def __init__(self):
        self.l = 0
        self.tree = []

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
            if a == None:
                self.tree[no].maxv = orig
            else:
                self.tree[no].maxv = a[l]
            self.tree[no].add = 0
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

def main():
    n, nq = map(int, input().split())
    arr = list(map(int, input().split()))
    que = []
    for _ in range(nq):
        l, r, p = map(float, input().split())
        que.append((l, r, p))
    fa = [-1] * nq
    son = [[] for _ in range(nq+1)]
    que.append((0, n-1, 0))
    sgt = segment_tree()
    sgt.tree = [segment_node() for _ in range(n * 4)]
    sgt.build(1, 0, n - 1, 0, arr)

    def dfs(no, deep=0):
        que[no] = list(que[no])
        que[no][2] = sgt.getmax(que[no][0], que[no][1], 1)
        nonlocal be, en
        be = max(be, que[no][2])
        en = max(en, que[no][2] + deep + 1)
        que[no].append(deep)
        for i in range(len(son[no])):
            dfs(son[no][i], deep + 1)

    dfs(nq)
    dp = [[] for _ in range(nq+1)]

    def dfsdp(no):
        dp[no].append((1, que[no][2]))
        for i in range(len(son[no])):
            rno = son[no][i]
            dfsdp(rno)
            rdp = []
            id1 = []
            sum1 = dp[no][0][0]
            sum2 = dp[rno][0][0]
            p = que[rno][2]
            for link1 in range(len(dp[no])):
                link2 = 0
                while link1 < len(dp[no]) or link2 < len(dp[rno]):
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
                    rdp.append((sum1 * sum2 * (1 - p), max(dp[no][link1][1], dp[rno][link2][1])))
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
            for link1 in range(len(dp[no])):
                link2 = 0
                while link1 < len(dp[no]) or link2 < len(dp[rno]):
                    if sum1 * sum2 > 1e-10:
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

            dp[no] = []
            link1 = 0
            link2 = 0
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
                elif rdp[link1][1] < id1[link2][1]:
                    dp[no].append(rdp[link1])
                    link1 += 1

    dfsdp(nq)
    ans = 0
    for i in range(len(dp[nq])):
        ans += dp[nq][i][0] * dp[nq][i][1]
    print("{:.10f}".format(ans))

if __name__ == "__main__":
    main()
