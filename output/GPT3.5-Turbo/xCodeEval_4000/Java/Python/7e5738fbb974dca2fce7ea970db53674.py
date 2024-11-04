class DSU:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.size = [1] * n

    def makeSet(self, v):
        self.parent[v] = v
        self.size[v] = 1

    def findSet(self, v):
        if v == self.parent[v]:
            return v
        self.parent[v] = self.findSet(self.parent[v])
        return self.parent[v]

    def unionSets(self, a, b):
        a = self.findSet(a)
        b = self.findSet(b)
        if a != b:
            if self.size[a] < self.size[b]:
                a, b = b, a
            self.parent[b] = a
            self.size[a] += self.size[b]


class FastFourierTransform:
    def fft(self, a, b, invert):
        count = len(a)
        i = 1
        j = 0
        while i < count:
            bit = count >> 1
            while j >= bit:
                j -= bit
                bit >>= 1
            j += bit
            if i < j:
                a[i], a[j] = a[j], a[i]
                b[i], b[j] = b[j], b[i]
            i += 1
        len = 2
        while len <= count:
            halfLen = len >> 1
            angle = 2 * math.pi / len
            if invert:
                angle = -angle
            wLenA = math.cos(angle)
            wLenB = math.sin(angle)
            i = 0
            while i < count:
                wA = 1
                wB = 0
                j = 0
                while j < halfLen:
                    uA = a[i + j]
                    uB = b[i + j]
                    vA = a[i + j + halfLen] * wA - b[i + j + halfLen] * wB
                    vB = a[i + j + halfLen] * wB + b[i + j + halfLen] * wA
                    a[i + j] = uA + vA
                    b[i + j] = uB + vB
                    a[i + j + halfLen] = uA - vA
                    b[i + j + halfLen] = uB - vB
                    nextWA = wA * wLenA - wB * wLenB
                    wB = wA * wLenB + wB * wLenA
                    wA = nextWA
                    j += 1
                i += len
            len <<= 1
        if invert:
            i = 0
            while i < count:
                a[i] /= count
                b[i] /= count
                i += 1

    def multiply(self, a, b):
        resultSize = 1 << (max(len(a), len(b)) - 1).bit_length()
        aReal = [0] * resultSize
        aImaginary = [0] * resultSize
        bReal = [0] * resultSize
        bImaginary = [0] * resultSize
        i = 0
        while i < len(a):
            aReal[i] = a[i]
            i += 1
        i = 0
        while i < len(b):
            bReal[i] = b[i]
            i += 1
        self.fft(aReal, aImaginary, False)
        self.fft(bReal, bImaginary, False)
        i = 0
        while i < resultSize:
            real = aReal[i] * bReal[i] - aImaginary[i] * bImaginary[i]
            aImaginary[i] = aImaginary[i] * bReal[i] + bImaginary[i] * aReal[i]
            aReal[i] = real
            i += 1
        self.fft(aReal, aImaginary, True)
        result = [0] * resultSize
        i = 0
        while i < resultSize:
            result[i] = round(aReal[i])
            i += 1
        return result


