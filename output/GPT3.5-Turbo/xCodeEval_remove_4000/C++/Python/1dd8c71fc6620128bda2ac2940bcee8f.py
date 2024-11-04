import sys
from typing import List, Tuple

class Fenwick:
    def __init__(self, n: int):
        self.fw = [0] * (n + 1)
    
    def update(self, i: int, d: int):
        while i < len(self.fw):
            self.fw[i] = max(self.fw[i], d)
            i |= i + 1
    
    def get(self, n: int) -> int:
        result = 0
        while n >= 0:
            result = max(result, self.fw[n])
            n = (n & (n + 1)) - 1
        return result
    
    def get_range(self, l: int, r: int) -> int:
        return self.get(r) - self.get(l - 1)

def solution(n: int, m: int, intervals: List[Tuple[int, int]]) -> int:
    cnt = [0] * (m + 1)
    for l, r in intervals:
        cnt[l] += 1
        cnt[r + 1] -= 1
    
    for i in range(1, m + 1):
        cnt[i] += cnt[i - 1]
    
    fw_l = Fenwick(100001)
    l = [0] * (m + 1)
    for i in range(1, m + 1):
        l[i] = fw_l.get(cnt[i]) + 1
        fw_l.update(cnt[i], l[i])
    
    fw_r = Fenwick(100001)
    r = [0] * (m + 1)
    for i in range(m, 0, -1):
        r[i] = fw_r.get(cnt[i]) + 1
        fw_r.update(cnt[i], r[i])
    
    ans = 0
    for i in range(1, m + 1):
        ans = max(ans, l[i] + r[i] - 1)
    
    return ans

def from_input_string(input_string: str) -> Tuple[int, int, List[Tuple[int, int]]]:
    lines = input_string.strip().split('\n')
    n, m = map(int, lines[0].strip().split())
    intervals = [tuple(map(int, line.strip().split())) for line in lines[1:]]
    return n, m, intervals

def to_input_string(inputs: Tuple[int, int, List[Tuple[int, int]]]) -> str:
    n, m, intervals = inputs
    res = []
    res.append(f"{n} {m}")
    for interval in intervals:
        res.append(" ".join(str(x) for x in interval))
    return "\n".join(res)

def from_output_string(output_string: str) -> int:
    return int(output_string.strip())

def to_output_string(output: int) -> str:
    return str(output)

EXAMPLES_PROVIDED = [{'input': '5 5\n1 2\n2 3\n3 4\n4 5\n5 5\n', 'output': '5\n'}, {'input': '5 5\n1 1\n2 2\n3 3\n4 4\n5 5\n', 'output': '1\n'}, {'input': '5 5\n1 5\n1 5\n1 5\n1 5\n1 5\n', 'output': '5\n'}, {'input': '5 5\n1 5\n1 5\n1 5\n1 5\n1 5\n', 'outp...

for example in EXAMPLES_PROVIDED:
    input_str = example['input']
    expected_output_str = example['output']
    inputs = from_input_string(input_str)
    expected_output = from_output_string(expected_output_str)

    # Ensure the function is correct
    assert solution(*inputs) == expected_output

    # Ensure str -> variable -> str consistency, while ignoring leading/trailing white space
    assert input_str.strip() == to_input_string(from_input_string(input_str)).strip()
    assert expected_output_str.strip() == to_output_string(from_output_string(expected_output_str)).strip()

    # Ensure variable -> str -> variable consistency
    assert inputs == from_input_string(to_input_string(inputs))
    assert expected_output == from_output_string(to_output_string(expected_output))
