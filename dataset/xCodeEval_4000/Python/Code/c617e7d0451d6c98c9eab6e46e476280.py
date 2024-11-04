
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
    'lib.data_structure': (False, 'from itertools import repeat\n\n\nclass DisjointSet:\n    def __init__(self, parent):\n        self.parent = parent\n\n    @classmethod\n    def empty(cls, size):\n        return cls([-1]*size)\n\n    def find(self, x):\n        stack = []\n        while self.parent[x] >= 0:\n            stack.append(x)\n            x = self.parent[x]\n        for y in stack:\n            self.parent[y] = x\n        return x\n\n    def union_reps(self, xr, yr):\n        if xr == yr:\n            return xr\n        if self.parent[xr] > self.parent[yr]:\n            xr, yr = yr, xr\n        self.parent[xr] += self.parent[yr]\n        self.parent[yr] = xr\n        return xr\n\n    def union(self, x, y):\n        return self.union_reps(self.find(x), self.find(y))\n\n    def group_size(self, x):\n        return -self.parent[self.find(x)]\n\n    def is_rep(self, x):\n        return self.parent[x] < 0\n\n\nclass SegmentTree:\n    """\n    ???????????????????????????????????\n    ???????????????????????????(???????????)\n    """\n\n    @classmethod\n    def all_identity(cls, operator, identity, size):\n        return cls(operator, identity, [identity] * (2 << (size - 1).bit_length()))\n\n    @classmethod\n    def from_initial_data(cls, operator, identity, data):\n        size = 1 << (len(data) - 1).bit_length()\n        temp = [identity] * (2 * size)\n        temp[size:size + len(data)] = data\n        data = temp\n\n        for i in reversed(range(size)):\n            data[i] = operator(data[2 * i], data[2 * i + 1])\n        return cls(operator, identity, data)\n\n    
    'lib': (True, ''),
}
_sys.meta_path.insert(2, InlineImporter)


from lib.data_structure import DisjointSet
from itertools import chain, accumulate

n,m,q = map(int, input().split())
a = sorted(map(int,input().split()))
b = list(map(int,input().split()))

queries = list(map(int,input().split()))
res = [0]*q
queries = sorted((k,i) for i,k in enumerate(queries))

i2v = sorted(a+b)
acc = [0]+list(accumulate(i2v))
ds = DisjointSet.empty(n+m)

cnt = [0]*(n+m)
total = [0]*(n+m)
top = list(range(n+m))
j = 0
for i,v in enumerate(i2v):
    if a[j] == v:
        cnt[i] = 1
        total[i] = v
        j += 1
        if j >= len(a):
            break

events = sorted(chain(((i2v[i+1]-i2v[i], ~i) for i in range(n+m-1)), queries))
gross = sum(total)
for _, k in events:
    if k < 0:
        k = ~k
        x = ds.find(k)
        y = ds.find(k+1)
        c = cnt[x] + cnt[y]
        gross -= total[x] + total[y]
        cnt[x] = 0
        total[x] = 0
        cnt[y] = 0
        total[y] = 0
        r = ds.union_reps(x, y)
        t = top[r] = top[y]
        cnt[r] = c
        total[r] = acc[t+1]-acc[t+1-c]
        gross += total[r]
    else:
        res[k] = gross

print(*res, sep='\n')