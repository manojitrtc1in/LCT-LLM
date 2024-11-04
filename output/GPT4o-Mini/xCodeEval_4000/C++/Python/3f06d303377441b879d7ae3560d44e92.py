from math import gcd
from collections import defaultdict
import sys
from functools import reduce
from itertools import accumulate

MOD = 998244353

class ModInt:
    def __init__(self, v=0):
        if v < 0:
            v = v % MOD + MOD
        if v >= MOD:
            v %= MOD
        self.val = v

    @staticmethod
    def mod_inv(a, m=MOD):
        g, r = m, a
        x, y = 0, 1

        while r != 0:
            q = g // r
            g, r = r, g % r
            x, y = y, x - q * y

        return x if x >= 0 else x + m

    def __int__(self):
        return self.val

    def __add__(self, other):
        return ModInt((self.val + other.val) % MOD)

    def __sub__(self, other):
        return ModInt((self.val - other.val) % MOD)

    def __mul__(self, other):
        return ModInt((self.val * other.val) % MOD)

    def __truediv__(self, other):
        return self * other.inv()

    def __eq__(self, other):
        return self.val == other.val

    def __ne__(self, other):
        return self.val != other.val

    def inv(self):
        return ModInt(self.mod_inv(self.val))

    def pow(self, p):
        assert p >= 0
        a = self
        result = ModInt(1)

        while p > 0:
            if p & 1:
                result *= a
            a *= a
            p >>= 1

        return result

    def __str__(self):
        return str(self.val)

INF = int(1e9 + 5)

class SegmentChange:
    SENTINEL = -INF

    def __init__(self, set_min=SENTINEL, set_max=SENTINEL):
        self.set_min = set_min
        self.set_max = set_max

    def reset(self):
        self.set_min = self.set_max = self.SENTINEL

    def has_set_min(self):
        return self.set_min != self.SENTINEL

    def has_set_max(self):
        return self.set_max != self.SENTINEL

    def has_change(self):
        return self.has_set_min() or self.has_set_max()

    def combine(self, other):
        return SegmentChange(
            other.set_min if other.has_set_min() else self.set_min,
            other.set_max if other.has_set_max() else self.set_max
        )

class Segment:
    def __init__(self, L=ModInt(1), R=ModInt(1), sum=ModInt(1), minimum=INF, maximum=-INF):
        self.L_product = L
        self.R_product = R
        self.sum = sum
        self.minimum = minimum
        self.maximum = maximum

    def apply(self, length, change):
        if change.has_set_min():
            self.minimum = change.set_min
        if change.has_set_max():
            self.maximum = change.set_max

    def join(self, other):
        self.sum = self.sum * other.R_product + self.L_product * other.sum - self.L_product * other.R_product
        self.L_product *= other.L_product
        self.R_product *= other.R_product
        self.minimum = min(self.minimum, other.minimum)
        self.maximum = max(self.maximum, other.maximum)

    def join_two(self, a, b):
        self.__init__(a.L_product, a.R_product, a.sum, a.minimum, a.maximum)
        self.join(b)

