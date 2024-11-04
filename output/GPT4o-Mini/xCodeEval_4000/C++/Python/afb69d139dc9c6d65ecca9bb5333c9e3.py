import random
import sys
from collections import deque
from typing import List, Tuple, Optional

VERSION = "0.1.4"

class Treap:
    def __init__(self, t: int, val: int, speed: int):
        self.left: Optional[Treap] = None
        self.right: Optional[Treap] = None
        self.t = t
        self.y = random.randint(0, 2**31 - 1)
        self.prefix_sum = val
        self.speed = speed
        self.push = 0
        self.min_prefix_sum_in_subtree = val

def vertex_add(a: Treap, push: int):
    a.prefix_sum += push
    a.min_prefix_sum_in_subtree += push
    a.push += push

def push(a: Treap):
    if not a or a.push == 0:
        return
    if a.left:
        vertex_add(a.left, a.push)
    if a.right:
        vertex_add(a.right, a.push)
    a.push = 0

INF = 10**18

def smin(a: Optional[Treap]) -> int:
    return a.min_prefix_sum_in_subtree if a else INF

def recalc(a: Treap):
    a.min_prefix_sum_in_subtree = min(smin(a.left), smin(a.right), a.prefix_sum)

def merge(a: Optional[Treap], b: Optional[Treap]) -> Optional[Treap]:
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

def split(a: Optional[Treap], k: int) -> Tuple[Optional[Treap], Optional[Treap]]:
    if not a:
        return a, a
    push(a)
    if a.t < k:
        l, r = split(a.right, k)
        a.right = l
        recalc(a)
        return a, r
    else:
        l, r = split(a.left, k)
        a.left = r
        recalc(a)
        return l, a

def get_least(a: Optional[Treap]) -> Optional[Treap]:
    push(a)
    if not a.left:
        return a
    return get_least(a.left)

def get_greatest(a: Optional[Treap]) -> Optional[Treap]:
    push(a)
    if not a.right:
        return a
    return get_greatest(a.right)

def find_first_less(a: Optional[Treap], v: int) -> Optional[Treap]:
    push(a)
    if smin(a.left) <= v:
        return find_first_less(a.left, v)
    if a.prefix_sum <= v:
        return a
    return find_first_less(a.right, v)

def read_int() -> int:
    return int(sys.stdin.readline().strip())

def main():
    random.seed()
    root = Treap(0, 0, 0)
    root = merge(root, Treap(2 * 10**9, 0, 0))
    q = read_int()
    
    for _ in range(q):
        type_query = read_int()
        if type_query == 1:
            t = read_int()
            s = read_int()
            l, r = split(root, t)
            vr = get_least(r)
            vl = get_greatest(l)
            psum = vl.prefix_sum + (t - vl.t) * vl.speed
            new_psum = psum + (vr.t - t) * s
            vertex_add(r, new_psum - vr.prefix_sum)
            root = merge(l, merge(Treap(t, psum, s), r))
        elif type_query == 2:
            t = read_int()
            l, tr = split(root, t)
            y, r = split(tr, t + 1)
            vl = get_greatest(l)
            vr = get_least(r)
            new_psum = vl.prefix_sum + (vr.t - vl.t) * vl.speed
            vertex_add(r, new_psum - vr.prefix_sum)
            root = merge(l, r)
        else:
            L = read_int()
            R = read_int()
            v = read_int()
            if v == 0:
                print(L)
                continue
            l, yr = split(root, L)
            y, r = split(yr, R + 1)
            if not y:
                print(-1)
            else:
                vl = get_least(y)
                vr = get_greatest(y)
                searching_v = vl.prefix_sum - v
                if y.min_prefix_sum_in_subtree > searching_v:
                    new_psum = vr.prefix_sum + (R - vr.t) * vr.speed
                    if new_psum > searching_v:
                        print("-1")
                    else:
                        print(vr.t + (searching_v - vr.prefix_sum) / vr.speed)
                else:
                    h = find_first_less(y, searching_v)
                    yl, yr = split(y, h.t)
                    vyl = get_greatest(yl)
                    print(vyl.t + (searching_v - vyl.prefix_sum) / vyl.speed)
                    y = merge(yl, yr)
            root = merge(l, merge(y, r))

if __name__ == "__main__":
    main()
