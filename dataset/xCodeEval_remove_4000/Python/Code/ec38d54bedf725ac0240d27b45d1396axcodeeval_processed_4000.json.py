import math



























t = int(input())
for i in range(t):
    n, m, k = map(int, input().split())
    a = input()
    b = input()
    c = ''
    a = ''.join(sorted([char for char in a]))
    b = ''.join(sorted([char for char in b]))
    aCount = 0
    bCount = 0
    while(a != '' and b != ''):
        if(aCount != k and (a[0] < b[0] or bCount == k or (a[0] == b[0] and len(a) < len(b)))):
            c += a[0]
            aCount += 1
            bCount = 0
            a = a[1:]
        else:
            c += b[0]
            bCount += 1
            aCount = 0
            b = b[1:]
    print(c)
