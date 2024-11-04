import random
from collections.abc import MutableSet
from typing import Optional, Tuple, TypeVar, Generic, List, Union, Iterable, Collection

K = TypeVar('K')
V = TypeVar('V')


class TreapSet(MutableSet[K]):
    class Node(Generic[K]):
        def __init__(self, key: K, priority: int) -> None:
            self.key = key
            self.priority = priority
            self.left: Optional[TreapSet.Node[K]] = None
            self.right: Optional[TreapSet.Node[K]] = None

    def __init__(self, iterable: Optional[Iterable[K]] = None, key: Optional[Callable[[K], int]] = None) -> None:
        self.root: Optional[TreapSet.Node[K]] = None
        self.key = key if key else lambda x: x
        self.size = 0
        if iterable:
            self |= iterable

    def __contains__(self, key: object) -> bool:
        node = self.root
        while node:
            if self.key(node.key) == self.key(key):
                return True
            if self.key(node.key) > self.key(key):
                node = node.left
            else:
                node = node.right
        return False

    def __iter__(self) -> Iterator[K]:
        stack = []
        node = self.root
        while stack or node:
            if node:
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                yield node.key
                node = node.right

    def __len__(self) -> int:
        return self.size

    def add(self, key: K) -> None:
        priority = random.randint(0, 1 << 30)
        node = TreapSet.Node(key, priority)
        if not self.root:
            self.root = node
            self.size += 1
            return
        stack = []
        current = self.root
        while True:
            stack.append(current)
            if self.key(current.key) == self.key(key):
                return
            if self.key(current.key) > self.key(key):
                if not current.left:
                    current.left = node
                    self.size += 1
                    self._rebalance(stack)
                    return
                current = current.left
            else:
                if not current.right:
                    current.right = node
                    self.size += 1
                    self._rebalance(stack)
                    return
                current = current.right

    def discard(self, key: K) -> None:
        stack = []
        current = self.root
        while current:
            if self.key(current.key) == self.key(key):
                break
            stack.append(current)
            if self.key(current.key) > self.key(key):
                current = current.left
            else:
                current = current.right
        else:
            return
        self.size -= 1
        self._rebalance(stack)
        if not current.left and not current.right:
            if not stack:
                self.root = None
            elif stack[-1].left is current:
                stack[-1].left = None
            else:
                stack[-1].right = None
        elif current.left and current.right:
            if random.randint(0, 1):
                stack.append(current)
                node = current.left
                while node.right:
                    stack.append(node)
                    node = node.right
                current.key = node.key
                if node.left:
                    if stack[-1].left is node:
                        stack[-1].left = node.left
                    else:
                        stack[-1].right = node.left
                else:
                    if stack[-1].left is node:
                        stack[-1].left = None
                    else:
                        stack[-1].right = None
            else:
                stack.append(current)
                node = current.right
                while node.left:
                    stack.append(node)
                    node = node.left
                current.key = node.key
                if node.right:
                    if stack[-1].left is node:
                        stack[-1].left = node.right
                    else:
                        stack[-1].right = node.right
                else:
                    if stack[-1].left is node:
                        stack[-1].left = None
                    else:
                        stack[-1].right = None
        else:
            if stack[-1].left is current:
                stack[-1].left = current.left or current.right
            else:
                stack[-1].right = current.left or current.right

    def _rebalance(self, path: List[TreapSet.Node[K]]) -> None:
        while path:
            current = path.pop()
            if current.left and current.left.priority > current.priority:
                self._rotate_right(path, current)
            elif current.right and current.right.priority > current.priority:
                self._rotate_left(path, current)

    def _rotate_right(self, path: List[TreapSet.Node[K]], node: TreapSet.Node[K]) -> None:
        if not path:
            self.root = node.left
        elif path[-1].left is node:
            path[-1].left = node.left
        else:
            path[-1].right = node.left
        node.left, node.left.right = node.left.right, node

    def _rotate_left(self, path: List[TreapSet.Node[K]], node: TreapSet.Node[K]) -> None:
        if not path:
            self.root = node.right
        elif path[-1].left is node:
            path[-1].left = node.right
        else:
            path[-1].right = node.right
        node.right, node.right.left = node.right.left, node

    def __repr__(self) -> str:
        return '{' + ', '.join(map(repr, self)) + '}'

    def __eq__(self, other: object) -> bool:
        if isinstance(other, TreapSet):
            return len(self) == len(other) and all(a == b for a, b in zip(self, other))
        return super().__eq__(other)

    def __getitem__(self, item: Union[int, slice]) -> Union[K, 'TreapSet[K]']:
        if isinstance(item, int):
            if item < 0:
                item += len(self)
            if not 0 <= item < len(self):
                raise IndexError('Index out of range')
            for i, value in enumerate(self):
                if i == item:
                    return value
        elif isinstance(item, slice):
            start, stop, step = item.indices(len(self))
            if step == 1 and start == 0 and stop == len(self):
                return self
            return TreapSet(itertools.islice(self, start, stop, step))
        else:
            raise TypeError('Invalid argument type')

    def __setitem__(self, key: K, value: V) -> None:
        self.add(key)

    def __delitem__(self, key: K) -> None:
        self.discard(key)

    def __reversed__(self) -> Iterator[K]:
        return iter(self)[::-1]

    def __and__(self, other: Collection[K]) -> 'TreapSet[K]':
        return TreapSet(value for value in self if value in other)

    def __or__(self, other: Collection[K]) -> 'TreapSet[K]':
        return TreapSet(itertools.chain(self, other))

    def __sub__(self, other: Collection[K]) -> 'TreapSet[K]':
        return TreapSet(value for value in self if value not in other)

    def __xor__(self, other: Collection[K]) -> 'TreapSet[K]':
        return TreapSet(itertools.chain(self - other, other - self))

    def __ior__(self, other: Collection[K]) -> 'TreapSet[K]':
        self |= other
        return self

    def __iand__(self, other: Collection[K]) -> 'TreapSet[K]':
        self &= other
        return self

    def __isub__(self, other: Collection[K]) -> 'TreapSet[K]':
        self -= other
        return self

    def __ixor__(self, other: Collection[K]) -> 'TreapSet[K]':
        self ^= other
        return self

    def __contains__(self, item: object) -> bool:
        return item in self

    def __len__(self) -> int:
        return len(self)

    def __iter__(self) -> Iterator[K]:
        return iter(self)

    def __repr__(self) -> str:
        return repr(self)


