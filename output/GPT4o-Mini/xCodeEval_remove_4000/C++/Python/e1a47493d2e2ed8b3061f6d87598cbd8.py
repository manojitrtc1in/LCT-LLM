from sys import stdin, stdout
from itertools import accumulate

def solve():
    n, k = map(int, stdin.readline().split())
    k += 1
    a = list(map(int, stdin.readline().split()))
    a.sort(reverse=True)

    b = [0] * n
    for i in range(n):
        b[n - 1 - i] = a[n - 1 - i] * (i // max(k, 1))

    b = list(accumulate(reversed(b), initial=0))[1:]

    cum = 0
    sum_ = 0
    ans = b[0]

    if k > 0:
        for i in range(n):
            res = sum_ + b[i]
            longest = (n - i - 1) // k + 1
            ans = max(ans, res + cum * longest)
            sum_ += cum
            cum += a[i]

    stdout.write(f"{ans}\n")

if __name__ == "__main__":
    solve()
