class ProblemSolver:
    def id13(self, in, out, nt):
        test = 1

        while test > 0:
            n = in.nextInt()
            ar = [[0] * n for _ in range(n)]
            ar = in.id0(n, n)

            sum = 0
            for i in range(n):
                sum += ar[i][i]

            for i in range(n):
                sum += ar[n - i - 1][i]

            for i in range(n):
                sum += ar[(n - 1) // 2][i]

            for i in range(n):
                sum += ar[i][(n - 1) // 2]

            print(sum - ar[(n - 1) // 2][(n - 1) // 2] * 3)


def main():
    problemSolver = ProblemSolver()
    problemSolver.id13(InputReader(), OutputWriter(), NumberTheory())


class InputReader:
    def __init__(self):
        self.stream = sys.stdin.buffer
        self.buf = bytearray()
        self.curChar = 0
        self.numChars = 0

    def read(self):
        if self.numChars == -1:
            raise EOFError()
        if self.curChar >= self.numChars:
            self.curChar = 0
            self.numChars = self.stream.readinto(self.buf)
            if self.numChars <= 0:
                return -1
        return self.buf[self.curChar]

    def peek(self):
        if self.numChars == -1:
            return -1
        if self.curChar >= self.numChars:
            self.curChar = 0
            self.numChars = self.stream.readinto(self.buf)
            if self.numChars <= 0:
                return -1
        return self.buf[self.curChar]

    def nextInt(self):
        c = self.read()
        while c <= 32:
            c = self.read()
        sign = 1 if c > 45 else -1
        if sign == -1:
            c = self.read()
        res = 0
        while c >= 48 and c <= 57:
            res = res * 10 + c - 48
            c = self.read()
        return res * sign

    def nextLong(self):
        c = self.read()
        while c <= 32:
            c = self.read()
        sign = 1 if c > 45 else -1
        if sign == -1:
            c = self.read()
        res = 0
        while c >= 48 and c <= 57:
            res = res * 10 + c - 48
            c = self.read()
        return res * sign

    def nextLine(self):
        c = self.read()
        while c <= 32:
            c = self.read()
        res = bytearray()
        while c != 10 and c != 13 and c != -1:
            res.append(c)
            c = self.read()
        return res.decode()

    def id5(self, c):
        return c == 32 or c == 10 or c == 13 or c == 9 or c == -1

    def id1(self):
        res = bytearray()
        c = self.read()
        while c != 10 and c != 13 and c != -1:
            if c != 13:
                res.append(c)
            c = self.read()
        return res.decode()

    def readLine(self):
        s = self.id1()
        while len(s.strip()) == 0:
            s = self.id1()
        return s

    def id20(self):
        try:
            return int(self.nextLine())
        except ValueError:
            raise ValueError("Invalid integer")

    def nextCharacter(self):
        c = self.read()
        while c <= 32:
            c = self.read()
        return chr(c)

    def nextDouble(self):
        c = self.read()
        while c <= 32:
            c = self.read()
        sign = 1 if c > 45 else -1
        if sign == -1:
            c = self.read()
        res = 0.0
        while c >= 48 and c <= 57:
            res = res * 10 + c - 48
            c = self.read()
        if c == 46:
            c = self.read()
            m = 1.0
            while c >= 48 and c <= 57:
                m /= 10
                res += (c - 48) * m
                c = self.read()
        return res * sign

    def id4(self):
        value = self.peek()
        while self.id5(value) and value != -1:
            self.read()
            value = self.peek()
        return value == -1

    def next(self):
        return self.nextLine()

    def id12(self, n):
        array = [0] * n
        for i in range(n):
            array[i] = self.nextInt()
        return array

    def id17(self, n):
        array = self.id12(n)
        array.sort()
        return array

    def id3(self, n):
        ar = []
        for i in range(n):
            ar.append(self.nextInt())
        return ar

    def id24(self, n):
        ar = []
        for i in range(n):
            ar.append(self.nextLong())
        return ar

    def id22(self, n):
        array = [0] * n
        array[0] = self.nextInt()
        for i in range(1, n):
            array[i] = array[i - 1] + self.nextInt()
        return array

    def id28(self, n):
        array = [0] * n
        for i in range(n):
            array[i] = self.nextLong()
        return array

    def id2(self, n):
        array = [0] * n
        array[0] = self.nextInt()
        for i in range(1, n):
            array[i] = array[i - 1] + self.nextInt()
        return array

    def id14(self, n):
        array = self.id28(n)
        array.sort()
        return array

    def id0(self, n, m):
        matrix = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                matrix[i][j] = self.nextInt()
        return matrix

    def id18(self, n, m):
        matrix = []
        for i in range(n):
            matrix.append(list(self.next()))
        return matrix


class OutputWriter:
    def __init__(self):
        self.writer = sys.stdout

    def print(self, *objects):
        for i in range(len(objects)):
            if i != 0:
                self.writer.write(' ')
            self.writer.write(str(objects[i]))

    def println(self, *objects):
        self.print(*objects)
        self.writer.write('\n')

    def printLine(self):
        self.writer.write('\n')

    def printArray(self, array):
        for i in range(len(array)):
            if i != 0:
                self.writer.write(' ')
            self.writer.write(str(array[i]))

    def printMatrix(self, matrix):
        for i in range(len(matrix)):
            self.println(matrix[i])

    def printChar(self, c):
        self.writer.write(c)

    def printlnChar(self, c):
        self.writer.write(c)
        self.writer.write('\n')

    def printlnArray(self, array):
        self.printArray(array)
        self.writer.write('\n')

    def printf(self, format, *objects):
        self.writer.write(format % objects)

    def close(self):
        self.writer.close()

    def flush(self):
        self.writer.flush()


class NumberTheory:
    def id11(self, a, b, MOD):
        return (a % MOD + b % MOD) % MOD

    def id19(self, a, b, MOD):
        return ((a % MOD) * (b % MOD)) % MOD

    def id15(self, a, b, MOD):
        return (a % MOD - b % MOD + MOD) % MOD

    def id26(self, x, n):
        if n == 0:
            return 1
        elif n % 2 == 0:
            return self.id26(x * x, n // 2)
        else:
            return x * self.id26(x * x, (n - 1) // 2)

    def id23(self, x, n, MOD):
        if n == 0:
            return 1 % MOD
        elif n % 2 == 0:
            return self.id23(self.id19(x, x, MOD), n // 2, MOD)
        else:
            return self.id19(x, self.id23(self.id19(x, x, MOD), (n - 1) // 2, MOD), MOD)

    def factorials(self, n):
        if n == 0:
            return 1
        return n * self.factorials(n - 1)

    def id16(self, n):
        factorials = []
        limit = int(n ** 0.5)
        if n % 2 == 0:
            factorials.append(2)
            while n % 2 == 0:
                n //= 2
        for i in range(3, limit + 1, 2):
            if n % i == 0:
                factorials.append(i)
                while n % i == 0:
                    n //= i
        if n > 2:
            factorials.append(n)
        return factorials

    def primeFactors(self, n):
        factorials = []
        limit = int(n ** 0.5)
        if n % 2 == 0:
            factorials.append(2)
            while n % 2 == 0:
                n //= 2
        for i in range(3, limit + 1, 2):
            if n % i == 0:
                factorials.append(i)
                while n % i == 0:
                    n //= i
        if n > 2:
            factorials.append(n)
        return factorials

    def id6(self, n, k):
        if k == 0 or k == n:
            return 1
        return self.id6(n - 1, k - 1) + self.id6(n - 1, k)

    def id21(self, n, k):
        C = [[0] * (k + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            for j in range(min(n, k) + 1):
                if j == 0 or j == i:
                    C[i][j] = 1
                else:
                    C[i][j] = C[i - 1][j - 1] + C[i - 1][j]
        return C[n][k]

    def id7(self, n):
        catlan = [0] * (n + 1)
        catlan[0] = catlan[1] = 1
        for i in range(2, n + 1):
            for j in range(i):
                catlan[i] += catlan[j] * catlan[i - 1 - j]
        return catlan[n]

    def gcd(self, a, b):
        if b == 0:
            return a
        return self.gcd(b, a % b)

    def lcm(self, a, b):
        return (a * b) // self.gcd(a, b)


if __name__ == "__main__":
    main()
