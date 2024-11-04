import sys
import math
import random

class Abra:
    def __init__(self):
        self.inp = sys.stdin
        self.out = sys.stdout
        self.oj = False
        self.br = None
        self.selectionTime = 0

    def init(self):
        self.oj = True if "ONLINE_JUDGE" in os.environ else False
        reader = sys.stdin if self.oj else open("input.txt", "r")
        writer = sys.stdout if self.oj else open("output.txt", "w")
        self.br = reader
        self.inp = reader
        self.out = writer

    def startSelection(self):
        self.selectionTime -= time.time()

    def stopSelection(self):
        self.selectionTime += time.time()

    def run(self):
        beginTime = time.time()
        self.init()
        self.solve()
        endTime = time.time()
        if not self.oj:
            self.out.write("Memory used = " + str(resource.getrusage(resource.RUSAGE_SELF).ru_maxrss / 1000) + "KB\n")
            self.out.write("Running time = " + str(endTime - beginTime) + "s\n")
            self.out.write("Time of the selection = " + str(self.selectionTime) + "s\n")
        self.out.flush()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextString(self):
        return self.next()

    def nextDouble(self):
        return float(self.next())

    def next(self):
        return self.br.readline().strip()

    def solve(self):
        w = self.nextInt()
        if w == 2:
            self.out.write("NO")
        elif w % 2 == 0:
            self.out.write("YES")
        else:
            self.out.write("NO")

if __name__ == "__main__":
    Abra().run()
