md = int(1e9 + 7)
class Mint:
    def __init__(self, value):
        self.value = value % md
    
    def __call__(self):
        return self.value
    
    def __str__(self):
        return str(self.value)
    
    def __repr__(self):
        return str(self.value)
    
    def __eq__(self, other):
        return self.value == other.value
    
    def __ne__(self, other):
        return self.value != other.value
    
    def __lt__(self, other):
        return self.value < other.value
    
    def __le__(self, other):
        return self.value <= other.value
    
    def __gt__(self, other):
        return self.value > other.value
    
    def __ge__(self, other):
        return self.value >= other.value
    
    def __add__(self, other):
        return Mint(self.value + other.value)
    
    def __sub__(self, other):
        return Mint(self.value - other.value)
    
    def __mul__(self, other):
        return Mint(self.value * other.value)
    
    def __truediv__(self, other):
        return Mint(self.value * pow(other.value, md - 2, md))
    
    def __pow__(self, other):
        return Mint(pow(self.value, other.value, md))
    
    def __neg__(self):
        return Mint(-self.value)
    
    def __pos__(self):
        return Mint(self.value)
    
    def __abs__(self):
        return Mint(abs(self.value))
    
    def __int__(self):
        return self.value
    
    def __float__(self):
        return float(self.value)
    
    def __complex__(self):
        return complex(self.value)
    
    def __bool__(self):
        return bool(self.value)
    
    def __hash__(self):
        return hash(self.value)
    
    def __index__(self):
        return self.value

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

def power(a, b):
    x = a
    res = Mint(1)
    p = b
    while p > 0:
        if p & 1:
            res *= x
        x *= x
        p >>= 1
    return res

def solve():
    tt = int(input())
    for _ in range(tt):
        m = int(input())
        d = []
        while m > 0:
            d.append(m & 1)
            m >>= 1
        dp = [Mint(0)] * 7
        new_dp = [Mint(0)] * 7
        dp[0] = Mint(1)
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
