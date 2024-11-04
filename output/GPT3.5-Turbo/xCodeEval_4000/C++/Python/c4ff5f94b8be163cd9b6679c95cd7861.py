import sys
from typing import List, Tuple
from math import isclose

MOD = 998244353


class Mint:
    def __init__(self, value: int = 0):
        self.value = value % MOD

    def __add__(self, other: 'Mint') -> 'Mint':
        if isinstance(other, Mint):
            return Mint(self.value + other.value)
        return Mint(self.value + other)

    def __sub__(self, other: 'Mint') -> 'Mint':
        if isinstance(other, Mint):
            return Mint(self.value - other.value)
        return Mint(self.value - other)

    def __mul__(self, other: 'Mint') -> 'Mint':
        if isinstance(other, Mint):
            return Mint(self.value * other.value)
        return Mint(self.value * other)

    def __truediv__(self, other: 'Mint') -> 'Mint':
        if isinstance(other, Mint):
            return Mint(self.value * pow(other.value, MOD - 2, MOD))
        return Mint(self.value * pow(other, MOD - 2, MOD))

    def __pow__(self, other: int) -> 'Mint':
        return Mint(pow(self.value, other, MOD))

    def __eq__(self, other: 'Mint') -> bool:
        if isinstance(other, Mint):
            return self.value == other.value
        return self.value == other

    def __ne__(self, other: 'Mint') -> bool:
        if isinstance(other, Mint):
            return self.value != other.value
        return self.value != other

    def __lt__(self, other: 'Mint') -> bool:
        if isinstance(other, Mint):
            return self.value < other.value
        return self.value < other

    def __le__(self, other: 'Mint') -> bool:
        if isinstance(other, Mint):
            return self.value <= other.value
        return self.value <= other

    def __gt__(self, other: 'Mint') -> bool:
        if isinstance(other, Mint):
            return self.value > other.value
        return self.value > other

    def __ge__(self, other: 'Mint') -> bool:
        if isinstance(other, Mint):
            return self.value >= other.value
        return self.value >= other

    def __repr__(self) -> str:
        return str(self.value)


def inverse(a: int, m: int) -> int:
    u, v = 0, 1
    while a != 0:
        t = m // a
        m -= t * a
        a, m = m, a
        u -= t * v
        u, v = v, u
    assert m == 1
    return u


class Modular:
    def __init__(self, value: int = 0):
        self.value = value % self.mod()

    @staticmethod
    def normalize(x: int) -> int:
        if -Modular.mod() <= x < Modular.mod():
            return x
        return x % Modular.mod()

    def __call__(self) -> int:
        return self.value

    def __int__(self) -> int:
        return self.value

    @staticmethod
    def mod() -> int:
        return MOD

    def __iadd__(self, other: 'Modular') -> 'Modular':
        self.value = self.normalize(self.value + other.value)
        return self

    def __isub__(self, other: 'Modular') -> 'Modular':
        self.value = self.normalize(self.value - other.value)
        return self

    def __add__(self, other: 'Modular') -> 'Modular':
        return Modular(self.value + other.value)

    def __sub__(self, other: 'Modular') -> 'Modular':
        return Modular(self.value - other.value)

    def __imul__(self, other: 'Modular') -> 'Modular':
        self.value = self.normalize(self.value * other.value)
        return self

    def __mul__(self, other: 'Modular') -> 'Modular':
        return Modular(self.value * other.value)

    def __itruediv__(self, other: 'Modular') -> 'Modular':
        self.value = self.normalize(self.value * inverse(other.value, self.mod()))
        return self

    def __truediv__(self, other: 'Modular') -> 'Modular':
        return Modular(self.value * inverse(other.value, self.mod()))

    def __neg__(self) -> 'Modular':
        return Modular(-self.value)

    def __repr__(self) -> str:
        return str(self.value)


def get_prime(n: int) -> List[int]:
    minp = [0] * (n + 1)
    p = []
    for i in range(2, n + 1):
        if not minp[i]:
            minp[i] = i
            p.append(i)
        for x in p:
            if x <= minp[i] and x * i <= n:
                minp[x * i] = x
            else:
                break
    return p


def power(a: Modular, b: int) -> Modular:
    assert b >= 0
    x = a
    res = Modular(1)
    p = b
    while p > 0:
        if p & 1:
            res *= x
        x *= x
        p >>= 1
    return res


def get_mid(l: int, r: int) -> int:
    assert l <= r
    return l + (r - l) // 2


def get_bit(a: int, i: int) -> int:
    return (a >> i) & 1


