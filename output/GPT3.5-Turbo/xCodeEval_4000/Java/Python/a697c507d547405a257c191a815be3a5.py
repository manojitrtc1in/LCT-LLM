import sys
from typing import List, Tuple
from collections import defaultdict
from bisect import bisect_left, bisect_right

MODULO = 1000 * 1000 * 1000 + 7

class SegmentTree:
    def __init__(self, n: int):
        self.size = n
        self.sums = [0] * (4 * n)
        self.mins = [0] * (4 * n)

    def update_index(self, index: int, value: int):
        self._update_tree_index(1, 0, self.size, index, value)

    def _update_tree_index(self, v: int, left: int, right: int, index: int, value: int):
        if left + 1 == right:
            self.sums[v] = value
            self.mins[v] = min(0, value)
        else:
            mid = (left + right) // 2
            v_left = 2 * v
            v_right = v_left + 1

            if index < mid:
                self._update_tree_index(v_left, left, mid, index, value)
            else:
                self._update_tree_index(v_right, mid, right, index, value)

            self._update_vertex(v, v_left, v_right)

    def _update_vertex(self, v: int, v_left: int, v_right: int):
        self.sums[v] = self.sums[v_left] + self.sums[v_right]
        self.mins[v] = min(self.mins[v_left], self.sums[v_left] + self.mins[v_right])

    def get_interval(self, start: int, end: int, value: int) -> int:
        return self._get_tree_interval(1, 0, self.size, start, end, value)

    def _get_tree_interval(self, v: int, left: int, right: int, start: int, end: int, value: int) -> int:
        if start <= left and right <= end:
            if not self.found:
                if value + self.mins[v] <= 0:
                    self._find_tree_index(v, left, right)
                    self.found = True
                else:
                    value += self.sums[v]
        else:
            mid = (left + right) // 2
            v_left = 2 * v
            v_right = v_left + 1

            if start < mid:
                self._get_tree_interval(v_left, left, mid, start, end, value)
            if mid < end:
                self._get_tree_interval(v_right, mid, right, start, end, value)

    def _find_tree_index(self, v: int, left: int, right: int):
        if left + 1 == right:
            self.found_index = left
        else:
            mid = (left + right) // 2
            v_left = 2 * v
            v_right = v_left + 1

            if self.value + self.mins[v_left] <= 0:
                self._find_tree_index(v_left, left, mid)
            else:
                self.value += self.sums[v_left]
                self._find_tree_index(v_right, mid, right)

class SortedIdMapper:
    def __init__(self):
        self.values = []

    def add_value(self, value: int):
        self.values.append(value)

    def build(self) -> dict:
        self.values.sort()

        ids = {}
        unique_values = []

        for value in self.values:
            if value not in ids:
                ids[value] = len(ids)
                unique_values.append(value)

        self.values = unique_values

        return ids

def solve(q: int, queries: List[Tuple[int, int, int]]) -> None:
    MAX_T = 1000 * 1000 * 1000

    queries = [(type, a, b, c) for type, a, b, c in queries]
    mapper = SortedIdMapper()
    mapper.add_value(0)
    mapper.add_value(MAX_T + 1)

    for query in queries:
        mapper.add_value(query[1])
        if query[0] == 3:
            mapper.add_value(query[2])

    ids = mapper.build()
    times = [0] * len(mapper.values)

    min_time = ids[0]
    max_time = ids[MAX_T + 1]

    time_speeds = defaultdict(int)
    time_speeds[min_time] = 0
    time_speeds[max_time] = 0

    for query in queries:
        query[1] = ids[query[1]]
        if query[0] == 3:
            query[2] = ids[query[2]]

    tree = SegmentTree(len(ids))

    for query in queries:
        type = query[0]
        if type == 1:
            time = query[1]
            real_time = times[time]
            speed = query[2]

            time_before = max(time_speeds.keys(), key=lambda x: x < time)
            real_time_before = times[time_before]
            speed_before = time_speeds[time_before]

            time_after = min(time_speeds.keys(), key=lambda x: x > time)
            real_time_after = times[time_after]

            tree.update_index(time_before, speed_before * (real_time - real_time_before))
            tree.update_index(time, speed * (real_time_after - real_time))

            time_speeds[time] = speed
        elif type == 2:
            time = query[1]
            real_time = times[time]

            time_before = max(time_speeds.keys(), key=lambda x: x < time)
            real_time_before = times[time_before]

            speed_before = time_speeds[time_before]

            tree.update_index(time_before, speed_before * (real_time_after - real_time_before))
            tree.update_index(time, 0)

            del time_speeds[time]
        else:
            start = query[1]
            end = query[2]
            value = query[3]

            if value == 0:
                print(times[start])
                continue

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

                    time_after = min(end, min(time_speeds.keys(), key=lambda x: x > time))
                    real_time_after = times[time_after]

                    delta = real_time_after - real_time
                    total = delta * speed

                    if value + total > 0:
                        print(-1)
                    else:
                        bad_time = real_time + value / abs(speed)
                        print(bad_time)

def from_input_string(input_string: str) -> Tuple[int, List[Tuple[int, int, int]]]:
    lines = input_string.strip().split('\n')
    q = int(lines[0])
    queries = []
    for line in lines[1:]:
        query = tuple(map(int, line.split()))
        queries.append(query)
    return q, queries

def to_input_string(inputs: Tuple[int, List[Tuple[int, int, int]]]) -> str:
    q, queries = inputs
    res = []
    res.append(str(q))
    for query in queries:
        res.append(' '.join(str(x) for x in query))
    return '\n'.join(res)

def from_output_string(output_string: str) -> None:
    return None

def to_output_string(output: None) -> str:
    return ''

def main():
    input_str = sys.stdin.read()
    inputs = from_input_string(input_str)
    output = solve(*inputs)
    output_str = to_output_string(output)
    sys.stdout.write(output_str)

if __name__ == '__main__':
    main()
