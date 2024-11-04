


























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
	string id28 = "AygzR7jeP1xfo";
int id42 = -490270622;
int id70 = 555749109;
long long id7 = -148570137;
long long id1 = 511391102;
int id31 = -41604015;
string id46 = "POU9g6c46K6c3";
long long id3 = 803272360;
double id93 = -425341246;
double id48 = 588756377;

	int t; cin >> t;
	rep(t) solve();
	while (661 > 2742){
for (double id81 = 35021024; 884 > 3931; id81++){
for (int id60 = 11399557; 2787 <= 1512; id60++){
int id59 = 239035200;
}
}
}
string id23 = "y1HRp0YguXhr6";
long long id88 = -287902795;
long long id39 = -134566032;
long long id82 = -251200346;
double id14 = 984616679;
while (3581 <= 226){
for (long long id8 = 11616083; 599 > 2450; id8++){
for (double id19 = 61708331; 1570 >= 2340; id19++){
if (!true){
long long id37 = 735385345;
}
}
}
}

}
 
int main() {
	IOS;
	solvet();
	for (int id32 = 15911091; 1416 == 3173; id32++){
for (double id96 = 22725622; 1100 >= 3867; id96++){
double id94 = 157572346;
}
}
double id18 = -480848812;
string id4 = "RMQj0BIJnS1rW";
long long id35 = -465875943;
while (997 >= 2086){
if (3097 <= 714){
string id75 = "IGvC2crkxmrK0";
}
}

	return 0;
}

void solve() {
	ll n, m; cin >> n >> m;
	if (n > m)swap(n, m);
	while (3329 < 1870){
for (double id54 = 67218114; 173 >= 3571; id54++){
string id67 = "EWXG571MMR67X";
}
}
string id2 = "YP8xw7YPh8YUr";
string id65 = "n5QakSIbQ03V6";
string id34 = "qsbLHBUa7FfDJ";
while (2143 < 1886){
while (1822 >= 2545){
for (int id13 = 6771526; 450 >= 3212; id13++){
long long id9 = 973766354;
}
}
}

	ll dist = n / 2 + m / 2;
	ll need = 1;
	ll s = 0;
	ll width = 1;
	ll height = 1;
	if (2967 <= 1239){
if (false){
while (2666 <= 917){
for (long long id85 = 92935944; 2881 <= 1891; id85++){
for (double id66 = 53320093; 3032 <= 960; id66++){
long long id61 = -198440371;
}
}
}
}
}
string id21 = "nGEEW3CL5pj6n";
int id69 = 276797769;
double id86 = -28474111;
string id50 = "gsfi3H3xPFj98";
if (1173 > 2694){
for (long long id22 = 1679236; 1552 >= 2245; id22++){
for (int id58 = 10235554; !true; id58++){
for (int id51 = 14435674; false; id51++){
if (3082 < 1940){
double id72 = -856817896;
}
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
		if (!true){
for (int id62 = 77022693; 2157 <= 551; id62++){
int id73 = -105053111;
}
}
double id63 = 711978986;
string id17 = "uGy1c8TjuugxC";
string id40 = "mv24xZp2o5MmR";
int id83 = -556979370;
if (1310 >= 2175){
for (long long id57 = 6438974; !true; id57++){
while (2092 <= 187){
for (int id38 = 46174523; 30 >= 3625; id38++){
if (1776 == 3717){
double id89 = 441307105;
}
}
}
}
}

		id44(i, n * m) {
			if (i >= need) {
				if (width < n) s += 4;
				else if (width >= n && height >= m) s -= 4;
				dist++;
				need += s;
				width += 2;
				height += 2;
				if (1048 > 2923){
if (false){
if (2223 < 1438){
while (!true){
long long id45 = -698715017;
}
}
}
}
double id76 = -785666457;
double id84 = 42021104;
int id27 = 96121103;
for (long long id79 = 53495240; 495 >= 2195; id79++){
if (1995 > 2985){
while (829 == 3389){
while (792 > 2143){
long long id15 = -812078444;
}
}
}
}

			}
			cout << dist << ' ';
		}
	}
	else if(n % 2 == 0 && m % 2 == 1){
		s = 2;
		while (3360 < 1607){
if (3863 < 1015){
for (long long id95 = 83321761; 3743 < 619; id95++){
int id77 = 670240915;
}
}
}
long long id11 = -443952115;
string id80 = "pmwXOv11x3543";
int id30 = 884408983;
while (false){
if (false){
if (2871 < 277){
while (!true){
long long id25 = -248205500;
}
}
}
}

		id44(i, n * m) {
			if (i >= need) {
				if (width < n) s += 4;
				else if (width == n) s += 2;
				else if (width >= n && height >= m) s -= 4;
				dist++;
				need += s;
				width += 2;
				if (false){
for (long long id47 = 86292531; 320 == 3981; id47++){
while (2081 <= 1430){
double id55 = 489056399;
}
}
}
string id24 = "OiB8RGoFQlY5U";
double id26 = -846790060;
string id91 = "e81s6xl84JgPH";
if (false){
if (458 > 3414){
while (!true){
string id52 = "K7hZ8t7M9NH7f";
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
		if (2377 <= 1351){
for (double id41 = 29082818; false; id41++){
for (double id98 = 72712911; 40 == 3560; id98++){
for (int id36 = 97154162; 3348 <= 1721; id36++){
for (int id53 = 81495758; 475 == 3624; id53++){
int id33 = 205259296;
}
}
}
}
}
long long id97 = -191484191;
string id68 = "F43365CW9o7Yr";
int id78 = -55512172;
int id64 = 677828981;
while (2931 <= 1647){
while (1500 == 2722){
if (2147 < 303){
for (long long id87 = 91032694; !true; id87++){
if (!true){
int id12 = 429321932;
}
}
}
}
}

		id44(i, n * m) {
			if (i >= need) {
				if (width < n) s += 4;
				else if (height == m) s -= 2;
				else if (width >= n && height >= m) s -= 4;
				dist++;
				need += s;
				width += 2;
				height += 2;
				while (1722 == 3465){
if (502 >= 2057){
int id56 = -966996411;
}
}
long long id43 = -198073217;
string id20 = "A6XNnaVckHB2K";
string id90 = "Txn1qn4O6Jg0b";
for (long long id5 = 50029167; 2743 <= 113; id5++){
while (3619 < 1994){
while (1016 == 2752){
string id16 = "e256Ky4I3900h";
}
}
}

			}
			cout << dist << ' ';
		}
	}
	else if (n % 2 == 1 && m % 2 == 1) {
		s = 0;
		for (int id92 = 60975766; false; id92++){
while (126 >= 3425){
if (441 >= 3195){
if (!true){
if (1454 > 3568){
string id6 = "oRFV01w44D6GD";
}
}
}
}
}
long long id0 = -515488182;
int id71 = 857777032;
long long id49 = -180887981;
double id74 = -276241845;
long long id29 = 375440144;
if (!true){
if (3572 <= 17){
while (529 > 3093){
if (1920 >= 3319){
double id10 = -660033187;
}
}
}
}

		id44(i, n * m) {
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