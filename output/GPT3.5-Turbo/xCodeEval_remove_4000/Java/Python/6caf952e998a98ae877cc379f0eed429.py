import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Line:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

class Segment:
    def __init__(self, a, b):
        self.a = a
        self.b = b

class GeometryUtils:
    epsilon = 1e-8

    @staticmethod
    def id28(x, y):
        return math.sqrt(x * x + y * y)

    @staticmethod
    def id4(v, angle, g):
        return (v * v * math.sin(2 * angle)) / g

    @staticmethod
    def sphereVolume(radius):
        return 4 * math.pi * radius * radius * radius / 3

    @staticmethod
    def triangleSquare(first, second, third):
        p = (first + second + third) / 2
        return math.sqrt(p * (p - first) * (p - second) * (p - third))

    @staticmethod
    def canonicalAngle(angle):
        while angle > math.pi:
            angle -= 2 * math.pi
        while angle < -math.pi:
            angle += 2 * math.pi
        return angle

    @staticmethod
    def positiveAngle(angle):
        while angle > 2 * math.pi - GeometryUtils.epsilon:
            angle -= 2 * math.pi
        while angle < -GeometryUtils.epsilon:
            angle += 2 * math.pi
        return angle

class Circle:
    def __init__(self, center, radius):
        self.center = center
        self.radius = radius

    def contains(self, point):
        return self.center.distance(point) < self.radius + GeometryUtils.epsilon

    def strictContains(self, point):
        return self.center.distance(point) < self.radius - GeometryUtils.epsilon

    def id27(self, point):
        distance = self.center.distance(point)
        if distance < self.radius - GeometryUtils.epsilon:
            return []
        if distance < self.radius + GeometryUtils.epsilon:
            return [point]
        power = Circle(point, math.sqrt((distance - self.radius) * (distance + self.radius)))
        return self.intersect(power)

    def intersect(self, other):
        distance = self.center.distance(other.center)
        if distance > self.radius + other.radius + GeometryUtils.epsilon or abs(self.radius - other.radius) > distance + GeometryUtils.epsilon:
            return []
        p = (self.radius + other.radius + distance) / 2
        height = 2 * math.sqrt(p * (p - self.radius) * (p - other.radius) * (p - distance)) / distance
        l1 = math.sqrt(self.radius * self.radius - height * height)
        l2 = math.sqrt(other.radius * other.radius - height * height)
        if self.radius * self.radius + distance * distance < other.radius * other.radius:
            l1 = -l1
        if self.radius * self.radius > distance * distance + other.radius * other.radius:
            l2 = -l2
        middle = Point((self.center.x * l2 + other.center.x * l1) / (l1 + l2),
            (self.center.y * l2 + other.center.y * l1) / (l1 + l2))
        line = self.center.line(other.center).perpendicular(middle)
        return line.intersect(self)

class Line:
    def __init__(self, p, angle):
        self.a = math.sin(angle)
        self.b = -math.cos(angle)
        self.c = -p.x * self.a - p.y * self.b

    def intersect(self, other):
        if self.parallel(other):
            return None
        id8 = self.b * other.a - self.a * other.b
        x = (self.c * other.b - self.b * other.c) / id8
        y = (self.a * other.c - self.c * other.a) / id8
        return Point(x, y)

    def parallel(self, other):
        return abs(self.a * other.b - self.b * other.a) < GeometryUtils.epsilon

    def contains(self, point):
        return abs(self.value(point)) < GeometryUtils.epsilon

    def perpendicular(self, point):
        return Line(-self.b, self.a, self.b * point.x - self.a * point.y)

    def value(self, point):
        return self.a * point.x + self.b * point.y + self.c

    def intersect(self, circle):
        distance = self.distance(circle.center)
        if distance > circle.radius + GeometryUtils.epsilon:
            return []
        intersection = self.intersect(self.perpendicular(circle.center))
        if abs(distance - circle.radius) < GeometryUtils.epsilon:
            return [intersection]
        shift = math.sqrt(circle.radius * circle.radius - distance * distance)
        return [Point(intersection.x + shift * self.b, intersection.y - shift * self.a),
            Point(intersection.x - shift * self.b, intersection.y + shift * self.a)]

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def line(self, other):
        if self == other:
            return None
        a = other.y - self.y
        b = self.x - other.x
        c = -a * self.x - b * self.y
        return Line(a, b, c)

    def distance(self, other):
        return GeometryUtils.id28(self.x - other.x, self.y - other.y)

    def value(self):
        return GeometryUtils.id28(self.x, self.y)

    def angle(self):
        return math.atan2(self.y, self.x)

    def rotate(self, angle):
        nx = self.x * math.cos(angle) - self.y * math.sin(angle)
        ny = self.y * math.cos(angle) + self.x * math.sin(angle)
        return Point(nx, ny)

