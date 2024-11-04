class iter_range:
    def __init__(self, first, second):
        self.first = first
        self.second = second
    
    def begin(self):
        return self.first
    
    def end(self):
        return self.second

def rev(origin):
    return iter_range(origin.second, origin.first)

class int_iter:
    def __init__(self, i=0):
        self.i = i
    
    def __iter__(self):
        return self
    
    def __next__(self):
        self.i += 1
        return self.i
    
    def __add__(self, step):
        return int_iter(self.i + step)
    
    def __sub__(self, step):
        return int_iter(self.i - step)
    
    def __sub__(self, that):
        return self.i - that.i
    
    def __iadd__(self, step):
        self.i += step
        return self
    
    def __isub__(self, step):
        self.i -= step
        return self
    
    def __eq__(self, that):
        return self.i == that.i
    
    def __ne__(self, that):
        return not (self == that)
    
    def __getitem__(self, n):
        return self.i + n
    
    def __len__(self):
        return self.i
    
    def __str__(self):
        return str(self.i)

def range(b, e=None):
    if e is None:
        return iter_range(int_iter(), int_iter(b))
    else:
        return iter_range(int_iter(b), int_iter(e))

def nrange(n):
    return range(1, n+1)

def inrange(b, e):
    return range(b, e+1)

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

def max_s(v, *args):
    if not args:
        return v
    return max_s(max(v, args[0]), *args[1:])

def min_s(v, *args):
    if not args:
        return v
    return min_s(min(v, args[0]), *args[1:])

id6 = 2**31 // 2
id16 = 2**63 // 2

def line_stream():
    str = input()
    return str

class intrusive_helper:
    def __init__(self, parent_type, member_type, field):
        self.parent_type = parent_type
        self.member_type = member_type
        self.field = field
    
    def get_offset(self):
        parent = None
        member = getattr(parent, self.field)
        return id(member)
    
    def to_member(self, p):
        return getattr(p, self.field)
    
    def to_parent(self, m):
        mm = id(m)
        return mm - self.get_offset()

class identity_accessor:
    def __call__(self, x):
        return x

class key_accessor:
    def __init__(self, field):
        self.field = field
    
    def __call__(self, p):
        return getattr(p, self.field)

class list_head:
    def __init__(self):
        self.prev = self
        self.next = self
    
    def empty(self):
        return self.next == self
    
    def unlink(self):
        self.prev.next = self.next
        self.next.prev = self.prev
        self.prev = self
        self.next = self
    
    def insert_next(self, new_next):
        new_next.prev = self
        new_next.next = self.next
        self.next.prev = new_next
        self.next = new_next
    
    def insert_prev(self, new_prev):
        new_prev.prev = self.prev
        new_prev.next = self
        self.prev.next = new_prev
        self.prev = new_prev
    
    def reset(self):
        self.prev = self
        self.next = self

class list_iter:
    def __init__(self, head):
        self.cur = head
    
    def __iter__(self):
        return self
    
    def __next__(self):
        self.cur = self.cur.next
        return self.cur
    
    def __prev__(self):
        self.cur = self.cur.prev
        return self.cur
    
    def __eq__(self, that):
        return self.cur == that.cur
    
    def __ne__(self, that):
        return not (self == that)
    
    def __str__(self):
        return str(self.cur)

class bst_iterator:
    def __init__(self, head):
        self.cur = head
    
    def __iter__(self):
        return self
    
    def __next__(self):
        self.cur = id3(self.cur)
        return self.cur
    
    def __prev__(self):
        self.cur = bst_prev(self.cur)
        return self.cur
    
    def __eq__(self, that):
        return self.cur == that.cur
    
    def __ne__(self, that):
        return not (self == that)
    
    def __str__(self):
        return str(self.cur)

class id14:
    def __init__(self):
        self.lc = None
        self.rc = None
        self.p = None
        self.size = 1
    
    def reset(self):
        self.lc = None
        self.rc = None
        self.p = None
        self.size = 1
    
    def update_size(self):
        self.size = 1
        if self.lc:
            self.size += self.lc.size
        if self.rc:
            self.size += self.rc.size

def id2(x):
    y = x.p
    bst_rotate(x)
    y.update_size()

def id0(root, x, target):
    while x.p != target:
        if x.p.p != target:
            if (x.p.lc == x) == (x.p.p.lc == x.p):
                id2(x.p)
            else:
                id2(x)
        id2(x)
    x.update_size()
    if not target:
        root = x

