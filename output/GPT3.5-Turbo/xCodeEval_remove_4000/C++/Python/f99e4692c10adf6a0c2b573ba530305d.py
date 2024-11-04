N = int(1e6) + 9
a = [0] * N
n = int(input())
for i in range(n):
    a[i] = int(input())
s = [0] * N
top = 0

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
        print(a[i])
