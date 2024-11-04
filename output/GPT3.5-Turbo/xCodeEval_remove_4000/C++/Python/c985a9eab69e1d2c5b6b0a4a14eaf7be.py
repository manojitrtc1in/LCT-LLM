import random

class Item:
    def __init__(self, key):
        self.key = key
        self.prior = random.randint(0, 10**9)
        self.cnt = 1
        self.l = None
        self.r = None

def upd(t):
    if t is None:
        return
    t.cnt = (t.l.cnt if t.l else 0) + (t.r.cnt if t.r else 0) + 1

def split(t, key):
    if t is None:
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
    if t is None:
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
    if t is None:
        t = it
    elif it.prior > t.prior:
        l, r = split(t, it.key)
        it.l = l
        it.r = r
        t = it
    else:
        insert(t.l if it.key < t.key or (it.key == t.key and random.randint(0, 1)) else t.r, it)
    upd(t)

def merge(t, l, r):
    if not l or not r:
        t = l if l else r
    elif l.prior > r.prior:
        merge(l.r, l.r, r)
        t = l
    else:
        merge(r.l, l, r.l)
        t = r
    upd(t)

def erase(t, key):
    if t.key == key:
        merge(t, t.l, t.r)
    else:
        erase(t.l if key < t.key else t.r, key)
    upd(t)

def ans(a):
    t = None
    ans = 0
    for i in a:
        l, r = wsplit(t, i[1])
        ans += r.cnt if r else 0
        merge(t, l, r)
        insert(t, Item(i[1]))
    return ans

n, w = map(int, input().split())
b = []
for _ in range(n):
    a, v = map(int, input().split())
    b.append([(abs(a), abs(v - w)), (abs(a), abs(v + w))])
b.sort(key=lambda x: (x[0], -x[1]))
print(ans(b))
