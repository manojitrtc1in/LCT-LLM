import sys
import math
from collections import defaultdict

mod = int(math.pow(10, 9) + 7)
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
dx8 = [-1, -1, -1, 0, 0, 1, 1, 1]
dy8 = [-1, 0, 1, -1, 1, -1, 0, 1]
dx9 = [-1, -1, -1, 0, 0, 0, 1, 1, 1]
dy9 = [-1, 0, 1, -1, 0, 1, -1, 0, 1]

eps = 1e-10
prime_numbers = []

def main():
    inp = input().strip()
    n = len(inp)

    pos = ["00", "25", "50", "75"]
    count = 0

    if n == 1:
        if inp[0] == '0' or inp[0] == 'X' or inp[0] == '_':
            count += 1
    else:
        for cstr in pos:
            X = -1
            idx = 0
            possible = True
            for i in range(n - 2, n):
                curr = inp[i]
                strcurr = cstr[idx]
                idx += 1

                if curr == '_':
                    continue
                elif curr == 'X':
                    if X == -1:
                        X = int(strcurr)
                    else:
                        if X != int(strcurr):
                            possible = False
                            break
                else:
                    if curr != strcurr:
                        possible = False
                        break

            if not possible:
                continue

            if n == 2:
                if cstr[0] == '0':
                    continue
                count += 1
                continue

            ninp = list(inp)

            cntX = sum(1 for ch in inp if ch == 'X')

            if X != -1 or cntX == 0:
                if X != -1:
                    for k in range(n):
                        ninp[k] = inp[k] if inp[k] != 'X' else str(X)

                if ninp[0] == '0':
                    continue
                counter = 1
                for k in range(n - 2):
                    if ninp[k] == '_':
                        counter *= 9 if k == 0 else 10

                count += counter
            else:
                if ninp[0] == '0':
                    continue

                counter = 1
                for k in range(n - 2):
                    if ninp[k] == '_':
                        counter *= 9 if k == 0 else 10

                if ninp[0] == 'X':
                    counter *= 9
                else:
                    counter *= 10

                count += counter

    print(count)

class Graph:
    def __init__(self, V):
        self.V = V
        self.edges = [[] for _ in range(V + 1)]

    def add_edge(self, from_node, to_node):
        self.edges[from_node].append(to_node)
        self.edges[to_node].append(from_node)

class UnionFind:
    def __init__(self, n):
        self.rank = [1] * n
        self.parent = [-1] * n
        self.n = n

    def find(self, curr):
        if self.parent[curr] == -1:
            return curr
        self.parent[curr] = self.find(self.parent[curr])
        return self.parent[curr]

    def union(self, a, b):
        s1 = self.find(a)
        s2 = self.find(b)

        if s1 != s2:
            if self.rank[s1] < self.rank[s2]:
                self.parent[s1] = s2
                self.rank[s2] += self.rank[s1]
            else:
                self.parent[s2] = s1
                self.rank[s1] += self.rank[s2]

def power_mod(x, y):
    res = 1
    while y > 0:
        if (y & 1) != 0:
            x %= mod
            res = (res * x) % mod
        y >>= 1
        x = (x * x) % mod
    return res % mod

def power(x, y):
    res = 1
    while y > 0:
        if (y & 1) != 0:
            res *= x
        y >>= 1
        x *= x
    return res

class SegmentTree:
    def __init__(self, arr):
        self.arr = arr
        self.tree = [0] * (4 * len(arr) + 1)

    def build_tree(self, s, e, index):
        if s == e:
            self.tree[index] = self.arr[s]
            return

        mid = (s + e) // 2
        self.build_tree(s, mid, 2 * index)
        self.build_tree(mid + 1, e, 2 * index + 1)
        self.tree[index] = min(self.tree[2 * index], self.tree[2 * index + 1])

    def query(self, s, e, qs, qe, index):
        if s >= qs and e <= qe:
            return self.tree[index]
        if qe < s or qs > e:
            return float('inf')

        mid = (s + e) // 2
        left = self.query(s, mid, qs, qe, 2 * index)
        right = self.query(mid + 1, e, qs, qe, 2 * index + 1)
        return min(left, right)

    def update_node(self, s, e, i, increment, index):
        if i < s or i > e:
            return

        if s == e:
            self.tree[index] += increment
            return

        mid = (s + e) // 2
        self.update_node(s, mid, i, increment, 2 * index)
        self.update_node(mid + 1, e, i, increment, 2 * index + 1)
        self.tree[index] = min(self.tree[2 * index], self.tree[2 * index + 1])

    def update_range(self, s, e, l, r, increment, index):
        if l > e or r < s:
            return

        if s == e:
            self.tree[index] += increment
            return

        mid = (s + e) // 2
        self.update_range(s, mid, l, r, increment, 2 * index)
        self.update_range(mid + 1, e, l, r, increment, 2 * index + 1)
        self.tree[index] = min(self.tree[2 * index], self.tree[2 * index + 1])

