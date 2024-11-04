import sys
from typing import List, Tuple, Dict, Any

class C:
    def __init__(self):
        self.MODULO = 1000 * 1000 * 1000 + 7

    def solve(self) -> None:
        MAX_T = 1000 * 1000 * 1000

        q = self.readInt()
        queries = []
        for _ in range(q):
            query_type = self.readInt()
            if query_type == 1:
                queries.append((1, self.readInt(), self.readInt()))
            elif query_type == 2:
                queries.append((2, self.readInt()))
            else:
                queries.append((3, self.readInt(), self.readInt(), self.readInt()))

        mapper = SortedIdMapper()
        mapper.add_value(0)
        mapper.add_value(MAX_T + 1)

        for query in queries:
            mapper.add_value(query[1])
            if query[0] == 3:
                mapper.add_value(query[2])

        ids = mapper.build()
        times = list(mapper.values)

        min_time = ids.get_id(0)
        max_time = ids.get_id(MAX_T + 1)

        time_speeds = {}

        time_speeds[min_time] = 0
        time_speeds[max_time] = 0

        for query in queries:
            query[1] = ids.get_id(query[1])
            if query[0] == 3:
                query[2] = ids.get_id(query[2])

        tree = SegmentTree(ids.size())

        for query in queries:
            query_type = query[0]
            if query_type == 1:
                time = query[1]
                real_time = times[time]
                speed = query[2]

                entry_before = self.lower_entry(time_speeds, time)

                time_after = self.higher_key(time_speeds, time)
                real_time_after = times[time_after]

                time_before = entry_before[0]
                real_time_before = times[time_before]
                speed_before = entry_before[1]

                tree.update_index(time_before, speed_before * (real_time - real_time_before))
                tree.update_index(time, speed * (real_time_after - real_time))

                time_speeds[time] = speed
            elif query_type == 2:
                time = query[1]
                real_time = times[time]

                entry_before = self.lower_entry(time_speeds, time)

                time_after = self.higher_key(time_speeds, time)
                real_time_after = times[time_after]

                time_before = entry_before[0]
                real_time_before = times[time_before]

                speed_before = entry_before[1]

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

                        time_after = min(end, self.higher_key(time_speeds, time))
                        real_time_after = times[time_after]

                        delta = real_time_after - real_time
                        total = delta * speed

                        if value + total > 0:
                            print(-1)
                        else:
                            bad_time = real_time + value / abs(speed)
                            print(bad_time)

    def lower_entry(self, time_speeds: Dict[int, int], time: int) -> Tuple[int, int]:
        keys = sorted(time_speeds.keys())
        for key in keys:
            if key >= time:
                return (key, time_speeds[key])
        return (0, 0)

    def higher_key(self, time_speeds: Dict[int, int], time: int) -> int:
        keys = sorted(time_speeds.keys())
        for key in keys:
            if key > time:
                return key
        return 0

    def readInt(self) -> int:
        return int(input())

    def run(self) -> None:
        self.solve()

class SegmentTree:
    def __init__(self, n: int) -> None:
        self.size = n
        tree_size = n << 2
        self.sums = [0] * tree_size
        self.mins = [0] * tree_size

    def update_index(self, index: int, value: int) -> None:
        self.index = index
        self.value = value
        self.update_tree_index(1, 0, self.size)

    def update_tree_index(self, v: int, left: int, right: int) -> None:
        if left + 1 == right:
            self.sums[v] = self.value
            self.mins[v] = min(0, self.value)
        else:
            mid = (left + right) >> 1
            v_left = v << 1
            v_right = v_left + 1

            if self.index < mid:
                self.update_tree_index(v_left, left, mid)
            else:
                self.update_tree_index(v_right, mid, right)

            self.update_vertex(v, v_left, v_right)

    def update_vertex(self, v: int, v_left: int, v_right: int) -> None:
        self.sums[v] = self.sums[v_left] + self.sums[v_right]
        self.mins[v] = min(self.mins[v_left], self.sums[v_left] + self.mins[v_right])

    def get_interval(self, start: int, end: int, value: int) -> int:
        self.start = start
        self.end = end
        self.value = value
        self.found = False
        self.found_index = -1
        self.get_tree_interval(1, 0, self.size)
        return self.found_index

    def get_tree_interval(self, v: int, left: int, right: int) -> None:
        if self.start <= left and right <= self.end:
            if not self.found:
                if self.value + self.mins[v] <= 0:
                    self.find_tree_index(v, left, right)
                    self.found = True
                else:
                    self.value += self.sums[v]
        else:
            mid = (left + right) >> 1
            v_left = v << 1
            v_right = v_left + 1

            if self.start < mid:
                self.get_tree_interval(v_left, left, mid)
            if mid < self.end:
                self.get_tree_interval(v_right, mid, right)

    def find_tree_index(self, v: int, left: int, right: int) -> None:
        if left + 1 == right:
            self.found_index = left
        else:
            mid = (left + right) >> 1
            v_left = v << 1
            v_right = v_left + 1

            if self.value + self.mins[v_left] <= 0:
                self.find_tree_index(v_left, left, mid)
            else:
                self.value += self.sums[v_left]
                self.find_tree_index(v_right, mid, right)

class SortedIdMapper:
    def __init__(self) -> None:
        self.values = []

    def add_value(self, value: int) -> None:
        self.values.append(value)

    def build(self) -> Dict[int, int]:
        self.values.sort()

        ids = {}
        unique_values = []

        for value in self.values:
            if len(unique_values) == 0 or unique_values[-1] != value:
                ids[value] = len(ids)
                unique_values.append(value)

        self.values = unique_values

        return ids

if __name__ == "__main__":
    c = C()
    c.run()
