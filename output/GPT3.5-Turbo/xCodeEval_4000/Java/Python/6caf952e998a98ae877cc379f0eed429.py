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

class Polygon:
    def __init__(self, vertices):
        self.vertices = vertices

class GeometryUtils:
    epsilon = 1e-8

    @staticmethod
    def fastHypot(*x):
        if len(x) == 0:
            return 0
        elif len(x) == 1:
            return abs(x[0])
        else:
            sumSquares = 0
            for value in x:
                sumSquares += value * value
            return math.sqrt(sumSquares)

    @staticmethod
    def fastHypot(x, y):
        return math.sqrt(x * x + y * y)

    @staticmethod
    def fastHypot(x, y):
        return math.sqrt(x * x + y * y)

    @staticmethod
    def fastHypot(x, y):
        return math.sqrt(x * x + y * y)

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

    def findTouchingPoints(self, point):
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
        determinant = self.b * other.a - self.a * other.b
        x = (self.c * other.b - self.b * other.c) / determinant
        y = (self.a * other.c - self.c * other.a) / determinant
        return Point(x, y)

    def parallel(self, other):
        return abs(self.a * other.b - self.b * other.a) < GeometryUtils.epsilon

    def contains(self, point):
        return abs(self.value(point)) < GeometryUtils.epsilon

    def perpendicular(self, point):
        return Line(-self.b, self.a, self.b * point.x - self.a * point.y)

    def value(self, point):
        return self.a * point.x + self.b * point.y + self.c

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
        return GeometryUtils.fastHypot(self.x - other.x, self.y - other.y)

    def value(self):
        return GeometryUtils.fastHypot(self.x, self.y)

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
    def __init__(self, vertices):
        self.vertices = vertices

    def square(self):
        s = 0
        for i in range(1, len(self.vertices)):
            s += (self.vertices[i].x - self.vertices[i - 1].x) * (self.vertices[i].y + self.vertices[i - 1].y)
        s += (self.vertices[0].x - self.vertices[len(self.vertices) - 1].x) * (self.vertices[0].y + self.vertices[len(self.vertices) - 1].y)
        return abs(s) / 2

    def center(self):
        sx = 0
        sy = 0
        for point in self.vertices:
            sx += point.x
            sy += point.y
        return Point(sx / len(self.vertices), sy / len(self.vertices))

    def contains(self, point, strict):
        for segment in self.sides():
            if segment.contains(point, True):
                return not strict
        totalAngle = GeometryUtils.canonicalAngle(math.atan2(self.vertices[0].y - point.y, self.vertices[0].x - point.x) -
                                                  math.atan2(self.vertices[len(self.vertices) - 1].y - point.y, self.vertices[len(self.vertices) - 1].x - point.x))
        for i in range(1, len(self.vertices)):
            totalAngle += GeometryUtils.canonicalAngle(math.atan2(self.vertices[i].y - point.y, self.vertices[i].x - point.x) -
                                                      math.atan2(self.vertices[i - 1].y - point.y, self.vertices[i - 1].x - point.x))
        return abs(totalAngle) > math.pi

    def sides(self):
        if hasattr(self, 'sides'):
            return self.sides
        sides = []
        for i in range(len(self.vertices) - 1):
            sides.append(Segment(self.vertices[i], self.vertices[i + 1]))
        sides.append(Segment(self.vertices[len(self.vertices) - 1], self.vertices[0]))
        self.sides = sides
        return sides

class Circle:
    def __init__(self, center, radius):
        self.center = center
        self.radius = radius

    def contains(self, point):
        return self.center.distance(point) < self.radius + GeometryUtils.epsilon

    def strictContains(self, point):
        return self.center.distance(point) < self.radius - GeometryUtils.epsilon

    def findTouchingPoints(self, point):
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

class GeometryUtils:
    epsilon = 1e-8

    @staticmethod
    def fastHypot(*x):
        if len(x) == 0:
            return 0
        elif len(x) == 1:
            return abs(x[0])
        else:
            sumSquares = 0
            for value in x:
                sumSquares += value * value
            return math.sqrt(sumSquares)

    @staticmethod
    def fastHypot(x, y):
        return math.sqrt(x * x + y * y)

    @staticmethod
    def fastHypot(x, y):
        return math.sqrt(x * x + y * y)

    @staticmethod
    def fastHypot(x, y):
        return math.sqrt(x * x + y * y)

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
