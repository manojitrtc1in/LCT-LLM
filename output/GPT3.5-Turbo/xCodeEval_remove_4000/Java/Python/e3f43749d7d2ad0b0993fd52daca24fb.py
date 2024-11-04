import sys
import math
import heapq
from collections import defaultdict, deque
from typing import List, Tuple


class MyScanner:
    def __init__(self, input_file=sys.stdin):
        self.input_file = input_file
        self.tokens = deque()
    
    def next(self) -> str:
        if not self.tokens:
            self.tokens = deque(input().split())
        return self.tokens.popleft()
    
    def next_int(self) -> int:
        return int(self.next())
    
    def next_long(self) -> int:
        return int(self.next())
    
    def next_double(self) -> float:
        return float(self.next())
    
    def next_line(self) -> str:
        return input()
    
    def next_pairs(self, n: int) -> Tuple[List[int], List[int]]:
        u = []
        v = []
        for _ in range(n):
            u.append(self.next_int())
            v.append(self.next_int())
        return u, v
    
    def next_matrix(self, n: int, m: int) -> List[List[int]]:
        matrix = []
        for _ in range(n):
            row = []
            for _ in range(m):
                row.append(self.next_int())
            matrix.append(row)
        return matrix
    
    def id5(self, n: int, offset: int) -> Tuple[List[int], List[int]]:
        e = []
        for _ in range(n-1):
            u = self.next_int() + offset
            v = self.next_int() + offset
            e.append((u, v))
        return zip(*e)
    
    def id9(self, offset: int) -> Tuple[List[int], List[int]]:
        m = self.next_int()
        e = []
        for _ in range(m):
            u = self.next_int() + offset
            v = self.next_int() + offset
            e.append((u, v))
        return zip(*e)
    
    def id6(self, length: int, offset: int) -> List[int]:
        return [self.next_int() + offset for _ in range(length)]
    
    def id14(self, length: int, offset: int) -> List[int]:
        return [self.next_long() + offset for _ in range(length)]


class id4:
    def __init__(self, output_file=sys.stdout):
        self.output_file = output_file
    
    def println(self, *args, **kwargs):
        print(*args, **kwargs, file=self.output_file)
    
    def print_ans(self, arr: List[int], add: int = 0):
        if arr:
            print(arr[0] + add, end='', file=self.output_file)
            for num in arr[1:]:
                print(f' {num + add}', end='', file=self.output_file)
    
    def println_ans(self, arr: List[int], add: int = 0):
        self.print_ans(arr, add)
        print(file=self.output_file)
    
    def print_ans_boolean(self, ans: bool):
        if ans:
            print('YES', file=self.output_file)
        else:
            print('NO', file=self.output_file)
    
    def id0(self, arr: List[int], split: int):
        if arr:
            for i in range(0, len(arr), split):
                print(arr[i], end='', file=self.output_file)
                for num in arr[i+1:i+split]:
                    print(f' {num}', end='', file=self.output_file)
                print(file=self.output_file)


class id3:
    def __init__(self):
        self.inp = MyScanner()
        self.out = id4()
        self.MOD = 998244353
    
    def run(self):
        is_debug = False
        id7 = True
        id1 = False
        
        self.init_io(id7)
        
        t = self.inp.next_int() if id1 else 1
        
        for i in range(1, t+1):
            n = self.inp.next_int()
            m = self.inp.next_int()
            uv = self.inp.next_pairs(m)
            u, v = uv
            
            if is_debug:
                self.out.println(f'Test {i}')
            
            ans = self.solve2(u, v, n)
            self.out.println(ans)
            
            if is_debug:
                self.out.flush()
        
        self.inp.close()
        self.out.close()
    
    def init_io(self, id7: bool):
        if 'ONLINE_JUDGE' not in sys.argv and id7:
            try:
                self.inp = MyScanner(open('input.txt', 'r'))
                self.out = id4(open('output.txt', 'w'))
            except FileNotFoundError as e:
                e.printStackTrace()
        else:
            self.inp = MyScanner()
            self.out = id4()
    
    def solve2(self, u: List[int], v: List[int], n: int) -> int:
        RADIX = 10
        
        dp = [0] * (1 << RADIX)
        for j in range(RADIX):
            dp[1 << j] = 1
        
        cmp = [[0] * RADIX for _ in range(RADIX)]
        m = len(u)
        for i in range(m):
            small = min(u[i], v[i])
            larger = max(u[i], v[i])
            cmp[small][larger] = -1
            cmp[larger][small] = 1
        
        is_valid = [[False] * RADIX for _ in range(1 << RADIX)]
        mapping = [[0] * RADIX for _ in range(1 << RADIX)]
        
        for mask in range(1 << RADIX):
            for j in range(RADIX):
                ok = True
                next_mask = 1 << j
                for k in range(RADIX):
                    if (1 << k) & mask == 0:
                        continue
                    
                    if cmp[j][k] == 0:
                        pass
                    elif cmp[j][k] == -1:
                        next_mask |= 1 << k
                    else:
                        ok = False
                
                is_valid[mask][j] = ok
                mapping[mask][j] = next_mask
        
        for i in range(n-2, -1, -1):
            next_dp = [0] * (1 << RADIX)
            for mask in range(1 << RADIX):
                for j in range(RADIX):
                    if not is_valid[mask][j]:
                        continue
                    mask2 = mapping[mask][j]
                    val = (next_dp[mask2] + dp[mask]) % self.MOD
                    next_dp[mask2] = val
            
            dp = next_dp
        
        return sum(dp) % self.MOD
    
    def solve(self, u: List[int], v: List[int], n: int) -> int:
        RADIX = 10
        
        num = [1] * RADIX
        
        multipliers = [[1] * RADIX for _ in range(RADIX)]
        for i in range(len(u)):
            small = min(u[i], v[i])
            larger = max(u[i], v[i])
            multipliers[larger][small] = 0
        
        for _ in range(1, n):
            num2 = [0] * RADIX
            for j in range(RADIX):
                for k in range(RADIX):
                    num2[j] += num[k] * multipliers[j][k] % self.MOD
                num2[j] %= self.MOD
            num = num2
        
        return sum(num) % self.MOD


if __name__ == '__main__':
    sol = id3()
    sol.run()
