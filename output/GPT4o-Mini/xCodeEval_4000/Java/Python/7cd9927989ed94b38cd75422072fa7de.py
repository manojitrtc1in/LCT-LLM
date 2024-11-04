from collections import defaultdict, deque

def bfs(arr, visited, start, map):
    q = deque()
    q.append((start, 0))
    map[start] = 0
    visited[start] = 1
    while q:
        ob = q.popleft()
        for curr in arr[ob[0]]:
            if visited[curr] == 0:
                visited[curr] = 1
                q.append((curr, ob[1] + 1))
                map[curr] = ob[1] + 1

def main():
    n = int(input())
    m = int(input())
    
    rarr = [list() for _ in range(n + 1)]
    arr = [list() for _ in range(n + 1)]
    
    for _ in range(m):
        a, b = map(int, input().split())
        arr[a].append(b)
        rarr[b].append(a)
    
    h = int(input())
    path = list(map(int, input().split()))
    
    map = {}
    visited = [0] * (n + 1)
    bfs(rarr, visited, path[-1], map)
    
    min_count = 0
    max_count = 0
    
    for i in range(h - 1):
        count = 0
        if map.get(path[i]) == map.get(path[i + 1]) + 1:
            for curr in arr[path[i]]:
                if map.get(curr) == map.get(path[i]) - 1:
                    count += 1
            
            if count > 1:
                max_count += 1
        else:
            min_count += 1
            max_count += 1
    
    print(min_count, max_count)

if __name__ == "__main__":
    main()
