import math
import array

N = 18000
M = 18000
is_prime = array.array('b', [True] * N)
prm = array.array('i')
cntp = 0

def id0(n):
    global cntp
    prm.append(2)
    is_prime[0] = is_prime[1] = False
    for i in range(4, n, 2):
        is_prime[i] = False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if is_prime[i]:
            prm.append(i)
            for j in range(i * 2, n, i):
                is_prime[j] = False
    for i in range(i, n, 2):
        if is_prime[i]:
            prm.append(i)
    cntp = len(prm)
    return cntp

