import sys
from typing import List, Tuple, Dict, Any

def solve() -> None:
    n: int = int(input())
    a1, a2, a3 = map(int, input().split())
    b1, b2, b3 = map(int, input().split())

    min_val: int = 0

    if b1 >= a1 + a2:
        min_val = a3 - b2 - b3
    elif b2 >= a3 + a2:
        min_val = a1 - b1 - b3
    elif b3 >= a1 + a3:
        min_val = a2 - b2 - b1
    else:
        min_val = 0

    max_val: int = min(a1, b2) + min(a2, b3) + min(a3, b1)

    print(min_val, max_val)

def from_input_string(input_string: str) -> Tuple:
    return tuple()

def from_output_string(output_string: str) -> Any:
    return None

def to_input_string(inputs: Tuple) -> str:
    return ""

def to_output_string(output: Any) -> str:
    return ""

def from_input_string(input_string: str) -> Tuple:
    lines = input_string.strip().split("\n")
    return tuple(map(int, lines[0].split()))

def from_output_string(output_string: str) -> Any:
    return None

def to_input_string(inputs: Tuple) -> str:
    return str(inputs[0]) + "\n"

def to_output_string(output: Any) -> str:
    return ""

EXAMPLES_PROVIDED = [{'input': '3\n1 2 3\n4 5 6\n', 'output': '0 9\n'}, {'input': '1\n1 1 1\n1 1 1\n', 'output': '0 3\n'}, {'input': '1\n1 1 1\n1 1 2\n', 'output': '0 3\n'}, {'input': '1\n1 1 1\n1 2 1\n', 'output': '0 3\n'}, {'input': '1\n1 1 1\n2 1 1\n',...

for example in EXAMPLES_PROVIDED:
    input_str = example['input']
    expected_output_str = example['output']
    inputs = from_input_string(input_str)
    expected_output = from_output_string(expected_output_str)

    # Ensure the function is correct
    solve()
    # Ensure str -> variable -> str consistency, while ignoring leading/trailing white space
    assert input_str.strip() == to_input_string(from_input_string(input_str)).strip()
    assert expected_output_str.strip() == to_output_string(from_output_string(expected_output_str)).strip()

    # Ensure variable -> str -> variable consistency
    assert inputs == from_input_string(to_input_string(inputs))
    assert expected_output == from_output_string(to_output_string(expected_output))
