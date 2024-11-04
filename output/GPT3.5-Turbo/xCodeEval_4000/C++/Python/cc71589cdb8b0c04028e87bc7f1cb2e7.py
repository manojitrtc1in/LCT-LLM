import sys
import math
import random

def solve():
    x = int(s)
    if x >= lim[n]:
        return pr1[n] + s
    else:
        return pr2[n] + s

def read():
    s = input().strip()
    s = s[4:]
    n = len(s)
    return s, n

def main():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

    tc = int(input())
    for _ in range(tc):
        s, n = read()
        print(solve())

if __name__ == "__main__":
    main()
