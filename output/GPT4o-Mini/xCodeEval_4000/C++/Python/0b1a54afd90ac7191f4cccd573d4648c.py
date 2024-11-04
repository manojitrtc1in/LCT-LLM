import sys
from collections import defaultdict

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    a = list(map(int, data[1:N+1]))
    b = list(map(int, data[N+1:2*N+1]))

    mp = defaultdict(int)
    for num in a:
        mp[num] += 1

    vs = [key for key, value in mp.items() if value > 1]

    ans = 0
    for i in range(N):
        isok = any((elem & a[i]) == a[i] for elem in vs)
        if isok:
            ans += b[i]

    print(ans)

if __name__ == "__main__":
    main()
