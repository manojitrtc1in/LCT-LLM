from math import gcd

MOD = int(1e9) + 7
INF = int(1e18)

def yes():
    print("Yes")

def no():
    print("No")

class ordered_set:
    def __init__(self):
        self.tree = []
    
    def insert(self, x):
        self.tree.append(x)
    
    def erase(self, x):
        self.tree.remove(x)
    
    def order_of_key(self, x):
        count = 0
        for num in self.tree:
            if num < x:
                count += 1
        return count
    
    def find_by_order(self, k):
        return self.tree[k]

def main():
    a = int(input())
    n = int(1e17) * 18 % a
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
