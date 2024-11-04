class Main:
    @staticmethod
    def main(args):
        g = IO.readInt()
        sh = IO.readInt()
        j = IO.readInt()
        p = IO.readInt()
        priceFirst = IO.readInt()
        priceSecond = IO.readInt()
        answer = 0
        if priceFirst <= priceSecond:
            answer = min(min(sh, j), p)
            p -= answer
            answer *= priceSecond
            answer += (min(p, g) * priceFirst)
        else:
            answer = min(g, p)
            p -= answer
            answer *= priceFirst
            answer += (min(min(sh, j), p) * priceSecond)
        IO.writeInt(answer, "\n")
        
class math:
    remains = 0x989687
    
    @staticmethod
    def gcd(a, b):
        if b == 0:
            return a
        return math.gcd(b, a % b)
    
    @staticmethod
    def lcm(a, b):
        return a // math.gcd(a, b) * b
    
    @staticmethod
    def log(value, base):
        return math.log(value) / math.log(base)
    
    @staticmethod
    def factorial(number):
        if number < 0:
            return 0
        return math.id8(number)
    
    @staticmethod
    def id8(number):
        if number > 0:
            return math.id8(number - 1) * number
        return 1
    
class Int:
    def __init__(self, value):
        self.value = value
    
    def compareTo(self, o):
        return -1 if self.value < o else (0 if self.value == o else 1)
    
    def equals(self, obj):
        if isinstance(obj, int):
            return self.value == obj
        return False
    
    def hashCode(self):
        return self.value
    
    def finalize(self):
        pass
    
