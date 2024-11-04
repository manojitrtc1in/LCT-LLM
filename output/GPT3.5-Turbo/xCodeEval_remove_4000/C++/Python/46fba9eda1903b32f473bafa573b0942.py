from math import inf
from collections import defaultdict

class ordered_set:
    def __init__(self):
        self.tree = defaultdict(int)
    
    def insert(self, val):
        self.tree[val] += 1
    
    def erase(self, val):
        if self.tree[val] > 0:
            self.tree[val] -= 1
    
    def order_of_key(self, val):
        count = 0
        for key in self.tree:
            if key < val:
                count += self.tree[key]
        return count
    
    def find_by_order(self, k):
        count = 0
        for key in self.tree:
            count += self.tree[key]
            if count > k:
                return key
        return -1

def yes():
    print("Yes")

def no():
    print("No")

def main():
    a = int(input())
    n = int(1e17)
    n *= 18
    n %= a
    k = n

    for i in range(44):
        n = (n + k) % a

    if n < 0:
        n += a
    c = a - n
    d = c + int(1e18) - 1
    print(c, d)

if __name__ == "__main__":
    main()
