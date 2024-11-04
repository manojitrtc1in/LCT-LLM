import sys
import random

class Abra:
    def __init__(self):
        self.selection_time = 0

    def start_selection(self):
        self.selection_time -= self.current_time()

    def stop_selection(self):
        self.selection_time += self.current_time()

    def current_time(self):
        import time
        return int(round(time.time() * 1000))

    def run(self):
        begin_time = self.current_time()
        self.init()
        self.solve()
        end_time = self.current_time()
        if not self.oj:
            print("Memory used =", self.memory_used())
            print("Running time =", end_time - begin_time)
            print("Time of the selection =", self.selection_time)

    def memory_used(self):
        import os, psutil
        process = psutil.Process(os.getpid())
        return process.memory_info().rss

    def next_int(self):
        return int(self.next_token())

    def next_long(self):
        return int(self.next_token())

    def next_string(self):
        return self.next_token()

    def next_double(self):
        return float(self.next_token())

    def next_token(self):
        return self.br.readline().strip()

    def init(self):
        self.oj = 'ONLINE_JUDGE' in os.environ
        if self.oj:
            self.br = sys.stdin
            self.out = sys.stdout
        else:
            self.br = open("input.txt", "r")
            self.out = open("output.txt", "w")

    def solve(self):
        w = self.next_int()
        if w == 2:
            self.out.write("NO\n")
            return
        if w % 2 == 0:
            self.out.write("YES\n")
        else:
            self.out.write("NO\n")

if __name__ == "__main__":
    Abra().run()
