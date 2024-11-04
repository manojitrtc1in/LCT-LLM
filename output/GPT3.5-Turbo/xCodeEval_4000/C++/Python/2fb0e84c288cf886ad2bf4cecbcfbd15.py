class ModInt:
    def __init__(self, x, mod):
        self.x = x % mod
        self.mod = mod

    def __add__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x + other.x, self.mod)
        return ModInt(self.x + other, self.mod)

    def __sub__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x - other.x, self.mod)
        return ModInt(self.x - other, self.mod)

    def __mul__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x * other.x, self.mod)
        return ModInt(self.x * other, self.mod)

    def __pow__(self, n):
        if n == 0:
            return ModInt(1, self.mod)
        if n % 2 == 0:
            return (self * self) ** (n // 2)
        return self * (self ** (n - 1))

    def __eq__(self, other):
        if isinstance(other, ModInt):
            return self.x == other.x
        return self.x == other

    def __ne__(self, other):
        return not self.__eq__(other)

    def __str__(self):
        return str(self.x)

    def __repr__(self):
        return str(self.x)


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

    dp = [ModInt(0, m) for _ in range(n + 1)]
    p1 = [ModInt(0, m) for _ in range(n + 1)]

    dp[n] = ModInt(1, m)
    p1[n] = ModInt(1, m)

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
