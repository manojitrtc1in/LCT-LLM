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

    def add_without_return(self, number):
        self.add(number, 0)

    def add(self, number, function):
        if isinstance(self.dividend, int) and isinstance(number.dividend, int):
            lcm = math.lcm(self.divider, number.divider)
            if function == 0:
                self.dividend = (lcm // self.divider) * self.dividend + (lcm // number.divider) * number.dividend
                self.divider = lcm
                self.reduce()
                return None
            result = Fraction((lcm // self.divider) * self.dividend + (lcm // number.divider) * number.dividend, lcm)
            result.reduce()
            return result
        elif isinstance(self.dividend, float) and isinstance(number.dividend, float):
            lcm = math.lcm(self.divider, number.divider)
            if function == 0:
                self.dividend = (lcm / self.divider) * self.dividend + (lcm / number.divider) * number.dividend
                self.divider = lcm
                self.reduce()
                return None
            result = Fraction((lcm / self.divider) * self.dividend + (lcm / number.divider) * number.dividend, lcm)
            result.reduce()
            return result

    def add_with_return(self, number):
        return self.add(number, 1)

    def multiply_without_return(self, number):
        self.multiply(number, 0)

    def multiply(self, number, function):
        if isinstance(self.dividend, int) and isinstance(number.dividend, int):
            first = self.dividend * number.dividend
            second = self.divider * number.divider
            if function == 0:
                self.dividend = first
                self.divider = second
                self.reduce()
                return None
            result = Fraction(first, second)
            result.reduce()
            return result
        elif isinstance(self.dividend, float) and isinstance(number.dividend, float):
            first = self.dividend * number.dividend
            second = self.divider * number.divider
            if function == 0:
                self.dividend = first
                self.divider = second
                self.reduce()
                return None
            result = Fraction(first, second)
            result.reduce()
            return result


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
        self.base = None
        self.used = None
        self.quantity = None
        self.ancestor = None

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
        ancestor = [start] * size
        dist[start] = 0

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
                    ancestor[next_position] = position
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
        self.segment_array = [0] * (len(start_base) * 2)
        self.function = function
        self.in_depth(start_base, 1, 0, len(start_base) - 1)

    def in_depth(self, base, position, low, high):
        if low == high:
            self.segment_array[position] = base[low]
        else:
            mid = (low + high) // 2
            self.in_depth(base, position * 2, low, mid)
            self.in_depth(base, position * 2 + 1, mid + 1, high)
            self.segment_array[position] = self.function(self.segment_array[position * 2], self.segment_array[position * 2 + 1])

    def get_value(self, left, right, neutral):
        return self.find_value(1, 0, len(self.segment_array) // 2 - 1, left, right, neutral)

    def find_value(self, position, low, high, left, right, neutral):
        if left > right:
            return neutral
        if left == low and right == high:
            return self.segment_array[position]
        mid = (low + high) // 2
        return self.function(self.find_value(position * 2, low, mid, left, min(right, mid), neutral),
                             self.find_value(position * 2 + 1, mid + 1, high, max(left, mid + 1), right, neutral))

    def replace_value(self, index, value):
        self.update(1, 0, len(self.segment_array) // 2 - 1, index, value)

    def update(self, position, low, high, index, value):
        if low == high:
            self.segment_array[position] = value
        else:
            mid = (low + high) // 2
            if index <= mid:
                self.update(position * 2, low, mid, index, value)
            else:
                self.update(position * 2 + 1, mid + 1, high, index, value)
            self.segment_array[position] = self.function(self.segment_array[position * 2], self.segment_array[position * 2 + 1])


class SegmentTreeGeneric:
    def __init__(self, start_base, neutral, function):
        self.segment_array = [0] * (len(start_base) * 2)
        self.function = function
        self.in_depth(start_base, 1, 0, len(start_base) - 1)

    def in_depth(self, base, position, low, high):
        if low == high:
            self.segment_array[position] = base[low]
        else:
            mid = (low + high) // 2
            self.in_depth(base, position * 2, low, mid)
            self.in_depth(base, position * 2 + 1, mid + 1, high)
            self.segment_array[position] = self.function(self.segment_array[position * 2], self.segment_array[position * 2 + 1])

    def get_value(self, left, right, neutral):
        return self.find_value(1, 0, len(self.segment_array) // 2 - 1, left, right, neutral)

    def find_value(self, position, low, high, left, right, neutral):
        if left > right:
            return neutral
        if left == low and right == high:
            return self.segment_array[position]
        mid = (low + high) // 2
        return self.function(self.find_value(position * 2, low, mid, left, min(right, mid), neutral),
                             self.find_value(position * 2 + 1, mid + 1, high, max(left, mid + 1), right, neutral))

    def replace_value(self, index, value):
        self.update(1, 0, len(self.segment_array) // 2 - 1, index, value)

    def update(self, position, low, high, index, value):
        if low == high:
            self.segment_array[position] = value
        else:
            mid = (low + high) // 2
            if index <= mid:
                self.update(position * 2, low, mid, index, value)
            else:
                self.update(position * 2 + 1, mid + 1, high, index, value)
            self.segment_array[position] = self.function(self.segment_array[position * 2], self.segment_array[position * 2 + 1])


def fast_sort(array, shell_heap_merge_my_insertion_sort):
    sort(array, shell_heap_merge_my_insertion_sort, len(array))
    return array


def sort_clone(array, shell_heap_merge_my_insertion_sort):
    base = array.copy()
    sort(base, shell_heap_merge_my_insertion_sort, len(array))
    return base


def sort(array, shell_heap_merge_my_insertion_sort, length):
    if shell_heap_merge_my_insertion_sort < 0 or shell_heap_merge_my_insertion_sort > 4:
        import random
        shell_heap_merge_my_insertion_sort = random.randint(0, 3)
    if shell_heap_merge_my_insertion_sort == 0:
        shell_sort(array)
    elif shell_heap_merge_my_insertion_sort == 1:
        heap_sort(array)
    elif shell_heap_merge_my_insertion_sort == 2:
        merge_sort(array, 0, length - 1)
    elif shell_heap_merge_my_insertion_sort == 3:
        straight_merge_sort(array, length)
    elif shell_heap_merge_my_insertion_sort == 4:
        insertion_sort(array)


def straight_merge_sort(array, size):
    if size == 0:
        return
    length = (size >> 1) + ((size % 2) == 0)
    zero_buffer = [[None, None] for _ in range(length + length % 2)]
    first_buffer = []
    for index in range(length):
        array_index = index << 1
        next_array_index = (index << 1) + 1
        if next_array_index < size:
            if array[array_index] > array[next_array_index]:
                zero_buffer[index][0] = array[next_array_index]
                zero_buffer[index][1] = array[array_index]
            else:
                zero_buffer[index][0] = array[array_index]
                zero_buffer[index][1] = array[next_array_index]
        else:
            zero_buffer[index][0] = array[array_index]
    position = False
    pointer0, pointer, pointer1, number = 0, 0, 0, 4
    new_pointer, count = 0, (number >> 1) - 1
    new_buffer, old_buffer = [], []
    length = (size >> 2) + (size % 4 != 0)
    while True:
        pointer0 = 0
        if not position:
            first_buffer = [[None] * number for _ in range(length + length % 2)]
            new_buffer = first_buffer
            old_buffer = zero_buffer
        else:
            zero_buffer = [[None] * number for _ in range(length + length % 2)]
            new_buffer = zero_buffer
            old_buffer = first_buffer
        for i in range(length):
            pointer = 0
            pointer1 = 0
            new_pointer = pointer0 + 1
            if length == 1:
                for g in range(size):
                    if pointer > count or old_buffer[pointer0][pointer] is None:
                        array[g] = old_buffer[new_pointer][pointer1]
                        pointer1 += 1
                    elif pointer1 > count or old_buffer[new_pointer][pointer1] is None:
                        if old_buffer[pointer0][pointer] is None:
                            continue
                        array[g] = old_buffer[pointer0][pointer]
                        pointer += 1
                    elif old_buffer[pointer0][pointer] >= old_buffer[new_pointer][pointer1]:
                        array[g] = old_buffer[new_pointer][pointer1]
                        pointer1 += 1
                    else:
                        array[g] = old_buffer[pointer0][pointer]
                        pointer += 1
                return
            for g in range(number):
                if pointer > count or old_buffer[pointer0][pointer] is None:
                    if old_buffer[new_pointer][pointer1] is None:
                        continue
                    new_buffer[i][g] = old_buffer[new_pointer][pointer1]
                    pointer1 += 1
                elif pointer1 > count or old_buffer[new_pointer][pointer1] is None:
                    if old_buffer[pointer0][pointer] is None:
                        continue
                    new_buffer[i][g] = old_buffer[pointer0][pointer]
                    pointer += 1
                elif old_buffer[pointer0][pointer] >= old_buffer[new_pointer][pointer1]:
                    new_buffer[i][g] = old_buffer[new_pointer][pointer1]
                    pointer1 += 1
                else:
                    new_buffer[i][g] = old_buffer[pointer0][pointer]
                    pointer += 1
            pointer0 += 2
        position = not position
        length = (length >> 1) + (length % 2)
        number <<= 1


def shell_sort(array):
    gap = len(array) // 2
    while gap > 0:
        for i in range(gap, len(array)):
            temp = array[i]
            j = i
            while j >= gap and array[j - gap] > temp:
                array[j] = array[j - gap]
                j -= gap
            array[j] = temp
        gap //= 2


def heap_sort(array):
    def shift_down(array, i, n):
        child = left_child(i)
        tmp = array[i]
        while child < n:
            if child != n - 1 and array[child] < array[child + 1]:
                child += 1
            if tmp < array[child]:
                array[i] = array[child]
            else:
                break
            i = child
            child = left_child(i)
        array[i] = tmp

    def left_child(i):
        return (i << 1) + 1

    for i in range(len(array) // 2 - 1, -1, -1):
        shift_down(array, i, len(array))
    for i in range(len(array) - 1, 0, -1):
        array[0], array[i] = array[i], array[0]
        shift_down(array, 0, i)


def merge_sort(array, low, high):
    if low < high:
        mid = (low + high) // 2
        merge_sort(array, low, mid)
        merge_sort(array, mid + 1, high)
        merge(array, low, mid, high)


def merge(array, low, mid, high):
    n = high - low + 1
    temp = [0] * n
    i = low
    j = mid + 1
    k = 0
    while i <= mid or j <= high:
        if i > mid:
            temp[k] = array[j]
            j += 1
        elif j > high:
            temp[k] = array[i]
            i += 1
        elif array[i] < array[j]:
            temp[k] = array[i]
            i += 1
        else:
            temp[k] = array[j]
            j += 1
        k += 1
    for j in range(n):
        array[low + j] = temp[j]


def insertion_sort(elements):
    for i in range(1, len(elements)):
        key = elements[i]
        j = i - 1
        while j >= 0 and key < elements[j]:
            elements[j + 1] = elements[j]
            j -= 1
        elements[j + 1] = key


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
