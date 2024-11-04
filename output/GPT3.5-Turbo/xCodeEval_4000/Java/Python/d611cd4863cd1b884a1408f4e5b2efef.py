import random
from collections.abc import MutableMapping

class EHashMap(MutableMapping):
    def __init__(self):
        self.data = {}
    
    def __getitem__(self, key):
        return self.data[key]
    
    def __setitem__(self, key, value):
        self.data[key] = value
    
    def __delitem__(self, key):
        del self.data[key]
    
    def __iter__(self):
        return iter(self.data)
    
    def __len__(self):
        return len(self.data)
    
    def __contains__(self, key):
        return key in self.data
    
    def clear(self):
        self.data.clear()
    
    def keys(self):
        return self.data.keys()
    
    def values(self):
        return self.data.values()
    
    def items(self):
        return self.data.items()

class IntervalTree:
    def __init__(self, size, should_init=True):
        self.size = size
        self.data = [0] * (4 * size)
        self.delta = [0] * (4 * size)
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

class TreapSet:
    def __init__(self):
        self.data = EHashMap()
    
    def add(self, value):
        self.data[value] = True
    
    def remove(self, value):
        del self.data[value]
    
    def contains(self, value):
        return value in self.data
    
    def size(self):
        return len(self.data)
    
    def isEmpty(self):
        return len(self.data) == 0
    
    def clear(self):
        self.data.clear()
    
    def __iter__(self):
        return iter(self.data.keys())
    
    def __len__(self):
        return len(self.data)
    
    def __contains__(self, value):
        return value in self.data
