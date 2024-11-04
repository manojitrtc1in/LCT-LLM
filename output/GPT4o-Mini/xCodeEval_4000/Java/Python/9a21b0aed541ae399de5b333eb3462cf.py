import sys
from collections import defaultdict
from math import gcd

class IO:
    @staticmethod
    def read_int():
        return int(sys.stdin.readline().strip())

    @staticmethod
    def read_array_int(split):
        return list(map(int, sys.stdin.readline().strip().split(split)))

    @staticmethod
    def write_int(number, end="\n"):
        sys.stdout.write(f"{number}{end}")

class Main:
    @staticmethod
    def main():
        i1 = IO.read_int()
        for _ in range(i1):
            count_value = defaultdict(int)
            quantity = IO.read_array_int(" ")
            base = IO.read_array_int(" ")
            for i in range(quantity[2]):
                count_value[base[i]] += 1
            min_count = len(count_value)
            for i in range(quantity[2], quantity[0]):
                count_value[base[i - quantity[2]]] -= 1
                if count_value[base[i - quantity[2]]] == 0:
                    del count_value[base[i - quantity[2]]]
                count_value[base[i]] += 1
                min_count = min(min_count, len(count_value))
            IO.write_int(min_count)

class Math:
    @staticmethod
    def lcm(a, b):
        return abs(a * b) // gcd(a, b)

class Division:
    def __init__(self, dividend, divider):
        self.first = dividend
        self.second = divider
        self.reduce()

    @staticmethod
    def create_division(dividend, divider):
        return Division(dividend, divider)

    def reduce(self):
        g = gcd(self.first, self.second)
        self.first //= g
        self.second //= g

    def add_without_return(self, number):
        self.add(number, 0)

    def add(self, number, function):
        if isinstance(self.first, int) and isinstance(number.first, int):
            lcm_value = Math.lcm(self.second, number.second)
            if function == 0:
                self.first = (lcm_value // self.second) * self.first + (lcm_value // number.second) * number.first
                self.second = lcm_value
                self.reduce()
                return None
            result = Division.create_division((lcm_value // self.second) * self.first + (lcm_value // number.second) * number.first, lcm_value)
            result.reduce()
            return result
        else:
            raise NotImplementedError()

    def multiply_without_return(self, number):
        self.multiply(number, 0)

    def multiply_with_return(self, number):
        return self.multiply(number, 1)

    def multiply(self, number, function):
        if isinstance(self.first, int) and isinstance(number.first, int):
            first = self.first * number.first
            second = self.second * number.second
            if function == 0:
                self.first = first
                self.second = second
                self.reduce()
                return None
            result = Division.create_division(first, second)
            result.reduce()
            return result
        else:
            raise NotImplementedError()

class Graph:
    def __init__(self):
        self.base = []
        self.used = []
        self.quantity = 0
        self.ancestor = []

    def start(self, length):
        self.used = [False] * length
        self.ancestor = [-1] * length
        self.quantity = 0

    def rib_matrix_to_default(self, length, quantity, read_console, value):
        self.base = [[] for _ in range(length)]
        for i in range(quantity):
            input_data = IO.read_array_int(" ") if read_console else value[i]
            self.base[input_data[0] - 1].append(input_data[1] - 1)
            self.base[input_data[1] - 1].append(input_data[0] - 1)
        self.start(length)

    def dfs(self, position):
        self.used[position] = True
        self.quantity += 1
        for next in self.base[position]:
            if not self.used[next]:
                self.ancestor[next] = position
                self.dfs(next)
            elif next != self.ancestor[position]:
                raise Exception()

    def dijkstra(self, start, stop, size):
        start -= 1
        stop -= 1
        dist = [float('inf')] * size
        dist[start] = 0
        self.ancestor[start] = start
        queue = [(0, start)]
        while queue:
            current_dist, position = queue.pop(0)
            if current_dist > dist[position]:
                continue
            for index in range(0, len(self.base[position]), 2):
                next_pos = self.base[position][index]
                if dist[position] + self.base[position][index + 1] < dist[next_pos]:
                    dist[next_pos] = dist[position] + self.base[position][index + 1]
                    self.ancestor[next_pos] = position
                    queue.append((dist[next_pos], next_pos))
        return dist[stop] if dist[stop] != float('inf') else -1

    @staticmethod
    def floyd_warshall(base, length, not_value):
        for k in range(length):
            for i in range(length):
                for j in range(length):
                    if base[i][k] == not_value or base[k][j] == not_value:
                        continue
                    total = base[i][k] + base[k][j]
                    if base[i][j] != not_value:
                        base[i][j] = min(base[i][j], total)
                    else:
                        base[i][j] = total
        for index in range(length):
            if base[index][index] != 0:
                return False
        return True

if __name__ == "__main__":
    Main.main()
