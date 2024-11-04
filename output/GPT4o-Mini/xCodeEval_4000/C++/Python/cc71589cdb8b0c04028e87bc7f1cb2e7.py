import sys
import random
import time

INF = int(1e9)
INF64 = int(1e18)
MOD = int(1e9) + 7
EPS = 1e-9
PI = 3.141592653589793

lim = [0, 9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099]
pr1 = ["", "198", "19", "2", "", "", "", "", "", ""]
pr2 = ["", "199", "20", "3", "1", "1", "1", "1", "1", "1"]

def read():
    s = input().strip()
    return s[4:], len(s[4:])

def solve(s, n):
    x = int(s)
    if x >= lim[n]:
        return pr1[n] + s
    else:
        return pr2[n] + s

def main():
    if len(sys.argv) > 1 and sys.argv[1] == "_DEBUG":
        with open("input.txt", "r") as f:
            input_data = f.read().strip().splitlines()
        input_iter = iter(input_data)
    else:
        input_iter = iter(sys.stdin)

    if len(sys.argv) > 1 and sys.argv[1] == "MULTITEST":
        tc = int(next(input_iter))
        for _ in range(tc):
            s, n = read()
            print(solve(s, n))
    else:
        while True:
            try:
                s, n = read()
                print(solve(s, n))
            except EOFError:
                break

if __name__ == "__main__":
    main()
