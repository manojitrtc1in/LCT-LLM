#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define INF UINT_MAX

typedef struct {
    int x;
    int y;
} xyPoint;

typedef struct {
    xyPoint center;
    double radius;
} xyCircle;

typedef struct {
    double slope;
    double intercept;
} xyLine;

typedef struct {
    size_t first;
    size_t second;
} Pair;

typedef struct {
    size_t root;
    size_t n;
    size_t NIL;
    size_t INF;
    size_t* g1;
    size_t* dist;
    size_t* pair;
} id1;

typedef struct {
    size_t n;
    size_t* depth;
    size_t* parent;
    unsigned short** dist;
} id3;

typedef struct {
    size_t* parent;
    size_t* rank;
} UnionFind;

typedef struct {
    int* val;
    size_t size;
    size_t capacity;
    int (*comp)(const void*, const void*);
} Heap;

typedef struct {
    int x;
    int y;
} tuple;

typedef struct {
    int x;
    int y;
} pair;

typedef struct {
    int x;
    int y;
} triplet;

typedef struct {
    int x;
    int y;
} quad;

typedef struct {
    int x;
    int y;
} quint;

typedef struct {
    int x;
    int y;
} sext;

typedef struct {
    int x;
    int y;
} sept;

typedef struct {
    int x;
    int y;
} oct;

typedef struct {
    int x;
    int y;
} non;

typedef struct {
    int x;
    int y;
} dec;

typedef struct {
    int x;
    int y;
} undec;

typedef struct {
    int x;
    int y;
} dodec;

typedef struct {
    int x;
    int y;
} tridec;

typedef struct {
    int x;
    int y;
} tetradec;

typedef struct {
    int x;
    int y;
} pentadec;

typedef struct {
    int x;
    int y;
} hexadec;

typedef struct {
    int x;
    int y;
} heptadec;

typedef struct {
    int x;
    int y;
} octadec;

typedef struct {
    int x;
    int y;
} nonadec;

typedef struct {
    int x;
    int y;
} vigint;

typedef struct {
    int x;
    int y;
} unvigint;

typedef struct {
    int x;
    int y;
} dovigint;

typedef struct {
    int x;
    int y;
} trivigint;

typedef struct {
    int x;
    int y;
} tetavigint;

typedef struct {
    int x;
    int y;
} pentavigint;

typedef struct {
    int x;
    int y;
} hexavigint;

typedef struct {
    int x;
    int y;
} heptavigint;

typedef struct {
    int x;
    int y;
} octavigint;

typedef struct {
    int x;
    int y;
} nonavigint;

typedef struct {
    int x;
    int y;
} trigint;

typedef struct {
    int x;
    int y;
} unit;

typedef struct {
    int x;
    int y;
} duo;

typedef struct {
    int x;
    int y;
} tre;

typedef struct {
    int x;
    int y;
} quattuor;

typedef struct {
    int x;
    int y;
} quinque;

typedef struct {
    int x;
    int y;
} sex;

typedef struct {
    int x;
    int y;
} septem;

typedef struct {
    int x;
    int y;
} octo;

typedef struct {
    int x;
    int y;
} novem;

typedef struct {
    int x;
    int y;
} triginta;

typedef struct {
    int x;
    int y;
} untriginta;

typedef struct {
    int x;
    int y;
} dotriginta;

typedef struct {
    int x;
    int y;
} tretriginta;

typedef struct {
    int x;
    int y;
} quattuortriginta;

typedef struct {
    int x;
    int y;
} quinquetriginta;

typedef struct {
    int x;
    int y;
} sextriginta;

typedef struct {
    int x;
    int y;
} septentriginta;

typedef struct {
    int x;
    int y;
} octotriginta;

typedef struct {
    int x;
    int y;
} noventriginta;

typedef struct {
    int x;
    int y;
} quadraginta;

typedef struct {
    int x;
    int y;
} unquadraginta;

typedef struct {
    int x;
    int y;
} doquadraginta;

typedef struct {
    int x;
    int y;
} trequadraginta;

typedef struct {
    int x;
    int y;
} quattuorquadraginta;

