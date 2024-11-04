import sys

def read():
    return sys.stdin.readline().strip()

def main():
    n, m = map(int, read().split())
    l = [0] * n
    r = [0] * n
    sum = [0] * (m + 1)
    dp1 = [0] * (m + 1)
    dp2 = [0] * (m + 1)
    bit = [0] * (m + 1)

    for i in range(n):
        l[i], r[i] = map(int, read().split())
        sum[l[i]] += 1
        sum[r[i] + 1] -= 1

    for i in range(1, m + 1):
        sum[i] += sum[i - 1]

    dp1[0] = 0
    for i in range(1, m + 1):
        dp1[i] = query(bit, sum[i] + 1) + 1
        modify(bit, sum[i] + 1, dp1[i])

    bit = [0] * (m + 1)
    for i in range(m, 0, -1):
        dp2[i] = query(bit, sum[i] + 1) + 1
        modify(bit, sum[i] + 1, dp2[i])

    ans = 0
    for i in range(1, m + 1):
        ans = max(ans, dp1[i] + dp2[i] - 1)

    print(ans)

def modify(bit, pos, val):
    while pos < len(bit):
        bit[pos] = max(bit[pos], val)
        pos += pos & -pos

def query(bit, pos):
    ans = 0
    while pos:
        ans = max(ans, bit[pos])
        pos -= pos & -pos
    return ans

if __name__ == "__main__":
    main()
