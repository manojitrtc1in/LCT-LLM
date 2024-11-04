import sys

a = [0] * 128
c = [0] * 128
t = [0] * 128

b, d = map(int, input().split())
a = input()
c = input()

s = 0
n = len(c)

for i in range(n):
    k = t[i]
    for j in range(len(a)):
        if a[j] == c[(i + k) % n]:
            k += 1
    t[i] = k

for i in range(b):
    s += t[s % n]

print(s // n // d)
