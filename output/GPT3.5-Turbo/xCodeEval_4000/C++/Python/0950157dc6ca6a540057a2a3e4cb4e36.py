MOD = 10007

class Field:
    def __init__(self, x):
        self.x = x % MOD
    
    def __add__(self, other):
        return Field(self.x + other.x)
    
    def __sub__(self, other):
        return Field(self.x - other.x)
    
    def __mul__(self, other):
        return Field(self.x * other.x)
    
    def __pow__(self, n):
        return Field(pow(self.x, n, MOD))
    
    def __str__(self):
        return str(self.x)

def go(left, right, i):
    if i < 0:
        return Field(0)
    if i == 0 and left >= right:
        return Field(1)
    if ok[left][right][i]:
        return dp[left][right][i]
    res = Field(0)
    
    if left >= right:
        res += go(left, right, max(i - 2, 0)) * 26
    elif left + 1 == right:
        if i == 0:
            res += go(left + 1, right - 1, i)
        else:
            res += go(left + 1, right, i - 1)
        res += go(left, right, i - 2) * 25
    else:
        if s[left] == s[right - 1]:
            res += go(left + 1, right - 1, i)
            res += go(left, right, i - 2) * 25
        else:
            res += go(left + 1, right, i - 1)
            res += go(left, right - 1, i - 1)
            res += go(left, right, i - 2) * 24
    
    ok[left][right][i] = True
    dp[left][right][i] = res
    return res

s = input()
n = int(input())

dp = [[[Field(0) for _ in range(10 * len(s))] for _ in range(len(s) + 1)] for _ in range(len(s) + 1)]
ok = [[[False for _ in range(10 * len(s))] for _ in range(len(s) + 1)] for _ in range(len(s) + 1)]

base = []
for i in range(10 * len(s)):
    base.append(go(0, len(s), i))

solver = BMSolver(Poly)
solver.solve(base)
print(solver.compute(n))
