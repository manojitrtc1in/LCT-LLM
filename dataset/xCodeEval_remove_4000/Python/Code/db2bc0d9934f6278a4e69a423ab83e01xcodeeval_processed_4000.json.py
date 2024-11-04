

for _ in range(int(input())):
    x = 998244351
    y = 998244353
    z = 499122177
    q = 998244353
    n=int(input())
    arr=list(map(int,input().split()))
    c,s,e,p=[0,0,0,n*(n-1)]
    for i in range(0,n):
        if arr[i]==0:
            s+=arr[c]
            c+=1
    for i in range(1,s+1):
        e+=p*pow(i*i,x,y)
    print(e*z%q)
