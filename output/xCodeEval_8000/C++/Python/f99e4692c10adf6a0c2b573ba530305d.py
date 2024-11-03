N = int(1e6) + 9
a = [0] * N
n = int(input())
a[:n] = list(map(int, input().split()))
s = [0] * N
top = 0

def RD(x):
    return int(x)

def OT(x):
    print(x, end=' ')

for i in range(n):
    a[i] = RD(a[i])
a[RD() - 1] *= -1

for i in range(n-1, -1, -1):
    if a[i] > 0:
        if top and s[top] == a[i]:
            top -= 1
        else:
            top += 1
            s[top] = a[i]
            a[i] = -a[i]
    else:
        top += 1
        s[top] = -a[i]

if top:
    print("NO")
else:
    print("YES")
    for i in range(n):
        OT(a[i])
