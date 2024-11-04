import sys

def solve(n, k, arrs):
    sums = []
    for arr in arrs:
        if len(arr) > k:
            arr = arr[:k]
        sums.append(sum(arr))
    
    dps = [[0] * (k+1) for _ in range(13)]
    def do_copy(dpi):
        dps[dpi+1] = dps[dpi].copy()
    
    def add_to_knap(i, dpi):
        v = sums[i]
        k1 = len(arrs[i])
        for j in range(k, k1-1, -1):
            dps[dpi][j] = max(dps[dpi][j], dps[dpi][j-k1] + v)
    
    def rec(l, r, dpi):
        ans = 0
        carr = arrs[l]
        dp = dps[dpi]
        if l+1 == r:
            ans = max(ans, dp[k])
            _sum = 0
            for i in range(min(k, len(carr))):
                _sum += carr[i]
                ans = max(ans, dp[k-i-1] + _sum)
        else:
            def do_split(l1, r1, l2, r2):
                do_copy(dpi)
                for i in range(l1, r1-1):
                    add_to_knap(i, dpi+1)
                return rec(l2, r2, dpi+1)
            
            m = (l+r)//2
            ans = max(ans, do_split(l, m, m, r))
            ans = max(ans, do_split(m, r, l, m))
        
        return ans
    
    return rec(0, n, 0)

def main():
    n, k = map(int, input().split())
    arrs = []
    for _ in range(n):
        t = int(input())
        arr = list(map(int, input().split()))
        arrs.append(arr)
    ans = solve(n, k, arrs)
    print(ans)

if __name__ == "__main__":
    main()
