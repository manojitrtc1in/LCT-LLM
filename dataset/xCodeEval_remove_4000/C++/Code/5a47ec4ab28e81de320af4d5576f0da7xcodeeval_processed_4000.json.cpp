











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
template<typename id15>
class i11 {
private:
id15 * id9;
int id19;
int * iil;
int ii1, iii;
public:
void clear() {
for (int iiI = 0; iiI < id19; iiI++)
id9[iiI].clear();
ii1 = 0;
iii = id19;
iil[id19] = -1;
for (int iiI = 0; iiI < id19; iiI++)
iil[iiI] = iiI;
}
i11(int iIl, ...) {
if (iIl <= 0) {
id9 = NULL;
id19 = 0;
iil = NULL;
ii1 = iii = 0;
return;
}
id19 = iIl;
ii1 = 0;
iii = id19;
iil = new int [id19 + 1];
iil[id19] = -1;
for (int iiI = 0; iiI < id19; iiI++)
iil[iiI] = iiI;
va_list id3;
va_start(id3, iIl);
id9 = (id15 *) operator new ( sizeof(id15) * id19 );
for (int iiI = 0; iiI < id19; iiI++) {
new(&id9[iiI]) id15(id3);
id9[iiI].clear();
}
va_end(id3);
}
~i11() {
clear();
if (id9 != NULL) {
for (int iiI = 0; iiI < id19; iiI++)
id9[iiI].~id15();
operator delete(id9);
}
if (iil != NULL)
delete [] iil;
}
int iIi() const {
return iil[ii1] == -1;
}
id15 * iII() {
if (iIi())
return NULL;
id15 * Ill = id9 + iil[ii1];
iil[ii1] = -1;
ii1++;
if (ii1 >= id19+1)
ii1 -= id19+1;
Ill->clear();
return Ill;
}
void Il1(id15 * Ili) {
if (Ili == NULL)
return;
Ili->clear();
iil[iii] = Ili - id9;
iii++;
if (iii >= id19+1)
iii -= id19+1;
}
};
}
namespace IlI {
using namespace l;


struct id2 {
public:
id2 * I11;
public:
void clear() {
I11 = NULL;
}
id2(...) {
I11 = NULL;
}
~id2() {
clear();
}
};


int const id13 = 300100;
using namespace ilI;

template<typename I1I>
class Iil {
public:
template<typename Ii1>
class Iii {
public:
Ii1 IiI;

id2 * IIl;

int II1;
unsigned int IIi;
int III;
int llll;
Iii *lll1, *llli;


i11<id2> * lllI;


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
id2 * ll11 = IIl;
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
lllI = va_arg(id3, i11<id2> *);

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
ll1i id18;


i11<id2> * llil;

i11<Iii<I1I> > * lli1;

lli llii;
private:
unsigned int lliI() {
return llii.ill();
}
void llIl(ll1i id14, I1I IiI, ll1i & llIi, ll1i & llII) {
if (id14 == NULL) {
llIi = llII = NULL;
return;
}
if (IiI <= id14->IiI) {
llIl(id14->lll1, IiI, llIi, id14->lll1);
llII = id14;
if (llII)
llII->ll1l();
}
else {
llIl(id14->llli, IiI, id14->llli, llII);
llIi = id14;
if (llIi)
llIi->ll1l();
}
}
void l1ll(ll1i & id14, ll1i llIi, ll1i llII) {
if (llIi == NULL) {
id14 = llII;
if (id14)
id14->ll1l();
return;
}
if (llII == NULL) {
id14 = llIi;
if (id14)
id14->ll1l();
return;
}
if (llIi->IIi > llII->IIi) {
l1ll(llIi->llli, llIi->llli, llII);
id14 = llIi;
}
else {
l1ll(llII->lll1, llIi, llII->lll1);
id14 = llII;
}
if (id14)
id14->ll1l();
}

void l1l1(ll1i id14) {
if (id14 == NULL) return;
l1l1(id14->lll1);
l1l1(id14->llli);
delete id14;
}

ll1i l1li(I1I IiI, unsigned int IIi  ) {

if (lli1->iIi())
return NULL;
ll1i id16 = lli1->iII();
if (id16 == NULL)
return NULL;
id16->IiI = IiI;
id16->IIi = IIi;
id16->lll1 = id16->llli = NULL;

id16->IIl = llil->iII();


ll1i id16 = new (std::nothrow) Iii<I1I>;
if (id16 == NULL)
return NULL;
id16->IiI = IiI;
id16->IIi = IIi;
id16->lll1 = id16->llli = NULL;

id16->IIl = new (std::nothrow) id2;



if (id16->IIl == NULL) {

id16->clear();
delete id16;

lli1->Il1(id16);

return NULL;
}
id16->IIl->I11 = NULL;

id16->II1 = id16->III = id16->llll = 1;
id16->ll1l();
return id16;
}
void l11l(ll1i & id14, I1I IiI  ) {
id14->II1 += 1;


id2 * l111 = llil->iII();

id2 * l111 = new (std::nothrow) id2;

if (l111 == NULL)
return;
l111->I11 = id14->IIl;
id14->IIl = l111;



int id6 = id14->II1;
id6--;
while (id14->IIl != NULL && id6 > 0) {
id2 * ll11 = id14->IIl;
id14->IIl = id14->IIl->I11;

llil->Il1(ll11);

delete ll11;

id6--;
}

id14->II1 = min(id14->II1, 1);

}
public:
void clear() {

l1l1(id18);

int id1 = 0;
if (id18 != NULL) {
long long id20 = l1i1();
long long id24 = 1LL, id26 = 1LL;
while (id26 < id20) {
id26 *= 2LL;
id24++;
}
if (id20 * id24 * 3LL < (long long) id13)
id1 = 1;
}
else
id1 = 1;
if (id1) {
while (id18)
erase(id18->IiI);
}
else
lli1->clear();

id18 = NULL;
}
Iil() {
id18 = NULL;


llil = new i11<id2> (id13);
lli1 = new i11<Iii<I1I> > (id13, llil);

lli1 = new i11<Iii<I1I> > (id13);


}
~Iil() {
clear();

if (lli1 != NULL)
delete lli1;

if (llil != NULL)
delete llil;


}
ll1i l1Il(ll1i & id14, I1I IiI  ) {
if (id14 == NULL)
return NULL;
if (id14->IiI == IiI) {
l11l(id14, IiI  );
if (id14)
id14->ll1l();
return id14;
}
ll1i Ill = NULL;
if (id14->IiI < IiI)
Ill = l1Il(id14->llli, IiI  );
else
Ill = l1Il(id14->lll1, IiI  );
if (id14)
id14->ll1l();
return Ill;
}
ll1i insert(ll1i & id14, I1I IiI, unsigned int IIi  ) {
if (id14 == NULL) {
ll1i id16 = l1li(IiI, IIi  );
if (id16 == NULL)
return NULL;
id14 = id16;
if (id14)
id14->ll1l();
return id14;
}
if (id14->IiI == IiI) {
l11l(id14, IiI  );
if (id14)
id14->ll1l();
return id14;
}
if (IIi > id14->IIi) {
ll1i id21 = l1Il(id14, IiI  );
if (id21 != NULL) {
if (id14)
id14->ll1l();
return id21;
}
ll1i id16 = l1li(IiI, IIi  );
if (id16 == NULL)
return NULL;
llIl(id14, id16->IiI, id16->lll1, id16->llli);
id14 = id16;
if (id14)
id14->ll1l();
return id14;
}
ll1i Ill = NULL;
if (id14->IiI < IiI)
Ill = insert(id14->llli, IiI, IIi  );
else
Ill = insert(id14->lll1, IiI, IIi  );
if (id14)
id14->ll1l();
return Ill;
}
ll1i insert(ll1i & id14 , I1I IiI  ) {
return insert(id14, IiI, lliI()  );
}
ll1i insert(I1I IiI, unsigned int IIi  ) {
return insert(id18, IiI, IIi  );
}
ll1i insert(I1I IiI  ) {
return insert(id18, IiI, lliI()  );
}
ll1i find(ll1i id14, I1I IiI) const {
if (id14 == NULL)
return NULL;
if (id14->IiI < IiI)
return find(id14->llli, IiI);
else if (id14->IiI > IiI)
return find(id14->lll1, IiI);
else
return id14;
}
ll1i find(I1I IiI) const {
return find(id18, IiI);
}
ll1i l1Ii(ll1i id14, int id5) const {
if (id14 == NULL)
return NULL;
int lill = 0;
if (id14->lll1)
lill = id14->lll1->llll;
if (id5 <= lill)
return l1Ii(id14->lll1, id5);
if (id5 <= lill + id14->II1)
return id14;
return l1Ii(id14->llli, id5 - lill - id14->II1);
}
ll1i lil1(int id5) const {
return l1Ii(id18, id5);
}
ll1i lili(ll1i id14, int id5) const {
if (id14 == NULL)
return NULL;
int lill = 0;
if (id14->lll1)
lill = id14->lll1->III;
if (id5 <= lill)
return lili(id14->lll1, id5);
if (id5 == lill + 1)
return id14;
return lili(id14->llli, id5 - lill - 1);
}
ll1i lilI(int id5) const {
return lili(id18, id5);
}
ll1i li1l(ll1i id14, int li11) const {
if (id14 == NULL)
return NULL;
int id25 = 0;
if (id14->llli)
id25 = id14->llli->llll;
if (li11 <= id25)
return li1l(id14->llli, li11);
if (li11 <= id25 + id14->II1)
return id14;
return li1l(id14->lll1, li11 - id25 - id14->II1);
}
ll1i li1I(int li11) const {
return li1l(id18, li11);
}
ll1i liil(ll1i id14, int li11) const {
if (id14 == NULL)
return NULL;
int id25 = 0;
if (id14->llli)
id25 = id14->llli->III;
if (li11 <= id25)
return liil(id14->llli, li11);
if (li11 == id25 + 1)
return id14;
return liil(id14->lll1, li11 - id25 - 1);
}
ll1i lii1(int li11) const {
return liil(id18, li11);
}
void erase(ll1i & id14, I1I IiI) {
if (id14 == NULL)
return;
if (id14->IiI == IiI) {

id14->II1--;

if (id14->IIl) {
id2 * l111 = id14->IIl;
id14->IIl = id14->IIl->I11;

llil->Il1(l111);

delete l111;

}

if (id14->II1 <= 0) {
ll1i liii = id14;
l1ll(id14, id14->lll1, id14->llli);

delete liii;

lli1->Il1(liii);

}

ll1i liii = id14;
l1ll(id14, id14->lll1, id14->llli);

delete liii;

lli1->Il1(liii);


if (id14)
id14->ll1l();
return;
}
if (id14->IiI < IiI)
erase(id14->llli, IiI);
else
erase(id14->lll1, IiI);
if (id14)
id14->ll1l();
}
void erase(I1I IiI) {
erase(id18, IiI);
}
ll1i liiI(ll1i id14) const {
if (id14 == NULL)
return id14;
while (id14->lll1)
id14 = id14->lll1;
return id14;
}
ll1i liIl() const {
return liiI(id18);
}
ll1i liI1(ll1i id14) const {
if (id14 == NULL)
return id14;
while (id14->llli)
id14 = id14->llli;
return id14;
}
ll1i liIi(ll1i id14) const {
return liI1(id18);
}
ll1i liII(I1I value) const {
ll1i id14 = id18;
if (id14 == NULL)
return id14;
ll1i lIll = NULL;
while (id14) {
if (id14->IiI < value)
id14 = id14->llli;
else if (id14->IiI > value) {
if (lIll == NULL)
lIll = id14;
else
if (id14->IiI < lIll->IiI)
lIll = id14;
id14 = id14->lll1;
}
else
break;
}
if (id14)
if (id14->llli) {
ll1i id21 = liiI(id14->llli);
if (lIll == NULL)
lIll = id21;
else
if (id21->IiI < lIll->IiI)
lIll = id21;
}
return lIll;
}
ll1i lIl1(I1I value) const {
ll1i id14 = id18;
if (id14 == NULL)
return id14;
ll1i id12 = NULL;
while (id14) {
if (id14->IiI < value) {
if (id12 == NULL)
id12 = id14;
else
if (id14->IiI > id12->IiI)
id12 = id14;
id14 = id14->llli;
}
else if (id14->IiI > value)
id14 = id14->lll1;
else
break;
}
if (id14)
if (id14->lll1) {
ll1i id21 = liI1(id14->lll1);
if (id12 == NULL)
id12 = id21;
else
if (id21->IiI > id12->IiI)
id12 = id21;
}
return id12;
}
int lIlI(I1I value) const {
ll1i id14 = id18;
if (id14 == NULL)
return 0;
while (id14)
if (id14->IiI < value)
id14 = id14->llli;
else if (id14->IiI > value)
id14 = id14->lll1;
else
break;
if (id14 == NULL)
return 0;
return id14->II1;
}
int lI1l(I1I value) const {
ll1i id14 = id18;
if (id14 == NULL)
return 0;
int Ill = 0;
while (id14)
if (id14->IiI < value) {
Ill += id14->II1;
if (id14->lll1)
Ill += id14->lll1->llll;
id14 = id14->llli;
}
else if (id14->IiI > value)
id14 = id14->lll1;
else
break;
if (id14)
if (id14->lll1)
Ill += id14->lll1->llll;
return Ill;
}
int lI11(I1I value) const {
ll1i id14 = id18;
if (id14 == NULL)
return 0;
int Ill = 0;
while (id14)
if (id14->IiI < value) {
Ill++;
if (id14->lll1)
Ill += id14->lll1->III;
id14 = id14->llli;
}
else if (id14->IiI > value)
id14 = id14->lll1;
else
break;
if (id14)
if (id14->lll1)
Ill += id14->lll1->III;
return Ill;
}
int lI1i(I1I value) const {
ll1i id14 = id18;
if (id14 == NULL)
return 0;
int Ill = 0;
while (id14)
if (id14->IiI < value)
id14 = id14->llli;
else if (id14->IiI > value) {
Ill += id14->II1;
if (id14->llli)
Ill += id14->llli->llll;
id14 = id14->lll1;
}
else
break;
if (id14)
if (id14->llli)
Ill += id14->llli->llll;
return Ill;
}
int lI1I(I1I value) const {
ll1i id14 = id18;
if (id14 == NULL)
return 0;
int Ill = 0;
while (id14)
if (id14->IiI < value)
id14 = id14->llli;
else if (id14->IiI > value) {
Ill++;
if (id14->llli)
Ill += id14->llli->III;
id14 = id14->lll1;
}
else
break;
if (id14)
if (id14->llli)
Ill += id14->llli->III;
return Ill;
}
int l1i1() {
if (id18 == NULL)
return 0;
id18->ll1l();
return id18->llll;
}
int lIil() {
if (id18 == NULL)
return 0;
id18->ll1l();
return id18->III;
}
size_t size() {
return (size_t) (max(0, l1i1()));
}
int empty() {
return size() == 0;
}
ll1i begin() const {
return lil1(1);
}
ll1i lIi1() const {
return li1I(1);
}
};
}
using namespace IlI;
int const id23 = 300100;
struct lIiI {long long lIIl,id17; int lIIi;} lIII[id23];
bool operator < (const lIiI &illl, const lIiI &ill1) {
return illl.lIIl < ill1.lIIl || (illl.lIIl == ill1.lIIl && illl.id17-illl.lIIl < ill1.id17-ill1.lIIl);
}
Iil<pair<long long,long long> > illi;
Iil<pair<long long,long long> >::ll1i illI;
int main() {
int id7;
scanf("%d",&id7);
for (int iiI=0; iiI<id7; iiI++) {
lIII[iiI].lIIi = iiI;
scanf("%I64d%I64d",&lIII[iiI].lIIl,&lIII[iiI].id17);
}
sort(lIII,lIII+id7);
int Ili = -1;
for (int iiI=0; iiI<id7; iiI++)
if (lIII[iiI].lIIi==0) Ili = iiI;
long long il11 = lIII[Ili].lIIl;
int Ill = 0;
for (int iiI=0; iiI<id7; iiI++)
if (lIII[iiI].lIIl > il11) Ill++;
long long id17 = lIII[Ili].id17;
for (int llII=Ili; llII+1<id7; llII++) lIII[llII] = lIII[llII+1];
id7--;
lIII[id7].lIIi = -1; lIII[id7].lIIl = 0; lIII[id7].id17 = 0;
int id10 = Ili;
while (id10 < id7 && lIII[id10].lIIl <= il11) id10++;
if (id10 >= id7) {
cout<<(Ill+1);
return 0;
}
for (int iiI=id10; iiI<id7; iiI++) illi.insert(make_pair(lIII[iiI].id17-lIII[iiI].lIIl+1, lIII[iiI].lIIl));
while (il11 > 0 && !(illi.empty())) {
Ill = min(Ill, ((int) illi.size()));
illI = illi.begin();
if (il11 < illI->IiI.first) break;
il11 -= illI->IiI.first;
illi.erase(illI->IiI);
int id22 = id10;
while (id10 >= 1 && lIII[id10-1].lIIl > il11) id10--;
for (int ilil=id10; ilil<id22; ilil++) illi.insert(make_pair(lIII[ilil].id17-lIII[ilil].lIIl+1, lIII[ilil].lIIl));
}
Ill = min(Ill, ((int) illi.size()));
cout<<(Ill+1);
return 0;
}