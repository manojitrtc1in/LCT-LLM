
T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ok = False
    ans = []
    for i in range(min(n, m)):
        if min(n, m) == n and a[i] in b:
            print("YES")
            print(1, a[i])
            ok = True
            break
        elif min(n, m) == m and b[i] in a:
            print("YES")
            print(1, b[i])
            ok = True
            break
    else:
        print("NO")