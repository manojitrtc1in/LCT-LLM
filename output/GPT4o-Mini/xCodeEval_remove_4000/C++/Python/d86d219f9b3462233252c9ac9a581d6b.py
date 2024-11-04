from sys import stdin, stdout

def read_int():
    return int(stdin.readline().strip())

def solve():
    n, r = map(int, stdin.readline().strip().split())
    f = [0] * 55
    s = [0] * 55
    p = [0.0] * 55
    dans = [[0.0] * 5010 for _ in range(55)]
    
    for i in range(n):
        f[i], s[i], p[i] = map(float, stdin.readline().strip().split())
        p[i] *= 0.01

    K = 50 * 100 + 1
    lp = 0
    rp = 1e8

    for _ in range(100):
        z = (lp + rp) * 0.5
        for i in range(n):
            for j in range(K):
                dans[i][j] = z

        for i in range(n - 1, -1, -1):
            for j in range(f[i]):
                dans[i][j] = z
            fi = f[i]
            si = s[i]
            pi = p[i]
            for j in range(fi, si):
                dans[i][j] = min(z, (fi + dans[i + 1][j - fi]) * pi + (si + z) * (1 - pi))
            for j in range(si, K):
                dans[i][j] = min(z, (fi + dans[i + 1][j - fi]) * pi + (si + dans[i + 1][j - si]) * (1 - pi))

        if dans[0][r] < z - 1e-10:
            rp = z
        else:
            lp = z

    stdout.write(f"{(lp + rp) * 0.5:.10f}\n")
    return 0

if __name__ == "__main__":
    solve()
