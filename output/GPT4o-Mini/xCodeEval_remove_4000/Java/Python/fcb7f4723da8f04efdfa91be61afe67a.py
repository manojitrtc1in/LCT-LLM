import sys
from collections import defaultdict
import math

class Count:
    def __init__(self):
        self.count = 0
        self.cost = 0

    def increment(self, cost):
        if self.count >= k:
            return
        self.cost += cost
        self.count += 1

    def __str__(self):
        return f"({self.count}, {self.cost})"

def solver():
    n = in_int()
    global k
    k = in_int()
    arr = in_id12(n)
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
            num //= 2
            cost += 1
        counts[0].increment(cost)

    ans = float('inf')
    for count in counts.values():
        if count.count >= k:
            ans = min(ans, count.cost)

    out_print(ans)

def in_int():
    return int(sys.stdin.readline().strip())

def in_id12(n):
    return list(map(int, sys.stdin.readline().strip().split()))

class FastWriter:
    def __init__(self):
        self.out = []

    def p(self, object):
        self.out.append(str(object))
        return self

    def pp(self, *args):
        self.out.append(" ".join(map(str, args)) + "\n")
        return self

    def println(self, object):
        self.out.append(str(object) + "\n")
        return self

    def close(self):
        sys.stdout.write("".join(self.out))

out = FastWriter()

if __name__ == "__main__":
    solver()
    out.close()
