import sys
from typing import List, Dict
from collections import defaultdict
from functools import reduce

def main() -> None:
    ans = sys.maxsize
    n, k = map(int, input().split())
    t = defaultdict(bool)
    a = defaultdict(list)
    for i in range(n):
        temp = int(input())
        cnt = 0
        while temp:
            a[temp].append(cnt)
            t[temp] = True
            temp //= 2
            cnt += 1
    for i, val in t.items():
        if len(a[i]) < k:
            continue
        a[i].sort()
        ans = min(ans, reduce(lambda x, y: x + y, a[i][:k]))
    print(ans)

if __name__ == "__main__":
    main()
