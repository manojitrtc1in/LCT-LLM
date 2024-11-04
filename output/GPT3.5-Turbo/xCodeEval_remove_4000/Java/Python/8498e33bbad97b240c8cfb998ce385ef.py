import sys
from typing import List, Tuple, Dict, Any


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
        n = self.io.nextInt()

        id13 = min(n, 30)
        prev = set()
        prev.add(0)
        for i in range(id13):
            next_set = set()
            for v in prev:
                next_set.add(v + 1)
                next_set.add(v + 5)
                next_set.add(v + 10)
                next_set.add(v + 50)
            prev = next_set

        if n > id13:
            diff = n - id13
            self.done(len(prev) + diff * 49)

        self.io.println(len(prev))


MOD = int(1e9) + 7


def id11(v: float) -> bool:
    return abs(v) <= 0.0000000000001


class DrawGrid:
    def draw(self, d: List[List[bool]]) -> None:
        print("  ", end="")
        for x in range(len(d[0])):
            print(f" {x} ", end="")
        print("")
        for y in range(len(d)):
            print(f"{y} ", end="")
            for x in range(len(d[0])):
                print(("[x]" if d[y][x] else "[ ]"), end="")
            print("")

    def draw(self, d: List[List[int]]) -> None:
        max_val = 1
        for y in range(len(d)):
            for x in range(len(d[0])):
                max_val = max(max_val, len(str(d[y][x])))
        print("  ", end="")
        format_str = "%" + str(max_val + 2) + "s"
        for x in range(len(d[0])):
            print(format_str % str(x) + " ", end="")
        format_str = "%" + str(max_val) + "s"
        print("")
        for y in range(len(d)):
            print(f"{y} ", end="")
            for x in range(len(d[0])):
                print(f" [{format_str % str(d[y][x])}]", end="")
            print("")


class IDval:
    def __init__(self, id: int, val: int):
        self.id = id
        self.val = val

    def __lt__(self, other: "IDval") -> bool:
        if self.val < other.val:
            return True
        if self.val > other.val:
            return False
        return self.id < other.id


class ElementCounter:
    def __init__(self):
        self.elements = {}

    def add(self, element: int) -> None:
        count = 1
        prev = self.elements.get(element)
        if prev is not None:
            count += prev
        self.elements[element] = count

    def remove(self, element: int) -> None:
        count = self.elements.pop(element)
        count -= 1
        if count > 0:
            self.elements[element] = count

    def get(self, element: int) -> int:
        val = self.elements.get(element)
        if val is None:
            return 0
        return val

    def size(self) -> int:
        return len(self.elements)


class StringCounter:
    def __init__(self):
        self.elements = {}

    def add(self, identifier: str) -> None:
        count = 1
        prev = self.elements.get(identifier)
        if prev is not None:
            count += prev
        self.elements[identifier] = count

    def remove(self, identifier: str) -> None:
        count = self.elements.pop(identifier)
        count -= 1
        if count > 0:
            self.elements[identifier] = count

    def get(self, identifier: str) -> int:
        val = self.elements.get(identifier)
        if val is None:
            return 0
        return val

    def size(self) -> int:
        return len(self.elements)


class id18:
    def __init__(self, n: int):
        self.componentCount = n
        self.size = [1] * n
        self.parent = [i for i in range(n)]

    def join(self, a: int, b: int) -> None:
        rootA = self.parent[a]
        rootB = self.parent[b]
        while rootA != self.parent[rootA]:
            rootA = self.parent[rootA]
        while rootB != self.parent[rootB]:
            rootB = self.parent[rootB]

        if rootA == rootB:
            return

        if self.size[rootA] > self.size[rootB]:
            self.size[rootA] += self.size[rootB]
            self.parent[rootB] = rootA
        else:
            self.size[rootB] += self.size[rootA]
            self.parent[rootA] = rootB
        self.componentCount -= 1


