from collections import defaultdict
import sys
import itertools

input = sys.stdin.read
INT_INF = 0x3f3f3f3f
LL_INF = 0x3f3f3f3f3f3f3f3f

def dfs(v, prev):
    SZV = 1
    dp[v][0] = (0, W[v] - B[v])
    for w in adj[v]:
        if w != prev:
            SZW = dfs(w, v)
            for i in range(SZW, 0, -1):
                dp[w][i] = max(dp[w][i], (dp[w][i - 1][0] + int(dp[w][i - 1][1] > 0), 0))
            merged = [(-INT_INF, -LL_INF)] * (SZV + SZW)
            for i in range(SZV):
                for j in range(SZW + 1):
                    merged[i + j] = max(merged[i + j], (dp[v][i][0] + dp[w][j][0], dp[v][i][1] + dp[w][j][1]))
            dp[v] = merged
            SZV += SZW
    return SZV

def main():
    global B, W, dp, adj
    data = input().split()
    index = 0
    T = int(data[index])
    index += 1
    results = []
    
    for _ in range(T):
        N = int(data[index])
        M = int(data[index + 1])
        index += 2
        B = list(map(int, data[index:index + N]))
        index += N
        W = list(map(int, data[index:index + N]))
        index += N
        
        adj = defaultdict(list)
        for _ in range(N - 1):
            a = int(data[index]) - 1
            b = int(data[index + 1]) - 1
            index += 2
            adj[a].append(b)
            adj[b].append(a)
        
        dp = [[(-INT_INF, -LL_INF)] * (N + 1) for _ in range(N)]
        dfs(0, -1)
        results.append(dp[0][M - 1][0] + int(dp[0][M - 1][1] > 0))
    
    print('\n'.join(map(str, results)))

if __name__ == "__main__":
    main()
