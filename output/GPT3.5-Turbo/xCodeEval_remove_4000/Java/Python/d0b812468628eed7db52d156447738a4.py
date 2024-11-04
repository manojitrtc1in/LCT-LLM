import sys
from collections import deque
from typing import List, Tuple, Dict, Any


class id7:
    def __init__(self, i: Any = sys.stdin, o: Any = sys.stdout):
        self.r = i
        self.w = o
        self.st = None

    def next_line(self) -> str:
        try:
            return self.r.readline()
        except IOError as e:
            print(e)

    def next(self) -> str:
        try:
            while self.st is None or not self.st.hasMoreTokens():
                self.st = self.r.readline().split()
            return self.st.nextToken()
        except Exception as e:
            pass
        return None

    def next_int(self) -> int:
        return int(self.next())

    def next_double(self) -> float:
        return float(self.next())

    def next_long(self) -> int:
        return int(self.next())


class id6:
    def __init__(self):
        self.input = id7()
        self.log = sys.stdout
        self.powerSet = []
        self.mod = int(1e9 + 7)
        self.dp = None

    def main(self) -> None:
        n = self.input.next_int()
        w = self.input.next_long()
        self.log.write(str(self.bfs(w, n)) + "\n")
        self.log.flush()

    def bfs(self, w: int, n: int) -> int:
        q = deque()
        q.append(w)
        h = {}
        h[w] = 0
        min_val = float('inf')
        while q:
            s = q.popleft()
            if n == len(str(s)):
                return h[s]
            t = set()
            e = str(s)
            for i in range(len(e)):
                t.add(int(e[i]))
            for x in t:
                v = x * s
                if len(str(v)) > n:
                    continue
                if v not in h:
                    h[v] = h[s] + 1
                    q.append(v)
        return -1 if min_val == float('inf') else min_val

    def log2(self, n: int) -> int:
        cnt = 0
        while n > 1:
            n //= 2
            cnt += 1
        return cnt

    def bfs(self, node: int, a: List[List[int]]) -> List[int]:
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

    def get(self, n: int) -> int:
        s = 0
        while n > 0:
            s += n % 10
            n //= 10
        return s

    def primeFactors(self, n: int) -> int:
        s = 1
        while n % 2 == 0:
            s *= 2
            n //= 2
        for i in range(3, int(n ** 0.5) + 1, 2):
            while n % i == 0:
                s *= i
                n //= i
            if n < i:
                break
        if n > 2:
            s *= n
        return s

    def id9(self, n: int) -> List[int]:
        a = []
        for i in range(1, int(n ** 0.5) + 1):
            if n % i == 0:
                if self.isPrime(i):
                    a.append(i)
                    n //= i
                    i = 0
                elif self.isPrime(n // i):
                    a.append(n // i)
                    n = i
                    i = 0
        return a

    def generate(self, ind: int, a: List[int], sub: List[int]) -> None:
        if ind == len(a):
            self.powerSet.append(sub)
            return
        have = sub[:]
        less = sub[:]
        have.append(a[ind])
        self.generate(ind + 1, a, have)
        self.generate(ind + 1, a, less)

    def factorial(self, n: int) -> int:
        if n <= 1:
            return 1
        t = n - 1
        while t > 1:
            n *= t
            t -= 1
        return n

    def isPalindrome(self, n: int) -> bool:
        t = n
        ans = 0
        while t > 0:
            ans = ans * 10 + t % 10
            t //= 10
        return ans == n

    class tri:
        def __init__(self, x: int, y: int, z: int):
            self.x = x
            self.y = y
            self.z = z

    def isPrime(self, num: int) -> bool:
        if num == 1:
            return False
        if num == 2:
            return True
        if num % 2 == 0:
            return False
        if num == 3:
            return True
        for i in range(3, int(num ** 0.5) + 1, 2):
            if num % i == 0:
                return False
        return True

    def prefixSum(self, a: List[int]) -> None:
        for i in range(1, len(a)):
            a[i] += a[i - 1]

    def suffixSum(self, a: List[int]) -> None:
        for i in range(len(a) - 2, -1, -1):
            a[i] += a[i + 1]

    def mod(self, a: int, b: int) -> int:
        r = a % b
        return r + b if r < 0 else r

    def id13(self, w: str) -> int:
        r = 0
        l = 0
        for i in range(len(w) - 1, -1, -1):
            x = int(w[i]) * 2 ** l
            r += x
            l += 1
        return r

    def id3(self, n: int) -> str:
        w = ""
        while n > 0:
            w = str(n % 2) + w
            n //= 2
        return w

    def isSorted(self, a: List[int]) -> bool:
        for i in range(len(a) - 1):
            if a[i] > a[i + 1]:
                return False
        return True

    def print(self, a: List[int]) -> None:
        for i in range(len(a)):
            self.log.write(str(a[i]) + " ")
        self.log.write("\n")

    def read(self, a: List[int]) -> None:
        for i in range(len(a)):
            a[i] = self.input.next_int()

    class pair:
        def __init__(self, x: int, y: int):
            self.x = x
            self.y = y

        def __str__(self) -> str:
            return str(self.x) + " " + str(self.y)

    def LCM(self, x: int, y: int) -> int:
        return x // self.GCD(x, y) * y

    def GCD(self, x: int, y: int) -> int:
        if y == 0:
            return x
        return self.GCD(y, x % y)

    def id10(self, a: int, b: int) -> None:
        GCD = self.GCD(a, b)
        print(a // GCD, b // GCD)

    class id0:
        BLACK = 0
        RED = 1

        def __init__(self, key: Any = None):
            self.key = key
            self.parent = None
            self.left = None
            self.right = None
            self.numLeft = 0
            self.numRight = 0
            self.color = self.BLACK

    class id5:
        def __init__(self):
            self.nil = id6.id0()
            self.root = self.nil

        def leftRotate(self, x: id6.id0) -> None:
            y = x.right
            x.right = y.left
            if not self.isNil(y.left):
                y.left.parent = x
            y.parent = x.parent
            if self.isNil(x.parent):
                self.root = y
            elif x.parent.left == x:
                x.parent.left = y
            else:
                x.parent.right = y
            y.left = x
            x.parent = y

        def rightRotate(self, y: id6.id0) -> None:
            x = y.left
            y.left = x.right
            if not self.isNil(x.right):
                x.right.parent = y
            x.parent = y.parent
            if self.isNil(y.parent):
                self.root = x
            elif y.parent.right == y:
                y.parent.right = x
            else:
                y.parent.left = x
            x.right = y
            y.parent = x

        def insert(self, key: Any) -> None:
            z = id6.id0(key)
            y = self.nil
            x = self.root
            while not self.isNil(x):
                y = x
                if z.key < x.key:
                    x.numLeft += 1
                    x = x.left
                else:
                    x.numRight += 1
                    x = x.right
            z.parent = y
            if self.isNil(y):
                self.root = z
            elif z.key < y.key:
                y.left = z
            else:
                y.right = z
            z.left = self.nil
            z.right = self.nil
            z.color = id6.id0.RED
            self.insertFixup(z)

        def insertFixup(self, z: id6.id0) -> None:
            while z.parent.color == id6.id0.RED:
                if z.parent == z.parent.parent.left:
                    y = z.parent.parent.right
                    if y.color == id6.id0.RED:
                        z.parent.color = id6.id0.BLACK
                        y.color = id6.id0.BLACK
                        z.parent.parent.color = id6.id0.RED
                        z = z.parent.parent
                    elif z == z.parent.right:
                        z = z.parent
                        self.leftRotate(z)
                    else:
                        z.parent.color = id6.id0.BLACK
                        z.parent.parent.color = id6.id0.RED
                        self.rightRotate(z.parent.parent)
                else:
                    y = z.parent.parent.left
                    if y.color == id6.id0.RED:
                        z.parent.color = id6.id0.BLACK
                        y.color = id6.id0.BLACK
                        z.parent.parent.color = id6.id0.RED
                        z = z.parent.parent
                    elif z == z.parent.left:
                        z = z.parent
                        self.rightRotate(z)
                    else:
                        z.parent.color = id6.id0.BLACK
                        z.parent.parent.color = id6.id0.RED
                        self.leftRotate(z.parent.parent)
            self.root.color = id6.id0.BLACK

        def treeMinimum(self, node: id6.id0) -> id6.id0:
            while not self.isNil(node.left):
                node = node.left
            return node

        def successor(self, x: id6.id0) -> id6.id0:
            if not self.isNil(x.right):
                return self.treeMinimum(x.right)
            y = x.parent
            while not self.isNil(y) and x == y.right:
                x = y
                y = y.parent
            return y

        def remove(self, v: id6.id0) -> None:
            z = self.search(v.key)
            x = None
            y = None
            if self.isNil(z.left) or self.isNil(z.right):
                y = z
            else:
                y = self.successor(z)
            if not self.isNil(y.left):
                x = y.left
            else:
                x = y.right
            x.parent = y.parent
            if self.isNil(y.parent):
                self.root = x
            elif not self.isNil(y.parent.left) and y.parent.left == y:
                y.parent.left = x
            elif not self.isNil(y.parent.right) and y.parent.right == y:
                y.parent.right = x
            if y != z:
                z.key = y.key
            if y.color == id6.id0.BLACK:
                self.removeFixup(x)

        def removeFixup(self, x: id6.id0) -> None:
            while x != self.root and x.color == id6.id0.BLACK:
                if x == x.parent.left:
                    w = x.parent.right
                    if w.color == id6.id0.RED:
                        w.color = id6.id0.BLACK
                        x.parent.color = id6.id0.RED
                        self.leftRotate(x.parent)
                        w = x.parent.right
                    if w.left.color == id6.id0.BLACK and w.right.color == id6.id0.BLACK:
                        w.color = id6.id0.RED
                        x = x.parent
                    else:
                        if w.right.color == id6.id0.BLACK:
                            w.left.color = id6.id0.BLACK
                            w.color = id6.id0.RED
                            self.rightRotate(w)
                            w = x.parent.right
                        w.color = x.parent.color
                        x.parent.color = id6.id0.BLACK
                        w.right.color = id6.id0.BLACK
                        self.leftRotate(x.parent)
                        x = self.root
                else:
                    w = x.parent.left
                    if w.color == id6.id0.RED:
                        w.color = id6.id0.BLACK
                        x.parent.color = id6.id0.RED
                        self.rightRotate(x.parent)
                        w = x.parent.left
                    if w.right.color == id6.id0.BLACK and w.left.color == id6.id0.BLACK:
                        w.color = id6.id0.RED
                        x = x.parent
                    else:
                        if w.left.color == id6.id0.BLACK:
                            w.right.color = id6.id0.BLACK
                            w.color = id6.id0.RED
                            self.leftRotate(w)
                            w = x.parent.left
                        w.color = x.parent.color
                        x.parent.color = id6.id0.BLACK
                        w.left.color = id6.id0.BLACK
                        self.rightRotate(x.parent)
                        x = self.root
            x.color = id6.id0.BLACK

        def search(self, key: Any) -> id6.id0:
            current = self.root
            while not self.isNil(current):
                if current.key == key:
                    return current
                elif current.key < key:
                    current = current.right
                else:
                    current = current.left
            return None

        def numGreater(self, key: Any) -> int:
            return self.countGreater(self.root, key)

        def countGreater(self, node: id6.id0, key: Any) -> int:
            if self.isNil(node):
                return 0
            elif key < node.key:
                return 1 + node.numRight + self.countGreater(node.left, key)
            else:
                return self.countGreater(node.right, key)

        def numLess(self, key: Any) -> int:
            return self.countLess(self.root, key)

        def countLess(self, node: id6.id0, key: Any) -> int:
            if self.isNil(node):
                return 0
            elif key <= node.key:
                return self.countLess(node.left, key)
            else:
                return 1 + node.numLeft + self.countLess(node.right, key)

        def size(self) -> int:
            return self.root.numLeft + self.root.numRight + 1

        def isNil(self, node: id6.id0) -> bool:
            return node == self.nil


if __name__ == "__main__":
    id6().main()
