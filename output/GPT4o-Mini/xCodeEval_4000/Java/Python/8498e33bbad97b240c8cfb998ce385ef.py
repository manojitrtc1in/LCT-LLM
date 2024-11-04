import sys
from collections import defaultdict

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
        n = self.io.next_int()

        end_of_brute = min(n, 30)
        prev = {0}
        for i in range(end_of_brute):
            next_set = set()
            for v in prev:
                next_set.add(v + 1)
                next_set.add(v + 5)
                next_set.add(v + 10)
                next_set.add(v + 50)
            prev = next_set

        if n > end_of_brute:
            diff = n - end_of_brute
            self.done(len(prev) + diff * 49)

        self.io.println(len(prev))

    MOD = int(1e9 + 7)

    def close_to_zero(self, v):
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
            max_len = 1
            for y in range(len(d)):
                for x in range(len(d[0])):
                    max_len = max(max_len, len(str(d[y][x])))
            print("  ", end="")
            format_str = f"%{max_len + 2}s"
            for x in range(len(d[0])):
                print(format_str % x, end=" ")
            print()
            format_str = f"%{max_len}s"
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
            if self.elements[element] > 0:
                self.elements[element] -= 1

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
            if self.elements[identifier] > 0:
                self.elements[identifier] -= 1

        def get(self, identifier):
            return self.elements[identifier]

        def size(self):
            return len(self.elements)

    class DisjointSet:
        def __init__(self, n):
            self.component_count = n
            self.size = [1] * n
            self.parent = list(range(n))

        def join(self, a, b):
            root_a = self.find(a)
            root_b = self.find(b)

            if root_a == root_b:
                return

            if self.size[root_a] > self.size[root_b]:
                self.size[root_a] += self.size[root_b]
                self.parent[root_b] = root_a
            else:
                self.size[root_b] += self.size[root_a]
                self.parent[root_a] = root_b
            self.component_count -= 1

        def find(self, a):
            while a != self.parent[a]:
                a = self.parent[a]
            return a

    class Trie:
        def __init__(self, max_len_sum, alphabet_size):
            self.N = max_len_sum
            self.Z = alphabet_size
            self.next_free_id = 1
            self.pointers = [[0] * alphabet_size for _ in range(self.N + 1)]
            self.end = [False] * (self.N + 1)

        def add_word(self, word):
            curr = 0
            for char in word:
                c = ord(char) - ord('a')
                next_node = self.pointers[curr][c]
                if next_node == 0:
                    next_node = self.next_free_id
                    self.next_free_id += 1
                    self.pointers[curr][c] = next_node
                curr = next_node
            self.end[curr] = True

        def has_word(self, word):
            curr = 0
            for char in word:
                c = ord(char) - ord('a')
                next_node = self.pointers[curr][c]
                if next_node == 0:
                    return False
                curr = next_node
            return self.end[curr]

    class Prob:
        def __init__(self, real):
            self.logP = math.log(real) if real > 0 else float('nan')

        @staticmethod
        def add(a, b):
            if a is None and b is None:
                return Prob(float('nan'))
            if a is None:
                return Prob(b.logP)
            if b is None:
                return Prob(a.logP)

            x = max(a.logP, b.logP)
            y = min(a.logP, b.logP)
            sum_log = x + math.log(1 + math.exp(y - x))
            return Prob(sum_log)

        @staticmethod
        def multiply(a, b):
            if a is None or b is None:
                return Prob(float('nan'))
            return Prob(a.logP + b.logP)

    class Binary:
        def __init__(self, binary_string, init_with_min_array_size=False):
            self.length = len(binary_string)
            size = max(2 * self.length, 1)
            self.first = self.length // 4
            if init_with_min_array_size:
                self.first = 0
                size = max(self.length, 1)
            self.d = [False] * size
            for i in range(self.length):
                if binary_string[i] == '1':
                    self.d[i + self.first] = True

        def add_first(self, c):
            if self.first - 1 < 0:
                self.double_array_size()
            self.first -= 1
            self.d[self.first] = (c == '1')

        def add_last(self, c):
            if self.first + self.length >= len(self.d):
                self.double_array_size()
            self.d[self.first + self.length] = (c == '1')
            self.length += 1

        def double_array_size(self):
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
            self.d[self.first + i] = (c == '1')

        def get(self, i):
            return '1' if self.d[self.first + i] else '0'

    class FenwickMin:
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

    class FenwickSum:
        def __init__(self, n):
            self.d = [0] * (n + 1)

        def modify(self, i, v):
            while i < len(self.d):
                self.d[i] += v
                i += (i & -i)

        def get_sum(self, a, b):
            return self.get_sum(b) - self.get_sum(a - 1)

        def get_sum(self, i):
            total = 0
            while i > 0:
                total += self.d[i]
                i -= (i & -i)
            return total

    class SegmentTree:
        def __init__(self, n):
            self.N = 1
            while self.N < n:
                self.N *= 2
            self.p = [0] * (2 * self.N)

        def modify_range(self, a, b, change):
            self.muuta(a, change)
            self.muuta(b + 1, -change)

        def muuta(self, k, muutos):
            k += self.N
            self.p[k] += muutos
            for k in range(k // 2, 0, k // 2):
                self.p[k] = self.p[2 * k] + self.p[2 * k + 1]

        def get(self, k):
            a = self.N
            b = k + self.N
            total = 0
            while a <= b:
                if a % 2 == 1:
                    total += self.p[a]
                    a += 1
                if b % 2 == 0:
                    total += self.p[b]
                    b -= 1
                a //= 2
                b //= 2
            return total

    def to_graph(io, n):
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

        def get_set_neighbors(self, node):
            return self.edges[node]

        def add_bi_edge(self, a, b):
            self.add_edge(a, b)
            self.add_edge(b, a)

        def add_edge(self, from_node, to_node):
            self.get_set_neighbors(to_node)
            self.edges[from_node].append(to_node)

        UNTOUCHED = 0
        FINISHED = 2
        INPROGRESS = 1

        def topo_sort(self):
            self.topo_ans = []
            self.vis = {}
            for a in self.edges.keys():
                if not self.topo_dfs(a):
                    return [-1]
            self.topo_ans.reverse()
            return self.topo_ans

        def topo_dfs(self, curr):
            status = self.vis.get(curr, self.UNTOUCHED)
            if status == self.FINISHED:
                return True
            if status == self.INPROGRESS:
                return False
            self.vis[curr] = self.INPROGRESS
            for next_node in self.edges[curr]:
                if not self.topo_dfs(next_node):
                    return False
            self.vis[curr] = self.FINISHED
            self.topo_ans.append(curr)
            return True

    class StronglyConnectedComponents:
        def get_count(self, n, mista, minne):
            self.forw = [[] for _ in range(n + 1)]
            self.bacw = [[] for _ in range(n + 1)]
            for a, b in zip(mista, minne):
                self.forw[a].append(b)
                self.bacw[b].append(a)
            count = 0
            list_nodes = []
            visited = [False] * (n + 1)
            for i in range(1, n + 1):
                self.dfs_forward(i, visited, list_nodes)
            visited = [False] * (n + 1)
            for i in range(len(list_nodes) - 1, -1, -1):
                node = list_nodes[i]
                if visited[node]:
                    continue
                count += 1
                self.dfs_backward(node, visited)
            return count

        def dfs_forward(self, i, visited, list_nodes):
            if visited[i]:
                return
            visited[i] = True
            for neighbor in self.forw[i]:
                self.dfs_forward(neighbor, visited, list_nodes)
            list_nodes.append(i)

        def dfs_backward(self, i, visited):
            if visited[i]:
                return
            visited[i] = True
            for neighbor in self.bacw[i]:
                self.dfs_backward(neighbor, visited)

    class LCAFinder:
        def __init__(self, graph):
            self.nodes = [0] * int(1e6)
            self.depths = [0] * int(1e6)
            self.entries = [0] * len(graph)
            self.pointer = 1
            visited = [False] * (len(graph) + 1)
            self.dfs(1, 0, graph, visited)
            self.fenwick = FenwickMin(self.pointer - 1)
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
            index = int(mixed_bag % 1000000)
            return self.nodes[index]

    class Point:
        def __init__(self, y, x):
            self.y = y
            self.x = x

    def segments_intersect(self, x1, y1, x2, y2, x3, y3, x4, y4):
        if x1 == x2 and x3 == x4:
            if x1 != x3:
                return False
            return max(y1, y2) >= min(y3, y4) if min(y1, y2) < min(y3, y4) else max(y3, y4) >= min(y1, y2)

        if x1 == x2:
            a34 = (y4 - y3) / (x4 - x3)
            b34 = y3 - a34 * x3
            y = a34 * x1 + b34
            return y >= min(y1, y2) and y <= max(y1, y2) and x1 >= min(x3, x4) and x1 <= max(x3, x4)

        if x3 == x4:
            a12 = (y2 - y1) / (x2 - x1)
            b12 = y1 - a12 * x1
            y = a12 * x3 + b12
            return y >= min(y3, y4) and y <= max(y3, y4) and x3 >= min(x1, x2) and x3 <= max(x1, x2)

        a12 = (y2 - y1) / (x2 - x1)
        b12 = y1 - a12 * x1
        a34 = (y4 - y3) / (x4 - x3)
        b34 = y3 - a34 * x3
        if self.close_to_zero(a12 - a34):
            return self.close_to_zero(b12 - b34)

        x = -(b12 - b34) / (a12 - a34)
        return min(x1, x2) <= x <= max(x1, x2) and min(x3, x4) <= x <= max(x3, x4)

    def point_inside_rectangle(self, p, r):
        a, b, c, d = r
        apd = self.area_of_triangle(a, p, d)
        dpc = self.area_of_triangle(d, p, c)
        cpb = self.area_of_triangle(c, p, b)
        pba = self.area_of_triangle(p, b, a)
        sum_of_areas = apd + dpc + cpb + pba
        if self.close_to_zero(sum_of_areas - self.area_of_rectangle(r)):
            return not (self.close_to_zero(apd) or self.close_to_zero(dpc) or self.close_to_zero(cpb) or self.close_to_zero(pba))
        return False

    def area_of_triangle(self, a, b, c):
        return 0.5 * abs((a.x - c.x) * (b.y - a.y) - (a.x - b.x) * (c.y - a.y))

    def area_of_rectangle(self, r):
        side1x_diff = r[0].x - r[1].x
        side1y_diff = r[0].y - r[1].y
        side2x_diff = r[1].x - r[2].x
        side2y_diff = r[1].y - r[2].y
        side1 = (side1x_diff ** 2 + side1y_diff ** 2) ** 0.5
        side2 = (side2x_diff ** 2 + side2y_diff ** 2) ** 0.5
        return side1 * side2

    def points_on_same_line(self, x1, y1, x2, y2, x3, y3):
        area_times_2 = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)
        return self.close_to_zero(area_times_2)

    class PointToLineSegmentDistanceCalculator:
        def min_dist_from_point_to_line_segment(self, point_x, point_y, x1, y1, x2, y2):
            return (self.dist_to_segment_squared(point_x, point_y, x1, y1, x2, y2)) ** 0.5

        def dist_to_segment_squared(self, point_x, point_y, x1, y1, x2, y2):
            l2 = self.dist2(x1, y1, x2, y2)
            if l2 == 0:
                return self.dist2(point_x, point_y, x1, y1)
            t = ((point_x - x1) * (x2 - x1) + (point_y - y1) * (y2 - y1)) / l2
            if t < 0:
                return self.dist2(point_x, point_y, x1, y1)
            if t > 1:
                return self.dist2(point_x, point_y, x2, y2)

            com_x = x1 + t * (x2 - x1)
            com_y = y1 + t * (y2 - y1)
            return self.dist2(point_x, point_y, com_x, com_y)

        def dist2(self, x1, y1, x2, y2):
            return (x1 - x2) ** 2 + (y1 - y2) ** 2

    def pow(self, base, exp):
        if exp == 0:
            return 1
        x = self.pow(base, exp // 2)
        ans = x * x
        if exp % 2 != 0:
            ans *= base
        return ans

    def gcd(self, *v):
        if len(v) == 1:
            return v[0]
        ans = self.gcd(v[1], v[0])
        for i in range(2, len(v)):
            ans = self.gcd(ans, v[i])
        return ans

    def gcd(self, a, b):
        if b == 0:
            return a
        return self.gcd(b, a % b)

    def generate_primes_up_to(self, last):
        div = [0] * (last + 1)
        for x in range(2, last + 1):
            if div[x] > 0:
                continue
            for u in range(2 * x, last + 1, x):
                div[u] = x
        return div

    def lcm(self, a, b):
        return a * b // self.gcd(a, b)

    class BaseConverter:
        def convert(self, number, base):
            return str(number)

        def convert_str(self, number, base_from, base_to):
            return str(int(number, base_from))

        def longify(self, number, base_from):
            return int(number, base_from)

    class BinomialCoefficients:
        def bi_co(self, n, k):
            r = 1
            if k > n:
                return 0
            for d in range(1, k + 1):
                r *= n
                n -= 1
                r //= d
            return r

        def precalc_binomial_coefficients_k(self, n, max_k):
            v = [0] * (max_k + 1)
            v[0] = 1

            for i in range(1, n + 1):
                for j in range(min(i, max_k), 0, -1):
                    v[j] += v[j - 1]

            return v

        def precalc_binomial_coefficients_k_mod(self, n, k, M):
            v = [0] * (k + 1)
            v[0] = 1

            for i in range(1, n + 1):
                for j in range(min(i, k), 0, -1):
                    v[j] += v[j - 1]
                    v[j] %= M

            return v

    class Zalgo:
        def pisin_eisiintyma(self, haku, kohde):
            s = list(haku) + ['#'] + list(kohde)
            z = self.to_z_array(s)
            return max(z[len(haku):])

        def to_z_array(self, s):
            n = len(s)
            z = [0] * n
            a, b = 0, 0
            for i in range(1, n):
                if i > b:
                    for j in range(i, n):
                        if s[j - i] != s[j]:
                            break
                        z[i] += 1
                else:
                    z[i] = z[i - a]
                    if i + z[i - a] > b:
                        for j in range(b + 1, n):
                            if s[j - i] != s[j]:
                                break
                            z[i] += 1
                        a = i
                        b = i + z[i] - 1
            return z

        def get_start_indexes_where_word_is_found(self, haku, kohde):
            s = list(haku) + ['#'] + list(kohde)
            z = self.to_z_array(s)
            indexes = []
            for i in range(len(haku), len(z)):
                if z[i] >= len(haku):
                    indexes.append(i)
            return indexes

    class StringHasher:
        class HashedString:
            def __init__(self, hashes, modifiers):
                self.hashes = hashes
                self.modifiers = modifiers

        def __init__(self):
            self.initialize_p_and_m()

        def hash_string(self, s):
            n = len(s)
            hashes = [0] * n
            modifiers = [0] * n
            hashes[0] = ord(s[0])
            modifiers[0] = 1
            for i in range(1, n):
                hashes[i] = (hashes[i - 1] * self.P + ord(s[i])) % self.M
                modifiers[i] = (modifiers[i - 1] * self.P) % self.M
            return self.HashedString(hashes, modifiers)

        def get_hash(self, hashed_string, start_index, end_index):
            hashes = hashed_string.hashes
            modifiers = hashed_string.modifiers
            result = hashes[end_index]
            if start_index > 0:
                result -= (hashes[start_index - 1] * modifiers[end_index - start_index + 1]) % self.M
            if result < 0:
                result += self.M
            return result

        def initialize_p_and_m(self):
            mod_options = [
                353873237, 353875897, 353878703, 353882671,
                353885303, 353888377, 353893457
            ]
            self.P = mod_options[random.randint(0, len(mod_options) - 1)]

            mod_options = [
                452940277, 452947687, 464478431, 468098221,
                470374601, 472879717, 472881973
            ]
            self.M = mod_options[random.randint(0, len(mod_options) - 1)]

    class IO:
        def __init__(self):
            self.r = sys.stdin
            self.buf = bytearray(1 << 15)
            self.bufc = 0
            self.bufi = 0
            self.sb = []

        def next(self):
            self.eat_delimiters()
            start = self.bufi
            while True:
                if self.bufi == self.bufc:
                    self.fill_buf()
                    start = 0
                    if self.bufc == 0:
                        break
                if not self.is_delimiter(self.buf[self.bufi]):
                    break
                self.bufi += 1
            self.sb.append(self.buf[start:self.bufi].decode())
            return ''.join(self.sb)

        def next_int(self):
            self.eat_delimiters()
            ret = 0
            positive = True
            if self.buf[self.bufi] == ord('-'):
                self.bufi += 1
                positive = False
            first = True
            while True:
                if not self.pump_buf():
                    break
                if self.is_delimiter(self.buf[self.bufi]):
                    if first:
                        raise RuntimeError("IO.nextInt: Invalid int.")
                    break
                first = False
                if b'0' <= self.buf[self.bufi] <= b'9':
                    if ret < -214748364:
                        raise RuntimeError("IO.nextInt: Invalid int.")
                    ret *= 10
                    ret -= self.buf[self.bufi] - ord('0')
                    if ret > 0:
                        raise RuntimeError("IO.nextInt: Invalid int.")
                else:
                    raise RuntimeError("IO.nextInt: Invalid int.")
                self.bufi += 1
            if positive:
                if ret == -2147483648:
                    raise RuntimeError("IO.nextInt: Invalid int.")
