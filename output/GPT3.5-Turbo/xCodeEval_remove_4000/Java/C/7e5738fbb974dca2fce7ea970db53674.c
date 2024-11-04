#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100000

struct TrieNode {
    struct TrieNode* children[26];
    bool isEndOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(struct TrieNode* root, char* word) {
    struct TrieNode* current = root;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

bool search(struct TrieNode* root, char* word) {
    struct TrieNode* current = root;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
    }
    return current->isEndOfWord;
}

bool delete(struct TrieNode* root, char* word) {
    struct TrieNode* current = root;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
    }
    if (current->isEndOfWord == false) {
        return false;
    }
    current->isEndOfWord = false;
    for (int i = 0; i < 26; i++) {
        if (current->children[i] != NULL) {
            return true;
        }
    }
    return true;
}

int main() {
    struct TrieNode* root = createNode();

    insert(root, "hello");
    insert(root, "world");

    printf("Search 'hello': %s\n", search(root, "hello") ? "Found" : "Not Found");
    printf("Search 'world': %s\n", search(root, "world") ? "Found" : "Not Found");
    printf("Search 'hi': %s\n", search(root, "hi") ? "Found" : "Not Found");

    delete(root, "hello");
    printf("Search 'hello' after deletion: %s\n", search(root, "hello") ? "Found" : "Not Found");

    return 0;
}
