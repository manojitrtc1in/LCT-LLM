import sys
from collections import defaultdict
import math

MOD = 1000000007

class FastReader:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.buffer = []
    
    def next(self):
        while not self.buffer:
            line = self.input_stream.readline()
            if not line:
                return ""
            self.buffer = line.split()
        return self.buffer.pop(0)
    
    def next_int(self):
        return int(self.next())
    
    def next_long(self):
        return int(self.next())
    
    def next_double(self):
        return float(self.next())
    
    def next_line(self):
        return self.input_stream.readline().strip()

def cnt(v, n):
    if v > n:
        return 0
    
    count = 0
    if v % 2 == 1:
        seg_size = 1
        start = v
        while start <= n:
            end = min(n, start + seg_size - 1)
            count += end - start + 1
            
            seg_size *= 2
            start *= 2
    else:
        seg_size = 2
        start = v
        while start <= n:
            end = min(n, start + seg_size - 1)
            count += end - start + 1
            
            seg_size *= 2
            start *= 2
    
    return count

def main():
    input_stream = sys.stdin
    in_reader = FastReader(input_stream)
    
    nt = 1
    for _ in range(nt):
        n = in_reader.next_long()
        k = in_reader.next_long()
        
        if k == 1:
            print(n)
            return
        
        lo, hi = 1, n // 2
        
        while lo <= hi:
            mid = (hi + lo) // 2
            val = mid * 2 - 1
            
            if cnt(val, n) >= k:
                lo = mid + 1
            else:
                hi = mid - 1
        
        cand = hi * 2 - 1
        if cnt(cand, n) < k:
            cand = 0
        
        lo, hi = 1, n // 2
        
        while lo <= hi:
            mid = (hi + lo) // 2
            val = mid * 2
            if cnt(val, n) >= k:
                lo = mid + 1
            else:
                hi = mid - 1
        
        cand = max(cand, hi * 2)
        print(cand)

if __name__ == "__main__":
    main()