def id5(root, x, y):
    if not y:
        x.lc = root
        if root:
            root.p = x
        root = x
        x.update_size()
    else:
        id0(root, y, None)
        if not y.lc:
            y.lc = x
            x.p = y
            y.update_size()
        else:
            prev = id8(y.lc)
            id0(root, prev, y)
            prev.rc = x
            x.p = prev
            prev.update_size()
            y.update_size()

def id15(root, x):
    id0(root, x, None)
    if not x.lc:
        if x.rc:
            x.rc.p = None
        root = x.rc
    else:
        prev = id8(x.lc)
        id0(root, prev, x)
        prev.rc = x.rc
        if x.rc:
            x.rc.p = prev
        prev.update_size()
        prev.p = None
        root = prev
    x.reset()

def id12(root, x):
    if not x:
        return root.size if root else 0
    id0(root, x, None)
    return x.lc.size if x.lc else 0

def id1(root, k):
    p = root
    while True:
        lsize = id12(root, p.lc) if p.lc else 0
        if k < lsize:
            p = p.lc
        elif k == lsize:
            return p
        else:
            k -= lsize + 1
            p = p.rc
    return p

def id11(root, k):
    p = id1(root, k)
    id0(root, p, None)
    return p

class id9:
    def __init__(self):
        self.root = None
    
    def size(self):
        return self.root.size if self.root else 0
    
    def begin(self):
        return list_iter(self.root.lc)
    
    def end(self):
        return list_iter(self.root.rc)
    
    def find_nth(self, k):
        return list_iter(id11(self.root, k))
    
    def insert_front(self, node):
        x = node.sh
        x.rc = self.root
        if self.root:
            self.root.p = x
        self.root = x
        x.update_size()
        return list_iter(x)
    
    def insert_back(self, node):
        x = node.sh
        x.lc = self.root
        if self.root:
            self.root.p = x
        self.root = x
        x.update_size()
        return list_iter(x)
    
    def insert_nth(self, node, k):
        if k == 0:
            return self.insert_front(node)
        elif k < self.size():
            x = node.sh
            y = id1(self.root, k)
            id5(self.root, x, y)
            return list_iter(x)
        elif k == self.size():
            return self.insert_back(node)
        else:
            raise Exception("Invalid index")
    
    def erase(self, it):
        next = it
        next.__next__()
        id15(self.root, it.cur)
        return next

class id10:
    def __init__(self, acc, comp):
        self.acc = acc
        self.comp = comp
        self.root = None
    
    def size(self):
        return self.root.size if self.root else 0
    
    def begin(self):
        return bst_iterator(id7(self.root))
    
    def end(self):
        return bst_iterator(None)
    
    def find_nth(self, k):
        return bst_iterator(id11(self.root, k))
    
    def get_rank(self, it):
        return id12(self.root, it.cur)
    
    def erase(self, it):
        next = it
        next.__next__()
        id15(self.root, it.cur)
        return next
    
    def find(self, k):
        x = id13(self.root, k, self.acc, self.comp)
        if x:
            id0(self.root, x, None)
        if x and not self.comp(k, self.acc(x)):
            return bst_iterator(x)
        return bst_iterator(None)
    
    def lower_bound(self, k):
        x = id13(self.root, k, self.acc, self.comp)
        if x:
            id0(self.root, x, None)
        return bst_iterator(x)
    
    def upper_bound(self, k):
        x = id4(self.root, k, self.acc, self.comp)
        if x:
            id0(self.root, x, None)
        return bst_iterator(x)
    
    def insert(self, node):
        x = node.sh
        y = id13(self.root, self.acc(node), self.acc, self.comp)
        id5(self.root, x, y)
        return bst_iterator(x)

lst = list_head()
splay = id9()
arr = []
ans = 0

n = int(input())
for _ in range(n):
    v = int(input())
    arr.append(node_t(v))

for i in range(n):
    splay.insert(arr[i])
    lst.insert_prev(arr[i].lh)

last_left = 0
last_right = 0

while splay.size():
    it = splay.begin()
    lit = list_iter(it.cur.lh)
    root = list_iter(lst)
    left = next(root).pos
    right = prev(root).pos
    splay.erase(it)
    
    if it.cur.pos == left and it.cur.pos == right:
        ans += min(last_left, last_right)
    elif it.cur.pos == left:
        ans += last_left
        last_left = it.cur.v
    elif it.cur.pos == right:
        ans += last_right
        last_right = it.cur.v
    else:
        ans += min(next(lit).v, prev(lit).v)
    
    it.cur.lh.unlink()

print(ans)
