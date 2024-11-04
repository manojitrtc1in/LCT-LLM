class ListNode:
    def __init__(self):
        self.prev = None
        self.next = None

class SplayNode:
    def __init__(self):
        self.lc = None
        self.rc = None
        self.p = None
        self.size = 1

    def update_size(self):
        self.size = 1
        if self.lc:
            self.size += self.lc.size
        if self.rc:
            self.size += self.rc.size

class SplayTree:
    def __init__(self):
        self.root = None

    def rotate(self, x):
        y = x.p
        if y:
            if x == y.lc:
                y.lc = x.rc
                if x.rc:
                    x.rc.p = y
                x.rc = y
            else:
                y.rc = x.lc
                if x.lc:
                    x.lc.p = y
                x.lc = y
            x.p = y.p
            y.p = x
            if x.p:
                if x == x.p.lc:
                    x.p.lc = x
                else:
                    x.p.rc = x
            else:
                self.root = x
            y.update_size()
            x.update_size()

    def splay(self, x):
        while x.p:
            if x.p.p:
                if (x.p.lc == x) == (x.p.p.lc == x.p):
                    self.rotate(x.p)
                else:
                    self.rotate(x)
            self.rotate(x)

    def insert(self, node):
        if not self.root:
            self.root = node
            return
        current = self.root
        while True:
            if node.v < current.v:
                if current.lc:
                    current = current.lc
                else:
                    current.lc = node
                    node.p = current
                    break
            else:
                if current.rc:
                    current = current.rc
                else:
                    current.rc = node
                    node.p = current
                    break
        self.splay(node)

    def erase(self, node):
        self.splay(node)
        if not node.lc:
            self.root = node.rc
            if self.root:
                self.root.p = None
        else:
            max_node = node.lc
            while max_node.rc:
                max_node = max_node.rc
            self.splay(max_node)
            max_node.rc = node.rc
            if node.rc:
                node.rc.p = max_node
            self.root = max_node

    def find_nth(self, k):
        p = self.root
        while p:
            lsize = p.lc.size if p.lc else 0
            if k < lsize:
                p = p.lc
            elif k == lsize:
                self.splay(p)
                return p
            else:
                k -= lsize + 1
                p = p.rc
        return None

class Node:
    def __init__(self, v, pos):
        self.lh = ListNode()
        self.sh = SplayNode()
        self.v = v
        self.pos = pos

def main():
    n = int(input())
    arr = [Node(0, i) for i in range(n)]
    splay = SplayTree()
    lst = ListNode()
    lst.prev = lst
    lst.next = lst

    for i in range(n):
        v = int(input())
        arr[i].v = v
        splay.insert(arr[i])
        arr[i].lh.prev = lst
        arr[i].lh.next = lst.next
        lst.next.prev = arr[i].lh
        lst.next = arr[i].lh

    last_left = 0
    last_right = 0
    ans = 0

    while splay.root:
        it = splay.root
        left = it.lh.next.pos if it.lh.next != lst else None
        right = it.lh.prev.pos if it.lh.prev != lst else None
        splay.erase(it)

        if it.pos == left and it.pos == right:
            ans += min(last_left, last_right)
        elif it.pos == left:
            ans += last_left
            last_left = it.v
        elif it.pos == right:
            ans += last_right
            last_right = it.v
        else:
            ans += min(arr[it.lh.next.pos].v, arr[it.lh.prev.pos].v)

    print(ans)

if __name__ == "__main__":
    main()
