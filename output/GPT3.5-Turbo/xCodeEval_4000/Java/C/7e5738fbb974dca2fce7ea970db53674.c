#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TrieNode {
    struct TrieNode* children[26];
    int endOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->endOfWord = 0;
    return node;
}

void insert(struct TrieNode* root, char* word) {
    struct TrieNode* current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->endOfWord = 1;
}

int search(struct TrieNode* root, char* word) {
    struct TrieNode* current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->endOfWord;
}

void delete(struct TrieNode* root, char* word) {
    struct TrieNode* current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return;
        }
        current = current->children[index];
    }
    current->endOfWord = 0;
}

int main() {
    struct TrieNode* root = createNode();

    insert(root, "hello");
    insert(root, "world");

    printf("%d\n", search(root, "hello")); // Output: 1
    printf("%d\n", search(root, "world")); // Output: 1
    printf("%d\n", search(root, "hi")); // Output: 0

    delete(root, "hello");

    printf("%d\n", search(root, "hello")); // Output: 0

    return 0;
}
