class IterRange:
    def __init__(self, first, second):
        self.first = first
        self.second = second

    def begin(self):
        return self.first

    def end(self):
        return self.second


def rev(origin):
    return IterRange(reversed(origin.end()), reversed(origin.begin()))


class IntIter:
    def __init__(self, i=0):
        self.i = i

    def __iter__(self):
        return self

    def __next__(self):
        result = self.i
        self.i += 1
        return result

    def __add__(self, step):
        return IntIter(self.i + step)

    def __sub__(self, step):
        return IntIter(self.i - step)

    def __eq__(self, other):
        return self.i == other.i

    def __ne__(self, other):
        return not self.__eq__(other)

    def __getitem__(self, n):
        return self.i + n


def range_func(b, e=None):
    if e is None:
        return IterRange(IntIter(0), IntIter(b))
    return IterRange(IntIter(b), IntIter(e if e > b else b))


def nrange(n):
    return range_func(1, n + 1)


def inrange(b, e):
    return range_func(b, e + 1)


def chmax(m, v):
    if v > m:
        m = v
        return True
    return False


def chmin(m, v):
    if v < m:
        m = v
        return True
    return False


def max_s(*args):
    return max(args)


def min_s(*args):
    return min(args)


class ListHead:
    def __init__(self):
        self.prev = self
        self.next = self

    def empty(self):
        return self.next == self

    def unlink(self):
        self.link(self.prev, self.next)
        self.reset()

    def insert_next(self, new_next):
        self.link(new_next, self.next)
        self.link(self, new_next)

    def insert_prev(self, new_prev):
        self.link(self.prev, new_prev)
        self.link(new_prev, self)

    @staticmethod
    def link(prev, next):
        prev.next = next
        next.prev = prev

    def reset(self):
        self.prev = self
        self.next = self


class ListIter:
    def __init__(self, head):
        self.cur = head

    def __iter__(self):
        return self

    def __next__(self):
        if self.cur is None:
            raise StopIteration
        result = self.cur
        self.cur = self.cur.next
        return result

    def __eq__(self, other):
        return self.cur == other.cur

    def __ne__(self, other):
        return not self.__eq__(other)


class Node:
    def __init__(self, v, pos):
        self.lh = ListHead()
        self.v = v
        self.pos = pos


maxn = 500005
lst = ListHead()
arr = [Node(0, i) for i in range(maxn)]
splay = []
ans = 0

n = int(input())
for i in range(n):
    v = int(input())
    arr[i].v = v
    arr[i].pos = i

for i in range(n):
    splay.append(arr[i])
    lst.insert_prev(arr[i].lh)

last_left = 0
last_right = 0

while splay:
    it = splay.pop(0)
    root = ListIter(lst)
    left = next(root).pos
    right = prev(root).pos
    if it.pos == left and it.pos == right:
        ans += min(last_left, last_right)
    elif it.pos == left:
        ans += last_left
        last_left = it.v
    elif it.pos == right:
        ans += last_right
        last_right = it.v
    else:
        ans += min(next(it).v, prev(it).v)
    it.lh.unlink()

print(ans)
