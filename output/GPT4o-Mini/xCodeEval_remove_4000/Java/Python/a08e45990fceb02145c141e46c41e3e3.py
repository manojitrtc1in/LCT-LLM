import sys
import random
from collections import defaultdict

class B:
    ENTER = "+"
    EXIT = "-"
    
    def __init__(self):
        self.rnd = random.Random()
        self.file_name = ""
        self.id33 = []
        self.input_events = []
        self.were_before = set()
        self.used = []
        self.zeros = set()
    
    def solve(self):
        n = self.read_int()
        m = self.read_int()
        
        self.id33 = [True] * n
        self.input_events = [self.Event(self.read_string(), self.read_int() - 1) for _ in range(m)]
        
        self.used = [False] * n
        for input_event in self.input_events:
            if not input_event.enter and not self.used[input_event.index]:
                self.were_before.add(input_event.index)
            self.used[input_event.index] = True
        
        meeting_size = len(self.were_before)
        for event in self.input_events:
            if event.enter:
                if meeting_size != 0:
                    self.id33[event.index] = False
                else:
                    self.zeros.add(event.index)
                meeting_size += 1
            else:
                meeting_size -= 1
                if meeting_size != 0:
                    self.id33[event.index] = False
                else:
                    self.zeros.add(event.index)
        
        if len(self.zeros) > 1:
            for index in self.zeros:
                self.id33[index] = False
        elif len(self.zeros) == 1:
            zero_enter = next(iter(self.zeros))
            if self.were_before and zero_enter not in self.were_before:
                self.id33[zero_enter] = False
        
        id14 = [i for i in range(n) if self.id33[i]]
        print(len(id14))
        print(" ".join(str(leader + 1) for leader in id14))
    
    class Event:
        def __init__(self, type, index):
            self.enter = (type == B.ENTER)
            self.index = index
    
    def read_line(self):
        return sys.stdin.readline().strip()
    
    def read_string(self):
        return self.read_line()
    
    def read_int(self):
        return int(self.read_string())
    
    def run(self):
        try:
            self.solve()
        except Exception as e:
            print(e, file=sys.stderr)
            sys.exit(-1)

if __name__ == "__main__":
    B().run()
