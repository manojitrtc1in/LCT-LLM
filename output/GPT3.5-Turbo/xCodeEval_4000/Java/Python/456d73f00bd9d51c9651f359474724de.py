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
            self.io.println(self.brute1(m))
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

    def brute1(self, m):
        ans = 6 * (m // 6)
        if m % 6 == 5:
            ans += 4
        elif m % 6 == 4:
            ans += 2
        return ans

    MOD = int(1e9) + 7

    def closeToZero(self, v):
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

    class DisjointSet:
        def __init__(self, n):
            self.size = [1] * n
            self.parent = [i for i in range(n)]
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
            while a != self.parent[a]:
                self.parent[a] = self.parent[self.parent[a]]
                a = self.parent[a]
            return a

    class Trie:
        def __init__(self, maxLenSum, alphabetSize):
            self.N = maxLenSum
            self.Z = alphabetSize
            self.nextFreeId = 1
            self.pointers = [[0] * alphabetSize for _ in range(maxLenSum + 1)]
            self.end = [False] * (maxLenSum + 1)

        def addWord(self, word):
            curr = 0
            for j in range(len(word)):
                c = ord(word[j]) - ord('a')
                next = self.pointers[curr][c]
                if next == 0:
                    next = self.nextFreeId
                    self.nextFreeId += 1
                    self.pointers[curr][c] = next
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

        @staticmethod
        def add(a, b):
            if Prob.nullOrNaN(a) and Prob.nullOrNaN(b):
                return Prob(float('nan'))
            if Prob.nullOrNaN(a):
                return Prob.copy(b)
            if Prob.nullOrNaN(b):
                return Prob.copy(a)

            x = max(a.logP, b.logP)
            y = min(a.logP, b.logP)
            sum = x + math.log(1 + math.exp(y - x))
            return Prob(sum)

        @staticmethod
        def multiply(a, b):
            if Prob.nullOrNaN(a) or Prob.nullOrNaN(b):
                return Prob(float('nan'))
            return Prob(a.logP + b.logP)

        @staticmethod
        def nullOrNaN(p):
            return p is None or math.isnan(p.logP)

        @staticmethod
        def copy(original):
            return Prob(original.logP)

        def get(self):
            return math.exp(self.logP)

        def __str__(self):
            return str(self.get())

    class Binary:
        def __init__(self, binaryString, initWithMinArraySize=False):
            self.length = len(binaryString)
            size = max(2 * self.length, 1)
            self.first = self.length // 4
            if initWithMinArraySize:
                self.first = 0
                size = max(self.length, 1)
            self.d = [False] * size
            for i in range(self.length):
                if binaryString[i] == '1':
                    self.d[i + self.first] = True

        def addFirst(self, c):
            if self.first - 1 < 0:
                self.doubleArraySize()
            self.first -= 1
            self.d[self.first] = c == '1'
            self.length += 1

        def addLast(self, c):
            if self.first + self.length >= len(self.d):
                self.doubleArraySize()
            self.d[self.first + self.length] = c == '1'
            self.length += 1

        def doubleArraySize(self):
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

    class FenwickMin:
        def __init__(self, n):
            self.n = n
            self.original = [0] * (n + 2)
            self.bottomUp = [0] * (n + 2)
            self.topDown = [0] * (n + 2)

        def set(self, modifiedNode, value):
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

        def getMin(self, a, b):
            min = self.original[a]
            prev = a
            curr = prev + (prev & -prev)

            while curr <= b:
                min = min(min, self.topDown[prev])

                prev = curr
                curr = prev + (prev & -prev)
            min = min(min, self.original[prev])
            prev = b
            curr = prev - (prev & -prev)

            while curr >= a:
                min = min(min, self.bottomUp[prev])

                prev = curr
                curr = prev - (prev & -prev)
            return min

    class FenwickSum:
        def __init__(self, n):
            self.d = [0] * (n + 1)

        def modify(self, i, v):
            while i < len(self.d):
                self.d[i] += v
                i += (i & -i)

        def getSum(self, a, b):
            return self.getSum(b) - self.getSum(a - 1)

        def getSum(self, i):
            sum = 0
            while i > 0:
                sum += self.d[i]
                i -= (i & -i)
            return sum

    class SegmentTree:
        def __init__(self, n, supportSum=True, supportMin=True, supportMax=True):
            self.N = 2
            while self.N < n:
                self.N *= 2
            self.lazy = [0] * (2 * self.N)
            self.supportSum = supportSum
            self.supportMin = supportMin
            self.supportMax = supportMax
            if self.supportSum:
                self.sum = [0] * (2 * self.N)
            if self.supportMin:
                self.min = [0] * (2 * self.N)
            if self.supportMax:
                self.max = [0] * (2 * self.N)

        def modifyRange(self, x, a, b):
            self.modifyRec(a, b, 1, 0, self.N - 1, x)

        def setRange(self):
            pass

        def getSum(self, a, b):
            return self.querySum(a, b, 1, 0, self.N - 1)

        def getMin(self, a, b):
            return self.queryMin(a, b, 1, 0, self.N - 1)

        def getMax(self, a, b):
            return self.queryMax(a, b, 1, 0, self.N - 1)

        def querySum(self, wantedLeft, wantedRight, i, actualLeft, actualRight):
            if wantedLeft > actualRight or wantedRight < actualLeft:
                return 0
            if wantedLeft == actualLeft and wantedRight == actualRight:
                count = wantedRight - wantedLeft + 1
                return self.sum[i] + count * self.lazy[i]
            if self.lazy[i] != 0:
                self.propagate(i, actualLeft, actualRight)
            d = (actualRight - actualLeft + 1) // 2
            left = self.querySum(wantedLeft, min(actualLeft + d - 1, wantedRight), 2 * i, actualLeft, actualLeft + d - 1)
            right = self.querySum(max(actualLeft + d, wantedLeft), wantedRight, 2 * i + 1, actualLeft + d, actualRight)
            return left + right

        def queryMin(self, wantedLeft, wantedRight, i, actualLeft, actualRight):
            if wantedLeft > actualRight or wantedRight < actualLeft:
                return 0
            if wantedLeft == actualLeft and wantedRight == actualRight:
                return self.min[i] + self.lazy[i]
            if self.lazy[i] != 0:
                self.propagate(i, actualLeft, actualRight)
            d = (actualRight - actualLeft + 1) // 2
            left = self.queryMin(wantedLeft, min(actualLeft + d - 1, wantedRight), 2 * i, actualLeft, actualLeft + d - 1)
            right = self.queryMin(max(actualLeft + d, wantedLeft), wantedRight, 2 * i + 1, actualLeft + d, actualRight)
            return min(left, right)

        def queryMax(self, wantedLeft, wantedRight, i, actualLeft, actualRight):
            if wantedLeft > actualRight or wantedRight < actualLeft:
                return 0
            if wantedLeft == actualLeft and wantedRight == actualRight:
                return self.max[i] + self.lazy[i]
            if self.lazy[i] != 0:
                self.propagate(i, actualLeft, actualRight)
            d = (actualRight - actualLeft + 1) // 2
            left = self.queryMax(wantedLeft, min(actualLeft + d - 1, wantedRight), 2 * i, actualLeft, actualLeft + d - 1)
            right = self.queryMax(max(actualLeft + d, wantedLeft), wantedRight, 2 * i + 1, actualLeft + d, actualRight)
            return max(left, right)

        def modifyRec(self, wantedLeft, wantedRight, i, actualLeft, actualRight, value):
            if wantedLeft > actualRight or wantedRight < actualLeft:
                return
            if wantedLeft == actualLeft and wantedRight == actualRight:
                self.lazy[i] += value
                return
            if self.lazy[i] != 0:
                self.propagate(i, actualLeft, actualRight)
            d = (actualRight - actualLeft + 1) // 2
            self.modifyRec(wantedLeft, min(actualLeft + d - 1, wantedRight), 2 * i, actualLeft, actualLeft + d - 1, value)
            self.modifyRec(max(actualLeft + d, wantedLeft), wantedRight, 2 * i + 1, actualLeft + d, actualRight, value)
            if self.supportSum:
                self.sum[i] += value * (min(actualRight, wantedRight) - max(actualLeft, wantedLeft) + 1)
            if self.supportMin:
                self.min[i] = min(self.min[2 * i] + self.lazy[2 * i], self.min[2 * i + 1] + self.lazy[2 * i + 1])
            if self.supportMax:
                self.max[i] = max(self.max[2 * i] + self.lazy[2 * i], self.max[2 * i + 1] + self.lazy[2 * i + 1])

        def propagate(self, i, actualLeft, actualRight):
            self.lazy[2 * i] += self.lazy[i]
            self.lazy[2 * i + 1] += self.lazy[i]
            if self.supportSum:
                self.sum[i] += self.lazy[i] * (actualRight - actualLeft + 1)
            if self.supportMin:
                self.min[i] += self.lazy[i]
            if self.supportMax:
                self.max[i] += self.lazy[i]
            self.lazy[i] = 0

    class Graph:
        def __init__(self):
            self.edges = {}

        def getSetNeighbors(self, node):
            neighbors = self.edges.get(node)
            if neighbors is None:
                neighbors = []
                self.edges[node] = neighbors
            return neighbors

        def addBiEdge(self, a, b):
            self.addEdge(a, b)
            self.addEdge(b, a)

        def addEdge(self, fromNode, toNode):
            self.getSetNeighbors(toNode)

            neighbors = self.getSetNeighbors(fromNode)
            neighbors.append(toNode)

    class StronglyConnectedComponents:
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

    class LCAFinder:
        def __init__(self, graph):
            self.nodes = [0] * int(10e6)
            self.depths = [0] * int(10e6)
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
                temp = left
                left = right
                right = temp
            mixedBag = self.fenwick.getMin(left, right)
            index = mixedBag % 1000000
            return self.nodes[index]

    class Point:
        def __init__(self, y, x):
            self.y = y
            self.x = x

    def __init__(self):
        self.solver = Solver()

    def run(self):
        pass

if __name__ == "__main__":
    Main().run()
