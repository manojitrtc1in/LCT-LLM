import sys
from collections import defaultdict
import math

class icpc:
    @staticmethod
    def main():
        input = sys.stdin.read
        data = input().splitlines()
        s1 = data[0].split(" ")
        n = int(s1[0])
        k = int(s1[1])
        s = data[1]
        stringBuilder = []

        if k == 0:
            print(s)
            sys.exit(0)
        if n == 1:
            if k >= 1:
                stringBuilder.append('0')
            else:
                stringBuilder.append(s)
        else:
            count = 0
            if s[0] != '1':
                stringBuilder.append('1')
                count += 1
            else:
                stringBuilder.append('1')
            for i in range(1, n):
                if count >= k:
                    stringBuilder.append(s[i:])
                    break
                else:
                    if s[i] == '0':
                        stringBuilder.append('0')
                        continue
                    else:
                        stringBuilder.append('0')
                        count += 1
        print(''.join(stringBuilder))


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


class id18:
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

        len_ = 2
        while len_ <= count:
            half_len = len_ >> 1
            angle = 2 * math.pi / len_
            if invert:
                angle = -angle
            id17 = math.cos(angle)
            id2 = math.sin(angle)
            for i in range(0, count, len_):
                wA = 1
                wB = 0
                for j in range(half_len):
                    uA = a[i + j]
                    uB = b[i + j]
                    vA = a[i + j + half_len] * wA - b[i + j + half_len] * wB
                    vB = a[i + j + half_len] * wB + b[i + j + half_len] * wA
                    a[i + j] = uA + vA
                    b[i + j] = uB + vB
                    a[i + j + half_len] = uA - vA
                    b[i + j + half_len] = uB - vB
                    next_wA = wA * id17 - wB * id2
                    wB = wA * id2 + wB * id17
                    wA = next_wA
            len_ <<= 1
        if invert:
            for i in range(count):
                a[i] /= count
                b[i] /= count

    def multiply(self, a, b):
        result_size = 1 << (math.ceil(math.log2(max(len(a), len(b)))) + 1)
        a_real = [0.0] * result_size
        b_real = [0.0] * result_size
        for i in range(len(a)):
            a_real[i] = a[i]
        for i in range(len(b)):
            b_real[i] = b[i]
        id10 = [0.0] * result_size
        id29 = [0.0] * result_size
        self.fft(a_real, id10, False)
        self.fft(b_real, id29, False)
        for i in range(result_size):
            real = a_real[i] * b_real[i] - id10[i] * id29[i]
            id10[i] = id10[i] * b_real[i] + id29[i] * a_real[i]
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

    def id26(self, n):
        f = []
        for x in range(2, int(math.sqrt(n)) + 1):
            while n % x == 0:
                f.append(x)
                n //= x
        if n > 1:
            f.append(n)
        return f

    def id19(self, n):
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

    def id21(self, a, b):
        if b == 0:
            return Name(a, 1, 0)
        n1 = self.id21(b, a % b)
        return Name(n1.d, n1.y, n1.x - (a // b) * n1.y)

    def id22(self, a, b, n):
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
    def __init__(self, str_):
        self.id6 = 256
        self.N = len(str_)
        self.T = self.id12(str_)
        self.lcp = [0] * self.N
        self.sa = [0] * self.N
        self.sa2 = [0] * self.N
        self.rank = [0] * self.N
        self.tmp = [0] * self.N
        self.c = [0] * max(self.id6, self.N)
        self.construct()
        self.kasai()

    @staticmethod
    def id12(s):
        return [ord(ch) for ch in s]

    def construct(self):
        for i in range(self.N):
            self.c[self.rank[i] := self.T[i]] += 1
        for i in range(1, self.id6):
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
            self.c = [0] * max(self.id6, self.N)
            for i in range(self.N):
                self.c[self.rank[i]] += 1
            for i in range(1, self.id6):
                self.c[i] += self.c[i - 1]
            for i in range(self.N - 1, -1, -1):
                self.sa[self.c[self.rank[self.sa2[i]]] - 1] = self.sa2[i]
                self.c[self.rank[self.sa2[i]]] -= 1
            self.sa2[self.sa[0]] = r = 0
            for i in range(1, self.N):
                if (self.rank[self.sa[i - 1]], self.rank[self.sa[i - 1] + p] if self.sa[i - 1] + p < self.N else -1) == \
                        (self.rank[self.sa[i]], self.rank[self.sa[i] + p] if self.sa[i] + p < self.N else -1):
                    self.sa2[self.sa[i]] = r
                else:
                    r += 1
                    self.sa2[self.sa[i]] = r
            self.tmp = self.rank
            self.rank = self.sa2
            self.sa2 = self.tmp
            if r == self.N - 1:
                break
            self.id6 = r + 1

    def kasai(self):
        inv = [0] * self.N
        for i in range(self.N):
            inv[self.sa[i]] = i
        len_ = 0
        for i in range(self.N):
            if inv[i] > 0:
                k = self.sa[inv[i] - 1]
                while (i + len_ < self.N) and (k + len_ < self.N) and (self.T[i + len_] == self.T[k + len_]):
                    len_ += 1
                self.lcp[inv[i] - 1] = len_
                if len_ > 0:
                    len_ -= 1


class ZAlgorithm:
    def calculate_z(self, input_):
        Z = [0] * len(input_)
        left = right = 0
        for k in range(1, len(input_)):
            if k > right:
                left = right = k
                while right < len(input_) and input_[right] == input_[right - left]:
                    right += 1
                Z[k] = right - left
                right -= 1
            else:
                k1 = k - left
                if Z[k1] < right - k + 1:
                    Z[k] = Z[k1]
                else:
                    left = k
                    while right < len(input_) and input_[right] == input_[right - left]:
                        right += 1
                    Z[k] = right - left
                    right -= 1
        return Z

    def match_pattern(self, text, pattern):
        new_string = list(pattern) + ['$'] + list(text)
        result = []
        Z = self.calculate_z(new_string)
        for i in range(len(Z)):
            if Z[i] == len(pattern):
                result.append(i - len(pattern) - 1)
        return result


class id1:
    def id5(self, pattern):
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

    def id3(self, text, pattern):
        lps = self.id5(pattern)
        j = i = 0
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
    def id8(self, p, n, m):
        powers = [1] * n
        for i in range(1, n):
            powers[i] = (powers[i - 1] * p) % m
        return powers

    def compute_hash(self, s):
        p = 31
        m = 1_000_000_009
        hash_value = 0
        powers = self.id8(p, len(s), m)
        for i in range(len(s)):
            ch = s[i]
            hash_value = (hash_value + (ord(ch) - ord('a') + 1) * powers[i]) % m
        return hash_value


class BasicFunctions:
    def min(self, A):
        return min(A)

    def max(self, A):
        return max(A)


class id25:
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


class id7:
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
        self.buffer_pointer = 0
        self.bytes_read = 0

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
        while c <= ' ':
            c = self.read()
        neg = (c == '-')
        if neg:
            c = self.read()
        while '0' <= chr(c) <= '9':
            ret = ret * 10 + c - ord('0')
            c = self.read()
        return -ret if neg else ret

    def next_long(self):
        ret = 0
        c = self.read()
        while c <= ' ':
            c = self.read()
        neg = (c == '-')
        if neg:
            c = self.read()
        while '0' <= chr(c) <= '9':
            ret = ret * 10 + c - ord('0')
            c = self.read()
        return -ret if neg else ret

    def next_double(self):
        ret = 0
        div = 1
        c = self.read()
        while c <= ' ':
            c = self.read()
        neg = (c == '-')
        if neg:
            c = self.read()
        while '0' <= chr(c) <= '9':
            ret = ret * 10 + c - ord('0')
            c = self.read()
        if c == ord('.'):
            while True:
                c = self.read()
                if not ('0' <= chr(c) <= '9'):
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


class id28:
    def update(self, id24, delta, index):
        index += 1
        while index < len(id24):
            id24[index] += delta
            index += index & -index

    def prefix_sum(self, id24, index):
        sum_ = 0
        index += 1
        while index > 0:
            sum_ += id24[index]
            index -= index & -index
        return sum_


class SegmentTree:
    def id23(self, num):
        if num == 0:
            return 1
        if num > 0 and (num & (num - 1)) == 0:
            return num
        while (num & (num - 1)) > 0:
            num &= (num - 1)
        return num << 1

    def id16(self, input_):
        np2 = self.id23(len(input_))
        segment_tree = [float('-inf')] * (np2 * 2 - 1)
        self.id11(segment_tree, input_, 0, len(input_) - 1, 0)
        return segment_tree

    def id11(self, segment_tree, input_, low, high, pos):
        if low == high:
            segment_tree[pos] = input_[low]
            return
        mid = (low + high) // 2
        self.id11(segment_tree, input_, low, mid, 2 * pos + 1)
        self.id11(segment_tree, input_, mid + 1, high, 2 * pos + 2)
        segment_tree[pos] = max(segment_tree[2 * pos + 1], segment_tree[2 * pos + 2])

    def id4(self, segment_tree, qlow, qhigh, length):
        return self.id4(segment_tree, 0, length - 1, qlow, qhigh, 0)

    def id4(self, segment_tree, low, high, qlow, qhigh, pos):
        if qlow <= low and qhigh >= high:
            return segment_tree[pos]
        if qlow > high or qhigh < low:
            return float('-inf')
        mid = (low + high) // 2
        return max(self.id4(segment_tree, low, mid, qlow, qhigh, 2 * pos + 1),
                   self.id4(segment_tree, mid + 1, high, qlow, qhigh, 2 * pos + 2))


class Trie:
    class TrieNode:
        def __init__(self):
            self.children = {}
            self.id13 = False

    def __init__(self):
        self.root = self.TrieNode()

    def insert(self, word):
        current = self.root
        for ch in word:
            if ch not in current.children:
                current.children[ch] = self.TrieNode()
            current = current.children[ch]
        current.id13 = True

    def search(self, word):
        current = self.root
        for ch in word:
            if ch not in current.children:
                return False
            current = current.children[ch]
        return current.id13

    def delete(self, word):
        self.delete_node(self.root, word, 0)

    def delete_node(self, current, word, index):
        if index == len(word):
            if not current.id13:
                return False
            current.id13 = False
            return len(current.children) == 0
        ch = word[index]
        if ch not in current.children:
            return False
        should_delete = self.delete_node(current.children[ch], word, index + 1)
        if should_delete:
            del current.children[ch]
            return len(current.children) == 0
        return False


class id15:
    def id23(self, num):
        if num == 0:
            return 1
        if num > 0 and (num & (num - 1)) == 0:
            return num
        while (num & (num - 1)) > 0:
            num &= (num - 1)
        return num << 1

    def id16(self, input_):
        id20 = self.id23(len(input_))
        segment_tree = [float('inf')] * (id20 * 2 - 1)
        for i in range(len(segment_tree)):
            segment_tree[i] = float('inf')
        self.id0(segment_tree, input_, 0, len(input_) - 1, 0)
        return segment_tree

    def id0(self, segment_tree, input_, low, high, pos):
        if low == high:
            segment_tree[pos] = input_[low]
            return
        mid = (low + high) // 2
        self.id0(segment_tree, input_, low, mid, 2 * pos + 1)
        self.id0(segment_tree, input_, mid + 1, high, 2 * pos + 2)
        segment_tree[pos] = min(segment_tree[2 * pos + 1], segment_tree[2 * pos + 2])

    def id9(self, input_, segment_tree, lazy, start_range, end_range, delta):
        self.id9_helper(segment_tree, lazy, start_range, end_range, delta, 0, len(input_) - 1, 0)

    def id9_helper(self, segment_tree, lazy, start_range, end_range, delta, low, high, pos):
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
        self.id9_helper(segment_tree, lazy, start_range, end_range, delta, low, mid, 2 * pos + 1)
        self.id9_helper(segment_tree, lazy, start_range, end_range, delta, mid + 1, high, 2 * pos + 2)
        segment_tree[pos] = min(segment_tree[2 * pos + 1], segment_tree[2 * pos + 2])

    def id27(self, segment_tree, lazy, qlow, qhigh, length):
        return self.id27_helper(segment_tree, lazy, qlow, qhigh, 0, length - 1, 0)

    def id27_helper(self, segment_tree, lazy, qlow, qhigh, low, high, pos):
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
        return min(self.id27_helper(segment_tree, lazy, qlow, qhigh, low, mid, 2 * pos + 1),
                   self.id27_helper(segment_tree, lazy, qlow, qhigh, mid + 1, high, 2 * pos + 2)
