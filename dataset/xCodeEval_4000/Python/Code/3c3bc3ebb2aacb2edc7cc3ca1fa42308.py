
import copy
from collections import defaultdict as dd
from collections import deque
import math
import sys
import os
import random































from types import GeneratorType
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc




local_run = False
def dbg(*args, **kwargs): pass
def dbgG(*args, **kwargs): pass
def dbgP(*args, **kwargs): pass
def dbgY(*args, **kwargs): pass
def dbgR(*args, **kwargs): pass
def dbgB(*args, **kwargs): pass
def dbgW(*args, **kwargs): pass
def dbgBackground(*args, **kwargs): pass
def dbgc(*args, **kwargs): pass
def dbgcG(*args, **kwargs): pass
def dbgcP(*args, **kwargs): pass
def dbgcY(*args, **kwargs): pass
def dbgcR(*args, **kwargs): pass
def dbgcB(*args, **kwargs): pass
def dbgcW(*args, **kwargs): pass
def dbgcBackground(*args, **kwargs): pass
def el(n=1): pass
def print_details_helper(*args, **kwargs): pass
def print_tsv_helper(*args, **kwargs): pass
def pdh(*args, **kwargs): pass
def pth(*args, **kwargs): pass
if os.environ.get("PYTHON_CONTEST_HELPER"):
    local_run = True

    
    
    def print_details_helper(q):
        out = []
        for k, x in enumerate(q):
            out.append(f"\n\t{k}:\t{x}")
        return ''.join(out) + '\n'

    pdh = print_details_helper  

    
    def print_tsv_helper(q):
        out = []
        for row in q:
            out.append('\t'.join(str(x) for x in row))
        return ''.join('\n\t' + x for x in out) + '\n'

    pth = print_tsv_helper

    OUT_RED_BOLD = "\033[31;1m"
    OUT_GREEN = "\033[32m"
    OUT_RESET = "\033[0m"
    OUT_BOLD = "\033[;1m"
    OUT_RED = "\033[31m"
    OUT_WHITE = "\033[97m"
    OUT_BLUE = "\033[34;1m"
    OUT_CYAN = "\033[36;1m"
    OUT_PURPLE = "\033[35;1m"
    OUT_YELLOW = "\033[33;1m"
    OUT_BACKGROUND = "\033[41;30;1m"

    
    def flush_stdout():
        print('', flush=True, end='')

    def dbgBase(*args, **kwargs):
        flush_stdout()
        color_helper = kwargs.pop('color', OUT_CYAN)
        if kwargs.get('comment_first', False):
            print(f'{OUT_BOLD}{color_helper}{args[0]: >11} {OUT_RESET}', end='', file=sys.stderr)
            args = tuple(args[1:])
        else:
            print(f"{'': >12}", end='', file=sys.stderr)
        if 'comment_first' in kwargs:
            del kwargs['comment_first']
        print(f"{OUT_RED_BOLD}{sys._getframe().f_back.f_back.f_lineno: >7} {OUT_BOLD}:  {OUT_RESET}{color_helper}", end='', file=sys.stderr)
        end_maybe = kwargs.get('end', '\n')
        kwargs['end']=f"{OUT_RESET}{end_maybe}"
        if 'sep' not in kwargs:
            kwargs['sep'] = ' '*3
        kwargs['flush'] = True
        print(*args, file=sys.stderr, **kwargs)

    
    
    def dbg(*args, **kwargs): dbgBase(color=OUT_CYAN, *args, **kwargs)
    def dbgG(*args, **kwargs): dbgBase(color=OUT_GREEN, *args, **kwargs)
    def dbgP(*args, **kwargs): dbgBase(color=OUT_PURPLE, *args, **kwargs)
    def dbgY(*args, **kwargs): dbgBase(color=OUT_YELLOW, *args, **kwargs)
    def dbgR(*args, **kwargs): dbgBase(color=OUT_RED, *args, **kwargs)
    def dbgB(*args, **kwargs): dbgBase(color=OUT_BLUE, *args, **kwargs)
    def dbgW(*args, **kwargs): dbgBase(color=OUT_WHITE, *args, **kwargs)
    def dbgBackground(*args, **kwargs): dbgBase(color=OUT_BACKGROUND, *args, **kwargs)
    def el(n=1): flush_stdout(); print('\n'*n, file=sys.stderr, end='', flush=True)
    def dbgc(*args, **kwargs): dbgBase(comment_first=True, color=OUT_CYAN, *args, **kwargs)
    def dbgcG(*args, **kwargs): dbgBase(comment_first=True, color=OUT_GREEN, *args, **kwargs)
    def dbgcP(*args, **kwargs): dbgBase(comment_first=True, color=OUT_PURPLE, *args, **kwargs)
    def dbgcY(*args, **kwargs): dbgBase(comment_first=True, color=OUT_YELLOW, *args, **kwargs)
    def dbgcR(*args, **kwargs): dbgBase(comment_first=True, color=OUT_RED, *args, **kwargs)
    def dbgcB(*args, **kwargs): dbgBase(comment_first=True, color=OUT_BLUE, *args, **kwargs)
    def dbgcW(*args, **kwargs): dbgBase(comment_first=True, color=OUT_WHITE, *args, **kwargs)
    def dbgcBackground(*args, **kwargs): dbgBase(comment_first=True, color=OUT_BACKGROUND, *args, **kwargs)


