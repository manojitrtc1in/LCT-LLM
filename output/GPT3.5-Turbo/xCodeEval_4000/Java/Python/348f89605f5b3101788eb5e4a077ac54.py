import heapq
import sys

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
        self.out.write(str(gg) + '\n')

    def sort(self, a):
        a.sort()

    def ruffleSort(self, a):
        random.shuffle(a)
        a.sort()

    def input(self, a, n):
        for i in range(n):
            a[i] = self.inp.nextLong()

class FastReader:
    def __init__(self):
        self.br = sys.stdin
        self.st = None

    def next(self):
        while self.st is None or not self.st.hasMoreElements():
            try:
                self.st = self.br.readline().split()
            except IOError:
                pass
        return self.st.pop(0)

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        try:
            return self.br.readline()
        except IOError:
            pass

if __name__ == '__main__':
    g = InVoker()
    g.main()
    g.out.close()
