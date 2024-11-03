import random

def solve(id, p, n, k):
    if p[id] <= 1e-9:
        return '0'
    
    subret = [0] * (k+1)
    subret[0] = dp = p[id]
    for i in range(1, (1 << n)):
        dp = 0
        if (i >> id) & 1:
            continue
        sum = 0
        for j in range(n):
            if (i >> j) & 1:
                sum += p[j]
                dp += dp ^ (1 << j) * p[j]
        dp /= 1 - sum
        subret[bin(i).count('1')] += dp
    
    ret = sum(subret[:k+1])
    return str(ret)

def main():
    n, k = map(int, input().split())
    p = list(map(float, input().split()))
    
    for i in range(n):
        print(solve(i, p, n, k))

if __name__ == "__main__":
    main()