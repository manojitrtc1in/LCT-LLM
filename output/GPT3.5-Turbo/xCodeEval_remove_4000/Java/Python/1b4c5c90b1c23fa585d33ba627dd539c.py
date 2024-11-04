import sys
from collections import defaultdict

def main():
    t = int(input())
    for _ in range(t):
        n, k, d = map(int, input().split())
        a = list(map(int, input().split()))
        hm = defaultdict(int)
        occ = [0] * (n + 1)
        id = 0
        for i in range(n):
            if a[i] not in hm:
                hm[a[i]] = id
                id += 1
            a[i] = hm[a[i]]
        ans = 0
        for i in range(d):
            occ[a[i]] += 1
            if occ[a[i]] == 1:
                ans += 1
        ansl = ans
        for i in range(d, n):
            ans1 = ansl
            occ[a[i]] += 1
            if occ[a[i]] == 1:
                ans1 += 1
            occ[a[i - d]] -= 1
            if occ[a[i - d]] == 0:
                ans1 -= 1
            ans = min(ans, ans1)
            ansl = ans1
        print(ans)

if __name__ == "__main__":
    main()