typedef struct {
    int x;
    int y;
} quinquequadraginta;

typedef struct {
    int x;
    int y;
} sexquadraginta;

typedef struct {
    int x;
    int y;
} septenquadraginta;

typedef struct {
    int x;
    int y;
} octoquadraginta;

typedef struct {
    int x;
    int y;
} novemquadraginta;

typedef struct {
    int x;
    int y;
} quinquaginta;

typedef struct {
    int x;
    int y;
} unquinquaginta;

typedef struct {
    int x;
    int y;
} duoquinquaginta;

typedef struct {
    int x;
    int y;
} trequinquaginta;

typedef struct {
    int x;
    int y;
} quattuorquinquaginta;

typedef struct {
    int x;
    int y;
} quinquequinquaginta;

typedef struct {
    int x;
    int y;
} sexquinquaginta;

typedef struct {
    int x;
    int y;
} septenquinquaginta;

typedef struct {
    int x;
    int y;
} octoquinquaginta;

typedef struct {
    int x;
    int y;
} novemquinquaginta;

typedef struct {
    int x;
    int y;
} sexaginta;

typedef struct {
    int x;
    int y;
} unsexaginta;

typedef struct {
    int x;
    int y;
} duosexaginta;

typedef struct {
    int x;
    int y;
} tresexaginta;

typedef struct {
    int x;
    int y;
} quattuorsexaginta;

typedef struct {
    int x;
    int y;
} quinquesexaginta;

typedef struct {
    int x;
    int y;
} sexsexaginta;

typedef struct {
    int x;
    int y;
} septensexaginta;

typedef struct {
    int x;
    int y;
} octosexaginta;

typedef struct {
    int x;
    int y;
} novemsexaginta;

typedef struct {
    int x;
    int y;
} septuaginta;

typedef struct {
    int x;
    int y;
} unseptuaginta;

typedef struct {
    int x;
    int y;
} duoseptuaginta;

typedef struct {
    int x;
    int y;
} treseptuaginta;

typedef struct {
    int x;
    int y;
} quattuorseptuaginta;

typedef struct {
    int x;
    int y;
} quinqueseptuaginta;

typedef struct {
    int x;
    int y;
} sexseptuaginta;

typedef struct {
    int x;
    int y;
} septenseptuaginta;

typedef struct {
    int x;
    int y;
} octoseptuaginta;

typedef struct {
    int x;
    int y;
} novemseptuaginta;

typedef struct {
    int x;
    int y;
} octoginta;

typedef struct {
    int x;
    int y;
} unoctoginta;

typedef struct {
    int x;
    int y;
} duooctoginta;

typedef struct {
    int x;
    int y;
} treoctoginta;

typedef struct {
    int x;
    int y;
} quattuoroctoginta;

typedef struct {
    int x;
    int y;
} quinqueoctoginta;

typedef struct {
    int x;
    int y;
} sexoctoginta;

typedef struct {
    int x;
    int y;
} septenoctoginta;

typedef struct {
    int x;
    int y;
} octooctoginta;

typedef struct {
    int x;
    int y;
} novemoctoginta;

typedef struct {
    int x;
    int y;
} nonaginta;

typedef struct {
    int x;
    int y;
} unnonaginta;

typedef struct {
    int x;
    int y;
} duononaginta;

typedef struct {
    int x;
    int y;
} trenonaginta;

typedef struct {
    int x;
    int y;
} quattuornonaginta;

typedef struct {
    int x;
    int y;
} quinquenonaginta;

typedef struct {
    int x;
    int y;
} sexnonaginta;

typedef struct {
    int x;
    int y;
} septennonaginta;

typedef struct {
    int x;
    int y;
} octononaginta;

typedef struct {
    int x;
    int y;
} novemnonaginta;

typedef struct {
    int x;
    int y;
} centum;

typedef struct {
    int x;
    int y;
} uncentum;

typedef struct {
    int x;
    int y;
} duocentum;

typedef struct {
    int x;
    int y;
} trecentum;

typedef struct {
    int x;
    int y;
} quattuorcentum;

typedef struct {
    int x;
    int y;
} quinquecentum;

