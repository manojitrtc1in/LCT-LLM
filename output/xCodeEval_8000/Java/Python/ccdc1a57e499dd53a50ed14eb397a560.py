import random
from collections.abc import MutableSet

class TreapSet(MutableSet):
    class Node:
        def __init__(self, key):
            self.key = key
            self.priority = random.random()
            self.left = None
            self.right = None

    def __init__(self, iterable=None):
        self.root = None
        self.size = 0
        if iterable is not None:
            self |= iterable

    def __contains__(self, key):
        node = self.root
        while node is not None:
            if key == node.key:
                return True
            elif key < node.key:
                node = node.left
            else:
                node = node.right
        return False

    def __iter__(self):
        stack = []
        node = self.root
        while stack or node is not None:
            if node is not None:
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                yield node.key
                node = node.right

    def __len__(self):
        return self.size

    def add(self, key):
        if self.root is None:
            self.root = self.Node(key)
            self.size += 1
            return True

        node = self.root
        parent = None
        while node is not None:
            if key == node.key:
                return False
            elif key < node.key:
                parent = node
                node = node.left
            else:
                parent = node
                node = node.right

        new_node = self.Node(key)
        if key < parent.key:
            parent.left = new_node
        else:
            parent.right = new_node

        self._sift_up(new_node)
        self.size += 1
        return True

    def discard(self, key):
        node = self.root
        parent = None
        while node is not None:
            if key == node.key:
                self._sift_down(node)
                if parent is None:
                    self.root = None
                elif parent.left == node:
                    parent.left = None
                else:
                    parent.right = None
                self.size -= 1
                return
            elif key < node.key:
                parent = node
                node = node.left
            else:
                parent = node
                node = node.right

    def _sift_up(self, node):
        while node is not self.root and node.priority < node.parent.priority:
            if node.parent.left == node:
                self._rotate_right(node.parent)
            else:
                self._rotate_left(node.parent)

    def _sift_down(self, node):
        while True:
            if node.left is None and node.right is None:
                break
            elif node.left is None:
                self._rotate_left(node)
            elif node.right is None:
                self._rotate_right(node)
            elif node.left.priority < node.right.priority:
                self._rotate_right(node)
            else:
                self._rotate_left(node)

    def _rotate_left(self, node):
        parent = node.parent
        child = node.right
        if parent is not None:
            if parent.left == node:
                parent.left = child
            else:
                parent.right = child
        else:
            self.root = child
        child.parent = parent
        node.right = child.left
        if child.left is not None:
            child.left.parent = node
        child.left = node
        node.parent = child

    def _rotate_right(self, node):
        parent = node.parent
        child = node.left
        if parent is not None:
            if parent.left == node:
                parent.left = child
            else:
                parent.right = child
        else:
            self.root = child
        child.parent = parent
        node.left = child.right
        if child.right is not None:
            child.right.parent = node
        child.right = node
        node.parent = child

    def __repr__(self):
        return f"TreapSet({list(self)})"
