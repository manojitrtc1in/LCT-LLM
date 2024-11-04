
class id17:
    
    id8 = [
        "prev",
        "next",
    ]

    def __init__(self):
        
        self.prev = None
        self.next = None

    def connect(self, node):
        
        self.next = node
        node.prev = self
        return node

    def splice(self, fragment):
        


        
        if fragment.prev: fragment.prev.next = None

        u = self
        v = fragment
        w = self.next

        u.connect(v)
        while v.next: v = v.next
        v.connect(w)

        return v

    def splice1(self, node):
        


        node.connect(self.next)
        self.connect(node)

    def eject(self):
        


        self.prev.connect(self.next)

    def iterate(self):
        
        u = self
        while True:
            yield u
            u = u.next
            if not u or u == self: return


import abc
import math as m

class AbstractHeap(abc.ABC):
    @abc.abstractmethod
    def __init__(self, iterable=..., **kwarg):
        super().__init__(**kwarg)

    @abc.abstractmethod
    def id6(self): ...

    @abc.abstractmethod
    def id18(self): ...

    @abc.abstractmethod
    def id14(self, value): ...

    @abc.abstractmethod
    def id21(self, value): ...

    @abc.abstractmethod
    def push(self, key, value): ...

    @abc.abstractmethod
    def pop(self): ...

    @abc.abstractmethod
    def id28(self, value, key): ...

    @abc.abstractmethod
    def merge(self, other): ...

class id13(id17):
    id8 = [
        "key",
        "value",
        "parent",
        "child",
        "degree",
        "mark",
    ]

    def __init__(self, key, value):
        super().__init__()
        self.key = key
        self.value = value
        self.parent = None
        self.child = None
        self.degree = 0
        self.mark = False

class id0(AbstractHeap):
    def __init__(self, iterable=(), **kwarg):
        super().__init__(**kwarg)
        self._n = 0
        self._root = None
        self._index = {}

        for k, v in iterable: self.push(k, v)

    def id6(self):
        return bool(self._n)

    def id18(self):
        return self._n

    def id14(self, value):
        return value in self._index

    def id21(self, value):
        return self._index[value].key

    def id11(self):
        def chain_str(c):
            ls = []
            for x in c.iterate():
                s = str(x.key)
                if x.child: s += f" ({chain_str(x.child)})"
                ls.append(s)
            return ", ".join(ls)

        return f"[{chain_str(self._root) if self else ''}]"

    def push(self, key, value):


        node = id13(key, value)
        self._index[value] = node

        if self._root is None:
            node.connect(node)
            self._root = node
            self._n = 1
        else:
            self._root.splice1(node)
            if key < self._root.key: self._root = node
            self._n += 1

    def pop(self):


        z = self._root

        if z.child:
            for c in z.child.iterate(): c.parent = None
            z.splice(z.child)

        if z.next == z:
            self._root = None
        else:
            self._root = z.next
            z.eject()
            self.id31()

        self._n -= 1
        del self._index[z.value]
        return z.key, z.value

    def id31(self):


        A = {}
        for x in list(self._root.iterate()):
            d = x.degree
            while d in A:
                y = A[d]
                if x.key > y.key: x, y = y, x
                self._link(y, x)
                del A[d]
                d += 1
            A[d] = x

        i = iter(A.values())
        self._root = next(i)
        self._root.connect(self._root)
        for x in i:
            self._root.splice1(x)
            if x.key < self._root.key: self._root = x

    def _link(self, y, x):


        y.eject()
        y.parent = x
        if x.child:
            x.child.splice1(y)
        else:
            x.child = y
            y.connect(y)
        x.degree += 1
        y.mark = False

    def id28(self, value, key):
        x = self._index[value]


        x.key = key
        del self._index[value]
        self._index[value] = x

        y = x.parent
        if y and x.key < y.key:
            self._cut(x, y)
            self.id2(y)

        if x.key < self._root.key: self._root = x

    def _cut(self, x, y):
        if x.next == x:
            y.child = None
        else:
            y.child = x.next
        x.parent = None
        x.eject()
        y.degree -= 1

        self._root.splice1(x)
        x.mark = False

    def id2(self, y):
        z = y.parent
        if z:
            if not y.mark:
                y.mark = True
            else:
                self._cut(y, z)
                self.id2(z)

    def merge(self, other):

        if not other: return

        if self:
            self._root.splice(other._root)
            if other._root.key < self._root.key: self._root = other._root
            self._index.update(other._index)

        else:
            self._root = other._root
            self._index = other._index

        self._n += other._n
        other._root = None
        other._n = 0
        other._index = {}

