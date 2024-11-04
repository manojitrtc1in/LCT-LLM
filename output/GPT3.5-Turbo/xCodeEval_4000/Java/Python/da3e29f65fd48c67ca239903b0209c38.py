class math:
    remains = 0x989687

    @staticmethod
    def gcd(a, b):
        if b == 0:
            return a
        return math.gcd(b, a % b)

    @staticmethod
    def lcm(a, b):
        return a // math.gcd(a, b) * b

    @staticmethod
    def log(value, base):
        return math.log(value) / math.log(base)

    @staticmethod
    def factorial(number):
        if number < 0:
            return 0
        return math.solve_factorial(number)

    @staticmethod
    def solve_factorial(number):
        if number > 0:
            return math.solve_factorial(number - 1) * number
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


class Fraction:
    def __init__(self, dividend, divider):
        self.dividend = dividend
        self.divider = divider
        self.reduce()

    def reduce(self):
        if isinstance(self.dividend, int) and isinstance(self.divider, int):
            gcd = math.gcd(self.dividend, self.divider)
            self.dividend //= gcd
            self.divider //= gcd
        elif isinstance(self.dividend, float) and isinstance(self.divider, float):
            gcd = math.gcd(self.dividend, self.divider)
            self.dividend /= gcd
            self.divider /= gcd

    def add(self, number):
        lcm = math.lcm(self.divider, number.divider)
        self.dividend = (lcm // self.divider) * self.dividend + (lcm // number.divider) * number.dividend
        self.divider = lcm
        self.reduce()

    def multiply(self, number):
        self.dividend *= number.dividend
        self.divider *= number.divider
        self.reduce()


class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

    def __eq__(self, other):
        if not isinstance(other, Pair):
            return False
        return self.first == other.first and self.second == other.second

    def __hash__(self):
        return hash((self.first, self.second))

    def __str__(self):
        return f"({self.first}, {self.second})"


class Graph:
    def __init__(self):
        self.base = []
        self.used = []
        self.quantity = 0
        self.ancestor = []

    def set_base(self, base):
        self.base = base

    def get_base(self):
        return self.base.copy()

    def get_used(self):
        return self.used.copy()

    def get_quantity(self):
        return self.quantity

    def get_ancestor(self):
        return self.ancestor.copy()

    def start(self, length):
        self.used = [False] * length
        self.ancestor = [-1] * length
        self.quantity = 0

    def edges_matrix_to_default(self, length, quantity, value):
        input_base = [[] for _ in range(length)]
        for i in range(quantity):
            input = value[i]
            input_base[input[0] - 1].append(input[1] - 1)
            input_base[input[1] - 1].append(input[0] - 1)
        self.base = [list(map(int, x)) for x in input_base]
        self.start(length)

    def adjacency_matrix_to_default(self, length, not_value, value):
        self.base = []
        for i in range(length):
            input_array = value[i]
            buffer = []
            for index in range(length):
                if i != index and input_array[index] != not_value:
                    buffer.append(index)
            self.base.append(buffer)
        self.start(length)

    def dfs(self, position):
        self.used[position] = True
        self.quantity += 1
        for next_position in self.base[position]:
            if not self.used[next_position]:
                self.ancestor[next_position] = position
                self.dfs(next_position)

    def dijkstra(self, start, stop, size):
        start -= 1
        stop -= 1
        dist = [float('inf')] * size
        dist[start] = 0
        self.ancestor = [start] * size

        queue = [(start, 0)]
        while queue:
            position, distance = queue.pop(0)
            if distance > dist[position]:
                continue
            for index in range(0, len(self.base[position]), 2):
                next_position = self.base[position][index]
                weight = self.base[position][index + 1]
                if dist[position] + weight < dist[next_position] and not self.used[next_position]:
                    dist[next_position] = dist[position] + weight
                    self.ancestor[next_position] = position
                    queue.append((next_position, dist[next_position]))
            self.used[position] = True
        return dist[stop] if dist[stop] != float('inf') else -1

    @staticmethod
    def solve_floyd_warshall(base, length, not_value):
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

    @staticmethod
    def solve_kruskal(edges_matrix, count_vertex, index_sort):
        answer = []
        sum = 0
        edges_matrix.sort(key=lambda x: x[index_sort])
        dsu = SystemOfDisjointSets(count_vertex)
        for i in range(count_vertex):
            dsu.make_set(i)
        for value in edges_matrix:
            if dsu.merge_sets(value[0], value[1]):
                sum += value[index_sort]
                answer.append(Pair(value[0], value[1]))
        if len(answer) < count_vertex - 1:
            return None, None
        return sum, answer


class SystemOfDisjointSets:
    def __init__(self, size):
        self.rank = [0] * size
        self.ancestor = [0] * size

    def make_set(self, value):
        self.ancestor[value] = value
        self.rank[value] = 0

    def find_set(self, value):
        if value != self.ancestor[value]:
            self.ancestor[value] = self.find_set(self.ancestor[value])
        return self.ancestor[value]

    def merge_sets(self, first, second):
        first = self.find_set(first)
        second = self.find_set(second)
        if first != second:
            if self.rank[first] < self.rank[second]:
                first, second = second, first
            self.ancestor[second] = first
            if self.rank[first] == self.rank[second]:
                self.rank[first] += 1
            return True
        return False


class SegmentTree:
    def __init__(self, start_base, neutral, function):
        self.function = function
        length = len(start_base)
        base = start_base.copy()
        if length & (length - 1) != 0:
            pow = 0
            while length > 0:
                length >>= 1
                pow += 1
            pow -= 1
            base.extend([neutral] * (2 << pow))
        self.segment_array = [neutral] * (len(base) << 1)
        self.in_depth(base, 1, 0, len(base) - 1)

    def in_depth(self, base, position, low, high):
        if low == high:
            self.segment_array[position] = base[low]
        else:
            mid = (low + high) >> 1
            self.in_depth(base, position << 1, low, mid)
            self.in_depth(base, (position << 1) + 1, mid + 1, high)
            self.segment_array[position] = self.function(self.segment_array[position << 1], self.segment_array[(position << 1) + 1])

    def get_value(self, left, right, neutral):
        return self.find_value(1, 0, (len(self.segment_array) >> 1) - 1, left, right, neutral)

    def find_value(self, position, low, high, left, right, neutral):
        if left > right:
            return neutral
        if left == low and right == high:
            return self.segment_array[position]
        mid = (low + high) >> 1
        return self.function(self.find_value(position << 1, low, mid, left, min(right, mid), neutral),
                             self.find_value((position << 1) + 1, mid + 1, high, max(left, mid + 1), right, neutral))

    def replace_value(self, index, value):
        self.update(1, 0, (len(self.segment_array) >> 1) - 1, index, value)

    def update(self, position, low, high, index, value):
        if low == high:
            self.segment_array[position] = value
        else:
            mid = (low + high) >> 1
            if index <= mid:
                self.update(position << 1, low, mid, index, value)
            else:
                self.update((position << 1) + 1, mid + 1, high, index, value)
            self.segment_array[position] = self.function(self.segment_array[position << 1], self.segment_array[(position << 1) + 1])


class SegmentTreeGeneric:
    def __init__(self, start_base, neutral, function):
        self.function = function
        length = len(start_base)
        base = start_base.copy()
        if length & (length - 1) != 0:
            pow = 0
            while length > 0:
                length >>= 1
                pow += 1
            pow -= 1
            base.extend([neutral] * (2 << pow))
        self.segment_array = [neutral] * (len(base) << 1)
        self.in_depth(base, 1, 0, len(base) - 1)

    def in_depth(self, base, position, low, high):
        if low == high:
            self.segment_array[position] = base[low]
        else:
            mid = (low + high) >> 1
            self.in_depth(base, position << 1, low, mid)
            self.in_depth(base, (position << 1) + 1, mid + 1, high)
            self.segment_array[position] = self.function(self.segment_array[position << 1], self.segment_array[(position << 1) + 1])

    def get_value(self, left, right, neutral):
        return self.find_value(1, 0, (len(self.segment_array) >> 1) - 1, left, right, neutral)

    def find_value(self, position, low, high, left, right, neutral):
        if left > right:
            return neutral
        if left == low and right == high:
            return self.segment_array[position]
        mid = (low + high) >> 1
        return self.function(self.find_value(position << 1, low, mid, left, min(right, mid), neutral),
                             self.find_value((position << 1) + 1, mid + 1, high, max(left, mid + 1), right, neutral))

    def replace_value(self, index, value):
        self.update(1, 0, (len(self.segment_array) >> 1) - 1, index, value)

    def update(self, position, low, high, index, value):
        if low == high:
            self.segment_array[position] = value
        else:
            mid = (low + high) >> 1
            if index <= mid:
                self.update(position << 1, low, mid, index, value)
            else:
                self.update((position << 1) + 1, mid + 1, high, index, value)
            self.segment_array[position] = self.function(self.segment_array[position << 1], self.segment_array[(position << 1) + 1])
