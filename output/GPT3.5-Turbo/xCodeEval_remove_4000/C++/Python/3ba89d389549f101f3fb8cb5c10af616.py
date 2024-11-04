import sys
from typing import List, Tuple, Dict, Any


def dfs(g: List[List[int]], v: int, t: int, st: set, used: List[int], s: int) -> None:
    used[v] = 1
    if v != s:
        st.add(v)
    if v == t:
        return
    if v != s:
        for i in range(len(g[v])):
            to = g[v][i].to
            if used[to] == 0:
                dfs(g, to, t, st, used, s)
            elif used[to] == 2:
                st.add(t)
    else:
        for i in range(len(g[v])):
            to = g[v][i].to
            if used[to] != 0:
                continue
            dfs(g, to, t, st, used, s)
            if t in st:
                for itr in st:
                    used[itr] = 2
            st.clear()


def solve() -> None:
    n, m, a, b = map(int, input().split())
    a -= 1
    b -= 1
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        g[u].append(v)
        g[v].append(u)
    used = [0] * n
    st = set()
    dfs(g, a, b, st, used, a)
    s = 0
    t = 0
    for i in range(n):
        if used[i] == 1:
            s += 1
        elif used[i] == 0:
            t += 1
    s -= 1
    print(s * t)


def from_input_string(input_string: str) -> Tuple:
    return tuple(map(int, input_string.strip().split()))


def from_output_string(output_string: str) -> Any:
    return None


def to_input_string(inputs: Tuple) -> str:
    return ' '.join(map(str, inputs))


def to_output_string(output: Any) -> str:
    return ''


def to_input_string(inputs: Tuple) -> str:
    return ' '.join(map(str, inputs))


def to_output_string(output: Any) -> str:
    return ''


def main() -> None:
    input_string = sys.stdin.read()
    inputs = from_input_string(input_string)
    output = solve(*inputs)
    output_string = to_output_string(output)
    sys.stdout.write(output_string)


if __name__ == '__main__':
    main()
