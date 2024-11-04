def solve():
    n = int(input())
    a = list(map(int, input().split()))
    
    idx = [i for i in range(n) if i == n - 1 - i or i == n // 2 or i == n // 2]
    
    result = sum(a[i] for i in idx)
    print(result)

if __name__ == "__main__":
    solve()
