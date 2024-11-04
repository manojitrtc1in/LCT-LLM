RL = lambda type = int: list(map(type, input().rstrip().split()))

A = ["0","1","2","6","(","D","E3","_&","/51","n`6","n4>","!rR2","E+a*","j61h1","!3ab!","q`t6


def from_base(X):
    base = "0123456789`~!@
    l = len(base)
    r = 0
    e = 1
    for c in X:
        r += base.index(c)*e
        e *= l
    return r

def solve():
    N, mod = RL()
    print(from_base(A[N]) % mod)


    

T = 1
for t in range(T):
    solve()
