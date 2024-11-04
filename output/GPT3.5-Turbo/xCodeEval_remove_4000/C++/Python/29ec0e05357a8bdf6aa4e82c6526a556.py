import sys
from typing import List, Tuple, Dict, Any


def dfs(adj: List[int], n: int) -> int:
    F = [0] * (1 << n)
    F[0] = 1
    for s in range((1 << n) - 1):
        if F[s]:
            for i in range(n):
                if not (s & (1 << i)) and not (s & adj[i]):
                    F[s | (1 << i)] += F[s]
    return F[(1 << n) - 1]


def translate_input(input_string: str) -> Tuple:
    lines = input_string.strip().split("\n")
    n, k = map(int, lines[0].split())
    adj = [0] * n
    for line in lines[1:]:
        u, v = map(int, line.split())
        adj[u - 1] |= (1 << (v - 1))
    return adj, n, k


def translate_output(output: Any) -> str:
    if output == -1:
        return "The times have changed"
    else:
        return " ".join(str(x + 1) for x in output)


def translate_input_string(input_string: str) -> Tuple:
    return (input_string,)


def translate_output_string(output_string: str) -> Any:
    if output_string.strip() == "The times have changed":
        return -1
    else:
        return list(map(int, output_string.strip().split()))


def solve(adj: List[int], n: int, k: int) -> Any:
    k -= 2000
    P = [-1] * n
    if dfs(adj, n) < k:
        return -1
    else:
        s = (1 << n) - 1
        A = [0] * n
        for i in range(n):
            for j in range(n):
                if (s & (1 << j)):
                    P[A[i]] = i
                    t = dfs(adj, n)
                    if t < k:
                        k -= t
                        P[j] = -1
                    else:
                        s ^= (1 << j)
                        A[i] = j
                        break
        return A


def main(input_string: str) -> str:
    inputs = translate_input(input_string)
    outputs = solve(*inputs)
    return translate_output(outputs)
