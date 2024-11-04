import sys
from typing import List, Tuple

class id6:
    def solve(self, testNumber: int, n: int, A: List[int], B: List[int]) -> int:
        used = [False] * n
        order = sorted(range(n), key=lambda i: A[i], reverse=True)
        res = 0
        idx = 0
        while idx < n:
            to = idx
            while to + 1 < n and A[order[to + 1]] == A[order[idx]]:
                to += 1
            valid = to > idx
            if not valid:
                for i in range(idx):
                    if used[i] and (A[order[i]] & A[order[idx]]) == A[order[idx]]:
                        valid = True
                        break
            if valid:
                for i in range(idx, to + 1):
                    res += B[order[i]]
                    used[i] = True
            idx = to + 1
        return res

def main():
    input = sys.stdin.buffer.readline
    output = sys.stdout.buffer.write

    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    solver = id6()
    result = solver.solve(1, n, A, B)
    output(str(result).encode())

if __name__ == "__main__":
    main()