class Trie:
    def __init__(self, id35: int, alphabetSize: int):
        self.N = id35
        self.Z = alphabetSize
        self.id44 = 1
        self.pointers = [[0] * alphabetSize for _ in range(id35 + 1)]
        self.end = [False] * (id35 + 1)

    def addWord(self, word: str) -> None:
        curr = 0
        for j in range(len(word)):
            c = ord(word[j]) - ord("a")
            next = self.pointers[curr][c]
            if next == 0:
                next = self.id44
                self.pointers[curr][c] = next
                self.id44 += 1
            curr = next
        self.end[curr] = True

    def hasWord(self, word: str) -> bool:
        curr = 0
        for j in range(len(word)):
            c = ord(word[j]) - ord("a")
            next = self.pointers[curr][c]
            if next == 0:
                return False
            curr = next
        return self.end[curr]


class Prob:
    def __init__(self, real: float):
        if real > 0:
            self.logP = math.log(real)
        else:
            self.logP = float("nan")

    @staticmethod
    def id10() -> bool:
        return True

    def __add__(self, other: "Prob") -> "Prob":
        if self.id29() and other.id29():
            return Prob(float("nan"), Prob.id10())
        if self.id29():
            return self.copy(other)
        if other.id29():
            return self.copy(self)

        x = max(self.logP, other.logP)
        y = min(self.logP, other.logP)
        sum_ = x + math.log(1 + math.exp(y - x))
        return Prob(sum_, Prob.id10())

    def __mul__(self, other: "Prob") -> "Prob":
        if self.id29() or other.id29():
            return Prob(float("nan"), Prob.id10())
        return Prob(self.logP + other.logP, Prob.id10())

    @staticmethod
    def id29(p: "Prob") -> bool:
        return p is None or math.isnan(p.logP)

    @staticmethod
    def copy(original: "Prob") -> "Prob":
        return Prob(original.logP, Prob.id10())

    def get(self) -> float:
        return math.exp(self.logP)

    def __str__(self) -> str:
        return str(self.get())


class Binary:
    def __init__(self, binaryString: str, id39: bool = False):
        self.length = len(binaryString)
        size = max(2 * self.length, 1)
        self.first = self.length // 4
        if id39:
            self.first = 0
            size = max(self.length, 1)
        self.d = [False] * size
        for i in range(self.length):
            if binaryString[i] == "1":
                self.d[i + self.first] = True

    def addFirst(self, c: str) -> None:
        if self.first - 1 < 0:
            self.id42()
        self.first -= 1
        self.d[self.first] = c == "1"
        self.length += 1

    def addLast(self, c: str) -> None:
        if self.first + self.length >= len(self.d):
            self.id42()
        self.d[self.first + self.length] = c == "1"
        self.length += 1

    def id42(self) -> None:
        bigArray = [False] * ((len(self.d) + 1) * 2)
        newFirst = len(bigArray) // 4
        for i in range(self.length):
            bigArray[i + newFirst] = self.d[i + self.first]
        self.first = newFirst
        self.d = bigArray

    def flip(self, i: int) -> bool:
        value = not self.d[self.first + i]
        self.d[self.first + i] = value
        return value

    def set(self, i: int, c: str) -> None:
        value = c == "1"
        self.d[self.first + i] = value

    def get(self, i: int) -> str:
        return "1" if self.d[self.first + i] else "0"

    def __lt__(self, other: "Binary") -> bool:
        if self.length != other.length:
            return self.length < other.length
        for i in range(self.length):
            diff = ord(self.get(i)) - ord(other.get(i))
            if diff != 0:
                return diff < 0
        return False

    def __str__(self) -> str:
        sb = []
        for i in range(self.length):
            sb.append("1" if self.d[i + self.first] else "0")
        return "".join(sb)


