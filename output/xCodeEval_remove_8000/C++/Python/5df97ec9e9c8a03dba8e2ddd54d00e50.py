import math

def is_prime(x):
    if x < 2:
        return False
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return False
    return True

def f(n):
    if n <= 1:
        return 0
    if n <= 4:
        return 1
    sum = 1
    bl = n // 100000
    for i in range(bl):
        sum += block[i]

    for i in range(max(5, bl * 100000 + 1), n + 1, 4):
        if is_prime(i):
            sum += 1
    return sum

block = [
