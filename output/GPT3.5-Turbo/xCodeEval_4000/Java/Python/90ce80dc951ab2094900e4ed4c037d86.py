class Solution:
    def __init__(self):
        self.MAX = float('inf')
        self.MIN = float('-inf')

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
                    score += F[k] * (d // 3)
            print(score)
            return

        for i in range(6):
            weight = ten[i] * 3
            cur = 0
            for j in range(32):
                go = 1 << j
                if cur + go >= (3 * K):
                    remain = 3 * K - cur
                    item = (weight * remain, F[i] * remain, i)
                    A.append(item)
                    break
                item = (weight * (1 << j), F[i] * (1 << j), i)
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
                w = item[0]
                val = item[1]
                if j < w or pre[j - w] == -1:
                    continue
                dp[j] = max(dp[j], pre[j - w] + val)
                num = str(W - j)
                num = num[::-1]
                score = 0
                for k in range(len(num)):
                    d = int(num[k])
                    if d % 3 == 0:
                        score += F[k] * (d // 3)
                res = max(res, dp[j] + score)

            pre = dp

        print(res)


if __name__ == "__main__":
    T = 1

    for t in range(T):
        K = int(input())
        F = list(map(int, input().split()))
        q = int(input())
        W = int(input())

        sol = Solution()
        sol.solution(K, F, W)
