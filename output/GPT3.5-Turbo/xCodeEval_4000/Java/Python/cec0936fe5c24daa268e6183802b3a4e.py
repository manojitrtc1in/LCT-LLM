class AMarcinAndTrainingCamp:
    def solve(self, testNumber, in, out):
        n = in.readInt()
        A = in.readLongArray(n)
        B = in.readIntArray(n)
        used = [False] * n
        order = ArrayUtils.order(A)
        res = 0
        ArrayUtils.reverse(order)
        idx = 0
        while idx < n:
            to = idx
            while to + 1 < n and A[order[to + 1]] == A[order[idx]]:
                to += 1
            valid = to > idx
            if not valid:
                i = 0
                while i < idx:
                    if used[i] and (A[order[i]] & A[order[idx]]) == A[order[idx]]:
                        valid = True
                    i += 1
            if valid:
                i = idx
                while i <= to:
                    res += B[order[i]]
                    used[i] = True
                    i += 1
            idx = to + 1
        out.printLine(res)


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
        return ArrayUtils.sort(ArrayUtils.createOrder(len(array)), lambda first, second: array[first] - array[second])

    @staticmethod
    def reverse(array):
        ArrayUtils.reverse(array, 0, len(array))

    @staticmethod
    def reverse(array, from_, to):
        if from_ == 0 and to == len(array):
            IntArray(array).inPlaceReverse()
        else:
            IntArray(array).subList(from_, to).inPlaceReverse()


class IntArray:
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

    def sort(self, comparator):
        Sorter.sort(self, comparator)
        return self

    def inPlaceReverse(self):
        for i in range(self.size() // 2):
            self.swap(i, self.size() - i - 1)

    def subList(self, from_, to):
        return IntList(self.data[from_:to])

    def swap(self, first, second):
        if first == second:
            return
        temp = self.get(first)
        self.set(first, self.get(second))
        self.set(second, temp)


class Sorter:
    INSERTION_THRESHOLD = 16

    @staticmethod
    def sort(list_, comparator):
        Sorter.quickSort(list_, 0, list_.size() - 1, (bin(list_.size() - 1).count("1") * 5) >> 1, comparator)

    @staticmethod
    def quickSort(list_, from_, to, remaining, comparator):
        if to - from_ < Sorter.INSERTION_THRESHOLD:
            Sorter.insertionSort(list_, from_, to, comparator)
            return
        if remaining == 0:
            Sorter.heapSort(list_, from_, to, comparator)
            return
        remaining -= 1
        pivotIndex = (from_ + to) >> 1
        pivot = list_.get(pivotIndex)
        list_.swap(pivotIndex, to)
        storeIndex = from_
        equalIndex = to
        i = from_
        while i < equalIndex:
            value = comparator.compare(list_.get(i), pivot)
            if value < 0:
                list_.swap(storeIndex, i)
                storeIndex += 1
            elif value == 0:
                equalIndex -= 1
                list_.swap(equalIndex, i)
                i -= 1
            i += 1
        Sorter.quickSort(list_, from_, storeIndex - 1, remaining, comparator)
        i = equalIndex
        while i <= to:
            list_.swap(storeIndex, i)
            storeIndex += 1
            i += 1
        Sorter.quickSort(list_, storeIndex, to, remaining, comparator)

    @staticmethod
    def heapSort(list_, from_, to, comparator):
        for i in range((to + from_ - 1) >> 1, from_ - 1, -1):
            Sorter.siftDown(list_, i, to, comparator, from_)
        for i in range(to, from_, -1):
            list_.swap(from_, i)
            Sorter.siftDown(list_, from_, i - 1, comparator, from_)

    @staticmethod
    def siftDown(list_, start, end, comparator, delta):
        value = list_.get(start)
        while True:
            child = ((start - delta) << 1) + 1 + delta
            if child > end:
                return
            childValue = list_.get(child)
            if child + 1 <= end:
                otherValue = list_.get(child + 1)
                if comparator.compare(otherValue, childValue) > 0:
                    child += 1
                    childValue = otherValue
            if comparator.compare(value, childValue) >= 0:
                return
            list_.swap(start, child)
            start = child

    @staticmethod
    def insertionSort(list_, from_, to, comparator):
        for i in range(from_ + 1, to + 1):
            value = list_.get(i)
            for j in range(i - 1, from_ - 1, -1):
                if comparator.compare(list_.get(j), value) <= 0:
                    break
                list_.swap(j, j + 1)


class IntList:
    def __init__(self, arr):
        self.data = arr

    def size(self):
        return len(self.data)

    def get(self, index):
        return self.data[index]

    def addAt(self, index, value):
        self.data.insert(index, value)

    def removeAt(self, index):
        self.data.pop(index)

    def set(self, index, value):
        self.data[index] = value

    def compute(self):
        return IntArrayList(self.data)


class IntArrayList(IntList):
    def __init__(self, arr):
        super().__init__(arr)

    def toArray(self):
        return self.data


class Range:
    @staticmethod
    def range(from_, to):
        return IntArray(list(range(from_, to)))


class InputReader:
    def __init__(self, stream):
        self.stream = stream

    def readLongArray(self, size):
        array = []
        for _ in range(size):
            array.append(self.readLong())
        return array

    def readIntArray(self, size):
        array = []
        for _ in range(size):
            array.append(self.readInt())
        return array

    def read(self):
        c = self.stream.read(1)
        if c == "":
            return -1
        return ord(c)

    def readInt(self):
        c = self.read()
        while InputReader.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == ord("-"):
            sgn = -1
            c = self.read()
        res = 0
        while not InputReader.isSpaceChar(c):
            if c < ord("0") or c > ord("9"):
                raise ValueError()
            res = res * 10 + (c - ord("0"))
            c = self.read()
        return res * sgn

    def readLong(self):
        c = self.read()
        while InputReader.isSpaceChar(c):
            c = self.read()
        sgn = 1
        if c == ord("-"):
            sgn = -1
            c = self.read()
        res = 0
        while not InputReader.isSpaceChar(c):
            if c < ord("0") or c > ord("9"):
                raise ValueError()
            res = res * 10 + (c - ord("0"))
            c = self.read()
        return res * sgn

    @staticmethod
    def isSpaceChar(c):
        return c == ord(" ") or c == ord("\n") or c == ord("\r") or c == ord("\t") or c == -1


class OutputWriter:
    def __init__(self, writer):
        self.writer = writer

    def close(self):
        self.writer.close()

    def printLine(self, i):
        self.writer.write(str(i) + "\n")


def main():
    inputStream = sys.stdin.buffer
    outputStream = sys.stdout.buffer
    in_ = InputReader(inputStream)
    out = OutputWriter(outputStream)
    solver = AMarcinAndTrainingCamp()
    solver.solve(1, in_, out)
    out.close()


if __name__ == "__main__":
    main()
