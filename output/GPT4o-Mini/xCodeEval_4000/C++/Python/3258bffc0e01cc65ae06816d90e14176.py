import sys
import time
from collections import defaultdict

def control_io():
    global infile, outfile
    infile = "FILE.IN"
    outfile = "FILE.OUT"
    
    if len(sys.argv) > 1:
        infile = sys.argv[1]
    if len(sys.argv) > 2:
        outfile = sys.argv[2]
    
    if 'Akikaze' in globals():
        print("Source code by #Team4T-Akikaze.")
        print("Current time:", time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()))
        print("\n")
        if 'OImode' in globals():
            print("OI-Mode: ON")
            print("Input file:", infile)
            print("Output file:", outfile)
            print("\n")
        else:
            print("OI-Mode: OFF")
            print("Input file: NULL")
            print("Output file: NULL")
            print("\n")
        if 'MultiTest' in globals():
            print("MultiTest-Mode: ON")
        else:
            print("MultiTest-Mode: OFF")
        
        if 'Interactive' in globals():
            print("Interactive-Mode: ON\n")
        else:
            print("Interactive-Mode: OFF\n")
    
    sys.stdin = open(infile, 'r')
    sys.stdout = open(outfile, 'w')

def timer_start():
    global time_start
    if 'Akikaze' in globals():
        time_start = time.time()

def timer_stop():
    if 'Akikaze' in globals():
        elapsed_time = time.time() - time_start
        print("\n\nTime elapsed:", elapsed_time, "seconds.")

def input_data():
    global s
    s = input().strip()

def solve():
    global q
    q = 0
    base_answer = 1
    char_count = defaultdict(int)

    for x in s:
        if '0' <= x <= '9':
            continue
        if x == '?':
            q += 1
            continue
        char_count[x] += 1

    for i in range(10, 10 - len(char_count), -1):
        base_answer *= i

    if 'A' <= s[0] <= 'J':
        base_answer //= 10
        base_answer *= 9
    if s[0] == '?':
        base_answer *= 9
        q -= 1

    print(base_answer, end='')
    print('0' * q)

def main():
    control_io()
    
    if 'Interactive' not in globals():
        timer_start()
    
    if 'MultiTest' in globals():
        T = int(input())
        for _ in range(T):
            input_data()
            solve()
    else:
        input_data()
        solve()

    if 'Interactive' not in globals():
        timer_stop()

if __name__ == "__main__":
    main()
