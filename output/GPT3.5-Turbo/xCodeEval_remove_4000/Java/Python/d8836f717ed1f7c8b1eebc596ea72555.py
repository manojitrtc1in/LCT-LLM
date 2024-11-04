import sys
from collections import deque

class C:
    def __init__(self):
        self.id3 = False
        self.id6 = True
        self.id10 = not os.path.exists("input.txt")
        self.id17 = 128
        self.id30 = False
        self.rnd = random.Random()
        self.fileName = ""
        self.MODULO = 1000 * 1000 * 1000 + 7

    def solve(self):
        n, k = self.readInt(), self.readInt()
        a = self.id2(n)

        answer = self.getAnswer(n, a, k)

        self.out.println(answer.x)
        self.out.println(answer.y)

    def getAnswer(self, n, a, limit):
        id22 = 50

        limit //= id22

        for i in range(n):
            a[i] //= id22

        onesCount = 0
        id33 = 0
        for v in a:
            if v == 1:
                onesCount += 1
            else:
                id33 += 1

        c = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            c[i][0] = c[i][i] = 1
            for j in range(1, i):
                c[i][j] = self.add(c[i - 1][j - 1], c[i - 1][j])

        FROM_SIDE = 0
        TO_SIDE = 1
        INF = sys.maxsize // 3

        distances = [[[INF] * (id33 + 1) for _ in range(onesCount + 1)] for _ in range(2)]
        ways = [[[0] * (id33 + 1) for _ in range(onesCount + 1)] for _ in range(2)]

        distances[FROM_SIDE][onesCount][id33] = 0
        ways[FROM_SIDE][onesCount][id33] = 1

        class Triple:
            def __init__(self, side, ones, twos):
                self.side = side
                self.ones = ones
                self.twos = twos

        q = deque()
        q.append(Triple(FROM_SIDE, onesCount, id33))

        while q:
            from_ = q.popleft()

            fromDistance = distances[from_.side][from_.ones][from_.twos]
            fromWays = ways[from_.side][from_.ones][from_.twos]
            id39 = fromDistance + 1

            nextSide = FROM_SIDE + TO_SIDE - from_.side

            if from_.side == FROM_SIDE:
                for id44 in range(from_.ones + 1):
                    for id45 in range(from_.twos + 1):
                        if id44 + id45 == 0:
                            continue
                        if id44 + 2 * id45 > limit:
                            continue

                        id24 = from_.ones - id44
                        id32 = from_.twos - id45

                        nextDistance = distances[nextSide][id24][id32]

                        if nextDistance < id39:
                            continue

                        id23 = self.mult(fromWays, self.mult(c[from_.ones][id44], c[from_.twos][id45]))

                        if nextDistance > id39:
                            nextDistance = distances[nextSide][id24][id32] = id39
                            q.append(Triple(nextSide, id24, id32))

                        if nextDistance == id39:
                            ways[nextSide][id24][id32] = self.add(ways[nextSide][id24][id32], id23)
            else:
                id34 = onesCount - from_.ones
                id12 = id33 - from_.twos

                for id44 in range(id34 + 1):
                    for id45 in range(id12 + 1):
                        if id44 + id45 == 0:
                            continue
                        if id44 + 2 * id45 > limit:
                            continue

                        id24 = from_.ones + id44
                        id32 = from_.twos + id45

                        nextDistance = distances[nextSide][id24][id32]

                        if nextDistance < id39:
                            continue

                        id23 = self.mult(fromWays, self.mult(c[id34][id44], c[id12][id45]))

                        if nextDistance > id39:
                            nextDistance = distances[nextSide][id24][id32] = id39
                            q.append(Triple(nextSide, id24, id32))

                        if nextDistance == id39:
                            ways[nextSide][id24][id32] = self.add(ways[nextSide][id24][id32], id23)

        distance = distances[TO_SIDE][0][0]
        if INF == distance:
            return Point(-1, 0)
        else:
            return Point(distance, ways[TO_SIDE][0][0])

    def inverse(self, x):
        return self.binpow(x, self.MODULO - 2)

    def binpow(self, base, power):
        if power == 0:
            return 1
        if power & 1 == 0:
            half = self.binpow(base, power >> 1)
            return self.mult(half, half)
        else:
            prev = self.binpow(base, power - 1)
            return self.mult(prev, base)

    def add(self, a, b):
        return (a + b) % self.MODULO

    def subtract(self, a, b):
        return self.add(a, self.MODULO - b % self.MODULO)

    def mult(self, a, b):
        return (a * b) % self.MODULO

    def yesNo(self, yes):
        self.out.println("YES" if yes else "NO")

    def run(self):
        try:
            self.timeInit()
            sys.stdin = open('input.txt', 'r')
            sys.stdout = open('output.txt', 'w')

            self.init()

            if self.id10:
                self.solve()
            else:
                while self.id6:
                    try:
                        self.timeInit()
                        self.solve()
                        self.time()

                        self.out.println()
                        self.out.flush()
                    except EOFError:
                        break
                    except TypeError:
                        if self.id3:
                            break
                        else:
                            raise
            self.out.close()
            self.time()
        except Exception as e:
            print(e)
            sys.exit(-1)

    def init(self):
        if self.id10:
            if self.fileName == "":
                self.in_ = sys.stdin
                self.out = sys.stdout
            else:
                self.in_ = open(self.fileName + ".in", "r")
                self.out = open(self.fileName + ".out", "w")
        else:
            self.in_ = open("input.txt", "r")
            self.out = open("output.txt", "w")

    def timeInit(self):
        self.timeBegin = time.time()

    def time(self):
        timeEnd = time.time()
        print("Time =", timeEnd - self.timeBegin, file=sys.stderr)

    def debug(self, *objects):
        if self.id10:
            for o in objects:
                print(o, file=sys.stderr)

    def readLine(self):
        return self.in_.readline()

    def readString(self):
        while not self.tok.hasMoreTokens():
            nextLine = self.readLine()
            if nextLine is None:
                raise EOFError()

            self.tok = StringTokenizer(nextLine, self.delim)

        return self.tok.nextToken(self.delim)

    def readInt(self):
        if not self.id30:
            return int(self.readString())
        else:
            return int(self.id21())

    def id2(self, size):
        array = [0] * size

        for index in range(size):
            array[index] = self.readInt()

        return array

    def id14(self, size):
        array = self.id2(size)

        for i in range(size):
            array[i] -= 1

        return array

    def readLong(self):
        if not self.id30:
            return int(self.readString())
        else:
            return int(self.id21())

    def readDouble(self):
        return float(self.readString())

    def readPoint(self):
        x = self.readInt()
        y = self.readInt()
        return Point(x, y)

    def readGraph(self, vertexNumber, edgeNumber):
        graph = [[] for _ in range(vertexNumber)]

        for _ in range(edgeNumber):
            from_ = self.readInt() - 1
            to = self.readInt() - 1

            graph[from_].append(to)
            graph[to].append(from_)

        return graph

    def id13(self, vertexNumber, edgesNumber, indexation, directed):
        graph = [[] for _ in range(vertexNumber)]

        for _ in range(edgesNumber):
            from_ = self.readInt() - indexation
            to = self.readInt() - indexation

            if directed:
                graph[from_].append(to)
            else:
                graph[from_].append(to)
                graph[to].append(from_)

        return graph

    def id31(self, vertexNumber, edgesNumber, indexation, directed):
        graph = [[] for _ in range(vertexNumber)]

        for _ in range(edgesNumber):
            from_ = self.readInt() - indexation
            to = self.readInt() - indexation
            w = self.readInt()

            graph[from_].append(Edge(to, w))
            if not directed:
                graph[to].append(Edge(from_, w))

        return graph

    def id4(self, size):
        array = []

        for _ in range(size):
            array.append(id35(self.readInt(), index))

        return array

    def swap(self, array, i, j):
        if i != j:
            array[i], array[j] = array[j], array[i]

    def checkCell(self, row, rowsCount, column, columnsCount):
        return self.checkIndex(row, rowsCount) and self.checkIndex(column, columnsCount)

    def checkIndex(self, index, lim):
        return 0 <= index < lim

    def getBit(self, mask, bit):
        return (mask >> bit) & 1

    def checkBit(self, mask, bit):
        return self.getBit(mask, bit) != 0

    def getSum(self, array):
        return sum(array)

    def id18(self, array):
        min_ = array[0]
        max_ = array[0]

        for index in range(0, len(array), 2):
            value = array[index]

            if index == len(array) - 1:
                min_ = min(min_, value)
                max_ = max(max_, value)
            else:
                otherValue = array[index + 1]

                if value <= otherValue:
                    min_ = min(min_, value)
                    max_ = max(max_, otherValue)
                else:
                    min_ = min(min_, otherValue)
                    max_ = max(max_, value)

        return Point(min_, max_)

    def isPrime(self, x):
        if x < 2:
            return False
        for d in range(2, int(x ** 0.5) + 1):
            if x % d == 0:
                return False

        return True

    def id20(self, n):
        used = [False] * n
        used[0] = used[1] = True

        primes = []
        for i in range(2, n):
            if not used[i]:
                primes.append(i)
                for j in range(2 * i, n, i):
                    used[j] = True

        return primes

    def id41(self, value):
        divisors = []
        for divisor in range(1, int(value ** 0.5) + 1):
            if value % divisor == 0:
                divisors.append(divisor)
                if divisor * divisor != value:
                    divisors.append(value // divisor)

        return divisors

    def lcm(self, a, b):
        return a // self.gcd(a, b) * b

    def gcd(self, a, b):
        return a if b == 0 else self.gcd(b, a % b)

    def castInt(self, lst):
        return list(lst)

    def castLong(self, lst):
        return list(lst)

    def order(self, n):
        return list(range(n))

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

c = C()
c.run()
