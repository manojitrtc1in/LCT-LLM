def solve():
    n = int(input())
    a = [list(map(int, input().split())) for _ in range(n)]
    idx = [(i, j) for i in range(n) for j in range(n) if i == j or i == n-1-j or i == n//2 or j == n//2]
    res = sum(a[i][j] for i, j in idx)
    print(res)
