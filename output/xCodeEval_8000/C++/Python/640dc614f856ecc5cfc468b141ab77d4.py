import sys
import math
import time

def getbit(s, i):
    return (s >> i) & 1

def onbit(s, i):
    return s | (1 << i)

def offbit(s, i):
    return s & (~(1 << i))

def cntbit(s):
    return bin(s).count('1')

def func(m, n, s):
    if m == 0:
        return (n, s)
    k = int(m ** (1/3))
    x = k * k * k
    y = (k - 1) * (k - 1) * (k - 1)
    return max(func(m - x, n + 1, s + x), func(x - y - 1, n + 1, s + y))

def Input():
    global x
    x = int(input())

def Solve():
    Token = func(x, 0, 0)
    print(Token[0], Token[1])

if __name__ == "__main__":
    Input()
    Solve()
