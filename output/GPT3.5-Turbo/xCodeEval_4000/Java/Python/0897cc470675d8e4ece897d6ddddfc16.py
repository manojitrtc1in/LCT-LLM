class Graph:
    def __init__(self, vertexCount):
        self.vertexCount = vertexCount
        self.edgeCount = 0
        self.firstOutbound = [-1] * vertexCount
        self.firstInbound = [-1] * vertexCount
        self.edges = []
        self.nextInbound = []
        self.nextOutbound = []
        self.from_ = []
        self.to = []
        self.weight = []
        self.capacity = []
        self.reverseEdge = []
        self.flags = []

    def addEdge(self, fromID, toID, weight, capacity, reverseEdge):
        self.ensureEdgeCapacity(self.edgeCount + 1)
        if self.firstOutbound[fromID] != -1:
            self.nextOutbound.append(self.firstOutbound[fromID])
        else:
            self.nextOutbound.append(-1)
        self.firstOutbound[fromID] = self.edgeCount
        if self.firstInbound is not None:
            if self.firstInbound[toID] != -1:
                self.nextInbound.append(self.firstInbound[toID])
            else:
                self.nextInbound.append(-1)
            self.firstInbound[toID] = self.edgeCount
        self.from_.append(fromID)
        self.to.append(toID)
        if capacity != 0:
            if self.capacity is None:
                self.capacity = [0] * len(self.from_)
            self.capacity[self.edgeCount] = capacity
        if weight != 0:
            if self.weight is None:
                self.weight = [0] * len(self.from_)
            self.weight[self.edgeCount] = weight
        if reverseEdge != -1:
            if self.reverseEdge is None:
                self.reverseEdge = [-1] * len(self.from_)
            self.reverseEdge[self.edgeCount] = reverseEdge
        self.edges.append(self.createEdge(self.edgeCount))
        self.edgeCount += 1
        return self.edgeCount - 1

    def ensureEdgeCapacity(self, size):
        if len(self.from_) < size:
            newSize = max(size, 2 * len(self.from_))
            if self.edges is not None:
                self.edges = self.resize(self.edges, newSize)
            self.from_ = self.resize(self.from_, newSize)
            self.to = self.resize(self.to, newSize)
            self.nextOutbound = self.resize(self.nextOutbound, newSize)
            if self.nextInbound is not None:
                self.nextInbound = self.resize(self.nextInbound, newSize)
            if self.weight is not None:
                self.weight = self.resize(self.weight, newSize)
            if self.capacity is not None:
                self.capacity = self.resize(self.capacity, newSize)
            if self.reverseEdge is not None:
                self.reverseEdge = self.resize(self.reverseEdge, newSize)
            self.flags = self.resize(self.flags, newSize)

    def resize(self, array, size):
        newArray = [0] * size
        for i in range(len(array)):
            newArray[i] = array[i]
        return newArray

    def addFlowWeightedEdge(self, from_, to, weight, capacity):
        if capacity == 0:
            return self.addEdge(from_, to, weight, 0, -1)
        else:
            lastEdgeCount = self.edgeCount
            self.addEdge(to, from_, -weight, 0, lastEdgeCount + self.entriesPerEdge())
            return self.addEdge(from_, to, weight, capacity, lastEdgeCount)

    def entriesPerEdge(self):
        return 1

    def vertexCount(self):
        return self.vertexCount

    def firstOutbound(self, vertex):
        id = self.firstOutbound[vertex]
        while id != -1 and self.isRemoved(id):
            id = self.nextOutbound[id]
        return id

    def nextOutbound(self, id):
        id = self.nextOutbound[id]
        while id != -1 and self.isRemoved(id):
            id = self.nextOutbound[id]
        return id

    def source(self, id):
        return self.from_[id]

    def destination(self, id):
        return self.to[id]

    def weight(self, id):
        if self.weight is None:
            return 0
        return self.weight[id]

    def capacity(self, id):
        if self.capacity is None:
            return 0
        return self.capacity[id]

    def flow(self, id):
        if self.reverseEdge is None:
            return 0
        return self.capacity[self.reverseEdge[id]]

    def pushFlow(self, id, flow):
        if flow == 0:
            return
        if flow > 0:
            if self.capacity(id) < flow:
                raise ValueError("Not enough capacity")
        else:
            if self.flow(id) < -flow:
                raise ValueError("Not enough capacity")
        self.capacity[id] -= flow
        self.capacity[self.reverseEdge[id]] += flow

    def flag(self, id, bit):
        return (self.flags[id] >> bit & 1) != 0

    def isRemoved(self, id):
        return self.flag(id, self.REMOVED_BIT)

    def createEdge(self, id):
        return GraphEdge(id)

    REMOVED_BIT = 0


class GraphEdge:
    def __init__(self, id):
        self.id = id