class Segment:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def length(self):
        return self.a.distance(self.b)

    def distance(self, point):
        length = self.length()
        left = point.distance(self.a)
        if length < GeometryUtils.epsilon:
            return left
        right = point.distance(self.b)
        if left * left > right * right + length * length:
            return right
        if right * right > left * left + length * length:
            return left
        return point.distance(self.line())

    def intersect(self, other, includeEnds):
        line = self.line()
        otherLine = other.a.line(other.b)
        if line.parallel(otherLine):
            return None
        intersection = line.intersect(otherLine)
        if self.contains(intersection, includeEnds) and other.contains(intersection, includeEnds):
            return intersection
        else:
            return None

    def contains(self, point, includeEnds):
        if self.a == point or self.b == point:
            return includeEnds
        if self.a == self.b:
            return False
        line = self.line()
        if not line.contains(point):
            return False
        perpendicular = line.perpendicular(self.a)
        aValue = perpendicular.value(self.a)
        bValue = perpendicular.value(self.b)
        pointValue = perpendicular.value(point)
        return (aValue < pointValue and pointValue < bValue) or (bValue < pointValue and pointValue < aValue)

    def line(self):
        return self.a.line(self.b)

    def middle(self):
        return Point((self.a.x + self.b.x) / 2, (self.a.y + self.b.y) / 2)

    def intersect(self, line):
        selfLine = self.line()
        intersection = selfLine.intersect(line)
        if intersection is None:
            return None
        if self.contains(intersection, True):
            return intersection
        return None

    def distance(self, other):
        line = self.line()
        otherLine = other.line()
        p = line.intersect(otherLine)
        if p is not None and self.contains(p, True) and other.contains(p, True):
            return 0
        return min(min(other.distance(self.a), other.distance(self.b)), min(self.distance(other.a), self.distance(other.b)))

class Polygon:
    def __init__(self, *vertices):
        self.vertices = list(vertices)

    def square(self):
        s = 0
        for i in range(1, len(self.vertices)):
            s += (self.vertices[i].x - self.vertices[i - 1].x) * (self.vertices[i].y + self.vertices[i - 1].y)
        s += (self.vertices[0].x - self.vertices[-1].x) * (self.vertices[0].y + self.vertices[-1].y)
        return abs(s) / 2

    def center(self):
        sx = 0
        sy = 0
        for point in self.vertices:
            sx += point.x
            sy += point.y
        return Point(sx / len(self.vertices), sy / len(self.vertices))

    def contains(self, point, strict=False):
        for segment in self.sides():
            if segment.contains(point, True):
                return not strict
        totalAngle = GeometryUtils.canonicalAngle(math.atan2(self.vertices[0].y - point.y, self.vertices[0].x - point.x) -
            math.atan2(self.vertices[-1].y - point.y, self.vertices[-1].x - point.x))
        for i in range(1, len(self.vertices)):
            totalAngle += GeometryUtils.canonicalAngle(math.atan2(self.vertices[i].y - point.y, self.vertices[i].x - point.x) -
                math.atan2(self.vertices[i - 1].y - point.y, self.vertices[i - 1].x - point.x))
        return abs(totalAngle) > math.pi

    def sides(self):
        if len(self.vertices) == 1:
            return []
        sides = []
        for i in range(len(self.vertices) - 1):
            sides.append(Segment(self.vertices[i], self.vertices[i + 1]))
        sides.append(Segment(self.vertices[-1], self.vertices[0]))
        return sides

    def perimeter(self):
        result = self.vertices[0].distance(self.vertices[-1])
        for i in range(1, len(self.vertices)):
            result += self.vertices[i].distance(self.vertices[i - 1])
        return result

