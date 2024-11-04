


























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
	int id52 = -604254594;
double id44 = -373188844;
double id67 = 549881768;
int id7 = -658923777;
int id8 = -856099342;
double id60 = 195536366;
int id73 = 94602210;
long long id58 = -148890286;
int id53 = 245853830;
long long id50 = 355227885;

	int t; cin >> t;
	rep(t) solve();
	while (2663 < 309){
if (!true){
double id28 = 416418425;
}
}
double id65 = 801274046;
double id80 = 461615086;
double id51 = 166058858;
double id93 = 67591808;
while (2954 < 1214){
while (1036 > 2526){
string id27 = "pnJPAwCtp15Oq";
}
}

}
 
int main() {
	IOS;
	solvet();
	if (false){
while (1399 > 3171){
while (!true){
while (522 > 3718){
string id61 = "xc38FX73hVr93";
}
}
}
}
double id41 = 940368022;
string id64 = "e3RJ27cWS8F47";
long long id76 = 130360202;
int id78 = -198775610;
if (2034 <= 1128){
while (1455 >= 3289){
while (!true){
double id16 = 167681425;
}
}
}

	return 0;
}

void solve() {
	ll n, m; cin >> n >> m;
	if (n > m)swap(n, m);
	for (long long id43 = 7278652; 570 > 2767; id43++){
while (843 == 2958){
for (int id90 = 63606657; 782 > 2242; id90++){
while (2441 <= 1533){
for (long long id20 = 22111508; 324 > 3647; id20++){
double id54 = -382503130;
}
}
}
}
}
int id29 = 443793316;
int id24 = 871367676;
string id10 = "igekU5oXf9OJr";
string id0 = "lqPQ6HuXYRaZj";
while (1576 >= 2294){
while (858 > 3927){
for (double id33 = 72157590; 2213 < 293; id33++){
if (false){
if (600 > 3242){
long long id45 = 574111867;
}
}
}
}
}

	ll dist = n / 2 + m / 2;
	ll need = 1;
	ll s = 0;
	ll width = 1;
	ll height = 1;
	while (!true){
if (1956 == 3436){
if (2150 < 1799){
if (1425 == 2756){
double id9 = -125407909;
}
}
}
}
int id34 = -499998558;
long long id13 = -654349674;
string id69 = "NBT34052YlLOT";
int id22 = 388396838;
if (2758 < 222){
for (long long id14 = 3749882; 524 == 2799; id14++){
while (2264 < 1581){
int id40 = 644866976;
}
}
}

	if (n % 2 == 0) {
		need *= 2;
		width *= 2;
	}
	if (m % 2 == 0) {
		need *= 2;
		height *= 2;
	}
	if (n % 2 == 0 && m % 2 == 0) {
		s = 4;
		while (false){
while (1842 == 3891){
while (false){
long long id47 = -828820058;
}
}
}
int id79 = 373753743;
long long id89 = -645841409;
double id71 = 840872525;
string id38 = "N8YEJaGO8bB7m";
while (1911 == 3236){
for (int id12 = 32075697; 3874 < 1770; id12++){
while (3055 <= 1115){
int id70 = -83339121;
}
}
}

		id39(i, n * m) {
			if (i >= need) {
				if (width < n) s += 4;
				else if (width >= n && height >= m) s -= 4;
				dist++;
				need += s;
				width += 2;
				height += 2;
				if (1022 > 3027){
if (3995 <= 129){
if (false){
while (1267 > 2362){
string id57 = "K0nX9MNMcjHnu";
}
}
}
}
double id72 = 580761843;
long long id87 = 917186797;
double id30 = -864262699;
int id66 = -979709743;
for (double id26 = 78279749; false; id26++){
for (int id59 = 22320979; 1888 == 3417; id59++){
long long id37 = -286619273;
}
}

			}
			cout << dist << ' ';
		}
	}
	else if(n % 2 == 0 && m % 2 == 1){
		s = 2;
		for (double id84 = 9037307; !true; id84++){
for (long long id35 = 65142347; !true; id35++){
string id23 = "tpxUbFHmZ9cTN";
}
}
int id55 = 558590676;
double id91 = -339766696;
string id5 = "PM1HMUmNmf0q7";
while (619 == 3138){
while (!true){
for (long long id85 = 23884473; false; id85++){
for (long long id82 = 13136569; 3205 < 1811; id82++){
string id11 = "vyQ4dy0F7KzPf";
}
}
}
}

		id39(i, n * m) {
			if (i >= need) {
				if (width < n) s += 4;
				else if (width == n) s += 2;
				else if (width >= n && height >= m) s -= 4;
				dist++;
				need += s;
				width += 2;
				while (3064 < 316){
for (long long id25 = 28339059; 2650 <= 1708; id25++){
int id48 = -193184112;
}
}
string id63 = "QT1QiwiGg1Ljs";
string id83 = "VLh2ukG7iJxb4";
int id88 = -296600179;
double id2 = -962706091;
string id18 = "DexN385h7QU6M";
if (1186 >= 2380){
if (1237 == 3105){
if (1673 > 3870){
while (false){
for (int id46 = 52630412; 154 == 3742; id46++){
int id1 = -463788551;
}
}
}
}
}

				height += 2;
			}
			cout << dist << ' ';
		}
	}
	else if (n % 2 == 1 && m % 2 == 0) {
		s = 2;
		while (!true){
if (2312 <= 1383){
string id36 = "E5HI25K67yE7X";
}
}
double id3 = 773575749;
long long id62 = 389083935;
long long id15 = 806947475;
while (1399 == 3067){
if (2655 < 787){
if (2998 <= 189){
for (long long id56 = 45161838; 1183 >= 3067; id56++){
while (2642 < 1631){
int id42 = -948149600;
}
}
}
}
}

		id39(i, n * m) {
			if (i >= need) {
				if (width < n) s += 4;
				else if (height == m) s -= 2;
				else if (width >= n && height >= m) s -= 4;
				dist++;
				need += s;
				width += 2;
				height += 2;
				if (false){
if (2982 < 77){
while (688 == 2605){
if (!true){
if (false){
int id75 = 859528310;
}
}
}
}
}
string id21 = "wV9757laz1y4A";
double id81 = 111906494;
double id92 = 667935533;
for (long long id68 = 93431875; 2013 <= 204; id68++){
for (int id31 = 54695850; 477 > 2925; id31++){
if (3747 < 873){
for (int id77 = 96844853; !true; id77++){
double id86 = 663159750;
}
}
}
}

			}
			cout << dist << ' ';
		}
	}
	else if (n % 2 == 1 && m % 2 == 1) {
		s = 0;
		while (3280 < 323){
for (double id32 = 80576985; 1848 > 3930; id32++){
while (false){
while (789 == 3312){
if (false){
double id4 = 449814779;
}
}
}
}
}
string id94 = "V9XM26ozF932a";
double id17 = 932705820;
double id49 = 750316535;
string id6 = "GB36MWCqUpnnj";
if (false){
for (double id74 = 59232025; 1994 == 2152; id74++){
double id19 = 679699388;
}
}

		id39(i, n * m) {
			if (i >= need) {
				if (width < n) s += 4;
				else if (width == n && height == m) s += 0;
				else if (width == n) s += 2;
				else if (height == m) s -= 2;
				else if (width > n && height > m) s -= 4;
				dist++;
				need += s;
				width += 2;
				height += 2;
			}
			cout << dist << ' ';
		}
	}
	cout << endl;
}