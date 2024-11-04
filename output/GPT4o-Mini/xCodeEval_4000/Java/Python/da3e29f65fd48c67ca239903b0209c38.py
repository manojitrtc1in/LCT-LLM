import sys
from math import gcd
from functools import reduce
from collections import deque

class IO:
    @staticmethod
    def read_int():
        return int(sys.stdin.readline().strip())

    @staticmethod
    def read_array_int(split):
        return list(map(int, sys.stdin.readline().strip().split(split)))

class Main:
    @staticmethod
    def main():
        g = IO.read_int()
        sh = IO.read_int()
        j = IO.read_int()
        p = IO.read_int()
        price_first = IO.read_int()
        price_second = IO.read_int()
        answer = 0
        
        if price_first <= price_second:
            answer = min(sh, j, p)
            p -= answer
            answer *= price_second
            answer += min(p, g) * price_first
        else:
            answer = min(g, p)
            p -= answer
            answer *= price_first
            answer += min(sh, j, p) * price_second
        
        print(answer)

class Math:
    remains = 0x989687

    @staticmethod
    def gcd(a, b):
        if b == 0:
            return a
        return Math.gcd(b, a % b)

    @staticmethod
    def lcm(a, b):
        return a // Math.gcd(a, b) * b

    @staticmethod
    def log(value, base):
        from math import log
        return log(value) / log(base)

    @staticmethod
    def factorial(number):
        if number < 0:
            return 0
        return Math.solve_factorial(number)

    @staticmethod
    def solve_factorial(number):
        if number > 0:
            return Math.solve_factorial(number - 1) * number
        return 1

class Int:
    def __init__(self, value):
        self.value = value

    def __lt__(self, other):
        return self.value < other

    def __eq__(self, other):
        return self.value == other

    def __hash__(self):
        return hash(self.value)

class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

    @staticmethod
    def create_pair(element, element1):
        return Pair(element, element1)

    def get_first_element(self):
        return self.first

    def get_second_element(self):
        return self.second

    def set_first(self, element):
        self.first = element

    def set_second(self, element):
        self.second = element

    def __eq__(self, other):
        return isinstance(other, Pair) and self.first == other.first and self.second == other.second

    def __hash__(self):
        return hash((self.first, self.second))

class Graph:
    def __init__(self):
        self.base = []
        self.used = []
        self.quantity = 0
        self.ancestor = []

    def get_base(self):
        return self.base.copy()

    def get_used(self):
        return self.used.copy()

    def get_quantity(self):
        return self.quantity

    def get_ancestor(self):
        return self.ancestor.copy()

    def set_base(self, base):
        self.base = base

    def start(self, length):
        self.used = [False] * length
        self.ancestor = [-1] * length
        self.quantity = 0

    def edges_matrix_to_default(self, length, quantity, read_console, value):
        self.base = [[] for _ in range(length)]
        input_base = [[] for _ in range(length)]
        
        for i in range(quantity):
            input = value[i] if not read_console else IO.read_array_int(" ")
            input_base[input[0] - 1].append(input[1] - 1)
            input_base[input[1] - 1].append(input[0] - 1)

        for i in range(length):
            self.base[i] = input_base[i]

        self.start(length)

    def dfs(self, position):
        self.used[position] = True
        self.quantity += 1
        for next in self.base[position]:
            if not self.used[next]:
                self.ancestor[next] = position
                self.dfs(next)

    def dijkstra(self, start, stop, size):
        start -= 1
        stop -= 1
        dist = [float('inf')] * size
        dist[start] = 0
        self.ancestor[start] = start

        queue = deque([(start, 0)])
        while queue:
            position, d = queue.popleft()
            if d > dist[position]:
                continue
            for index in range(0, len(self.base[position]), 2):
                if dist[position] + self.base[position][index + 1] < dist[self.base[position][index]]:
                    dist[self.base[position][index]] = dist[position] + self.base[position][index + 1]
                    self.ancestor[self.base[position][index]] = position
                    queue.append((self.base[position][index], dist[self.base[position][index]]))

        return dist[stop] if dist[stop] != float('inf') else -1

if __name__ == "__main__":
    Main.main()
