import sys
import math
from collections import defaultdict

class Reader:
    def __init__(self):
        self.buffer = sys.stdin.read().split()
        self.index = 0

    def next_long(self):
        value = int(self.buffer[self.index])
        self.index += 1
        return value

class DSU:
    def __init__(self, n):
        self.parent = [-1] * n
        self.size = [0] * n

    def make_set(self, v):
        self.parent[v] = v
        self.size[v] = 1

    def find_set(self, v):
        if v == self.parent[v]:
            return v
        self.parent[v] = self.find_set(self.parent[v])
        return self.parent[v]

    def union_sets(self, a, b):
        a = self.find_set(a)
        b = self.find_set(b)
        if a != b:
            if self.size[a] < self.size[b]:
                a, b = b, a
            self.parent[b] = a
            self.size[a] += self.size[b]

class FFT:
    def fft(self, a, b, invert):
        count = len(a)
        j = 0
        for i in range(1, count):
            bit = count >> 1
            while j >= bit:
                j -= bit
                bit >>= 1
            j += bit
            if i < j:
                a[i], a[j] = a[j], a[i]
                b[i], b[j] = b[j], b[i]

        for length in range(2, count + 1, length << 1):
            half_length = length >> 1
            angle = 2 * math.pi / length
            if invert:
                angle = -angle
            id17 = math.cos(angle)
            id2 = math.sin(angle)
            for i in range(0, count, length):
                wA = 1
                wB = 0
                for j in range(half_length):
                    uA = a[i + j]
                    uB = b[i + j]
                    vA = a[i + j + half_length] * wA - b[i + j + half_length] * wB
                    vB = a[i + j + half_length] * wB + b[i + j + half_length] * wA
                    a[i + j] = uA + vA
                    b[i + j] = uB + vB
                    a[i + j + half_length] = uA - vA
                    b[i + j + half_length] = uB - vB
                    next_wA = wA * id17 - wB * id2
                    wB = wA * id2 + wB * id17
                    wA = next_wA

        if invert:
            for i in range(count):
                a[i] /= count
                b[i] /= count

    def multiply(self, a, b):
        result_size = 1 << (math.ceil(math.log2(max(len(a), len(b)) + 1)) + 1)
        a_real = [0.0] * result_size
        b_real = [0.0] * result_size
        for i in range(len(a)):
            a_real[i] = a[i]
        for i in range(len(b)):
            b_real[i] = b[i]
        id10 = [0.0] * result_size
        id30 = [0.0] * result_size
        self.fft(a_real, id10, False)
        self.fft(b_real, id30, False)
        for i in range(result_size):
            real = a_real[i] * b_real[i] - id10[i] * id30[i]
            id10[i] = id10[i] * b_real[i] + id30[i] * a_real[i]
            a_real[i] = real
        self.fft(a_real, id10, True)
        return [round(a_real[i]) for i in range(result_size)]

