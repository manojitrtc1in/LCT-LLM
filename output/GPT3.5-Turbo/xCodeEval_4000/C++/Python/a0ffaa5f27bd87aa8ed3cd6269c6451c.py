import sys
from typing import List, Tuple

MOD = 998244353

def solve(n: int, m: int, mod: int) -> int:
    def pow_mod(x: int, n: int, m: int) -> int:
        if m == 1:
            return 0
        r = 1
        y = x % m
        while n:
            if n & 1:
                r = (r * y) % m
            y = (y * y) % m
            n >>= 1
        return r

    def is_prime(n: int) -> bool:
        if n <= 1:
            return False
        if n == 2 or n == 7 or n == 61:
            return True
        if n % 2 == 0:
            return False
        d = n - 1
        while d % 2 == 0:
            d //= 2
        bases = [2, 7, 61]
        for a in bases:
            t = d
            y = pow_mod(a, t, n)
            while t != n - 1 and y != 1 and y != n - 1:
                y = (y * y) % n
                t <<= 1
            if y != n - 1 and t % 2 == 0:
                return False
        return True

    def inv_gcd(a: int, b: int) -> Tuple[int, int]:
        a = a % b
        if a == 0:
            return (b, 0)
        s = b
        t = a
        m0 = 0
        m1 = 1
        while t:
            u = s // t
            s -= t * u
            m0 -= m1 * u
            s, t = t, s
            m0, m1 = m1, m0
        if m0 < 0:
            m0 += b // s
        return (s, m0)

    def primitive_root(m: int) -> int:
        if m == 2:
            return 1
        if m == 167772161:
            return 3
        if m == 469762049:
            return 3
        if m == 754974721:
            return 11
        if m == 998244353:
            return 3
        divs = [0] * 20
        divs[0] = 2
        cnt = 1
        x = (m - 1) // 2
        while x % 2 == 0:
            x //= 2
        for i in range(3, int(x ** 0.5) + 1, 2):
            if x % i == 0:
                divs[cnt] = i
                while x % i == 0:
                    x //= i
                cnt += 1
        if x > 1:
            divs[cnt] = x
            cnt += 1
        for g in range(2, m):
            ok = True
            for i in range(cnt):
                if pow_mod(g, (m - 1) // divs[i], m) == 1:
                    ok = False
                    break
            if ok:
                return g
        return -1

    def ntt(f: List[int], g: List[int], p: int, root: int) -> None:
        n = len(f)
        if n == 1:
            g[0] = f[0]
            return
        m = n // 2
        f0 = [0] * m
        f1 = [0] * m
        g0 = [0] * m
        g1 = [0] * m
        for i in range(m):
            f0[i] = f[2 * i]
            f1[i] = f[2 * i + 1]
        ntt(f0, g0, p, (root * root) % p)
        ntt(f1, g1, p, (root * root) % p)
        x = 1
        for i in range(m):
            u = g0[i]
            v = (g1[i] * x) % p
            g[i] = (u + v) % p
            g[i + m] = (u - v) % p
            x = (x * root) % p

    def intt(f: List[int], g: List[int], p: int, root: int) -> None:
        n = len(f)
        inv_n = inv_gcd(n, p)[1]
        ntt(f, g, p, inv_gcd(root, p)[1])
        for i in range(n):
            g[i] = (g[i] * inv_n) % p

    def convolution(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_2(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_3(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_4(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_5(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_6(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_7(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_8(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_9(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_10(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_11(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_12(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_13(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_14(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_15(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_16(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_17(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_18(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    def convolution_mod_19(f: List[int], g: List[int], p: int, root: int) -> List[int]:
        n = len(f)
        m = len(g)
        if n == 0 or m == 0:
            return []
        z = 1 << (n + m - 2).bit_length()
        f = f + [0] * (z - n)
        g = g + [0] * (z - m)
        ntt(f, f, p, root)
        ntt(g, g, p, root)
        for i in range(z):
            f[i] = (f[i] * g[i]) % p
        intt(f, f, p, root)
        return f[:n + m - 1]

    if not is_prime(mod):
        return -1

    root = primitive_root(mod)
    f = [0] * (n + 1)
    for i in range(n + 1):
        f[i] = pow_mod(i + 1, i, mod)
    g = [0] * (n + 1)
    for i in range(n + 1):
        g[i] = pow_mod(i + 1, n - i, mod)
    h = convolution_mod(f, g, mod, root)
    ans = 0
    for i in range(m + 1):
        ans += h[i]
    return ans

def main() -> None:
    n, m, mod = map(int, input().split())
    ans = solve(n, m, mod)
    print(ans)

if __name__ == "__main__":
    main()
