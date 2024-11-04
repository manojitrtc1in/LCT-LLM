





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








if platform.python_implementation() != "PyPy":
    builtins.print(
        "Should use PyPy interpreter. "
        "This script is tailor made for PyPy environment."
    )
    raise RuntimeError(
        "Should use PyPy interpreter. "
        "This script is tailor made for PyPy environment."
    )





T = TypeVar("T")
S = TypeVar("S")

Node = TypeVar("Node")
Graph = DefaultDict[Node, AbstractSet[Node]]


if (sys.version_info.major, sys.version_info.minor) >= (3, 8):

    class Comparable(Protocol):
        @abstractmethod
        def id38(self, other: Any) -> bool:
            pass

        @abstractmethod
        def id21(self, other: Any) -> bool:
            pass

        def id34(self, other: Any) -> bool:
            return not self > other

        def id41(self, other: Any) -> bool:
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
    

    id29 = [int(comp) for comp in version.split(".")]

    v = sys.version_info
    if [v.major, v.minor, v.micro] >= id29:
        
        
        
        return lambda id39: eval(id39.__name__)
    else:
        return identity


def future(version: str, fallback=None):
    

    id29 = [int(comp) for comp in version.split(".")]

    v = sys.version_info

    if [v.major, v.minor, v.micro] >= id29:
        return identity

    elif fallback is not None:
        return lambda _: fallback

    else:

        def decorator(id39):
            @wraps(id39)
            def wrapper(*_, **__):
                raise NotImplementedError(
                    f"{id39.__name__} has dependency that relies on "
                    "features added since Python {v.major}.{v.minor}.{v.micro}"
                )

            return wrapper

        return decorator


def id19() -> bool:
    
    

    
    
    
    

    
    

    try:
        import is_local
    except ImportError:
        return False
    else:
        return True


def localize(fn):
    @wraps(fn)
    def wrapper(*args, **kwargs):
        if not id19():
            return
        return fn(*args, **kwargs)

    return wrapper
















def id13(cls_name: str):
    def id12(cls):
        if cls._singleton is None:
            cls._singleton = object.id12(cls)
        return cls._singleton

    cls = type(
        cls_name, (object,), {"id12": id12, "_singleton": None, "id10": ()}
    )

    return cls()


id0 = id13("id0")







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
    

    if id19():
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
pprint = id0

p = print
p = localize(p)
print = id0

enu = enumerate
enumerate = id0

fs = id1
id1 = id0

dd = defaultdict
defaultdict = id0

dds = lambda: dd(set)

bl = id2
id2 = id0
br = id32
id32 = id0
bisect = id0

ct = Counter
Counter = id0

pm = pdb.pm

bp = breakpoint
breakpoint = id0

combs = combinations
combinations = id0
perms = id7
id7 = id0

INFINITY = float("inf")  
NEG_INFINITY = float("-inf")  







class id26:
    def __init__(self) -> None:
        self._lookahead = None

    id11 = "_lookahead"

    def id20(self) -> str:
        if self._lookahead is None:
            return builtins.input()
        res = self._lookahead
        self._lookahead = None
        return res

    def peek(self) -> str:
        if self._lookahead is None:
            self._lookahead = builtins.input()
        return self._lookahead


input = id26()


class ps:
    _cache = []
    id24 = False

    def __init__(self, *args, **kwargs) -> None:

        if id19():
            if not self.__class__.id24:
                atexit.register(lambda: ps.flush())
                self.__class__.id24 = True

            self.__class__._cache.append((args, kwargs))

        else:
            builtins.print(*args, **kwargs)

        

    id10 = ()

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


def id36(target_t: int, num: int, lines: int) -> None:
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


def id23(graph: Graph) -> int:
    

    return len(id3(graph))


def id3(graph: Graph[Node]) -> Collection[Node]:
    

    def id27(vs: Collection[Node]) -> bool:
        
        
        
        
        

        covered_edges = sum(len(graph[vertex]) for vertex in vs)
        for v1, v2 in combs(vs, 2):
            if v2 in graph[v1]:
                covered_edges -= 1

        if covered_edges == m:
            nonlocal id3
            id3 = vs
            return True

        else:
            return False

    def id16(k: int) -> int:
        
        return int(any(id27(vs) for vs in combs(graph, k)))

    n = len(graph)
    m = sum(len(neighbors) for neighbors in graph.values()) // 2

    id3 = ()

    
    k = id31(list(range(n)), 1, id16)

    return id3







