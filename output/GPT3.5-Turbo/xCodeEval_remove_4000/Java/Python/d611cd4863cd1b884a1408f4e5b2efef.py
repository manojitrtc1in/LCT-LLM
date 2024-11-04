import random
from collections.abc import MutableMapping

class id11(MutableMapping):
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

class id17:
    def __init__(self, size):
        self.size = size
        self.value = [0] * (4 * size)
        self.delta = [0] * (4 * size)
    
    def joinValue(self, left, right):
        return left + right
    
    def joinDelta(self, was, delta):
        return was + delta
    
    def accumulate(self, value, delta, length):
        return value + delta * length
    
    def neutralValue(self):
        return 0
    
    def neutralDelta(self):
        return 0
    
    def initValue(self, index):
        return 0
    
    def init(self):
        self.initHelper(0, 0, self.size - 1)
    
    def initHelper(self, root, left, right):
        if left == right:
            self.value[root] = self.initValue(left)
        else:
            middle = (left + right) // 2
            self.initHelper(2 * root + 1, left, middle)
            self.initHelper(2 * root + 2, middle + 1, right)
            self.value[root] = self.joinValue(self.value[2 * root + 1], self.value[2 * root + 2])
    
    def pushDown(self, root, left, middle, right):
        self.value[2 * root + 1] = self.accumulate(self.value[2 * root + 1], self.delta[root], middle - left + 1)
        self.value[2 * root + 2] = self.accumulate(self.value[2 * root + 2], self.delta[root], right - middle)
        self.delta[2 * root + 1] = self.joinDelta(self.delta[2 * root + 1], self.delta[root])
        self.delta[2 * root + 2] = self.joinDelta(self.delta[2 * root + 2], self.delta[root])
        self.delta[root] = self.neutralDelta()
    
    def update(self, from_, to, delta):
        self.updateHelper(0, 0, self.size - 1, from_, to, delta)
    
    def updateHelper(self, root, left, right, from_, to, delta):
        if left > to or right < from_:
            return
        if left >= from_ and right <= to:
            self.value[root] = self.accumulate(self.value[root], delta, right - left + 1)
            self.delta[root] = self.joinDelta(self.delta[root], delta)
            return
        middle = (left + right) // 2
        self.pushDown(root, left, middle, right)
        self.updateHelper(2 * root + 1, left, middle, from_, to, delta)
        self.updateHelper(2 * root + 2, middle + 1, right, from_, to, delta)
        self.value[root] = self.joinValue(self.value[2 * root + 1], self.value[2 * root + 2])
    
    def query(self, from_, to):
        return self.queryHelper(0, 0, self.size - 1, from_, to)
    
    def queryHelper(self, root, left, right, from_, to):
        if left > to or right < from_:
            return self.neutralValue()
        if left >= from_ and right <= to:
            return self.value[root]
        middle = (left + right) // 2
        self.pushDown(root, left, middle, right)
        leftResult = self.queryHelper(2 * root + 1, left, middle, from_, to)
        rightResult = self.queryHelper(2 * root + 2, middle + 1, right, from_, to)
        return self.joinValue(leftResult, rightResult)
