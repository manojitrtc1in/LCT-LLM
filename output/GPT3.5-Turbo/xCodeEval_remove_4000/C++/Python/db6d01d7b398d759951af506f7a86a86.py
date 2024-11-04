a = [0] * 10
n = len(s)
for i in range(n):
    a[int(s[i])] += 1

S = -1
Sx = 0
Sy = 0
AS = -1
ASx = 0
ASy = 0
ASz = 0

def chk(x, y):
    global A, B, S, Sx, Sy
    A = a.copy()
    B = a.copy()
    A[x] -= 1
    B[y] -= 1
    if A[x] < 0 or B[y] < 0:
        return
    T = 0
    for i in range(10):
        T += min(A[i], B[9 - i])
    if T > S:
        S = T
        Sx = x
        Sy = y

for i in range(a[0] + 1):
    a[0] -= i
    S = -1
    Sx = 0
    Sy = 0
    chk(1, 9)
    chk(2, 8)
    chk(3, 7)
    chk(4, 6)
    chk(5, 5)
    a[0] += i
    if S == -1:
        if i >= 1 and i >= AS:
            AS = i
            Sx = 0
            Sy = 0
            ASz = i
        continue
    if S + i + 1 > AS:
        AS = S + i + 1
        ASx = Sx
        ASy = Sy
        ASz = i

if AS <= 0:
    print(s)
    print(s)
else:
    if not ASx:
        ASz -= 1
    a[0] -= ASz
    A = a.copy()
    B = a.copy()
    A[ASx] -= 1
    B[ASy] -= 1
    for i in range(10):
        for j in range(A[i] - min(A[i], B[9 - i])):
            print(i, end='')
    for i in range(10):
        for j in range(min(A[i], B[9 - i])):
            print(i, end='')
    print(ASx, end='')
    for i in range(ASz):
        print('0', end='')
    print()
    for i in range(10):
        for j in range(B[9 - i] - min(A[i], B[9 - i])):
            print(9 - i, end='')
    for i in range(10):
        for j in range(min(A[i], B[9 - i])):
            print(9 - i, end='')
    print(ASy, end='')
    for i in range(ASz):
        print('0', end='')
    print()
