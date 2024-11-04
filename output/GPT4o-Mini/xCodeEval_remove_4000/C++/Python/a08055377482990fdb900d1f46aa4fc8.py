from collections import deque
from itertools import groupby

t = int(input())
la, ma, at = 0, 0, 0
to = [0] * 1000005
p = [0] * 1000005
pp = [([], 0)] * 1000005
s = set()
m = [{} for _ in range(300)]
x = [[0] * 289 for _ in range(289)]
