import math




























for t in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    ans = sorted(arr)
    if(n==1):
        print(-1)
        continue
    for i in range(n-1):
        if(arr[i]==ans[i]):
            ans[i],ans[i+1]=ans[i+1],ans[i]
    if(ans[n-1]==arr[n-1]):
        ans[n-1],ans[n-2] = ans[n-2],ans[n-1]
    print(*ans)
