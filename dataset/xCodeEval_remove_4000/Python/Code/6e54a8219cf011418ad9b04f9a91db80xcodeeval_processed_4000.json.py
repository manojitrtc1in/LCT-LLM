



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
    

    id18 = [int(comp) for comp in version.split(".")]

    v = sys.version_info
    if [v.major, v.minor, v.micro] >= id18:
        
        
        
        return lambda id25: eval(id25.__name__)
    else:
        return identity


def future(version: str, fallback=None):
    

    id18 = [int(comp) for comp in version.split(".")]

    v = sys.version_info

    if [v.major, v.minor, v.micro] >= id18:
        return identity

    elif fallback is not None:
        return lambda _: fallback

    else:

        def decorator(id25):
            @wraps(id25)
            def wrapper(*_, **__):
                raise NotImplementedError(
                    f"{id25.__name__} has dependency that relies on "
                    "features added since Python {v.major}.{v.minor}.{v.micro}"
                )

            return wrapper

        return decorator


class id15:
    def __init__(self) -> None:
        self._lookahead = None

    id6 = "_lookahead"

    def id11(self) -> str:
        if self._lookahead is None:
            return builtins.input()
        res = self._lookahead
        self._lookahead = None
        return res

    def peek(self) -> str:
        if self._lookahead is None:
            self._lookahead = builtins.input()
        return self._lookahead


input = id15()


rd = lambda: map(int, input().split())
rl = lambda: [int(s) for s in input().split()]
rlm = lambda: [int(s) - 1 for s in input().split()]
re = lambda: int(input())


def id10() -> bool:
    
    return platform.node() == "Inspiron-5000"


def localize(fn):
    @wraps(fn)
    def wrapper(*args, **kwargs):
        if not id10():
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
        

    id5 = ()

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


def id12(fn):
    @wraps(fn)
    def wrapper(*args, **kwargs):
        try:
            return fn(*args, **kwargs)
        except RecursionError as e:
            builtins.print("Encounter RecursionError")
            sys.exit(200)

    return wrapper


def id23(target_t: int, num: int, lines: int) -> None:
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

    def id7(cls: Type["Singleton"]) -> "Singleton":
        if cls._singleton is None:
            cls._singleton = object.id7(cls)
        return cls._singleton

    id5 = ()


_sentinel = object()
NO_DEFAULT = object()



class peekable(Iterator[T]):
    def __init__(self, iterable: Iterable[T]) -> None:
        self._iterator = iter(iterable)
        try:
            self._head = next(self._iterator)
        except StopIteration:
            self._head = _sentinel

    id5 = ("_iterator", "_head")

    def peek(self, default=NO_DEFAULT) -> T:
        if self._head is _sentinel:
            if default is NO_DEFAULT:
                raise StopIteration
            else:
                return default
        else:
            return cast(T, self._head)

    def id3(self) -> bool:
        return self._head is not _sentinel

    def id21(self) -> T:
        raise NotImplementedError

    def prepend(self) -> None:
        raise NotImplementedError

    def id19(self) -> T:
        if self._head is _sentinel:
            raise StopIteration
        res = self._head
        try:
            self._head = next(self._iterator)
        except StopIteration:
            self._head = _sentinel
        return cast(T, res)

    def id27(self) -> Iterator[T]:
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

    id5 = "_functions"

    def id11(self, *args, **kwargs):
        res = self._functions[-1](*args, **kwargs)
        i = len(self._functions) - 2
        while i >= 0:
            func = self._functions[i]
            res = func(res)
        return res


def id9(fn):
    return compose(list, iter, fn)



def id14(iterable: Iterable[T], func: Callable[[T, T], T] = operator.add) -> List[T]:
    return list(accumulate(iterable, func))



def id26(sequence: Sequence[T], func: Callable[[T, T], T] = operator.add) -> List[T]:
    n = len(sequence)
    res = cast(List[T], [None] * n)
    res[n - 1] = sequence[n - 1]
    i = n - 2
    while i >= 0:
        last = res[i + 1]
        res[i] = func(last, sequence[i])
        i -= 1
    return res


prefix_sum = id14
suffix_sum = id26
prefix_max = partial(id14, func=max)
suffix_max = partial(id26, func=max)
prefix_min = partial(id14, func=min)
suffix_min = partial(id26, func=min)

helper = lambda module: module.dataclass(order=True)































































CT = TypeVar("CT", bound=Any)


def id22(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity
) -> bool:
    return id1(arr, target, key) != -1


def id1(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity
) -> int:
    

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


def id2(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity
) -> int:
    

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


def id4(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity
) -> int:
    

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


def id17(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity
) -> int:
    

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


def id20(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity
) -> int:
    

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


def id24(fn):
    @wraps(fn)
    def wrapper(*args, **kwargs):
        res = fn(*args, **kwargs)

        arg_str = ", ".join(str(arg) for arg in args)
        if kwargs:
            arg_str += ", " + ", ".join(f"{k}={v}" for k, v in kwargs)

        p(f"{fn.__name__}({arg_str}) -> {res}")

        return res

    return wrapper


def id13(graph: Graph) -> int:
    

    return len(id0(graph))


def id0(graph: Graph) -> Collection[Node]:
    

    def id16(vs: Collection[Node]) -> bool:
        
        
        
        
        

        covered_edges = sum(len(graph[vertex]) for vertex in vs)
        for v1, v2 in combinations(vs, 2):
            if v2 in graph[v1]:
                covered_edges -= 1

        if covered_edges == m:
            nonlocal id0
            id0 = vs
            return True

        else:
            return False

    def id8(k: int) -> int:
        
        return int(any(id16(vs) for vs in combinations(graph, k)))

    n = len(graph)
    m = sum(len(neighbors) for neighbors in graph.values()) // 2

    id0 = ()

    
    k = id20(list(range(n)), 1, id8)

    return id0













@id12
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
    
