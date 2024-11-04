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

    printInt64(res)
    printLine()


def readString():
    return input()

def readLine():
    return input()

def readInt():
    return int(input())

def readInt64():
    return int(input())

def readFloat64():
    return float(input())


def printString(value):
    print(value, end='')

def printLine():
    print()

def printSpace():
    print(' ', end='')

def printInt(value):
    print(value, end='')

def printInt64(value):
    print(value, end='')

def printFloat64(value):
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

def maxInt64(a, b):
    if a > b:
        return a
    else:
        return b

def minInt64(a, b):
    if a < b:
        return a
    else:
        return b

def absInt64(a):
    if a > 0:
        return a
    else:
        return -a

def maxFloat64(a, b):
    if a > b:
        return a
    else:
        return b

def minFloat64(a, b):
    if a < b:
        return a
    else:
        return b

def absFloat64(a):
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

    def swap(self, i, j):
        self.tuples[i], self.tuples[j] = self.tuples[j], self.tuples[i]


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

def maxInt64(a, b):
    if a > b:
        return a
    else:
        return b

def minInt64(a, b):
    if a < b:
        return a
    else:
        return b

def absInt64(a):
    if a > 0:
        return a
    else:
        return -a

def maxFloat64(a, b):
    if a > b:
        return a
    else:
        return b

def minFloat64(a, b):
    if a < b:
        return a
    else:
        return b

def absFloat64(a):
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
        if x is None:
            return None

        left = self.tmp
        right = self.tmp

        while True:
            if key.less(x.key):
                y = x.left
                if y is None:
                    break
                if key.less(y.key):
                    self.rotateRight(y, x)
                    x = y
                    if x.left is None:
                        break

                right.left = x
                right = x

                x = x.left
            elif x.key.less(key):
                y = x.right
                if y is None:
                    break
                if y.key.less(key):
                    self.rotateLeft(y, x)
                    x = y
                    if x.right is None:
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
        if left is None:
            return right
        elif right is None:
            return left
        left = self.splay(left, right.key)
        left.right = right
        return left

class Set:
    def __init__(self):
        self.tree = SplayTree()

    def __len__(self):
        return self.tree.len

    def insert(self, key):
        try:
            self.tree.insert(key)
        except:
            raise Exception("Such key already exists")

    def find(self, key):
        return self.tree.find(key)

    def remove(self, key):
        try:
            self.tree.remove(key)
        except:
            raise Exception("Such key doesn't exist")


class Scanner:
    def __init__(self, r):
        self.r = r
        self.split = scanWords
        self.maxTokenSize = 1 << 20
        self.token = b''
        self.buf = bytearray(4096)
        self.start = 0
        self.end = 0
        self.err = None

    def err(self):
        if self.err == io.EOF:
            return None
        return self.err

    def bytes(self):
        return self.token

    def text(self):
        return self.token.decode()

    def scan(self):
        while True:
            if self.end > self.start:
                advance, token, err = self.split(self.buf[self.start:self.end], self.err is not None)
                if err is not None:
                    self.setErr(err)
                    return False
                if not self.advance(advance):
                    return False
                self.token = token
                if token is not None:
                    return True

            if self.err is not None:
                self.start = 0
                self.end = 0
                return False

            if self.start > 0 and (self.end == len(self.buf) or self.start > len(self.buf)//2):
                self.buf[:self.end-self.start] = self.buf[self.start:self.end]
                self.end -= self.start
                self.start = 0

            if self.end == len(self.buf):
                if len(self.buf) >= self.maxTokenSize:
                    self.setErr("ErrTooLong")
                    return False
                newSize = len(self.buf) * 2
                if newSize > self.maxTokenSize:
                    newSize = self.maxTokenSize
                newBuf = bytearray(newSize)
                newBuf[:self.end-self.start] = self.buf[self.start:self.end]
                self.buf = newBuf
                self.end -= self.start
                self.start = 0
                continue

            for loop in range(101):
                n, err = self.r.readinto(self.buf[self.end:])
                self.end += n
                if err is not None:
                    self.setErr(err)
                    break
                if n > 0:
                    break
                if loop > 100:
                    self.setErr("ErrNoProgress")
                    break

    def advance(self, n):
        if n < 0:
            self.setErr("ErrNegativeAdvance")
            return False
        if n > self.end - self.start:
            self.setErr("ErrAdvanceTooFar")
            return False
        self.start += n
        return True

    def setErr(self, err):
        if self.err is None or self.err == io.EOF:
            self.err = err

def scanBytes(data, atEOF):
    if atEOF and len(data) == 0:
        return 0, None, None
    return 1, data[:1], None

errorRune = b'\xef\xbf\xbd'

def scanRunes(data, atEOF):
    if atEOF and len(data) == 0:
        return 0, None, None

    if data[0] < 0x80:
        return 1, data[:1], None

    _, width = utf8.decodeRune(data)
    if width > 1:
        return width, data[:width], None

    if not atEOF and not utf8.fullRune(data):
        return 0, None, None

    return 1, errorRune, None

def dropCR(data):
    if len(data) > 0 and data[-1] == '\r':
        return data[:-1]
    return data

def scanLines(data, atEOF):
    if atEOF and len(data) == 0:
        return 0, None, None
    i = data.find(b'\n')
    if i >= 0:
        return i+1, dropCR(data[:i]), None

    if atEOF:
        return len(data), dropCR(data), None

    return 0, None, None

def isSpace(r):
    if r <= 0xFF:
        if r == ord(' ') or r == ord('\t') or r == ord('\n') or r == ord('\v') or r == ord('\f') or r == ord('\r'):
            return True
        if r == 0x85 or r == 0xA0:
            return True
        return False

    if 0x2000 <= r <= 0x200a:
        return True
    if r == 0x1680 or r == 0x180e or r == 0x2028 or r == 0x2029 or r == 0x202f or r == 0x205f or r == 0x3000:
        return True
    return False

def scanWords(data, atEOF):
    start = 0
    while start < len(data):
        r, width = utf8.decodeRune(data[start:])
        if not isSpace(r):
            break
        start += width
    if atEOF and len(data) == 0:
        return 0, None, None
    for i in range(start, len(data)):
        r, width = utf8.decodeRune(data[i:])
        if isSpace(r):
            return i+width, data[start:i], None
    if atEOF and len(data) > start:
        return len(data), data[start:], None
    return 0, None, None

def main():
    solve()

if __name__ == "__main__":
    main()
