class FenwickTree:
    def __init__(self, size):
        self.value = [0] * size

    def add(self, at, v):
        while at < len(self.value):
            self.value[at] += v
            at |= at + 1

    def get(self, from_, to):
        if from_ >= to:
            return 0
        return self._get(to - 1) - self._get(from_ - 1)

    def _get(self, to):
        to = min(to, len(self.value) - 1)
        result = 0
        while to >= 0:
            result += self.value[to]
            to = (to & (to + 1)) - 1
        return result


class BVerkhnyayaYacheika:
    def solve(self):
        n = int(input())
        m = int(input())

        mod = m
        ft = FenwickTree(n + 1)
        ft.add(n, 1)
        for i in range(n, 1, -1):
            res = ft.get(i + 1, n + 1)
            for z in range(2, n // i + 1):
                res += ft.get(z * i, z * i + z)
            ft.add(i, res)
        print(ft.get(1, 2))


solver = BVerkhnyayaYacheika()
solver.solve()
