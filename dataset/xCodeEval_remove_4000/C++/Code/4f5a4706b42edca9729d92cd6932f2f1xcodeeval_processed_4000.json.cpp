











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
unsigned int l11, id9;
unsigned int id14;
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
id9 = 0;
id4[0] = lIl;
for (unsigned int id0 = 1;
id0 < Ii;
id0++) {
id9++;
id4[id9] = lll * id4[id9-1] + ll1;
}
for (unsigned int lIi = Ii;
lIi < I;
lIi++) {
id9++;
id4[id9] = id4[id9 - Ii] -
id4[id9 - II];
}
lil = (unsigned int) (
( ((unsigned long long) 1) << ((unsigned long long) li) ) - 1
);
id14 = (unsigned int) (
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
unsigned int il1 = (id4[li1(0)] & id14) |
(id4[li1(1)] & lil);
unsigned int ili = id4[li1(ll)] ^ (il1>>1);
if (il1 & 1)
ili ^= lI;
ili = ili ^ (ili >> il);
ili = ili ^ ((ili << i1) & Il);
ili = ili ^ ((ili << ii) & I1);
ili = ili ^ (ili >> iI);
id9++;
if (id9 >= llI)
id9 -= llI;
id4[id9] = ili;
l11++;
if (l11 >= llI)
l11 -= llI;
return ili;
}
};
}
namespace ilI {
template<typename id19>
class i11 {
private:
id19 * id10;
int id22;
int * iil;
int ii1, iii;
public:
void clear() {
for (int iiI = 0; iiI < id22; iiI++)
id10[iiI].clear();
ii1 = 0;
iii = id22;
iil[id22] = -1;
for (int iiI = 0; iiI < id22; iiI++)
iil[iiI] = iiI;
}
i11(int iIl, ...) {
if (iIl <= 0) {
id10 = NULL;
id22 = 0;
iil = NULL;
ii1 = iii = 0;
return;
}
id22 = iIl;
ii1 = 0;
iii = id22;
iil = new int [id22 + 1];
iil[id22] = -1;
for (int iiI = 0; iiI < id22; iiI++)
iil[iiI] = iiI;
va_list id3;
va_start(id3, iIl);
id10 = (id19 *) operator new ( sizeof(id19) * id22 );
for (int iiI = 0; iiI < id22; iiI++) {
new(&id10[iiI]) id19(id3);
id10[iiI].clear();
}
va_end(id3);
}
~i11() {
if (id10 != NULL) {
for (int iiI = 0; iiI < id22; iiI++)
id10[iiI].~id19();
operator delete(id10);
}
if (iil != NULL)
delete [] iil;
}
int iIi() const {
return iil[ii1] == -1;
}
id19 * iII() {
if (iIi())
return NULL;
id19 * Ill = id10 + iil[ii1];
iil[ii1] = -1;
ii1++;
if (ii1 >= id22+1)
ii1 -= id22+1;
Ill->clear();
return Ill;
}
void Il1(id19 * Ili) {
if (Ili == NULL)
return;
Ili->clear();
iil[iii] = Ili - id10;
iii++;
if (iii >= id22+1)
iii -= id22+1;
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
}
};


int const id16 = 300100;
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
void clear() {
IiI = Ii1();

while (IIl) {
id2 * ll1l = IIl;
IIl = IIl->I11;

lllI->Il1(ll1l);

delete ll1l;

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
typedef Iii<I1I> * ll11;
private:
ll11 id24;


i11<id2> * id21;

i11<Iii<I1I> > * llil;

lli lli1;
private:
unsigned int llii() {
return lli1.ill();
}
void lliI(ll11 llIl, I1I IiI, ll11 & id17, ll11 & llIi) {
if (llIl == NULL) {
id17 = llIi = NULL;
return;
}
if (IiI <= llIl->IiI) {
lliI(llIl->lll1, IiI, id17, llIl->lll1);
llIi = llIl;
}
else {
lliI(llIl->llli, IiI, llIl->llli, llIi);
id17 = llIl;
}
}
void llII(ll11 & llIl, ll11 id17, ll11 llIi) {
if (id17 == NULL) {
llIl = llIi;
return;
}
if (llIi == NULL) {
llIl = id17;
return;
}
if (id17->IIi > llIi->IIi) {
llII(id17->llli, id17->llli, llIi);
llIl = id17;
}
else {
llII(llIi->lll1, id17, llIi->lll1);
llIl = llIi;
}
}

void l1ll(ll11 llIl) {
if (llIl == NULL) return;
l1ll(llIl->lll1);
l1ll(llIl->llli);
delete llIl;
}

ll11 l1l1(I1I IiI, unsigned int IIi  ) {

if (llil->iIi())
return NULL;
ll11 id5 = llil->iII();
if (id5 == NULL)
return NULL;
id5->IiI = IiI;
id5->IIi = IIi;
id5->lll1 = id5->llli = NULL;

id5->IIl = id21->iII();


ll11 id5 = new (std::nothrow) Iii<I1I>;
if (id5 == NULL)
return NULL;
id5->IiI = IiI;
id5->IIi = IIi;
id5->lll1 = id5->llli = NULL;

id5->IIl = new (std::nothrow) id2;



if (id5->IIl == NULL) {

id5->clear();
delete id5;

llil->Il1(id5);

return NULL;
}
id5->IIl->I11 = NULL;

id5->II1 = id5->III = id5->llll = 1;
return id5;
}
void l1lI(ll11 & llIl, I1I IiI  ) {
llIl->II1 += 1;


id2 * id18 = id21->iII();

id2 * id18 = new (std::nothrow) id2;

if (id18 == NULL)
return;
id18->I11 = llIl->IIl;
llIl->IIl = id18;



int l111 = llIl->II1;
l111--;
while (llIl->IIl != NULL && l111 > 0) {
id2 * ll1l = llIl->IIl;
llIl->IIl = llIl->IIl->I11;

id21->Il1(ll1l);

delete ll1l;

l111--;
}

llIl->II1 = min(llIl->II1, 1);

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

l1ll(id24);

int id1 = 0;
if (id24 != NULL) {
long long id23 = l1i1();
long long id28 = 1LL, id29 = 1LL;
while (id29 < id23) {
id29 *= 2LL;
id28++;
}
if (id23 * id28 * 3LL < (long long) id16)
id1 = 1;
}
else
id1 = 1;
if (id1) {
while (id24)
erase(id24->IiI);
}
else
llil->clear();

id24 = NULL;
}
Iil() {
id24 = NULL;


id21 = new i11<id2> (id16);
llil = new i11<Iii<I1I> > (id16, id21);

llil = new i11<Iii<I1I> > (id16);


}
~Iil() {

if (llil != NULL)
delete llil;

if (id21 != NULL)
delete id21;


l1ll(id24);

}
ll11 insert(ll11 & llIl, I1I IiI, unsigned int IIi  ) {
if (llIl == NULL) {
ll11 id5 = l1l1(IiI, IIi  );
if (id5 == NULL)
return NULL;
llIl = id5;
return llIl;
}
if (llIl->IiI == IiI) {
l1lI(llIl, IiI  );
return llIl;
}
if (IIi > llIl->IIi) {
ll11 id15 = l11i(llIl, IiI  );
if (id15 != NULL) {
return id15;
}
ll11 id5 = l1l1(IiI, IIi  );
if (id5 == NULL)
return NULL;
lliI(llIl, id5->IiI, id5->lll1, id5->llli);
llIl = id5;
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
return insert(id24, IiI, IIi  );
}
ll11 insert(I1I IiI  ) {
return insert(id24, IiI, llii()  );
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
return find(id24, IiI);
}
ll11 l1I1(ll11 llIl, int id12) const {
if (llIl == NULL)
return NULL;
int id7 = 0;
if (llIl->lll1)
id7 = llIl->lll1->llll;
if (id12 <= id7)
return l1I1(llIl->lll1, id12);
if (id12 <= id7 + llIl->II1)
return llIl;
return l1I1(llIl->llli, id12 - id7 - llIl->II1);
}
ll11 lill(int id12) const {
return l1I1(id24, id12);
}
ll11 lil1(ll11 llIl, int id12) const {
if (llIl == NULL)
return NULL;
int id7 = 0;
if (llIl->lll1)
id7 = llIl->lll1->III;
if (id12 <= id7)
return lil1(llIl->lll1, id12);
if (id12 == id7 + 1)
return llIl;
return lil1(llIl->llli, id12 - id7 - 1);
}
ll11 lili(int id12) const {
return lil1(id24, id12);
}
ll11 lilI(ll11 llIl, int id6) const {
if (llIl == NULL)
return NULL;
int li11 = 0;
if (llIl->llli)
li11 = llIl->llli->llll;
if (id6 <= li11)
return lilI(llIl->llli, id6);
if (id6 <= li11 + llIl->II1)
return llIl;
return lilI(llIl->lll1, id6 - li11 - llIl->II1);
}
ll11 li1i(int id6) const {
return lilI(id24, id6);
}
ll11 li1I(ll11 llIl, int id6) const {
if (llIl == NULL)
return NULL;
int li11 = 0;
if (llIl->llli)
li11 = llIl->llli->III;
if (id6 <= li11)
return li1I(llIl->llli, id6);
if (id6 == li11 + 1)
return llIl;
return li1I(llIl->lll1, id6 - li11 - 1);
}
ll11 liil(int id6) const {
return li1I(id24, id6);
}
void erase(ll11 & llIl, I1I IiI) {
if (llIl == NULL)
return;
if (llIl->IiI == IiI) {

llIl->II1--;

if (llIl->IIl) {
id2 * id18 = llIl->IIl;
llIl->IIl = llIl->IIl->I11;

id21->Il1(id18);

delete id18;

}

if (llIl->II1 <= 0) {
ll11 id11 = llIl;
llII(llIl, llIl->lll1, llIl->llli);

delete id11;

llil->Il1(id11);

}

ll11 id11 = llIl;
llII(llIl, llIl->lll1, llIl->llli);

delete id11;

llil->Il1(id11);


return;
}
if (llIl->IiI < IiI)
erase(llIl->llli, IiI);
else
erase(llIl->lll1, IiI);
}
void erase(I1I IiI) {
erase(id24, IiI);
}
ll11 liii(ll11 llIl) const {
if (llIl == NULL)
return llIl;
while (llIl->lll1)
llIl = llIl->lll1;
return llIl;
}
ll11 liiI() const {
return liii(id24);
}
ll11 liIl(ll11 llIl) const {
if (llIl == NULL)
return llIl;
while (llIl->llli)
llIl = llIl->llli;
return llIl;
}
ll11 liI1(ll11 llIl) const {
return liIl(id24);
}
ll11 liIi(I1I value) const {
ll11 llIl = id24;
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
ll11 id15 = liii(llIl->llli);
if (liII == NULL)
liII = id15;
else
if (id15->IiI < liII->IiI)
liII = id15;
}
return liII;
}
ll11 lIll(I1I value) const {
ll11 llIl = id24;
if (llIl == NULL)
return llIl;
ll11 id25 = NULL;
while (llIl) {
if (llIl->IiI < value) {
if (id25 == NULL)
id25 = llIl;
else
if (llIl->IiI > id25->IiI)
id25 = llIl;
llIl = llIl->llli;
}
else if (llIl->IiI > value)
llIl = llIl->lll1;
else
break;
}
if (llIl)
if (llIl->lll1) {
ll11 id15 = liIl(llIl->lll1);
if (id25 == NULL)
id25 = id15;
else
if (id15->IiI > id25->IiI)
id25 = id15;
}
return id25;
}
int lIli(I1I value) const {
ll11 llIl = id24;
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
ll11 llIl = id24;
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
ll11 llIl = id24;
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
ll11 llIl = id24;
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
ll11 llIl = id24;
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
if (id24 == NULL)
return 0;
return id24->llll;
}
int lI1I() {
if (id24 == NULL)
return 0;
id24->lIil();
return id24->III;
}
size_t size() {
return (size_t) (max(0, l1i1()));
}
int empty() {
return size() == 0;
}
ll11 begin() const {
ll11 llIl = id24;
if (llIl == NULL)
return NULL;
while (llIl->lll1) llIl = llIl->lll1;
return llIl;
}
ll11 lIi1() const {
ll11 llIl = id24;
if (llIl == NULL)
return NULL;
while (llIl->llli) llIl = llIl->llli;
return llIl;
}
};
}
using namespace IlI;
int const id27 = 300100;
struct lIiI {long long lIIl,id20; int lIIi;} lIII[id27];
bool operator < (const lIiI &illl, const lIiI &ill1) {
return illl.lIIl < ill1.lIIl || (illl.lIIl == ill1.lIIl && illl.id20-illl.lIIl < ill1.id20-ill1.lIIl);
}
Iil<pair<long long, long long> > illi;
Iil<pair<long long, long long> >::ll11 illI;
int main() {
int id8;
scanf("%d",&id8);
for (int iiI=0; iiI<id8; iiI++) {
lIII[iiI].lIIi = iiI;
scanf("%I64d%I64d",&lIII[iiI].lIIl,&lIII[iiI].id20);
}
sort(lIII,lIII+id8);
int Ili = -1;
for (int iiI=0; iiI<id8; iiI++)
if (lIII[iiI].lIIi==0) Ili = iiI;
long long il11 = lIII[Ili].lIIl;
int Ill = 0;
for (int iiI=0; iiI<id8; iiI++)
if (lIII[iiI].lIIl > il11) Ill++;
long long id20 = lIII[Ili].id20;
for (int llIi=Ili; llIi+1<id8; llIi++) lIII[llIi] = lIII[llIi+1];
id8--;
lIII[id8].lIIi = -1; lIII[id8].lIIl = 0; lIII[id8].id20 = 0;
int id13 = Ili;
while (id13 < id8 && lIII[id13].lIIl <= il11) id13++;
if (id13 >= id8) {
cout<<(Ill+1);
return 0;
}
int id26 = 0;
for (int iiI=id13; iiI<id8; iiI++) {
illi.insert(make_pair(lIII[iiI].id20-lIII[iiI].lIIl+1, lIII[iiI].lIIl));
id26++;
}
while (il11 > 0 && id26 > 0) {
Ill = min(Ill, id26);
illI = illi.begin();
if (il11 < illI->IiI.first) break;
il11 -= illI->IiI.first;
id26--;
illi.erase(illI->IiI);
int ilil = id13;
while (id13 >= 1 && lIII[id13-1].lIIl > il11) id13--;
for (int ili1=id13; ili1<ilil; ili1++) {
id26++;
illi.insert(make_pair(lIII[ili1].id20-lIII[ili1].lIIl+1, lIII[ili1].lIIl));
}
}
Ill = min(Ill, id26);
cout<<(Ill+1);
return 0;
}