import sys
from typing import List, Tuple

def dfs(adj: List[int], n: int) -> int:
    F = [0] * (1 << n)
    F[0] = 1
    for s in range((1 << n) - 1):
        if F[s]:
            for i in range(n):
                if not (s & (1 << i)) and not (s & adj[i]):
                    F[s | (1 << i)] += F[s]
    return F[(1 << n) - 1]

def solve(n: int, k: int, queries: List[Tuple[int, int]]) -> List[int]:
    adj = [0] * n
    A = [0] * n
    P = [-1] * n

    for query in queries:
        u, v = query
        adj[u - 1] |= (1 << (v - 1))
    
    k -= 2000
    if dfs(adj, n) < k:
        return [-1]
    
    result = []
    s = (1 << n) - 1
    for i in range(n):
        for j in range(n):
            if (s & (1 << j)):
                P[A[i]] = j
                t = dfs(adj, n)
                if t < k:
                    k -= t
                    P[j] = -1
                else:
                    s ^= (1 << j)
                    result.append(j + 1)
                    break
    return result

def from_input_string(input_string: str) -> Tuple[int, int, List[Tuple[int, int]]]:
    lines = input_string.strip().split('\n')
    n, k = map(int, lines[0].strip().split())
    queries = []
    for line in lines[1:]:
        u, v = map(int, line.strip().split())
        queries.append((u, v))
    return n, k, queries

def to_input_string(inputs: Tuple[int, int, List[Tuple[int, int]]]) -> str:
    n, k, queries = inputs
    res = []
    res.append(f"{n} {k}")
    for query in queries:
        res.append(f"{query[0]} {query[1]}")
    return '\n'.join(res)

def from_output_string(output_string: str) -> List[int]:
    lines = output_string.strip().split('\n')
    if lines[0] == "-1":
        return [-1]
    return list(map(int, lines[0].strip().split()))

def to_output_string(output: List[int]) -> str:
    if output[0] == -1:
        return "-1"
    return ' '.join(map(str, output))

def main():
    input_str = sys.stdin.read()
    inputs = from_input_string(input_str)
    output = solve(*inputs)
    output_str = to_output_string(output)
    sys.stdout.write(output_str)

if __name__ == "__main__":
    main()
