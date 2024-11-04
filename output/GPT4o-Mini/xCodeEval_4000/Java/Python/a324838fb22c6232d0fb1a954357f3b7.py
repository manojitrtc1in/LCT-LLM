import sys
import math
from collections import defaultdict

class ProblemSolver:
    def solve_the_problem(self, in_stream, out_stream):
        test = 1

        while test > 0:
            n = in_stream()
            ar = [list(map(int, in_stream().split())) for _ in range(n)]

            total_sum = 0
            for i in range(n):
                total_sum += ar[i][i]

            for i in range(n):
                total_sum += ar[n - i - 1][i]

            for i in range(n):
                total_sum += ar[(n - 1) // 2][i]

            for i in range(n):
                total_sum += ar[i][(n - 1) // 2]

            out_stream(total_sum - ar[(n - 1) // 2][(n - 1) // 2] * 3)
            test -= 1

def main():
    input_stream = sys.stdin.read
    output_stream = sys.stdout.write
    problem_solver = ProblemSolver()
    problem_solver.solve_the_problem(lambda: int(input_stream().strip()), output_stream)

if __name__ == "__main__":
    main()
