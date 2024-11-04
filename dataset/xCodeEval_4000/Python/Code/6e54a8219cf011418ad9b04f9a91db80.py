



import builtins
import operator
import platform
import sys
from abc import abstractmethod
from array import *  
from bisect import *  
from collections import *  
from functools import *  
from heapq import *  
from importlib import import_module
from itertools import *  
from math import *  
from pprint import pprint as pp
from typing import *  







if platform.python_implementation() != "PyPy":
    raise RuntimeError(
        "Should use PyPy interpreter. "
        "This script is tailor made for PyPy environment."
    )

T = TypeVar("T")
S = TypeVar("S")


def identity(x: T) -> T:
    return x


def polyfill(version: str):
    """ major.minor.micro version granularity is supported. """

    lowest_supported_version = [int(comp) for comp in version.split(".")]

    v = sys.version_info
    if [v.major, v.minor, v.micro] >= lowest_supported_version:
        
        
        
        return lambda fn_or_cls: eval(fn_or_cls.__name__)
    else:
        return identity


def future(version: str, fallback=None):
    """ major.minor.micro version granularity is supported. """

    lowest_supported_version = [int(comp) for comp in version.split(".")]

    v = sys.version_info

    if [v.major, v.minor, v.micro] >= lowest_supported_version:
        return identity

    elif fallback is not None:
        return lambda _: fallback

    else:

        def decorator(fn_or_cls):
            @wraps(fn_or_cls)
            def wrapper(*_, **__):
                raise NotImplementedError(
                    f"{fn_or_cls.__name__} has dependency that relies on "
                    "features added since Python {v.major}.{v.minor}.{v.micro}"
                )

            return wrapper

        return decorator


class LookaheadInputWrapper:
    def __init__(self) -> None:
        self._lookahead = None

    __slot__ = "_lookahead"

    def __call__(self) -> str:
        if self._lookahead is None:
            return builtins.input()
        res = self._lookahead
        self._lookahead = None
        return res

    def peek(self) -> str:
        if self._lookahead is None:
            self._lookahead = builtins.input()
        return self._lookahead


input = LookaheadInputWrapper()


rd = lambda: map(int, input().split())
rl = lambda: [int(s) for s in input().split()]
rlm = lambda: [int(s) - 1 for s in input().split()]
re = lambda: int(input())


def is_local_environment() -> bool:
    
    return platform.node() == "Inspiron-5000"


def localize(fn):
    @wraps(fn)
    def wrapper(*args, **kwargs):
        if not is_local_environment():
            return
        return fn(*args, **kwargs)

    return wrapper


pp = localize(pp)
p = localize(print)
print = 0  

enu = enumerate
enumerate = 0  




@polyfill("3.9")
def cache(fn):
    return lru_cache(maxsize=None)(fn)


def mod(n: int) -> int:
    return n % (10 ** 9 + 7)  


def even(n: int) -> bool:
    return n % 2 == 0


def odd(n: int) -> bool:
    return n % 2 == 1


class ps:
    _cache = []

    def __init__(self, *args, **kwargs) -> None:
        self.__class__._cache.append((args, kwargs))
        

    __slots__ = ()

    @classmethod
    def serialize(cls: Type["ps"]) -> str:
        from io import StringIO

        string_stream = StringIO()

        p("\033[92m", end="", file=string_stream)

        for args, kwargs in cls._cache:
            builtins.print(*args, file=string_stream, **kwargs)

        p("\033[0m", end="", file=string_stream)

        return string_stream.getvalue()

    @classmethod
    def flush(cls: Type["ps"]) -> None:
        p("\033[92m", end="")

        for args, kwargs in cls._cache:
            builtins.print(*args, **kwargs)

        p("\033[0m", end="")


def psb(boolean: bool) -> None:
    if boolean:
        ps("yes")
    else:
        ps("no")


def log_recursion_error(fn):
    @wraps(fn)
    def wrapper(*args, **kwargs):
        try:
            return fn(*args, **kwargs)
        except RecursionError as e:
            builtins.print("Encounter RecursionError")
            sys.exit(200)

    return wrapper


