
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    ans = n - 1
    while ans and a[ans] <= a[ans - 1]: ans -= 1
    while ans and a[ans] >= a[ans - 1]: ans -= 1
    print(ans)
