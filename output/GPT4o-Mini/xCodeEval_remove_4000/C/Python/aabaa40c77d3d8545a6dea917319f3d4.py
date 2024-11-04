import math
import sys

MAXP = 10**6  # Define MAXP as needed
INTER = 1000  # Define INTER as needed

sieve = [1] * MAXP
prime = []
primes = 0

def createsieve():
    global sieve
    q = int(math.sqrt(MAXP))
    sieve[0] = sieve[1] = 0
    for i in range(2, q):
        if sieve[i]:
            for j in range(i * i, MAXP, i):
                sieve[j] = 0

def id0():
    global primes
    for i in range(MAXP):
        if sieve[i]:
            prime.append(i)
            primes += 1

def isprime(n):
    if n < 2:
        return 0
    if n == 2:
        return 1
    if n % 2 == 0:
        return 0
    for p in prime:
        if p * p > n:
            break
        if n % p == 0:
            return 0
    return 1

