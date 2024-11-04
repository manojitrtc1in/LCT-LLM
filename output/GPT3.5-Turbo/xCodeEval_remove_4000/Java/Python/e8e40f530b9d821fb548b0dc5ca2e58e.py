import sys
from collections import defaultdict
from typing import List, Tuple

class F:
    def __init__(self):
        self.n = 0
        self.m = 0
        self.arr = []
        self.required = 0
        self.typeDays = defaultdict(set)

    def solver(self):
        self.n, self.m = map(int, input().split())
        self.arr = list(map(int, input().split()))
        self.required = sum(self.arr)
        for _ in range(self.m):
            d, typ = map(int, input().split())
            if self.arr[typ - 1] <= 0:
                continue
            self.typeDays[typ].add(d)

        lo = self.required
        hi = 2 * self.required
        valid = hi
        while lo <= hi:
            mid = (lo + hi) // 2
            if self.is_enough(mid):
                valid = mid
                hi = mid - 1
            else:
                lo = mid + 1
        print(valid)

    def is_enough(self, day):
        total_coin = day
        req = self.required
        ddays = [0] * (day + 1)
        for typ in self.typeDays.keys():
            last_day = max(filter(lambda x: x <= day, self.typeDays[typ]), default=None)
            if last_day is None:
                continue
            ddays[last_day] += self.arr[typ - 1]

        removed = 0
        for i in range(1, day + 1):
            coins = i - removed
            to_remove = min(coins, ddays[i])
            removed += to_remove
            total_coin -= to_remove
            req -= to_remove

        return req * 2 <= total_coin


def main():
    f = F()
    f.solver()


if __name__ == "__main__":
    main()
