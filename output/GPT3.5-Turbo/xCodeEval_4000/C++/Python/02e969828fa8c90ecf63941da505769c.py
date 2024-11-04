import sys
import time
import math

def modPow(a, b, M):
    if b == 0:
        return 1
    tmp = modPow(a, b//2, M)
    if b % 2 == 0:
        return (tmp * tmp) % M
    return (((tmp * tmp) % M) * a) % M

def Input():
    global n, m
    n, m = map(int, input().split())

def Solve():
    A = (modPow(3, n, m) + m - 1) % m
    print(A)

def main():
    Input()
    Solve()

if __name__ == "__main__":
    main()
