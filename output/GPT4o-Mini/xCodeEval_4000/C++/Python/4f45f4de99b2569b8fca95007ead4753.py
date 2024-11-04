import sys
from collections import defaultdict
from math import sqrt, acos, sin, cos

MOD = 1000000007
MODL = 1000000000000000003
eps = 1e-8
inf = 0x3f3f3f3f

class Chest:
    def __init__(self):
        self.foo = defaultdict(int)

    def clear(self):
        self.foo.clear()

    def put(self, key, val=1):
        if val == 0:
            return
        self.foo[key] += val

    def pop(self, key, val=inf):
        res = 0
        if key in self.foo:
            if self.foo[key] > val:
                res = val
                self.foo[key] -= val
            else:
                res = self.foo[key]
                del self.foo[key]
        return res

def process(from_val):
    global seq, sup
    seq = _seq[:]
    sup = _sup[:]
    if from_val + from_val < seq[0]:
        return 1
    open_chest.clear()
    close_chest.clear()
    open_chest.put(0, from_val - (seq[0] - from_val))
    close_chest.put(0, seq[0] - from_val)
    
    for i in range(1, 45):
        ext = open_chest.pop(i - 1, seq[i])
        seq[i] -= ext
        open_chest.put(i, ext)
        ext = close_chest.pop(i - 1, seq[i])
        sup[i] += seq[i] - ext
        close_chest.put(i, ext)
        cls = open_chest.pop(i, sup[i])
        sup[i + 1] += sup[i] - cls
        close_chest.put(i, cls)
    
    if sup[45] != 0:
        return 1
    return 0

def find(lef, rig):
    while lef <= rig:
        mid = (lef + rig) // 2
        if not process(mid):
            if mid == lef or process(mid - 1):
                return mid
            rig = mid - 1
        else:
            lef = mid + 1
    return -1

input_data = sys.stdin.read
data = input_data().split()
index = 0

while index < len(data):
    n = int(data[index])
    index += 1
    a = [int(data[i]) for i in range(index, index + n)]
    index += n

    _seq = [0] * 50
    _sup = [0] * 50
    cur = 0

    for i in range(n):
        while a[i] >= (1 << (cur + 1)):
            cur += 1
        if a[i] == (1 << cur):
            _seq[cur] += 1
        else:
            _sup[cur] += 1

    open_chest = Chest()
    close_chest = Chest()

    if process(_seq[0]):
        print("-1")
    else:
        hig = _seq[0]
        low = find(1, hig)
        for i in range(low, hig + 1):
            if i != low:
                print(" ", end="")
            print(i, end="")
        print()
