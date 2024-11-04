import sys
import random
from collections import deque
from math import gcd, isqrt

MODULO = 1000 * 1000 * 1000 + 7
id3 = False
id6 = True
id10 = not (open("input.txt").exists() if 'input.txt' in locals() else False)
id17 = 128
id30 = False

class C:
    def solve(self):
        n = self.read_int()
        k = self.read_int()
        a = self.id2(n)

        answer = self.get_answer(n, a, k)

        print(answer[0])
        print(answer[1])

    def get_answer(self, n, a, limit):
        id22 = 50
        limit //= id22

        for i in range(n):
            a[i] //= id22

        ones_count = sum(1 for v in a if v == 1)
        id33 = n - ones_count

        c = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            c[i][0] = c[i][i] = 1
            for j in range(1, i):
                c[i][j] = self.add(c[i - 1][j - 1], c[i - 1][j])

        FROM_SIDE = 0
        TO_SIDE = 1
        INF = float('inf')

        distances = [[[INF] * (id33 + 1) for _ in range(ones_count + 1)] for _ in range(2)]
        ways = [[[0] * (id33 + 1) for _ in range(ones_count + 1)] for _ in range(2)]

        distances[FROM_SIDE][ones_count][id33] = 0
        ways[FROM_SIDE][ones_count][id33] = 1

        q = deque([(FROM_SIDE, ones_count, id33)])

        while q:
            from_side, ones, twos = q.popleft()
            from_distance = distances[from_side][ones][twos]
            from_ways = ways[from_side][ones][twos]
            id39 = from_distance + 1

            next_side = FROM_SIDE + TO_SIDE - from_side

            if from_side == FROM_SIDE:
                for id44 in range(ones + 1):
                    for id45 in range(twos + 1):
                        if id44 + id45 == 0:
                            continue
                        if id44 + 2 * id45 > limit:
                            continue

                        id24 = ones - id44
                        id32 = twos - id45

                        next_distance = distances[next_side][id24][id32]

                        if next_distance < id39:
                            continue

                        id23 = self.mult(from_ways, self.mult(c[ones][id44], c[twos][id45]))

                        if next_distance > id39:
                            next_distance = distances[next_side][id24][id32] = id39
                            q.append((next_side, id24, id32))

                        if next_distance == id39:
                            ways[next_side][id24][id32] = self.add(ways[next_side][id24][id32], id23)
            else:
                id34 = ones_count - ones
                id12 = id33 - twos

                for id44 in range(id34 + 1):
                    for id45 in range(id12 + 1):
                        if id44 + id45 == 0:
                            continue
                        if id44 + 2 * id45 > limit:
                            continue

                        id24 = ones + id44
                        id32 = twos + id45

                        next_distance = distances[next_side][id24][id32]

                        if next_distance < id39:
                            continue

                        id23 = self.mult(from_ways, self.mult(c[id34][id44], c[id12][id45]))

                        if next_distance > id39:
                            next_distance = distances[next_side][id24][id32] = id39
                            q.append((next_side, id24, id32))

                        if next_distance == id39:
                            ways[next_side][id24][id32] = self.add(ways[next_side][id24][id32], id23)

        distance = distances[TO_SIDE][0][0]
        if INF == distance:
            return (-1, 0)
        else:
            return (distance, int(ways[TO_SIDE][0][0]))

    def inverse(self, x):
        return self.binpow(x, MODULO - 2)

    def binpow(self, base, power):
        if power == 0:
            return 1
        if power % 2 == 0:
            half = self.binpow(base, power // 2)
            return self.mult(half, half)
        else:
            prev = self.binpow(base, power - 1)
            return self.mult(prev, base)

    def add(self, a, b):
        return (a + b) % MODULO

    def mult(self, a, b):
        return (a * b) % MODULO

    def read_int(self):
        return int(sys.stdin.readline().strip())

    def id2(self, size):
        return [self.read_int() for _ in range(size)]

    def main(self):
        try:
            if id10:
                self.solve()
            else:
                while True:
                    try:
                        self.solve()
                        print()
                    except EOFError:
                        break
                    except Exception as e:
                        if id3:
                            break
                        else:
                            raise e
        except Exception as e:
            print(e, file=sys.stderr)
            sys.exit(-1)

if __name__ == "__main__":
    C().main()