from io import BytesIO, IOBase

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")


def nn():
    return int(input())

def nn1():
    return nn() - 1

def li():
    return list(input())

def lm():
    return list(map(int, input().split()))

def lm1():
    return list(map(lambda x : int(x) - 1, input().split()))

rv = lm
rv1 = lm1





def ps(*args, **kwargs):
    if hasattr(args[0], '__iter__') and not isinstance(args[0], str):
        print(' '.join(str(x) for x in args[0]), **kwargs)
    else:
        print(' '.join(str(x) for x in args), **kwargs)

def pv(q): ps(*q)
def ps1(*args, **kwargs):
    if hasattr(args[0], '__iter__'):
        print(' '.join(str(x+1) for x in args[0]), **kwargs)
    else:
        print(' '.join(str(x+1) for x in args), **kwargs)
def pv1(q): ps1(*q)
def pvn(q):
    for x in q: ps(x)
def pvn1(q):
    for x in q: ps1(x)



def YES(): return print("YES")
def NO(): return print("NO")
def Yes(): return print("Yes")
def No(): return print("No")

def remDup(v):
    v = list(set(v))

steps_orthogonal = [(1,0), (0,1), (-1,0), (0,-1)]
steps_diagonal = [(1,1), (1,-1), (-1,-1), (-1,1)]
steps_8dirs = [(-1,-1), (0,-1), (1,-1), (-1,0), (1,0), (-1,1), (0,1), (1,1)]

def fstTrue(lo, hi, f):
    hi += 1
    assert lo <= hi
    while lo < hi:
        mid = lo + (hi-lo) // 2
        if f(mid): hi = mid
        else: lo = mid + 1
    return lo

first_true = fstTrue

def lstTrue(lo, hi, f):
    lo -= 1
    assert lo <= hi
    while lo < hi:
        mid = lo + (hi-lo+1) // 2
        if f(mid): lo = mid
        else: hi = mid-1
    return lo

last_true = lstTrue


def cdiv(a, b): return a//b + (1 if ((a^b)>0 and a%b != 0) else 0)
def fdiv(a, b): return a//b - (1 if ((a^b)<0 and a%b != 0) else 0)

def bits_set(x): return bin(x).count('1')
pct = bits_set
popcount = bits_set
















def getsum(BITTree,i):
	s = 0 

	
	i = i+1

	
	while i > 0:

		
		s += BITTree[i]

		
		i -= i & (-i)
	return s




def updatebit(BITTree , n , i ,v):

	
	i += 1

	
	while i <= n:

		
		BITTree[i] += v

		
		i += i & (-i)




def construct(arr, n):

	
	BITTree = [0]*(n+1)

	
	for i in range(n):
		updatebit(BITTree, n, i, arr[i])

	
	
	
	return BITTree


