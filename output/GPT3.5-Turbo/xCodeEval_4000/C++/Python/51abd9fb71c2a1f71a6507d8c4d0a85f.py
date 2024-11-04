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

def Pow(a, b):
    if b == 0:
        return 1
    tmp = Pow(a, b//2)
    if b % 2 == 0:
        return tmp * tmp
    return tmp * tmp * a

def Try(id, x1, x2, x3):
    global Min, Max, A
    if id == len(A):
        Min = min(Min, (x1+1)*(x2+2)*(x3+2))
        Min = min(Min, (x1+2)*(x2+1)*(x3+2))
        Min = min(Min, (x1+2)*(x2+2)*(x3+1))
        Max = max(Max, (x1+1)*(x2+2)*(x3+2))
        Max = max(Max, (x1+2)*(x2+1)*(x3+2))
        Max = max(Max, (x1+2)*(x2+2)*(x3+1))
        return
    key = A[id][0]
    v = A[id][1]
    for i in range(v+1):
        for j in range(v+1):
            for k in range(v+1):
                if i + j + k != v:
                    continue
                Try(id+1, x1 * Pow(key, i), x2 * Pow(key, j), x3 * Pow(key, k))

def Input():
    global n
    n = int(input())

def Solve():
    global n, Min, Max, A
    Map = {}
    N = n
    for i in range(2, int(math.sqrt(n))+1):
        while n % i == 0:
            if i in Map:
                Map[i] += 1
            else:
                Map[i] = 1
            n //= i
    if n > 1:
        if n in Map:
            Map[n] += 1
        else:
            Map[n] = 1
    A = list(Map.items())
    Try(0, 1, 1, 1)
    print(Min - N, Max - N)

def main():
    global n, Min, Max, A
    n = 0
    Min = float('inf')
    Max = float('-inf')
    A = []
    Input()
    Solve()

if __name__ == "__main__":
    main()
