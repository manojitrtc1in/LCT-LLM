class Graph:
    def __init__(self, vertexCount):
        self.vertexCount = vertexCount
        self.edgeCount = 0
        self.firstOutbound = [-1] * vertexCount
        self.firstInbound = None
        self.edges = None
        self.nextInbound = None
        self.nextOutbound = None
        self.from_ = None
        self.to = None
        self.weight = None
        self.capacity = None
        self.reverseEdge = None
        self.flags = None

    def addEdge(self, fromID, toID, weight, capacity, reverseEdge):
        self.ensureEdgeCapacity(self.edgeCount + 1)
        if self.firstOutbound[fromID] != -1:
            self.nextOutbound[self.edgeCount] = self.firstOutbound[fromID]
        else:
            self.nextOutbound[self.edgeCount] = -1
        self.firstOutbound[fromID] = self.edgeCount
        if self.firstInbound is not None:
            if self.firstInbound[toID] != -1:
                self.nextInbound[self.edgeCount] = self.firstInbound[toID]
            else:
                self.nextInbound[self.edgeCount] = -1
            self.firstInbound[toID] = self.edgeCount
        self.from_[self.edgeCount] = fromID
        self.to[self.edgeCount] = toID
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
        if self.edges is not None:
            self.edges[self.edgeCount] = self.createEdge(self.edgeCount)
        self.edgeCount += 1
        return self.edgeCount - 1

    def createEdge(self, id):
        return GraphEdge(id)

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

    def isRemoved(self, id):
        return self.flag(id, 0)

    def flag(self, id, bit):
        return (self.flags[id] >> bit) & 1 != 0

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


class GraphEdge(Edge):
    def __init__(self, id):
        self.id = id


class MiscUtils:
    DX4 = [1, 0, -1, 0]
    DY4 = [0, -1, 0, 1]

    @staticmethod
    def isInside(row, column, rowCount, columnCount):
        return 0 <= row < rowCount and 0 <= column < columnCount


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
        return f"({self.first}, {self.second})"

    def __lt__(self, other):
        if isinstance(other, Pair):
            if self.first != other.first:
                return self.first < other.first
            return self.second < other.second
        return False


class IntList(IntCollection):
    def __init__(self, capacity=10):
        self.array = [0] * capacity
        self.size = 0

    def get(self, index):
        if index >= self.size:
            raise IndexError("Index out of range")
        return self.array[index]

    def size(self):
        return self.size

    def add(self, value):
        self.ensureCapacity(self.size + 1)
        self.array[self.size] = value
        self.size += 1

    def ensureCapacity(self, newCapacity):
        if newCapacity > len(self.array):
            newArray = [0] * max(newCapacity, len(self.array) << 1)
            for i in range(self.size):
                newArray[i] = self.array[i]
            self.array = newArray


class InputReader:
    def __init__(self, stream):
        self.stream = stream

    def read(self):
        c = self.stream.read(1)
        if c == "":
            return -1
        return ord(c)

    def readInt(self):
        c = self.read()
        while self.isWhitespace(c):
            c = self.read()
        sgn = 1
        if c == ord("-"):
            sgn = -1
            c = self.read()
        res = 0
        while not self.isWhitespace(c):
            if c < ord("0") or c > ord("9"):
                raise ValueError("Invalid integer")
            res *= 10
            res += c - ord("0")
            c = self.read()
        return res * sgn

    def isWhitespace(self, c):
        return c == ord(" ") or c == ord("\n") or c == ord("\r") or c == ord("\t") or c == -1


class OutputWriter:
    def __init__(self, stream):
        self.stream = stream

    def print(self, *objects):
        for i in range(len(objects)):
            if i != 0:
                self.stream.write(" ")
            self.stream.write(str(objects[i]))

    def printLine(self, *objects):
        self.print(*objects)
        self.stream.write("\n")

    def close(self):
        self.stream.close()


class IOUtils:
    @staticmethod
    def readIntList(inReader, size):
        array = IntList(size)
        for i in range(size):
            array.add(inReader.readInt())
        return array

    @staticmethod
    def readIntMatrix(inReader, rowCount, columnCount):
        matrix = []
        for i in range(rowCount):
            matrix.append(IOUtils.readIntList(inReader, columnCount))
        return matrix


