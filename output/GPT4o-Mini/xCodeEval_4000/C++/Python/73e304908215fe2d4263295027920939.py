import sys
import time
from collections import deque

def control_io():
    global infile, outfile
    infile = "FILE.IN"
    outfile = "FILE.OUT"
    
    if len(sys.argv) > 1:
        infile = sys.argv[1]
    if len(sys.argv) > 2:
        outfile = sys.argv[2]

    if infile != "NULL":
        sys.stdin = open(infile, 'r')
    if outfile != "NULL":
        sys.stdout = open(outfile, 'w')

def timer_start():
    global time_start
    time_start = time.time()

def timer_stop():
    elapsed_time = time.time() - time_start
    print(f"\n\nTime elapsed: {elapsed_time} seconds.")

def input_data():
    global m, h1, a1, x1, y1, h2, a2, x2, y2, vis1, vis2
    m, h1, a1, x1, y1 = map(int, input().split())
    h2, a2, x2, y2 = map(int, input().split())
    vis1 = [-1] * m
    vis2 = [-1] * m

def solve():
    global h1, h2, vis1, vis2
    vis1[h1] = 0
    cycle_start1 = -1
    cycle_len1 = -1
    
    while True:
        z = (h1 * x1 + y1) % m
        if vis1[z] != -1:
            cycle_start1 = vis1[z]
            cycle_len1 = (vis1[h1] + 1) - vis1[z]
            break
        else:
            vis1[z] = vis1[h1] + 1
        h1 = z

    vis2[h2] = 0
    cycle_start2 = -1
    cycle_len2 = -1
    
    while True:
        z = (h2 * x2 + y2) % m
        if vis2[z] != -1:
            cycle_start2 = vis2[z]
            cycle_len2 = (vis2[h2] + 1) - vis2[z]
            break
        else:
            vis2[z] = vis2[h2] + 1
        h2 = z

    if vis1[a1] == -1 or vis2[a2] == -1:
        print("-1")
        return

    if vis1[a1] < cycle_start1 and vis2[a2] < cycle_start2:
        if vis1[a1] == vis2[a2]:
            print(vis1[a1])
        else:
            print("-1")
        return

    if vis1[a1] >= cycle_start1 and vis2[a2] >= cycle_start2:
        ans = -1
        for i in range(1000001):
            expected = vis1[a1] + cycle_len1 * i
            if (expected - vis2[a2]) % cycle_len2 == 0 and (expected - vis2[a2]) // cycle_len2 >= 0:
                ans = expected
                break
        print(ans)
        return

    if vis1[a1] < cycle_start1 and vis2[a2] >= cycle_start2:
        if (vis1[a1] - vis2[a2]) % cycle_len2 == 0 and (vis1[a1] - vis2[a2]) // cycle_len2 >= 0:
            print(vis1[a1])
        else:
            print("-1")
        return

    if vis1[a1] >= cycle_start1 and vis2[a2] < cycle_start2:
        if (vis2[a2] - vis1[a1]) % cycle_len1 == 0 and (vis2[a2] - vis1[a1]) // cycle_len1 >= 0:
            print(vis2[a2])
        else:
            print("-1")
        return

if __name__ == "__main__":
    control_io()
    timer_start()
    
    if 'MultiTest' in globals():
        T = int(input())
        for _ in range(T):
            input_data()
            solve()
    else:
        input_data()
        solve()
    
    timer_stop()
