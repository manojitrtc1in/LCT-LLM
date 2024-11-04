def solve():
    n, k = map(int, input().split())
    k += 1
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    b = [0] * n
    for i in range(n):
        b[n - 1 - i] = a[n - 1 - i] * (i // max(k, 1))
    for i in range(n - 1, -1, -1):
        b[i] += b[i + 1]
    cum = 0
    sum = 0
    ans = b[0]
    if k > 0:
        for i in range(n):
            res = sum + b[i]
            longest = (n - i - 1) // k + 1
            ans = max(ans, res + cum * longest)
            sum += cum
            cum += a[i]
    print(ans)

solve()