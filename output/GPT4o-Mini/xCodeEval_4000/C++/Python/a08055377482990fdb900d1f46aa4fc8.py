import sys
from collections import deque
from itertools import groupby

MAGIC = 20000000

t = 0
la = 0
ma = 0
at = 0
to = [0] * 1000005
p = [0] * 1000005
pp = [([], 0)] * 1000005
s = set()
m = [{} for _ in range(300)]
x = [[0] * 289 for _ in range(289)]
