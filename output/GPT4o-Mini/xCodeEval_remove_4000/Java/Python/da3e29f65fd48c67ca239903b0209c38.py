import sys
from math import gcd
from functools import reduce

class IO:
    @staticmethod
    def read_int():
        return int(sys.stdin.readline().strip())

class Main(IO):
    @staticmethod
    def main():
        g = IO.read_int()
        sh = IO.read_int()
        j = IO.read_int()
        p = IO.read_int()
        price_first = IO.read_int()
        price_second = IO.read_int()
        answer = 0
        
        if price_first <= price_second:
            answer = min(sh, j, p)
            p -= answer
            answer *= price_second
            answer += min(p, g) * price_first
        else:
            answer = min(g, p)
            p -= answer
            answer *= price_first
            answer += min(sh, j, p) * price_second
        
        print(answer)

if __name__ == "__main__":
    Main.main()