def print_test_case(target_t: int, num: int, lines: int) -> None:
    num -= 1

    t = int(input())

    if t != target_t:
        for _ in range(t):
            solve()
        ps.flush()
        return

    assert num < t

    for i in range(t):
        test_case = "\n".join(input() for _ in range(lines))
        if i == num:
            builtins.print(test_case)
            sys.exit(201)


class Singleton:
    _singleton = None

    def __new__(cls: Type["Singleton"]) -> "Singleton":
        if cls._singleton is None:
            cls._singleton = object.__new__(cls)
        return cls._singleton

    __slots__ = ()


_sentinel = object()
NO_DEFAULT = object()



class peekable(Iterator[T]):
    def __init__(self, iterable: Iterable[T]) -> None:
        self._iterator = iter(iterable)
        try:
            self._head = next(self._iterator)
        except StopIteration:
            self._head = _sentinel

    __slots__ = ("_iterator", "_head")

    def peek(self, default=NO_DEFAULT) -> T:
        if self._head is _sentinel:
            if default is NO_DEFAULT:
                raise StopIteration
            else:
                return default
        else:
            return cast(T, self._head)

    def __bool__(self) -> bool:
        return self._head is not _sentinel

    def __getitem__(self) -> T:
        raise NotImplementedError

    def prepend(self) -> None:
        raise NotImplementedError

    def __next__(self) -> T:
        if self._head is _sentinel:
            raise StopIteration
        res = self._head
        try:
            self._head = next(self._iterator)
        except StopIteration:
            self._head = _sentinel
        return cast(T, res)

    def __iter__(self) -> Iterator[T]:
        return self



Node = Any
Graph = DefaultDict[Node, Set[Node]]


def bfs(graph: Graph, src: Node) -> Iterator[Set[Node]]:
    queue: Set[Node] = {src}
    seen: Set[Node] = set()
    while queue:
        new_queue = set()
        for node in queue:
            seen.add(node)
            for child in graph[node]:
                if child not in seen:
                    new_queue.add(child)
        yield queue
        queue = new_queue


def dfs(graph: Graph, src: Node) -> Iterator[Node]:
    stack: List[Node] = [src]
    seen: Set[Node] = set()
    while stack:
        node = stack.pop()
        if node in seen:
            continue
        yield node
        seen.add(node)
        for child in graph[node]:
            if child not in seen:
                stack.append(child)


class compose:
    def __init__(self, *functions) -> None:
        if not functions:
            raise ValueError("compose function needs at least one argument")

        self._functions = functions

    __slots__ = "_functions"

    def __call__(self, *args, **kwargs):
        res = self._functions[-1](*args, **kwargs)
        i = len(self._functions) - 2
        while i >= 0:
            func = self._functions[i]
            res = func(res)
        return res


def eagerify(fn):
    return compose(list, iter, fn)



def scanl1(iterable: Iterable[T], func: Callable[[T, T], T] = operator.add) -> List[T]:
    return list(accumulate(iterable, func))



def scanr1(sequence: Sequence[T], func: Callable[[T, T], T] = operator.add) -> List[T]:
    n = len(sequence)
    res = cast(List[T], [None] * n)
    res[n - 1] = sequence[n - 1]
    i = n - 2
    while i >= 0:
        last = res[i + 1]
        res[i] = func(last, sequence[i])
        i -= 1
    return res


prefix_sum = scanl1
suffix_sum = scanr1
prefix_max = partial(scanl1, func=max)
suffix_max = partial(scanr1, func=max)
prefix_min = partial(scanl1, func=min)
suffix_min = partial(scanr1, func=min)

helper = lambda module: module.dataclass(order=True)































































CT = TypeVar("CT", bound=Any)


def binary_search_contains(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity
) -> bool:
    return binary_search_eq(arr, target, key) != -1


def binary_search_eq(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity
) -> int:
    """ Return -1 if not found """

    n = len(arr)
    l, r = 0, n - 1
    while l <= r:
        mid = l + ((r - l) >> 2)
        val = key(arr[mid])
        if val == target:
            return mid
        elif val < target:
            l = mid + 1
        else:
            r = mid - 1
    return -1


