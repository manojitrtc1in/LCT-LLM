import sys
import math
from collections import defaultdict

MOD = int(1e9 + 7)

class SegTree:
    def __init__(self, n, init):
        self.n = n
        self.N = 2 ** math.ceil(math.log2(n))
        self.base = self.N - 1
        self.nodes = [init] * (self.base + self.N)

    def left_of(self, index):
        return -1 if index >= self.base else index * 2 + 1

    def right_of(self, index):
        return -1 if index >= self.base else index * 2 + 2

    def parent_of(self, index):
        return -1 if index == 0 else (index - 1) // 2

    def update_rec(self, s, t, l, r, index, v):
        if s == l and t == r:
            self.nodes[index] = v
        else:
            mid = (l + r) // 2
            index_l = self.left_of(index)
            index_r = self.right_of(index)
            if s < mid < t:
                self.update_rec(s, mid, l, mid, index_l, v)
                self.update_rec(mid, t, mid, r, index_r, v)
            elif s < mid:
                self.update_rec(s, t, l, mid, index_l, v)
            elif mid < t:
                self.update_rec(s, t, mid, r, index_r, v)
            self.nodes[index] = self.nodes[index_l] + self.nodes[index_r]

    def add_rec(self, s, t, l, r, index):
        if s == l and t == r:
            return self.nodes[index]
        else:
            mid = (l + r) // 2
            index_l = self.left_of(index)
            index_r = self.right_of(index)
            v0 = 0
            v1 = 0
            if s < mid < t:
                v0 = self.add_rec(s, mid, l, mid, index_l)
                v1 = self.add_rec(mid, t, mid, r, index_r)
            elif s < mid:
                v0 = self.add_rec(s, t, l, mid, index_l)
            elif mid < t:
                v1 = self.add_rec(s, t, mid, r, index_r)
            return v0 + v1

    def update(self, k, v):
        self.update_rec(k, k + 1, 0, self.N, 0, v)

    def sum(self, s, t):
        return self.add_rec(s, t, 0, self.N, 0)

def lower_binary_search(l, r, v, evalfunc):
    if r - l == 1:
        return l if evalfunc(l, v) else l - 1
    m = (l + r) // 2
    if evalfunc(m, v):
        return lower_binary_search(m, r, v, evalfunc)
    else:
        return lower_binary_search(l, m, v, evalfunc)

class bsargv_t:
    def __init__(self, st, s, sum):
        self.st = st
        self.s = s
        self.sum = sum

def evalfunc(val, v):
    buf = v.st.sum(v.s, val + 1)
    return buf <= v.sum / 2

class modll:
    def __init__(self, init=0):
        self.val = init % MOD
        if self.val < 0:
            self.val += MOD

    def __add__(self, x):
        return modll(self.val + x.val)

    def __sub__(self, x):
        return modll(self.val - x.val)

    def __mul__(self, x):
        return modll(self.val * x.val)

    def __truediv__(self, x):
        return modll(self.val * pow(x.val, MOD - 2, MOD) % MOD)

    def __eq__(self, x):
        return self.val == x.val

    def __ne__(self, x):
        return self.val != x.val

    def __repr__(self):
        return str(self.val)

def make_facts(n):
    facts = [modll(1)]
    for i in range(1, n + 1):
        facts.append(facts[-1] * modll(i))
    return facts

def make_ifacts(n, facts):
    ifacts = [modll(1)]
    for i in range(1, n + 1):
        ifacts.append(ifacts[-1] / modll(i))
    return ifacts

def combination(n, r, facts, ifacts):
    if n >= r >= 0:
        return facts[n] * ifacts[r] * ifacts[n - r]
    return modll(0)

def main():
    input = sys.stdin.read
    data = input().split()
    idx = 0
    n = int(data[idx])
    q = int(data[idx + 1])
    idx += 2
    a = list(map(int, data[idx:idx + n]))
    idx += n

    st = SegTree(n, 0)
    ast = SegTree(n, modll(0))
    lst = SegTree(n, modll(0))
    rst = SegTree(n, modll(0))

    for i in range(n):
        w = int(data[idx])
        st.update(i, w)
        ast.update(i, modll(w) * modll(a[i]))
        lst.update(i, modll(w) * modll(n - 1 - i))
        rst.update(i, modll(w) * modll(i))
        idx += 1

    ans = []
    for _ in range(q):
        x = int(data[idx])
        idx += 1
        if x < 0:
            x += 1
            y = int(data[idx])
            idx += 1
            st.update(-x, y)
            ast.update(-x, modll(y) * modll(a[-x]))
            lst.update(-x, modll(y) * modll(n - 1 - (-x)))
            rst.update(-x, modll(y) * modll(-x))
        else:
            y = int(data[idx])
            idx += 1
            x -= 1
            y -= 1
            if x == y:
                ans.append(modll(0))
            else:
                if y - x == 1:
                    halfid = x
                else:
                    v = bsargv_t(st, x, st.sum(x, y + 1))
                    halfid = lower_binary_search(x + 1, y, v, evalfunc)

                cand0 = st.sum(x, halfid + 1)
                cand1 = st.sum(halfid + 1, y + 1)
                dst = 0
                dstid = 0
                if cand0 <= cand1:
                    dst = a[halfid + 1]
                    dstid = halfid + 1
                else:
                    dst = a[halfid]
                    dstid = halfid

                buf = modll(0)
                buf += modll(dst) * st.sum(x, dstid) - ast.sum(x, dstid) - (lst.sum(x, dstid) - modll(st.sum(x, dstid)) * modll(n - 1 - dstid))
                buf += modll(ast.sum(dstid, y + 1)) - modll(dst) * st.sum(dstid, y + 1) - (rst.sum(dstid, y + 1) - modll(st.sum(dstid, y + 1)) * modll(dstid))
                ans.append(buf)

    for result in ans:
        print(result)

if __name__ == "__main__":
    main()
