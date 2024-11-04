import sys

n = 0
a = b = c = d = e = g = h = l = p = f = 0
s = ""

def mi(a, b):
    return min(a, b)

def main():
    global n, a, b, c, d, e, g, h, l, p, f, s
    n, s = map(str, input().split())
    n = int(n)
    
    i = 0
    while i < n:
        if i != 0:
            p = p[i - 1]
            h = h[i - 1]
            l = l[i]
        
        if s[i] == 'V':
            d = a + 1
            h += 1
        elif s[i] == 'K':
            e = b + 1
            l += 1
        else:
            g = c + 1
            p += 1
        
        i += 1

    f = [[float('inf')] * (c + 1) for _ in range(a + 1)]
    
    for i in range(a + 1):
        for j in range(b + 1):
            for k in range(c + 1):
                for t in range(2):
                    if i < a:
                        f[i + 1][j][k][1] = min(f[i + 1][j][k][1], f[i][j][k][t] + abs(l[d[i]] - j) + abs(p[d[i]] - k))
                    if j < b and not t:
                        f[i][j + 1][k][0] = min(f[i][j + 1][k][0], f[i][j][k][t] + abs(h[e[j]] - i) + abs(p[e[j]] - k))
                    if k < c:
                        f[i][j][k + 1][0] = min(f[i][j][k + 1][0], f[i][j][k][t] + abs(h[g[k]] - i) + abs(l[g[k]] - j))

    print(min(f[a][b][c][0], f[a][b][c][1]) // 2)

if __name__ == "__main__":
    main()
