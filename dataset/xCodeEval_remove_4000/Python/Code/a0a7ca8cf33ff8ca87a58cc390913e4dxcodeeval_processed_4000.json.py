
import os as _os
import sys as _sys
from functools import lru_cache as _lru_cache
from importlib.abc import ExecutionLoader, MetaPathFinder
from importlib.machinery import ModuleSpec


class InlineImporter(ExecutionLoader, MetaPathFinder):

    version = None
    id0 = {}
    namespace_packages = False

    @classmethod
    def find_spec(cls, fullname, path=None, target=None):
        
        if fullname in cls.id0:
            
            ms = ModuleSpec(fullname, cls, origin=cls.get_filename(fullname), is_package=cls.is_package(fullname))
            ms.has_location = True
            if cls.namespace_packages and ms.submodule_search_locations is not None:
                for p in _sys.path:
                    ms.submodule_search_locations.append(_os.path.join(p, _os.path.dirname(ms.origin)))
            return ms

        return None

    @staticmethod
    def id1(f, *args, **kwds):
        
        return f(*args, **kwds)

    @classmethod
    def create_module(cls, spec):
        
        return None

    @classmethod
    def exec_module(cls, module):
        
        code = cls.get_code(module.__name__)
        if code is None:
            raise ImportError("cannot load module {!r} when get_code() returns None".format(module.__name__))
        cls.id1(exec, code, module.__dict__)

    @classmethod
    @_lru_cache(maxsize=None)
    def get_filename(cls, fullname):
        
        if fullname not in cls.id0:
            raise ImportError

        mod = cls.id0[fullname]
        origin = fullname
        if mod[0]:
            origin = ".".join([origin, "__init__"])
        origin = ".".join([origin.replace(".", "/"), "py"])

        return origin

    @classmethod
    @_lru_cache(maxsize=None)
    def is_package(cls, fullname):
        if fullname not in cls.id0:
            raise ImportError

        return cls.id0[fullname][0]

    @classmethod
    def get_source(cls, fullname):
        if fullname not in cls.id0:
            raise ImportError

        return cls.id0[fullname][1]

    @classmethod
    def get_code(cls, fullname):
        
        source = cls.get_source(fullname)
        if source is None:
            return None
        try:
            path = cls.get_filename(fullname)
        except ImportError:
            return cls.source_to_code(source)
        else:
            return cls.source_to_code(source, path)


