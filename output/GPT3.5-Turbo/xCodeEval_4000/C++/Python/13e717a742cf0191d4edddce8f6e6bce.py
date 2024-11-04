a = [0] * 10
b = [0] * 10
s = input()
for i in range(len(s)):
    a[int(s[i])] += 1

r = -1
x = int(s[0])
y = x
zero = 0

for i in range(1, a[0] + 1):
    a[0] -= i
    rr = 0
    xx = x
    yy = y
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
b = a.copy()
a[x] -= 1
b[y] -= 1

for i in range(10):
    for j in range(a[i] - min(a[i], b[9-i])):
        print(i, end="")
for i in range(10):
    for j in range(min(a[i], b[9-i])):
        print(i, end="")
if a[x] >= 0:
    print(x, end="")
for i in range(zero):
    print(0, end="")
print()

for i in range(10):
    for j in range(b[9-i] - min(a[i], b[9-i])):
        print(9-i, end="")
for i in range(10):
    for j in range(min(a[i], b[9-i])):
        print(9-i, end="")
if b[y] >= 0:
    print(y, end="")
for i in range(zero):
    print(0, end="")
print()
