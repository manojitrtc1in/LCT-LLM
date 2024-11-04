import math
import sys
from collections import defaultdict
from typing import List, Tuple


class FastReader:
    def __init__(self):
        self.buffer = sys.stdin.readlines()
        self.pointer = 0

    def next(self) -> str:
        self.pointer += 1
        return self.buffer[self.pointer - 1].strip()

    def next_int(self) -> int:
        return int(self.next())

    def next_long(self) -> int:
        return int(self.next())

    def next_double(self) -> float:
        return float(self.next())

    def next_line(self) -> str:
        return self.next()


def count_digit(n: int) -> int:
    return int(math.floor(math.log10(n) + 1))


def sum_of_digits(n: int) -> int:
    if n < 0:
        return -1

    sum = 0

    while n > 0:
        sum += n % 10
        n //= 10

    return sum


def array_sum(arr: List[int], start: int, end: int) -> int:
    ans = 0

    for i in range(start, end + 1):
        ans += arr[i]

    return ans


def mod(x: int) -> int:
    if x < 0:
        return -1 * x
    else:
        return x


def swap_array(arr: List[int], start: int, end: int) -> None:
    while start < end:
        temp = arr[start]
        arr[start] = arr[end]
        arr[end] = temp
        start += 1
        end -= 1


def rotate(input: List[List[int]]) -> List[List[int]]:
    n = len(input)
    m = len(input[0])
    output = [[0] * n for _ in range(m)]

    for i in range(n):
        for j in range(m):
            output[j][n - 1 - i] = input[i][j]

    return output


def count_bits(n: int) -> int:
    count = 0

    while n != 0:
        count += 1
        n = n >> 1

    return count


def is_power_of_two(n: int) -> bool:
    if n == 0:
        return False

    return (n & (n - 1)) == 0


def min(a: int, b: int, c: int, d: int) -> int:
    arr = [a, b, c, d]
    arr.sort()
    return arr[0]


def max(a: int, b: int, c: int, d: int) -> int:
    arr = [a, b, c, d]
    arr.sort()
    return arr[3]


def reverse(input: str) -> str:
    return input[::-1]


def same_parity(a: int, b: int) -> bool:
    x = a % 2
    y = b % 2
    return x == y


def is_possible_triangle(a: int, b: int, c: int) -> bool:
    return a + b > c and c + b > a and a + c > b


def xnor(num1: int, num2: int) -> int:
    if num1 < num2:
        temp = num1
        num1 = num2
        num2 = temp

    num1 = toggle_bit(num1)
    return num1 ^ num2


def toggle_bit(n: int) -> int:
    if n == 0:
        return 1

    i = n
    n |= n >> 1
    n |= n >> 2
    n |= n >> 4
    n |= n >> 8
    n |= n >> 16
    return i ^ n


def xor_of_first_n(n: int) -> int:
    if n % 4 == 0:
        return n
    elif n % 4 == 1:
        return 1
    elif n % 4 == 2:
        return n + 1
    else:
        return 0


def gcd(a: int, b: int) -> int:
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def lcm(a: int, b: int, c: int, d: int) -> int:
    temp = lcm(a, b, c)
    return lcm(temp, d)


def lcm(a: int, b: int, c: int) -> int:
    temp = lcm(a, b)
    return lcm(temp, c)


def lcm(a: int, b: int) -> int:
    gc = gcd(a, b)
    return (a * b) // gc


def is_prime(n: int) -> bool:
    if n == 1:
        return False

    ans = True

    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            ans = False
            break

    return ans


def sieve_of_eratosthenes() -> None:
    sieve = 1000000
    prime = [False] * (sieve + 1)

    for i in range(4, sieve + 1, 2):
        prime[i] = True
        i += 1

    for p in range(3, int(math.sqrt(sieve)) + 1):
        if not prime[p]:
            for i in range(p * p, sieve + 1, p):
                prime[i] = True
            p += 1


def sort_d(arr: List[int], s: int, e: int) -> None:
    sort(arr, s, e)

    i = s
    j = e

    while i < j:
        temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp
        i += 1
        j -= 1


def sort_d(arr: List[int], s: int, e: int) -> None:
    sort(arr, s, e)

    i = s
    j = e

    while i < j:
        temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp
        i += 1
        j -= 1


