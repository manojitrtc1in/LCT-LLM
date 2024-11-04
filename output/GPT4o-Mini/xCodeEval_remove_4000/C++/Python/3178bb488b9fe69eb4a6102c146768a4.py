from collections import deque, defaultdict

def dfs1(x, y=-1, d=0):
    siz[x] = 1
    dep[x] = d
    for v in graf[x]:
        if v != y:
            dfs1(v, x, d + 1)
            siz[x] += siz[v]

def dfs2(x, y, d):
    t = ava.popleft()
    assert t > d
    ans.append(((x, y), t - d))
    for v in graf[x]:
        if v != y:
            dfs2(v, x, t)

def dfs3(x, y=-1, d=0):
    seen.add(d)
    for e in graf2[x]:
        if e[0] != y:
            dfs3(e[0], x, d + e[1])

def test_ans():
    for x in ans:
        graf2[x[0][0]].append((x[0][1], x[1]))
        graf2[x[0][1]].append((x[0][0], x[1]))
    for i in range(1, n + 1):
        dfs3(i)
    for i in range(1, n * n * 2 // 9):
        assert i in seen

nax = int(1e3) + 44
graf = defaultdict(list)
siz = [0] * nax
dep = [0] * nax
ans = []
ava = deque()
graf2 = defaultdict(list)
seen = set()

n = int(input())
if n == 1:
    exit()

for _ in range(n - 1):
    a, b = map(int, input().split())
    graf[a].append(b)
    graf[b].append(a)

dfs1(1)
M = n * 2 // 3

for i in range(1, n + 1):
    sizes = [(1, i)]
    p = -1
    for v in graf[i]:
        if dep[v] == dep[i] + 1:
            sizes.append((siz[v], v))
        else:
            p = v
    if i != 1:
        sizes.append((n - siz[i], p))
    
    good = all(x[0] <= M for x in sizes)
    
    if good:
        v1, v2 = [], []
        sizes.sort(reverse=True)
        sum1, sum2 = 0, 0
        whme = 0
        
        for c in sizes:
            if sum1 + c[0] > M:
                v2.append(c)
                sum2 += c[0]
                if c[1] == i:
                    whme = 2
            else:
                v1.append(c)
                sum1 += c[0]
                if c[1] == i:
                    whme = 1
        
        assert sum1 * sum2 >= n * n * 2 // 9
        assert whme != 0
        
        if whme == 2:
            v1, v2 = v2, v1
            sum1, sum2 = sum2, sum1
        
        for j in range(1, sum1):
            ava.append(j)
        
        for x in v1:
            if x[1] != i:
                dfs2(x[1], i, 0)
        
        assert not ava
        
        for j in range(sum2):
            ava.append(1 + j * sum1)
        
        for x in v2:
            dfs2(x[1], i, 0)
        
        assert not ava
        
        for x in ans:
            print(x[0][0], x[0][1], x[1])
        
        test_ans()
        exit()
    else:
        print("err")

assert False
