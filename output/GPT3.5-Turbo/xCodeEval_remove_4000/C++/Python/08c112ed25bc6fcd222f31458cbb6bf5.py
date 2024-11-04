import sys

INF = int(1e9)

def solve():
    n = int(input())
    a = [0] * (n + 2)
    for i in range(1, n + 1):
        a[i] = int(input())
    a[0] = -INF
    a[n + 1] = INF + INF
    ans = INF
    for i in range(1, n + 1):
        s = a[i]
        for j in range(2, 51):
            if i + j - 1 <= n:
                s ^= a[i + j - 1]
                z = 0
                for r in range(50):
                    if i + j + r <= n + 1:
                        z ^= a[i + j + r]
                        if a[i - 1] > s or s > z:
                            ans = min(ans, j + r)
                            break
    if ans == INF:
        ans = 0
    print(ans - 1)

def main():
    solve()

if __name__ == "__main__":
    main()
