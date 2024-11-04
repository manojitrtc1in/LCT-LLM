import sys
import random
import heapq

mod = 1000000007
mod2 = 998244353

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        self.index += 1
        return self.data[self.index - 1]

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return self.data[self.index:]

def input_array(n):
    return [inp.next_long() for _ in range(n)]

def sort(arr):
    arr.sort()

def main():
    n = inp.next_int()
    k = inp.next_int()
    a = input_array(n)
    sort(a)
    
    for i in range(n // 2):
        a[i], a[n - 1 - i] = a[n - 1 - i], a[i]

    pq = [0] * (k + 1)
    heapq._heapify_max(pq)

    gg = 0
    for i in range(n):
        cur = heapq._heappop_max(pq)
        gg += cur
        cur += a[i]
        heapq.heappush(pq, cur)

    print(gg)

inp = FastReader()
main()
