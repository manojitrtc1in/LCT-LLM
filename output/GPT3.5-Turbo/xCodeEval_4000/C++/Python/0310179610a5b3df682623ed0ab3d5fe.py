import math

m = int(input())
h1, a1, x1, y1 = map(int, input().split())
t = [h1]
used = [0] * m
used[h1] = 1
while True:
    tmp = (t[-1] * x1 + y1) % m
    t.append(tmp)
    if used[tmp]:
        break
    used[tmp] = 1

used = [0] * m
h2, a2, x2, y2 = map(int, input().split())
used[h2] = 1
s = [h2]
while True:
    tmp = (s[-1] * x2 + y2) % m
    s.append(tmp)
    if used[tmp]:
        break
    used[tmp] = 1

l1 = -1
l2 = -1
mn1 = math.inf
mn2 = math.inf
now = 0
while True:
    if t[-1] == t[now]:
        l1 = len(t) - now - 1
    if t[now] == a1:
        mn1 = now
        break
    now += 1
    if now == len(t):
        break

now = 0
while True:
    if s[-1] == s[now]:
        l2 = len(s) - now - 1
    if s[now] == a2:
        mn2 = now
        break
    now += 1
    if now == len(s):
        break

def calc():
    if mn1 != math.inf and mn2 != math.inf:
        if mn1 == mn2:
            return mn1
        if mn1 > mn2 and l2 == -1:
            return -1
        if mn1 < mn2 and l1 == -1:
            return -1
        if l1 == -1:
            if (mn1 - mn2) % l2 == 0:
                return mn1
            else:
                return -1
        if l2 == -1:
            if (mn2 - mn1) % l1 == 0:
                return mn2
            else:
                return -1
        if l1 == l2:
            if abs(mn1 - mn2) % l1 == 0:
                return max(mn1, mn2)
            else:
                return -1
        if mn2 > mn1 and (mn2 - mn1) % l1 == 0:
            return mn2
        if mn1 > mn2 and (mn1 - mn2) % l2 == 0:
            return mn1
        if abs(mn2 - mn1) % math.gcd(l1, l2) != 0:
            return -1
        x, y = 0, 0
        g = math.gcd(l1, l2)
        x *= (mn2 - mn1) // g
        y *= (mn2 - mn1) // g
        if x * l1 + mn1 < max(mn1, mn2):
            x += ((max(mn1, mn2) - x * l1 + mn1 + l1 - 1) // l1 + l2 // g - 1) // (l2 // g) * (l2 // g)
        if x * l1 + mn1 >= max(mn1, mn2):
            x -= (x * l1 + mn1 - max(mn1, mn2)) // l1 // (l2 // g) * (l2 // g)
        return x * l1 + mn1
    else:
        return -1

print(calc())
