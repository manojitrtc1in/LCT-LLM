















t = int(input())
for t in range(t):
    n,m,k = map(int, input().split())
    colors = list(map(int, input().split()))
    if(n == 3 and m == 3):
        if(max(colors) >= n*m):
            print("Yes")
        else:
            print("No")
        continue
    c1,c2 = 0,0
    check1, check2 = set(), set()
    for color in colors:
        if(color//n > 1):
            c1 += color//n
            check1.add(color//n)
        if(color//m > 1):
            c2 += color//m
            check2.add(color//m)
    if((c1  >= m and check1 != set([2])) or (c2 >= n and check2 != set([2]))):
        print("Yes")
    elif((c1 >= m and m%2==0) or (c2 >= n and n%2==0)):
        print("Yes")
    else:
        print("No")
