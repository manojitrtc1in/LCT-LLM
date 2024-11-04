import math

class chest_t:
    def __init__(self):
        self.foo = {}
    
    def clear(self):
        self.foo.clear()
    
    def put(self, key, val=1):
        if val == 0:
            return
        if key in self.foo:
            self.foo[key] += val
        else:
            self.foo[key] = val
    
    def pop(self, key, val=math.inf):
        res = 0
        if key in self.foo:
            if self.foo[key] > val:
                res = val
                self.foo[key] -= val
            else:
                res = self.foo[key]
                del self.foo[key]
        return res

n = int(input())
a = list(map(int, input().split()))
_seq = [0] * 50
_sup = [0] * 50
seq = [0] * 50
sup = [0] * 50

def process(from_):
    seq[:] = _seq[:]
    sup[:] = _sup[:]
    if from_ + from_ < seq[0]:
        return 1
    open_ = chest_t()
    close = chest_t()
    open_.put(0, from_ - (seq[0] - from_))
    close.put(0, seq[0] - from_)
    for i in range(1, 45):
        ext = open_.pop(i - 1, seq[i])
        seq[i] -= ext
        open_.put(i, ext)
        ext = close.pop(i - 1, seq[i])
        sup[i] += seq[i] - ext
        close.put(i, ext)
        cls = open_.pop(i, sup[i])
        sup[i + 1] += sup[i] - cls
        close.put(i, cls)
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

for i in range(50):
    _seq[i] = 0
    _sup[i] = 0

cur = 0
for i in range(n):
    while a[i] >= (1 << (cur + 1)):
        cur += 1
    if a[i] == (1 << cur):
        _seq[cur] += 1
    else:
        _sup[cur] += 1

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
