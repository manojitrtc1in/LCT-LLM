
using namespace std;




constexpr int NCBUF = 1 << 21;


using ll=long long;using ull=unsigned long long;using PI=pair<int,int>;using PL=pair<ll,ll>;using PIL=pair<int,ll>;using PLI=pair<ll,int>;inline char nc()
{static char b[NCBUF],*x=b,*y=b;return x==y&&(y=(x=b)+fread(b,1,NCBUF,stdin),x==y)?EOF:*x++;}template<class T>inline bool input(T&x){x=0;char c=nc();bool
f=0;while(c<'0'||c>'9'){if(c==EOF)return 0;f=c=='-',c=nc();}while(c>='0'&&c<='9')x=x*10+(c^48),c=nc();if(f)x=-x;return 1;}template<>inline bool input(char
&x){for(;;){x=nc();if(x==EOF)return 0;if(!isspace(x))return 1;}}template<class T,class...S>inline bool input(T&x,S&...y){return input(x)&&input(y...);}inline
bool readstr(char*p){if(!input(*p))return 0;do*++p=nc();while(!(*p==EOF||isspace(*p)));*p=0;return 1;}inline void output(const char*p){while(*p!=0)putchar(*p++);}
inline void output(int x){printf("%d",x);}inline void output(ll x){printf("%lld",x);}inline void output(double x){printf("%.10f",x);}inline void output(char x)
{putchar(x);}template<class...T>inline void print(T...y){bool f=0;(((f?putchar(' '):f=1),output(y)),...);}template<class...T>inline void println(T...y){print(y...)
,putchar('\n');}template<class T,class U>inline void chkmin(T&a,U b){if(a>b)a=b;}template<class T,class U>inline void chkmax(T&a,U b){if(a<b)a=b;}




constexpr ll MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;



