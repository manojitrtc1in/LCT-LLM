import sys
import math
import random
import itertools
import functools
import operator
import collections
import heapq
import bisect
import string
import re
import time
import datetime
import fractions
import decimal
import array
import copy
import inspect
import queue
import typing
import io
import os
import sys
import random
import math
import itertools
import functools
import operator
import collections
import heapq
import bisect
import string
import re
import time
import datetime
import fractions
import decimal
import array
import copy
import inspect
import queue
import typing
import io
import os

def get_gain(xs, l, r):
    len = len(xs) - l - r
    return xs[l + len // 2] if len % 2 else 0

def c388():
    n = int(input())
    xs = []
    for _ in range(n):
        row = list(map(int, input().split()))
        xs.append(row)

    k = sum(len(row) for row in xs)
    acc = sum(sum(row) for row in xs)

    left = [0] * n
    right = [0] * n

    left_acc = 0

    for j in range(k):
        imax = 0
        while len(xs[imax]) == left[imax] + right[imax]:
            imax += 1

        val = get_gain(xs[imax], left[imax], right[imax])

        for i in range(imax + 1, n):
            if left[i] + right[i] < len(xs[i]):
                g = get_gain(xs[i], left[i], right[i])
                if val < g:
                    val = g
                    imax = i

        if j & 1:
            right[imax] += 1
        else:
            left_acc += xs[imax][left[imax]]
            left[imax] += 1

    print(left_acc, acc - left_acc)

c388()
