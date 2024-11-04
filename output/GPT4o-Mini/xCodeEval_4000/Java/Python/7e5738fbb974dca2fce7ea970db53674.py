import sys
from collections import defaultdict
import math

class ICPC:
    @staticmethod
    def main():
        input = sys.stdin.read
        data = input().splitlines()
        s1 = data[0].split()
        n = int(s1[0])
        k = int(s1[1])
        s = data[1]
        string_builder = []

        if k == 0:
            print(s)
            sys.exit(0)
        if n == 1:
            if k >= 1:
                string_builder.append('0')
            else:
                string_builder.append(s)
        else:
            count = 0
            if s[0] != '1':
                string_builder.append('1')
                count += 1
            else:
                string_builder.append('1')
            for i in range(1, n):
                if count >= k:
                    string_builder.append(s[i:])
                    break
                else:
                    if s[i] == '0':
                        string_builder.append('0')
                        continue
                    else:
                        string_builder.append('0')
                        count += 1
        print(''.join(string_builder))

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

class FastFourierTransform:
    def fft(self, a, b, invert):
        count = len(a)
        j = 0
        for i in range(1, count):
            bit = count >> 1
            while j >= bit:
                bit >>= 1
            j += bit
            if i < j:
                a[i], a[j] = a[j], a[i]
                b[i], b[j] = b[j], b[i]
        for len in range(2, count + 1, len << 1):
            half_len = len >> 1
            angle = 2 * math.pi / len
            if invert:
                angle = -angle
            w_len_a = math.cos(angle)
            w_len_b = math.sin(angle)
            for i in range(0, count, len):
                w_a = 1
                w_b = 0
                for j in range(half_len):
                    u_a = a[i + j]
                    u_b = b[i + j]
                    v_a = a[i + j + half_len] * w_a - b[i + j + half_len] * w_b
                    v_b = a[i + j + half_len] * w_b + b[i + j + half_len] * w_a
                    a[i + j] = u_a + v_a
                    b[i + j] = u_b + v_b
                    a[i + j + half_len] = u_a - v_a
                    b[i + j + half_len] = u_b - v_b
                    next_w_a = w_a * w_len_a - w_b * w_len_b
                    w_b = w_a * w_len_b + w_b * w_len_a
                    w_a = next_w_a
        if invert:
            for i in range(count):
                a[i] /= count
                b[i] /= count

    def multiply(self, a, b):
        result_size = 1 << (math.ceil(math.log2(max(len(a), len(b)))) + 1)
        a_real = [0] * result_size
        a_imaginary = [0] * result_size
        b_real = [0] * result_size
        b_imaginary = [0] * result_size
        for i in range(len(a)):
            a_real[i] = a[i]
        for i in range(len(b)):
            b_real[i] = b[i]
        self.fft(a_real, a_imaginary, False)
        self.fft(b_real, b_imaginary, False)
        for i in range(result_size):
            real = a_real[i] * b_real[i] - a_imaginary[i] * b_imaginary[i]
            a_imaginary[i] = a_imaginary[i] * b_real[i] + b_imaginary[i] * a_real[i]
            a_real[i] = real
        self.fft(a_real, a_imaginary, True)
        result = [round(a_real[i]) for i in range(result_size)]
        return result

class NumberTheory:
    def is_prime(self, n):
        if n < 2:
            return False
        for x in range(2, int(math.sqrt(n)) + 1):
            if n % x == 0:
                return False
        return True

    def prime_factorisation(self, n):
        f = []
        for x in range(2, int(math.sqrt(n)) + 1):
            while n % x == 0:
                f.append(x)
                n //= x
        if n > 1:
            f.append(n)
        return f

    def sieve_of_eratosthenes(self, n):
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

    def extended_euclid(self, a, b):
        if b == 0:
            return Name(a, 1, 0)
        n1 = self.extended_euclid(b, a % b)
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
    ALPHABET_SZ = 256

    def __init__(self, str):
        self.T = self.to_int_array(str)
        self.N = len(self.T)
        self.sa = [0] * self.N
        self.sa2 = [0] * self.N
        self.rank = [0] * self.N
        self.c = [0] * max(self.ALPHABET_SZ, self.N)
        self.construct()
        self.kasai()

    @staticmethod
    def to_int_array(s):
        return [ord(ch) for ch in s]

    def construct(self):
        for i in range(self.N):
            self.c[self.rank[i] := self.T[i]] += 1
        for i in range(1, self.ALPHABET_SZ):
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
            self.c = [0] * max(self.ALPHABET_SZ, self.N)
            for i in range(self.N):
                self.c[self.rank[i]] += 1
            for i in range(1, self.ALPHABET_SZ):
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
            self.rank, self.sa2 = self.sa2, self.rank
            if r == self.N - 1:
                break
            self.ALPHABET_SZ = r + 1

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
        left = right = 0
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

class KMPAlgorithm:
    def compute_temporal_array(self, pattern):
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

    def kmp_matcher(self, text, pattern):
        lps = self.compute_temporal_array(pattern)
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
    def compute_powers(self, p, n, m):
        powers = [0] * n
        powers[0] = 1
        for i in range(1, n):
            powers[i] = (powers[i - 1] * p) % m
        return powers

    def compute_hash(self, s):
        p = 31
        m = 1_000_000_009
        hash_value = 0
        powers = self.compute_powers(p, len(s), m)
        for i in range(len(s)):
            ch = s[i]
            hash_value = (hash_value + (ord(ch) - ord('a') + 1) * powers[i]) % m
        return hash_value

class BasicFunctions:
    @staticmethod
    def min(A):
        return min(A)

    @staticmethod
    def max(A):
        return max(A)

