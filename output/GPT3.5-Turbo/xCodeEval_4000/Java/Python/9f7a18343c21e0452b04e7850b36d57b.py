import heapq
from typing import List, Tuple

class Graph:
    def __init__(self, vertexCount: int):
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

    def addEdge(self, fromID: int, toID: int, weight: int, capacity: int, reverseEdge: int) -> int:
        self.ensureEdgeCapacity(len(self.edges) + 1)
        if self.firstOutbound[fromID] != -1:
            self.nextOutbound.append(self.firstOutbound[fromID])
        else:
            self.nextOutbound.append(-1)
        self.firstOutbound[fromID] = len(self.edges)
        if self.firstInbound is not None:
            if self.firstInbound[toID] != -1:
                self.nextInbound.append(self.firstInbound[toID])
            else:
                self.nextInbound.append(-1)
            self.firstInbound[toID] = len(self.edges)
        self.from_.append(fromID)
        self.to.append(toID)
        if capacity != 0:
            if self.capacity is None:
                self.capacity = [0] * len(self.from_)
            self.capacity.append(capacity)
        if weight != 0:
            if self.weight is None:
                self.weight = [0] * len(self.from_)
            self.weight.append(weight)
        if reverseEdge != -1:
            if self.reverseEdge is None:
                self.reverseEdge = [-1] * len(self.from_)
            self.reverseEdge.append(reverseEdge)
        if self.edges is not None:
            self.edges.append(self.createEdge(len(self.edges)))
        return len(self.edges) - 1

    def ensureEdgeCapacity(self, size: int) -> None:
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

    def resize(self, array: List[int], size: int) -> List[int]:
        newArray = [0] * size
        for i in range(len(array)):
            newArray[i] = array[i]
        return newArray

    def addFlowWeightedEdge(self, from_: int, to: int, weight: int, capacity: int) -> int:
        if capacity == 0:
            return self.addEdge(from_, to, weight, 0, -1)
        else:
            lastEdgeCount = len(self.edges)
            self.addEdge(to, from_, -weight, 0, lastEdgeCount + self.entriesPerEdge())
            return self.addEdge(from_, to, weight, capacity, lastEdgeCount)

    def entriesPerEdge(self) -> int:
        return 1

    def addFlowEdge(self, from_: int, to: int, capacity: int) -> int:
        return self.addFlowWeightedEdge(from_, to, 0, capacity)

    def vertexCount(self) -> int:
        return self.vertexCount

    def firstOutbound(self, vertex: int) -> int:
        id = self.firstOutbound[vertex]
        while id != -1 and self.isRemoved(id):
            id = self.nextOutbound[id]
        return id

    def nextOutbound(self, id: int) -> int:
        id = self.nextOutbound[id]
        while id != -1 and self.isRemoved(id):
            id = self.nextOutbound[id]
        return id

    def source(self, id: int) -> int:
        return self.from_[id]

    def destination(self, id: int) -> int:
        return self.to[id]

    def weight(self, id: int) -> int:
        if self.weight is None:
            return 0
        return self.weight[id]

    def capacity(self, id: int) -> int:
        if self.capacity is None:
            return 0
        return self.capacity[id]

    def flow(self, id: int) -> int:
        if self.reverseEdge is None:
            return 0
        return self.capacity[self.reverseEdge[id]]

    def pushFlow(self, id: int, flow: int) -> None:
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

    def flag(self, id: int, bit: int) -> bool:
        return (self.flags[id] >> bit & 1) != 0

    def isRemoved(self, id: int) -> bool:
        return self.flag(id, 0)

    class GraphEdge(Edge):
        def __init__(self, id: int):
            self.id = id

class MinCostFlow:
    def __init__(self, graph: Graph, source: int, destination: int, hasNegativeEdges: bool):
        self.graph = graph
        self.source = source
        self.destination = destination
        self.vertexCount = graph.vertexCount()
        self.phi = [0] * self.vertexCount
        if hasNegativeEdges:
            self.fordBellman()
        self.dijkstraResult = [0] * self.vertexCount
        self.lastEdge = [-1] * self.vertexCount
        self.heap = []
        self.visitIndex = 0

    def fordBellman(self) -> None:
        self.phi[self.source] = 0
        inQueue = [False] * self.vertexCount
        queue = [self.source]
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

    def dijkstraAlgorithm(self) -> None:
        self.dijkstraResult = [float('inf')] * self.vertexCount
        self.lastEdge = [-1] * self.vertexCount
        self.dijkstraResult[self.source] = 0
        heapq.heappush(self.heap, (0, self.source))
        while self.heap:
            current = heapq.heappop(self.heap)[1]
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

    def minCostMaxFlow(self, maxFlow: int = float('inf')) -> Tuple[int, int]:
        cost = 0
        flow = 0
        while maxFlow != 0:
            self.dijkstraAlgorithm()
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

class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

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

def translate_to_python():
    n, m = map(int, input().split())
    a = []
    for _ in range(n):
        a.append(list(map(int, input().split())))

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

translate_to_python()
