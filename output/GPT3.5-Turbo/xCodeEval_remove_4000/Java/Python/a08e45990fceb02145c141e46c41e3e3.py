import random
import sys
from collections import defaultdict
from typing import List, Set, Tuple


def solve() -> None:
    n, m = map(int, input().split())

    id33 = [True] * n

    class Event:
        def __init__(self, event_type: str, index: int):
            self.enter = event_type == "+"
            self.index = index

    input_events = []
    for _ in range(m):
        event_type, index = input().split()
        input_events.append(Event(event_type, int(index) - 1))

    id16 = 0

    was_before = set()
    used = [False] * n
    for input_event in input_events:
        if not input_event.enter and not used[input_event.index]:
            was_before.add(input_event.index)

        used[input_event.index] = True

    zeros = set()

    meeting_size = len(was_before)
    for event in input_events:
        if event.enter:
            if meeting_size != 0:
                id33[event.index] = False
            else:
                zeros.add(event.index)

            meeting_size += 1
        else:
            meeting_size -= 1

            if meeting_size != 0:
                id33[event.index] = False
            else:
                zeros.add(event.index)

    if len(zeros) > 1:
        for index in zeros:
            id33[index] = False
    elif len(zeros) == 1:
        zero_enter = zeros.pop()

        if len(was_before) > 0 and zero_enter not in was_before:
            id33[zero_enter] = False

    id14 = [i for i in range(n) if id33[i]]

    print(len(id14))
    print(*[leader + 1 for leader in id14])


def main() -> None:
    solve()


if __name__ == "__main__":
    main()