class NumberTheory:
    def is_prime(self, n):
        if n < 2:
            return False
        for x in range(2, int(math.sqrt(n)) + 1):
            if n % x == 0:
                return False
        return True

    def prime_factors(self, n):
        f = []
        for x in range(2, int(math.sqrt(n)) + 1):
            while n % x == 0:
                f.append(x)
                n //= x
        if n > 1:
            f.append(n)
        return f

    def sieve(self, n):
        sieve = [0] * (n + 1)
        for x in range(2, int(math.sqrt(n)) + 1):
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
        for p in range(2, int(math.sqrt(n)) + 1):
            if n % p == 0:
                while n % p == 0:
                    n //= p
                result *= (1.0 - (1.0 / p))
        if n > 1:
            result *= (1.0 - (1.0 / n))
        return int(result)

    def extended_gcd(self, a, b):
        if b == 0:
            return Name(a, 1, 0)
        n1 = self.extended_gcd(b, a % b)
        return Name(n1.d, n1.y, n1.x - (a // b) * n1.y)

    def modular_exponentiation(self, a, b, n):
        d = 1
        b_string = bin(b)[2:]
        for i in range(len(b_string)):
            d = (d * d) % n
            if b_string[i] == '1':
                d = (d * a) % n
        return d

class Name:
    def __init__(self, d, x, y):
        self.d = d
        self.x = x
        self.y = y

class SuffixArray:
    def __init__(self, s):
        self.T = self.to_int_array(s)
        self.N = len(self.T)
        self.sa = [0] * self.N
        self.sa2 = [0] * self.N
        self.rank = [0] * self.N
        self.c = [0] * max(256, self.N)
        self.construct()
        self.kasai()

    @staticmethod
    def to_int_array(s):
        return [ord(ch) for ch in s]

    def construct(self):
        for i in range(self.N):
            self.c[self.rank[i] := self.T[i]] += 1
        for i in range(1, 256):
            self.c[i] += self.c[i - 1]
        for i in range(self.N - 1, -1, -1):
            self.sa[self.c[self.T[i]] - 1] = i
            self.c[self.T[i]] -= 1
        p = 1
        while p < self.N:
            r = 0
            for i in range(self.N - p, self.N):
                self.sa2[r] = i
                r += 1
            for i in range(self.N):
                if self.sa[i] >= p:
                    self.sa2[r] = self.sa[i] - p
                    r += 1
            self.c = [0] * max(256, self.N)
            for i in range(self.N):
                self.c[self.rank[i]] += 1
            for i in range(1, 256):
                self.c[i] += self.c[i - 1]
            for i in range(self.N - 1, -1, -1):
                self.sa[self.c[self.rank[self.sa2[i]]] - 1] = self.sa2[i]
                self.c[self.rank[self.sa2[i]]] -= 1
            self.sa2[self.sa[0]] = r = 0
            for i in range(1, self.N):
                if (self.rank[self.sa[i - 1]] == self.rank[self.sa[i]] and
                        self.sa[i - 1] + p < self.N and
                        self.sa[i] + p < self.N and
                        self.rank[self.sa[i - 1] + p] == self.rank[self.sa[i] + p]):
                    r += 1
                self.sa2[self.sa[i]] = r
            self.tmp = self.rank
            self.rank = self.sa2
            self.sa2 = self.tmp
            if r == self.N - 1:
                break

    def kasai(self):
        self.lcp = [0] * self.N
        inv = [0] * self.N
        for i in range(self.N):
            inv[self.sa[i]] = i
        len = 0
        for i in range(self.N):
            if inv[i] > 0:
                k = self.sa[inv[i] - 1]
                while (i + len < self.N and k + len < self.N and self.T[i + len] == self.T[k + len]):
                    len += 1
                self.lcp[inv[i] - 1] = len
                if len > 0:
                    len -= 1

class ZAlgorithm:
    def calculate_z(self, input):
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

    def match_pattern(self, text, pattern):
        new_string = pattern + ['$'] + text
        result = []
        Z = self.calculate_z(new_string)
        for i in range(len(Z)):
            if Z[i] == len(pattern):
                result.append(i - len(pattern) - 1)
        return result

class KMP:
    def compute_lps(self, pattern):
        lps = [0] * len(pattern)
        index = 0
        for i in range(1, len(pattern)):
            if pattern[i] == pattern[index]:
                lps[i] = index + 1
                index += 1
            else:
                if index != 0:
                    index = lps[index - 1]
                else:
                    lps[i] = 0
        return lps

    def kmp_search(self, text, pattern):
        lps = self.compute_lps(pattern)
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
    def compute_hash(self, s):
        p = 31
        m = 1_000_000_009
        hash_value = 0
        powers = self.compute_powers(p, len(s), m)
        for i in range(len(s)):
            ch = s[i]
            hash_value = (hash_value + (ord(ch) - ord('a') + 1) * powers[i]) % m
        return hash_value

    def compute_powers(self, p, n, m):
        powers = [1] * n
        for i in range(1, n):
            powers[i] = (powers[i - 1] * p) % m
        return powers

class BasicFunctions:
    @staticmethod
    def min(A):
        return min(A)

    @staticmethod
    def max(A):
        return max(A)

class MergeSort:
    @staticmethod
    def merge(arr, l, m, r):
        n1 = m - l + 1
        n2 = r - m
        L = arr[l:m + 1]
        R = arr[m + 1:r + 1]
        i = j = 0
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

    @staticmethod
    def sort(arr, l, r):
        if l < r:
            m = (l + r) // 2
            MergeSort.sort(arr, l, m)
            MergeSort.sort(arr, m + 1, r)
            MergeSort.merge(arr, l, m, r)

class Node:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __eq__(self, other):
        if other is None:
            return False
        if not isinstance(other, Node):
            return False
        return self.x == other.x and self.y == other.y

    def __hash__(self):
        return hash(self.x)

class SegmentTree:
    def __init__(self, input):
        self.np2 = self.next_power_of_two(len(input))
        self.segment_tree = [float('-inf')] * (self.np2 * 2 - 1)
        self.build_segment_tree(input, 0, len(input) - 1, 0)

    @staticmethod
    def next_power_of_two(num):
        if num == 0:
            return 1
        if num > 0 and (num & (num - 1)) == 0:
            return num
        while (num & (num - 1)) > 0:
            num = num & (num - 1)
        return num << 1

    def build_segment_tree(self, segment_tree, input, low, high, pos):
        if low == high:
            self.segment_tree[pos] = input[low]
            return
        mid = (low + high) // 2
        self.build_segment_tree(segment_tree, input, low, mid, 2 * pos + 1)
        self.build_segment_tree(segment_tree, input, mid + 1, high, 2 * pos + 2)
        self.segment_tree[pos] = max(self.segment_tree[2 * pos + 1], self.segment_tree[2 * pos + 2])

    def query(self, qlow, qhigh, len):
        return self.query_util(0, len - 1, qlow, qhigh, 0)

    def query_util(self, low, high, qlow, qhigh, pos):
        if qlow <= low and qhigh >= high:
            return self.segment_tree[pos]
        if qlow > high or qhigh < low:
            return float('-inf')
        mid = (low + high) // 2
        return max(self.query_util(low, mid, qlow, qhigh, 2 * pos + 1),
                   self.query_util(mid + 1, high, qlow, qhigh, 2 * pos + 2))

class Trie:
    class TrieNode:
        def __init__(self):
            self.children = {}
            self.is_end = False

    def __init__(self):
        self.root = self.TrieNode()

    def insert(self, word):
        current = self.root
        for ch in word:
            if ch not in current.children:
                current.children[ch] = self.TrieNode()
            current = current.children[ch]
        current.is_end = True

    def search(self, word):
        current = self.root
        for ch in word:
            if ch not in current.children:
                return False
            current = current.children[ch]
        return current.is_end

    def delete(self, word):
        self.delete_util(self.root, word, 0)

    def delete_util(self, current, word, index):
        if index == len(word):
            if not current.is_end:
                return False
            current.is_end = False
            return len(current.children) == 0
        ch = word[index]
        if ch not in current.children:
            return False
        should_delete = self.delete_util(current.children[ch], word, index + 1)
        if should_delete:
            del current.children[ch]
            return len(current.children) == 0
        return False
