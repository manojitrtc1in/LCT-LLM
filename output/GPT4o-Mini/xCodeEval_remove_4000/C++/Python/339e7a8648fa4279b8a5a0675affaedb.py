import sys
from collections import deque
from itertools import islice
from typing import List, Tuple, Optional

class Node:
    def __init__(self):
        self.lp: Optional[Node] = None
        self.rp: Optional[Node] = None
        self.sum = 0
        self.minVal = 0
        self.s = 0
        self.free = 0

    def update(self, tl: int, tr: int):
        assert self.lp or self.rp
        if not self.lp:
            self.sum = self.rp.sum
            self.minVal = self.rp.minVal
            self.s = self.rp.s
            self.free = self.rp.free
            self.free += tl
            return
        if not self.rp:
            self.sum = self.lp.sum
            self.minVal = self.lp.minVal
            self.s = self.lp.s
            self.free = self.lp.free
            self.sum += self.lp.s * tr
            self.minVal = min(self.minVal, self.sum)
            return
        self.sum = self.lp.sum + self.rp.free * self.lp.s + self.rp.sum
        self.minVal = min(self.lp.minVal, self.lp.sum + self.rp.free * self.lp.s + self.rp.minVal)
        self.s = self.rp.s
        self.free = self.lp.free

nodes = [Node() for _ in range(101010 * 32)]
lastn = 0
root: Optional[Node] = None

def update(cur: Optional[Node], l: int, r: int, pos: int, val: int):
    global lastn
    if cur is None:
        cur = nodes[lastn]
        lastn += 1
    if l == r:
        cur.s = val
        cur.free = 0
        cur.minVal = min(0, cur.s)
        cur.sum = val
    else:
        m = (l + r) // 2
        if pos <= m:
            update(cur.lp, l, m, pos, val)
        else:
            update(cur.rp, m + 1, r, pos, val)
        cur.update(m - l + 1, r - m)

def del_node(cur: Optional[Node], l: int, r: int, pos: int):
    if l == r:
        cur = None
    else:
        m = (l + r) // 2
        if pos <= m:
            del_node(cur.lp, l, m, pos)
        else:
            del_node(cur.rp, m + 1, r, pos)
        if not cur.lp and not cur.rp:
            cur = None
            return
        cur.update(m - l + 1, r - m)

ans = float('inf')

def get_ans(cur: Optional[Node], l: int, r: int, x: int, y: int, v: List[int], s: List[int]):
    if y < l or x > r:
        return
    if not cur or l == r:
        if cur:
            s[0] = cur.s
        tot = s[0] * (y - x + 1)
        if tot + v[0] > 0:
            v[0] += tot
            return
        global ans
        ans = x + v[0] * 1.0 / -s[0]
        v[0] = 0
        return
    m = (l + r) // 2
    if x <= l and r <= y:
        minVal = cur.minVal + cur.free * s[0]
        if minVal + v[0] > 0:
            v[0] += cur.sum + cur.free * s[0]
            s[0] = cur.s
            return
        else:
            get_ans(cur.lp, l, m, x, m, v, s)
            if not v[0]:
                return
            get_ans(cur.rp, m + 1, r, m + 1, y, v, s)
            return
    if x <= m:
        get_ans(cur.lp, l, m, x, min(y, m), v, s)
        if not v[0]:
            return
    get_ans(cur.rp, m + 1, r, max(x, m + 1), y, v, s)

def solve():
    q = int(input())
    for _ in range(q):
        t = int(input())
        if t == 1:
            w = int(input())
            s = int(input())
            update(root, 0, float('inf'), w, s)
        elif t == 2:
            w = int(input())
            del_node(root, 0, float('inf'), w)
        else:
            l = int(input())
            r = int(input())
            v = [int(input())]
            global ans
            ans = float('inf')
            if not v[0]:
                ans = l
            if l < r and v[0]:
                s = [0]
                get_ans(root, 0, float('inf'), l, r - 1, v, s)
            if v[0]:
                print(-1)
            else:
                print(f"{ans:.8f}")

if __name__ == "__main__":
    input = sys.stdin.read
    data = input().splitlines()
    sys.stdin = iter(data)
    solve()
