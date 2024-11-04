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
unsigned int const i1l = 16369;
unsigned int const i11 = 3;
unsigned int const i1i = 3;
unsigned long long const i1I = 1000000000000000009ULL;
template <class iil>
class ii1 {
private:
struct iii {
iil value;
void * iiI;
unsigned long long iIl;
iii *iI1;
iii() {
value = iil();
iiI = NULL;
iIl = 0ULL;
iI1 = NULL;
}
~iii() {}
} **iIi;
unsigned int iII;
unsigned int Ill;
unsigned long long Il1(const iil & value) const {
return (i1I * (((unsigned long long) value.first) + 1ULL) + ((unsigned long long) value.second)) * i1I;
}
void resize() {
if (iIi == NULL)
return;
unsigned int Ili = iII * i1i;
iii **IlI = new iii* [Ili];
for (unsigned int I1l = 0UL; I1l < Ili; I1l++)
IlI[I1l] = NULL;
for (unsigned int I1l = 0UL; I1l < iII; I1l++)
if (iIi[I1l]) {
iii *I11 = iIi[I1l], *I1i;
while (I11) {
unsigned int I1I = I11->iIl % Ili;
I1i = I11->iI1;
I11->iI1 = IlI[I1I];
IlI[I1I] = I11;
I11 = I1i;
}
iIi[I1l] = NULL;
}
delete [] iIi;
iIi = IlI;
iII = Ili;
}
public:
ii1() {
iII = i1l;
Ill = 0UL;
iIi = new iii* [iII];
for (unsigned int I1l = 0UL; I1l < iII; I1l++)
iIi[I1l] = NULL;
}
void clear() {
if (iIi != NULL)
for (unsigned int I1l = 0UL; I1l < iII; I1l++)
if (iIi[I1l]) {
iii *I11 = iIi[I1l], *Iil;
while (I11) {
Iil = I11;
I11 = I11->iI1;
delete Iil;
}
iIi[I1l] = NULL;
}
Ill = 0UL;
}
~ii1() {
clear();
if (iIi != NULL)
delete [] iIi;
}
void insert(const iil & value, void * iiI) {
unsigned long long Ii1 = Il1(value);
unsigned int I1I = Ii1 % iII;
iii * I11 = new iii();
I11->value = value;
I11->iiI = iiI;
I11->iIl = Ii1;
I11->iI1 = iIi[I1I];
iIi[I1I] = I11;
Ill++;
if (i11 * iII < Ill)
resize();
}
void * find(const iil & value) const {
unsigned long long Ii1 = Il1(value);
unsigned int I1I = Ii1 % iII;
iii *I11 = iIi[I1I];
while (I11) {
if (I11->value == value)
return I11->iiI;
I11 = I11->iI1;
}
return NULL;
}
void erase(const iil & value) {
unsigned long long Ii1 = Il1(value);
unsigned int I1I = Ii1 % iII;
iii *I11 = iIi[I1I], *Iii = NULL;
while (I11) {
if (I11->value == value)
{
if (Iii == NULL)
iIi[I1I] = I11->iI1;
else
Iii->iI1 = I11->iI1;
delete I11;
return;
}
Iii = I11;
I11 = I11->iI1;
}
return;
}
};
}
namespace IiI {
template<typename IIl>
class II1 {
private:
IIl * IIi;
int III;
int * llll;
int lll1, llli;
public:
void clear() {
for (int I1l = 0; I1l < III; I1l++)
IIi[I1l].clear();
lll1 = 0;
llli = III;
llll[III] = -1;
for (int I1l = 0; I1l < III; I1l++)
llll[I1l] = I1l;
}
II1(int lllI, ...) {
if (lllI <= 0) {
IIi = NULL;
III = 0;
llll = NULL;
lll1 = llli = 0;
return;
}
III = lllI;
lll1 = 0;
llli = III;
llll = new int [III + 1];
llll[III] = -1;
for (int I1l = 0; I1l < III; I1l++)
llll[I1l] = I1l;
va_list ll1l;
va_start(ll1l, lllI);
IIi = (IIl *) operator new ( sizeof(IIl) * III );
for (int I1l = 0; I1l < III; I1l++) {
new(&IIi[I1l]) IIl(ll1l);
IIi[I1l].clear();
}
va_end(ll1l);
}
~II1() {
clear();
if (IIi != NULL) {
for (int I1l = 0; I1l < III; I1l++)
IIi[I1l].~IIl();
operator delete(IIi);
}
if (llll != NULL)
delete [] llll;
}
int ll11() const {
return llll[lll1] == -1;
}
IIl * ll1i() {
if (ll11())
return NULL;
IIl * ll1I = IIi + llll[lll1];
llll[lll1] = -1;
lll1++;
if (lll1 >= III+1)
lll1 -= III+1;
ll1I->clear();
return ll1I;
}
void llil(IIl * I11) {
if (I11 == NULL)
return;
I11->clear();
llll[llli] = I11 - IIi;
llli++;
if (llli >= III+1)
llli -= III+1;
}
};
}
namespace lli1 {
using namespace l;
using namespace ilI;
#define __STATIC_ALLOCATION__
#ifdef __KEY_INFO_LIST_SUPPORT__
struct llii {
public:
llii * iI1;
public:
void clear() {
iI1 = NULL;
}
llii(...) {
iI1 = NULL;
}
~llii() {
clear();
}
};
#endif
#ifdef __STATIC_ALLOCATION__
int const lliI = 300100;
using namespace IiI;
#endif
template<typename llIl>
class llI1 {
public:
template<typename llIi>
class llII {
public:
llIi l1ll;
#ifdef __KEY_INFO_LIST_SUPPORT__
llii * l1l1;
#endif
int l1li;
unsigned int l1lI;
int l11l;
int l111;
llII *l11i, *l11I;
#ifdef __STATIC_ALLOCATION__
#ifdef __KEY_INFO_LIST_SUPPORT__
II1<llii> * l1il;
#endif
#endif
public:
void l1i1() {
l11l = 1;
l111 = l1li;
if (l11i) {
l11l += l11i->l11l;
l111 += l11i->l111;
}
if (l11I) {
l11l += l11I->l11l;
l111 += l11I->l111;
}
}
void clear() {
l1ll = llIi();
#ifdef __KEY_INFO_LIST_SUPPORT__
while (l1l1) {
llii * Iii = l1l1;
l1l1 = l1l1->iI1;
#ifdef __STATIC_ALLOCATION__
l1il->llil(Iii);
#else
delete Iii;
#endif
}
#endif
l1li = 0;
l1lI = 0UL;
l11l = 0;
l111 = 0;
l11i = l11I = NULL;
}
#ifdef __STATIC_ALLOCATION__
llII(va_list ll1l) {
#ifdef __KEY_INFO_LIST_SUPPORT__
l1l1 = NULL;
l1il = va_arg(ll1l, II1<llii> *);
#endif
clear();
}
#else
llII() {
#ifdef __KEY_INFO_LIST_SUPPORT__
l1l1 = NULL;
#endif
clear();
}
#endif
~llII() {
clear();
}
};
typedef llII<llIl> * l1ii;
private:
l1ii l1iI;
#ifdef __STATIC_ALLOCATION__
#ifdef __KEY_INFO_LIST_SUPPORT__
II1<llii> * l1Il;
#endif
II1<llII<llIl> > * l1I1;
#endif
lli l1Ii;
ii1<llIl> * iIi;
private:
unsigned int l1II() {
return l1Ii.ill();
}
void lill(l1ii lil1, llIl l1ll) {
if (lil1 == NULL)
return;
if (lil1->l1ll < l1ll)
lill(lil1->l11I, l1ll);
else if (lil1->l1ll > l1ll)
lill(lil1->l11i, l1ll);
if (lil1)
lil1->l1i1();
}
void lili(l1ii lil1, llIl l1ll, l1ii & lilI, l1ii & li1l) {
if (lil1 == NULL) {
lilI = li1l = NULL;
return;
}
if (l1ll <= lil1->l1ll) {
lili(lil1->l11i, l1ll, lilI, lil1->l11i);
li1l = lil1;
if (li1l)
li1l->l1i1();
}
else {
lili(lil1->l11I, l1ll, lil1->l11I, li1l);
lilI = lil1;
if (lilI)
lilI->l1i1();
}
}
void li11(l1ii & lil1, l1ii lilI, l1ii li1l) {
if (lilI == NULL) {
lil1 = li1l;
if (lil1)
lil1->l1i1();
return;
}
if (li1l == NULL) {
lil1 = lilI;
if (lil1)
lil1->l1i1();
return;
}
if (lilI->l1lI > li1l->l1lI) {
li11(lilI->l11I, lilI->l11I, li1l);
lil1 = lilI;
}
else {
li11(li1l->l11i, lilI, li1l->l11i);
lil1 = li1l;
}
if (lil1)
lil1->l1i1();
}
#ifndef __STATIC_ALLOCATION__
void li1i(l1ii lil1) {
if (lil1 == NULL) return;
li1i(lil1->l11i);
li1i(lil1->l11I);
if (iIi)
iIi->erase(lil1->l1ll);
delete lil1;
}
#endif
void insert(l1ii & lil1, l1ii & li1I) {
if (lil1 == NULL) {
lil1 = li1I;
if (lil1)
lil1->l1i1();
return;
}
if (lil1->l1ll == li1I->l1ll) {
lil1->l1li += li1I->l1li;
#ifdef __KEY_INFO_LIST_SUPPORT__
llii * liil = li1I->l1l1;
while (liil) {
llii * I1i = liil->iI1;
liil->iI1 = lil1->l1l1;
lil1->l1l1 = liil;
liil = I1i;
}
#endif
#ifdef __SET__ONLY__
#ifdef __KEY_INFO_LIST_SUPPORT__
int lii1 = lil1->l1li;
lii1 -= 1;
while (lil1->l1l1 != NULL && lii1 > 0) {
llii * Iii = lil1->l1l1;
lil1->l1l1 = lil1->l1l1->iI1;
#ifdef __STATIC_ALLOCATION__
l1Il->llil(Iii);
#else
delete Iii;
#endif
lii1--;
}
#endif
lil1->l1li = min(lil1->l1li, 1);
#endif
#ifdef __KEY_INFO_LIST_SUPPORT__
li1I->l1l1 = NULL;
#endif
#ifdef __STATIC_ALLOCATION__
l1I1->llil(li1I);
#else
delete li1I;
#endif
if (lil1)
lil1->l1i1();
li1I = lil1;
return;
}
if (li1I->l1lI > lil1->l1lI) {
lili(lil1, li1I->l1ll, li1I->l11i, li1I->l11I);
lil1 = li1I;
if (lil1)
lil1->l1i1();
return;
}
if (lil1->l1ll < li1I->l1ll)
insert(lil1->l11I, li1I);
else
insert(lil1->l11i, li1I);
if (lil1)
lil1->l1i1();
}
public:
void clear() {
#ifndef __STATIC_ALLOCATION__
li1i(l1iI);
#else
int liii = 0;
if (l1iI != NULL) {
long long liiI = liIl();
long long liI1 = 1LL, liIi = 1LL;
while (liIi < liiI) {
liIi *= 2LL;
liI1++;
}
if (liiI * liI1 * 3LL < (long long) lliI)
liii = 1;
}
else
liii = 1;
if (liii) {
while (l1iI)
erase(l1iI->l1ll);
}
else
l1I1->clear();
#endif
l1iI = NULL;
if (iIi)
iIi->clear();
}
llI1() {
l1iI = NULL;
iIi = new ii1<llIl>;
#ifdef __STATIC_ALLOCATION__
#ifdef __KEY_INFO_LIST_SUPPORT__
l1Il = new II1<llii> (lliI);
l1I1 = new II1<llII<llIl> > (lliI, l1Il);
#else
l1I1 = new II1<llII<llIl> > (lliI);
#endif
#endif
}
~llI1() {
clear();
if (iIi)
delete iIi;
#ifdef __STATIC_ALLOCATION__
if (l1I1 != NULL)
delete l1I1;
#ifdef __KEY_INFO_LIST_SUPPORT__
if (l1Il != NULL)
delete l1Il;
#endif
#endif
}
l1ii insert(l1ii & lil1, llIl l1ll, unsigned int l1lI  ) {
l1ii I11 = find(l1ll);
if (I11 != NULL) {
I11->l1li++;
I11->l1i1();
lill(l1iI, l1ll);
return I11;
}
#ifdef __STATIC_ALLOCATION__
if (l1I1->ll11())
return NULL;
l1ii li1I = l1I1->ll1i();
if (li1I == NULL)
return NULL;
li1I->l1ll = l1ll;
li1I->l1lI = l1lI;
li1I->l11i = li1I->l11I = NULL;
#ifdef __KEY_INFO_LIST_SUPPORT__
li1I->l1l1 = l1Il->ll1i();
#endif
#else
l1ii li1I = new (std::nothrow) llII<llIl>;
if (li1I == NULL)
return NULL;
li1I->l1ll = l1ll;
li1I->l1lI = l1lI;
li1I->l11i = li1I->l11I = NULL;
#ifdef __KEY_INFO_LIST_SUPPORT__
li1I->l1l1 = new (std::nothrow) llii;
#endif
#endif
#ifdef __KEY_INFO_LIST_SUPPORT__
if (li1I->l1l1 == NULL) {
#ifndef __STATIC_ALLOCATION__
li1I->clear();
delete li1I;
#else
l1I1->llil(li1I);
#endif
return NULL;
}
li1I->l1l1->iI1 = NULL;
#endif
li1I->l1li = li1I->l11l = li1I->l111 = 1;
li1I->l1i1();
if (iIi)
iIi->insert(li1I->l1ll, (void *) li1I);
insert(lil1, li1I);
return li1I;
}
l1ii insert(l1ii & lil1 , llIl l1ll  ) {
return insert(lil1, l1ll, l1II()  );
}
l1ii insert(llIl l1ll, unsigned int l1lI  ) {
return insert(l1iI, l1ll, l1lI  );
}
l1ii insert(llIl l1ll  ) {
return insert(l1iI, l1ll, l1II()  );
}
l1ii find(l1ii lil1, llIl l1ll) const {
if (lil1 == NULL)
return NULL;
if (lil1->l1ll < l1ll)
return find(lil1->l11I, l1ll);
else if (lil1->l1ll > l1ll)
return find(lil1->l11i, l1ll);
else
return lil1;
}
l1ii find(llIl l1ll) const {
l1ii liII = NULL;
if (iIi)
liII = (l1ii) iIi->find(l1ll);
if (liII)
return liII;
return find(l1iI, l1ll);
}
l1ii lIll(l1ii lil1, int lIl1) const {
if (lil1 == NULL)
return NULL;
int lIli = 0;
if (lil1->l11i)
lIli = lil1->l11i->l111;
if (lIl1 <= lIli)
return lIll(lil1->l11i, lIl1);
if (lIl1 <= lIli + lil1->l1li)
return lil1;
return lIll(lil1->l11I, lIl1 - lIli - lil1->l1li);
}
l1ii lIlI(int lIl1) const {
return lIll(l1iI, lIl1);
}
l1ii lI1l(l1ii lil1, int lIl1) const {
if (lil1 == NULL)
return NULL;
int lIli = 0;
if (lil1->l11i)
lIli = lil1->l11i->l11l;
if (lIl1 <= lIli)
return lI1l(lil1->l11i, lIl1);
if (lIl1 == lIli + 1)
return lil1;
return lI1l(lil1->l11I, lIl1 - lIli - 1);
}
l1ii lI11(int lIl1) const {
return lI1l(l1iI, lIl1);
}
l1ii lI1i(l1ii lil1, int lI1I) const {
if (lil1 == NULL)
return NULL;
int lIil = 0;
if (lil1->l11I)
lIil = lil1->l11I->l111;
if (lI1I <= lIil)
return lI1i(lil1->l11I, lI1I);
if (lI1I <= lIil + lil1->l1li)
return lil1;
return lI1i(lil1->l11i, lI1I - lIil - lil1->l1li);
}
l1ii lIi1(int lI1I) const {
return lI1i(l1iI, lI1I);
}
l1ii lIii(l1ii lil1, int lI1I) const {
if (lil1 == NULL)
return NULL;
int lIil = 0;
if (lil1->l11I)
lIil = lil1->l11I->l11l;
if (lI1I <= lIil)
return lIii(lil1->l11I, lI1I);
if (lI1I == lIil + 1)
return lil1;
return lIii(lil1->l11i, lI1I - lIil - 1);
}
l1ii lIiI(int lI1I) const {
return lIii(l1iI, lI1I);
}
void erase(l1ii & lil1, llIl l1ll) {
if (lil1 == NULL)
return;
if (lil1->l1ll == l1ll) {
#ifndef __SET__ONLY__
lil1->l1li--;
#ifdef __KEY_INFO_LIST_SUPPORT__
if (lil1->l1l1) {
llii * liil = lil1->l1l1;
lil1->l1l1 = lil1->l1l1->iI1;
#ifdef __STATIC_ALLOCATION__
l1Il->llil(liil);
#else
delete liil;
#endif
}
#endif
if (lil1->l1li <= 0) {
l1ii lIIl = lil1;
li11(lil1, lil1->l11i, lil1->l11I);
if (iIi)
iIi->erase(lIIl->l1ll);
#ifndef __STATIC_ALLOCATION__
delete lIIl;
#else
l1I1->llil(lIIl);
#endif
}
#else
l1ii lIIl = lil1;
li11(lil1, lil1->l11i, lil1->l11I);
if (iIi)
iIi->erase(lIIl->l1ll);
#ifndef __STATIC_ALLOCATION__
delete lIIl;
#else
l1I1->llil(lIIl);
#endif
#endif
if (lil1)
lil1->l1i1();
return;
}
if (lil1->l1ll < l1ll)
erase(lil1->l11I, l1ll);
else
erase(lil1->l11i, l1ll);
if (lil1)
lil1->l1i1();
}
void erase(llIl l1ll) {
erase(l1iI, l1ll);
}
l1ii lII1(l1ii lil1) const {
if (lil1 == NULL)
return lil1;
while (lil1->l11i)
lil1 = lil1->l11i;
return lil1;
}
l1ii lIIi() const {
return lII1(l1iI);
}
l1ii lIII(l1ii lil1) const {
if (lil1 == NULL)
return lil1;
while (lil1->l11I)
lil1 = lil1->l11I;
return lil1;
}
l1ii illl(l1ii lil1) const {
return lIII(l1iI);
}
l1ii ill1(llIl value) const {
l1ii lil1 = l1iI;
if (lil1 == NULL)
return lil1;
l1ii illi = NULL;
while (lil1) {
if (lil1->l1ll < value)
lil1 = lil1->l11I;
else if (lil1->l1ll > value) {
if (illi == NULL)
illi = lil1;
else
if (lil1->l1ll < illi->l1ll)
illi = lil1;
lil1 = lil1->l11i;
}
else
break;
}
if (lil1)
if (lil1->l11I) {
l1ii liII = lII1(lil1->l11I);
if (illi == NULL)
illi = liII;
else
if (liII->l1ll < illi->l1ll)
illi = liII;
}
return illi;
}
l1ii illI(llIl value) const {
l1ii lil1 = l1iI;
if (lil1 == NULL)
return lil1;
l1ii il1l = NULL;
while (lil1) {
if (lil1->l1ll < value) {
if (il1l == NULL)
il1l = lil1;
else
if (lil1->l1ll > il1l->l1ll)
il1l = lil1;
lil1 = lil1->l11I;
}
else if (lil1->l1ll > value)
lil1 = lil1->l11i;
else
break;
}
if (lil1)
if (lil1->l11i) {
l1ii liII = lIII(lil1->l11i);
if (il1l == NULL)
il1l = liII;
else
if (liII->l1ll > il1l->l1ll)
il1l = liII;
}
return il1l;
}
int il11(llIl value) const {
l1ii liII = NULL;
if (iIi)
liII = (l1ii) iIi->find(value);
if (liII)
return liII->l1li;
if (iIi)
return 0;
l1ii lil1 = l1iI;
if (lil1 == NULL)
return 0;
while (lil1)
if (lil1->l1ll < value)
lil1 = lil1->l11I;
else if (lil1->l1ll > value)
lil1 = lil1->l11i;
else
break;
if (lil1 == NULL)
return 0;
return lil1->l1li;
}
int il1i(llIl value) const {
l1ii lil1 = l1iI;
if (lil1 == NULL)
return 0;
int ll1I = 0;
while (lil1)
if (lil1->l1ll < value) {
ll1I += lil1->l1li;
if (lil1->l11i)
ll1I += lil1->l11i->l111;
lil1 = lil1->l11I;
}
else if (lil1->l1ll > value)
lil1 = lil1->l11i;
else
break;
if (lil1)
if (lil1->l11i)
ll1I += lil1->l11i->l111;
return ll1I;
}
int il1I(llIl value) const {
l1ii lil1 = l1iI;
if (lil1 == NULL)
return 0;
int ll1I = 0;
while (lil1)
if (lil1->l1ll < value) {
ll1I++;
if (lil1->l11i)
ll1I += lil1->l11i->l11l;
lil1 = lil1->l11I;
}
else if (lil1->l1ll > value)
lil1 = lil1->l11i;
else
break;
if (lil1)
if (lil1->l11i)
ll1I += lil1->l11i->l11l;
return ll1I;
}
int ilil(llIl value) const {
l1ii lil1 = l1iI;
if (lil1 == NULL)
return 0;
int ll1I = 0;
while (lil1)
if (lil1->l1ll < value)
lil1 = lil1->l11I;
else if (lil1->l1ll > value) {
ll1I += lil1->l1li;
if (lil1->l11I)
ll1I += lil1->l11I->l111;
lil1 = lil1->l11i;
}
else
break;
if (lil1)
if (lil1->l11I)
ll1I += lil1->l11I->l111;
return ll1I;
}
int ili1(llIl value) const {
l1ii lil1 = l1iI;
if (lil1 == NULL)
return 0;
int ll1I = 0;
while (lil1)
if (lil1->l1ll < value)
lil1 = lil1->l11I;
else if (lil1->l1ll > value) {
ll1I++;
if (lil1->l11I)
ll1I += lil1->l11I->l11l;
lil1 = lil1->l11i;
}
else
break;
if (lil1)
if (lil1->l11I)
ll1I += lil1->l11I->l11l;
return ll1I;
}
int liIl() {
if (l1iI == NULL)
return 0;
l1iI->l1i1();
return l1iI->l111;
}
int ilii() {
if (l1iI == NULL)
return 0;
l1iI->l1i1();
return l1iI->l11l;
}
size_t size() {
return (size_t) (max(0, liIl()));
}
int empty() {
return size() == 0;
}
l1ii begin() const {
return lIlI(1);
}
l1ii iliI() const {
return lIi1(1);
}
};
}
using namespace lli1;
int const ilIl = 300100;
struct ilI1 {long long ilIi,ilII; int i1ll;} i1l1[ilIl];
bool operator < (const ilI1 &i1li, const ilI1 &i1lI) {
return i1li.ilIi < i1lI.ilIi || (i1li.ilIi == i1lI.ilIi && i1li.ilII-i1li.ilIi < i1lI.ilII-i1lI.ilIi);
}
llI1<pair<long long,long long> > i11l;
llI1<pair<long long,long long> >::l1ii i111;
int main() {
int i11i;
scanf("%d",&i11i);
for (int I1l=0; I1l<i11i; I1l++) {
i1l1[I1l].i1ll = I1l;
scanf("%I64d%I64d",&i1l1[I1l].ilIi,&i1l1[I1l].ilII);
}
sort(i1l1,i1l1+i11i);
int I11 = -1;
for (int I1l=0; I1l<i11i; I1l++)
if (i1l1[I1l].i1ll==0) I11 = I1l;
long long i11I = i1l1[I11].ilIi;
int ll1I = 0;
for (int I1l=0; I1l<i11i; I1l++)
if (i1l1[I1l].ilIi > i11I) ll1I++;
long long ilII = i1l1[I11].ilII;
for (int li1l=I11; li1l+1<i11i; li1l++) i1l1[li1l] = i1l1[li1l+1];
i11i--;
i1l1[i11i].i1ll = -1; i1l1[i11i].ilIi = 0; i1l1[i11i].ilII = 0;
int i1il = I11;
while (i1il < i11i && i1l1[i1il].ilIi <= i11I) i1il++;
if (i1il >= i11i) {
cout<<(ll1I+1);
return 0;
}
for (int I1l=i1il; I1l<i11i; I1l++) i11l.insert(make_pair(i1l1[I1l].ilII-i1l1[I1l].ilIi+1, i1l1[I1l].ilIi));
while (i11I > 0 && !(i11l.empty())) {
ll1I = min(ll1I, ((int) i11l.size()));
i111 = i11l.begin();
if (i11I < i111->l1ll.first) break;
i11I -= i111->l1ll.first;
i11l.erase(i111->l1ll);
int i1i1 = i1il;
while (i1il >= 1 && i1l1[i1il-1].ilIi > i11I) i1il--;
for (int i1ii=i1il; i1ii<i1i1; i1ii++) i11l.insert(make_pair(i1l1[i1ii].ilII-i1l1[i1ii].ilIi+1, i1l1[i1ii].ilIi));
}
ll1I = min(ll1I, ((int) i11l.size()));
cout<<(ll1I+1);
return 0;
}