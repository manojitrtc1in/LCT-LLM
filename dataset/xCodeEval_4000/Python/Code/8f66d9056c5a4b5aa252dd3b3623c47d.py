from itertools import accumulate as ac
from collections import Counter as cc
from bisect import bisect_left as bsl
from bisect import bisect as bs
from math import factorial
from collections import OrderedDict as odict
from collections import defaultdict as dfd
import itertools
from statistics import mean
from math import ceil, sqrt, log, gcd
import math
import os
import sys
from io import BytesIO, IOBase
import random
import copy
import time
from itertools import islice
from functools import lru_cache




BUFSIZE = 8192


























































def lcm(xnum1, xnum2): return (xnum1*xnum2//gcd(xnum1, xnum2))
def intinput(): return int(input())
def strinputlist(): return input().split()
def intinputiter(): return map(int, input().split())
def intinputlist(): return list(intinputiter())
def intinputset(): return set(intinputiter())
















































































































































































































































































































n = int(input())
for _ in range(n):
    n, k = list(map(int, input().split()))
    mountains = list(map(int, input().split()))
    for i in range(k):
        ans = -1
        for j in range(n - 1):
            if mountains[j] < mountains[j + 1]:
                ans = j
                mountains[j] += 1
                break
        if ans == -1:
            break
    print(ans if ans == -1 else ans+1)
