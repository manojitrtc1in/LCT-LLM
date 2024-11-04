
































































        
    
            










































   



















        
             





t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    c=1
    a=[[a[i],i]for i in range(n)]
   
    a.sort()
   
    for j in range(1,n):
        \
        if a[j-1][1]+1!=a[j][1]:
            c+=1
    if c<=k:
        print('YES')
    else:
        print('NO')