def count_subarrays_sum_to_k(arr: List[int], sum: int) -> int:
    map = defaultdict(int)
    n = len(arr)
    prefix_sum = 0
    count = 0

    for i in range(n):
        prefix_sum += arr[i]

        if sum == prefix_sum:
            count += 1

        if prefix_sum - sum in map:
            count += map[prefix_sum - sum]

        map[prefix_sum] += 1

    return count


def kmp_algorithm(string: str, pattern: str) -> List[int]:
    list = []
    n = len(string)
    m = len(pattern)
    q = pattern + "#" + string
    lps = [0] * (n + m + 1)

    longest_prefix_suffix(lps, q, n + m + 1)

    for i in range(m + 1, n + m + 1):
        if lps[i] == m:
            list.append(i - 2 * m)

    return list


def longest_prefix_suffix(lps: List[int], string: str, n: int) -> None:
    lps[0] = 0

    for i in range(1, n):
        l = lps[i - 1]

        while l > 0 and string[i] != string[l]:
            l = lps[l - 1]

        if string[i] == string[l]:
            l += 1

        lps[i] = l


def generate_permutation(string: str, start: int, end: int) -> None:
    if start == end - 1:
        print(string)
    else:
        for i in range(start, end):
            string = swap_string(string, start, i)
            generate_permutation(string, start + 1, end)
            string = swap_string(string, start, i)


def swap_string(string: str, i: int, j: int) -> str:
    string_list = list(string)
    string_list[i], string_list[j] = string_list[j], string_list[i]
    return "".join(string_list)


def euler_totient_function(arr: List[int], n: int) -> None:
    for i in range(1, n + 1):
        arr[i] = i

    for i in range(2, n + 1):
        if arr[i] == i:
            arr[i] = i - 1

            for j in range(2 * i, n + 1, i):
                arr[j] = (arr[j] * (i - 1)) // i


def ncr(n: int, k: int) -> int:
    ans = 1

    k = min(k, n - k)

    for j in range(1, k + 1):
        if n % j == 0:
            ans *= n // j
        elif ans % j == 0:
            ans = ans // j * n
        else:
            ans = (ans * n) // j

    return ans


def all_factors(n: int) -> List[int]:
    list = []

    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            if i * i == n:
                list.append(i)
            else:
                list.append(i)
                list.append(n // i)

    return list


def all_factors(n: int) -> List[int]:
    list = []

    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            if i * i == n:
                list.append(i)
            else:
                list.append(i)
                list.append(n // i)

    return list


def get_factorization(x: int) -> List[int]:
    ret = []

    while x != 1:
        ret.append(spf[x])
        x = x // spf[x]

    return ret


def sieve() -> None:
    spf[1] = 1

    for i in range(2, MAXN):
        spf[i] = i

    for i in range(4, MAXN, 2):
        spf[i] = 2
        i += 1

    for p in range(3, int(math.sqrt(MAXN)) + 1):
        if spf[p] == p:
            for i in range(p * p, MAXN, p):
                if spf[i] == i:
                    spf[i] = p
                i += 1


def merge(arr: List[int], l: int, m: int, r: int) -> None:
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


def sort(arr: List[int], l: int, r: int) -> None:
    if l < r:
        m = (l + r) // 2
        sort(arr, l, m)
        sort(arr, m + 1, r)
        merge(arr, l, m, r)


def merge(arr: List[int], l: int, m: int, r: int) -> None:
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


def binary_search_greater(arr: List[int], start: int, end: int, val: int) -> int:
    if start > end:
        return 0

    mid = (start + end) // 2

    if arr[mid] <= val:
        return binary_search_greater(arr, mid + 1, end, val)
    else:
        return binary_search_greater(arr, start, mid - 1, val) + end - mid + 1


def solve() -> None:
    scn = FastReader()

    list = []
    listl = []
    lista = []
    listb = []

    map = defaultdict(int)

    map1 = defaultdict(int)
    map2 = defaultdict(int)

    set = set()

    setx = set()
    sety = set()

    sb = ""

    testcases = 1

    for testcase in range(1, testcases + 1):
        n = scn.next_long()
        x = n

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

        sb = ""
        list.clear()
        listb.clear()
        map.clear()
        map1.clear()
        map2.clear()
        set.clear()
        sety.clear()


solve()
