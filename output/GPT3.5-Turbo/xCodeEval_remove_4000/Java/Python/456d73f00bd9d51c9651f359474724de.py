import sys

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
        n = self.io.nextLong()
        m = self.io.nextLong()
        if m < n:
            helper = m
            m = n
            n = helper

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

    MOD = int(1e9) + 7

    def id11(self, v):
        return abs(v) <= 0.0000000000001

    class DrawGrid:
        def draw(self, d):
            sys.stdout.write("  ")
            for x in range(len(d[0])):
                sys.stdout.write(" " + str(x) + " ")
            sys.stdout.write("\n")
            for y in range(len(d)):
                sys.stdout.write(str(y) + " ")
                for x in range(len(d[0])):
                    sys.stdout.write(("[x]" if d[y][x] else "[ ]"))
                sys.stdout.write("\n")

        def draw(self, d):
            max = 1
            for y in range(len(d)):
                for x in range(len(d[0])):
                    max = max(max, len(str(d[y][x])))
            sys.stdout.write("  ")
            format = "%" + str(max + 2) + "s"
            for x in range(len(d[0])):
                sys.stdout.write(format % str(x) + " ")
            format = "%" + str(max) + "s"
            sys.stdout.write("\n")
            for y in range(len(d)):
                sys.stdout.write(str(y) + " ")
                for x in range(len(d[0])):
                    sys.stdout.write(" [" + format % str(d[y][x]) + "]")
                sys.stdout.write("\n")

    class IDval:
        def __init__(self, id, val):
            self.val = val
            self.id = id

        def __lt__(self, o):
            if self.val < o.val:
                return -1
            if self.val > o.val:
                return 1
            return self.id - o.id

    class ElementCounter:
        def __init__(self):
            self.elements = {}

        def add(self, element):
            count = 1
            prev = self.elements.get(element)
            if prev is not None:
                count += prev
            self.elements[element] = count

        def remove(self, element):
            count = self.elements.pop(element)
            count -= 1
            if count > 0:
                self.elements[element] = count

        def get(self, element):
            val = self.elements.get(element)
            if val is None:
                return 0
            return val

        def size(self):
            return len(self.elements)

    class StringCounter:
        def __init__(self):
            self.elements = {}

        def add(self, identifier):
            count = 1
            prev = self.elements.get(identifier)
            if prev is not None:
                count += prev
            self.elements[identifier] = count

        def remove(self, identifier):
            count = self.elements.pop(identifier)
            count -= 1
            if count > 0:
                self.elements[identifier] = count

        def get(self, identifier):
            val = self.elements.get(identifier)
            if val is None:
                return 0
            return val

        def size(self):
            return len(self.elements)

    class id18:
        def __init__(self, n):
            self.componentCount = n
            self.size = [1] * n
            self.parent = [i for i in range(n)]

        def join(self, a, b):
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
        def __init__(self, id35, alphabetSize):
            self.N = id35
            self.Z = alphabetSize
            self.id44 = 1
            self.pointers = [[0] * alphabetSize for _ in range(id35 + 1)]
            self.end = [False] * (id35 + 1)

        def addWord(self, word):
            curr = 0
            for j in range(len(word)):
                c = ord(word[j]) - ord('a')
                next = self.pointers[curr][c]
                if next == 0:
                    next = self.id44
                    self.pointers[curr][c] = next
                    self.id44 += 1
                curr = next
            self.end[curr] = True

        def hasWord(self, word):
            curr = 0
            for j in range(len(word)):
                c = ord(word[j]) - ord('a')
                next = self.pointers[curr][c]
                if next == 0:
                    return False
                curr = next
            return self.end[curr]

    class Prob:
        def __init__(self, real):
            if real > 0:
                self.logP = math.log(real)
            else:
                self.logP = float('nan')

        def __init__(self, logP, id26):
            self.logP = logP

        def get(self):
            return math.exp(self.logP)

        def __str__(self):
            return str(self.get())

        @staticmethod
        def add(a, b):
            if Prob.id29(a) and Prob.id29(b):
                return Prob(float('nan'), Prob.id10)
            if Prob.id29(a):
                return Prob.copy(b)
            if Prob.id29(b):
                return Prob.copy(a)

            x = max(a.logP, b.logP)
            y = min(a.logP, b.logP)
            sum = x + math.log(1 + math.exp(y - x))
            return Prob(sum, Prob.id10)

        @staticmethod
        def multiply(a, b):
            if Prob.id29(a) or Prob.id29(b):
                return Prob(float('nan'), Prob.id10)
            return Prob(a.logP + b.logP, Prob.id10)

        @staticmethod
        def id29(p):
            return p is None or math.isnan(p.logP)

        @staticmethod
        def copy(original):
            return Prob(original.logP, Prob.id10)

    class Binary:
        def __init__(self, binaryString, id39):
            self.length = len(binaryString)
            size = max(2 * self.length, 1)
            self.first = self.length // 4
            if id39:
                self.first = 0
                size = max(self.length, 1)
            self.d = [False] * size
            for i in range(self.length):
                if binaryString[i] == '1':
                    self.d[i + self.first] = True

        def addFirst(self, c):
            if self.first - 1 < 0:
                self.id42()
            self.first -= 1
            self.d[self.first] = c == '1'
            self.length += 1

        def addLast(self, c):
            if self.first + self.length >= len(self.d):
                self.id42()
            self.d[self.first + self.length] = c == '1'
            self.length += 1

        def id42(self):
            bigArray = [False] * ((len(self.d) + 1) * 2)
            newFirst = len(bigArray) // 4
            for i in range(self.length):
                bigArray[i + newFirst] = self.d[i + self.first]
            self.first = newFirst
            self.d = bigArray

        def flip(self, i):
            value = not self.d[self.first + i]
            self.d[self.first + i] = value
            return value

        def set(self, i, c):
            value = c == '1'
            self.d[self.first + i] = value

        def get(self, i):
            return '1' if self.d[self.first + i] else '0'

        def __lt__(self, o):
            if self.length != o.length:
                return self.length - o.length
            for i in range(self.length):
                diff = self.get(i) - o.get(i)
                if diff != 0:
                    return diff
            return 0

        def __str__(self):
            sb = []
            for i in range(self.length):
                sb.append('1' if self.d[i + self.first] else '0')
            return ''.join(sb)

    def toGraph(self, io, n):
        g = [[] for _ in range(n + 1)]
        for _ in range(n - 1):
            a = io.nextInt()
            b = io.nextInt()
            g[a].append(b)
            g[b].append(a)
        return g

    class Graph:
        def __init__(self):
            self.edges = {}

        def id22(self, node):
            neighbors = self.edges.get(node)
            if neighbors is None:
                neighbors = []
                self.edges[node] = neighbors
            return neighbors

        def id13(self, a, b):
            self.addEdge(a, b)
            self.addEdge(b, a)

        def addEdge(self, fromNode, toNode):
            self.id22(toNode)

            neighbors = self.id22(fromNode)
            neighbors.append(toNode)

        def id27(self):
            id25 = []
            vis = {}
            for a in self.edges.keys():
                if not self.id19(a):
                    return [-1]
            id25.reverse()
            return id25

        def id19(self, curr):
            status = vis.get(curr)
            if status is None:
                status = 0
            if status == 2:
                return True
            if status == 1:
                return False
            vis[curr] = 1
            for next in self.edges.get(curr, []):
                if not self.id19(next):
                    return False
            vis[curr] = 2
            id25.append(curr)
            return True

    class id24:
        def getCount(self, n, mista, minne):
            forw = [[] for _ in range(n + 1)]
            bacw = [[] for _ in range(n + 1)]
            for i in range(len(mista)):
                a = mista[i]
                b = minne[i]
                forw[a].append(b)
                bacw[b].append(a)
            count = 0
            list = []
            visited = [False] * (n + 1)
            for i in range(1, n + 1):
                self.dfsForward(i, visited, list, forw)
            visited = [False] * (n + 1)
            for i in range(n - 1, -1, -1):
                node = list[i]
                if visited[node]:
                    continue
                count += 1
                self.dfsBackward(node, visited, bacw)
            return count

        def dfsForward(self, i, visited, list, forw):
            if visited[i]:
                return
            visited[i] = True
            for neighbor in forw[i]:
                self.dfsForward(neighbor, visited, list, forw)
            list.append(i)

        def dfsBackward(self, i, visited, bacw):
            if visited[i]:
                return
            visited[i] = True
            for neighbor in bacw[i]:
                self.dfsBackward(neighbor, visited, bacw)

    class id21:
        def __init__(self, graph):
            self.nodes = [0] * int(10e6)
            self.depths = [0] * int(10e6)
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
                temp = left
                left = right
                right = temp
            mixedBag = self.fenwick.getMin(left, right)
            index = mixedBag % 1000000
            return self.nodes[index]

    def segmentsIntersect(self, x1, y1, x2, y2, x3, y3, x4, y4):
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

    def id28(self, p, r):
        a = r[0]
        b = r[1]
        c = r[2]
        d = r[3]
        apd = self.id7(a, p, d)
        dpc = self.id7(d, p, c)
        cpb = self.id7(c, p, b)
        pba = self.id7(p, b, a)
        id33 = apd + dpc + cpb + pba
        if id33 == self.id40(r):
            if apd == 0 or dpc == 0 or cpb == 0 or pba == 0:
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
        id9 = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)
        return id9 == 0

    class id15:
        def id16(self, point_x, point_y, x1, y1, x2, y2):
            return math.sqrt(self.id32(point_x, point_y, x1, y1, x2, y2))

        def id32(self, point_x, point_y, x1, y1, x2, y2):
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

    def id8(self, last):
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
            return str(int(number, base))

        def convert(self, number, baseFrom, baseTo):
            return str(int(number, baseFrom), baseTo)

        def longify(self, number, baseFrom):
            return int(number, baseFrom)

    class id31:
        def biCo(self, n, k):
            r = 1
            if k > n:
                return 0
            for d in range(1, k + 1):
                r *= n
                r //= d
                n -= 1
            return r

        def id34(self, n, maxK):
            v = [0] * (maxK + 1)
            v[0] = 1

            for i in range(1, n + 1):
                for j in range(min(i, maxK), 0, -1):
                    v[j] = v[j] + v[j - 1]

            return v

        def id34(self, n, k, M):
            v = [0] * (k + 1)
            v[0] = 1

            for i in range(1, n + 1):
                for j in range(min(i, k), 0, -1):
                    v[j] = v[j] + v[j - 1]
                    v[j] %= M

            return v

    def __init__(self):
        self.io = self.IO()
        self.solver = self.Solver()

    class IO:
        def __init__(self):
            self.r = sys.stdin
            self.buf = [0] * self.id38
            self.bufc = 0
            self.bufi = 0
            self.sb = []

        def queryInt(self, s):
            print(s)
            sys.stdout.flush()
            return self.nextInt()

        def queryLong(self, s):
            print(s)
            sys.stdout.flush()
            return self.nextLong()

        def queryNext(self, s):
            print(s)
            sys.stdout.flush()
            return self.next()

        def fillBuf(self):
            self.bufi = 0
            self.bufc = 0
            while self.bufc == 0:
                self.bufc = self.r.readinto(self.buf)
                if self.bufc == -1:
                    self.bufc = 0
                    return

        def pumpBuf(self):
            if self.bufi == self.bufc:
                self.fillBuf()
            return self.bufc != 0

        def isDelimiter(self, c):
            return c == ' ' or c == '\t' or c == '\n' or c == '\r' or c == '\f'

        def id43(self):
            while True:
                if self.bufi == self.bufc:
                    self.fillBuf()
                    if self.bufc == 0:
                        raise RuntimeError("IO: Out of input.")

                if not self.isDelimiter(self.buf[self.bufi]):
                    break
                self.bufi += 1

        def next(self):
            self.sb.clear()

            self.id43()
            start = self.bufi

            while True:
                if not self.pumpBuf():
                    break
                if self.isDelimiter(self.buf[self.bufi]):
                    if not self.sb:
                        raise RuntimeError("IO.next: Invalid string.")
                    break

                self.sb.append(chr(self.buf[self.bufi]))

                self.bufi += 1

            return ''.join(self.sb)

        def nextInt(self):
            ret = 0

            self.id43()

            positive = True
            if self.buf[self.bufi] == ord('-'):
                self.bufi += 1
                if not self.pumpBuf():
                    raise RuntimeError("IO.nextInt: Invalid int.")
                positive = False

            first = True
            while True:
                if not self.pumpBuf():
                    break
                if self.isDelimiter(self.buf[self.bufi]):
                    if first:
                        raise RuntimeError("IO.nextInt: Invalid int.")
                    break
                first = False

                if self.buf[self.bufi] >= ord('0') and self.buf[self.bufi] <= ord('9'):
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
                ret = -ret

            return ret

        def nextLong(self):
            ret = 0

            self.id43()

            positive = True
            if self.buf[self.bufi] == ord('-'):
                self.bufi += 1
                if not self.pumpBuf():
