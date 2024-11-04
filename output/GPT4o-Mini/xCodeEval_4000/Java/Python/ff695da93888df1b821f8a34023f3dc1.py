import sys
import math
from collections import defaultdict

class Reader:
    def __init__(self):
        self.buffer = []
        self.pointer = 0

    def read_line(self):
        return sys.stdin.readline().strip()

    def next_int(self):
        return int(self.read_line())

    def next_long(self):
        return int(self.read_line())

    def next_double(self):
        return float(self.read_line())

class ICPC:
    @staticmethod
    def give_ans(x):
        num_of_digits = len(str(x))
        ans = 0
        for i in range(2, num_of_digits):
            ans += 9 * (10 ** (i - 2))
        if num_of_digits > 1:
            ans += 9
        if num_of_digits == 1:
            ans += x
        else:
            first_digit = int(str(x)[0])
            last_digit = int(str(x)[-1])
            ans += (first_digit - 1) * (10 ** (num_of_digits - 2))
            s = str(x)
            for j in range(1, num_of_digits - 1):
                digit = int(s[j])
                ans += digit * (10 ** (num_of_digits - j - 2))
            if first_digit <= last_digit:
                ans += 1
        return ans

    @staticmethod
    def main():
        l = Reader().next_long()
        r = Reader().next_long()
        print(ICPC.give_ans(r) - ICPC.give_ans(l - 1))

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
        for length in range(2, count + 1, length << 1):
            half_length = length >> 1
            angle = 2 * math.pi / length
            if invert:
                angle = -angle
            w_len_a = math.cos(angle)
            w_len_b = math.sin(angle)
            for i in range(0, count, length):
                w_a = 1
                w_b = 0
                for j in range(half_length):
                    u_a = a[i + j]
                    u_b = b[i + j]
                    v_a = a[i + j + half_length] * w_a - b[i + j + half_length] * w_b
                    v_b = a[i + j + half_length] * w_b + b[i + j + half_length] * w_a
                    a[i + j] = u_a + v_a
                    b[i + j] = u_b + v_b
                    a[i + j + half_length] = u_a - v_a
                    b[i + j + half_length] = u_b - v_b
                    next_w_a = w_a * w_len_a - w_b * w_len_b
                    w_b = w_a * w_len_b + w_b * w_len_a
                    w_a = next_w_a
        if invert:
            for i in range(count):
                a[i] /= count
                b[i] /= count

    def multiply(self, a, b):
        result_size = 1 << (math.ceil(math.log2(max(len(a), len(b)))) + 1)
        a_real = [0.0] * result_size
        a_imaginary = [0.0] * result_size
        b_real = [0.0] * result_size
        b_imaginary = [0.0] * result_size
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
        return [round(a_real[i]) for i in range(result_size)]

