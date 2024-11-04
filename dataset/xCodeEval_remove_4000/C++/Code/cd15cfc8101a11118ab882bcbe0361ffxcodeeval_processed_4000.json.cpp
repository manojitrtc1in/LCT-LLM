











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
unsigned int id13;
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
id13 = (unsigned int) (
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
unsigned int il1 = (id4[li1(0)] & id13) |
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
template<typename id18>
class i11 {
private:
id18 * id10;
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
id10 = (id18 *) operator new ( sizeof(id18) * id22 );
for (int iiI = 0; iiI < id22; iiI++) {
new(&id10[iiI]) id18(id3);
id10[iiI].clear();
}
va_end(id3);
}
~i11() {
clear();
if (id10 != NULL) {
for (int iiI = 0; iiI < id22; iiI++)
id10[iiI].~id18();
operator delete(id10);
}
if (iil != NULL)
delete [] iil;
}
int iIi() const {
return iil[ii1] == -1;
}
id18 * iII() {
if (iIi())
return NULL;
id18 * Ill = id10 + iil[ii1];
iil[ii1] = -1;
ii1++;
if (ii1 >= id22+1)
ii1 -= id22+1;
Ill->clear();
return Ill;
}
void Il1(id18 * Ili) {
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
clear();
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
ll1i id21;


i11<id2> * llil;

i11<Iii<I1I> > * lli1;

lli llii;
private:
unsigned int lliI() {
return llii.ill();
}
void llIl(ll1i id16, I1I IiI) {
if (id16 == NULL)
return;
if (id16->IiI < IiI)
llIl(id16->llli, IiI);
else if (id16->IiI > IiI)
llIl(id16->lll1, IiI);
if (id16)
id16->ll1l();
}
void llIi(ll1i id16, I1I IiI, ll1i & llII, ll1i & id23) {
if (id16 == NULL) {
llII = id23 = NULL;
return;
}
if (IiI <= id16->IiI) {
llIi(id16->lll1, IiI, llII, id16->lll1);
id23 = id16;
if (id23)
id23->ll1l();
}
else {
llIi(id16->llli, IiI, id16->llli, id23);
llII = id16;
if (llII)
llII->ll1l();
}
}
void l1l1(ll1i & id16, ll1i llII, ll1i id23) {
if (llII == NULL) {
id16 = id23;
if (id16)
id16->ll1l();
return;
}
if (id23 == NULL) {
id16 = llII;
if (id16)
id16->ll1l();
return;
}
if (llII->IIi > id23->IIi) {
l1l1(llII->llli, llII->llli, id23);
id16 = llII;
}
else {
l1l1(id23->lll1, llII, id23->lll1);
id16 = id23;
}
if (id16)
id16->ll1l();
}

void l1li(ll1i id16) {
if (id16 == NULL) return;
l1li(id16->lll1);
l1li(id16->llli);
delete id16;
}

void insert(ll1i & id16, ll1i & id19) {
if (id16 == NULL) {
id16 = id19;
if (id16)
id16->ll1l();
return;
}
if (id16->IiI == id19->IiI) {
id16->II1 += id19->II1;

id2 * id17 = id19->IIl;
while (id17) {
id2 * l111 = id17->I11;
id17->I11 = id16->IIl;
id16->IIl = id17;
id17 = l111;
}



int id7 = id16->II1;
id7 -= 1;
while (id16->IIl != NULL && id7 > 0) {
id2 * ll11 = id16->IIl;
id16->IIl = id16->IIl->I11;

llil->Il1(ll11);

delete ll11;

id7--;
}

id16->II1 = min(id16->II1, 1);


id19->IIl = NULL;


lli1->Il1(id19);

delete id19;

if (id16)
id16->ll1l();
id19 = id16;
return;
}
if (id19->IIi > id16->IIi) {
llIi(id16, id19->IiI, id19->lll1, id19->llli);
id16 = id19;
if (id16)
id16->ll1l();
return;
}
if (id16->IiI < id19->IiI)
insert(id16->llli, id19);
else
insert(id16->lll1, id19);
if (id16)
id16->ll1l();
}
public:
void clear() {

l1li(id21);

int id1 = 0;
if (id21 != NULL) {
long long id24 = l1i1();
long long id30 = 1LL, id31 = 1LL;
while (id31 < id24) {
id31 *= 2LL;
id30++;
}
if (id24 * id30 * 3LL < (long long) id15)
id1 = 1;
}
else
id1 = 1;
if (id1) {
while (id21)
erase(id21->IiI);
}
else
lli1->clear();

id21 = NULL;
}
Iil() {
id21 = NULL;


llil = new i11<id2> (id15);
lli1 = new i11<Iii<I1I> > (id15, llil);

lli1 = new i11<Iii<I1I> > (id15);


}
~Iil() {
clear();

if (lli1 != NULL)
delete lli1;

if (llil != NULL)
delete llil;


}
ll1i insert(ll1i & id16, I1I IiI, unsigned int IIi  ) {
ll1i Ili = find(IiI);
if (Ili != NULL) {
Ili->II1++;
Ili->ll1l();
llIl(id21, IiI);
return Ili;
}

if (lli1->iIi())
return NULL;
ll1i id19 = lli1->iII();
if (id19 == NULL)
return NULL;
id19->IiI = IiI;
id19->IIi = IIi;
id19->lll1 = id19->llli = NULL;

id19->IIl = llil->iII();


ll1i id19 = new (std::nothrow) Iii<I1I>;
if (id19 == NULL)
return NULL;
id19->IiI = IiI;
id19->IIi = IIi;
id19->lll1 = id19->llli = NULL;

id19->IIl = new (std::nothrow) id2;



if (id19->IIl == NULL) {

id19->clear();
delete id19;

lli1->Il1(id19);

return NULL;
}
id19->IIl->I11 = NULL;

id19->II1 = id19->III = id19->llll = 1;
id19->ll1l();
insert(id16, id19);
return id19;
}
ll1i insert(ll1i & id16 , I1I IiI  ) {
return insert(id16, IiI, lliI()  );
}
ll1i insert(I1I IiI, unsigned int IIi  ) {
return insert(id21, IiI, IIi  );
}
ll1i insert(I1I IiI  ) {
return insert(id21, IiI, lliI()  );
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
return find(id21, IiI);
}
ll1i l1Il(ll1i id16, int id26) const {
if (id16 == NULL)
return NULL;
int id11 = 0;
if (id16->lll1)
id11 = id16->lll1->llll;
if (id26 <= id11)
return l1Il(id16->lll1, id26);
if (id26 <= id11 + id16->II1)
return id16;
return l1Il(id16->llli, id26 - id11 - id16->II1);
}
ll1i l1II(int id26) const {
return l1Il(id21, id26);
}
ll1i lill(ll1i id16, int id26) const {
if (id16 == NULL)
return NULL;
int id11 = 0;
if (id16->lll1)
id11 = id16->lll1->III;
if (id26 <= id11)
return lill(id16->lll1, id26);
if (id26 == id11 + 1)
return id16;
return lill(id16->llli, id26 - id11 - 1);
}
ll1i lil1(int id26) const {
return lill(id21, id26);
}
ll1i lili(ll1i id16, int id20) const {
if (id16 == NULL)
return NULL;
int id6 = 0;
if (id16->llli)
id6 = id16->llli->llll;
if (id20 <= id6)
return lili(id16->llli, id20);
if (id20 <= id6 + id16->II1)
return id16;
return lili(id16->lll1, id20 - id6 - id16->II1);
}
ll1i li11(int id20) const {
return lili(id21, id20);
}
ll1i li1i(ll1i id16, int id20) const {
if (id16 == NULL)
return NULL;
int id6 = 0;
if (id16->llli)
id6 = id16->llli->III;
if (id20 <= id6)
return li1i(id16->llli, id20);
if (id20 == id6 + 1)
return id16;
return li1i(id16->lll1, id20 - id6 - 1);
}
ll1i li1I(int id20) const {
return li1i(id21, id20);
}
void erase(ll1i & id16, I1I IiI) {
if (id16 == NULL)
return;
if (id16->IiI == IiI) {

id16->II1--;

if (id16->IIl) {
id2 * id17 = id16->IIl;
id16->IIl = id16->IIl->I11;

llil->Il1(id17);

delete id17;

}

if (id16->II1 <= 0) {
ll1i liil = id16;
l1l1(id16, id16->lll1, id16->llli);

delete liil;

lli1->Il1(liil);

}

ll1i liil = id16;
l1l1(id16, id16->lll1, id16->llli);

delete liil;

lli1->Il1(liil);


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
erase(id21, IiI);
}
ll1i lii1(ll1i id16) const {
if (id16 == NULL)
return id16;
while (id16->lll1)
id16 = id16->lll1;
return id16;
}
ll1i liii() const {
return lii1(id21);
}
ll1i liiI(ll1i id16) const {
if (id16 == NULL)
return id16;
while (id16->llli)
id16 = id16->llli;
return id16;
}
ll1i liIl(ll1i id16) const {
return liiI(id21);
}
ll1i liI1(I1I value) const {
ll1i id16 = id21;
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
ll1i liII = lii1(id16->llli);
if (liIi == NULL)
liIi = liII;
else
if (liII->IiI < liIi->IiI)
liIi = liII;
}
return liIi;
}
ll1i lIll(I1I value) const {
ll1i id16 = id21;
if (id16 == NULL)
return id16;
ll1i id27 = NULL;
while (id16) {
if (id16->IiI < value) {
if (id27 == NULL)
id27 = id16;
else
if (id16->IiI > id27->IiI)
id27 = id16;
id16 = id16->llli;
}
else if (id16->IiI > value)
id16 = id16->lll1;
else
break;
}
if (id16)
if (id16->lll1) {
ll1i liII = liiI(id16->lll1);
if (id27 == NULL)
id27 = liII;
else
if (liII->IiI > id27->IiI)
id27 = liII;
}
return id27;
}
int lIli(I1I value) const {
ll1i id16 = id21;
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
int lIlI(I1I value) const {
ll1i id16 = id21;
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
int lI1l(I1I value) const {
ll1i id16 = id21;
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
int lI11(I1I value) const {
ll1i id16 = id21;
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
int lI1i(I1I value) const {
ll1i id16 = id21;
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
int l1i1() {
if (id21 == NULL)
return 0;
id21->ll1l();
return id21->llll;
}
int lI1I() {
if (id21 == NULL)
return 0;
id21->ll1l();
return id21->III;
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
Iil<pair<long long,long long> > id5;
Iil<pair<long long,long long> >::ll1i id29;
int const id25 = 300100;
struct lIIl {long long lII1,id14; int lIII;} illl[id25];
bool operator < (const lIIl &ill1, const lIIl &illi) {
return ill1.lII1 < illi.lII1 || (ill1.lII1 == illi.lII1 && ill1.id14-ill1.lII1 < illi.id14-illi.lII1);
}
int main() {
int illI;
scanf("%d",&illI);
for (int iiI=0; iiI<illI; iiI++) {
illl[iiI].lIII = iiI;
scanf("%I64d%I64d",&illl[iiI].lII1,&illl[iiI].id14);
}
sort(illl,illl+illI);
int Ili = -1;
for (int iiI=0; iiI<illI; iiI++)
if (illl[iiI].lIII==0) Ili = iiI;
long long id8 = illl[Ili].lII1;
int Ill = 0;
for (int iiI=0; iiI<illI; iiI++)
if (illl[iiI].lII1 > id8) Ill++;
long long id14 = illl[Ili].id14;
for (int id23=Ili; id23+1<illI; id23++) illl[id23] = illl[id23+1];
illI--;
illl[illI].lIII = -1; illl[illI].lII1 = 0; illl[illI].id14 = 0;
int il11 = Ili;
while (il11 < illI && illl[il11].lII1 <= id8) il11++;
if (il11 >= illI) {
cout<<(Ill+1);
return 0;
}
for (int iiI=il11; iiI<illI; iiI++) id5.insert(make_pair(illl[iiI].id14-illl[iiI].lII1+1, illl[iiI].lII1));
while (id8 > 0 && !(id5.empty())) {
Ill = min(Ill, ((int) id5.size()));
id29 = id5.begin();
if (id8 < id29->IiI.first) break;
id8 -= id29->IiI.first;
id5.erase(id29->IiI);
int id12 = il11;
while (il11 >= 1 && illl[il11-1].lII1 > id8) il11--;
for (int id28=il11; id28<id12; id28++) id5.insert(make_pair(illl[id28].id14-illl[id28].lII1+1, illl[id28].lII1));
}
Ill = min(Ill, ((int) id5.size()));
cout<<(Ill+1);
return 0;
}