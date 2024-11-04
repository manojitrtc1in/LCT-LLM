from collections import defaultdict
import sys
import time

class Modular:
    def __init__(self, value=0, mod=10**9 + 7):
        self.value = value % mod
        self.mod = mod

    def __call__(self):
        return self.value

    def __add__(self, other):
        return Modular(self.value + other.value, self.mod)

    def __sub__(self, other):
        return Modular(self.value - other.value, self.mod)

    def __mul__(self, other):
        return Modular(self.value * other.value, self.mod)

    def __truediv__(self, other):
        return self * Modular(inverse(other.value, self.mod), self.mod)

    def __repr__(self):
        return str(self.value)

def inverse(a, m):
    u, v = 0, 1
    while a != 0:
        t = m // a
        m, a = a, m - t * a
        u, v = v, u - t * v
    assert m == 1
    return u % m

def main():
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    tt = int(data[index])
    index += 1
    results = []
    
    for _ in range(tt):
        m = int(data[index])
        index += 1
        d = []
        
        while m > 0:
            d.append(m & 1)
            m >>= 1
        
        len_d = len(d)
        dp = [Modular(0) for _ in range(7)]
        new_dp = [Modular(0) for _ in range(7)]
        dp[0] = Modular(1)

        for it in range(len_d - 1, -1, -1):
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

        results.append(str(dp[0]()))
    
    print('\n'.join(results))

if __name__ == "__main__":
    start_time = time.time()
    main()
    print("Execution time:", time.time() - start_time)