class id10:
    def __init__(self, graph, source, destination, id16):
        self.graph = graph
        self.source = source
        self.destination = destination
        self.vertexCount = graph.vertexCount
        self.phi = [0] * self.vertexCount
        if id16:
            self.id11()
        self.id8 = [0] * self.vertexCount
        self.lastEdge = [0] * self.vertexCount
        self.heap = None
        self.visited = None
        self.visitIndex = 0

    def id11(self):
        self.phi = [float("inf")] * self.vertexCount
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

    def id18(self):
        self.id8 = [float("inf")] * self.vertexCount
        self.lastEdge = [-1] * self.vertexCount
        self.id8[self.source] = 0
        self.heap.clear()
        self.heap.add(self.source)
        while not self.heap.isEmpty():
            current = self.heap.poll()
            edgeID = self.graph.firstOutbound(current)
            while edgeID != -1:
                if self.graph.capacity(edgeID) != 0:
                    next = self.graph.destination(edgeID)
                    total = self.graph.weight(edgeID) - self.phi[next] + self.phi[current] + self.id8[current]
                    if self.id8[next] > total:
                        self.id8[next] = total
                        if self.heap.getIndex(next) == -1:
                            self.heap.add(next)
                        else:
                            self.heap.shiftUp(self.heap.getIndex(next))
                        self.lastEdge[next] = edgeID
                edgeID = self.graph.nextOutbound(edgeID)

    def id14(self):
        self.visitIndex += 1
        self.id8 = [float("inf")] * self.vertexCount
        self.lastEdge[self.destination] = -1
        self.id8[self.source] = 0
        for i in range(self.vertexCount):
            index = -1
            length = float("inf")
            for j in range(self.vertexCount):
                if self.visited[j] != self.visitIndex and self.id8[j] < length:
                    length = self.id8[j]
                    index = j
            if index == -1:
                return
            self.visited[index] = self.visitIndex
            edgeID = self.graph.firstOutbound(index)
            while edgeID != -1:
                if self.graph.capacity(edgeID) != 0:
                    next = self.graph.destination(edgeID)
                    if self.visited[next] != self.visitIndex:
                        total = self.graph.weight(edgeID) - self.phi[next] + self.phi[index] + self.id8[index]
                        if self.id8[next] > total:
                            self.id8[next] = total
                            self.lastEdge[next] = edgeID
                edgeID = self.graph.nextOutbound(edgeID)

    def id6(self, maxFlow=float("inf")):
        cost = 0
        flow = 0
        while maxFlow != 0:
            if self.graph.isSparse():
                self.id18()
            else:
                self.id14()
            if self.lastEdge[self.destination] == -1:
                return Pair(cost, flow)
            for i in range(len(self.id8)):
                if self.id8[i] != float("inf"):
                    self.phi[i] += self.id8[i]
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
                self.graph.addFlow(edgeID, currentFlow)
                vertex = self.graph.source(edgeID)
        return Pair(cost, flow)


class Heap:
    def __init__(self, vertexCount, intComparator, id1):
        self.list = id15(vertexCount)
        self.index = [-1] * id1

    def add(self, source):
        self.index[source] = 0
        self.list.add(source)

    def isEmpty(self):
        return self.shift == self.list.size()

    def poll(self):
        result = self.list.get(self.shift)
        self.shift += 1
        self.index[result] = -1
        return result

    def getIndex(self, next):
        return self.index[next]

    def shiftUp(self, index):
        pass

    def clear(self):
        self.list = id15()
        self.shift = 0
        self.index = [-1] * len(self.index)


class id15(IntList):
    def __init__(self, capacity=10):
        self.array = [0] * capacity
        self.size = 0

    def get(self, index):
        if index >= self.size:
            raise IndexError("Index out of range")
        return self.array[index]

    def size(self):
        return self.size

    def add(self, value):
        self.ensureCapacity(self.size + 1)
        self.array[self.size] = value
        self.size += 1

    def ensureCapacity(self, newCapacity):
        if newCapacity > len(self.array):
            newArray = [0] * max(newCapacity, len(self.array) << 1)
            for i in range(self.size):
                newArray[i] = self.array[i]
            self.array = newArray


class InputReader:
    def __init__(self, stream):
        self.stream = stream

    def read(self):
        c = self.stream.read(1)
        if c == "":
            return -1
        return ord(c)

    def readInt(self):
        c = self.read()
        while self.isWhitespace(c):
            c = self.read()
        sgn = 1
        if c == ord("-"):
            sgn = -1
            c = self.read()
        res = 0
        while not self.isWhitespace(c):
            if c < ord("0") or c > ord("9"):
                raise ValueError("Invalid integer")
            res *= 10
            res += c - ord("0")
            c = self.read()
        return res * sgn

    def isWhitespace(self, c):
        return c == ord(" ") or c == ord("\n") or c == ord("\r") or c == ord("\t") or c == -1


class OutputWriter:
    def __init__(self, stream):
        self.stream = stream

    def print(self, *objects):
        for i in range(len(objects)):
            if i != 0:
                self.stream.write(" ")
            self.stream.write(str(objects[i]))

    def printLine(self, *objects):
        self.print(*objects)
        self.stream.write("\n")

    def close(self):
        self.stream.close()


class IOUtils:
    @staticmethod
    def readIntList(inReader, size):
        array = IntList(size)
        for i in range(size):
            array.add(inReader.readInt())
        return array

    @staticmethod
    def readIntMatrix(inReader, rowCount, columnCount):
        matrix = []
        for i in range(rowCount):
            matrix.append(IOUtils.readIntList(inReader, columnCount))
        return matrix


class IntegerUtils:
    @staticmethod
    def longCompare(a, b):
        if a < b:
            return -1
        if a > b:
            return 1
        return 0


def solve():
    rowCount = inReader.readInt()
    columnCount = inReader.readInt()
    type_ = IOUtils.readIntMatrix(inReader, rowCount, columnCount)
    graph = Graph(rowCount * columnCount + 2)
    source = graph.vertexCount - 2
    sink = graph.vertexCount - 1
    for i in range(rowCount):
        for j in range(columnCount):
            index = i * columnCount + j
            if (i + j) & 1 == 0:
                graph.addEdge(source, index, 1, 0, 1)
                for k in range(4):
                    row = i + MiscUtils.DX4[k]
                    column = j + MiscUtils.DY4[k]
                    if MiscUtils.isInside(row, column, rowCount, columnCount):
                        graph.addEdge(index, row * columnCount + column, 1 if type_[i][j] == type_[row][column] else 0, 1, 1)
            else:
                graph.addEdge(index, sink, 1, 0, 1)
    out.printLine(id10(graph, source, sink, False).id6().first)


inputStream = InputStream()
outputStream = OutputStream()
inReader = InputReader(inputStream)
out = OutputWriter(outputStream)
solve()
out.close()
