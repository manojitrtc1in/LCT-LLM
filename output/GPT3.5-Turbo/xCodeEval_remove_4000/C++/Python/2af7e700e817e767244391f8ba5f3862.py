import math

class Vert:
    def __init__(self, hoge):
        self.hoge = hoge

def sign(a, b):
    hoge = 0
    for i in range(5):
        hoge += a.hoge[i] * b.hoge[i]
    return hoge <= 0

def solve():
    n = int(input())
    inputs = []
    for _ in range(n):
        a = Vert(list(map(int, input().split())))
        inputs.append(a)
    
    ans = []
    for i in range(n):
        ok = 1
        for q in range(n):
            if i == q:
                continue
            for j in range(q+1, n):
                if i == j:
                    continue
                A = Vert([inputs[q].hoge[t] - inputs[i].hoge[t] for t in range(5)])
                B = Vert([inputs[j].hoge[t] - inputs[i].hoge[t] for t in range(5)])
                if not sign(A, B):
                    ok = 0
                    break
            if ok == 0:
                break
        if ok == 1:
            ans.append(i)
    
    print(len(ans))
    print(*[x+1 for x in ans])

solve()
