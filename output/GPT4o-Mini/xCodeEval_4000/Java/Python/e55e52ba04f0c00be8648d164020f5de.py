import sys
from collections import defaultdict
from math import log10, gcd

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
    return int(log10(n) + 1)

def sumOfDigits(n):
    if n < 0:
        return -1
    total = 0
    while n > 0:
        total += n % 10
        n //= 10
    return total

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
    return min(a, b, c, d)

def max(a, b, c, d):
    return max(a, b, c, d)

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

def sortD(arr, s, e):
    arr[s:e + 1] = sorted(arr[s:e + 1], reverse=True)

def countSubarraysSumToK(arr, sum):
    map = defaultdict(int)
    n = len(arr)
    prefixsum = 0
    count = 0
    for i in range(n):
        prefixsum += arr[i]
        if sum == prefixsum:
            count += 1
        count += map[prefixsum - sum]
        map[prefixsum] += 1
    return count

def kmpAlgorithm(str, pat):
    list = []
    n = len(str)
    m = len(pat)
    q = pat + "#" + str
    lps = [0] * (n + m + 1)
    longestPrefixSuffix(lps, q, n + m + 1)
    for i in range(m + 1, n + m + 1):
        if lps[i] == m:
            list.append(i - 2 * m)
    return list

def longestPrefixSuffix(lps, str, n):
    lps[0] = 0
    for i in range(1, n):
        l = lps[i - 1]
        while l > 0 and str[i] != str[l]:
            l = lps[l - 1]
        if str[i] == str[l]:
            l += 1
        lps[i] = l

def eulerTotientFunction(arr, n):
    for i in range(1, n + 1):
        arr[i] = i
    for i in range(2, n + 1):
        if arr[i] == i:
            arr[i] = i - 1
            for j in range(2 * i, n + 1, i):
                arr[j] = (arr[j] * (i - 1)) // i

def nCr(n, k):
    ans = 1
    k = k if k < n - k else n - k
    for j in range(1, k + 1):
        if n % j == 0:
            ans *= n // j
        else:
            ans = (ans * n) // j
        n -= 1
    return ans

def allFactors(n):
    list = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            list.append(i)
            if i * i != n:
                list.append(n // i)
    return list

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
    max = dp[0]
    for i in range(1, len(arr)):
        dp[i] = dp[i - 1] + arr[i] if dp[i - 1] > 0 else arr[i]
        max = max if dp[i] <= max else dp[i]
    return max

def binarySearchGreater(arr, start, end, val):
    if start > end:
        return 0
    mid = (start + end) // 2
    if arr[mid] <= val:
        return binarySearchGreater(arr, mid + 1, end, val)
    else:
        return binarySearchGreater(arr, start, mid - 1, val) + end - mid + 1

def swapString(a, i, j):
    b = list(a)
    b[i], b[j] = b[j], b[i]
    return ''.join(b)

def generatePermutation(str, start, end):
    if start == end - 1:
        print(str)
    else:
        for i in range(start, end):
            str = swapString(str, start, i)
            generatePermutation(str, start + 1, end)
            str = swapString(str, start, i)

def factMod(n, mod):
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

def powerMod(x, n, mod):
    if n == 0:
        return 1
    if n == 1:
        return x
    ans = 1
    while n > 0:
        if n % 2 == 1:
            ans = (ans * x) % mod
        x = (x * x) % mod
        n //= 2
    return ans

def lowerBound(arr, k):
    ans = -1
    start = 0
    end = len(arr) - 1
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
    start = 0
    end = len(arr) - 1
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

def printArrayln(arr, si, ei):
    print(" ".join(map(str, arr[si:ei + 1])))

def printLArray(arr, si, ei):
    print(" ".join(map(str, arr[si:ei + 1])))

def printLArrayln(arr, si, ei):
    print(" ".join(map(str, arr[si:ei + 1])))

def printtwodArray(ans):
    for row in ans:
        print(" ".join(map(str, row)))

def modPow(a, x, p):
    res = 1
    while x > 0:
        if x % 2 != 0:
            res = (res * a) % p
        a = (a * a) % p
        x //= 2
    return res

def modInverse(a, p):
    return modPow(a, p - 2, p)

def modBinomial(n, k, p):
    numerator = 1
    for i in range(k):
        numerator = (numerator * (n - i)) % p
    denominator = 1
    for i in range(1, k + 1):
        denominator = (denominator * i) % p
    return (numerator * modInverse(denominator, p)) % p

def countNoOfNodesInsubtree(child, par, dp):
    count = 1
    for x in tree[child]:
        if x == par:
            continue
        count += countNoOfNodesInsubtree(x, child, dp)
    dp[child] = count

def depth(child, par, dp, d):
    dp[child] = d
    for x in tree[child]:
        if x == par:
            continue
        depth(x, child, dp, d + 1)

def dfs(sv, vis):
    vis[sv] = True
    for x in tree[sv]:
        if not vis[x]:
            dfs(x, vis)

def solve():
    scn = FastReader()
    testcases = 1
    for testcase in range(1, testcases + 1):
        n = scn.nextLong()
        x = n
        list = []
        for i in range(2, int(n**0.5) + 1):
            if x % i == 0:
                while x % i == 0:
                    list.append(i)
                    x //= i
        if x > 1:
            list.append(x)
        if n == 1:
            print(1)
            print(0)
        elif len(list) == 2:
            print(2)
        else:
            print(1)
            if len(list) == 1:
                print(0)
            else:
                ans = list[0] * list[1]
                print(ans)

if __name__ == "__main__":
    solve()
