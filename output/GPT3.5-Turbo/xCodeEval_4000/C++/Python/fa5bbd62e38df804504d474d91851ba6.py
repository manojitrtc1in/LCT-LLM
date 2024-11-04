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
        max_angle = get_angle(cur_xy, xys_idx[l][1])
        for i in range(l, r+1):
            angle = get_angle(cur_xy, xys_idx[i][1])
            if angle + math.pi < max_angle:
                angle += 2 * math.pi
            xys_idx[i][0] = angle
            max_angle = max(max_angle, angle)
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
            nxt_l = cur_r + 1
            solve_rec(cur_l, cur_r, i, root)
            cur_l = nxt_l

    subtree_sz = [0] * n
    xy_mapping = [0] * n
    e = [[] for _ in range(n)]
    for u, v in tree:
        e[u-1].append(v-1)
        e[v-1].append(u-1)
    points = [(x, y) for x, y in points]
    calculate_subtree_sizes(0, -1)
    xys_idx = [[0.0, i] for i in range(n)]
    xys_idx.sort(key=lambda x: (points[x[1]][0], points[x[1]][1]), reverse=True)
    solve_rec(0, n-1, 0, -1)
    xy_mapping = [x+1 for x in xy_mapping]
    return xy_mapping

def calculate_subtree_sizes(i: int, p: int) -> None:
    subtree_sz[i] = 1
    for j in e[i]:
        if j == p:
            continue
        calculate_subtree_sizes(j, i)
        subtree_sz[i] += subtree_sz[j]

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
    for u, v in tree:
        res.append(f"{u} {v}")
    for x, y in points:
        res.append(f"{x} {y}")
    return "\n".join(res)

def from_output_string(output_string: str) -> List[int]:
    lines = output_string.strip().split("\n")
    return list(map(int, lines))

def to_output_string(output: List[int]) -> str:
    res = [str(x) for x in output]
    return "\n".join(res)