class MinCostFlow:
    def __init__(self, graph, source, destination, hasNegativeEdges):
        self.graph = graph
        self.source = source
        self.destination = destination
        self.vertexCount = graph.vertexCount()
        self.phi = [0] * self.vertexCount
        if hasNegativeEdges:
            self.fordBellman()
        self.dijkstraResult = [0] * self.vertexCount
        self.lastEdge = [0] * self.vertexCount
        if graph.isSparse():
            self.heap = Heap(self.vertexCount, lambda first, second: IntegerUtils.longCompare(self.dijkstraResult[first], self.dijkstraResult[second]), self.vertexCount)
            self.visited = None
        else:
            self.heap = None
            self.visited = [0] * self.vertexCount

    def fordBellman(self):
        self.phi[self.source] = 0
        inQueue = [False] * self.vertexCount
        queue = [0] * (self.vertexCount + 1)
        queue[0] = self.source
        inQueue[self.source] = True
        stepCount = 0
        head = 0
        end = 1
        maxSteps = 2 * self.vertexCount * self.vertexCount
        while head != end:
            vertex = queue[head]
            head += 1
            if head == len(queue):
                head = 0
            inQueue[vertex] = False
            edgeID = self.graph.firstOutbound(vertex)
            while edgeID != -1:
                total = self.phi[vertex] + self.graph.weight(edgeID)
                destination = self.graph.destination(edgeID)
                if self.graph.capacity(edgeID) != 0 and self.phi[destination] > total:
                    self.phi[destination] = total
                    if not inQueue[destination]:
                        queue[end] = destination
                        end += 1
                        if end == len(queue):
                            end = 0
                        inQueue[destination] = True
                edgeID = self.graph.nextOutbound(edgeID)
            stepCount += 1
            if stepCount > maxSteps:
                raise ValueError("Graph contains negative cycle")

    def minCostMaxFlow(self, maxFlow=float('inf')):
        cost = 0
        flow = 0
        while maxFlow != 0:
            if self.graph.isSparse():
                self.dijkstraAlgorithm()
            else:
                self.dijkstraAlgorithmFull()
            if self.lastEdge[self.destination] == -1:
                return (cost, flow)
            for i in range(len(self.dijkstraResult)):
                if self.dijkstraResult[i] != float('inf'):
                    self.phi[i] += self.dijkstraResult[i]
            vertex = self.destination
            currentFlow = maxFlow
            currentCost = 0
            while vertex != self.source:
                edgeID = self.lastEdge[vertex]
                currentFlow = min(currentFlow, self.graph.capacity(edgeID))
                currentCost += self.graph.weight(edgeID)
                vertex = self.graph.source(edgeID)
            maxFlow -= currentFlow
            cost += currentCost * currentFlow
            flow += currentFlow
            vertex = self.destination
            while vertex != self.source:
                edgeID = self.lastEdge[vertex]
                self.graph.pushFlow(edgeID, currentFlow)
                vertex = self.graph.source(edgeID)
        return (cost, flow)

    def dijkstraAlgorithm(self):
        self.dijkstraResult = [float('inf')] * self.vertexCount
        self.lastEdge = [-1] * self.vertexCount
        self.dijkstraResult[self.source] = 0
        self.heap.add(self.source)
        while not self.heap.isEmpty():
            current = self.heap.poll()
            edgeID = self.graph.firstOutbound(current)
            while edgeID != -1:
                if self.graph.capacity(edgeID) != 0:
                    next = self.graph.destination(edgeID)
                    total = self.graph.weight(edgeID) - self.phi[next] + self.phi[current] + self.dijkstraResult[current]
                    if self.dijkstraResult[next] > total:
                        self.dijkstraResult[next] = total
                        if self.heap.getIndex(next) == -1:
                            self.heap.add(next)
                        else:
                            self.heap.shiftUp(self.heap.getIndex(next))
                        self.lastEdge[next] = edgeID
                edgeID = self.graph.nextOutbound(edgeID)

    def dijkstraAlgorithmFull(self):
        self.visited = [0] * self.vertexCount
        self.dijkstraResult = [float('inf')] * self.vertexCount
        self.lastEdge[self.destination] = -1
        self.dijkstraResult[self.source] = 0
        for i in range(self.vertexCount):
            index = -1
            length = float('inf')
            for j in range(self.vertexCount):
                if self.visited[j] != self.visitIndex and self.dijkstraResult[j] < length:
                    length = self.dijkstraResult[j]
                    index = j
            if index == -1:
                return
            self.visited[index] = self.visitIndex
            edgeID = self.graph.firstOutbound(index)
            while edgeID != -1:
                if self.graph.capacity(edgeID) != 0:
                    next = self.graph.destination(edgeID)
                    if self.visited[next] != self.visitIndex:
                        total = self.graph.weight(edgeID) - self.phi[next] + self.phi[index] + length
                        if self.dijkstraResult[next] > total:
                            self.dijkstraResult[next] = total
                            self.lastEdge[next] = edgeID
                edgeID = self.graph.nextOutbound(edgeID)

    visitIndex = 0


