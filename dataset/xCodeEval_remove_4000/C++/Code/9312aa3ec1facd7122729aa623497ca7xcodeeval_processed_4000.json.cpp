











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
unsigned int * id3;
unsigned int l11, id7;
unsigned int id10;
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
id3 = new unsigned int [llI];
l11 = 0;
id7 = 0;
id3[0] = lIl;
for (unsigned int id0 = 1;
id0 < Ii;
id0++) {
id7++;
id3[id7] = lll * id3[id7-1] + ll1;
}
for (unsigned int lIi = Ii;
lIi < I;
lIi++) {
id7++;
id3[id7] = id3[id7 - Ii] -
id3[id7 - II];
}
lil = (unsigned int) (
( ((unsigned long long) 1) << ((unsigned long long) li) ) - 1
);
id10 = (unsigned int) (
( ((unsigned long long) 1) << ((unsigned long long) l1) ) - 1 -
lil
);
}
~lli() {
delete [] id3;
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
unsigned int il1 = (id3[li1(0)] & id10) |
(id3[li1(1)] & lil);
unsigned int ili = id3[li1(ll)] ^ (il1>>1);
if (il1 & 1)
ili ^= lI;
ili = ili ^ (ili >> il);
ili = ili ^ ((ili << i1) & Il);
ili = ili ^ ((ili << ii) & I1);
ili = ili ^ (ili >> iI);
id7++;
if (id7 >= llI)
id7 -= llI;
id3[id7] = ili;
l11++;
if (l11 >= llI)
l11 -= llI;
return ili;
}
};
}
namespace ilI {
template<typename id16>
class i11 {
private:
id16 * id8;
int id20;
int * iil;
int ii1, iii;
public:
void clear() {
for (int iiI = 0; iiI < id20; iiI++)
id8[iiI].clear();
ii1 = 0;
iii = id20;
iil[id20] = -1;
for (int iiI = 0; iiI < id20; iiI++)
iil[iiI] = iiI;
}
i11(int iIl, ...) {
if (iIl <= 0) {
id8 = NULL;
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
va_list id2;
va_start(id2, iIl);
id8 = (id16 *) operator new ( sizeof(id16) * id20 );
for (int iiI = 0; iiI < id20; iiI++) {
new(&id8[iiI]) id16(id2);
id8[iiI].clear();
}
va_end(id2);
}
~i11() {
if (id8 != NULL) {
for (int iiI = 0; iiI < id20; iiI++)
id8[iiI].~id16();
operator delete(id8);
}
if (iil != NULL)
delete [] iil;
}
int iIi() const {
return iil[ii1] == -1;
}
id16 * iII() {
if (iIi())
return NULL;
id16 * Ill = id8 + iil[ii1];
iil[ii1] = -1;
ii1++;
if (ii1 >= id20+1)
ii1 -= id20+1;
Ill->clear();
return Ill;
}
void Il1(id16 * Ili) {
if (Ili == NULL)
return;
Ili->clear();
iil[iii] = Ili - id8;
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


int const id14 = 300100;
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

Iii(va_list id2) {

IIl = NULL;
lllI = va_arg(id2, i11<id1> *);

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
void llIl(ll1i id15, I1I IiI, ll1i & llIi, ll1i & llII) {
if (id15 == NULL) {
llIi = llII = NULL;
return;
}
if (IiI <= id15->IiI) {
llIl(id15->lll1, IiI, llIi, id15->lll1);
llII = id15;
if (llII)
llII->ll1l();
}
else {
llIl(id15->llli, IiI, id15->llli, llII);
llIi = id15;
if (llIi)
llIi->ll1l();
}
}
void l1ll(ll1i & id15, ll1i llIi, ll1i llII) {
if (llIi == NULL) {
id15 = llII;
if (id15)
id15->ll1l();
return;
}
if (llII == NULL) {
id15 = llIi;
if (id15)
id15->ll1l();
return;
}
if (llIi->IIi > llII->IIi) {
l1ll(llIi->llli, llIi->llli, llII);
id15 = llIi;
}
else {
l1ll(llII->lll1, llIi, llII->lll1);
id15 = llII;
}
if (id15)
id15->ll1l();
}

void l1l1(ll1i id15) {
if (id15 == NULL) return;
l1l1(id15->lll1);
l1l1(id15->llli);
delete id15;
}

ll1i l1li(I1I IiI, unsigned int IIi  ) {

if (lli1->iIi())
return NULL;
ll1i id17 = lli1->iII();
if (id17 == NULL)
return NULL;
id17->IiI = IiI;
id17->IIi = IIi;
id17->lll1 = id17->llli = NULL;

id17->IIl = llil->iII();


ll1i id17 = new (std::nothrow) Iii<I1I>;
if (id17 == NULL)
return NULL;
id17->IiI = IiI;
id17->IIi = IIi;
id17->lll1 = id17->llli = NULL;

id17->IIl = new (std::nothrow) id1;



if (id17->IIl == NULL) {

id17->clear();
delete id17;

lli1->Il1(id17);

return NULL;
}
id17->IIl->I11 = NULL;

id17->II1 = id17->III = id17->llll = 1;
id17->ll1l();
return id17;
}
void l11l(ll1i & id15, I1I IiI  ) {
id15->II1 += 1;


id1 * l111 = llil->iII();

id1 * l111 = new (std::nothrow) id1;

if (l111 == NULL)
return;
l111->I11 = id15->IIl;
id15->IIl = l111;



int id5 = id15->II1;
id5--;
while (id15->IIl != NULL && id5 > 0) {
id1 * ll11 = id15->IIl;
id15->IIl = id15->IIl->I11;

llil->Il1(ll11);

delete ll11;

id5--;
}

id15->II1 = min(id15->II1, 1);

}
ll1i l11I(ll1i & id15, I1I IiI  ) {
if (id15 == NULL)
return NULL;
if (id15->IiI == IiI) {
l11l(id15, IiI  );
if (id15)
id15->ll1l();
return id15;
}
ll1i Ill = NULL;
if (id15->IiI < IiI)
Ill = l11I(id15->llli, IiI  );
else
Ill = l11I(id15->lll1, IiI  );
if (id15)
id15->ll1l();
return Ill;
}
public:
void clear() {

l1l1(id19);

int id21 = 0;
if (id19 != NULL) {
long long id12 = l1ii();
long long id26 = 1LL, id13 = 1LL;
while (id13 < id12) {
id13 *= 2LL;
id26++;
}
if (id12 * id26 * 3LL < (long long) id14)
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


llil = new i11<id1> (id14);
lli1 = new i11<Iii<I1I> > (id14, llil);

lli1 = new i11<Iii<I1I> > (id14);


}
~Iil() {

if (lli1 != NULL)
delete lli1;

if (llil != NULL)
delete llil;


l1l1(id19);

}
ll1i insert(ll1i & id15, I1I IiI, unsigned int IIi  ) {
if (id15 == NULL) {
ll1i id17 = l1li(IiI, IIi  );
if (id17 == NULL)
return NULL;
id15 = id17;
if (id15)
id15->ll1l();
return id15;
}
if (id15->IiI == IiI) {
l11l(id15, IiI  );
if (id15)
id15->ll1l();
return id15;
}
if (IIi > id15->IIi) {
ll1i id22 = l11I(id15, IiI  );
if (id22 != NULL) {
if (id15)
id15->ll1l();
return id22;
}
ll1i id17 = l1li(IiI, IIi  );
if (id17 == NULL)
return NULL;
llIl(id15, id17->IiI, id17->lll1, id17->llli);
id15 = id17;
if (id15)
id15->ll1l();
return id15;
}
ll1i Ill = NULL;
if (id15->IiI < IiI)
Ill = insert(id15->llli, IiI, IIi  );
else
Ill = insert(id15->lll1, IiI, IIi  );
if (id15)
id15->ll1l();
return Ill;
}
ll1i insert(ll1i & id15 , I1I IiI  ) {
return insert(id15, IiI, lliI()  );
}
ll1i insert(I1I IiI, unsigned int IIi  ) {
return insert(id19, IiI, IIi  );
}
ll1i insert(I1I IiI  ) {
return insert(id19, IiI, lliI()  );
}
ll1i find(ll1i id15, I1I IiI) const {
if (id15 == NULL)
return NULL;
if (id15->IiI < IiI)
return find(id15->llli, IiI);
else if (id15->IiI > IiI)
return find(id15->lll1, IiI);
else
return id15;
}
ll1i find(I1I IiI) const {
return find(id19, IiI);
}
ll1i l1Ii(ll1i id15, int id4) const {
if (id15 == NULL)
return NULL;
int lill = 0;
if (id15->lll1)
lill = id15->lll1->llll;
if (id4 <= lill)
return l1Ii(id15->lll1, id4);
if (id4 <= lill + id15->II1)
return id15;
return l1Ii(id15->llli, id4 - lill - id15->II1);
}
ll1i lil1(int id4) const {
return l1Ii(id19, id4);
}
ll1i lili(ll1i id15, int id4) const {
if (id15 == NULL)
return NULL;
int lill = 0;
if (id15->lll1)
lill = id15->lll1->III;
if (id4 <= lill)
return lili(id15->lll1, id4);
if (id4 == lill + 1)
return id15;
return lili(id15->llli, id4 - lill - 1);
}
ll1i lilI(int id4) const {
return lili(id19, id4);
}
ll1i li1l(ll1i id15, int li11) const {
if (id15 == NULL)
return NULL;
int id25 = 0;
if (id15->llli)
id25 = id15->llli->llll;
if (li11 <= id25)
return li1l(id15->llli, li11);
if (li11 <= id25 + id15->II1)
return id15;
return li1l(id15->lll1, li11 - id25 - id15->II1);
}
ll1i li1I(int li11) const {
return li1l(id19, li11);
}
ll1i liil(ll1i id15, int li11) const {
if (id15 == NULL)
return NULL;
int id25 = 0;
if (id15->llli)
id25 = id15->llli->III;
if (li11 <= id25)
return liil(id15->llli, li11);
if (li11 == id25 + 1)
return id15;
return liil(id15->lll1, li11 - id25 - 1);
}
ll1i lii1(int li11) const {
return liil(id19, li11);
}
void erase(ll1i & id15, I1I IiI) {
if (id15 == NULL)
return;
if (id15->IiI == IiI) {

id15->II1--;

if (id15->IIl) {
id1 * l111 = id15->IIl;
id15->IIl = id15->IIl->I11;

llil->Il1(l111);

delete l111;

}

if (id15->II1 <= 0) {
ll1i liii = id15;
l1ll(id15, id15->lll1, id15->llli);

delete liii;

lli1->Il1(liii);

}

ll1i liii = id15;
l1ll(id15, id15->lll1, id15->llli);

delete liii;

lli1->Il1(liii);


if (id15)
id15->ll1l();
return;
}
if (id15->IiI < IiI)
erase(id15->llli, IiI);
else
erase(id15->lll1, IiI);
if (id15)
id15->ll1l();
}
void erase(I1I IiI) {
erase(id19, IiI);
}
ll1i liiI(ll1i id15) const {
if (id15 == NULL)
return id15;
while (id15->lll1)
id15 = id15->lll1;
return id15;
}
ll1i liIl() const {
return liiI(id19);
}
ll1i liI1(ll1i id15) const {
if (id15 == NULL)
return id15;
while (id15->llli)
id15 = id15->llli;
return id15;
}
ll1i liIi(ll1i id15) const {
return liI1(id19);
}
ll1i liII(I1I value) const {
ll1i id15 = id19;
if (id15 == NULL)
return id15;
ll1i lIll = NULL;
while (id15) {
if (id15->IiI < value)
id15 = id15->llli;
else if (id15->IiI > value) {
if (lIll == NULL)
lIll = id15;
else
if (id15->IiI < lIll->IiI)
lIll = id15;
id15 = id15->lll1;
}
else
break;
}
if (id15)
if (id15->llli) {
ll1i id22 = liiI(id15->llli);
if (lIll == NULL)
lIll = id22;
else
if (id22->IiI < lIll->IiI)
lIll = id22;
}
return lIll;
}
ll1i lIl1(I1I value) const {
ll1i id15 = id19;
if (id15 == NULL)
return id15;
ll1i id11 = NULL;
while (id15) {
if (id15->IiI < value) {
if (id11 == NULL)
id11 = id15;
else
if (id15->IiI > id11->IiI)
id11 = id15;
id15 = id15->llli;
}
else if (id15->IiI > value)
id15 = id15->lll1;
else
break;
}
if (id15)
if (id15->lll1) {
ll1i id22 = liI1(id15->lll1);
if (id11 == NULL)
id11 = id22;
else
if (id22->IiI > id11->IiI)
id11 = id22;
}
return id11;
}
int lIlI(I1I value) const {
ll1i id15 = id19;
if (id15 == NULL)
return 0;
while (id15)
if (id15->IiI < value)
id15 = id15->llli;
else if (id15->IiI > value)
id15 = id15->lll1;
else
break;
if (id15 == NULL)
return 0;
return id15->II1;
}
int lI1l(I1I value) const {
ll1i id15 = id19;
if (id15 == NULL)
return 0;
int Ill = 0;
while (id15)
if (id15->IiI < value) {
Ill += id15->II1;
if (id15->lll1)
Ill += id15->lll1->llll;
id15 = id15->llli;
}
else if (id15->IiI > value)
id15 = id15->lll1;
else
break;
if (id15)
if (id15->lll1)
Ill += id15->lll1->llll;
return Ill;
}
int lI11(I1I value) const {
ll1i id15 = id19;
if (id15 == NULL)
return 0;
int Ill = 0;
while (id15)
if (id15->IiI < value) {
Ill++;
if (id15->lll1)
Ill += id15->lll1->III;
id15 = id15->llli;
}
else if (id15->IiI > value)
id15 = id15->lll1;
else
break;
if (id15)
if (id15->lll1)
Ill += id15->lll1->III;
return Ill;
}
int lI1i(I1I value) const {
ll1i id15 = id19;
if (id15 == NULL)
return 0;
int Ill = 0;
while (id15)
if (id15->IiI < value)
id15 = id15->llli;
else if (id15->IiI > value) {
Ill += id15->II1;
if (id15->llli)
Ill += id15->llli->llll;
id15 = id15->lll1;
}
else
break;
if (id15)
if (id15->llli)
Ill += id15->llli->llll;
return Ill;
}
int lI1I(I1I value) const {
ll1i id15 = id19;
if (id15 == NULL)
return 0;
int Ill = 0;
while (id15)
if (id15->IiI < value)
id15 = id15->llli;
else if (id15->IiI > value) {
Ill++;
if (id15->llli)
Ill += id15->llli->III;
id15 = id15->lll1;
}
else
break;
if (id15)
if (id15->llli)
Ill += id15->llli->III;
return Ill;
}
int l1ii() {
if (id19 == NULL)
return 0;
id19->ll1l();
return id19->llll;
}
int lIil() {
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
ll1i id15 = id19;
if (id15 == NULL)
return NULL;
while (id15->lll1) id15 = id15->lll1;
return id15;
}
ll1i lIi1() const {
ll1i id15 = id19;
if (id15 == NULL)
return NULL;
while (id15->llli) id15 = id15->llli;
return id15;
}
};
}
using namespace IlI;
int const id24 = 300100;
struct lIiI {long long lIIl,id18; int lIIi;} lIII[id24];
bool operator < (const lIiI &illl, const lIiI &ill1) {
return illl.lIIl < ill1.lIIl || (illl.lIIl == ill1.lIIl && illl.id18-illl.lIIl < ill1.id18-ill1.lIIl);
}
Iil<pair<long long, long long> > illi;
Iil<pair<long long, long long> >::ll1i illI;
int main() {
int id6;
scanf("%d",&id6);
for (int iiI=0; iiI<id6; iiI++) {
lIII[iiI].lIIi = iiI;
scanf("%I64d%I64d",&lIII[iiI].lIIl,&lIII[iiI].id18);
}
sort(lIII,lIII+id6);
int Ili = -1;
for (int iiI=0; iiI<id6; iiI++)
if (lIII[iiI].lIIi==0) Ili = iiI;
long long il11 = lIII[Ili].lIIl;
int Ill = 0;
for (int iiI=0; iiI<id6; iiI++)
if (lIII[iiI].lIIl > il11) Ill++;
long long id18 = lIII[Ili].id18;
for (int llII=Ili; llII+1<id6; llII++) lIII[llII] = lIII[llII+1];
id6--;
lIII[id6].lIIi = -1; lIII[id6].lIIl = 0; lIII[id6].id18 = 0;
int id9 = Ili;
while (id9 < id6 && lIII[id9].lIIl <= il11) id9++;
if (id9 >= id6) {
cout<<(Ill+1);
return 0;
}
for (int iiI=id9; iiI<id6; iiI++) illi.insert(make_pair(lIII[iiI].id18-lIII[iiI].lIIl+1, lIII[iiI].lIIl));
while (il11 > 0 && !(illi.empty())) {
Ill = min(Ill, ((int) illi.size()));
illI = illi.begin();
if (il11 < illI->IiI.first) break;
il11 -= illI->IiI.first;
illi.erase(illI->IiI);
int id23 = id9;
while (id9 >= 1 && lIII[id9-1].lIIl > il11) id9--;
for (int ilil=id9; ilil<id23; ilil++) illi.insert(make_pair(lIII[ilil].id18-lIII[ilil].lIIl+1, lIII[ilil].lIIl));
}
Ill = min(Ill, ((int) illi.size()));
cout<<(Ill+1);
return 0;
}