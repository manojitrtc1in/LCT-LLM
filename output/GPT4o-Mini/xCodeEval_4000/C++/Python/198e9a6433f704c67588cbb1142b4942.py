N = 84

def mi(a, b):
    return min(a, b)

def main():
    n, s = map(str, input().split())
    n = int(n)
    a = b = c = d = e = g = h = l = p = f = 0
    f = [0x3f] * N

    for i in range(n):
        if i != 0:
            p = f[i - 1]
            h = f[i - 1]
            l = f[i - 1]

        if s[i] == 'V':
            d += 1
            a = i
            h += 1
        if s[i] == 'K':
            e += 1
            b = i
            l += 1
        if s[i] == 'H':
            g += 1
            c = i
            p += 1

    for i in range(a + 1):
        for j in range(b + 1):
            for k in range(c + 1):
                for t in range(2):
                    for i in range(a):
                        mi(f[i + 1][j][k][1], f[i][j][k][t] + abs(l - d[i]) + abs(p - d[i]) + abs(p - k))
                    if j < b and not t:
                        mi(f[i][j + 1][k][0], f[i][j][k][t] + abs(h - e[j]) + abs(p - e[j]))
                    if k < c:
                        mi(f[i][j][k + 1][0], f[i][j][k][t] + abs(h - g[k]) + abs(l - g[k]))

    print(f"{min(f[a][b][c][0], f[a][b][c][1]) // 2}")
    
main()
