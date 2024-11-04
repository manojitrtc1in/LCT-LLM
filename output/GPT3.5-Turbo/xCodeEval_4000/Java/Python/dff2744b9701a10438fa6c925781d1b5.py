class Graph:
    def __init__(self, vertexCount):
        self.vertexCount = vertexCount
        self.edgeCount = 0
        self.firstOutbound = [-1] * vertexCount
        self.firstInbound = None
        self.edges = None
        self.nextInbound = None
        self.nextOutbound = None
        self.from_ = []
        self.to = []
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
        if self.edges is not None:
            self.edges[self.edgeCount] = self.createEdge(self.edgeCount)
        self.edgeCount += 1
        return self.edgeCount - 1

    def createEdge(self, id):
        return GraphEdge(id)

    def addFlowWeightedEdge(self, from_, to, weight, capacity):
        if capacity == 0:
            return self.addEdge(from_, to, weight, 0, -1)
        else:
            lastEdgeCount = self.edgeCount
            self.addEdge(to, from_, -weight, 0, lastEdgeCount + self.entriesPerEdge())
            return self.addEdge(from_, to, weight, capacity, lastEdgeCount)

    def entriesPerEdge(self):
        return 1

    def addWeightedEdge(self, from_, to, weight):
        return self.addFlowWeightedEdge(from_, to, weight, 0)

    def addSimpleEdge(self, from_, to):
        return self.addWeightedEdge(from_, to, 0)

    def edgeCapacity(self):
        return len(self.from_)

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

    def destination(self, id):
        return self.to[id]

    def flag(self, id, bit):
        return (self.flags[id] >> bit & 1) != 0

    def isRemoved(self, id):
        return self.flag(id, self.REMOVED_BIT)

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

    class GraphEdge:
        def __init__(self, id):
            self.id = id


class BidirectionalGraph(Graph):
    def __init__(self, vertexCount):
        super().__init__(vertexCount, 2 * vertexCount)
        self.transposedEdge = [0] * (2 * vertexCount)

    @staticmethod
    def createGraph(vertexCount, from_, to):
        graph = BidirectionalGraph(vertexCount, len(from_))
        for i in range(len(from_)):
            graph.addSimpleEdge(from_[i], to[i])
        return graph

    def addEdge(self, fromID, toID, weight, capacity, reverseEdge):
        lastEdgeCount = self.edgeCount
        super().addEdge(fromID, toID, weight, capacity, reverseEdge)
        super().addEdge(toID, fromID, weight, capacity, reverseEdge if reverseEdge == -1 else reverseEdge + 1)
        self.transposedEdge[lastEdgeCount] = lastEdgeCount + 1
        self.transposedEdge[lastEdgeCount + 1] = lastEdgeCount
        return lastEdgeCount


