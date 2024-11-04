import sys
from collections import defaultdict

class Mem:
    def __init__(self):
        self.N = 3000 + 10
        self.n = 0
        self.k = 0
        self.m = [0] * self.N
        self.a = [[] for _ in range(self.N)]
        self.ans = 0
        self.sum = [0] * self.N

    def insert(self, dp, a, b):
        for i in range(self.k, a - 1, -1):
            dp[i] = max(dp[i], dp[i - a] + b)

    def DFS(self, l, r, f):
        if l == r:
            self.ans = max(self.ans, f[self.k])
            s = 0
            for i in range(1, min(self.m[l], self.k) + 1):
                s += self.a[l][i]
                self.ans = max(self.ans, s + f[self.k - i])
            return
        
        mid = (l + r) // 2
        g = f[:]
        
        for i in range(mid + 1, r + 1):
            self.insert(g, self.m[i], self.sum[i])
        
        self.DFS(l, mid, g)
        
        g = f[:]
        
        for i in range(l, mid + 1):
            self.insert(g, self.m[i], self.sum[i])
        
        self.DFS(mid + 1, r, g)

    def main(self):
        input_file = open("1.in", "r")
        self.n, self.k = map(int, input_file.readline().split())
        
        for i in range(1, self.n + 1):
            self.m[i] = int(input_file.readline())
            self.a[i] = list(map(int, input_file.readline().split()))
            self.sum[i] = sum(self.a[i])
        
        self.DFS(1, self.n, [0] * (self.k + 1))
        print(self.ans)

if __name__ == "__main__":
    mem = Mem()
    mem.main()