class id4:
    def __init__(self, n: int):
        self.n = n
        self.original = [0] * (n + 2)
        self.bottomUp = [0] * (n + 2)
        self.topDown = [0] * (n + 2)

    def set(self, modifiedNode: int, value: int) -> None:
        replaced = self.original[modifiedNode]
        self.original[modifiedNode] = value

        i = modifiedNode
        v = value
        while i <= self.n:
            if v > self.bottomUp[i]:
                if replaced == self.bottomUp[i]:
                    v = min(v, self.original[i])
                    r = 1
                    while True:
                        x = (i & -i) >> r
                        if x == 0:
                            break
                        child = i - x
                        v = min(v, self.bottomUp[child])
                        r += 1
                else:
                    break
            if v == self.bottomUp[i]:
                break
            self.bottomUp[i] = v
            i += (i & -i)

        i = modifiedNode
        v = value
        while i > 0:
            if v > self.topDown[i]:
                if replaced == self.topDown[i]:
                    v = min(v, self.original[i])
                    r = 1
                    while True:
                        x = (i & -i) >> r
                        if x == 0:
                            break
                        child = i + x
                        if child > self.n + 1:
                            break
                        v = min(v, self.topDown[child])
                        r += 1
                else:
                    break
            if v == self.topDown[i]:
                break
            self.topDown[i] = v
            i -= (i & -i)


class id36:
    def __init__(self, n: int):
        self.d = [0] * (n + 1)

    def modify(self, i: int, v: int) -> None:
        while i < len(self.d):
            self.d[i] += v
            i += (i & -i)

    def getSum(self, a: int, b: int) -> int:
        return self.getSum(b) - self.getSum(a - 1)

    def getSum(self, i: int) -> int:
        sum_ = 0
        while i > 0:
            sum_ += self.d[i]
            i -= (i & -i)
        return sum_


class SegmentTree:
    def __init__(self, n: int):
        self.N = 2
        while self.N < n:
            self.N *= 2
        self.p = [0] * (2 * self.N)

    def modifyRange(self, a: int, b: int, change: int) -> None:
        self.muuta(a, change)
        self.muuta(b + 1, -change)

    def muuta(self, k: int, muutos: int) -> None:
        k += self.N
        self.p[k] += muutos
        k //= 2
        while k >= 1:
            self.p[k] = self.p[2 * k] + self.p[2 * k + 1]
            k //= 2

    def get(self, k: int) -> int:
        a = self.N
        b = k + self.N
        s = 0
        while a <= b:
            if a % 2 == 1:
                s += self.p[a]
                a += 1
            if b % 2 == 0:
                s += self.p[b]
                b -= 1
            a //= 2
            b //= 2
        return s


def toGraph(io: IO, n: int) -> List[List[int]]:
    g = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        a, b = io.nextInt(), io.nextInt()
        g[a].append(b)
        g[b].append(a)
    return g


class Graph:
    def __init__(self):
        self.edges = {}

    def id22(self, node: int) -> List[int]:
        neighbors = self.edges.get(node)
        if neighbors is None:
            neighbors = []
            self.edges[node] = neighbors
        return neighbors

    def id14(self, a: int, b: int) -> None:
        self.addEdge(a, b)
        self.addEdge(b, a)

    def addEdge(self, from_: int, to: int) -> None:
        self.id22(to)

        neighbors = self.id22(from_)
        neighbors.append(to)


def id27() -> int:
    return 0


FINISHED = 2
id3 = 1


class id24:
    def getCount(self, n: int, mista: List[int], minne: List[int]) -> int:
        forw = [[] for _ in range(n + 1)]
        bacw = [[] for _ in range(n + 1)]
        for i in range(len(mista)):
            a, b = mista[i], minne[i]
            forw[a].append(b)
            bacw[b].append(a)
        count = 0
        list_ = []
        visited = [False] * (n + 1)
        for i in range(1, n + 1):
            self.dfsForward(i, visited, list_, forw)
        visited = [False] * (n + 1)
        for i in range(n - 1, -1, -1):
            node = list_[i]
            if visited[node]:
                continue
            count += 1
            self.dfsBackward(node, visited, bacw)
        return count

    def dfsForward(self, i: int, visited: List[bool], list_: List[int], forw: List[List[int]]) -> None:
        if visited[i]:
            return
        visited[i] = True
        for neighbor in forw[i]:
            self.dfsForward(neighbor, visited, list_, forw)
        list_.append(i)

    def dfsBackward(self, i: int, visited: List[bool], bacw: List[List[int]]) -> None:
        if visited[i]:
            return
        visited[i] = True
        for neighbor in bacw[i]:
            self.dfsBackward(neighbor, visited, bacw)


