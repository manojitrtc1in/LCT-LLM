import random
import math

def solve():
    lim = [0, 9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099]
    pr1 = ["", "198", "19", "2", "", "", "", "", "", ""]
    pr2 = ["", "199", "20", "3", "1", "1", "1", "1", "1", "1"]
    
    x = int(s)
    if x >= lim[n]:
        return pr1[n] + s
    else:
        return pr2[n] + s

def read():
    global s, n
    s = input().strip()
    s = s[4:]
    n = len(s)
    return True

def main():
    random.seed()
    
    tc = int(input())
    while tc > 0:
        read()
        while read():
            print(solve())
        tc -= 1

if __name__ == "__main__":
    main()
