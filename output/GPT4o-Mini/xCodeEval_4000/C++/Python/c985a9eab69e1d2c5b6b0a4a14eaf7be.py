import sys
import random
from collections import defaultdict

class Item:
    def __init__(self, key):
        self.key = key
        self.prior = random.randint(0, 2**31 - 1)
        self.cnt = 1
        self.l = None
        self.r = None

def update(t):
    if t is None:
        return
    t.cnt = (0 if t.l is None else t.l.cnt) + (0 if t.r is None else t.r.cnt) + 1

def split(t, key):
    if t is None:
        return None, None
    elif key < t.key or (key == t.key and random.randint(0, 1)):
        l, t.l = split(t.l, key)
        r = t
    else:
        t.r, r = split(t.r, key)
        l = t
    update(l)
    update(r)
    return l, r

def wsplit(t, key):
    if t is None:
        return None, None
    elif key < t.key or key == t.key:
        l, t.l = wsplit(t.l, key)
        r = t
    else:
        t.r, r = wsplit(t.r, key)
        l = t
    update(l)
    update(r)
    return l, r

def insert(t, it):
    if t is None:
        t = it
    elif it.prior > t.prior:
        it.l, it.r = split(t, it.key)
        t = it
    else:
        insert(t.l if it.key < t.key or (it.key == t.key and random.randint(0, 1)) else t.r, it)
    update(t)

def merge(t, l, r):
    if l is None or r is None:
        t = l if l else r
    elif l.prior > r.prior:
        merge(l.r, l.r, r)
        t = l
    else:
        merge(r.l, l, r.l)
        t = r
    update(t)

def erase(t, key):
    if t.key == key:
        merge(t, t.l, t.r)
    else:
        erase(t.l if key < t.key else t.r, key)
    update(t)

def ans(a):
    t = None
    total = 0
    for i in a:
        l, r = wsplit(t, i[1])
        total += 0 if r is None else r.cnt
        merge(t, l, r)
        insert(t, Item(i[1]))
    return total

def main():
    input = sys.stdin.read
    data = input().splitlines()
    n, w = map(int, data[0].split())
    b = []
    for i in range(1, n + 1):
        a, v = map(int, data[i].split())
        b.append(((abs(a), abs(v - w)), (abs(a), abs(v + w))))
    
    b.sort(key=lambda x: (x[0], -x[1][1]))
    print(ans(b))

if __name__ == "__main__":
    main()
