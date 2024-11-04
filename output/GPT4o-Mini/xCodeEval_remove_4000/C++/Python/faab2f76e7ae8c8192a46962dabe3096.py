import random
import sys
from collections import deque

class Random:
    def __init__(self):
        self.seed(3731)

    def seed(self, seed_value):
        random.seed(seed_value)

    def getInt(self, up_to):
        return random.randint(0, up_to - 1)

rnd = Random()

class Node:
    def __init__(self, priority, value, original_id):
        self.priority = priority
        self.value = value
        self.originalId = original_id
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
        return l if l else r
    if l.priority > r.priority:
        l.r = merge(l.r, l.r, r)
        return l
    else:
        r.l = merge(l, l, r.l)
        return r

def split(t, key):
    if not t:
        return None, None
    push(t)
    if key < t.value:
        l, t.l = split(t.l, key)
        return l, t
    else:
        t.r, r = split(t.r, key)
        return t, r

root = None
memo = [Node(0, 0, 0) for _ in range(2000000)]
countNodes = 0

def newNode(value, id):
    global countNodes
    p = memo[countNodes]
    p.priority = rnd.getInt(1000000000)
    p.value = value
    p.originalId = id
    p.id = -1
    countNodes += 1
    return p

def solve(in_stream, out_stream):
    n = int(in_stream.readline())
    m = int(in_stream.readline())
    global root
    root = None

    leftIds = set(range(n))

    for i in range(n):
        t = newNode(i, i)
        root = merge(root, root, t)

    for _ in range(m):
        id = int(in_stream.readline()) - 1
        pos = int(in_stream.readline()) - 1

        t1, t2, t3 = None, None, None
        t1, t2 = split(root, pos - 1)
        t2, t3 = split(t2, pos)

        if t2.id != -1:
            if t2.id != id:
                out_stream.write("-1\n")
                return
        else:
            if id not in leftIds:
                out_stream.write("-1\n")
                return
            leftIds.remove(id)
            t2.id = id

        t2.value = 0
        t2.upd = 0
        if t1:
            t1.upd += 1
        root = merge(root, t2, t1)
        root = merge(root, root, t3)

    p = [-1] * n

    for i in range(n):
        t1, root = split(root, i)
        if t1.id != -1:
            p[t1.originalId] = t1.id

    for i in range(n):
        if p[i] == -1:
            p[i] = leftIds.pop()

    out_stream.write(" ".join(str(x + 1) for x in p) + "\n")

if __name__ == "__main__":
    solve(sys.stdin, sys.stdout)