def mod(n: int) -> int:
    return n % (10 ** 9 + 7)  


def even(n: int) -> bool:
    return n % 2 == 0


def odd(n: int) -> bool:
    return n % 2 == 1


def id22(fn):
    @wraps(fn)
    def wrapper(*args, **kwargs):
        try:
            return fn(*args, **kwargs)
        except RecursionError as e:
            builtins.print("Encounter RecursionError")
            sys.exit(200)

    return wrapper


_sentinel = id13("_sentinel")
NO_DEFAULT = id13("NO_DEFAULT")



class peekable(Iterator[T]):
    def __init__(self, iterable: Iterable[T]) -> None:
        self._iterator = iter(iterable)
        try:
            self._head = next(self._iterator)
        except StopIteration:
            self._head = _sentinel

    id10 = ("_iterator", "_head")

    def peek(self, default=NO_DEFAULT) -> T:
        if self._head is _sentinel:
            if default is NO_DEFAULT:
                raise StopIteration
            else:
                return default
        else:
            return cast(T, self._head)

    def id8(self) -> bool:
        return self._head is not _sentinel

    def id33(self) -> T:
        raise NotImplementedError

    def prepend(self) -> None:
        raise NotImplementedError

    def id30(self) -> T:
        if self._head is _sentinel:
            raise StopIteration
        res = self._head
        try:
            self._head = next(self._iterator)
        except StopIteration:
            self._head = _sentinel
        return cast(T, res)

    def id43(self) -> Iterator[T]:
        return self


class compose:
    def __init__(self, *functions) -> None:
        if not functions:
            raise ValueError("compose function needs at least one argument")

        self._functions = list(reversed(functions))

    id10 = "_functions"

    def id20(self, *args, **kwargs):
        init = self._functions[0](*args, **kwargs)
        return reduce(lambda acc, fn: fn(acc), islice(self._functions, 1), init)


def id17(fn):
    return compose(list, iter, fn)



def id25(iterable: Iterable[T], func: Callable[[T, T], T] = operator.add) -> List[T]:
    return list(accumulate(iterable, func))



def id40(sequence: Sequence[T], func: Callable[[T, T], T] = operator.add) -> List[T]:
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


prefix_sum = id25
suffix_sum = id40
prefix_max = partial(id25, func=max)
suffix_max = partial(id40, func=max)
prefix_min = partial(id25, func=min)
suffix_min = partial(id40, func=min)


def id35(
    arr: List[T], target: CT, key: Callable[[T], CT] = identity, reverse: bool = False
) -> bool:
    return id4(arr, target, key, reverse) is not None