typedef struct {
    int x;
    int y;
} sexcentum;

typedef struct {
    int x;
    int y;
} septencentum;

typedef struct {
    int x;
    int y;
} octocentum;

typedef struct {
    int x;
    int y;
} novemcentum;

typedef struct {
    int x;
    int y;
} mille;

typedef struct {
    int x;
    int y;
} unumille;

typedef struct {
    int x;
    int y;
} duomille;

typedef struct {
    int x;
    int y;
} tremille;

typedef struct {
    int x;
    int y;
} quattuormille;

typedef struct {
    int x;
    int y;
} quinquemille;

typedef struct {
    int x;
    int y;
} sexmille;

typedef struct {
    int x;
    int y;
} septemmille;

typedef struct {
    int x;
    int y;
} octomille;

typedef struct {
    int x;
    int y;
} novemmille;

typedef struct {
    int x;
    int y;
} decemille;

typedef struct {
    int x;
    int y;
} undecimille;

typedef struct {
    int x;
    int y;
} duodecimille;

typedef struct {
    int x;
    int y;
} tredecimille;

typedef struct {
    int x;
    int y;
} quattuordecimille;

typedef struct {
    int x;
    int y;
} quindecimille;

typedef struct {
    int x;
    int y;
} sedecimille;

typedef struct {
    int x;
    int y;
} septendecimille;

typedef struct {
    int x;
    int y;
} duodeviginti;

typedef struct {
    int x;
    int y;
} undeviginti;

typedef struct {
    int x;
    int y;
} viginti;

typedef struct {
    int x;
    int y;
} unviginti;

typedef struct {
    int x;
    int y;
} doviginti;

typedef struct {
    int x;
    int y;
} treviginti;

typedef struct {
    int x;
    int y;
} quattuorviginti;

typedef struct {
    int x;
    int y;
} quinquaviginti;

typedef struct {
    int x;
    int y;
} sexviginti;

typedef struct {
    int x;
    int y;
} septemviginti;

typedef struct {
    int x;
    int y;
} octoviginti;

typedef struct {
    int x;
    int y;
} novemviginti;

typedef struct {
    int x;
    int y;
} triginta;

typedef struct {
    int x;
    int y;
} untriginta;

typedef struct {
    int x;
    int y;
} dotriginta;

typedef struct {
    int x;
    int y;
} tretriginta;

typedef struct {
    int x;
    int y;
} quattuortriginta;

typedef struct {
    int x;
    int y;
} quinquetriginta;

typedef struct {
    int x;
    int y;
} sextriginta;

typedef struct {
    int x;
    int y;
} septentriginta;

typedef struct {
    int x;
    int y;
} octotriginta;

typedef struct {
    int x;
    int y;
} noventriginta;

typedef struct {
    int x;
    int y;
} quadraginta;

typedef struct {
    int x;
    int y;
} unquadraginta;

typedef struct {
    int x;
    int y;
} doquadraginta;

typedef struct {
    int x;
    int y;
} trequadraginta;

typedef struct {
    int x;
    int y;
} quattuorquadraginta;

typedef struct {
    int x;
    int y;
} quinquequadraginta;

typedef struct {
    int x;
    int y;
} sexquadraginta;

typedef struct {
    int x;
    int y;
} septenquadraginta;

typedef struct {
    int x;
    int y;
} octoquadraginta;

typedef struct {
    int x;
    int y;
} novemquadraginta;

typedef struct {
    int x;
    int y;
} quinquaginta;

typedef struct {
    int x;
    int y;
} unquinquaginta;

typedef struct {
    int x;
    int y;
} duoquinquaginta;

typedef struct {
    int x;
    int y;
} trequinquaginta;

typedef struct {
    int x;
    int y;
} quattuorquinquaginta;

typedef struct {
    int x;
    int y;
} quinquequinquaginta;

typedef struct {
    int x;
    int y;
} sexquinquaginta;

typedef struct {
    int x;
    int y;
} septenquinquaginta;

typedef struct {
    int x;
    int y;
} octoquinquaginta;

typedef struct {
    int x;
    int y;
} novemquinquaginta;

