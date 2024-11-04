import sys
from collections import defaultdict

def sum(arr):
    return sum(arr)

def main():
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    N = int(data[idx])
    M = int(data[idx + 1])
    idx += 2
    
    K = list(map(int, data[idx:idx + N]))
    idx += N
    
    vv = defaultdict(list)
    
    for _ in range(M):
        D = int(data[idx]) - 1
        T = int(data[idx + 1]) - 1
        vv[D].append(T)
        idx += 2
    
    ok = 2 * sum(K)
    ng = sum(K) - 1
    
    while ok - ng > 1:
        k = (ok + ng) // 2
        v = [0] * k
        b = [False] * N
        
        for i in range(k - 1, -1, -1):
            for j in vv[i]:
                if not b[j]:
                    b[j] = True
                    v[i] += K[j]
        
        t = 0
        s = sum(K)
        
        for i in range(k):
            t += 1
            m = min(t, v[i])
            t -= m
            s -= m
        
        if t >= s * 2:
            ok = k
        else:
            ng = k
    
    print(ok)

if __name__ == "__main__":
    main()
