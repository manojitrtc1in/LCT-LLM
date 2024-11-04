import math

MAXP = 1000000
INTER = 10000

sieve = [True] * MAXP
prime = []
primes = 0

def createsieve():
    global sieve
    q = int(math.sqrt(MAXP))
    sieve[0] = sieve[1] = False
    for i in range(2, q):
        if sieve[i]:
            for j in range(i * i, MAXP, i):
                sieve[j] = False

def id0():
    global primes
    for i in range(MAXP):
        if sieve[i]:
            prime.append(i)
            primes += 1

def isprime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(primes):
        if prime[i] * prime[i] > n:
            break
        if n % prime[i] == 0:
            return False
    return True

