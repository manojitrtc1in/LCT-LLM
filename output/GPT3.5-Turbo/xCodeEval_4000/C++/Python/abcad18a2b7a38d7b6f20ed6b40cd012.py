class Modular:
    def __init__(self, value):
        self.value = value

    def __call__(self):
        return self.value

    def __add__(self, other):
        return Modular((self.value + other.value) % self.mod())

    def __sub__(self, other):
        return Modular((self.value - other.value) % self.mod())

    def __mul__(self, other):
        return Modular((self.value * other.value) % self.mod())

    def __truediv__(self, other):
        return Modular(self.value * self.inverse(other.value, self.mod()))

    def __eq__(self, other):
        return self.value == other.value

    def __lt__(self, other):
        return self.value < other.value

    def mod(self):
        return 1000000007

    @staticmethod
    def inverse(a, m):
        u, v = 0, 1
        while a != 0:
            t = m // a
            m -= t * a
            a, m = m, a
            u -= t * v
            u, v = v, u
        assert m == 1
        return u

    def power(self, a, b):
        assert b >= 0
        x = a
        res = Modular(1)
        p = b
        while p > 0:
            if p & 1:
                res *= x
            x *= x
            p >>= 1
        return res

    def normalize(self, x):
        v = x % self.mod()
        if v < 0:
            v += self.mod()
        return v

    def __str__(self):
        return str(self.value)


def solve():
    tt = int(input())
    for _ in range(tt):
        m = int(input())
        d = []
        while m > 0:
            d.append(m & 1)
            m >>= 1
        dp = [Modular(0) for _ in range(7)]
        new_dp = [Modular(0) for _ in range(7)]
        dp[0] = Modular(1)
        for it in range(len(d) - 1, -1, -1):
            if d[it] == 0:
                new_dp[0] = dp[0] + dp[1] + dp[2] + dp[3]
                new_dp[1] = new_dp[2] = dp[1] + dp[2] + dp[3] + dp[4]
                new_dp[3] = new_dp[4] = dp[2] + dp[3] + dp[4] + dp[5]
                new_dp[5] = new_dp[6] = dp[3] + dp[4] + dp[5] + dp[6]
            else:
                new_dp[0] = new_dp[1] = dp[0] + dp[1] + dp[2] + dp[3]
                new_dp[2] = new_dp[3] = dp[1] + dp[2] + dp[3] + dp[4]
                new_dp[4] = new_dp[5] = dp[2] + dp[3] + dp[4] + dp[5]
                new_dp[6] = dp[3] + dp[4] + dp[5] + dp[6]
            dp, new_dp = new_dp, dp
        print(dp[0])


solve()
