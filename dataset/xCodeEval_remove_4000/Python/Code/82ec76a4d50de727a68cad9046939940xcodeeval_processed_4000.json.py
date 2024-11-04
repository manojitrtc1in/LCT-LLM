













































import sys;input=sys.stdin.readline
n,q= map(int, input().split())
a=[0]+sorted(list(map(int, input().split())))[::-1]
for i in range(n):
    a[i+1]+=a[i]
for i in range(q):
    x, y = map(int, input().split())
    print(a[x]-a[x-y])