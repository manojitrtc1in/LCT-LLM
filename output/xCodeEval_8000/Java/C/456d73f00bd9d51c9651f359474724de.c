#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 100000

typedef struct {
    long long *arr;
    int size;
    int capacity;
} LongArray;

typedef struct {
    int *arr;
    int size;
    int capacity;
} IntArray;

typedef struct {
    double *arr;
    int size;
    int capacity;
} DoubleArray;

typedef struct {
    char **arr;
    int size;
    int capacity;
} StringArray;

typedef struct {
    bool *arr;
    int size;
    int capacity;
} BoolArray;

typedef struct {
    LongArray *arr;
    int size;
    int capacity;
} LongArrayList;

typedef struct {
    IntArray *arr;
    int size;
    int capacity;
} IntArrayList;

typedef struct {
    DoubleArray *arr;
    int size;
    int capacity;
} DoubleArrayList;

typedef struct {
    StringArray *arr;
    int size;
    int capacity;
} StringArrayList;

typedef struct {
    long long val;
    int id;
} IDVal;

typedef struct {
    IDVal *arr;
    int size;
    int capacity;
} IDValArray;

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *arr;
    int size;
    int capacity;
} PointArray;

typedef struct {
    int **arr;
    int size;
    int capacity;
} IntMatrix;

typedef struct {
    long long **arr;
    int size;
    int capacity;
} LongMatrix;

typedef struct {
    double **arr;
    int size;
    int capacity;
} DoubleMatrix;

typedef struct {
    char **arr;
    int size;
    int capacity;
} StringMatrix;

typedef struct {
    bool **arr;
    int size;
    int capacity;
} BoolMatrix;

typedef struct {
    int x;
    int y;
    int z;
} Point3D;

typedef struct {
    Point3D *arr;
    int size;
    int capacity;
} Point3DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
} Point4D;

typedef struct {
    Point4D *arr;
    int size;
    int capacity;
} Point4DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
} Point5D;

typedef struct {
    Point5D *arr;
    int size;
    int capacity;
} Point5DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
} Point6D;

typedef struct {
    Point6D *arr;
    int size;
    int capacity;
} Point6DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
} Point7D;

typedef struct {
    Point7D *arr;
    int size;
    int capacity;
} Point7DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
} Point8D;

typedef struct {
    Point8D *arr;
    int size;
    int capacity;
} Point8DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
} Point9D;

typedef struct {
    Point9D *arr;
    int size;
    int capacity;
} Point9DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
} Point10D;

typedef struct {
    Point10D *arr;
    int size;
    int capacity;
} Point10DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
} Point11D;

typedef struct {
    Point11D *arr;
    int size;
    int capacity;
} Point11DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
} Point12D;

typedef struct {
    Point12D *arr;
    int size;
    int capacity;
} Point12DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
} Point13D;

typedef struct {
    Point13D *arr;
    int size;
    int capacity;
} Point13DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
} Point14D;

typedef struct {
    Point14D *arr;
    int size;
    int capacity;
} Point14DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
} Point15D;

typedef struct {
    Point15D *arr;
    int size;
    int capacity;
} Point15DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
} Point16D;

typedef struct {
    Point16D *arr;
    int size;
    int capacity;
} Point16DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
} Point17D;

typedef struct {
    Point17D *arr;
    int size;
    int capacity;
} Point17DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
} Point18D;

typedef struct {
    Point18D *arr;
    int size;
    int capacity;
} Point18DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
} Point19D;

typedef struct {
    Point19D *arr;
    int size;
    int capacity;
} Point19DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
} Point20D;

typedef struct {
    Point20D *arr;
    int size;
    int capacity;
} Point20DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
} Point21D;

typedef struct {
    Point21D *arr;
    int size;
    int capacity;
} Point21DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
} Point22D;

typedef struct {
    Point22D *arr;
    int size;
    int capacity;
} Point22DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
} Point23D;

typedef struct {
    Point23D *arr;
    int size;
    int capacity;
} Point23DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
} Point24D;

typedef struct {
    Point24D *arr;
    int size;
    int capacity;
} Point24DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
} Point25D;

