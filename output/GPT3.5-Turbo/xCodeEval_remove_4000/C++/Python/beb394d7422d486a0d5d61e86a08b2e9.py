class statistic:
    def __init__(self, pr=0, pos=0):
        self.p = [[1 - pr, 0], [0, pr]]
        self.l = self.r = pos
    
    def merge(self, a, b):
        self.l = a.l
        self.r = b.r
        m = a.r
        self.p = [[0, 0], [0, 0]]
        for i in range(2):
            for j in range(2):
                for k in range(2):
                    for l in range(2):
                        if k == 0 and l == 1 and policy[m][3]:
                            self.p[i][j] += a.p[i][k] * b.p[l][j]
                        elif k == 0 and l == 0 and policy[m][0]:
                            self.p[i][j] += a.p[i][k] * b.p[l][j]
                        elif k == 1 and l == 1 and policy[m][1]:
                            self.p[i][j] += a.p[i][k] * b.p[l][j]
                        elif k == 1 and l == 0 and policy[m][2]:
                            self.p[i][j] += a.p[i][k] * b.p[l][j]
    
    def ans(self):
        tmp = 0
        for i in range(2):
            for j in range(2):
                tmp += self.p[i][j]
        return tmp

class col:
    def __init__(self):
        self.i = 0
        self.tp = 0
        self.t1 = 0
        self.t2 = 0
    
    def ans(self):
        return self.t1 / self.t2

    def __lt__(self, other):
        return self.t1 * other.t2 < other.t1 * self.t2

inte_p = 998244353

def main():
    n = int(input())
    policy = [[1, 1, 1, 1] for _ in range(n - 1)]
    s = []
    x = []
    v = []
    p = []
    for _ in range(n - 1):
        xi, vi, pi = map(int, input().split())
        x.append(xi)
        v.append(vi)
        p.append(pi)
        s.append(statistic(p[-1] / 100, len(s)))
    tree = segment_tree(s)
    ans = 0
    cols = []
    for i in range(n - 2):
        tmp = col()
        tmp.i = i
        tmp.t1 = x[i + 1] - x[i]
        tmp.tp = 2
        tmp.t2 = v[i] + v[i + 1]
        cols.append(tmp)
        if v[i] > v[i + 1]:
            tmp.tp = 1
            tmp.t2 = v[i] - v[i + 1]
            cols.append(tmp)
        if v[i] < v[i + 1]:
            tmp.tp = 0
            tmp.t2 = v[i + 1] - v[i]
            cols.append(tmp)
    cols.sort()
    for c in cols:
        old = policy[c.i][:]
        policy[c.i][c.tp] = 1
        tree.modify_single(c.i, statistic(p[c.i] / 100, c.i))
        ans += tree.root.s.ans() * c.ans()
        policy[c.i] = old[:]
        policy[c.i][c.tp] = 0
        tree.modify_single(c.i, statistic(p[c.i] / 100, c.i))
        if tree.root.s.ans() == 0:
            break
    print(ans)

if __name__ == "__main__":
    main()
