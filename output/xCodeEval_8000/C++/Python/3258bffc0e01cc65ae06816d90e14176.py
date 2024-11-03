import sys
import time

def getbit(s, i):
    return (s >> i) & 1

def onbit(s, i):
    return s | (1 << i)

def offbit(s, i):
    return s & (~(1 << i))

def cntbit(s):
    return bin(s).count('1')

def control_io():
    cppstr_infile = "FILE.IN"
    cppstr_outfile = "FILE.OUT"
    infile = cppstr_infile.encode()
    outfile = cppstr_outfile.encode()
    sys.stdin = open(infile, "r")
    sys.stdout = open(outfile, "w")

def timer_start():
    global TimeStart
    TimeStart = time.time()

def timer_stop():
    global TimeEnd
    TimeEnd = time.time()
    elapsed_time = TimeEnd - TimeStart
    print("\n\nTime elapsed: {} seconds.".format(elapsed_time))

def exit_program():
    timer_stop()
    sys.exit(0)

def input():
    global s
    s = sys.stdin.readline().strip()

def solve():
    base_answer = 1
    q = 0
    Map = {}
    for x in s:
        if x >= '0' and x <= '9':
            continue
        if x == '?':
            q += 1
            continue
        if x in Map:
            Map[x] += 1
        else:
            Map[x] = 1
    for i in range(10, 10 - len(Map), -1):
        base_answer *= i
    if s[0] >= 'A' and s[0] <= 'J':
        base_answer //= 10
        base_answer *= 9
    if s[0] == '?':
        base_answer *= 9
        q -= 1
    print(base_answer, end='')
    for i in range(q):
        print('0', end='')

def main():
    control_io()

    input()
    timer_start()
    solve()
    timer_stop()

if __name__ == "__main__":
    main()
