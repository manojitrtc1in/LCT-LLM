import math

def countDigit(n):
    return int(math.log10(n) + 1)

def sumOfDigits(n):
    if n < 0:
        return -1
    sum = 0
    while n > 0:
        sum = sum + (n % 10)
        n //= 10
    return sum

def arraySum(arr, start, end):
    ans = 0
    for i in range(start, end+1):
        ans += arr[i]
    return ans

def mod(x):
    if x < 0:
        return -1 * x
    else:
        return x

def swapArray(arr, start, end):
    while start < end:
        temp = arr[start]
        arr[start] = arr[end]
        arr[end] = temp
        start += 1
        end -= 1

def rotate(input):
    n = len(input)
    m = len(input[0])
    output = [[0 for j in range(n)] for i in range(m)]
    for i in range(n):
        for j in range(m):
            output[j][n-1-i] = input[i][j]
    return output

def countBits(n):
    count = 0
    while n != 0:
        count += 1
        n = n >> 1
    return count

def isPowerOfTwo(n):
    if n == 0:
        return False
    return (n & (n-1)) == 0

def min(a, b, c, d):
    arr = [a, b, c, d]
    arr.sort()
    return arr[0]

def max(a, b, c, d):
    arr = [a, b, c, d]
    arr.sort()
    return arr[3]

def reverse(input):
    return input[::-1]

def sameParity(a, b):
    x = a % 2
    y = b % 2
    return x == y

def isPossibleTriangle(a, b, c):
    return a + b > c and c + b > a and a + c > b

def xnor(num1, num2):
    if num1 < num2:
        temp = num1
        num1 = num2
        num2 = temp
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
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def lcm(a, b, c, d):
    temp = lcm(a, b, c)
    return lcm(temp, d)

def lcm(a, b, c):
    temp = lcm(a, b)
    return lcm(temp, c)

def lcm(a, b):
    gc = gcd(a, b)
    return (a * b) // gc

def isPrime(n):
    if n == 1:
        return False
    ans = True
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            ans = False
            break
    return ans

def sieveOfEratosthenes():
    sieve = 1000000
    prime = [False] * (sieve + 1)
    for i in range(4, sieve + 1, 2):
        prime[i] = True
        i += 1
    for p in range(3, int(math.sqrt(sieve)) + 1):
        if prime[p] == False:
            for i in range(p * p, sieve + 1, p):
                prime[i] = True
            p += 1
    return prime

def sortD(arr, s, e):
    sort(arr, s, e)
    i = s
    j = e
    while i < j:
        temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp
        i += 1
        j -= 1
    return

def countSubarraysSumToK(arr, sum):
    map = {}
    n = len(arr)
    prefixsum = 0
    count = 0
    for i in range(n):
        prefixsum += arr[i]
        if sum == prefixsum:
            count += 1
        if prefixsum - sum in map:
            count += map[prefixsum - sum]
        if prefixsum in map:
            map[prefixsum] += 1
        else:
            map[prefixsum] = 1
    return count

def kmpAlgorithm(str, pat):
    list = []
    n = len(str)
    m = len(pat)
    q = pat + "#" + str
    lps = [0] * (n + m + 1)
    longestPefixSuffix(lps, q, n + m + 1)
    for i in range(m + 1, n + m + 1):
        if lps[i] == m:
            list.append(i - 2 * m)
    return list

def longestPefixSuffix(lps, str, n):
    lps[0] = 0
    for i in range(1, n):
        l = lps[i-1]
        while l > 0 and str[i] != str[l]:
            l = lps[l-1]
        if str[i] == str[l]:
            l += 1
        lps[i] = l

def eulerTotientFunction(arr, n):
    for i in range(1, n+1):
        arr[i] = i
    for i in range(2, n+1):
        if arr[i] == i:
            arr[i] = i - 1
            for j in range(2*i, n+1, i):
                arr[j] = (arr[j] * (i - 1)) // i
    return

def nCr(n, k):
    ans = 1
    k = min(k, n-k)
    j = 1
    for i in range(j, k+1):
        if n % i == 0:
            ans *= n // i
        elif ans % i == 0:
            ans = (ans // i) * n
        else:
            ans = (ans * n) // i
    return ans

def allFactors(n):
    list = []
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            if i * i == n:
                list.append(i)
            else:
                list.append(i)
                list.append(n // i)
    return list

def sieve():
    sieve = 1000000
    prime = [False] * (sieve + 1)
    for i in range(4, sieve + 1, 2):
        prime[i] = True
        i += 1
    for p in range(3, int(math.sqrt(sieve)) + 1):
        if prime[p] == False:
            for i in range(p * p, sieve + 1, p):
                prime[i] = True
            p += 1
    return prime

def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m
    L = [0] * n1
    R = [0] * n2
    for i in range(n1):
        L[i] = arr[l + i]
    for j in range(n2):
        R[j] = arr[m + 1 + j]
    i = 0
    j = 0
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
        if dp[i-1] > 0:
            dp[i] = dp[i-1] + arr[i]
        else:
            dp[i] = arr[i]
        if dp[i] > max:
            max = dp[i]
    return max

def binarySerachGreater(arr, start, end, val):
    if start > end:
        return 0
    mid = (start + end) // 2
    if arr[mid] <= val:
        return binarySerachGreater(arr, mid + 1, end, val)
    else:
        return binarySerachGreater(arr, start, mid - 1, val) + end - mid + 1

def swapString(a, i, j):
    b = list(a)
    b[i], b[j] = b[j], b[i]
    return ''.join(b)

def generatePermutation(string, start, end):
    if start == end - 1:
        print(string)
    else:
        for i in range(start, end):
            string = swapString(string, start, i)
            generatePermutation(string, start + 1, end)
            string = swapString(string, start, i)

def factMod(n, mod):
    if n <= 1:
        return 1
    ans = 1
    for i in range(1, n+1):
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
            ans = ans * x
        n //= 2
        x = x * x
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
    for i in range(si, ei+1):
        print(arr[i], end=" ")
    print()

def printLArray(arr, si, ei):
    for i in range(si, ei+1):
        print(arr[i], end=" ")
    print()

def printtwodArray(ans):
    for i in range(len(ans)):
        for j in range(len(ans[0])):
            print(ans[i][j], end=" ")
        print()

def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m
    L = [0] * n1
    R = [0] * n2
    for i in range(n1):
        L[i] = arr[l + i]
    for j in range(n2):
        R[j] = arr[m + 1 + j]
    i = 0
    j = 0
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

def mergeSort(arr, l, r):
    if l < r:
        m = (l + r) // 2
        mergeSort(arr, l, m)
        mergeSort(arr, m + 1, r)
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
        if dp[i-1] > 0:
            dp[i] = dp[i-1] + arr[i]
        else:
            dp[i] = arr[i]
        if dp[i] > max:
            max = dp[i]
    return max

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

def dfs(sv, vis):
    vis[sv] = True
    for x in tree[sv]:
        if not vis[x]:
            dfs(x, vis)

def solve():
    n = int(input())
    x = n
    list = []
    for i in range(2, int(math.sqrt(n)) + 1):
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

testcases = 1
for testcase in range(1, testcases + 1):
    solve()
