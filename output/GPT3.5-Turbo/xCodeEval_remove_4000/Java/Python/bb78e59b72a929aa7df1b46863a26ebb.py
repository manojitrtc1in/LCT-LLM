import sys
from collections import defaultdict
from bisect import bisect_left, bisect_right

MODULO = 1000 * 1000 * 1000 + 7

class SegmentTree:
    def __init__(self, n):
        self.size = n
        self.sums = [0] * (4 * n)
        self.mins = [0] * (4 * n)

    def updateIndex(self, index, value):
        self.index = index
        self.value = value
        self._update(1, 0, self.size)

    def _update(self, v, left, right):
        if left + 1 == right:
            self.sums[v] = self.value
            self.mins[v] = min(0, self.value)
        else:
            mid = (left + right) // 2
            vLeft = 2 * v
            vRight = vLeft + 1

            if self.index < mid:
                self._update(vLeft, left, mid)
            else:
                self._update(vRight, mid, right)

            self._updateVertex(v, vLeft, vRight)

    def _updateVertex(self, v, vLeft, vRight):
        self.sums[v] = self.sums[vLeft] + self.sums[vRight]
        self.mins[v] = min(self.mins[vLeft], self.sums[vLeft] + self.mins[vRight])

    def getInterval(self, start, end, value):
        self.start = start
        self.end = end
        self.value = value
        self.found = False
        self.foundIndex = -1
        self._find(1, 0, self.size)
        return self.foundIndex

    def _find(self, v, left, right):
        if self.start <= left and right <= self.end:
            if not self.found:
                if self.value + self.mins[v] <= 0:
                    self._findIndex(v, left, right)
                    self.found = True
                else:
                    self.value += self.sums[v]
        else:
            mid = (left + right) // 2
            vLeft = 2 * v
            vRight = vLeft + 1

            if self.start < mid:
                self._find(vLeft, left, mid)
            if mid < self.end:
                self._find(vRight, mid, right)

    def _findIndex(self, v, left, right):
        if left + 1 == right:
            self.foundIndex = left
        else:
            mid = (left + right) // 2
            vLeft = 2 * v
            vRight = vLeft + 1

            if self.value + self.mins[vLeft] <= 0:
                self._findIndex(vLeft, left, mid)
            else:
                self.value += self.sums[vLeft]
                self._findIndex(vRight, mid, right)

class C:
    def __init__(self):
        self.inp = sys.stdin
        self.out = sys.stdout
        self.tok = iter(self.inp.read().split())

    def readString(self):
        return next(self.tok)

    def readInt(self):
        return int(self.readString())

    def readLong(self):
        return int(self.readString())

    def readDouble(self):
        return float(self.readString())

    def readPoint(self):
        x = self.readInt()
        y = self.readInt()
        return (x, y)

    def solve(self):
        MAX_T = 1000 * 1000 * 1000

        q = self.readInt()
        queries = []
        for _ in range(q):
            type = self.readInt()
            if type == 1:
                queries.append([1, self.readInt(), self.readInt()])
            elif type == 2:
                queries.append([2, self.readInt()])
            else:
                queries.append([3, self.readInt(), self.readInt(), self.readInt()])

        mapper = defaultdict(int)
        mapper[0]
        mapper[MAX_T + 1]

        for query in queries:
            mapper[query[1]]
            if query[0] == 3:
                mapper[query[2]]

        ids = sorted(mapper.values())
        times = [0] * len(ids)
        for i, val in enumerate(ids):
            times[i] = val

        minTime = ids.index(0)
        maxTime = ids.index(MAX_T + 1)

        id33 = {}
        id33[minTime] = 0
        id33[maxTime] = 0

        for query in queries:
            query[1] = ids.index(query[1])
            if query[0] == 3:
                query[2] = ids.index(query[2])

        tree = SegmentTree(len(ids))

        for query in queries:
            type = query[0]
            if type == 1:
                time = query[1]
                realTime = times[time]
                speed = query[2]

                timeBefore = bisect_right(ids, time) - 1
                timeAfter = bisect_left(ids, time)
                id10 = times[timeAfter]

                timeBefore = bisect_right(ids, timeBefore) - 1
                id38 = times[timeBefore]
                speedBefore = id33[timeBefore]

                tree.updateIndex(timeBefore, speedBefore * (realTime - id38))
                tree.updateIndex(time, speed * (id10 - realTime))

                id33[time] = speed
            elif type == 2:
                time = query[1]
                realTime = times[time]

                timeBefore = bisect_right(ids, time) - 1
                timeAfter = bisect_left(ids, time)
                id10 = times[timeAfter]

                timeBefore = bisect_right(ids, timeBefore) - 1
                id38 = times[timeBefore]
                speedBefore = id33[timeBefore]

                tree.updateIndex(timeBefore, speedBefore * (id10 - id38))
                tree.updateIndex(time, 0)

                del id33[time]
            else:
                start = query[1]
                end = query[2]
                value = query[3]

                foundIndex = tree.getInterval(start, end, value)
                if foundIndex == -1:
                    self.out.write("-1\n")
                else:
                    value = tree.value

                    time = foundIndex
                    realTime = times[time]

                    if value == 0:
                        self.out.write(str(realTime) + "\n")
                    else:
                        speed = id33.get(time, -1)

                        timeAfter = min(end, bisect_left(ids, time))
                        id10 = times[timeAfter]

                        delta = id10 - realTime
                        total = delta * speed

                        if value + total > 0:
                            self.out.write("-1\n")
                        else:
                            badTime = realTime + value / abs(speed)
                            self.out.write(str(badTime) + "\n")

    def run(self):
        self.solve()

if __name__ == "__main__":
    C().run()
