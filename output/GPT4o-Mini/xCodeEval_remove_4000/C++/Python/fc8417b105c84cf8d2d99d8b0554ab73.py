from collections import defaultdict
import sys

MAXN = int(2e5 + 99)
INF = 0x3f3f3f3f

def main():
    ans = INF
    n, k = map(int, sys.stdin.readline().split())
    t = {}
    a = defaultdict(list)

    for _ in range(n):
        temp = int(sys.stdin.readline().strip())
        cnt = 0
        while temp:
            a[temp].append(cnt)
            t[temp] = True
            cnt += 1
            temp //= 2

    for i in t.keys():
        if len(a[i]) < k:
            continue
        a[i].sort()
        ans = min(ans, sum(a[i][:k]))

    print(ans)

if __name__ == "__main__":
    main()
