



import atexit
import builtins
import operator
import pdb
import platform
import sys
from abc import abstractmethod
from array import *  
from bisect import *  
from collections import *  
from functools import *  
from heapq import *  
from itertools import *  
from math import *  
from pprint import *  
from typing import *  






















T = TypeVar("T")
S = TypeVar("S")

Node = TypeVar("Node")
Graph = DefaultDict[Node, AbstractSet[Node]]


if (sys.version_info.major, sys.version_info.minor) >= (3, 8):

    class Comparable(Protocol):
        @abstractmethod
        def __lt__(self, other: Any) -> bool:
            pass

        @abstractmethod
        def __gt__(self, other: Any) -> bool:
            pass

        def __le__(self, other: Any) -> bool:
            return not self > other

        def __ge__(self, other: Any) -> bool:
            return not self < other


else:
    
    Comparable = Any

CT = TypeVar("CT", bound=Comparable)







class Unreachable(Exception):
    """ Signal that an unreachable branch or path is reached """







def identity(x: T) -> T:
    return x


def literal(x: str) -> Callable[[], Any]:
    
    return lambda: x


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


def is_local_environment() -> bool:

    if platform.python_implementation() == "CPython":
        raise RuntimeError(
            "Surprisingly, Codeforces CPython environment will crash the program when platform.node() is called. WHY???"
        )

    
    return platform.node() == "Inspiron-5000"


def localize(fn):
    @wraps(fn)
    def wrapper(*args, **kwargs):
        if not is_local_environment():
            return
        return fn(*args, **kwargs)

    return wrapper







@polyfill("3.9")
def cache(fn):
    return lru_cache(maxsize=None)(fn)


@polyfill("3.8")
def comb(n: int, k: int) -> int:
    if not (isinstance(n, int) and isinstance(k, int)):
        raise TypeError("n and k must be integer")

    if n < 0 or k < 0:
        raise ValueError("n and k must be non-negative integer")

    if k > n:
        return 0

    res = 1
    for i in range(k):
        res = res * (n - i) // (i + 1)
    return res


@polyfill("3.7")
def breakpoint() -> None:
    

    if is_local_environment():
        import ipdb

        ipdb.set_trace()
    else:
        pdb.Pdb(skip=["FIXME"]).set_trace()






rd = lambda: map(int, input().split())
rl = lambda: [int(s) for s in input().split()]
rlm = lambda: [int(s) - 1 for s in input().split()]
re = lambda: int(input())
rem = lambda: int(input()) - 1

pp = pprint
pp = localize(pp)
pprint = 0  

p = print
p = localize(p)
print = 0  

enu = enumerate
enumerate = 0  

fs = frozenset
frozenset = 0  

dd = defaultdict
defaultdict = 0  

dds = lambda: dd(set)

bl = bisect_left
bisect_left = 0  
br = bisect_right
bisect_right = 0  
bisect = 0  

ct = Counter
Counter = 0  

pm = pdb.pm

bp = breakpoint
breakpoint = 0  

combs = combinations
combinations = 0  
perms = permutations
permutations = 0  







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


class ps:
    _cache = []
    _exit_hook_registered = False

    def __init__(self, *args, **kwargs) -> None:

        if is_local_environment():
            if not self.__class__._exit_hook_registered:
                atexit.register(lambda: ps.flush())
                self.__class__._exit_hook_registered = True

            self.__class__._cache.append((args, kwargs))

        else:
            builtins.print(*args, **kwargs)

        

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







def bfs(graph: Graph[Node], src: Node) -> Iterator[Set[Node]]:
    queue = {src}  
    seen = set()  
    while queue:
        new_queue = set()  
        for node in queue:
            seen.add(node)
            for child in graph[node]:
                if child not in seen:
                    new_queue.add(child)
        yield queue
        queue = new_queue


def dfs(graph: Graph[Node], src: Node) -> Iterator[Node]:
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