class Heap:
    def __init__(self, maxElement, comparator, size):
        self.comparator = comparator
        self.size = 0
        self.elements = [0] * size
        self.at = [-1] * maxElement

    def isEmpty(self):
        return self.size == 0

    def add(self, element):
        self.ensureCapacity(self.size + 1)
        self.elements[self.size] = element
        self.at[element] = self.size
        self.shiftUp(self.size)
        self.size += 1

    def shiftUp(self, index):
        value = self.elements[index]
        while index != 0:
            parent = (index - 1) >> 1
            parentValue = self.elements[parent]
            if self.comparator(parentValue, value) <= 0:
                self.elements[index] = value
                self.at[value] = index
                return
            self.elements[index] = parentValue
            self.at[parentValue] = index
            index = parent
        self.elements[0] = value
        self.at[value] = 0

    def poll(self):
        if self.isEmpty():
            raise IndexError("Heap is empty")
        result = self.elements[0]
        self.at[result] = -1
        if self.size == 1:
            self.size = 0
            return result
        self.elements[0] = self.elements[self.size - 1]
        self.at[self.elements[0]] = 0
        self.size -= 1
        self.shiftDown(0)
        return result

    def getIndex(self, element):
        return self.at[element]

    def shiftDown(self, index):
        while True:
            child = (index << 1) + 1
            if child >= self.size:
                return
            if child + 1 < self.size and self.comparator(self.elements[child], self.elements[child + 1]) > 0:
                child += 1
            if self.comparator(self.elements[index], self.elements[child]) <= 0:
                return
            self.swap(index, child)
            index = child

    def swap(self, first, second):
        temp = self.elements[first]
        self.elements[first] = self.elements[second]
        self.elements[second] = temp
        self.at[self.elements[first]] = first
        self.at[self.elements[second]] = second

    def ensureCapacity(self, size):
        if len(self.elements) < size:
            newSize = max(size, 2 * len(self.elements))
            newElements = [0] * newSize
            for i in range(len(self.elements)):
                newElements[i] = self.elements[i]
            self.elements = newElements


class IntegerUtils:
    @staticmethod
    def longCompare(a, b):
        if a < b:
            return -1
        if a > b:
            return 1
        return 0


class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

    @staticmethod
    def makePair(first, second):
        return Pair(first, second)

    def __eq__(self, other):
        if isinstance(other, Pair):
            return self.first == other.first and self.second == other.second
        return False

    def __hash__(self):
        return hash((self.first, self.second))

    def __str__(self):
        return "(" + str(self.first) + "," + str(self.second) + ")"

    def __lt__(self, other):
        if isinstance(other, Pair):
            if self.first != other.first:
                return self.first < other.first
            return self.second < other.second
        return False


class InputReader:
    def __init__(self, stream):
        self.stream = stream

    def read(self):
        c = self.stream.read()
        while self.isSpaceChar(c):
            c = self.stream.read()
        return c

    def nextInt(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < '0' or c > '9':
                raise ValueError("Invalid input")
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def nextString(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = ""
        while not self.isSpaceChar(c):
            res += c
            c = self.read()
        return res

    @staticmethod
    def isSpaceChar(c):
        return c == ' ' or c == '\n' or c == '\r' or c == '\t' or c == -1


def main():
    inputStream = sys.stdin.buffer
    outputStream = sys.stdout.buffer
    in_ = InputReader(inputStream)
    out = OutputWriter(outputStream)
    solver = TaskF()
    solver.solve(1, in_, out)
    out.close()


class TaskF:
    def solve(self, testNumber, in_, out):
        n = in_.nextInt()
        s = in_.nextString()
        a = [0] * n
        cnt = [0] * 26
        for i in range(n):
            a[i] = in_.nextInt()
            cnt[ord(s[i]) - ord('a')] += 1
        g = Graph(n + 100)
        source = n + 100 - 2
        target = source + 1
        for i in range(n // 2):
            g.addFlowWeightedEdge(i, target, 0, 2)
        for i in range(26):
            g.addFlowWeightedEdge(source, i + n, 0, cnt[i])
            for j in range(n // 2):
                if s[j] == s[n - j - 1]:
                    w = 0
                    if s[j] == chr(i + ord('a')):
                        w = -max(a[j], a[n - j - 1])
                    g.addFlowWeightedEdge(i + n, j, w, 1)
                else:
                    w = 0
                    if s[j] == chr(i + ord('a')):
                        w -= a[j]
                    if s[n - j - 1] == chr(i + ord('a')):
                        w -= a[n - j - 1]
                    g.addFlowWeightedEdge(i + n, j, w, 1)
        mcmf = MinCostFlow(g, source, target, True)
        out.println(-mcmf.minCostMaxFlow().first)


if __name__ == "__main__":
    main()
