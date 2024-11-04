class modint:
    def __init__(self, v, m):
        self.v = v % m
        self.m = m

    def __add__(self, other):
        return modint(self.v + other.v, self.m)

    def __sub__(self, other):
        return modint(self.v - other.v, self.m)

    def __mul__(self, other):
        return modint(self.v * other.v, self.m)

    def __truediv__(self, other):
        return modint(self.v * pow(other.v, self.m - 2, self.m), self.m)

    def __pow__(self, n):
        return modint(pow(self.v, n, self.m), self.m)

    def __eq__(self, other):
        return self.v == other.v

    def __ne__(self, other):
        return self.v != other.v

    def __str__(self):
        return str(self.v)

def get(i, z):
    l = i * z
    r = (i + i) * z
    ans = l
    while l <= r:
        m = (l + r) // 2
        if m // z > i:
            r = m - 1
        else:
            ans = max(ans, m)
            l = m + 1
    return ans

def solve():
    n, m = map(int, input().split())
    dp = [modint(0, m) for _ in range(n + 1)]
    p1 = [modint(0, m) for _ in range(n + 1)]
    dp[n] = modint(1, m)
    p1[n] = modint(1, m)
    for i in range(n - 1, 0, -1):
        dp[i] += p1[i + 1]
        for z in range(2, n // i + 1):
            r = get(i, z) + 1
            l = z * i
            dp[i] += p1[l]
            if r <= n:
                dp[i] -= p1[r]
        p1[i] = p1[i + 1] + dp[i]
    print(dp[1])

solve()
