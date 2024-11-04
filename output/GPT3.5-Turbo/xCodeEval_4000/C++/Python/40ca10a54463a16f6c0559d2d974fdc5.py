import math

N = 18000
M = 18000
is_prime = [True] * N
prm = []
cntp = 0

def getprm(n):
    global cntp
    global prm
    is_prime[0] = is_prime[1] = False
    prm.append(2)
    cntp += 1
    for i in range(4, n, 2):
        is_prime[i] = False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if is_prime[i]:
            prm.append(i)
            cntp += 1
            for j in range(i * i, n, i * 2):
                is_prime[j] = False
    for i in range(i, n, 2):
        if is_prime[i]:
            prm.append(i)
            cntp += 1
    return cntp

def getr(l, r):
    isp = [True] * (r - l + 1)
    for i in range(len(prm)):
        j = l // prm[i] * prm[i]
        if j < l:
            j += prm[i]
        if j <= prm[i] * prm[i]:
            j = prm[i] * prm[i]
        while j <= r:
            isp[j - l] = False
            j += prm[i]
    ret = 0
    for i in range(l, r + 1):
        if isp[i - l] and i % 4 == 1:
            ret += 1
    return ret

def get(n):
    if n == 1:
        return 0
    if n % 100000 == 0:
        return f[n // 100000] + (n >= 2)
    else:
        return f[n // 100000] + (n > 100000) + getr(n // 100000 * 100000 + 1, n)

