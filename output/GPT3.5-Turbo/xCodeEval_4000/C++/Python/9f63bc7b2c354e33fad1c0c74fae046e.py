class modint:
    def __init__(self, v):
        self.v = v

    def __add__(self, other):
        return modint((self.v + other.v) % mod)

    def __sub__(self, other):
        return modint((self.v - other.v + mod) % mod)

    def __mul__(self, other):
        return modint((self.v * other.v) % mod)

    def __pow__(self, n):
        if n == 0:
            return modint(1)
        elif n % 2 == 0:
            return (self * self) ** (n // 2)
        else:
            return self * (self ** (n - 1))

    def __eq__(self, other):
        return self.v == other.v

    def __ne__(self, other):
        return self.v != other.v

    def __str__(self):
        return str(self.v)


def get(i, z):
    l1 = 1 * i * z
    r1 = 1 * (i + i) * z
    ans = l1

    while l1 <= r1:
        m = (l1 + r1) // 2
        if m // z > i:
            r1 = m - 1
        else:
            ans = max(ans, m)
            l1 = m + 1

    return ans


def solve():
    n, m = map(int, input().split())

    dp = [modint(0)] * (n + 1)
    p = [modint(0)] * (n + 1)

    dp[n] = modint(1)
    p[n] = modint(1)

    for i in range(n - 1, 0, -1):
        dp[i] += p[i + 1]

        for z in range(2, n // i + 1):
            r = get(i, z) + 1
            l = z * i
            dp[i] += p[l]
            if r <= n:
                dp[i] -= p[r]

        p[i] = p[i + 1] + dp[i]

    print(dp[1])


solve()
