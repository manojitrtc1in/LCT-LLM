


















import math

t = int(input())
for t in range(t):
    n = int(input())
    s = input()
    if(len(set(s)) == 1):
        print(n)
        continue
    mid = math.floor(n/2)
    ans = 0
    if(n%2 == 1):
        ans = 1
        i = mid-1
        while(s[i] == s[mid]):
            ans += 1
            i -= 1
        i = mid+1
        while(s[i] == s[mid]):
            ans += 1
            i += 1
    else:
        if(s[mid] == s[mid-1]):
            ans = 2
            i = mid-2
            while(s[i] == s[mid]):
                ans += 1
                i -= 1
            i = mid+1
            while(s[i] == s[mid]):
                ans += 1
                i += 1
    print(ans)