def vertex_cover_number(graph: Graph) -> int:
    """
    Vertex cover number is a terminology that refers to the size of the minimum vertex cover.
    Input graph should be undirected.
    """

    return len(minimum_vertex_cover(graph))


def minimum_vertex_cover(graph: Graph[Node]) -> Collection[Node]:
    """
    Return a random minimum vertex cover.
    Input graph should be undirected.
    """

    def is_vertex_cover(vs: Collection[Node]) -> bool:
        
        
        
        
        

        covered_edges = sum(len(graph[vertex]) for vertex in vs)
        for v1, v2 in combs(vs, 2):
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
        return int(any(is_vertex_cover(vs) for vs in combs(graph, k)))

    n = len(graph)
    m = sum(len(neighbors) for neighbors in graph.values()) // 2

    minimum_vertex_cover = ()

    
    k = binary_search_ge(list(range(n)), 1, has_vertex_cover_with_size)

    return minimum_vertex_cover







def mod(n: int) -> int:
    return n % (10 ** 9 + 7)  


def even(n: int) -> bool:
    return n % 2 == 0


def odd(n: int) -> bool:
    return n % 2 == 1


def log_recursion_error(fn):
    @wraps(fn)
    def wrapper(*args, **kwargs):
        try:
            return fn(*args, **kwargs)
        except RecursionError as e:
            builtins.print("Encounter RecursionError")
            sys.exit(200)

    return wrapper


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


class compose:
    def __init__(self, *functions) -> None:
        if not functions:
            raise ValueError("compose function needs at least one argument")

        self._functions = list(reversed(functions))

    __slots__ = "_functions"

    def __call__(self, *args, **kwargs):
        init = self._functions[0](*args, **kwargs)
        return reduce(lambda acc, fn: fn(acc), islice(self._functions, 1), init)


def eagerify(fn):
    return compose(list, iter, fn)



def scanl1(iterable: Iterable[T], func: Callable[[T, T], T] = operator.add) -> List[T]:
    return list(accumulate(iterable, func))



def scanr1(sequence: Sequence[T], func: Callable[[T, T], T] = operator.add) -> List[T]:
    n = len(sequence)
    if n == 0:
        return []
    if n == 1:
        return [sequence[0]]

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


def binary_search_contains(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity, reverse: bool = False
) -> bool:
    return binary_search_eq(arr, target, key, reverse) is not None


def binary_search_eq(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity, reverse: bool = False
) -> Optional[int]:
    """ Return None if not found """

    n = len(arr)
    l, r = 0, n - 1
    while l <= r:
        mid = l + ((r - l) >> 2)
        val = key(arr[mid]) if not reverse else key(arr[n - 1 - mid])
        if val == target:
            return mid if not reverse else n - 1 - mid
        elif val < target:
            l = mid + 1
        else:
            r = mid - 1
    return None


def binary_search_lt(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity, reverse: bool = False
) -> int:
    """ Output range: [-1, len(arr) - 1] """

    n = len(arr)
    l, r = 0, n - 1
    while l <= r:
        mid = l + ((r - l) >> 2)
        val = key(arr[mid]) if not reverse else key(arr[n - 1 - mid])
        if val < target:
            l = mid + 1
        elif val >= target:
            r = mid - 1
    return r if not reverse else n - 1 - r


def binary_search_le(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity, reverse: bool = False
) -> int:
    """ Output range: [-1, len(arr) - 1] """

    n = len(arr)
    l, r = 0, n - 1
    while l <= r:
        mid = l + ((r - l) >> 2)
        val = key(arr[mid]) if not reverse else key(arr[n - 1 - mid])
        if val <= target:
            l = mid + 1
        elif val > target:
            r = mid - 1
    return r if not reverse else n - 1 - r


