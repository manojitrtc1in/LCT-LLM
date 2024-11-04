
t = int(input())
while t:
    t -= 1
    n = int(input())
    a = list(map(int, input().split()))
    if a[n - 1] > a[0]: print("YES")
    else: print("NO")
        