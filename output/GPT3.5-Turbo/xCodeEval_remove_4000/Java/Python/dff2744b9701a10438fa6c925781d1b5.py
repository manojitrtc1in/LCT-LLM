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
        return Edge(id)

    def ensureEdgeCapacity(self, size):
        if self.from_ is None or len(self.from_) < size:
            newSize = max(2 * len(self.from_), size)
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
        if array is not None:
            newArray[:len(array)] = array
        return newArray

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
        return (self.flags[id] >> bit) & 1 != 0

    def isRemoved(self, id):
        return self.flag(id, 0)

    class Edge:
        def __init__(self, id):
            self.id = id


class TaskD:
    def solve(self, testNumber, in_, out):
        n = in_.readInt()
        k = in_.readInt()
        a = IOUtils.id1(in_, n)
        u = [0] * (n - 1)
        v = [0] * (n - 1)
        IOUtils.id11(in_, u, v)
        MiscUtils.id9(u, v)
        graph = Graph.createGraph(n, u, v)
        order = ArrayUtils.order(a)
        ArrayUtils.reverse(order)
        left = k
        right = n
        weight = [0] * n
        degree = [0] * n
        for i in range(n - 1):
            degree[u[i]] += 1
            degree[v[i]] += 1
        remaining = [0] * n
        queue = [0] * n
        path = [0] * n
        while left < right:
            middle = (left + right) >> 1
            threshold = a[order[middle - 1]]
            weight = [1 if a[i] >= threshold else 0 for i in range(n)]
            remaining = degree[:]
            size = 0
            for i in range(n):
                if degree[i] == 1 and weight[i] > 0:
                    queue[size] = i
                    size += 1
            for i in range(size):
                current = queue[i]
                for j in range(graph.firstOutbound(current), -1, graph.nextOutbound(j)):
                    next_ = graph.destination(j)
                    if weight[next_] != 0:
                        weight[next_] += weight[current]
                        weight[current] = 0
                        remaining[next_] -= 1
                        if remaining[next_] == 1:
                            queue[size] = next_
                            size += 1
            result = self.dfs(0, -1, graph, weight, path)
            if result >= k:
                right = middle
            else:
                left = middle + 1
        out.printLine(a[order[left - 1]])

    def dfs(self, current, last, graph, weight, path):
        result = 0
        max_ = 0
        second = 0
        for i in range(graph.firstOutbound(current), -1, graph.nextOutbound(i)):
            next_ = graph.destination(i)
            if next_ == last:
                continue
            result = max(result, self.dfs(next_, current, graph, weight, path))
            if path[next_] > max_:
                second = max_
                max_ = path[next_]
            else:
                second = max(second, path[next_])
        if weight[current] != 0:
            path[current] = weight[current] + max_
            result = max(result, max_ + second + weight[current])
        else:
            path[current] = 0
        return result