const string s[]{
    "a",
    "aabb",
    "aabacbbcc",
    "aabacadbbcbdccdd",
    "aabacadaebbcbdbeccdceddee",
    "aabacadaeafbbcbdbebfccdcecfddedfeeff",
    "aabacadaeafagbbcbdbebfbgccdcecfcgddedfdgeefegffgg",
    "aabacadaeafagahbbcbdbebfbgbhccdcecfcgchddedfdgdheefegehffgfhgghh",
    "aabacadaeafagahaibbcbdbebfbgbhbiccdcecfcgchciddedfdgdhdieefegeheiffgfhfigghgihhii",
    "aabacadaeafagahaiajbbcbdbebfbgbhbibjccdcecfcgchcicjddedfdgdhdidjeefegeheiejffgfhfifjgghgigjhhihjiijj",
    "aabacadaeafagahaiajakbbcbdbebfbgbhbibjbkccdcecfcgchcicjckddedfdgdhdidjdkeefegeheiejekffgfhfifjfkgghgigjgkhhihjhkiijikjjkk",
    "aabacadaeafagahaiajakalbbcbdbebfbgbhbibjbkblccdcecfcgchcicjckclddedfdgdhdidjdkdleefegeheiejekelffgfhfifjfkflgghgigjgkglhhihjhkhliijikiljjkjlkkll",
    "aabacadaeafagahaiajakalambbcbdbebfbgbhbibjbkblbmccdcecfcgchcicjckclcmddedfdgdhdidjdkdldmeefegeheiejekelemffgfhfifjfkflfmgghgigjgkglgmhhihjhkhlhmiijikilimjjkjljmkklkmllmm",
    "aabacadaeafagahaiajakalamanbbcbdbebfbgbhbibjbkblbmbnccdcecfcgchcicjckclcmcnddedfdgdhdidjdkdldmdneefegeheiejekelemenffgfhfifjfkflfmfngghgigjgkglgmgnhhihjhkhlhmhniijikiliminjjkjljmjnkklkmknllmlnmmnn",
    "aabacadaeafagahaiajakalamanaobbcbdbebfbgbhbibjbkblbmbnboccdcecfcgchcicjckclcmcncoddedfdgdhdidjdkdldmdndoeefegeheiejekelemeneoffgfhfifjfkflfmfnfogghgigjgkglgmgngohhihjhkhlhmhnhoiijikiliminiojjkjljmjnjokklkmknkollmlnlommnmonnoo",
    "aabacadaeafagahaiajakalamanaoapbbcbdbebfbgbhbibjbkblbmbnbobpccdcecfcgchcicjckclcmcncocpddedfdgdhdidjdkdldmdndodpeefegeheiejekelemeneoepffgfhfifjfkflfmfnfofpgghgigjgkglgmgngogphhihjhkhlhmhnhohpiijikiliminioipjjkjljmjnjojpkklkmknkokpllmlnlolpmmnmompnnonpoopp",
    "aabacadaeafagahaiajakalamanaoapaqbbcbdbebfbgbhbibjbkblbmbnbobpbqccdcecfcgchcicjckclcmcncocpcqddedfdgdhdidjdkdldmdndodpdqeefegeheiejekelemeneoepeqffgfhfifjfkflfmfnfofpfqgghgigjgkglgmgngogpgqhhihjhkhlhmhnhohphqiijikiliminioipiqjjkjljmjnjojpjqkklkmknkokpkqllmlnlolplqmmnmompmqnnonpnqoopoqppqq",
    "aabacadaeafagahaiajakalamanaoapaqarbbcbdbebfbgbhbibjbkblbmbnbobpbqbrccdcecfcgchcicjckclcmcncocpcqcrddedfdgdhdidjdkdldmdndodpdqdreefegeheiejekelemeneoepeqerffgfhfifjfkflfmfnfofpfqfrgghgigjgkglgmgngogpgqgrhhihjhkhlhmhnhohphqhriijikiliminioipiqirjjkjljmjnjojpjqjrkklkmknkokpkqkrllmlnlolplqlrmmnmompmqmrnnonpnqnroopoqorppqprqqrr",
    "aabacadaeafagahaiajakalamanaoapaqarasbbcbdbebfbgbhbibjbkblbmbnbobpbqbrbsccdcecfcgchcicjckclcmcncocpcqcrcsddedfdgdhdidjdkdldmdndodpdqdrdseefegeheiejekelemeneoepeqeresffgfhfifjfkflfmfnfofpfqfrfsgghgigjgkglgmgngogpgqgrgshhihjhkhlhmhnhohphqhrhsiijikiliminioipiqirisjjkjljmjnjojpjqjrjskklkmknkokpkqkrksllmlnlolplqlrlsmmnmompmqmrmsnnonpnqnrnsoopoqorosppqprpsqqrqsrrss",
    "aabacadaeafagahaiajakalamanaoapaqarasatbbcbdbebfbgbhbibjbkblbmbnbobpbqbrbsbtccdcecfcgchcicjckclcmcncocpcqcrcsctddedfdgdhdidjdkdldmdndodpdqdrdsdteefegeheiejekelemeneoepeqeresetffgfhfifjfkflfmfnfofpfqfrfsftgghgigjgkglgmgngogpgqgrgsgthhihjhkhlhmhnhohphqhrhshtiijikiliminioipiqirisitjjkjljmjnjojpjqjrjsjtkklkmknkokpkqkrksktllmlnlolplqlrlsltmmnmompmqmrmsmtnnonpnqnrnsntoopoqorosotppqprpsptqqrqsqtrrsrtsstt",
    "aabacadaeafagahaiajakalamanaoapaqarasataubbcbdbebfbgbhbibjbkblbmbnbobpbqbrbsbtbuccdcecfcgchcicjckclcmcncocpcqcrcsctcuddedfdgdhdidjdkdldmdndodpdqdrdsdtdueefegeheiejekelemeneoepeqereseteuffgfhfifjfkflfmfnfofpfqfrfsftfugghgigjgkglgmgngogpgqgrgsgtguhhihjhkhlhmhnhohphqhrhshthuiijikiliminioipiqirisitiujjkjljmjnjojpjqjrjsjtjukklkmknkokpkqkrksktkullmlnlolplqlrlsltlummnmompmqmrmsmtmunnonpnqnrnsntnuoopoqorosotouppqprpsptpuqqrqsqtqurrsrtrusstsuttuu",
    "aabacadaeafagahaiajakalamanaoapaqarasatauavbbcbdbebfbgbhbibjbkblbmbnbobpbqbrbsbtbubvccdcecfcgchcicjckclcmcncocpcqcrcsctcucvddedfdgdhdidjdkdldmdndodpdqdrdsdtdudveefegeheiejekelemeneoepeqereseteuevffgfhfifjfkflfmfnfofpfqfrfsftfufvgghgigjgkglgmgngogpgqgrgsgtgugvhhihjhkhlhmhnhohphqhrhshthuhviijikiliminioipiqirisitiuivjjkjljmjnjojpjqjrjsjtjujvkklkmknkokpkqkrksktkukvllmlnlolplqlrlsltlulvmmnmompmqmrmsmtmumvnnonpnqnrnsntnunvoopoqorosotouovppqprpsptpupvqqrqsqtquqvrrsrtrurvsstsusvttutvuuvv",
    "aabacadaeafagahaiajakalamanaoapaqarasatauavawbbcbdbebfbgbhbibjbkblbmbnbobpbqbrbsbtbubvbwccdcecfcgchcicjckclcmcncocpcqcrcsctcucvcwddedfdgdhdidjdkdldmdndodpdqdrdsdtdudvdweefegeheiejekelemeneoepeqereseteuevewffgfhfifjfkflfmfnfofpfqfrfsftfufvfwgghgigjgkglgmgngogpgqgrgsgtgugvgwhhihjhkhlhmhnhohphqhrhshthuhvhwiijikiliminioipiqirisitiuiviwjjkjljmjnjojpjqjrjsjtjujvjwkklkmknkokpkqkrksktkukvkwllmlnlolplqlrlsltlulvlwmmnmompmqmrmsmtmumvmwnnonpnqnrnsntnunvnwoopoqorosotouovowppqprpsptpupvpwqqrqsqtquqvqwrrsrtrurvrwsstsusvswttutvtwuuvuwvvww",
    "aabacadaeafagahaiajakalamanaoapaqarasatauavawaxbbcbdbebfbgbhbibjbkblbmbnbobpbqbrbsbtbubvbwbxccdcecfcgchcicjckclcmcncocpcqcrcsctcucvcwcxddedfdgdhdidjdkdldmdndodpdqdrdsdtdudvdwdxeefegeheiejekelemeneoepeqereseteuevewexffgfhfifjfkflfmfnfofpfqfrfsftfufvfwfxgghgigjgkglgmgngogpgqgrgsgtgugvgwgxhhihjhkhlhmhnhohphqhrhshthuhvhwhxiijikiliminioipiqirisitiuiviwixjjkjljmjnjojpjqjrjsjtjujvjwjxkklkmknkokpkqkrksktkukvkwkxllmlnlolplqlrlsltlulvlwlxmmnmompmqmrmsmtmumvmwmxnnonpnqnrnsntnunvnwnxoopoqorosotouovowoxppqprpsptpupvpwpxqqrqsqtquqvqwqxrrsrtrurvrwrxsstsusvswsxttutvtwtxuuvuwuxvvwvxwwxx",
    "aabacadaeafagahaiajakalamanaoapaqarasatauavawaxaybbcbdbebfbgbhbibjbkblbmbnbobpbqbrbsbtbubvbwbxbyccdcecfcgchcicjckclcmcncocpcqcrcsctcucvcwcxcyddedfdgdhdidjdkdldmdndodpdqdrdsdtdudvdwdxdyeefegeheiejekelemeneoepeqereseteuevewexeyffgfhfifjfkflfmfnfofpfqfrfsftfufvfwfxfygghgigjgkglgmgngogpgqgrgsgtgugvgwgxgyhhihjhkhlhmhnhohphqhrhshthuhvhwhxhyiijikiliminioipiqirisitiuiviwixiyjjkjljmjnjojpjqjrjsjtjujvjwjxjykklkmknkokpkqkrksktkukvkwkxkyllmlnlolplqlrlsltlulvlwlxlymmnmompmqmrmsmtmumvmwmxmynnonpnqnrnsntnunvnwnxnyoopoqorosotouovowoxoyppqprpsptpupvpwpxpyqqrqsqtquqvqwqxqyrrsrtrurvrwrxrysstsusvswsxsyttutvtwtxtyuuvuwuxuyvvwvxvywwxwyxxyy",
    "aabacadaeafagahaiajakalamanaoapaqarasatauavawaxayazbbcbdbebfbgbhbibjbkblbmbnbobpbqbrbsbtbubvbwbxbybzccdcecfcgchcicjckclcmcncocpcqcrcsctcucvcwcxcyczddedfdgdhdidjdkdldmdndodpdqdrdsdtdudvdwdxdydzeefegeheiejekelemeneoepeqereseteuevewexeyezffgfhfifjfkflfmfnfofpfqfrfsftfufvfwfxfyfzgghgigjgkglgmgngogpgqgrgsgtgugvgwgxgygzhhihjhkhlhmhnhohphqhrhshthuhvhwhxhyhziijikiliminioipiqirisitiuiviwixiyizjjkjljmjnjojpjqjrjsjtjujvjwjxjyjzkklkmknkokpkqkrksktkukvkwkxkykzllmlnlolplqlrlsltlulvlwlxlylzmmnmompmqmrmsmtmumvmwmxmymznnonpnqnrnsntnunvnwnxnynzoopoqorosotouovowoxoyozppqprpsptpupvpwpxpypzqqrqsqtquqvqwqxqyqzrrsrtrurvrwrxryrzsstsusvswsxsyszttutvtwtxtytzuuvuwuxuyuzvvwvxvyvzwwxwywzxxyxzyyzz",
};


int N, K;
void solve() {
    cin >> N >> K;
    auto& t = s[K - 1];
    while (N >= t.size()) {
        N -= t.size();
        cout << t;
    }
    rep(i, 0, N) cout << t[i];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}
			  								 			 			  		 	 	