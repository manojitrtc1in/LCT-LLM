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
clear();
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
clear();
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
void ll1l() {
III = 1;
llll = II1;
if (lll1) {
III += lll1->III;
llll += lll1->llll;
}
if (llli) {
III += llli->III;
llll += llli->llll;
}
}
void clear() {
IiI = Ii1();
#ifdef __KEY_INFO_LIST_SUPPORT__
while (IIl) {
I1l * ll11 = IIl;
IIl = IIl->I11;
#ifdef __STATIC_ALLOCATION__
lllI->Il1(ll11);
#else
delete ll11;
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
typedef Iii<I1I> * ll1i;
private:
ll1i ll1I;
#ifdef __STATIC_ALLOCATION__
#ifdef __KEY_INFO_LIST_SUPPORT__
i11<I1l> * llil;
#endif
i11<Iii<I1I> > * lli1;
#endif
lli llii;
private:
unsigned int lliI() {
return llii.ill();
}
void llIl(ll1i llI1, I1I IiI) {
if (llI1 == NULL)
return;
if (llI1->IiI < IiI)
llIl(llI1->llli, IiI);
else if (llI1->IiI > IiI)
llIl(llI1->lll1, IiI);
if (llI1)
llI1->ll1l();
}
void llIi(ll1i llI1, I1I IiI, ll1i & llII, ll1i & l1ll) {
if (llI1 == NULL) {
llII = l1ll = NULL;
return;
}
if (IiI <= llI1->IiI) {
llIi(llI1->lll1, IiI, llII, llI1->lll1);
l1ll = llI1;
if (l1ll)
l1ll->ll1l();
}
else {
llIi(llI1->llli, IiI, llI1->llli, l1ll);
llII = llI1;
if (llII)
llII->ll1l();
}
}
void l1l1(ll1i & llI1, ll1i llII, ll1i l1ll) {
if (llII == NULL) {
llI1 = l1ll;
if (llI1)
llI1->ll1l();
return;
}
if (l1ll == NULL) {
llI1 = llII;
if (llI1)
llI1->ll1l();
return;
}
if (llII->IIi > l1ll->IIi) {
l1l1(llII->llli, llII->llli, l1ll);
llI1 = llII;
}
else {
l1l1(l1ll->lll1, llII, l1ll->lll1);
llI1 = l1ll;
}
if (llI1)
llI1->ll1l();
}
#ifndef __STATIC_ALLOCATION__
void l1li(ll1i llI1) {
if (llI1 == NULL) return;
l1li(llI1->lll1);
l1li(llI1->llli);
delete llI1;
}
#endif
void insert(ll1i & llI1, ll1i & l1lI) {
if (llI1 == NULL) {
llI1 = l1lI;
if (llI1)
llI1->ll1l();
return;
}
if (llI1->IiI == l1lI->IiI) {
llI1->II1 += l1lI->II1;
#ifdef __KEY_INFO_LIST_SUPPORT__
I1l * l11l = l1lI->IIl;
while (l11l) {
I1l * l111 = l11l->I11;
l11l->I11 = llI1->IIl;
llI1->IIl = l11l;
l11l = l111;
}
#endif
#ifdef __SET__ONLY__
#ifdef __KEY_INFO_LIST_SUPPORT__
int l11i = llI1->II1;
l11i -= 1;
while (llI1->IIl != NULL && l11i > 0) {
I1l * ll11 = llI1->IIl;
llI1->IIl = llI1->IIl->I11;
#ifdef __STATIC_ALLOCATION__
llil->Il1(ll11);
#else
delete ll11;
#endif
l11i--;
}
#endif
llI1->II1 = min(llI1->II1, 1);
#endif
#ifdef __KEY_INFO_LIST_SUPPORT__
l1lI->IIl = NULL;
#endif
#ifdef __STATIC_ALLOCATION__
lli1->Il1(l1lI);
#else
delete l1lI;
#endif
if (llI1)
llI1->ll1l();
l1lI = llI1;
return;
}
if (l1lI->IIi > llI1->IIi) {
llIi(llI1, l1lI->IiI, l1lI->lll1, l1lI->llli);
llI1 = l1lI;
if (llI1)
llI1->ll1l();
return;
}
if (llI1->IiI < l1lI->IiI)
insert(llI1->llli, l1lI);
else
insert(llI1->lll1, l1lI);
if (llI1)
llI1->ll1l();
}
public:
void clear() {
#ifndef __STATIC_ALLOCATION__
l1li(ll1I);
#else
int l11I = 0;
if (ll1I != NULL) {
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
while (ll1I)
erase(ll1I->IiI);
}
else
lli1->clear();
#endif
ll1I = NULL;
}
Iil() {
ll1I = NULL;
#ifdef __STATIC_ALLOCATION__
#ifdef __KEY_INFO_LIST_SUPPORT__
llil = new i11<I1l> (I1i);
lli1 = new i11<Iii<I1I> > (I1i, llil);
#else
lli1 = new i11<Iii<I1I> > (I1i);
#endif
#endif
}
~Iil() {
clear();
#ifdef __STATIC_ALLOCATION__
if (lli1 != NULL)
delete lli1;
#ifdef __KEY_INFO_LIST_SUPPORT__
if (llil != NULL)
delete llil;
#endif
#endif
}
ll1i insert(ll1i & llI1, I1I IiI, unsigned int IIi  ) {
ll1i Ili = find(IiI);
if (Ili != NULL) {
Ili->II1++;
Ili->ll1l();
llIl(ll1I, IiI);
return Ili;
}
#ifdef __STATIC_ALLOCATION__
if (lli1->iIi())
return NULL;
ll1i l1lI = lli1->iII();
if (l1lI == NULL)
return NULL;
l1lI->IiI = IiI;
l1lI->IIi = IIi;
l1lI->lll1 = l1lI->llli = NULL;
#ifdef __KEY_INFO_LIST_SUPPORT__
l1lI->IIl = llil->iII();
#endif
#else
ll1i l1lI = new (std::nothrow) Iii<I1I>;
if (l1lI == NULL)
return NULL;
l1lI->IiI = IiI;
l1lI->IIi = IIi;
l1lI->lll1 = l1lI->llli = NULL;
#ifdef __KEY_INFO_LIST_SUPPORT__
l1lI->IIl = new (std::nothrow) I1l;
#endif
#endif
#ifdef __KEY_INFO_LIST_SUPPORT__
if (l1lI->IIl == NULL) {
#ifndef __STATIC_ALLOCATION__
l1lI->clear();
delete l1lI;
#else
lli1->Il1(l1lI);
#endif
return NULL;
}
l1lI->IIl->I11 = NULL;
#endif
l1lI->II1 = l1lI->III = l1lI->llll = 1;
l1lI->ll1l();
insert(llI1, l1lI);
return l1lI;
}
ll1i insert(ll1i & llI1 , I1I IiI  ) {
return insert(llI1, IiI, lliI()  );
}
ll1i insert(I1I IiI, unsigned int IIi  ) {
return insert(ll1I, IiI, IIi  );
}
ll1i insert(I1I IiI  ) {
return insert(ll1I, IiI, lliI()  );
}
ll1i find(ll1i llI1, I1I IiI) const {
if (llI1 == NULL)
return NULL;
if (llI1->IiI < IiI)
return find(llI1->llli, IiI);
else if (llI1->IiI > IiI)
return find(llI1->lll1, IiI);
else
return llI1;
}
ll1i find(I1I IiI) const {
return find(ll1I, IiI);
}
ll1i l1Il(ll1i llI1, int l1I1) const {
if (llI1 == NULL)
return NULL;
int l1Ii = 0;
if (llI1->lll1)
l1Ii = llI1->lll1->llll;
if (l1I1 <= l1Ii)
return l1Il(llI1->lll1, l1I1);
if (l1I1 <= l1Ii + llI1->II1)
return llI1;
return l1Il(llI1->llli, l1I1 - l1Ii - llI1->II1);
}
ll1i l1II(int l1I1) const {
return l1Il(ll1I, l1I1);
}
ll1i lill(ll1i llI1, int l1I1) const {
if (llI1 == NULL)
return NULL;
int l1Ii = 0;
if (llI1->lll1)
l1Ii = llI1->lll1->III;
if (l1I1 <= l1Ii)
return lill(llI1->lll1, l1I1);
if (l1I1 == l1Ii + 1)
return llI1;
return lill(llI1->llli, l1I1 - l1Ii - 1);
}
ll1i lil1(int l1I1) const {
return lill(ll1I, l1I1);
}
ll1i lili(ll1i llI1, int lilI) const {
if (llI1 == NULL)
return NULL;
int li1l = 0;
if (llI1->llli)
li1l = llI1->llli->llll;
if (lilI <= li1l)
return lili(llI1->llli, lilI);
if (lilI <= li1l + llI1->II1)
return llI1;
return lili(llI1->lll1, lilI - li1l - llI1->II1);
}
ll1i li11(int lilI) const {
return lili(ll1I, lilI);
}
ll1i li1i(ll1i llI1, int lilI) const {
if (llI1 == NULL)
return NULL;
int li1l = 0;
if (llI1->llli)
li1l = llI1->llli->III;
if (lilI <= li1l)
return li1i(llI1->llli, lilI);
if (lilI == li1l + 1)
return llI1;
return li1i(llI1->lll1, lilI - li1l - 1);
}
ll1i li1I(int lilI) const {
return li1i(ll1I, lilI);
}
void erase(ll1i & llI1, I1I IiI) {
if (llI1 == NULL)
return;
if (llI1->IiI == IiI) {
#ifndef __SET__ONLY__
llI1->II1--;
#ifdef __KEY_INFO_LIST_SUPPORT__
if (llI1->IIl) {
I1l * l11l = llI1->IIl;
llI1->IIl = llI1->IIl->I11;
#ifdef __STATIC_ALLOCATION__
llil->Il1(l11l);
#else
delete l11l;
#endif
}
#endif
if (llI1->II1 <= 0) {
ll1i liil = llI1;
l1l1(llI1, llI1->lll1, llI1->llli);
#ifndef __STATIC_ALLOCATION__
delete liil;
#else
lli1->Il1(liil);
#endif
}
#else
ll1i liil = llI1;
l1l1(llI1, llI1->lll1, llI1->llli);
#ifndef __STATIC_ALLOCATION__
delete liil;
#else
lli1->Il1(liil);
#endif
#endif
if (llI1)
llI1->ll1l();
return;
}
if (llI1->IiI < IiI)
erase(llI1->llli, IiI);
else
erase(llI1->lll1, IiI);
if (llI1)
llI1->ll1l();
}
void erase(I1I IiI) {
erase(ll1I, IiI);
}
ll1i lii1(ll1i llI1) const {
if (llI1 == NULL)
return llI1;
while (llI1->lll1)
llI1 = llI1->lll1;
return llI1;
}
ll1i liii() const {
return lii1(ll1I);
}
ll1i liiI(ll1i llI1) const {
if (llI1 == NULL)
return llI1;
while (llI1->llli)
llI1 = llI1->llli;
return llI1;
}
ll1i liIl(ll1i llI1) const {
return liiI(ll1I);
}
ll1i liI1(I1I value) const {
ll1i llI1 = ll1I;
if (llI1 == NULL)
return llI1;
ll1i liIi = NULL;
while (llI1) {
if (llI1->IiI < value)
llI1 = llI1->llli;
else if (llI1->IiI > value) {
if (liIi == NULL)
liIi = llI1;
else
if (llI1->IiI < liIi->IiI)
liIi = llI1;
llI1 = llI1->lll1;
}
else
break;
}
if (llI1)
if (llI1->llli) {
ll1i liII = lii1(llI1->llli);
if (liIi == NULL)
liIi = liII;
else
if (liII->IiI < liIi->IiI)
liIi = liII;
}
return liIi;
}
ll1i lIll(I1I value) const {
ll1i llI1 = ll1I;
if (llI1 == NULL)
return llI1;
ll1i lIl1 = NULL;
while (llI1) {
if (llI1->IiI < value) {
if (lIl1 == NULL)
lIl1 = llI1;
else
if (llI1->IiI > lIl1->IiI)
lIl1 = llI1;
llI1 = llI1->llli;
}
else if (llI1->IiI > value)
llI1 = llI1->lll1;
else
break;
}
if (llI1)
if (llI1->lll1) {
ll1i liII = liiI(llI1->lll1);
if (lIl1 == NULL)
lIl1 = liII;
else
if (liII->IiI > lIl1->IiI)
lIl1 = liII;
}
return lIl1;
}
int lIli(I1I value) const {
ll1i llI1 = ll1I;
if (llI1 == NULL)
return 0;
while (llI1)
if (llI1->IiI < value)
llI1 = llI1->llli;
else if (llI1->IiI > value)
llI1 = llI1->lll1;
else
break;
if (llI1 == NULL)
return 0;
return llI1->II1;
}
int lIlI(I1I value) const {
ll1i llI1 = ll1I;
if (llI1 == NULL)
return 0;
int Ill = 0;
while (llI1)
if (llI1->IiI < value) {
Ill += llI1->II1;
if (llI1->lll1)
Ill += llI1->lll1->llll;
llI1 = llI1->llli;
}
else if (llI1->IiI > value)
llI1 = llI1->lll1;
else
break;
if (llI1)
if (llI1->lll1)
Ill += llI1->lll1->llll;
return Ill;
}
int lI1l(I1I value) const {
ll1i llI1 = ll1I;
if (llI1 == NULL)
return 0;
int Ill = 0;
while (llI1)
if (llI1->IiI < value) {
Ill++;
if (llI1->lll1)
Ill += llI1->lll1->III;
llI1 = llI1->llli;
}
else if (llI1->IiI > value)
llI1 = llI1->lll1;
else
break;
if (llI1)
if (llI1->lll1)
Ill += llI1->lll1->III;
return Ill;
}
int lI11(I1I value) const {
ll1i llI1 = ll1I;
if (llI1 == NULL)
return 0;
int Ill = 0;
while (llI1)
if (llI1->IiI < value)
llI1 = llI1->llli;
else if (llI1->IiI > value) {
Ill += llI1->II1;
if (llI1->llli)
Ill += llI1->llli->llll;
llI1 = llI1->lll1;
}
else
break;
if (llI1)
if (llI1->llli)
Ill += llI1->llli->llll;
return Ill;
}
int lI1i(I1I value) const {
ll1i llI1 = ll1I;
if (llI1 == NULL)
return 0;
int Ill = 0;
while (llI1)
if (llI1->IiI < value)
llI1 = llI1->llli;
else if (llI1->IiI > value) {
Ill++;
if (llI1->llli)
Ill += llI1->llli->III;
llI1 = llI1->lll1;
}
else
break;
if (llI1)
if (llI1->llli)
Ill += llI1->llli->III;
return Ill;
}
int l1i1() {
if (ll1I == NULL)
return 0;
ll1I->ll1l();
return ll1I->llll;
}
int lI1I() {
if (ll1I == NULL)
return 0;
ll1I->ll1l();
return ll1I->III;
}
size_t size() {
return (size_t) (max(0, l1i1()));
}
int empty() {
return size() == 0;
}
ll1i begin() const {
return l1II(1);
}
ll1i lIil() const {
return li11(1);
}
};
}
using namespace IlI;
Iil<pair<long long,long long> > lIi1;
Iil<pair<long long,long long> >::ll1i lIii;
int const lIiI = 300100;
struct lIIl {long long lII1,lIIi; int lIII;} illl[lIiI];
bool operator < (const lIIl &ill1, const lIIl &illi) {
return ill1.lII1 < illi.lII1 || (ill1.lII1 == illi.lII1 && ill1.lIIi-ill1.lII1 < illi.lIIi-illi.lII1);
}
int main() {
int illI;
scanf("%d",&illI);
for (int iiI=0; iiI<illI; iiI++) {
illl[iiI].lIII = iiI;
scanf("%I64d%I64d",&illl[iiI].lII1,&illl[iiI].lIIi);
}
sort(illl,illl+illI);
int Ili = -1;
for (int iiI=0; iiI<illI; iiI++)
if (illl[iiI].lIII==0) Ili = iiI;
long long il1l = illl[Ili].lII1;
int Ill = 0;
for (int iiI=0; iiI<illI; iiI++)
if (illl[iiI].lII1 > il1l) Ill++;
long long lIIi = illl[Ili].lIIi;
for (int l1ll=Ili; l1ll+1<illI; l1ll++) illl[l1ll] = illl[l1ll+1];
illI--;
illl[illI].lIII = -1; illl[illI].lII1 = 0; illl[illI].lIIi = 0;
int il11 = Ili;
while (il11 < illI && illl[il11].lII1 <= il1l) il11++;
if (il11 >= illI) {
cout<<(Ill+1);
return 0;
}
for (int iiI=il11; iiI<illI; iiI++) lIi1.insert(make_pair(illl[iiI].lIIi-illl[iiI].lII1+1, illl[iiI].lII1));
while (il1l > 0 && !(lIi1.empty())) {
Ill = min(Ill, ((int) lIi1.size()));
lIii = lIi1.begin();
if (il1l < lIii->IiI.first) break;
il1l -= lIii->IiI.first;
lIi1.erase(lIii->IiI);
int il1i = il11;
while (il11 >= 1 && illl[il11-1].lII1 > il1l) il11--;
for (int il1I=il11; il1I<il1i; il1I++) lIi1.insert(make_pair(illl[il1I].lIIi-illl[il1I].lII1+1, illl[il1I].lII1));
}
Ill = min(Ill, ((int) lIi1.size()));
cout<<(Ill+1);
return 0;
}