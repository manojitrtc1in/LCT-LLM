from collections import deque

def scan():
    return input().strip()

def print_con(*args):
    print(' '.join(map(str, args)), end='')

def print_(var):
    print(var)

def max_set(a, b):
    return a < b

def solve():
    A = scan()
    B = scan()
    V = scan()
    nA = len(A)
    nB = len(B)
    nV = len(V)
    
    prefix = [[0] * 256 for _ in range(nV)]
    d = [[[-1] * nV for _ in range(nB + 1)] for _ in range(nA + 1)]
    c = [[[-1] * nV for _ in range(nB + 1)] for _ in range(nA + 1)]
    
    for iV in range(nV):
        for C in range(ord('A'), ord('Z') + 1):
            prefix[iV][C] = iV + 1
            while prefix[iV][C] > 0:
                if V[0:prefix[iV][C]] == V[iV + 1 - prefix[iV][C]:iV + 1] + chr(C):
                    break
                prefix[iV][C] -= 1

    mx = 0
    cans = 0
    ans = deque()

    for iA in range(1, nA + 1):
        for iB in range(1, nB + 1):
            for iV in range(nV):
                d[iA][iB][iV] = -1
                if max_set(d[iA][iB][iV], d[iA - 1][iB][iV]):
                    c[iA][iB][iV] = -1
                if max_set(d[iA][iB][iV], d[iA][iB - 1][iV]):
                    c[iA][iB][iV] = -2

            for iV in range(nV):
                if A[iA - 1] == B[iB - 1]:
                    if max_set(d[iA][iB][prefix[iV][ord(A[iA - 1])]], d[iA - 1][iB - 1][iV] + 1):
                        c[iA][iB][prefix[iV][ord(A[iA - 1])]] = iV

    for iV in range(nV):
        if max_set(mx, d[nA][nB][iV]):
            cans = iV

    if mx == 0:
        print_(0)
    else:
        iA, iB, iV = nA, nB, cans
        while iA > 0 and iB > 0:
            if c[iA][iB][iV] == -1:
                iA -= 1
            elif c[iA][iB][iV] == -2:
                iB -= 1
            else:
                ans.append(A[iA - 1])
                iV = c[iA][iB][iV]
                iA -= 1
                iB -= 1

    while ans:
        print_(ans.pop())

def prep():
    pass

def main():
    USEFILE = False
    TESTCASE = False
    if USEFILE:
        # read from file
        pass
    prep()
    if TESTCASE:
        test_num = int(scan())
        for test_count in range(1, test_num + 1):
            solve()
    else:
        solve()

if __name__ == "__main__":
    main()
