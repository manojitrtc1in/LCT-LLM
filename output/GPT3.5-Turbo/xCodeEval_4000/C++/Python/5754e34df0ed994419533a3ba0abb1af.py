import sys

def read_int():
    return int(sys.stdin.readline())

def read_list():
    return list(map(int, sys.stdin.readline().split()))

def sum_digits(n):
    s = 0
    while n > 0:
        s += n % 10
        n //= 10
    return s

def solve():
    n, k = read_list()
    arrs = []
    for _ in range(n):
        t = read_int()
        arrs.append(list(map(int, sys.stdin.readline().split())))
    
    sums = [sum_digits(sum(arr)) for arr in arrs]
    
    dps = [[0] * (k + 1) for _ in range(13)]
    
    def do_copy(dpi):
        dps[dpi + 1] = dps[dpi].copy()
    
    def add_to_knap(i, dpi):
        v = sums[i]
        k1 = len(arrs[i])
        for j in range(k, k1 - 1, -1):
            dps[dpi][j] = max(dps[dpi][j], dps[dpi][j - k1] + v)
    
    def rec(l, r, dpi):
        ans = 0
        carr = arrs[l]
        dp = dps[dpi]
        if l + 1 == r:
            ans = max(ans, dp[k])
            s = 0
            for i in range(min(k, len(carr))):
                s += carr[i]
                ans = max(ans, dp[k - i - 1] + s)
        else:
            def do_split(l1, r1, l2, r2):
                dps[dpi + 1] = dps[dpi].copy()
                for i in range(l1, r1):
                    add_to_knap(i, dpi + 1)
                return rec(l2, r2, dpi + 1)
            
            m = (l + r) // 2
            ans = max(ans, do_split(l, m, m, r))
            ans = max(ans, do_split(m, r, l, m))
        
        return ans
    
    print(rec(0, n, 0))

solve()
