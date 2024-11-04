
t = int(input())
while t:
    t -= 1
    n, m = map(int, input().split())
    a = []
    for i in range(n):
        a.append(list(map(int, input().split())))
    for i in range(n):
        ok = True
        for j in range(m):
            if (i == n - 1 or j == m - 1 or not i or not j) and a[i][j] > 3:
                print("NO")
                ok = False
                break
            if not i and not j and a[i][j] > 2:
                print("NO")
                ok = False
                break
            elif not i and not j: a[i][j] = 2
            if not j and i == n - 1 and a[i][j] > 2:
                print("NO")
                ok = False
                break
            elif not j and i == n - 1: a[i][j] = 2
            if i == n - 1 and j == m - 1 and a[i][j] > 2:
                print("NO")
                ok = False
                break
            elif i == n - 1 and j == m - 1: a[i][j] = 2
            if not i and j == m - 1 and a[i][j] > 2:
                print("NO")
                ok = False
                break
            elif not i and j == m - 1: a[i][j] = 2
            
            if not i and j and j < m - 1: a[i][j] = 3
            if not j and i and i < n - 1: a[i][j] = 3
            if i == n - 1 and j and j < m - 1: a[i][j] = 3
            if j == m - 1 and i and i < n - 1: a[i][j] = 3
            if i and i < n - 1 and j and j < m - 1 and a[i][j] > 4:
                print("NO")
                ok = False
                break
            elif i and i < n - 1 and j and j < m - 1: a[i][j] = 4
        if not ok: break
    if ok:
        print("YES")
        for i in a:
            print(' '.join(str(j) for j in i))
            
        