class NumberTheory:
    @staticmethod
    def is_prime(n):
        if n < 2:
            return False
        for x in range(2, int(math.sqrt(n)) + 1):
            if n % x == 0:
                return False
        return True

    @staticmethod
    def prime_factorisation(n):
        factors = []
        for x in range(2, int(math.sqrt(n)) + 1):
            while n % x == 0:
                factors.append(x)
                n //= x
        if n > 1:
            factors.append(n)
        return factors

    @staticmethod
    def sieve_of_eratosthenes(n):
        sieve = [0] * (n + 1)
        for x in range(2, int(math.sqrt(n)) + 1):
            if sieve[x] != 0:
                continue
            for u in range(x * x, n + 1, x):
                if sieve[u] == 0:
                    sieve[u] = x
        return sieve

    @staticmethod
    def gcd(a, b):
        if b == 0:
            return a
        return NumberTheory.gcd(b, a % b)

    @staticmethod
    def phi(n):
        result = n
        for p in range(2, int(math.sqrt(n)) + 1):
            if n % p == 0:
                while n % p == 0:
                    n //= p
                result *= (1.0 - (1.0 / p))
        if n > 1:
            result *= (1.0 - (1.0 / n))
        return int(result)

    @staticmethod
    def extended_euclid(a, b):
        if b == 0:
            return Name(a, 1, 0)
        n1 = NumberTheory.extended_euclid(b, a % b)
        return Name(n1.d, n1.y, n1.x - (a // b) * n1.y)

    @staticmethod
    def modular_exponentiation(a, b, n):
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
            self.rank, self.sa2 = self.sa2, self.rank
            if r == self.N - 1:
                break
            256 = r + 1

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
    @staticmethod
    def calculate_z(input):
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

    @staticmethod
    def match_pattern(text, pattern):
        new_string = list(pattern) + ['$'] + list(text)
        result = []
        Z = ZAlgorithm.calculate_z(new_string)
        for i in range(len(Z)):
            if Z[i] == len(pattern):
                result.append(i - len(pattern) - 1)
        return result

class KMPAlgorithm:
    @staticmethod
    def compute_temporal_array(pattern):
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

    @staticmethod
    def kmp_matcher(text, pattern):
        lps = KMPAlgorithm.compute_temporal_array(pattern)
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
    @staticmethod
    def compute_powers(p, n, m):
        powers = [0] * n
        powers[0] = 1
        for i in range(1, n):
            powers[i] = (powers[i - 1] * p) % m
        return powers

    @staticmethod
    def compute_hash(s):
        p = 31
        m = 1_000_000_009
        hash_value = 0
        powers = Hashing.compute_powers(p, len(s), m)
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
            MergeSortInt.sort(arr, l, m)
            MergeSortInt.sort(arr, m + 1, r)
            MergeSortInt.merge(arr, l, m, r)

class MergeSortLong:
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
            MergeSortLong.sort(arr, l, m)
            MergeSortLong.sort(arr, m + 1, r)
            MergeSortLong.merge(arr, l, m, r)

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

class FenwickTree:
    @staticmethod
    def update(fenwick_tree, delta, index):
        index += 1
        while index < len(fenwick_tree):
            fenwick_tree[index] += delta
            index += index & -index

    @staticmethod
    def prefix_sum(fenwick_tree, index):
        sum = 0
        index += 1
        while index > 0:
            sum += fenwick_tree[index]
            index -= index & -index
        return sum

class SegmentTree:
    @staticmethod
    def next_power_of_two(num):
        if num == 0:
            return 1
        if num > 0 and (num & (num - 1)) == 0:
            return num
        while (num & (num - 1)) > 0:
            num &= (num - 1)
        return num << 1

    @staticmethod
    def create_segment_tree(input):
        np2 = SegmentTree.next_power_of_two(len(input))
        segment_tree = [float('-inf')] * (np2 * 2 - 1)
        SegmentTree.construct_segment_tree(segment_tree, input, 0, len(input) - 1, 0)
        return segment_tree

    @staticmethod
    def construct_segment_tree(segment_tree, input, low, high, pos):
        if low == high:
            segment_tree[pos] = input[low]
            return
        mid = (low + high) // 2
        SegmentTree.construct_segment_tree(segment_tree, input, low, mid, 2 * pos + 1)
        SegmentTree.construct_segment_tree(segment_tree, input, mid + 1, high, 2 * pos + 2)
        segment_tree[pos] = max(segment_tree[2 * pos + 1], segment_tree[2 * pos + 2])

    @staticmethod
    def range_minimum_query(segment_tree, qlow, qhigh, length):
        return SegmentTree.range_minimum_query(segment_tree, 0, length - 1, qlow, qhigh, 0)

    @staticmethod
    def range_minimum_query(segment_tree, low, high, qlow, qhigh, pos):
        if qlow <= low and qhigh >= high:
            return segment_tree[pos]
        if qlow > high or qhigh < low:
            return float('-inf')
        mid = (low + high) // 2
        return max(SegmentTree.range_minimum_query(segment_tree, low, mid, qlow, qhigh, 2 * pos + 1),
                   SegmentTree.range_minimum_query(segment_tree, mid + 1, high, qlow, qhigh, 2 * pos + 2))

class Trie:
    class TrieNode:
        def __init__(self):
            self.children = {}
            self.end_of_word = False

    def __init__(self):
        self.root = Trie.TrieNode()

    def insert(self, word):
        current = self.root
        for ch in word:
            if ch not in current.children:
                current.children[ch] = Trie.TrieNode()
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
        self.delete_node(self.root, word, 0)

    def delete_node(self, current, word, index):
        if index == len(word):
            if not current.end_of_word:
                return False
            current.end_of_word = False
            return len(current.children) == 0
        ch = word[index]
        node = current.children.get(ch)
        if node is None:
            return False
        should_delete_current_node = self.delete_node(node, word, index + 1)
        if should_delete_current_node:
            del current.children[ch]
            return len(current.children) == 0
        return False

class SegmentTreeLazy:
    @staticmethod
    def next_power_of_two(num):
        if num == 0:
            return 1
        if num > 0 and (num & (num - 1)) == 0:
            return num
        while (num & (num - 1)) > 0:
            num &= (num - 1)
        return num << 1

    @staticmethod
    def create_segment_tree(input):
        next_pow_of_two = SegmentTreeLazy.next_power_of_two(len(input))
        segment_tree = [float('inf')] * (next_pow_of_two * 2 - 1)
        lazy = [0] * (next_pow_of_two * 2 - 1)
        SegmentTreeLazy.construct_min_segment_tree(segment_tree, input, 0, len(input) - 1, 0)
        return segment_tree, lazy

    @staticmethod
    def construct_min_segment_tree(segment_tree, input, low, high, pos):
        if low == high:
            segment_tree[pos] = input[low]
            return
        mid = (low + high) // 2
        SegmentTreeLazy.construct_min_segment_tree(segment_tree, input, low, mid, 2 * pos + 1)
        SegmentTreeLazy.construct_min_segment_tree(segment_tree, input, mid + 1, high, 2 * pos + 2)
        segment_tree[pos] = min(segment_tree[2 * pos + 1], segment_tree[2 * pos + 2])

    @staticmethod
    def update_segment_tree_range_lazy(input, segment_tree, lazy, start_range, end_range, delta):
        SegmentTreeLazy.update_segment_tree_range_lazy(segment_tree, lazy, start_range, end_range, delta, 0, len(input) - 1, 0)

    @staticmethod
    def update_segment_tree_range_lazy(segment_tree, lazy, start_range, end_range, delta, low, high, pos):
        if low > high:
            return
        if lazy[pos] != 0:
            segment_tree[pos] += lazy[pos]
            if low != high:
                lazy[2 * pos + 1] += lazy[pos]
                lazy[2 * pos + 2] += lazy[pos]
            lazy[pos] = 0
        if start_range > high or end_range < low:
            return
        if start_range <= low and end_range >= high:
            segment_tree[pos] += delta
            if low != high:
                lazy[2 * pos + 1] += delta
                lazy[2 * pos + 2] += delta
            return
        mid = (low + high) // 2
        SegmentTreeLazy.update_segment_tree_range_lazy(segment_tree, lazy, start_range, end_range, delta, low, mid, 2 * pos + 1)
        SegmentTreeLazy.update_segment_tree_range_lazy(segment_tree, lazy, start_range, end_range, delta, mid + 1, high, 2 * pos + 2)
        segment_tree[pos] = min(segment_tree[2 * pos + 1], segment_tree[2 * pos + 2])

    @staticmethod
    def range_minimum_query_lazy(segment_tree, lazy, qlow, qhigh, length):
        return SegmentTreeLazy.range_minimum_query_lazy(segment_tree, lazy, qlow, qhigh, 0, length - 1, 0)

    @staticmethod
    def range_minimum_query_lazy(segment_tree, lazy, qlow, qhigh, low, high, pos):
        if low > high:
            return float('inf')
        if lazy[pos] != 0:
            segment_tree[pos] += lazy[pos]
            if low != high:
                lazy[2 * pos + 1] += lazy[pos]
                lazy[2 * pos + 2] += lazy[pos]
            lazy[pos] = 0
        if qlow > high or qhigh < low:
            return float('inf')
        if qlow <= low and qhigh >= high:
            return segment_tree[pos]
        mid = (low + high) // 2
        return min(SegmentTreeLazy.range_minimum_query_lazy(segment_tree, lazy, qlow, qhigh, low, mid, 2 * pos + 1),
                   SegmentTreeLazy.range_minimum_query_lazy(segment_tree, lazy, qlow, qhigh, mid + 1, high, 2 * pos + 2))
