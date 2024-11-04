import math

class SegTree:
    def __init__(self, n, init):
        self.n = n
        self.N = 2 ** math.ceil(math.log2(n))
        self.base = self.N - 1
        self.nodes = [init] * (self.base + self.N)
    
    def left_of(self, index):
        if index >= self.base:
            return -1
        else:
            return index * 2 + 1
    
    def right_of(self, index):
        if index >= self.base:
            return -1
        else:
            return index * 2 + 2
    
    def parent_of(self, index):
        if index == 0:
            return -1
        else:
            return (index - 1) >> 1
    
    def update_rec(self, s, t, l, r, index, v):
        if s == l and t == r:
            self.nodes[index] = v
        else:
            mid = (l + r) // 2
            index_l = self.left_of(index)
            index_r = self.right_of(index)
            if s < mid and mid < t:
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
            if s < mid and mid < t:
                v0 = self.add_rec(s, mid, l, mid, index_l)
                v1 = self.add_rec(mid, t, mid, r, index_r)
            elif s < mid:
                v0 = self.add_rec(s, t, l, mid, index_l)
            elif mid < t:
                v1 = self.add_rec(s, t, mid, r, index_r)
            return v0 + v1

def lower_binary_search(l, r, v, evalfunc):
    if r - l == 1:
        if evalfunc(l, v):
            return l
        else:
            return l - 1
    m = (l + r) // 2
    if evalfunc(m, v):
        return lower_binary_search(m, r, v, evalfunc)
    else:
        return lower_binary_search(l, m, v, evalfunc)

class modll:
    MOD = int(1e9 + 7)
    
    def __init__(self, init=0):
        self.val = self.modify(init)
    
    def modify(self, x):
        ret = x % self.MOD
        if ret < 0:
            ret += self.MOD
        return ret
    
    def inv(self, x):
        if x == 0:
            return 1 / x
        elif x == 1:
            return 1
        else:
            return self.modify(self.inv(self.MOD % x) * self.modify(-self.MOD / x))
    
    def __add__(self, x):
        return self.modify(self.val + x.val)
    
    def __sub__(self, x):
        return self.modify(self.val - x.val)
    
    def __mul__(self, x):
        return self.modify(self.val * x.val)
    
    def __truediv__(self, x):
        return self.modify(self.val * self.inv(x.val))
    
    def __iadd__(self, x):
        self.val = self.modify(self.val + x.val)
        return self
    
    def __isub__(self, x):
        self.val = self.modify(self.val - x.val)
        return self
    
    def __imul__(self, x):
        self.val = self.modify(self.val * x.val)
        return self
    
    def __itruediv__(self, x):
        self.val = self.modify(self.val * self.inv(x.val))
        return self
    
    def __eq__(self, x):
        return self.val == x.val
    
    def __ne__(self, x):
        return self.val != x.val
    
    def __str__(self):
        return str(self.val)
    
    def get_val(self):
        return self.val

def pow(n, p):
    ret = modll()
    if p == 0:
        ret = 1
    elif p == 1:
        ret = n
    else:
        ret = pow(n, p // 2)
        ret *= ret
        if p % 2 == 1:
            ret *= n
    return ret

def make_facts(n):
    facts = [modll(1)]
    for i in range(len(facts), n + 1):
        facts.append(modll(facts[-1] * i))
    return facts

def make_invs(n):
    invs = [modll(0), modll(1)]
    for i in range(len(invs), n + 1):
        invs.append(invs[int(modll.MOD % i)] * (modll.MOD - modll.MOD // i))
    return invs

def make_ifacts(n):
    ifacts = [modll(1)]
    invs = make_invs(n)
    for i in range(len(ifacts), n + 1):
        ifacts.append(modll(ifacts[-1] * invs[i]))
    return ifacts

def combination(n, r):
    if n >= r and r >= 0:
        ret = modll()
        facts = make_facts(n)
        ifacts = make_ifacts(n)
        ret = facts[n] * ifacts[r] * ifacts[n - r]
        return ret
    else:
        return 0

def get_fact(n):
    facts = make_facts(n)
    return facts[n]

def get_ifact(n):
    ifacts = make_ifacts(n)
    return ifacts[n]

def disc_log(a, b):
    ret = -1
    m = math.isqrt(modll.MOD)
    mp = {}
    x = modll(1)
    for i in range(m):
        mp[x.get_val()] = i
        x *= a
    x = modll(1) / pow(a, m)
    k = b
    for i in range(m):
        if k.get_val() not in mp:
            k *= x
        else:
            ret = i * m + mp[k.get_val()]
            break
    return ret

def main():
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    st = SegTree(n, 0)
    ast = SegTree(n, 0)
    lst = SegTree(n, 0)
    rst = SegTree(n, 0)
    for i in range(n):
        w = int(input())
        st.update(i, w)
        ast.update(i, modll(w) * a[i])
        lst.update(i, modll(w) * (n - 1 - i))
        rst.update(i, modll(w) * i)
    ans = []
    for _ in range(q):
        x = int(input())
        if x < 0:
            x += 1
            y = int(input())
            st.update(-x, y)
            ast.update(-x, modll(y) * a[-x])
            lst.update(-x, modll(y) * (n - 1 - (-x)))
            rst.update(-x, modll(y) * (-x))
        else:
            y = int(input())
            x -= 1
            y -= 1
            if x == y:
                ans.append(0)
            else:
                if y - x == 1:
                    halfid = x
                else:
                    v = {
                        'st': st,
                        's': x,
                        'sum': st.add_rec(x, y + 1, 0, st.N, 0) // 2
                    }
                    halfid = lower_binary_search(x + 1, y, v, evalfunc)
                cand0 = st.add_rec(x, halfid + 1, 0, st.N, 0)
                cand1 = st.add_rec(halfid + 1, y + 1, 0, st.N, 0)
                dst = 0
                dstid = 0
                if cand0 <= cand1:
                    dst = a[halfid + 1]
                    dstid = halfid + 1
                else:
                    dst = a[halfid]
                    dstid = halfid
                buf = 0
                buf += modll(dst) * st.add_rec(x, dstid, 0, st.N, 0) - ast.add_rec(x, dstid, 0, st.N, 0) - (lst.add_rec(x, dstid, 0, st.N, 0) - modll(st.add_rec(x, dstid, 0, st.N, 0)) * (n - 1 - dstid))
                buf += modll(ast.add_rec(dstid, y + 1, 0, st.N, 0)) - modll(dst) * st.add_rec(dstid, y + 1, 0, st.N, 0) - (rst.add_rec(dstid, y + 1, 0, st.N, 0) - modll(st.add_rec(dstid, y + 1, 0, st.N, 0)) * dstid)
                ans.append(buf)
    for a in ans:
        print(a)

def evalfunc(val, v):
    buf = v['st'].add_rec(v['s'], val + 1, 0, v['st'].N, 0)
    if buf <= v['sum'] // 2:
        return True
    else:
        return False

if __name__ == "__main__":
    main()
