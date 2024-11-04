





import math








































n, m=map(int, input().split())
a =[int(n) for n in input().split()]
x=[0]
y=[0]
for i in range(1,n):
    x+=[x[-1]+max(0,a[i-1]-a[i])]
    y+=[y[-1]+max(0,a[n-i]-a[n-i-1])]
for j in range(m):
    s, t=map(int,  input().split())
    if s<t:
        print(x[t-1]-x[s-1])
    else:
        print(y[n-t]-y[n-s])