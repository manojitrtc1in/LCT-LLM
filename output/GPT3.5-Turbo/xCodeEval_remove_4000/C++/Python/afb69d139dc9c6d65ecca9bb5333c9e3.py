import random
import sys

class Treap:
    def __init__(self, t, val, speed):
        self.left = None
        self.right = None
        self.t = t
        self.y = random.randint(0, sys.maxsize)
        self.prefix_sum = val
        self.speed = speed
        self.push = 0
        self.min_prefix_sum_in_subtree = val

def vertex_add(a, push):
    a.prefix_sum += push
    a.min_prefix_sum_in_subtree += push
    a.push += push

def push(a):
    push = a.push
    if not push:
        return
    if a.left:
        vertex_add(a.left, push)
    if a.right:
        vertex_add(a.right, push)
    a.push = 0

INF = 10 ** 18

def smin(a):
    return a.min_prefix_sum_in_subtree if a else INF

def recalc(a):
    a.min_prefix_sum_in_subtree = min(smin(a.left), smin(a.right), a.prefix_sum)

def merge(a, b):
    if not a:
        return b
    if not b:
        return a
    if a.y < b.y:
        push(a)
        a.right = merge(a.right, b)
        recalc(a)
        return a
    else:
        push(b)
        b.left = merge(a, b.left)
        recalc(b)
        return b

def split(a, k):
    if not a:
        return (None, None)
    push(a)
    if a.t < k:
        l, r = split(a.right, k)
        a.right = l
        recalc(a)
        return (a, r)
    else:
        l, r = split(a.left, k)
        a.left = r
        recalc(a)
        return (l, a)

def id12(a):
    push(a)
    if not a.left:
        return a
    return id12(a.left)

def id7(a):
    push(a)
    if not a.right:
        return a
    return id7(a.right)

def id2(a, v):
    push(a)
    if smin(a.left) <= v:
        return id2(a.left, v)
    if a.prefix_sum <= v:
        return a
    return id2(a.right, v)

def print_tree(a):
    if not a:
        return
    print_tree(a.left)
    print(a.t, end=' ')
    print_tree(a.right)

def main():
    root = Treap(0, 0, 0)
    root = merge(root, Treap(2 * 10 ** 9, 0, 0))
    q = readInt()
    for _ in range(q):
        type = readInt()
        if type == 1:
            t = readInt()
            s = readInt()
            l, r = split(root, t)
            vr = id12(r)
            vl = id7(l)
            psum = vl.prefix_sum + (t - vl.t) * vl.speed
            id5 = psum + (vr.t - t) * s
            vertex_add(r, id5 - vr.prefix_sum)
            root = merge(l, merge(Treap(t, psum, s), r))
        elif type == 2:
            t = readInt()
            l, tr = split(root, t)
            y, r = split(tr, t + 1)
            vl = id7(l)
            vr = id12(r)
            id5 = vl.prefix_sum + (vr.t - vl.t) * vl.speed
            vertex_add(r, id5 - vr.prefix_sum)
            root = merge(l, r)
        else:
            L = readInt()
            R = readInt()
            v = readInt()
            if v == 0:
                print(L)
                continue
            l, yr = split(root, L)
            y, r = split(yr, R + 1)
            if not y:
                print(-1)
            else:
                vl = id12(y)
                vr = id7(y)
                id13 = vl.prefix_sum - v
                if y.min_prefix_sum_in_subtree > id13:
                    id5 = vr.prefix_sum + (R - vr.t) * vr.speed
                    if id5 > id13:
                        print(-1)
                    else:
                        print(vr.t + (id13 - vr.prefix_sum) / vr.speed)
                else:
                    h = id2(y, id13)
                    yl, yr = split(y, h.t)
                    vyl = id7(yl)
                    print(vyl.t + (id13 - vyl.prefix_sum) / vyl.speed)
                    y = merge(yl, yr)
            root = merge(l, merge(y, r))

if __name__ == '__main__':
    main()
