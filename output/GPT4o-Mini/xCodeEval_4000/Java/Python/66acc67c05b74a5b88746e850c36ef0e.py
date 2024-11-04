import sys
from collections import deque

class Solution:
    def __init__(self):
        self.count = 0
        self.mod = 1000000007
        self.ts = [set() for _ in range(200000)]
        self.visited = []
        self.par = []
        self.adj = []

    def dfs(self, start, root):
        self.visited[start] = True
        self.par[start] = root
        for i in self.adj[start]:
            if not self.visited[i]:
                self.dfs(i, start)

    def soln(self):
        a = self.next_int()
        b = self.next_int()
        x = self.next_int()
        y = self.next_int()
        z = self.next_int()
        ans = 0

        if a < 2 * x:
            ans += 2 * x - a
            a = 0
        else:
            a -= 2 * x

        if b < 3 * z:
            ans += 3 * z - b
            b = 0
        else:
            b -= 3 * z

        if a < b:
            y = max(y - a, 0)
            b -= a
            a = 0
        else:
            y = max(y - b, 0)
            b = a - b
            a = 0

        if y > b:
            ans += b + 2 * (y - b)
        else:
            ans += y

        print(ans)

    def bfs_pair(self, arr, visited, x1, y1, x2, y2):
        q = deque()
        visited[x1][y1] = True
        level = 1
        increamenter = 0

        if x1 - 1 >= 0 and arr[x1 - 1][y1] == 1:
            increamenter += 1
        if y1 - 1 >= 0 and arr[x1][y1 - 1] == 1:
            increamenter += 1
        if y1 + 1 < len(arr[1]) and arr[x1][y1 + 1] == 1:
            increamenter += 1
        if x1 + 1 < len(arr) and arr[x1 + 1][y1] == 1:
            increamenter += 1

        q.append((x1, y1))
        i = 0
        while q:
            p = q.popleft()
            x, y = p

            if x - 1 >= 0 and y >= 0 and x - 1 < len(arr) and y < len(arr[1]):
                if not visited[x - 1][y] and arr[x - 1][y] == 1:
                    q.append((x - 1, y))
                visited[x - 1][y] = True
            if x >= 0 and y - 1 >= 0 and x < len(arr) and y - 1 < len(arr[1]):
                if not visited[x][y - 1] and arr[x][y - 1] == 1:
                    q.append((x, y - 1))
                visited[x][y - 1] = True
            if x >= 0 and y + 1 >= 0 and x < len(arr) and y + 1 < len(arr[1]):
                if not visited[x][y + 1] and arr[x][y + 1] == 1:
                    q.append((x, y + 1))
                visited[x][y + 1] = True
            if x + 1 >= 0 and y >= 0 and x + 1 < len(arr) and y < len(arr[1]):
                if not visited[x + 1][y] and arr[x + 1][y] == 1:
                    q.append((x + 1, y))
                visited[x + 1][y] = True

            if x == x2 and y == y2:
                return level

            if increamenter == 0:
                level += 1
                increamenter = len(q)

            increamenter -= 1

        return -1

    def bfs(self, gp, s, visited, dist):
        qu = deque()
        level = 1
        increamenter = len(gp[s]) + 1 if gp[s] is not None else 0
        visited[s] = True
        qu.append(s)

        while qu:
            temp = qu.popleft()
            increamenter -= 1
            dist[temp] = level * 6

            for neighbor in gp[temp]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    qu.append(neighbor)

            if increamenter == 0:
                level += 1
                increamenter = len(qu)

    def max_sub_array_sum(self, a):
        size = len(a)
        max_so_far = float('-inf')
        max_ending_here = 0

        for i in range(size):
            max_ending_here += a[i]
            if max_so_far < max_ending_here:
                max_so_far = max_ending_here
            if max_ending_here < 0:
                max_ending_here = 0

        return max_so_far

    def all_prime(self, n):
        arr = [2]
        for i in range(3, n, 2):
            flag = 0
            for j in arr:
                if i % j == 0:
                    flag = 1
                    break
            if flag == 0:
                arr.append(i)
        return arr

    def fact(self, n):
        ans = 1
        for i in range(1, n + 1):
            ans = (ans * i) % self.mod
        return ans

    class Pair:
        def __init__(self, idx, val):
            self.idx = idx
            self.val = val

        def __lt__(self, other):
            if other.val < self.val:
                return True
            if other.val == self.val:
                return False
            return False

        def __str__(self):
            return f"idx: {self.idx} val: {self.val}"

    def gcd(self, x, y):
        if x % y == 0:
            return y
        else:
            return self.gcd(y, x % y)

    def binary_search(self, a, low, high, target):
        if low > high:
            return -1
        mid = low + (high - low) // 2
        if a[mid] == target:
            return mid
        if a[mid] > target:
            high = mid - 1
        if a[mid] < target:
            low = mid + 1
        return self.binary_search(a, low, high, target)

    def reverse_string(self, s):
        return s[::-1]

    def pow(self, n, p, m=None):
        result = 1
        if p == 0:
            return 1
        if p == 1:
            return n
        while p != 0:
            if p % 2 == 1:
                result *= n
                if m is not None and result >= m:
                    result %= m
            p >>= 1
            n *= n
            if m is not None and n >= m:
                n %= m
        return result

    def pow_simple(self, n, p):
        result = 1
        if p == 0:
            return 1
        if p == 1:
            return n
        while p != 0:
            if p % 2 == 1:
                result *= n
            p >>= 1
            n *= n
        return result

    def radix_sort(self, f):
        to = [0] * len(f)
        b = [0] * 65537
        for i in f:
            b[1 + (i & 0xffff)] += 1
        for i in range(1, 65537):
            b[i] += b[i - 1]
        for i in f:
            to[b[i & 0xffff]] = i
            b[i & 0xffff] += 1
        f, to = to, f

        b = [0] * 65537
        for i in f:
            b[1 + (i >> 16)] += 1
        for i in range(1, 65537):
            b[i] += b[i - 1]
        for i in f:
            to[b[i >> 16]] = i
            b[i >> 16] += 1
        return f

    def next_power_of_2(self, a):
        b = 1
        while b < a:
            b <<= 1
        return b

    def point_in_triangle(self, p1, p2, p3, p4, p5, p6, p7, p8):
        s = p2 * p5 - p1 * p6 + (p6 - p2) * p7 + (p1 - p5) * p8
        t = p1 * p4 - p2 * p3 + (p2 - p4) * p7 + (p3 - p1) * p8

        if (s < 0) != (t < 0):
            return False

        A = -p4 * p5 + p2 * (p5 - p3) + p1 * (p4 - p6) + p3 * p6
        if A < 0:
            s = -s
            t = -t
            A = -A
        return s > 0 and t > 0 and (s + t) <= A

    def area(self, x1, y1, x2, y2, x3, y3):
        return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0)

    def is_prime(self, n):
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

    def sort(self, a):
        n = len(a)
        b = [0] * n
        return self.merge_sort(a, b, 0, n - 1)

    def merge_sort(self, a, b, left, right):
        c = 0
        if left < right:
            mid = left + (right - left) // 2
            c += self.merge_sort(a, b, left, mid)
            c += self.merge_sort(a, b, mid + 1, right)
            c += self.merge(a, b, left, mid + 1, right)
        return c

    def merge(self, a, b, left, mid, right):
        c = 0
        i = left
        j = mid
        k = left
        while i <= mid - 1 and j <= right:
            if a[i] > a[j]:
                b[k] = a[i]
                i += 1
            else:
                b[k] = a[j]
                c += mid - i
                j += 1
            k += 1
        while i <= mid - 1:
            b[k] = a[i]
            k += 1
            i += 1
        while j <= right:
            b[k] = a[j]
            k += 1
            j += 1
        for i in range(left, right + 1):
            a[i] = b[i]
        return c

    def input_reader(self):
        self.stream = sys.stdin

    def is_whitespace(self, c):
        return c in (' ', '\n', '\r', '\t', -1)

    def is_end_of_line(self, c):
        return c in ('\n', '\r', -1)

    def read(self):
        if self.num_chars == -1:
            raise ValueError("InputMismatchException")
        if self.cur_char >= self.num_chars:
            self.cur_char = 0
            try:
                self.num_chars = self.stream.read(self.buf)
            except Exception:
                raise ValueError("InputMismatchException")
            if self.num_chars <= 0:
                return -1
        return self.buf[self.cur_char]

    def next_int(self):
        c = self.read()
        while self.is_space_char(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while True:
            if c < '0' or c > '9':
                raise ValueError("InputMismatchException")
            res = res * 10 + (ord(c) - ord('0'))
            c = self.read()
            if self.is_space_char(c):
                break
        return res * sgn

    def next_long(self):
        c = self.read()
        while self.is_space_char(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while True:
            if c < '0' or c > '9':
                raise ValueError("InputMismatchException")
            res = res * 10 + (ord(c) - ord('0'))
            c = self.read()
            if self.is_space_char(c):
                break
        return res * sgn

    def next_token(self):
        c = self.read()
        while self.is_space_char(c):
            c = self.read()
        res = []
        while True:
            res.append(chr(c))
            c = self.read()
            if self.is_space_char(c):
                break
        return ''.join(res)

    def next_line(self):
        c = self.read()
        while self.is_space_char(c):
            c = self.read()
        res = []
        while True:
            res.append(chr(c))
            c = self.read()
            if self.is_end_of_line(c):
                break
        return ''.join(res)

    def next_int_array(self, n):
        return [self.next_int() for _ in range(n)]

    def next_2d_array(self, n, m):
        return [[self.next_int() for _ in range(m)] for _ in range(n)]

    def next_long_array(self, n):
        return [self.next_long() for _ in range(n)]

    def p_array(self, arr):
        print(" ".join(map(str, arr)))

    def is_space_char(self, c):
        return self.is_whitespace(c)

if __name__ == "__main__":
    solution = Solution()
    solution.input_reader()
    solution.soln()
