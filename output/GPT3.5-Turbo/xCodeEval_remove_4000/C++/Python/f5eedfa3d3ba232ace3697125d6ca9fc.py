import sys
from typing import List, Tuple

MOD = 1000000007

def solve() -> int:
    fact = [0] * 201010
    revFact = [0] * 202020
    fact[0] = 1
    N = 200000
    for i in range(1, N + 1):
        fact[i] = fact[i - 1] * i % MOD
    revFact[N] = pow(fact[N], MOD - 2, MOD)
    for i in range(N - 1, -1, -1):
        revFact[i] = revFact[i + 1] * (i + 1) % MOD
    
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.append(a[0])
    cnt = 0
    for i in range(n):
        cnt += a[i] != a[i + 1]
    if k == 1 or n == 1:
        return 0
    ans = 0
    freeChoices = k - 2
    for i in range(cnt // 2 + 1):
        cur = (fact[cnt] * revFact[i] % MOD * revFact[cnt - i] % MOD * pow(freeChoices, cnt - 2 * i, MOD) % MOD * pow(k, n - cnt, MOD) % MOD) % MOD
        ans += cur
    ans %= MOD
    tot = pow(k, n, MOD) - ans
    if tot < 0:
        tot += MOD
    return (tot * pow(2, MOD - 2, MOD) % MOD)

def main() -> None:
    n = int(input())
    for _ in range(n):
        solve()

if __name__ == "__main__":
    main()
