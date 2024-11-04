N = 84

def mi(a, b):
    return min(a, b)

def main():
    n, a, b, c, d, e, g, h, l, p, f = [0] * 11
    s = [''] * N
    
    n, s = map(str, input().split())
    n = int(n)

    for i in range(n):
        if i != 0:
            p[i] = p[i - 1]
            h[i] = h[i - 1]
            l[i] = l[i - 1]

        if s[i] == 'V':
            d += 1
            p[i] = i
            h[i] += 1
        elif s[i] == 'K':
            e += 1
            l[i] += 1
        else:
            g += 1
            p[i] += 1

    f = [[0x3f] * (b + 1) for _ in range(a + 1)]
    
    for i in range(a + 1):
        for j in range(b + 1):
            for k in range(c + 1):
                for t in range(2):
                    pos = i + j + k
                    f[i][j][k][t] = min(f[i + 1][j][k][t] + abs(l[i] - d[i]) + abs(p[i] - d[i]),
                                        f[i][j + 1][k][t] + abs(h[i] - e[j]) + abs(p[i] - e[j]),
                                        f[i][j][k + 1][t] + abs(g[i] - g[k]) + abs(l[i] - g[k]))

    print(f"{min(f[a][b][c][0], f[a][b][c][1]) // 2}")

main()
