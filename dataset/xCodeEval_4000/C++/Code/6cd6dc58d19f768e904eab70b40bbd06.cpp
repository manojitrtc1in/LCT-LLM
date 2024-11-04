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
void llIl(ll1i llI1, I1I IiI, ll1i & llIi, ll1i & llII) {
if (llI1 == NULL) {
llIi = llII = NULL;
return;
}
if (IiI <= llI1->IiI) {
llIl(llI1->lll1, IiI, llIi, llI1->lll1);
llII = llI1;
if (llII)
llII->ll1l();
}
else {
llIl(llI1->llli, IiI, llI1->llli, llII);
llIi = llI1;
if (llIi)
llIi->ll1l();
}
}
void l1ll(ll1i & llI1, ll1i llIi, ll1i llII) {
if (llIi == NULL) {
llI1 = llII;
if (llI1)
llI1->ll1l();
return;
}
if (llII == NULL) {
llI1 = llIi;
if (llI1)
llI1->ll1l();
return;
}
if (llIi->IIi > llII->IIi) {
l1ll(llIi->llli, llIi->llli, llII);
llI1 = llIi;
}
else {
l1ll(llII->lll1, llIi, llII->lll1);
llI1 = llII;
}
if (llI1)
llI1->ll1l();
}
#ifndef __STATIC_ALLOCATION__
void l1l1(ll1i llI1) {
if (llI1 == NULL) return;
l1l1(llI1->lll1);
l1l1(llI1->llli);
delete llI1;
}
#endif
ll1i l1li(I1I IiI, unsigned int IIi  ) {
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
return l1lI;
}
void l11l(ll1i & llI1, I1I IiI  ) {
llI1->II1 += 1;
#ifdef __KEY_INFO_LIST_SUPPORT__
#ifdef __STATIC_ALLOCATION__
I1l * l111 = llil->iII();
#else
I1l * l111 = new (std::nothrow) I1l;
#endif
if (l111 == NULL)
return;
l111->I11 = llI1->IIl;
llI1->IIl = l111;
#endif
#ifdef __SET__ONLY__
#ifdef __KEY_INFO_LIST_SUPPORT__
int l11i = llI1->II1;
l11i--;
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
}
ll1i l11I(ll1i & llI1, I1I IiI  ) {
if (llI1 == NULL)
return NULL;
if (llI1->IiI == IiI) {
l11l(llI1, IiI  );
if (llI1)
llI1->ll1l();
return llI1;
}
ll1i Ill = NULL;
if (llI1->IiI < IiI)
Ill = l11I(llI1->llli, IiI  );
else
Ill = l11I(llI1->lll1, IiI  );
if (llI1)
llI1->ll1l();
return Ill;
}
public:
void clear() {
#ifndef __STATIC_ALLOCATION__
l1l1(ll1I);
#else
int l1il = 0;
if (ll1I != NULL) {
long long l1i1 = l1ii();
long long l1iI = 1LL, l1Il = 1LL;
while (l1Il < l1i1) {
l1Il *= 2LL;
l1iI++;
}
if (l1i1 * l1iI * 3LL < (long long) I1i)
l1il = 1;
}
else
l1il = 1;
if (l1il) {
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
#ifdef __STATIC_ALLOCATION__
if (lli1 != NULL)
delete lli1;
#ifdef __KEY_INFO_LIST_SUPPORT__
if (llil != NULL)
delete llil;
#endif
#else
l1l1(ll1I);
#endif
}
ll1i insert(ll1i & llI1, I1I IiI, unsigned int IIi  ) {
if (llI1 == NULL) {
ll1i l1lI = l1li(IiI, IIi  );
if (l1lI == NULL)
return NULL;
llI1 = l1lI;
if (llI1)
llI1->ll1l();
return llI1;
}
if (llI1->IiI == IiI) {
l11l(llI1, IiI  );
if (llI1)
llI1->ll1l();
return llI1;
}
if (IIi > llI1->IIi) {
ll1i l1I1 = l11I(llI1, IiI  );
if (l1I1 != NULL) {
if (llI1)
llI1->ll1l();
return l1I1;
}
ll1i l1lI = l1li(IiI, IIi  );
if (l1lI == NULL)
return NULL;
llIl(llI1, l1lI->IiI, l1lI->lll1, l1lI->llli);
llI1 = l1lI;
if (llI1)
llI1->ll1l();
return llI1;
}
ll1i Ill = NULL;
if (llI1->IiI < IiI)
Ill = insert(llI1->llli, IiI, IIi  );
else
Ill = insert(llI1->lll1, IiI, IIi  );
if (llI1)
llI1->ll1l();
return Ill;
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
ll1i l1Ii(ll1i llI1, int l1II) const {
if (llI1 == NULL)
return NULL;
int lill = 0;
if (llI1->lll1)
lill = llI1->lll1->llll;
if (l1II <= lill)
return l1Ii(llI1->lll1, l1II);
if (l1II <= lill + llI1->II1)
return llI1;
return l1Ii(llI1->llli, l1II - lill - llI1->II1);
}
ll1i lil1(int l1II) const {
return l1Ii(ll1I, l1II);
}
ll1i lili(ll1i llI1, int l1II) const {
if (llI1 == NULL)
return NULL;
int lill = 0;
if (llI1->lll1)
lill = llI1->lll1->III;
if (l1II <= lill)
return lili(llI1->lll1, l1II);
if (l1II == lill + 1)
return llI1;
return lili(llI1->llli, l1II - lill - 1);
}
ll1i lilI(int l1II) const {
return lili(ll1I, l1II);
}
ll1i li1l(ll1i llI1, int li11) const {
if (llI1 == NULL)
return NULL;
int li1i = 0;
if (llI1->llli)
li1i = llI1->llli->llll;
if (li11 <= li1i)
return li1l(llI1->llli, li11);
if (li11 <= li1i + llI1->II1)
return llI1;
return li1l(llI1->lll1, li11 - li1i - llI1->II1);
}
ll1i li1I(int li11) const {
return li1l(ll1I, li11);
}
ll1i liil(ll1i llI1, int li11) const {
if (llI1 == NULL)
return NULL;
int li1i = 0;
if (llI1->llli)
li1i = llI1->llli->III;
if (li11 <= li1i)
return liil(llI1->llli, li11);
if (li11 == li1i + 1)
return llI1;
return liil(llI1->lll1, li11 - li1i - 1);
}
ll1i lii1(int li11) const {
return liil(ll1I, li11);
}
void erase(ll1i & llI1, I1I IiI) {
if (llI1 == NULL)
return;
if (llI1->IiI == IiI) {
#ifndef __SET__ONLY__
llI1->II1--;
#ifdef __KEY_INFO_LIST_SUPPORT__
if (llI1->IIl) {
I1l * l111 = llI1->IIl;
llI1->IIl = llI1->IIl->I11;
#ifdef __STATIC_ALLOCATION__
llil->Il1(l111);
#else
delete l111;
#endif
}
#endif
if (llI1->II1 <= 0) {
ll1i liii = llI1;
l1ll(llI1, llI1->lll1, llI1->llli);
#ifndef __STATIC_ALLOCATION__
delete liii;
#else
lli1->Il1(liii);
#endif
}
#else
ll1i liii = llI1;
l1ll(llI1, llI1->lll1, llI1->llli);
#ifndef __STATIC_ALLOCATION__
delete liii;
#else
lli1->Il1(liii);
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
ll1i liiI(ll1i llI1) const {
if (llI1 == NULL)
return llI1;
while (llI1->lll1)
llI1 = llI1->lll1;
return llI1;
}
ll1i liIl() const {
return liiI(ll1I);
}
ll1i liI1(ll1i llI1) const {
if (llI1 == NULL)
return llI1;
while (llI1->llli)
llI1 = llI1->llli;
return llI1;
}
ll1i liIi(ll1i llI1) const {
return liI1(ll1I);
}
ll1i liII(I1I value) const {
ll1i llI1 = ll1I;
if (llI1 == NULL)
return llI1;
ll1i lIll = NULL;
while (llI1) {
if (llI1->IiI < value)
llI1 = llI1->llli;
else if (llI1->IiI > value) {
if (lIll == NULL)
lIll = llI1;
else
if (llI1->IiI < lIll->IiI)
lIll = llI1;
llI1 = llI1->lll1;
}
else
break;
}
if (llI1)
if (llI1->llli) {
ll1i l1I1 = liiI(llI1->llli);
if (lIll == NULL)
lIll = l1I1;
else
if (l1I1->IiI < lIll->IiI)
lIll = l1I1;
}
return lIll;
}
ll1i lIl1(I1I value) const {
ll1i llI1 = ll1I;
if (llI1 == NULL)
return llI1;
ll1i lIli = NULL;
while (llI1) {
if (llI1->IiI < value) {
if (lIli == NULL)
lIli = llI1;
else
if (llI1->IiI > lIli->IiI)
lIli = llI1;
llI1 = llI1->llli;
}
else if (llI1->IiI > value)
llI1 = llI1->lll1;
else
break;
}
if (llI1)
if (llI1->lll1) {
ll1i l1I1 = liI1(llI1->lll1);
if (lIli == NULL)
lIli = l1I1;
else
if (l1I1->IiI > lIli->IiI)
lIli = l1I1;
}
return lIli;
}
int lIlI(I1I value) const {
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
int lI1l(I1I value) const {
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
int lI11(I1I value) const {
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
int lI1i(I1I value) const {
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
int lI1I(I1I value) const {
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
int l1ii() {
if (ll1I == NULL)
return 0;
ll1I->ll1l();
return ll1I->llll;
}
int lIil() {
if (ll1I == NULL)
return 0;
ll1I->ll1l();
return ll1I->III;
}
size_t size() {
return (size_t) (max(0, l1ii()));
}
int empty() {
return size() == 0;
}
ll1i begin() const {
ll1i llI1 = ll1I;
if (llI1 == NULL)
return NULL;
while (llI1->lll1) llI1 = llI1->lll1;
return llI1;
}
ll1i lIi1() const {
ll1i llI1 = ll1I;
if (llI1 == NULL)
return NULL;
while (llI1->llli) llI1 = llI1->llli;
return llI1;
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
Iil<pair<long long, long long> >::ll1i illI;
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
for (int llII=Ili; llII+1<il1l; llII++) lIII[llII] = lIII[llII+1];
il1l--;
lIII[il1l].lIIi = -1; lIII[il1l].lIIl = 0; lIII[il1l].lII1 = 0;
int il1i = Ili;
while (il1i < il1l && lIII[il1i].lIIl <= il11) il1i++;
if (il1i >= il1l) {
cout<<(Ill+1);
return 0;
}
for (int iiI=il1i; iiI<il1l; iiI++) illi.insert(make_pair(lIII[iiI].lII1-lIII[iiI].lIIl+1, lIII[iiI].lIIl));
while (il11 > 0 && !(illi.empty())) {
Ill = min(Ill, ((int) illi.size()));
illI = illi.begin();
if (il11 < illI->IiI.first) break;
il11 -= illI->IiI.first;
illi.erase(illI->IiI);
int il1I = il1i;
while (il1i >= 1 && lIII[il1i-1].lIIl > il11) il1i--;
for (int ilil=il1i; ilil<il1I; ilil++) illi.insert(make_pair(lIII[ilil].lII1-lIII[ilil].lIIl+1, lIII[ilil].lIIl));
}
Ill = min(Ill, ((int) illi.size()));
cout<<(Ill+1);
return 0;
}