
























































































































































































































































import collections





































































































































































































































































































































































































































































































































































































































































































































































































































n = int(input())
a = list(map(int, input().split()))
b = a.copy()
for i in range(n):
    if a[i] >= 0:
        a[i] = (a[i] + 1) * -1
if not n % 2:
    print(' '.join((str(i) for i in a)))
else:
    m = (float('inf'), -1)
    for i in range(n):
        m = (m, (a[i], i))[m[0] > a[i] and a[i] < -1]
    if m[1] == -1:
        b[0] = 0
        print(' '.join((str(i) for i in b)))
    else:
        a[m[1]] = (a[m[1]] + 1) * -1
        print(' '.join((str(i) for i in a)))
