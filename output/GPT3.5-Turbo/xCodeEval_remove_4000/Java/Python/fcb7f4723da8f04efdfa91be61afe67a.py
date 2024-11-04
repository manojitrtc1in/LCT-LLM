import sys
from typing import List, Tuple, Dict

class Count:
    def __init__(self):
        self.count = 0
        self.cost = 0

    def increment(self, cost: int) -> None:
        if self.count >= k:
            return
        self.cost += cost
        self.count += 1

def solver() -> None:
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    counts: Dict[int, Count] = {0: Count()}
    for number in arr:
        num = number
        cost = 0
        while num > 0:
            if num not in counts:
                counts[num] = Count()
            counts[num].increment(cost)
            num //= 2
            cost += 1
        counts[0].increment(cost)
    ans = sys.maxsize
    for count in counts.values():
        if count.count >= k:
            ans = min(ans, count.cost)
    print(ans)

if __name__ == '__main__':
    solver()
