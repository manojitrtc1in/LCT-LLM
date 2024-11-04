
import os as _os
import sys as _sys
from functools import lru_cache as _lru_cache
from importlib.abc import ExecutionLoader, MetaPathFinder
from importlib.machinery import ModuleSpec


class InlineImporter(ExecutionLoader, MetaPathFinder):

    version = None
    inlined_modules = {}
    namespace_packages = False

    @classmethod
    def find_spec(cls, fullname, path=None, target=None):
        """Find a spec for a given module.
        
        Because we only deal with our inlined module, we don't have to care about path or target.
        The import machinery also takes care of fully resolving all names, so we just have to deal with the fullnames.
        """
        if fullname in cls.inlined_modules:
            
            ms = ModuleSpec(fullname, cls, origin=cls.get_filename(fullname), is_package=cls.is_package(fullname))
            ms.has_location = True
            if cls.namespace_packages and ms.submodule_search_locations is not None:
                for p in _sys.path:
                    ms.submodule_search_locations.append(_os.path.join(p, _os.path.dirname(ms.origin)))
            return ms

        return None

    @staticmethod
    def _call_with_frames_removed(f, *args, **kwds):
        """remove_importlib_frames in import.c will always remove sequences
        of importlib frames that end with a call to this function

        Use it instead of a normal call in places where including the importlib
        frames introduces unwanted noise into the traceback (e.g. when executing
        module code)
        """
        return f(*args, **kwds)

    @classmethod
    def create_module(cls, spec):
        """Create a module using the default machinery."""
        return None

    @classmethod
    def exec_module(cls, module):
        """Execute the module."""
        code = cls.get_code(module.__name__)
        if code is None:
            raise ImportError("cannot load module {!r} when get_code() returns None".format(module.__name__))
        cls._call_with_frames_removed(exec, code, module.__dict__)

    @classmethod
    @_lru_cache(maxsize=None)
    def get_filename(cls, fullname):
        """Returns the 

        Raises ImportError if the module cannot be found.
        """
        if fullname not in cls.inlined_modules:
            raise ImportError

        mod = cls.inlined_modules[fullname]
        origin = fullname
        if mod[0]:
            origin = ".".join([origin, "__init__"])
        origin = ".".join([origin.replace(".", "/"), "py"])

        return origin

    @classmethod
    @_lru_cache(maxsize=None)
    def is_package(cls, fullname):
        if fullname not in cls.inlined_modules:
            raise ImportError

        return cls.inlined_modules[fullname][0]

    @classmethod
    def get_source(cls, fullname):
        if fullname not in cls.inlined_modules:
            raise ImportError

        return cls.inlined_modules[fullname][1]

    @classmethod
    def get_code(cls, fullname):
        """Method to return the code object for fullname.

        Should return None if not applicable (e.g. built-in module).
        Raise ImportError if the module cannot be found.
        """
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
InlineImporter.inlined_modules = {
    'lib.data_structure': (False, 'class DisjointSet:\n    def __init__(self, size):\n        self.parent = list(range(size))\n        self.rank = [0] * size\n\n    def find(self, x):\n        stack = []\n        parent = self.parent\n        while parent[x] != x:\n            stack.append(x)\n            x = parent[x]\n        for y in stack:\n            parent[y] = x\n        return x\n\n    def union(self, x, y):\n        xr, yr = self.find(x), self.find(y)\n\n        if self.rank[xr] > self.rank[yr]:\n            self.parent[yr] = xr\n        elif self.rank[xr] < self.rank[yr]:\n            self.parent[xr] = yr\n        elif xr != yr:\n            self.parent[yr] = xr\n            self.rank[xr] += 1\n\n\nclass SegmentTree:\n    """\n    ???????????????????????????????????\n    ???????????????????????????(???????????)\n    """\n\n    @classmethod\n    def all_identity(cls, operator, identity, size):\n        return cls(operator, identity, [identity] * (2 << (size - 1).bit_length()))\n\n    @classmethod\n    def from_initial_data(cls, operator, identity, data):\n        size = 1 << (len(data) - 1).bit_length()\n        temp = [identity] * (2 * size)\n        temp[size:size + len(data)] = data\n        data = temp\n\n        for i in reversed(range(size)):\n            data[i] = operator(data[2 * i], data[2 * i + 1])\n        return cls(operator, identity, data)\n\n    
    'lib.misc': (False, 'from typing import List, Any, Callable, Sequence, Union, Tuple, TypeVar\n\nV = TypeVar(\'V\')\n\nimport sys\nfrom functools import reduce\nfrom itertools import accumulate\nfrom lib.data_structure import BinaryIndexedTree, DisjointSet\nimport bisect\n\n\ndef general_bisect(ng: int, ok: int, judge: Callable[[int], V]) -> int:\n    """\n    ???????????????????O(log L)??????\n\n    :param ng: judge(ng)==False????\n    :param ok: judge(ok)==True????\n    :param judge: ??????????\n    :return: judge(x)==True???????????\n    """\n    while abs(ng - ok) > 1:\n        m = (ng + ok) // 2\n        if judge(m):\n            ok = m\n        else:\n            ng = m\n    return ok\n\n\ndef fibonacci_search(left: int, right: int, func: Union[Callable[[int], V], Sequence], inf: V = 2 ** 60) -> Tuple[\n    V, int]:\n    """\n    ??????????????????????????????O(log L)??????\n    ???(left, right)?????????\n\n    :param left: ?????????????\n    :param right: ?????????????\n    :param func: ??????\n    :param inf: func???\n    :return: (func????, ????????func???)\n    """\n    try:\n        func = func.__getitem__\n    except AttributeError:\n        pass\n    f1, f2 = 1, 1\n    while f1 + f2 < right - left:\n        f1, f2 = f1 + f2, f1\n    l = left\n    m1 = func(l + f2)\n    m2 = func(l + f1)\n    while f1 > 2:\n        f1, f2 = f2, f1 - f2\n        if m1 > m2:\n            l += f1\n            m1 = m2\n            m2 = func(l + f1) if l + f1 < right else inf\n        else:\n            m2 = m1\n            m1 = func(l + f2)\n    if m1 < m2:\n        return m1, l + 1\n    else:\n        return m2, l + 2\n\n\ndef max2(x: V, y: V) -> V:\n    return x if x > y else y\n\n\ndef min2(x: V, y: V) -> V:\n    return x if x < y else y\n\n\nread = sys.stdin.buffer.read\nreadline = sys.stdin.buffer.readline\n\n\ndef rerooting(rooted_tree, merge, identity, finalize):\n    """\n    merge: (T,T) -> T, (T, merge)?????\n    identity: ???\n    finalize: (T, V, V) -> T\n\n    ????????dp?????\n    dp[u,v] = finalize(merge(dp[v,k] for k in adj[v] if k != u), u, v)\n    ???(u,v)?? u->v\n    """\n    N = rooted_tree.n_vertices\n    parent = rooted_tree.parent\n    children = rooted_tree.children\n    order = rooted_tree.dfs_order\n\n    
    'lib': (True, ''),
}
_sys.meta_path.insert(2, InlineImporter)


from lib.misc import general_bisect
from functools import lru_cache

def ask(c):
    print(f'+ {c}', flush=True)
    return int(input())

def answer(x):
    print(f'! {x}', flush=True)

n = int(input())
offset = 0
prev = 0

@lru_cache(None)
def check(t):
    """
    answer < t ?
    """
    global offset, prev
    k = (-(offset+t))%n
    r = ask(k)
    offset += k
    if r > prev:
        prev = r
        return False
    return True


res = general_bisect(1, n, check)
answer(res-1+offset)
