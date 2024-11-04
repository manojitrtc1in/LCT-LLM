import sys
from collections import deque

class Solution:
    def __init__(self):
        self.stream = sys.stdin
        self.buf = bytearray()
        self.curChar = 0
        self.numChars = 0
        self.pw = sys.stdout
        self.count = 0
        self.mod = 1000000007
        self.ts = [set() for _ in range(200000)]
    
    def main(self):
        self.soln()
    
    def soln(self):
        a, b, x, y, z = map(int, input().split())
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
            y = y - a if y - a > 0 else 0
            b -= a
            a = 0
        else:
            y = y - b if y - b > 0 else 0
            b = a - b
            a = 0
        if y > b:
            ans += b + 2 * (y - b)
        else:
            ans += y
        print(ans)
    
    def bfs(self, gp, s, visited, dist):
        qu = deque()
        level = 1
        id4 = len(gp[s]) + 1 if gp[s] else 0
        visited[s] = True
        qu.append(s)
        while qu:
            temp = qu.popleft()
            id4 -= 1
            dist[temp] = level * 6
            for i in range(len(gp[temp])):
                if not visited[gp[temp][i]]:
                    visited[gp[temp][i]] = True
                    qu.append(gp[temp][i])
            if id4 == 0:
                level += 1
                id4 = len(qu)
    
    def id1(self, a):
        size = len(a)
        id5 = float('-inf')
        id3 = 0
        for i in range(size):
            id3 += a[i]
            if id5 < id3:
                id5 = id3
            if id3 < 0:
                id3 = 0
        return id5
    
    def allprime(self, n):
        arr = [2]
        for i in range(3, n, 2):
            flag = 0
            for j in range(len(arr)):
                if i % arr[j] == 0:
                    flag = 1
                    break
            if flag == 0:
                arr.append(i)
        return arr
    
    def fact(self, n):
        ans = 1
        for i in range(1, n+1):
            ans = (ans * i) % 1000000007
        return ans
    
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
    
    def pow(self, n, p, m):
        result = 1
        if p == 0:
            return 1
        if p == 1:
            return n
        while p != 0:
            if p % 2 == 1:
                result *= n
            if result >= m:
                result %= m
            p >>= 1
            n *= n
            if n >= m:
                n %= m
        return result
    
    def pow(self, n, p):
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
    
    def id11(self, f):
        to = [0] * len(f)
        b = [0] * 65537
        for i in range(len(f)):
            b[1 + (f[i] & 0xffff)] += 1
        for i in range(1, 65536):
            b[i] += b[i - 1]
        for i in range(len(f)):
            to[b[f[i] & 0xffff]] = f[i]
            b[f[i] & 0xffff] += 1
        d = f
        f = to
        to = d
        b = [0] * 65537
        for i in range(len(f)):
            b[1 + (f[i] >> 16)] += 1
        for i in range(1, 65536):
            b[i] += b[i - 1]
        for i in range(len(f)):
            to[b[f[i] >> 16]] = f[i]
            b[f[i] >> 16] += 1
        d = f
        f = to
        to = d
        return f
    
    def id13(self, a):
        b = 1
        while b < a:
            b = b << 1
        return b
    
    def id9(self, p1, p2, p3, p4, p5, p6, p7, p8):
        s = p2 * p5 - p1 * p6 + (p6 - p2) * p7 + (p1 - p5) * p8
        t = p1 * p4 - p2 * p3 + (p2 - p4) * p7 + (p3 - p1) * p8
        if (s < 0) != (t < 0):
            return False
        A = -p4 * p5 + p2 * (p5 - p3) + p1 * (p4 - p6) + p3 * p6
        if A < 0.0:
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
        i = 5
        while i * i <= n:
            if n % i == 0 or n % (i + 2) == 0:
                return False
            i += 6
        return True
    
    def input_reader(self):
        self.stream = sys.stdin
    
    def is_whitespace(self, c):
        return c == ' ' or c == '\n' or c == '\r' or c == '\t' or c == -1
    
    def id7(self, c):
        return c == '\n' or c == '\r' or c == -1
    
    def read(self):
        if self.numChars == -1:
            raise Exception("InputMismatchException")
        if self.curChar >= self.numChars:
            self.curChar = 0
            self.numChars = self.stream.readinto(self.buf)
            if self.numChars <= 0:
                return -1
        return self.buf[self.curChar]
    
    def next_int(self):
        c = self.read()
        while self.id2(c):
            c = self.read()
        sgn = 1
        if c == ord('-'):
            sgn = -1
            c = self.read()
        res = 0
        while not self.id2(c):
            if c < ord('0') or c > ord('9'):
                raise Exception("InputMismatchException")
            res = res * 10 + c - ord('0')
            c = self.read()
        return res * sgn
    
    def next_long(self):
        c = self.read()
        while self.id2(c):
            c = self.read()
        sgn = 1
        if c == ord('-'):
            sgn = -1
            c = self.read()
        res = 0
        while not self.id2(c):
            if c < ord('0') or c > ord('9'):
                raise Exception("InputMismatchException")
            res = res * 10 + c - ord('0')
            c = self.read()
        return res * sgn
    
    def next_token(self):
        c = self.read()
        while self.id2(c):
            c = self.read()
        res = bytearray()
        while not self.id2(c):
            res.append(c)
            c = self.read()
        return res.decode()
    
    def next_line(self):
        c = self.read()
        while self.id2(c):
            c = self.read()
        res = bytearray()
        while not self.id7(c):
            res.append(c)
            c = self.read()
        return res.decode()
    
    def id6(self, n):
        arr = [0] * n
        for i in range(n):
            arr[i] = self.next_int()
        return arr
    
    def id8(self, n, m):
        arr = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                arr[i][j] = self.next_int()
        return arr
    
    def id12(self, n):
        arr = [0] * n
        for i in range(n):
            arr[i] = self.next_long()
        return arr
    
    def p_array(self, arr):
        for i in range(len(arr)):
            self.pw.write(str(arr[i]) + " ")
        self.pw.write("\n")
    
    def id10(self, c):
        return self.is_whitespace(c)
    
sol = Solution()
sol.main()
