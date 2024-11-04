def mulmod(a, b, MOD):
    if b == 0:
        return 0
    res = mulmod(a, b >> 1, MOD)
    res += res
    res %= MOD
    return (a + res) % MOD if b & 1 else res

def gcd(a, b):
    while a != 0 and b != 0:
        if a > b:
            a %= b
        else:
            b %= a
    return a + b

def gcd(a, b):
    while a != 0 and b != 0:
        if a > b:
            a %= b
        else:
            b %= a
    return a + b

