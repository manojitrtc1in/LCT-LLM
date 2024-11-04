import sys
from typing import List

class TaskE:
    def solve(self, r: int, c: int, n: int, k: int, x: List[int], y: List[int]) -> int:
        x = [xi - 1 for xi in x]
        y = [yi - 1 for yi in y]
        yx = sorted(zip(y, x))
        head_position = [Position(-1, -1) for _ in range(k)]
        tail_position = [Position(r, -2) for _ in range(k)]
        for i in range(1, k):
            head_position[i].last = head_position[i - 1]
            head_position[i - 1].next = head_position[i]
        for i in range(1, k):
            tail_position[i].last = tail_position[i - 1]
            tail_position[i - 1].next = tail_position[i]
        positions = [Position(xi, i) for i, xi in enumerate(x)]
        answer = 0
        at = 0
        for i in range(c):
            while at < n and yx[at][0] < i:
                at += 1
            for j in range(k - 1):
                head_position[j + 1].link = tail_position[j]
            linked_set = LinkedSet()
            linked_set.add(head_position[k - 1])
            linked_set.add(tail_position[0])
            head_position[k - 1].next = tail_position[0]
            tail_position[0].last = head_position[k - 1]
            delta = 0
            for j in range(i, c):
                while at < n and yx[at][0] == j:
                    where = linked_set.lower(positions[yx[at][1]])
                    current = where
                    for l in range(1, k):
                        delta -= current.value(r)
                        current = current.last
                    next_pos = where.next
                    delta -= next_pos.value(r)
                    current = positions[yx[at][1]]
                    where.next = current
                    current.last = where
                    next_pos.last = current
                    current.next = next_pos
                    current.link = current if k == 1 else where.link
                    linked_set.add(current)
                    delta += next_pos.value(r)
                    delta += current.value(r)
                    current = where
                    for l in range(1, k):
                        current.link = current.link.last
                        delta += current.value(r)
                        current = current.last
                    at += 1
                answer += delta
        return answer

class Position:
    def __init__(self, row: int, id: int):
        self.row = row
        self.id = id
        self.last = None
        self.next = None
        self.link = None
    
    def __lt__(self, other):
        if self.row != other.row:
            return self.row < other.row
        return self.id < other.id
    
    def value(self, r: int) -> int:
        if self.link is None:
            return 0
        return (self.row - self.last.row) * (r - self.link.row)

class LinkedSet:
    def __init__(self):
        self.head = Position(-1, -1)
        self.tail = Position(-2, -2)
        self.head.next = self.tail
        self.tail.last = self.head
    
    def add(self, position: Position):
        position.last = self.tail.last
        position.next = self.tail
        self.tail.last.next = position
        self.tail.last = position
    
    def lower(self, position: Position) -> Position:
        current = self.head.next
        while current != self.tail and current < position:
            current = current.next
        return current

def main():
    r, c, n, k = map(int, sys.stdin.readline().split())
    x = [0] * n
    y = [0] * n
    for i in range(n):
        x[i], y[i] = map(int, sys.stdin.readline().split())
    solver = TaskE()
    answer = solver.solve(r, c, n, k, x, y)
    sys.stdout.write(str(answer))

if __name__ == "__main__":
    main()
