import sys
from collections import defaultdict
import math

class D:
    def __init__(self):
        self.k = 0

    def solver(self):
        n = int(input())
        self.k = int(input())
        arr = list(map(int, input().split()))
        arr.sort()
        counts = defaultdict(lambda: Count())
        counts[0] = Count()

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

        ans = float('inf')
        for count in counts.values():
            if count.count >= self.k:
                ans = min(ans, count.cost)

        print(ans)

class Count:
    def __init__(self):
        self.count = 0
        self.cost = 0

    def increment(self, cost):
        if self.count >= D.k:
            return
        self.cost += cost
        self.count += 1

    def __str__(self):
        return f"({self.count}, {self.cost})"

if __name__ == "__main__":
    D().solver()
