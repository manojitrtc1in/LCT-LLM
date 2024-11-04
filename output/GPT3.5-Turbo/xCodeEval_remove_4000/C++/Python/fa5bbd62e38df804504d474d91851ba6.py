import sys
from typing import List, Tuple

def solve(n: int, tree: List[Tuple[int, int]], points: List[Tuple[int, int]]) -> List[int]:
    def x_dist(i: int, j: int) -> int:
        return points[j][0] - points[i][0]

    def y_dist(i: int, j: int) -> int:
        return points[j][1] - points[i][1]

    def get_angle(i: int, j: int) -> float:
        return math.atan2(y_dist(i, j), x_dist(i, j))

    def sort_by_angle(l: int, r: int, cur_xy: int) -> None:
        if r < l:
            return
        for i in range(l, r+1):
            xys_idx[i][0] = get_angle(cur_xy, xys_idx[i][1])
        max_angle = xys_idx[l][0]
        for i in range(l, r+1):
            max_angle = max(max_angle, xys_idx[i][0])
        for i in range(l, r+1):
            if xys_idx[i][0] + math.pi < max_angle:
                xys_idx[i][0] += 2 * math.pi
        xys_idx[l:r+1] = sorted(xys_idx[l:r+1])

    def solve_rec(l: int, r: int, root: int, parent: int) -> None:
        curr_xy = xys_idx[r][1]
        xy_mapping[curr_xy] = root
        sort_by_angle(l, r-1, curr_xy)
        cur_l = l
        for i in range(n):
            if i == parent:
                continue
            cur_r = cur_l + subtree_sz[i] - 1
            solve_rec(cur_l, cur_r, i, root)
            cur_l = cur_r + 1

    def calculate_subtree_sizes(i: int, p: int) -> None:
        subtree_sz[i] = 1
        for j in tree[i]:
            if j == p:
                continue
            calculate_subtree_sizes(j, i)
            subtree_sz[i] += subtree_sz[j]

    subtree_sz = [0] * n
    xy_mapping = [0] * n
    calculate_subtree_sizes(0, -1)
    xys_idx = [[0, 0]] * n
    for i in range(n):
        xys_idx[i][1] = i
    xys_idx.sort(key=lambda x: (-points[x[1]][0], -points[x[1]][1]))
    solve_rec(0, n-1, 0, -1)
    xy_mapping = [x+1 for x in xy_mapping]
    return xy_mapping

def from_input_string(input_string: str) -> Tuple[int, List[Tuple[int, int]], List[Tuple[int, int]]]:
    lines = input_string.strip().split("\n")
    n = int(lines[0])
    tree = [tuple(map(int, x.strip().split())) for x in lines[1:n]]
    points = [tuple(map(int, x.strip().split())) for x in lines[n:]]
    return n, tree, points

def to_input_string(inputs: Tuple[int, List[Tuple[int, int]], List[Tuple[int, int]]]) -> str:
    n, tree, points = inputs
    res = []
    res.append(str(n))
    for t in tree:
        res.append(" ".join(str(x) for x in t))
    for p in points:
        res.append(" ".join(str(x) for x in p))
    return "\n".join(res)

def from_output_string(output_string: str) -> List[int]:
    return list(map(int, output_string.strip().split("\n")))

def to_output_string(output: List[int]) -> str:
    return "\n".join(str(x) for x in output)
    
EXAMPLES_PROVIDED = [{'input': '4\n1 2\n2 3\n2 4\n1 1\n2 2\n3 3\n4 4\n', 'output': '1\n2\n3\n4\n'}, {'input': '5\n1 2\n2 3\n3 4\n4 5\n1 1\n2 2\n3 3\n4 4\n5 5\n', 'output': '1\n2\n3\n4\n5\n'}, {'input': '3\n1 2\n1 3\n1 1\n2 2\n3 3\n', 'output': '1\n2\n3\n'}...

for example in EXAMPLES_PROVIDED:
    input_str = example['input']
    expected_output_str = example['output']
    inputs = from_input_string(input_str)
    expected_output = from_output_string(expected_output_str)

    # Ensure the function is correct
    assert solve(*inputs) == expected_output

    # Ensure str -> variable -> str consistency, while ignoring leading/trailing white space
    assert input_str.strip() == to_input_string(from_input_string(input_str)).strip()
    assert expected_output_str.strip() == to_output_string(from_output_string(expected_output_str)).strip()

    # Ensure variable -> str -> variable consistency
    assert inputs == from_input_string(to_input_string(inputs))
    assert expected_output == from_output_string(to_output_string(expected_output))
