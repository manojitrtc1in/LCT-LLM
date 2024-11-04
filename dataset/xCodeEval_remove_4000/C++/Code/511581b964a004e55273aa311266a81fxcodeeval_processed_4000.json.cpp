











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
unsigned int l11, id8;
unsigned int id12;
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
id8 = 0;
id3[0] = lIl;
for (unsigned int id0 = 1;
id0 < Ii;
id0++) {
id8++;
id3[id8] = lll * id3[id8-1] + ll1;
}
for (unsigned int lIi = Ii;
lIi < I;
lIi++) {
id8++;
id3[id8] = id3[id8 - Ii] -
id3[id8 - II];
}
lil = (unsigned int) (
( ((unsigned long long) 1) << ((unsigned long long) li) ) - 1
);
id12 = (unsigned int) (
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
unsigned int il1 = (id3[li1(0)] & id12) |
(id3[li1(1)] & lil);
unsigned int ili = id3[li1(ll)] ^ (il1>>1);
if (il1 & 1)
ili ^= lI;
ili = ili ^ (ili >> il);
ili = ili ^ ((ili << i1) & Il);
ili = ili ^ ((ili << ii) & I1);
ili = ili ^ (ili >> iI);
id8++;
if (id8 >= llI)
id8 -= llI;
id3[id8] = ili;
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
id16 * id9;
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
va_list id2;
va_start(id2, iIl);
id9 = (id16 *) operator new ( sizeof(id16) * id19 );
for (int iiI = 0; iiI < id19; iiI++) {
new(&id9[iiI]) id16(id2);
id9[iiI].clear();
}
va_end(id2);
}
~i11() {
if (id9 != NULL) {
for (int iiI = 0; iiI < id19; iiI++)
id9[iiI].~id16();
operator delete(id9);
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
id16 * Ill = id9 + iil[ii1];
iil[ii1] = -1;
ii1++;
if (ii1 >= id19+1)
ii1 -= id19+1;
Ill->clear();
return Ill;
}
void Il1(id16 * Ili) {
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
Iii *III, *llll;


i11<id1> * lll1;


public:
void clear() {
IiI = Ii1();

while (IIl) {
id1 * llli = IIl;
IIl = IIl->I11;

lll1->Il1(llli);

delete llli;

}

II1 = 0;
IIi = 0UL;
III = llll = NULL;
}

Iii(va_list id2) {

IIl = NULL;
lll1 = va_arg(id2, i11<id1> *);

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
typedef Iii<I1I> * lllI;
private:
lllI id27;


i11<id1> * ll11;

i11<Iii<I1I> > * id22;

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

void llIi(lllI llii) {
if (llii == NULL) return;
llIi(llii->III);
llIi(llii->llll);
delete llii;
}

lllI llII(I1I IiI, unsigned int IIi  ) {

if (id22->iIi())
return NULL;
lllI id20 = id22->iII();
if (id20 == NULL)
return NULL;
id20->IiI = IiI;
id20->IIi = IIi;
id20->III = id20->llll = NULL;

id20->IIl = ll11->iII();


lllI id20 = new (std::nothrow) Iii<I1I>;
if (id20 == NULL)
return NULL;
id20->IiI = IiI;
id20->IIi = IIi;
id20->III = id20->llll = NULL;

id20->IIl = new (std::nothrow) id1;



if (id20->IIl == NULL) {

id20->clear();
delete id20;

id22->Il1(id20);

return NULL;
}
id20->IIl->I11 = NULL;

id20->II1 = 1;
return id20;
}
void l1l1(lllI & llii, I1I IiI  ) {
llii->II1 += 1;


id1 * id4 = ll11->iII();

id1 * id4 = new (std::nothrow) id1;

if (id4 == NULL)
return;
id4->I11 = llii->IIl;
llii->IIl = id4;



int id17 = llii->II1;
id17--;
while (llii->IIl != NULL && id17 > 0) {
id1 * llli = llii->IIl;
llii->IIl = llii->IIl->I11;

ll11->Il1(llli);

delete llli;

id17--;
}

llii->II1 = min(llii->II1, 1);

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

llIi(id27);

int l111 = 0;
if (id27 != NULL) {
long long id6 = l11I();
long long id21 = 1LL, id13 = 1LL;
while (id13 < id6) {
id13 *= 2LL;
id21++;
}
if (id6 * id21 * 3LL < (long long) id15)
l111 = 1;
}
else
l111 = 1;
if (l111) {
while (id27)
erase(id27->IiI);
}
else
id22->clear();

id27 = NULL;
}
Iil() {
id27 = NULL;


ll11 = new i11<id1> (id15);
id22 = new i11<Iii<I1I> > (id15, ll11);

id22 = new i11<Iii<I1I> > (id15);


}
~Iil() {

if (id22 != NULL)
delete id22;

if (ll11 != NULL)
delete ll11;


llIi(id27);

}
lllI insert(lllI & llii, I1I IiI, unsigned int IIi  ) {
if (llii == NULL) {
lllI id20 = llII(IiI, IIi  );
if (id20 == NULL)
return NULL;
llii = id20;
return llii;
}
if (llii->IiI == IiI) {
l1l1(llii, IiI  );
return llii;
}
if (IIi > llii->IIi) {
lllI id28 = l11l(llii, IiI  );
if (id28 != NULL) {
return id28;
}
lllI id20 = llII(IiI, IIi  );
if (id20 == NULL)
return NULL;
lli1(llii, id20->IiI, id20->III, id20->llll);
llii = id20;
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
return insert(id27, IiI, IIi  );
}
lllI insert(I1I IiI  ) {
return insert(id27, IiI, llil()  );
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
return find(id27, IiI);
}
lllI l1iI(lllI llii, int id14) const {
if (llii == NULL)
return NULL;
int id23 = 0;
if (llii->III)
id23 = llii->III->l1Ii;
if (id14 <= id23)
return l1iI(llii->III, id14);
if (id14 <= id23 + llii->II1)
return llii;
return l1iI(llii->llll, id14 - id23 - llii->II1);
}
lllI l1II(int id14) const {
return l1iI(id27, id14);
}
lllI lill(lllI llii, int id14) const {
if (llii == NULL)
return NULL;
int id23 = 0;
if (llii->III)
id23 = llii->III->lil1;
if (id14 <= id23)
return lill(llii->III, id14);
if (id14 == id23 + 1)
return llii;
return lill(llii->llll, id14 - id23 - 1);
}
lllI lili(int id14) const {
return lill(id27, id14);
}
lllI lilI(lllI llii, int id5) const {
if (llii == NULL)
return NULL;
int li11 = 0;
if (llii->llll)
li11 = llii->llll->l1Ii;
if (id5 <= li11)
return lilI(llii->llll, id5);
if (id5 <= li11 + llii->II1)
return llii;
return lilI(llii->III, id5 - li11 - llii->II1);
}
lllI li1i(int id5) const {
return lilI(id27, id5);
}
lllI li1I(lllI llii, int id5) const {
if (llii == NULL)
return NULL;
int li11 = 0;
if (llii->llll)
li11 = llii->llll->lil1;
if (id5 <= li11)
return li1I(llii->llll, id5);
if (id5 == li11 + 1)
return llii;
return li1I(llii->III, id5 - li11 - 1);
}
lllI liil(int id5) const {
return li1I(id27, id5);
}
void erase(lllI & llii, I1I IiI) {
if (llii == NULL)
return;
if (llii->IiI == IiI) {

llii->II1--;

if (llii->IIl) {
id1 * id4 = llii->IIl;
llii->IIl = llii->IIl->I11;

ll11->Il1(id4);

delete id4;

}

if (llii->II1 <= 0) {
lllI id10 = llii;
llI1(llii, llii->III, llii->llll);

delete id10;

id22->Il1(id10);

}

lllI id10 = llii;
llI1(llii, llii->III, llii->llll);

delete id10;

id22->Il1(id10);


return;
}
if (llii->IiI < IiI)
erase(llii->llll, IiI);
else
erase(llii->III, IiI);
}
void erase(I1I IiI) {
erase(id27, IiI);
}
lllI liii(lllI llii) const {
if (llii == NULL)
return llii;
while (llii->III)
llii = llii->III;
return llii;
}
lllI liiI() const {
return liii(id27);
}
lllI liIl(lllI llii) const {
if (llii == NULL)
return llii;
while (llii->llll)
llii = llii->llll;
return llii;
}
lllI liI1(lllI llii) const {
return liIl(id27);
}
lllI liIi(I1I value) const {
lllI llii = id27;
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
lllI id28 = liii(llii->llll);
if (liII == NULL)
liII = id28;
else
if (id28->IiI < liII->IiI)
liII = id28;
}
return liII;
}
lllI lIll(I1I value) const {
lllI llii = id27;
if (llii == NULL)
return llii;
lllI id24 = NULL;
while (llii) {
if (llii->IiI < value) {
if (id24 == NULL)
id24 = llii;
else
if (llii->IiI > id24->IiI)
id24 = llii;
llii = llii->llll;
}
else if (llii->IiI > value)
llii = llii->III;
else
break;
}
if (llii)
if (llii->III) {
lllI id28 = liIl(llii->III);
if (id24 == NULL)
id24 = id28;
else
if (id28->IiI > id24->IiI)
id24 = id28;
}
return id24;
}
int lIli(I1I value) const {
lllI llii = id27;
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
lllI llii = id27;
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
lllI llii = id27;
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
lllI llii = id27;
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
lllI llii = id27;
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
if (id27 == NULL)
return 0;
return id27->l1Ii;
}
int lI1I() {
if (id27 == NULL)
return 0;
id27->lIil();
return id27->lil1;
}
size_t size() {
return (size_t) (max(0, l11I()));
}
int empty() {
return size() == 0;
}
lllI begin() const {
lllI llii = id27;
if (llii == NULL)
return NULL;
while (llii->III) llii = llii->III;
return llii;
}
lllI lIi1() const {
lllI llii = id27;
if (llii == NULL)
return NULL;
while (llii->llll) llii = llii->llll;
return llii;
}
};
}
using namespace IlI;
int const id26 = 300100;
struct lIiI {long long lIIl,id18; int lIIi;} lIII[id26];
bool operator < (const lIiI &illl, const lIiI &ill1) {
return illl.lIIl < ill1.lIIl || (illl.lIIl == ill1.lIIl && illl.id18-illl.lIIl < ill1.id18-ill1.lIIl);
}
Iil<pair<long long, long long> > illi;
Iil<pair<long long, long long> >::lllI illI;
int main() {
int id7;
scanf("%d",&id7);
for (int iiI=0; iiI<id7; iiI++) {
lIII[iiI].lIIi = iiI;
scanf("%I64d%I64d",&lIII[iiI].lIIl,&lIII[iiI].id18);
}
sort(lIII,lIII+id7);
int Ili = -1;
for (int iiI=0; iiI<id7; iiI++)
if (lIII[iiI].lIIi==0) Ili = iiI;
long long il11 = lIII[Ili].lIIl;
int Ill = 0;
for (int iiI=0; iiI<id7; iiI++)
if (lIII[iiI].lIIl > il11) Ill++;
long long id18 = lIII[Ili].id18;
for (int llIl=Ili; llIl+1<id7; llIl++) lIII[llIl] = lIII[llIl+1];
id7--;
lIII[id7].lIIi = -1; lIII[id7].lIIl = 0; lIII[id7].id18 = 0;
int id11 = Ili;
while (id11 < id7 && lIII[id11].lIIl <= il11) id11++;
if (id11 >= id7) {
cout<<(Ill+1);
return 0;
}
int id25 = 0;
for (int iiI=id11; iiI<id7; iiI++) {
illi.insert(make_pair(lIII[iiI].id18-lIII[iiI].lIIl+1, lIII[iiI].lIIl));
id25++;
}
while (il11 > 0 && id25 > 0) {
Ill = min(Ill, id25);
illI = illi.begin();
if (il11 < illI->IiI.first) break;
il11 -= illI->IiI.first;
id25--;
illi.erase(illI->IiI);
int ilil = id11;
while (id11 >= 1 && lIII[id11-1].lIIl > il11) id11--;
for (int ili1=id11; ili1<ilil; ili1++) {
id25++;
illi.insert(make_pair(lIII[ili1].id18-lIII[ili1].lIIl+1, lIII[ili1].lIIl));
}
}
Ill = min(Ill, id25);
cout<<(Ill+1);
return 0;
}