def get_id(l: int, r: int) -> int:
    assert 0 <= l <= r
    return l + r | (l != r)


def ceil(x: int, y: int) -> int:
    return (x + y - 1) // y


def lowbit(x: int) -> int:
    return x & -x


def build_sparse_table(arr: List[int]) -> List[List[int]]:
    n = len(arr)
    logn = (n - 1).bit_length()
    st = [[0] * logn for _ in range(n)]
    st[0] = arr[:]
    for j in range(1, logn):
        for i in range(n - (1 << j) + 1):
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1])
    return st


def query_sparse_table(st: List[List[int]], l: int, r: int) -> int:
    j = (r - l + 1).bit_length() - 1
    return min(st[l][j], st[r - (1 << j) + 1][j])


def solve(n: int, x: List[int], v: List[int], p: List[Modular]) -> Modular:
    if n == 1:
        return Modular(0)
    allowed_collisions = [Modular(0)] * (n - 1)
    for i in range(n - 1):
        allowed_collisions[i] = [Modular(0), p[i + 1]]
    a = [allowed_collisions[i] for i in range(n - 1)]
    get_prob = lambda: to_right * (mat[1][0] + mat[1][1]) + (1 - to_right) * (mat[0][0] + mat[0][1])
    build = lambda l, r: None if l == r else (build(l, mid), build(mid + 1, r), a[get_id(l, r)].__imul__(a[get_id(l, mid)] * a[get_id(mid + 1, r)]))
    modify = lambda l, r, k: None if l == r else (modify(l, mid, k) if k <= mid else modify(mid + 1, r, k), a[get_id(l, r)].__imul__(a[get_id(l, mid)] * a[get_id(mid + 1, r)]))
    events = []
    for i in range(n - 1):
        d = x[i + 1] - x[i]
        events.append(((d, v[i + 1] + v[i]), i << 2 | 1))
        events.append(((d, v[i + 1] - v[i]), i << 2 | 0))
        events.append(((d, v[i] - v[i + 1]), i << 2 | 3))
    events.sort()
    prev_prob = get_prob()
    ans = Modular(0)
    for event in reversed(events):
        i = event[1] >> 2
        dir1 = get_bit(event[1], 0)
        dir2 = get_bit(event[1], 1)
        allowed_collisions[i][dir1][dir2] = p[i + 1] if dir2 else 1 - p[i + 1]
        modify(0, n - 2, i)
        prob = get_prob()
        if not isclose(event[0][1], 0):
            ans += (prob - prev_prob) * event[0][0] / event[0][1]
        prev_prob = prob
    return ans


def from_input_string(input_string: str) -> Tuple[int, List[int], List[int], List[Modular]]:
    lines = input_string.strip().split('\n')
    n = int(lines[0])
    x = list(map(int, lines[1].split()))
    v = list(map(int, lines[2].split()))
    p = [Modular(int(x)) for x in lines[3].split()]
    return n, x, v, p


def to_input_string(inputs: Tuple[int, List[int], List[int], List[Modular]]) -> str:
    n = inputs[0]
    x = ' '.join(map(str, inputs[1]))
    v = ' '.join(map(str, inputs[2]))
    p = ' '.join(str(x) for x in inputs[3])
    return f"{n}\n{x}\n{v}\n{p}"


def from_output_string(output_string: str) -> Modular:
    return Modular(int(output_string.strip()))


def to_output_string(output: Modular) -> str:
    return str(output)


EXAMPLES_PROVIDED = [{'input': '2\n0 1\n1 0\n100 100\n', 'output': '0\n'}, {'input': '2\n0 1\n1 0\n0 100\n', 'output': '1\n'}, {'input': '2\n0 1\n1 0\n100 0\n', 'output': '0\n'}, {'input': '2\n0 1\n1 0\n100 100\n', 'output': '0\n'}, {'input': '2\n0 1\n1 0\n...

for example in EXAMPLES_PROVIDED:
    input_str = example['input']
    expected_output_str = example['output']
    inputs = from_input_string(input_str)
    expected_output = from_output_string(expected_output_str)

    # Ensure the function is correct
    assert solve(*inputs) == expected_output

    # Ensure str -> variable -> str consistency, while ignoring leading/trailing white space
    assert input_str.strip() == to_input_string(from_input_string(input_str)).strip()
    assert expected_output_str.strip() == to_output_string(from_output_string(expected_output_str)).strip()

    # Ensure variable -> str -> variable consistency
    assert inputs == from_input_string(to_input_string(inputs))
