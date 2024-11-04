import sys

class Main:
    @staticmethod
    def main():
        i1 = IO.readInt()
        countValue = {}
        for i2 in range(i1):
            countValue.clear()
            quantity = IO.readArrayInt(" ")
            base = IO.readArrayInt(" ")
            for i in range(quantity[2]):
                countValue[base[i]] = countValue.get(base[i], 0) + 1
            min_val = len(countValue)
            for i in range(quantity[2], quantity[0]):
                countValue[base[i - quantity[2]]] -= 1
                if countValue[base[i - quantity[2]]] == 0:
                    del countValue[base[i - quantity[2]]]
                countValue[base[i]] = countValue.get(base[i], 0) + 1
                min_val = min(min_val, len(countValue))
            IO.writeInt(min_val, "\n")
        IO.print()

class math:
    @staticmethod
    def gcd(a, b):
        if b == 0:
            return a
        return math.gcd(b, a % b)

    @staticmethod
    def lcm(a, b):
        return a // math.gcd(a, b) * b

class Division(Pair):
    def __init__(self, dividend, divider):
        super().__init__(dividend, divider)
        self.reduce()

    def reduce(self):
        if isinstance(self.getFirstElement(), int):
            Dividend = self.getFirstElement()
            Divider = self.getSecondElement()
            gcd = math.gcd(Dividend, Divider)
            self.setFirst(Dividend // gcd)
            self.setSecond(Divider // gcd)
        elif isinstance(self.getFirstElement(), float):
            Dividend = self.getFirstElement()
            Divider = self.getSecondElement()
            gcd = math.gcd(Dividend, Divider)
            self.setFirst(Dividend / gcd)
            self.setSecond(Divider / gcd)

    def addWithoutReturn(self, number):
        self.add(number, 0)

    def add(self, number, function):
        if isinstance(self.getFirstElement(), int) and isinstance(number.getFirstElement(), int):
            Dividend = self.getFirstElement()
            Divider = self.getSecondElement()
            Dividend1 = number.getFirstElement()
            Divider1 = number.getSecondElement()
            lcm = math.lcm(Divider, Divider1)
            if function == 0:
                self.setFirst((lcm // Divider) * Dividend + (lcm // Divider1) * Dividend1)
                self.setSecond(lcm)
                self.reduce()
                return None
            result = Division((lcm // Divider) * Dividend + (lcm // Divider1) * Dividend1, lcm)
            result.reduce()
            return result
        else:
            raise NotImplementedError

    def addWithReturn(self, number):
        return self.add(number, 1)

    def multiplyWithoutReturn(self, number):
        self.multiply(number, 0)

    def multiply(self, number, function):
        if isinstance(self.getFirstElement(), int) and isinstance(number.getFirstElement(), int):
            first = self.getFirstElement() * number.getFirstElement()
            second = self.getSecondElement() * number.getSecondElement()
            if function == 0:
                self.setFirst(first)
                self.setSecond(second)
                self.reduce()
                return None
            answer = Division(first, second)
            answer.reduce()
            return answer
        else:
            raise NotImplementedError

class Pair:
    def __init__(self, obj, obj1):
        self.first = obj
        self.second = obj1

    @staticmethod
    def createPair(element, element1):
        return Pair(element, element1)

    def getFirstElement(self):
        return self.first

    def getSecondElement(self):
        return self.second

    def setFirst(self, element):
        self.first = element

    def setSecond(self, element):
        self.second = element

    def __eq__(self, obj):
        if not isinstance(obj, Pair):
            return False
        pair = obj
        return self.first == pair.first and self.second == pair.second

    def __hash__(self):
        return 1

class Graph:
    def __init__(self):
        self.base = []
        self.used = []
        self.quantity = 0
        self.ancestor = []

    def getBase(self):
        return self.base.copy()

    def getUsed(self):
        return self.used.copy()

    def getQuantity(self):
        return self.quantity

    def getAncestor(self):
        return self.ancestor.copy()

    def start(self, length):
        self.used = [False] * length
        self.ancestor = [None] * length
        self.ancestor[0] = -1
        self.quantity = 0

    def ribMatrixToDefault(self, length, quantity, readConsole, value):
        self.base = [[] for _ in range(length)]
        inputBase = [[] for _ in range(length)]
        for _ in range(quantity):
            input = IO.readArrayInt(" ") if readConsole else value[_]
            inputBase[input[0] - 1].append(input[1] - 1)
            inputBase[input[1] - 1].append(input[0] - 1)
        for i in range(length):
            self.base[i] = inputBase[i].copy()
        self.start(length)

    def adjacencyMatrixToDefault(self, length, not_val, readConsole, value):
        self.base = [[] for _ in range(length)]
        buffer = []
        for i in range(length):
            InputArray = IO.readArrayInt(" ") if readConsole else value[i]
            for index in range(length):
                if i != index and InputArray[index] != not_val:
                    buffer.append(index)
            self.base[i] = buffer.copy()
            buffer.clear()
        self.start(length)

    def dfs(self, position):
        self.used[position] = True
        self.quantity += 1
        for next_pos in self.base[position]:
            if not self.used[next_pos]:
                self.ancestor[next_pos] = position
                self.dfs(next_pos)
            else:
                if next_pos != self.ancestor[position]:
                    raise Exception

    def dijkstra(self, start, stop, size):
        start -= 1
        stop -= 1
        dist = [sys.maxsize] * size
        for i in range(size):
            if i != start:
                dist[i] = sys.maxsize
            self.ancestor[i] = start

        queue = [(start, 0)]
        while queue:
            position, dist_val = queue.pop(0)
            if dist_val > dist[position]:
                continue
            for index in range(0, len(self.base[position]), 2):
                if dist[position] + self.base[position][index + 1] < dist[self.base[position][index]] and not self.used[self.base[position][index]]:
                    dist[self.base[position][index]] = dist[position] + self.base[position][index + 1]
                    self.ancestor[self.base[position][index]] = position
                    queue.append((self.base[position][index], dist[self.base[position][index]]))
            self.used[position] = True
        return dist[stop] if dist[stop] != sys.maxsize else -1

    @staticmethod
    def floydWarshall(base, length, not_val):
        for k in range(length):
            for i in range(length):
                for j in range(length):
                    if base[i][k] == not_val or base[k][j] == not_val:
                        continue
                    total = base[i][k] + base[k][j]
                    if base[i][j] != not_val:
                        base[i][j] = min(base[i][j], total)
                    else:
                        base[i][j] = total
        for index in range(length):
            if base[index][index] != 0:
                return False
        return True

class IO:
    read = None
    fileInput = False
    write = None
    fileOutput = False

    @staticmethod
    def setFileInput(fileInput):
        IO.fileInput = fileInput

    @staticmethod
    def setFileOutput(fileOutput):
        IO.fileOutput = fileOutput

    @staticmethod
    def startInput():
        try:
            IO.read = open("input.txt", "r") if IO.fileInput else sys.stdin
        except Exception as error:
            pass

    @staticmethod
    def startOutput():
        try:
            IO.write = open("output.txt", "w") if IO.fileOutput else sys.stdout
        except Exception as error:
            pass

    @staticmethod
    def readInt():
        if IO.read is None:
            IO.startInput()
        return int(IO.read.readline())

    @staticmethod
    def readLong():
        if IO.read is None:
            IO.startInput()
        return int(IO.read.readline())

    @staticmethod
    def readString():
        if IO.read is None:
            IO.startInput()
        return IO.read.readline().strip()

    @staticmethod
    def readArrayInt(split):
        if IO.read is None:
            IO.startInput()
        return list(map(int, IO.read.readline().strip().split(split)))

    @staticmethod
    def readArrayLong(split):
        if IO.read is None:
            IO.startInput()
        return list(map(int, IO.read.readline().strip().split(split)))

    @staticmethod
    def readArrayString(split):
        if IO.read is None:
            IO.startInput()
        return IO.read.readline().strip().split(split)

    @staticmethod
    def writeArray(array, split, enter):
        if IO.write is None:
            IO.startOutput()
        IO.write.write(split.join(map(str, array)))
        if enter:
            IO.writeEnter()

    @staticmethod
    def writeInt(number, end):
        if IO.write is None:
            IO.startOutput()
        IO.write.write(str(number) + end)

    @staticmethod
    def writeLong(number, end):
        if IO.write is None:
            IO.startOutput()
        IO.write.write(str(number) + end)

    @staticmethod
    def writeString(word, end):
        if IO.write is None:
            IO.startOutput()
        IO.write.write(word + end)

    @staticmethod
    def writeBoolean(value, end):
        if IO.write is None:
            IO.startOutput()
        IO.write.write(str(value).lower() + end)

    @staticmethod
    def writeChar(word, end):
        if IO.write is None:
            IO.startOutput()
        IO.write.write(word + end)

    @staticmethod
    def writeEnter():
        if IO.write is None:
            IO.startOutput()
        IO.write.write("\n")

    @staticmethod
    def print(exit_val=False):
        if exit_val:
            IO.print()
        else:
            IO.write.flush()

    @staticmethod
    def print():
        if IO.write is None:
            return
        IO.write.flush()
        if IO.read is not None:
            IO.read.close()
        IO.write.close()

if __name__ == "__main__":
    Main.main()
