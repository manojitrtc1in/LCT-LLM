import sys
from typing import List, Tuple

def solution(n: int, m: int, intervals: List[Tuple[int, int]]) -> int:
    cnt = [0] * (m + 1)
    for l, r in intervals:
        cnt[l] += 1
        cnt[r + 1] -= 1

    for i in range(1, m + 1):
        cnt[i] += cnt[i - 1]

    l = [0] * (m + 1)
    r = [0] * (m + 1)
    fw_l = [0] * (100001)
    fw_r = [0] * (100001)

    for i in range(1, m + 1):
        l[i] = fw_l[cnt[i]] + 1
        fw_l[cnt[i]] = l[i]

    for i in range(m, 0, -1):
        r[i] = fw_r[cnt[i]] + 1
        fw_r[cnt[i]] = r[i]

    ans = 0
    for i in range(1, m + 1):
        ans = max(ans, l[i] + r[i] - 1)

    return ans

def main():
    n, m = map(int, input().split())
    intervals = []
    for _ in range(n):
        l, r = map(int, input().split())
        intervals.append((l, r))
    
    ans = solution(n, m, intervals)
    print(ans)

if __name__ == "__main__":
    main()
