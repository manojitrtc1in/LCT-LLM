from itertools import combinations

def count_bits(x):
    return bin(x).count('1')

def solve(S):
    n = len(S)
    m = len(S[0])
    f = [0] * (1 << m)
    ok = [0] * (m + 1)

    for i in range(n):
        for j in range(n):
            if i != j:
                s = 0
                for k in range(m):
                    if S[i][k] == S[j][k]:
                        s |= (1 << k)
                f[s] |= (1 << i)

    for s in range((1 << m) - 1, -1, -1):
        for i in range(m):
            if (s & (1 << i)) == 0:
                f[s ^ (1 << i)] |= f[s]

    for s in range(1, 1 << m):
        step = count_bits(s) + 1
        for i in range(m):
            if (s & (1 << i)) == 0:
                d = f[s | (1 << i)] ^ f[s]
                ok[step] += count_bits(d)

    ans = 0
    for i in range(1, m + 1):
        if ok[i]:
            t = ok[i] * i
            for j in range(1, i):
                t *= j
            for j in range(m - i + 1, m + 1):
                t /= j
            ans += t

    ans /= n
    return ans

S = []
for _ in range(int(input())):
    S.append(input())

ans = solve(S)
print(ans)