class id21:
    def __init__(self, graph: List[List[int]]):
        self.nodes = [0] * int(10e6)
        self.depths = [0] * int(10e6)
        self.entries = [0] * len(graph)
        self.pointer = 1
        visited = [False] * (len(graph) + 1)
        self.dfs(1, 0, graph, visited)
        self.fenwick = id4(self.pointer - 1)
        for i in range(1, self.pointer):
            self.fenwick.set(i, self.depths[i] * 1000000 + i)

    def dfs(self, node: int, depth: int, graph: List[List[int]], visited: List[bool]) -> None:
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

    def find(self, a: int, b: int) -> int:
        left = self.entries[a]
        right = self.entries[b]
        if left > right:
            left, right = right, left
        mixedBag = self.fenwick.getMin(left, right)
        index = mixedBag % 1000000
        return self.nodes[index]


class Point:
    def __init__(self, y: int, x: int):
        self.y = y
        self.x = x


def segmentsIntersect(x1: float, y1: float, x2: float, y2: float, x3: float, y3: float, x4: float, y4: float) -> bool:
    if x1 == x2 and x3 == x4:
        if x1 != x3:
            return False
        if min(y1, y2) < min(y3, y4):
            return max(y1, y2) >= min(y3, y4)
        else:
            return max(y3, y4) >= min(y1, y2)
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
    if a12 - a34 == 0:
        return b12 - b34 == 0
    x = -(b12 - b34) / (a12 - a34)
    return x >= min(x1, x2) and x <= max(x1, x2) and x >= min(x3, x4) and x <= max(x3, x4)


def id28(p: Point, r: List[Point]) -> bool:
    a = r[0]
    b = r[1]
    c = r[2]
    d = r[3]
    apd = id7(a, p, d)
    dpc = id7(d, p, c)
    cpb = id7(c, p, b)
    pba = id7(p, b, a)
    id33 = apd + dpc + cpb + pba
    if id11(id33 - id40(r)):
        if id11(apd) or id11(dpc) or id11(cpb) or id11(pba):
            return False
        return True
    return False


def id7(a: Point, b: Point, c: Point) -> float:
    return 0.5 * abs((a.x - c.x) * (b.y - a.y) - (a.x - b.x) * (c.y - a.y))


def id40(r: List[Point]) -> float:
    id37 = r[0].x - r[1].x
    id6 = r[0].y - r[1].y
    id30 = r[1].x - r[2].x
    id20 = r[1].y - r[2].y
    side1 = math.sqrt(id37 * id37 + id6 * id6)
    side2 = math.sqrt(id30 * id30 + id20 * id20)
    return side1 * side2


def id12(x1: float, y1: float, x2: float, y2: float, x3: float, y3: float) -> bool:
    id9 = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)
    return id11(id9)


class id16:
    def id17(self, point_x: float, point_y: float, x1: float, y1: float, x2: float, y2: float) -> float:
        return math.sqrt(self.id32(point_x, point_y, x1, y1, x2, y2))

    def id32(self, point_x: float, point_y: float, x1: float, y1: float, x2: float, y2: float) -> float:
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

    def dist2(self, x1: float, y1: float, x2: float, y2: float) -> float:
        return (x1 - x2) ** 2 + (y1 - y2) ** 2


