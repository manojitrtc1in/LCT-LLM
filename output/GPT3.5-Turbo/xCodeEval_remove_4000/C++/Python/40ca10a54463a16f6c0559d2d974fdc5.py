import math
import sys

N = 18000
M = 18000
is_prime = [True] * N
prm = []
cntp = 0

def id0(n):
    global cntp
    global prm
    k = 0
    s = int(math.sqrt(n) + 1)
    is_prime[0] = is_prime[1] = False
    prm.append(2)
    k += 1
    for i in range(4, n, 2):
        is_prime[i] = False
    for i in range(3, s, 2):
        if is_prime[i]:
            prm.append(i)
            k += 1
            for j in range(i * 2, n, i):
                is_prime[j] = False
    for i in range(s, n, 2):
        if is_prime[i]:
            prm.append(i)
            k += 1
    cntp = k
    return k