InlineImporter.version = '0.0.4'
InlineImporter.id0 = {
    'lib.array2d': (False, "class Array2dView:\n    def __init__(self, arr, i_indices, j_indices):\n        self.arr = arr\n        self.i_indices = i_indices\n        self.j_indices = j_indices\n    \n    def _get_view(self, i, j):\n        i = self.i_indices[i]\n        j = self.j_indices[j]\n        return Array2dView(self.arr, i, j)\n\n    def get_ind(self, i, j):\n        return self.i_indices[i]+self.j_indices[j]\n    \n    def __getitem__(self, index):\n        i, j = index\n        try:\n            return self.arr[self.get_ind(i,j)]\n        except TypeError:\n            return self._get_view(i, j)\n    \n    def __setitem__(self, index, value):\n        i, j = index\n        try:\n            self.arr[self.get_ind(i,j)] = value\n        except TypeError:\n            x = self._get_view(i, j)\n            for i in x.i_indices:\n                for j in x.j_indices:\n                    self.arr[i+j] = value\n    \n    def __iter__(self):\n        for i in self.i_indices:\n            for j in self.j_indices:\n                yield self.arr[i+j]\n    \n    def __reversed__(self):\n        for i in reversed(self.i_indices):\n            for j in reversed(self.j_indices):\n                yield self.arr[i+j]\n    \n    def __str__(self):\n        m = max(len(str(v)) for v in self)\n        res = ['']*len(self.i_indices)\n        row = ['']*(len(self.j_indices)+2)\n        for ri,i in enumerate(self.i_indices):\n            if ri == 0:\n                row[0] = '['\n            else:\n                row[0] = ' '\n            if ri == len(self.i_indices)-1:\n                row[-1] = ']\\n'\n            for rj,j in enumerate(self.j_indices):\n                row[rj+1] = f'{str(self.arr[i+j]):>{m+1}}'\n            res[ri] = ''.join(row)\n        return '\\n'.join(res)\n    \n    def copy(self):\n        return Array2d(len(self.i_indices), len(self.j_indices), list(self))\n\n\nclass Array2d:\n    def __init__(self, n, m, arr):\n        self.n = n\n        self.m = m\n        self.arr = arr\n    \n    @classmethod\n    def full(cls, n, m, fill_value):\n        return cls(n, m, [fill_value]*(n*m))\n    \n    @classmethod\n    def from_list(cls, lst):\n        n,m = len(lst), len(lst[0])\n        arr = [lst[0]]*(n*m)\n        k = 0\n        for row in lst:\n            for v in row:\n                arr[k] = v\n                k += 1\n        return cls(n, m, arr)\n    \n    def _get_view(self, i, j):\n        i = tuple(range(0, self.n*self.m, self.m))[i]\n        j = tuple(range(self.m))[j]\n        return Array2dView(self.arr, i, j)\n\n    def get_ind(self, i, j):\n        return i*self.m+j\n\n    def __getitem__(self, index):\n        try:\n            return self.arr[self.get_ind(*index)]\n        except TypeError:\n            return self._get_view(*index)\n    \n    def __setitem__(self, index, value):\n        try:\n            self.arr[self.get_ind(*index)] = value\n        except TypeError:\n            x = self._get_view(*index)\n            for i in x.i_indices:\n                for j in x.j_indices:\n                    self.arr[i+j] = value\n    \n    def __iter__(self):\n        return iter(self.arr)\n    \n    def __reversed__(self):\n        return reversed(self.arr)\n    \n    def __str__(self):\n        m = max(len(str(v)) for v in self)\n        res = ['']*self.n\n        row = ['']*(self.m+2)\n        for i in range(self.n):\n            if i == 0:\n                row[0] = '['\n            else:\n                row[0] = ' '\n            if i == self.n-1:\n                row[-1] = ']\\n'\n            for j in range(self.m):\n                row[j+1] = f'{str(self.arr[i*self.m+j]):>{m+1}}'\n            res[i] = ''.join(row)\n        return '\\n'.join(res)\n\n    def __eq__(self, other):\n        return self.arr == other.arr\n\n    def copy(self):\n        return self.__class__(self.n, self.m, self.arr[:])\n\n    @property\n    def t(self):\n        arr = [self.arr[0]]*(len(self.arr))\n        x = 0\n        for i in range(self.n):\n            for j in range(self.m):\n                arr[j*self.n + i] = self.arr[x]\n                x += 1\n        return self.__class__(self.m, self.n, arr)\n"),
    'lib.misc': (False, 'from typing import List, Any, Callable, Sequence, Union, Tuple, TypeVar\n\nV = TypeVar(\'V\')\n\nimport sys\nfrom functools import reduce\nfrom itertools import accumulate\nfrom lib.data_structure import BinaryIndexedTree, DisjointSet\nimport bisect\n\n\ndef general_bisect(ng: int, ok: int, judge: Callable[[int], V]) -> int:\n    \n    while abs(ng - ok) > 1:\n        m = (ng + ok) // 2\n        if judge(m):\n            ok = m\n        else:\n            ng = m\n    return ok\n\n\ndef fibonacci_search(left: int, right: int, func: Union[Callable[[int], V], Sequence], inf: V = 2 ** 60) -> Tuple[\n    V, int]:\n    \n    try:\n        func = func.__getitem__\n    except AttributeError:\n        pass\n    f1, f2 = 1, 1\n    while f1 + f2 < right - left:\n        f1, f2 = f1 + f2, f1\n    l = left\n    m1 = func(l + f2)\n    m2 = func(l + f1)\n    while f1 > 2:\n        f1, f2 = f2, f1 - f2\n        if m1 > m2:\n            l += f1\n            m1 = m2\n            m2 = func(l + f1) if l + f1 < right else inf\n        else:\n            m2 = m1\n            m1 = func(l + f2)\n    if m1 < m2:\n        return m1, l + 1\n    else:\n        return m2, l + 2\n\n\ndef max2(x: V, y: V) -> V:\n    return x if x > y else y\n\n\ndef min2(x: V, y: V) -> V:\n    return x if x < y else y\n\n\nread = sys.stdin.buffer.read\nreadline = sys.stdin.buffer.readline\n\n\ndef rerooting(rooted_tree, merge, identity, finalize):\n    \n    N = rooted_tree.n_vertices\n    parent = rooted_tree.parent\n    children = rooted_tree.children\n    order = rooted_tree.dfs_order\n\n    
    'lib': (True, ''),
}
_sys.meta_path.insert(2, InlineImporter)


from lib.array2d import Array2d

def helper(n, m, queries):
    grid = Array2d.full(n, m, 0)
    cnt = 0
    for s in range(1, min(n,m)+1):
        cnt += (n-s)*(m-s)*2 + (n-s)*(m-s+1) + (n-s+1)*(m-s)
    cnt += n*m
    res = [cnt]
    for i,j in queries:
        ul = 0
        x,y = i,j-1
        f = True
        while x >= 0 and y >= 0 and not grid[x,y]:
            ul += 1
            if f:
                x -= 1
            else:
                y -= 1
            f = not f
        rd = 0
        x,y = i+1,j
        f = True
        while x < n and y < m and not grid[x,y]:
            rd += 1
            if f:
                y += 1
            else:
                x += 1
            f = not f

        lu = 0
        x,y = i-1,j
        f = False
        while x >= 0 and y >= 0 and not grid[x,y]:
            lu += 1
            if f:
                x -= 1
            else:
                y -= 1
            f = not f
        dr = 0
        x,y = i,j+1
        f = False
        while x < n and y < m and not grid[x,y]:
            dr += 1
            if f:
                y += 1
            else:
                x += 1
            f = not f

        k = (ul+1)*(rd+1) + (lu+1)*(dr+1) - 1
        r = res[-1]
        if not grid[i,j]:
            res.append(r-k)
            grid[i,j] = 1
        else:
            res.append(r+k)
            grid[i,j] = 0
    return res[1:]



n, m, q = map(int, input().split())
queries = [tuple(int(c)-1 for c in input().split()) for _ in range(q)]
print(*helper(n,m,queries), sep='\n')