class statistic:
    def __init__(self, pr=0, pos=0):
        self.p = [[1 - pr, 0], [0, pr]]
        self.l = pos
        self.r = pos
    
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
        return self.p[0][0] + self.p[0][1] + self.p[1][0] + self.p[1][1]

class col:
    def __init__(self, i, tp, t1, t2):
        self.i = i
        self.tp = tp
        self.t1 = t1
        self.t2 = t2
    
    def ans(self):
        return self.t1 / self.t2

n = int(input())
policy = [[1, 1, 1, 1] for _ in range(n - 1)]
s = []
x = []
v = []
p = []
for _ in range(n):
    xi, vi, pi = map(int, input().split())
    x.append(xi)
    v.append(vi)
    p.append(pi)
    s.append(statistic(p=pi / 100, pos=_))
tree = segment_tree(s)
ans = 0
cols = []
for i in range(n - 1):
    tmp = col(i, 2, x[i + 1] - x[i], v[i] + v[i + 1])
    cols.append(tmp)
    if v[i] > v[i + 1]:
        tmp = col(i, 1, x[i + 1] - x[i], v[i] - v[i + 1])
        cols.append(tmp)
    if v[i] < v[i + 1]:
        tmp = col(i, 0, x[i + 1] - x[i], v[i + 1] - v[i])
        cols.append(tmp)
cols.sort()
for c in cols:
    old = policy[c.i][:]
    policy[c.i][c.tp] = 1
    tree.modify_single(c.i, statistic(p=p[c.i] / 100, pos=c.i))
    ans += tree.root.s.ans() * c.ans()
    policy[c.i] = old[:]
    policy[c.i][c.tp] = 0
    tree.modify_single(c.i, statistic(p=p[c.i] / 100, pos=c.i))
    if tree.root.s.ans() == 0:
        break
print(ans)
