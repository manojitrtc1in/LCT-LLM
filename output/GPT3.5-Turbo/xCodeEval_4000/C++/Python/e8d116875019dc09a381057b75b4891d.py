a = [0] * 10
b = [0] * 10
s = input()
for i in range(len(s)):
    a[int(s[i])] += 1

r = 0
x = int(s[0])
y = int(s[0])
zero = 0

for i in range(1, a[0] + 1):
    a[0] -= i
    rr = 0
    xx = int(s[0])
    yy = int(s[0])
    calc(1)
    calc(2)
    calc(3)
    calc(4)
    calc(5)
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
    for j in range(a[i] - min(a[i], b[9 - i])):
        print(i, end="")
for i in range(10):
    for j in range(min(a[i], b[9 - i])):
        print(i, end="")
if a[x] >= 0:
    print(x, end="")
for i in range(zero):
    print(0, end="")
print()

for i in range(10):
    for j in range(b[9 - i] - min(a[i], b[9 - i])):
        print(9 - i, end="")
for i in range(10):
    for j in range(min(a[i], b[9 - i])):
        print(9 - i, end="")
if b[y] >= 0:
    print(y, end="")
for i in range(zero):
    print(0, end="")
print()