class NumberTheory:
    def isPrime(self, n):
        if n < 2:
            return False
        for x in range(2, int(n ** 0.5) + 1):
            if n % x == 0:
                return False
        return True

    def primeFactorisation(self, n):
        f = []
        for x in range(2, int(n ** 0.5) + 1):
            while n % x == 0:
                f.append(x)
                n //= x
        if n > 1:
            f.append(n)
        return f

    def sieveOfEratosthenes(self, n):
        sieve = [0] * (n + 1)
        for x in range(2, int(n ** 0.5) + 1):
            if sieve[x] != 0:
                continue
            for u in range(x * x, n + 1, x):
                if sieve[u] == 0:
                    sieve[u] = x
        return sieve

    def gcd(self, a, b):
        if b == 0:
            return a
        return self.gcd(b, a % b)

    def phi(self, n):
        result = n
        p = 2
        while p * p <= n:
            if n % p == 0:
                while n % p == 0:
                    n //= p
                result *= (1.0 - (1.0 / p))
            p += 1
        if n > 1:
            result *= (1.0 - (1.0 / n))
        return int(result)

    def extendedEuclid(self, a, b):
        if b == 0:
            return (a, 1, 0)
        (d, x, y) = self.extendedEuclid(b, a % b)
        return (d, y, x - (a // b) * y)

    def modularExponentiation(self, a, b, n):
        d = 1
        bString = bin(b)[2:]
        for i in range(len(bString)):
            d = (d * d) % n
            if bString[i] == '1':
                d = (d * a) % n
        return d


class Name:
    def __init__(self, d, x, y):
        self.d = d
        self.x = x
        self.y = y


class SuffixArray:
    def __init__(self, s):
        self.ALPHABET_SZ = 256
        self.N = len(s)
        self.T = [0] * self.N
        self.lcp = [0] * self.N
        self.sa = [0] * self.N
        self.sa2 = [0] * self.N
        self.rank = [0] * self.N
        self.tmp = [0] * self.N
        self.c = [0] * max(self.ALPHABET_SZ, self.N)
        self.construct(s)

    def toIntArray(self, s):
        arr = [0] * len(s)
        for i in range(len(s)):
            arr[i] = ord(s[i])
        return arr

    def construct(self, s):
        self.T = self.toIntArray(s)
        self.constructSuffixArray()
        self.kasai()

    def constructSuffixArray(self):
        for i in range(self.N):
            self.c[self.rank[i] = self.T[i]] += 1
        for i in range(1, self.ALPHABET_SZ):
            self.c[i] += self.c[i - 1]
        for i in range(self.N - 1, -1, -1):
            self.sa[--self.c[self.rank[i]]] = i
        for p in range(1, self.N):
            self.sa2[self.sa[0]] = r = 0
            for i in range(1, self.N):
                if not (self.rank[self.sa[i - 1]] == self.rank[self.sa[i]] and self.sa[i - 1] + p < self.N and self.sa[i] + p < self.N and self.rank[self.sa[i - 1] + p] == self.rank[self.sa[i] + p]):
                    r += 1
                self.sa2[self.sa[i]] = r
            self.tmp, self.sa, self.sa2 = self.sa, self.sa2, self.tmp
            self.rank[self.sa[0]] = r = 0
            for i in range(1, self.N):
                if not (self.sa2[self.sa[i - 1]] == self.sa2[self.sa[i]] and self.sa[i - 1] + p < self.N and self.sa[i] + p < self.N and self.sa2[self.sa[i - 1] + p] == self.sa2[self.sa[i] + p]):
                    r += 1
                self.rank[self.sa[i]] = r

    def kasai(self):
        inv = [0] * self.N
        for i in range(self.N):
            inv[self.sa[i]] = i
        k = 0
        for i in range(self.N):
            if inv[i] == self.N - 1:
                k = 0
                continue
            j = self.sa[inv[i] + 1]
            while i + k < self.N and j + k < self.N and self.T[i + k] == self.T[j + k]:
                k += 1
            self.lcp[inv[i]] = k
            if k > 0:
                k -= 1


class ZAlgorithm:
    def calculateZ(self, input):
        Z = [0] * len(input)
        left = 0
        right = 0
        for k in range(1, len(input)):
            if k > right:
                left = right = k
                while right < len(input) and input[right] == input[right - left]:
                    right += 1
                Z[k] = right - left
                right -= 1
            else:
                k1 = k - left
                if Z[k1] < right - k + 1:
                    Z[k] = Z[k1]
                else:
                    left = k
                    while right < len(input) and input[right] == input[right - left]:
                        right += 1
                    Z[k] = right - left
                    right -= 1
        return Z

    def matchPattern(self, text, pattern):
        newString = pattern + '$' + text
        Z = self.calculateZ(newString)
        result = []
        for i in range(len(Z)):
            if Z[i] == len(pattern):
                result.append(i - len(pattern) - 1)
        return result


class KMPAlgorithm:
    def computeTemporalArray(self, pattern):
        lps = [0] * len(pattern)
        index = 0
        i = 1
        while i < len(pattern):
            if pattern[i] == pattern[index]:
                lps[i] = index + 1
                index += 1
                i += 1
            else:
                if index != 0:
                    index = lps[index - 1]
                else:
                    lps[i] = 0
                    i += 1
        return lps

    def KMPMatcher(self, text, pattern):
        lps = self.computeTemporalArray(pattern)
        j = 0
        i = 0
        n = len(text)
        m = len(pattern)
        indices = []
        while i < n:
            if pattern[j] == text[i]:
                i += 1
                j += 1
            if j == m:
                indices.append(i - j)
                j = lps[j - 1]
            elif i < n and pattern[j] != text[i]:
                if j != 0:
                    j = lps[j - 1]
                else:
                    i += 1
        return indices


class Hashing:
    def computePowers(self, p, n, m):
        powers = [0] * n
        powers[0] = 1
        for i in range(1, n):
            powers[i] = (powers[i - 1] * p) % m
        return powers

    def computeHash(self, s):
        p = 31
        m = 1_000_000_009
        hashValue = 0
        powers = self.computePowers(p, len(s), m)
        for i in range(len(s)):
            ch = s[i]
            hashValue = (hashValue + (ord(ch) - ord('a') + 1) * powers[i]) % m
        return hashValue


class BasicFunctions:
    def min(self, A):
        return min(A)

    def max(self, A):
        return max(A)


class MergeSortInt:
    def merge(self, arr, l, m, r):
        n1 = m - l + 1
        n2 = r - m
        L = [0] * n1
        R = [0] * n2
        for i in range(n1):
            L[i] = arr[l + i]
        for j in range(n2):
            R[j] = arr[m + 1 + j]
        i = 0
        j = 0
        k = l
        while i < n1 and j < n2:
            if L[i] <= R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        while i < n1:
            arr[k] = L[i]
            i += 1
            k += 1
        while j < n2:
            arr[k] = R[j]
            j += 1
            k += 1

    def sort(self, arr, l, r):
        if l < r:
            m = (l + r) // 2
            self.sort(arr, l, m)
            self.sort(arr, m + 1, r)
            self.merge(arr, l, m, r)


class MergeSortLong:
    def merge(self, arr, l, m, r):
        n1 = m - l + 1
        n2 = r - m
        L = [0] * n1
        R = [0] * n2
        for i in range(n1):
            L[i] = arr[l + i]
        for j in range(n2):
            R[j] = arr[m + 1 + j]
        i = 0
        j = 0
        k = l
        while i < n1 and j < n2:
            if L[i] <= R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        while i < n1:
            arr[k] = L[i]
            i += 1
            k += 1
        while j < n2:
            arr[k] = R[j]
            j += 1
            k += 1

    def sort(self, arr, l, r):
        if l < r:
            m = (l + r) // 2
            self.sort(arr, l, m)
            self.sort(arr, m + 1, r)
            self.merge(arr, l, m, r)


class Node:
    def __init__(self, s):
        self.s = s

    def __eq__(self, other):
        if isinstance(other, Node):
            return self.s == other.s
        return False

    def __hash__(self):
        return len(self.s)


class Reader:
    def __init__(self):
        self.BUFFER_SIZE = 1 << 16
        self.din = sys.stdin
        self.buffer = bytearray(self.BUFFER_SIZE)
        self.bufferPointer, self.bytesRead = 0, 0

    def readLine(self):
        buf = bytearray()
        while True:
            if self.bufferPointer == self.bytesRead:
                self.bufferPointer = 0
                self.bytesRead = self.din.readinto(self.buffer)
                if self.bytesRead == -1:
                    break
            if self.buffer[self.bufferPointer] == ord('\n'):
                self.bufferPointer += 1
                break
            else:
                buf.append(self.buffer[self.bufferPointer])
                self.bufferPointer += 1
        return buf.decode()

    def nextInt(self):
        ret = 0
        c = self.read()
        while c <= ord(' '):
            c = self.read()
        neg = c == ord('-')
        if neg:
            c = self.read()
        while c >= ord('0') and c <= ord('9'):
            ret = ret * 10 + c - ord('0')
            c = self.read()
        if neg:
            return -ret
        return ret

    def nextLong(self):
        ret = 0
        c = self.read()
        while c <= ord(' '):
            c = self.read()
        neg = c == ord('-')
        if neg:
            c = self.read()
        while c >= ord('0') and c <= ord('9'):
            ret = ret * 10 + c - ord('0')
            c = self.read()
        if neg:
            return -ret
        return ret

    def nextDouble(self):
        ret = 0
        div = 1
        c = self.read()
        while c <= ord(' '):
            c = self.read()
        neg = c == ord('-')
        if neg:
            c = self.read()
        while c >= ord('0') and c <= ord('9'):
            ret = ret * 10 + c - ord('0')
            c = self.read()
        if c == ord('.'):
            c = self.read()
            while c >= ord('0') and c <= ord('9'):
                ret += (c - ord('0')) / (div * 10)
                div *= 10
                c = self.read()
        if neg:
            return -ret
        return ret

    def fillBuffer(self):
        bytesRead = self.din.readinto(self.buffer)
        if bytesRead == -1:
            self.buffer[0] = -1

    def read(self):
        if self.bufferPointer == self.bytesRead:
            self.fillBuffer()
        self.bufferPointer += 1
        return self.buffer[self.bufferPointer - 1]

    def close(self):
        if self.din is None:
            return
        self.din.close()


class FenwickTree:
    def update(self, fenwickTree, delta, index):
        index += 1
        while index < len(fenwickTree):
            fenwickTree[index] += delta
            index += index & -index

    def prefixSum(self, fenwickTree, index):
        sum = 0
        index += 1
        while index > 0:
            sum += fenwickTree[index]
            index -= index & -index
        return sum


class SegmentTree:
    def nextPowerOfTwo(self, num):
        if num == 0:
            return 1
        if num > 0 and (num & (num - 1)) == 0:
            return num
        while (num & (num - 1)) > 0:
            num = num & (num - 1)
        return num << 1

    def createSegmentTree(self, input):
        np2 = self.nextPowerOfTwo(len(input))
        segmentTree = [0] * (np2 * 2 - 1)
        for i in range(len(segmentTree)):
            segmentTree[i] = float('-inf')
        self.constructSegmentTree(segmentTree, input, 0, len(input) - 1, 0)
        return segmentTree

    def constructSegmentTree(self, segmentTree, input, low, high, pos):
        if low == high:
            segmentTree[pos] = input[low]
            return
        mid = (low + high) // 2
        self.constructSegmentTree(segmentTree, input, low, mid, 2 * pos + 1)
        self.constructSegmentTree(segmentTree, input, mid + 1, high, 2 * pos + 2)
        segmentTree[pos] = max(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2])

    def rangeMinimumQuery(self, segmentTree, qlow, qhigh, len):
        return self.rangeMinimumQuery(segmentTree, qlow, qhigh, 0, len - 1, 0)

    def rangeMinimumQuery(self, segmentTree, qlow, qhigh, low, high, pos):
        if qlow <= low and qhigh >= high:
            return segmentTree[pos]
        if qlow > high or qhigh < low:
            return float('-inf')
        mid = (low + high) // 2
        return max(self.rangeMinimumQuery(segmentTree, qlow, qhigh, low, mid, 2 * pos + 1),
                   self.rangeMinimumQuery(segmentTree, qlow, qhigh, mid + 1, high, 2 * pos + 2))


class Trie:
    class TrieNode:
        def __init__(self):
            self.children = {}
            self.endOfWord = False

    def __init__(self):
        self.root = self.TrieNode()

    def insert(self, word):
        current = self.root
        for i in range(len(word)):
            ch = word[i]
            node = current.children.get(ch)
            if node is None:
                node = self.TrieNode()
                current.children[ch] = node
            current = node
        current.endOfWord = True

    def search(self, word):
        current = self.root
        for i in range(len(word)):
            ch = word[i]
            node = current.children.get(ch)
            if node is None:
                return False
            current = node
        return current.endOfWord

    def delete(self, word):
        self.delete(self.root, word, 0)

    def delete(self, current, word, index):
        if index == len(word):
            if not current.endOfWord:
                return False
            current.endOfWord = False
            return len(current.children) == 0
        ch = word[index]
        node = current.children.get(ch)
        if node is None:
            return False
        shouldDeleteCurrentNode = self.delete(node, word, index + 1)
        if shouldDeleteCurrentNode:
            current.children.pop(ch)
            return len(current.children) == 0
        return False
