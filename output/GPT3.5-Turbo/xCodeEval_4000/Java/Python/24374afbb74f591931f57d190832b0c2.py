def go(A, i, pv, v):
    if i == len(A):
        if pv == 0:
            return 1
        return 0
    if dp[i][pv][v] != -1:
        return dp[i][pv][v]
    ans = 0
    if A[i] == '_':
        for j in range(10):
            if i == 0 and j == 0:
                continue
            y = pv * 10 + j
            y %= 25
            ans += go(A, i + 1, y, v)
    elif A[i] == 'X':
        if v != 10:
            ans += go(A, i + 1, (pv * 10 + v) % 25, v)
        else:
            for j in range(10):
                if i == 0 and j == 0:
                    continue
                y = pv * 10 + j
                y %= 25
                ans += go(A, i + 1, y, j)
    else:
        ans += go(A, i + 1, (pv * 10 + int(A[i])) % 25, v)
    dp[i][pv][v] = ans
    return ans

def main():
    ttt = 1
    while ttt > 0:
        A = list(input().strip())
        if len(A) == 1 and A[0] == '0':
            print("1")
            return
        if A[0] == '0':
            print("0")
            return
        if len(A) == 1:
            if A[0] == 'X' or A[0] == '_':
                print("1")
                return
        dp = [[[-1 for _ in range(11)] for _ in range(25)] for _ in range(len(A) + 1)]
        print(go(A, 0, 0, 10))
        ttt -= 1

if __name__ == "__main__":
    main()
