import sys
from typing import List, Tuple

class TaskD:
    def solve(self, n: int, m: int, b: List[int], w: List[int], edges: List[Tuple[int, int]]) -> int:
        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        q = [0] * n
        def calcQ(vert: int, last: int) -> int:
            res = 1
            for next_vert in graph[vert]:
                if next_vert == last:
                    continue
                res += calcQ(next_vert, vert)
            q[vert] = res
            return res
        
        calcQ(0, -1)
        
        answer = [[(0, 0)] * (m + 2) for _ in range(n)]
        
        def go(vert: int, last: int) -> None:
            id = -1
            for next_vert in graph[vert]:
                if next_vert == last:
                    continue
                go(next_vert, vert)
                if id == -1 or q[next_vert] > q[id]:
                    id = next_vert
            
            cur = answer[vert]
            delta = w[vert] - b[vert]
            if id == -1:
                cur[0] = (0, delta)
                cur[1] = (1 if delta > 0 else 0, 0)
                return
            
            aid = answer[id]
            for i in range(q[id] + 1):
                cur[i] = (aid[i][0], aid[i][1] + delta)
            
            sz = q[id]
            for i in range(sz + 1, q[vert] + 1):
                cur[i] = (-1, 0)
            
            for next_vert in graph[vert]:
                if next_vert == last or next_vert == id:
                    continue
                anext = answer[next_vert]
                for i in range(sz + 1):
                    temp = cur[i]
                    cur[i] = (-1, 0)
                    
                    nsz = sz + q[next_vert]
                    for j in range(q[next_vert] + 1):
                        if temp[i][0] + anext[j][0] > cur[i + j][0]:
                            cur[i + j] = (temp[i][0] + anext[j][0], temp[i][1] + anext[j][1])
                
                sz = nsz
            
            if vert == 0:
                for i in range(n - 1, -1, -1):
                    cur[i + 1] = (cur[i][0] + (1 if cur[i][1] > 0 else 0), 0)
                return
            
            for i in range(sz + 1, -1, -1):
                cur[i + 1] = (cur[i][0] + (1 if cur[i][1] > 0 else 0), 0)
        
        go(0, -1)
        return answer[0][m][0]
        

def main() -> None:
    solver = TaskD()
    t = int(input())
    for _ in range(t):
        n = int(input())
        b = list(map(int, input().split()))
        w = list(map(int, input().split()))
        edges = [tuple(map(int, input().split())) for _ in range(n - 1)]
        m = int(input())
        result = solver.solve(n, m, b, w, edges)
        print(result)


if __name__ == "__main__":
    main()
