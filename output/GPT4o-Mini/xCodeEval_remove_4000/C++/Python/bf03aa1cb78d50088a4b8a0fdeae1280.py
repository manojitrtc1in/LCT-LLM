import sys
import random
from collections import defaultdict
from itertools import islice

class Disjunction:
    @staticmethod
    def value(*args):
        return any(args)

class Container:
    @staticmethod
    def has_begin(container):
        return hasattr(container, '__iter__')

class IsContainer:
    @staticmethod
    def value(container):
        return Container.has_begin(container)

class IsOneOf:
    @staticmethod
    def value(target, *types):
        return any(isinstance(target, t) for t in types)

class IsSaneInteger:
    @staticmethod
    def value(value):
        return isinstance(value, int) and not IsOneOf.value(value, bool, bytes)

def to_string(value):
    if isinstance(value, str):
        return f'"{value}"'
    elif isinstance(value, bool):
        return str(value).lower()
    elif isinstance(value, (int, float)):
        return str(value)
    elif isinstance(value, tuple):
        return f"({to_string(value[0])}, {to_string(value[1])})"
    elif IsContainer.value(value):
        return "{" + ", ".join(to_string(x) for x in value) + "}"
    else:
        return str(value)

def id28(s):
    return s.split(',')

def debug_out(args, idx=0, line_num=0, *values):
    if idx >= len(args):
        return
    value = to_string(values[idx])
    if args[idx] != value:
        print(f"{args[idx]} = {value}")
    else:
        print(args[idx])
    debug_out(args, idx + 1, line_num, *values)

class IntegerIterator:
    def __init__(self, value):
        self.value = value

    def __iter__(self):
        return self

    def __next__(self):
        current = self.value
        self.value += 1
        return current

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

def inclusive_range(from_, to):
    return IntegerRange(from_, to + 1)

def downrange(from_, to=None):
    if to is None:
        return reversed(range_func(from_))
    return reversed(range_func(to, from_))

def reversed(iterable):
    return list(iterable)[::-1]

def sort(range_):
    range_.sort()

def unique(range_):
    seen = set()
    unique_list = []
    for item in range_:
        if item not in seen:
            seen.add(item)
            unique_list.append(item)
    return unique_list

def dedup(range_):
    sort(range_)
    return unique(range_)

def min_element(range_):
    return min(range_)

def max_element(range_):
    return max(range_)

class Graph:
    def __init__(self, vertices_count=0):
        self.vertices_count = vertices_count
        self.edges = defaultdict(list)
        self.from_ = []
        self.to = []
        self.weight = []

    def add_edge(self, from_vertex, to_vertex, weight=None):
        self.from_.append(from_vertex)
        self.to.append(to_vertex)
        self.edges[from_vertex].append(len(self.from_) - 1)
        if weight is not None:
            self.weight.append(weight)

    def clear(self):
        self.vertices_count = 0
        self.edges.clear()
        self.from_.clear()
        self.to.clear()
        self.weight.clear()

class DirectedGraph(Graph):
    def is_acyclic(self):
        visited = [False] * self.vertices_count
        rec_stack = [False] * self.vertices_count

        def is_cyclic(v):
            visited[v] = True
            rec_stack[v] = True

            for neighbor in self.edges[v]:
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
    def __init__(self, size=0):
        super().__init__(range(size))

    def multiply(self, other):
        return Permutation(self[other[i]] for i in range(len(self)))

    def next(self):
        return self.sort()

class Id16:
    def solve(self, in_stream, out_stream):
        s = in_stream.readline().strip()[::-1]
        L, R = 1, 1111

        while R - L > 1:
            length = (L + R) // 2
            p = Permutation(length)
            tmp = s
            recovered = self.try_recover(0, length, tmp, p)

            if recovered:
                if not tmp:
                    ans = [0] * length
                    for i in range(length):
                        ans[p[i]] = i
                    out_stream.write(f"{length}\n")
                    out_stream.write(" ".join(str(x + 1) for x in ans) + "\n")
                    return
                L = length
            else:
                R = length

    def try_recover(self, l, r, s, p):
        if r - l <= 1:
            return True
        mid = (l + r) // 2
        if not self.try_recover(l, mid, s, p) or not self.try_recover(mid, r, s, p):
            return False

        left = [p[i] for i in range(mid - 1, l - 1, -1)]
        right = [p[i] for i in range(r - 1, mid - 1, -1)]
        pos = l

        while left and right:
            if not s:
                return False
            ch = s[-1]
            s = s[:-1]

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
    solver = Id16()
    solver.solve(sys.stdin, sys.stdout)

if __name__ == "__main__":
    main()
