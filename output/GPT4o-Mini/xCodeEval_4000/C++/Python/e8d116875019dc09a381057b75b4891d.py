from collections import defaultdict

def calc(x):
    y = 10 - x
    if not a[x] or not a[y]:
        return
    r = 1
    for i in range(10):
        r += min(a[i] - (i == x), a[9 - i] - (9 - i == y))
    global rr, xx, yy
    if r > rr:
        rr = r
        xx = x
        yy = y

s = input().strip()
a = [0] * 10
for char in s:
    a[int(char)] += 1

r = 0
x = y = int(s[0])
for i in range(a[0] + 1):
    a[0] -= i
    rr = 0
    xx = yy = int(s[0])
    for j in range(1, 6):
        calc(j)
    if rr + i > r:
        r = rr + i
        zero = i
        x = xx
        y = yy
    a[0] += i

if x == 0:
    zero -= 1
a[0] -= zero
b = a[:]
a[x] -= 1
b[y] -= 1

for i in range(10):
    for j in range(a[i] - min(a[i], b[9 - i])):
        print(i, end='')
for i in range(10):
    for j in range(min(a[i], b[9 - i])):
        print(i, end='')
if a[x] >= 0:
    print(x, end='')
for _ in range(zero):
    print('0', end='')
print()

for i in range(10):
    for j in range(b[9 - i] - min(a[i], b[9 - i])):
        print(9 - i, end='')
for i in range(10):
    for j in range(min(a[i], b[9 - i])):
        print(9 - i, end='')
if b[y] >= 0:
    print(y, end='')
for _ in range(zero):
    print('0', end='')
print()
