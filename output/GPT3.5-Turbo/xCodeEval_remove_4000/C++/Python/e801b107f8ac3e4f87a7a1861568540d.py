import sys
from typing import List, Tuple, Dict, Any

def id0() -> None:
    sys.stdin = open(0)
    sys.stdout = open(1, 'w')
    sys.setrecursionlimit(10**6)
    sys.setswitchinterval(10**-6)
    sys.setrecursionlimit(10**9)

MOD = int(1e9) + 7
MX = int(2e5) + 5
INF = int(1e18)
PI = acos(-1)
xd = [1, 0, -1, 0]
yd = [0, 1, 0, -1]

def nod(a: int, b: int) -> int:
    if b > a:
        a, b = b, a
    while b > 0:
        a %= b
        a, b = b, a
    return a

def nok(a: int, b: int) -> int:
    return a * b // nod(a, b)

def sp(a: int, b: float) -> None:
    print(f'{b:.{a}f}', end='')

def binpow(a: int, n: int) -> int:
    if n == 0:
        return 1
    if n % 2 == 1:
        return binpow(a, n - 1) * a
    else:
        b = binpow(a, n // 2)
        return b * b

def read() -> Any:
    return input()

def read_double() -> float:
    return float(input())

def read_long_double() -> float:
    return float(input())

def read_list() -> List:
    return list(map(int, input().split()))

def read_tuple() -> Tuple:
    return tuple(map(int, input().split()))

def to_string(c: str) -> str:
    return str(c)

def to_string(b: bool) -> str:
    return 'true' if b else 'false'

def to_string(s: str) -> str:
    return s

def to_string(v: List[bool]) -> str:
    return ''.join(map(str, map(int, v)))

def to_string(b: int) -> str:
    return bin(b)[2:]

def to_string(v: Any) -> str:
    return ' '.join(map(str, v))

def write(x: Any) -> None:
    print(to_string(x), end='')

def print(*args: Any) -> None:
    write(' '.join(map(str, args)))
    write('\n')

def yes(ok: bool) -> None:
    print('YES' if ok else 'Yes')

def no(ok: bool) -> None:
    print('NO' if ok else 'No')

def solve() -> None:
    m: Dict[int, int] = {}
    n, s, k = read_tuple()
    ans = MOD
    cnt = 0
    for i in range(1, n + 1):
        a = read()
        if i >= k:
            m[a[i - k]] -= 1
            if m[a[i - k]] == 0:
                cnt -= 1
            m[a[i]] += 1
            if m[a[i]] == 1:
                cnt += 1
            ans = min(ans, cnt)
        else:
            m[a[i]] += 1
            if m[a[i]] == 1:
                cnt += 1
    ans = min(ans, cnt)
    print(ans)

def main() -> None:
    id0()
    t = 1
    t = int(input())
    for i in range(1, t + 1):
        solve()

if __name__ == '__main__':
    main()
