import sys

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

N = int(1e6) + 9
a = [0] * N
s = [0] * N
top = 0

n = read_int()
a = read_ints()
a[read_int() - 1] *= -1

for i in range(n - 1, -1, -1):
    if a[i] > 0:
        if top > 0 and s[top] == a[i]:
            top -= 1
        else:
            top += 1
            s[top] = a[i]
            a[i] = -a[i]
    else:
        top += 1
        s[top] = -a[i]

if top > 0:
    print("NO")
else:
    print("YES")
    print(" ".join(map(str, a)))
