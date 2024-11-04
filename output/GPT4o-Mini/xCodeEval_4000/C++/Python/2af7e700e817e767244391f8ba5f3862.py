import sys
import math
from collections import deque, defaultdict
from itertools import combinations

def init():
    sys.stdin = open(0)
    sys.stdout = open(1)
    print("{:.20f}".format(0))

class Vert:
    def __init__(self, values):
        self.hoge = values

def sign(a, b):
    return sum(a.hoge[q] * b.hoge[q] for q in range(5)) <= 0

def solve():
    n = int(input())
    inputs = []
    for _ in range(n):
        a = list(map(int, input().split()))
        inputs.append(Vert(a))
    
    ans = []
    for i in range(n):
        ok = 1
        for q in range(n):
            if i == q:
                continue
            for j in range(q + 1, n):
                if i == j:
                    continue
                A = Vert([inputs[q].hoge[t] - inputs[i].hoge[t] for t in range(5)])
                B = Vert([inputs[j].hoge[t] - inputs[i].hoge[t] for t in range(5)])
                if sign(A, B) == 0:
                    ok = 0
                    break
            if ok == 0:
                break
        if ok == 1:
            ans.append(i)
    
    print(len(ans))
    print(" ".join(str(x + 1) for x in ans))

if __name__ == "__main__":
    init()
    solve()
