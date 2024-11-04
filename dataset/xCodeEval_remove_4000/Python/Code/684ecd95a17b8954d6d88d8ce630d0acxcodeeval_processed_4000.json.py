


































t=int(input())
for i in range(t):
    n=int(input())
    b=set()
    m=0
    f=[int(num) for num in input().split(" ",n-1)]
    c=f[::-1]
    for j in c:
     if j not in b:
         b.add(j)
     else:
         break
     m+=1
    res=n-m   
    print(res)
    