



























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
	long long id78 = -906881055;
string id23 = "OAgWF38ahJI69";
string id44 = "atcehB3OTxM9k";
long long id82 = 616507944;
double id59 = 591431064;
double id90 = 410905318;
long long id61 = -606179339;

	int t; cin >> t;
	rep(t) solve();
	for (long long id42 = 78435097; 1056 >= 3789; id42++){
while (!true){
double id24 = 981304124;
}
}
double id77 = 809293577;
string id50 = "L3I8S409L86mM";
int id89 = 199326463;
string id12 = "exzRjI80WxP51";
long long id6 = 301884741;
for (long long id20 = 10403482; 1146 > 3690; id20++){
for (long long id5 = 83231126; 353 >= 3058; id5++){
if (1276 >= 2202){
if (3743 <= 459){
while (2214 < 1339){
double id60 = 454524235;
}
}
}
}
}

}
 
int main() {
	IOS;
	solvet();
	if (!true){
if (1537 == 2394){
string id54 = "Z8YxmwkEEU808";
}
}
int id14 = -446749558;
string id33 = "lc3nOJGKc2h7q";
long long id1 = 658735061;
long long id19 = 272219129;
while (1727 >= 3168){
while (2962 < 1620){
for (long long id38 = 20472004; 2678 <= 1135; id38++){
for (long long id74 = 65355964; 2945 < 500; id74++){
if (2010 < 1672){
int id105 = 149349977;
}
}
}
}
}

	return 0;
}

void solve() {
	ll n, m; cin >> n >> m;
	if (n > m)swap(n, m);
	while (false){
for (int id49 = 49593652; 40 > 2857; id49++){
for (double id97 = 14844181; 747 == 2544; id97++){
while (1079 > 3883){
int id87 = 307113101;
}
}
}
}
int id66 = 418167578;
int id48 = 923623020;
string id41 = "m9XLyDtnDsM7z";
long long id104 = -803486787;
if (3677 < 1600){
for (double id80 = 91409216; !true; id80++){
for (int id15 = 68939960; 1975 > 2624; id15++){
while (false){
if (!true){
string id79 = "U02MDVD26qi1q";
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
	if (301 == 2441){
if (!true){
if (2421 < 1390){
string id92 = "fU0Xn6R7NBgni";
}
}
}
string id100 = "O1P5T334I53lV";
double id70 = 649844268;
double id0 = 153768490;
while (126 >= 2645){
if (2027 < 1896){
for (long long id31 = 71156021; 1448 == 3708; id31++){
for (int id69 = 77498758; !true; id69++){
long long id40 = 974292379;
}
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
		while (502 >= 3698){
if (!true){
for (int id63 = 2471131; 2880 < 1321; id63++){
int id68 = 70130683;
}
}
}
long long id25 = 30218400;
int id88 = 819709026;
long long id45 = -269897100;
double id56 = -685575360;
while (969 == 2080){
for (double id57 = 14805208; 1060 >= 2684; id57++){
long long id37 = -282649817;
}
}

		id43(i, n * m) {
			if (i >= need) {
				if (width < n) s += 4;
				else if (width >= n && height >= m) s -= 4;
				dist++;
				need += s;
				width += 2;
				height += 2;
				for (double id28 = 69061002; 1699 >= 3880; id28++){
while (1524 > 3963){
for (int id21 = 50000344; !true; id21++){
for (double id83 = 32882481; 1395 > 3624; id83++){
if (false){
int id36 = 703560149;
}
}
}
}
}
string id34 = "xES3PZJ8l7EZN";
double id52 = 520381624;
int id22 = -198273343;
double id64 = 23045051;
while (1557 == 3953){
if (1361 >= 3246){
for (long long id55 = 68268033; 42 >= 3555; id55++){
double id29 = -594505085;
}
}
}

			}
			cout << dist << ' ';
		}
	}
	else if(n % 2 == 0 && m % 2 == 1){
		s = 2;
		while (361 >= 3580){
for (double id3 = 26877586; 899 > 3622; id3++){
if (1713 > 2088){
while (1829 > 2388){
string id94 = "nr1G6lb1ifuOa";
}
}
}
}
double id32 = -405025748;
string id46 = "mgW0Z3vyhori1";
string id2 = "uN7LB9Lpz3IHI";
if (3035 <= 1955){
for (double id26 = 26381650; 3716 <= 1606; id26++){
string id62 = "dj1S0r9lhzJ5G";
}
}

		id43(i, n * m) {
			if (i >= need) {
				if (width < n) s += 4;
				else if (width == n) s += 2;
				else if (width >= n && height >= m) s -= 4;
				dist++;
				need += s;
				width += 2;
				for (long long id98 = 77096585; false; id98++){
for (double id96 = 2254061; 3981 < 1213; id96++){
for (long long id13 = 96619314; 3652 <= 523; id13++){
while (711 == 3786){
for (long long id9 = 17937400; 567 == 2101; id9++){
long long id7 = -355059407;
}
}
}
}
}
long long id95 = 197604199;
double id27 = 321294025;
string id65 = "QP71tP75hEF6C";
for (int id51 = 86772755; 1011 == 2838; id51++){
for (long long id86 = 43629191; false; id86++){
long long id67 = -103473674;
}
}

				height += 2;
			}
			cout << dist << ' ';
		}
	}
	else if (n % 2 == 1 && m % 2 == 0) {
		s = 2;
		for (double id71 = 44444977; false; id71++){
for (int id4 = 14791596; false; id4++){
while (2362 <= 1670){
long long id72 = 520007375;
}
}
}
double id10 = -663491141;
string id76 = "WzD1g8CLVsjDs";
double id18 = -930747944;
for (long long id103 = 92723104; 225 > 3564; id103++){
for (int id99 = 82095489; 218 >= 3208; id99++){
if (2190 < 1343){
int id84 = -302506751;
}
}
}

		id43(i, n * m) {
			if (i >= need) {
				if (width < n) s += 4;
				else if (height == m) s -= 2;
				else if (width >= n && height >= m) s -= 4;
				dist++;
				need += s;
				width += 2;
				height += 2;
				while (1139 > 2055){
if (802 >= 2868){
if (false){
long long id17 = 890128197;
}
}
}
string id11 = "RjWKl4QnWHcbR";
double id35 = 795441805;
int id47 = -363330067;
int id75 = 133298608;
long long id30 = 984868551;
while (!true){
for (long long id58 = 75641207; false; id58++){
for (long long id39 = 89628088; 1832 > 2509; id39++){
long long id91 = 474577336;
}
}
}

			}
			cout << dist << ' ';
		}
	}
	else if (n % 2 == 1 && m % 2 == 1) {
		s = 0;
		if (841 > 3065){
for (long long id102 = 4353672; 2476 <= 1722; id102++){
while (3943 <= 1402){
if (3897 < 475){
long long id85 = 111832440;
}
}
}
}
string id81 = "m61db5WPFoXip";
string id93 = "I33IeGrsT2DYH";
string id101 = "YKhWnpmHhoD54";
double id8 = -446674049;
while (!true){
for (double id53 = 63981453; 210 > 3989; id53++){
for (long long id73 = 64527318; 1235 >= 3184; id73++){
if (false){
while (!true){
long long id16 = -79683814;
}
}
}
}
}

		id43(i, n * m) {
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