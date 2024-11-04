
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
    'lib.data_structure': (False, 'from itertools import repeat\n\n\nclass DisjointSet:\n    def __init__(self, parent):\n        self.parent = parent\n\n    @classmethod\n    def empty(cls, size):\n        return cls([-1]*size)\n\n    def find(self, x):\n        stack = []\n        while self.parent[x] >= 0:\n            stack.append(x)\n            x = self.parent[x]\n        for y in stack:\n            self.parent[y] = x\n        return x\n\n    def union_reps(self, xr, yr):\n        self.parent[yr] = xr\n\n    def union(self, x, y):\n        self.union_reps(self.find(x), self.find(y))\n\n\nclass SegmentTree:\n    \n\n    @classmethod\n    def all_identity(cls, operator, identity, size):\n        return cls(operator, identity, [identity] * (2 << (size - 1).bit_length()))\n\n    @classmethod\n    def from_initial_data(cls, operator, identity, data):\n        size = 1 << (len(data) - 1).bit_length()\n        temp = [identity] * (2 * size)\n        temp[size:size + len(data)] = data\n        data = temp\n\n        for i in reversed(range(size)):\n            data[i] = operator(data[2 * i], data[2 * i + 1])\n        return cls(operator, identity, data)\n\n    
    'lib.misc': (False, 'from typing import List, Any, Callable, Sequence, Union, Tuple, TypeVar\n\nV = TypeVar(\'V\')\n\nimport sys\nfrom functools import reduce\nfrom itertools import accumulate\nfrom lib.data_structure import BinaryIndexedTree, DisjointSet\nimport bisect\n\n\ndef general_bisect(ng: int, ok: int, judge: Callable[[int], V]) -> int:\n    \n    while abs(ng - ok) > 1:\n        m = (ng + ok) // 2\n        if judge(m):\n            ok = m\n        else:\n            ng = m\n    return ok\n\n\ndef fibonacci_search(left: int, right: int, func: Union[Callable[[int], V], Sequence], inf: V = 2 ** 60) -> Tuple[\n    V, int]:\n    \n    try:\n        func = func.__getitem__\n    except AttributeError:\n        pass\n    f1, f2 = 1, 1\n    while f1 + f2 < right - left:\n        f1, f2 = f1 + f2, f1\n    l = left\n    m1 = func(l + f2)\n    m2 = func(l + f1)\n    while f1 > 2:\n        f1, f2 = f2, f1 - f2\n        if m1 > m2:\n            l += f1\n            m1 = m2\n            m2 = func(l + f1) if l + f1 < right else inf\n        else:\n            m2 = m1\n            m1 = func(l + f2)\n    if m1 < m2:\n        return m1, l + 1\n    else:\n        return m2, l + 2\n\n\ndef max2(x: V, y: V) -> V:\n    return x if x > y else y\n\n\ndef min2(x: V, y: V) -> V:\n    return x if x < y else y\n\n\nread = sys.stdin.buffer.read\nreadline = sys.stdin.buffer.readline\n\n\ndef rerooting(rooted_tree, merge, identity, finalize):\n    \n    N = rooted_tree.n_vertices\n    parent = rooted_tree.parent\n    children = rooted_tree.children\n    order = rooted_tree.dfs_order\n\n    
    'lib': (True, ''),
}
_sys.meta_path.insert(2, InlineImporter)


from lib.data_structure import DisjointSet
from lib.misc import read


def solve(n, edges):
    def helper(mask):
        ds = DisjointSet.empty(n)
        cnt = 1
        for x, y, w in edges:
            x, y = ds.find(x), ds.find(y)
            if x != y and w | mask == mask:
                ds.union_reps(x, y)
                cnt += 1
                if cnt >= n:
                    return True
        return False

    dd = max(w for _,_,w in edges).bit_length()
    res = (1 << dd) - 1
    for d in reversed(range(dd)):
        if helper(res ^ (1 << d)):
            res ^= 1 << d
    return res


mm = map(int, read().split())

t = next(mm)
for _ in range(t):
    n, m = next(mm), next(mm)
    edges = [(a - 1, b - 1, c) for i, a, b, c in zip(range(m), mm, mm, mm)]
    print(solve(n, edges))