def binary_search_lt(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity
) -> int:
    """ Output range: [-1, len(arr) - 1] """

    n = len(arr)
    l, r = 0, n - 1
    while l <= r:
        mid = l + ((r - l) >> 2)
        val = key(arr[mid])
        if val < target:
            l = mid + 1
        elif val >= target:
            r = mid - 1
    return r


def binary_search_le(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity
) -> int:
    """ Output range: [-1, len(arr) - 1] """

    n = len(arr)
    l, r = 0, n - 1
    while l <= r:
        mid = l + ((r - l) >> 2)
        val = key(arr[mid])
        if val <= target:
            l = mid + 1
        elif val > target:
            r = mid - 1
    return r


def binary_search_gt(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity
) -> int:
    """ Output range: [0, len(arr)] """

    n = len(arr)
    l, r = 0, n - 1
    while l <= r:
        mid = l + ((r - l) >> 2)
        val = key(arr[mid])
        if val <= target:
            l = mid + 1
        elif val > target:
            r = mid - 1
    return l


def binary_search_ge(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity
) -> int:
    """ Output range: [0, len(arr)] """

    n = len(arr)
    l, r = 0, n - 1
    while l <= r:
        mid = l + ((r - l) >> 2)
        val = key(arr[mid])
        if val < target:
            l = mid + 1
        elif val >= target:
            r = mid - 1
    return l


def log_function_result(fn):
    @wraps(fn)
    def wrapper(*args, **kwargs):
        res = fn(*args, **kwargs)

        arg_str = ", ".join(str(arg) for arg in args)
        if kwargs:
            arg_str += ", " + ", ".join(f"{k}={v}" for k, v in kwargs)

        p(f"{fn.__name__}({arg_str}) -> {res}")

        return res

    return wrapper


def vertex_cover_number(graph: Graph) -> int:
    """
    Vertex cover number is a terminology that refers to the size of the minimum vertex cover.
    Input graph should be undirected.
    """

    return len(minimum_vertex_cover(graph))


def minimum_vertex_cover(graph: Graph) -> Collection[Node]:
    """
    Return a random minimum vertex cover.
    Input graph should be undirected.
    """

    def is_vertex_cover(vs: Collection[Node]) -> bool:
        
        
        
        
        

        covered_edges = sum(len(graph[vertex]) for vertex in vs)
        for v1, v2 in combinations(vs, 2):
            if v2 in graph[v1]:
                covered_edges -= 1

        if covered_edges == m:
            nonlocal minimum_vertex_cover
            minimum_vertex_cover = vs
            return True

        else:
            return False

    def has_vertex_cover_with_size(k: int) -> int:
        """ Return 1 when some vertex cover with size k exists, else 0 """
        return int(any(is_vertex_cover(vs) for vs in combinations(graph, k)))

    n = len(graph)
    m = sum(len(neighbors) for neighbors in graph.values()) // 2

    minimum_vertex_cover = ()

    
    k = binary_search_ge(list(range(n)), 1, has_vertex_cover_with_size)

    return minimum_vertex_cover













@log_recursion_error
def solve() -> None:
    n = re()

    l, r = 0, n - 1
    while l <= r:
        mid = (l + r) // 2
        if mid - 1 >= 0:
            builtins.print("? " + str(mid))
            sys.stdout.flush()
            val1 = re()
        else:
            val1 = float("inf")
        builtins.print("? " + str(mid + 1))
        sys.stdout.flush()
        val2 = re()
        if mid + 1 < n:
            builtins.print("? " + str(mid + 2))
            sys.stdout.flush()
            val3 = re()
        else:
            val3 = float("inf")
        if val1 > val2 < val3:
            builtins.print("! " + str(mid + 1))
            return
        elif val1 < val2 < val3:
            r = mid - 1
        elif val1 > val2 > val3:
            l = mid + 1
        else:
            r = mid - 1


def main() -> None:
    t = 1
    for _ in range(t):
        solve()

    ps.flush()


if __name__ == "__main__":
    main()
    
