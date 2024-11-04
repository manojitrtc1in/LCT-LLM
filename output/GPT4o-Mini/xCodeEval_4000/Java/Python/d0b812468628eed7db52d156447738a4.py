import sys
from collections import deque
from math import sqrt, pow
from typing import List, Optional, Tuple

class Kattio:
    def __init__(self, input_stream=sys.stdin, output_stream=sys.stdout):
        self.r = input_stream
        self.o = output_stream
        self.st = None

    def next_line(self):
        return self.r.readline().strip()

    def next(self):
        while self.st is None or not self.st:
            self.st = self.next_line().split()
        return self.st.pop(0)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

class IceCave:
    power_set = []
    mod = int(pow(10, 9) + 7)

    @staticmethod
    def bfs(w: int, n: int) -> int:
        q = deque([w])
        h = {w: 0}
        min_val = float('inf')

        while q:
            s = q.popleft()
            if n == len(str(s)):
                return h[s]
            t = set(int(e) for e in str(s))
            for x in t:
                v = x * s
                if len(str(v)) > n:
                    continue
                if v not in h:
                    h[v] = h[s] + 1
                    q.append(v)
        return -1 if min_val == float('inf') else min_val

    @staticmethod
    def log2(n: int) -> int:
        cnt = 0
        while n > 1:
            n //= 2
            cnt += 1
        return cnt

    @staticmethod
    def bfs_graph(node: int, a: List[List[int]]) -> List[int]:
        q = deque([node])
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

    @staticmethod
    def get(n: int) -> int:
        sum_val = 0
        while n > 0:
            sum_val += n % 10
            n //= 10
        return sum_val

    @staticmethod
    def prime_factors(n: int) -> int:
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

    @staticmethod
    def print_prime_factorization(n: int) -> List[int]:
        a = []
        for i in range(1, int(sqrt(n)) + 1):
            if n % i == 0:
                if IceCave.is_prime(i):
                    a.append(i)
                    n //= i
                    i = 0
                elif IceCave.is_prime(n // i):
                    a.append(n // i)
                    n = i
                    i = 0
        return a

    @staticmethod
    def generate(ind: int, a: List[int], sub: List[int]):
        if ind == len(a):
            IceCave.power_set.append(sub)
            return
        have = sub + [a[ind]]
        IceCave.generate(ind + 1, a, have)
        IceCave.generate(ind + 1, a, sub)

    @staticmethod
    def factorial(n: int) -> int:
        if n <= 1:
            return 1
        result = n
        for t in range(n - 1, 1, -1):
            result *= t
        return result

    @staticmethod
    def is_palindrome(n: int) -> bool:
        return str(n) == str(n)[::-1]

    @staticmethod
    def is_prime(num: int) -> bool:
        if num <= 1:
            return False
        if num <= 3:
            return True
        if num % 2 == 0:
            return False
        for i in range(3, int(sqrt(num)) + 1, 2):
            if num % i == 0:
                return False
        return True

    @staticmethod
    def prefix_sum(a: List[int]):
        for i in range(1, len(a)):
            a[i] += a[i - 1]

    @staticmethod
    def suffix_sum(a: List[int]):
        for i in range(len(a) - 2, -1, -1):
            a[i] += a[i + 1]

    @staticmethod
    def mod(a: int, b: int) -> int:
        r = a % b
        return r + b if r < 0 else r

    @staticmethod
    def binary_to_decimal(w: str) -> int:
        return int(w, 2)

    @staticmethod
    def decimal_to_binary(n: int) -> str:
        return bin(n)[2:]

    @staticmethod
    def is_sorted(a: List[int]) -> bool:
        return all(a[i] <= a[i + 1] for i in range(len(a) - 1))

    @staticmethod
    def print_array(a: List[int]):
        print(" ".join(map(str, a)))

    @staticmethod
    def read_array(a: List[int]):
        for i in range(len(a)):
            a[i] = input.next_int()

    @staticmethod
    def lcm(x: int, y: int) -> int:
        return x // IceCave.gcd(x, y) * y

    @staticmethod
    def gcd(x: int, y: int) -> int:
        while y:
            x, y = y, x % y
        return x

    @staticmethod
    def simplify_fraction(a: int, b: int):
        gcd_val = IceCave.gcd(a, b)
        print(a // gcd_val, b // gcd_val)

class RedBlackNode:
    BLACK = 0
    RED = 1

    def __init__(self, key=None):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None
        self.num_left = 0
        self.num_right = 0
        self.color = RedBlackNode.BLACK

class RedBlackTree:
    def __init__(self):
        self.nil = RedBlackNode()
        self.root = self.nil
        self.root.left = self.nil
        self.root.right = self.nil
        self.root.parent = self.nil

    def left_rotate(self, x: RedBlackNode):
        self.left_rotate_fixup(x)
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

    def left_rotate_fixup(self, x: RedBlackNode):
        if self.is_nil(x.left) and self.is_nil(x.right.left):
            x.num_left = 0
            x.num_right = 0
            x.right.num_left = 1
        elif self.is_nil(x.left) and not self.is_nil(x.right.left):
            x.num_left = 0
            x.num_right = 1 + x.right.left.num_left + x.right.left.num_right
            x.right.num_left = 2 + x.right.left.num_left + x.right.left.num_right
        elif not self.is_nil(x.left) and self.is_nil(x.right.left):
            x.num_right = 0
            x.right.num_left = 2 + x.left.num_left + x.left.num_right
        else:
            x.num_right = 1 + x.right.left.num_left + x.right.left.num_right
            x.right.num_left = 3 + x.left.num_left + x.left.num_right + x.right.left.num_left + x.right.left.num_right

    def right_rotate(self, y: RedBlackNode):
        self.right_rotate_fixup(y)
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

    def right_rotate_fixup(self, y: RedBlackNode):
        if self.is_nil(y.right) and self.is_nil(y.left.right):
            y.num_right = 0
            y.num_left = 0
            y.left.num_right = 1
        elif self.is_nil(y.right) and not self.is_nil(y.left.right):
            y.num_right = 0
            y.num_left = 1 + y.left.right.num_right + y.left.right.num_left
            y.left.num_right = 2 + y.left.right.num_right + y.left.right.num_left
        elif not self.is_nil(y.right) and self.is_nil(y.left.right):
            y.num_left = 0
            y.left.num_right = 2 + y.right.num_right + y.right.num_left
        else:
            y.num_left = 1 + y.left.right.num_right + y.left.right.num_left
            y.left.num_right = 3 + y.right.num_right + y.right.num_left + y.left.right.num_right + y.left.right.num_left

    def insert(self, key):
        self.insert_node(RedBlackNode(key))

    def insert_node(self, z: RedBlackNode):
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
        z.color = RedBlackNode.RED
        self.insert_fixup(z)

    def insert_fixup(self, z: RedBlackNode):
        while z.parent.color == RedBlackNode.RED:
            if z.parent == z.parent.parent.left:
                y = z.parent.parent.right
                if y.color == RedBlackNode.RED:
                    z.parent.color = RedBlackNode.BLACK
                    y.color = RedBlackNode.BLACK
                    z.parent.parent.color = RedBlackNode.RED
                    z = z.parent.parent
                elif z == z.parent.right:
                    z = z.parent
                    self.left_rotate(z)
                else:
                    z.parent.color = RedBlackNode.BLACK
                    z.parent.parent.color = RedBlackNode.RED
                    self.right_rotate(z.parent.parent)
            else:
                y = z.parent.parent.left
                if y.color == RedBlackNode.RED:
                    z.parent.color = RedBlackNode.BLACK
                    y.color = RedBlackNode.BLACK
                    z.parent.parent.color = RedBlackNode.RED
                    z = z.parent.parent
                elif z == z.parent.left:
                    z = z.parent
                    self.right_rotate(z)
                else:
                    z.parent.color = RedBlackNode.BLACK
                    z.parent.parent.color = RedBlackNode.RED
                    self.left_rotate(z.parent.parent)
        self.root.color = RedBlackNode.BLACK

    def is_nil(self, node: RedBlackNode) -> bool:
        return node == self.nil

    def search(self, key) -> Optional[RedBlackNode]:
        current = self.root
        while not self.is_nil(current):
            if current.key == key:
                return current
            elif current.key < key:
                current = current.right
            else:
                current = current.left
        return None

    def size(self) -> int:
        return self.root.num_left + self.root.num_right + 1
