class InputReader:
    def __init__(self, stream):
        self.stream = stream
    
    def readIntArrays(self, *arrays):
        for i in range(len(arrays[0])):
            for j in range(len(arrays)):
                arrays[j][i] = self.readInt()
    
    def readIntArray(self, size):
        array = [0] * size
        for i in range(size):
            array[i] = self.readInt()
        return array
    
    def read(self):
        c = self.stream.read(1)
        if not c:
            return -1
        return ord(c)
    
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
            res = res * 10 + (c - ord('0'))
            c = self.read()
        return res * sgn
    
    def isSpaceChar(self, c):
        return c == ord(' ') or c == ord('\n') or c == ord('\r') or c == ord('\t') or c == -1


class OutputWriter:
    def __init__(self, stream):
        self.stream = stream
    
    def printLine(self, i):
        self.stream.write(str(i) + '\n')


class IntList:
    def __init__(self):
        self.data = []
    
    def size(self):
        return len(self.data)
    
    def get(self, at):
        return self.data[at]
    
    def addAt(self, index, value):
        self.data.insert(index, value)
    
    def removeAt(self, index):
        del self.data[index]
    
    def set(self, index, value):
        self.data[index] = value
    
    def sort(self, comparator):
        self.data.sort(key=comparator)
    
    def subList(self, fromIndex, toIndex):
        sublist = IntList()
        sublist.data = self.data[fromIndex:toIndex]
        return sublist
    
    def add(self, value):
        self.data.append(value)
    
    def toArray(self):
        return self.data.copy()


class ArrayUtils:
    @staticmethod
    def fill(array, value):
        for i in range(len(array)):
            array[i] = value
    
    @staticmethod
    def range(fromValue, toValue):
        return list(range(fromValue, toValue))
    
    @staticmethod
    def createOrder(size):
        return list(range(size))
    
    @staticmethod
    def sort(array, comparator):
        array.sort(key=comparator)
    
    @staticmethod
    def order(base):
        return sorted(range(len(base)), key=lambda i: base[i])
    
    @staticmethod
    def orderBy(base, *arrays):
        order = ArrayUtils.order(base)
        ArrayUtils.order(order, base)
        for array in arrays:
            ArrayUtils.order(order, array)
    
    @staticmethod
    def order(order, array):
        temp = [0] * len(order)
        for i in range(len(order)):
            temp[i] = array[order[i]]
        for i in range(len(order)):
            array[i] = temp[i]
    
    @staticmethod
    def createArray(count, value):
        return [value] * count


class Sorter:
    INSERTION_THRESHOLD = 16
    
    @staticmethod
    def sort(list, comparator):
        Sorter.quickSort(list, 0, list.size() - 1, (bin(list.size() - 1).count('1') * 5) >> 1, comparator)
    
    @staticmethod
    def quickSort(list, fromIndex, toIndex, remaining, comparator):
        if toIndex - fromIndex < Sorter.INSERTION_THRESHOLD:
            Sorter.insertionSort(list, fromIndex, toIndex, comparator)
            return
        if remaining == 0:
            Sorter.heapSort(list, fromIndex, toIndex, comparator)
            return
        remaining -= 1
        pivotIndex = (fromIndex + toIndex) >> 1
        pivot = list.get(pivotIndex)
        list.set(pivotIndex, list.get(toIndex))
        list.set(toIndex, pivot)
        storeIndex = fromIndex
        equalIndex = toIndex
        i = fromIndex
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
        Sorter.quickSort(list, fromIndex, storeIndex - 1, remaining, comparator)
        i = equalIndex
        while i <= toIndex:
            list.swap(storeIndex, i)
            storeIndex += 1
            i += 1
        Sorter.quickSort(list, storeIndex, toIndex, remaining, comparator)
    
    @staticmethod
    def heapSort(list, fromIndex, toIndex, comparator):
        i = (toIndex + fromIndex - 1) >> 1
        while i >= fromIndex:
            Sorter.siftDown(list, i, toIndex, comparator, fromIndex)
            i -= 1
        i = toIndex
        while i > fromIndex:
            list.swap(fromIndex, i)
            Sorter.siftDown(list, fromIndex, i - 1, comparator, fromIndex)
            i -= 1
    
    @staticmethod
    def siftDown(list, start, end, comparator, delta):
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
    def insertionSort(list, fromIndex, toIndex, comparator):
        i = fromIndex + 1
        while i <= toIndex:
            value = list.get(i)
            j = i - 1
            while j >= fromIndex:
                if comparator.compare(list.get(j), value) <= 0:
                    break
                list.swap(j, j + 1)
                j -= 1
            i += 1


