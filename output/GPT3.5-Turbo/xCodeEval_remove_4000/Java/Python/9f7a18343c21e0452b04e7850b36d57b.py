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
        self.fromVertex = []
        self.toVertex = []
        self.weight = []
        self.capacity = []
        self.reverseEdge = []
        self.flags = []

    def addEdge(self, fromID, toID, weight, capacity, reverseEdge):
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
        self.fromVertex.append(fromID)
        self.toVertex.append(toID)
        self.weight.append(weight)
        self.capacity.append(capacity)
        self.reverseEdge.append(reverseEdge)
        self.flags.append(0)
        return len(self.edges)

    def ensureEdgeCapacity(self, size):
        if len(self.fromVertex) < size:
            newSize = max(size, 2 * len(self.fromVertex))
            self.fromVertex.extend([-1] * (newSize - len(self.fromVertex)))
            self.toVertex.extend([-1] * (newSize - len(self.toVertex)))
            self.nextOutbound.extend([-1] * (newSize - len(self.nextOutbound)))
            if self.nextInbound is not None:
                self.nextInbound.extend([-1] * (newSize - len(self.nextInbound)))
            if self.weight is not None:
                self.weight.extend([0] * (newSize - len(self.weight)))
            if self.capacity is not None:
                self.capacity.extend([0] * (newSize - len(self.capacity)))
            if self.reverseEdge is not None:
                self.reverseEdge.extend([-1] * (newSize - len(self.reverseEdge)))
            self.flags.extend([0] * (newSize - len(self.flags)))

class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

def main():
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
            id = i * m + j
            if (i + j) % 2 == 0:
                for z in range(4):
                    i1 = i + dx[z]
                    j1 = j + dy[z]
                    if i1 < 0 or i1 >= n or j1 < 0 or j1 >= m:
                        continue
                    id1 = i1 * m + j1
                    wt = 0 if a[i][j] == a[i1][j1] else 1
                    graph.addEdge(id, id1, wt, 1, 1)
                graph.addEdge(source, id, 0, 1, 1)
            else:
                graph.addEdge(id, sink, 0, 1, 1)

    ans = mcf(graph, source, sink, False)
    print(ans.first)

def mcf(graph, source, sink, id11):
    vertexCount = graph.vertexCount
    phi = [float('inf')] * vertexCount
    if id11:
        id6(graph, source, phi)
    id13 = [float('inf')] * vertexCount
    lastEdge = [-1] * vertexCount
    heap = []
    visited = [0] * vertexCount

    def id6(graph, source, phi):
        phi[source] = 0
        inQueue = [False] * vertexCount
        queue = deque()
        queue.append(source)
        inQueue[source] = True
        stepCount = 0
        maxSteps = 2 * vertexCount * vertexCount
        while queue:
            vertex = queue.popleft()
            inQueue[vertex] = False
            edgeID = graph.firstOutbound[vertex]
            while edgeID != -1:
                total = phi[vertex] + graph.weight[edgeID]
                destination = graph.toVertex[edgeID]
                if graph.capacity[edgeID] != 0 and phi[destination] > total:
                    phi[destination] = total
                    if not inQueue[destination]:
                        queue.append(destination)
                        inQueue[destination] = True
                edgeID = graph.nextOutbound[edgeID]
            stepCount += 1
            if stepCount > maxSteps:
                raise ValueError("Graph contains negative cycle")

    def id12(graph, id13, lastEdge):
        id13[source] = 0
        heap.append(source)
        while heap:
            current = heap.pop(0)
            edgeID = graph.firstOutbound[current]
            while edgeID != -1:
                if graph.capacity[edgeID] != 0:
                    next = graph.toVertex[edgeID]
                    total = graph.weight[edgeID] - phi[next] + phi[current] + id13[current]
                    if id13[next] > total:
                        id13[next] = total
                        if next not in heap:
                            heap.append(next)
                        lastEdge[next] = edgeID
                edgeID = graph.nextOutbound[edgeID]

    def id9(graph, id13, lastEdge):
        visitIndex = 0
        id13[source] = 0
        for _ in range(vertexCount):
            index = -1
            length = float('inf')
            for j in range(vertexCount):
                if visited[j] != visitIndex and id13[j] < length:
                    length = id13[j]
                    index = j
            if index == -1:
                return
            visited[index] = visitIndex
            edgeID = graph.firstOutbound[index]
            while edgeID != -1:
                if graph.capacity[edgeID] != 0:
                    next = graph.toVertex[edgeID]
                    if visited[next] != visitIndex:
                        total = graph.weight[edgeID] - phi[next] + phi[index] + length
                        if id13[next] > total:
                            id13[next] = total
                            lastEdge[next] = edgeID
                edgeID = graph.nextOutbound[edgeID]

    id12(graph, id13, lastEdge) if graph.isSparse() else id9(graph, id13, lastEdge)

    while lastEdge[sink] != -1:
        for i in range(len(id13)):
            if id13[i] != float('inf'):
                phi[i] += id13[i]
        vertex = sink
        currentFlow = float('inf')
        currentCost = 0
        while vertex != source:
            edgeID = lastEdge[vertex]
            currentFlow = min(currentFlow, graph.capacity[edgeID])
            currentCost += graph.weight[edgeID]
            vertex = graph.fromVertex[edgeID]
        maxFlow -= currentFlow
        cost += currentCost * currentFlow
        flow += currentFlow
        vertex = sink
        while vertex != source:
            edgeID = lastEdge[vertex]
            graph.pushFlow(edgeID, currentFlow)
            vertex = graph.fromVertex[edgeID]

    return Pair(cost, flow)

if __name__ == "__main__":
    main()
