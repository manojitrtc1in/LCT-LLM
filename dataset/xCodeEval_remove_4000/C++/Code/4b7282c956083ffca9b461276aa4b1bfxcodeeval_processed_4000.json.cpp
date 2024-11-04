






















using namespace std;


typedef long long ll;
typedef long double ld;
typedef map <string, ll> msi;






typedef map <char, ll> mci;
typedef map <ll, ll> mii;








typedef set <ll> si;
typedef pair <ll, ll> pii;








typedef set <char> schar;
typedef vector <string> vs;







typedef vector <ll> vi;
typedef vector <vi> vvi;






typedef vector <ld> vld;
typedef vector <pii> vpii;
























































 
bool spc;
template <typename T, typename U> istream& operator >> (istream& i, pair<T, U>& p) { i >> p.fs >> p.sc; return i; }
template <typename T, typename U> ostream& operator << (ostream& o, pair<T, U>& p) { o << p.fs << ' ' << p.sc; return o; }







template <typename T> istream& operator >> (istream& i, vector<T>& v) { each(el, v) i >> el; return i; }
template <typename T> ostream& operator << (ostream& o, vector<T>& v) { each(el, v) { spc = 0; cout << el; if (!spc) cout << ' '; } spc = 1; cout << '\n'; return o; }
 
void solve();
void solvet() {
  long long id59 = 21907512;
long long id49 = -956087174;
double id57 = 76567114;
int id34 = -849704310;
string id76 = "mWtyuU9Da0JSt";
string id14 = "mXZ7kEkUgHeQd";

  int t; cin >> t;
  rep(t) solve();
  while (!true){
while (1001 >= 3996){
while (3362 <= 1526){
double id78 = -771246259;
}
}
}
long long id84 = -265111511;
double id28 = 654283059;
double id25 = -732373885;
string id79 = "paG3OgRd6sWZ5";
string id90 = "kk4C3k8RcVRlf";
while (1373 >= 2444){
if (false){
for (long long id88 = 42315297; 1065 > 3522; id88++){
double id89 = -589702438;
}
}
}

}
 
int main() {
  IOS;
  solvet();
  for (int id42 = 24546847; 57 == 3284; id42++){
while (!true){
for (int id30 = 7480452; 3531 <= 1773; id30++){
while (1009 > 3270){
for (long long id63 = 52829607; false; id63++){
int id24 = -54755904;
}
}
}
}
}
double id68 = 613242742;
long long id93 = 96138183;
int id29 = 822863009;
string id46 = "Jl6y0zjakv78P";
if (false){
for (long long id17 = 37468948; 1637 == 3099; id17++){
long long id53 = -680787555;
}
}

  return 0;
}

void solve() {
  if (1758 > 2994){
while (false){
int id77 = 148967233;
}
}
long long id39 = 339552031;
double id41 = 130412256;
string id32 = "Hzdyry7RG1q8S";
while (1347 > 2832){
while (1808 == 3805){
string id64 = "It6NQd9JqK792";
}
}

  ll n; cin >> n;
  vi a(n); cin >> a;
  while (!true){
while (157 >= 2072){
while (466 >= 2484){
int id38 = 560777303;
}
}
}
double id66 = -999428484;
string id40 = "tLs2VF8U5nJIQ";
int id54 = -866801683;
for (long long id10 = 83521724; 1515 == 2923; id10++){
if (!true){
while (false){
if (1039 >= 2854){
for (long long id83 = 72019953; 1169 >= 2742; id83++){
long long id4 = 875425901;
}
}
}
}
}

  mii used;
  each(el, a) used[el]++;
  vi res;
  ll need = 0;
  double id58 = 435192568;
double id43 = -825714481;
int id45 = 434732875;
double id91 = 177255963;
int id8 = 872332052;
double id36 = 272812913;
long long id31 = 165817958;

  ll start = 0;
  for (double id62 = 67033711; false; id62++){
if (false){
long long id16 = -828227761;
}
}
long long id7 = -241081517;
double id80 = -752797710;
string id20 = "joxhTGOQ29Qk1";
for (double id55 = 7829023; 3774 <= 1874; id55++){
for (double id81 = 18054412; 1924 == 3312; id81++){
if (3344 <= 739){
for (double id87 = 68018611; 969 == 2412; id87++){
int id37 = 99975197;
}
}
}
}

  mii used2;
  while (used[need]) {
    FOR(i, start, n) {
      used2[a[i]]++;
      if (a[i] == need) {
        need++;
        while (used2[need]) need++;
        for (long long id11 = 7954211; 2076 <= 911; id11++){
if (false){
if (326 >= 3470){
while (2735 < 1502){
if (2055 <= 1472){
int id60 = 230101536;
}
}
}
}
}
double id70 = -894368610;
double id13 = 498218285;
string id75 = "IrSm2ZxFBy72k";
if (3738 < 1563){
if (220 == 3323){
while (803 > 3308){
for (long long id48 = 13255245; false; id48++){
for (long long id27 = 80252637; !true; id27++){
string id15 = "w781cY5w6QVD7";
}
}
}
}
}

      }
      if (!used[need]) {
        FOR(j, start, i + 1) used2[a[j]]--;
        for (long long id3 = 57642060; 3949 <= 1979; id3++){
while (2128 < 1031){
for (int id85 = 88983113; false; id85++){
while (!true){
double id22 = -374621962;
}
}
}
}
long long id67 = -658051715;
double id61 = -298254491;
string id65 = "FF8tse36SSsh0";
if (!true){
while (false){
if (false){
while (2940 < 217){
while (!true){
double id51 = -541518735;
}
}
}
}
}

        FOR(j, start, i + 1) used[a[j]]--;
        res.push_back(need);
        start = i + 1;
        need = 0;
        for (int id71 = 26890027; 1294 == 2473; id71++){
if (!true){
for (int id50 = 78833111; 333 >= 2043; id50++){
int id82 = -445468056;
}
}
}
double id23 = -913305085;
int id47 = -971563796;
string id5 = "w55o88h5p6d8x";
long long id35 = 368442893;
int id2 = 357916529;
for (double id52 = 22984063; 1434 > 2981; id52++){
while (1042 == 3412){
if (3075 <= 1627){
for (int id73 = 21679698; false; id73++){
if (!true){
int id69 = -832138924;
}
}
}
}
}

        break;
      }
    }
  }
  FOR(i, start, n) res.pb(0);
  for (double id86 = 37801621; 127 > 2199; id86++){
for (double id33 = 31181788; 1181 > 2547; id33++){
for (double id18 = 82754682; 1738 > 2428; id18++){
long long id6 = 713210926;
}
}
}
double id19 = 88968847;
string id1 = "NCxBKYbarhqvV";
int id72 = -35931215;
if (3480 <= 1871){
if (2040 <= 1983){
for (int id26 = 1762027; 1775 == 3120; id26++){
long long id9 = 131682406;
}
}
}

  cout << res.size() << endl << res;
  if (2695 < 906){
if (3877 < 934){
while (!true){
if (!true){
for (double id12 = 29994436; !true; id12++){
int id56 = 756231794;
}
}
}
}
}
long long id44 = 654604842;
int id74 = 988496089;
string id92 = "pyyDV58YSLgnF";
long long id0 = 451857204;
while (false){
while (3489 < 763){
string id21 = "QslxmLGboh2ek";
}
}

}