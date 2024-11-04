import sys
from collections import defaultdict
import math

class D:

    def main():
        solver = Solver()

class Solver:
    def __init__(self):
        self.io = IO()
        try:
            self.solve()
        except RuntimeError as e:
            if str(e) != "Clean exit":
                raise e
        finally:
            self.io.close()

    def solve(self):
        n = self.io.next_long()
        m = self.io.next_long()
        if m < n:
            n, m = m, n

        if n == 1:
            self.io.println(self.id17(m))
            return
        if n == 2:
            if m < 3:
                self.io.println(0)
            elif m == 3:
                self.io.println(4)
            elif m == 7:
                self.io.println(12)
            else:
                self.io.println(2 * m)
            return

        self.io.println(2 * (n * m // 2))

    def id17(self, m):
        ans = 6 * (m // 6)
        if m % 6 == 5:
            ans += 4
        elif m % 6 == 4:
            ans += 2
        return ans

    MOD = int(1e9 + 7)

    def id11(self, v):
        return abs(v) <= 1e-10

    class DrawGrid:
        def draw(self, d):
            print("  ", end="")
            for x in range(len(d[0])):
                print(f" {x} ", end="")
            print()
            for y in range(len(d)):
                print(y, end=" ")
                for x in range(len(d[0])):
                    print("[x]" if d[y][x] else "[ ]", end="")
                print()

        def draw_int(self, d):
            max_len = max(len(str(d[y][x])) for y in range(len(d)) for x in range(len(d[0])))
            print("  ", end="")
            format_str = f"%{max_len + 2}s"
            for x in range(len(d[0])):
                print(format_str % x, end=" ")
            print()
            for y in range(len(d)):
                print(y, end=" ")
                for x in range(len(d[0])):
                    print(f" [{format_str % d[y][x]}]", end="")
                print()

    class IDval:
        def __init__(self, id, val):
            self.id = id
            self.val = val

        def __lt__(self, other):
            if self.val != other.val:
                return self.val < other.val
            return self.id < other.id

    class ElementCounter:
        def __init__(self):
            self.elements = defaultdict(int)

        def add(self, element):
            self.elements[element] += 1

        def remove(self, element):
            if element in self.elements:
                self.elements[element] -= 1
                if self.elements[element] <= 0:
                    del self.elements[element]

        def get(self, element):
            return self.elements[element]

        def size(self):
            return len(self.elements)

    class StringCounter:
        def __init__(self):
            self.elements = defaultdict(int)

        def add(self, identifier):
            self.elements[identifier] += 1

        def remove(self, identifier):
            if identifier in self.elements:
                self.elements[identifier] -= 1
                if self.elements[identifier] <= 0:
                    del self.elements[identifier]

        def get(self, identifier):
            return self.elements[identifier]

        def size(self):
            return len(self.elements)

    class id18:
        def __init__(self, n):
            self.size = [1] * n
            self.parent = list(range(n))
            self.componentCount = n

        def join(self, a, b):
            rootA = self.find(a)
            rootB = self.find(b)

            if rootA == rootB:
                return

            if self.size[rootA] > self.size[rootB]:
                self.size[rootA] += self.size[rootB]
                self.parent[rootB] = rootA
            else:
                self.size[rootB] += self.size[rootA]
                self.parent[rootA] = rootB
            self.componentCount -= 1

        def find(self, a):
            if self.parent[a] != a:
                self.parent[a] = self.find(self.parent[a])
            return self.parent[a]

    class Trie:
        def __init__(self, id35, alphabet_size):
            self.N = id35
            self.Z = alphabet_size
            self.id44 = 1
            self.pointers = [[0] * alphabet_size for _ in range(N + 1)]
            self.end = [False] * (N + 1)

        def add_word(self, word):
            curr = 0
            for char in word:
                c = ord(char) - ord('a')
                next = self.pointers[curr][c]
                if next == 0:
                    next = self.id44
                    self.id44 += 1
                    self.pointers[curr][c] = next
                curr = next
            self.end[curr] = True

        def has_word(self, word):
            curr = 0
            for char in word:
                c = ord(char) - ord('a')
                next = self.pointers[curr][c]
                if next == 0:
                    return False
                curr = next
            return self.end[curr]

    class Prob:
        def __init__(self, real):
            self.logP = math.log(real) if real > 0 else float('nan')

        def get(self):
            return math.exp(self.logP)

        def __str__(self):
            return str(self.get())

        @staticmethod
        def add(a, b):
            if a.id29() and b.id29():
                return Prob(float('nan'))
            if a.id29():
                return b.copy()
            if b.id29():
                return a.copy()

            x = max(a.logP, b.logP)
            y = min(a.logP, b.logP)
            sum = x + math.log(1 + math.exp(y - x))
            return Prob(sum)

        @staticmethod
        def multiply(a, b):
            if a.id29() or b.id29():
                return Prob(float('nan'))
            return Prob(a.logP + b.logP)

        def id29(self):
            return self.logP is None or math.isnan(self.logP)

        def copy(self):
            return Prob(self.logP)

    class Binary:
        def __init__(self, binary_string, id39=False):
            self.length = len(binary_string)
            size = max(2 * self.length, 1)
            self.first = self.length // 4
            if id39:
                self.first = 0
                size = max(self.length, 1)
            self.d = [False] * size
            for i in range(self.length):
                if binary_string[i] == '1':
                    self.d[i + self.first] = True

        def add_first(self, c):
            if self.first - 1 < 0:
                self.id42()
            self.first -= 1
            self.d[self.first] = c == '1'
            self.length += 1

        def add_last(self, c):
            if self.first + self.length >= len(self.d):
                self.id42()
            self.d[self.first + self.length] = c == '1'
            self.length += 1

        def id42(self):
            big_array = [False] * ((len(self.d) + 1) * 2)
            new_first = len(big_array) // 4
            for i in range(self.length):
                big_array[i + new_first] = self.d[i + self.first]
            self.first = new_first
            self.d = big_array

        def flip(self, i):
            value = not self.d[self.first + i]
            self.d[self.first + i] = value
            return value

        def set(self, i, c):
            self.d[self.first + i] = c == '1'

        def get(self, i):
            return '1' if self.d[self.first + i] else '0'

    class id4:
        def __init__(self, n):
            self.n = n
            self.original = [0] * (n + 2)
            self.bottom_up = [0] * (n + 2)
            self.top_down = [0] * (n + 2)

        def set(self, modified_node, value):
            replaced = self.original[modified_node]
            self.original[modified_node] = value

            i = modified_node
            v = value
            while i <= self.n:
                if v > self.bottom_up[i]:
                    if replaced == self.bottom_up[i]:
                        v = min(v, self.original[i])
                        for r in range(1, self.n + 1):
                            x = (i & -i) >> r
                            if x == 0:
                                break
                            child = i - x
                            v = min(v, self.bottom_up[child])
                    else:
                        break
                if v == self.bottom_up[i]:
                    break
                self.bottom_up[i] = v
                i += (i & -i)

            i = modified_node
            v = value
            while i > 0:
                if v > self.top_down[i]:
                    if replaced == self.top_down[i]:
                        v = min(v, self.original[i])
                        for r in range(1, self.n + 1):
                            x = (i & -i) >> r
                            if x == 0:
                                break
                            child = i + x
                            if child > self.n + 1:
                                break
                            v = min(v, self.top_down[child])
                    else:
                        break
                if v == self.top_down[i]:
                    break
                self.top_down[i] = v
                i -= (i & -i)

        def get_min(self, a, b):
            min_val = self.original[a]
            prev = a
            curr = prev + (prev & -prev)

            while curr <= b:
                min_val = min(min_val, self.top_down[prev])
                prev = curr
                curr = prev + (prev & -prev)

            min_val = min(min_val, self.original[prev])
            prev = b
            curr = prev - (prev & -prev)

            while curr >= a:
                min_val = min(min_val, self.bottom_up[prev])
                prev = curr
                curr = prev - (prev & -prev)

            return min_val

    class id36:
        def __init__(self, n):
            self.d = [0] * (n + 1)

        def __init__(self, a):
            self.d = [0] * len(a)
            for i in range(1, len(a)):
                self.modify(i, a[i])

        def modify(self, i, v):
            while i < len(self.d):
                self.d[i] += v
                i += (i & -i)

        def get_sum(self, a, b):
            return self.get_sum(b) - self.get_sum(a - 1)

        def get_sum(self, i):
            sum_val = 0
            while i > 0:
                sum_val += self.d[i]
                i -= (i & -i)
            return sum_val

    class SegmentTree:
        def __init__(self, n, support_sum=True, support_min=True, support_max=True):
            self.N = 1
            while self.N < n:
                self.N *= 2
            self.lazy = [0] * (2 * self.N)
            self.support_sum = support_sum
            self.support_min = support_min
            self.support_max = support_max
            if self.support_sum:
                self.sum = [0] * (2 * self.N)
            if self.support_min:
                self.min = [0] * (2 * self.N)
            if self.support_max:
                self.max = [0] * (2 * self.N)

        def modify_range(self, x, a, b):
            self.modify_rec(a, b, 1, 0, self.N - 1, x)

        def get_sum(self, a, b):
            return self.query_sum(a, b, 1, 0, self.N - 1)

        def get_min(self, a, b):
            return self.query_min(a, b, 1, 0, self.N - 1)

        def get_max(self, a, b):
            return self.query_max(a, b, 1, 0, self.N - 1)

        def query_sum(self, wanted_left, wanted_right, i, actual_left, actual_right):
            if wanted_left > actual_right or wanted_right < actual_left:
                return 0
            if wanted_left == actual_left and wanted_right == actual_right:
                count = wanted_right - wanted_left + 1
                return self.sum[i] + count * self.lazy[i]
            if self.lazy[i] != 0:
                self.propagate(i, actual_left, actual_right)
            d = (actual_right - actual_left + 1) // 2
            left = self.query_sum(wanted_left, min(actual_left + d - 1, wanted_right), 2 * i, actual_left, actual_left + d - 1)
            right = self.query_sum(max(actual_left + d, wanted_left), wanted_right, 2 * i + 1, actual_left + d, actual_right)
            return left + right

        def query_min(self, wanted_left, wanted_right, i, actual_left, actual_right):
            if wanted_left > actual_right or wanted_right < actual_left:
                return 0
            if wanted_left == actual_left and wanted_right == actual_right:
                return self.min[i] + self.lazy[i]
            if self.lazy[i] != 0:
                self.propagate(i, actual_left, actual_right)
            d = (actual_right - actual_left + 1) // 2
            left = self.query_min(wanted_left, min(actual_left + d - 1, wanted_right), 2 * i, actual_left, actual_left + d - 1)
            right = self.query_min(max(actual_left + d, wanted_left), wanted_right, 2 * i + 1, actual_left + d, actual_right)
            return min(left, right)

        def query_max(self, wanted_left, wanted_right, i, actual_left, actual_right):
            if wanted_left > actual_right or wanted_right < actual_left:
                return 0
            if wanted_left == actual_left and wanted_right == actual_right:
                return self.max[i] + self.lazy[i]
            if self.lazy[i] != 0:
                self.propagate(i, actual_left, actual_right)
            d = (actual_right - actual_left + 1) // 2
            left = self.query_max(wanted_left, min(actual_left + d - 1, wanted_right), 2 * i, actual_left, actual_left + d - 1)
            right = self.query_max(max(actual_left + d, wanted_left), wanted_right, 2 * i + 1, actual_left + d, actual_right)
            return max(left, right)

        def modify_rec(self, wanted_left, wanted_right, i, actual_left, actual_right, value):
            if wanted_left > actual_right or wanted_right < actual_left:
                return
            if wanted_left == actual_left and wanted_right == actual_right:
                self.lazy[i] += value
                return
            if self.lazy[i] != 0:
                self.propagate(i, actual_left, actual_right)
            d = (actual_right - actual_left + 1) // 2
            self.modify_rec(wanted_left, min(actual_left + d - 1, wanted_right), 2 * i, actual_left, actual_left + d - 1, value)
            self.modify_rec(max(actual_left + d, wanted_left), wanted_right, 2 * i + 1, actual_left + d, actual_right, value)
            if self.support_sum:
                self.sum[i] += value * (min(actual_right, wanted_right) - max(actual_left, wanted_left) + 1)
            if self.support_min:
                self.min[i] = min(self.min[2 * i] + self.lazy[2 * i], self.min[2 * i + 1] + self.lazy[2 * i + 1])
            if self.support_max:
                self.max[i] = max(self.max[2 * i] + self.lazy[2 * i], self.max[2 * i + 1] + self.lazy[2 * i + 1])

        def propagate(self, i, actual_left, actual_right):
            self.lazy[2 * i] += self.lazy[i]
            self.lazy[2 * i + 1] += self.lazy[i]
            if self.support_sum:
                self.sum[i] += self.lazy[i] * (actual_right - actual_left + 1)
            if self.support_min:
                self.min[i] += self.lazy[i]
            if self.support_max:
                self.max[i] += self.lazy[i]
            self.lazy[i] = 0

    def to_graph(self, io, n):
        g = [[] for _ in range(n + 1)]
        for i in range(1, n):
            a = io.next_int()
            b = io.next_int()
            g[a].append(b)
            g[b].append(a)
        return g

    class Graph:
        def __init__(self):
            self.edges = defaultdict(list)

        def id22(self, node):
            if node not in self.edges:
                self.edges[node] = []
            return self.edges[node]

        def id13(self, a, b):
            self.add_edge(a, b)
            self.add_edge(b, a)

        def add_edge(self, from_node, to_node):
            self.id22(to_node)
            neighbors = self.id22(from_node)
            neighbors.append(to_node)

        def id41(self):
            id25 = []
            vis = {}
            for a in self.edges.keys():
                if not self.id19(a, vis, id25):
                    return [-1]
            id25.reverse()
            return id25

        def id19(self, curr, vis, id25):
            status = vis.get(curr, 0)
            if status == 2:
                return True
            if status == 1:
                return False
            vis[curr] = 1
            for next in self.edges[curr]:
                if not self.id19(next, vis, id25):
                    return False
            vis[curr] = 2
            id25.append(curr)
            return True

    class id24:
        def get_count(self, n, mista, minne):
            forw = [[] for _ in range(n + 1)]
            bacw = [[] for _ in range(n + 1)]
            for i in range(len(mista)):
                a = mista[i]
                b = minne[i]
                forw[a].append(b)
                bacw[b].append(a)
            count = 0
            visited = [False] * (n + 1)
            list = []
            for i in range(1, n + 1):
                self.dfs_forward(i, visited, list)
            visited = [False] * (n + 1)
            for i in range(len(list) - 1, -1, -1):
                node = list[i]
                if visited[node]:
                    continue
                count += 1
                self.dfs_backward(node, visited)
            return count

        def dfs_forward(self, i, visited, list):
            if visited[i]:
                return
            visited[i] = True
            for neighbor in self.forw[i]:
                self.dfs_forward(neighbor, visited, list)
            list.append(i)

        def dfs_backward(self, i, visited):
            if visited[i]:
                return
            visited[i] = True
            for neighbor in self.bacw[i]:
                self.dfs_backward(neighbor, visited)

    class id21:
        def __init__(self, graph):
            self.nodes = [0] * int(1e6)
            self.depths = [0] * int(1e6)
            self.entries = [0] * len(graph)
            self.pointer = 1
            visited = [False] * (len(graph) + 1)
            self.dfs(1, 0, graph, visited)
            self.fenwick = id4(self.pointer - 1)
            for i in range(1, self.pointer):
                self.fenwick.set(i, self.depths[i] * 1000000 + i)

        def dfs(self, node, depth, graph, visited):
            visited[node] = True
            self.entries[node] = self.pointer
            self.nodes[self.pointer] = node
            self.depths[self.pointer] = depth
            self.pointer += 1
            for neighbor in graph[node]:
                if visited[neighbor]:
                    continue
                self.dfs(neighbor, depth + 1, graph, visited)
                self.nodes[self.pointer] = node
                self.depths[self.pointer] = depth
                self.pointer += 1

        def find(self, a, b):
            left = self.entries[a]
            right = self.entries[b]
            if left > right:
                left, right = right, left
            mixed_bag = self.fenwick.get_min(left, right)
            index = mixed_bag % 1000000
            return self.nodes[index]

    class Point:
        def __init__(self, y, x):
            self.y = y
            self.x = x

    def segments_intersect(self, x1, y1, x2, y2, x3, y3, x4, y4):
        if x1 == x2 and x3 == x4:
            if x1 != x3:
                return False
            return (max(y1, y2) >= min(y3, y4)) if min(y1, y2) < min(y3, y4) else (max(y3, y4) >= min(y1, y2))

        if x1 == x2:
            a34 = (y4 - y3) / (x4 - x3)
            b34 = y3 - a34 * x3
            y = a34 * x1 + b34
            return (y >= min(y1, y2) and y <= max(y1, y2) and x1 >= min(x3, x4) and x1 <= max(x3, x4))

        if x3 == x4:
            a12 = (y2 - y1) / (x2 - x1)
            b12 = y1 - a12 * x1
            y = a12 * x3 + b12
            return (y >= min(y3, y4) and y <= max(y3, y4) and x3 >= min(x1, x2) and x3 <= max(x1, x2))

        a12 = (y2 - y1) / (x2 - x1)
        b12 = y1 - a12 * x1
        a34 = (y4 - y3) / (x4 - x3)
        b34 = y3 - a34 * x3
        if self.id11(a12 - a34):
            return self.id11(b12 - b34)

        x = -(b12 - b34) / (a12 - a34)
        return (x >= min(x1, x2) and x <= max(x1, x2) and x >= min(x3, x4) and x <= max(x3, x4))

    def id28(self, p, r):
        a, b, c, d = r
        apd = self.id7(a, p, d)
        dpc = self.id7(d, p, c)
        cpb = self.id7(c, p, b)
        pba = self.id7(p, b, a)
        id33 = apd + dpc + cpb + pba
        if self.id11(id33 - self.id40(r)):
            if self.id11(apd) or self.id11(dpc) or self.id11(cpb) or self.id11(pba):
                return False
            return True
        return False

    def id7(self, a, b, c):
        return 0.5 * abs((a.x - c.x) * (b.y - a.y) - (a.x - b.x) * (c.y - a.y))

    def id40(self, r):
        id37 = r[0].x - r[1].x
        id6 = r[0].y - r[1].y
        id30 = r[1].x - r[2].x
        id20 = r[1].y - r[2].y
        side1 = math.sqrt(id37 * id37 + id6 * id6)
        side2 = math.sqrt(id30 * id30 + id20 * id20)
        return side1 * side2

    def id12(self, x1, y1, x2, y2, x3, y3):
