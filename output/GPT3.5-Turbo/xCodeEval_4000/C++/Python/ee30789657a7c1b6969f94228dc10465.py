import sys
from typing import List, Tuple

MOD = int(1e9) + 7

def solve(t: int) -> int:
    dp = [[[0 for _ in range(2)] for _ in range(2)] for _ in range(2)]
    dp[0][0][0] = 1

    for i in range(60):
        f2 = (t >> i) & 1

        if f2:
            dp[i + 1][0][0] += dp[i][0][0]
            dp[i + 1][1][0] += dp[i][0][0]
            dp[i + 1][0][1] += dp[i][0][0]
            dp[i + 1][1][1] += dp[i][0][0]
            dp[i + 1][0][1] += dp[i][0][1]
            dp[i + 1][1][1] += dp[i][0][1]
            dp[i + 1][0][0] += dp[i][0][1]
            dp[i + 1][1][0] += dp[i][0][1]
            dp[i + 1][1][0] += dp[i][1][0]
            dp[i + 1][0][1] += dp[i][1][0]
            dp[i + 1][1][1] += dp[i][1][0]
            dp[i + 1][0][0] += dp[i][1][0]
            dp[i + 1][1][1] += dp[i][1][1]
            dp[i + 1][0][0] += dp[i][1][1]
            dp[i + 1][1][0] += dp[i][1][1]
            dp[i + 1][0][1] += dp[i][1][1]
        else:
            dp[i + 1][0][0] += dp[i][0][0]
            dp[i + 1][1][0] += dp[i][0][0]
            dp[i + 1][0][1] += dp[i][0][0]
            dp[i + 1][1][1] += dp[i][0][0]
            dp[i + 1][0][1] += dp[i][0][1]
            dp[i + 1][1][1] += dp[i][0][1]
            dp[i + 1][0][0] += dp[i][0][1]
            dp[i + 1][1][0] += dp[i][0][1]
            dp[i + 1][1][0] += dp[i][1][0]
            dp[i + 1][0][1] += dp[i][1][0]
            dp[i + 1][1][1] += dp[i][1][0]
            dp[i + 1][0][0] += dp[i][1][0]
            dp[i + 1][1][1] += dp[i][1][1]
            dp[i + 1][0][0] += dp[i][1][1]
            dp[i + 1][1][0] += dp[i][1][1]
            dp[i + 1][0][1] += dp[i][1][1]

        for j in range(2):
            for k in range(2):
                for l in range(2):
                    dp[i + 1][j][k][l] %= MOD

    return dp[60][0][0][0]


def from_input_string(input_string: str) -> Tuple[int, List[int]]:
    lines = input_string.strip().split("\n")
    t = int(lines[0])
    queries = [int(x) for x in lines[1:]]
    return t, queries


def to_input_string(inputs: Tuple[int, List[int]]) -> str:
    t, queries = inputs
    res = []
    res.append(str(t))
    res.extend(str(x) for x in queries)
    return "\n".join(res)


def from_output_string(output_string: str) -> List[int]:
    return [int(x) for x in output_string.strip().split("\n")]


def to_output_string(output: List[int]) -> str:
    return "\n".join(str(x) for x in output)


def main(t: int, queries: List[int]) -> List[int]:
    return [solve(x) for x in queries]


if __name__ == "__main__":
    input_data = from_input_string(sys.stdin.read())
    output_data = main(*input_data)
    print(to_output_string(output_data))
