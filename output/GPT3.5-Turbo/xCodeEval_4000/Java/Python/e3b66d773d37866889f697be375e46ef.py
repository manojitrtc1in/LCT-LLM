import sys

class Scanner:
    def __init__(self, file=None):
        if file:
            self.br = open(file, 'r')
        else:
            self.br = sys.stdin
        self.st = None

    def next(self):
        while self.st is None or not self.st:
            self.st = self.br.readline().split()
        return self.st.pop(0)

    def nextLine(self):
        return self.br.readline().strip()

    def nextInt(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextChar(self):
        return self.next()[0]

    def nextLong(self):
        return int(self.next())

    def ready(self):
        return self.br.ready()

    def waitForInput(self):
        import time
        time.sleep(3)

    def nxtArr(self, n):
        return [self.nextInt() for _ in range(n)]

class Main:
    def __init__(self):
        self.mod = None
        self.notmemo = None
        self.k = None
        self.a = None
        self.b = None
        self.m = None
        self.c = None
        self.s1 = None
        self.s = None
        self.set1 = None

    def main(self):
        sc = Scanner()
        self.n = sc.nextInt()
        self.a = [0] * self.n
        for i in range(self.n):
            self.a[i] = sc.nextInt()
        self.notmemo = [[-1] * 2 for _ in range(self.n)]
        print(self.dp(0, 0))
        sys.stdout.flush()

    def dp(self, idx, state):
        if idx == self.n:
            return 0
        if self.notmemo[idx][state] != -1:
            return self.notmemo[idx][state]
        take = 0
        leave = 0
        leaveall = 0
        if self.a[idx] == 1 and (state == 1 or state == 0):
            take = 1 + self.dp(idx + 1, 1)
        if self.a[idx] == 0 and state == 0:
            leave = 1 + self.dp(idx + 1, state)
        leaveall = self.dp(idx + 1, state)
        self.notmemo[idx][state] = max(take, max(leaveall, leave))
        return self.notmemo[idx][state]

if __name__ == "__main__":
    obj = Main()
    obj.main()
