import sys
import math
from collections import defaultdict

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        self.index += 1
        return self.data[self.index - 1]

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return self.data[self.index:]

def count_digit(n):
    return int(math.floor(math.log10(n) + 1))

def id2(n):
    if n < 0:
        return -1
    sum_digits = 0
    while n > 0:
        sum_digits += n % 10
        n //= 10
    return sum_digits

def array_sum(arr, start, end):
    return sum(arr[start:end + 1])

def mod(x):
    return -x if x < 0 else x

def swap_array(arr, start, end):
    while start < end:
        arr[start], arr[end] = arr[end], arr[start]
        start += 1
        end -= 1

def rotate(input_matrix):
    n = len(input_matrix)
    m = len(input_matrix[0])
    output = [[0] * n for _ in range(m)]
    for i in range(n):
        for j in range(m):
            output[j][n - 1 - i] = input_matrix[i][j]
    return output

def count_bits(n):
    count = 0
    while n != 0:
        count += 1
        n >>= 1
    return count

def id0(n):
    return n != 0 and (n & (n - 1)) == 0

def min4(a, b, c, d):
    return min(a, b, c, d)

def max4(a, b, c, d):
    return max(a, b, c, d)

def reverse(input_str):
    return input_str[::-1]

def same_parity(a, b):
    return (a % 2) == (b % 2)

def id5(a, b, c):
    return a + b > c and c + b > a and a + c > b

def xnor(num1, num2):
    if num1 < num2:
        num1, num2 = num2, num1
    num1 = toggle_bit(num1)
    return num1 ^ num2

def toggle_bit(n):
    if n == 0:
        return 1
    i = n
    n |= n >> 1
    n |= n >> 2
    n |= n >> 4
    n |= n >> 8
    n |= n >> 16
    return i ^ n

def id6(n):
    if n % 4 == 0:
        return n
    elif n % 4 == 1:
        return 1
    elif n % 4 == 2:
        return n + 1
    else:
        return 0

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def lcm(a, b):
    return (a * b) // gcd(a, b)

def is_prime(n):
    if n == 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def sieve(max_n):
    spf = list(range(max_n + 1))
    for i in range(4, max_n + 1, 2):
        spf[i] = 2
    for i in range(3, int(math.sqrt(max_n)) + 1):
        if spf[i] == i:
            for j in range(i * i, max_n + 1, i):
                if spf[j] == j:
                    spf[j] = i
    return spf

def get_factorization(x, spf):
    ret = []
    while x != 1:
        ret.append(spf[x])
        x //= spf[x]
    return ret

def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m
    L = arr[l:m + 1]
    R = arr[m + 1:r + 1]
    i = j = 0
    k = l
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def sort(arr, l, r):
    if l < r:
        m = (l + r) // 2
        sort(arr, l, m)
        sort(arr, m + 1, r)
        merge(arr, l, m, r)

def knapsack(weight, value, max_weight):
    n = len(value)
    dp = [0] * (max_weight + 1)
    for i in range(n):
        for j in range(max_weight, weight[i] - 1, -1):
            dp[j] = max(dp[j], value[i] + dp[j - weight[i]])
    return dp[max_weight]

def kadanes_algorithm(arr):
    max_so_far = max_ending_here = arr[0]
    for i in range(1, len(arr)):
        max_ending_here = max(arr[i], max_ending_here + arr[i])
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far

def binary_search_greater(arr, start, end, val):
    if start > end:
        return 0
    mid = (start + end) // 2
    if arr[mid] <= val:
        return binary_search_greater(arr, mid + 1, end, val)
    else:
        return binary_search_greater(arr, start, mid - 1, val) + (end - mid + 1)

def swap_string(a, i, j):
    b = list(a)
    b[i], b[j] = b[j], b[i]
    return ''.join(b)

def generate_permutation(s, start, end):
    if start == end - 1:
        print(s)
    else:
        for i in range(start, end):
            s = swap_string(s, start, i)
            generate_permutation(s, start + 1, end)
            s = swap_string(s, start, i)

def fact_mod(n, mod):
    if n <= 1:
        return 1
    ans = 1
    for i in range(1, n + 1):
        ans = (ans * i) % mod
    return ans

def power(x, n):
    if n == 0:
        return 1
    if n == 1:
        return x
    ans = 1
    while n > 0:
        if n % 2 == 1:
            ans *= x
        n //= 2
        x *= x
    return ans

def lower_bound(arr, k):
    ans = -1
    start, end = 0, len(arr) - 1
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] <= k:
            ans = arr[mid]
            start = mid + 1
        else:
            end = mid - 1
    return ans

def upper_bound(arr, k):
    ans = -1
    start, end = 0, len(arr) - 1
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] >= k:
            ans = arr[mid]
            end = mid - 1
        else:
            start = mid + 1
    return ans

def print_array(arr, si, ei):
    print(" ".join(map(str, arr[si:ei + 1])))

def solve():
    scn = FastReader()
    testcases = 1
    for testcase in range(1, testcases + 1):
        n = scn.next_long()
        x = n
        list_factors = []
        for i in range(2, int(math.sqrt(n)) + 1):
            if x % i == 0:
                while x % i == 0:
                    list_factors.append(i)
                    x //= i
        if x > 1:
            list_factors.append(x)

        if n == 1:
            print(1)
            print(0)
        elif len(list_factors) == 2:
            print(2)
        else:
            print(1)
            if len(list_factors) == 1:
                print(0)
            else:
                ans = list_factors[0] * list_factors[1]
                print(ans)

def main():
    solve()

if __name__ == "__main__":
    main()