class Heap:
    def __init__(self, maxElement):
        self.comparator = lambda a, b: a - b
        self.size = 0
        self.elements = [0] * maxElement
        self.at = [-1] * maxElement

    def getSize(self):
        return self.size

    def setComparator(self, comparator):
        self.comparator = comparator

    def isEmpty(self):
        return self.size == 0

    def add(self, element):
        self.ensureCapacity(self.size + 1)
        self.elements[self.size] = element
        self.at[element] = self.size
        self.shiftUp(self.size)
        self.size += 1
        return self.at[element]

    def shiftUp(self, index):
        value = self.elements[index]
        while index != 0:
            parent = (index - 1) >> 1
            parentValue = self.elements[parent]
            if self.comparator(parentValue, value) <= 0:
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
            if child + 1 < self.size and self.comparator(self.elements[child], self.elements[child + 1]) > 0:
                child += 1
            if self.comparator(self.elements[index], self.elements[child]) <= 0:
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

    def peek(self):
        if self.isEmpty():
            raise IndexError()
        return self.elements[0]

    def poll(self):
        if self.isEmpty():
            raise IndexError()
        result = self.elements[0]
        self.at[result] = -1
        if self.size == 1:
            self.size = 0
            return result
        self.elements[0] = self.elements[self.size - 1]
        self.at[self.elements[0]] = 0
        self.size -= 1
        self.shiftDown(0)
        return result

    def clear(self):
        self.size = 0
        self.at = [-1] * len(self.at)

    def ensureCapacity(self, size):
        if len(self.elements) < size:
            newElements = [0] * max(2 * len(self.elements), size)
            newElements[:len(self.elements)] = self.elements
            self.elements = newElements

class BooleanMatrix:
    def __init__(self, rowCount, columnCount):
        self.rowCount = rowCount
        self.columnCount = columnCount
        self.data = [[False] * columnCount for _ in range(rowCount)]

    @staticmethod
    def add(first, second):
        result = BooleanMatrix(first.rowCount, first.columnCount)
        for i in range(result.rowCount):
            for j in range(result.columnCount):
                result.data[i][j] = first.data[i][j] or second.data[i][j]
        return result

    @staticmethod
    def multiply(first, second):
        result = BooleanMatrix(first.rowCount, second.columnCount)
        for i in range(first.rowCount):
            for j in range(second.rowCount):
                for k in range(second.columnCount):
                    result.data[i][k] |= first.data[i][j] and second.data[j][k]
        return result

    @staticmethod
    def identityMatrix(size):
        result = BooleanMatrix(size, size)
        for i in range(size):
            result.data[i][i] = True
        return result

    def power(self, exponent):
        if exponent == 0:
            return BooleanMatrix.identityMatrix(self.rowCount)
        if exponent == 1:
            return self
        result = self.power(exponent >> 1)
        result = BooleanMatrix.multiply(result, result)
        if exponent & 1 == 1:
            result = BooleanMatrix.multiply(result, self)
        return result

class DoubleUtils:
    @staticmethod
    def id20(p, q):
        return p / (1 - q)

class id26:
    @staticmethod
    def fft(a, b, invert):
        count = len(a)
        for i in range(1, count):
            bit = count >> 1
            j = 0
            while j >= bit:
                j -= bit
                bit >>= 1
            j += bit
            if i < j:
                a[i], a[j] = a[j], a[i]
                b[i], b[j] = b[j], b[i]
        for length in range(2, count + 1, length << 1):
            halfLen = length >> 1
            angle = 2 * math.pi / length
            if invert:
                angle = -angle
            id24 = math.cos(angle)
            id7 = math.sin(angle)
            for i in range(0, count, length):
                wA = 1
                wB = 0
                for j in range(halfLen):
                    uA = a[i + j]
                    uB = b[i + j]
                    vA = a[i + j + halfLen] * wA - b[i + j + halfLen] * wB
                    vB = a[i + j + halfLen] * wB + b[i + j + halfLen] * wA
                    a[i + j] = uA + vA
                    b[i + j] = uB + vB
                    a[i + j + halfLen] = uA - vA
                    b[i + j + halfLen] = uB - vB
                    nextWA = wA * id24 - wB * id7
                    wB = wA * id7 + wB * id24
                    wA = nextWA
        if invert:
            for i in range(count):
                a[i] /= count
                b[i] /= count

    @staticmethod
    def multiply(a, b):
        resultSize = 1 << (max(len(a), len(b)) - 1).bit_length() << 2
        aReal = [0] * resultSize
        id14 = [0] * resultSize
        bReal = [0] * resultSize
        id34 = [0] * resultSize
        for i in range(len(a)):
            aReal[i] = a[i]
        for i in range(len(b)):
            bReal[i] = b[i]
        id26.fft(aReal, id14, False)
        if a == b:
            bReal[:] = aReal
            id34[:] = id14
        else:
            id26.fft(bReal, id34, False)
        for i in range(resultSize):
            real = aReal[i] * bReal[i] - id14[i] * id34[i]
            id14[i] = id14[i] * bReal[i] + id34[i] * aReal[i]
            aReal[i] = real
        id26.fft(aReal, id14, True)
        result = [0] * resultSize
        for i in range(resultSize):
            result[i] = round(aReal[i])
        return result
