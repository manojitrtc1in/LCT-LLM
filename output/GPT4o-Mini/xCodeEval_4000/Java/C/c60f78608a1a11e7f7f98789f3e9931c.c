#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BIG 1000000007

typedef struct Point {
    int index;
    int x;
    int y;
} Point;

typedef struct Node {
    Point point;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} PointList;

typedef struct {
    int size;
    Point* points;
} PointArray;

PointArray createPointArray(int n) {
    PointArray arr;
    arr.size = n;
    arr.points = (Point*)malloc(n * sizeof(Point));
    return arr;
}

PointList createPointList() {
    PointList list;
    list.head = NULL;
    return list;
}

void addPoint(PointList* list, Point point) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->point = point;
    newNode->next = list->head;
    list->head = newNode;
}

void freePointList(PointList* list) {
    Node* current = list->head;