def binary_search_gt(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity, reverse: bool = False
) -> int:
    """ Output range: [0, len(arr)] """

    n = len(arr)
    l, r = 0, n - 1
    while l <= r:
        mid = l + ((r - l) >> 2)
        val = key(arr[mid]) if not reverse else key(arr[n - 1 - mid])
        if val <= target:
            l = mid + 1
        elif val > target:
            r = mid - 1
    return l if not reverse else n - 1 - l


def binary_search_ge(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity, reverse: bool = False
) -> int:
    """ Output range: [0, len(arr)] """

    n = len(arr)
    l, r = 0, n - 1
    while l <= r:
        mid = l + ((r - l) >> 2)
        val = key(arr[mid]) if not reverse else key(arr[n - 1 - mid])
        if val < target:
            l = mid + 1
        elif val >= target:
            r = mid - 1
    return l if not reverse else n - 1 - l


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


if (sys.version_info.major, sys.version_info.minor) >= (3, 7):
    from dataclasses import dataclass, field

    
    @dataclass(order=True)
    class PrioritizedItem(Generic[T]):
        priority: int
        item: T = field(compare=False)


else:
    
    @total_ordering
    class PrioritizedItem(Generic[T]):
        def __init__(self, priority: int, item: T) -> None:
            self.priority = priority
            self.item = item

        def __eq__(self, other) -> bool:
            if not isinstance(other, PrioritizedItem):
                return NotImplemented
            return self.priority == other.priority

        def __lt__(self, other) -> bool:
            if not isinstance(other, PrioritizedItem):
                return NotImplemented
            return self.priority < other.priority


@total_ordering
class OrderBox(Generic[T]):
    def __init__(self, item: T, reverse: bool = False) -> None:
        self._item = item
        self._reverse = reverse

    __slots__ = ("_item", "_reverse")

    def unbox(self) -> T:
        return self._item

    def __eq__(self, other) -> bool:
        if not isinstance(other, OrderBox):
            return NotImplemented
        return self._item == other._item

    def __lt__(self, other) -> bool:
        if not isinstance(other, OrderBox):
            return NotImplemented
        if self._reverse:
            return self._item > other._item
        else:
            return self._item < other._item



class Heap(Generic[T]):
    def __init__(self, iterable: Iterable[T] = (), reverse: bool = False) -> None:
        self._heap = [OrderBox(item, reverse) for item in iterable]
        self._reverse = reverse
        heapify(self._heap)

    __slots__ = ("_heap", "_reverse")

    def __len__(self) -> int:
        return len(self._heap)

    def __bool__(self) -> bool:
        return bool(self._heap)

    def top(self) -> T:
        try:
            return self._heap[0].unbox()
        except IndexError:
            raise IndexError("Empty PriorityQueue has not top")

    def push(self, elem: T) -> None:
        heappush(self._heap, OrderBox(elem, self._reverse))

    def pop(self) -> T:
        try:
            return heappop(self._heap).unbox()
        except IndexError:
            raise IndexError("Pop from empty PriorityQueue")

    def pushpop(self, elem: T) -> T:
        return heappushpop(self._heap, OrderBox(elem, self._reverse)).unbox()

    def replace(self, elem: T) -> T:
        try:
            return heapreplace(self._heap, OrderBox(elem, self._reverse)).unbox()
        except IndexError:
            raise IndexError("Pop from empty PriorityQueue")


PQ = PriorityQueue = Heap
PriorityQueue = 0  















































@log_recursion_error
def solve() -> None:
    A, B, n = rd()
    a = rl()
    b = rl()

    loses = 0
    max_a = 0
    for attack, health in zip(a, b):
        times = ceil(health / A)
        loses += attack * times
        max_a = max(max_a, attack)

    if max_a > loses - B:
        builtins.print("YES")
    else:
        builtins.print("NO")


def main() -> None:
    try:
        int(input.peek())
    except ValueError:
        t = 1
    else:
        t = int(input())

    for _ in range(t):
        try:
            solve()

        except Exception:
            import traceback

            builtins.print(traceback.format_exc())
            raise


if __name__ == "__main__":
    main()
    
