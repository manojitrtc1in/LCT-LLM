











































import sys
input=sys.stdin.readline
n,q= map(int, input().split())
a = dict(enumerate(map(int, input().split())))
s=sum(a.values())
default=0
for _ in range(q):
    b=list(map(int, input().split()))
    t = b[0]
    if t==1:
        s-=a.get(b[1]-1,default)
        s+=b[2]
        a[b[1] - 1] = b[2]
    elif t==2:
        s = n*b[1]
        a={}
        default=b[1]
    print(s)