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
            self.capacity.append(capacity)
        if weight != 0:
            self.weight.append(weight)
        if reverseEdge != -1:
            self.reverseEdge.append(reverseEdge)
        self.flags.append(0)
        self.edgeCount += 1
        return self.edgeCount - 1

    def ensureEdgeCapacity(self, size):
        if len(self.from_) < size:
            newSize = max(size, 2 * len(self.from_))
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
            if self.first < other.first:
                return True
            elif self.first == other.first:
                return self.second < other.second
        return False


class Heap:
    def __init__(self, maxElement, comparator=None, capacity=10):
        self.comparator = comparator
        self.size = 0
        self.elements = [0] * capacity
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
            if self.comparator.compare(parentValue, value) <= 0:
                self.elements[index] = value
                self.at[value] = index
                return
            self.elements[index] = parentValue
            self.at[parentValue] = index
            index = parent
        self.elements[0] = value
        self.at[value] = 0

    def shiftDown(self, index):
        while True:
            child = (index << 1) + 1
            if child >= self.size:
                return
            if child + 1 < self.size and self.comparator.compare(self.elements[child], self.elements[child + 1]) > 0:
                child += 1
            if self.comparator.compare(self.elements[index], self.elements[child]) <= 0:
                return
            self.swap(index, child)
            index = child

    def getIndex(self, element):
        return self.at[element]

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
            for i in range(self.size):
                newElements[i] = self.elements[i]
            self.elements = newElements

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
        self.shiftDown(0)
        self.size -= 1
        return result


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
            g.addEdge(i, target, 0, 2, -1)
        for i in range(26):
            g.addEdge(source, i + n, 0, cnt[i], -1)
            for j in range(n // 2):
                if s[j] == s[n - j - 1]:
                    w = 0
                    if s[j] == chr(i + ord('a')):
                        w = -max(a[j], a[n - j - 1])
                    g.addEdge(i + n, j, w, 1, -1)
                else:
                    w = 0
                    if s[j] == chr(i + ord('a')):
                        w -= a[j]
                    if s[n - j - 1] == chr(i + ord('a')):
                        w -= a[n - j - 1]
                    g.addEdge(i + n, j, w, 1, -1)
        id3 = id6(g, source, target, True)
        out.println(-id3.id1().first)


class InputReader:
    def __init__(self, stream):
        self.stream = stream

    def read(self):
        c = self.stream.read()
        if c == -1:
            raise EOFError()
        return c

    def nextInt(self):
        c = self.read()
        while self.isWhitespace(c):
            c = self.read()
        sgn = 1
        if c == ord('-'):
            sgn = -1
            c = self.read()
        res = 0
        while not self.isWhitespace(c):
            if c < ord('0') or c > ord('9'):
                raise ValueError("Invalid character")
            res = res * 10 + c - ord('0')
            c = self.read()
        return res * sgn

    def nextString(self):
        c = self.read()
        while self.isWhitespace(c):
            c = self.read()
        res = []
        while not self.isWhitespace(c):
            if not self.isValidCodePoint(c):
                raise ValueError("Invalid character")
            res.append(chr(c))
            c = self.read()
        return ''.join(res)

    def isWhitespace(self, c):
        return c == ord(' ') or c == ord('\n') or c == ord('\r') or c == ord('\t') or c == -1

    def isValidCodePoint(self, c):
        return c >= 0 and c <= 0x10FFFF


class OutputWriter:
    def __init__(self, stream):
        self.stream = stream

    def println(self, i):
        self.stream.write(str(i) + '\n')


def main():
    inputStream = sys.stdin.buffer
    outputStream = sys.stdout.buffer
    in_ = InputReader(inputStream)
    out = OutputWriter(outputStream)
    solver = TaskF()
    solver.solve(1, in_, out)
    out.close()


if __name__ == "__main__":
    main()
