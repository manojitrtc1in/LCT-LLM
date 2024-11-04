import math

def __lcm(a, b):
    return a * b // math.gcd(a, b)

def f(s, t, D):
    return D[t]

def bfs(adj, aa, lcm, D):
    s = aa
    D[0] = 0

    for i in range(3 * lcm):
        u = (s - i) % lcm
        if u < 0:
            u += lcm

        Du = D[i]

        if Du == math.inf:
            continue

        for v in adj[u]:
            D[i + v] = min(D[i + v], Du + 1)

def main():
    a, b, k = map(int, input().split())

    lcm = 1
    for i in range(2, k + 1):
        lcm = __lcm(lcm, i)

    adj = [[] for _ in range(lcm)]
    for i in range(lcm):
        adj[i].append(1)
        for j in range(2, k + 1):
            if i % j != 0:
                adj[i].append(i % j)

    tt = (a - b) // lcm

    aa = a % lcm
    bb = b % lcm

    D = [math.inf] * (3 * lcm)
    bfs(adj, aa, lcm, D)

    bb = (aa - bb + 3 * lcm) % lcm

    tt *= D[bb + lcm] - D[bb]

    print(D[bb] + tt)

if __name__ == "__main__":
    main()
