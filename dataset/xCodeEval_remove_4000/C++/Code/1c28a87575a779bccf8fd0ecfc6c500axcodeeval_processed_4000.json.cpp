











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
unsigned int * id6;
unsigned int l11, id12;
unsigned int id17;
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
id6 = new unsigned int [llI];
l11 = 0;
id12 = 0;
id6[0] = lIl;
for (unsigned int id0 = 1;
id0 < Ii;
id0++) {
id12++;
id6[id12] = lll * id6[id12-1] + ll1;
}
for (unsigned int lIi = Ii;
lIi < I;
lIi++) {
id12++;
id6[id12] = id6[id12 - Ii] -
id6[id12 - II];
}
lil = (unsigned int) (
( ((unsigned long long) 1) << ((unsigned long long) li) ) - 1
);
id17 = (unsigned int) (
( ((unsigned long long) 1) << ((unsigned long long) l1) ) - 1 -
lil
);
}
~lli() {
delete [] id6;
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
unsigned int il1 = (id6[li1(0)] & id17) |
(id6[li1(1)] & lil);
unsigned int ili = id6[li1(ll)] ^ (il1>>1);
if (il1 & 1)
ili ^= lI;
ili = ili ^ (ili >> il);
ili = ili ^ ((ili << i1) & Il);
ili = ili ^ ((ili << ii) & I1);
ili = ili ^ (ili >> iI);
id12++;
if (id12 >= llI)
id12 -= llI;
id6[id12] = ili;
l11++;
if (l11 >= llI)
l11 -= llI;
return ili;
}
};
}
namespace ilI {
unsigned int const id29 = 16369;
unsigned int const i11 = 3;
unsigned int const id13 = 3;
unsigned long long const id34 = 1000000000000000009ULL;
template <class iil>
class ii1 {
private:
struct iii {
iil value;
void * iiI;
unsigned long long iIl;
iii *id4;
iii() {
value = iil();
iiI = NULL;
iIl = 0ULL;
id4 = NULL;
}
~iii() {}
} **iIi;
unsigned int iII;
unsigned int Ill;
unsigned long long Il1(const iil & value) const {
return id34 * (((unsigned long long) value) + 1ULL);
}
void resize() {
if (iIi == NULL)
return;
unsigned int Ili = iII * id13;
iii **IlI = new iii* [Ili];
for (unsigned int id2 = 0UL; id2 < Ili; id2++)
IlI[id2] = NULL;
for (unsigned int id2 = 0UL; id2 < iII; id2++)
if (iIi[id2]) {
iii *I11 = iIi[id2], *id24;
while (I11) {
unsigned int id9 = I11->iIl % Ili;
id24 = I11->id4;
I11->id4 = IlI[id9];
IlI[id9] = I11;
I11 = id24;
}
iIi[id2] = NULL;
}
delete [] iIi;
iIi = IlI;
iII = Ili;
}
public:
ii1() {
iII = id29;
Ill = 0UL;
iIi = new iii* [iII];
for (unsigned int id2 = 0UL; id2 < iII; id2++)
iIi[id2] = NULL;
}
void clear() {
if (iIi != NULL)
for (unsigned int id2 = 0UL; id2 < iII; id2++)
if (iIi[id2]) {
iii *I11 = iIi[id2], *Iil;
while (I11) {
Iil = I11;
I11 = I11->id4;
delete Iil;
}
iIi[id2] = NULL;
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
unsigned int id9 = Ii1 % iII;
iii * I11 = new iii();
I11->value = value;
I11->iiI = iiI;
I11->iIl = Ii1;
I11->id4 = iIi[id9];
iIi[id9] = I11;
Ill++;
if (i11 * iII < Ill)
resize();
}
void * find(const iil & value) const {
unsigned long long Ii1 = Il1(value);
unsigned int id9 = Ii1 % iII;
iii *I11 = iIi[id9];
while (I11) {
if (I11->value == value)
return I11->iiI;
I11 = I11->id4;
}
return NULL;
}
void erase(const iil & value) {
unsigned long long Ii1 = Il1(value);
unsigned int id9 = Ii1 % iII;
iii *I11 = iIi[id9], *Iii = NULL;
while (I11) {
if (I11->value == value)
{
if (Iii == NULL)
iIi[id9] = I11->id4;
else
Iii->id4 = I11->id4;
delete I11;
return;
}
Iii = I11;
I11 = I11->id4;
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
for (int id2 = 0; id2 < III; id2++)
IIi[id2].clear();
lll1 = 0;
llli = III;
llll[III] = -1;
for (int id2 = 0; id2 < III; id2++)
llll[id2] = id2;
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
for (int id2 = 0; id2 < III; id2++)
llll[id2] = id2;
va_list id43;
va_start(id43, lllI);
IIi = (IIl *) operator new ( sizeof(IIl) * III );
for (int id2 = 0; id2 < III; id2++) {
new(&IIi[id2]) IIl(id43);
IIi[id2].clear();
}
va_end(id43);
}
~II1() {
clear();
if (IIi != NULL) {
for (int id2 = 0; id2 < III; id2++)
IIi[id2].~IIl();
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
IIl * id33 = IIi + llll[lll1];
llll[lll1] = -1;
lll1++;
if (lll1 >= III+1)
lll1 -= III+1;
id33->clear();
return id33;
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


struct llii {
public:
llii * id4;
public:
void clear() {
id4 = NULL;
}
llii(...) {
id4 = NULL;
}
~llii() {
clear();
}
};


int const lliI = 100100;
using namespace IiI;

template<typename llIl>
class id26 {
public:
template<typename llIi>
class llII {
public:
llIi id35;

llii * id19;

int id7;
unsigned int id30;
int id27;
int l111;
llII *id10, *id1;


II1<llii> * id36;


public:
void l1i1() {
id27 = 1;
l111 = id7;
if (id10) {
id27 += id10->id27;
l111 += id10->l111;
}
if (id1) {
id27 += id1->id27;
l111 += id1->l111;
}
}
void clear() {
id35 = llIi();

while (id19) {
llii * Iii = id19;
id19 = id19->id4;

id36->llil(Iii);

delete Iii;

}

id7 = 0;
id30 = 0UL;
id27 = 0;
l111 = 0;
id10 = id1 = NULL;
}

llII(va_list id43) {

id19 = NULL;
id36 = va_arg(id43, II1<llii> *);

clear();
}

llII() {

id19 = NULL;

clear();
}

~llII() {
clear();
}
};
typedef llII<llIl> * l1ii;
private:
l1ii id45;


II1<llii> * id23;

II1<llII<llIl> > * id40;

lli l1Ii;
ii1<llIl> * iIi;
private:
unsigned int l1II() {
return l1Ii.ill();
}
void lill(l1ii id39, llIl id35) {
if (id39 == NULL)
return;
if (id39->id35 < id35)
lill(id39->id1, id35);
else if (id39->id35 > id35)
lill(id39->id10, id35);
if (id39)
id39->l1i1();
}
void lili(l1ii id39, llIl id35, l1ii & id31, l1ii & id8) {
if (id39 == NULL) {
id31 = id8 = NULL;
return;
}
if (id35 <= id39->id35) {
lili(id39->id10, id35, id31, id39->id10);
id8 = id39;
if (id8)
id8->l1i1();
}
else {
lili(id39->id1, id35, id39->id1, id8);
id31 = id39;
if (id31)
id31->l1i1();
}
}
void li11(l1ii & id39, l1ii id31, l1ii id8) {
if (id31 == NULL) {
id39 = id8;
if (id39)
id39->l1i1();
return;
}
if (id8 == NULL) {
id39 = id31;
if (id39)
id39->l1i1();
return;
}
if (id31->id30 > id8->id30) {
li11(id31->id1, id31->id1, id8);
id39 = id31;
}
else {
li11(id8->id10, id31, id8->id10);
id39 = id8;
}
if (id39)
id39->l1i1();
}

void li1i(l1ii id39) {
if (id39 == NULL) return;
li1i(id39->id10);
li1i(id39->id1);
if (iIi)
iIi->erase(id39->id35);
delete id39;
}

void insert(l1ii & id39, l1ii & id18) {
if (id39 == NULL) {
id39 = id18;
if (id39)
id39->l1i1();
return;
}
if (id39->id35 == id18->id35) {
id39->id7 += id18->id7;

llii * liil = id18->id19;
while (liil) {
llii * id24 = liil->id4;
liil->id4 = id39->id19;
id39->id19 = liil;
liil = id24;
}



int id14 = id39->id7;
id14 -= 1;
while (id39->id19 != NULL && id14 > 0) {
llii * Iii = id39->id19;
id39->id19 = id39->id19->id4;

id23->llil(Iii);

delete Iii;

id14--;
}

id39->id7 = min(id39->id7, 1);


id18->id19 = NULL;


id40->llil(id18);

delete id18;

if (id39)
id39->l1i1();
id18 = id39;
return;
}
if (id18->id30 > id39->id30) {
lili(id39, id18->id35, id18->id10, id18->id1);
id39 = id18;
if (id39)
id39->l1i1();
return;
}
if (id39->id35 < id18->id35)
insert(id39->id1, id18);
else
insert(id39->id10, id18);
if (id39)
id39->l1i1();
}
public:
void clear() {

li1i(id45);

int liii = 0;
if (id45 != NULL) {
long long id21 = liIl();
long long id25 = 1LL, liIi = 1LL;
while (liIi < id21) {
liIi *= 2LL;
id25++;
}
if (id21 * id25 * 3LL < (long long) lliI)
liii = 1;
}
else
liii = 1;
if (liii) {
while (id45)
erase(id45->id35);
}
else
id40->clear();

id45 = NULL;
if (iIi)
iIi->clear();
}
id26() {
id45 = NULL;
iIi = new ii1<llIl>;


id23 = new II1<llii> (lliI);
id40 = new II1<llII<llIl> > (lliI, id23);

id40 = new II1<llII<llIl> > (lliI);


}
~id26() {
clear();
if (iIi)
delete iIi;

if (id40 != NULL)
delete id40;

if (id23 != NULL)
delete id23;


}
l1ii insert(l1ii & id39, llIl id35, unsigned int id30  ) {
l1ii I11 = find(id35);
if (I11 != NULL) {
I11->id7++;
I11->l1i1();
lill(id45, id35);
return I11;
}

if (id40->ll11())
return NULL;
l1ii id18 = id40->ll1i();
if (id18 == NULL)
return NULL;
id18->id35 = id35;
id18->id30 = id30;
id18->id10 = id18->id1 = NULL;

id18->id19 = id23->ll1i();


l1ii id18 = new (std::nothrow) llII<llIl>;
if (id18 == NULL)
return NULL;
id18->id35 = id35;
id18->id30 = id30;
id18->id10 = id18->id1 = NULL;

id18->id19 = new (std::nothrow) llii;



if (id18->id19 == NULL) {

id18->clear();
delete id18;

id40->llil(id18);

return NULL;
}
id18->id19->id4 = NULL;

id18->id7 = id18->id27 = id18->l111 = 1;
id18->l1i1();
if (iIi)
iIi->insert(id18->id35, (void *) id18);
insert(id39, id18);
return id18;
}
l1ii insert(l1ii & id39 , llIl id35  ) {
return insert(id39, id35, l1II()  );
}
l1ii insert(llIl id35, unsigned int id30  ) {
return insert(id45, id35, id30  );
}
l1ii insert(llIl id35  ) {
return insert(id45, id35, l1II()  );
}
l1ii find(l1ii id39, llIl id35) const {
if (id39 == NULL)
return NULL;
if (id39->id35 < id35)
return find(id39->id1, id35);
else if (id39->id35 > id35)
return find(id39->id10, id35);
else
return id39;
}
l1ii find(llIl id35) const {
l1ii liII = NULL;
if (iIi)
liII = (l1ii) iIi->find(id35);
if (liII)
return liII;
return find(id45, id35);
}
l1ii lIll(l1ii id39, int id42) const {
if (id39 == NULL)
return NULL;
int id20 = 0;
if (id39->id10)
id20 = id39->id10->l111;
if (id42 <= id20)
return lIll(id39->id10, id42);
if (id42 <= id20 + id39->id7)
return id39;
return lIll(id39->id1, id42 - id20 - id39->id7);
}
l1ii lIlI(int id42) const {
return lIll(id45, id42);
}
l1ii lI1l(l1ii id39, int id42) const {
if (id39 == NULL)
return NULL;
int id20 = 0;
if (id39->id10)
id20 = id39->id10->id27;
if (id42 <= id20)
return lI1l(id39->id10, id42);
if (id42 == id20 + 1)
return id39;
return lI1l(id39->id1, id42 - id20 - 1);
}
l1ii lI11(int id42) const {
return lI1l(id45, id42);
}
l1ii lI1i(l1ii id39, int id15) const {
if (id39 == NULL)
return NULL;
int id3 = 0;
if (id39->id1)
id3 = id39->id1->l111;
if (id15 <= id3)
return lI1i(id39->id1, id15);
if (id15 <= id3 + id39->id7)
return id39;
return lI1i(id39->id10, id15 - id3 - id39->id7);
}
l1ii lIi1(int id15) const {
return lI1i(id45, id15);
}
l1ii lIii(l1ii id39, int id15) const {
if (id39 == NULL)
return NULL;
int id3 = 0;
if (id39->id1)
id3 = id39->id1->id27;
if (id15 <= id3)
return lIii(id39->id1, id15);
if (id15 == id3 + 1)
return id39;
return lIii(id39->id10, id15 - id3 - 1);
}
l1ii lIiI(int id15) const {
return lIii(id45, id15);
}
void erase(l1ii & id39, llIl id35) {
if (id39 == NULL)
return;
if (id39->id35 == id35) {

id39->id7--;

if (id39->id19) {
llii * liil = id39->id19;
id39->id19 = id39->id19->id4;

id23->llil(liil);

delete liil;

}

if (id39->id7 <= 0) {
l1ii lIIl = id39;
li11(id39, id39->id10, id39->id1);
if (iIi)
iIi->erase(lIIl->id35);

delete lIIl;

id40->llil(lIIl);

}

l1ii lIIl = id39;
li11(id39, id39->id10, id39->id1);
if (iIi)
iIi->erase(lIIl->id35);

delete lIIl;

id40->llil(lIIl);


if (id39)
id39->l1i1();
return;
}
if (id39->id35 < id35)
erase(id39->id1, id35);
else
erase(id39->id10, id35);
if (id39)
id39->l1i1();
}
void erase(llIl id35) {
erase(id45, id35);
}
l1ii lII1(l1ii id39) const {
if (id39 == NULL)
return id39;
while (id39->id10)
id39 = id39->id10;
return id39;
}
l1ii lIIi() const {
return lII1(id45);
}
l1ii lIII(l1ii id39) const {
if (id39 == NULL)
return id39;
while (id39->id1)
id39 = id39->id1;
return id39;
}
l1ii illl(l1ii id39) const {
return lIII(id45);
}
l1ii ill1(llIl value) const {
l1ii id39 = id45;
if (id39 == NULL)
return id39;
l1ii illi = NULL;
while (id39) {
if (id39->id35 < value)
id39 = id39->id1;
else if (id39->id35 > value) {
if (illi == NULL)
illi = id39;
else
if (id39->id35 < illi->id35)
illi = id39;
id39 = id39->id10;
}
else
break;
}
if (id39)
if (id39->id1) {
l1ii liII = lII1(id39->id1);
if (illi == NULL)
illi = liII;
else
if (liII->id35 < illi->id35)
illi = liII;
}
return illi;
}
l1ii illI(llIl value) const {
l1ii id39 = id45;
if (id39 == NULL)
return id39;
l1ii id11 = NULL;
while (id39) {
if (id39->id35 < value) {
if (id11 == NULL)
id11 = id39;
else
if (id39->id35 > id11->id35)
id11 = id39;
id39 = id39->id1;
}
else if (id39->id35 > value)
id39 = id39->id10;
else
break;
}
if (id39)
if (id39->id10) {
l1ii liII = lIII(id39->id10);
if (id11 == NULL)
id11 = liII;
else
if (liII->id35 > id11->id35)
id11 = liII;
}
return id11;
}
int il11(llIl value) const {
l1ii liII = NULL;
if (iIi)
liII = (l1ii) iIi->find(value);
if (liII)
return liII->id7;
if (iIi)
return 0;
l1ii id39 = id45;
if (id39 == NULL)
return 0;
while (id39)
if (id39->id35 < value)
id39 = id39->id1;
else if (id39->id35 > value)
id39 = id39->id10;
else
break;
if (id39 == NULL)
return 0;
return id39->id7;
}
int il1i(llIl value) const {
l1ii id39 = id45;
if (id39 == NULL)
return 0;
int id33 = 0;
while (id39)
if (id39->id35 < value) {
id33 += id39->id7;
if (id39->id10)
id33 += id39->id10->l111;
id39 = id39->id1;
}
else if (id39->id35 > value)
id39 = id39->id10;
else
break;
if (id39)
if (id39->id10)
id33 += id39->id10->l111;
return id33;
}
int il1I(llIl value) const {
l1ii id39 = id45;
if (id39 == NULL)
return 0;
int id33 = 0;
while (id39)
if (id39->id35 < value) {
id33++;
if (id39->id10)
id33 += id39->id10->id27;
id39 = id39->id1;
}
else if (id39->id35 > value)
id39 = id39->id10;
else
break;
if (id39)
if (id39->id10)
id33 += id39->id10->id27;
return id33;
}
int ilil(llIl value) const {
l1ii id39 = id45;
if (id39 == NULL)
return 0;
int id33 = 0;
while (id39)
if (id39->id35 < value)
id39 = id39->id1;
else if (id39->id35 > value) {
id33 += id39->id7;
if (id39->id1)
id33 += id39->id1->l111;
id39 = id39->id10;
}
else
break;
if (id39)
if (id39->id1)
id33 += id39->id1->l111;
return id33;
}
int ili1(llIl value) const {
l1ii id39 = id45;
if (id39 == NULL)
return 0;
int id33 = 0;
while (id39)
if (id39->id35 < value)
id39 = id39->id1;
else if (id39->id35 > value) {
id33++;
if (id39->id1)
id33 += id39->id1->id27;
id39 = id39->id10;
}
else
break;
if (id39)
if (id39->id1)
id33 += id39->id1->id27;
return id33;
}
int liIl() {
if (id45 == NULL)
return 0;
id45->l1i1();
return id45->l111;
}
int ilii() {
if (id45 == NULL)
return 0;
id45->l1i1();
return id45->id27;
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
int const ilIl = 100100;
long long ilI1[ilIl];
int ilIi[ilIl], ilII;
id26<long long> id5;
id26<long long>::l1ii id41;
id26<int> id37;
id26<int>::l1ii id32;
long long id28(int i111, int id22) {
if (i111 > id22) return 0;
if (id22 < 0) return 0;
long long id33 = ilI1[id22];
if (i111 > 0)
id33 -= ilI1[i111-1];
return id33;
}
int main() {
scanf("%d",&ilII);
for (int id2=0; id2<ilII; id2++) scanf("%d",&ilIi[id2]);
ilI1[0] = ilIi[0];
for (int id2=1; id2<ilII; id2++) ilI1[id2] = ilI1[id2-1] + ilIi[id2];
id37.insert(-1); id37.insert(ilII);
id5.insert(0);
id5.insert(id28(0,ilII-1));
for (int id2=0; id2<ilII; id2++) {
int id38;
scanf("%d",&id38);
id38--;
id32 = id37.find(id38);
if (id32 == NULL)
id32 = id37.ill1(id38);
int id44 = id32->id35;
id32 = id37.illI(id32->id35);
int id16 = id32->id35;
id5.erase(id28(id16+1,id44-1));
id5.insert(id28(id16+1, id38-1));
id5.insert(id28(id38+1, id44-1));
id37.insert(id38);
if (id5.empty()) printf("0\n");
else {
id41 = id5.iliI();
printf("%I64d\n",id41->id35);
}
}
return 0;
}