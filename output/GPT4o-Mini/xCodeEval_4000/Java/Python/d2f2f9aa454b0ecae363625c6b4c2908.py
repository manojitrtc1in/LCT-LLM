import sys
from collections import defaultdict
from math import gcd
from typing import List, Tuple

class IO:
    @staticmethod
    def read_int() -> int:
        return int(sys.stdin.readline().strip())

    @staticmethod
    def read_array_int(split: str) -> List[int]:
        return list(map(int, sys.stdin.readline().strip().split(split)))

    @staticmethod
    def write_int(number: int, end: str = "\n"):
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
    def lcm(a: int, b: int) -> int:
        return a // gcd(a, b) * b

class Division:
    def __init__(self, dividend: float, divider: float):
        self.first = dividend
        self.second = divider
        self.reduce()

    @staticmethod
    def create_division(dividend: float, divider: float):
        return Division(dividend, divider)

    def reduce(self):
        g = gcd(int(self.first), int(self.second))
        self.first //= g
        self.second //= g

    def add_without_return(self, number):
        self.add(number, 0)

    def add(self, number, function):
        if isinstance(self.first, int) and isinstance(number.first, int):
            lcm_value = Math.lcm(int(self.second), int(number.second))
            if function == 0:
                self.first = (lcm_value // int(self.second)) * int(self.first) + (lcm_value // int(number.second)) * int(number.first)
                self.second = lcm_value
                self.reduce()
                return None
            return Division((lcm_value // int(self.second)) * int(self.first) + (lcm_value // int(number.second)) * int(number.first), lcm_value)

    def multiply_without_return(self, number):
        self.multiply(number, 0)

    def multiply_with_return(self, number):
        return self.multiply(number, 1)

    def multiply(self, number, function):
        first = self.first * number.first
        second = self.second * number.second
        if function == 0:
            self.first = first
            self.second = second
            self.reduce()
            return None
        return Division(first, second)

class Graph:
    def __init__(self):
        self.base = []
        self.used = []
        self.quantity = 0
        self.ancestor = []

    def start(self, length: int):
        self.used = [False] * length
        self.ancestor = [-1] * length
        self.quantity = 0

    def rib_matrix_to_default(self, length: int, quantity: int, read_console: bool, value: List[List[int]]):
        self.base = [[] for _ in range(length)]
        for i in range(quantity):
            input_data = IO.read_array_int(" ") if read_console else value[i]
            self.base[input_data[0] - 1].append(input_data[1] - 1)
            self.base[input_data[1] - 1].append(input_data[0] - 1)
        self.start(length)

    def dfs(self, position: int):
        self.used[position] = True
        self.quantity += 1
        for next in self.base[position]:
            if not self.used[next]:
                self.ancestor[next] = position
                self.dfs(next)
            elif next != self.ancestor[position]:
                raise Exception()

    def dijkstra(self, start: int, stop: int, size: int) -> int:
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

if __name__ == "__main__":
    Main.main()
