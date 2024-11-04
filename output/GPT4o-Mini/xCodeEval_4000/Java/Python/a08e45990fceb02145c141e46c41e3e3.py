import sys
import random
from collections import defaultdict

class B:
    ENTER = "+"
    EXIT = "-"
    
    def __init__(self):
        self.n = 0
        self.m = 0
        self.can_be_leader = []
        self.input_events = []
        self.was_before = set()
        self.used = []
    
    def solve(self):
        self.n = self.read_int()
        self.m = self.read_int()
        
        self.can_be_leader = [True] * self.n
        self.input_events = [None] * self.m
        
        for i in range(self.m):
            event_type = self.read_string()
            index = self.read_int() - 1
            self.input_events[i] = (event_type, index)
        
        meeting_size = 0
        self.used = [False] * self.n
        
        for event_type, index in self.input_events:
            if event_type == self.EXIT and not self.used[index]:
                self.was_before.add(index)
            self.used[index] = True
        
        zeros = set()
        
        meeting_size = len(self.was_before)
        for event_type, index in self.input_events:
            if event_type == self.ENTER:
                if meeting_size != 0:
                    self.can_be_leader[index] = False
                else:
                    zeros.add(index)
                meeting_size += 1
            else:
                meeting_size -= 1
                if meeting_size != 0:
                    self.can_be_leader[index] = False
                else:
                    zeros.add(index)
        
        if len(zeros) > 1:
            for index in zeros:
                self.can_be_leader[index] = False
        elif len(zeros) == 1:
            zero_enter = next(iter(zeros))
            if len(self.was_before) > 0 and zero_enter not in self.was_before:
                self.can_be_leader[zero_enter] = False
        
        possible_leaders = [i for i in range(self.n) if self.can_be_leader[i]]
        
        print(len(possible_leaders))
        print(" ".join(str(leader + 1) for leader in possible_leaders))
    
    def read_string(self):
        return input().strip()
    
    def read_int(self):
        return int(input().strip())
    
    def run(self):
        try:
            self.solve()
        except Exception as e:
            print(e, file=sys.stderr)
            sys.exit(-1)

if __name__ == "__main__":
    B().run()
