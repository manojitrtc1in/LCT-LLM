



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
        def id33(self, other: Any) -> bool:
            pass

        @abstractmethod
        def id16(self, other: Any) -> bool:
            pass

        def id29(self, other: Any) -> bool:
            return not self > other

        def id36(self, other: Any) -> bool:
            return not self < other


else:
    
    Comparable = Any

CT = TypeVar("CT", bound=Comparable)







class Unreachable(Exception):
    







def identity(x: T) -> T:
    return x


def literal(x: str) -> Callable[[], Any]:
    
    return lambda: x


def polyfill(version: str):
    

    id24 = [int(comp) for comp in version.split(".")]

    v = sys.version_info
    if [v.major, v.minor, v.micro] >= id24:
        
        
        
        return lambda id34: eval(id34.__name__)
    else:
        return identity


def future(version: str, fallback=None):
    

    id24 = [int(comp) for comp in version.split(".")]

    v = sys.version_info

    if [v.major, v.minor, v.micro] >= id24:
        return identity

    elif fallback is not None:
        return lambda _: fallback

    else:

        def decorator(id34):
            @wraps(id34)
            def wrapper(*_, **__):
                raise NotImplementedError(
                    f"{id34.__name__} has dependency that relies on "
                    "features added since Python {v.major}.{v.minor}.{v.micro}"
                )

            return wrapper

        return decorator


def id14() -> bool:

    if platform.python_implementation() == "CPython":
        raise RuntimeError(
            "Surprisingly, Codeforces CPython environment will crash the program when platform.node() is called. WHY???"
        )

    
    return platform.node() == "Inspiron-5000"


def localize(fn):
    @wraps(fn)
    def wrapper(*args, **kwargs):
        if not id14():
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
    

    if id14():
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

fs = id0
id0 = 0  

dd = defaultdict
defaultdict = 0  

dds = lambda: dd(set)

bl = id1
id1 = 0  
br = id27
id27 = 0  
bisect = 0  

ct = Counter
Counter = 0  

pm = pdb.pm

bp = breakpoint
breakpoint = 0  

combs = combinations
combinations = 0  
perms = id5
id5 = 0  







class id21:
    def __init__(self) -> None:
        self._lookahead = None

    id9 = "_lookahead"

    def id15(self) -> str:
        if self._lookahead is None:
            return builtins.input()
        res = self._lookahead
        self._lookahead = None
        return res

    def peek(self) -> str:
        if self._lookahead is None:
            self._lookahead = builtins.input()
        return self._lookahead


input = id21()


class ps:
    _cache = []
    id19 = False

    def __init__(self, *args, **kwargs) -> None:

        if id14():
            if not self.__class__.id19:
                atexit.register(lambda: ps.flush())
                self.__class__.id19 = True

            self.__class__._cache.append((args, kwargs))

        else:
            builtins.print(*args, **kwargs)

        

    id8 = ()

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


def id31(target_t: int, num: int, lines: int) -> None:
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


def id18(graph: Graph) -> int:
    

    return len(id2(graph))


def id2(graph: Graph[Node]) -> Collection[Node]:
    

    def id22(vs: Collection[Node]) -> bool:
        
        
        
        
        

        covered_edges = sum(len(graph[vertex]) for vertex in vs)
        for v1, v2 in combs(vs, 2):
            if v2 in graph[v1]:
                covered_edges -= 1

        if covered_edges == m:
            nonlocal id2
            id2 = vs
            return True

        else:
            return False

    def id12(k: int) -> int:
        
        return int(any(id22(vs) for vs in combs(graph, k)))

    n = len(graph)
    m = sum(len(neighbors) for neighbors in graph.values()) // 2

    id2 = ()

    
    k = id26(list(range(n)), 1, id12)

    return id2







def mod(n: int) -> int:
    return n % (10 ** 9 + 7)  


def even(n: int) -> bool:
    return n % 2 == 0


def odd(n: int) -> bool:
    return n % 2 == 1


def id17(fn):
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

    def id10(cls: Type["Singleton"]) -> "Singleton":
        if cls._singleton is None:
            cls._singleton = object.id10(cls)
        return cls._singleton

    id8 = ()


_sentinel = object()
NO_DEFAULT = object()



class peekable(Iterator[T]):
    def __init__(self, iterable: Iterable[T]) -> None:
        self._iterator = iter(iterable)
        try:
            self._head = next(self._iterator)
        except StopIteration:
            self._head = _sentinel

    id8 = ("_iterator", "_head")

    def peek(self, default=NO_DEFAULT) -> T:
        if self._head is _sentinel:
            if default is NO_DEFAULT:
                raise StopIteration
            else:
                return default
        else:
            return cast(T, self._head)

    def id6(self) -> bool:
        return self._head is not _sentinel

    def id28(self) -> T:
        raise NotImplementedError

    def prepend(self) -> None:
        raise NotImplementedError

    def id25(self) -> T:
        if self._head is _sentinel:
            raise StopIteration
        res = self._head
        try:
            self._head = next(self._iterator)
        except StopIteration:
            self._head = _sentinel
        return cast(T, res)

    def id38(self) -> Iterator[T]:
        return self


class compose:
    def __init__(self, *functions) -> None:
        if not functions:
            raise ValueError("compose function needs at least one argument")

        self._functions = list(reversed(functions))

    id8 = "_functions"

    def id15(self, *args, **kwargs):
        init = self._functions[0](*args, **kwargs)
        return reduce(lambda acc, fn: fn(acc), islice(self._functions, 1), init)


def id13(fn):
    return compose(list, iter, fn)



def id20(iterable: Iterable[T], func: Callable[[T, T], T] = operator.add) -> List[T]:
    return list(accumulate(iterable, func))



def id35(sequence: Sequence[T], func: Callable[[T, T], T] = operator.add) -> List[T]:
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


prefix_sum = id20
suffix_sum = id35
prefix_max = partial(id20, func=max)
suffix_max = partial(id35, func=max)
prefix_min = partial(id20, func=min)
suffix_min = partial(id35, func=min)


def id30(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity, reverse: bool = False
) -> bool:
    return id3(arr, target, key, reverse) is not None


def id3(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity, reverse: bool = False
) -> Optional[int]:
    

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


def id4(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity, reverse: bool = False
) -> int:
    

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


def id7(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity, reverse: bool = False
) -> int:
    

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


def id23(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity, reverse: bool = False
) -> int:
    

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


def id26(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity, reverse: bool = False
) -> int:
    

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


def id32(fn):
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
    class id37(Generic[T]):
        priority: int
        item: T = field(compare=False)


else:
    
    @total_ordering
    class id37(Generic[T]):
        def __init__(self, priority: int, item: T) -> None:
            self.priority = priority
            self.item = item

        def id11(self, other) -> bool:
            if not isinstance(other, id37):
                return NotImplemented
            return self.priority == other.priority

        def id33(self, other) -> bool:
            if not isinstance(other, id37):
                return NotImplemented
            return self.priority < other.priority


@total_ordering
class OrderBox(Generic[T]):
    def __init__(self, item: T, reverse: bool = False) -> None:
        self._item = item
        self._reverse = reverse

    id8 = ("_item", "_reverse")

    def unbox(self) -> T:
        return self._item

    def id11(self, other) -> bool:
        if not isinstance(other, OrderBox):
            return NotImplemented
        return self._item == other._item

    def id33(self, other) -> bool:
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

    id8 = ("_heap", "_reverse")

    def id39(self) -> int:
        return len(self._heap)

    def id6(self) -> bool:
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















































@id17
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
    
