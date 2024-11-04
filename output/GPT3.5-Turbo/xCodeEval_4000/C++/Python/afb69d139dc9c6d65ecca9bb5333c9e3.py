import sys
import random
import time

class HashedString:
    def __init__(self, s, n=1):
        self.s = s
        self.MOD = []
        self.POW = []
        self.hash = []
        self.pows = []
        for i in range(n):
            self.MOD.append(self.gen_random_prime())
            self.POW.append(self.gen_random_prime())
            self.hash.append([0])
            self.pows.append([1])
        self += s
    
    def substr(self, L, n):
        return self.s[L:L+n]
    
    def size(self):
        return len(self.s)
    
    def __getitem__(self, n):
        return self.s[n]
    
    def get_hash(self, L, R):
        ret = []
        for i in range(len(self.hash)):
            ret.append(self.nmod(self.hash[i][R] - self.hash[i][L] * self.pows[i][R - L], self.MOD[i]))
        return ret
    
    def equal(self, L1, R1, L2, R2):
        return self.get_hash(L1, R1) == self.get_hash(L2, R2)
    
    def __iadd__(self, oth):
        for i in range(len(self.hash)):
            for c in oth:
                self.s += c
                m = self.MOD[i]
                p = self.POW[i]
                cp = self.pows[i][-1]
                cm = self.hash[i][-1]
                cm = (cm * p + ord(c)) % m
                cp = cp * p % m
                self.hash[i].append(cm)
                self.pows[i].append(cp)
        return self
    
    def gen_random_prime(self, L=1e9):
        L += random.randint(0, 4242)
        while not self.is_prime(L):
            L += 1
        return L
    
    def is_prime(self, n):
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                return False
        return True
    
    def factor(self, n):
        ans = []
        for i in range(2, int(n ** 0.5) + 1):
            while n % i == 0:
                ans.append(i)
                n //= i
        if n != 1:
            ans.append(n)
        return ans
    
    def divisors(self, n):
        ret = []
        for i in range(1, int(n ** 0.5) + 1):
            if n % i == 0:
                ret.append(i)
                if i * i != n:
                    ret.append(n // i)
        return ret
    
    def factor_pows(self, n):
        fac = self.factor(n)
        ret = []
        L = 0
        while L < len(fac):
            R = L
            while R < len(fac) and fac[R] == fac[L]:
                R += 1
            ret.append((fac[L], R - L))
            L = R
        return ret
    
    def nmod(self, a, m):
        return (a % m + m) % m
    
    def mrand(self):
        return abs((1 * random.randint(0, (1 << 15))) + random.randint(0, (1 << 15)))

class Treap:
    def __init__(self, t, val, speed):
        self.left = None
        self.right = None
        self.t = t
        self.y = self.mrand()
        self.prefix_sum = val
        self.speed = speed
        self.push = 0
        self.min_prefix_sum_in_subtree = val
    
    def vertex_add(self, push):
        self.prefix_sum += push
        self.min_prefix_sum_in_subtree += push
        self.push += push
    
    def push(self):
        push = self.push
        if not push:
            return
        if self.left:
            self.left.vertex_add(push)
        if self.right:
            self.right.vertex_add(push)
        self.push = 0
    
    def smin(self):
        return self.min_prefix_sum_in_subtree if self else INF
    
    def recalc(self):
        self.min_prefix_sum_in_subtree = min(self.smin(self.left), self.smin(self.right), self.prefix_sum)
    
    def merge(self, a, b):
        if not a:
            return b
        if not b:
            return a
        if a.y < b.y:
            a.push()
            a.right = self.merge(a.right, b)
            a.recalc()
            return a
        else:
            b.push()
            b.left = self.merge(a, b.left)
            b.recalc()
            return b
    
    def split(self, a, k):
        if not a:
            return (a, a)
        a.push()
        if a.t < k:
            l, r = self.split(a.right, k)
            a.right = l
            a.recalc()
            return (a, r)
        else:
            l, r = self.split(a.left, k)
            a.left = r
            a.recalc()
            return (l, a)
    
    def get_least(self, a):
        a.push()
        if not a.left:
            return a
        return self.get_least(a.left)
    
    def get_greatest(self, a):
        a.push()
        if not a.right:
            return a
        return self.get_greatest(a.right)
    
    def find_first_less(self, a, v):
        a.push()
        if self.smin(a.left) <= v:
            return self.find_first_less(a.left, v)
        if a.prefix_sum <= v:
            return a
        return self.find_first_less(a.right, v)
    
    def print_tree(self, a):
        if not a:
            return
        self.print_tree(a.left)
        print(a.t, end=' ')
        self.print_tree(a.right)

def readString():
    return sys.stdin.readline().strip()

def readInt():
    return int(readString())

def readDouble():
    return float(readString())

def writeInt(x, end=' ', output_len=-1):
    sys.stdout.write(str(x))
    sys.stdout.write(end)

def writeWord(s):
    sys.stdout.write(s)

def writeDouble(x, output_len=0):
    sys.stdout.write(format(x, '.{}f'.format(output_len)))

def flush():
    sys.stdout.flush()

def isEof():
    return peekChar() == -1

def getChar():
    global buf_pos, buf_len
    if buf_pos == buf_len:
        buf_pos = 0
        buf_len = sys.stdin.buffer.readinto(buf)
        if buf_pos == buf_len:
            return -1
    return buf[buf_pos]

def peekChar():
    global buf_pos, buf_len
    if buf_pos == buf_len:
        buf_pos = 0
        buf_len = sys.stdin.buffer.readinto(buf)
        if buf_pos == buf_len:
            return -1
    return buf[buf_pos]

def seekEof():
    while peekChar() != -1 and peekChar() <= 32:
        buf_pos += 1
    return peekChar() == -1

def skipBlanks():
    while not isEof() and buf[buf_pos] <= 32:
        buf_pos += 1

def readChar():
    c = getChar()
    while c != -1 and c <= 32:
        c = getChar()
    return c

def init():
    random.seed(time.time())
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

def main():
    init()
    root = Treap(0, 0, 0)
    root = root.merge(root, Treap(2e9, 0, 0))
    q = readInt()
    for _ in range(q):
        type = readInt()
        if type == 1:
            t = readInt()
            s = readInt()
            l, r = root.split(root, t)
            vr = root.get_least(r)
            vl = root.get_greatest(l)
            psum = vl.prefix_sum + (t - vl.t) * vl.speed
            new_psum = psum + (vr.t - t) * s
            vr.vertex_add(new_psum - vr.prefix_sum)
            root = root.merge(l, root.merge(Treap(t, psum, s), r))
        elif type == 2:
            t = readInt()
            l, tr = root.split(root, t)
            y, r = root.split(tr, t + 1)
            vl = root.get_greatest(l)
            vr = root.get_least(r)
            new_psum = vl.prefix_sum + (vr.t - vl.t) * vl.speed
            vr.vertex_add(new_psum - vr.prefix_sum)
            root = root.merge(l, r)
        else:
            L = readInt()
            R = readInt()
            v = readInt()
            if v == 0:
                writeInt(L, '\n')
                continue
            l, yr = root.split(root, L)
            y, r = root.split(yr, R + 1)
            if not y:
                writeInt(-1, '\n')
            else:
                vl = root.get_least(y)
                vr = root.get_greatest(y)
                searching_v = vl.prefix_sum - v
                if y.min_prefix_sum_in_subtree > searching_v:
                    new_psum = vr.prefix_sum + (R - vr.t) * vr.speed
                    if new_psum > searching_v:
                        writeInt(-1, '\n')
                    else:
                        writeDouble(vr.t + (searching_v - vr.prefix_sum) / vr.speed, '\n')
                else:
                    h = root.find_first_less(y, searching_v)
                    yl, yr = root.split(y, h.t)
                    vyl = root.get_greatest(yl)
                    writeDouble(vyl.t + (searching_v - vyl.prefix_sum) / vyl.speed, '\n')
                    y = root.merge(yl, yr)
            root = root.merge(l, root.merge(y, r))
    flush()

if __name__ == "__main__":
    main()
