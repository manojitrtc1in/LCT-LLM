import sys
import random
from collections import defaultdict
from bisect import bisect_left, bisect_right

MODULO = 1000 * 1000 * 1000 + 7

class SegmentTree:
    def __init__(self, n):
        self.size = n
        self.sums = [0] * (4 * n)
        self.mins = [0] * (4 * n)

    def update_index(self, index, value):
        self.index = index
        self.value = value
        self._update_tree_index(1, 0, self.size)

    def _update_tree_index(self, v, left, right):
        if left + 1 == right:
            self.sums[v] = self.value
            self.mins[v] = min(0, self.value)
        else:
            mid = (left + right) // 2
            v_left = v * 2
            v_right = v_left + 1

            if self.index < mid:
                self._update_tree_index(v_left, left, mid)
            else:
                self._update_tree_index(v_right, mid, right)

            self._update_vertex(v, v_left, v_right)

    def _update_vertex(self, v, v_left, v_right):
        self.sums[v] = self.sums[v_left] + self.sums[v_right]
        self.mins[v] = min(self.mins[v_left], self.sums[v_left] + self.mins[v_right])

    def get_interval(self, start, end, value):
        self.start = start
        self.end = end
        self.value = value
        self.found = False
        self.found_index = -1
        self._get_tree_interval(1, 0, self.size)
        return self.found_index

    def _get_tree_interval(self, v, left, right):
        if self.start <= left and right <= self.end:
            if not self.found:
                if self.value + self.mins[v] <= 0:
                    self._find_tree_index(v, left, right)
                    self.found = True
                else:
                    self.value += self.sums[v]
        else:
            mid = (left + right) // 2
            v_left = v * 2
            v_right = v_left + 1

            if self.start < mid:
                self._get_tree_interval(v_left, left, mid)
            if mid < self.end:
                self._get_tree_interval(v_right, mid, right)

    def _find_tree_index(self, v, left, right):
        if left + 1 == right:
            self.found_index = left
        else:
            mid = (left + right) // 2
            v_left = v * 2
            v_right = v_left + 1

            if self.value + self.mins[v_left] <= 0:
                self._find_tree_index(v_left, left, mid)
            else:
                self.value += self.sums[v_left]
                self._find_tree_index(v_right, mid, right)

class IdMap(defaultdict):
    def __init__(self):
        super().__init__(int)

    def register(self, key):
        if key not in self:
            self[key] = len(self)
        return self[key]

class SortedIdMapper:
    def __init__(self):
        self.values = []

    def add_value(self, value):
        self.values.append(value)

    def build(self):
        self.values = sorted(set(self.values))
        ids = IdMap()
        for value in self.values:
            ids.register(value)
        return ids

def read_int():
    return int(sys.stdin.readline().strip())

def read_int_array(size):
    return list(map(int, sys.stdin.readline().strip().split()))

def solve():
    MAX_T = 1000 * 1000 * 1000
    q = read_int()
    queries = []
    for _ in range(q):
        query = list(map(int, sys.stdin.readline().strip().split()))
        queries.append(query)

    mapper = SortedIdMapper()
    mapper.add_value(0)
    mapper.add_value(MAX_T + 1)

    for query in queries:
        mapper.add_value(query[1])
        if query[0] == 3:
            mapper.add_value(query[2])

    ids = mapper.build()
    times = list(mapper.values)

    min_time = ids[0]
    max_time = ids[MAX_T + 1]

    time_speeds = {min_time: 0, max_time: 0}

    for query in queries:
        query[1] = ids[query[1]]
        if query[0] == 3:
            query[2] = ids[query[2]]

    tree = SegmentTree(len(ids))

    for query in queries:
        type_query = query[0]
        if type_query == 1:
            time = query[1]
            real_time = times[time]
            speed = query[2]

            entry_before = max(k for k in time_speeds if k < time)
            time_after = min(k for k in time_speeds if k > time)
            real_time_after = times[time_after]

            time_before = entry_before
            real_time_before = times[time_before]
            speed_before = time_speeds[entry_before]

            tree.update_index(time_before, speed_before * (real_time - real_time_before))
            tree.update_index(time, speed * (real_time_after - real_time))

            time_speeds[time] = speed
        elif type_query == 2:
            time = query[1]
            real_time = times[time]

            entry_before = max(k for k in time_speeds if k < time)
            time_after = min(k for k in time_speeds if k > time)
            real_time_after = times[time_after]

            time_before = entry_before
            real_time_before = times[time_before]
            speed_before = time_speeds[entry_before]

            tree.update_index(time_before, speed_before * (real_time_after - real_time_before))
            tree.update_index(time, 0)

            del time_speeds[time]
        else:
            start = query[1]
            end = query[2]
            value = query[3]

            found_index = tree.get_interval(start, end, value)
            if found_index == -1:
                print(-1)
            else:
                value = tree.value

                time = found_index
                real_time = times[time]

                if value == 0:
                    print(real_time)
                else:
                    speed = time_speeds.get(time, -1)

                    time_after = min(end, min(k for k in time_speeds if k > time))
                    real_time_after = times[time_after]

                    delta = real_time_after - real_time
                    total = delta * speed

                    if value + total > 0:
                        print(-1)
                    else:
                        bad_time = real_time + value / abs(speed)
                        print(bad_time)

def main():
    solve()

if __name__ == "__main__":
    main()
