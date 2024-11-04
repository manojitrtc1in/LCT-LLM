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

    def addEdge(self, fromID, toID, weight, capacity, reverseEdge):
        edgeID = len(self.edges)
        self.edges.append(None)
        self.from_.append(fromID)
        self.to.append(toID)
        self.weight.append(weight)
        self.capacity.append(capacity)
        self.reverseEdge.append(reverseEdge)
        self.flags.append(0)

        if self.firstOutbound[fromID] != -1:
            self.nextOutbound[edgeID] = self.firstOutbound[fromID]
        else:
            self.nextOutbound[edgeID] = -1
        self.firstOutbound[fromID] = edgeID

        if self.firstInbound is not None:
            if self.firstInbound[toID] != -1:
                self.nextInbound[edgeID] = self.firstInbound[toID]
            else:
                self.nextInbound[edgeID] = -1
            self.firstInbound[toID] = edgeID

        return edgeID

    def addFlowWeightedEdge(self, from_, to, weight, capacity):
        if capacity == 0:
            return self.addEdge(from_, to, weight, 0, -1)
        else:
            lastEdgeCount = len(self.edges)
            self.addEdge(to, from_, -weight, 0, lastEdgeCount + self.entriesPerEdge())
            return self.addEdge(from_, to, weight, capacity, lastEdgeCount)

    def entriesPerEdge(self):
        return 1

    def addFlowEdge(self, from_, to, capacity):
        return self.addFlowWeightedEdge(from_, to, 0, capacity)

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
        return self.flag(id, 0)

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
        self.lastEdge = [-1] * self.vertexCount
        self.heap = Heap(self.vertexCount, self.dijkstraResult)
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

    def minCostMaxFlow(self, maxFlow=sys.maxsize):
        cost = 0
        flow = 0
        while maxFlow != 0:
            self.dijkstraAlgorithm()
            if self.lastEdge[self.destination] == -1:
                return cost, flow
            for i in range(len(self.dijkstraResult)):
                if self.dijkstraResult[i] != sys.maxsize:
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
        return cost, flow

    def dijkstraAlgorithm(self):
        self.dijkstraResult = [sys.maxsize] * self.vertexCount
        self.lastEdge = [-1] * self.vertexCount
        self.dijkstraResult[self.source] = 0
        self.heap.clear()
        self.heap.add(self.source)
        while not self.heap.isEmpty():
            current = self.heap.poll()
            edgeID = self.graph.firstOutbound(current)
            while edgeID != -1:
                if self.graph.capacity(edgeID) != 0:
                    next_ = self.graph.destination(edgeID)
                    total = self.graph.weight(edgeID) - self.phi[next_] + self.phi[current] + self.dijkstraResult[current]
                    if self.dijkstraResult[next_] > total:
                        self.dijkstraResult[next_] = total
                        if not self.heap.contains(next_):
                            self.heap.add(next_)
                        else:
                            self.heap.shiftUp(next_)
                        self.lastEdge[next_] = edgeID
                edgeID = self.graph.nextOutbound(edgeID)

class Heap:
    def __init__(self, vertexCount, dijkstraResult):
        self.list = []
        self.index = [-1] * vertexCount
        self.dijkstraResult = dijkstraResult

    def add(self, source):
        self.index[source] = 0
        self.list.append(source)

    def isEmpty(self):
        return len(self.list) == 0

    def poll(self):
        result = self.list.pop(0)
        self.index[result] = -1
        return result

    def contains(self, next_):
        return self.index[next_] != -1

    def shiftUp(self, index):
        pass

    def clear(self):
        self.list = []
        self.index = [-1] * len(self.index)

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
        return f"({self.first}, {self.second})"

    def __lt__(self, other):
        if isinstance(other, Pair):
            if self.first != other.first:
                return self.first < other.first
            return self.second < other.second
        return False

class IntArrayList(IntList):
    def __init__(self, capacity=10):
        self.array = [0] * capacity
        self.size = 0

    def get(self, index):
        if index >= self.size:
            raise IndexError()
        return self.array[index]

    def size(self):
        return self.size

    def add(self, value):
        self.ensureCapacity(self.size + 1)
        self.array[self.size] = value
        self.size += 1

    def ensureCapacity(self, newCapacity):
        if newCapacity > len(self.array):
            newArray = [0] * max(newCapacity, 2 * len(self.array))
            newArray[:self.size] = self.array[:self.size]
            self.array = newArray

class IntList(IntCollection):
    def __init__(self):
        pass

    def iterator(self):
        return IntIterator(self)

    def size(self):
        raise NotImplementedError()

    def add(self, value):
        raise NotImplementedError()

class IntIterator:
    def __init__(self, collection):
        self.collection = collection
        self.size = collection.size()
        self.index = 0

    def value(self):
        if not self.isValid():
            raise StopIteration()
        return self.collection.get(self.index)

    def advance(self):
        if not self.isValid():
            raise StopIteration()
        self.index += 1

    def isValid(self):
        return self.index < self.size

class IntegerUtils:
    @staticmethod
    def longCompare(a, b):
        if a < b:
            return -1
        if a > b:
            return 1
        return 0

def main():
    n, m = map(int, input().split())
    a = [[0] * m for _ in range(n)]
    for i in range(n):
        a[i] = list(map(int, input().split()))

    shoe = m * n // 2
    dx = [-1, 0, 0, 1]
    dy = [0, -1, 1, 0]

    graph = Graph(2 * shoe + 2)
    source = 2 * shoe
    sink = 2 * shoe + 1

    for i in range(n):
        for j in range(m):
            id_ = i * m + j
            if (i + j) % 2 == 0:
                for z in range(4):
                    i1 = i + dx[z]
                    j1 = j + dy[z]
                    if i1 < 0 or i1 >= n or j1 < 0 or j1 >= m:
                        continue
                    id1 = i1 * m + j1
                    wt = 0 if a[i][j] == a[i1][j1] else 1
                    graph.addEdge(id_, id1, wt, 1, 1)
                graph.addEdge(source, id_, 0, 1, 1)
            else:
                graph.addEdge(id_, sink, 0, 1, 1)

    mcf = MinCostFlow(graph, source, sink, False)
    ans = mcf.minCostMaxFlow()
    print(ans.first)

if __name__ == "__main__":
    main()