class MiscUtils:
    @staticmethod
    def decreaseByOne(*arrays):
        for array in arrays:
            for i in range(len(array)):
                array[i] -= 1


class Main:
    @staticmethod
    def main():
        inputStream = sys.stdin
        outputStream = sys.stdout
        in_ = InputReader(inputStream)
        out = OutputWriter(outputStream)
        solver = Main.TaskC()
        solver.solve(1, in_, out)
        out.close()
    
    class TaskC:
        def solve(self, testNumber, in_, out):
            x = in_.readInt()
            k = in_.readInt()
            n = in_.readInt()
            q = in_.readInt()
            c = in_.readIntArray(k)
            p = [0] * q
            w = [0] * q
            in_.readIntArrays(p, w)
            ArrayUtils.orderBy(p, w)
            MiscUtils.decreaseByOne(p)
            id_ = ArrayUtils.createArray(1 << k, -1)
            byId = [0] * (1 << k)
            size = 0
            for i in range(1 << k):
                if bin(i).count('1') == x:
                    id_[i] = size
                    byId[size] = i
                    size += 1
            baseMat = [[float('inf')] * size for _ in range(size)]
            ArrayUtils.fill(baseMat, float('inf'))
            specMat = [[[float('inf')] * size for _ in range(size)] for _ in range(q)]
            ArrayUtils.fill(specMat, float('inf'))
            for i in range(size):
                ii = byId[i]
                if (ii & 1) == 0:
                    baseMat[id_[ii]][id_[ii >> 1]] = 0
                    for j in range(q):
                        specMat[j][id_[ii]][id_[ii >> 1]] = 0
                else:
                    ni = ii >> 1
                    for j in range(k):
                        if (ni >> j) & 1 == 0:
                            baseMat[id_[ii]][id_[ni + (1 << j)]] = c[j]
                            for l in range(q):
                                specMat[l][id_[ii]][id_[ni + (1 << j)]] = c[j] + w[l]
            current = [[0] * size for _ in range(size)]
            self.makeOne(current)
            temp = [[0] * size for _ in range(size)]
            temp1 = [[0] * size for _ in range(size)]
            temp2 = [[0] * size for _ in range(size)]
            start = 0
            for i in range(q + 1):
                stop = n - x
                if i < q:
                    stop = min(stop, p[i])
                self.power(baseMat, stop - start, temp1, temp2)
                self.multiply(temp, current, temp1)
                if stop == n - x:
                    current = temp
                    break
                else:
                    self.multiply(current, temp, specMat[i])
                    start = stop + 1
            answer = current[id_[(1 << x) - 1]][id_[(1 << x) - 1]]
            for i in range(q):
                if p[i] >= n - x:
                    answer += w[i]
            out.printLine(answer)
        
        def power(self, base, exponent, result, temp):
            if exponent == 0:
                self.makeOne(result)
                return
            if exponent & 1 == 0:
                self.power(base, exponent >> 1, temp, result)
                self.multiply(result, temp, temp)
            else:
                self.power(base, exponent - 1, temp, result)
                self.multiply(result, temp, base)
        
        def multiply(self, c, a, b):
            for i in range(len(c)):
                for j in range(len(c)):
                    c[i][j] = float('inf')
                    for k in range(len(c)):
                        if a[i][k] != float('inf') and b[k][j] != float('inf'):
                            c[i][j] = min(c[i][j], a[i][k] + b[k][j])
        
        def makeOne(self, current):
            ArrayUtils.fill(current, float('inf'))
            for i in range(len(current)):
                current[i][i] = 0


if __name__ == '__main__':
    Main.main()
