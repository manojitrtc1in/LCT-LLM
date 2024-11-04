import math
from collections import defaultdict

MOD = 1000000007
MODL = 1000000000000000003
eps = 1e-8

class Point:
    def __init__(self, x=0.0, y=0.0):
        self.x = x
        self.y = y

    def __sub__(self, other):
        return Point(self.x - other.x, self.y - other.y)

    def __mul__(self, other):
        return self.x * other.x + self.y * other.y

    def cross(self, p, q):
        return (p - self) ^ (q - self)

    def dist(self, other):
        return math.sqrt((self - other) * (self - other))

class Segment:
    def __init__(self, p, q):
        self.p = p
        self.q = q

    def length(self):
        return self.p.dist(self.q)

    def contain(self, pnt, ignore_endpoint=0):
        if ignore_endpoint:
            return (self.p - pnt).cross(self.q - pnt) == 0 and \
                   (pnt.x - self.p.x) * (pnt.x - self.q.x) < 0 and \
                   (pnt.y - self.p.y) * (pnt.y - self.q.y) < 0
        else:
            return (self.p - pnt).cross(self.q - pnt) == 0 and \
                   (pnt.x - self.p.x) * (pnt.x - self.q.x) <= 0 and \
                   (pnt.y - self.p.y) * (pnt.y - self.q.y) <= 0

class Id13:
    def __init__(self):
        self.foo = defaultdict(int)

    def clear(self):
        self.foo.clear()

    def put(self, key, val=1):
        if val == 0:
            return
        self.foo[key] += val

    def pop(self, key, val=float('inf')):
        res = 0
        if key in self.foo:
            if self.foo[key] > val:
                res = val
                self.foo[key] -= val
            else:
                res = self.foo[key]
                del self.foo[key]
        return res

def process(from_val):
    global seq, sup
    seq = _seq[:]
    sup = _sup[:]
    if from_val + from_val < seq[0]:
        return 1
    open_map.clear()
    close_map.clear()
    open_map.put(0, from_val - (seq[0] - from_val))
    close_map.put(0, seq[0] - from_val)
    
    for i in range(1, 45):
        ext = open_map.pop(i - 1, seq[i])
        seq[i] -= ext
        open_map.put(i, ext)
        ext = close_map.pop(i - 1, seq[i])
        sup[i] += seq[i] - ext
        close_map.put(i, ext)
        cls = open_map.pop(i, sup[i])
        sup[i + 1] += sup[i] - cls
        close_map.put(i, cls)
    
    if sup[45] != 0:
        return 1
    return 0

def find(lef, rig):
    while lef <= rig:
        mid = (lef + rig) // 2
        if not process(mid):
            if mid == lef or process(mid - 1):
                return mid
            rig = mid - 1
        else:
            lef = mid + 1
    return -1

open_map = Id13()
close_map = Id13()
n = 0
a = [0] * 110000
_seq = [0] * 50
_sup = [0] * 50
seq = [0] * 50
sup = [0] * 50

while True:
    try:
        n = int(input())
        for i in range(n):
            a[i] = int(input())
        for i in range(50):
            _seq[i] = 0
            _sup[i] = 0
        cur = 0
        for i in range(n):
            while a[i] >= (1 << (cur + 1)):
                cur += 1
            if a[i] == (1 << cur):
                _seq[cur] += 1
            else:
                _sup[cur] += 1
        if process(_seq[0]):
            print("-1")
        else:
            hig = _seq[0]
            low = find(1, hig)
            for i in range(low, hig + 1):
                if i != low:
                    print(" ", end="")
                print(i, end="")
            print()
    except EOFError:
        break