typedef struct {
    int x;
    int y;
} sexaginta;

typedef struct {
    int x;
    int y;
} unsexaginta;

typedef struct {
    int x;
    int y;
} duosexaginta;

typedef struct {
    int x;
    int y;
} tresexaginta;

typedef struct {
    int x;
    int y;
} quattuorsexaginta;

typedef struct {
    int x;
    int y;
} quinquesexaginta;

typedef struct {
    int x;
    int y;
} sexsexaginta;

typedef struct {
    int x;
    int y;
} septensexaginta;

typedef struct {
    int x;
    int y;
} octosexaginta;

typedef struct {
    int x;
    int y;
} novemsexaginta;

typedef struct {
    int x;
    int y;
} septuaginta;

typedef struct {
    int x;
    int y;
} unseptuaginta;

typedef struct {
    int x;
    int y;
} duoseptuaginta;

typedef struct {
    int x;
    int y;
} treseptuaginta;

typedef struct {
    int x;
    int y;
} quattuorseptuaginta;

typedef struct {
    int x;
    int y;
} quinqueseptuaginta;

typedef struct {
    int x;
    int y;
} sexseptuaginta;

typedef struct {
    int x;
    int y;
} septenseptuaginta;

typedef struct {
    int x;
    int y;
} octoseptuaginta;

typedef struct {
    int x;
    int y;
} novemseptuaginta;

typedef struct {
    int x;
    int y;
} octoginta;

typedef struct {
    int x;
    int y;
} unoctoginta;

typedef struct {
    int x;
    int y;
} duooctoginta;

typedef struct {
    int x;
    int y;
} treoctoginta;

typedef struct {
    int x;
    int y;
} quattuoroctoginta;

typedef struct {
    int x;
    int y;
} quinqueoctoginta;

typedef struct {
    int x;
    int y;
} sexoctoginta;

typedef struct {
    int x;
    int y;
} septenoctoginta;

typedef struct {
    int x;
    int y;
} octooctoginta;

typedef struct {
    int x;
    int y;
} novemoctoginta;

typedef struct {
    int x;
    int y;
} nonaginta;

typedef struct {
    int x;
    int y;
} unnonaginta;

typedef struct {
    int x;
    int y;
} duononaginta;

typedef struct {
    int x;
    int y;
} trenonaginta;

typedef struct {
    int x;
    int y;
} quattuornonaginta;

typedef struct {
    int x;
    int y;
} quinquenonaginta;

typedef struct {
    int x;
    int y;
} sexnonaginta;

typedef struct {
    int x;
    int y;
} septennonaginta;

typedef struct {
    int x;
    int y;
} octononaginta;

typedef struct {
    int x;
    int y;
} novemnonaginta;

typedef struct {
    int x;
    int y;
} triginta;

typedef struct {
    int x;
    int y;
} untriginta;

typedef struct {
    int x;
    int y;
} dotriginta;

typedef struct {
    int x;
    int y;
} tretriginta;

typedef struct {
    int x;
    int y;
} quattuortriginta;

typedef struct {
    int x;
    int y;
} quinquetriginta;

typedef struct {
    int x;
    int y;
} sextriginta;

typedef struct {
    int x;
    int y;
} septentriginta;

typedef struct {
    int x;
    int y;
} octotriginta;

typedef struct {
    int x;
    int y;
} noventriginta;

typedef struct {
    int x;
    int y;
} quadraginta;

typedef struct {
    int x;
    int y;
} unquadraginta;

typedef struct {
    int x;
    int y;
} doquadraginta;

typedef struct {
    int x;
    int y;
} trequadraginta;

typedef struct {
    int x;
    int y;
} quattuorquadraginta;

typedef struct {
    int x;
    int y;
} quinquequadraginta;

typedef struct {
    int x;
    int y;
} sexquadraginta;

typedef struct {
    int x;
    int y;
} septenquadraginta;

typedef struct {
    int x;
    int y;
} octoquadraginta;

typedef struct {
    int x;
    int y;
} novemquadraginta;

typedef struct {
    int x;
    int y;
} quinquaginta;

