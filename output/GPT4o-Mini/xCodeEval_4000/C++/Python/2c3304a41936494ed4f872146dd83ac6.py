import sys

M = 1000000007

def main():
    s = input().strip()
    t = input().strip()
    
    sz1 = len(s)
    sz2 = len(t)
    
    dp = [[0] * (sz2 + 1) for _ in range(sz1 + 1)]
    
    for i in range(sz1):
        for j in range(sz2):
            dp[i + 1][j + 1] = (dp[i + 1][j] % M + (s[i] == t[j]) * ((dp[i][j] + 1) % M)) % M
            
    re = 0
    for i in range(sz1):
        re = (re + dp[i + 1][sz2] % M) % M
        
    print(re)

if __name__ == "__main__":
    main()