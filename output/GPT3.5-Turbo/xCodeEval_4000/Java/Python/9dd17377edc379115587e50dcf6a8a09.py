import sys
from typing import List

class TaskE:
    def solve(self, r: int, c: int, n: int, k: int, x: List[int], y: List[int]) -> int:
        x = [i-1 for i in x]
        y = [i-1 for i in y]
        positions = [Position(x[i], i) for i in range(n)]
        positions.sort()
        headPosition = [Position(-1, -1) for _ in range(k)]
        tailPosition = [Position(r, -2) for _ in range(k)]
        for i in range(1, k):
            headPosition[i].last = headPosition[i-1]
            headPosition[i-1].next = headPosition[i]
        for i in range(1, k):
            tailPosition[i].last = tailPosition[i-1]
            tailPosition[i-1].next = tailPosition[i]
        answer = 0
        for i in range(c):
            at = 0
            while at < n and y[at] < i:
                at += 1
            for j in range(k-1):
                headPosition[j+1].link = tailPosition[j]
            positionsSet = set(positions)
            positionsSet.add(headPosition[k-1])
            positionsSet.add(tailPosition[0])
            headPosition[k-1].next = tailPosition[0]
            tailPosition[0].last = headPosition[k-1]
            delta = 0
            for j in range(i, c):
                while at < n and y[at] == j:
                    where = max(filter(lambda x: x < positions[at], positionsSet))
                    current = where
                    for l in range(1, k):
                        delta -= current.value(r)
                        current = current.last
                    nextPos = where.next
                    delta -= nextPos.value(r)
                    current = positions[at]
                    where.next = current
                    current.last = where
                    nextPos.last = current
                    current.next = nextPos
                    current.link = current if k == 1 else where.link
                    positionsSet.add(current)
                    delta += nextPos.value(r)
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

def main():
    r, c, n, k = map(int, input().split())
    x = [0] * n
    y = [0] * n
    for i in range(n):
        x[i], y[i] = map(int, input().split())
    solver = TaskE()
    answer = solver.solve(r, c, n, k, x, y)
    print(answer)

if __name__ == "__main__":
    main()
