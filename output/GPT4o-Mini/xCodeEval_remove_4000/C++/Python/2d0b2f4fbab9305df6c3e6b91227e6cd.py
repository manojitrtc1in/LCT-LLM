from collections import defaultdict
from itertools import count
import sys
import math
import random

class ScopeTimer:
    def __init__(self, msg=""):
        self.tic = self.current_time()
        self.msg = msg

    def __del__(self):
        toc = self.current_time()
        dt = (toc - self.tic) * 1000
        mil = dt % 1000
        sec = (dt // 1000) % 60
        min = (dt // 60000) % 60
        hrs = (dt // 3600000)

        print(f'\n{self.msg}\n\telapsed time: ', end='')
        if hrs: print(f"{hrs} hrs, ", end='')
        if min: print(f"{min} min, ", end='')
        if sec: print(f"{sec} sec, ", end='')
        print(f"{mil} mil-sec")

    @staticmethod
    def current_time():
        return int(round(time.time() * 1000))

def refill(k, left, right):
    def comp(i, j):
        return right[i][1] - left[i][0] < right[j][1] - left[j][0]

    idx = list(range(len(left)))
    heap = sorted(idx, key=comp)
    val = 0

    while heap and k > 0:
        i = heap.pop(0)

        if left[i][0] < right[i][1]:
            w = min(k, left[i][2])
            k -= w
            val += w * (right[i][1] - left[i][0])

    return val

def a176():
    n, m, k = map(int, input().split())
    a = [tuple(map(int, input().split())) for _ in range(n)]

    val = 0
    for i in range(n):
        for j in range(n):
            if i != j:
                val = max(val, refill(k, a[i], a[j]))

    return val

def main():
    print(a176())

if __name__ == "__main__":
    main()