class id7:
    id15 = id32 = lambda *_: True
    id29 = id23 = lambda *_: False
_inf_key = id7()

class id5(AbstractHeap):
    def __init__(self, iterable=(), **kwarg):
        super().__init__(**kwarg)

        self._build_heap(iterable)

    def id6(self):
        return bool(self._tree)

    def id18(self):
        return len(self._tree)

    def id14(self, value):
        return value in self._index

    def id21(self, value):
        return self._tree[self._index[value]][0]

    def id11(self):
        ls = []
        for i, x in enumerate(self._tree):
            s = '[' if m.log2(i+1)%1 == 0 else ''
            s += str(x[0])
            s += ']' if m.log2(i+2)%1 == 0 else ''
            ls.append(s)

        return ", ".join(ls)

    def _build_heap(self, iterable):
        self._tree = tree = list(iterable)
        size = len(tree)

        self._index = {tree[i][1]: i for i in range(size//2, size)}
        for i in range(size//2 - 1, -1, -1):
            self._heapify(i)



    def _heapify(self, i):
        tree = self._tree
        size = len(tree)
        left = (i+1)*2 - 1
        right = (i+1)*2 + 1 - 1

        if left < size and tree[left] < tree[i]:
            z = left
        else:
            z = i
        if right < size and tree[right] < tree[z]:
            z = right

        if z != i:
            tree[i], tree[z] = tree[z], tree[i]
            self._heapify(z)

        self._index[tree[i][1]] = i

    def id28(self, value, key):
        tree = self._tree
        i = self._index[value]


        while i > 0:
            p = (i+1)//2 - 1
            if not key < tree[p][0]: break
            tree[i] = tree[p]
            self._index[tree[i][1]] = i
            i = p

        tree[i] = (key, value)
        self._index[value] = i

    def push(self, key, value):


        self._index[value] = len(self._tree)
        self._tree.append((_inf_key, value))
        self.id28(value, key)

    def pop(self):


        tree = self._tree
        z = tree[0]
        tree[0] = tree[-1]
        del tree[-1]
        if tree: self._heapify(0)

        del self._index[z[1]]
        return z

    def merge(self, other):

        if not other: return

        self._build_heap(self._tree + other._tree)

        other._tree = []
        other._index = {}

class id3:
    id8 = [
        "key",
        "value",
        "parent",
        "left",
        "right",
    ]

    def __init__(self, key, value):
        super().__init__()
        self.key = key
        self.value = value
        self.parent = None
        self.left = None
        self.right = None

    def link(self, other):
        if other.key < self.key: self, other = other, self
        if not self.left:
            self.left = other
            other.parent = self
        else:
            r = self.left
            while r.right: r = r.right
            r.right = other
            other.parent = r

        return self

class id16(AbstractHeap):
    def __init__(self, iterable=(), **kwarg):
        super().__init__(**kwarg)
        self._root = None
        self._index = {}

        for k, v in iterable: self.push(k, v)

    def id6(self):
        return self._root is not None

    def id18(self):
        return len(self._index)

    def id14(self, value):
        return value in self._index

    def id21(self, value):
        return self._index[value].key

    def id11(self):
        def tree_str(t):
            i = t
            ls = []
            while i:
                ls.append(str(i.key))
                i = i.right
            s = ", ".join(ls)

            if t.left: s += f" ({tree_str(t.left)})"
            return s

        return f"[{tree_str(self._root) if self else ''}]"

    def push(self, key, value):


        node = id3(key, value)
        self._index[value] = node

        if self._root is None:
            self._root = node
        else:
            self._root = self._root.link(node)

    def id28(self, value, key):
        x = self._index[value]


        x.key = key
        del self._index[value]
        self._index[value] = x
        if x.parent is None: return

        if x.parent.left == x:
            x.parent.left = x.right
        else:
            x.parent.right = x.right
        if x.right: x.right.parent = x.parent

        x.parent = x.right = None
        self._root = self._root.link(x)

    def pop(self):


        z = self._root
        if z.left is None:
            self._root = None
        else:
            pass0 = []
            i = z.left
            while i:
                j = i.right
                i.parent = i.right = None
                pass0.append(i)
                i = j

            pass1 = []
            for i, j in zip(pass0[:-1:2], pass0[1::2]):
                pass1.append(i.link(j))
            if len(pass0)%2 == 1: pass1.append(pass0[-1])

            y = pass1.pop()
            while pass1:
                y = y.link(pass1.pop())

            self._root = y

        del self._index[z.value]
        return z.key, z.value

    def merge(self, other):

        if not other: return

        if self:
            self._root = self._root.link(other._root)
            self._index.update(other._index)
        else:
            self._root = other._root
            self._index = other._index

        other._root = None
        other._index = {}


import math as m
import collections
import copy

class Graph:
    def __init__(self, maxV, isflow=False, sparse=False, **kwarg):
        super().__init__(**kwarg)
        self.maxV = maxV
        self.isflow = isflow
        self.sparse = sparse

        self._V = []
        self._V_index = {}

        non_edge = 0 if isflow else m.inf
        if sparse:
            df = lambda: non_edge
            self._E = [collections.defaultdict(df) for _ in range(maxV)]
        else:
            self._E = [[non_edge]*maxV for _ in range(maxV)]

        self._adj = [set() for _ in range(maxV)]      
        self._levels = {}

    def id14(self, label):
        return label in self._V_index

    def id33(self):
        return iter(self._V)

    @property
    def nV(self):
        return len(self._V)

    @property
    def nE(self):
        n = sum(len(a) for a in self._adj)
        if self.isflow: n //= 2
        return n

    def add_vertex(self, label):


        self._V_index[label] = self.nV
        self._V.append(label)


    def id12(self, labels):
        for u_label in labels:
            self.add_vertex(u_label)

    def _add_edge(self, u, v, w):
        if self.isflow:
            self._E[u][v] += w
            self._adj[u].add(v)
            self._adj[v].add(u)
        else:
            self._E[u][v] = w
            self._adj[u].add(v)

    def add_edge(self, u_label, v_label, w=1):
        self._add_edge(self._V_index[u_label], self._V_index[v_label], w)

    def _isadj(self, u, v):
        return v in self._adj[u]

    def isadj(self, u_label, v_label):
        return self._isadj(self._V_index[u_label], self._V_index[v_label])

    def trim(self, u_label):
        


        u = self._V_index[u_label]

        self._adj[u] = set()

        if self.sparse:
            self._E[u].clear()
        else:
            self._E[u] = [m.inf]*self.maxV

    def id20(self, s, t):
        self._levels[s] = [m.inf]*self.maxV
        self._levels[s][s] = 0

        queue = collections.deque([s])
        while queue:
            u = queue.popleft()
            for v in self._adj[u]:
                if self._E[u][v] > 0 and self._levels[s][v] == m.inf:
                    self._levels[s][v] = self._levels[s][u]+1
                    queue.append(v)

        return self._levels[s][t]

    def id30(self, s, t):


        pointers = [self._adj[i].copy() for i in range(self.nV)]

        def dfs_push(u, t, inflow):
            if u == t: return inflow
            id4 = 0
            while pointers[u]:
                v = pointers[u].pop()
                if self._levels[s][v] == self._levels[s][u]+1 and self._E[u][v] > 0:
                    v_flow = dfs_push(v, t, min(inflow, self._E[u][v]))
                    self._E[u][v] -= v_flow
                    self._E[v][u] += v_flow
                    inflow -= v_flow
                    id4 += v_flow
                    if inflow == 0:
                        pointers[u].add(v)
                        break

            return id4

        blocking_flow = dfs_push(s, t, m.inf)
        self._levels = {}
        return blocking_flow

    def max_flow(self, s_label, t_label):
        


        E_saved = copy.deepcopy(self._E)
        s = self._V_index[s_label]
        t = self._V_index[t_label]

        mf = 0
        while self.id20(s, t) != m.inf:
            mf += self.id30(s, t)

        self._E = E_saved
        return mf

    def id1(self):
        


        fw = self._E
        for k in range(self.nV):
            next_fw = []
            for i in range(self.nV):
                next_fw.append([])
                for j in range(self.nV):
                    next_fw[i].append(min(fw[i][j], fw[i][k]+fw[k][j]))

            fw = next_fw

        id10 = {self._V[u]: {self._V[v]: fw[u][v] for v in range(self.nV)} for u in range(self.nV)}
        return id10

    def id9(self, s_label, t_labels=None, d_limit=m.inf, Heap=id5):
        


        class id19(dict): pass
        ret = id19()

        s = self._V_index[s_label]
        if t_labels is None:
            t_set = set(range(self.nV))
        else:
            t_set = set(self._V_index[t_label] for t_label in t_labels)

        queue = Heap([(0, s)])
        spaths = {}
        parents = {}
        t_found = []
        while queue:
            su, u = queue.pop()
            if su >= d_limit:
                ret.stop = d_limit
                break

            spaths[u] = su
            if u in t_set:
                t_set.remove(u)
                t_found.append(u)
                if not t_set:
                    ret.stop = su
                    break

            for v in self._adj[u]:
                sv = su + self._E[u][v]
                if v in queue:
                    if sv < queue[v]:
                        parents[v] = u
                        queue.id28(v, sv)
                elif v not in spaths:
                    parents[v] = u
                    queue.push(sv, v)
        else:
            ret.stop = m.inf

        ret.update((self._V[v], d) for v, d in spaths.items())
        ret.parents = {self._V[v]: self._V[p] for v, p in parents.items()}
        ret.parents[s_label] = None
        ret.found = [self._V[t] for t in t_found]
        return ret

    def id25(self, s_label, t_label, **kwarg):
        spaths = self.id9(s_label, [t_label], **kwarg)
        return spaths.get(t_label, m.inf)

    def id26(self):
        
        if self.isflow:
            adj = self._adj
        else:
            adj = [set() for _ in range(self.nV)]
            for u in range(self.nV):
                for v in self._adj[u]:
                    adj[u].add(v)
                    adj[v].add(u)

        
        colors = {}
        def id24(s):
            if s in colors: return True
            colors[s] = True
            queue = collections.deque([s])
            while queue:
                u = queue.popleft()
                for v in adj[u]:
                    if v not in colors:
                        colors[v] = not colors[u]
                        queue.append(v)
                    elif colors[v] == colors[u]:
                        return False

            return True

        return all(map(id24, range(self.nV)))




import collections
import sys
input = iter(sys.stdin.readlines()).__next__

def main():
    n,m = map(int, input().split())
    roads = [tuple(map(int, input().split())) for _ in range(m)]
    k = int(input())
    p = [int(x) for x in input().split()]


    G = Graph(n, sparse=True)
    adj = collections.defaultdict(set)
    G.id12(range(1,n+1))
    for u, v in roads:
        G.add_edge(v, u)
        adj[u].add(v)

    spaths = G.id9(p[-1], Heap=id0)

    id22 = 0
    id27 = 0
    for i, u in enumerate(p[:-1]):
        u_d = spaths[u]
        v = p[i+1]
        v_d = spaths[v]

        
        if v_d != u_d-1:
            id22 += 1
            id27 += 1
            continue

        
        for w in adj[u]:
            if w != v and spaths[w] == v_d:
                id27 += 1
                break

    print(id22, id27)

main()
