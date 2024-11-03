
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
    'lib.array2d': (False, "class Array2dView:\n    def __init__(self, arr, i_indices, j_indices):\n        self.arr = arr\n        self.i_indices = i_indices\n        self.j_indices = j_indices\n    \n    def _get_view(self, i, j):\n        i = self.i_indices[i]\n        j = self.j_indices[j]\n        return Array2dView(self.arr, i, j)\n\n    def get_ind(self, i, j):\n        return self.i_indices[i]+self.j_indices[j]\n    \n    def __getitem__(self, index):\n        i, j = index\n        try:\n            return self.arr[self.get_ind(i,j)]\n        except TypeError:\n            return self._get_view(i, j)\n    \n    def __setitem__(self, index, value):\n        i, j = index\n        try:\n            self.arr[self.get_ind(i,j)] = value\n        except TypeError:\n            x = self._get_view(i, j)\n            for i in x.i_indices:\n                for j in x.j_indices:\n                    self.arr[i+j] = value\n    \n    def __iter__(self):\n        for i in self.i_indices:\n            for j in self.j_indices:\n                yield self.arr[i+j]\n    \n    def __reversed__(self):\n        for i in reversed(self.i_indices):\n            for j in reversed(self.j_indices):\n                yield self.arr[i+j]\n    \n    def __str__(self):\n        m = max(len(str(v)) for v in self)\n        res = ['']*len(self.i_indices)\n        row = ['']*(len(self.j_indices)+2)\n        for ri,i in enumerate(self.i_indices):\n            if ri == 0:\n                row[0] = '['\n            else:\n                row[0] = ' '\n            if ri == len(self.i_indices)-1:\n                row[-1] = ']\\n'\n            for rj,j in enumerate(self.j_indices):\n                row[rj+1] = f'{str(self.arr[i+j]):>{m+1}}'\n            res[ri] = ''.join(row)\n        return '\\n'.join(res)\n    \n    def copy(self):\n        return Array2d(len(self.i_indices), len(self.j_indices), list(self))\n\n\nclass Array2d:\n    def __init__(self, n, m, arr):\n        self.n = n\n        self.m = m\n        self.arr = arr\n    \n    @classmethod\n    def full(cls, n, m, fill_value):\n        return cls(n, m, [fill_value]*(n*m))\n    \n    @classmethod\n    def from_list(cls, lst):\n        n,m = len(lst), len(lst[0])\n        arr = [lst[0]]*(n*m)\n        k = 0\n        for row in lst:\n            for v in row:\n                arr[k] = v\n                k += 1\n        return cls(n, m, arr)\n    \n    def _get_view(self, i, j):\n        i = tuple(range(0, self.n*self.m, self.m))[i]\n        j = tuple(range(self.m))[j]\n        return Array2dView(self.arr, i, j)\n\n    def get_ind(self, i, j):\n        return i*self.m+j\n\n    def __getitem__(self, index):\n        try:\n            return self.arr[self.get_ind(*index)]\n        except TypeError:\n            return self._get_view(*index)\n    \n    def __setitem__(self, index, value):\n        try:\n            self.arr[self.get_ind(*index)] = value\n        except TypeError:\n            x = self._get_view(*index)\n            for i in x.i_indices:\n                for j in x.j_indices:\n                    self.arr[i+j] = value\n    \n    def __iter__(self):\n        return iter(self.arr)\n    \n    def __reversed__(self):\n        return reversed(self.arr)\n    \n    def __str__(self):\n        m = max(len(str(v)) for v in self)\n        res = ['']*self.n\n        row = ['']*(self.m+2)\n        for i in range(self.n):\n            if i == 0:\n                row[0] = '['\n            else:\n                row[0] = ' '\n            if i == self.n-1:\n                row[-1] = ']\\n'\n            for j in range(self.m):\n                row[j+1] = f'{str(self.arr[i*self.m+j]):>{m+1}}'\n            res[i] = ''.join(row)\n        return '\\n'.join(res)\n\n    def __eq__(self, other):\n        return self.arr == other.arr\n\n    def copy(self):\n        return self.__class__(self.n, self.m, self.arr[:])\n\n    @property\n    def t(self):\n        arr = [self.arr[0]]*(len(self.arr))\n        x = 0\n        for i in range(self.n):\n            for j in range(self.m):\n                arr[j*self.n + i] = self.arr[x]\n                x += 1\n        return self.__class__(self.m, self.n, arr)\n"),
    'lib.data_structure': (False, 'from itertools import repeat\n\n\nclass DisjointSet:\n    def __init__(self, parent):\n        self.parent = parent\n\n    @classmethod\n    def empty(cls, size):\n        return cls([-1]*size)\n\n    def find(self, x):\n        stack = []\n        while self.parent[x] >= 0:\n            stack.append(x)\n            x = self.parent[x]\n        for y in stack:\n            self.parent[y] = x\n        return x\n\n    def union_reps(self, xr, yr):\n        if xr == yr:\n            return xr\n        if self.parent[xr] > self.parent[yr]:\n            xr, yr = yr, xr\n        self.parent[xr] += self.parent[yr]\n        self.parent[yr] = xr\n        return xr\n\n    def union(self, x, y):\n        return self.union_reps(self.find(x), self.find(y))\n\n    def group_size(self, x):\n        return -self.parent[self.find(x)]\n\n    def is_rep(self, x):\n        return self.parent[x] < 0\n\n\nclass SegmentTree:\n    """\n    ???????????????????????????????????\n    ???????????????????????????(???????????)\n    """\n\n    @classmethod\n    def all_identity(cls, operator, identity, size):\n        return cls(operator, identity, [identity] * (2 << (size - 1).bit_length()))\n\n    @classmethod\n    def from_initial_data(cls, operator, identity, data):\n        size = 1 << (len(data) - 1).bit_length()\n        temp = [identity] * (2 * size)\n        temp[size:size + len(data)] = data\n        data = temp\n\n        for i in reversed(range(size)):\n            data[i] = operator(data[2 * i], data[2 * i + 1])\n        return cls(operator, identity, data)\n\n    
    'lib.graph': (False, 'import itertools\nimport heapq as hq\nfrom random import randrange, shuffle\nfrom lib.misc import min2\nfrom lib.array2d import Array2d\nfrom collections import defaultdict\n\nfrom typing import Union, Iterable, Any, Tuple, List, Sequence, TypeVar, Optional, Callable\n\nT = TypeVar(\'T\')\n\nINF = 2 ** 62\n\n\nclass BaseWeightedGraph:\n\n    def __init__(self, n_vertices: int):\n        self.n_vertices = n_vertices\n\n    def wadj(self, v: int) -> Iterable[Tuple[int, Any]]:\n        """\n        Return an iterable of vertices adjacent to v and edge weight\n        """\n        raise NotImplementedError\n\n    def adj(self, v: int) -> Iterable[int]:\n        """\n        Return an iterable of vertices adjacent to v\n        """\n        return (u for u, w in self.wadj(v))\n\n    @property\n    def wedges(self) -> Iterable[Tuple[int, int, Any]]:\n        """\n        Return an iterable of weighted edges (vertex_1, vertex_2, weight)\n        """\n        return ((v, u, w) for v in range(self.n_vertices) for u, w in self.wadj(v))\n\n    @property\n    def edges(self):\n        return ((v, u) for v in range(self.n_vertices) for u in self.adj(v))\n\n    def dist(self, s: int, t: int, inf=INF):\n        return dijkstra(self, s, t, inf)[1]\n\n    def warshall_floyd(self, inf=INF):\n        dist = Array2d.full(self.n_vertices, self.n_vertices, inf)\n        for u, v, w in self.wedges:\n            dist[u, v] = w\n        for i in range(self.n_vertices):\n            dist[i, i] = 0\n        for k in range(self.n_vertices):\n            for i in range(self.n_vertices):\n                for j in range(self.n_vertices):\n                    dist[i, j] = min2(dist[i, j], dist[i, k] + dist[k, j])\n        return dist\n\n\nclass WeightedGraph(BaseWeightedGraph):\n\n    def __init__(self, n_vertices: int, adj: List[int], weight: List[Any], ind: List[int]):\n        super().__init__(n_vertices)\n        self._adj = adj\n        self._weight = weight\n        self._ind = ind\n\n    @classmethod\n    def from_lil_adj(cls, n_vertices: int, adj_list: Iterable[Sequence[Tuple[int, int]]]) -> \'WeightedGraph\':\n        n_edges = sum(len(l) for l in adj_list)\n        adj = [0] * n_edges\n        weight = [0] * n_edges\n        ind = [0] * (n_vertices + 1)\n        i = 0\n        for u, l in enumerate(adj_list):\n            ind[u] = i\n            for v, w in l:\n                adj[i] = v\n                weight[i] = w\n                i += 1\n        ind[n_vertices] = i\n        return cls(n_vertices, adj, weight, ind)\n\n    @classmethod\n    def from_directed_edges(cls, n_vertices: int, edges: Iterable[Tuple[int, int, int]]) -> \'WeightedGraph\':\n        temp = [[] for _ in range(n_vertices)]\n        for u, v, w in edges:\n            temp[u].append((v, w))\n        return cls.from_lil_adj(n_vertices, temp)\n\n    @classmethod\n    def from_undirected_edges(cls, n_vertices: int, edges: Iterable[Tuple[int, int, int]]) -> \'WeightedGraph\':\n        temp = [[] for _ in range(n_vertices)]\n        for u, v, w in edges:\n            temp[u].append((v, w))\n            temp[v].append((u, w))\n        return cls.from_lil_adj(n_vertices, temp)\n\n    def wadj(self, v):\n        i, j = self._ind[v], self._ind[v + 1]\n        return ((self._adj[k], self._weight[k]) for k in range(i, j))\n\n    def to_wgraph(self) -> \'WeightedGraph\':\n        l = [[] for _ in range(self.n_vertices)]\n        for u, v, w in self.wedges:\n            l[u].append((v, w))\n        return WeightedGraph.from_lil_adj(self.n_vertices, l)\n\n    def to_reverse_wgraph(self) -> \'WeightedGraph\':\n        l = [[] for _ in range(self.n_vertices)]\n        for u, v, w in self.wedges:\n            l[v].append((u, w))\n        return WeightedGraph.from_lil_adj(self.n_vertices, l)\n\n\nclass BaseGraph(BaseWeightedGraph):\n\n    def adj(self, v):\n        raise NotImplementedError\n\n    def wadj(self, v):\n        return ((u, 1) for u in self.adj(v))\n\n    def bfs(self, s: Union[int, Iterable[int]], t: int = -1) -> List[int]:\n        """\n        Returns a list of distance. If starts contains more than one vertex, returns the shortest distance from any of them\n        """\n        dist = [-1] * self.n_vertices\n\n        if isinstance(s, int):\n            q = [s]\n            dist[s] = 0\n        else:\n            q = list(s)\n            for v in q:\n                dist[v] = 0\n        for d in range(1, self.n_vertices):\n            nq = []\n            for v in q:\n                for u in self.adj(v):\n                    if dist[u] < 0:\n                        dist[u] = d\n                        nq.append(u)\n                    if u == t:\n                        return dist\n            q = nq\n        return dist\n\n    def dist(self, s: int, t: int, inf: Any = INF):\n        d = self.bfs(s, t)[t]\n        return inf if d == -1 else d\n\n    def to_graph(self) -> \'Graph\':\n        l = [[] for _ in range(self.n_vertices)]\n        for u, v in self.edges:\n            l[u].append(v)\n        return Graph.from_lil_adj(self.n_vertices, l)\n\n    def to_reverse_graph(self) -> \'Graph\':\n        l = [[] for _ in range(self.n_vertices)]\n        for u, v in self.edges:\n            l[v].append(u)\n        return Graph.from_lil_adj(self.n_vertices, l)\n\n\nclass Graph(BaseGraph):\n\n    def __init__(self, n_vertices: int, adj: List[int], ind: List[int]):\n        super().__init__(n_vertices)\n        self._adj = adj\n        self._ind = ind\n\n    @classmethod\n    def from_lil_adj(cls, n_vertices: int, adj_list: Iterable[Sequence[int]]) -> \'Graph\':\n        n_edges = sum(len(l) for l in adj_list)\n        adj = [0] * n_edges\n        ind = [0] * (n_vertices + 1)\n        i = 0\n        for u, l in enumerate(adj_list):\n            ind[u] = i\n            for v in l:\n                adj[i] = v\n                i += 1\n        ind[n_vertices] = i\n        return cls(n_vertices, adj, ind)\n\n    @classmethod\n    def from_directed_edges(cls, n_vertices: int, edges: Iterable[Tuple[int, int]]) -> \'Graph\':\n        temp = [[] for _ in range(n_vertices)]\n        for u, v in edges:\n            temp[u].append(v)\n        return cls.from_lil_adj(n_vertices, temp)\n\n    @classmethod\n    def from_undirected_edges(cls, n_vertices: int, edges: Iterable[Tuple[int, int]]) -> \'Graph\':\n        temp = [[] for _ in range(n_vertices)]\n        for u, v in edges:\n            temp[u].append(v)\n            temp[v].append(u)\n        return cls.from_lil_adj(n_vertices, temp)\n\n    def adj(self, v):\n        return self._adj[self._ind[v]: self._ind[v + 1]]\n\n\nclass BaseRootedTree(BaseGraph):\n\n    def __init__(self, n_vertices, root_vertex=0):\n        super().__init__(n_vertices)\n        self.root = root_vertex\n\n    def parent(self, v: int) -> int:\n        raise NotImplementedError\n\n    def children(self, v: int) -> Iterable[int]:\n        raise NotImplementedError\n\n    def adj(self, v) -> Iterable[int]:\n        if self.root == v:\n            return self.children(v)\n        return itertools.chain(self.children(v), (self.parent(v),))\n\n    def post_order(self) -> Iterable[int]:\n        """\n        bottom vertices first\n        """\n        return (~v for v in self.prepost_order() if v < 0)\n\n    def pre_order(self) -> Iterable[int]:\n        """\n        top vertices first\n        """\n        stack = [self.root]\n        while stack:\n            v = stack.pop()\n            yield v\n            for u in self.children(v):\n                stack.append(u)\n\n    def prepost_order(self) -> Iterable[int]:\n        """\n        if v >= 0: it\'s pre-order entry.\n\n        otherwise: it\'s post-order entry.\n        """\n        stack = [~self.root, self.root]\n        while stack:\n            v = stack.pop()\n            yield v\n            if v >= 0:\n                for u in self.children(v):\n                    stack.append(~u)\n                    stack.append(u)\n\n    def prepost_indices(self) -> Tuple[List[int], List[int]]:\n        pre_ind = [0] * self.n_vertices\n        post_ind = [0] * self.n_vertices\n        for i, t in enumerate(self.prepost_order()):\n            if t >= 0:\n                pre_ind[t] = i\n            else:\n                post_ind[~t] = i\n        return pre_ind, post_ind\n\n    def depth(self) -> List[int]:\n        depth = [0] * self.n_vertices\n        for v in self.pre_order():\n            d = depth[v]\n            for c in self.children(v):\n                depth[c] = d + 1\n        return depth\n\n    def sort_edge_values(self, wedges: Iterable[Tuple[int, int, T]], default: Optional[T] = None) -> List[T]:\n        memo = [default] * self.n_vertices\n        for u, v, d in wedges:\n            if self.parent(u) == v:\n                memo[u] = d\n            else:\n                memo[v] = d\n        return memo\n\n    def height(self, depth=None) -> int:\n        if depth is None:\n            depth = self.depth()\n        return max(depth) + 1\n\n    def path(self, v: int, k: int) -> List[int]:\n        """\n        ??v??k???????????.\n\n        :param v: ??\n        :param k: ??????????\n        :return: ??\n        """\n        res = [-1] * (k + 1)\n        for i in range(k + 1):\n            res[i] = v\n            v = self.parent(v)\n            if v < 0:\n                break\n        return res\n\n    def aggregate_parent_path(self, aggregate: Callable[[T, int], T], identity: T,\n                              pre_order: Optional[Iterable[int]] = None) -> List[T]:\n        """\n        ????????????dp??????.\n\n        :param aggregate: (T, V) -> T\n        :param identity: ???\n        :param pre_order: pre_order????\n        :return ?????????????dp?\n        """\n        if pre_order is None:\n            pre_order = self.pre_order()\n\n        dp = [identity] * self.n_vertices\n        for v in pre_order:\n            p = self.parent(v)\n            if p >= 0:\n                dp[v] = aggregate(dp[p], v)\n        return dp\n\n    def aggregate_subtree(self, merge: Callable[[T, T], T], identity: T, finalize: Callable[[T, int], T],\n                          post_order: Optional[Iterable[int]] = None) -> List[T]:\n        """\n        ???????????????dp??????.\n\n        :param merge: (T, T) -> T, (T, merge)?????\n        :param identity: ???\n        :param finalize: (T, V) -> T\n        :param post_order: post_order????\n        :return ???????????????????dp?\n        """\n        if post_order is None:\n            post_order = self.post_order()\n\n        dp = [identity] * self.n_vertices\n        for v in post_order:\n            t = identity\n            for u in self.children(v):\n                t = merge(t, dp[u])\n            dp[v] = finalize(t, v)\n        return dp\n\n    def solve_rerooting(self, merge: Callable[[T, T], T], identity: T, finalize: Callable[[T, int, int], T],\n                        pre_order: Optional[Iterable[int]] = None) -> List[T]:\n        """\n        ????dp???.\n\n        dp[u,v] = finalize(merge(dp[v,k] for k in adj[v] if k != u), u, v)\n\n        (v?????u?????????????????)\n\n        :param merge: (T,T) -> T, (T, merge)?????\n        :param identity: ???\n        :param finalize: (T, V, V) -> T\n        :param pre_order: pre_order????\n        :return ???????????????dp?\n        """\n\n        if pre_order is None:\n            pre_order = list(self.pre_order())\n        dp1 = [identity] * self.n_vertices\n        dp2 = [identity] * self.n_vertices\n\n        for v in reversed(pre_order):\n            t = identity\n            for u in self.children(v):\n                dp2[u] = t\n                t = merge(t, finalize(dp1[u], v, u))\n            t = identity\n            for u in reversed(list(self.children(v))):\n                dp2[u] = merge(t, dp2[u])\n                t = merge(t, finalize(dp1[u], v, u))\n            dp1[v] = t\n        for v in pre_order:\n            if v == self.root:\n                continue\n            p = self.parent(v)\n            dp2[v] = finalize(merge(dp2[v], dp2[p]), v, p)\n            dp1[v] = merge(dp1[v], dp2[v])\n        return dp1\n\n\nclass DoublingStrategy:\n    def __init__(self, tree: BaseRootedTree, depth=None, pre_order=None):\n        if pre_order is None:\n            pre_order = tree.pre_order()\n        if depth is None:\n            depth = tree.depth()\n        self.depth = depth\n        self.tree = tree\n        d = (max(depth) + 1).bit_length()\n        dbl = Array2d.full(tree.n_vertices, d, -1)\n        for v in pre_order:\n            u = tree.parent(v)\n            dbl[v, 0] = u\n            for i in range(d - 1):\n                u = dbl[u, i]\n                if u < 0:\n                    break\n                dbl[v, i + 1] = u\n        self.dbl = dbl\n\n    def ancestor_of(self, v: int, k: int) -> int:\n        if k > self.depth[v]:\n            return -1\n        i = 0\n        while k:\n            if k & 1:\n                v = self.dbl[v, i]\n            k //= 2\n            i += 1\n        return v\n\n    def lca(self, u: int, v: int) -> int:\n        lu, lv = self.depth[u], self.depth[v]\n        if lu > lv:\n            u = self.ancestor_of(u, lu - lv)\n        else:\n            v = self.ancestor_of(v, lv - lu)\n        if u == v:\n            return u\n\n        i = self.dbl.m - 1\n        while True:\n            while i >= 0 and self.dbl[u, i] == self.dbl[v, i]:\n                i -= 1\n            if i < 0:\n                return self.dbl[u, 0]\n            u, v = self.dbl[u, i], self.dbl[v, i]\n\n    def dist(self, u: int, v: int) -> int:\n        return self.depth[u] + self.depth[v] - 2 * self.depth[self.lca(u, v)]\n\n\nclass RootedTree(BaseRootedTree):\n\n    def __init__(self, parent: List[int], children: Graph, root_vertex: int):\n        super().__init__(len(parent), root_vertex)\n        self._parent = parent\n        self._children = children\n\n    @classmethod\n    def from_edges(cls, edges, root_vertex=0):\n        n = len(edges) + 1\n        g = Graph.from_undirected_edges(n, edges)\n        parent = [0] * n\n        parent[root_vertex] = -1\n        stack = [root_vertex]\n        while stack:\n            v = stack.pop()\n            p = parent[v]\n            for u in g.adj(v):\n                if u != p:\n                    parent[u] = v\n                    stack.append(u)\n        return cls.from_parent(parent, root_vertex)\n\n    @classmethod\n    def from_parent(cls, parent, root_vertex=0):\n        return cls(parent,\n                   Graph.from_directed_edges(len(parent), ((p, v) for v, p in enumerate(parent) if p >= 0)),\n                   root_vertex)\n\n    @classmethod\n    def random(cls, n_vertices, root_vertex=0):\n        parent = [-1] * n_vertices\n        vertices = list(range(root_vertex)) + list(range(root_vertex + 1, n_vertices))\n        shuffle(vertices)\n        vertices.append(root_vertex)\n        for i, v in zip(reversed(range(n_vertices)), vertices[-2::-1]):\n            parent[v] = vertices[randrange(i, n_vertices)]\n        return cls.from_parent(parent, root_vertex)\n\n    def parent(self, v):\n        return self._parent[v]\n\n    def children(self, v):\n        return self._children.adj(v)\n\n\nclass Grid(BaseGraph):\n    def __init__(self, grid):\n        super().__init__(grid.n * grid.m)\n        self.grid = grid\n\n    def adj(self, v):\n        if not self.grid.arr[v]:\n            return\n        i, j = divmod(v, self.grid.m)\n        if i + 1 < self.grid.n and self.grid[i + 1, j]:\n            yield v + self.grid.m\n        if 0 <= i - 1 and self.grid[i - 1, j]:\n            yield v - self.grid.m\n        if j + 1 < self.grid.m and self.grid[i, j + 1]:\n            yield v + 1\n        if 0 <= j - 1 and self.grid[i, j - 1]:\n            yield v - 1\n\n\ndef strongly_connected_components(graph: BaseGraph, rgraph: BaseGraph = None):\n    if rgraph is None:\n        rgraph = graph.to_reverse_graph()\n    n = graph.n_vertices\n    order = []\n    color = [0] * n\n    for v0 in range(n):\n        if color[v0]:\n            continue\n        color[v0] = -1\n        stack = [iter(graph.adj(v0))]\n        path = [v0]\n        while path:\n            for u in stack[-1]:\n                if color[u] == 0:\n                    color[u] = -1\n                    path.append(u)\n                    stack.append(iter(graph.adj(u)))\n                    break\n            else:\n                v = path.pop()\n                order.append(v)\n                stack.pop()\n\n    label = 0\n    for v0 in reversed(order):\n        if color[v0] >= 0:\n            continue\n        color[v0] = label\n        stack = [v0]\n        while stack:\n            v = stack.pop()\n            for u in rgraph.adj(v):\n                if color[u] < 0:\n                    color[u] = label\n                    stack.append(u)\n        label += 1\n    return label, color\n\n\ndef dijkstra(graph: BaseWeightedGraph, s: Union[int, Iterable[int]], t: Union[int, Iterable[int]] = -1,\n             inf: Any = 2 ** 62) -> Tuple[List[int], Any]:\n    """\n    Returns a list of distance. If starts contains more than one vertex, returns the shortest distance from any of them.\n    """\n    K = graph.n_vertices.bit_length()\n    MASK = (1 << K) - 1\n    dist = [inf] * graph.n_vertices\n\n    if isinstance(s, int):\n        q = [s]\n        dist[s] = 0\n    else:\n        q = list(s)\n        for v in q:\n            dist[v] = 0\n    if isinstance(t, int):\n        if t < 0:\n            t = []\n        else:\n            t = [t]\n    else:\n        t = set(t)\n\n    while q:\n        x = hq.heappop(q)\n        d, v = x >> K, x & MASK\n        if v in t:\n            return dist, d\n        if d > dist[v]:\n            continue\n        for u, w in graph.wadj(v):\n            if dist[u] > d + w:\n                dist[u] = d + w\n                hq.heappush(q, ((d + w) << K) | u)\n    return dist, None\n\n\ndef dijkstra_general(graph: BaseWeightedGraph, inf: Any, zero: Any, s: Union[int, Iterable[int]],\n                     t: Union[int, Iterable[int]] = -1) -> Tuple[List[Any], Any]:\n    """\n    Returns a list of distance. If starts contains more than one vertex, returns the shortest distance from any of them.\n    """\n    dist = [inf] * graph.n_vertices\n\n    if isinstance(s, int):\n        q = [(zero, s)]\n        dist[s] = zero\n    else:\n        q = [(zero, v) for v in s]\n        for d, v in q:\n            dist[v] = zero\n    if isinstance(t, int):\n        if t < 0:\n            t = []\n        else:\n            t = [t]\n    else:\n        t = set(t)\n\n    while q:\n        d, v = hq.heappop(q)\n        if v in t:\n            return dist, d\n        if d > dist[v]:\n            continue\n        for u, w in graph.wadj(v):\n            nw = d + w\n            if dist[u] > nw:\n                dist[u] = nw\n                hq.heappush(q, (nw, u))\n    return dist, None\n\n\ndef get_dual_graph(n_vertices: int, wedges: Iterable[Tuple[int, int, int]]) -> Tuple[\n    List[int], List[int], List[int], List[int]]:\n    """\n    ??????????????????\n    (u, v, cap) in wedges???????????(u, v, cap)?(v, u, 0)?????????????????????????\n\n    :param n_vertices: ???\n    :param wedges: ?????\n    :return: (???????, ???index?????)\n    """\n\n    cap = defaultdict(int)\n    for u, v, c in wedges:\n        cap[(u, v)] += c\n        cap[(v, u)] += 0\n\n    temp: List[List[Tuple[int, int]]] = [[] for _ in range(n_vertices)]\n    for (u, v), w in cap.items():\n        temp[u].append((v, w))\n    adj = [0] * len(cap)\n    weight = [0] * len(cap)\n    rev = [0] * len(cap)\n    ind = [0] * (n_vertices + 1)\n\n    i = 0\n    for u, l in enumerate(temp):\n        ind[u] = i\n        for v, w in l:\n            adj[i] = v\n            weight[i] = w\n            if u < v:\n                cap[(v, u)] = i\n            else:\n                j = cap[(u, v)]\n                rev[i] = j\n                rev[j] = i\n            i += 1\n    ind[n_vertices] = i\n\n    return adj, weight, ind, rev\n\n\ndef edmonds_karp(n_vertices: int, edges: Iterable[Tuple[int, int, int]], s: int, t: int):\n    """\n    ?????????O(VE^2)\n\n    :param n_vertices: ???\n    :param edges: (??1, ??2, ??)?Iterable\n    :param s: ??\n    :param t: ??\n    :return: (????, ?????)\n    """\n\n    adj, caps, ind, rev = get_dual_graph(n_vertices, edges)\n\n    m0 = max(caps)\n    bfs_memo = [0] * n_vertices\n    pv = [-1] * n_vertices\n    pe = [-1] * n_vertices\n    bfs_memo[s] = n_vertices + 1\n    offset = 0\n\n    def find_path():\n        nonlocal offset\n        offset += 1\n        q = [s]\n        while q:\n            nq = []\n            for v in q:\n                if v == t:\n                    return True\n                for i in range(ind[v], ind[v + 1]):\n                    if caps[i] == 0:\n                        continue\n                    u = adj[i]\n                    if bfs_memo[u] < offset:\n                        bfs_memo[u] = offset\n                        pv[u] = v\n                        pe[u] = i\n                        nq.append(u)\n            q = nq\n        return False\n\n    res = 0\n    flag = find_path()\n    while flag:\n        v = t\n        m = m0\n        while pv[v] >= 0:\n            e = pe[v]\n            m = min2(m, caps[e])\n            v = pv[v]\n        v = t\n        while pv[v] >= 0:\n            e = pe[v]\n            caps[e] -= m\n            caps[rev[e]] += m\n            v = pv[v]\n        res += m\n        flag = find_path()\n    return res, WeightedGraph(n_vertices, adj, caps, ind), rev\n\n\ndef max_bipartite_matching(graph: BaseWeightedGraph):\n    pass\n'),
    'lib.misc': (False, 'from typing import List, Any, Callable, Sequence, Union, Tuple, TypeVar\n\nV = TypeVar(\'V\')\n\nimport sys\nfrom functools import reduce\nfrom itertools import accumulate\nfrom lib.data_structure import BinaryIndexedTree, DisjointSet\nimport bisect\n\n\ndef general_bisect(ng: int, ok: int, judge: Callable[[int], V]) -> int:\n    """\n    ???????????????????O(log L)??????\n\n    :param ng: judge(ng)==False????\n    :param ok: judge(ok)==True????\n    :param judge: ??????????\n    :return: judge(x)==True???????????\n    """\n    while abs(ng - ok) > 1:\n        m = (ng + ok) // 2\n        if judge(m):\n            ok = m\n        else:\n            ng = m\n    return ok\n\n\ndef fibonacci_search(left: int, right: int, func: Union[Callable[[int], V], Sequence], inf: V = 2 ** 60) -> Tuple[\n    V, int]:\n    """\n    ??????????????????????????????O(log L)??????\n    ???(left, right)?????????\n\n    :param left: ?????????????\n    :param right: ?????????????\n    :param func: ??????\n    :param inf: func???\n    :return: (func????, ????????func???)\n    """\n    try:\n        func = func.__getitem__\n    except AttributeError:\n        pass\n    f1, f2 = 1, 1\n    while f1 + f2 < right - left:\n        f1, f2 = f1 + f2, f1\n    l = left\n    m1 = func(l + f2)\n    m2 = func(l + f1)\n    while f1 > 2:\n        f1, f2 = f2, f1 - f2\n        if m1 > m2:\n            l += f1\n            m1 = m2\n            m2 = func(l + f1) if l + f1 < right else inf\n        else:\n            m2 = m1\n            m1 = func(l + f2)\n    if m1 < m2:\n        return m1, l + 1\n    else:\n        return m2, l + 2\n\n\ndef max2(x: V, y: V) -> V:\n    return x if x > y else y\n\n\ndef min2(x: V, y: V) -> V:\n    return x if x < y else y\n\n\nread = sys.stdin.buffer.read\nreadline = sys.stdin.buffer.readline\n\n\ndef rerooting(rooted_tree, merge, identity, finalize):\n    """\n    merge: (T,T) -> T, (T, merge)?????\n    identity: ???\n    finalize: (T, V, V) -> T\n\n    ????????dp?????\n    dp[u,v] = finalize(merge(dp[v,k] for k in adj[v] if k != u), u, v)\n    ???(u,v)?? u->v\n    """\n    N = rooted_tree.n_vertices\n    parent = rooted_tree.parent\n    children = rooted_tree.children\n    order = rooted_tree.dfs_order\n\n    
    'lib': (True, ''),
}
_sys.meta_path.insert(2, InlineImporter)


from lib.graph import RootedTree
from lib.misc import min2, read
from operator import add


def solve(rt, people):
    n = rt.n_vertices
    q = [0] * n
    for v in people:
        q[v] = 1
    order = list(rt.post_order())
    total = rt.aggregate_subtree(add, 0, lambda x, v: x + q[v], order)
    shortest = rt.aggregate_subtree(min2, 2 ** 60, lambda x, v: 0 if q[v] else x + 1, order)
    dist = rt.aggregate_parent_path(lambda x, v: x + 1, 0)

    leaves = [1] * n
    for v in range(1, n):
        leaves[rt.parent(v)] = 0
    stack = [0]
    res = len(people)
    while stack:
        v = stack.pop()
        if dist[v] >= shortest[v]:
            res -= total[v] - 1
        elif leaves[v]:
            return -1
        else:
            stack.extend(rt.children(v))
    return res


mm = map(int, read().split())
t = next(mm)
for _ in range(t):
    n, k = next(mm), next(mm)
    x = [c - 1 for _, c in zip(range(k), mm)]
    edges = [(x - 1, y - 1) for _, x, y in zip(range(n - 1), mm, mm)]
    rt = RootedTree.from_edges(edges)
    print(solve(rt, x))