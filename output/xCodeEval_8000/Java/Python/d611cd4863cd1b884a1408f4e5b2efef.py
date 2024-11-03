import random

class IntervalTree:
    def __init__(self, size, should_init=True):
        self.size = size
        node_count = max(1, 2**(size.bit_length() + 1))
        self.data = [0] * node_count
        self.delta = [0] * node_count
        if should_init:
            self.init()

    def init_data(self, size, node_count):
        self.data = [0] * node_count
        self.delta = [0] * node_count

    def init_after(self, root, left, right, middle):
        self.data[root] = self.join_value(self.data[2 * root + 1], self.data[2 * root + 2])
        self.delta[root] = self.neutral_delta()

    def init_before(self, root, left, right, middle):
        pass

    def init_leaf(self, root, index):
        self.data[root] = self.init_value(index)
        self.delta[root] = self.neutral_delta()

    def update_post_process(self, root, left, right, from_, to, delta, middle):
        self.data[root] = self.join_value(self.data[2 * root + 1], self.data[2 * root + 2])

    def update_pre_process(self, root, left, right, from_, to, delta, middle):
        self.push_down(root, left, middle, right)

    def push_down(self, root, left, middle, right):
        self.data[2 * root + 1] = self.accumulate(self.data[2 * root + 1], self.delta[root], middle - left + 1)
        self.data[2 * root + 2] = self.accumulate(self.data[2 * root + 2], self.delta[root], right - middle)
        self.delta[2 * root + 1] = self.join_delta(self.delta[2 * root + 1], self.delta[root])
        self.delta[2 * root + 2] = self.join_delta(self.delta[2 * root + 2], self.delta[root])
        self.delta[root] = self.neutral_delta()

    def update_full(self, root, left, right, from_, to, delta):
        self.data[root] = self.accumulate(self.data[root], delta, right - left + 1)
        self.delta[root] = self.join_delta(self.delta[root], delta)

    def query_post_process(self, root, left, right, from_, to, middle, left_result, right_result):
        return self.join_value(left_result, right_result)

    def query_pre_process(self, root, left, right, from_, to, middle):
        self.push_down(root, left, middle, right)

    def query_full(self, root, left, right, from_, to):
        return self.data[root]

    def empty_segment_result(self):
        return self.neutral_value()

    def init(self):
        if self.size == 0:
            return
        self.init_(0, 0, self.size - 1)

    def init_(self, root, left, right):
        if left == right:
            self.init_leaf(root, left)
        else:
            middle = (left + right) // 2
            self.init_before(root, left, right, middle)
            self.init_(2 * root + 1, left, middle)
            self.init_(2 * root + 2, middle + 1, right)
            self.init_after(root, left, right, middle)

    def update(self, from_, to, delta):
        self.update_(0, 0, self.size - 1, from_, to, delta)

    def update_(self, root, left, right, from_, to, delta):
        if left > to or right < from_:
            return
        if left >= from_ and right <= to:
            self.update_full(root, left, right, from_, to, delta)
            return
        middle = (left + right) // 2
        self.update_pre_process(root, left, right, from_, to, delta, middle)
        self.update_(2 * root + 1, left, middle, from_, to, delta)
        self.update_(2 * root + 2, middle + 1, right, from_, to, delta)
        self.update_post_process(root, left, right, from_, to, delta, middle)

    def query(self, from_, to):
        return self.query_(0, 0, self.size - 1, from_, to)

    def query_(self, root, left, right, from_, to):
        if left > to or right < from_:
            return self.empty_segment_result()
        if left >= from_ and right <= to:
            return self.query_full(root, left, right, from_, to)
        middle = (left + right) // 2
        self.query_pre_process(root, left, right, from_, to, middle)
        left_result = self.query_(2 * root + 1, left, middle, from_, to)
        right_result = self.query_(2 * root + 2, middle + 1, right, from_, to)
        return self.query_post_process(root, left, right, from_, to, middle, left_result, right_result)

    def accumulate(self, value, delta, length):
        return value + delta * length

    def join_value(self, left, right):
        return left + right

    def join_delta(self, was, delta):
        return was + delta

    def neutral_value(self):
        return 0

    def neutral_delta(self):
        return 0

    def init_value(self, index):
        return 0

class LongIntervalTree(LongIntervalTree):
    def __init__(self, size):
        super().__init__(size)

    def accumulate(self, value, delta, length):
        return value + delta * length

    def join_value(self, left, right):
        return left + right

    def join_delta(self, was, delta):
        return was + delta

    def neutral_value(self):
        return 0

    def neutral_delta(self):
        return 0

    def init_value(self, index):
        return 0

class EHashMap:
    def __init__(self):
        self.size = 0
        self.capacity = 4
        self.data = [None] * self.capacity

    def clear(self):
        self.size = 0
        self.data = [None] * self.capacity

    def index(self, o):
        return self.get_hash(hash(o)) & (self.capacity - 1)

    def get_hash(self, h):
        result = h
        for i in [1, 4, 7]:
            result ^= h >> i
        return result

    def remove(self, o):
        if o is None:
            return None
        index = self.index(o)
        current = self.data[index]
        last = None
        while current is not None:
            if current.key == o:
                if last is None:
                    self.data[index] = current.next
                else:
                    last.next = current.next
                self.size -= 1
                return current.value
            last = current
            current = current.next
        return None

    def put(self, e, value):
        if e is None:
            return None
        index = self.index(e)
        current = self.data[index]
        if current is not None:
            while True:
                if current.key == e:
                    old_value = current.value
                    current.value = value
                    return old_value
                if current.next is None:
                    break
                current = current.next
        if current is None:
            self.data[index] = HashEntry(e, value)
        else:
            current.next = HashEntry(e, value)
        self.size += 1
        if 2 * self.size > self.capacity:
            old_data = self.data
            self.set_capacity(self.size)
            for entry in old_data:
                while entry is not None:
                    next = entry.next
                    index = self.index(entry.key)
                    entry.next = self.data[index]
                    self.data[index] = entry
                    entry = next
        return None

    def get(self, o):
        if o is None:
            return None
        index = self.index(o)
        current = self.data[index]
        while current is not None:
            if current.key == o:
                return current.value
            current = current.next
        return None

    def contains_key(self, o):
        if o is None:
            return False
        index = self.index(o)
        current = self.data[index]
        while current is not None:
            if current.key == o:
                return True
            current = current.next
        return False

    def size(self):
        return self.size

    def set_capacity(self, size):
        self.capacity = 1 << (size.bit_length() + 1)
        self.data = [None] * self.capacity

class HashEntry:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None
