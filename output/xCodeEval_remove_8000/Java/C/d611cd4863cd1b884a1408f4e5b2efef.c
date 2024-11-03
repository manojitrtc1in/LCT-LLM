#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    void* key;
    void* value;
    struct Node* next;
} Node;

typedef struct {
    int size;
    Node** data;
    int capacity;
} HashMap;

HashMap* createHashMap(int maxSize) {
    HashMap* hashMap = (HashMap*)malloc(sizeof(HashMap));
    hashMap->size = 0;
    hashMap->capacity = maxSize;
    hashMap->data = (Node**)malloc(sizeof(Node*) * maxSize);
    for (int i = 0; i < maxSize; i++) {
        hashMap->data[i] = NULL;
    }
    return hashMap;
}

int hashCode(int key) {
    return key;
}

int getIndex(HashMap* hashMap, int key) {
    int index = hashCode(key) % hashMap->capacity;
    if (index < 0) {
        index += hashMap->capacity;
    }
    return index;
}

void put(HashMap* hashMap, int key, int value) {
    int index = getIndex(hashMap, key);
    Node* current = hashMap->data[index];
    while (current != NULL) {
        if (*(int*)current->key == key) {
            *(int*)current->value = value;
            return;
        }
        current = current->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = malloc(sizeof(int));
    newNode->value = malloc(sizeof(int));
    *(int*)newNode->key = key;
    *(int*)newNode->value = value;
    newNode->next = hashMap->data[index];
    hashMap->data[index] = newNode;
    hashMap->size++;
}

int get(HashMap* hashMap, int key) {
    int index = getIndex(hashMap, key);
    Node* current = hashMap->data[index];
    while (current != NULL) {
        if (*(int*)current->key == key) {
            return *(int*)current->value;
        }
        current = current->next;
    }
    return -1;
}

bool containsKey(HashMap* hashMap, int key) {
    int index = getIndex(hashMap, key);
    Node* current = hashMap->data[index];
    while (current != NULL) {
        if (*(int*)current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void removeKey(HashMap* hashMap, int key) {
    int index = getIndex(hashMap, key);
    Node* current = hashMap->data[index];
    Node* prev = NULL;
    while (current != NULL) {
        if (*(int*)current->key == key) {
            if (prev == NULL) {
                hashMap->data[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->key);
            free(current->value);
            free(current);
            hashMap->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void clearHashMap(HashMap* hashMap) {
    for (int i = 0; i < hashMap->capacity; i++) {
        Node* current = hashMap->data[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
        hashMap->data[i] = NULL;
    }
    hashMap->size = 0;
}

void printHashMap(HashMap* hashMap) {
    for (int i = 0; i < hashMap->capacity; i++) {
        Node* current = hashMap->data[i];
        while (current != NULL) {
            printf("%d -> %d\n", *(int*)current->key, *(int*)current->value);
            current = current->next;
        }
    }
}

int main() {
    HashMap* hashMap = createHashMap(10);
    put(hashMap, 1, 10);
    put(hashMap, 2, 20);
    put(hashMap, 3, 30);
    put(hashMap, 4, 40);
    put(hashMap, 5, 50);
    put(hashMap, 6, 60);
    put(hashMap, 7, 70);
    put(hashMap, 8, 80);
    put(hashMap, 9, 90);
    put(hashMap, 10, 100);
    printHashMap(hashMap);
    printf("Value for key 5: %d\n", get(hashMap, 5));
    printf("Contains key 8: %s\n", containsKey(hashMap, 8) ? "true" : "false");
    removeKey(hashMap, 3);
    printf("After removing key 3:\n");
    printHashMap(hashMap);
    clearHashMap(hashMap);
    printf("After clearing the hashmap:\n");
    printHashMap(hashMap);
    return 0;
}