class LazySeg:
    idSeg = 0  
    idLazy = 0  
    def cmb(self, a, b):  
        return a + b
    def init(self, _n):
        self.orig_n = _n
        self.n = 1
        while self.n < _n: self.n *= 2
        self.SZ = self.n
        self.seg = [self.idSeg for _ in range(2*self.n)]
        self.lazy = [self.idLazy for _ in range(2*self.n)]

    def push(self, ind, L, R):
        
        self.seg[ind] += self.lazy[ind] * (R-L+1)
        if L != R:
            for k in range(2):
                
                self.lazy[2*ind+k] += self.lazy[ind]

        self.lazy[ind] = self.idLazy

    def pull(self, ind): self.seg[ind] = self.cmb(self.seg[2*ind],self.seg[2*ind+1])
    def build(self):
        for k in reversed(range(1, self.n)): self.pull(k)

    def push_all(self):
        todo = [(1, 0, self.n-1)]
        while len(todo) > 0:
            ind, L, R = todo.pop()
            self.push(ind,L,R)
            if L < R:
                M = (L+R)>>1
                todo.append((2*ind,L,M))
                todo.append((2*ind+1,M+1,R))

    def upd(self, lo, hi, inc):
        todo = [(1, 0, self.n-1)]
        post = []
        while len(todo) > 0:
            ind, L, R = todo.pop()
            self.push(ind, L, R)
            if hi < L or R < lo: continue
            if lo <= L and R <= hi:
                self.lazy[ind] = inc
                self.push(ind,L,R)
                continue
            M = (L+R)>>1
            todo.append((2*ind,L,M))
            todo.append((2*ind+1,M+1,R))
            post.append(ind)
        for ind in reversed(post):
            self.pull(ind)

    def query(self, l, r):
        ra = self.idSeg
        rb = self.idSeg
        l += self.n
        r += self.n+1
        while l < r:
            if l&1:
                ra = self.cmb(ra, self.seg[l])
                l += 1
            if r&1:
                r -= 1
                rb = self.cmb(self.seg[r], rb)
            l >>= 1
            r >>= 1
        return self.cmb(ra, rb)

    
    def first_satisfying_R(self, base, val, ind=1, l=0, r=None):
        if r is None: r = self.n - 1
        
        ok = (self.query(l,r,ind,l,r) >= val)
        if r < base or not ok: return -1
        if l == r: return l
        m = (l+r) // 2
        res = self.first_satisfying_R(base,val,2*ind,l,m)
        if res != -1: return res
        return self.first_satisfying_R(base,val,2*ind+1,m+1,r)

    
    def first_satisfying_L(self, base, val, ind=1, l=0, r=None):
        if r is None: r = self.n - 1
        
        ok = (self.query(l,r,ind,l,r) >= val)
        if l > base or not ok: return -1
        if l == r: return l
        m = (l+r) // 2
        res = self.first_satisfying_R(base,val,2*ind+1,m+1,r)
        if res != -1: return res
        return self.first_satisfying_R(base,val,2*ind,l,m)

    def __str__(self):  
        if not local_run: return  
        self.push_all()  
        out = [self.seg[k] for k in range(self.n, self.n + self.orig_n)]
        return str(out)

    def detailed_printouts(self):
        
        if not local_run: return  
        ST_SIZE = self.n
        ST_PRINT_SIZE = self.orig_n
        el()
        dbgc("LazySeg DETAILS")
        for k in range(1, ST_SIZE + ST_PRINT_SIZE):
            if k >= ST_SIZE:
                p = k - ST_SIZE
                dbgP(k, p, self.seg[k], self.lazy[k])
            else:
                binary_digits = bin(k)[2:]
                l = 0
                r = ST_SIZE - 1
                for d in binary_digits:
                    m = (l+r) // 2
                    if d == '1': l = m+1
                    else: r = m
                if l < ST_PRINT_SIZE:
                    dbgY(k, (l,r), self.seg[k], self.lazy[k])
        el()
        

