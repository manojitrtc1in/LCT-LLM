def is_prime(x):
    if x <= 1:
        return 0
    if x <= 4:
        return 1
    for i in range(3, int(x**0.5) + 1, 2):
        if x % i == 0:
            return 0
    return 1

def f(n):
    if n <= 1:
        return 0
    if n <= 4:
        return 1
    sum_primes = 1
    bl = n // 100000
    for i in range(bl):
        sum_primes += block[i]

    for i in range(max(5, bl * 100000 + 1), n + 1, 4):
        if is_prime(i):
            sum_primes += 1
    return sum_primes

block = [
