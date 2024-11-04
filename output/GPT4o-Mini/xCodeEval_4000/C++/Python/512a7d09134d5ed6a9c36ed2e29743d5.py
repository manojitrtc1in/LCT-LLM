s, t = input().split()
n, m = len(s), len(t)

front = [0] * m
back = [0] * m
pos = 0

for i in range(m):
    front[i] = s.find(t[i], pos)
    pos = front[i] + 1

pos = n - 1
for i in range(m - 1, -1, -1):
    back[i] = s.rfind(t[i], pos)
    pos = back[i] - 1

ans = max(back[0], n - 1 - front[-1])
for i in range(m - 1):
    ans = max(ans, back[i + 1] - front[i] - 1)

print(ans)