class IntArray(id5):
    def __init__(self, arr):
        self.data = arr

    def size(self):
        return len(self.data)

    def get(self, at):
        return self.data[at]

    def addAt(self, index, value):
        raise NotImplementedError()

    def removeAt(self, index):
        raise NotImplementedError()

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
            raise InputMismatchException()
        if self.curChar >= self.numChars:
            self.curChar = 0
            try:
                self.numChars = self.stream.read(self.buf)
            except IOException as e:
                raise InputMismatchException()
            if self.numChars <= 0:
                return -1
        return self.buf[self.curChar]

    def readInt(self):
        c = self.read()
        while id4(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not id4(c):
            if c < '0' or c > '9':
                raise InputMismatchException()
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def id4(self, c):
        if self.filter is not None:
            return self.filter.id4(c)
        return self.isWhitespace(c)

    @staticmethod
    def isWhitespace(c):
        return c == ' ' or c == '\n' or c == '\r' or c == '\t' or c == -1


class IntCollection(IntStream):
    def size(self):
        raise NotImplementedError()

    def add(self, value):
        raise NotImplementedError()

    def toArray(self):
        size = self.size()
        array = [0] * size
        i = 0
        it = self.intIterator()
        while it.isValid():
            array[i] = it.value()
            i += 1
            it.advance()
        return array

    def addAll(self, values):
        it = values.intIterator()
        while it.isValid():
            self.add(it.value())
            it.advance()


class IntStream(Iterable):
    def intIterator(self):
        raise NotImplementedError()

    def iterator(self):
        return Iterator(self)

    def compareTo(self, c):
        it = self.intIterator()
        jt = c.intIterator()
        while it.isValid() and jt.isValid():
            i = it.value()
            j = jt.value()
            if i < j:
                return -1
            elif i > j:
                return 1
            it.advance()
            jt.advance()
        if it.isValid():
            return 1
        if jt.isValid():
            return -1
        return 0


class id18(IntCollection):
    def __init__(self):
        self.size = 0
        self.data = []

    def __init__(self, capacity):
        self.data = [0] * capacity

    def __init__(self, c):
        self.size = c.size()
        self.data = c.toArray()

    def __init__(self, c):
        self.size = 0
        self.data = []
        self.addAll(c)

    def __init__(self, c):
        self.size = c.size()
        self.data = c.toArray()

    def __init__(self, arr):
        self.size = len(arr)
        self.data = arr

    def size(self):
        return self.size

    def get(self, at):
        if at >= self.size:
            raise IndexError("at = " + str(at) + ", size = " + str(self.size))
        return self.data[at]

    def ensureCapacity(self, capacity):
        if len(self.data) >= capacity:
            return
        capacity = max(2 * len(self.data), capacity)
        self.data = self.data[:capacity]

    def addAt(self, index, value):
        self.ensureCapacity(self.size + 1)
        if index > self.size or index < 0:
            raise IndexError("at = " + str(index) + ", size = " + str(self.size))
        if index != self.size:
            self.data[index + 1:self.size + 1] = self.data[index:self.size]
        self.data[index] = value
        self.size += 1

    def removeAt(self, index):
        if index >= self.size or index < 0:
            raise IndexError("at = " + str(index) + ", size = " + str(self.size))
        if index != self.size - 1:
            self.data[index:self.size - 1] = self.data[index + 1:self.size]
        self.size -= 1

    def set(self, index, value):
        if index >= self.size:
            raise IndexError("at = " + str(index) + ", size = " + str(self.size))
        self.data[index] = value


class id17(IntCollection):
    pass


class Sorter:
    @staticmethod
    def sort(list, comparator):
        Sorter.quickSort(list, 0, list.size() - 1, (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
                          comparator)

    @staticmethod
    def quickSort(list, from_, to, remaining, comparator):
        if to - from_ < id16:
            Sorter.id6(list, from_, to, comparator)
            return
        if remaining == 0:
            Sorter.heapSort(list, from_, to, comparator)
            return
        remaining -= 1
        pivotIndex = (from_ + to) >> 1
        pivot = list.get(pivotIndex)
        list.swap(pivotIndex, to)
        storeIndex = from_
        equalIndex = to
        i = from_
        while i < equalIndex:
            value = comparator.compare(list.get(i), pivot)
            if value < 0:
                list.swap(storeIndex, i)
                storeIndex += 1
            elif value == 0:
                equalIndex -= 1
                list.swap(equalIndex, i)
                i -= 1
            i += 1
        Sorter.quickSort(list, from_, storeIndex - 1, remaining, comparator)
        i = equalIndex
        while i <= to:
            list.swap(storeIndex, i)
            storeIndex += 1
            i += 1
        Sorter.quickSort(list, storeIndex, to, remaining, comparator)

    @staticmethod
    def heapSort(list, from_, to, comparator):
        for i in range((to + from_ - 1) >> 1, from_ - 1, -1):
            Sorter.id2(list, i, to, comparator, from_)
        for i in range(to, from_, -1):
            list.swap(from_, i)
            Sorter.id2(list, from_, i - 1, comparator, from_)

    @staticmethod
    def id2(list, start, end, comparator, delta):
        value = list.get(start)
        while True:
            child = ((start - delta) << 1) + 1 + delta
            if child > end:
                return
            childValue = list.get(child)
            if child + 1 <= end:
                otherValue = list.get(child + 1)
                if comparator.compare(otherValue, childValue) > 0:
                    child += 1
                    childValue = otherValue
            if comparator.compare(value, childValue) >= 0:
                return
            list.swap(start, child)
            start = child

    @staticmethod
    def id6(list, from_, to, comparator):
        for i in range(from_ + 1, to + 1):
            value = list.get(i)
            for j in range(i - 1, from_ - 1, -1):
                if comparator.compare(list.get(j), value) <= 0:
                    break
                list.swap(j, j + 1)


class Range:
    @staticmethod
    def range(from_, to):
        result = []
        current = from_
        if from_ <= to:
            while current <= to:
                result.append(current)
                current += 1
        else:
            while current >= to:
                result.append(current)
                current -= 1
        return result


class ArrayUtils:
    @staticmethod
    def range(from_, to):
        return Range.range(from_, to)

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
        IntArray(array).id8()


class IntComparator:
    def __init__(self, array):
        self.array = array

    def compare(self, first, second):
        if self.array[first] < self.array[second]:
            return -1
        if self.array[first] > self.array[second]:
            return 1
        return 0


class GraphEdge(Edge):
    def __init__(self, id):
        super().__init__(id)


class IOUtils:
    @staticmethod
    def id1(in_, size):
        array = [0] * size
        for i in range(size):
            array[i] = in_.readInt()
        return array

    @staticmethod
    def id11(in_, *arrays):
        for i in range(len(arrays[0])):
            for j in range(len(arrays)):
                arrays[j][i] = in_.readInt()


class MiscUtils:
    @staticmethod
    def id9(*arrays):
        for array in arrays:
            for i in range(len(array)):
                array[i] -= 1


class InputMismatchException(Exception):
    pass


class IntIterator:
    def __init__(self, collection):
        self.collection = collection
        self.at = 0
        self.removed = False

    def value(self):
        if self.removed:
            raise IllegalStateException()
        return self.collection.get(self.at)

    def advance(self):
        self.at += 1
        self.removed = False
        return self.isValid()

    def isValid(self):
        return not self.removed and self.at < self.collection.size()

    def remove(self):
        self.collection.removeAt(self.at)
        self.at -= 1
        self.removed = True


class IllegalStateException(Exception):
    pass


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
            raise InputMismatchException()
        if self.curChar >= self.numChars:
            self.curChar = 0
            try:
                self.numChars = self.stream.read(self.buf)
            except IOException as e:
                raise InputMismatchException()
            if self.numChars <= 0:
                return -1
        return self.buf[self.curChar]

    def readInt(self):
        c = self.read()
        while id4(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not id4(c):
            if c < '0' or c > '9':
                raise InputMismatchException()
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def id4(self, c):
        if self.filter is not None:
            return self.filter.id4(c)
        return self.isWhitespace(c)

    @staticmethod
    def isWhitespace(c):
        return c == ' ' or c == '\n' or c == '\r' or c == '\t' or c == -1


class IntCollection(IntStream):
    def size(self):
        raise NotImplementedError()

    def add(self, value):
        raise NotImplementedError()

    def toArray(self):
        size = self.size()
        array = [0] * size
        i = 0
        it = self.intIterator()
        while it.isValid():
            array[i] = it.value()
            i += 1
            it.advance()
        return array

    def addAll(self, values):
        it = values.intIterator()
        while it.isValid():
            self.add(it.value())
            it.advance()


class IntStream(Iterable):
    def intIterator(self):
        raise NotImplementedError()

    def iterator(self):
        return Iterator(self)

    def compareTo(self, c):
        it = self.intIterator()
        jt = c.intIterator()
        while it.isValid() and jt.isValid():
            i = it.value()
            j = jt.value()
            if i < j:
                return -1
            elif i > j:
                return 1
            it.advance()
            jt.advance()
        if it.isValid():
            return 1
        if jt.isValid():
            return -1
        return 0


class id18(IntCollection):
    def __init__(self):
        self.size = 0
        self.data = []

    def __init__(self, capacity):
        self.data = [0] * capacity

    def __init__(self, c):
        self.size = c.size()
        self.data = c.toArray()

    def __init__(self, c):
        self.size = 0
        self.data = []
        self.addAll(c)

    def __init__(self, c):
        self.size = c.size()
        self.data = c.toArray()

    def __init__(self, arr):
        self.size = len(arr)
        self.data = arr

    def size(self):
        return self.size

    def get(self, at):
        if at >= self.size:
            raise IndexError("at = " + str(at) + ", size = " + str(self.size))
        return self.data[at]

    def ensureCapacity(self, capacity):
        if len(self.data) >= capacity:
            return
        capacity = max(2 * len(self.data), capacity)
        self.data = self.data[:capacity]

    def addAt(self, index, value):
        self.ensureCapacity(self.size + 1)
        if index > self.size or index < 0:
            raise IndexError("at = " + str(index) + ", size = " + str(self.size))
        if index != self.size:
            self.data[index + 1:self.size + 1] = self.data[index:self.size]
        self.data[index] = value
        self.size += 1

    def removeAt(self, index):
        if index >= self.size or index < 0:
            raise IndexError("at = " + str(index) + ", size = " + str(self.size))
        if index != self.size - 1:
            self.data[index:self.size - 1] = self.data[index + 1:self.size]
        self.size -= 1

    def set(self, index, value):
        if index >= self.size:
            raise IndexError("at = " + str(index) + ", size = " + str(self.size))
        self.data[index] = value


class id17(IntCollection):
    pass


class Sorter:
    @staticmethod
    def sort(list, comparator):
        Sorter.quickSort(list, 0, list.size() - 1, (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
                          comparator)

    @staticmethod
    def quickSort(list, from_, to, remaining, comparator):
        if to - from_ < id16:
            Sorter.id6(list, from_, to, comparator)
            return
        if remaining == 0:
            Sorter.heapSort(list, from_, to, comparator)
            return
        remaining -= 1
        pivotIndex = (from_ + to) >> 1
        pivot = list.get(pivotIndex)
        list.swap(pivotIndex, to)
        storeIndex = from_
        equalIndex = to
        i = from_
        while i < equalIndex:
            value = comparator.compare(list.get(i), pivot)
            if value < 0:
                list.swap(storeIndex, i)
                storeIndex += 1
            elif value == 0:
                equalIndex -= 1
                list.swap(equalIndex, i)
                i -= 1
            i += 1
        Sorter.quickSort(list, from_, storeIndex - 1, remaining, comparator)
        i = equalIndex
        while i <= to:
            list.swap(storeIndex, i)
            storeIndex += 1
            i += 1
        Sorter.quickSort(list, storeIndex, to, remaining, comparator)

    @staticmethod
    def heapSort(list, from_, to, comparator):
        for i in range((to + from_ - 1) >> 1, from_ - 1, -1):
            Sorter.id2(list, i, to, comparator, from_)
        for i in range(to, from_, -1):
            list.swap(from_, i)
            Sorter.id2(list, from_, i - 1, comparator, from_)

    @staticmethod
    def id2(list, start, end, comparator, delta):
        value = list.get(start)
        while True:
            child = ((start - delta) << 1) + 1 + delta
            if child > end:
                return
            childValue = list.get(child)
            if child + 1 <= end:
                otherValue = list.get(child + 1)
                if comparator.compare(otherValue, childValue) > 0:
                    child += 1
                    childValue = otherValue
            if comparator.compare(value, childValue) >= 0:
                return
            list.swap(start, child)
            start = child

    @staticmethod
    def id6(list, from_, to, comparator):
        for i in range(from_ + 1, to + 1):
            value = list.get(i)
            for j in range(i - 1, from_ - 1, -1):
                if comparator.compare(list.get(j), value) <= 0:
                    break
                list.swap(j, j + 1)


class Range:
    @staticmethod
    def range(from_, to):
        result = []
        current = from_
        if from_ <= to:
            while current <= to:
                result.append(current)
                current += 1
        else:
            while current >= to:
                result.append(current)
                current -= 1
        return result


class ArrayUtils:
    @staticmethod
    def range(from_, to):
        return Range.range(from_, to)

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
        IntArray(array).id8()


class IntComparator:
    def __init__(self, array):
        self.array = array

    def compare(self, first, second):
        if self.array[first] < self.array[second]:
            return -1
        if self.array[first] > self.array[second]:
            return 1
        return 0


class GraphEdge(Edge):
    def __init__(self, id):
        super().__init__(id)


class IOUtils:
    @staticmethod
    def id1(in_, size):
        array = [0] * size
        for i in range(size):
            array[i] = in_.readInt()
        return array

    @staticmethod
    def id11(in_, *arrays):
        for i in range(len(arrays[0])):
            for j in range(len(arrays)):
                arrays[j][i] = in_.readInt()


class MiscUtils:
    @staticmethod
    def id9(*arrays):
        for array in arrays:
            for i in range(len(array)):
                array[i] -= 1


class InputMismatchException(Exception):
    pass


class IntIterator:
    def __init__(self, collection):
        self.collection = collection
        self.at = 0
        self.removed = False

    def value(self):
        if self.removed:
            raise IllegalStateException()
        return self.collection.get(self.at)

    def advance(self):
        self.at += 1
        self.removed = False
        return self.isValid()

    def isValid(self):
        return not self.removed and self.at < self.collection.size()

    def remove(self):
        self.collection.removeAt(self.at)
        self.at -= 1
        self.removed = True


class IllegalStateException(Exception):
    pass


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
            raise InputMismatchException()
        if self.curChar >= self.numChars:
            self.curChar = 0
            try:
                self.numChars = self.stream.read(self.buf)
            except IOException as e:
                raise InputMismatchException()
            if self.numChars <= 0:
                return -1
        return self.buf[self.curChar]

    def readInt(self):
        c = self.read()
        while id4(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not id4(c):
            if c < '0' or c > '9':
                raise InputMismatchException()
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def id4(self, c):
        if self.filter is not None:
            return self.filter.id4(c)
        return self.isWhitespace(c)

    @staticmethod
    def isWhitespace(c):
        return c == ' ' or c == '\n' or c == '\r' or c == '\t' or c == -1


class IntCollection(IntStream):
    def size(self):
        raise NotImplementedError()

    def add(self, value):
        raise NotImplementedError()

    def toArray(self):
        size = self.size()
        array = [0] * size
        i = 0
        it = self.intIterator()
        while it.isValid():
            array[i] = it.value()
            i += 1
            it.advance()
        return array

    def addAll(self, values):
        it = values.intIterator()
        while it.isValid():
            self.add(it.value())
            it.advance()


class IntStream(Iterable):
    def intIterator(self):
        raise NotImplementedError()

    def iterator(self):
        return Iterator(self)

    def compareTo(self, c):
        it = self.intIterator()
        jt = c.intIterator()
        while it.isValid() and jt.isValid():
            i = it.value()
            j = jt.value()
            if i < j:
                return -1
            elif i > j:
                return 1
            it.advance()
            jt.advance()
        if it.isValid():
            return 1
        if jt.isValid():
            return -1
        return 0


class id18(IntCollection):
    def __init__(self):
        self.size = 0
        self.data = []

    def __init__(self, capacity):
        self.data = [0] * capacity

    def __init__(self, c):
        self.size = c.size()
        self.data = c.toArray()

    def __init__(self, c):
        self.size = 0
        self.data = []
        self.addAll(c)

    def __init__(self, c):
        self.size = c.size()
        self.data = c.toArray()

    def __init__(self, arr):
        self.size = len(arr)
        self.data = arr

    def size(self):
        return self.size

    def get(self, at):
        if at >= self.size:
            raise IndexError("at = " + str(at) + ", size = " + str(self.size))
        return self.data[at]

    def ensureCapacity(self, capacity):
        if len(self.data) >= capacity:
            return
        capacity = max(2 * len(self.data), capacity)
        self.data = self.data[:capacity]

    def addAt(self, index, value):
        self.ensureCapacity(self.size + 1)
        if index > self.size or index < 0:
            raise IndexError("at = " + str(index) + ", size = " + str(self.size))
        if index != self.size:
            self.data[index + 1:self.size + 1] = self.data[index:self.size]
        self.data[index] = value
        self.size += 1

    def removeAt(self, index):
        if index >= self.size or index < 0:
            raise IndexError("at = " + str(index) + ", size = " + str(self.size))
        if index != self.size - 1:
            self.data[index:self.size - 1] = self.data[index + 1:self.size]
        self.size -= 1

    def set(self, index, value):
        if index >= self.size:
            raise IndexError("at = " + str(index) + ", size = " + str(self.size))
        self.data[index] = value


class id17(IntCollection):
    pass


class Sorter:
    @staticmethod
    def sort(list, comparator):
        Sorter.quickSort(list, 0, list.size() - 1, (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
                          comparator)

    @staticmethod
    def quickSort(list, from_, to, remaining, comparator):
        if to - from_ < id16:
            Sorter.id6(list, from_, to, comparator)
            return
        if remaining == 0:
            Sorter.heapSort(list, from_, to, comparator)
            return
        remaining -= 1
        pivotIndex = (from_ + to) >> 1
        pivot = list.get(pivotIndex)
        list.swap(pivotIndex, to)
        storeIndex = from_
        equalIndex = to
        i = from_
        while i < equalIndex:
            value = comparator.compare(list.get(i), pivot)
            if value < 0:
                list.swap(storeIndex, i)
                storeIndex += 1
            elif value == 0:
                equalIndex -= 1
                list.swap(equalIndex, i)
                i -= 1
            i += 1
        Sorter.quickSort(list, from_, storeIndex - 1, remaining, comparator)
        i = equalIndex
        while i <= to:
            list.swap(storeIndex, i)
            storeIndex += 1
            i += 1
        Sorter.quickSort(list, storeIndex, to, remaining, comparator)

    @staticmethod
    def heapSort(list, from_, to, comparator):
        for i in range((to + from_ - 1) >> 1, from_ - 1, -1):
            Sorter.id2(list, i, to, comparator, from_)
        for i in range(to, from_, -1):
            list.swap(from_, i)
            Sorter.id2(list, from_, i - 1, comparator, from_)

    @staticmethod
    def id2(list, start, end, comparator, delta):
        value = list.get(start)
        while True:
            child = ((start - delta) << 1) + 1 + delta
            if child > end:
                return
            childValue = list.get(child)
            if child + 1 <= end:
                otherValue = list.get(child + 1)
                if comparator.compare(otherValue, childValue) > 0:
                    child += 1
                    childValue = otherValue
            if comparator.compare(value, childValue) >= 0:
                return
            list.swap(start, child)
            start = child

    @staticmethod
    def id6(list, from_, to, comparator):
        for i in range(from_ + 1, to + 1):
            value = list.get(i)
            for j in range(i - 1, from_ - 1, -1):
                if comparator.compare(list.get(j), value) <= 0:
                    break
                list.swap(j, j + 1)


class Range:
    @staticmethod
    def range(from_, to):
        result = []
        current = from_
        if from_ <= to:
            while current <= to:
                result.append(current)
                current += 1
        else:
            while current >= to:
                result.append(current)
                current -= 1
        return result


class ArrayUtils:
    @staticmethod
    def range(from_, to):
        return Range.range(from_, to)

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
        IntArray(array).id8()


class IntComparator:
    def __init__(self, array):
        self.array = array

    def compare(self, first, second):
        if self.array[first] < self.array[second]:
            return -1
        if self.array[first] > self.array[second]:
            return 1
        return 0


class GraphEdge(Edge):
    def __init__(self, id):
        super().__init__(id)


class IOUtils:
    @staticmethod
    def id1(in_, size):
        array = [0] * size
        for i in range(size):
            array[i] = in_.readInt()
        return array

    @staticmethod
    def id11(in_, *arrays):
        for i in range(len(arrays[0])):
            for j in range(len(arrays)):
                arrays[j][i] = in_.readInt()


class MiscUtils:
    @staticmethod
    def id9(*arrays):
        for array in arrays:
            for i in range(len(array)):
                array[i] -= 1


class InputMismatchException(Exception):
    pass


class IntIterator:
    def __init__(self, collection):
        self.collection = collection
        self.at = 0
        self.removed = False

    def value(self):
        if self.removed:
            raise IllegalStateException()
        return self.collection.get(self.at)

    def advance(self):
        self.at += 1
        self.removed = False
        return self.isValid()

    def isValid(self):
        return not self.removed and self.at < self.collection.size()

    def remove(self):
        self.collection.removeAt(self.at)
        self.at -= 1
        self.removed = True


class IllegalStateException(Exception):
    pass


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
            raise InputMismatchException()
        if self.curChar >= self.numChars:
            self.curChar = 0
            try:
                self.numChars = self.stream.read(self.buf)
            except IOException as e:
                raise InputMismatchException()
            if self.numChars <= 0:
                return -1
        return self.buf[self.curChar]

    def readInt(self):
        c = self.read()
        while id4(c):
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while not id4(c):
            if c < '0' or c > '9':
                raise InputMismatchException()
            res *= 10
            res += ord(c) - ord('0')
            c = self.read()
        return res * sgn

    def id4(self, c):
        if self.filter is not None:
            return self.filter.id4(c)
        return self.isWhitespace(c)

    @staticmethod
    def isWhitespace(c):
        return c == ' ' or c == '\n' or c == '\r' or c == '\t' or c == -1


class IntCollection(IntStream):
    def size(self):
        raise NotImplementedError()

    def add(self, value):
        raise NotImplementedError()

    def toArray(self):
        size = self.size()
        array = [0] * size
        i = 0
        it = self.intIterator()
        while it.isValid():
            array[i] = it.value()
            i += 1
            it.advance()
        return array

    def addAll(self, values):
        it = values.intIterator()
        while it.isValid():
            self.add(it.value())
            it.advance()


class IntStream(Iterable):
    def intIterator(self):
        raise NotImplementedError()

    def iterator(self):
        return Iterator(self)

    def compareTo(self, c):
        it = self.intIterator()
        jt = c.intIterator()
        while it.isValid() and jt.isValid():
            i = it.value()
            j = jt.value()
            if i < j:
                return -1
            elif i > j:
                return 1
            it.advance()
            jt.advance()
        if it.isValid():
            return 1
        if jt.isValid():
            return -1
        return 0


class id18(IntCollection):
    def __init__(self):
        self.size = 0
        self.data = []

    def __init__(self, capacity):
        self.data = [0] * capacity

    def __init__(self, c):
        self.size = c.size()
        self.data = c.toArray()

    def __init__(self, c):
        self.size = 0
        self.data = []
        self.addAll(c)

    def __init__(self, c):
        self.size = c.size()
        self.data = c.toArray()

    def __init__(self, arr):
        self.size = len(arr)
        self.data = arr

    def size(self):
        return self.size

    def get(self, at):
        if at >= self.size:
            raise IndexError("at = " + str(at) + ", size = " + str(self.size))
        return self.data[at]

    def ensureCapacity(self, capacity):
        if len(self.data) >= capacity:
            return
        capacity = max(2 * len(self.data), capacity)
        self.data = self.data[:capacity]

    def addAt(self, index, value):
        self.ensureCapacity(self.size + 1)
        if index > self.size or index < 0:
            raise IndexError("at = " + str(index) + ", size = " + str(self.size))
        if index != self.size:
            self.data[index + 1:self.size + 1] = self.data[index:self.size]
        self.data[index] = value
        self.size += 1

    def removeAt(self, index):
        if index >= self.size or index < 0:
            raise IndexError("at = " + str(index) + ", size = " + str(self.size))
        if index != self.size - 1:
            self.data[index:self.size - 1] = self.data[index + 1:self.size]
        self.size -= 1

    def set(self, index, value):
        if index >= self.size:
            raise IndexError("at = " + str(index) + ", size = " + str(self.size))
        self.data[index] = value


class id17(IntCollection):
    pass


class Sorter:
    @staticmethod
    def sort(list, comparator):
        Sorter.quickSort(list, 0, list.size() - 1, (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
                          comparator)

    @staticmethod
    def quickSort(list, from_, to, remaining, comparator):
        if to - from_ < id16:
            Sorter.id6(list, from_, to, comparator)
            return
        if remaining == 0:
            Sorter.heapSort(list, from_, to, comparator)
            return
        remaining -= 1
        pivotIndex = (from_ + to) >> 1
        pivot = list.get(pivotIndex)
        list.swap(pivotIndex, to)
        storeIndex = from_
        equalIndex = to
        i = from_
        while i < equalIndex:
            value = comparator.compare(list.get(i), pivot)
            if value < 0:
                list.swap(storeIndex, i)
                storeIndex += 1
            elif value == 0:
                equalIndex -= 1
                list.swap(equalIndex, i)
                i -= 1
            i += 1
        Sorter.quickSort(list, from_, storeIndex - 1, remaining, comparator)
        i = equalIndex
        while i <= to:
            list.swap(storeIndex, i)
            storeIndex += 1
            i += 1
        Sorter.quickSort(list, storeIndex, to, remaining, comparator)

    @staticmethod
    def heapSort(list, from_, to, comparator):
        for i in range((to + from_ - 1) >> 1, from_ - 1, -1):
            Sorter.id2(list, i, to, comparator, from_)
        for i in range(to, from_, -1):
            list.swap(from_, i)
            Sorter.id2(list, from_, i - 1, comparator, from_)

    @staticmethod
    def id2(list, start, end, comparator, delta):
