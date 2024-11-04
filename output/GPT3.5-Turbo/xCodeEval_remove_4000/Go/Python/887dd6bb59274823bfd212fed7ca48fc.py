MOD = 1000 * 1000 * 1000 + 7

def solve():
    a = readInt()
    b = readInt()
    
    r = 0
    for i in range(1, b):
        r += i
        if r >= MOD:
            r -= MOD
    
    res = a * r % MOD
    
    k = 0
    for i in range(1, a+1):
        k += i * r % MOD
        if k >= MOD:
            k -= MOD
    
    res += b * k % MOD
    if res >= MOD:
        res -= MOD
    
    id5(res)
    printLine()


def readString():
    return input()

def readLine():
    return input()

def readInt():
    return int(input())

def id8():
    return int(input())

def id4():
    return float(input())


def printString(value):
    print(value, end='')

def printLine():
    print()

def printSpace():
    print(' ', end='')

def printInt(value):
    print(value, end='')

def id5(value):
    print(value, end='')

def id6(value):
    print(value, end='')


def maxInt(a, b):
    if a > b:
        return a
    else:
        return b

def minInt(a, b):
    if a < b:
        return a
    else:
        return b

def absInt(a):
    if a > 0:
        return a
    else:
        return -a

def id2(a, b):
    if a > b:
        return a
    else:
        return b

def id9(a, b):
    if a < b:
        return a
    else:
        return b

def id14(a):
    if a > 0:
        return a
    else:
        return -a

def id11(a, b):
    if a > b:
        return a
    else:
        return b

def id0(a, b):
    if a < b:
        return a
    else:
        return b

def id12(a):
    if a > 0:
        return a
    else:
        return -a


class Tuple:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def equals(self, key):
        return self.a == key.a

    def less(self, key):
        return self.a < key.a

class TupleSlice:
    def __init__(self, tuples):
        self.tuples = tuples

    def __len__(self):
        return len(self.tuples)

    def __getitem__(self, index):
        return self.tuples[index]

    def __setitem__(self, index, value):
        self.tuples[index] = value

    def less(self, i, j):
        return self.tuples[i].less(self.tuples[j])

def maxInt(a, b):
    if a > b:
        return a
    else:
        return b

def minInt(a, b):
    if a < b:
        return a
    else:
        return b

def absInt(a):
    if a > 0:
        return a
    else:
        return -a

def id2(a, b):
    if a > b:
        return a
    else:
        return b

def id9(a, b):
    if a < b:
        return a
    else:
        return b

def id14(a):
    if a > 0:
        return a
    else:
        return -a

def id11(a, b):
    if a > b:
        return a
    else:
        return b

def id0(a, b):
    if a < b:
        return a
    else:
        return b

def id12(a):
    if a > 0:
        return a
    else:
        return -a


class Int:
    def __init__(self, value):
        self.value = value

    def equals(self, key):
        return self.value == key.value

    def less(self, key):
        return self.value < key.value


class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class SplayTree:
    def __init__(self):
        self.root = None
        self.tmp = Node(None)
        self.len = 0

    def rotateLeft(self, x, p):
        p.right = x.left
        x.left = p

    def rotateRight(self, x, p):
        p.left = x.right
        x.right = p

    def splay(self, x, key):
        if x == None:
            return None

        left = self.tmp
        right = self.tmp

        while True:
            if key.less(x.key):
                y = x.left
                if y == None:
                    break
                if key.less(y.key):
                    self.rotateRight(y, x)
                    x = y
                    if x.left == None:
                        break

                right.left = x
                right = x

                x = x.left
            elif x.key.less(key):
                y = x.right
                if y == None:
                    break
                if y.key.less(key):
                    self.rotateLeft(y, x)
                    x = y
                    if x.right == None:
                        break

                left.right = x
                left = x

                x = x.right
            else:
                break

        left.right = x.left
        right.left = x.right
        x.left = self.tmp.right
        x.right = self.tmp.left

        return x

    def split(self, key):
        self.root = self.splay(self.root, key)
        if self.root.key.equals(key) or self.root.key.less(key):
            right = self.root.right
            self.root.right = None
            return self.root, right
        else:
            left = self.root.left
            self.root.left = None
            return left, self.root

    def join(self, left, right):
        if left == None:
            return right
        elif right == None:
            return left
        left = self.splay(left, right.key)
        left.right = right
        return left

    def insert(self, key):
        if self.root == None:
            self.root = Node(key)
            self.len += 1
        else:
            self.root = self.splay(self.root, key)
            if self.root.key.equals(key):
                raise Exception("Such key already exists")
            else:
                left, right = self.split(key)
                self.root = Node(key)
                self.root.left = left
                self.root.right = right
                self.len += 1

    def find(self, key):
        if self.root == None:
            return False
        self.root = self.splay(self.root, key)
        return self.root.key.equals(key)

    def remove(self, key):
        self.root = self.splay(self.root, key)
        if self.root == None or not self.root.key.equals(key):
            raise Exception("Such key doesn't exist")
        self.root = self.join(self.split(key))

def readInt():
    return int(input())

def id5(value):
    print(value, end='')

def printLine():
    print()

def solve():
    a = readInt()
    b = readInt()
    
    r = 0
    for i in range(1, b):
        r += i
        if r >= MOD:
            r -= MOD
    
    res = a * r % MOD
    
    k = 0
    for i in range(1, a+1):
        k += i * r % MOD
        if k >= MOD:
            k -= MOD
    
    res += b * k % MOD
    if res >= MOD:
        res -= MOD
    
    id5(res)
    printLine()

solve()
