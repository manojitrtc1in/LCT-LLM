














    























































































































































































































































































































































































































































































































































n,k=map(int,input().split())
a=list(map(int,input().split()))
m=min(a)
c=0
for i in a:
    if (i-m)%k!=0:
        print(-1)
        break
    c+=(i-m)//k
else:
    print(c)