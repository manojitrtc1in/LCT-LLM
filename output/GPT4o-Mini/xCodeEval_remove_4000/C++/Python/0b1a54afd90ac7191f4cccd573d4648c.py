from collections import defaultdict

def gcd(a, b):
    if a < b:
        a, b = b, a
    if b == 0:
        return a
    if a % b == 0:
        return b
    return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

def pow_fast(x, n_power, modulus):
    if n_power == 0:
        return 1
    if n_power % 2 == 0:
        return pow_fast(x * x % modulus, n_power // 2, modulus)
    return x * pow_fast(x, n_power - 1, modulus) % modulus

def print_vector(h, verbose=True):
    L = len(h)
    for i in range(L):
        if verbose:
            print(h[i], end="")
        else:
            print(h[i], file=sys.stderr, end="")
        
        if i != L - 1:
            if verbose:
                print(" ", end="")
            else:
                print(" ", file=sys.stderr, end="")
        else:
            if verbose:
                print()
            else:
                print(file=sys.stderr)

def main():
    N = int(input())
    a = [0] * N
    mp = defaultdict(int)

    for i in range(N):
        a[i] = int(input())
        mp[a[i]] += 1

    b = [0] * N
    for i in range(N):
        b[i] = int(input())

    vs = [elem for elem, count in mp.items() if count > 1]

    ans = 0
    for i in range(N):
        isok = any((elem & a[i]) == a[i] for elem in vs)
        if isok:
            ans += b[i]

    print(ans)

if __name__ == "__main__":
    main()
