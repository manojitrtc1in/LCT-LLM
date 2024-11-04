import sys
from collections import defaultdict
from sortedcontainers import SortedSet

class F:
    def __init__(self):
        self.n = 0
        self.m = 0
        self.arr = []
        self.required = 0
        self.typeDays = defaultdict(SortedSet)

    def solver(self):
        self.n, self.m = map(int, sys.stdin.readline().split())
        self.arr = list(map(int, sys.stdin.readline().split()))
        self.required = sum(self.arr)

        for _ in range(self.m):
            d, typ = map(int, sys.stdin.readline().split())
            if self.arr[typ - 1] <= 0:
                continue
            self.typeDays[typ].add(d)

        lo = self.required
        hi = 2 * self.required
        valid = hi
        while lo <= hi:
            mid = (lo + hi) // 2
            if self.isEnough(mid):
                valid = mid
                hi = mid - 1
            else:
                lo = mid + 1
        print(valid)

    def isEnough(self, day):
        totalCoin = day
        req = self.required

        ddays = [0] * (day + 1)
        for typ in self.typeDays:
            lastDay = self.typeDays[typ].bisect_right(day) - 1
            if lastDay >= 0:
                ddays[self.typeDays[typ][lastDay]] += self.arr[typ - 1]

        removed = 0
        for i in range(1, day + 1):
            coins = i - removed
            toRemove = min(coins, ddays[i])
            removed += toRemove
            totalCoin -= toRemove
            req -= toRemove

        return req * 2 <= totalCoin

if __name__ == "__main__":
    F().solver()