def id4(
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


def id6(
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


def id9(
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


def id28(
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


def id31(
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


def id37(fn):
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
    class id42(Generic[T]):
        priority: int
        item: T = field(compare=False)


else:
    
    @total_ordering
    class id42(Generic[T]):
        def __init__(self, priority: int, item: T) -> None:
            self.priority = priority
            self.item = item

        id10 = ("priority", "item")

        def id18(self)->str:
            return f"id42(priority={self.priority}, item={self.item}"

        def id14(self, other) -> bool:
            if not isinstance(other, id42):
                return NotImplemented

            return self.priority == other.priority

        def id38(self, other) -> bool:
            if not isinstance(other, id42):
                return NotImplemented

            return self.priority < other.priority


@total_ordering
class OrderBox(Generic[T]):
    def __init__(self, item: T, reverse: bool = False) -> None:
        self._item = item
        self._reverse = reverse

    id10 = ("_item", "_reverse")

    def unbox(self) -> T:
        return self._item

    def id18(self) -> str:
        return f"OrderBox(item={self._item})"

    def id14(self, other) -> bool:
        if not isinstance(other, OrderBox):
            return NotImplemented

        return self._item == other._item

    def id38(self, other) -> bool:
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

    id10 = ("_heap", "_reverse")

    def size(self) -> int:
        return len(self._heap)

    def id8(self) -> bool:
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
PriorityQueue = id0

li = lambda n: cast(list, [None] * n)


def id15(operation: Callable[[T, T], T]) -> T:
    if operation is operator.add:
        return 0
    elif operation is min:
        return inf
    elif operation is max:
        return -inf
    else:
        raise ValueError


class SegmentTree(Generic[T]):
    def __init__(
        self, seq: Sequence[T], operation: Callable[[T, T], T] = operator.add
    ) -> None:
        seq = list(seq) + [id15(operation)] * ((1 << ceil(log2(len(seq)))) - len(seq))

        n = len(seq)

        identity_element = id15(operation)
        self._array = [identity_element] * 2 * n

        idx = 2 * n - 1
        flow_len = (n - (1 << floor(log2(n)))) << 1

        for i in range(flow_len - 1, -1, -1):
            self._array[idx] = seq[i]
            idx -= 1

        for i in range(n - 1, flow_len - 1, -1):
            self._array[idx] = seq[i]
            idx -= 1

        while idx >= 1:
            self._array[idx] = operation(self._array[idx * 2], self._array[idx * 2 + 1])
            idx -= 1

        self._identity_element = identity_element
        self._item_count = n
        self._operation = operation

    id10 = ("_array", "_identity_element", "_item_count", "_operation")

    def query(self, l: int, r: int) -> T:
        if not (0 <= l <= r <= self._item_count - 1):
            raise ValueError("Invalid indices")

        def helper(pos: int, x: int, y: int) -> T:
            if l <= x <= y <= r:
                return self._array[pos]

            res = self._identity_element
            mid = (x + y) // 2
            if r >= x and l <= mid:
                res = self._operation(res, helper(pos * 2, x, mid))
            if r >= mid + 1 and l <= y:
                res = self._operation(res, helper(pos * 2 + 1, mid + 1, y))
            return res

        return helper(1, 0, self._item_count - 1)

    def update(self, index: int, delta: T)->None:
        if not (0 <= index <= self._item_count - 1):
            raise ValueError("Invalid index")

        def helper(pos: int, x: int, y: int)->None:
            self._array[pos] += delta

            mid = (x + y) // 2
            if x == y == index:
                return
            elif x <= index <= mid:
                helper(pos * 2, x, mid)
            else:
                helper(pos * 2 + 1, mid + 1, y)

        helper(1, 0, self._item_count - 1)

    def range_update(self, l:int, r: int, delta: T)->None:
        

        raise NotImplementedError


if (sys.version_info.major, sys.version_info.minor) >= (3, 7):

    from dataclasses import dataclass

    @dataclass
    class id5(Generic[T]):
        item: T
        parent: "id5[T]"
        rank: int = 0


else:

    class id5(Generic[T]):
        def __init__(self, item: T, parent: "id5[T]", rank: int = 0) -> None:
            self.item = item
            self.parent = parent
            self.rank = rank

        id10 = ("item", "parent", "rank")

        def id18(self) -> str:
            return f"id5(item={self.item}, parent={self.parent}, rank={self.rank})"


class UnionFind(Generic[T]):
    def __init__(self):
        self._table = {}  
        self._size = 0

    id10 = ("_table", "_size")

    def size(self) -> int:
        return self._size

    def id8(self) -> bool:
        return bool(self._size)

    def add(self, item: T) -> None:
        if item in self._table:
            return

        node = id5(item, parent=None)  
        node.parent = node

        self._table[item] = node
        self._size += 1

    def _find_set(self, item: T) -> id5[T]:
        if item not in self._table:
            raise ValueError(f"{item} not in UnionFind")

        node = self._table[item]
        path = []

        while node.parent != node:
            path.append(node)
            node = node.parent

        for descendant in path:
            descendant.parent = node

        return node

    def union(self, item1: T, item2: T) -> None:
        if item1 not in self._table:
            self.add(item1)
        if item2 not in self._table:
            self.add(item2)

        set1 = self._find_set(item1)
        set2 = self._find_set(item2)

        if set1 == set2:
            return

        rank1 = set1.rank
        rank2 = set2.rank

        if rank1 == rank2:
            set2.parent = set1
            set1.rank += 1

        elif rank1 > rank2:
            set2.parent = set1

        else:
            set1.parent = set2









































































































def solve() -> None:
    n = re()
    a = rl()

    st = SegmentTree(a, operation=max)

    def helper(l: int, r: int, depth: int)->None:
        if l > r:
            return

        max_num = st.query(l, r)
        res[indexer[max_num]] = depth
        idx = indexer[max_num]
        helper(l, idx -1, depth + 1)
        helper(idx + 1, r, depth + 1)

    indexer = {num: i for i, num in enu(a)}
    res = li(n)
    helper(0, n - 1, 0)

    ps(*res)


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
    
