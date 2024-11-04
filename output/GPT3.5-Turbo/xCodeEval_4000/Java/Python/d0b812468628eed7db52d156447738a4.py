import sys
from collections import deque

class Kattio:
    def __init__(self, problemName=None):
        self.r = sys.stdin
        self.w = sys.stdout
        if problemName is not None:
            self.r = open(problemName + ".in", "r")
            self.w = open(problemName + ".out", "w")
        self.done = False

    def nextLine(self):
        return self.r.readline().strip()

    def next(self):
        return self.r.readline().strip()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def write(self, s):
        self.w.write(s)

    def flush(self):
        self.w.flush()

    def close(self):
        if not self.done:
            self.r.close()
            self.w.close()
            self.done = True

class IceCave:
    class RedBlackNode:
        BLACK = 0
        RED = 1

        def __init__(self, key=None):
            self.key = key
            self.parent = None
            self.left = None
            self.right = None
            self.numLeft = 0
            self.numRight = 0
            self.color = self.BLACK

    class RedBlackTree:
        def __init__(self):
            self.nil = IceCave.RedBlackNode()
            self.root = self.nil
            self.nil.left = self.nil
            self.nil.right = self.nil
            self.nil.parent = self.nil

        def leftRotate(self, x):
            self.leftRotateFixup(x)
            y = x.right
            x.right = y.left
            if y.left != self.nil:
                y.left.parent = x
            y.parent = x.parent
            if x.parent == self.nil:
                self.root = y
            elif x.parent.left == x:
                x.parent.left = y
            else:
                x.parent.right = y
            y.left = x
            x.parent = y

        def leftRotateFixup(self, x):
            if x.left == self.nil and x.right.left == self.nil:
                x.numLeft = 0
                x.numRight = 0
                x.right.numLeft = 1
            elif x.left == self.nil and x.right.left != self.nil:
                x.numLeft = 0
                x.numRight = 1 + x.right.left.numLeft + x.right.left.numRight
                x.right.numLeft = 2 + x.right.left.numLeft + x.right.left.numRight
            elif x.left != self.nil and x.right.left == self.nil:
                x.numRight = 0
                x.right.numLeft = 2 + x.left.numLeft + x.left.numRight
            else:
                x.numRight = 1 + x.right.left.numLeft + x.right.left.numRight
                x.right.numLeft = 3 + x.left.numLeft + x.left.numRight + x.right.left.numLeft + x.right.left.numRight

        def rightRotate(self, y):
            self.rightRotateFixup(y)
            x = y.left
            y.left = x.right
            if x.right != self.nil:
                x.right.parent = y
            x.parent = y.parent
            if y.parent == self.nil:
                self.root = x
            elif y.parent.right == y:
                y.parent.right = x
            else:
                y.parent.left = x
            x.right = y
            y.parent = x

        def rightRotateFixup(self, y):
            if y.right == self.nil and y.left.right == self.nil:
                y.numRight = 0
                y.numLeft = 0
                y.left.numRight = 1
            elif y.right == self.nil and y.left.right != self.nil:
                y.numRight = 0
                y.numLeft = 1 + y.left.right.numRight + y.left.right.numLeft
                y.left.numRight = 2 + y.left.right.numRight + y.left.right.numLeft
            elif y.right != self.nil and y.left.right == self.nil:
                y.numLeft = 0
                y.left.numRight = 2 + y.right.numRight + y.right.numLeft
            else:
                y.numLeft = 1 + y.left.right.numRight + y.left.right.numLeft
                y.left.numRight = 3 + y.right.numRight + y.right.numLeft + y.left.right.numRight + y.left.right.numLeft

        def insert(self, key):
            z = IceCave.RedBlackNode(key)
            y = self.nil
            x = self.root
            while x != self.nil:
                y = x
                if z.key < x.key:
                    x.numLeft += 1
                    x = x.left
                else:
                    x.numRight += 1
                    x = x.right
            z.parent = y
            if y == self.nil:
                self.root = z
            elif z.key < y.key:
                y.left = z
            else:
                y.right = z
            z.left = self.nil
            z.right = self.nil
            z.color = IceCave.RedBlackNode.RED
            self.insertFixup(z)

        def insertFixup(self, z):
            while z.parent.color == IceCave.RedBlackNode.RED:
                if z.parent == z.parent.parent.left:
                    y = z.parent.parent.right
                    if y.color == IceCave.RedBlackNode.RED:
                        z.parent.color = IceCave.RedBlackNode.BLACK
                        y.color = IceCave.RedBlackNode.BLACK
                        z.parent.parent.color = IceCave.RedBlackNode.RED
                        z = z.parent.parent
                    elif z == z.parent.right:
                        z = z.parent
                        self.leftRotate(z)
                    else:
                        z.parent.color = IceCave.RedBlackNode.BLACK
                        z.parent.parent.color = IceCave.RedBlackNode.RED
                        self.rightRotate(z.parent.parent)
                else:
                    y = z.parent.parent.left
                    if y.color == IceCave.RedBlackNode.RED:
                        z.parent.color = IceCave.RedBlackNode.BLACK
                        y.color = IceCave.RedBlackNode.BLACK
                        z.parent.parent.color = IceCave.RedBlackNode.RED
                        z = z.parent.parent
                    elif z == z.parent.left:
                        z = z.parent
                        self.rightRotate(z)
                    else:
                        z.parent.color = IceCave.RedBlackNode.BLACK
                        z.parent.parent.color = IceCave.RedBlackNode.RED
                        self.leftRotate(z.parent.parent)
            self.root.color = IceCave.RedBlackNode.BLACK

        def treeMinimum(self, node):
            while node.left != self.nil:
                node = node.left
            return node

        def treeSuccessor(self, x):
            if x.right != self.nil:
                return self.treeMinimum(x.right)
            y = x.parent
            while y != self.nil and x == y.right:
                x = y
                y = y.parent
            return y

        def remove(self, v):
            z = self.search(v.key)
            x = None
            y = None
            if z.left == self.nil or z.right == self.nil:
                y = z
            else:
                y = self.treeSuccessor(z)
            if y.left != self.nil:
                x = y.left
            else:
                x = y.right
            x.parent = y.parent
            if y.parent == self.nil:
                self.root = x
            elif y == y.parent.left:
                y.parent.left = x
            else:
                y.parent.right = x
            if y != z:
                z.key = y.key
            self.fixNodeData(x, y)
            if y.color == IceCave.RedBlackNode.BLACK:
                self.removeFixup(x)

        def fixNodeData(self, x, y):
            current = None
            track = None
            if x == self.nil:
                current = y.parent
                track = y
            else:
                current = x.parent
                track = x
            while current != self.nil:
                if y.key != current.key:
                    if y.key > current.key:
                        current.numRight -= 1
                    if y.key < current.key:
                        current.numLeft -= 1
                else:
                    if current.left == self.nil:
                        current.numLeft -= 1
                    elif current.right == self.nil:
                        current.numRight -= 1
                    elif track == current.right:
                        current.numRight -= 1
                    elif track == current.left:
                        current.numLeft -= 1
                track = current
                current = current.parent

        def removeFixup(self, x):
            while x != self.root and x.color == IceCave.RedBlackNode.BLACK:
                if x == x.parent.left:
                    w = x.parent.right
                    if w.color == IceCave.RedBlackNode.RED:
                        w.color = IceCave.RedBlackNode.BLACK
                        x.parent.color = IceCave.RedBlackNode.RED
                        self.leftRotate(x.parent)
                        w = x.parent.right
                    if w.left.color == IceCave.RedBlackNode.BLACK and w.right.color == IceCave.RedBlackNode.BLACK:
                        w.color = IceCave.RedBlackNode.RED
                        x = x.parent
                    else:
                        if w.right.color == IceCave.RedBlackNode.BLACK:
                            w.left.color = IceCave.RedBlackNode.BLACK
                            w.color = IceCave.RedBlackNode.RED
                            self.rightRotate(w)
                            w = x.parent.right
                        w.color = x.parent.color
                        x.parent.color = IceCave.RedBlackNode.BLACK
                        w.right.color = IceCave.RedBlackNode.BLACK
                        self.leftRotate(x.parent)
                        x = self.root
                else:
                    w = x.parent.left
                    if w.color == IceCave.RedBlackNode.RED:
                        w.color = IceCave.RedBlackNode.BLACK
                        x.parent.color = IceCave.RedBlackNode.RED
                        self.rightRotate(x.parent)
                        w = x.parent.left
                    if w.right.color == IceCave.RedBlackNode.BLACK and w.left.color == IceCave.RedBlackNode.BLACK:
                        w.color = IceCave.RedBlackNode.RED
                        x = x.parent
                    else:
                        if w.left.color == IceCave.RedBlackNode.BLACK:
                            w.right.color = IceCave.RedBlackNode.BLACK
                            w.color = IceCave.RedBlackNode.RED
                            self.leftRotate(w)
                            w = x.parent.left
                        w.color = x.parent.color
                        x.parent.color = IceCave.RedBlackNode.BLACK
                        w.left.color = IceCave.RedBlackNode.BLACK
                        self.rightRotate(x.parent)
                        x = self.root
            x.color = IceCave.RedBlackNode.BLACK

    def __init__(self):
        self.input = Kattio()
        self.log = sys.stdout
        self.powerSet = []
        self.mod = int(1e9 + 7)
        self.dp = None

    def main(self):
        n = self.input.nextInt()
        w = self.input.nextLong()
        self.log.write(str(self.bfs(w, n)) + "\n")
        self.log.flush()

    def bfs(self, w, n):
        q = deque()
        q.append(w)
        h = {}
        h[w] = 0
        min_val = float('inf')
        while q:
            s = q.popleft()
            if n == len(str(s)):
                return h[s]
            t = set()
            e = str(s)
            for i in range(len(e)):
                t.add(int(e[i]))
            for x in t:
                v = x * s
                if len(str(v)) > n:
                    continue
                if v not in h:
                    h[v] = h[s] + 1
                    q.append(v)
        return -1 if min_val == float('inf') else min_val

if __name__ == "__main__":
    ice_cave = IceCave()
    ice_cave.main()
