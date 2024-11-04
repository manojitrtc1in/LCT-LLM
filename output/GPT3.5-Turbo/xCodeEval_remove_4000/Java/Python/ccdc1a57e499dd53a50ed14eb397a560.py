import random
from collections.abc import MutableMapping
from typing import Optional, Tuple, TypeVar

K = TypeVar('K')
V = TypeVar('V')

class id11(MutableMapping[K, V]):
    class HashEntry:
        def __init__(self, key: K, value: V) -> None:
            self.key = key
            self.value = value
            self.next: Optional[id11.HashEntry] = None

    def __init__(self, maxSize: int = 4) -> None:
        self.size = 0
        self.capacity = 0
        self.data: Optional[List[Optional[id11.HashEntry]]] = None
        self.entrySet = set()
        self.setCapacity(maxSize)

    def setCapacity(self, size: int) -> None:
        self.capacity = 1 << (size.bit_length() + 2)
        self.data = [None] * self.capacity

    def index(self, o: object) -> int:
        return self.getHash(hash(o)) & (self.capacity - 1)

    def getHash(self, h: int) -> int:
        result = h
        for i in [1 + 3 * i + random.randint(0, 2) for i in range(10)]:
            result ^= h >> i
        return result

    def remove(self, o: object) -> Optional[V]:
        if o is None:
            return None
        index = self.index(o)
        current = self.data[index]
        last = None
        while current is not None:
            if current.key == o:
                if last is None:
                    self.data[index] = current.next
                else:
                    last.next = current.next
                self.size -= 1
                return current.value
            last = current
            current = current.next
        return None

    def put(self, e: K, value: V) -> Optional[V]:
        if e is None:
            return None
        index = self.index(e)
        current = self.data[index]
        if current is not None:
            while True:
                if current.key == e:
                    oldValue = current.value
                    current.value = value
                    return oldValue
                if current.next is None:
                    break
                current = current.next
        if current is None:
            self.data[index] = id11.HashEntry(e, value)
        else:
            current.next = id11.HashEntry(e, value)
        self.size += 1
        if 2 * self.size > self.capacity:
            oldData = self.data
            self.setCapacity(self.size)
            for entry in oldData:
                while entry is not None:
                    next = entry.next
                    index = self.index(entry.key)
                    entry.next = self.data[index]
                    self.data[index] = entry
                    entry = next
        return None

    def get(self, o: object) -> Optional[V]:
        if o is None:
            return None
        index = self.index(o)
        current = self.data[index]
        while current is not None:
            if current.key == o:
                return current.value
            current = current.next
        return None

    def __getitem__(self, key: K) -> V:
        value = self.get(key)
        if value is None:
            raise KeyError(key)
        return value

    def __setitem__(self, key: K, value: V) -> None:
        self.put(key, value)

    def __delitem__(self, key: K) -> None:
        self.remove(key)

    def __iter__(self):
        return iter(self.entrySet)

    def __len__(self) -> int:
        return self.size

    def __contains__(self, key: object) -> bool:
        return self.get(key) is not None

    def __repr__(self) -> str:
        return repr(dict(self.items()))