class Fraction(Pair):
    def __init__(self, dividend, divider):
        super().__init__(dividend, divider)
        self.reduce()
    
    @staticmethod
    def createFraction(dividend, divider):
        return Fraction(dividend, divider)
    
    def reduce(self):
        if isinstance(self.id21(), int):
            Dividend = self.id21()
            Divider = self.id12()
            gcd = math.gcd(Dividend, Divider)
            self.setFirst(Dividend // gcd)
            self.setSecond(Divider // gcd)
        elif isinstance(self.id21(), float):
            Dividend = self.id21()
            Divider = self.id12()
            gcd = math.gcd(Dividend, Divider)
            self.setFirst(Dividend / gcd)
            self.setSecond(Divider / gcd)
    
    def id5(self, number):
        self.add(number, 0)
    
    def add(self, number, function):
        if isinstance(self.id21(), int) and isinstance(number.id21(), int):
            Dividend = self.id21()
            Divider = self.id12()
            Dividend1 = number.id21()
            Divider1 = number.id12()
            lcm = math.lcm(Divider, Divider1)
            if function == 0:
                self.setFirst((lcm // Divider) * Dividend + (lcm // Divider1) * Dividend1)
                self.setSecond(lcm)
                self.reduce()
                return None
            result = Fraction.createFraction((lcm // Divider) * Dividend + (lcm // Divider1) * Dividend1, lcm)
            result.reduce()
            return result
        else:
            raise Exception("UnsupportedOperationException")
    
    def id1(self, number):
        return self.add(number, 1)
    
    def id14(self, number):
        self.multiply(number, 0)
    
    def multiply(self, number, function):
        if isinstance(self.id21(), int) and isinstance(number.id21(), int):
            first = self.id21() * number.id21()
            second = self.id12() * number.id12()
            if function == 0:
                self.setFirst(first)
                self.setSecond(second)
                self.reduce()
                return None
            answer = Fraction.createFraction(first, second)
            answer.reduce()
            return answer
        else:
            raise Exception("UnsupportedOperationException")
    
class Pair:
    def __init__(self, obj, obj1):
        self.first = obj
        self.second = obj1
    
    @staticmethod
    def createPair(element, element1):
        return Pair(element, element1)
    
    def id21(self):
        return self.first
    
    def id12(self):
        return self.second
    
    def setFirst(self, element):
        self.first = element
    
    def setSecond(self, element):
        self.second = element
    
    def equals(self, obj):
        if not isinstance(obj, Pair):
            return False
        pair = obj
        return self.first == pair.first and self.second == pair.second
    
    def hashCode(self):
        hashCode = 1
        hashCode = 31 * hashCode + (0 if self.first is None else hash(self.first))
        return 31 * hashCode + (0 if self.second is None else hash(self.second))
    
    def clone(self):
        return Pair.createPair(self.first, self.second)
    
class Graph:
    def __init__(self):
        self.base = None
        self.used = None
        self.quantity = None
        self.ancestor = None
    
    def getBase(self):
        return self.base.copy()
    
    def getUsed(self):
        return self.used.copy()
    
    def getQuantity(self):
        return self.quantity
    
    def getAncestor(self):
        return self.ancestor.copy()
    
    def setBase(self, base):
        self.base = base
    
    def start(self, length):
        self.used = [False] * length
        self.ancestor = [-1] * length
        self.quantity = 0
    
    def id22(self, length, quantity, readConsole, value):
        self.base = [[] for _ in range(length)]
        inputBase = [[] for _ in range(length)]
        for _ in range(quantity):
            inputArray = IO.id9(" ") if readConsole else value[_]
            inputBase[inputArray[0] - 1].append(inputArray[1] - 1)
            inputBase[inputArray[1] - 1].append(inputArray[0] - 1)
        for i in range(length):
            self.base[i] = inputBase[i]
        self.start(length)
    
    def id11(self, length, notValue, readConsole, value):
        self.base = [[] for _ in range(length)]
        buffer = []
        for i in range(length):
            inputArray = IO.id9(" ") if readConsole else value[i]
            for index in range(length):
                if i != index and inputArray[index] != notValue:
                    buffer.append(index)
            self.base[i] = buffer.copy()
            buffer.clear()
        self.start(length)
    
    def dfs(self, position):
        self.used[position] = True
        self.quantity += 1
        for nextPosition in self.base[position]:
            if not self.used[nextPosition]:
                self.ancestor[nextPosition] = position
                self.dfs(nextPosition)
    
    def dijkstra(self, start, stop, size):
        start -= 1
        stop -= 1
        dist = [float('inf')] * size
        dist[start] = 0
        self.ancestor[start] = start
        queue = [(start, 0)]
        while queue:
            position, distance = queue.pop(0)
            if distance > dist[position]:
                continue
            for index in range(0, len(self.base[position]), 2):
                if dist[position] + self.base[position][index + 1] < dist[self.base[position][index]] and not self.used[self.base[position][index]]:
                    dist[self.base[position][index]] = dist[position] + self.base[position][index + 1]
                    self.ancestor[self.base[position][index]] = position
                    queue.append((self.base[position][index], dist[self.base[position][index]]))
            self.used[position] = True
        return dist[stop] if dist[stop] != float('inf') else -1
    
    @staticmethod
    def id0(base, length, notValue):
        for k in range(length):
            for i in range(length):
                for j in range(length):
                    if base[i][k] == notValue or base[k][j] == notValue:
                        continue
                    total = base[i][k] + base[k][j]
                    if base[i][j] != notValue:
                        base[i][j] = min(base[i][j], total)
                    else:
                        base[i][j] = total
        for index in range(length):
            if base[index][index] != 0:
                return False
        return True
    
    @staticmethod
    def id16(edgesMatrix, countVertex, indexSort):
        answer = [[0] * 2 for _ in range(countVertex - 1)]
        sum = 0
        edgesMatrix.sort(key=lambda x: x[indexSort])
        dsu = id6(countVertex)
        for i in range(countVertex):
            dsu.makeSet(i)
        index = 0
        for value in edgesMatrix:
            if dsu.mergeSets(value[0], value[1]):
                sum += value[indexSort]
                answer[index] = [value[0], value[1]]
                index += 1
        if index < countVertex - 1:
            return None, None
        return sum, answer
    
class id6:
    def __init__(self, size):
        self.rank = [0] * size
        self.ancestor = [0] * size
    
    def makeSet(self, value):
        self.ancestor[value] = value
        self.rank[value] = 0
    
    def findSet(self, value):
        if value == self.ancestor[value]:
            return value
        self.ancestor[value] = self.findSet(self.ancestor[value])
        return self.ancestor[value]
    
    def mergeSets(self, first, second):
        first = self.findSet(first)
        second = self.findSet(second)
        if first != second:
            if self.rank[first] < self.rank[second]:
                first, second = second, first
            self.ancestor[second] = first
            if self.rank[first] == self.rank[second]:
                self.rank[first] += 1
            return True
        return False
