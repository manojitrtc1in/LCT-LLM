import sys
from collections import deque

MOD = 1000000007
MOD2 = 1000000009
INF = 2000000000
LINF = 8000000000000000000
PI = 3.141592653589793

def scan():
    return sys.stdin.readline().strip()

def print_con(*args):
    print(' '.join(map(str, args)), end='')

def max_set(lhs, rhs):
    if lhs < rhs:
        lhs = rhs
        return True
    return False

def solve():
    global mx, cans
    A = '#' + scan() + '#'
    B = '#' + scan() + '#'
    V = '#' + scan() + '#'
    
    nA = len(A) - 1
    nB = len(B) - 1
    nV = len(V) - 1
    
    prefix = [[0] * 256 for _ in range(nV)]
    d = [[[-1] * 101 for _ in range(101)] for _ in range(101)]
    c = [[[-1] * 101 for _ in range(101)] for _ in range(101)]
    
    for iV in range(nV):
        for C in range(ord('A'), ord('Z') + 1):
            prefix[iV][C] = iV + 1
            while prefix[iV][C] > 0:
                if V[1:prefix[iV][C]] == V[iV + 2 - prefix[iV][C]:prefix[iV][C] - 1] + chr(C):
                    break
                prefix[iV][C] -= 1

    for iA in range(1, nA + 1):
        for iB in range(1, nB + 1):
            for iV in range(nV):
                d[iA][iB][iV] = -1
                if max_set(d[iA][iB][iV], d[iA - 1][iB][iV]):
                    c[iA][iB][iV] = -1
                if max_set(d[iA][iB][iV], d[iA][iB - 1][iV]):
                    c[iA][iB][iV] = -2

            for iV in range(nV):
                if A[iA] == B[iB]:
                    if max_set(d[iA][iB][prefix[iV][ord(A[iA])]], d[iA - 1][iB - 1][iV] + 1):
                        c[iA][iB][prefix[iV][ord(A[iA])]] = iV

    mx = 0
    for iV in range(nV):
        if max_set(mx, d[nA][nB][iV]):
            cans = iV

    if mx == 0:
        print_con(0)
    else:
        iA, iB, iV = nA, nB, cans
        ans = deque()
        while iA > 0 and iB > 0:
            if c[iA][iB][iV] == -1:
                iA -= 1
            elif c[iA][iB][iV] == -2:
                iB -= 1
            else:
                ans.append(A[iA])
                iV = c[iA][iB][iV]
                iA -= 1
                iB -= 1

        while ans:
            print_con(ans.pop())

def prep():
    pass

def main():
    prep()
    solve()

if __name__ == "__main__":
    main()
