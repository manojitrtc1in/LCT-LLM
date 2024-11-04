import random
import sys
from collections import defaultdict
from typing import List, Tuple


def solve() -> None:
    n, m = map(int, input().split())
    
    can_be_leader = [True] * n
    events = []
    for _ in range(m):
        event_type, index = input().split()
        index = int(index) - 1
        events.append((event_type, index))
    
    start_meeting_size = 0
    was_before = set()
    used = [False] * n
    for event_type, index in events:
        if event_type == '-' and not used[index]:
            was_before.add(index)
        used[index] = True
    
    zeros = set()
    meeting_size = len(was_before)
    for event_type, index in events:
        if event_type == '+':
            if meeting_size != 0:
                can_be_leader[index] = False
            else:
                zeros.add(index)
            meeting_size += 1
        else:
            meeting_size -= 1
            if meeting_size != 0:
                can_be_leader[index] = False
            else:
                zeros.add(index)
    
    if len(zeros) > 1:
        for index in zeros:
            can_be_leader[index] = False
    elif len(zeros) == 1:
        zero_enter = zeros.pop()
        if len(was_before) > 0 and zero_enter not in was_before:
            can_be_leader[zero_enter] = False
    
    possible_leaders = [i for i in range(n) if can_be_leader[i]]
    
    print(len(possible_leaders))
    print(*[leader + 1 for leader in possible_leaders])


def main() -> None:
    solve()


if __name__ == '__main__':
    main()
