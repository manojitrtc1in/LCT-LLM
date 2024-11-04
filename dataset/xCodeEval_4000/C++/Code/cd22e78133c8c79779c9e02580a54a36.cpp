#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
#include <stdio.h>
#define ull unsigned long long
#define si short int
#define ll long long int
#define ld long double
#define pb push_back
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define piii pair<pair<int, int>, int>
#define all(vec) vec.begin(), vec.end()
#define piiii pair<pair<int, int>, pair<int, int>>
#define fr(a, from, c) for(int a=(from); (a)<(c); (a)++)
#define RslzCxSlnNfBMHZkuTPoauRZ 

#define pMhWJbrNBIYgrxoqzNGbZdPkJ using namespace std;
#define ECyBdJBYljVjZNnDDibsfVTa 
#define JeaQfpQdsqvHxdduKYSn 
#define ZntnoKRbHYkxgTmrsTrnbFydrhfDm 
#define opuQUJefPyuzgMwtHIbFDGPWZy mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define TfSgnSswSbxpGHrAKhyKFpPglXCP 
#define ShkWYbFpzxmAIFvJbyVlwgJ inline ll gcd(ll a, ll b) {
#define dfHpDcsUymOoxBiSNiBDFdxoi while (b) {
#define FGSQBQOJsvWmvTwYxhvilDOL a %= b;
#define mixMzWFhnlrQgHrDKxYuimjFNgZv swap(a, b);
#define LdukguquHrlxAioaAOpNvjdrItSP }
#define YxaQAhIIUCtQrvxSmCyGdiqs return a;
#define qtYfZjIRvaqSmIlHPTwtRaeCyTgfR }
#define znlDBWHruTebajxhggJIHhegvEtnB inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
#define rbcJdbeFpsFHrcRKfgbNmdkIYkb inline ll pwm(ll xx, ll pow, ll MD) {
#define sjTewhARfWXxARHWmAojulIyZIJ if (pow < 0) { pow = pow % (MD - 1) + MD - 1; }
#define omKDpXAOBZeITmEZPoHpdWwI ll mlt = 1;
#define CVYzcnTbsHjoavyrMJydTGERMcJAs while (pow) {
#define GXJkwscxieVrDdofuhHN if (pow & 1) {
#define zajpzkiyJTciAPJmHqWgHiNj mlt *= xx;
#define WheYBFTMFSwyBrMwNRKIIqvzfKiPf mlt %= MD;
#define kSTBTMwyKkSQzZroPvCQSfqjl }
#define ICCPlgOMhcDZmvhsBPQXdry xx *= xx;
#define hqzyEDwltPMMiVafMDApHqfvHgf pow >>= 1;
#define XNiCCrsChdjfmrWAJqVILEgh xx %= MD;
#define HLzOFUSoRRZvkJEvOaaBqan }
#define GVEeURODOSSMtFLgbJkEyHrhm return mlt;
#define esOFmlCuRqiqlYbjGxPjXp }
#define SEXPVpsOMjclsCuHARZhNcpenOoSf inline ll gcdex(ll a, ll b, ll &x, ll &y) {
#define yrKWPanSiPWPUGiHcCAxFg if (b == 0) {
#define qNYXyUdrJUbxEZXZlpxKeRaFJvt x = 1;
#define wGLLLSvNfLVFtqfABPwf y = 0;
#define VuoyKZfHRvuemRwygearr return a;
#define XotuAppbJJPtFEWZeOTQNaXYGsV }
#define FnBMialQVbokDZVchRXvbTEXaFEW ll xx, yy;
#define NtncdPLIsWggZxGqqusd ll gc = gcdex(b, a % b, yy, xx);
#define RwlyRkcdFIPGFxiGPrSLZvnPk x = xx;
#define TcrPrLWoktLIcISoXeQNPvjbVI y = yy - (a / b) * xx;
#define ZcEbUzIAmURjAXGScaJFjKvdqdj return gc;
#define LotyizukmqUmezvmDeicIE }
#define jgblwlIqNDyxvYIDveZLVwOAJ inline int inv(ll r, int _mod) { return pwm(r % _mod, _mod - 2, _mod); }
#define hxAHPPDpDLEOsPVHgQsVH inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
#define yjqaoBKgcfPctIMeUhGRon if (pow == 0) {
#define lktDaYYmbbIVaueOAMnXAE return 0;
#define ltmkQqdCAYdxaEBstQgb }
#define SpMsfahhStYCRfMupigquapetI int hpow = 1 << (pow - 1);
#define QnbMfnokrblnbmznXiyzMpvY int seg = (x < hpow) ? (
#define TGzXNshefsROvWklFrcKON (y < hpow) ? 0 : 3
#define HSWQHLAmSWEDbEqpIRJmx ) : (
#define fmgIwmznEETYBWhwRHmRqXLK (y < hpow) ? 1 : 2
#define AFkxWXOUkIGxsVwjfgzsS );
#define mUNNJKODAvRFDyYlHdSj seg = (seg + rotate) & 3;
#define TRTiwfNdJdLmlyqxnvmunfJV const int rotateDelta[4] = {3, 0, 0, 1};
#define NLdnQCCCiLnWRIcfCjwdf int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
#define uNJkGsyFvpRsrOwztEdM int nrot = (rotate + rotateDelta[seg]) & 3;
#define FcmNkhKkCcRBThStYmvLHK int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
#define iaowTcvGbcbgOxXdokbAWTxG int64_t ans = seg * subSquareSize;
#define VRayaYVeKsdpszKIpjUOwKTIqit int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
#define qsXIxrrlDafHYSbGcyCkkiopb ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
#define dZrUArmEhPBFIaioGJUnQMqfDjDs return ans;
#define YOUdZsHQJDDhBEueIqVzve }
#define ViBcfcrHKhTbFSNtApDpL 
#define hnUDDyzvEuHonMDgbgSe struct tup{
#define lMrsNsAwGRvvKFTIZxODtSahAD int predper,per;
#define LiIIuuQdVwFvfJxMGmIkVtuAGaxXT };
#define cEzbVjnLYFPpebztTxLVRcoxjwvu int grandi[1000][3];
#define lBCtfNYAwcUsNMfJNpBpblNNxwc tup per[6][6][6];
#define czgEBXyBvcyihBVujKowtOmVzdf vector<ll> arr;
#define OxmEwefBNylIdZJxHLLhRRrfEMX int x,y,z;
#define omvSAXjfWebBjEsILvZOzBPsR int mex(vector<int> kek){
#define oxrikbBqYlcYOdkZUqMou for(int i=0;i<=4;i++){
#define HbqoSdXxNuqQFjaAhrCQxKF bool ok=false;
#define bhFpveyGiqLVJazseXpQySfqJiyOr for(int son:kek){
#define qFEQYYeRVwUIVNjxsITysZN if(son==i) ok=true;
#define xcjHBWyXvKaioacGKgmNvD }
#define ARUKNcCsgnPNJvFDynovNMQhwI if(!ok) return i;
#define lBxWDcUOTJVGOpZjfpKTV }
#define LyysbebfbvOFosMjibeQzvy }
#define rBbflXEMtfWIagaEFmgqWOR void precalc(){
#define NwMBFlVBNGjaovpjGUPuznwQkC for(x=1;x<6;x++){
#define eZNAfpcQYFKQdVrfaHOvVKy for(y=1;y<6;y++){
#define SodBFgKSUMAbMRUjCnmEbHVC for(z=1;z<6;z++){
#define gIYaeErblROdmQocgPCGwK for(int i=1;i<1000;i++){
#define ktKdhfYFsaGkExdydsBIytEunK grandi[i][0]=mex({grandi[max(i-x, 0)][0], grandi[max(i-y, 0)][1], grandi[max(i-z, 0)][2]});
#define vcdmayzledJKCfIgznscUd grandi[i][1]=mex({grandi[max(i-x, 0)][0], grandi[max(i-z, 0)][2]});
#define UeLsLCtsMNQOhZBhArHmDdQEBpplR grandi[i][2]=mex({grandi[max(i-x, 0)][0], grandi[max(i-y, 0)][1]});
#define gyxmxRTmwEnzFNUrksFsC }
#define dLLlkpLsryLxuVohwamHJnLPrkT for(int i=0;i<1000;i++){
#define OOFSNNoCAdZxRPzMPvvMrGQMMYy bool kekk=false;
#define lGnQPmgiDsgYrmTKqaSaoaLXEJKCi for(int j=i+1;j<1000-6;j++){
#define CVercfWAqPMLUgOUChPhNZrzvqrS bool ok=true;
#define addPkKVGMfQICHEVFDkOJahThFUqL for(int s=0;s<6;s++){
#define DKVCegZyTnEIqbkERocBtxG for(int h=0;h<3;h++){
#define XVIwmGLTKwCvGCqKhvFG if(grandi[i+s][h]!=grandi[j+s][h]) ok=false;
#define hiwqVvHTRcMlKEVsAFnLDz }
#define gXtXHbugEtltaMScBhhWapcE }
#define oQyWNfwMDBkpFwXEERgsYIEpn if(ok){
#define uDPhGYtKXFEJfpMfvcIGh per[x][y][z]={i,j-i};
#define XGRKrnmGiSjINiBwVWBR kekk=true;
#define iodWEGbLoMstXEBVbIVf break;
#define vBvhqkgzbAgfpxPPYKLqCOp }
#define nLyArtlkmeeEYtcVbvRbhXToLvSwD }
#define tTbRRJuFWgUceUqGcYokEFstzUnk if(kekk) break;
#define bWQhtuljurygNKtkjUKPrvGoTu }
#define yvpoJszWiprpRjWhGQesOyg }
#define dAZHuKrDPpfbOqGyRTCT }
#define DZSOYDrLowSKfXuFLZWsIv }
#define grjBoNvZYFRjgLxrPFidfOIT for(x=1;x<6;x++){
#define KcJDCHQytDCUmwBIOFGot for(y=1;y<6;y++){
#define ikkduKYeoiwsjfTAkXJabrcMFZIW for(z=1;z<6;z++) {
#define hgbsirdqCXVvyIiglOBrwKxsELqz 

