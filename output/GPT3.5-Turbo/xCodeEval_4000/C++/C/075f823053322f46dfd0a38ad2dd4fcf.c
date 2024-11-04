#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 15000000
#define inf 1000000007
#define ll_inf 1000000000000000420
#define eps 0.0001
#define N 1000007
#define MAX 200009
#define MOD 1000000007
#define pi 3.14159265359

typedef long long ll;
typedef unsigned long long ull;
typedef struct {
    ll first;
    ll second;
} pll;
typedef struct {
    int first;
    int second;
} pii;
typedef struct {
    int first;
    pii second;
} ppiipii;
typedef struct {
    int first;
    pii second;
    int third;
} pipii;
typedef struct {
    int first;
    pii second;
    pii third;
} pipiipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
} pipiipipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
} pipiipipiipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
} pipiipipiipipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
} pipiipipiipipiipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
} pipiipipiipipiipipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
    pii ninth;
} pipiipipiipipiipipiipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
    pii ninth;
    pii tenth;
} pipiipipiipipiipipiipipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
    pii ninth;
    pii tenth;
    pii eleventh;
} pipiipipiipipiipipiipipiipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
    pii ninth;
    pii tenth;
    pii eleventh;
    pii twelfth;
} pipiipipiipipiipipiipipiipipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
    pii ninth;
    pii tenth;
    pii eleventh;
    pii twelfth;
    pii thirteenth;
} pipiipipiipipiipipiipipiipipiipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
    pii ninth;
    pii tenth;
    pii eleventh;
    pii twelfth;
    pii thirteenth;
    pii fourteenth;
} pipiipipiipipiipipiipipiipipiipipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
    pii ninth;
    pii tenth;
    pii eleventh;
    pii twelfth;
    pii thirteenth;
    pii fourteenth;
    pii fifteenth;
} pipiipipiipipiipipiipipiipipiipipiipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
    pii ninth;
    pii tenth;
    pii eleventh;
    pii twelfth;
    pii thirteenth;
    pii fourteenth;
    pii fifteenth;
    pii sixteenth;
} pipiipipiipipiipipiipipiipipiipipiipipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
    pii ninth;
    pii tenth;
    pii eleventh;
    pii twelfth;
    pii thirteenth;
    pii fourteenth;
    pii fifteenth;
    pii sixteenth;
    pii seventeenth;
} pipiipipiipipiipipiipipiipipiipipiipipiipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
    pii ninth;
    pii tenth;
    pii eleventh;
    pii twelfth;
    pii thirteenth;
    pii fourteenth;
    pii fifteenth;
    pii sixteenth;
    pii seventeenth;
    pii eighteenth;
} pipiipipiipipiipipiipipiipipiipipiipipiipipiipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
    pii ninth;
    pii tenth;
    pii eleventh;
    pii twelfth;
    pii thirteenth;
    pii fourteenth;
    pii fifteenth;
    pii sixteenth;
    pii seventeenth;
    pii eighteenth;
    pii nineteenth;
} pipiipipiipipiipipiipipiipipiipipiipipiipipiipipiipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
    pii ninth;
    pii tenth;
    pii eleventh;
    pii twelfth;
    pii thirteenth;
    pii fourteenth;
    pii fifteenth;
    pii sixteenth;
    pii seventeenth;
    pii eighteenth;
    pii nineteenth;
    pii twentieth;
} pipiipipiipipiipipiipipiipipiipipiipipiipipiipipiipipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
    pii ninth;
    pii tenth;
    pii eleventh;
    pii twelfth;
    pii thirteenth;
    pii fourteenth;
    pii fifteenth;
    pii sixteenth;
    pii seventeenth;
    pii eighteenth;
    pii nineteenth;
    pii twentieth;
    pii twentyfirst;
} pipiipipiipipiipipiipipiipipiipipiipipiipipiipipiipipiipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
    pii ninth;
    pii tenth;
    pii eleventh;
    pii twelfth;
    pii thirteenth;
    pii fourteenth;
    pii fifteenth;
    pii sixteenth;
    pii seventeenth;
    pii eighteenth;
    pii nineteenth;
    pii twentieth;
    pii twentyfirst;
    pii twentysecond;
} pipiipipiipipiipipiipipiipipiipipiipipiipipiipipiipipiipipiipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
    pii ninth;
    pii tenth;
    pii eleventh;
    pii twelfth;
    pii thirteenth;
    pii fourteenth;
    pii fifteenth;
    pii sixteenth;
    pii seventeenth;
    pii eighteenth;
    pii nineteenth;
    pii twentieth;
    pii twentyfirst;
    pii twentysecond;
    pii twentythird;
} pipiipipiipipiipipiipipiipipiipipiipipiipipiipipiipipiipipiipipiipii;
typedef struct {
    int first;
    pii second;
    pii third;
    pii fourth;
    pii fifth;
    pii sixth;
    pii seventh;
    pii eighth;
    pii ninth;
    pii tenth;
    pii eleventh;
    pii twelfth;
    pii thirteenth;
    pii fourteenth;
    pii fifteenth;
    pii sixteenth;
    pii seventeenth;
    pii eighteenth;
    pii nineteenth;
    pii twentieth;
    pii twentyfirst;
    pii twentysecond;
    pii twentythird;
    pii twentyfourth;