class MergeSortInt:
    def merge(self, arr, l, m, r):
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

    def sort(self, arr, l, r):
        if l < r:
            m = (l + r) // 2
            self.sort(arr, l, m)
            self.sort(arr, m + 1, r)
            self.merge(arr, l, m, r)

class Node:
    def __init__(self, s):
        self.s = s

    def __eq__(self, ob):
        if ob is None:
            return False
        if not isinstance(ob, Node):
            return False
        if ob is self:
            return True
        return self.s == ob.s

    def __hash__(self):
        return len(self.s)

class Reader:
    def __init__(self):
        self.buffer_size = 1 << 16
        self.din = sys.stdin.buffer
        self.buffer = bytearray(self.buffer_size)
        self.buffer_pointer = self.bytes_read = 0

    def read_line(self):
        buf = bytearray(64)
        cnt = 0
        while True:
            c = self.read()
            if c == -1 or c == b'\n'[0]:
                break
            buf[cnt] = c
            cnt += 1
        return buf[:cnt].decode()

    def next_int(self):
        ret = 0
        c = self.read()
        while c <= 32:
            c = self.read()
        neg = c == ord('-')
        if neg:
            c = self.read()
        while c >= ord('0') and c <= ord('9'):
            ret = ret * 10 + c - ord('0')
            c = self.read()
        return -ret if neg else ret

    def next_long(self):
        ret = 0
        c = self.read()
        while c <= 32:
            c = self.read()
        neg = c == ord('-')
        if neg:
            c = self.read()
        while c >= ord('0') and c <= ord('9'):
            ret = ret * 10 + c - ord('0')
            c = self.read()
        return -ret if neg else ret

    def next_double(self):
        ret = 0
        div = 1
        c = self.read()
        while c <= 32:
            c = self.read()
        neg = c == ord('-')
        if neg:
            c = self.read()
        while c >= ord('0') and c <= ord('9'):
            ret = ret * 10 + c - ord('0')
            c = self.read()
        if c == ord('.'):
            while True:
                c = self.read()
                if not (c >= ord('0') and c <= ord('9')):
                    break
                ret += (c - ord('0')) / (div := div * 10)
        return -ret if neg else ret

    def fill_buffer(self):
        self.bytes_read = self.din.readinto(self.buffer)
        if self.bytes_read == 0:
            self.buffer[0] = -1

    def read(self):
        if self.buffer_pointer == self.bytes_read:
            self.fill_buffer()
        return self.buffer[self.buffer_pointer]

    def close(self):
        if self.din is not None:
            self.din.close()

class FenwickTree:
    def update(self, fenwick_tree, delta, index):
        index += 1
        while index < len(fenwick_tree):
            fenwick_tree[index] += delta
            index += (index & -index)

    def prefix_sum(self, fenwick_tree, index):
        sum = 0
        index += 1
        while index > 0:
            sum += fenwick_tree[index]
            index -= (index & -index)
        return sum

class SegmentTree:
    def next_power_of_two(self, num):
        if num == 0:
            return 1
        if num > 0 and (num & (num - 1)) == 0:
            return num
        while (num & (num - 1)) > 0:
            num &= (num - 1)
        return num << 1

    def create_segment_tree(self, input):
        np2 = self.next_power_of_two(len(input))
        segment_tree = [float('-inf')] * (np2 * 2 - 1)
        self.construct_segment_tree(segment_tree, input, 0, len(input) - 1, 0)
        return segment_tree

    def construct_segment_tree(self, segment_tree, input, low, high, pos):
        if low == high:
            segment_tree[pos] = input[low]
            return
        mid = (low + high) // 2
        self.construct_segment_tree(segment_tree, input, low, mid, 2 * pos + 1)
        self.construct_segment_tree(segment_tree, input, mid + 1, high, 2 * pos + 2)
        segment_tree[pos] = max(segment_tree[2 * pos + 1], segment_tree[2 * pos + 2])

    def range_minimum_query(self, segment_tree, qlow, qhigh, length):
        return self.range_minimum_query_helper(segment_tree, 0, length - 1, qlow, qhigh, 0)

    def range_minimum_query_helper(self, segment_tree, low, high, qlow, qhigh, pos):
        if qlow <= low and qhigh >= high:
            return segment_tree[pos]
        if qlow > high or qhigh < low:
            return float('-inf')
        mid = (low + high) // 2
        return max(self.range_minimum_query_helper(segment_tree, low, mid, qlow, qhigh, 2 * pos + 1),
                   self.range_minimum_query_helper(segment_tree, mid + 1, high, qlow, qhigh, 2 * pos + 2))

class Trie:
    class TrieNode:
        def __init__(self):
            self.children = {}
            self.end_of_word = False

    def __init__(self):
        self.root = self.TrieNode()

    def insert(self, word):
        current = self.root
        for ch in word:
            if ch not in current.children:
                current.children[ch] = self.TrieNode()
            current = current.children[ch]
        current.end_of_word = True

    def search(self, word):
        current = self.root
        for ch in word:
            if ch not in current.children:
                return False
            current = current.children[ch]
        return current.end_of_word

    def delete(self, word):
        self.delete_helper(self.root, word, 0)

    def delete_helper(self, current, word, index):
        if index == len(word):
            if not current.end_of_word:
                return False
            current.end_of_word = False
            return len(current.children) == 0
        ch = word[index]
        if ch not in current.children:
            return False
        should_delete_current_node = self.delete_helper(current.children[ch], word, index + 1)
        if should_delete_current_node:
            del current.children[ch]
            return len(current.children) == 0
        return False