def pow(base: int, exp: int) -> int:
    if exp == 0:
        return 1
    x = pow(base, exp // 2)
    ans = x * x
    if exp % 2 != 0:
        ans *= base
    return ans


def gcd(*v: int) -> int:
    if len(v) == 1:
        return v[0]
    ans = gcd(v[1], v[0])
    for i in range(2, len(v)):
        ans = gcd(ans, v[i])
    return ans


def lcm(a: int, b: int) -> int:
    return a * b // gcd(a, b)


class BaseConverter:
    def convert(self, number: int, base: int) -> str:
        return format(number, f"0{base}d")

    def convert(self, number: str, baseFrom: int, baseTo: int) -> str:
        return format(int(number, baseFrom), f"0{baseTo}d")

    def longify(self, number: str, baseFrom: int) -> int:
        return int(number, baseFrom)


class id31:
    def biCo(self, n: int, k: int) -> int:
        r = 1
        if k > n:
            return 0
        for d in range(1, k + 1):
            r *= n
            r //= d
            n -= 1
        return r

    def id34(self, n: int, maxK: int) -> List[int]:
        v = [0] * (maxK + 1)
        v[0] = 1

        for i in range(1, n + 1):
            for j in range(min(i, maxK), 0, -1):
                v[j] = v[j] + v[j - 1]

        return v

    def id34(self, n: int, k: int, M: int) -> List[int]:
        v = [0] * (k + 1)
        v[0] = 1

        for i in range(1, n + 1):
            for j in range(min(i, k), 0, -1):
                v[j] = (v[j] + v[j - 1]) % M

        return v


class Zalgo:
    def id1(self, haku: str, kohde: str) -> int:
        s = haku + "#" + kohde
        z = self.id23(s)
        max_ = 0
        for i in range(len(haku), len(z)):
            max_ = max(max_, z[i])
        return max_

    def id23(self, s: str) -> List[int]:
        n = len(s)
        z = [0] * n
        a = 0
        b = 0
        for i in range(1, n):
            if i > b:
                while i + z[i] < n and s[z[i]] == s[i + z[i]]:
                    z[i] += 1
            else:
                z[i] = z[i - a]
                if i + z[i - a] > b:
                    while b + 1 < n and s[b - i] == s[b]:
                        z[i] += 1
                        b += 1
                    a = i
        return z

    def id2(self, haku: str, kohde: str) -> List[int]:
        s = haku + "#" + kohde
        z = self.id23(s)
        indexes = []
        for i in range(len(haku), len(z)):
            if z[i] < len(haku):
                continue
            indexes.append(i)
        return indexes


class StringHasher:
    def __init__(self):
        self.P = 353873237
        self.M = 452940277

    def hashString(self, s: str) -> Dict[str, Any]:
        n = len(s)
        hashes = [0] * n
        modifiers = [0] * n
        hashes[0] = ord(s[0])
        modifiers[0] = 1
        for i in range(1, n):
            hashes[i] = (hashes[i - 1] * self.P + ord(s[i])) % self.M
            modifiers[i] = (modifiers[i - 1] * self.P) % self.M
        return {"hashes": hashes, "modifiers": modifiers}

    def getHash(self, hashedString: Dict[str, Any], startIndex: int, endIndex: int) -> int:
        hashes = hashedString["hashes"]
        modifiers = hashedString["modifiers"]
        result = hashes[endIndex]
        if startIndex > 0:
            result -= (hashes[startIndex - 1] * modifiers[endIndex - startIndex + 1]) % self.M
        if result < 0:
            result += self.M
        return result

    def hashString(self, first: str, second: str) -> Tuple[Dict[str, Any], Dict[str, Any]]:
        n = len(first)
        modifiers = [0] * n
        modifiers[0] = 1

        firstHashes = [0] * n
        firstHashes[0] = ord(first[0])

        secondHashes = [0] * n
        secondHashes[0] = ord(second[0])

        firstHashedString = {"hashes": firstHashes, "modifiers": modifiers}
        secondHashedString = {"hashes": secondHashes, "modifiers": modifiers}

        for i in range(1, n):
            modifiers[i] = (modifiers[i - 1] * self.P) % self.M
            firstHashes[i] = (firstHashes[i - 1] * self.P + ord(first[i])) % self.M
            secondHashes[i] = (secondHashes[i - 1] * self.P + ord(second[i])) % self.M

        return firstHashedString, secondHashedString

    def hashString(self, *strings: str) -> List[Dict[str, Any]]:
        n = len(strings[0])
        modifiers = [0] * n
        modifiers[0] = 1
        hashedStrings = []

        for j in range(len(strings)):
            s = strings[j]
            if len(s) != n:
                for i in range(n):
                    hashedStrings.append(self.hashString(strings[i]))
                return hashedStrings

            hashes = [0] * n
            hashes[0] = ord(s[0])
