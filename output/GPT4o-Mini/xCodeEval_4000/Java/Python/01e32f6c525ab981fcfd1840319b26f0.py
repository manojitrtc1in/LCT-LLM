import sys
from collections import defaultdict
from math import log10, floor

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        self.index += 1
        return self.data[self.index - 1]

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        return self.data[self.index]

def countDigit(n):
    return int(floor(log10(n) + 1))

def sumOfDigits(n):
    if n < 0:
        return -1
    sum_digits = 0
    while n > 0:
        sum_digits += n % 10
        n //= 10
    return sum_digits

def arraySum(arr, start, end):
    return sum(arr[start:end + 1])

def mod(x):
    return -x if x < 0 else x

def swapArray(arr, start, end):
    while start < end:
        arr[start], arr[end] = arr[end], arr[start]
        start += 1
        end -= 1

def rotate(input):
    n = len(input)
    m = len(input[0])
    output = [[0] * n for _ in range(m)]
    for i in range(n):
        for j in range(m):
            output[j][n - 1 - i] = input[i][j]
    return output

def countBits(n):
    count = 0
    while n != 0:
        count += 1
        n >>= 1
    return count

def isPowerOfTwo(n):
    return n != 0 and (n & (n - 1)) == 0

def min(a, b, c, d):
    return sorted([a, b, c, d])[0]

def max(a, b, c, d):
    return sorted([a, b, c, d])[3]

def reverse(input):
    return input[::-1]

def sameParity(a, b):
    return (a % 2) == (b % 2)

def isPossibleTriangle(a, b, c):
    return a + b > c and b + c > a and a + c > b

def xnor(num1, num2):
    if num1 < num2:
        num1, num2 = num2, num1
    num1 = togglebit(num1)
    return num1 ^ num2

def togglebit(n):
    if n == 0:
        return 1
    i = n
    n |= n >> 1
    n |= n >> 2
    n |= n >> 4
    n |= n >> 8
    n |= n >> 16
    return i ^ n

def xorOfFirstN(n):
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

def sieveOfEratosthenes(sieve):
    prime = [False] * (sieve + 1)
    for i in range(4, sieve + 1):
        prime[i] = True
    for p in range(3, int(sieve**0.5) + 1):
        if not prime[p]:
            for i in range(p * p, sieve + 1, p):
                prime[i] = True
    return prime

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

def knapsack(weight, value, maxWeight):
    n = len(value)
    dp = [0] * (maxWeight + 1)
    for i in range(n):
        for j in range(maxWeight, weight[i] - 1, -1):
            dp[j] = max(dp[j], value[i] + dp[j - weight[i]])
    return dp[maxWeight]

def kadanesAlgorithm(arr):
    dp = [0] * len(arr)
    dp[0] = arr[0]
    max_sum = dp[0]
    for i in range(1, len(arr)):
        dp[i] = max(dp[i - 1] + arr[i], arr[i])
        max_sum = max(max_sum, dp[i])
    return max_sum

def lowerBound(arr, k):
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

def upperBound(arr, k):
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

def printArray(arr, si, ei):
    print(" ".join(map(str, arr[si:ei + 1])))

def solve():
    scn = FastReader()
    testcases = 1
    for testcase in range(1, testcases + 1):
        n = scn.nextLong()
        a1 = scn.nextLong()
        a2 = scn.nextLong()
        a3 = scn.nextLong()
        b1 = scn.nextLong()
        b2 = scn.nextLong()
        b3 = scn.nextLong()

        min_value = 0
        if b1 >= a1 + a2:
            min_value = a3 - b2 - b3
        elif b2 >= a3 + a2:
            min_value = a1 - b1 - b3
        elif b3 >= a1 + a3:
            min_value = a2 - b2 - b1
        else:
            min_value = 0

        max_value = min(a1, b2) + min(a2, b3) + min(a3, b1)
        print(f"{min_value} {max_value}")

if __name__ == "__main__":
    solve()