def sieve_of_eratosthenes(n):
    bitset = [False] * (n + 1)
    for i in range(n + 1):
        if i == 0 or i == 1:
            bitset[i] = True
            continue
        if bitset[i]:
            continue
        prime_numbers.append(i)
        for j in range(i, n + 1, i):
            bitset[j] = True

def prime_factor_count(number):
    if number == 1:
        return 1
    prime_factors = []
    index = 0
    curr = prime_numbers[index]
    while curr * curr <= number:
        while number % curr == 0:
            number //= curr
            prime_factors.append(curr)
        index += 1
        if index < len(prime_numbers):
            curr = prime_numbers[index]
        else:
            break

    if number != 1:
        prime_factors.append(number)
    current = prime_factors[0]
    id8 = 1
    current_count = 2
    for i in range(1, len(prime_factors)):
        if prime_factors[i] == current:
            current_count += 1
        else:
            id8 *= current_count
            current_count = 2
            current = prime_factors[i]
    id8 *= current_count
    return id8

def count_prime_factors(n):
    if n <= 1:
        return 0
    sqrt_n = int(math.sqrt(n))
    remaining_number = n
    result = 0
    for i in range(2, sqrt_n + 1):
        while remaining_number % i == 0:
            result += 1
            remaining_number //= i

    if remaining_number > 1:
        result += 1
    return result

def next_permutation(p):
    for a in range(len(p) - 2, -1, -1):
        if p[a] < p[a + 1]:
            for b in range(len(p) - 1, -1, -1):
                if p[b] > p[a]:
                    p[a], p[b] = p[b], p[a]
                    p[a + 1:] = reversed(p[a + 1:])
                    return True
    return False

def nCr(n, r):
    p = 1
    k = 1
    if n - r < r:
        r = n - r

    if r != 0:
        while r > 0:
            p *= n
            k *= r
            m = gcd(p, k)
            p //= m
            k //= m
            n -= 1
            r -= 1
    else:
        p = 1
    return p

def is_vowel(c):
    return c in 'aeiouAEIOU'

def sort_array(arr):
    arr.sort()

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a * (b // gcd(a, b))

def swap(arr, left, right):
    arr[left], arr[right] = arr[right], arr[left]

def reverse(arr):
    left = 0
    right = len(arr) - 1
    while left <= right:
        swap(arr, left, right)
        left += 1
        right -= 1

def expo(a, b, mod):
    res = 1
    while b > 0:
        if (b & 1) == 1:
            res = (res * a) % mod
        a = (a * a) % mod
        b >>= 1
    return res

def mod_add(a, b, m):
    return (a % m + b % m) % m

def mod_sub(a, b, m):
    return (a % m - b % m + m) % m

def mod_mul(a, b, m):
    return (a % m * b % m) % m

def mod_div(a, b, m):
    return mod_mul(a, mod_inverse(b, m), m)

def mod_inverse(a, m):
    return expo(a, m - 2, m)

def nCr_with_mod(N, K, mod):
    upper = 1
    lower = 1
    lowerr = 1

    for i in range(1, N + 1):
        upper = mod_mul(upper, i, mod)

    for i in range(1, K + 1):
        lower = mod_mul(lower, i, mod)

    for i in range(1, N - K + 1):
        lowerr = mod_mul(lowerr, i, mod)

    answer = mod_mul(lower, lowerr, mod)
    answer = mod_div(upper, answer, mod)

    return answer

if __name__ == "__main__":
    main()
