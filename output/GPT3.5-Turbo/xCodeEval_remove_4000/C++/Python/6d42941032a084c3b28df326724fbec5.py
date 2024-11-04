import sys
from typing import List, Tuple

def solve(n: int, m: int, a: List[int], w: List[int]) -> List[int]:
    W1 = 0
    W2 = 0
    for i in range(n):
        if a[i]:
            W1 += w[i]
        else:
            W2 += w[i]
    
    probs = [0] * (m + 1)
    probs[0] = 1
    for i in range(m):
        new_probs = [0] * (m + 1)
        for d1 in range(i + 1):
            d2 = d1 - i
            w1 = W1 + d1
            w2 = W2 + d2
            w0 = w1 + w2
            if probs[d1] and (w2 >= 0):
                id16 = pow(w0, M - 2, M)
                if w2 > 0:
                    new_probs[d1] = (new_probs[d1] + probs[d1] * w2 * id16) % M
                new_probs[d1 + 1] = (new_probs[d1 + 1] + probs[d1] * w1 * id16) % M
        probs = new_probs
    
    id4 = [0] * (m + 1)
    id29 = [0] * (m + 1)
    id4[0] = 1
    id29[0] = 1
    for i in range(1, m + 1):
        id4[i] = id4[i - 1] * (1 + pow(W1 + i - 1, M - 2, M)) % M
    for i in range(1, m + 1):
        id29[i] = id29[i - 1] * (1 - pow(W2 - i + 1, M - 2, M)) % M
    
    coef1 = 0
    coef2 = 0
    for i in range(m + 1):
        coef1 = (coef1 + id4[i] * probs[i]) % M
    for i in range(m + 1):
        coef2 = (coef2 + id29[i] * probs[m - i]) % M
    
    result = []
    for i in range(n):
        if a[i]:
            result.append(w[i] * coef1 % M)
        else:
            result.append(w[i] * coef2 % M)
    
    return result

def from_input_string(input_string: str) -> Tuple[int, int, List[int], List[int]]:
    lines = input_string.strip().split("\n")
    n, m = map(int, lines[0].strip().split())
    a = list(map(int, lines[1].strip().split()))
    w = list(map(int, lines[2].strip().split()))
    return n, m, a, w

def to_input_string(inputs: Tuple[int, int, List[int], List[int]]) -> str:
    n, m, a, w = inputs
    res = []
    res.append(f"{n} {m}")
    res.append(" ".join(str(x) for x in a))
    res.append(" ".join(str(x) for x in w))
    return "\n".join(res)

def from_output_string(output_string: str) -> List[int]:
    lines = output_string.strip().split("\n")
    return [int(x) for x in lines]

def to_output_string(output: List[int]) -> str:
    res = [str(x) for x in output]
    return "\n".join(res)

