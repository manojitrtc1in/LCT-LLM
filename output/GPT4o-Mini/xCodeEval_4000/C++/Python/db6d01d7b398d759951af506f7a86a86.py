def chk(x, y):
    global S, Sx, Sy, A, B
    A = a.copy()
    B = a.copy()
    A[x] -= 1
    B[y] -= 1
    if A[x] < 0 or B[y] < 0:
        return
    T = sum(min(A[i], B[9 - i]) for i in range(10))
    if T > S:
        S = T
        Sx = x
        Sy = y

s = input().strip()
n = len(s)
a = [0] * 10
for char in s:
    a[int(char)] += 1

S = -1
AS = -1
ASx = ASy = ASz = 0

for i in range(a[0] + 1):
    a[0] -= i
    S = -1
    Sx = Sy = 0
    chk(1, 9)
    chk(2, 8)
    chk(3, 7)
    chk(4, 6)
    chk(5, 5)
    a[0] += i
    if S == -1:
        if i >= 1 and i >= AS:
            AS = i
            Sx = Sy = 0
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
    if ASx == 0:
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
    print('0' * ASz)
    print()

    for i in range(10):
        for j in range(B[9 - i] - min(A[i], B[9 - i])):
            print(9 - i, end='')
    
    for i in range(10):
        for j in range(min(A[i], B[9 - i])):
            print(9 - i, end='')
    
    print(ASy, end='')
    print('0' * ASz)
    print()
