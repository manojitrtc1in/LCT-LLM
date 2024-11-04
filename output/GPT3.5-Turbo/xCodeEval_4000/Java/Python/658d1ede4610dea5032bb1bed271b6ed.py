import sys
from collections import deque

class Graph:
    def __init__(self, vertexCount):
        self.vertexCount = vertexCount
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

    def addEdge(self, from_, to, weight, capacity, reverseEdge):
        self.edges.append(Edge(len(self.edges), from_, to))
        self.from_.append(from_)
        self.to.append(to)
        self.weight.append(weight)
        self.capacity.append(capacity)
        self.reverseEdge.append(reverseEdge)
        self.flags.append(0)

        if self.firstOutbound[from_] == -1:
            self.firstOutbound[from_] = len(self.edges) - 1
        else:
            self.nextOutbound.append(self.firstOutbound[from_])
            self.firstOutbound[from_] = len(self.edges) - 1

        if self.firstInbound[to] == -1:
            self.firstInbound[to] = len(self.edges) - 1
        else:
            self.nextInbound.append(self.firstInbound[to])
            self.firstInbound[to] = len(self.edges) - 1

        return len(self.edges) - 1

    def addFlowWeightedEdge(self, from_, to, weight, capacity):
        if capacity == 0:
            return self.addEdge(from_, to, weight, 0, -1)
        else:
            lastEdgeCount = len(self.edges)
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
        return (self.flags[id] >> bit) & 1 != 0

    def isRemoved(self, id):
        return self.flag(id, self.REMOVED_BIT)

    def ensureEdgeCapacity(self, size):
        if len(self.from_) < size:
            newSize = max(size, 2 * len(self.from_))
            self.from_ += [-1] * (newSize - len(self.from_))
            self.to += [-1] * (newSize - len(self.to))
            self.nextOutbound += [-1] * (newSize - len(self.nextOutbound))
            if self.nextInbound is not None:
                self.nextInbound += [-1] * (newSize - len(self.nextInbound))
            if self.weight is not None:
                self.weight += [0] * (newSize - len(self.weight))
            if self.capacity is not None:
                self.capacity += [0] * (newSize - len(self.capacity))
            if self.reverseEdge is not None:
                self.reverseEdge += [-1] * (newSize - len(self.reverseEdge))
            self.flags += [0] * (newSize - len(self.flags))

class Edge:
    def __init__(self, id, source, destination):
        self.id = id
        self.source = source
        self.destination = destination

class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

    @staticmethod
    def makePair(first, second):
        return Pair(first, second)

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
        self.heap = []
        self.visited = [0] * self.vertexCount
        self.visitIndex = 0

    def fordBellman(self):
        self.phi[self.source] = 0
        inQueue = [False] * self.vertexCount
        queue = deque([self.source])
        inQueue[self.source] = True
        stepCount = 0
        maxSteps = 2 * self.vertexCount * self.vertexCount
        while queue:
            vertex = queue.popleft()
            inQueue[vertex] = False
            edgeID = self.graph.firstOutbound(vertex)
            while edgeID != -1:
                total = self.phi[vertex] + self.graph.weight(edgeID)
                destination = self.graph.destination(edgeID)
                if self.graph.capacity(edgeID) != 0 and self.phi[destination] > total:
                    self.phi[destination] = total
                    if not inQueue[destination]:
                        queue.append(destination)
                        inQueue[destination] = True
                edgeID = self.graph.nextOutbound(edgeID)
            stepCount += 1
            if stepCount > maxSteps:
                raise ValueError("Graph contains negative cycle")

    def minCostMaxFlow(self, maxFlow):
        cost = 0
        flow = 0
        while maxFlow != 0:
            self.dijkstraAlgorithm()
            if self.lastEdge[self.destination] == -1:
                return Pair(cost, flow)
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
        return Pair(cost, flow)

    def dijkstraAlgorithm(self):
        self.dijkstraResult = [float('inf')] * self.vertexCount
        self.lastEdge = [-1] * self.vertexCount
        self.dijkstraResult[self.source] = 0
        self.heap = [(0, self.source)]
        while self.heap:
            current = self.heap[0][1]
            heapq.heappop(self.heap)
            if self.dijkstraResult[current] < self.heap[0][0]:
                continue
            edgeID = self.graph.firstOutbound(current)
            while edgeID != -1:
                if self.graph.capacity(edgeID) != 0:
                    next_ = self.graph.destination(edgeID)
                    total = self.graph.weight(edgeID) - self.phi[next_] + self.phi[current] + self.dijkstraResult[current]
                    if self.dijkstraResult[next_] > total:
                        self.dijkstraResult[next_] = total
                        heapq.heappush(self.heap, (total, next_))
                        self.lastEdge[next_] = edgeID
                edgeID = self.graph.nextOutbound(edgeID)

def main():
    inputStream = sys.stdin
    outputStream = sys.stdout
    in_ = InputReader(inputStream)
    out = PrintWriter(outputStream)
    taskF = TaskF()
    taskF.solve(1, in_, out)
    out.close()

class TaskF:
    def solve(self, testNumber, in_, out):
        n = in_.readInt()
        s = in_.readString()
        ugliness = [-in_.readInt() for _ in range(n)]

        graph = Graph(1 + 26 + n // 2 + 1)
        for c in range(ord('a'), ord('z') + 1):
            for i in range(n // 2):
                cost = 0
                if chr(c) == s[i]:
                    cost = min(cost, ugliness[i])
                if chr(c) == s[n - 1 - i]:
                    cost = min(cost, ugliness[n - 1 - i])
                graph.addEdge(1 + (c - ord('a')), 1 + 26 + i, cost, 1, -1)

        occurs = [0] * 128
        for i in range(n):
            occurs[ord(s[i])] += 1
        for c in range(ord('a'), ord('z') + 1):
            graph.addEdge(0, 1 + (c - ord('a')), 0, occurs[c], -1)

        for i in range(n // 2):
            graph.addEdge(1 + 26 + i, 1 + 26 + n // 2, 0, 2, -1)

        flow = MinCostFlow(graph, 0, 1 + 26 + n // 2, True)
        out.println(-flow.first)

class InputReader:
    def __init__(self, stream):
        self.stream = stream

    def read(self):
        return ord(self.stream.read(1))

    def readInt(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == ord('-'):
            sgn = -1
            c = self.read()
        res = 0
        while not self.isSpaceChar(c):
            if c < ord('0') or c > ord('9'):
                raise ValueError("Invalid input")
            res *= 10
            res += c - ord('0')
            c = self.read()
        return res * sgn

    def readString(self):
        c = self.read()
        while self.isSpaceChar(c):
            c = self.read()
        res = []
        while not self.isSpaceChar(c):
            if not self.isWhitespace(c):
                res.append(chr(c))
            c = self.read()
        return ''.join(res)

    def isSpaceChar(self, c):
        return c == ord(' ') or c == ord('\n') or c == ord('\r') or c == ord('\t') or c == -1

    def isWhitespace(self, c):
        return c == ord(' ') or c == ord('\n') or c == ord('\r') or c == ord('\t')

class PrintWriter:
    def __init__(self, stream):
        self.stream = stream

    def println(self, x):
        self.stream.write(str(x) + '\n')

if __name__ == '__main__':
    main()
