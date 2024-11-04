class ListNode:
    def __init__(self, val=0, pos=0):
        self.val = val
        self.pos = pos
        self.next = None
        self.prev = None

class SplayNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
        self.size = 1

class SplayTree:
    def __init__(self):
        self.root = None

    def left_rotate(self, x):
        y = x.parent
        y_right = x.right
        if y.parent is not None:
            if y == y.parent.left:
                y.parent.left = x
            else:
                y.parent.right = x
        x.parent = y.parent
        x.right = y
        y.parent = x
        y.left = y_right
        if y_right is not None:
            y_right.parent = y
        y.size = 1
        if y.left is not None:
            y.size += y.left.size
        if y.right is not None:
            y.size += y.right.size

    def right_rotate(self, x):
        y = x.parent
        y_left = x.left
        if y.parent is not None:
            if y == y.parent.left:
                y.parent.left = x
            else:
                y.parent.right = x
        x.parent = y.parent
        x.left = y
        y.parent = x
        y.right = y_left
        if y_left is not None:
            y_left.parent = y
        y.size = 1
        if y.left is not None:
            y.size += y.left.size
        if y.right is not None:
            y.size += y.right.size

    def splay(self, x):
        while x.parent is not None:
            if x.parent.parent is None:
                if x == x.parent.left:
                    self.right_rotate(x.parent)
                else:
                    self.left_rotate(x.parent)
            elif x == x.parent.left and x.parent == x.parent.parent.left:
                self.right_rotate(x.parent.parent)
                self.right_rotate(x.parent)
            elif x == x.parent.right and x.parent == x.parent.parent.right:
                self.left_rotate(x.parent.parent)
                self.left_rotate(x.parent)
            elif x == x.parent.right and x.parent == x.parent.parent.left:
                self.left_rotate(x.parent)
                self.right_rotate(x.parent)
            else:
                self.right_rotate(x.parent)
                self.left_rotate(x.parent)

    def insert(self, val):
        new_node = SplayNode(val)
        if self.root is None:
            self.root = new_node
            return
        curr = self.root
        while True:
            curr.size += 1
            if val < curr.val:
                if curr.left is None:
                    curr.left = new_node
                    new_node.parent = curr
                    break
                else:
                    curr = curr.left
            else:
                if curr.right is None:
                    curr.right = new_node
                    new_node.parent = curr
                    break
                else:
                    curr = curr.right
        self.splay(new_node)

    def find(self, val):
        curr = self.root
        while curr is not None:
            if val < curr.val:
                curr = curr.left
            elif val > curr.val:
                curr = curr.right
            else:
                self.splay(curr)
                return curr
        return None

    def erase(self, val):
        node = self.find(val)
        if node is None:
            return
        self.splay(node)
        if node.left is None:
            self.root = node.right
            if self.root is not None:
                self.root.parent = None
        elif node.right is None:
            self.root = node.left
            if self.root is not None:
                self.root.parent = None
        else:
            left_subtree = node.left
            left_subtree.parent = None
            right_subtree = node.right
            right_subtree.parent = None
            self.root = left_subtree
            self.find(float('inf'))
            self.root.right = right_subtree
            right_subtree.parent = self.root
            self.root.size = 1
            if self.root.right is not None:
                self.root.size += self.root.right.size

def solve():
    n = int(input())
    arr = []
    for i in range(n):
        v = int(input())
        arr.append(ListNode(v, i))
    lst = ListNode()
    lst.next = arr[0]
    arr[0].prev = lst
    for i in range(1, n):
        arr[i].prev = arr[i-1]
        arr[i-1].next = arr[i]
    splay = SplayTree()
    for i in range(n):
        splay.insert(arr[i].val)
    last_left = 0
    last_right = 0
    ans = 0
    while splay.root is not None:
        it = splay.root
        lit = it.next
        root = lst.next
        left = root.next.pos
        right = root.prev.pos
        splay.erase(it.val)
        if it.pos == left and it.pos == right:
            ans += min(last_left, last_right)
        elif it.pos == left:
            ans += last_left
            last_left = it.val
        elif it.pos == right:
            ans += last_right
            last_right = it.val
        else:
            ans += min(lit.val, lit.prev.val)
        it.prev.next = it.next
        it.next.prev = it.prev
    print(ans)

solve()
