class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        current = self.root
        for ch in word:
            if ch not in current.children:
                current.children[ch] = TrieNode()
            current = current.children[ch]
        current.endOfWord = True

    def search(self, word):
        current = self.root
        for ch in word:
            if ch not in current.children:
                return False
            current = current.children[ch]
        return current.endOfWord

    def delete(self, word):
        self._delete(self.root, word, 0)

    def _delete(self, current, word, index):
        if index == len(word):
            if not current.endOfWord:
                return False
            current.endOfWord = False
            return len(current.children) == 0

        ch = word[index]
        if ch not in current.children:
            return False

        shouldDeleteCurrentNode = self._delete(current.children[ch], word, index + 1)

        if shouldDeleteCurrentNode:
            del current.children[ch]
            return len(current.children) == 0

        return False
