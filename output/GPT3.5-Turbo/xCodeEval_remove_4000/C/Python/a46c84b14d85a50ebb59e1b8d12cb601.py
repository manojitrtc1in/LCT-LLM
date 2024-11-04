import sys

def swap(a, b):
    c = b
    b = a
    a = c

def cin(n):
    n = int(input())

def id28(a, n):
    for i in range(n):
        print(a[i], end="")
        if i != n-1:
            print(" ", end="")
    print()

def min(a, b):
    return a if a < b else b

def max(a, b):
    return a if a > b else b

def min3(a, b, c):
    return a if (a <= b and a <= c) else (b if b <= c else c)

def max3(a, b, c):
    return a if (a >= b and a >= c) else (b if b >= c else c)

def minn(n, a):
    b = float('inf')
    for i in range(n):
        b = min(b, a[i])
    return b

def maxn(n, a):
    b = float('-inf')
    for i in range(n):
        b = max(b, a[i])
    return b

def POW(a, b):
    c = 1
    for i in range(b):
        c *= a
    return c

def id37(a, b):
    c = 1
    for i in range(b):
        c *= a
    return c

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def lcm(a, b):
    return a // gcd(a, b) * b

def id34(n):
    n += ((-n) // MOD1 + 1) * MOD1
    return n % MOD1

def mod_p(n, p):
    n += ((-n) // p + 1) * p
    return n % p

def id31(s, length, p):
    return 0 if p == 0 else POW(10, p-1) * (int(s[length-p]) - int('0')) + id31(s, length, p-1)

def digits(a, b):
    return 1 + digits(a // b, b) if a // b else 1

def base(n, a, i):
    return n % a if i == 1 else base(n // a, a, i-1)

def id16(x, n):
    return 1 if (x < 0 or x >= n) else 0

def id2(y, x, h, w):
    return 1 if (y < 0 or y >= h or x < 0 or x >= w) else 0

def lr_lower(l, r, am, val, type):
    if type < 3:
        if am < val:
            l = (l + r) // 2
        else:
            r = (l + r) // 2
    else:
        if am <= val:
            l = (l + r) // 2
        else:
            r = (l + r) // 2

def lr_upper(l, r, am, val, type):
    if type < 3:
        if am <= val:
            l = (l + r) // 2
        else:
            r = (l + r) // 2
    else:
        if am < val:
            l = (l + r) // 2
        else:
            r = (l + r) // 2

def cmp_lower(a, b, type):
    return 1 if (a == b) else (1 if (a >= b) else 0) if type == 1 else (1 if (a >= b) else 0) if type == 2 else (1 if (a > b) else 0)

def cmp_upper(a, b, type):
    return 1 if (a == b) else (1 if (a <= b) else 0) if type == 1 else (1 if (a <= b) else 0) if type == 2 else (1 if (a < b) else 0)

def lower_bound(a, l, r, val, type):
    while r - l > 1:
        lr_lower(l, r, a[(l+r)//2], val, type)
    return l if cmp_lower(a[l], val, type) else r if cmp_lower(a[r], val, type) else -1

def upper_bound(a, l, r, val, type):
    while r - l > 1:
        lr_upper(l, r, a[(l+r)//2], val, type)
    return r if cmp_upper(a[r], val, type) else l if cmp_upper(a[l], val, type) else -1

def count(a, l, r, x):
    p = lower_bound(a, l, r, x, 1)
    return 0 if p == -1 else upper_bound(a, p, r, x, 1) - p + 1

def factor_pre():
    global factors, fac_cnt, id27
    id27 = 0
    factors = [[], []]
    fac_cnt = 0
    tmp = (10**6) // 2 + 1
    fac_tmp = [0] * tmp
    for i in range(tmp):
        fac_tmp[i] = 2*i+1 if i else 2
    for i in range(1, tmp):
        if fac_tmp[i]:
            for j in range(3, tmp // (2*i+1) + 1, 2):
                if j * (2*i+1) < tmp:
                    fac_tmp[(j*(2*i+1)-1)//2] = 0
        else:
            continue
    for i in range(tmp):
        if fac_tmp[i]:
            for j in range(2):
                factors[j].append(fac_tmp[i])
    return 0

def factor(n, id29):
    factor_pre()
    for i in range(fac_cnt):
        cnt = 0
        while cnt += 1 if n % factors[0][i] == 0 else 0 and (n //= factors[0][i]) % factors[0][i] == 0:
            continue
        factors[1][i] = cnt if id29 == 1 else max(factors[1][i], cnt) if id29 == 2 else factors[1][i] + cnt
        if factors[0][i] > n:
            break
    return n

def judge_prime(n):
    factor_pre()
    for i in range(fac_cnt):
        if n < factors[0][i] * factors[0][i] or n == factors[0][i]:
            break
        elif n % factors[0][i] == 0:
            n //= n
    return 0 if n == 1 else 1

def makeinv(n, mod):
    global inv_arr, id33, id10, id3, id8
    if id10:
        return
    inv_arr = [0] * (n + 1)
    id33 = [0] * (n + 1)
    inv_arr[1] = id33[0] = id33[1] = 1
    for i in range(2, n + 1):
        inv_arr[i] = mod - inv_arr[mod % i] * (mod // i) % mod
        id33[i] = id33[i - 1] * inv_arr[i] % mod

def id30(n, mod):
    global mf_arr, id3, id8
    if id3:
        return
    mf_arr = [0] * (n + 1)
    x = mf_arr[0] = mf_arr[1] = 1
    for i in range(2, n + 1):
        x = x * i % mod
        mf_arr[i] = x

def m_inv(x, mod, is_fac):
    makeinv(id8, mod)
    return id33[x] if is_fac else inv_arr[x]

def m_f(x, mod):
    id30(id8, mod)
    return mf_arr[x]

def id20(n, k, mod):
    return m_f(n, mod) * m_inv(k, mod, 1) % mod * m_inv(n-k, mod, 1) % mod

def m_p(r, n, mod):
    t = 1
    s = r
    while n > 0:
        t = t * s % mod if n & 1 else t
        s = s * s % mod
        n >>= 1
    return t if r else 0

def upll(a, b):
    return -1 if a < b else 1 if a > b else 0

def downll(a, b):
    return 1 if a < b else -1 if a > b else 0

def cmp_string(a, b):
    return strcmp(a, b)

def cmp_char(a, b):
    return ord(a) - ord(b)

def sortup(a, n):
    a.sort()

def sortdown(a, n):
    a.sort(reverse=True)

def compare(a, b):
    return -1 if a < b else 1 if a > b else 0

class fr:
    def __init__(self, a, b):
        self.a = a
        self.b = b

def cmp1(p, q):
    pa = p.a
    qa = q.a
    return compare(pa, qa)

def cmp2(p, q):
    pa = p.a
    qa = q.a
    return compare(qa, pa)

def id41(a, n):
    a.sort(key=lambda x: x.a)

def id5(a, n):
    a.sort(key=lambda x: x.a, reverse=True)

def sort_partial(a, begin, end, id19):
    b = a[begin:end]
    if id19:
        sortup(b, end-begin)
    else:
        sortdown(b, end-begin)
    for i in range(begin, end):
        a[i] = b[i-begin]

class AVL_set:
    def __init__(self):
        self.val = 0
        self.diff = 0
        self.cnt = 0
        self.child = [None, None]

def id32(node, is_right):
    l = 0 if not is_right else 1
    r = 1 if not is_right else 0
    sign = 1 if is_right else -1
    if node.child[l] is not None:
        left = node.child[l]
        a = node.diff * sign
        b = left.diff * sign
        if b + 1:
            na = a - 1 - b
            nb = b - 1 if a - b else a - 2
        else:
            na = a - 1
            nb = b - 1 if a else a + b - 2
        node.diff = na * sign
        left.diff = nb * sign
        node.child[l] = node.child[l].child[r]
        left.child[r] = node
        node = left

def id13(node, data, add):
    if node is None:
        if add == 2:
            node = AVL_set()
            node.val = data
            node.cnt = 1
            node.diff = 0
            node.child[0] = None
            node.child[1] = None
        return node is not None
    else:
        l = 0 if data >= node.val else 1
        delta_sign = 1 if data < node.val else -1
        delta = id13(node.child[l], data, add)
        if delta:
            orig_diff = node.diff
            do_rotate = 0
            rotate_l = 0
            diff_sign = 0
            rotate_right = 0
            node.diff += delta * delta_sign
            if node.diff > 1:
                do_rotate = 1
                rotate_l = 0
                diff_sign = 1
                rotate_right = 1
            elif node.diff < -1:
                do_rotate = 1
                rotate_l = 1
                diff_sign = -1
                rotate_right = 0
            if do_rotate:
                child_diff = node.child[rotate_l].diff
                if node.child[rotate_l].diff * diff_sign < 0:
                    id32(node.child[rotate_l], not rotate_right)
                id32(node, rotate_right)
                return -1 if delta < 0 and child_diff != 0 else 0
            if delta > 0 and orig_diff == 0:
                return 1
            elif delta < 0 and orig_diff != 0:
                return -1
            else:
                return 0
        else:
            return 0

def id18(node, depth):
    if node is None:
        return
    id18(node.child[1], depth + 1)
    print(node.val, node.cnt)
    id18(node.child[0], depth + 1)

def id7(node):
    if node is None:
        return
    id7(node.child[0])
    id7(node.child[1])
    del node

def id9(root, val):
    node = root
    while node:
        if val < node.val:
            node = node.child[0]
        elif val > node.val:
            node = node.child[1]
        else:
            return node.cnt
    return 0

def id24(node, val, type):
    if node == val:
        if type != 3:
            return 0
        else:
            return 1
    if node < val:
        return 1
    if node > val:
        return -1
    return 0

def id39(root, val, type):
    node = root
    while node:
        com = id24(node.val, val, type)
        if com == 0:
            return node
        if com == 1:
            node = node.child[1]
        if com == -1:
            small = id39(node.child[0], val, type)
            if type == 1:
                return small
            else:
                if small is not None:
                    return small
                else:
                    return node
    return node

def id42(node, val, type):
    if node == val:
        if type != 3:
            return 0
        else:
            return -1
    if node < val:
        return 1
    if node > val:
        return -1
    return 0

def id4(root, val, type):
    node = root
    while node:
        com = id42(node.val, val, type)
        if com == 0:
            return node
        if com == -1:
            node = node.child[0]
        if com == 1:
            big = id4(node.child[1], val, type)
            if type == 1:
                return big
            else:
                if big is not None:
                    return big
                else:
                    return node
    return node

def id15(root, type):
    while root.child[type] is not None:
        root = root.child[type]
    return root.val

def id14(node1, node2):
    tmp = node1
    node1 = node2
    node2 = tmp

def set_main(command, set_num, val, option):
    global id12, set_pointer, id1
    if command == -1:
        id18(set_pointer[set_num], 0)
    if command == 1:
        return 1 if id9(set_pointer[set_num], val) else id1[set_num] += 1; id13(set_pointer[set_num], val, 2)
    if command == 2:
        return id9(set_pointer[set_num], val)
    if command == 3:
        return 1 if id9(set_pointer[set_num], val) > 1 else id1[set_num] -= 1; id13(set_pointer[set_num], val, 1)
    if command == 4:
        id1[set_num] -= 1; id13(set_pointer[set_num], val, 0)
    if command == 5:
        id1[set_num] = 0; id7(set_pointer[set_num]); set_pointer[set_num] = None
    if command == 6:
        return id1[set_num]
    if command == 7:
        return id15(set_pointer[set_num], 1)
    if command == 8:
        return id15(set_pointer[set_num], 0)
    if command == 9:
        set_pointer[set_num], set_pointer[val] = set_pointer[val], set_pointer[set_num]
    if 10 <= command <= 12:
        lowbound = id39(set_pointer[set_num], val, command-9)
        if lowbound is None:
            return option
        else:
            return lowbound.val
    if 13 <= command <= 15:
        upbound = id4(set_pointer[set_num], val, command-12)
        if upbound is None:
            return option
        else:
            return upbound.val
    return 0

def set_print(set_num):
    set_main(-1, set_num, 0, 0)

def set_insert(set_num, val):
    set_main(1, set_num, val, 0)

def set_count(set_num, val):
    return set_main(2, set_num, val, 0)

def id17(set_num, val, is_all):
    if is_all:
        set_main(4, set_num, val, 0)
    else:
        set_main(3, set_num, val, 0)

def set_clear(set_num):
    set_main(5, set_num, 0, 0)

def set_size(set_num):
    return set_main(6, set_num, 0, 0)

def set_max(set_num):
    return set_main(7, set_num, 0, 0)

def set_min(set_num):
    return set_main(8, set_num, 0, 0)

def set_swap(id26, id21):
    set_main(9, id26, id21, 0)

def id11(set_num, val, type, error):
    return set_main(9+type, set_num, val, error)

def id35(set_num, val, type, error):
    return set_main(12+type, set_num, val, error)

def vector_push(v, x):
    if v.n == v.max:
        v.max *= 2
        v.data = v.data[:v.max] + [0] * (v.max - v.n)
    if x is None:
        v.data[v.n] = 0
    else:
        v.data[v.n] = x
    v.n += 1

def vector_set(v, idx, x):
    if x is None:
        v.data[idx] = 0
    else:
        v.data[idx] = x

def vector_get(v, idx):
    return v.data[idx]

def vector_size(v):
    return v.n

def vector_init(n, data_size):
    ret = {}
    ret['n'] = 0
    ret['max'] = n
    ret['data_size'] = data_size
    ret['data'] = [0] * n

    ret['push'] = vector_push
    ret['set'] = vector_set
    ret['size'] = vector_size
    ret['get'] = vector_get

    return ret

def id40(d, from_, to, cap):
    d['rev'][from_].push(d['to'][to].n)
    d['rev'][to].push(d['to'][from_].n)
    d['to'][from_].push(to)
    d['to'][to].push(from_)
    d['cap'][from_].push(cap)
    d['cap'][to].push(None)

def id6(d, s, t):
    init = -1
    for i in range(d['n']):
        d['min_cost'].set(i, init)
    q = vector_init(1, 4)
    d['min_cost'].set(s, None)
    head = 0
    q['push'](s)
    while head != q['n'] and d['min_cost'].get(t) == -1:
        p = q['get'](head)
        head += 1
        for i in range(d['to'][p].n):
            to = d['to'][p].get(i)
            if d['cap'][p].get(i) > 0 and d['min_cost'].get(to) == -1:
                cost = d['min_cost'].get(p) + 1
                d['min_cost'].set(to, cost)
                q['push'](to)
    return d['min_cost'].get(t) != -1

def id0(d, idx, t, flow):
    if idx == t:
        return flow
    for i in range(d['iter'].get(idx), d['cap'][idx].n):
        d['iter'].set(idx, i)
        cap = d['cap'][idx].get(i)
        to = d['to'][idx].get(i)
        if cap > 0 and d['min_cost'].get(idx) < d['min_cost'].get(to):
            delta = id0(d, to, t, flow if flow < cap else cap)
            if delta > 0:
                cap -= delta
                d['cap'][idx].set(i, cap)
                rev = d['rev'][idx].get(i)
                rev_cap = d['cap'][to].get(rev) + delta
                d['cap'][to].set(rev, rev_cap)
                return delta
    return 0

def id36(d, s, t):
    flow = 0
    while id6(d, s, t):
        for i in range(d['n']):
            d['iter'].set(i, None)
        f = 0
        while (f := id0(d, s, t, INF)) > 0:
            flow += f
    return flow

def id38(n):
    ret = {}
    ret['n'] = n
    ret['to'] = [vector_init(1, 4) for _ in range(n)]
    ret['cap'] = [vector_init(1, 8) for _ in range(n)]
    ret['rev'] = [vector_init(1, 4) for _ in range(n)]
    ret['min_cost'] = vector_init(n, 4)
    ret['iter'] = vector_init(n, 4)
    ret['add'] = id40
    ret['max_flow'] = id36
    return ret

def solve():
    n = int(input())
    ans = 0

    a = [0] * 3
    b = [0] * 3
    for i in range(3):
        a[i] = int(input())
    for i in range(3):
        b[i] = int(input())
    ma = 0

    ma = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0])
    d = id38(8)
    d['add'](d, 6, 0, a[0])
    d['add'](d, 6, 1, a[1])
    d['add'](d, 6, 2, a[2])

    d['add'](d, 0, 3, INF)
    d['add'](d, 0, 5, INF)
    d['add'](d, 1, 3, INF)
    d['add'](d, 1, 4, INF)
    d['add'](d, 2, 4, INF)
    d['add'](d, 2, 5, INF)

    d['add'](d, 3, 7, b[0])
    d['add'](d, 4, 7, b[1])
    d['add'](d, 5, 7, b[2])
    print(n - d['max_flow'](d, 6, 7), ma)

T = 1

for _ in range(T):
    solve()
