import sys
from collections import defaultdict

mod = pow(10, 9) + 7

def main():
    n, m = map(int, input().split())
    a = [n // m] * m
    for i in range(1, n % m + 1):
        a[i] += 1
    
    b = [0] * m
    for i in range(m):
        t = (i * i) % m
        b[t] += a[i]
    
    ans = 0
    for i in range(m):
        if i == 0:
            ans += b[i] * b[i]
        else:
            ans += b[i] * b[m - i]
    
    print(ans % mod)

if __name__ == "__main__":
    main()
