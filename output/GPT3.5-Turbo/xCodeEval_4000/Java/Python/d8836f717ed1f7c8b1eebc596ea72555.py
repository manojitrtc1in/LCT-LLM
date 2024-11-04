import sys
from collections import deque

class C:
    def __init__(self):
        self.ONLINE_JUDGE = not (sys.stdin and sys.stdin.isatty())
        self.MODULO = 1000 * 1000 * 1000 + 7

    def solve(self):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))

        answer = self.getAnswer(n, a, k)

        print(answer[0])
        print(answer[1])

    def getAnswer(self, n, a, limit):
        MULTIPLIER = 50

        limit //= MULTIPLIER

        for i in range(n):
            a[i] //= MULTIPLIER

        onesCount = 0
        twosCount = 0
        for v in a:
            if v == 1:
                onesCount += 1
            else:
                twosCount += 1

        c = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            c[i][0] = c[i][i] = 1
            for j in range(1, i):
                c[i][j] = self.add(c[i - 1][j - 1], c[i - 1][j])

        FROM_SIDE = 0
        TO_SIDE = 1
        INF = float('inf')

        distances = [[[INF] * (twosCount + 1) for _ in range(onesCount + 1)] for _ in range(2)]
        ways = [[[0] * (twosCount + 1) for _ in range(onesCount + 1)] for _ in range(2)]

        distances[FROM_SIDE][onesCount][twosCount] = 0
        ways[FROM_SIDE][onesCount][twosCount] = 1

        q = deque([(FROM_SIDE, onesCount, twosCount)])

        while q:
            fromSide, fromOnes, fromTwos = q.popleft()

            fromDistance = distances[fromSide][fromOnes][fromTwos]
            fromWays = ways[fromSide][fromOnes][fromTwos]
            fromNextDistance = fromDistance + 1

            nextSide = FROM_SIDE + TO_SIDE - fromSide

            if fromSide == FROM_SIDE:
                for deltaOnes in range(fromOnes + 1):
                    for deltaTwos in range(fromTwos + 1):
                        if deltaOnes + deltaTwos == 0:
                            continue
                        if deltaOnes + 2 * deltaTwos > limit:
                            continue

                        nextOnes = fromOnes - deltaOnes
                        nextTwos = fromTwos - deltaTwos

                        nextDistance = distances[nextSide][nextOnes][nextTwos]

                        if nextDistance < fromNextDistance:
                            continue

                        fromNextWays = self.mult(fromWays, self.mult(c[fromOnes][deltaOnes], c[fromTwos][deltaTwos]))

                        if nextDistance > fromNextDistance:
                            nextDistance = distances[nextSide][nextOnes][nextTwos] = fromNextDistance
                            q.append((nextSide, nextOnes, nextTwos))

                        if nextDistance == fromNextDistance:
                            ways[nextSide][nextOnes][nextTwos] = self.add(ways[nextSide][nextOnes][nextTwos], fromNextWays)
            else:
                toOnes = onesCount - fromOnes
                toTwos = twosCount - fromTwos

                for deltaOnes in range(toOnes + 1):
                    for deltaTwos in range(toTwos + 1):
                        if deltaOnes + deltaTwos == 0:
                            continue
                        if deltaOnes + 2 * deltaTwos > limit:
                            continue

                        nextOnes = fromOnes + deltaOnes
                        nextTwos = fromTwos + deltaTwos

                        nextDistance = distances[nextSide][nextOnes][nextTwos]

                        if nextDistance < fromNextDistance:
                            continue

                        fromNextWays = self.mult(fromWays, self.mult(c[toOnes][deltaOnes], c[toTwos][deltaTwos]))

                        if nextDistance > fromNextDistance:
                            nextDistance = distances[nextSide][nextOnes][nextTwos] = fromNextDistance
                            q.append((nextSide, nextOnes, nextTwos))

                        if nextDistance == fromNextDistance:
                            ways[nextSide][nextOnes][nextTwos] = self.add(ways[nextSide][nextOnes][nextTwos], fromNextWays)

        distance = distances[TO_SIDE][0][0]
        if INF == distance:
            return (-1, 0)
        else:
            return (distance, ways[TO_SIDE][0][0])

    def inverse(self, x):
        return self.binpow(x, self.MODULO - 2)

    def binpow(self, base, power):
        if power == 0:
            return 1
        if power & 1 == 0:
            half = self.binpow(base, power >> 1)
            return self.mult(half, half)
        else:
            prev = self.binpow(base, power - 1)
            return self.mult(prev, base)

    def add(self, a, b):
        return (a + b) % self.MODULO

    def subtract(self, a, b):
        return self.add(a, self.MODULO - b % self.MODULO)

    def mult(self, a, b):
        return (a * b) % self.MODULO

    def run(self):
        if self.ONLINE_JUDGE:
            self.solve()
        else:
            while True:
                try:
                    self.solve()
                except EOFError:
                    break

if __name__ == "__main__":
    C().run()
