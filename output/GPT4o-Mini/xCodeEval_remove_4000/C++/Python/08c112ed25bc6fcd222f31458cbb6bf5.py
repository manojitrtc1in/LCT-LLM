from sys import stdin, stdout

INF = float('inf')

def solve():
    n = int(stdin.readline().strip())
    a = list(map(int, stdin.readline().strip().split()))
    a = [-INF] + a + [INF + INF]
    
    ans = INF
    for i in range(1, n + 1):
        s = a[i]
        for j in range(2, 51):
            if i + j - 1 > n:
                break
            s ^= a[i + j - 1]
            z = 0
            for r in range(50):
                if i + j + r > n + 1:
                    break
                z ^= a[i + j + r]
                if a[i - 1] > s or s > z:
                    ans = min(ans, j + r)
                    break

    if ans == INF:
        ans = 0
    stdout.write(str(ans - 1) + '\n')
    return 0

if __name__ == "__main__":
    solve()
