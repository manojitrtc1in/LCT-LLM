from typing import List
from itertools import permutations

def max_beauty(n: int) -> int:
    max_beauty = 0
    for perm in permutations(range(1, n+1)):
        beauty = 0
        for i in range(1, n):
            beauty += abs(perm[i] - perm[i-1])
        max_beauty = max(max_beauty, beauty)
    return max_beauty

def from_input_string(input_string: str) -> int:
    return int(input_string.strip())