class Main:
    class TaskD:
        def __init__(self):
            self.graph = None
            self.weight = None
            self.path = None

        def solve(self, testNumber, in_, out):
            n = in_.readInt()
            k = in_.readInt()
            a = IOUtils.readIntArray(in_, n)
            u = [0] * (n - 1)
            v = [0] * (n - 1)
            IOUtils.readIntArrays(in_, u, v)
            MiscUtils.decreaseByOne(u, v)
            self.graph = BidirectionalGraph.createGraph(n, u, v)
            order = ArrayUtils.order(a)
            ArrayUtils.reverse(order)
            left = k
            right = n
            self.weight = [0] * n
            degree = [0] * n
            for i in range(n - 1):
                degree[u[i]] += 1
                degree[v[i]] += 1
            remaining = [0] * n
            queue = [0] * n
            self.path = [0] * n
            while left < right:
                middle = (left + right) >> 1
                threshold = a[order[middle - 1]]
                for i in range(n):
                    self.weight[i] = 1 if a[i] >= threshold else 0
                remaining = degree[:]
                size = 0
                for i in range(n):
                    if degree[i] == 1 and self.weight[i] > 0:
                        queue[size] = i
                        size += 1
                for i in range(size):
                    current = queue[i]
                    for j in range(self.graph.firstOutbound(current), -1, self.graph.nextOutbound(current)):
                        next_ = self.graph.destination(j)
                        if self.weight[next_] != 0:
                            self.weight[next_] += self.weight[current]
                            self.weight[current] = 0
                            remaining[next_] -= 1
                            if remaining[next_] == 1:
                                queue[size] = next_
                                size += 1
                result = self.dfs(0, -1)
                if result >= k:
                    right = middle
                else:
                    left = middle + 1
            out.printLine(a[order[left - 1]])

        def dfs(self, current, last):
            result = 0
            max_ = 0
            second = 0
            for i in range(self.graph.firstOutbound(current), -1, self.graph.nextOutbound(current)):
                next_ = self.graph.destination(i)
                if next_ == last:
                    continue
                result = max(result, self.dfs(next_, current))
                if self.path[next_] > max_:
                    second = max_
                    max_ = self.path[next_]
                else:
                    second = max(second, self.path[next_])
            if self.weight[current] != 0:
                self.path[current] = self.weight[current] + max_
                result = max(result, max_ + second + self.weight[current])
            else:
                self.path[current] = 0
            return result

    class IntArray(IntAbstractStream, IntList):
        def __init__(self, arr):
            self.data = arr

        def size(self):
            return len(self.data)

        def get(self, at):
            return self.data[at]

        def set(self, index, value):
            self.data[index] = value

    class OutputWriter:
        def __init__(self, outputStream):
            self.writer = outputStream

        def close(self):
            self.writer.close()

        def printLine(self, i):
            self.writer.println(i)

    class InputReader:
        def __init__(self, inputStream):
            self.stream = inputStream
            self.buf = [0] * 1024
            self.curChar = 0
            self.numChars = 0
            self.filter = None

        def read(self):
            if self.numChars == -1:
                raise Exception()
            if self.curChar >= self.numChars:
                self.curChar = 0
                try:
                    self.numChars = self.stream.read(self.buf)
                except IOException as e:
                    raise Exception()
                if self.numChars <= 0:
                    return -1
            return self.buf[self.curChar]

        def readInt(self):
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
                    raise Exception()
                res *= 10
                res += ord(c) - ord('0')
                c = self.read()
            return res * sgn

        def isSpaceChar(self, c):
            if self.filter is not None:
                return self.filter.isSpaceChar(c)
            return c == ' ' or c == '\n' or c == '\r' or c == '\t' or c == -1

        @staticmethod
        def isWhitespace(c):
            return c == ' ' or c == '\n' or c == '\r' or c == '\t' or c == -1

        class SpaceCharFilter:
            def isSpaceChar(self, ch):
                pass

    class IntCollection(IntStream):
        def size(self):
            pass

        def add(self, value):
            pass

        def toArray(self):
            pass

        def addAll(self, values):
            pass

    class IntStream(Iterable, Comparable):
        def intIterator(self):
            pass

        def iterator(self):
            return self.intIterator()

        def compareTo(self, c):
            pass

    class IntArrayList(IntAbstractStream, IntList):
        def __init__(self):
            self.size = 0
            self.data = []

        def __init__(self, capacity):
            self.size = 0
            self.data = [0] * capacity

        def __init__(self, c):
            self.size = c.size()
            self.data = [0] * self.size
            i = 0
            for it in c.intIterator():
                self.data[i] = it
                i += 1

        def __init__(self, c):
            self.size = 0
            self.data = c.data[:]

        def __init__(self, arr):
            self.size = arr.length
            self.data = arr.data[:]

        def size(self):
            return self.size

        def get(self, at):
            if at >= self.size:
                raise Exception()
            return self.data[at]

        def addAt(self, index, value):
            raise Exception()

        def removeAt(self, index):
            raise Exception()

        def set(self, index, value):
            if index >= self.size:
                raise Exception()
            self.data[index] = value

        def swap(self, first, second):
            if first == second:
                return
            temp = self.get(first)
            self.set(first, self.get(second))
            self.set(second, temp)

        def intIterator(self):
            return IntIterator(self)

        def add(self, value):
            self.addAt(self.size, value)

        def sort(self, comparator):
            Sorter.sort(self, comparator)
            return self

        def inPlaceReverse(self):
            for i in range(self.size // 2):
                self.swap(i, self.size - i - 1)

        def subList(self, from_, to):
            return IntList(self, from_, to)

    class IntList(IntReversableCollection):
        def get(self, index):
            pass

        def set(self, index, value):
            pass

        def addAt(self, index, value):
            pass

        def removeAt(self, index):
            pass

        def swap(self, first, second):
            pass

        def intIterator(self):
            pass

        def add(self, value):
            pass

        def sort(self, comparator):
            pass

        def inPlaceReverse(self):
            pass

        def subList(self, from_, to):
            pass

    class IntIterator:
        def value(self):
            pass

        def advance(self):
            pass

        def isValid(self):
            pass

        def remove(self):
            pass

    class MiscUtils:
        @staticmethod
        def decreaseByOne(arrays):
            for array in arrays:
                for i in range(len(array)):
                    array[i] -= 1

    class Sorter:
        @staticmethod
        def sort(list, comparator):
            pass

    class Range:
        @staticmethod
        def range(from_, to):
            result = []
            current = from_
            if from_ <= to:
                for i in range(result.length):
                    result[i] = current
                    current += 1
            else:
                for i in range(result.length):
                    result[i] = current
                    current -= 1
            return IntArray(result)

    class ArrayUtils:
        @staticmethod
        def range(from_, to):
            return Range.range(from_, to).toArray()

        @staticmethod
        def createOrder(size):
            return ArrayUtils.range(0, size)

        @staticmethod
        def sort(array, comparator):
            return ArrayUtils.sort(array, 0, len(array), comparator)

        @staticmethod
        def sort(array, from_, to, comparator):
            if from_ == 0 and to == len(array):
                IntArray(array).sort(comparator)
            else:
                IntArray(array).subList(from_, to).sort(comparator)
            return array

        @staticmethod
        def order(array):
            return ArrayUtils.sort(ArrayUtils.createOrder(len(array)), IntComparator(array))

        @staticmethod
        def reverse(array):
            IntArray(array).inPlaceReverse()


class Main:
    def main(self):
        inputStream = System.in
        outputStream = System.out
        in_ = Main.InputReader(inputStream)
        out = Main.OutputWriter(outputStream)
        solver = Main.TaskD()
        solver.solve(1, in_, out)
        out.close()


if __name__ == "__main__":
    Main().main()