class SegTree:
    ID = 0  
    def cmb(self, a, b):  
        return a+b
    def init(self, _n):
        self.orig_n = _n
        self.n = 1
        while self.n < _n:
            self.n *= 2
        self.seg = [self.ID for _ in range(2*self.n)]

    def pull(self, p):
        self.seg[p] = self.cmb(self.seg[2*p], self.seg[2*p+1])

    def build(self):
        for k in reversed(range(1, self.n)): self.pull(k)

    def upd(self, p, val):  
        p += self.n
        self.seg[p] = val
        p >>= 1
        while p != 0:
            self.pull(p)
            p >>= 1

    def query(self, l, r):  
        ra = self.ID
        rb = self.ID
        l += self.n
        r += self.n+1
        while l < r:
            if l&1:
                ra = self.cmb(ra, self.seg[l])
                l += 1
            if r&1:
                r -= 1
                rb = self.cmb(self.seg[r], rb)
            l >>= 1
            r >>= 1
        return self.cmb(ra, rb)

    
    def first_satisfying_R(self, base, val, ind=1, l=0, r=None):
        if r is None: r = self.n - 1
        
        ok = (self.seg[ind] >= val)
        if r < base or not ok: return -1
        if l == r: return l
        m = (l+r) // 2
        res = self.first_satisfying_R(base,val,2*ind,l,m)
        if res != -1: return res
        return self.first_satisfying_R(base,val,2*ind+1,m+1,r)

    
    def first_satisfying_L(self, base, val, ind=1, l=0, r=None):
        if r is None: r = self.n - 1
        
        ok = (self.seg[ind] >= val)
        if l > base or not ok: return -1
        if l == r: return l
        m = (l+r) // 2
        res = self.first_satisfying_R(base,val,2*ind+1,m+1,r)
        if res != -1: return res
        return self.first_satisfying_R(base,val,2*ind,l,m)

    def __str__(self):  
        if not local_run: return ''
        out = [self.seg[k] for k in range(self.n, self.n + self.orig_n)]
        return str(out)

    def detailed_printouts(self):
        
        if not local_run: return  
        ST_SIZE = self.n
        ST_PRINT_SIZE = self.orig_n
        el()
        dbgc("ST DETAILS")
        for k in range(1, ST_SIZE + ST_PRINT_SIZE):
            if k >= ST_SIZE:
                p = k - ST_SIZE
                dbgP(k, p, self.seg[k])
            else:
                binary_digits = bin(k)[2:]
                l = 0
                r = ST_SIZE - 1
                for d in binary_digits:
                    m = (l+r) // 2
                    if d == '1': l = m+1
                    else: r = m
                if l < ST_PRINT_SIZE:
                    dbgY(k, (l,r), self.seg[k])
        el()
        


def solve(testID):
    R, C, Q = lm()
    dat = []
    for _ in range(R):
        dat.append(input())
    queries = []
    for _ in range(Q):
        val = lm()
        queries.append((val[0] - 1, val[1] - 1))

    dbgR(R, C, Q, dat, queries)
    el()
    base_desktop = [1 if dat[r][c] == "*" else 0 for c in range(C) for r in range(R)]
    dbgY(base_desktop)

    N = R * C
    
    st = SegTree()
    st.init(N)
    for k in range(N): st.seg[st.n + k] = base_desktop[k]
    st.build()

    
    total_tokens = sum(base_desktop)
    for q_num in range(Q):
        r, c = queries[q_num]
        pt_idx = c * R + r
        
        base_desktop[pt_idx] = (base_desktop[pt_idx] + 1) % 2
        update_val = 1 if base_desktop[pt_idx] % 2 == 1 else -1
        
        
        
        st.upd(pt_idx, base_desktop[pt_idx] % 2)

        total_tokens += update_val
        
        
        
        range_result = st.query(0, total_tokens - 1)
        print(total_tokens - range_result)


def solveBIT(testID):
    R, C, Q = lm()
    dat = []
    for _ in range(R):
        dat.append(input())
    queries = []
    for _ in range(Q):
        val = lm()
        queries.append((val[0] - 1, val[1] - 1))

    dbgR(R, C, Q, dat, queries)
    el()
    base_desktop = [1 if dat[r][c] == "*" else 0 for c in range(C) for r in range(R)]
    dbgY(base_desktop)
    BITTree = construct(base_desktop,len(base_desktop))
    total_tokens = sum(base_desktop)
    for q_num in range(Q):
        r, c = queries[q_num]
        pt_idx = c * R + r
        
        base_desktop[pt_idx] = (base_desktop[pt_idx] + 1) % 2
        update_val = 1 if base_desktop[pt_idx] % 2 == 1 else -1
        
        updatebit(BITTree, R * C, pt_idx, update_val)
        total_tokens += update_val
        
        
        print(total_tokens - getsum(BITTree,total_tokens - 1))

    return


if __name__ == '__main__':
    T = 1
    
    for testID in range(1, T+1):
        el()
        dbgBackground(f"Case {testID}")
        solve(testID)