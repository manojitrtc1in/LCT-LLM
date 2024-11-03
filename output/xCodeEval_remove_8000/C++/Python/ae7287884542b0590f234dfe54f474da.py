MAX = 1200001

dp = [0] * MAX
pi = [0] * MAX

def sieve():
    for i in range(2, MAX):
        dp[i] = 1
    for i in range(2, MAX):
        if dp[i]:
            for j in range(2*i, MAX, i):
                dp[j] = 0
    pi[1] = 0
    for i in range(2, MAX):
        if dp[i]:
            pi[i] = pi[i-1] + 1
        else:
            pi[i] = pi[i-1]

