import sys
import random
from collections import defaultdict
from itertools import islice

class Disjunction:
    @staticmethod
    def value(*args):
        return any(args)

def has_begin(obj):
    return hasattr(obj, '__iter__')

def is_container(obj):
    return has_begin(obj)

def is_one_of(value, *types):
    return any(isinstance(value, t) for t in types)

def is_sane_integer(value):
    return isinstance(value, int) and not is_one_of(value, bool, str, bytes)

def to_string(value):
    if isinstance(value, str):
        return f'"{value}"'
    elif isinstance(value, bool):
        return "true" if value else "false"
    elif isinstance(value, (int, float)):
        return str(value)
    elif isinstance(value, tuple):
        return f"({to_string(value[0])}, {to_string(value[1])})"
    elif is_container(value):
        return "{" + ", ".join(to_string(x) for x in value) + "}"
    else:
        return str(value)

def id26(s):
    return s.split(',')

def debug_out(args, idx=0, line_num=None):
    if idx >= len(args):
        return
    value = to_string(args[idx])
    if line_num is not None:
        print(f"Line({line_num}) {args[idx]} = {value}")
    else:
        print(args[idx])
    debug_out(args, idx + 1, line_num)

class IntegerIterator:
    def __init__(self, value):
        self.value = value

    def __iter__(self):
        return self

    def __next__(self):
        current = self.value
        self.value += 1
        return current

    def __eq__(self, other):
        return self.value == other.value

    def __ne__(self, other):
        return not self.__eq__(other)

class IntegerRange:
    def __init__(self, start, end):
        self.start = start
        self.end = end

    def __iter__(self):
        return IntegerIterator(self.start)

    def __len__(self):
        return self.end - self.start

def range_func(to):
    return IntegerRange(0, to)

def inclusive_range_func(to):
    return IntegerRange(0, to + 1)

def downrange(from_, to=None):
    if to is None:
        return reversed(range_func(from_))
    return reversed(range_func(to, from_))

def sort(range_):
    range_[:] = sorted(range_)

def unique(range_):
    range_[:] = list(dict.fromkeys(range_))

def dedup(range_):
    sort(range_)
    unique(range_)

def min_element(range_):
    return min(range_)

def max_element(range_):
    return max(range_)

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a // gcd(a, b) * b

class Graph:
    def __init__(self, vertices_count):
        self.vertices_count = vertices_count
        self.edges = defaultdict(list)

    def add_edge(self, from_, to):
        self.edges[from_].append(to)

    def get_edges(self, vertex):
        return self.edges[vertex]

class DirectedGraph(Graph):
    def __init__(self, vertices_count):
        super().__init__(vertices_count)

    def is_acyclic(self):
        visited = [False] * self.vertices_count
        rec_stack = [False] * self.vertices_count

        def is_cyclic(v):
            visited[v] = True
            rec_stack[v] = True
            for neighbor in self.get_edges(v):
                if not visited[neighbor]:
                    if is_cyclic(neighbor):
                        return True
                elif rec_stack[neighbor]:
                    return True
            rec_stack[v] = False
            return False

        for node in range(self.vertices_count):
            if not visited[node]:
                if is_cyclic(node):
                    return False
        return True

class Permutation(list):
    def __init__(self, size):
        super().__init__(range(size))

    def multiply(self, other):
        return Permutation(self[other[i]] for i in range(len(self)))

    def pow(self, exp):
        result = Permutation(len(self))
        a = self[:]
        while exp:
            if exp % 2:
                result = result.multiply(a)
            a = a.multiply(a)
            exp //= 2
        return result

class Id15:
    def solve(self, s):
        n = len(s)
        for length in range(2, 1112):
            p = Permutation(length)
            tmp = s[::-1]
            if self.try_recover(0, length, tmp, p) and not tmp:
                ans = [0] * length
                for i in range(length):
                    ans[p[i]] = i
                print(length)
                print(" ".join(str(x + 1) for x in ans))
                return

    def try_recover(self, l, r, s, p):
        if r - l <= 1:
            return True
        mid = (l + r) // 2
        if not (self.try_recover(l, mid, s, p) and self.try_recover(mid, r, s, p)):
            return False
        left = [p[i] for i in range(mid - 1, l - 1, -1)]
        right = [p[i] for i in range(r - 1, mid - 1, -1)]
        pos = l
        while left and right:
            if not s:
                return False
            ch = s.pop()
            if ch == '1':
                p[pos] = right.pop()
            else:
                p[pos] = left.pop()
            pos += 1
        while left:
            p[pos] = left.pop()
            pos += 1
        while right:
            p[pos] = right.pop()
            pos += 1
        return True

def main():
    solver = Id15()
    s = sys.stdin.readline().strip()
    solver.solve(s)

if __name__ == "__main__":
    main()
