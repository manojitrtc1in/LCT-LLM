def another_main():
    n = int(input())
    if n == 1:
        print("0")
    else:
        v = list(map(int, input().split()))
        v = [x-1 for x in v]
        q = [0] * n
        mx = (0, 0)
        for i in range(n):
            q[v[i]] += 1
            mx = max(mx, (q[v[i]], v[i]))
        p = mx[1]
        u = [[] for _ in range(n+1)]
        for i in range(n):
            if i != p:
                u[q[i]].append(i)
        uu = []
        for i in range(n, -1, -1):
            if len(u[i]) > 0:
                uu.append(i)
        last = 0
        leftmost = [[] for _ in range(n)]
        for i in range(n):
            leftmost[i] = [n+1] * (q[i] + 1)
            leftmost[i][0] = 0
        ans = 0
        for y in range(min(n, 100)):
            if y != p:
                g = [-1] * (n+1)
                b = 0
                for i in range(n):
                    if v[i] == p:
                        ans = max(ans, i - g[len(g) - b - 1] - 1)
                        if b > 0:
                            b -= 1
                        else:
                            g.append(i)
                    elif v[i] == y:
                        b += 1
                ans = max(ans, n - g[len(g) - b - 1] - 1)
        print(ans)

another_main()
