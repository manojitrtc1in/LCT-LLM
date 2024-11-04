




















for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    print("NO" if n == 2*k or s[:k] != s[:-k-1:-1] else "YES")
