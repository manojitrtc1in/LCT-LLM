MAX = 1200000
dp = [0] * (MAX + 1)
pi = [0] * (MAX + 1)

def sieve():
    for i in range(2, MAX):
        dp[i] = 1
    for i in range(2, MAX):
        if dp[i]:
            for j in range(2 * i, MAX, i):
                dp[j] = 0
    pi[1] = 0
    for i in range(2, MAX + 1):
        pi[i] = pi[i - 1] + 1 if dp[i] else pi[i - 1]

