import sys
from collections import defaultdict
import math
import heapq

class IO:
    @staticmethod
    def read_int():
        return int(sys.stdin.readline().strip())

    @staticmethod
    def read_int_array():
        return list(map(int, sys.stdin.readline().strip().split()))

    @staticmethod
    def write_int(value):
        sys.stdout.write(f"{value}\n")

class Main:
    @staticmethod
    def main():
        i1 = IO.read_int()
        for _ in range(i1):
            count_value = defaultdict(int)
            quantity = IO.read_int_array()
            base = IO.read_int_array()
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
    def gcd(a, b):
        while b:
            a, b = b, a % b
        return a

    @staticmethod
    def lcm(a, b):
        return a // Math.gcd(a, b) * b

class Division:
    def __init__(self, dividend, divider):
        self.first = dividend
        self.second = divider
        self.reduce()

    @staticmethod
    def create_division(dividend, divider):
        return Division(dividend, divider)

    def reduce(self):
        gcd_value = Math.gcd(self.first, self.second)
        self.first //= gcd_value
        self.second //= gcd_value

    def add(self, number):
        lcm_value = Math.lcm(self.second, number.second)
        new_first = (lcm_value // self.second) * self.first + (lcm_value // number.second) * number.first
        return Division.create_division(new_first, lcm_value)

    def multiply(self, number):
        new_first = self.first * number.first
        new_second = self.second * number.second
        return Division.create_division(new_first, new_second)

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

    def id6(self, length, quantity, read_console, value):
        self.base = [[] for _ in range(length)]
        for i in range(quantity):
            input_data = value[i] if not read_console else IO.read_int_array()
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
            current_dist, position = heapq.heappop(queue)
            if current_dist > dist[position]:
                continue
            for index in range(0, len(self.base[position]), 2):
                next_pos = self.base[position][index]
                weight = self.base[position][index + 1]
                if dist[position] + weight < dist[next_pos] and not self.used[next_pos]:
                    dist[next_pos] = dist[position] + weight
                    self.ancestor[next_pos] = position
                    heapq.heappush(queue, (dist[next_pos], next_pos))
            self.used[position] = True
        return -1 if dist[stop] == float('inf') else dist[stop]

if __name__ == "__main__":
    Main.main()