typedef struct {
    Point25D *arr;
    int size;
    int capacity;
} Point25DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
} Point26D;

typedef struct {
    Point26D *arr;
    int size;
    int capacity;
} Point26DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
    int aa;
} Point27D;

typedef struct {
    Point27D *arr;
    int size;
    int capacity;
} Point27DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
    int aa;
    int ab;
} Point28D;

typedef struct {
    Point28D *arr;
    int size;
    int capacity;
} Point28DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
    int aa;
    int ab;
    int ac;
} Point29D;

typedef struct {
    Point29D *arr;
    int size;
    int capacity;
} Point29DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
    int aa;
    int ab;
    int ac;
    int ad;
} Point30D;

typedef struct {
    Point30D *arr;
    int size;
    int capacity;
} Point30DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
    int aa;
    int ab;
    int ac;
    int ad;
    int ae;
} Point31D;

typedef struct {
    Point31D *arr;
    int size;
    int capacity;
} Point31DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
    int aa;
    int ab;
    int ac;
    int ad;
    int ae;
    int af;
} Point32D;

typedef struct {
    Point32D *arr;
    int size;
    int capacity;
} Point32DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
    int aa;
    int ab;
    int ac;
    int ad;
    int ae;
    int af;
    int ag;
} Point33D;

typedef struct {
    Point33D *arr;
    int size;
    int capacity;
} Point33DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
    int aa;
    int ab;
    int ac;
    int ad;
    int ae;
    int af;
    int ag;
    int ah;
} Point34D;

typedef struct {
    Point34D *arr;
    int size;
    int capacity;
} Point34DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
    int aa;
    int ab;
    int ac;
    int ad;
    int ae;
    int af;
    int ag;
    int ah;
    int ai;
} Point35D;

typedef struct {
    Point35D *arr;
    int size;
    int capacity;
} Point35DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
    int aa;
    int ab;
    int ac;
    int ad;
    int ae;
    int af;
    int ag;
    int ah;
    int ai;
    int aj;
} Point36D;

typedef struct {
    Point36D *arr;
    int size;
    int capacity;
} Point36DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
    int aa;
    int ab;
    int ac;
    int ad;
    int ae;
    int af;
    int ag;
    int ah;
    int ai;
    int aj;
    int ak;
} Point37D;

typedef struct {
    Point37D *arr;
    int size;
    int capacity;
} Point37DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
    int aa;
    int ab;
    int ac;
    int ad;
    int ae;
    int af;
    int ag;
    int ah;
    int ai;
    int aj;
    int ak;
    int al;
} Point38D;

typedef struct {
    Point38D *arr;
    int size;
    int capacity;
} Point38DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
    int aa;
    int ab;
    int ac;
    int ad;
    int ae;
    int af;
    int ag;
    int ah;
    int ai;
    int aj;
    int ak;
    int al;
    int am;
} Point39D;

typedef struct {
    Point39D *arr;
    int size;
    int capacity;
} Point39DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
    int aa;
    int ab;
    int ac;
    int ad;
    int ae;
    int af;
    int ag;
    int ah;
    int ai;
    int aj;
    int ak;
    int al;
    int am;
    int an;
} Point40D;

typedef struct {
    Point40D *arr;
    int size;
    int capacity;
} Point40DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
    int aa;
    int ab;
    int ac;
    int ad;
    int ae;
    int af;
    int ag;
    int ah;
    int ai;
    int aj;
    int ak;
    int al;
    int am;
    int an;
    int ao;
} Point41D;

typedef struct {
    Point41D *arr;
    int size;
    int capacity;
} Point41DArray;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
    int l;
    int k;
    int j;
    int i;
    int h;
    int g;
    int f;
    int e;
    int d;
    int c;
    int b;
    int a;
    int aa;
    int ab;
    int ac;
    int ad;
    int ae;
    int af;
    int ag;
    int ah;
    int ai;
    int aj;
    int ak;
    int al;
    int am;
    int an;
    int ao;
    int ap;
} Point42D;

typedef struct {
    Point42D *arr;
    int size;
    int capacity;
} Point42DArray;

typedef struct {
    int x;
    int y;
