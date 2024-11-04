import random

class Random:
    def __init__(self):
        random.seed(3731)

    def getInt(self, up_to):
        return random.randint(0, up_to - 1)

class Node:
    def __init__(self, value, id):
        self.priority = random.randint(0, 1000000000)
        self.value = value
        self.originalId = id
        self.id = -1
        self.upd = 0
        self.l = None
        self.r = None

def push(it):
    if it and it.upd:
        it.value += it.upd
        if it.l:
            it.l.upd += it.upd
        if it.r:
            it.r.upd += it.upd
        it.upd = 0

def merge(t, l, r):
    push(l)
    push(r)
    if not l or not r:
        t = l if l else r
    elif l.priority > r.priority:
        merge(l.r, l.r, r)
        t = l
    else:
        merge(r.l, l, r.l)
        t = r

def split(t, key, l, r):
    if not t:
        l = r = None
        return
    push(t)
    if key < t.value:
        split(t.l, key, l, t.l)
        r = t
    else:
        split(t.r, key, t.r, r)
        l = t

def solve():
    n, m = map(int, input().split())
    root = None
    memo = []
    countNodes = 0

    for i in range(n):
        t = Node(i, i)
        merge(root, root, t)
        memo.append(t)

    leftIds = set(range(n))

    for i in range(m):
        id, pos = map(int, input().split())
        id -= 1
        pos -= 1

        t1, t2, t3 = None, None, None
        split(root, pos - 1, t1, t2)
        split(t2, pos, t2, t3)

        if t2.id != -1:
            if t2.id != id:
                print("-1")
                return
        else:
            if id not in leftIds:
                print("-1")
                return
            leftIds.remove(id)
            t2.id = id

        t2.value = 0
        t2.upd = 0
        if t1:
            t1.upd += 1
        merge(root, t2, t1)
        merge(root, root, t3)

    p = [-1] * n

    for i in range(n):
        t1, root = root, None
        split(t1, i, t1, root)
        if t1.id != -1:
            p[t1.originalId] = t1.id

    for i in range(n):
        if p[i] == -1:
            p[i] = leftIds.pop()

    print(" ".join(str(x + 1) for x in p))

rnd = Random()
solve()
