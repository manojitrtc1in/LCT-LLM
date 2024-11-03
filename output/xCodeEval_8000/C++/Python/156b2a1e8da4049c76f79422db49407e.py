n, k = map(int, input().split())
p = list(map(float, input().split()))

def solve(id):
    if p[id] <= 1e-9:
        print('0', end=' ')
        return
    subret = [0] * (k+1)
    subret[0] = dp[0] = p[id]
    for i in range(1, 1 << n):
        dp[i] = 0
        if (i >> id) & 1:
            continue
        sum = 0
        for j in range(n):
            if (i >> j) & 1:
                sum += p[j]
                dp[i] += dp[i ^ (1 << j)] * p[j]
        dp[i] /= 1 - sum
        subret[bin(i).count('1')] += dp[i]
    ret = sum(subret[:k])
    print(f'{ret:.10f}', end=' ')

for i in range(n):
    solve(i)
print()
