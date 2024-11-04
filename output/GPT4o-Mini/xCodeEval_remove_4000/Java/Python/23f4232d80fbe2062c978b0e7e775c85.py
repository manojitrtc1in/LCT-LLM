import sys
from collections import defaultdict
from math import gcd

class IO:
    @staticmethod
    def read_int():
        return int(sys.stdin.readline().strip())

    @staticmethod
    def read_ints():
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
            quantity = IO.read_ints()
            base = IO.read_ints()
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
        return a // gcd(a, b) * b

class Division:
    def __init__(self, dividend, divider):
        self.first = dividend
        self.second = divider
        self.reduce()

    @staticmethod
    def create_division(dividend, divider):
        return Division(dividend, divider)

    def reduce(self):
        common_divisor = gcd(self.first, self.second)
        self.first //= common_divisor
        self.second //= common_divisor

    def add(self, number):
        lcm_value = Math.lcm(self.second, number.second)
        new_first = (lcm_value // self.second) * self.first + (lcm_value // number.second) * number.first
        return Division.create_division(new_first, lcm_value)

    def multiply(self, number):
        new_first = self.first * number.first
        new_second = self.second * number.second
        return Division.create_division(new_first, new_second)

class Pair:
    def __init__(self, obj, obj1):
        self.first = obj
        self.second = obj1

    @staticmethod
    def create_pair(element, element1):
        return Pair(element, element1)

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

    def read_graph(self, length, quantity):
        self.base = [[] for _ in range(length)]
        for _ in range(quantity):
            input_data = IO.read_ints()
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
                next_node = self.base[position][index]
                edge_weight = self.base[position][index + 1]
                if dist[position] + edge_weight < dist[next_node]:
                    dist[next_node] = dist[position] + edge_weight
                    self.ancestor[next_node] = position
                    queue.append((dist[next_node], next_node))
        return dist[stop] if dist[stop] != float('inf') else -1

if __name__ == "__main__":
    Main.main()
