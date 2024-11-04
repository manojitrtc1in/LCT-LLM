import sys
from typing import List

class InputReader:
    def __init__(self, stream=sys.stdin):
        self.stream = stream

    def read(self):
        return self.stream.readline().strip()

    def read_int(self):
        return int(self.read())

    def read_int_list(self):
        return list(map(int, self.read().split()))

    def read_int_matrix(self, rows):
        matrix = []
        for _ in range(rows):
            matrix.append(self.read_int_list())
        return matrix

class OutputWriter:
    def __init__(self, stream=sys.stdout):
        self.stream = stream

    def write(self, value):
        self.stream.write(str(value))

    def write_line(self, value):
        self.stream.write(str(value))
        self.stream.write('\n')

    def write_list(self, values):
        self.stream.write(' '.join(map(str, values)))

    def write_matrix(self, matrix):
        for row in matrix:
            self.write_list(row)
            self.write_line('')

class NumberTheory:
    def modular_addition(self, a, b, mod):
        return (a % mod + b % mod) % mod

    def modular_multiplication(self, a, b, mod):
        return ((a % mod) * (b % mod)) % mod

    def modular_subtraction(self, a, b, mod):
        return (a % mod - b % mod + mod) % mod

    def binary_exponentiation(self, x, n):
        result = 1
        while n > 0:
            if n % 2 == 1:
                result *= x
            x = x * x
            n //= 2
        return result

    def modular_exponentiation(self, x, n, mod):
        result = 1
        while n > 0:
            if n % 2 == 1:
                result = self.modular_multiplication(result, x, mod)
            x = self.modular_multiplication(x, x, mod)
            n //= 2
        return result

    def factorials(self, n):
        if n == 0:
            return 1
        return n * self.factorials(n - 1)

    def distinct_prime_factors(self, n):
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

    def prime_factors(self, n):
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

    def binomial_coefficient_recursive(self, n, k):
        if k == 0 or k == n:
            return 1
        return self.binomial_coefficient_recursive(n - 1, k - 1) + self.binomial_coefficient_recursive(n - 1, k)

    def binomial_coefficient_iterative(self, n, k):
        C = [[0] * (k + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            for j in range(min(i, k) + 1):
                if j == 0 or j == i:
                    C[i][j] = 1
                else:
                    C[i][j] = C[i - 1][j - 1] + C[i - 1][j]
        return C[n][k]

    def nCr(self, n, r):
        C = [0] * (r + 1)
        C[0] = 1
        for i in range(1, n + 1):
            j = min(i, r)
            while j > 0:
                C[j] = C[j] + C[j - 1]
                j -= 1
        return C[r]

    def catlan_number(self, n):
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

class ProblemSolver:
    def solve_the_problem(self, in_reader: InputReader, out_writer: OutputWriter, nt: NumberTheory):
        test = 1
        while test > 0:
            test -= 1
            n = in_reader.read_int()
            ar = in_reader.read_int_matrix(n, n)
            sum = 0
            for i in range(n):
                sum += ar[i][i]
            for i in range(n):
                sum += ar[n - i - 1][i]
            for i in range(n):
                sum += ar[(n - 1) // 2][i]
            for i in range(n):
                sum += ar[i][(n - 1) // 2]
            out_writer.write_line(sum - ar[(n - 1) // 2][(n - 1) // 2] * 3)

def main():
    in_reader = InputReader()
    out_writer = OutputWriter()
    nt = NumberTheory()
    problem_solver = ProblemSolver()
    problem_solver.solve_the_problem(in_reader, out_writer, nt)
    out_writer.flush()

if __name__ == '__main__':
    main()
