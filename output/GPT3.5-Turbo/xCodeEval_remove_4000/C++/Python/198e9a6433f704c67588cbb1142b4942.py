n, a, b, c, d = map(int, input().split())
s = input()

p = [0] * n
h = [0] * n
l = [0] * n
f = [[float('inf')] * (c+1) for _ in range(b+1)]

for i in range(n):
    if i != 0:
        p[i] = p[i-1]
        h[i] = h[i-1]
        l[i] = l[i-1]
    
    if s[i] == 'V':
        d += 1
        h[i] += 1
    elif s[i] == 'K':
        e += 1
        l[i] += 1
    
for i in range(a+1):
    for j in range(b+1):
        for k in range(c+1):
            for t in range(2):
                if i < a:
                    f[i+1][j][k][1] = min(f[i+1][j][k][1], f[i][j][k][t] + abs(l[d][i] - j) + abs(p[d][i] - k))
                
                if j < b and not t:
                    f[i][j+1][k][0] = min(f[i][j+1][k][0], f[i][j][k][t] + abs(h[e][j] - i) + abs(p[e][j] - k))
                
                if k < c:
                    f[i][j][k+1][0] = min(f[i][j][k+1][0], f[i][j][k][t] + abs(h[g][k] - i) + abs(l[g][k] - j))

print(min(f[a][b][c][0], f[a][b][c][1]) // 2)
