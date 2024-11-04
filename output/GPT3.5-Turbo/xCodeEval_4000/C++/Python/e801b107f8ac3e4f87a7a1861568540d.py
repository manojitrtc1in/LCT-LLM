import sys
from collections import defaultdict

def solve():
    m = defaultdict(int)
    n, s, k = map(int, input().split())
    ans = sys.maxsize
    cnt = 0
    for i in range(1, n + 1):
        a = int(input())
        if i >= k:
            m[a - k] -= 1
            if m[a - k] == 0:
                cnt -= 1
            m[a] += 1
            if m[a] == 1:
                cnt += 1
            ans = min(ans, cnt)
        else:
            m[a] += 1
            if m[a] == 1:
                cnt += 1
    ans = min(ans, cnt)
    print(ans)

def main():
    t = 1
    t = int(input())
    for i in range(1, t + 1):
        solve()

if __name__ == "__main__":
    main()
