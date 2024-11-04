import sys
from collections import deque
from math import sqrt, pow

class InputReader:
    def __init__(self):
        self.r = sys.stdin
        self.st = None

    def next_line(self):
        return self.r.readline().strip()

    def next(self):
        if self.st is None or not self.st:
            self.st = self.next_line().split()
        return self.st.pop(0)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

input_reader = InputReader()
log = sys.stdout
power_set = []
mod = int(pow(10, 9) + 7)

def bfs(w, n):
    q = deque()
    q.append(w)
    h = {w: 0}
    min_val = float('inf')
    
    while q:
        s = q.popleft()
        if n == len(str(s)):
            return h[s]
        
        t = set()
        e = str(s)
        for char in e:
            t.add(int(char))
        
        for x in t:
            v = x * s
            if len(str(v)) > n:
                continue
            if v not in h:
                h[v] = h[s] + 1
                q.append(v)
    
    return -1 if min_val == float('inf') else min_val

def log2(n):
    cnt = 0
    while n > 1:
        n //= 2
        cnt += 1
    return cnt

def bfs_graph(node, a):
    q = deque()
    q.append(node)
    distances = [-1] * len(a)
    distances[node] = 0
    
    while q:
        parent = q.popleft()
        nodes = a[parent]
        cost = distances[parent]
        
        for node1 in nodes:
            if distances[node1] == -1:
                q.append(node1)
                distances[node1] = cost + 1
    
    return distances

def get_digit_sum(n):
    sum_val = 0
    while n > 0:
        sum_val += n % 10
        n //= 10
    return sum_val

def prime_factors(n):
    sum_val = 1
    while n % 2 == 0:
        sum_val *= 2
        n //= 2
    for i in range(3, int(sqrt(n)) + 1, 2):
        while n % i == 0:
            sum_val *= i
            n //= i
    if n > 2:
        sum_val *= n
    return sum_val

def find_primes(n):
    a = []
    for i in range(1, int(sqrt(n)) + 1):
        if n % i == 0:
            if is_prime(i):
                a.append(i)
                n //= i
                i = 0
            elif is_prime(n // i):
                a.append(n // i)
                n = i
                i = 0
    return a

def generate(ind, a, sub):
    if ind == len(a):
        power_set.append(sub)
        return
    have = sub.copy()
    less = sub.copy()
    have.append(a[ind])
    generate(ind + 1, a, have)
    generate(ind + 1, a, less)

def factorial(n):
    if n <= 1:
        return 1
    t = n - 1
    while t > 1:
        n *= t
        t -= 1
    return n

def is_palindrome(n):
    t = n
    ans = 0
    while t > 0:
        ans = ans * 10 + t % 10
        t //= 10
    return ans == n

class Tri:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

def is_prime(num):
    if num == 1:
        return False
    if num == 2:
        return True
    if num % 2 == 0:
        return False
    if num == 3:
        return True
    for i in range(3, int(sqrt(num)) + 1, 2):
        if num % i == 0:
            return False
    return True

def prefix_sum(a):
    for i in range(1, len(a)):
        a[i] += a[i - 1]

def suffix_sum(a):
    for i in range(len(a) - 2, -1, -1):
        a[i] += a[i + 1]

def mod(a, b):
    r = a % b
    return r + b if r < 0 else r

def id13(w):
    r = 0
    l = 0
    for i in range(len(w) - 1, -1, -1):
        x = (ord(w[i]) - ord('0')) * int(pow(2, l))
        r += x
        l += 1
    return r

def id3(n):
    w = ""
    while n > 0:
        w = str(n % 2) + w
        n //= 2
    return w

def is_sorted(a):
    for i in range(len(a) - 1):
        if a[i] > a[i + 1]:
            return False
    return True

def print_array(a):
    log.write(" ".join(map(str, a)) + "\n")

def read_array(a):
    for i in range(len(a)):
        a[i] = input_reader.next_int()

class Pair:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"{self.x} {self.y}"

def lcm(x, y):
    return x // gcd(x, y) * y

def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x % y)

def id10(a, b):
    gcd_val = gcd(a, b)
    print(a // gcd_val, b // gcd_val)

class Node:
    BLACK = 0
    RED = 1

    def __init__(self, key=None):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None
        self.num_left = 0
        self.num_right = 0
        self.color = Node.BLACK

class RedBlackTree:
    def __init__(self):
        self.nil = Node()
        self.root = self.nil
        self.root.left = self.nil
        self.root.right = self.nil
        self.root.parent = self.nil

    def left_rotate(self, x):
        y = x.right
        x.right = y.left
        if not self.is_nil(y.left):
            y.left.parent = x
        y.parent = x.parent
        if self.is_nil(x.parent):
            self.root = y
        elif x.parent.left == x:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def right_rotate(self, y):
        x = y.left
        y.left = x.right
        if not self.is_nil(x.right):
            x.right.parent = y
        x.parent = y.parent
        if self.is_nil(y.parent):
            self.root = x
        elif y.parent.right == y:
            y.parent.right = x
        else:
            y.parent.left = x
        x.right = y
        y.parent = x

    def insert(self, key):
        z = Node(key)
        y = self.nil
        x = self.root
        while not self.is_nil(x):
            y = x
            if z.key < x.key:
                x.num_left += 1
                x = x.left
            else:
                x.num_right += 1
                x = x.right
        z.parent = y
        if self.is_nil(y):
            self.root = z
        elif z.key < y.key:
            y.left = z
        else:
            y.right = z
        z.left = self.nil
        z.right = self.nil
        z.color = Node.RED
        self.fix_insert(z)

    def fix_insert(self, z):
        while z.parent.color == Node.RED:
            if z.parent == z.parent.parent.left:
                y = z.parent.parent.right
                if y.color == Node.RED:
                    z.parent.color = Node.BLACK
                    y.color = Node.BLACK
                    z.parent.parent.color = Node.RED
                    z = z.parent.parent
                elif z == z.parent.right:
                    z = z.parent
                    self.left_rotate(z)
                else:
                    z.parent.color = Node.BLACK
                    z.parent.parent.color = Node.RED
                    self.right_rotate(z.parent.parent)
            else:
                y = z.parent.parent.left
                if y.color == Node.RED:
                    z.parent.color = Node.BLACK
                    y.color = Node.BLACK
                    z.parent.parent.color = Node.RED
                    z = z.parent.parent
                elif z == z.parent.left:
                    z = z.parent
                    self.right_rotate(z)
                else:
                    z.parent.color = Node.BLACK
                    z.parent.parent.color = Node.RED
                    self.left_rotate(z.parent.parent)
        self.root.color = Node.BLACK

    def is_nil(self, node):
        return node == self.nil

    def search(self, key):
        current = self.root
        while not self.is_nil(current):
            if current.key == key:
                return current
            elif current.key < key:
                current = current.right
            else:
                current = current.left
        return None

    def size(self):
        return self.root.num_left + self.root.num_right + 1
