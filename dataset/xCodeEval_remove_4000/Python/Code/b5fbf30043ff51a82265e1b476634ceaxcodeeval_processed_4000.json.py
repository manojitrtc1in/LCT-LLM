



















t = int(input())
for t in range(t):
    n, m = map(int, input().split())
    a = input()
    b = input()
    if(a == b):
        print("YES")
        continue
    if(n == m):
        print("NO")
        continue
    else:
        if(a[n-m+1:] == b[1:] and a.count(b[0]) >= b.count(b[0])):
            print("YES")
        elif(a[n-m:] == b):
            print("YES")
        else:
            print("NO")
