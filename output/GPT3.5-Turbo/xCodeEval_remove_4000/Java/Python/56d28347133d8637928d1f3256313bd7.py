import sys
from collections import deque

class Graph:
    def __init__(self, vertexCount):
        self.vertexCount = vertexCount
        self.edgeCount = 0
        self.firstOutbound = [-1] * vertexCount
        self.firstInbound = [-1] * vertexCount
        self.edges = []
        self.nextInbound = []
        self.nextOutbound = []
        self.fromVertex = []
        self.toVertex = []
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
        self.fromVertex.append(fromID)
        self.toVertex.append(toID)
        if capacity != 0:
            self.capacity.append(capacity)
        if weight != 0:
            self.weight.append(weight)
        if reverseEdge != -1:
            self.reverseEdge.append(reverseEdge)
        self.flags.append(0)
        self.edges.append(self.createEdge(self.edgeCount))
        self.edgeCount += 1

    def createEdge(self, id):
        return Edge(id)

    def addFlow(self, id, flow):
        if flow == 0:
            return
        if flow > 0:
            if self.capacity[id] < flow:
                raise ValueError("Not enough capacity")
        else:
            if self.flow(id) < -flow:
                raise ValueError("Not enough capacity")
        self.capacity[id] -= flow
        self.capacity[self.reverseEdge[id]] += flow

    def flow(self, id):
        if self.reverseEdge is None:
            return 0
        return self.capacity[self.reverseEdge[id]]

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
        return self.fromVertex[id]

    def destination(self, id):
        return self.toVertex[id]

    def weight(self, id):
        if self.weight is None:
            return 0
        return self.weight[id]

    def capacity(self, id):
        if self.capacity is None:
            return 0
        return self.capacity[id]

    def isRemoved(self, id):
        return self.flags[id] == 1

    def ensureEdgeCapacity(self, size):
        if len(self.fromVertex) < size:
            newSize = max(size, 2 * len(self.fromVertex))
            self.fromVertex = self.resize(self.fromVertex, newSize)
            self.toVertex = self.resize(self.toVertex, newSize)
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

class Edge:
    def __init__(self, id):
        self.id = id

class MCF:
    def __init__(self, graph, source, sink):
        self.graph = graph
        self.source = source
        self.sink = sink
        self.phi = [0] * graph.vertexCount
        self.potential = [0] * graph.vertexCount
        self.lastEdge = [-1] * graph.vertexCount
        self.vertexCount = graph.vertexCount
        self.visited = [0] * graph.vertexCount
        self.visitIndex = 0

    def findMinCostFlow(self):
        cost = 0
        flow = 0
        while True:
            self.dijkstra()
            if self.lastEdge[self.sink] == -1:
                return (cost, flow)
            for i in range(self.vertexCount):
                if self.phi[i] != sys.maxsize:
                    self.potential[i] += self.phi[i]
            vertex = self.sink
            currentFlow = sys.maxsize
            currentCost = 0
            while vertex != self.source:
                edgeID = self.lastEdge[vertex]
                currentFlow = min(currentFlow, self.graph.capacity[edgeID])
                currentCost += self.graph.weight[edgeID]
                vertex = self.graph.source(edgeID)
            self.graph.addFlow(self.lastEdge[vertex], currentFlow)
            cost += currentCost * currentFlow
            flow += currentFlow
            vertex = self.sink
            while vertex != self.source:
                edgeID = self.lastEdge[vertex]
                self.graph.addFlow(edgeID, -currentFlow)
                vertex = self.graph.source(edgeID)

    def dijkstra(self):
        self.visitIndex += 1
        self.phi = [sys.maxsize] * self.vertexCount
        self.lastEdge[self.source] = -1
        self.phi[self.source] = 0
        if self.graph.isSparse():
            self.heap = Heap(self.vertexCount, self.phi)
            self.visited = None
        else:
            self.heap = None
            self.visited = [0] * self.vertexCount
        self.heap.add(self.source)
        while not self.heap.isEmpty():
            current = self.heap.poll()
            edgeID = self.graph.firstOutbound(current)
            while edgeID != -1:
                if self.graph.capacity[edgeID] != 0:
                    next = self.graph.destination(edgeID)
                    total = self.graph.weight[edgeID] - self.potential[next] + self.potential[current] + self.phi[current]
                    if self.phi[next] > total:
                        self.phi[next] = total
                        if self.heap.getIndex(next) == -1:
                            self.heap.add(next)
                        else:
                            self.heap.shiftUp(self.heap.getIndex(next))
                        self.lastEdge[next] = edgeID
                edgeID = self.graph.nextOutbound(edgeID)

class Heap:
    def __init__(self, size, keys):
        self.list = []
        self.index = [-1] * size
        for i in range(size):
            self.list.append(i)
            self.index[i] = i
        self.size = size
        self.keys = keys

    def add(self, vertex):
        self.index[vertex] = self.size
        self.list.append(vertex)
        self.shiftUp(self.size)
        self.size += 1

    def isEmpty(self):
        return self.size == 0

    def poll(self):
        result = self.list[0]
        self.index[result] = -1
        self.size -= 1
        if self.size > 0:
            self.list[0] = self.list[self.size]
            self.index[self.list[0]] = 0
            self.shiftDown(0)
        return result

    def getIndex(self, vertex):
        return self.index[vertex]

    def shiftUp(self, index):
        while index != 0:
            parent = (index - 1) >> 1
            if self.compare(self.list[index], self.list[parent]) < 0:
                self.swap(index, parent)
                index = parent
            else:
                break

    def shiftDown(self, index):
        while True:
            child = (index << 1) + 1
            if child >= self.size:
                break
            if child + 1 < self.size and self.compare(self.list[child + 1], self.list[child]) < 0:
                child += 1
            if self.compare(self.list[index], self.list[child]) <= 0:
                break
            self.swap(index, child)
            index = child

    def swap(self, first, second):
        temp = self.list[first]
        self.list[first] = self.list[second]
        self.list[second] = temp
        self.index[self.list[first]] = first
        self.index[self.list[second]] = second

    def compare(self, first, second):
        return self.keys[first] - self.keys[second]

def main():
    n, m = map(int, input().split())
    a = []
    for i in range(n):
        a.append(list(map(int, input().split())))
    shoe = m * n // 2
    dx = [-1, 0, 0, 1]
    dy = [0, -1, 1, 0]
    graph = Graph(2 * shoe + 2)
    source = 2 * shoe
    sink = 2 * shoe + 1
    for i in range(n):
        for j in range(m):
            id = i * m + j
            if (i + j) % 2 == 0:
                for z in range(4):
                    i1 = i + dx[z]
                    j1 = j + dy[z]
                    if i1 < 0 or i1 >= n or j1 < 0 or j1 >= m:
                        continue
                    id1 = i1 * m + j1
                    wt = 0 if a[i][j] == a[i1][j1] else 1
                    graph.addEdge(id, id1, wt, 1, -1)
                graph.addEdge(source, id, 0, 1, -1)
            else:
                graph.addEdge(id, sink, 0, 1, -1)
    mcf = MCF(graph, source, sink)
    ans = mcf.findMinCostFlow()
    print(ans[0])

if __name__ == "__main__":
    main()
