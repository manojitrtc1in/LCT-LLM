import sys
from collections import defaultdict
from typing import List, Tuple

MODULO = 1000 * 1000 * 1000 + 7


class SegmentTree:
    def __init__(self, n: int):
        self.size = n
        self.sums = [0] * (n << 2)
        self.mins = [0] * (n << 2)
        self.index = 0
        self.value = 0

    def update_index(self, index: int, value: int):
        self.index = index
        self.value = value
        self.id26(1, 0, self.size)

    def id26(self, v: int, left: int, right: int):
        if left + 1 == right:
            self.sums[v] = self.value
            self.mins[v] = min(0, self.value)
        else:
            mid = (left + right) >> 1
            v_left = (v << 1)
            v_right = v_left + 1

            if self.index < mid:
                self.id26(v_left, left, mid)
            else:
                self.id26(v_right, mid, right)

            self.update_vertex(v, v_left, v_right)

    def update_vertex(self, v: int, v_left: int, v_right: int):
        self.sums[v] = self.sums[v_left] + self.sums[v_right]
        self.mins[v] = min(self.mins[v_left], self.sums[v_left] + self.mins[v_right])

    def get_interval(self, start: int, end: int, value: int) -> int:
        self.start = start
        self.end = end
        self.value = value
        self.found = False
        self.found_index = -1
        self.id12(1, 0, self.size)
        return self.found_index

    def id12(self, v: int, left: int, right: int):
        if self.start <= left and right <= self.end:
            if not self.found:
                if self.value + self.mins[v] <= 0:
                    self.id19(v, left, right)
                    self.found = True
                else:
                    self.value += self.sums[v]
        else:
            mid = (left + right) >> 1
            v_left = (v << 1)
            v_right = v_left + 1

            if self.start < mid:
                self.id12(v_left, left, mid)
            if mid < self.end:
                self.id12(v_right, mid, right)

    def id19(self, v: int, left: int, right: int):
        if left + 1 == right:
            self.found_index = left
        else:
            mid = (left + right) >> 1
            v_left = (v << 1)
            v_right = v_left + 1

            if self.value + self.mins[v_left] <= 0:
                self.id19(v_left, left, mid)
            else:
                self.value += self.sums[v_left]
                self.id19(v_right, mid, right)


def solve() -> None:
    MAX_T = 1000 * 1000 * 1000

    def read_int() -> int:
        return int(input())

    def read_ints() -> Tuple[int, int]:
        return tuple(map(int, input().split()))

    def read_int_list() -> List[int]:
        return list(map(int, input().split()))

    def read_query() -> Tuple[int, int, int, int]:
        return tuple(map(int, input().split()))

    q = read_int()
    queries = []
    for _ in range(q):
        query_type = read_int()
        if query_type == 1:
            queries.append((1, read_int(), read_int()))
        elif query_type == 2:
            queries.append((2, read_int()))
        else:
            queries.append((3, read_int(), read_int(), read_int()))

    mapper = defaultdict(int)
    mapper[0]
    mapper[MAX_T + 1]

    for query in queries:
        mapper[query[1]]
        if query[0] == 3:
            mapper[query[2]]

    ids = {value: index for index, value in enumerate(sorted(mapper))}
    times = list(ids.keys())

    min_time = ids[0]
    max_time = ids[MAX_T + 1]

    id33 = {min_time: 0, max_time: 0}

    for query in queries:
        query[1] = ids[query[1]]
        if query[0] == 3:
            query[2] = ids[query[2]]

    tree = SegmentTree(len(ids))

    for query in queries:
        query_type = query[0]
        if query_type == 1:
            time = query[1]
            real_time = times[time]
            speed = query[2]

            entry_before = max(id33.items(), key=lambda x: x[0] < time)
            time_after = min(id33.keys(), key=lambda x: x > time)
            id10 = times[time_after]

            time_before = entry_before[0]
            id38 = times[time_before]
            speed_before = entry_before[1]

            tree.update_index(time_before, speed_before * (real_time - id38))
            tree.update_index(time, speed * (id10 - real_time))

            id33[time] = speed
        elif query_type == 2:
            time = query[1]
            real_time = times[time]

            entry_before = max(id33.items(), key=lambda x: x[0] < time)
            time_after = min(id33.keys(), key=lambda x: x > time)
            id10 = times[time_after]

            time_before = entry_before[0]
            id38 = times[time_before]
            speed_before = entry_before[1]

            tree.update_index(time_before, speed_before * (id10 - id38))
            tree.update_index(time, 0)

            del id33[time]
        else:
            start, end, value = query[1], query[2], query[3]

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
                    speed = id33.get(time, -1)

                    time_after = min(end, min(id33.keys(), key=lambda x: x > time))
                    id10 = times[time_after]

                    delta = id10 - real_time
                    total = delta * speed

                    if value + total > 0:
                        print(-1)
                    else:
                        bad_time = real_time + value / abs(speed)
                        print(bad_time)


if __name__ == "__main__":
    solve()
