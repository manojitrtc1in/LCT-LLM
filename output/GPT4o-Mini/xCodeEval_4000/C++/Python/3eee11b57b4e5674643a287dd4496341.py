import sys
from collections import defaultdict

input = sys.stdin.read
def main():
    n = int(input().strip())
    a = list(map(lambda x: int(x) - 1, input().strip().split()))
    
    sum_counts = [[0] * (n + 1) for _ in range(100)]
    b = defaultdict(list)
    
    for i in range(n):
        sum_counts[a[i]][i + 1] += 1
        b[a[i]].append(i)
    
    for i in range(100):
        for j in range(n):
            sum_counts[i][j + 1] += sum_counts[i][j]
    
    def find():
        mx = 0
        ret = -1
        for i in range(100):
            if sum_counts[i][n] > mx:
                mx = sum_counts[i][n]
                ret = i
        return ret
    
    i = find()
    ans = 0
    mp = [-1] * 404040

    for j in range(100):
        if i == j:
            continue
        if not b[i] or not b[j]:
            continue
        
        x, y = 0, 0
        now = 202020
        mp[202020] = 0
        era = []
        
        while True:
            def nex(x, y):
                if x < len(b[i]) and y < len(b[j]):
                    if b[i][x] < b[j][y]:
                        return 1, b[i][x]
                    else:
                        return -1, b[j][y]
                elif x < len(b[i]):
                    return 1, b[i][x]
                elif y < len(b[j]):
                    return -1, b[j][y]
                else:
                    return -2, 0
            
            tmp = nex(x, y)
            if tmp[0] == -2:
                break
            if tmp[0] == 1:
                x += 1
            else:
                y += 1
            
            now += tmp[0]
            if mp[now] != -1:
                tmp = nex(x, y)
                if tmp[0] == -2:
                    ans = max(ans, n - mp[now])
                else:
                    ans = max(ans, tmp[1] - mp[now])
            else:
                mp[now] = tmp[1] + 1
                era.append(now)
        
        for e in era:
            mp[e] = -1
    
    print(ans)

if __name__ == "__main__":
    main()
