MOD = 998244353

class mod_int:
    def __init__(self, v=0):
        if v < 0:
            v = v % MOD + MOD
        if v >= MOD:
            v %= MOD
        self.val = v

    @staticmethod
    def mod_inv(a, m=MOD):
        g = m
        r = a
        x = 0
        y = 1

        while r != 0:
            q = g // r
            g %= r
            g, r = r, g
            x -= q * y
            x, y = y, x

        return x if x >= 0 else x + m

    def __int__(self):
        return self.val

    def __add__(self, other):
        self.val += other.val
        if self.val >= MOD:
            self.val -= MOD
        return self

    def __sub__(self, other):
        self.val -= other.val
        if self.val < 0:
            self.val += MOD
        return self

    def __mul__(self, other):
        self.val = (self.val * other.val) % MOD
        return self

    def __truediv__(self, other):
        return self * mod_int.mod_inv(other.val)

    def __pow__(self, p):
        assert p >= 0
        a = self
        result = mod_int(1)

        while p > 0:
            if p & 1:
                result *= a

            a *= a
            p >>= 1

        return result

    def __str__(self):
        return str(self.val)

INF = 1e9 + 5

class segment_change:
    SENTINEL = -INF

    def __init__(self, set_min=SENTINEL, set_max=SENTINEL):
        self.set_min = set_min
        self.set_max = set_max

    def reset(self):
        self.set_min = self.SENTINEL
        self.set_max = self.SENTINEL

    def has_set_min(self):
        return self.set_min != self.SENTINEL

    def has_set_max(self):
        return self.set_max != self.SENTINEL

    def has_change(self):
        return self.has_set_min() or self.has_set_max()

    def combine(self, other):
        return segment_change(other.set_min if other.has_set_min() else self.set_min,
                              other.set_max if other.has_set_max() else self.set_max)

class segment:
    def __init__(self, L=1, R=1, sum=1, minimum=INF, maximum=-INF):
        self.L_product = L
        self.R_product = R
        self.sum = sum
        self.minimum = minimum
        self.maximum = maximum

    def apply(self, _, change):
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

    def join(self, a, b):
        self.L_product = a.L_product
        self.R_product = a.R_product
        self.sum = a.sum
        self.minimum = a.minimum
        self.maximum = a.maximum
        self.join(b)

class seg_tree:
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

        self.tree = [segment() for _ in range(2 * self.tree_n)]
        self.changes = [segment_change() for _ in range(self.tree_n)]

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

        for up in range(31 - __builtin_clz(self.tree_n), 0, -1):
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
        r_size = 0

        for a += self.tree_n, b += self.tree_n; a < b; a //= 2, b //= 2, length *= 2:
            if a & 1:
                range_op(a, length)
                a += 1

            if b & 1:
                right_half[r_size++] = (b - 1, length)
                b -= 1

        for i in range(r_size - 1, -1, -1):
            range_op(right_half[i][0], right_half[i][1])

        if needs_join:
            self.join_all(original_a, original_b)

    def query(self, a, b):
        assert 0 <= a <= b <= self.tree_n
        answer = segment()

        def range_op(position, _):
            answer.join(self.tree[position])

        self.process_range(a, b, False, range_op)
        return answer

    def update(self, a, b, change):
        assert 0 <= a <= b <= self.tree_n

        def range_op(position, length):
            self.tree[position].apply(length, change)

            if position < self.tree_n:
                self.changes[position] = self.changes[position].combine(change)

        self.process_range(a, b, True, range_op)

class event:
    def __init__(self, distance, velocity, index, type):
        self.distance = distance
        self.velocity = velocity
        self.index = index
        self.type = type

    def get_time(self):
        return mod_int(self.distance) / self.velocity

    def __lt__(self, other):
        return self.distance * other.velocity < other.distance * self.velocity

INV100 = mod_int(100).inv()

N = int(input())
X = []
V = []
L = []
R = []

for _ in range(N):
    x, v, p = map(int, input().split())
    X.append(x)
    V.append(v)
    R.append(p * INV100)
    L.append(1 - R[-1])

tree = seg_tree(N)
initial = [segment(L[i], R[i], 1, i, i) for i in range(N)]
tree.build(initial)
status = ['?'] * N
events = []

for i in range(N - 1):
    distance = X[i + 1] - X[i]
    events.append(event(distance, V[i] + V[i + 1], i, 0))

    if V[i] > V[i + 1]:
        events.append(event(distance, V[i] - V[i + 1], i, +1))
    elif V[i + 1] > V[i]:
        events.append(event(distance, V[i + 1] - V[i], i + 1, -1))

events.sort()
current_probability = mod_int(1)
total = mod_int(0)

for ev in events:
    if ev.type == 0:
        x = ev.index
        y = ev.index + 1
        if tree.query(x, x + 1).maximum >= y:
            continue
        probability = current_probability * get_change_by_setting(x, 'R') * get_change_by_setting(y, 'L')
        total += probability * ev.get_time()
        connect_final(x, y)
    else:
        x = ev.index
        direction = 'R' if ev.type > 0 else 'L'
        opposite = 'L' if direction == 'R' else 'R'
        probability = current_probability * get_change_by_setting(x, direction)
        total += probability * ev.get_time()
        set_final(x, opposite)

    if current_probability == 0:
        break

print(total)
