#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int x;
    int y;
} xyPoint;

typedef struct {
    xyPoint center;
    double radius;
} xyCircle;

typedef struct {
    int first;
    int second;
} Pair;

typedef struct {
    int x;
    int y;
    int z;
} Triple;

typedef struct {
    int x;
    int y;
    int z;
    int w;
} Quadruple;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
} Quintuple;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
} Sextuple;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
} Septuple;

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int v;
    int u;
    int t;
    int s;
} Octuple;

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
} Nonuple;

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
} Decuple;

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
} Undecuple;

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
} Duodecuple;

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
} Tridecuple;

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
} Tetradecuple;

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
} Pentadecuple;

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
} Hexadecuple;

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
} Heptadecuple;

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
} Octadecuple;

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
} Nonadecuple;

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
} Vigintuple;

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
} Unvigintuple;

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
} Duovigintuple;

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
} Trevigintuple;

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
} Quadrigintuple;

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
} Quinvigintuple;

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
} Sexvigintuple;

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
} Septenvigintuple;

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
} Octovigintuple;

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
} Novemvigintuple;

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
} Trigintuple;

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
} Untrigintuple;

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
} Duotrigintuple;

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
} Tretrigintuple;

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
} Quadrigintuple;

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
} Quintrigintuple;

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
} Sextrigintuple;

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
} Septentrigintuple;

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
} Octotrigintuple;

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
} Novemtrigintuple;

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