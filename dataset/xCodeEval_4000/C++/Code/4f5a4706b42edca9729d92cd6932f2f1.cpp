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
int III;
int llll;
Iii *lll1, *llli;
#ifdef __STATIC_ALLOCATION__
#ifdef __KEY_INFO_LIST_SUPPORT__
i11<I1l> * lllI;
#endif
#endif
public:
void clear() {
IiI = Ii1();
#ifdef __KEY_INFO_LIST_SUPPORT__
while (IIl) {
I1l * ll1l = IIl;
IIl = IIl->I11;
#ifdef __STATIC_ALLOCATION__
lllI->Il1(ll1l);
#else
delete ll1l;
#endif
}
#endif
II1 = 0;
IIi = 0UL;
III = 0;
llll = 0;
lll1 = llli = NULL;
}
#ifdef __STATIC_ALLOCATION__
Iii(va_list iI1) {
#ifdef __KEY_INFO_LIST_SUPPORT__
IIl = NULL;
lllI = va_arg(iI1, i11<I1l> *);
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
typedef Iii<I1I> * ll11;
private:
ll11 ll1i;
#ifdef __STATIC_ALLOCATION__
#ifdef __KEY_INFO_LIST_SUPPORT__
i11<I1l> * ll1I;
#endif
i11<Iii<I1I> > * llil;
#endif
lli lli1;
private:
unsigned int llii() {
return lli1.ill();
}
void lliI(ll11 llIl, I1I IiI, ll11 & llI1, ll11 & llIi) {
if (llIl == NULL) {
llI1 = llIi = NULL;
return;
}
if (IiI <= llIl->IiI) {
lliI(llIl->lll1, IiI, llI1, llIl->lll1);
llIi = llIl;
}
else {
lliI(llIl->llli, IiI, llIl->llli, llIi);
llI1 = llIl;
}
}
void llII(ll11 & llIl, ll11 llI1, ll11 llIi) {
if (llI1 == NULL) {
llIl = llIi;
return;
}
if (llIi == NULL) {
llIl = llI1;
return;
}
if (llI1->IIi > llIi->IIi) {
llII(llI1->llli, llI1->llli, llIi);
llIl = llI1;
}
else {
llII(llIi->lll1, llI1, llIi->lll1);
llIl = llIi;
}
}
#ifndef __STATIC_ALLOCATION__
void l1ll(ll11 llIl) {
if (llIl == NULL) return;
l1ll(llIl->lll1);
l1ll(llIl->llli);
delete llIl;
}
#endif
ll11 l1l1(I1I IiI, unsigned int IIi  ) {
#ifdef __STATIC_ALLOCATION__
if (llil->iIi())
return NULL;
ll11 l1li = llil->iII();
if (l1li == NULL)
return NULL;
l1li->IiI = IiI;
l1li->IIi = IIi;
l1li->lll1 = l1li->llli = NULL;
#ifdef __KEY_INFO_LIST_SUPPORT__
l1li->IIl = ll1I->iII();
#endif
#else
ll11 l1li = new (std::nothrow) Iii<I1I>;
if (l1li == NULL)
return NULL;
l1li->IiI = IiI;
l1li->IIi = IIi;
l1li->lll1 = l1li->llli = NULL;
#ifdef __KEY_INFO_LIST_SUPPORT__
l1li->IIl = new (std::nothrow) I1l;
#endif
#endif
#ifdef __KEY_INFO_LIST_SUPPORT__
if (l1li->IIl == NULL) {
#ifndef __STATIC_ALLOCATION__
l1li->clear();
delete l1li;
#else
llil->Il1(l1li);
#endif
return NULL;
}
l1li->IIl->I11 = NULL;
#endif
l1li->II1 = l1li->III = l1li->llll = 1;
return l1li;
}
void l1lI(ll11 & llIl, I1I IiI  ) {
llIl->II1 += 1;
#ifdef __KEY_INFO_LIST_SUPPORT__
#ifdef __STATIC_ALLOCATION__
I1l * l11l = ll1I->iII();
#else
I1l * l11l = new (std::nothrow) I1l;
#endif
if (l11l == NULL)
return;
l11l->I11 = llIl->IIl;
llIl->IIl = l11l;
#endif
#ifdef __SET__ONLY__
#ifdef __KEY_INFO_LIST_SUPPORT__
int l111 = llIl->II1;
l111--;
while (llIl->IIl != NULL && l111 > 0) {
I1l * ll1l = llIl->IIl;
llIl->IIl = llIl->IIl->I11;
#ifdef __STATIC_ALLOCATION__
ll1I->Il1(ll1l);
#else
delete ll1l;
#endif
l111--;
}
#endif
llIl->II1 = min(llIl->II1, 1);
#endif
}
ll11 l11i(ll11 & llIl, I1I IiI  ) {
if (llIl == NULL)
return NULL;
if (llIl->IiI == IiI) {
l1lI(llIl, IiI  );
return llIl;
}
ll11 Ill = NULL;
if (llIl->IiI < IiI)
Ill = l11i(llIl->llli, IiI  );
else
Ill = l11i(llIl->lll1, IiI  );
return Ill;
}
public:
void clear() {
#ifndef __STATIC_ALLOCATION__
l1ll(ll1i);
#else
int l11I = 0;
if (ll1i != NULL) {
long long l1il = l1i1();
long long l1ii = 1LL, l1iI = 1LL;
while (l1iI < l1il) {
l1iI *= 2LL;
l1ii++;
}
if (l1il * l1ii * 3LL < (long long) I1i)
l11I = 1;
}
else
l11I = 1;
if (l11I) {
while (ll1i)
erase(ll1i->IiI);
}
else
llil->clear();
#endif
ll1i = NULL;
}
Iil() {
ll1i = NULL;
#ifdef __STATIC_ALLOCATION__
#ifdef __KEY_INFO_LIST_SUPPORT__
ll1I = new i11<I1l> (I1i);
llil = new i11<Iii<I1I> > (I1i, ll1I);
#else
llil = new i11<Iii<I1I> > (I1i);
#endif
#endif
}
~Iil() {
#ifdef __STATIC_ALLOCATION__
if (llil != NULL)
delete llil;
#ifdef __KEY_INFO_LIST_SUPPORT__
if (ll1I != NULL)
delete ll1I;
#endif
#else
l1ll(ll1i);
#endif
}
ll11 insert(ll11 & llIl, I1I IiI, unsigned int IIi  ) {
if (llIl == NULL) {
ll11 l1li = l1l1(IiI, IIi  );
if (l1li == NULL)
return NULL;
llIl = l1li;
return llIl;
}
if (llIl->IiI == IiI) {
l1lI(llIl, IiI  );
return llIl;
}
if (IIi > llIl->IIi) {
ll11 l1Il = l11i(llIl, IiI  );
if (l1Il != NULL) {
return l1Il;
}
ll11 l1li = l1l1(IiI, IIi  );
if (l1li == NULL)
return NULL;
lliI(llIl, l1li->IiI, l1li->lll1, l1li->llli);
llIl = l1li;
return llIl;
}
ll11 Ill = NULL;
if (llIl->IiI < IiI)
Ill = insert(llIl->llli, IiI, IIi  );
else
Ill = insert(llIl->lll1, IiI, IIi  );
return Ill;
}
ll11 insert(ll11 & llIl , I1I IiI  ) {
return insert(llIl, IiI, llii()  );
}
ll11 insert(I1I IiI, unsigned int IIi  ) {
return insert(ll1i, IiI, IIi  );
}
ll11 insert(I1I IiI  ) {
return insert(ll1i, IiI, llii()  );
}
ll11 find(ll11 llIl, I1I IiI) const {
if (llIl == NULL)
return NULL;
if (llIl->IiI < IiI)
return find(llIl->llli, IiI);
else if (llIl->IiI > IiI)
return find(llIl->lll1, IiI);
else
return llIl;
}
ll11 find(I1I IiI) const {
return find(ll1i, IiI);
}
ll11 l1I1(ll11 llIl, int l1Ii) const {
if (llIl == NULL)
return NULL;
int l1II = 0;
if (llIl->lll1)
l1II = llIl->lll1->llll;
if (l1Ii <= l1II)
return l1I1(llIl->lll1, l1Ii);
if (l1Ii <= l1II + llIl->II1)
return llIl;
return l1I1(llIl->llli, l1Ii - l1II - llIl->II1);
}
ll11 lill(int l1Ii) const {
return l1I1(ll1i, l1Ii);
}
ll11 lil1(ll11 llIl, int l1Ii) const {
if (llIl == NULL)
return NULL;
int l1II = 0;
if (llIl->lll1)
l1II = llIl->lll1->III;
if (l1Ii <= l1II)
return lil1(llIl->lll1, l1Ii);
if (l1Ii == l1II + 1)
return llIl;
return lil1(llIl->llli, l1Ii - l1II - 1);
}
ll11 lili(int l1Ii) const {
return lil1(ll1i, l1Ii);
}
ll11 lilI(ll11 llIl, int li1l) const {
if (llIl == NULL)
return NULL;
int li11 = 0;
if (llIl->llli)
li11 = llIl->llli->llll;
if (li1l <= li11)
return lilI(llIl->llli, li1l);
if (li1l <= li11 + llIl->II1)
return llIl;
return lilI(llIl->lll1, li1l - li11 - llIl->II1);
}
ll11 li1i(int li1l) const {
return lilI(ll1i, li1l);
}
ll11 li1I(ll11 llIl, int li1l) const {
if (llIl == NULL)
return NULL;
int li11 = 0;
if (llIl->llli)
li11 = llIl->llli->III;
if (li1l <= li11)
return li1I(llIl->llli, li1l);
if (li1l == li11 + 1)
return llIl;
return li1I(llIl->lll1, li1l - li11 - 1);
}
ll11 liil(int li1l) const {
return li1I(ll1i, li1l);
}
void erase(ll11 & llIl, I1I IiI) {
if (llIl == NULL)
return;
if (llIl->IiI == IiI) {
#ifndef __SET__ONLY__
llIl->II1--;
#ifdef __KEY_INFO_LIST_SUPPORT__
if (llIl->IIl) {
I1l * l11l = llIl->IIl;
llIl->IIl = llIl->IIl->I11;
#ifdef __STATIC_ALLOCATION__
ll1I->Il1(l11l);
#else
delete l11l;
#endif
}
#endif
if (llIl->II1 <= 0) {
ll11 lii1 = llIl;
llII(llIl, llIl->lll1, llIl->llli);
#ifndef __STATIC_ALLOCATION__
delete lii1;
#else
llil->Il1(lii1);
#endif
}
#else
ll11 lii1 = llIl;
llII(llIl, llIl->lll1, llIl->llli);
#ifndef __STATIC_ALLOCATION__
delete lii1;
#else
llil->Il1(lii1);
#endif
#endif
return;
}
if (llIl->IiI < IiI)
erase(llIl->llli, IiI);
else
erase(llIl->lll1, IiI);
}
void erase(I1I IiI) {
erase(ll1i, IiI);
}
ll11 liii(ll11 llIl) const {
if (llIl == NULL)
return llIl;
while (llIl->lll1)
llIl = llIl->lll1;
return llIl;
}
ll11 liiI() const {
return liii(ll1i);
}
ll11 liIl(ll11 llIl) const {
if (llIl == NULL)
return llIl;
while (llIl->llli)
llIl = llIl->llli;
return llIl;
}
ll11 liI1(ll11 llIl) const {
return liIl(ll1i);
}
ll11 liIi(I1I value) const {
ll11 llIl = ll1i;
if (llIl == NULL)
return llIl;
ll11 liII = NULL;
while (llIl) {
if (llIl->IiI < value)
llIl = llIl->llli;
else if (llIl->IiI > value) {
if (liII == NULL)
liII = llIl;
else
if (llIl->IiI < liII->IiI)
liII = llIl;
llIl = llIl->lll1;
}
else
break;
}
if (llIl)
if (llIl->llli) {
ll11 l1Il = liii(llIl->llli);
if (liII == NULL)
liII = l1Il;
else
if (l1Il->IiI < liII->IiI)
liII = l1Il;
}
return liII;
}
ll11 lIll(I1I value) const {
ll11 llIl = ll1i;
if (llIl == NULL)
return llIl;
ll11 lIl1 = NULL;
while (llIl) {
if (llIl->IiI < value) {
if (lIl1 == NULL)
lIl1 = llIl;
else
if (llIl->IiI > lIl1->IiI)
lIl1 = llIl;
llIl = llIl->llli;
}
else if (llIl->IiI > value)
llIl = llIl->lll1;
else
break;
}
if (llIl)
if (llIl->lll1) {
ll11 l1Il = liIl(llIl->lll1);
if (lIl1 == NULL)
lIl1 = l1Il;
else
if (l1Il->IiI > lIl1->IiI)
lIl1 = l1Il;
}
return lIl1;
}
int lIli(I1I value) const {
ll11 llIl = ll1i;
if (llIl == NULL)
return 0;
while (llIl)
if (llIl->IiI < value)
llIl = llIl->llli;
else if (llIl->IiI > value)
llIl = llIl->lll1;
else
break;
if (llIl == NULL)
return 0;
return llIl->II1;
}
int lIlI(I1I value) const {
ll11 llIl = ll1i;
if (llIl == NULL)
return 0;
int Ill = 0;
while (llIl)
if (llIl->IiI < value) {
Ill += llIl->II1;
if (llIl->lll1)
Ill += llIl->lll1->llll;
llIl = llIl->llli;
}
else if (llIl->IiI > value)
llIl = llIl->lll1;
else
break;
if (llIl)
if (llIl->lll1)
Ill += llIl->lll1->llll;
return Ill;
}
int lI1l(I1I value) const {
ll11 llIl = ll1i;
if (llIl == NULL)
return 0;
int Ill = 0;
while (llIl)
if (llIl->IiI < value) {
Ill++;
if (llIl->lll1)
Ill += llIl->lll1->III;
llIl = llIl->llli;
}
else if (llIl->IiI > value)
llIl = llIl->lll1;
else
break;
if (llIl)
if (llIl->lll1)
Ill += llIl->lll1->III;
return Ill;
}
int lI11(I1I value) const {
ll11 llIl = ll1i;
if (llIl == NULL)
return 0;
int Ill = 0;
while (llIl)
if (llIl->IiI < value)
llIl = llIl->llli;
else if (llIl->IiI > value) {
Ill += llIl->II1;
if (llIl->llli)
Ill += llIl->llli->llll;
llIl = llIl->lll1;
}
else
break;
if (llIl)
if (llIl->llli)
Ill += llIl->llli->llll;
return Ill;
}
int lI1i(I1I value) const {
ll11 llIl = ll1i;
if (llIl == NULL)
return 0;
int Ill = 0;
while (llIl)
if (llIl->IiI < value)
llIl = llIl->llli;
else if (llIl->IiI > value) {
Ill++;
if (llIl->llli)
Ill += llIl->llli->III;
llIl = llIl->lll1;
}
else
break;
if (llIl)
if (llIl->llli)
Ill += llIl->llli->III;
return Ill;
}
int l1i1() {
if (ll1i == NULL)
return 0;
return ll1i->llll;
}
int lI1I() {
if (ll1i == NULL)
return 0;
ll1i->lIil();
return ll1i->III;
}
size_t size() {
return (size_t) (max(0, l1i1()));
}
int empty() {
return size() == 0;
}
ll11 begin() const {
ll11 llIl = ll1i;
if (llIl == NULL)
return NULL;
while (llIl->lll1) llIl = llIl->lll1;
return llIl;
}
ll11 lIi1() const {
ll11 llIl = ll1i;
if (llIl == NULL)
return NULL;
while (llIl->llli) llIl = llIl->llli;
return llIl;
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
Iil<pair<long long, long long> >::ll11 illI;
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
for (int llIi=Ili; llIi+1<il1l; llIi++) lIII[llIi] = lIII[llIi+1];
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