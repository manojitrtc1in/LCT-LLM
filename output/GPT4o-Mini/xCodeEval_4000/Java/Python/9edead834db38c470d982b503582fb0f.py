import sys
import random
from collections import deque

mod = 10**9 + 7

def main():
    n = int(sys.stdin.readline().strip())
    m = int(sys.stdin.readline().strip())
    a = [n // m] * m
    for i in range(1, n % m + 1):
        a[i] += 1

    b = [0] * m
    for i in range(m):
        t = (i % m * i % m) % m
        b[t] += a[i]

    ans = 0
    for i in range(m):
        if i == 0:
            ans += b[i] * b[i]
        else:
            ans += b[i] * b[m - i]

    print(ans)

def fact_sieve(fact, n):
    for i in range(2, n + 1, 2):
        fact[i] = 2

    for i in range(3, n + 1, 2):
        if fact[i] == 0:
            fact[i] = i
            for j in range(i, n // i + 1):
                fact[i * j] = i

def gcd(p2, p22):
    if p2 == 0:
        return p22
    return gcd(p22 % p2, p2)

def next_greater(a):
    ans = [-1] * len(a)
    stk = []
    for i in range(len(a)):
        while stk and a[stk[-1]] < a[i]:
            ans[stk.pop()] = i
        stk.append(i)
    return ans

def next_greater_rev(a):
    n = len(a)
    pans = [-1] * n
    arev = a[::-1]
    stk = []
    for i in range(n):
        while stk and arev[stk[-1]] < arev[i]:
            pans[stk.pop()] = n - i - 1
        stk.append(i)
    return pans[::-1]

def next_smaller(a):
    ans = [-1] * len(a)
    stk = []
    for i in range(len(a)):
        while stk and a[stk[-1]] > a[i]:
            ans[stk.pop()] = i
        stk.append(i)
    return ans

def lcm(numbers):
    lcm = 1
    divisor = 2
    while True:
        cnt = 0
        divisible = False
        for i in range(len(numbers)):
            if numbers[i] == 0:
                return 0
            elif numbers[i] < 0:
                numbers[i] = -numbers[i]
            if numbers[i] == 1:
                cnt += 1
            if numbers[i] % divisor == 0:
                divisible = True
                numbers[i] //= divisor
        if divisible:
            lcm *= divisor
        else:
            divisor += 1
        if cnt == len(numbers):
            return lcm

def factorial(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

def choose(total, choose):
    if total < choose:
        return 0
    if choose == 0 or choose == total:
        return 1
    return (choose(total - 1, choose - 1) + choose(total - 1, choose)) % mod

def shuffle(arr):
    n = len(arr)
    for i in range(n):
        ind = random.randint(i, n - 1)
        arr[ind], arr[i] = arr[i], arr[ind]
    return arr

def shuffle_sort(arr):
    n = len(arr)
    arr = shuffle(arr)
    arr.sort()
    return arr

def floor_search(arr, low, high, x):
    if low > high:
        return -1
    if x > arr[high]:
        return high
    mid = (low + high) // 2
    if mid > 0 and arr[mid - 1] < x < arr[mid]:
        return mid - 1
    if x < arr[mid]:
        return floor_search(arr, low, mid - 1, x)
    return floor_search(arr, mid + 1, high, x)

def swap(a, b):
    return b, a

def prime_factorization(n):
    factors = []
    for i in range(2, int(n**0.5) + 1):
        while n % i == 0:
            factors.append(i)
            n //= i
    if n != 1:
        factors.append(n)
    return factors

def sieve(is_prime, n):
    for i in range(2, n):
        is_prime[i] = True
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(n**0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n, i):
                is_prime[j] = False

def lower_bound(net, c2):
    i = bisect.bisect_left(net, c2)
    return i

def lower_bound_array(dis, c2):
    i = bisect.bisect_left(dis, c2)
    return i

def upper_bound(list_, c2):
    i = bisect.bisect_right(list_, c2)
    return i

def upper_bound_array(dis, c2):
    i = bisect.bisect_right(dis, c2)
    return i

def gcd_int(a, b):
    while b:
        a, b = b, a % b
    return a

def extended_euclid(A, B):
    if B == 0:
        return A, 1, 0
    d, p, q = extended_euclid(B, A % B)
    return d, q, p - (A // B) * q

def lcm_int(a, b):
    return (a * b) // gcd_int(a, b)

def binary_exponentiation(x, n):
    result = 1
    while n > 0:
        if n % 2 == 1:
            result *= x
        x *= x
        n //= 2
    return result

def count_der(n):
    der = [0] * (n + 1)
    der[0] = 1
    der[1] = 0
    der[2] = 1
    for i in range(3, n + 1):
        der[i] = (i - 1) * (der[i - 1] + der[i - 2])
    return der

def binomial_coeff(n, k):
    C = [[0] * (k + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        for j in range(min(i, k) + 1):
            if j == 0 or j == i:
                C[i][j] = 1
            else:
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j]
    return C[n][k]

def modular_exponentiation(x, n, M):
    result = 1
    while n > 0:
        if n % 2 == 1:
            result = (result * x) % M
        x = (x * x) % M
        n //= 2
    return result

def mod_inverse(A, M):
    return modular_exponentiation(A, M - 2, M)

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    for i in range(5, int(n**0.5) + 1, 6):
        if n % i == 0 or n % (i + 2) == 0:
            return False
    return True

class Pair:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, other):
        return (self.x, self.y) < (other.x, other.y)

    def __str__(self):
        return f"{self.x} {self.y}"

    def __eq__(self, other):
        return isinstance(other, Pair) and self.x == other.x and self.y == other.y

class Triplet:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def __lt__(self, other):
        return (self.x, self.y, self.z) < (other.x, other.y, other.z)

    def __str__(self):
        return f"{self.x} {self.y} {self.z}"

    def __eq__(self, other):
        return isinstance(other, Triplet) and self.x == other.x and self.y == other.y and self.z == other.z

if __name__ == "__main__":
    main()
