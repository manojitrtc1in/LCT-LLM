import heapq
import sys
from typing import List

mod = 1000000007
mod2 = 998244353


class InVoker:
    def __init__(self):
        self.inp = FastReader()
        self.out = sys.stdout

    def main(self):
        n = self.inp.nextInt()
        k = self.inp.nextInt()
        a = [0] * n
        self.input(a, n)
        a.sort(reverse=True)
        pq = []
        for _ in range(k + 1):
            heapq.heappush(pq, 0)
        gg = 0
        for i in range(n):
            cur = heapq.heappop(pq)
            gg += cur
            cur += a[i]
            heapq.heappush(pq, cur)
        self.out.write(str(gg) + "\n")

    def sort(self, a: List[int]):
        a.sort()

    def ruffleSort(self, a: List[int]):
        import random
        random.shuffle(a)
        a.sort()

    def input(self, a: List[int], n: int):
        for i in range(n):
            a[i] = self.inp.nextLong()


class FastReader:
    def __init__(self):
        self.br = sys.stdin.buffer
        self.st = None

    def next(self):
        if self.st is None or not self.st.hasMoreElements():
            self.st = self.br.readline().split()
        return self.st.pop(0)

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        return self.br.readline()


if __name__ == "__main__":
    g = InVoker()
    g.main()
