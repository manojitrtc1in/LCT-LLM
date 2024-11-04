import sys
from collections import deque

class Solution:
    def __init__(self):
        self.adj = None
        self.visited = None
        self.par = None

    def main(self):
        self.InputReader(sys.stdin)
        self.soln()

    def dfs(self, start, root):
        self.visited[start] = True
        self.par[start] = root
        for i in self.adj[start]:
            if not self.visited[i]:
                self.dfs(i, start)

    def soln(self):
        a, b, x, y, z = map(int, input().split())
        ans = 0
        if a < 2 * x:
            ans += 2 * x - a
            a = 0
        else:
            a = a - 2 * x
        if b < 3 * z:
            ans += 3 * z - b
            b = 0
        else:
            b = b - 3 * z
        if a < b:
            y = y - a if y - a > 0 else 0
            b = b - a
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

    def bfsPair(self, arr, visited, x1, y1, x2, y2):
        q = deque()
        visited[x1][y1] = True
        level = 1
        increamenter = 0
        if x1 - 1 >= 0:
            if arr[x1 - 1][y1] == 1:
                increamenter += 1
        if y1 - 1 >= 0:
            if arr[x1][y1 - 1] == 1:
                increamenter += 1
        if y1 + 1 < len(arr[1]):
            if arr[x1][y1 + 1] == 1:
                increamenter += 1
        if x1 + 1 < len(arr):
            if arr[x1 + 1][y1] == 1:
                increamenter += 1
        q.append((x1, y1))
        while q:
            x, y = q.popleft()
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
        increamenter = 0
        if gp[s] is not None:
            increamenter = len(gp[s]) + 1
        else:
            return
        visited[s] = True
        qu.append(s)
        while qu:
            temp = qu.popleft()
            increamenter -= 1
            dist[temp] = level * 6
            for i in range(len(gp[temp])):
                if not visited[gp[temp][i]]:
                    visited[gp[temp][i]] = True
                    qu.append(gp[temp][i])
            if increamenter == 0:
                level += 1
                increamenter = len(qu)

    def maxSubArraySum(self, a):
        size = len(a)
        max_so_far = float('-inf')
        max_ending_here = 0
        for i in range(size):
            max_ending_here = max_ending_here + a[i]
            if max_so_far < max_ending_here:
                max_so_far = max_ending_here
            if max_ending_here < 0:
                max_ending_here = 0
        return max_so_far

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
        for i in range(1, n + 1):
            ans = (ans * i) % 1000000007
        return ans

    def gcd(self, x, y):
        if x % y == 0:
            return y
        else:
            return self.gcd(y, x % y)

    def BinarySearch(self, a, low, high, target):
        if low > high:
            return -1
        mid = low + (high - low) // 2
        if a[mid] == target:
            return mid
        if a[mid] > target:
            high = mid - 1
        if a[mid] < target:
            low = mid + 1
        return self.BinarySearch(a, low, high, target)

    def reverseString(self, s):
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

    def nextPowerOf2(self, a):
        b = 1
        while b < a:
            b = b << 1
        return b

    def PointInTriangle(self, p1, p2, p3, p4, p5, p6, p7, p8):
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

    def isPrime(self, n):
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

    def sort(self, a):
        n = len(a)
        b = [0] * n
        return self.mergeSort(a, b, 0, n - 1)

    def mergeSort(self, a, b, left, right):
        c = 0
        if left < right:
            mid = left + (right - left) // 2
            c = self.mergeSort(a, b, left, mid)
            c += self.mergeSort(a, b, mid + 1, right)
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
                j += 1
                c += mid - i
            k += 1
        while i <= mid - 1:
            b[k] = a[i]
            i += 1
            k += 1
        while j <= right:
            b[k] = a[j]
            j += 1
            k += 1
        for i in range(left, right + 1):
            a[i] = b[i]
        return c

    def InputReader(self, stream1):
        self.stream = stream1

    def isWhitespace(self, c):
        return c == ' ' or c == '\n' or c == '\r' or c == '\t' or c == -1

    def isEndOfLine(self, c):
        return c == '\n' or c == '\r' or c == -1

    def read(self):
        if self.numChars == -1:
            raise Exception("InputMismatchException")
        if self.curChar >= self.numChars:
            self.curChar = 0
            self.numChars = self.stream.read(self.buf)
            if self.numChars <= 0:
                return -1
        return self.buf[self.curChar]

    def nextInt(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < '0' or c > '9':
                raise Exception("InputMismatchException")
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def nextLong(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < '0' or c > '9':
                raise Exception("InputMismatchException")
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def nextToken(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = []
        while not self.isSpaceChar(c):
            res.append(c)
            c = self.read()
        return "".join(res)

    def nextLine(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = []
        while not self.isEndOfLine(c):
            res.append(c)
            c = self.read()
        return "".join(res)

    def nextIntArray(self, n):
        arr = [0] * n
        for i in range(n):
            arr[i] = self.nextInt()
        return arr

    def next2dArray(self, n, m):
        arr = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                arr[i][j] = self.nextInt()
        return arr

    def pArray(self, arr):
        for i in range(len(arr)):
            print(arr[i], end=" ")
        print()

    def isSpaceChar(self, c):
        if self.filter is not None:
            return self.filter.isSpaceChar(c)
        return self.isWhitespace(c)

    def nextPowerOf2(self, a):
        b = 1
        while b < a:
            b = b << 1
        return b

    def PointInTriangle(self, p1, p2, p3, p4, p5, p6, p7, p8):
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

    def isPrime(self, n):
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

    def sort(self, a):
        n = len(a)
        b = [0] * n
        return self.mergeSort(a, b, 0, n - 1)

    def mergeSort(self, a, b, left, right):
        c = 0
        if left < right:
            mid = left + (right - left) // 2
            c = self.mergeSort(a, b, left, mid)
            c += self.mergeSort(a, b, mid + 1, right)
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
                j += 1
                c += mid - i
            k += 1
        while i <= mid - 1:
            b[k] = a[i]
            i += 1
            k += 1
        while j <= right:
            b[k] = a[j]
            j += 1
            k += 1
        for i in range(left, right + 1):
            a[i] = b[i]
        return c

    def InputReader(self, stream1):
        self.stream = stream1

    def isWhitespace(self, c):
        return c == ' ' or c == '\n' or c == '\r' or c == '\t' or c == -1

    def isEndOfLine(self, c):
        return c == '\n' or c == '\r' or c == -1

    def read(self):
        if self.numChars == -1:
            raise Exception("InputMismatchException")
        if self.curChar >= self.numChars:
            self.curChar = 0
            self.numChars = self.stream.read(self.buf)
            if self.numChars <= 0:
                return -1
        return self.buf[self.curChar]

    def nextInt(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < '0' or c > '9':
                raise Exception("InputMismatchException")
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def nextLong(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < '0' or c > '9':
                raise Exception("InputMismatchException")
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def nextToken(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = []
        while not self.isSpaceChar(c):
            res.append(c)
            c = self.read()
        return "".join(res)

    def nextLine(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = []
        while not self.isEndOfLine(c):
            res.append(c)
            c = self.read()
        return "".join(res)

    def nextIntArray(self, n):
        arr = [0] * n
        for i in range(n):
            arr[i] = self.nextInt()
        return arr

    def next2dArray(self, n, m):
        arr = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                arr[i][j] = self.nextInt()
        return arr

    def pArray(self, arr):
        for i in range(len(arr)):
            print(arr[i], end=" ")
        print()

    def isSpaceChar(self, c):
        if self.filter is not None:
            return self.filter.isSpaceChar(c)
        return self.isWhitespace(c)

    def nextPowerOf2(self, a):
        b = 1
        while b < a:
            b = b << 1
        return b

    def PointInTriangle(self, p1, p2, p3, p4, p5, p6, p7, p8):
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

    def isPrime(self, n):
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

    def sort(self, a):
        n = len(a)
        b = [0] * n
        return self.mergeSort(a, b, 0, n - 1)

    def mergeSort(self, a, b, left, right):
        c = 0
        if left < right:
            mid = left + (right - left) // 2
            c = self.mergeSort(a, b, left, mid)
            c += self.mergeSort(a, b, mid + 1, right)
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
                j += 1
                c += mid - i
            k += 1
        while i <= mid - 1:
            b[k] = a[i]
            i += 1
            k += 1
        while j <= right:
            b[k] = a[j]
            j += 1
            k += 1
        for i in range(left, right + 1):
            a[i] = b[i]
        return c

    def InputReader(self, stream1):
        self.stream = stream1

    def isWhitespace(self, c):
        return c == ' ' or c == '\n' or c == '\r' or c == '\t' or c == -1

    def isEndOfLine(self, c):
        return c == '\n' or c == '\r' or c == -1

    def read(self):
        if self.numChars == -1:
            raise Exception("InputMismatchException")
        if self.curChar >= self.numChars:
            self.curChar = 0
            self.numChars = self.stream.read(self.buf)
            if self.numChars <= 0:
                return -1
        return self.buf[self.curChar]

    def nextInt(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < '0' or c > '9':
                raise Exception("InputMismatchException")
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def nextLong(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < '0' or c > '9':
                raise Exception("InputMismatchException")
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def nextToken(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = []
        while not self.isSpaceChar(c):
            res.append(c)
            c = self.read()
        return "".join(res)

    def nextLine(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = []
        while not self.isEndOfLine(c):
            res.append(c)
            c = self.read()
        return "".join(res)

    def nextIntArray(self, n):
        arr = [0] * n
        for i in range(n):
            arr[i] = self.nextInt()
        return arr

    def next2dArray(self, n, m):
        arr = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                arr[i][j] = self.nextInt()
        return arr

    def pArray(self, arr):
        for i in range(len(arr)):
            print(arr[i], end=" ")
        print()

    def isSpaceChar(self, c):
        if self.filter is not None:
            return self.filter.isSpaceChar(c)
        return self.isWhitespace(c)

    def nextPowerOf2(self, a):
        b = 1
        while b < a:
            b = b << 1
        return b

    def PointInTriangle(self, p1, p2, p3, p4, p5, p6, p7, p8):
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

    def isPrime(self, n):
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

    def sort(self, a):
        n = len(a)
        b = [0] * n
        return self.mergeSort(a, b, 0, n - 1)

    def mergeSort(self, a, b, left, right):
        c = 0
        if left < right:
            mid = left + (right - left) // 2
            c = self.mergeSort(a, b, left, mid)
            c += self.mergeSort(a, b, mid + 1, right)
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
                j += 1
                c += mid - i
            k += 1
        while i <= mid - 1:
            b[k] = a[i]
            i += 1
            k += 1
        while j <= right:
            b[k] = a[j]
            j += 1
            k += 1
        for i in range(left, right + 1):
            a[i] = b[i]
        return c

    def InputReader(self, stream1):
        self.stream = stream1

    def isWhitespace(self, c):
        return c == ' ' or c == '\n' or c == '\r' or c == '\t' or c == -1

    def isEndOfLine(self, c):
        return c == '\n' or c == '\r' or c == -1

    def read(self):
        if self.numChars == -1:
            raise Exception("InputMismatchException")
        if self.curChar >= self.numChars:
            self.curChar = 0
            self.numChars = self.stream.read(self.buf)
            if self.numChars <= 0:
                return -1
        return self.buf[self.curChar]

    def nextInt(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < '0' or c > '9':
                raise Exception("InputMismatchException")
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def nextLong(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < '0' or c > '9':
                raise Exception("InputMismatchException")
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def nextToken(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = []
        while not self.isSpaceChar(c):
            res.append(c)
            c = self.read()
        return "".join(res)

    def nextLine(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = []
        while not self.isEndOfLine(c):
            res.append(c)
            c = self.read()
        return "".join(res)

    def nextIntArray(self, n):
        arr = [0] * n
        for i in range(n):
            arr[i] = self.nextInt()
        return arr

    def next2dArray(self, n, m):
        arr = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                arr[i][j] = self.nextInt()
        return arr

    def pArray(self, arr):
        for i in range(len(arr)):
            print(arr[i], end=" ")
        print()

    def isSpaceChar(self, c):
        if self.filter is not None:
            return self.filter.isSpaceChar(c)
        return self.isWhitespace(c)

    def nextPowerOf2(self, a):
        b = 1
        while b < a:
            b = b << 1
        return b

    def PointInTriangle(self, p1, p2, p3, p4, p5, p6, p7, p8):
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

    def isPrime(self, n):
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

    def sort(self, a):
        n = len(a)
        b = [0] * n
        return self.mergeSort(a, b, 0, n - 1)

    def mergeSort(self, a, b, left, right):
        c = 0
        if left < right:
            mid = left + (right - left) // 2
            c = self.mergeSort(a, b, left, mid)
            c += self.mergeSort(a, b, mid + 1, right)
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
                j += 1
                c += mid - i
            k += 1
        while i <= mid - 1:
            b[k] = a[i]
            i += 1
            k += 1
        while j <= right:
            b[k] = a[j]
            j += 1
            k += 1
        for i in range(left, right + 1):
            a[i] = b[i]
        return c

    def InputReader(self, stream1):
        self.stream = stream1

    def isWhitespace(self, c):
        return c == ' ' or c == '\n' or c == '\r' or c == '\t' or c == -1

    def isEndOfLine(self, c):
        return c == '\n' or c == '\r' or c == -1

    def read(self):
        if self.numChars == -1:
            raise Exception("InputMismatchException")
        if self.curChar >= self.numChars:
            self.curChar = 0
            self.numChars = self.stream.read(self.buf)
            if self.numChars <= 0:
                return -1
        return self.buf[self.curChar]

    def nextInt(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < '0' or c > '9':
                raise Exception("InputMismatchException")
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def nextLong(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < '0' or c > '9':
                raise Exception("InputMismatchException")
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def nextToken(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = []
        while not self.isSpaceChar(c):
            res.append(c)
            c = self.read()
        return "".join(res)

    def nextLine(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = []
        while not self.isEndOfLine(c):
            res.append(c)
            c = self.read()
        return "".join(res)

    def nextIntArray(self, n):
        arr = [0] * n
        for i in range(n):
            arr[i] = self.nextInt()
        return arr

    def next2dArray(self, n, m):
        arr = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                arr[i][j] = self.nextInt()
        return arr

    def pArray(self, arr):
        for i in range(len(arr)):
            print(arr[i], end=" ")
        print()

    def isSpaceChar(self, c):
        if self.filter is not None:
            return self.filter.isSpaceChar(c)
        return self.isWhitespace(c)

    def nextPowerOf2(self, a):
        b = 1
        while b < a:
            b = b << 1
        return b

    def PointInTriangle(self, p1, p2, p3, p4, p5, p6, p7, p8):
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

    def isPrime(self, n):
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

    def sort(self, a):
        n = len(a)
        b = [0] * n
        return self.mergeSort(a, b, 0, n - 1)

    def mergeSort(self, a, b, left, right):
        c = 0
        if left < right:
            mid = left + (right - left) // 2
            c = self.mergeSort(a, b, left, mid)
            c += self.mergeSort(a, b, mid + 1, right)
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
                j += 1
                c += mid - i
            k += 1
        while i <= mid - 1:
            b[k] = a[i]
            i += 1
            k += 1
        while j <= right:
            b[k] = a[j]
            j += 1
            k += 1
        for i in range(left, right + 1):
            a[i] = b[i]
        return c

    def InputReader(self, stream1):
        self.stream = stream1

    def isWhitespace(self, c):
        return c == ' ' or c == '\n' or c == '\r' or c == '\t' or c == -1

    def isEndOfLine(self, c):
        return c == '\n' or c == '\r' or c == -1

    def read(self):
        if self.numChars == -1:
            raise Exception("InputMismatchException")
        if self.curChar >= self.numChars:
            self.curChar = 0
            self.numChars = self.stream.read(self.buf)
            if self.numChars <= 0:
                return -1
        return self.buf[self.curChar]

    def nextInt(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < '0' or c > '9':
                raise Exception("InputMismatchException")
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def nextLong(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < '0' or c > '9':
                raise Exception("InputMismatchException")
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def nextToken(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = []
        while not self.isSpaceChar(c):
            res.append(c)
            c = self.read()
        return "".join(res)

    def nextLine(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = []
        while not self.isEndOfLine(c):
            res.append(c)
            c = self.read()
        return "".join(res)

    def nextIntArray(self, n):
        arr = [0] * n
        for i in range(n):
            arr[i] = self.nextInt()
        return arr

    def next2dArray(self, n, m):
        arr = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                arr[i][j] = self.nextInt()
        return arr

    def pArray(self, arr):
        for i in range(len(arr)):
            print(arr[i], end=" ")
        print()

    def isSpaceChar(self, c):
        if self.filter is not None:
            return self.filter.isSpaceChar(c)
        return self.isWhitespace(c)

    def nextPowerOf2(self, a):
        b = 1
        while b < a:
            b = b << 1
        return b

    def PointInTriangle(self, p1, p2, p3, p4, p5, p6, p7, p8):
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

    def isPrime(self, n):
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

    def sort(self, a):
        n = len(a)
        b = [0] * n
        return self.mergeSort(a, b, 0, n - 1)

    def mergeSort(self, a, b, left, right):
        c = 0
        if left < right:
            mid = left + (right - left) // 2
            c = self.mergeSort(a, b, left, mid)
            c += self.mergeSort(a, b, mid + 1, right)
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
                j += 1
                c += mid - i
            k += 1
        while i <= mid - 1:
            b[k] = a[i]
            i += 1
            k += 1
        while j <= right:
            b[k] = a[j]
            j += 1
            k += 1
        for i in range(left, right + 1):
            a[i] = b[i]
        return c

    def InputReader(self, stream1):
        self.stream = stream1

    def isWhitespace(self, c):
        return c == ' ' or c == '\n' or c == '\r' or c == '\t' or c == -1

    def isEndOfLine(self, c):
        return c == '\n' or c == '\r' or c == -1

    def read(self):
        if self.numChars == -1:
            raise Exception("InputMismatchException")
        if self.curChar >= self.numChars:
            self.curChar = 0
            self.numChars = self.stream.read(self.buf)
            if self.numChars <= 0:
                return -1
        return self.buf[self.curChar]

    def nextInt(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < '0' or c > '9':
                raise Exception("InputMismatchException")
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def nextLong(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < '0' or c > '9':
                raise Exception("InputMismatchException")
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def nextToken(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = []
        while not self.isSpaceChar(c):
            res.append(c)
            c = self.read()
        return "".join(res)

    def nextLine(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = []
        while not self.isEndOfLine(c):
            res.append(c)
            c = self.read()
        return "".join(res)

    def nextIntArray(self, n):
        arr = [0] * n
        for i in range(n):
            arr[i] = self.nextInt()
        return arr

    def next2dArray(self, n, m):
        arr = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                arr[i][j] = self.nextInt()
        return arr

    def pArray(self, arr):
        for i in range(len(arr)):
            print(arr[i], end=" ")
        print()

    def isSpaceChar(self, c):
        if self.filter is not None:
            return self.filter.isSpaceChar(c)
        return self.isWhitespace(c)

    def nextPowerOf2(self, a):
        b = 1
        while b < a:
            b = b << 1
        return b

    def PointInTriangle(self, p1, p2, p3, p4, p5, p6, p7, p8):
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

    def isPrime(self, n):
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

    def sort(self, a):
        n = len(a)
        b = [0] * n
        return self.mergeSort(a, b, 0, n - 1)

    def mergeSort(self, a, b, left, right):
        c = 0
        if left < right:
            mid = left + (right - left) // 2
            c = self.mergeSort(a, b, left, mid)
            c += self.mergeSort(a, b, mid + 1, right)
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
                j += 1
                c += mid - i
            k += 1
        while i <= mid - 1:
            b[k] = a[i]
            i += 1
            k += 1
        while j <= right:
            b[k] = a[j]
            j += 1
            k += 1
        for i in range(left, right + 1):
            a[i] = b[i]
        return c

    def InputReader(self, stream1):
        self.stream = stream1

    def isWhitespace(self, c):
        return c == ' ' or c == '\n' or c == '\r' or c == '\t' or c == -1

    def isEndOfLine(self, c):
        return c == '\n' or c == '\r' or c == -1

    def read(self):
        if self.numChars == -1:
            raise Exception("InputMismatchException")
        if self.curChar >= self.numChars:
            self.curChar = 0
            self.numChars = self.stream.read(self.buf)
            if self.numChars <= 0:
                return -1
