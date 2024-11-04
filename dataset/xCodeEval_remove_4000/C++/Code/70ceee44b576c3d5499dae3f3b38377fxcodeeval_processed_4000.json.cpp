











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
unsigned int * id4;
unsigned int l11, id8;
unsigned int id11;
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
id4 = new unsigned int [llI];
l11 = 0;
id8 = 0;
id4[0] = lIl;
for (unsigned int id0 = 1;
id0 < Ii;
id0++) {
id8++;
id4[id8] = lll * id4[id8-1] + ll1;
}
for (unsigned int lIi = Ii;
lIi < I;
lIi++) {
id8++;
id4[id8] = id4[id8 - Ii] -
id4[id8 - II];
}
lil = (unsigned int) (
( ((unsigned long long) 1) << ((unsigned long long) li) ) - 1
);
id11 = (unsigned int) (
( ((unsigned long long) 1) << ((unsigned long long) l1) ) - 1 -
lil
);
}
~lli() {
delete [] id4;
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
unsigned int il1 = (id4[li1(0)] & id11) |
(id4[li1(1)] & lil);
unsigned int ili = id4[li1(ll)] ^ (il1>>1);
if (il1 & 1)
ili ^= lI;
ili = ili ^ (ili >> il);
ili = ili ^ ((ili << i1) & Il);
ili = ili ^ ((ili << ii) & I1);
ili = ili ^ (ili >> iI);
id8++;
if (id8 >= llI)
id8 -= llI;
id4[id8] = ili;
l11++;
if (l11 >= llI)
l11 -= llI;
return ili;
}
};
}
namespace ilI {
template<typename id17>
class i11 {
private:
id17 * id9;
int id20;
int * iil;
int ii1, iii;
public:
void clear() {
for (int iiI = 0; iiI < id20; iiI++)
id9[iiI].clear();
ii1 = 0;
iii = id20;
iil[id20] = -1;
for (int iiI = 0; iiI < id20; iiI++)
iil[iiI] = iiI;
}
i11(int iIl, ...) {
if (iIl <= 0) {
id9 = NULL;
id20 = 0;
iil = NULL;
ii1 = iii = 0;
return;
}
id20 = iIl;
ii1 = 0;
iii = id20;
iil = new int [id20 + 1];
iil[id20] = -1;
for (int iiI = 0; iiI < id20; iiI++)
iil[iiI] = iiI;
va_list id3;
va_start(id3, iIl);
id9 = (id17 *) operator new ( sizeof(id17) * id20 );
for (int iiI = 0; iiI < id20; iiI++) {
new(&id9[iiI]) id17(id3);
id9[iiI].clear();
}
va_end(id3);
}
~i11() {
if (id9 != NULL) {
for (int iiI = 0; iiI < id20; iiI++)
id9[iiI].~id17();
operator delete(id9);
}
if (iil != NULL)
delete [] iil;
}
int iIi() const {
return iil[ii1] == -1;
}
id17 * iII() {
if (iIi())
return NULL;
id17 * Ill = id9 + iil[ii1];
iil[ii1] = -1;
ii1++;
if (ii1 >= id20+1)
ii1 -= id20+1;
Ill->clear();
return Ill;
}
void Il1(id17 * Ili) {
if (Ili == NULL)
return;
Ili->clear();
iil[iii] = Ili - id9;
iii++;
if (iii >= id20+1)
iii -= id20+1;
}
};
}
namespace IlI {
using namespace l;


struct id1 {
public:
id1 * I11;
public:
void clear() {
I11 = NULL;
}
id1(...) {
I11 = NULL;
}
~id1() {
}
};


int const id15 = 300100;
using namespace ilI;

template<typename I1I>
class Iil {
public:
template<typename Ii1>
class Iii {
public:
Ii1 IiI;

id1 * IIl;

int II1;
unsigned int IIi;
int III;
int llll;
Iii *lll1, *llli;


i11<id1> * lllI;


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

while (IIl) {
id1 * ll11 = IIl;
IIl = IIl->I11;

lllI->Il1(ll11);

delete ll11;

}

II1 = 0;
IIi = 0UL;
III = 0;
llll = 0;
lll1 = llli = NULL;
}

Iii(va_list id3) {

IIl = NULL;
lllI = va_arg(id3, i11<id1> *);

clear();
}

Iii() {

IIl = NULL;

clear();
}

~Iii() {
clear();
}
};
typedef Iii<I1I> * ll1i;
private:
ll1i id19;


i11<id1> * llil;

i11<Iii<I1I> > * lli1;

lli llii;
private:
unsigned int lliI() {
return llii.ill();
}
void llIl(ll1i id16, I1I IiI, ll1i & llIi, ll1i & llII) {
if (id16 == NULL) {
llIi = llII = NULL;
return;
}
if (IiI <= id16->IiI) {
llIl(id16->lll1, IiI, llIi, id16->lll1);
llII = id16;
if (llII)
llII->ll1l();
}
else {
llIl(id16->llli, IiI, id16->llli, llII);
llIi = id16;
if (llIi)
llIi->ll1l();
}
}
void l1ll(ll1i & id16, ll1i llIi, ll1i llII) {
if (llIi == NULL) {
id16 = llII;
if (id16)
id16->ll1l();
return;
}
if (llII == NULL) {
id16 = llIi;
if (id16)
id16->ll1l();
return;
}
if (llIi->IIi > llII->IIi) {
l1ll(llIi->llli, llIi->llli, llII);
id16 = llIi;
}
else {
l1ll(llII->lll1, llIi, llII->lll1);
id16 = llII;
}
if (id16)
id16->ll1l();
}

void l1l1(ll1i id16) {
if (id16 == NULL) return;
l1l1(id16->lll1);
l1l1(id16->llli);
delete id16;
}

ll1i l1li(I1I IiI, unsigned int IIi  ) {

if (lli1->iIi())
return NULL;
ll1i id18 = lli1->iII();
if (id18 == NULL)
return NULL;
id18->IiI = IiI;
id18->IIi = IIi;
id18->lll1 = id18->llli = NULL;

id18->IIl = llil->iII();


ll1i id18 = new (std::nothrow) Iii<I1I>;
if (id18 == NULL)
return NULL;
id18->IiI = IiI;
id18->IIi = IIi;
id18->lll1 = id18->llli = NULL;

id18->IIl = new (std::nothrow) id1;



if (id18->IIl == NULL) {

id18->clear();
delete id18;

lli1->Il1(id18);

return NULL;
}
id18->IIl->I11 = NULL;

id18->II1 = id18->III = id18->llll = 1;
id18->ll1l();
return id18;
}
void l11l(ll1i & id16, I1I IiI  ) {
id16->II1 += 1;


id1 * l111 = llil->iII();

id1 * l111 = new (std::nothrow) id1;

if (l111 == NULL)
return;
l111->I11 = id16->IIl;
id16->IIl = l111;



int id6 = id16->II1;
id6--;
while (id16->IIl != NULL && id6 > 0) {
id1 * ll11 = id16->IIl;
id16->IIl = id16->IIl->I11;

llil->Il1(ll11);

delete ll11;

id6--;
}

id16->II1 = min(id16->II1, 1);

}
ll1i l11I(ll1i & id16, I1I IiI  ) {
if (id16 == NULL)
return NULL;
if (id16->IiI == IiI) {
l11l(id16, IiI  );
if (id16)
id16->ll1l();
return id16;
}
ll1i Ill = NULL;
if (id16->IiI < IiI)
Ill = l11I(id16->llli, IiI  );
else
Ill = l11I(id16->lll1, IiI  );
if (id16)
id16->ll1l();
return Ill;
}
public:
void clear() {

l1l1(id19);

int id21 = 0;
if (id19 != NULL) {
long long id13 = l1ii();
long long id25 = 1LL, id14 = 1LL;
while (id14 < id13) {
id14 *= 2LL;
id25++;
}
if (id13 * id25 * 3LL < (long long) id15)
id21 = 1;
}
else
id21 = 1;
if (id21) {
while (id19)
erase(id19->IiI);
}
else
lli1->clear();

id19 = NULL;
}
Iil() {
id19 = NULL;


llil = new i11<id1> (id15);
lli1 = new i11<Iii<I1I> > (id15, llil);

lli1 = new i11<Iii<I1I> > (id15);


}
~Iil() {

if (lli1 != NULL)
delete lli1;

if (llil != NULL)
delete llil;


l1l1(id19);

}
ll1i insert(ll1i & id16, I1I IiI, unsigned int IIi  ) {
if (id16 == NULL) {
ll1i id18 = l1li(IiI, IIi  );
if (id18 == NULL)
return NULL;
id16 = id18;
if (id16)
id16->ll1l();
return id16;
}
if (id16->IiI == IiI) {
l11l(id16, IiI  );
if (id16)
id16->ll1l();
return id16;
}
if (IIi > id16->IIi) {
ll1i id23 = l11I(id16, IiI  );
if (id23 != NULL) {
if (id16)
id16->ll1l();
return id23;
}
ll1i id18 = l1li(IiI, IIi  );
if (id18 == NULL)
return NULL;
llIl(id16, id18->IiI, id18->lll1, id18->llli);
id16 = id18;
if (id16)
id16->ll1l();
return id16;
}
ll1i Ill = NULL;
if (id16->IiI < IiI)
Ill = insert(id16->llli, IiI, IIi  );
else
Ill = insert(id16->lll1, IiI, IIi  );
if (id16)
id16->ll1l();
return Ill;
}
ll1i insert(ll1i & id16 , I1I IiI  ) {
return insert(id16, IiI, lliI()  );
}
ll1i insert(I1I IiI, unsigned int IIi  ) {
return insert(id19, IiI, IIi  );
}
ll1i insert(I1I IiI  ) {
return insert(id19, IiI, lliI()  );
}
ll1i find(ll1i id16, I1I IiI) const {
if (id16 == NULL)
return NULL;
if (id16->IiI < IiI)
return find(id16->llli, IiI);
else if (id16->IiI > IiI)
return find(id16->lll1, IiI);
else
return id16;
}
ll1i find(I1I IiI) const {
return find(id19, IiI);
}
ll1i l1Ii(ll1i id16, int id5) const {
if (id16 == NULL)
return NULL;
int lill = 0;
if (id16->lll1)
lill = id16->lll1->llll;
if (id5 <= lill)
return l1Ii(id16->lll1, id5);
if (id5 <= lill + id16->II1)
return id16;
return l1Ii(id16->llli, id5 - lill - id16->II1);
}
ll1i lil1(int id5) const {
return l1Ii(id19, id5);
}
ll1i lili(ll1i id16, int id5) const {
if (id16 == NULL)
return NULL;
int lill = 0;
if (id16->lll1)
lill = id16->lll1->III;
if (id5 <= lill)
return lili(id16->lll1, id5);
if (id5 == lill + 1)
return id16;
return lili(id16->llli, id5 - lill - 1);
}
ll1i lilI(int id5) const {
return lili(id19, id5);
}
ll1i li1l(ll1i id16, int li11) const {
if (id16 == NULL)
return NULL;
int id24 = 0;
if (id16->llli)
id24 = id16->llli->llll;
if (li11 <= id24)
return li1l(id16->llli, li11);
if (li11 <= id24 + id16->II1)
return id16;
return li1l(id16->lll1, li11 - id24 - id16->II1);
}
ll1i li1I(int li11) const {
return li1l(id19, li11);
}
ll1i liil(ll1i id16, int li11) const {
if (id16 == NULL)
return NULL;
int id24 = 0;
if (id16->llli)
id24 = id16->llli->III;
if (li11 <= id24)
return liil(id16->llli, li11);
if (li11 == id24 + 1)
return id16;
return liil(id16->lll1, li11 - id24 - 1);
}
ll1i lii1(int li11) const {
return liil(id19, li11);
}
void erase(ll1i & id16, I1I IiI) {
if (id16 == NULL)
return;
if (id16->IiI == IiI) {

id16->II1--;

if (id16->IIl) {
id1 * l111 = id16->IIl;
id16->IIl = id16->IIl->I11;

llil->Il1(l111);

delete l111;

}

if (id16->II1 <= 0) {
ll1i liii = id16;
l1ll(id16, id16->lll1, id16->llli);

delete liii;

lli1->Il1(liii);

}

ll1i liii = id16;
l1ll(id16, id16->lll1, id16->llli);

delete liii;

lli1->Il1(liii);


if (id16)
id16->ll1l();
return;
}
if (id16->IiI < IiI)
erase(id16->llli, IiI);
else
erase(id16->lll1, IiI);
if (id16)
id16->ll1l();
}
void erase(I1I IiI) {
erase(id19, IiI);
}
ll1i liiI(ll1i id16) const {
if (id16 == NULL)
return id16;
while (id16->lll1)
id16 = id16->lll1;
return id16;
}
ll1i liIl(ll1i id16) const {
if (id16 == NULL)
return id16;
while (id16->llli)
id16 = id16->llli;
return id16;
}
ll1i liI1(I1I value) const {
ll1i id16 = id19;
if (id16 == NULL)
return id16;
ll1i liIi = NULL;
while (id16) {
if (id16->IiI < value)
id16 = id16->llli;
else if (id16->IiI > value) {
if (liIi == NULL)
liIi = id16;
else
if (id16->IiI < liIi->IiI)
liIi = id16;
id16 = id16->lll1;
}
else
break;
}
if (id16)
if (id16->llli) {
ll1i id23 = liiI(id16->llli);
if (liIi == NULL)
liIi = id23;
else
if (id23->IiI < liIi->IiI)
liIi = id23;
}
return liIi;
}
ll1i liII(I1I value) const {
ll1i id16 = id19;
if (id16 == NULL)
return id16;
ll1i lIll = NULL;
while (id16) {
if (id16->IiI < value) {
if (lIll == NULL)
lIll = id16;
else
if (id16->IiI > lIll->IiI)
lIll = id16;
id16 = id16->llli;
}
else if (id16->IiI > value)
id16 = id16->lll1;
else
break;
}
if (id16)
if (id16->lll1) {
ll1i id23 = liIl(id16->lll1);
if (lIll == NULL)
lIll = id23;
else
if (id23->IiI > lIll->IiI)
lIll = id23;
}
return lIll;
}
int lIl1(I1I value) const {
ll1i id16 = id19;
if (id16 == NULL)
return 0;
while (id16)
if (id16->IiI < value)
id16 = id16->llli;
else if (id16->IiI > value)
id16 = id16->lll1;
else
break;
if (id16 == NULL)
return 0;
return id16->II1;
}
int lIli(I1I value) const {
ll1i id16 = id19;
if (id16 == NULL)
return 0;
int Ill = 0;
while (id16)
if (id16->IiI < value) {
Ill += id16->II1;
if (id16->lll1)
Ill += id16->lll1->llll;
id16 = id16->llli;
}
else if (id16->IiI > value)
id16 = id16->lll1;
else
break;
if (id16)
if (id16->lll1)
Ill += id16->lll1->llll;
return Ill;
}
int lIlI(I1I value) const {
ll1i id16 = id19;
if (id16 == NULL)
return 0;
int Ill = 0;
while (id16)
if (id16->IiI < value) {
Ill++;
if (id16->lll1)
Ill += id16->lll1->III;
id16 = id16->llli;
}
else if (id16->IiI > value)
id16 = id16->lll1;
else
break;
if (id16)
if (id16->lll1)
Ill += id16->lll1->III;
return Ill;
}
int lI1l(I1I value) const {
ll1i id16 = id19;
if (id16 == NULL)
return 0;
int Ill = 0;
while (id16)
if (id16->IiI < value)
id16 = id16->llli;
else if (id16->IiI > value) {
Ill += id16->II1;
if (id16->llli)
Ill += id16->llli->llll;
id16 = id16->lll1;
}
else
break;
if (id16)
if (id16->llli)
Ill += id16->llli->llll;
return Ill;
}
int lI11(I1I value) const {
ll1i id16 = id19;
if (id16 == NULL)
return 0;
int Ill = 0;
while (id16)
if (id16->IiI < value)
id16 = id16->llli;
else if (id16->IiI > value) {
Ill++;
if (id16->llli)
Ill += id16->llli->III;
id16 = id16->lll1;
}
else
break;
if (id16)
if (id16->llli)
Ill += id16->llli->III;
return Ill;
}
int l1ii() {
if (id19 == NULL)
return 0;
id19->ll1l();
return id19->llll;
}
int lI1i() {
if (id19 == NULL)
return 0;
id19->ll1l();
return id19->III;
}
size_t size() {
return (size_t) (max(0, l1ii()));
}
int empty() {
return size() == 0;
}
ll1i begin() const {
return liiI(id19);
}
ll1i lI1I() const {
return liIl(id19);
}
};
}
using namespace IlI;
int const id2 = 300100;
struct lIi1 {long long lIii,id22; int lIIl;} lII1[id2];
bool operator < (const lIi1 &id12, const lIi1 &lIII) {
return id12.lIii < lIII.lIii || (id12.lIii == lIII.lIii && id12.id22-id12.lIii < lIII.id22-lIII.lIii);
}
Iil<pair<long long, long long> > illl;
Iil<pair<long long, long long> >::ll1i ill1;
int main() {
int illi;
scanf("%d",&illi);
for (int iiI=0; iiI<illi; iiI++) {
lII1[iiI].lIIl = iiI;
scanf("%I64d%I64d",&lII1[iiI].lIii,&lII1[iiI].id22);
}
sort(lII1,lII1+illi);
int Ili = -1;
for (int iiI=0; iiI<illi; iiI++)
if (lII1[iiI].lIIl==0) Ili = iiI;
long long illI = lII1[Ili].lIii;
int Ill = 0;
for (int iiI=0; iiI<illi; iiI++)
if (lII1[iiI].lIii > illI) Ill++;
long long id22 = lII1[Ili].id22;
for (int llII=Ili; llII+1<illi; llII++) lII1[llII] = lII1[llII+1];
illi--;
lII1[illi].lIIl = -1; lII1[illi].lIii = 0; lII1[illi].id22 = 0;
int id7 = Ili;
while (id7 < illi && lII1[id7].lIii <= illI) id7++;
if (id7 >= illi) {
cout<<(Ill+1);
return 0;
}
for (int iiI=id7; iiI<illi; iiI++) illl.insert(make_pair(lII1[iiI].id22-lII1[iiI].lIii+1, lII1[iiI].lIii));
while (illI > 0 && !(illl.empty())) {
Ill = min(Ill, ((int) illl.size()));
ill1 = illl.begin();
if (illI < ill1->IiI.first) break;
illI -= ill1->IiI.first;
illl.erase(ill1->IiI);
int il11 = id7;
while (id7 >= 1 && lII1[id7-1].lIii > illI) id7--;
for (int id10=id7; id10<il11; id10++) illl.insert(make_pair(lII1[id10].id22-lII1[id10].lIii+1, lII1[id10].lIii));
}
Ill = min(Ill, ((int) illl.size()));
cout<<(Ill+1);
return 0;
}