#define gKuPqQJIeEtcNspAtwsibGw 

#define hUuZKziKaNMJDBQZhvbpxpQZg }
#define PEhpRggQQwmAWBSJIDXYrYo }
#define sFiZrFADafPOEMCEDddJtkwEx }
#define ibuhTHrxFKeVPVWKGtiwWwlpCWo }
#define iYDCTMhTQmCxUgsdBansuquDPNBZ int getgrandi(ll n, int laststep){
#define RYiEveyhGYqlzNtmoFgm if(n<40){
#define WwtdfRMuEPAkpEHBJyxvLoP return grandi[n][laststep];
#define CTtzGOwmwxOrHZwlgayOI }
#define UyrQpbqkBgLtsiLOXwnvY return grandi[(n-per[x][y][z].predper)%per[x][y][z].per+per[x][y][z].predper][laststep];
#define mGUJEDrZuEbJlXNLqwXjlRQx }
#define yLrezaxWEgMfFPIuMjsKi int zaebalsya[3];
#define hQBZxcsCngQXHqwAMYiXeaSUh void solve() {
#define SBHFiKEmGBKzPVgTIrkdzZMNKEO int n;
#define ufDEnXlwyWxqQXtUZtdBIjaRl cin>>n;
#define mVJptWXirlfRfSjtzTmvLJf cin>>x>>y>>z;
#define ThdJKNbLjxWzgoKhTZThmRHC zaebalsya[0]=x;
#define UVBYXBbgAbetAnpwPJrCteOgfzf zaebalsya[1]=y;
#define VNtOydjzyPlbVaHuKoanP zaebalsya[2]=z;
#define fYQTBVJpeWcqqRCuJIHLMITHEmB arr.resize(n);
#define cZvYCfiISZrcLOeFQCJRCfUufqb for(int i=0;i<n;i++) cin>>arr[i];
#define GWJrcgyQBhXtBalXqlmcxAqj for(int i=1;i<40;i++){
#define IZqxoJAvsobsgVuzfLJbjzmdT grandi[i][0]=mex({grandi[max(i-x, 0)][0], grandi[max(i-y, 0)][1], grandi[max(i-z, 0)][2]});
#define vqFYbWmkvMxspFgvQQbsXoonQx grandi[i][1]=mex({grandi[max(i-x, 0)][0], grandi[max(i-z, 0)][2]});
#define WxRqSSMrZavhVszscpPX grandi[i][2]=mex({grandi[max(i-x, 0)][0], grandi[max(i-y, 0)][1]});
#define SMNWOJyYUxPkysThnSMseFY }
#define YcmJLHnhZdzgduNiSpAICZcLO int ans=0;
#define KjAJQWsiEdMSNpHRUhRLJZS int allxor=0;
#define YcNOIaZgzAFkMzjmLeVHUntSgzry for(int i=0;i<n;i++){
#define sjqqplGZqaqFgbJTnHCNjrKbN allxor^=getgrandi(arr[i], 0);
#define MUheqzTTqAHpGoOnUQZczPjsO }
#define oVejfuDuiMEwHDPMPcCkNQUHjrB for(int i=0;i<n;i++){
#define gWkVoWIseuBaRYgMwpvBghZl for(int j=0;j<3;j++){
#define oESqscivXhhRwelTsBXKcWVvZ int res=allxor;
#define wTjRWHLOPyMWbTCczqOgkvJQ res^=getgrandi(arr[i], 0);
#define KswPTZWpUkSxPuLNWQpt res^=getgrandi(max(arr[i]-zaebalsya[j],(ll)0), j);
#define QWwIxdmIjNtYuzMNJYXS ans+=(res==0);
#define qOnOtkctooCCAeSpfVhx }
#define EsKYPWSERBvIRVbAyxjFeHkuWHI }
#define CbjhLZHJgWPsrbLZgrvPLWojWE cout<<ans<<endl;
#define XwmuZjAiXQFbkgfmDGgbH }
#define CrHJrJlYOOIkpLxxnuNvKtz void shit(){
#define VIBkinQerUubfiTjSEFg per[1][1][1]={0, 2};
#define dOvNXdaPmURaSPHgddXG per[1][1][2]={0, 3};
#define xObJvxtXhLgscsyNvcka per[1][1][3]={0, 4};
#define pfzCJyeKwcGDaVutluwFFzU per[1][1][4]={0, 5};
#define dAvRdUwPPabzCMwqoqJtkcjUVHU per[1][1][5]={0, 6};
#define RiKOaXiomtyscekeZCLPdYWVp per[1][2][1]={0, 3};
#define QWndRuBVDSjMtqwpKuRhFTphXcS per[1][2][2]={0, 3};
#define joTIiQnsTvLeNEIuryngF per[1][2][3]={8, 4};
#define NVaRxBbzpkjVGNrDmyiVe per[1][2][4]={10, 5};
#define kuEjIpvFNeBGwkfYenZi per[1][2][5]={0, 6};
#define zAlDMXloBqmhcdWTuRLr per[1][3][1]={0, 4};
#define TDpxJMGcQagZxGjIIczRht per[1][3][2]={8, 4};
#define MRwAtJmiGtwPFpXvWufNE per[1][3][3]={3, 2};
#define HbApaYmvadKcCRnrLgbEO per[1][3][4]={12, 7};
#define RjyOfBqIbSfDARpFXEFeHjUfvIlH per[1][3][5]={11, 2};
#define XsTjaHPyIroAxRcfwGgzmjTD per[1][4][1]={0, 5};
#define zhOFIwQcyIOGtPtSKFlqMMb per[1][4][2]={10, 5};
#define BiUyGfekwVVGLhIpiMzdSwTiT per[1][4][3]={12, 7};
#define xKJRpXXUstBUufFLXVxXmjLOoOZs per[1][4][4]={3, 5};
#define wLDZBbCNYEiPlxnAnGAduFGUUF per[1][4][5]={26, 3};
#define susQklxDioKKTQbYFKFrDNgzQJSx per[1][5][1]={0, 6};
#define fsmDePkjkLgpsIaumjOs per[1][5][2]={0, 6};
#define ETZsosyEcbKQeHBkXhZJY per[1][5][3]={11, 2};
#define FsyhWdPdlyUrIlSDtPsIc per[1][5][4]={26, 3};
#define PcclctaOMkoENwqhwjACtVIH per[1][5][5]={5, 2};
#define EeFjyTKYTrmyhDQwalnc per[2][1][1]={0, 3};
#define zpaqADwKONSFTsFQdqScUkPZLl per[2][1][2]={5, 3};
#define ertGMfyuxjtJTXwwpcNJ per[2][1][3]={8, 4};
#define SVMFoLscxWIZeEarZpImpqXIUYm per[2][1][4]={7, 5};
#define ldrZMRlbJaTeBKqWZbmWmuR per[2][1][5]={11, 6};
#define GMoDoDDlYkkQgMIaTKDitQc per[2][2][1]={5, 3};
#define QIxXOMVMRhmHncsLJkoVda per[2][2][2]={0, 4};
#define ctMdQATaISWmcjxhqLUDhKV per[2][2][3]={0, 5};
#define ApzxtmwSNeLatxLUKhoDVGUJvTBH per[2][2][4]={0, 6};
#define TpQAOBcISqrSuZSIOnBpGTCH per[2][2][5]={0, 7};
#define WyeTjEtDcKwbzQbzLAUTXtI per[2][3][1]={8, 4};
#define CcVNkOuOkHwqrhsWiLsvgIUc per[2][3][2]={0, 5};
#define MyHRDRcgTGvBJLFnqnpQktDhHhi per[2][3][3]={0, 5};
#define LanFVLnBUbrFrqJMbIMOhlDHMwbl per[2][3][4]={0, 6};
#define gttsmWGwvUsPQGxYfeQHrqxZpMo per[2][3][5]={12, 7};
#define FWWRRQFzfYaGDRGerolaSaftrFsgl per[2][4][1]={7, 5};
#define dcZHzjhbDmvWDDxHZSDDJH per[2][4][2]={0, 6};
#define xzEXMeNqZmBXZfUbAgaUp per[2][4][3]={0, 6};
#define luLoywTGcIzcQLbCPRsIqVIph per[2][4][4]={0, 6};
#define TlNeiLnMlvISGQVRGfjeAXJ per[2][4][5]={20, 7};
#define OYrfzNugNcgzUbmbyVqe per[2][5][1]={11, 6};
#define aJAgEhhNdmBWYDPckZmwliCtF per[2][5][2]={0, 7};
#define sLQTQXgyjCYUMtZdqAwgYNQCQvxR per[2][5][3]={12, 7};
#define iXdjyWLjDqDDBipGjvSMIjVWVBVkU per[2][5][4]={20, 7};
#define KhOYMHCopbpgJGIokJScnb per[2][5][5]={4, 7};
#define LBtYezMKRbojHOaNjMUyIajZCZ per[3][1][1]={3, 2};
#define whOgWxjWGjEZsLsQthQk per[3][1][2]={8, 4};
#define llahfPROfiWRYJtkCzFLXzQRuUgK per[3][1][3]={10, 4};
#define cwjKUznWGwwmLwfktfwiNQgD per[3][1][4]={13, 5};
#define qIQqKswtqYfnkgIHEmjQaGL per[3][1][5]={9, 6};
#define iuFQShPeLTswkgqewwnrQc per[3][2][1]={8, 4};
#define iqAQaLnhXdaJuhgCHCgPubQSvi per[3][2][2]={0, 5};
#define OKkpmIdJGddiuCivFRms per[3][2][3]={7, 5};
#define YfBztgrmgbQtMWLiWMDoNfekd per[3][2][4]={11, 6};
#define bjqSbxMwzlDokrCllAajtxb per[3][2][5]={12, 7};
#define lykCeBegZrEklSXBtjEkxQUnhFuC per[3][3][1]={10, 4};
#define fGPWWICpAzfOUTxkxvWqag per[3][3][2]={7, 5};
#define xDERWjIlNhkAyZGNDYymHm per[3][3][3]={0, 6};
#define AMtCqYYhILbKzTiSUxxmIdVh per[3][3][4]={0, 7};
#define QhRoeyEbJgKNjHkpNltQvzNrVSv per[3][3][5]={0, 8};
#define BlckcMFOVvzPLhVWqOKENBjdydBG per[3][4][1]={13, 5};
#define jDtoNrJcsSJeAILsMudXEJvTafTPM per[3][4][2]={11, 6};
#define PVGQTkuELIkpECJTtAbQJ per[3][4][3]={0, 7};
#define CwlCbGfSsfZuKLrTXOHeg per[3][4][4]={0, 7};
#define YLIujgnTVoTSuvKKidCXifMEoAt per[3][4][5]={0, 8};
#define gUyUzbwpePgRKGTmgTfCgkLs per[3][5][1]={9, 6};
#define jtzYMlgKRIVRXpQxnoglNJNTmLMih per[3][5][2]={12, 7};
#define mhCcBRWMdwnGYgjbFfQCKkEkIkzLw per[3][5][3]={0, 8};
#define CqxszWyFEfVHXNxqblmoaLx per[3][5][4]={0, 8};
#define ilUyUGcEfaWGkAjYLqqFOD per[3][5][5]={0, 8};
#define VnghIKBONbbibUeKgovNaTBROB per[4][1][1]={3, 5};
#define qoumhjPQIKagiHmCVcjz per[4][1][2]={14, 3};
#define SVOcPHBFyfElCdMUddNOlDfQ per[4][1][3]={15, 5};
#define WXRxWmMmAdwBpztrrvEoqK per[4][1][4]={17, 5};
#define mRLoNYVeMerjZzsesfscaexJcI per[4][1][5]={22, 6};
#define kYecRySiKiEpNtBDRQkJgVjYRT per[4][2][1]={14, 3};
#define UPnJdCHzIFHAohKxjlxAmPrZCxNOw per[4][2][2]={0, 6};
#define TrtTAXmWPdIuzUhcvrpyLqJTg per[4][2][3]={11, 6};
#define RLtUqpjervyohDFLATFLfpjAjtKit per[4][2][4]={9, 6};
#define SEVXDxspstXSKaIfQcDF per[4][2][5]={17, 7};
#define SITQcTMXGafiHWVYTYhpuudNx per[4][3][1]={15, 5};
#define KNwntvRnkNblHxpZKDuMQgb per[4][3][2]={11, 6};
#define prKoereHNQsBJDWzifULfpNAelP per[4][3][3]={0, 7};
#define EqbHhcyKCijHSmaJWxHMQDzotPN per[4][3][4]={9, 7};
#define WBVdBzPfnstMCHNgDoKiargL per[4][3][5]={14, 8};
#define xKwsxGCleNlAHqBoLyiObhhTXW per[4][4][1]={17, 5};
#define nolzILaYYmJFSdXJQHaFtkbFlY per[4][4][2]={9, 6};
#define wCCKTtQXGbDVOEsRuHQI per[4][4][3]={9, 7};
#define KduQzlNCbfIuUaSwxvsMhlaV per[4][4][4]={0, 8};
#define QxOLIfoeZwuqVqMrEsrIAwYRrhO per[4][4][5]={0, 9};
#define ilXGBjODdyFKwDXzycdesCw per[4][5][1]={22, 6};
#define eYLXfWbxdOmFoAxgZXIheWOPnGo per[4][5][2]={17, 7};
#define pefgAQJDrUQDrKtQLozULVpVAZHMG per[4][5][3]={14, 8};
#define zcPAQYyQlJZPECQYGsxNnHpfi per[4][5][4]={0, 9};
#define jGXPdPdTVwCvnQDYJRPYmVBO per[4][5][5]={0, 9};
#define sDPyBfvUIxaKgRLdFbmfuKxgrD per[5][1][1]={5, 2};
#define lSClVvNCXMsJWLrafTxhoFRpTUDVA per[5][1][2]={11, 3};
#define aAtgFvdlNWsGEkGmdJGvRhSNyZz per[5][1][3]={12, 2};
#define dtVbSwUbQADtslRwJgUCf per[5][1][4]={18, 6};
#define SGsEhWENKNvGZHJOBGoSBqWDN per[5][1][5]={26, 6};
#define GIkSiHuiGQciQgvqxRMQTmaBTTdbf per[5][2][1]={11, 3};
#define UaMupiTmqohjGFdYhSDaTFrarpvW per[5][2][2]={4, 7};
#define xHvsXWtyMueRfuUINGcvWrAKH per[5][2][3]={12, 7};
#define bdTRfgsnQjuNkMMSvVguvgycMPKcj per[5][2][4]={13, 7};
#define NtujwKDAOWWGEYubSRcHpqWIMkU per[5][2][5]={16, 7};
#define kZgwSGMGAaFVYyBQoBoxYWdEh per[5][3][1]={12, 2};
#define DqADVJzTliOgnkAcjPHe per[5][3][2]={12, 7};
#define XtDYTjlANmlkVobhxkYGpHN per[5][3][3]={0, 8};
#define TtCchvxxBpTSTFITCSRzeborjjI per[5][3][4]={14, 8};
#define LqEfwhXGudpEEvzTtFkCVsjCZ per[5][3][5]={11, 8};
#define IaUqNYZmqNAPcKMyMYKLtdNidjo per[5][4][1]={18, 6};
#define wDwbySKZWNavRhpLVCnwbErWbJChd per[5][4][2]={13, 7};
#define yKDjBoVsJtrNodAqRLgWUmGDT per[5][4][3]={14, 8};
#define VsYWJNJVJYSXMuIjqYWmVN per[5][4][4]={0, 9};
#define RbfUQobdtkvicpLBCcDlZSClZjjY per[5][4][5]={11, 9};
#define PFLUCmmzHhYpQaOWFmIvqYapBnG per[5][5][1]={26, 6};
#define GnlqIJMWktOqBEMGofTA per[5][5][2]={16, 7};
#define HMBabkODjuvALFkbVjfTX per[5][5][3]={11, 8};
#define ugzgRjBqmNCMfqhnPcWsfhlU per[5][5][4]={11, 9};
#define uhYzKIQSNIAuQriGyHza per[5][5][5]={0, 10};
#define wzrvwHbKoHYVBQHJbWYHk }
#define CowSeQLjmGKBGRKWkqteRnPJE int main() {
#define nHWKzUQpUvIjDzkIpEVuqED ios::sync_with_stdio(false);
#define gIYtAnZGZwsgYtOVLYXwYyyG cin.tie(nullptr);
#define taOSFBbUoInTAtyJxFzavYLVydv 