typedef struct {
    int x;
    int y;
} unquinquaginta;

typedef struct {
    int x;
    int y;
} duoquinquaginta;

typedef struct {
    int x;
    int y;
} trequinquaginta;

typedef struct {
    int x;
    int y;
} quattuorquinquaginta;

typedef struct {
    int x;
    int y;
} quinquequinquaginta;

typedef struct {
    int x;
    int y;
} sexquinquaginta;

typedef struct {
    int x;
    int y;
} septenquinquaginta;

typedef struct {
    int x;
    int y;
} octoquinquaginta;

typedef struct {
    int x;
    int y;
} novemquinquaginta;

typedef struct {
    int x;
    int y;
} sexaginta;

typedef struct {
    int x;
    int y;
} unsexaginta;

typedef struct {
    int x;
    int y;
} duosexaginta;

typedef struct {
    int x;
    int y;
} tresexaginta;

typedef struct {
    int x;
    int y;
} quattuorsexaginta;

typedef struct {
    int x;
    int y;
} quinquesexaginta;

typedef struct {
    int x;
    int y;
} sexsexaginta;

typedef struct {
    int x;
    int y;
} septensexaginta;

typedef struct {
    int x;
    int y;
} octosexaginta;

typedef struct {
    int x;
    int y;
} novemsexaginta;

typedef struct {
    int x;
    int y;
} septuaginta;

typedef struct {
    int x;
    int y;
} unseptuaginta;

typedef struct {
    int x;
    int y;
} duoseptuaginta;

typedef struct {
    int x;
    int y;
} treseptuaginta;

typedef struct {
    int x;
    int y;
} quattuorseptuaginta;

typedef struct {
    int x;
    int y;
} quinqueseptuaginta;

typedef struct {
    int x;
    int y;
} sexseptuaginta;

typedef struct {
    int x;
    int y;
} septenseptuaginta;

typedef struct {
    int x;
    int y;
} octoseptuaginta;

typedef struct {
    int x;
    int y;
} novemseptuaginta;

typedef struct {
    int x;
    int y;
} octoginta;

typedef struct {
    int x;
    int y;
} unoctoginta;

typedef struct {
    int x;
    int y;
} duooctoginta;

typedef struct {
    int x;
    int y;
} treoctoginta;

typedef struct {
    int x;
    int y;
} quattuoroctoginta;

typedef struct {
    int x;
    int y;
} quinqueoctoginta;

typedef struct {
    int x;
    int y;
} sexoctoginta;

typedef struct {
    int x;
    int y;
} septenoctoginta;

typedef struct {
    int x;
    int y;
} octooctoginta;

typedef struct {
    int x;
    int y;
} novemoctoginta;

typedef struct {
    int x;
    int y;
} nonaginta;

typedef struct {
    int x;
    int y;
} unnonaginta;

typedef struct {
    int x;
    int y;
} duononaginta;

typedef struct {
    int x;
    int y;
} trenonaginta;

typedef struct {
    int x;
    int y;
} quattuornonaginta;

typedef struct {
    int x;
    int y;
} quinquenonaginta;

typedef struct {
    int x;
    int y;
} sexnonaginta;

typedef struct {
    int x;
    int y;
} septennonaginta;

typedef struct {
    int x;
    int y;
} octononaginta;

typedef struct {
    int x;
    int y;
} novemnonaginta;

typedef struct {
    int x;
    int y;
} triginta;

typedef struct {
    int x;
    int y;
} untriginta;

typedef struct {
    int x;
    int y;
} dotriginta;

typedef struct {
    int x;
    int y;
} tretriginta;

typedef struct {
    int x;
    int y;
} quattuortriginta;

typedef struct {
    int x;
    int y;
} quinquetriginta;

typedef struct {
    int x;
    int y;
} sextriginta;

typedef struct {
    int x;
    int y;
} septentriginta;

typedef struct {
    int x;
    int y;
} octotriginta;

typedef struct {
    int x;
    int y;
} noventriginta;

typedef struct {
    int x;
    int y;
} quadraginta;

typedef struct {
    int x;
    int y;
} unquadraginta;

typedef struct {
    int x;
