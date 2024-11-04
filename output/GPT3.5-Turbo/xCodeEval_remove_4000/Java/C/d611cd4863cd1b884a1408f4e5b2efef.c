#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    long long key;
    long long value;
} HashEntry;

typedef struct {
    HashEntry* data[MAX_SIZE];
    int size;
} HashMap;

HashMap* createHashMap() {
    HashMap* hashMap = (HashMap*)malloc(sizeof(HashMap));
    hashMap->size = 0;
    memset(hashMap->data, 0, sizeof(hashMap->data));
    return hashMap;
}

int hashCode(long long key) {
    return key % MAX_SIZE;
}

void put(HashMap* hashMap, long long key, long long value) {
    int index = hashCode(key);
    HashEntry* entry = (HashEntry*)malloc(sizeof(HashEntry));
    entry->key = key;
    entry->value = value;
    hashMap->data[index] = entry;
    hashMap->size++;
}

long long get(HashMap* hashMap, long long key) {
    int index = hashCode(key);
    HashEntry* entry = hashMap->data[index];
    if (entry != NULL && entry->key == key) {
        return entry->value;
    }
    return -1;
}

bool containsKey(HashMap* hashMap, long long key) {
    int index = hashCode(key);
    HashEntry* entry = hashMap->data[index];
    if (entry != NULL && entry->key == key) {
        return true;
    }
    return false;
}

void removeEntry(HashMap* hashMap, long long key) {
    int index = hashCode(key);
    HashEntry* entry = hashMap->data[index];
    if (entry != NULL && entry->key == key) {
        free(entry);
        hashMap->data[index] = NULL;
        hashMap->size--;
    }
}

void clearHashMap(HashMap* hashMap) {
    for (int i = 0; i < MAX_SIZE; i++) {
        HashEntry* entry = hashMap->data[i];
        if (entry != NULL) {
            free(entry);
            hashMap->data[i] = NULL;
        }
    }
    hashMap->size = 0;
}

typedef struct {
    long long x;
    long long y;
} Point;

typedef struct {
    Point a;
    Point b;
} Segment;

typedef struct {
    Point center;
    long long radius;
} Circle;

typedef struct {
    Point vertices[100];
    int size;
} Polygon;

typedef struct {
    long long a;
    long long b;
    long long c;
} Line;

typedef struct {
    long long first;
    long long second;
} Pair;

typedef struct {
    long long key;
    long long value;
    struct HashEntry* next;
} HashEntry;

typedef struct {
    HashEntry* data[MAX_SIZE];
    int size;
} HashMap;

HashMap* createHashMap() {
    HashMap* hashMap = (HashMap*)malloc(sizeof(HashMap));
    hashMap->size = 0;
    memset(hashMap->data, 0, sizeof(hashMap->data));
    return hashMap;
}

int hashCode(long long key) {
    return key % MAX_SIZE;
}