class SegTree:
    def __init__(self, n=-1):
        self.tree_n = 0
        self.tree = []
        self.changes = []
        if n >= 0:
            self.init(n)

    def init(self, n):
        self.tree_n = 1
        while self.tree_n < n:
            self.tree_n *= 2
        self.tree = [Segment() for _ in range(2 * self.tree_n)]
        self.changes = [SegmentChange() for _ in range(self.tree_n)]

    def build(self, initial):
        n = len(initial)
        self.init(n)
        assert n <= self.tree_n

        for i in range(n):
            self.tree[self.tree_n + i] = initial[i]

        for position in range(self.tree_n - 1, 0, -1):
            self.tree[position].join(self.tree[2 * position], self.tree[2 * position + 1])

    def push_down(self, position, length):
        if not self.changes[position].has_change():
            return

        if 2 * position < self.tree_n:
            self.changes[2 * position] = self.changes[2 * position].combine(self.changes[position])
            self.changes[2 * position + 1] = self.changes[2 * position + 1].combine(self.changes[position])

        self.tree[2 * position].apply(length // 2, self.changes[position])
        self.tree[2 * position + 1].apply(length // 2, self.changes[position])
        self.changes[position].reset()

    def push_all(self, a, b):
        assert 0 <= a < b <= self.tree_n
        a += self.tree_n
        b += self.tree_n - 1

        for up in range(31, -1, -1):
            x = a >> up
            y = b >> up
            self.push_down(x, 1 << up)
            if x != y:
                self.push_down(y, 1 << up)

    def join_and_apply(self, position, length):
        self.tree[position].join(self.tree[2 * position], self.tree[2 * position + 1])
        self.tree[position].apply(length, self.changes[position])

    def join_all(self, a, b):
        assert 0 <= a < b <= self.tree_n
        a += self.tree_n
        b += self.tree_n - 1
        length = 1

        while a > 1:
            a //= 2
            b //= 2
            length *= 2
            self.join_and_apply(a, length)
            if a != b:
                self.join_and_apply(b, length)

    def process_range(self, a, b, needs_join, range_op):
        if a == b:
            return
        self.push_all(a, b)
        original_a = a
        original_b = b
        length = 1
        right_half = []

        for a, b in zip(range(a + self.tree_n, b + self.tree_n), range(b + self.tree_n)):
            if a & 1:
                range_op(a, length)
                a += 1
            if b & 1:
                right_half.append((b - 1, length))
                b -= 1

        for pos, len in reversed(right_half):
            range_op(pos, len)

        if needs_join:
            self.join_all(original_a, original_b)

    def query(self, a, b):
        assert 0 <= a <= b <= self.tree_n
        answer = Segment()

        self.process_range(a, b, False, lambda position, _: answer.join(self.tree[position]))

        return answer

    def update(self, a, b, change):
        assert 0 <= a <= b <= self.tree_n

        self.process_range(a, b, True, lambda position, length: (
            self.tree[position].apply(length, change),
            self.changes[position].combine(change) if position < self.tree_n else None
        ))

class Event:
    def __init__(self, distance, velocity, index, event_type):
        assert distance >= 0 and velocity > 0
        self.distance = distance
        self.velocity = velocity
        self.index = index
        self.type = event_type

    def get_time(self):
        return ModInt(self.distance) / self.velocity

    def __lt__(self, other):
        return self.distance * other.velocity < other.distance * self.velocity

INV100 = ModInt(100).inv()

N = 0
X = []
V = []
L = []
R = []
events = []
tree = SegTree()
current_probability = ModInt(1)
status = ""

def get_minimum(x):
    return tree.query(x, x + 1).minimum

def get_maximum(x):
    return tree.query(x, x + 1).maximum

def in_same_component(x, y):
    assert x <= y
    return y <= get_maximum(x)

def get_change_by_setting(index, direction):
    if status[index] == direction:
        return ModInt(1)

    if status[index] != '?' and status[index] != direction:
        return ModInt(0)

    assert status[index] == '?'
    minimum = get_minimum(index)
    maximum = get_maximum(index)

    if direction == 'L':
        left = tree.query(minimum, index + 1).L_product
        right = tree.query(index + 1, maximum + 1).sum
        before = tree.query(minimum, maximum + 1).sum
        return left * right / before
    elif direction == 'R':
        left = tree.query(minimum, index).sum
        right = tree.query(index, maximum + 1).R_product
        before = tree.query(minimum, maximum + 1).sum
        return left * right / before

    assert False

def connect_final(x, y):
    assert y - x == 1

    if status[x] == 'L' or status[y] == 'R':
        return

    if status[x] == 'R' and status[y] == 'L':
        global current_probability
        current_probability = ModInt(0)
        return

    assert get_maximum(x) == x and get_minimum(y) == y
    x_min = get_minimum(x)
    y_max = get_maximum(y)

    if status[x] == 'R':
        for i in range(y, y_max + 1):
            assert status[i] == '?'
            status[i] = 'R'

        y_seg = tree.query(y, y_max + 1)
        global current_probability
        current_probability *= y_seg.R_product / y_seg.sum
        return

    if status[y] == 'L':
        for i in range(x_min, x + 1):
            assert status[i] == '?'
            status[i] = 'L'

        x_seg = tree.query(x_min, x + 1)
        current_probability *= x_seg.L_product / x_seg.sum
        return

    assert status[x] == '?' and status[y] == '?'
    tree.update(x_min, y_max + 1, SegmentChange(x_min, y_max))
    current_probability *= tree.query(x_min, y_max + 1).sum / (
        tree.query(x_min, x + 1).sum * tree.query(y, y_max + 1).sum
    )

def set_final(index, direction):
    if status[index] != '?':
        if status[index] != direction:
            global current_probability
            current_probability = ModInt(0)
        return

    assert status[index] == '?'
    minimum = get_minimum(index)
    maximum = get_maximum(index)

    if direction == 'L':
        global current_probability
        current_probability *= get_change_by_setting(index, 'L')
        tree.update(index + 1, maximum + 1, SegmentChange(index + 1, maximum))

        for i in range(minimum, index + 1):
            assert status[i] == '?'
            status[i] = 'L'
    elif direction == 'R':
        current_probability *= get_change_by_setting(index, 'R')
        tree.update(minimum, index, SegmentChange(minimum, index - 1))

        for i in range(index, maximum + 1):
            assert status[i] == '?'
            status[i] = 'R'
    else:
        assert False

def check_validity():
    for i in range(N):
        if status[i] == '?':
            minimum = get_minimum(i)
            maximum = get_maximum(i)

            for j in range(minimum, maximum + 1):
                assert status[j] == '?'

def main():
    global N, X, V, L, R, events, tree, current_probability, status

    input = sys.stdin.read
    data = input().splitlines()
    N = int(data[0])
    X = [0] * N
    V = [0] * N
    L = [0] * N
    R = [0] * N

    for i in range(N):
        P = list(map(int, data[i + 1].split()))
        X[i], V[i], P = P
        R[i] = P * INV100
        L[i] = ModInt(1) - R[i]

    tree.init(N)
    initial = [Segment(L[i], R[i], ModInt(1), i, i) for i in range(N)]
    tree.build(initial)
    status = '?' * N

    for i in range(N - 1):
        distance = X[i + 1] - X[i]
        events.append(Event(distance, V[i] + V[i + 1], i, 0))

        if V[i] > V[i + 1]:
            events.append(Event(distance, V[i] - V[i + 1], i, 1))
        elif V[i + 1] > V[i]:
            events.append(Event(distance, V[i + 1] - V[i], i + 1, -1))

    events.sort()
    current_probability = ModInt(1)
    total = ModInt(0)

    for ev in events:
        if ev.type == 0:
            x = ev.index
            y = ev.index + 1
            assert not in_same_component(x, y)
            probability = current_probability * get_change_by_setting(x, 'R') * get_change_by_setting(y, 'L')
            total += probability * ev.get_time()
            connect_final(x, y)
        else:
            assert abs(ev.type) == 1
            x = ev.index
            direction = 'R' if ev.type > 0 else 'L'
            opposite = 'L' + 'R' - direction
            probability = current_probability * get_change_by_setting(x, direction)
            total += probability * ev.get_time()
            set_final(x, opposite)

        if current_probability == ModInt(0):
            break

    print(total)

if __name__ == "__main__":
    main()
