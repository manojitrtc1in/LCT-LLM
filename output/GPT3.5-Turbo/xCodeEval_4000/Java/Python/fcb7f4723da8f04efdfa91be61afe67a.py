import sys
from typing import List, Tuple, Dict
from collections import defaultdict

class D:
    def __init__(self):
        self.k = 0

    def solver(self) -> None:
        n = int(input())
        self.k = int(input())
        arr = list(map(int, input().split()))
        arr.sort()
        counts = defaultdict(Count)
        counts[0] = Count()
        for number in arr:
            num = number
            cost = 0
            while num > 0:
                if num not in counts:
                    counts[num] = Count()
                counts[num].increment(cost)
                num = num // 2
                cost += 1
            counts[0].increment(cost)
        ans = sys.maxsize
        for count in counts.values():
            if count.count >= self.k:
                ans = min(ans, count.cost)
        print(ans)

class Count:
    def __init__(self):
        self.count = 0
        self.cost = 0

    def increment(self, cost: int) -> None:
        if self.count >= self.k:
            return
        self.cost += cost
        self.count += 1

def main() -> None:
    d = D()
    d.solver()

if __name__ == "__main__":
    main()