class EHashMap(Generic[K, V], MutableMapping[K, V]):
    def __init__(self, iterable: Optional[Iterable[Tuple[K, V]]] = None) -> None:
        self.data: List[List[Tuple[K, V]]] = [[] for _ in range(16)]
        self.size = 0
        if iterable:
            self.update(iterable)

    def __getitem__(self, key: K) -> V:
        index = hash(key) & (len(self.data) - 1)
        for k, v in self.data[index]:
            if k == key:
                return v
        raise KeyError(key)

    def __setitem__(self, key: K, value: V) -> None:
        index = hash(key) & (len(self.data) - 1)
        for i, (k, v) in enumerate(self.data[index]):
            if k == key:
                self.data[index][i] = (key, value)
                break
        else:
            self.data[index].append((key, value))
            self.size += 1
            if self.size > len(self.data) * 3:
                self._resize()

    def __delitem__(self, key: K) -> None:
        index = hash(key) & (len(self.data) - 1)
        for i, (k, v) in enumerate(self.data[index]):
            if k == key:
                self.data[index].pop(i)
                self.size -= 1
                return
        raise KeyError(key)

    def __iter__(self) -> Iterator[K]:
        return iter(k for bucket in self.data for k, v in bucket)

    def __len__(self) -> int:
        return self.size

    def _resize(self) -> None:
        new_data: List[List[Tuple[K, V]]] = [[] for _ in range(len(self.data) * 2)]
        for bucket in self.data:
            for k, v in bucket:
                index = hash(k) & (len(new_data) - 1)
                new_data[index].append((k, v))
        self.data = new_data


class IntervalTree:
    def __init__(self, size: int, init: bool = True) -> None:
        self.size = size
        node_count = max(1, 2 ** (size - 1).bit_length() << 1)
        self.data = [0] * node_count
        if init:
            self._init()

    def _init(self, root: int = 0, left: int = 0, right: int = -1) -> None:
        if right == -1:
            right = self.size - 1
        if left == right:
            self._init_leaf(root, left)
        else:
            middle = (left + right) >> 1
            self._init_before(root, left, right, middle)
            self._init(2 * root + 1, left, middle)
            self._init(2 * root + 2, middle + 1, right)
            self._init_after(root, left, right, middle)

    def _init_leaf(self, root: int, index: int) -> None:
        pass

    def _init_before(self, root: int, left: int, right: int, middle: int) -> None:
        pass

    def _init_after(self, root: int, left: int, right: int, middle: int) -> None:
        pass

