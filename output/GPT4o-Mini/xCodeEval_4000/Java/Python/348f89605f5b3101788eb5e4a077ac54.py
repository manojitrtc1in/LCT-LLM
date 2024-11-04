import sys
import random
from collections import deque
from heapq import heappop, heappush

mod = 1000000007
mod2 = 998244353

class InVoker:
    
    def main(self):
        n = int(input())
        k = int(input())
        a = list(map(int, input().split()))
        a.sort()
        a = a[::-1]
        
        pq = [0] * (k + 1)
        gg = 0
        
        for i in range(n):
            cur = heappop(pq)
            gg += cur
            cur += a[i]
            heappush(pq, cur)
        
        print(gg)

if __name__ == "__main__":
    g = InVoker()
    g.main()
