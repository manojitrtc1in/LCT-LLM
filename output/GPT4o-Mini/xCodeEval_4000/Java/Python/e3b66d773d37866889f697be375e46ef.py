import sys
import random
from collections import defaultdict
from functools import lru_cache

class Pair:
    def __init__(self, a, b):
        self.x = a
        self.y = b

    def __lt__(self, other):
        if self.x != other.x:
            return self.x < other.x
        return self.y < other.y

class SegmentTree:
    def __init__(self, arr):
        self.array = arr
        self.N = len(arr)
        self.sTree = [0] * (self.N * 2)
        self.lazy = [0] * (self.N * 2)

    def build(self, node, b, e):
        if b == e:
            self.sTree[node] = self.array[b]
        else:
            mid = (b + e) // 2
            self.build(node * 2, b, mid)
            self.build(node * 2 + 1, mid + 1, e)
            self.sTree[node] = self.sTree[node * 2] + self.sTree[node * 2 + 1]

    def update_point(self, index, val):
        index += self.N - 1
        self.sTree[index] = val
        while index > 1:
            index //= 2
            self.sTree[index] = max(self.sTree[index * 2], self.sTree[index * 2 + 1])

    def update_range(self, i, j, val):
        self.update_range_helper(1, 0, self.N - 1, i, j, val)

    def update_range_helper(self, node, b, e, i, j, val):
        if i > e or j < b:
            return
        if b >= i and e <= j:
            self.sTree[node] += (e - b + 1) * val
            self.lazy[node] += val
        else:
            mid = (b + e) // 2
            self.propagate(node, b, mid, e)
            self.update_range_helper(node * 2, b, mid, i, j, val)
            self.update_range_helper(node * 2 + 1, mid + 1, e, i, j, val)
            self.sTree[node] = self.sTree[node * 2] + self.sTree[node * 2 + 1]

    def propagate(self, node, b, mid, e):
        self.lazy[node * 2] += self.lazy[node]
        self.lazy[node * 2 + 1] += self.lazy[node]
        self.sTree[node * 2] += (mid - b + 1) * self.lazy[node]
        self.sTree[node * 2 + 1] += (e - mid) * self.lazy[node]
        self.lazy[node] = 0

    def query(self, i, j):
        return self.query_helper(1, 0, self.N - 1, i, j)

    def query_helper(self, node, b, e, i, j):
        if i > e or j < b:
            return 0
        if b >= i and e <= j:
            return self.sTree[node]
        mid = (b + e) // 2
        q1 = self.query_helper(node * 2, b, mid, i, j)
        q2 = self.query_helper(node * 2 + 1, mid + 1, e, i, j)
        return max(q1, q2)

def sieve(N):
    isComposite = [0] * (N + 1)
    isComposite[0] = isComposite[1] = 1
    primes = []
    for i in range(2, N + 1):
        if isComposite[i] == 0:
            primes.append(i)
            for j in range(i * i, N + 1, i):
                isComposite[j] = 1
    return primes

def prime_factors(N, primes):
    factors = []
    idx = 0
    p = primes[idx]
    while p * p <= N:
        while N % p == 0:
            factors.append(p)
            N //= p
        idx += 1
        if idx < len(primes):
            p = primes[idx]
        else:
            break
    if N != 1:
        factors.append(N)
    return factors

def dp(idx, state, n, a, notmemo):
    if idx == n:
        return 0
    if notmemo[idx][state] != -1:
        return notmemo[idx][state]
    
    take = leave = leaveall = 0
    if a[idx] == 1 and (state == 1 or state == 0):
        take = 1 + dp(idx + 1, 1, n, a, notmemo)
    if a[idx] == 0 and state == 0:
        leave = 1 + dp(idx + 1, state, n, a, notmemo)
    leaveall = dp(idx + 1, state, n, a, notmemo)
    
    notmemo[idx][state] = max(take, max(leaveall, leave))
    return notmemo[idx][state]

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    a = list(map(int, data[1:n + 1]))
    notmemo = [[-1 for _ in range(2)] for _ in range(n)]
    
    print(dp(0, 0, n, a, notmemo))

if __name__ == "__main__":
    main()
