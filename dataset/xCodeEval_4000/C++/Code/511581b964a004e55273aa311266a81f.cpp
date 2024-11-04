#pragma comment(linker, "/STACK:108777216")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <string>
#include <cmath>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
using namespace std;
namespace l {
unsigned int const i = 4294967295UL;
unsigned int const I = 624;
unsigned int const ll = 397;
unsigned int const l1 = 32;
unsigned int const li = 31;
unsigned int const lI = 2567483615UL;
unsigned int const il = 11;
unsigned int const i1 = 7;
unsigned int const ii = 15;
unsigned int const iI = 18;
unsigned int const Il = 2636928640UL;
unsigned int const I1 = 4022730752UL;
unsigned int const Ii = 97;
unsigned int const II = 33;
unsigned int const lll = 214013;
unsigned int const ll1 = 2531011;
class lli {
private:
unsigned int llI;
unsigned int * l1l;
unsigned int l11, l1i;
unsigned int l1I;
unsigned int lil;
inline unsigned int li1(unsigned int lii) const {
unsigned int liI = l11 + lii;
if (liI >= llI)
return liI - llI;
else
return liI;
}
public:
lli(unsigned int lIl = 2010471600UL) {
llI = I + 20;
l1l = new unsigned int [llI];
l11 = 0;
l1i = 0;
l1l[0] = lIl;
for (unsigned int lI1 = 1;
lI1 < Ii;
lI1++) {
l1i++;
l1l[l1i] = lll * l1l[l1i-1] + ll1;
}
for (unsigned int lIi = Ii;
lIi < I;
lIi++) {
l1i++;
l1l[l1i] = l1l[l1i - Ii] -
l1l[l1i - II];
}
lil = (unsigned int) (
( ((unsigned long long) 1) << ((unsigned long long) li) ) - 1
);
l1I = (unsigned int) (
( ((unsigned long long) 1) << ((unsigned long long) l1) ) - 1 -
lil
);
}
~lli() {
delete [] l1l;
}
unsigned int lII() const {
if (Ii <= II)
return 0;
if (Ii >= I)
return 0;
if (II < 1)
return 0;
if (ll < 1 || ll >= I)
return 0;
if (li < 1 || li >= l1)
return 0;
return 1;
}
unsigned int ill() {
unsigned int il1 = (l1l[li1(0)] & l1I) |
(l1l[li1(1)] & lil);
unsigned int ili = l1l[li1(ll)] ^ (il1>>1);
if (il1 & 1)
ili ^= lI;
ili = ili ^ (ili >> il);
ili = ili ^ ((ili << i1) & Il);
ili = ili ^ ((ili << ii) & I1);
ili = ili ^ (ili >> iI);
l1i++;
if (l1i >= llI)
l1i -= llI;
l1l[l1i] = ili;
l11++;
if (l11 >= llI)
l11 -= llI;
return ili;
}
};
}
namespace ilI {
template<typename i1l>
class i11 {
private:
i1l * i1i;
int i1I;
int * iil;
int ii1, iii;
public:
void clear() {
for (int iiI = 0; iiI < i1I; iiI++)
i1i[iiI].clear();
ii1 = 0;
iii = i1I;
iil[i1I] = -1;
for (int iiI = 0; iiI < i1I; iiI++)
iil[iiI] = iiI;
}
i11(int iIl, ...) {
if (iIl <= 0) {
i1i = NULL;
i1I = 0;
iil = NULL;
ii1 = iii = 0;
return;
}
i1I = iIl;
ii1 = 0;
iii = i1I;
iil = new int [i1I + 1];
iil[i1I] = -1;
for (int iiI = 0; iiI < i1I; iiI++)
iil[iiI] = iiI;
va_list iI1;
va_start(iI1, iIl);
i1i = (i1l *) operator new ( sizeof(i1l) * i1I );
for (int iiI = 0; iiI < i1I; iiI++) {
new(&i1i[iiI]) i1l(iI1);
i1i[iiI].clear();
}
va_end(iI1);
}
~i11() {
if (i1i != NULL) {
for (int iiI = 0; iiI < i1I; iiI++)
i1i[iiI].~i1l();
operator delete(i1i);
}
if (iil != NULL)
delete [] iil;
}
int iIi() const {
return iil[ii1] == -1;
}
i1l * iII() {
if (iIi())
return NULL;
i1l * Ill = i1i + iil[ii1];
iil[ii1] = -1;
ii1++;
if (ii1 >= i1I+1)
ii1 -= i1I+1;
Ill->clear();
return Ill;
}
void Il1(i1l * Ili) {
if (Ili == NULL)
return;
Ili->clear();
iil[iii] = Ili - i1i;
iii++;
if (iii >= i1I+1)
iii -= i1I+1;
}
};
}
namespace IlI {
using namespace l;
#define __STATIC_ALLOCATION__
#ifdef __KEY_INFO_LIST_SUPPORT__
struct I1l {
public:
I1l * I11;
public:
void clear() {
I11 = NULL;
}
I1l(...) {
I11 = NULL;
}
~I1l() {
}
};
#endif
#ifdef __STATIC_ALLOCATION__
int const I1i = 300100;
using namespace ilI;
#endif
template<typename I1I>
class Iil {
public:
template<typename Ii1>
class Iii {
public:
Ii1 IiI;
#ifdef __KEY_INFO_LIST_SUPPORT__
I1l * IIl;
#endif
int II1;
unsigned int IIi;
Iii *III, *llll;
#ifdef __STATIC_ALLOCATION__
#ifdef __KEY_INFO_LIST_SUPPORT__
i11<I1l> * lll1;
#endif
#endif
public:
void clear() {
IiI = Ii1();
#ifdef __KEY_INFO_LIST_SUPPORT__
while (IIl) {
I1l * llli = IIl;
IIl = IIl->I11;
#ifdef __STATIC_ALLOCATION__
lll1->Il1(llli);
#else
delete llli;
#endif
}
#endif
II1 = 0;
IIi = 0UL;
III = llll = NULL;
}
#ifdef __STATIC_ALLOCATION__
Iii(va_list iI1) {
#ifdef __KEY_INFO_LIST_SUPPORT__
IIl = NULL;
lll1 = va_arg(iI1, i11<I1l> *);
#endif
clear();
}
#else
Iii() {
#ifdef __KEY_INFO_LIST_SUPPORT__
IIl = NULL;
#endif
clear();
}
#endif
~Iii() {
clear();
}
};
typedef Iii<I1I> * lllI;
private:
lllI ll1l;
#ifdef __STATIC_ALLOCATION__
#ifdef __KEY_INFO_LIST_SUPPORT__
i11<I1l> * ll11;
#endif
i11<Iii<I1I> > * ll1i;
#endif
lli ll1I;
private:
unsigned int llil() {
return ll1I.ill();
}
void lli1(lllI llii, I1I IiI, lllI & lliI, lllI & llIl) {
if (llii == NULL) {
lliI = llIl = NULL;
return;
}
if (IiI <= llii->IiI) {
lli1(llii->III, IiI, lliI, llii->III);
llIl = llii;
}
else {
lli1(llii->llll, IiI, llii->llll, llIl);
lliI = llii;
}
}
void llI1(lllI & llii, lllI lliI, lllI llIl) {
if (lliI == NULL) {
llii = llIl;
return;
}
if (llIl == NULL) {
llii = lliI;
return;
}
if (lliI->IIi > llIl->IIi) {
llI1(lliI->llll, lliI->llll, llIl);
llii = lliI;
}
else {
llI1(llIl->III, lliI, llIl->III);
llii = llIl;
}
}
#ifndef __STATIC_ALLOCATION__
void llIi(lllI llii) {
if (llii == NULL) return;
llIi(llii->III);
llIi(llii->llll);
delete llii;
}
#endif
lllI llII(I1I IiI, unsigned int IIi  ) {
#ifdef __STATIC_ALLOCATION__
if (ll1i->iIi())
return NULL;
lllI l1ll = ll1i->iII();
if (l1ll == NULL)
return NULL;
l1ll->IiI = IiI;
l1ll->IIi = IIi;
l1ll->III = l1ll->llll = NULL;
#ifdef __KEY_INFO_LIST_SUPPORT__
l1ll->IIl = ll11->iII();
#endif
#else
lllI l1ll = new (std::nothrow) Iii<I1I>;
if (l1ll == NULL)
return NULL;
l1ll->IiI = IiI;
l1ll->IIi = IIi;
l1ll->III = l1ll->llll = NULL;
#ifdef __KEY_INFO_LIST_SUPPORT__
l1ll->IIl = new (std::nothrow) I1l;
#endif
#endif
#ifdef __KEY_INFO_LIST_SUPPORT__
if (l1ll->IIl == NULL) {
#ifndef __STATIC_ALLOCATION__
l1ll->clear();
delete l1ll;
#else
ll1i->Il1(l1ll);
#endif
return NULL;
}
l1ll->IIl->I11 = NULL;
#endif
l1ll->II1 = 1;
return l1ll;
}
void l1l1(lllI & llii, I1I IiI  ) {
llii->II1 += 1;
#ifdef __KEY_INFO_LIST_SUPPORT__
#ifdef __STATIC_ALLOCATION__
I1l * l1li = ll11->iII();
#else
I1l * l1li = new (std::nothrow) I1l;
#endif
if (l1li == NULL)
return;
l1li->I11 = llii->IIl;
llii->IIl = l1li;
#endif
#ifdef __SET__ONLY__
#ifdef __KEY_INFO_LIST_SUPPORT__
int l1lI = llii->II1;
l1lI--;
while (llii->IIl != NULL && l1lI > 0) {
I1l * llli = llii->IIl;
llii->IIl = llii->IIl->I11;
#ifdef __STATIC_ALLOCATION__
ll11->Il1(llli);
#else
delete llli;
#endif
l1lI--;
}
#endif
llii->II1 = min(llii->II1, 1);
#endif
}
lllI l11l(lllI & llii, I1I IiI  ) {
if (llii == NULL)
return NULL;
if (llii->IiI == IiI) {
l1l1(llii, IiI  );
return llii;
}
lllI Ill = NULL;
if (llii->IiI < IiI)
Ill = l11l(llii->llll, IiI  );
else
Ill = l11l(llii->III, IiI  );
return Ill;
}
public:
void clear() {
#ifndef __STATIC_ALLOCATION__
llIi(ll1l);
#else
int l111 = 0;
if (ll1l != NULL) {
long long l11i = l11I();
long long l1il = 1LL, l1i1 = 1LL;
while (l1i1 < l11i) {
l1i1 *= 2LL;
l1il++;
}
if (l11i * l1il * 3LL < (long long) I1i)
l111 = 1;
}
else
l111 = 1;
if (l111) {
while (ll1l)
erase(ll1l->IiI);
}
else
ll1i->clear();
#endif
ll1l = NULL;
}
Iil() {
ll1l = NULL;
#ifdef __STATIC_ALLOCATION__
#ifdef __KEY_INFO_LIST_SUPPORT__
ll11 = new i11<I1l> (I1i);
ll1i = new i11<Iii<I1I> > (I1i, ll11);
#else
ll1i = new i11<Iii<I1I> > (I1i);
#endif
#endif
}
~Iil() {
#ifdef __STATIC_ALLOCATION__
if (ll1i != NULL)
delete ll1i;
#ifdef __KEY_INFO_LIST_SUPPORT__
if (ll11 != NULL)
delete ll11;
#endif
#else
llIi(ll1l);
#endif
}
lllI insert(lllI & llii, I1I IiI, unsigned int IIi  ) {
if (llii == NULL) {
lllI l1ll = llII(IiI, IIi  );
if (l1ll == NULL)
return NULL;
llii = l1ll;
return llii;
}
if (llii->IiI == IiI) {
l1l1(llii, IiI  );
return llii;
}
if (IIi > llii->IIi) {
lllI l1ii = l11l(llii, IiI  );
if (l1ii != NULL) {
return l1ii;
}
lllI l1ll = llII(IiI, IIi  );
if (l1ll == NULL)
return NULL;
lli1(llii, l1ll->IiI, l1ll->III, l1ll->llll);
llii = l1ll;
return llii;
}
lllI Ill = NULL;
if (llii->IiI < IiI)
Ill = insert(llii->llll, IiI, IIi  );
else
Ill = insert(llii->III, IiI, IIi  );
return Ill;
}
lllI insert(lllI & llii , I1I IiI  ) {
return insert(llii, IiI, llil()  );
}
lllI insert(I1I IiI, unsigned int IIi  ) {
return insert(ll1l, IiI, IIi  );
}
lllI insert(I1I IiI  ) {
return insert(ll1l, IiI, llil()  );
}
lllI find(lllI llii, I1I IiI) const {
if (llii == NULL)
return NULL;
if (llii->IiI < IiI)
return find(llii->llll, IiI);
else if (llii->IiI > IiI)
return find(llii->III, IiI);
else
return llii;
}
lllI find(I1I IiI) const {
return find(ll1l, IiI);
}
lllI l1iI(lllI llii, int l1Il) const {
if (llii == NULL)
return NULL;
int l1I1 = 0;
if (llii->III)
l1I1 = llii->III->l1Ii;
if (l1Il <= l1I1)
return l1iI(llii->III, l1Il);
if (l1Il <= l1I1 + llii->II1)
return llii;
return l1iI(llii->llll, l1Il - l1I1 - llii->II1);
}
lllI l1II(int l1Il) const {
return l1iI(ll1l, l1Il);
}
lllI lill(lllI llii, int l1Il) const {
if (llii == NULL)
return NULL;
int l1I1 = 0;
if (llii->III)
l1I1 = llii->III->lil1;
if (l1Il <= l1I1)
return lill(llii->III, l1Il);
if (l1Il == l1I1 + 1)
return llii;
return lill(llii->llll, l1Il - l1I1 - 1);
}
lllI lili(int l1Il) const {
return lill(ll1l, l1Il);
}
lllI lilI(lllI llii, int li1l) const {
if (llii == NULL)
return NULL;
int li11 = 0;
if (llii->llll)
li11 = llii->llll->l1Ii;
if (li1l <= li11)
return lilI(llii->llll, li1l);
if (li1l <= li11 + llii->II1)
return llii;
return lilI(llii->III, li1l - li11 - llii->II1);
}
lllI li1i(int li1l) const {
return lilI(ll1l, li1l);
}
lllI li1I(lllI llii, int li1l) const {
if (llii == NULL)
return NULL;
int li11 = 0;
if (llii->llll)
li11 = llii->llll->lil1;
if (li1l <= li11)
return li1I(llii->llll, li1l);
if (li1l == li11 + 1)
return llii;
return li1I(llii->III, li1l - li11 - 1);
}
lllI liil(int li1l) const {
return li1I(ll1l, li1l);
}
void erase(lllI & llii, I1I IiI) {
if (llii == NULL)
return;
if (llii->IiI == IiI) {
#ifndef __SET__ONLY__
llii->II1--;
#ifdef __KEY_INFO_LIST_SUPPORT__
if (llii->IIl) {
I1l * l1li = llii->IIl;
llii->IIl = llii->IIl->I11;
#ifdef __STATIC_ALLOCATION__
ll11->Il1(l1li);
#else
delete l1li;
#endif
}
#endif
if (llii->II1 <= 0) {
lllI lii1 = llii;
llI1(llii, llii->III, llii->llll);
#ifndef __STATIC_ALLOCATION__
delete lii1;
#else
ll1i->Il1(lii1);
#endif
}
#else
lllI lii1 = llii;
llI1(llii, llii->III, llii->llll);
#ifndef __STATIC_ALLOCATION__
delete lii1;
#else
ll1i->Il1(lii1);
#endif
#endif
return;
}
if (llii->IiI < IiI)
erase(llii->llll, IiI);
else
erase(llii->III, IiI);
}
void erase(I1I IiI) {
erase(ll1l, IiI);
}
lllI liii(lllI llii) const {
if (llii == NULL)
return llii;
while (llii->III)
llii = llii->III;
return llii;
}
lllI liiI() const {
return liii(ll1l);
}
lllI liIl(lllI llii) const {
if (llii == NULL)
return llii;
while (llii->llll)
llii = llii->llll;
return llii;
}
lllI liI1(lllI llii) const {
return liIl(ll1l);
}
lllI liIi(I1I value) const {
lllI llii = ll1l;
if (llii == NULL)
return llii;
lllI liII = NULL;
while (llii) {
if (llii->IiI < value)
llii = llii->llll;
else if (llii->IiI > value) {
if (liII == NULL)
liII = llii;
else
if (llii->IiI < liII->IiI)
liII = llii;
llii = llii->III;
}
else
break;
}
if (llii)
if (llii->llll) {
lllI l1ii = liii(llii->llll);
if (liII == NULL)
liII = l1ii;
else
if (l1ii->IiI < liII->IiI)
liII = l1ii;
}
return liII;
}
lllI lIll(I1I value) const {
lllI llii = ll1l;
if (llii == NULL)
return llii;
lllI lIl1 = NULL;
while (llii) {
if (llii->IiI < value) {
if (lIl1 == NULL)
lIl1 = llii;
else
if (llii->IiI > lIl1->IiI)
lIl1 = llii;
llii = llii->llll;
}
else if (llii->IiI > value)
llii = llii->III;
else
break;
}
if (llii)
if (llii->III) {
lllI l1ii = liIl(llii->III);
if (lIl1 == NULL)
lIl1 = l1ii;
else
if (l1ii->IiI > lIl1->IiI)
lIl1 = l1ii;
}
return lIl1;
}
int lIli(I1I value) const {
lllI llii = ll1l;
if (llii == NULL)
return 0;
while (llii)
if (llii->IiI < value)
llii = llii->llll;
else if (llii->IiI > value)
llii = llii->III;
else
break;
if (llii == NULL)
return 0;
return llii->II1;
}
int lIlI(I1I value) const {
lllI llii = ll1l;
if (llii == NULL)
return 0;
int Ill = 0;
while (llii)
if (llii->IiI < value) {
Ill += llii->II1;
if (llii->III)
Ill += llii->III->l1Ii;
llii = llii->llll;
}
else if (llii->IiI > value)
llii = llii->III;
else
break;
if (llii)
if (llii->III)
Ill += llii->III->l1Ii;
return Ill;
}
int lI1l(I1I value) const {
lllI llii = ll1l;
if (llii == NULL)
return 0;
int Ill = 0;
while (llii)
if (llii->IiI < value) {
Ill++;
if (llii->III)
Ill += llii->III->lil1;
llii = llii->llll;
}
else if (llii->IiI > value)
llii = llii->III;
else
break;
if (llii)
if (llii->III)
Ill += llii->III->lil1;
return Ill;
}
int lI11(I1I value) const {
lllI llii = ll1l;
if (llii == NULL)
return 0;
int Ill = 0;
while (llii)
if (llii->IiI < value)
llii = llii->llll;
else if (llii->IiI > value) {
Ill += llii->II1;
if (llii->llll)
Ill += llii->llll->l1Ii;
llii = llii->III;
}
else
break;
if (llii)
if (llii->llll)
Ill += llii->llll->l1Ii;
return Ill;
}
int lI1i(I1I value) const {
lllI llii = ll1l;
if (llii == NULL)
return 0;
int Ill = 0;
while (llii)
if (llii->IiI < value)
llii = llii->llll;
else if (llii->IiI > value) {
Ill++;
if (llii->llll)
Ill += llii->llll->lil1;
llii = llii->III;
}
else
break;
if (llii)
if (llii->llll)
Ill += llii->llll->lil1;
return Ill;
}
int l11I() {
if (ll1l == NULL)
return 0;
return ll1l->l1Ii;
}
int lI1I() {
if (ll1l == NULL)
return 0;
ll1l->lIil();
return ll1l->lil1;
}
size_t size() {
return (size_t) (max(0, l11I()));
}
int empty() {
return size() == 0;
}
lllI begin() const {
lllI llii = ll1l;
if (llii == NULL)
return NULL;
while (llii->III) llii = llii->III;
return llii;
}
lllI lIi1() const {
lllI llii = ll1l;
if (llii == NULL)
return NULL;
while (llii->llll) llii = llii->llll;
return llii;
}
};
}
using namespace IlI;
int const lIii = 300100;
struct lIiI {long long lIIl,lII1; int lIIi;} lIII[lIii];
bool operator < (const lIiI &illl, const lIiI &ill1) {
return illl.lIIl < ill1.lIIl || (illl.lIIl == ill1.lIIl && illl.lII1-illl.lIIl < ill1.lII1-ill1.lIIl);
}
Iil<pair<long long, long long> > illi;
Iil<pair<long long, long long> >::lllI illI;
int main() {
int il1l;
scanf("%d",&il1l);
for (int iiI=0; iiI<il1l; iiI++) {
lIII[iiI].lIIi = iiI;
scanf("%I64d%I64d",&lIII[iiI].lIIl,&lIII[iiI].lII1);
}
sort(lIII,lIII+il1l);
int Ili = -1;
for (int iiI=0; iiI<il1l; iiI++)
if (lIII[iiI].lIIi==0) Ili = iiI;
long long il11 = lIII[Ili].lIIl;
int Ill = 0;
for (int iiI=0; iiI<il1l; iiI++)
if (lIII[iiI].lIIl > il11) Ill++;
long long lII1 = lIII[Ili].lII1;
for (int llIl=Ili; llIl+1<il1l; llIl++) lIII[llIl] = lIII[llIl+1];
il1l--;
lIII[il1l].lIIi = -1; lIII[il1l].lIIl = 0; lIII[il1l].lII1 = 0;
int il1i = Ili;
while (il1i < il1l && lIII[il1i].lIIl <= il11) il1i++;
if (il1i >= il1l) {
cout<<(Ill+1);
return 0;
}
int il1I = 0;
for (int iiI=il1i; iiI<il1l; iiI++) {
illi.insert(make_pair(lIII[iiI].lII1-lIII[iiI].lIIl+1, lIII[iiI].lIIl));
il1I++;
}
while (il11 > 0 && il1I > 0) {
Ill = min(Ill, il1I);
illI = illi.begin();
if (il11 < illI->IiI.first) break;
il11 -= illI->IiI.first;
il1I--;
illi.erase(illI->IiI);
int ilil = il1i;
while (il1i >= 1 && lIII[il1i-1].lIIl > il11) il1i--;
for (int ili1=il1i; ili1<ilil; ili1++) {
il1I++;
illi.insert(make_pair(lIII[ili1].lII1-lIII[ili1].lIIl+1, lIII[ili1].lIIl));
}
}
Ill = min(Ill, il1I);
cout<<(Ill+1);
return 0;
}