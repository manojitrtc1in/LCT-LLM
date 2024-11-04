import sys
from typing import List, Tuple

class TaskD:
    def solve(self, n: int, b: List[int], w: List[int], edges: List[Tuple[int, int]]) -> int:
        def calcQ(vert: int, last: int) -> int:
            res = 1
            for e in graph[vert]:
                next_vert = e[1]
                if next_vert == last:
                    continue
                res += calcQ(next_vert, vert)
            q[vert] = res
            return res

        def go(vert: int, last: int) -> None:
            id = -1
            for e in graph[vert]:
                next_vert = e[1]
                if next_vert == last:
                    continue
                go(next_vert, vert)
                if id == -1 or q[next_vert] > q[id]:
                    id = next_vert
            cur = answer[vert]
            delta = w[vert] - b[vert]
            if id == -1:
                cur[0] = (0, delta)
                cur[1] = (1 if delta > 0 else 0, 0)
                return
            aid = answer[id]
            for i in range(q[id] + 1):
                cur[i] = aid[i][0], aid[i][1] + delta
            sz = q[id]
            for i in range(sz + 1, q[vert] + 1):
                cur[i] = -1, 0
            for e in graph[vert]:
                next_vert = e[1]
                if next_vert == last or next_vert == id:
                    continue
                anext = answer[next_vert]
                for i in range(sz + 1):
                    temp[i] = cur[i]
                    cur[i] = -1, 0
                nsz = sz + q[next_vert]
                for i in range(sz + 1):
                    for j in range(q[next_vert] + 1):
                        if temp[i][0] + anext[j][0] > cur[i + j][0]:
                            cur[i + j] = temp[i][0] + anext[j][0], temp[i][1] + anext[j][1]
                sz = nsz
            if vert == 0:
                for i in range(n - 1, -1, -1):
                    cur[i + 1] = cur[i][0] + (1 if cur[i][1] > 0 else 0), 0
                return
            for i in range(sz + 1, -1, -1):
                if cur[i][0] + (1 if cur[i][1] > 0 else 0) > cur[i + 1][0]:
                    cur[i + 1] = cur[i][0] + (1 if cur[i][1] > 0 else 0), 0

    def solve_all(self, testcases: List[Tuple[int, List[int], List[int], List[Tuple[int, int]]]]) -> List[int]:
        res = []
        for n, b, w, edges in testcases:
            res.append(self.solve(n, b, w, edges))
        return res

def from_input_string(input_string: str) -> Tuple[List[Tuple[int, List[int], List[int], List[Tuple[int, int]]]]]:
    lines = input_string.strip().split("\n")
    n = int(lines[0])
    testcases = []
    for i in range(1, len(lines), 3):
        b = list(map(int, lines[i].strip().split()))
        w = list(map(int, lines[i+1].strip().split()))
        edges = [tuple(map(int, x.strip().split())) for x in lines[i+2].strip().split()]
        testcases.append((n, b, w, edges))
    return testcases

def to_input_string(inputs: Tuple[List[Tuple[int, List[int], List[int], List[Tuple[int, int]]]]]) -> str:
    testcases = inputs[0]
    res = []
    res.append(str(len(testcases)))
    for n, b, w, edges in testcases:
        res.append(" ".join(str(x) for x in b))
        res.append(" ".join(str(x) for x in w))
        res.append(" ".join(f"{x[0]} {x[1]}" for x in edges))
    return "\n".join(res)

def from_output_string(output_string: str) -> List[int]:
    lines = output_string.strip().split("\n")
    return [int(x) for x in lines]

def to_output_string(output: List[int]) -> str:
    res = [str(x) for x in output]
    return "\n".join(res)

EXAMPLES_PROVIDED = [{'input': '1\n1 1\n1 1\n', 'output': '1\n'}]

for example in EXAMPLES_PROVIDED:
    input_str = example['input']
    expected_output_str = example['output']
    inputs = from_input_string(input_str)
    expected_output = from_output_string(expected_output_str)

    # Ensure the function is correct
    assert TaskD().solve_all(*inputs) == expected_output

    # Ensure str -> variable -> str consistency, while ignoring leading/trailing white space
    assert input_str.strip() == to_input_string(from_input_string(input_str)).strip()
    assert expected_output_str.strip() == to_output_string(from_output_string(expected_output_str)).strip()

    # Ensure variable -> str -> variable consistency
    assert inputs == from_input_string(to_input_string(inputs))
    assert expected_output == from_output_string(to_output_string(expected_output))
