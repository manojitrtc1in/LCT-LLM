import math

N = 18000
M = 18000
is_prime = [True] * N
primes = []
cntp = 0

def id0(n):
    global cntp
    k = 0
    e = int(math.sqrt(n) + 1)
    is_prime[0] = is_prime[1] = False
    primes.append(2)
    k += 1
    for i in range(4, n, 2):
        is_prime[i] = False
    for i in range(3, e, 2):
        if is_prime[i]:
            primes.append(i)
            k += 1
            for j in range(i * i, n, i * 2):
                is_prime[j] = False
    for i in range(e, n, 2):
        if is_prime[i]:
            primes.append(i)
            k += 1
    return k

