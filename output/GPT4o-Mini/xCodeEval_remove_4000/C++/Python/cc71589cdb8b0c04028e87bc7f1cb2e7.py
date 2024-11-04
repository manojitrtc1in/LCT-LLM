import sys
import time
import random

INF = int(1e9)
INF64 = int(1e18)
MOD = int(1e9) + 7
EPS = 1e-9
PI = 3.141592653589793

N = 1000 + 7

lim = [0, 9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099]
pr1 = ["", "198", "19", "2", "", "", "", "", "", ""]
pr2 = ["", "199", "20", "3", "1", "1", "1", "1", "1", "1"]

def read():
    global s, n
    buf = sys.stdin.readline().strip()
    if not buf:
        return False
    s = buf[4:]
    n = len(s)
    return True

def solve():
    x = int(s)
    if x >= lim[n]:
        return pr1[n] + s
    else:
        return pr2[n] + s

def main():
    sys.stdin = open("input.txt", "r")
    
    tt = time.clock()
    
    sys.stdout = open('output.txt', 'w')
    
    tc = int(sys.stdin.readline().strip())
    while tc > 0:
        tc -= 1
        if read():
            print(solve())
            print(f'TIME = {time.clock() - tt}')
            tt = time.clock()

if __name__ == "__main__":
    main()
