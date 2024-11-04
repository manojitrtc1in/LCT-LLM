s, t = input().split()
n = len(s)
m = len(t)

front = []
back = []
pos = 0
for i in range(m):
    front.append(s.find(t[i], pos))
    pos = front[i] + 1

pos = n - 1
for i in range(m-1, -1, -1):
    back.append(s.rfind(t[i], 0, pos))
    pos = back[m-i-1] - 1

ans = max(back[0], n - 1 - front[m-1])
for i in range(m - 1):
    ans = max(ans, back[i + 1] - front[i] - 1)

print(ans)
