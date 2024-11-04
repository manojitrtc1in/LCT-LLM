import sys
import random
from collections import deque
from math import gcd, isqrt

MODULO = 1000 * 1000 * 1000 + 7
MAX_STACK_SIZE = 128
FIRST_INPUT_STRING = False
MULTIPLE_TESTS = True
ONLINE_JUDGE = not (sys.stdin.isatty())

class C:
    def solve(self):
        n = self.read_int()
        k = self.read_int()
        a = self.read_int_array(n)

        answer = self.get_answer(n, a, k)

        print(answer[0])
        print(answer[1])

    def get_answer(self, n, a, limit):
        MULTIPLIER = 50
        limit //= MULTIPLIER

        for i in range(n):
            a[i] //= MULTIPLIER

        ones_count = sum(1 for v in a if v == 1)
        twos_count = sum(1 for v in a if v == 2)

        c = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            c[i][0] = c[i][i] = 1
            for j in range(1, i):
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MODULO

        FROM_SIDE = 0
        TO_SIDE = 1
        INF = float('inf')

        distances = [[[INF] * (twos_count + 1) for _ in range(ones_count + 1)] for _ in range(2)]
        ways = [[[0] * (twos_count + 1) for _ in range(ones_count + 1)] for _ in range(2)]

        distances[FROM_SIDE][ones_count][twos_count] = 0
        ways[FROM_SIDE][ones_count][twos_count] = 1

        q = deque([(FROM_SIDE, ones_count, twos_count)])

        while q:
            from_side, ones, twos = q.popleft()
            from_distance = distances[from_side][ones][twos]
            from_ways = ways[from_side][ones][twos]
            from_next_distance = from_distance + 1

            next_side = FROM_SIDE + TO_SIDE - from_side

            if from_side == FROM_SIDE:
                for delta_ones in range(ones + 1):
                    for delta_twos in range(twos + 1):
                        if delta_ones + delta_twos == 0:
                            continue
                        if delta_ones + 2 * delta_twos > limit:
                            continue

                        next_ones = ones - delta_ones
                        next_twos = twos - delta_twos

                        next_distance = distances[next_side][next_ones][next_twos]

                        if next_distance < from_next_distance:
                            continue

                        from_next_ways = (from_ways * c[ones][delta_ones] % MODULO * c[twos][delta_twos] % MODULO) % MODULO

                        if next_distance > from_next_distance:
                            distances[next_side][next_ones][next_twos] = from_next_distance
                            q.append((next_side, next_ones, next_twos))

                        if next_distance == from_next_distance:
                            ways[next_side][next_ones][next_twos] = (ways[next_side][next_ones][next_twos] + from_next_ways) % MODULO
            else:
                to_ones = ones_count - ones
                to_twos = twos_count - twos

                for delta_ones in range(to_ones + 1):
                    for delta_twos in range(to_twos + 1):
                        if delta_ones + delta_twos == 0:
                            continue
                        if delta_ones + 2 * delta_twos > limit:
                            continue

                        next_ones = ones + delta_ones
                        next_twos = twos + delta_twos

                        next_distance = distances[next_side][next_ones][next_twos]

                        if next_distance < from_next_distance:
                            continue

                        from_next_ways = (from_ways * c[to_ones][delta_ones] % MODULO * c[to_twos][delta_twos] % MODULO) % MODULO

                        if next_distance > from_next_distance:
                            distances[next_side][next_ones][next_twos] = from_next_distance
                            q.append((next_side, next_ones, next_twos))

                        if next_distance == from_next_distance:
                            ways[next_side][next_ones][next_twos] = (ways[next_side][next_ones][next_twos] + from_next_ways) % MODULO

        distance = distances[TO_SIDE][0][0]
        if INF == distance:
            return (-1, 0)
        else:
            return (distance, ways[TO_SIDE][0][0])

    @staticmethod
    def read_int():
        return int(sys.stdin.readline().strip())

    @staticmethod
    def read_int_array(size):
        return list(map(int, sys.stdin.readline().strip().split()))

    @staticmethod
    def main():
        c = C()
        if ONLINE_JUDGE:
            c.solve()
        else:
            while True:
                try:
                    c.solve()
                    print()
                except EOFError:
                    break

if __name__ == "__main__":
    C.main()
