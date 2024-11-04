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

def upd(t):
    if t is None:
        return
    t.cnt = (t.l.cnt if t.l else 0) + (t.r.cnt if t.r else 0) + 1

def split(t, key):
    if not t:
        return None, None
    elif key < t.key or (key == t.key and random.randint(0, 1)):
        l, t.l = split(t.l, key)
        r = t
    else:
        t.r, r = split(t.r, key)
        l = t
    upd(l)
    upd(r)
    return l, r

def wsplit(t, key):
    if not t:
        return None, None
    elif key < t.key or key == t.key:
        l, t.l = wsplit(t.l, key)
        r = t
    else:
        t.r, r = wsplit(t.r, key)
        l = t
    upd(l)
    upd(r)
    return l, r

def insert(t, it):
    if not t:
        t = it
    elif it.prior > t.prior:
        it.l, it.r = split(t, it.key)
        t = it
    else:
        insert(t.l if it.key < t.key or (it.key == t.key and random.randint(0, 1)) else t.r, it)
    upd(t)

def merge(l, r):
    if not l or not r:
        return l if l else r
    elif l.prior > r.prior:
        l.r = merge(l.r, r)
        return l
    else:
        r.l = merge(l, r.l)
        return r

def erase(t, key):
    if t.key == key:
        return merge(t.l, t.r)
    else:
        if key < t.key:
            t.l = erase(t.l, key)
        else:
            t.r = erase(t.r, key)
    upd(t)
    return t

def ans(a):
    t = None
    total = 0
    for i in a:
        l, r = wsplit(t, i[1])
        total += r.cnt if r else 0
        t = merge(l, r)
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