#define DrqcBLKIqBTAicslcwuHMbg 

#define CFbYwcyMwISmgXqywAhVOeHa 

#define GPpuCGjaPerQINHgFCarRZk unsigned int beg_time = clock();
#define mtJGHJUuLqmpTwiFVFQEGXfkOLYG shit();
#define sYggBEYigSlVCMoBFglJK int n;
#define inAuXbemaFKSxCivOrvERItK cin>>n;
#define KWkrchouWKCKPcGpQpIZgD for (int i = 0; i < n; i++) solve();
#define GErcwysivECNpXKPkVzqCnkSFgnh unsigned int end_time = clock();
#define xJOnoZFdUPBiBYauKnDZHWX 

#define cBrGxpbPJvgiBicwQdwNGM return 0;
#define INqZaMVbFxmmGLOMiHgxyTeNinC }RslzCxSlnNfBMHZkuTPoauRZ
pMhWJbrNBIYgrxoqzNGbZdPkJ
ECyBdJBYljVjZNnDDibsfVTa
JeaQfpQdsqvHxdduKYSn
ZntnoKRbHYkxgTmrsTrnbFydrhfDm
opuQUJefPyuzgMwtHIbFDGPWZy
TfSgnSswSbxpGHrAKhyKFpPglXCP
ShkWYbFpzxmAIFvJbyVlwgJ
dfHpDcsUymOoxBiSNiBDFdxoi
FGSQBQOJsvWmvTwYxhvilDOL
mixMzWFhnlrQgHrDKxYuimjFNgZv
LdukguquHrlxAioaAOpNvjdrItSP
YxaQAhIIUCtQrvxSmCyGdiqs
qtYfZjIRvaqSmIlHPTwtRaeCyTgfR
znlDBWHruTebajxhggJIHhegvEtnB
rbcJdbeFpsFHrcRKfgbNmdkIYkb
sjTewhARfWXxARHWmAojulIyZIJ
omKDpXAOBZeITmEZPoHpdWwI
CVYzcnTbsHjoavyrMJydTGERMcJAs
GXJkwscxieVrDdofuhHN
zajpzkiyJTciAPJmHqWgHiNj
WheYBFTMFSwyBrMwNRKIIqvzfKiPf
kSTBTMwyKkSQzZroPvCQSfqjl
ICCPlgOMhcDZmvhsBPQXdry
hqzyEDwltPMMiVafMDApHqfvHgf
XNiCCrsChdjfmrWAJqVILEgh
HLzOFUSoRRZvkJEvOaaBqan
GVEeURODOSSMtFLgbJkEyHrhm
esOFmlCuRqiqlYbjGxPjXp
SEXPVpsOMjclsCuHARZhNcpenOoSf
yrKWPanSiPWPUGiHcCAxFg
qNYXyUdrJUbxEZXZlpxKeRaFJvt
wGLLLSvNfLVFtqfABPwf
VuoyKZfHRvuemRwygearr
XotuAppbJJPtFEWZeOTQNaXYGsV
FnBMialQVbokDZVchRXvbTEXaFEW
NtncdPLIsWggZxGqqusd
RwlyRkcdFIPGFxiGPrSLZvnPk
TcrPrLWoktLIcISoXeQNPvjbVI
ZcEbUzIAmURjAXGScaJFjKvdqdj
LotyizukmqUmezvmDeicIE
jgblwlIqNDyxvYIDveZLVwOAJ
hxAHPPDpDLEOsPVHgQsVH
yjqaoBKgcfPctIMeUhGRon
lktDaYYmbbIVaueOAMnXAE
ltmkQqdCAYdxaEBstQgb
SpMsfahhStYCRfMupigquapetI
QnbMfnokrblnbmznXiyzMpvY
TGzXNshefsROvWklFrcKON
HSWQHLAmSWEDbEqpIRJmx
fmgIwmznEETYBWhwRHmRqXLK
AFkxWXOUkIGxsVwjfgzsS
mUNNJKODAvRFDyYlHdSj
TRTiwfNdJdLmlyqxnvmunfJV
NLdnQCCCiLnWRIcfCjwdf
uNJkGsyFvpRsrOwztEdM
FcmNkhKkCcRBThStYmvLHK
iaowTcvGbcbgOxXdokbAWTxG
VRayaYVeKsdpszKIpjUOwKTIqit
qsXIxrrlDafHYSbGcyCkkiopb
dZrUArmEhPBFIaioGJUnQMqfDjDs
YOUdZsHQJDDhBEueIqVzve
ViBcfcrHKhTbFSNtApDpL
hnUDDyzvEuHonMDgbgSe
lMrsNsAwGRvvKFTIZxODtSahAD
LiIIuuQdVwFvfJxMGmIkVtuAGaxXT
cEzbVjnLYFPpebztTxLVRcoxjwvu
lBCtfNYAwcUsNMfJNpBpblNNxwc
czgEBXyBvcyihBVujKowtOmVzdf
OxmEwefBNylIdZJxHLLhRRrfEMX
omvSAXjfWebBjEsILvZOzBPsR
oxrikbBqYlcYOdkZUqMou
HbqoSdXxNuqQFjaAhrCQxKF
bhFpveyGiqLVJazseXpQySfqJiyOr
qFEQYYeRVwUIVNjxsITysZN
xcjHBWyXvKaioacGKgmNvD
ARUKNcCsgnPNJvFDynovNMQhwI
lBxWDcUOTJVGOpZjfpKTV
LyysbebfbvOFosMjibeQzvy
rBbflXEMtfWIagaEFmgqWOR
NwMBFlVBNGjaovpjGUPuznwQkC
eZNAfpcQYFKQdVrfaHOvVKy
SodBFgKSUMAbMRUjCnmEbHVC
gIYaeErblROdmQocgPCGwK
ktKdhfYFsaGkExdydsBIytEunK
vcdmayzledJKCfIgznscUd
UeLsLCtsMNQOhZBhArHmDdQEBpplR
gyxmxRTmwEnzFNUrksFsC
dLLlkpLsryLxuVohwamHJnLPrkT
OOFSNNoCAdZxRPzMPvvMrGQMMYy
lGnQPmgiDsgYrmTKqaSaoaLXEJKCi
CVercfWAqPMLUgOUChPhNZrzvqrS
addPkKVGMfQICHEVFDkOJahThFUqL
DKVCegZyTnEIqbkERocBtxG
XVIwmGLTKwCvGCqKhvFG
hiwqVvHTRcMlKEVsAFnLDz
gXtXHbugEtltaMScBhhWapcE
oQyWNfwMDBkpFwXEERgsYIEpn
uDPhGYtKXFEJfpMfvcIGh
XGRKrnmGiSjINiBwVWBR
iodWEGbLoMstXEBVbIVf
vBvhqkgzbAgfpxPPYKLqCOp
nLyArtlkmeeEYtcVbvRbhXToLvSwD
tTbRRJuFWgUceUqGcYokEFstzUnk
bWQhtuljurygNKtkjUKPrvGoTu
yvpoJszWiprpRjWhGQesOyg
dAZHuKrDPpfbOqGyRTCT
DZSOYDrLowSKfXuFLZWsIv
grjBoNvZYFRjgLxrPFidfOIT
KcJDCHQytDCUmwBIOFGot
ikkduKYeoiwsjfTAkXJabrcMFZIW
hgbsirdqCXVvyIiglOBrwKxsELqz
gKuPqQJIeEtcNspAtwsibGw
hUuZKziKaNMJDBQZhvbpxpQZg
PEhpRggQQwmAWBSJIDXYrYo
sFiZrFADafPOEMCEDddJtkwEx
ibuhTHrxFKeVPVWKGtiwWwlpCWo
iYDCTMhTQmCxUgsdBansuquDPNBZ
RYiEveyhGYqlzNtmoFgm
WwtdfRMuEPAkpEHBJyxvLoP
CTtzGOwmwxOrHZwlgayOI
UyrQpbqkBgLtsiLOXwnvY
mGUJEDrZuEbJlXNLqwXjlRQx
yLrezaxWEgMfFPIuMjsKi
hQBZxcsCngQXHqwAMYiXeaSUh
SBHFiKEmGBKzPVgTIrkdzZMNKEO
ufDEnXlwyWxqQXtUZtdBIjaRl
mVJptWXirlfRfSjtzTmvLJf
ThdJKNbLjxWzgoKhTZThmRHC
UVBYXBbgAbetAnpwPJrCteOgfzf
VNtOydjzyPlbVaHuKoanP
fYQTBVJpeWcqqRCuJIHLMITHEmB
cZvYCfiISZrcLOeFQCJRCfUufqb
GWJrcgyQBhXtBalXqlmcxAqj
IZqxoJAvsobsgVuzfLJbjzmdT
vqFYbWmkvMxspFgvQQbsXoonQx
WxRqSSMrZavhVszscpPX
SMNWOJyYUxPkysThnSMseFY
YcmJLHnhZdzgduNiSpAICZcLO
KjAJQWsiEdMSNpHRUhRLJZS
YcNOIaZgzAFkMzjmLeVHUntSgzry
sjqqplGZqaqFgbJTnHCNjrKbN
MUheqzTTqAHpGoOnUQZczPjsO
oVejfuDuiMEwHDPMPcCkNQUHjrB
gWkVoWIseuBaRYgMwpvBghZl
oESqscivXhhRwelTsBXKcWVvZ
wTjRWHLOPyMWbTCczqOgkvJQ
KswPTZWpUkSxPuLNWQpt
QWwIxdmIjNtYuzMNJYXS
qOnOtkctooCCAeSpfVhx
EsKYPWSERBvIRVbAyxjFeHkuWHI
CbjhLZHJgWPsrbLZgrvPLWojWE
XwmuZjAiXQFbkgfmDGgbH
CrHJrJlYOOIkpLxxnuNvKtz
VIBkinQerUubfiTjSEFg
dOvNXdaPmURaSPHgddXG
xObJvxtXhLgscsyNvcka
pfzCJyeKwcGDaVutluwFFzU
dAvRdUwPPabzCMwqoqJtkcjUVHU
RiKOaXiomtyscekeZCLPdYWVp
QWndRuBVDSjMtqwpKuRhFTphXcS
joTIiQnsTvLeNEIuryngF
NVaRxBbzpkjVGNrDmyiVe
kuEjIpvFNeBGwkfYenZi
zAlDMXloBqmhcdWTuRLr
TDpxJMGcQagZxGjIIczRht
MRwAtJmiGtwPFpXvWufNE
HbApaYmvadKcCRnrLgbEO
RjyOfBqIbSfDARpFXEFeHjUfvIlH
XsTjaHPyIroAxRcfwGgzmjTD
zhOFIwQcyIOGtPtSKFlqMMb
BiUyGfekwVVGLhIpiMzdSwTiT
xKJRpXXUstBUufFLXVxXmjLOoOZs
wLDZBbCNYEiPlxnAnGAduFGUUF
susQklxDioKKTQbYFKFrDNgzQJSx
fsmDePkjkLgpsIaumjOs
ETZsosyEcbKQeHBkXhZJY
FsyhWdPdlyUrIlSDtPsIc
PcclctaOMkoENwqhwjACtVIH
EeFjyTKYTrmyhDQwalnc
zpaqADwKONSFTsFQdqScUkPZLl
ertGMfyuxjtJTXwwpcNJ
SVMFoLscxWIZeEarZpImpqXIUYm
ldrZMRlbJaTeBKqWZbmWmuR
GMoDoDDlYkkQgMIaTKDitQc
QIxXOMVMRhmHncsLJkoVda
ctMdQATaISWmcjxhqLUDhKV
ApzxtmwSNeLatxLUKhoDVGUJvTBH
TpQAOBcISqrSuZSIOnBpGTCH
WyeTjEtDcKwbzQbzLAUTXtI
CcVNkOuOkHwqrhsWiLsvgIUc
MyHRDRcgTGvBJLFnqnpQktDhHhi
LanFVLnBUbrFrqJMbIMOhlDHMwbl
gttsmWGwvUsPQGxYfeQHrqxZpMo
FWWRRQFzfYaGDRGerolaSaftrFsgl
dcZHzjhbDmvWDDxHZSDDJH
xzEXMeNqZmBXZfUbAgaUp
luLoywTGcIzcQLbCPRsIqVIph
TlNeiLnMlvISGQVRGfjeAXJ
OYrfzNugNcgzUbmbyVqe
aJAgEhhNdmBWYDPckZmwliCtF
sLQTQXgyjCYUMtZdqAwgYNQCQvxR
iXdjyWLjDqDDBipGjvSMIjVWVBVkU
KhOYMHCopbpgJGIokJScnb
LBtYezMKRbojHOaNjMUyIajZCZ
whOgWxjWGjEZsLsQthQk
llahfPROfiWRYJtkCzFLXzQRuUgK
cwjKUznWGwwmLwfktfwiNQgD
qIQqKswtqYfnkgIHEmjQaGL
iuFQShPeLTswkgqewwnrQc
iqAQaLnhXdaJuhgCHCgPubQSvi
OKkpmIdJGddiuCivFRms
YfBztgrmgbQtMWLiWMDoNfekd
bjqSbxMwzlDokrCllAajtxb
lykCeBegZrEklSXBtjEkxQUnhFuC
fGPWWICpAzfOUTxkxvWqag
xDERWjIlNhkAyZGNDYymHm
AMtCqYYhILbKzTiSUxxmIdVh
QhRoeyEbJgKNjHkpNltQvzNrVSv
BlckcMFOVvzPLhVWqOKENBjdydBG
jDtoNrJcsSJeAILsMudXEJvTafTPM
PVGQTkuELIkpECJTtAbQJ
CwlCbGfSsfZuKLrTXOHeg
YLIujgnTVoTSuvKKidCXifMEoAt
gUyUzbwpePgRKGTmgTfCgkLs
jtzYMlgKRIVRXpQxnoglNJNTmLMih
mhCcBRWMdwnGYgjbFfQCKkEkIkzLw
CqxszWyFEfVHXNxqblmoaLx
ilUyUGcEfaWGkAjYLqqFOD
VnghIKBONbbibUeKgovNaTBROB
qoumhjPQIKagiHmCVcjz
SVOcPHBFyfElCdMUddNOlDfQ
WXRxWmMmAdwBpztrrvEoqK
mRLoNYVeMerjZzsesfscaexJcI
kYecRySiKiEpNtBDRQkJgVjYRT
UPnJdCHzIFHAohKxjlxAmPrZCxNOw
TrtTAXmWPdIuzUhcvrpyLqJTg
RLtUqpjervyohDFLATFLfpjAjtKit
SEVXDxspstXSKaIfQcDF
SITQcTMXGafiHWVYTYhpuudNx
KNwntvRnkNblHxpZKDuMQgb
prKoereHNQsBJDWzifULfpNAelP
EqbHhcyKCijHSmaJWxHMQDzotPN
WBVdBzPfnstMCHNgDoKiargL
xKwsxGCleNlAHqBoLyiObhhTXW
nolzILaYYmJFSdXJQHaFtkbFlY
wCCKTtQXGbDVOEsRuHQI
KduQzlNCbfIuUaSwxvsMhlaV
QxOLIfoeZwuqVqMrEsrIAwYRrhO
ilXGBjODdyFKwDXzycdesCw
eYLXfWbxdOmFoAxgZXIheWOPnGo
pefgAQJDrUQDrKtQLozULVpVAZHMG
zcPAQYyQlJZPECQYGsxNnHpfi
jGXPdPdTVwCvnQDYJRPYmVBO
sDPyBfvUIxaKgRLdFbmfuKxgrD
lSClVvNCXMsJWLrafTxhoFRpTUDVA
aAtgFvdlNWsGEkGmdJGvRhSNyZz
dtVbSwUbQADtslRwJgUCf
SGsEhWENKNvGZHJOBGoSBqWDN
GIkSiHuiGQciQgvqxRMQTmaBTTdbf
UaMupiTmqohjGFdYhSDaTFrarpvW
xHvsXWtyMueRfuUINGcvWrAKH
bdTRfgsnQjuNkMMSvVguvgycMPKcj
NtujwKDAOWWGEYubSRcHpqWIMkU
kZgwSGMGAaFVYyBQoBoxYWdEh
DqADVJzTliOgnkAcjPHe
XtDYTjlANmlkVobhxkYGpHN
TtCchvxxBpTSTFITCSRzeborjjI
LqEfwhXGudpEEvzTtFkCVsjCZ
IaUqNYZmqNAPcKMyMYKLtdNidjo
wDwbySKZWNavRhpLVCnwbErWbJChd
yKDjBoVsJtrNodAqRLgWUmGDT
VsYWJNJVJYSXMuIjqYWmVN
RbfUQobdtkvicpLBCcDlZSClZjjY
PFLUCmmzHhYpQaOWFmIvqYapBnG
GnlqIJMWktOqBEMGofTA
HMBabkODjuvALFkbVjfTX
ugzgRjBqmNCMfqhnPcWsfhlU
uhYzKIQSNIAuQriGyHza
wzrvwHbKoHYVBQHJbWYHk
CowSeQLjmGKBGRKWkqteRnPJE
nHWKzUQpUvIjDzkIpEVuqED
gIYtAnZGZwsgYtOVLYXwYyyG
taOSFBbUoInTAtyJxFzavYLVydv
DrqcBLKIqBTAicslcwuHMbg
CFbYwcyMwISmgXqywAhVOeHa
GPpuCGjaPerQINHgFCarRZk
mtJGHJUuLqmpTwiFVFQEGXfkOLYG
sYggBEYigSlVCMoBFglJK
inAuXbemaFKSxCivOrvERItK
KWkrchouWKCKPcGpQpIZgD
GErcwysivECNpXKPkVzqCnkSFgnh
xJOnoZFdUPBiBYauKnDZHWX
cBrGxpbPJvgiBicwQdwNGM
INqZaMVbFxmmGLOMiHgxyTeNinC
