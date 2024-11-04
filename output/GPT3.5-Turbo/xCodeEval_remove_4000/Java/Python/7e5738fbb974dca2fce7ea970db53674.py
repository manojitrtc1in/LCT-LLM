class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        current = self.root
        for ch in word:
            if ch not in current.children:
                current.children[ch] = TrieNode()
            current = current.children[ch]
        current.is_end_of_word = True

    def search(self, word):
        current = self.root
        for ch in word:
            if ch not in current.children:
                return False
            current = current.children[ch]
        return current.is_end_of_word

    def delete(self, word):
        self._delete(self.root, word, 0)

    def _delete(self, current, word, index):
        if index == len(word):
            if not current.is_end_of_word:
                return False
            current.is_end_of_word = False
            return len(current.children) == 0

        ch = word[index]
        if ch not in current.children:
            return False

        if self._delete(current.children[ch], word, index + 1):
            del current.children[ch]
            return len(current.children) == 0

        return False
