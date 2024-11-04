import sys
from collections import defaultdict
from math import gcd, isqrt

input = sys.stdin.read
M = 998244353

def inverse(a, n):
    c = extended_gcd(a, n)[0]
    if c < 0:
        c += n
    return c

def extended_gcd(a, b):
    if b == 0:
        return (1, 0)
    x1, y1 = extended_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return (x, y)

def prod(a, b, M):
    return (a * b) % M

def sum(a, b, M):
    c = a + b
    return c - M if c >= M else c

def raz(a, b, M):
    c = a - b
    return c + M if c < 0 else c

def main():
    data = input().split()
    n = int(data[0])
    m = int(data[1])
    a = list(map(int, data[2:n + 2]))
    w = list(map(int, data[n + 2:n + 2 + n]))

    W1 = sum(w[i] for i in range(n) if a[i])
    W2 = sum(w[i] for i in range(n) if not a[i])

    probs = [0] * (m + 1)
    probs[0] = 1

    for i in range(m):
        new_probs = [0] * (m + 1)
        for d1 in range(i + 1):
            d2 = d1 - i
            w1 = W1 + d1
            w2 = W2 + d2
            w0 = w1 + w2
            if probs[d1] and w2 >= 0:
                id16 = inverse(w0, M)
                if w2 > 0:
                    new_probs[d1] = sum(new_probs[d1], prod(probs[d1], prod(w2, id16, M), M), M)
                new_probs[d1 + 1] = sum(new_probs[d1 + 1], prod(probs[d1], prod(w1, id16, M), M), M)
        probs = new_probs

    id4 = [0] * (m + 1)
    id29 = [0] * (m + 1)
    id4[0] = 1
    id29[0] = 1

    for i in range(1, m + 1):
        id4[i] = prod(id4[i - 1], sum(1, inverse(W1 + i - 1, M), M), M)

    for i in range(1, m + 1):
        id29[i] = prod(id29[i - 1], raz(1, inverse(W2 - i + 1, M), M), M)

    coef1 = 0
    coef2 = 0

    for i in range(m + 1):
        coef1 = sum(coef1, prod(id4[i], probs[i], M), M)

    for i in range(m + 1):
        coef2 = sum(coef2, prod(id29[i], probs[m - i], M), M)

    for i in range(n):
        if a[i]:
            print(prod(w[i], coef1, M))
        else:
            print(prod(w[i], coef2, M))

if __name__ == "__main__":
    main()
