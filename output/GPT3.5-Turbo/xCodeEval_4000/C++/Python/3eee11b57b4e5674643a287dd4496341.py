n = int(input())
a = list(map(int, input().split()))
b = [[] for _ in range(100)]
sum = [[0] * (n + 1) for _ in range(100)]
mp = [-1] * 404040

for i in range(n):
    a[i] -= 1
    sum[a[i]][i + 1] += 1
    b[a[i]].append(i)

for i in range(100):
    for j in range(n):
        sum[i][j + 1] += sum[i][j]

def find():
    mx = 0
    ret = -1
    for i in range(100):
        if sum[i][n] > mx:
            mx = sum[i][n]
            ret = i
    return ret

i = find()
ans = 0

for j in range(100):
    if i == j:
        continue
    if len(b[i]) == 0 or len(b[j]) == 0:
        continue
    x = 0
    y = 0
    now = 202020
    mp[202020] = 0
    era = []
    while True:
        if x != len(b[i]) and y != len(b[j]):
            if b[i][x] < b[j][y]:
                tmp = (1, b[i][x])
            else:
                tmp = (-1, b[j][y])
        elif x != len(b[i]):
            tmp = (1, b[i][x])
        elif y != len(b[j]):
            tmp = (-1, b[j][y])
        else:
            tmp = (-2, 0)
        if tmp[0] == -2:
            break
        if tmp[0] == 1:
            x += 1
        else:
            y += 1
        now += tmp[0]
        if mp[now] != -1:
            if tmp[0] == -2:
                ans = max(ans, n - mp[now])
            else:
                ans = max(ans, tmp[1] - mp[now])
        else:
            mp[now] = tmp[1] + 1
            era.append(now)
    for e in era:
        mp[e] = -1

print(ans)
