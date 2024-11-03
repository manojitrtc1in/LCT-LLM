import random
import math
import sys
import heapq
from collections import deque
from itertools import permutations, combinations
from functools import reduce
from operator import add, mul, sub, truediv, floordiv, mod, pow
from fractions import Fraction
from decimal import Decimal, getcontext
from copy import deepcopy
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapify
from queue import Queue, PriorityQueue
from math import gcd, factorial, ceil, floor, sqrt, log2, log10, log, pi, sin, cos, tan, asin, acos, atan, atan2
from string import ascii_lowercase, ascii_uppercase, digits
from datetime import datetime
from typing import List, Tuple, Dict, Set, Union


def refill(k: int, left: List[Tuple[int, int, int]], right: List[Tuple[int, int, int]]) -> int:
    def comp(i: int, j: int) -> bool:
        return right[i][1] - left[i][0] < right[j][1] - left[j][0]

    idx = list(range(len(left)))
    heapq.heapify(idx)
    val = 0

    while idx and k > 0:
        i = heapq.heappop(idx)

        if left[i][0] < right[i][1]:
            w = min(k, left[i][2])
            k -= w
            val += w * (right[i][1] - left[i][0])

    return val


def a176() -> int:
    n, m, k = map(int, input().split())
    a = [[0] * m for _ in range(n)]

    for i in range(n):
        a[i] = list(map(int, input().split()))

    val = 0
    for i in range(n):
        for j in range(n):
            if i != j:
                val = max(val, refill(k, a[i], a[j]))

    return val


if __name__ == "__main__":
    print(a176())
