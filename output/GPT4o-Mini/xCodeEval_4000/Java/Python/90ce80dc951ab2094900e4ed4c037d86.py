import sys
from collections import defaultdict
from math import inf

class Item:
    def __init__(self, w, val, group):
        self.w = w
        self.val = val
        self.group = group

    def __str__(self):
        return f"{self.w}  {self.val}   {self.group}  \n"

class Suffix:
    def __init__(self, index, rank, next):
        self.index = index
        self.rank = rank
        self.next = next

    def __lt__(self, other):
        if self.rank == other.rank:
            return self.next < other.next
        return self.rank < other.rank

class Solution:
    MAX = inf
    MIN = -inf

    def solution(self, K, F, W):
        res = 0
        ten = [1, 10, 100, 1000, 10000, 100000]
        A = []

        K -= 1

        if K == 0:
            num = str(W)
            num = num[::-1]
            score = 0
            for k in range(len(num)):
                d = int(num[k])
                if d % 3 == 0:
                    score += (F[k] * (d // 3))
            self.msg(str(score))
            return

        for i in range(6):
            weight = ten[i] * 3
            cur = 0
            for j in range(32):
                go = 1 << j
                if cur + go >= (3 * K):
                    remain = 3 * K - cur
                    item = Item(weight * remain, F[i] * remain, i)
                    A.append(item)
                    break
                item = Item(weight * (1 << j), F[i] * (1 << j), i)
                cur += (1 << j)
                A.append(item)

        pre = [-1] * (W + 1)
        dp = [-1] * (W + 1)
        pre[0] = 0

        for i in range(1, len(A)):
            item = A[i - 1]
            dp = [-1] * (W + 1)
            dp[0] = 0
            for j in range(1, len(dp)):
                dp[j] = max(dp[j], pre[j])
                w = item.w
                val = item.val
                if j < w or pre[j - w] == -1:
                    continue
                dp[j] = max(dp[j], pre[j - w] + val)
                num = str(W - j)
                num = num[::-1]
                score = 0
                for k in range(len(num)):
                    d = int(num[k])
                    if d % 3 == 0:
                        score += (F[k] * (d // 3))
                res = max(res, dp[j] + score)

            pre = dp

        self.msg(str(res))

    def msg(self, s):
        print(s)

def main():
    input = sys.stdin.read
    data = input().split()
    idx = 0
    T = 1

    for t in range(T):
        K = int(data[idx])
        idx += 1
        F = [int(data[idx + i]) for i in range(6)]
        idx += 6
        q = int(data[idx])
        idx += 1
        W = int(data[idx])
        idx += 1

        sol = Solution()
        sol.solution(K, F, W)

if __name__ == "__main__":
    main()