void put(HashMap* hashMap, long long key, long long value) {
    int index = hashCode(key);
    HashEntry* entry = (HashEntry*)malloc(sizeof(HashEntry));
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    if (hashMap->data[index] == NULL) {
        hashMap->data[index] = entry;
    } else {
        HashEntry* current = hashMap->data[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = entry;
    }
    hashMap->size++;
}

long long get(HashMap* hashMap, long long key) {
    int index = hashCode(key);
    HashEntry* current = hashMap->data[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

bool containsKey(HashMap* hashMap, long long key) {
    int index = hashCode(key);
    HashEntry* current = hashMap->data[index];
    while (current != NULL) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void removeEntry(HashMap* hashMap, long long key) {
    int index = hashCode(key);
    HashEntry* current = hashMap->data[index];
    HashEntry* prev = NULL;
    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                hashMap->data[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            hashMap->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void clearHashMap(HashMap* hashMap) {
    for (int i = 0; i < MAX_SIZE; i++) {
        HashEntry* current = hashMap->data[i];
        while (current != NULL) {
            HashEntry* temp = current;
            current = current->next;
            free(temp);
        }
        hashMap->data[i] = NULL;
    }
    hashMap->size = 0;
}

int compare(long long a, long long b) {
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    } else {
        return 0;
    }
}

bool over(Point a, Point b, Point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool under(Point a, Point b, Point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

Polygon createPolygon(Point* vertices, int size) {
    Polygon polygon;
    for (int i = 0; i < size; i++) {
        polygon.vertices[i] = vertices[i];
    }
    polygon.size = size;
    return polygon;
}

bool contains(Polygon polygon, Point point) {
    for (int i = 0; i < polygon.size; i++) {
        if (over(polygon.vertices[i], polygon.vertices[(i + 1) % polygon.size], point)) {
            return false;
        }
    }
    return true;
}

bool contains(Polygon polygon, Point point, bool strict) {
    for (int i = 0; i < polygon.size; i++) {
        if (over(polygon.vertices[i], polygon.vertices[(i + 1) % polygon.size], point)) {
            return false;
        }
    }
    if (strict) {
        for (int i = 0; i < polygon.size; i++) {
            if (polygon.vertices[i].x == point.x && polygon.vertices[i].y == point.y) {
                return false;
            }
        }
    }
    return true;
}

bool contains(Polygon polygon, Circle circle) {
    for (int i = 0; i < polygon.size; i++) {
        if (circle.center.x * (polygon.vertices[i].y - polygon.vertices[(i + 1) % polygon.size].y) +
            polygon.vertices[i].x * (polygon.vertices[(i + 1) % polygon.size].y - circle.center.y) +
            polygon.vertices[(i + 1) % polygon.size].x * (circle.center.y - polygon.vertices[i].y) < 0) {
            return false;
        }
    }
    return true;
}

bool contains(Polygon polygon, Circle circle, bool strict) {
    for (int i = 0; i < polygon.size; i++) {
        if (circle.center.x * (polygon.vertices[i].y - polygon.vertices[(i + 1) % polygon.size].y) +
            polygon.vertices[i].x * (polygon.vertices[(i + 1) % polygon.size].y - circle.center.y) +
            polygon.vertices[(i + 1) % polygon.size].x * (circle.center.y - polygon.vertices[i].y) < 0) {
            return false;
        }
    }
    if (strict) {
        for (int i = 0; i < polygon.size; i++) {
            if (polygon.vertices[i].x == circle.center.x && polygon.vertices[i].y == circle.center.y) {
                return false;
            }
        }
    }
    return true;
}

bool contains(Circle circle, Point point) {
    long long distance = (circle.center.x - point.x) * (circle.center.x - point.x) +
                         (circle.center.y - point.y) * (circle.center.y - point.y);
    return distance <= circle.radius * circle.radius;
}

bool contains(Circle circle, Point point, bool strict) {
    long long distance = (circle.center.x - point.x) * (circle.center.x - point.x) +
                         (circle.center.y - point.y) * (circle.center.y - point.y);
    if (strict) {
        return distance < circle.radius * circle.radius;
    } else {
        return distance <= circle.radius * circle.radius;
    }
}

bool contains(Circle circle1, Circle circle2) {
    long long distance = (circle1.center.x - circle2.center.x) * (circle1.center.x - circle2.center.x) +
                         (circle1.center.y - circle2.center.y) * (circle1.center.y - circle2.center.y);
    return distance <= (circle1.radius - circle2.radius) * (circle1.radius - circle2.radius);
}

bool contains(Circle circle1, Circle circle2, bool strict) {
    long long distance = (circle1.center.x - circle2.center.x) * (circle1.center.x - circle2.center.x) +
                         (circle1.center.y - circle2.center.y) * (circle1.center.y - circle2.center.y);
    if (strict) {
        return distance < (circle1.radius - circle2.radius) * (circle1.radius - circle2.radius);
    } else {
        return distance <= (circle1.radius - circle2.radius) * (circle1.radius - circle2.radius);
    }
}

bool contains(Circle circle, Polygon polygon) {
    for (int i = 0; i < polygon.size; i++) {
        if (circle.center.x * (polygon.vertices[i].y - polygon.vertices[(i + 1) % polygon.size].y) +
            polygon.vertices[i].x * (polygon.vertices[(i + 1) % polygon.size].y - circle.center.y) +
            polygon.vertices[(i + 1) % polygon.size].x * (circle.center.y - polygon.vertices[i].y) < 0) {
            return false;
        }
    }
    return true;
}

bool contains(Circle circle, Polygon polygon, bool strict) {
    for (int i = 0; i < polygon.size; i++) {
        if (circle.center.x * (polygon.vertices[i].y - polygon.vertices[(i + 1) % polygon.size].y) +
            polygon.vertices[i].x * (polygon.vertices[(i + 1) % polygon.size].y - circle.center.y) +
            polygon.vertices[(i + 1) % polygon.size].x * (circle.center.y - polygon.vertices[i].y) < 0) {
            return false;
        }
    }
    if (strict) {
        for (int i = 0; i < polygon.size; i++) {
            if (polygon.vertices[i].x == circle.center.x && polygon.vertices[i].y == circle.center.y) {
                return false;
            }
        }
    }
    return true;
}

bool contains(Polygon polygon1, Polygon polygon2) {
    for (int i = 0; i < polygon2.size; i++) {
        if (!contains(polygon1, polygon2.vertices[i])) {
            return false;
        }
    }
    return true;
}

bool contains(Polygon polygon1, Polygon polygon2, bool strict) {
    for (int i = 0; i < polygon2.size; i++) {
        if (!contains(polygon1, polygon2.vertices[i], strict)) {
            return false;
        }
    }
    if (strict) {
        for (int i = 0; i < polygon1.size; i++) {
            if (!contains(polygon2, polygon1.vertices[i], strict)) {
                return false;
            }
        }
    }
    return true;
}

bool contains(Polygon polygon, Segment segment) {
    for (int i = 0; i < polygon.size; i++) {
        if (polygon.vertices[i].x * (segment.b.y - segment.a.y) +
            segment.a.x * (segment.b.y - polygon.vertices[i].y) +
            segment.b.x * (polygon.vertices[i].y - segment.a.y) < 0) {
            return false;
        }
    }
    return true;
}

bool contains(Polygon polygon, Segment segment, bool strict) {
    for (int i = 0; i < polygon.size; i++) {
        if (polygon.vertices[i].x * (segment.b.y - segment.a.y) +
            segment.a.x * (segment.b.y - polygon.vertices[i].y) +
            segment.b.x * (polygon.vertices[i].y - segment.a.y) < 0) {
            return false;
        }
    }
    if (strict) {
        for (int i = 0; i < polygon.size; i++) {
            if ((polygon.vertices[i].x == segment.a.x && polygon.vertices[i].y == segment.a.y) ||
                (polygon.vertices[i].x == segment.b.x && polygon.vertices[i].y == segment.b.y)) {
                return false;
            }
        }
    }
    return true;
}

bool contains(Segment segment, Point point) {
    if (segment.a.x == point.x && segment.a.y == point.y) {
        return true;
    }
    if (segment.b.x == point.x && segment.b.y == point.y) {
        return true;
    }
    if (segment.a.x == segment.b.x && segment.a.y == segment.b.y) {
        return false;
    }
    if (segment.a.x == point.x) {
        return (segment.a.y - point.y) * (segment.b.x - point.x) ==
               (segment.b.y - point.y) * (segment.a.x - point.x);
    }
    if (segment.b.x == point.x) {
        return (segment.a.y - point.y) * (segment.b.x - point.x) ==
               (segment.b.y - point.y) * (segment.a.x - point.x);
    }
    return false;
}

bool contains(Segment segment1, Segment segment2) {
    if (contains(segment1, segment2.a)) {
        return true;
    }
    if (contains(segment1, segment2.b)) {
        return true;
    }
    if (contains(segment2, segment1.a)) {
        return true;
    }
    if (contains(segment2, segment1.b)) {
        return true;
    }
    return false;
}

bool contains(Segment segment1, Segment segment2, bool strict) {
    if (contains(segment1, segment2.a, strict)) {
        return true;
    }
    if (contains(segment1, segment2.b, strict)) {
        return true;
    }
    if (contains(segment2, segment1.a, strict)) {
        return true;
    }
    if (contains(segment2, segment1.b, strict)) {
        return true;
    }
    return false;
}

bool contains(Segment segment, Circle circle) {
    if (contains(circle, segment.a)) {
        return true;
    }
    if (contains(circle, segment.b)) {
        return true;
    }
    if (circle.center.x == segment.a.x && circle.center.y == segment.a.y) {
        return true;
    }
    if (circle.center.x == segment.b.x && circle.center.y == segment.b.y) {
        return true;
    }
    if (circle.center.x == segment.a.x && circle.center.y == segment.a.y &&
        circle.center.x == segment.b.x && circle.center.y == segment.b.y) {
        return true;
    }
    long long ax = segment.a.x - circle.center.x;
    long long ay = segment.a.y - circle.center.y;
    long long bx = segment.b.x - circle.center.x;
    long long by = segment.b.y - circle.center.y;
    long long a = ax * ax + ay * ay - circle.radius * circle.radius;
    long long b = 2 * (ax * (bx - ax) + ay * (by - ay));
    long long c = (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
    long long d = b * b - 4 * a * c;
    if (d < 0) {
        return false;
    } else if (d == 0) {
        long long t = -b / (2 * a);
        return t >= 0 && t <= 1;
    } else {
        long long t1 = (-b + sqrt(d)) / (2 * a);
        long long t2 = (-b - sqrt(d)) / (2 * a);
        return (t1 >= 0 && t1 <= 1) || (t2 >= 0 && t2 <= 1);
    }
}

bool contains(Segment segment, Circle circle, bool strict) {
    if (contains(circle, segment.a, strict)) {
        return true;
    }
    if (contains(circle, segment.b, strict)) {
        return true;
    }
    if (circle.center.x == segment.a.x && circle.center.y == segment.a.y) {
        return true;
    }
    if (circle.center.x == segment.b.x && circle.center.y == segment.b.y) {
        return true;
    }
    if (circle.center.x == segment.a.x && circle.center.y == segment.a.y &&
        circle.center.x == segment.b.x && circle.center.y == segment.b.y) {
        return true;
    }
    long long ax = segment.a.x - circle.center.x;
    long long ay = segment.a.y - circle.center.y;
    long long bx = segment.b.x - circle.center.x;
    long long by = segment.b.y - circle.center.y;
    long long a = ax * ax + ay * ay - circle.radius * circle.radius;
    long long b = 2 * (ax * (bx - ax) + ay * (by - ay));
    long long c = (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
