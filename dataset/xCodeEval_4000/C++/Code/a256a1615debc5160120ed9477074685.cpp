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
#define mIjbVgmxSwEhdIaVHimRPvAlsAhwuFZJAlcJvBIjTEvHXYzscS 

#define GOXMepGpUIbYXnWyquECsCLNMVVSKQuZjoerdyoysPWbBrYxXo 
#define JDKNSlZsRvNGidMCETbGmBVARVzLBmrIIGqorNCBpHDoNQdPcB using namespace std;
#define dBSIyanpsLhgHvNktsRQTNQENddeNhTLMAJFIyvkdZGGzdOfpo 
#define FJHrrWXSwwvHREoWNnuIiCBxBKOgMqKDGSjSrJpPJQvRxKZQgx 
#define bpNXOWFOunQUqTFvzeiPINtHBoxRjLseqjdAqQoHVeHRRvtIzz 
#define gUpjcUYGbHVucCkZFSAKVFzNcjcYrPYiomNKoReDLDVcUcnTZG 
#define YcObjYLYMyLXwZMGlBWWIIEmSXnXORXYdmXWbIalUWiPSVqNaH 
#define iSsXijcbuzeXBqQtkmdxMHdlDiefpeYOYhElfAIcWmJYnUZdyV mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define GlJBFeVpHvZxJNeWbSzgMbaFknQLveleuznmheOOwDNgKiFNEZ 
#define lkZhPVneWfINoxBwQbmtahKlHHyiYVmRGTeiARbHSWdVFuCxxl 
#define WRhfRDTallRXCLVaXEhbadhqqcOQuDiuaayxWwjPHTrvavzTOt inline ll gcd(ll a, ll b) {
#define EUAibbnIDgCdLOKuEpgnYtPGHqFYoHuDpKGrYcnUCrFSMRzTOi while (b) {
#define ExWXXEalpDiPNGAPcpgjKqkCHIiWjyzRoHYLcxFRdqQzwelGUu a %= b;
#define vQNywfEZrzPxcszPKsgNQABXjZwOrEupikgmsEUKCyEJRRBjgb swap(a, b);
#define mLEWCjedYvvSBqSDEXkDKqBkInyJoQCEekLNfsvjPyHVTFQOGT }
#define SIfHIOPExJnzIwXCWukmKiRPoWkwspeVJcTWFcsDCfnGuCIWFL return a;
#define vZRWonffGciwgUzjjvQBTyfJZRdKXKLKlIZpBThLgjvUeFDxIQ }
#define VcLxRdVofLIfcbmtTgmERHnwutRAhibTvYqEqPvdJfWcJqVjti 
#define fpyXjdyFXKgPsDwLJKWLznBdImsDGOrjijUUXYsnTAlUluLyGg inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
#define BBMwaqeAQTSzQLfzebEzCEIRGqsvQaalDKAeHzqmCorhiamMre 
#define pyeEmZmTeUVlfDnuclWdwRHIJtJDQjhYgWMocRxrrqJnQYRUOQ inline ll pwm(ll xx, ll pow, ll MD) {
#define QChtzhYhlbRJQIEyKosJIfeJFfaXzfMWbtXWJfTMixERCkHCyu if (pow < 0) { pow = pow % (MD - 1) + MD - 1; }
#define rmOUwKBnmbcruwDYoSNbGKoOfJPXwRAbsfidYLozELwunOqIih ll mlt = 1;
#define DtCdWwipTPjLcwTXUpPHwjjKJtbuDKbrDGvMybCKVgPnJSCtBm while (pow) {
#define kiHPdjCOMQcWVZssSerYwRyODwlPdkhdpAxxZZceJmIMalNmWQ if (pow & 1) {
#define TVfekJvSoGjGIHnrqlUzHkGrGinFSNmMRYvtHCGoTUUviYIfbe mlt *= xx;
#define osZRgQmuHwTELarqlveEHYznZbtIVQOJqXzARjvCyseffYQrlT mlt %= MD;
#define NLlBTvYtDEEWoeTFlqGvDNXZVvAPYHYvbJODXLczQgcnhYpMvV }
#define hSMEAlbsNPsimRWdSmFPruxWfssoBeRPcdQpTHrOVQGwjxixGD xx *= xx;
#define boEWQzrCSCiRQruWScoqjeAaeDfphTZknEWwgtUAbdQzrHNAoT pow >>= 1;
#define OcXQVnfYsTLQtMegfDCdikuGrzfxyzWXEBJtQblTjbsSDxQyAp xx %= MD;
#define VWpYUkfYylAqFxOGjatsZIgjnnCsVBpNNCnYEcPmneuGTxAJdE }
#define aIeGnpIdNIEqbZyXMbmKpSfAWErGcDRfJBykzHeZZOoNLEUHwA return mlt;
#define cuOOYiZKrnYzMEJAtzjqCKTOfOxnsdzBumbdbejlMPsZHLHlDE }
#define IOppMMPTYsMxRCYhyvIpnPcPdkijSHltaYQyuNPZCBsVgKSalL 
#define VVnsIMutgyChhKQFBfYqgpDxdlbhUQpooZXJIttdaTNuGHJGgG inline ll gcdex(ll a, ll b, ll &x, ll &y) {
#define HCRHgGDqUggGJxfeMeyQrKKIoOALlwvEeSFZkaMrBEsRBJCmDz if (b == 0) {
#define pLfROPBPvoAsxxTTWLsMplIVFmhgWasEZFZYSJFkJLGpqigiYh x = 1;
#define OCmRCXVgAyVTjxzmoBDSZJfqjspMcteqiJEYCHjgtfVGvzvumZ y = 0;
#define XBtaHlIzQBORJBMrpdVVYVjUooICHAQaePkYvSJdIodUCuCvGg return a;
#define LJXVYGZDRQMNYOtVKcoigMRDWAzeEerUQekqmISeQxUIgUayiC }
#define WMwaClxPMAOGJSfIVyBPhfNnavyreqdEqRDhBnVTdwQJIPwnFM ll xx, yy;
#define DSBAKoxqppQWtvCCONQKchYDhGBltsOpWifJojqLInDPwJXPBl ll gc = gcdex(b, a % b, yy, xx);
#define ecXRATLvLhRrJbbXwIsdMDholJLZckrOljfaocIgksGIbEJROR x = xx;
#define INXsooZGGcEFYlSYOZbTnmyMwYMfEaqpTDfdWHTsPceGEOynen y = yy - (a / b) * xx;
#define SrUFjkRNsRnPtdgidPHlBehoAADPfGvelwkCoYSVxcvMAklyOs return gc;
#define WxkmBospAonOGfqmDDFfjBBlKzCZsRVuQlqCJtSdjcAMNqgIZH }
#define fYMNLvCLRQUdHCKeebVLIBggYoMyaqlqLFjZxrsKrpbeEfvlmP 
#define IPNSqkgtXVtVuRDHwHAOICueJvLCJLdPdZwaDGYTBxaALvqQge inline int inv(ll r, int _mod) { return pwm(r % _mod, _mod - 2, _mod); }
#define SilHytvsfXJqvVamGmniLUKYcvnqwhnqLJfxNuMaBJbCvyEynT 
#define qcLgUutERfyMpwZgtttwrhJEEovnlOzFCRadwOHxNKTIJBpWHS inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
#define EDxGdvHXRHUgLBnVtNsHSsTkNHsGMgeFeuvTLeaLteYeZIIVsW if (pow == 0) {
#define puaHRKiyLEoQNoRALYiroEHsoFdZzqMRuNcopJWwXcDqbAXjIh return 0;
#define KbuFHGLpnJGGgQuMjRRmObfUoBCxKHpMEtPzVjCXgoVwxxwabu }
#define vCdrEbapXWuniiurSHnTfLiUEVwhiLoykNSFYHmPuyRdxQzbIf int hpow = 1 << (pow - 1);
#define FpLldZfYJHUmhaErUPTrGwaVrFtyHArSEtMNGsExNxjxHZEiVm int seg = (x < hpow) ? (
#define opZiuSkSavJGjdErOVsWgVAryUfOTBDgPZabGAYQvCiBcokftZ (y < hpow) ? 0 : 3
#define gNzJtpvSnaYdkGNQLrQqWcybYaABibpxuOrnWhlITeOqjdtDGv ) : (
#define YbQaoMpzdSxgqeETqHOUrpBWedCYcHdAaXTmzyUCmGGJHctnTn (y < hpow) ? 1 : 2
#define HLzaTOfqsBvaDDjxOUuOLcUxheBeyBylNcImsPyrZtrrWbJynK );
#define zoFeQgfQTibOOTUFWCxIhxIkHQyFixnWrWaJHqLpoaFcyhlgRB seg = (seg + rotate) & 3;
#define aPlEyQfgBcdLTqQNLiVzlsPdBMMJbRgGNBxYuaPPeNvHpEGolK const int rotateDelta[4] = {3, 0, 0, 1};
#define dAhJYQywYDMoBIMBSXLXtKppZLmnfoUKJFvLIQEDNxoCyueCkg int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
#define MDBBhIeUnqYBydsBHOFtRswPprKMcAsLPMakGuAUtaMPwMSjzJ int nrot = (rotate + rotateDelta[seg]) & 3;
#define vEYKeAPsHqddLQruzkdsyrowJemrDbbEzamkFOvURVuGbTVxJI int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
#define RiqmojGZhQTbUwFhYLKqSxhseavTXhNwqsOlbiGJedCnconjxb int64_t ans = seg * subSquareSize;
#define bSACRpEdeIrjAwOfTPzRynvsDEasIJusWixdXPycldLGQoiCqv int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
#define eEuMxTcoGeBBLrRRCXpilqMiqHCGcnSfORYeIDgRJAnByxXyVo ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
#define GGUreRNEyZBzMbvGvHAXVVupsrVwkgjIDhPFnaiuPwvHPHJNEt return ans;
#define ujJfUvUvNHsNktQbLyBqQhwaBeCxbAbLGFhJjyWWXalapsXXyD }
#define oOKbLqwganCluabTXwKvIrVKVvvEWXKDsqgrsTQfFHAdntjDsA 
#define kWSvVmSxoHkdpyMKQXrvuBGnSuHTPVBfFCSeMfYIjNTIrDBZPk 
#define pNerKkfGzjrGSpdshdfzuWtlwhFMmysFCtyLVJIDqSdBeZmZaM struct tup{
#define neSVuOyrSmMRFWYObkLCYMxCspsiiGmejDDInjCWxPpkeymnin int predper,per;
#define YGaIYkTWklXoCFPMJXWcoccyOxuFBRBgJALcgQThDcUZNyALLW };
#define xuAsNzWaROcDlGsXvxccitQtcupJfSxBSdgYukKvbUspLaRIzZ int grandi[1000][3];
#define cmboyNwvkvDmYWHhQGVtZJaqOhFLKwdvmwBJMOlTMMqGPKyCrA tup per[6][6][6];
#define jSKLAZHuXwhhJbSpIKmvJqOhBhftfRiFeTNrINhhFPkHyEDLmH vector<ll> arr;
#define fYFYwQlmcJnQLslcgorTLYnezzGYSvDIiPzYjUVrgEkuqYycfY int x,y,z;
#define naieupIgFbarNUJhYeoFWeoWKqjDWdeuwkZjrLEPfhmLgkpxHy int mex(vector<int> kek){
#define TVawGGNkOebVGwaRzDRmCiZNnrRgSuxexHYeRbZYfNWPrRbuwJ for(int i=0;i<=4;i++){
#define QOMpNAOxHcWlbBVAShwChRkJDRCXLmpmibQZERsmQdNSFadgCX bool ok=false;
#define ENNCkHPpTRVzFlJaCxoOGlOMRtBDbEopzdAPwnnwNNrLkTiDIa for(int son:kek){
#define kUnzOcdppbSMHghmWNpKpJDeNdmOtcQGmZWZzfKAaDyDYRDScp if(son==i) ok=true;
#define wKfOTSEkXbUAEtozPBokKBDnREbYNlSbLkdGAaBaLMWpTCuJqb }
#define jzNejisqyHVKbPSbPqgRhgLXAeEuIPEpBjQVKmdymHsqDtVRPo if(!ok) return i;
#define CBJgFxMysRQKCFfYxnFcAvfldGNfxXzCvAiGuUUIXGBHOgNrcv }
#define XHPWCjPCRxFuuaToPKQCTEtfsaSsssfqLHMOejAQYYgglaCQon }
#define yhYdIyKPOMLWyjXRzgwPWklEXtsUNKSiyzGiuPWESAuSTfriAD void precalc(){
#define BsNlvVjsahlnbqddvzloEmIHNoBiVIUEjXJcxKeXcvYqcwjEwC for(x=1;x<6;x++){
#define COXsnqwCiupxIqYuaXDsWhICjSvymwCWbZPoSVbhWUSUVGwgeD for(y=1;y<6;y++){
#define ueHgghjlpyizbWZkkJLuJtjLrEXRqSAzeOmHSSCtblbEUUkmwQ for(z=1;z<6;z++){
#define vkNTTjBHAoJIUOIrZTfjvYMRjRAXWkQHFGAyZmGgGlpqxjAogE for(int i=1;i<1000;i++){
#define YOCxtrUNHbJbdRGWNaIbUPqaELfTHuLErruwhMdYvSEHAmmpGa grandi[i][0]=mex({grandi[max(i-x, 0)][0], grandi[max(i-y, 0)][1], grandi[max(i-z, 0)][2]});
#define NKfcnWwjzKLbpAtIKMMkzbZGLouJoKXdFwszkQlbniYTFWYTWR grandi[i][1]=mex({grandi[max(i-x, 0)][0], grandi[max(i-z, 0)][2]});
#define rPmVtBxPKdKiutcFMUHaaufREmMFJuYEQiBkMvAuOFKutpXTea grandi[i][2]=mex({grandi[max(i-x, 0)][0], grandi[max(i-y, 0)][1]});
#define iuOSDyTRefRwThDubtgSbxbOfIzBTLdvndhZgaZoSxcqXgvfsa }
#define KgKYwYVEBIcZQNpJzsdBCnYAPvoVrSvueBZjYKcVcKjyhYXIoc for(int i=0;i<1000;i++){
#define hpllYNborshfADJOkpWJAfLedOxEsceMOzTDyCBRSGiZpTZkZC bool kekk=false;
#define oforjryfsknUfgnaZqTVJMoCaSJpoJyJkoxbByPCoXvNcniGRU for(int j=i+1;j<1000-6;j++){
#define QTFbxGEAxZxDFaBMJrpdAjhmtmAXRrwjVZPMDSCUTTJxOqGqWL bool ok=true;
#define cfIdBmuVjJXyaJLTeMkjqIFsgVxIHcsBsBKSOyLjcZcxIKgQwa for(int s=0;s<6;s++){
#define nKVQcGxMxwltZXcPoRcDhvNvEQbuSoTfhQdDcmyshswaWTEDvx for(int h=0;h<3;h++){
#define JQjkLaBWYMsjQuzGcYWYOLFbyuHoqntJTuSfSUGCeAJevcpAmi if(grandi[i+s][h]!=grandi[j+s][h]) ok=false;
#define JuGzgSXeWMuhuFzEXaVgpELIwlPOFBTqINfiUGbwxDGmCzKccy }
#define WwXPUAtPPWQofRFFQeAWaGWcyvIbgYlbTIingnrOdcLDWXKnXh }
#define vfGbsINNwkCQTqoHoVDupmOpnTDhnvfEGPooleyJLPKprkaNmI if(ok){
#define LvVAGQmQDpMfmcABrhsmIrzRQUYbQXsmODzDQdbwkupfWzHTOj per[x][y][z]={i,j-i};
#define UlTGQsOmoxrnLxPxzgxnhNizCDjpxldrJyITBEiusoxghpqVai kekk=true;
#define TapBFKCkMtdKLNehJQuVwhBRFYijqRaXeWVRxXWQZRvBgaWUql break;
#define VDIChjFTfGickRjQaIeBhEOiDgmksbfInJHEqKGkgPRAPwNpGF }
#define muENuxESVRbbpVaVDosbiGypNgpMLHNhVbPhjeDAObkmUanOlg }
#define dukwIpRibWjSAPLDOHQHWXtIBYfHheUKlWHeHyJqLcwasjLaSm if(kekk) break;
#define tuIRzEXfyhPEduBMgNaQNTRACtbSgJKvWNbYggYZbnYOiWQdZb }
#define fstQdZlYKyjWhZNiYEKcjWzyMJfEsfhEbYaIGpWMYqtyRPTlLf }
#define DUCgklizVFopiFDcpQBXeomBrJGKBSvTLivbUySCkHKOmxTjcJ }
#define niTOwfHEkDcQztkUwwnlAXFNgAnDIQitbEjqLVRNUwllQsGjQo }
#define DqvDzgcrqaAcPuSulJWcpFSIaVBYrACPyjXjpZRpuwFVsIlSfw for(x=1;x<6;x++){
#define EyUvuVRvoeWbWurflWDcTmNIhtwDnMbFzVewOaBsHowugLEgfH for(y=1;y<6;y++){
#define sOVrfenPGfWBgQtHdvjnerXxYQvepMvTixuNkshfJszjglCxQh for(z=1;z<6;z++) {
#define igsNhxNFimUEeBURlpWJYKueyYwKaMZRdLqxuqWMvMUqAkTKIF 

#define HGKwRnaXBvkLUSyggZKOisUKNxVdIogCbJYjHVuNfizGqCzBrE 

#define ALZVeIHUQYSykZwOhyKwnZAOAoDEtSWQsQneqBjIqwQXDAdSnQ }
#define idROTcqkLZJNtMTxUlMVLfEYCBwdLEaxEewGZhnIJxMjZzByML }
#define vwKurOGKyCKwmiroGrocDdmqWSjtHrPVyzeFTaizNQlSJRFiFR }
#define zoajNcFLoDgNGVEWUqtCLFwSdrKJUyrOKjwetfMiCIWwJjhafk }
#define bereRjVmISnvWndSaHowycGjtPCoZyBbWETUESprdTtrhwrzbc 
#define ItRwnFGTrUWaYEVbWSiDWrqxEIQADwwLMVywRZNUubuLjhmorc int getgrandi(ll n, int laststep){
#define mWpvlPqAoqhawLtcExRwzREkemSRWRdtdpVhiehriLbDuLuIUX if(n<40){
#define pwKxROOkxGJGGuHZlMCcNTymuOfqEglUdHmqevEVOKJnLNBThC return grandi[n][laststep];
#define pHZdjMmsfUjWbCDMsYkYWfqFkdWxJrNJuOOOXDMOGnqGYlUUtw }
#define KSlxQiPZUsUULUHRpEhoBpeQAOVWQmVLjpvBqMnSbLRUsKBKPn return grandi[(n-per[x][y][z].predper)%per[x][y][z].per+per[x][y][z].predper][laststep];
#define gOOCltTDLeQvYACqkiPhGFsMYYnStQxTlzpKVbsBPCIZAPtlJY }
#define fJjXNkovvbpwcUnGJmBWXfPRJRDOGSUiYNMJshmyJXUFWdTalC int zaebalsya[3];
#define ScXoaPGZoQWmDDwSUeHiPoXkbxfvYEwPhONlzwvArChhKytEzC void solve() {
#define TuOYRVKZvxawBiiQGKEuAenyfGRbaeydrFmlrRwYcUlMXbWKDa int n;
#define encHiIPDkLDuiBxFfgOkjaJTXsgSxIMqmPtrUcobNwveEVtJpO cin>>n;
#define dYogKEVMTqnVQzNlFDflmuyMyOodzTSGiNmZZNFmCrYckPmHKP cin>>x>>y>>z;
#define irEjhuzieCxLsBEYCHaXeYAbsQzByAYZMhkWdhrbijlANJSUoh zaebalsya[0]=x;
#define RAvLwGutXHCQcUhnzAuaoteXHYimPibBGZwjainiganHCyAppQ zaebalsya[1]=y;
#define JyMTgDYJDvibgugpVFYoqrWzPsWmwHRnJYGSPxIVOlwETYUKdd zaebalsya[2]=z;
#define ZioLadVjNNwGNFeKfktyNwuhkNBlVKmaKGTPncKsWUcNBipszV arr.resize(n);
#define fXPHONaNaTgtUdtlyiXibcVBIJWROQMLLgroYTrzeWusdVVTZL for(int i=0;i<n;i++) cin>>arr[i];
#define FbveUWyjplvkQeogChZVnCsuqckfIrloCIHBOEanbfRRQTzUbs for(int i=1;i<40;i++){
#define SrPNeHPIwIwBkAbNGaavPXvzmjSPtLfIsxbXYQbpKdQxJREAaz grandi[i][0]=mex({grandi[max(i-x, 0)][0], grandi[max(i-y, 0)][1], grandi[max(i-z, 0)][2]});
#define jjxdBrwEoBsWtBHZCzgQyxjZbkmvvPLblsMGExvQhAQQSdpmLk grandi[i][1]=mex({grandi[max(i-x, 0)][0], grandi[max(i-z, 0)][2]});
#define UoEwkqwEgLLEznkUaSBXhHLYAcayIMezDljIyNZOpsCGogxTJa grandi[i][2]=mex({grandi[max(i-x, 0)][0], grandi[max(i-y, 0)][1]});
#define GSQlLoNxVwJHyQIhZNbFcoiwoZRBxCABqpUmJvfuqHubKHQphs }
#define yqlViBUtrRqAjNACOaymQhQiWPsvMwNuDVxwWheLIMCrlwoCra int ans=0;
#define ZDcsjMlJxJOGmlXqUqzGwuJSAiTgVlPZNcCeTHhnqtaDjBtWvo int allxor=0;
#define zJwreWAXclonbYASysEYRJppzEmkLWlpINFupvijlkIhsawIWB for(int i=0;i<n;i++){
#define HLxiyEDGwpoeIUlkFzAJnqzltHoGVKsdnRRBNaNeimpfeaZpqu allxor^=getgrandi(arr[i], 0);
#define XWdhcuJuJsEeLKpQSIGekpKxGqwLzlEaWBtCxvsApbpzHhQfzP }
#define wMxKZxQDOlYzwUTTwLoWqboufgMuaIZdRrqYSasbyWMYYmUQZW for(int i=0;i<n;i++){
#define lQxNAFJXJWNGEnViLCPzBTMxuvowxQOWjvYUQpEqEyiLtlVDYr for(int j=0;j<3;j++){
#define DucduKQlciIEEIbCoJYfqiDfSipewkAPVpbqXaXFHOPfknRnjh int res=allxor;
#define NUMPOgxguvhvaeWNqKZwLncvYnybHlmqfztMHKAiIISWFZEnfA res^=getgrandi(arr[i], 0);
#define QXicjXOjnLtxVzDqjSgWUDLvaQEGzOHDlPKOYimjwlSnpMMLmk res^=getgrandi(max(arr[i]-zaebalsya[j],(ll)0), j);
#define ciOjGEGqdjnBweTLhNeYcMqULBpNnnLUnZFjajZoMTSZBBEJBa ans+=(res==0);
#define DMsDptINoUdKFFHpelyCRHWGphQgstUXlskhvLSNOVBJUbpoit }
#define xOFVYzziWdyzcdOgNBMahuCPbuFYfctLDBeqNDZCfXhCvIJQAZ }
#define KuwJYPZiAeSLEwjTlYnLmWolOwAjebMjrNlQhhBaiTnMLjrtXF cout<<ans<<endl;
#define rppjZqMkMKhFSjoOmSLyRysQrgbtlCqtpmMwdBdyBFXcGhiPzS }
#define DNYuwZNJKEFjQRuJFObJjrmwixxNtQxlzEGIMDvIvwdBbttsbZ void shit(){
#define VYahjNIwujLRYDaNZgGKpnDHRJqgzIyOvGWhPYvbwFfmAauFto per[1][1][1]={0, 2};
#define XGXFhEZZBbdVhObMrrAbcpWlXZzFJwDoAGbCxFxMSaCYbVZVFw per[1][1][2]={0, 3};
#define aTqVncMRFKxXyDLdGzyZzuZSnwNjBrZOARIyEhxwkPvatnhdJS per[1][1][3]={0, 4};
#define SsruPErFMWQtCbBywCHqaokDmmvBMytkfvCDrxQLcPbdQIBxMh per[1][1][4]={0, 5};
#define ZYKMxVMAHALZTwiyFMpQZXYJMusOlbpgiXfLRpeCMpiZihfKFk per[1][1][5]={0, 6};
#define TsnubPJPskJgUWVZDNByFASSkbMhDhzKjuAqcSaOTHQEMaWVrc per[1][2][1]={0, 3};
#define VPKQdNWBdguqUtLCuZngBBgnKbqLhZlbrgoEFuIwQMUgIAmMxq per[1][2][2]={0, 3};
#define xylaKJdscuhIFXHaLavmoygHXGiDtzSynqgUvouRkaGELydeMw per[1][2][3]={8, 4};
#define XhYxhdYsdzIPdwwHiQpiXddJtzgBcOYuJRHpAZthPnzFHbiyhL per[1][2][4]={10, 5};
#define NlKwQiucsfWXKmGmFdGjzUoPuONefQCbnUkANDMNByWQrWjJWO per[1][2][5]={0, 6};
#define iTMcNZwvFFsvXxUQHTNRKVvEHrXQHAjYZTilMwYDGBZdlFudWW per[1][3][1]={0, 4};
#define dCoIcTylHLAwnrnbBSCEYLTTvLeJpYZgBojFIOBzjwHPxvkYsT per[1][3][2]={8, 4};
#define rfpzfAYUZusnsyhmqUAUEyIeqYrGdKntFNzEVlLaEmngItOSGE per[1][3][3]={3, 2};
#define xVZVzvfUuvhhAOWuQPUpqNBCfbRrcztCwAbflJEQpAzFEAXzbg per[1][3][4]={12, 7};
#define kLnEjvuRSkHQAARCHGqMDuihfyATFBhcrHaBDGLSEeIEcwKytV per[1][3][5]={11, 2};
#define WsbOzyxDMHNWPobiFcQajwfOSMhMtILujhrybTNUiTZMZxHwVH per[1][4][1]={0, 5};
#define ujJGIvVYQpiinJnyFMjszoWBwBZuUREXawAmtAIKWRgfeyOofs per[1][4][2]={10, 5};
#define VhIfaEgalSaeCZCPWhCGgHinTVUXYEVzszISQVLSePazxflfyX per[1][4][3]={12, 7};
#define jiJVaqXedPsxnzwCoQZoBiHFbdqJNhIOmuXOEGJheDBCVmbPbF per[1][4][4]={3, 5};
#define juXMwcFxrbcAFdhUzVhMprgZVxmKGpyfGAXrUyMUvxXlwaZfep per[1][4][5]={26, 3};
#define NKYfzaLIsbwKAUfXiXzSJQgHppreADIFulsNXmSbZwHtBDShJB per[1][5][1]={0, 6};
#define VEOfuQwgQbJnilOWPIHMBNdKDTTjRylwkZLoIOaBuTaWehmHtL per[1][5][2]={0, 6};
#define KBvNmZEdelUZNnDkkgPHIBezOViXyfVJcaHPsmDZkPhvgFAZXs per[1][5][3]={11, 2};
#define TeUlbayPNfzirlXGwNPicvtrfAlnMIKMRqwhAEErieTWDGUdCg per[1][5][4]={26, 3};
#define pCceDfGXjNuXnLAKTmhigbQWXGYazjGIXAdIEWPBwKhDVjvbjH per[1][5][5]={5, 2};
#define wJBFXjhnQKzLkChUHIFuHpwMxZFMWwOUXwcFTnnrJsKqqENKZg per[2][1][1]={0, 3};
#define peajqtlEDxuSwoOmHnmVgMZZhwWThtvLWbpIJePmiVSLBjeJcQ per[2][1][2]={5, 3};
#define kqkUILdnqNtPQFixNJQbGnfhxowvudSKMiEUYtvBBsttRPcrbC per[2][1][3]={8, 4};
#define TpLCbrGimgTDrcyKFvKytcsHjLXWtuxgsHitJWtMUUPnQKfwsH per[2][1][4]={7, 5};
#define ayYXgKIGOIQWNxLxBoNZJYeeiQmnUvVzsjqKNPlcxHpmvqwVIT per[2][1][5]={11, 6};
#define lqdlXoUmYsNwephmVUMOcRgTnlfnXrvzZkDhloJoTOyJvSynRf per[2][2][1]={5, 3};
#define dOgLZCIWlGGWpzvWgMDVYwUOxdHSegpkCsjKxFKdAtVQmEwkaU per[2][2][2]={0, 4};
#define DOijLOyjnhYiHEeugcbAKeGWNEwaDwaJMyKTuHFImkUXhUaANF per[2][2][3]={0, 5};
#define HHRahrInzttMtRjofbyLyWvYoaHeCIBaDDzWRSwkWjLYJCctlp per[2][2][4]={0, 6};
#define yWrdPChpKiHmQOTyhrLWRBXvxZKaqGgATbIRCZTzYwCIxVEjAk per[2][2][5]={0, 7};
#define RDJfVNDcYWMTJHZLfYbskZIPjlihaTntlGtvPdNQmxhubUVJIs per[2][3][1]={8, 4};
#define vybEmCTDEezsUNXKfcbHfVVPvZpugYWhSnMlbbrPwitYpuAxXz per[2][3][2]={0, 5};
#define OqtNTvKyQQRnATfgbNiMaJTWzvBJEvkuaZHxqOgYCYTNrRDtdp per[2][3][3]={0, 5};
#define viLeKlRCdzBkbVSbbBTogvbURkGnbISgeXenexfluyqbdAtghm per[2][3][4]={0, 6};
#define TlQsqHQhHKrTBTZEOKCfiWvMngvusiaGljtUcoPtZpsDCPiIhC per[2][3][5]={12, 7};
#define PItskmISrTVfRpKcsNddSJxyKPCNVwWgreHhcNZsAmKyYCssLl per[2][4][1]={7, 5};
#define NaqDytsTIaQBbdpewGELaRLnrozNUCeuvYgKboqNHdOXiEjmNA per[2][4][2]={0, 6};
#define lohrPZizGdfjzsLMABdwQZImZcxzhNUThZDbhMeBbNOGXvEqRC per[2][4][3]={0, 6};
#define IOnQKBQZczBMLmsSXTVDotxGncZAseIqoppXSdhimcbAdbtUGq per[2][4][4]={0, 6};
#define yHPGhZgJVCgfkGJmFYllcXOcEmKzdwJMZcYwEoJbpjmFttWLUN per[2][4][5]={20, 7};
#define mpwIgPyOfRXUbtwdZhREbtPXinoIvdqTWyubTREICNeKIzlMeC per[2][5][1]={11, 6};
#define bfROnjSBSgUxTcXCtYOcTwtmCvfMxvjkENWRLlBCEhbtYZhMSV per[2][5][2]={0, 7};
#define iMxMtbjkxZAafiPyvcDmzQqZuMtnydRgbFsPMMilLEjinvXFma per[2][5][3]={12, 7};
#define BbqZCATbzvPgYsRPMLAkWMXVFXKnLfumxuQHeeoWUsbmjpGLfw per[2][5][4]={20, 7};
#define GtvtMrbRuybOhLsEiqMcTfQsoCnYdMHJJmJDmPhZTSheHemvcT per[2][5][5]={4, 7};
#define LmvFAGXsoRBqXYSKbMOVsnXkFxYmlfmuYMkopHoiAlBBduRNCj per[3][1][1]={3, 2};
#define rPIiyKrqHprXTpeMtFPCmZMviiGloGZrIuaktLSskidSXgdWap per[3][1][2]={8, 4};
#define rXTUtwhqlwLvWrFuLJPignhrtnKrIkvYTYAzVWvlwUdUWccknz per[3][1][3]={10, 4};
#define mILFIrmewUfkdiOEWRoABhvEJVIKnUjozAYOpTpiTORprVSExR per[3][1][4]={13, 5};
#define WNZiXJwewcVmUEyQvZuWGGOgpBbvHJpERcqJihZqZUcohNNfYp per[3][1][5]={9, 6};
#define voWpaXFMlXaAfNHfoPZibBnfkbkNmhKTfnjTrlxEfdZhLmTDdY per[3][2][1]={8, 4};
#define oTOjTvLUxNgSzvbgadCTQCLeyyNGLjkhGUQcJHlvMDoLdcsXQr per[3][2][2]={0, 5};
#define bSSvVexhmDqJvJtPYQIGNpxZNCohHspHcxyobjVSbKtwnKJtVO per[3][2][3]={7, 5};
#define LaMcwJbhkGDywNcAsDjZSviWKuaZhwiDwMPtnknHNnOqwNIpPS per[3][2][4]={11, 6};
#define NBqpSrCmxIRtudCtDpbUzLsVBlHraijeGImzKttLwsvKklugJr per[3][2][5]={12, 7};
#define oVeehbbTnNBtVrzjQGKJXObvNhBjUPOVewMVOgTdHvtpqKyjzJ per[3][3][1]={10, 4};
#define vMHkJuExdNgEGitYyoiXKYWNBelEmRlcpxfjKtszIRzTZnKUWB per[3][3][2]={7, 5};
#define ShjxRyJQyddCMrSTsDFpwVzSVIKfSSTsEXlhZzLdKeKOiycBHv per[3][3][3]={0, 6};
#define FLVgXqWSqgdxpiRmcExuJfFlBAqttHZyXYUIrAqHPPzqyPDaiv per[3][3][4]={0, 7};
#define DSOfWXPNNKkWwgvXcVAhiwteRlHnkhYsKFlWayQuzALQHyMSXA per[3][3][5]={0, 8};
#define MveDduPcmrYFRuKnEFOdWBEeAEpmjQdopsJXegDSMWovxOAMQJ per[3][4][1]={13, 5};
#define DkJMucCqryhsMXGGijrJtIAFYWhUvpUCbtAoGOagUxNcvjySkK per[3][4][2]={11, 6};
#define wzCUdDcyKFfNYmHFmsRxIuByHVFGtezdBHJcPTTQtjMoELhukA per[3][4][3]={0, 7};
#define pmodyJySqceRnnCbGSvxvTIxDzOGRYiBJxwiGDqQJqLtKSVWGv per[3][4][4]={0, 7};
#define FrEKZMxGdQMhmiPUSpGSApxDzzkFYpawtSbKpLJniexSeWugkt per[3][4][5]={0, 8};
#define aNZlqlSFYmmqcAgeEkxCxwWCiRncJoQZoKvBxlnnPFBghTOpqQ per[3][5][1]={9, 6};
#define NCiTYocsQDRzRSlNJdXMpTpGljoKGxGXFzjpcvPbpHecubyJBC per[3][5][2]={12, 7};
#define PaDGOsLSprQzPuHsMcYbmyFvYGjJQLpIkNdNuAbrPqfEAUNcMS per[3][5][3]={0, 8};
#define XDhxZvEksrrhmZSZHPNCgygDVvarHfKhtRftXVNEuplVuSzNSj per[3][5][4]={0, 8};
#define hBvxByvTRwvGSWIMzxpEamLZhINqPssyIEBDkUaooIRzfynPGP per[3][5][5]={0, 8};
#define ptGSxYlSPMutZlaqLlsGIxFEJAVRFXBhUkDAjbLyaOlfAyWvXF per[4][1][1]={3, 5};
#define fvWKrJHxzGpenMPbdNpCgUBPtIVveieIgWAiaUmTtzcVpwWJtq per[4][1][2]={14, 3};
#define GKUWEqNJuYWSRZXHAIWDSrnkDgwKzNzyAGHrNNXXVIGoUpsqDR per[4][1][3]={15, 5};
#define bXxgVCYJXkWfPkziVtxlpFnUqpKxQCBPhDvcDzulBOoNxJzjwZ per[4][1][4]={17, 5};
#define jWDtwkSAizEczGoNFObtaABMrFSSAtgAuJWFFFDKKiDxXpGWBh per[4][1][5]={22, 6};
#define zIMAHtKDKwBUxrilBxdnkCEksulaWBLXeHMzZbZujxUlOrlRvH per[4][2][1]={14, 3};
#define WHMMLjdOOOaEZDUarSldKPqEDJdimJpzdhBjeYqyCZviagWSDl per[4][2][2]={0, 6};
#define LkrrsEJGNVOUDFPcQTHeBNsyFRLtlnjCtHOBqVQggfgMLEWDMK per[4][2][3]={11, 6};
#define vLKEVIIDlSLxyTIMMiBhBMFnUlxuAhsVrMTadniMIznhyJxUiA per[4][2][4]={9, 6};
#define YSJYlmQuVvdGjSLCLQxEFLBlISyYKPeeypNRYOjntGMqLMUeSv per[4][2][5]={17, 7};
#define DgOFELdJmNAoDzzlxsCDmEEDYqwVecJzERrogTwmGjGhdxpdwA per[4][3][1]={15, 5};
#define lGhsJoWyspJCFjLEUYkdGYhKmPYnUxWbFxwBMTITDMKEQMnUeE per[4][3][2]={11, 6};
#define wGxXpOvuGYBFgHlfSwAYOQxrlRQKqOfxkQknzAlCkrZqssekBc per[4][3][3]={0, 7};
#define cMrkKlXQTMisxsIGKNAMMTqwFMcKYcWgOzAQGLxcpKrhDpwIRy per[4][3][4]={9, 7};
#define WAaVvYUksudMtWhfGeBkXxYtloTvrXwSqQVUXlrhzmCFrWvgnM per[4][3][5]={14, 8};
#define diWgGDMnfyLvvYULWxVkakTkOAMAxDSrPkqpPWNMijBeZfBOtT per[4][4][1]={17, 5};
#define jXXQpMujNVzAnpuaDByinkXruMzgLmQBGGsfxsmElSulxCvpKH per[4][4][2]={9, 6};
#define mJeQlKWBHWRQcQsaFtqQhbAeBxZcKEbiZOWAsAZIqOHhuZYowj per[4][4][3]={9, 7};
#define nPnmzzFIXFXEAxcAHnipnmvaBIqovEqIHUSCJEEnrtCKPhBszg per[4][4][4]={0, 8};
#define LaYjMWbDPJMfFYRwWGSaCWPcwAdKpaBFCFRtEhODBJppNSIoOT per[4][4][5]={0, 9};
#define nJbGYgzxxMprogmHmiZgnPAzyVlsWwAqIdIPthTHsZiGjBmOpv per[4][5][1]={22, 6};
#define aDujdKOQWHIWdMwInReVpUEuFuDhsotmSidwelFgBwrTueoLwv per[4][5][2]={17, 7};
#define uyAgQklPpEhqUkWugeXtQwuGrqFnPtvwLoYFSSDZlkqxgwMPvc per[4][5][3]={14, 8};
#define SxKMukKTQZrBJUEMZJQHEsFsPCVVJBqIDCZebVwiPaqakyORaH per[4][5][4]={0, 9};
#define MGvpuUaiIMFTIqJSMeqrkxvjSqqARWSJZspeHYumVyLkanbfsZ per[4][5][5]={0, 9};
#define ClZdMQicjMsxxEBjEptCoyHGVpsXfygsAaMIGtVwyLMWUlTDHi per[5][1][1]={5, 2};
#define qEXvehgzrjCpQgGyAHwCIsRgUdiTJYlgdRULKcFTsvJRkXiKJL per[5][1][2]={11, 3};
#define qtGvCGKSUelKViZpyDJerfbGkPmeKXJcFzpNtWFGzUbiKClRFK per[5][1][3]={12, 2};
#define JlfKUYTdZhpjxUbnoVlXOeIicMIutUNfPOgQVEqdRyvkiQiwlL per[5][1][4]={18, 6};
#define xxfqYJIURcTvOgUJCsLchvXFYMpUYuPhxOdmBfKUygkGviqpuD per[5][1][5]={26, 6};
#define xsahQTFaqYGDcNVJowviFWqIiVLGZeERBYTtuJLdvPwcSaDINI per[5][2][1]={11, 3};
#define EvLOhHbvIZSICbkXKBlXpHMNcQOwXQclXUmdrhZWOvngGceyvM per[5][2][2]={4, 7};
#define nfrwdJIiKXfYTmllmfWxteSSJzzBVEqbutymRchUnwNQZjbYra per[5][2][3]={12, 7};
#define CYRprckneRIebcPKynfBgkEBVJEqPfymOYYpnnVbHgboBdWTgF per[5][2][4]={13, 7};
#define wEntqhVPhTOSRwGWMxNuSVyRfAGCgmxeYKjTsFLEqgWguLzKHt per[5][2][5]={16, 7};
#define drUXDBjLMkxqIkCGqVNWXzVABkjQlVrtbCtTpDeBRWtsCxNqVm per[5][3][1]={12, 2};
#define oFIswGziEsvLNBWCuzmAzBqrGjFhRtqodZQqKSQifzyVOOnMFm per[5][3][2]={12, 7};
#define LwLtDWdYdwSTFVJPuGgHpgspYbDYOKxpejNqaIxrXdAvlxXVhP per[5][3][3]={0, 8};
#define veJddSbAVamwzDQGDqgmjaztStzEtDdHaxOFtInXUGDHOyFLHi per[5][3][4]={14, 8};
#define ZQmkLPbwwXKqLHFNxiOqrUnhNWpDIHjXTKbLKrCrtJcHnPDgVm per[5][3][5]={11, 8};
#define puKzEnCRHOkuaxGbCxNwbQFaJSMBpRWnjIYOLVSEUgEJeCKjnr per[5][4][1]={18, 6};
#define awQGFPpimpUhQPEvhgXhJYXAYMFfaMoMeylDvsrjlmHiJvFBeM per[5][4][2]={13, 7};
#define nUBLpodWzrSfhgwzhVABRWEgpISeqwlWgFzatMbfxlEXKOvnhv per[5][4][3]={14, 8};
#define NLQschPUNvBnNeiVvOlACcqWcwiCzRulupKLRPCFEdguFBpRup per[5][4][4]={0, 9};
#define YkevLpZUKyLfEgYLYMbwRHLiBgjUMgnBdnuutBmXzRpPVZLwXS per[5][4][5]={11, 9};
#define kAWLAxAoVHpfQMdXoZiZJbrCKNhBLSkZFNtKRTzzxxCbqyoooW per[5][5][1]={26, 6};
#define coZxrmtODpKydXmZbksuGyitipmgkNEjORwmovkgyaEkqKVzwl per[5][5][2]={16, 7};
#define GyhBVZmPAUuifMPYptMAaPOavpfUHoTXtqhkthqtNQABZFBIpF per[5][5][3]={11, 8};
#define OqvZaKygMFGfLUytHcQVPJeNGKsfrOHbMePZluIwLYRihZvjPk per[5][5][4]={11, 9};
#define ArNctlSNJXSpUYPyPvrJEksdZqPZvlDmezbBLQiLRxPXNFSyJi per[5][5][5]={0, 10};
#define IDTqXYvdyJSnOpbzkdjhMaMpYUbsEBsuwnZHnulqdzwvaqlIKM }
#define HDYXiYpJckJepNvqsTUfKHRRRRWXTSjAKftGJApMkvJgkoUCoO 
#define VLGziokaVWQQHGYsgvaARuvxOLCHMffqxXrxDZJCGnbWZNovaJ int main() {
#define VSvyOSKKGoiREAxMXCkLKRFLxEmLyEwNfqrkHTfmxptiOWBFzd ios::sync_with_stdio(false);
#define oyhKgibWkhhXZxtwLIIEpFLlqHFPCoDFtKyTFwkTNWXdoFTTzm cin.tie(nullptr);
#define yzyrlehzEamXPoKzGkxeZLhqNyFsPLlFPlDfKTZzMEYKjuVvPr 
#define tmwrIGIKYHiheWsatVvgiGftFuwQkhAYncWdoZiNKSpgJeEFCg 

#define pwRRvgDPHoOCujohRVbwwtaNJmxbOTjpvSNpJdjPLTfNNlSWbH 

#define uSGEwaxoEcvRQEdUrCmShfVvqwDJleptAXTrPOdRxbszFoekiG 

#define citPNwVYuatFxWIFuOmeYCIIiYlwaoBSKObaCqHbteRBEWDury unsigned int beg_time = clock();
#define UpPvsqNdVebCaRaGhigZPDEYnNnmHdQppzLikXOAwHLUQybXwf shit();
#define EzmbptQklliSfVaUFpyUmRNqmKfoFCpBqKesFIBAFFihMOCydn int n;
#define rKBuAEDmKehtYAOxjtXhEHQgUuktLNFFGIsDVKbbEyrAeKhgCq cin>>n;
#define bgkVxMZGSpsIEYbHxMlxUNzWkkCyTwLJHhznyCKbtjYMLuwgmS for (int i = 0; i < n; i++) solve();
#define XVhrpTdFjMMRnyESDEQWtUbJWAoqGcLrUTlVGgtbuUdtMHBfkX 
#define CfAljyeycLZIfodjtbteyTkJHEnXYCxDaDRLYtvtPoLZYSYbJA 
#define fLPxKWiTDlYpecjzjJgYfdhSzGsgBdDjxIZAdcfxcMiEsBcsDX unsigned int end_time = clock();
#define NXISJFWQRSfkOfyiZvQYESZbokggAWXCCsSIeerMUQFlAajjTl 

#define zWapKyQtkVAjoOFKpTpsXYxaOsLcllBMzdPIHGqcbCdxYxVYDY 
#define SmHilwAxHnOkiwXQaeCczEvxndZKwZKvAHDOocHVbPYoMSafNu return 0;
#define oTihSaYLpsTiKCbNxXQfxaZCTIYiROkPfmHjCIHzyuKPzdwrQr }mIjbVgmxSwEhdIaVHimRPvAlsAhwuFZJAlcJvBIjTEvHXYzscS
GOXMepGpUIbYXnWyquECsCLNMVVSKQuZjoerdyoysPWbBrYxXo
JDKNSlZsRvNGidMCETbGmBVARVzLBmrIIGqorNCBpHDoNQdPcB
dBSIyanpsLhgHvNktsRQTNQENddeNhTLMAJFIyvkdZGGzdOfpo
FJHrrWXSwwvHREoWNnuIiCBxBKOgMqKDGSjSrJpPJQvRxKZQgx
bpNXOWFOunQUqTFvzeiPINtHBoxRjLseqjdAqQoHVeHRRvtIzz
gUpjcUYGbHVucCkZFSAKVFzNcjcYrPYiomNKoReDLDVcUcnTZG
YcObjYLYMyLXwZMGlBWWIIEmSXnXORXYdmXWbIalUWiPSVqNaH
iSsXijcbuzeXBqQtkmdxMHdlDiefpeYOYhElfAIcWmJYnUZdyV
GlJBFeVpHvZxJNeWbSzgMbaFknQLveleuznmheOOwDNgKiFNEZ
lkZhPVneWfINoxBwQbmtahKlHHyiYVmRGTeiARbHSWdVFuCxxl
WRhfRDTallRXCLVaXEhbadhqqcOQuDiuaayxWwjPHTrvavzTOt
EUAibbnIDgCdLOKuEpgnYtPGHqFYoHuDpKGrYcnUCrFSMRzTOi
ExWXXEalpDiPNGAPcpgjKqkCHIiWjyzRoHYLcxFRdqQzwelGUu
vQNywfEZrzPxcszPKsgNQABXjZwOrEupikgmsEUKCyEJRRBjgb
mLEWCjedYvvSBqSDEXkDKqBkInyJoQCEekLNfsvjPyHVTFQOGT
SIfHIOPExJnzIwXCWukmKiRPoWkwspeVJcTWFcsDCfnGuCIWFL
vZRWonffGciwgUzjjvQBTyfJZRdKXKLKlIZpBThLgjvUeFDxIQ
VcLxRdVofLIfcbmtTgmERHnwutRAhibTvYqEqPvdJfWcJqVjti
fpyXjdyFXKgPsDwLJKWLznBdImsDGOrjijUUXYsnTAlUluLyGg
BBMwaqeAQTSzQLfzebEzCEIRGqsvQaalDKAeHzqmCorhiamMre
pyeEmZmTeUVlfDnuclWdwRHIJtJDQjhYgWMocRxrrqJnQYRUOQ
QChtzhYhlbRJQIEyKosJIfeJFfaXzfMWbtXWJfTMixERCkHCyu
rmOUwKBnmbcruwDYoSNbGKoOfJPXwRAbsfidYLozELwunOqIih
DtCdWwipTPjLcwTXUpPHwjjKJtbuDKbrDGvMybCKVgPnJSCtBm
kiHPdjCOMQcWVZssSerYwRyODwlPdkhdpAxxZZceJmIMalNmWQ
TVfekJvSoGjGIHnrqlUzHkGrGinFSNmMRYvtHCGoTUUviYIfbe
osZRgQmuHwTELarqlveEHYznZbtIVQOJqXzARjvCyseffYQrlT
NLlBTvYtDEEWoeTFlqGvDNXZVvAPYHYvbJODXLczQgcnhYpMvV
hSMEAlbsNPsimRWdSmFPruxWfssoBeRPcdQpTHrOVQGwjxixGD
boEWQzrCSCiRQruWScoqjeAaeDfphTZknEWwgtUAbdQzrHNAoT
OcXQVnfYsTLQtMegfDCdikuGrzfxyzWXEBJtQblTjbsSDxQyAp
VWpYUkfYylAqFxOGjatsZIgjnnCsVBpNNCnYEcPmneuGTxAJdE
aIeGnpIdNIEqbZyXMbmKpSfAWErGcDRfJBykzHeZZOoNLEUHwA
cuOOYiZKrnYzMEJAtzjqCKTOfOxnsdzBumbdbejlMPsZHLHlDE
IOppMMPTYsMxRCYhyvIpnPcPdkijSHltaYQyuNPZCBsVgKSalL
VVnsIMutgyChhKQFBfYqgpDxdlbhUQpooZXJIttdaTNuGHJGgG
HCRHgGDqUggGJxfeMeyQrKKIoOALlwvEeSFZkaMrBEsRBJCmDz
pLfROPBPvoAsxxTTWLsMplIVFmhgWasEZFZYSJFkJLGpqigiYh
OCmRCXVgAyVTjxzmoBDSZJfqjspMcteqiJEYCHjgtfVGvzvumZ
XBtaHlIzQBORJBMrpdVVYVjUooICHAQaePkYvSJdIodUCuCvGg
LJXVYGZDRQMNYOtVKcoigMRDWAzeEerUQekqmISeQxUIgUayiC
WMwaClxPMAOGJSfIVyBPhfNnavyreqdEqRDhBnVTdwQJIPwnFM
DSBAKoxqppQWtvCCONQKchYDhGBltsOpWifJojqLInDPwJXPBl
ecXRATLvLhRrJbbXwIsdMDholJLZckrOljfaocIgksGIbEJROR
INXsooZGGcEFYlSYOZbTnmyMwYMfEaqpTDfdWHTsPceGEOynen
SrUFjkRNsRnPtdgidPHlBehoAADPfGvelwkCoYSVxcvMAklyOs
WxkmBospAonOGfqmDDFfjBBlKzCZsRVuQlqCJtSdjcAMNqgIZH
fYMNLvCLRQUdHCKeebVLIBggYoMyaqlqLFjZxrsKrpbeEfvlmP
IPNSqkgtXVtVuRDHwHAOICueJvLCJLdPdZwaDGYTBxaALvqQge
SilHytvsfXJqvVamGmniLUKYcvnqwhnqLJfxNuMaBJbCvyEynT
qcLgUutERfyMpwZgtttwrhJEEovnlOzFCRadwOHxNKTIJBpWHS
EDxGdvHXRHUgLBnVtNsHSsTkNHsGMgeFeuvTLeaLteYeZIIVsW
puaHRKiyLEoQNoRALYiroEHsoFdZzqMRuNcopJWwXcDqbAXjIh
KbuFHGLpnJGGgQuMjRRmObfUoBCxKHpMEtPzVjCXgoVwxxwabu
vCdrEbapXWuniiurSHnTfLiUEVwhiLoykNSFYHmPuyRdxQzbIf
FpLldZfYJHUmhaErUPTrGwaVrFtyHArSEtMNGsExNxjxHZEiVm
opZiuSkSavJGjdErOVsWgVAryUfOTBDgPZabGAYQvCiBcokftZ
gNzJtpvSnaYdkGNQLrQqWcybYaABibpxuOrnWhlITeOqjdtDGv
YbQaoMpzdSxgqeETqHOUrpBWedCYcHdAaXTmzyUCmGGJHctnTn
HLzaTOfqsBvaDDjxOUuOLcUxheBeyBylNcImsPyrZtrrWbJynK
zoFeQgfQTibOOTUFWCxIhxIkHQyFixnWrWaJHqLpoaFcyhlgRB
aPlEyQfgBcdLTqQNLiVzlsPdBMMJbRgGNBxYuaPPeNvHpEGolK
dAhJYQywYDMoBIMBSXLXtKppZLmnfoUKJFvLIQEDNxoCyueCkg
MDBBhIeUnqYBydsBHOFtRswPprKMcAsLPMakGuAUtaMPwMSjzJ
vEYKeAPsHqddLQruzkdsyrowJemrDbbEzamkFOvURVuGbTVxJI
RiqmojGZhQTbUwFhYLKqSxhseavTXhNwqsOlbiGJedCnconjxb
bSACRpEdeIrjAwOfTPzRynvsDEasIJusWixdXPycldLGQoiCqv
eEuMxTcoGeBBLrRRCXpilqMiqHCGcnSfORYeIDgRJAnByxXyVo
GGUreRNEyZBzMbvGvHAXVVupsrVwkgjIDhPFnaiuPwvHPHJNEt
ujJfUvUvNHsNktQbLyBqQhwaBeCxbAbLGFhJjyWWXalapsXXyD
oOKbLqwganCluabTXwKvIrVKVvvEWXKDsqgrsTQfFHAdntjDsA
kWSvVmSxoHkdpyMKQXrvuBGnSuHTPVBfFCSeMfYIjNTIrDBZPk
pNerKkfGzjrGSpdshdfzuWtlwhFMmysFCtyLVJIDqSdBeZmZaM
neSVuOyrSmMRFWYObkLCYMxCspsiiGmejDDInjCWxPpkeymnin
YGaIYkTWklXoCFPMJXWcoccyOxuFBRBgJALcgQThDcUZNyALLW
xuAsNzWaROcDlGsXvxccitQtcupJfSxBSdgYukKvbUspLaRIzZ
cmboyNwvkvDmYWHhQGVtZJaqOhFLKwdvmwBJMOlTMMqGPKyCrA
jSKLAZHuXwhhJbSpIKmvJqOhBhftfRiFeTNrINhhFPkHyEDLmH
fYFYwQlmcJnQLslcgorTLYnezzGYSvDIiPzYjUVrgEkuqYycfY
naieupIgFbarNUJhYeoFWeoWKqjDWdeuwkZjrLEPfhmLgkpxHy
TVawGGNkOebVGwaRzDRmCiZNnrRgSuxexHYeRbZYfNWPrRbuwJ
QOMpNAOxHcWlbBVAShwChRkJDRCXLmpmibQZERsmQdNSFadgCX
ENNCkHPpTRVzFlJaCxoOGlOMRtBDbEopzdAPwnnwNNrLkTiDIa
kUnzOcdppbSMHghmWNpKpJDeNdmOtcQGmZWZzfKAaDyDYRDScp
wKfOTSEkXbUAEtozPBokKBDnREbYNlSbLkdGAaBaLMWpTCuJqb
jzNejisqyHVKbPSbPqgRhgLXAeEuIPEpBjQVKmdymHsqDtVRPo
CBJgFxMysRQKCFfYxnFcAvfldGNfxXzCvAiGuUUIXGBHOgNrcv
XHPWCjPCRxFuuaToPKQCTEtfsaSsssfqLHMOejAQYYgglaCQon
yhYdIyKPOMLWyjXRzgwPWklEXtsUNKSiyzGiuPWESAuSTfriAD
BsNlvVjsahlnbqddvzloEmIHNoBiVIUEjXJcxKeXcvYqcwjEwC
COXsnqwCiupxIqYuaXDsWhICjSvymwCWbZPoSVbhWUSUVGwgeD
ueHgghjlpyizbWZkkJLuJtjLrEXRqSAzeOmHSSCtblbEUUkmwQ
vkNTTjBHAoJIUOIrZTfjvYMRjRAXWkQHFGAyZmGgGlpqxjAogE
YOCxtrUNHbJbdRGWNaIbUPqaELfTHuLErruwhMdYvSEHAmmpGa
NKfcnWwjzKLbpAtIKMMkzbZGLouJoKXdFwszkQlbniYTFWYTWR
rPmVtBxPKdKiutcFMUHaaufREmMFJuYEQiBkMvAuOFKutpXTea
iuOSDyTRefRwThDubtgSbxbOfIzBTLdvndhZgaZoSxcqXgvfsa
KgKYwYVEBIcZQNpJzsdBCnYAPvoVrSvueBZjYKcVcKjyhYXIoc
hpllYNborshfADJOkpWJAfLedOxEsceMOzTDyCBRSGiZpTZkZC
oforjryfsknUfgnaZqTVJMoCaSJpoJyJkoxbByPCoXvNcniGRU
QTFbxGEAxZxDFaBMJrpdAjhmtmAXRrwjVZPMDSCUTTJxOqGqWL
cfIdBmuVjJXyaJLTeMkjqIFsgVxIHcsBsBKSOyLjcZcxIKgQwa
nKVQcGxMxwltZXcPoRcDhvNvEQbuSoTfhQdDcmyshswaWTEDvx
JQjkLaBWYMsjQuzGcYWYOLFbyuHoqntJTuSfSUGCeAJevcpAmi
JuGzgSXeWMuhuFzEXaVgpELIwlPOFBTqINfiUGbwxDGmCzKccy
WwXPUAtPPWQofRFFQeAWaGWcyvIbgYlbTIingnrOdcLDWXKnXh
vfGbsINNwkCQTqoHoVDupmOpnTDhnvfEGPooleyJLPKprkaNmI
LvVAGQmQDpMfmcABrhsmIrzRQUYbQXsmODzDQdbwkupfWzHTOj
UlTGQsOmoxrnLxPxzgxnhNizCDjpxldrJyITBEiusoxghpqVai
TapBFKCkMtdKLNehJQuVwhBRFYijqRaXeWVRxXWQZRvBgaWUql
VDIChjFTfGickRjQaIeBhEOiDgmksbfInJHEqKGkgPRAPwNpGF
muENuxESVRbbpVaVDosbiGypNgpMLHNhVbPhjeDAObkmUanOlg
dukwIpRibWjSAPLDOHQHWXtIBYfHheUKlWHeHyJqLcwasjLaSm
tuIRzEXfyhPEduBMgNaQNTRACtbSgJKvWNbYggYZbnYOiWQdZb
fstQdZlYKyjWhZNiYEKcjWzyMJfEsfhEbYaIGpWMYqtyRPTlLf
DUCgklizVFopiFDcpQBXeomBrJGKBSvTLivbUySCkHKOmxTjcJ
niTOwfHEkDcQztkUwwnlAXFNgAnDIQitbEjqLVRNUwllQsGjQo
DqvDzgcrqaAcPuSulJWcpFSIaVBYrACPyjXjpZRpuwFVsIlSfw
EyUvuVRvoeWbWurflWDcTmNIhtwDnMbFzVewOaBsHowugLEgfH
sOVrfenPGfWBgQtHdvjnerXxYQvepMvTixuNkshfJszjglCxQh
igsNhxNFimUEeBURlpWJYKueyYwKaMZRdLqxuqWMvMUqAkTKIF
HGKwRnaXBvkLUSyggZKOisUKNxVdIogCbJYjHVuNfizGqCzBrE
ALZVeIHUQYSykZwOhyKwnZAOAoDEtSWQsQneqBjIqwQXDAdSnQ
idROTcqkLZJNtMTxUlMVLfEYCBwdLEaxEewGZhnIJxMjZzByML
vwKurOGKyCKwmiroGrocDdmqWSjtHrPVyzeFTaizNQlSJRFiFR
zoajNcFLoDgNGVEWUqtCLFwSdrKJUyrOKjwetfMiCIWwJjhafk
bereRjVmISnvWndSaHowycGjtPCoZyBbWETUESprdTtrhwrzbc
ItRwnFGTrUWaYEVbWSiDWrqxEIQADwwLMVywRZNUubuLjhmorc
mWpvlPqAoqhawLtcExRwzREkemSRWRdtdpVhiehriLbDuLuIUX
pwKxROOkxGJGGuHZlMCcNTymuOfqEglUdHmqevEVOKJnLNBThC
pHZdjMmsfUjWbCDMsYkYWfqFkdWxJrNJuOOOXDMOGnqGYlUUtw
KSlxQiPZUsUULUHRpEhoBpeQAOVWQmVLjpvBqMnSbLRUsKBKPn
gOOCltTDLeQvYACqkiPhGFsMYYnStQxTlzpKVbsBPCIZAPtlJY
fJjXNkovvbpwcUnGJmBWXfPRJRDOGSUiYNMJshmyJXUFWdTalC
ScXoaPGZoQWmDDwSUeHiPoXkbxfvYEwPhONlzwvArChhKytEzC
TuOYRVKZvxawBiiQGKEuAenyfGRbaeydrFmlrRwYcUlMXbWKDa
encHiIPDkLDuiBxFfgOkjaJTXsgSxIMqmPtrUcobNwveEVtJpO
dYogKEVMTqnVQzNlFDflmuyMyOodzTSGiNmZZNFmCrYckPmHKP
irEjhuzieCxLsBEYCHaXeYAbsQzByAYZMhkWdhrbijlANJSUoh
RAvLwGutXHCQcUhnzAuaoteXHYimPibBGZwjainiganHCyAppQ
JyMTgDYJDvibgugpVFYoqrWzPsWmwHRnJYGSPxIVOlwETYUKdd
ZioLadVjNNwGNFeKfktyNwuhkNBlVKmaKGTPncKsWUcNBipszV
fXPHONaNaTgtUdtlyiXibcVBIJWROQMLLgroYTrzeWusdVVTZL
FbveUWyjplvkQeogChZVnCsuqckfIrloCIHBOEanbfRRQTzUbs
SrPNeHPIwIwBkAbNGaavPXvzmjSPtLfIsxbXYQbpKdQxJREAaz
jjxdBrwEoBsWtBHZCzgQyxjZbkmvvPLblsMGExvQhAQQSdpmLk
UoEwkqwEgLLEznkUaSBXhHLYAcayIMezDljIyNZOpsCGogxTJa
GSQlLoNxVwJHyQIhZNbFcoiwoZRBxCABqpUmJvfuqHubKHQphs
yqlViBUtrRqAjNACOaymQhQiWPsvMwNuDVxwWheLIMCrlwoCra
ZDcsjMlJxJOGmlXqUqzGwuJSAiTgVlPZNcCeTHhnqtaDjBtWvo
zJwreWAXclonbYASysEYRJppzEmkLWlpINFupvijlkIhsawIWB
HLxiyEDGwpoeIUlkFzAJnqzltHoGVKsdnRRBNaNeimpfeaZpqu
XWdhcuJuJsEeLKpQSIGekpKxGqwLzlEaWBtCxvsApbpzHhQfzP
wMxKZxQDOlYzwUTTwLoWqboufgMuaIZdRrqYSasbyWMYYmUQZW
lQxNAFJXJWNGEnViLCPzBTMxuvowxQOWjvYUQpEqEyiLtlVDYr
DucduKQlciIEEIbCoJYfqiDfSipewkAPVpbqXaXFHOPfknRnjh
NUMPOgxguvhvaeWNqKZwLncvYnybHlmqfztMHKAiIISWFZEnfA
QXicjXOjnLtxVzDqjSgWUDLvaQEGzOHDlPKOYimjwlSnpMMLmk
ciOjGEGqdjnBweTLhNeYcMqULBpNnnLUnZFjajZoMTSZBBEJBa
DMsDptINoUdKFFHpelyCRHWGphQgstUXlskhvLSNOVBJUbpoit
xOFVYzziWdyzcdOgNBMahuCPbuFYfctLDBeqNDZCfXhCvIJQAZ
KuwJYPZiAeSLEwjTlYnLmWolOwAjebMjrNlQhhBaiTnMLjrtXF
rppjZqMkMKhFSjoOmSLyRysQrgbtlCqtpmMwdBdyBFXcGhiPzS
DNYuwZNJKEFjQRuJFObJjrmwixxNtQxlzEGIMDvIvwdBbttsbZ
VYahjNIwujLRYDaNZgGKpnDHRJqgzIyOvGWhPYvbwFfmAauFto
XGXFhEZZBbdVhObMrrAbcpWlXZzFJwDoAGbCxFxMSaCYbVZVFw
aTqVncMRFKxXyDLdGzyZzuZSnwNjBrZOARIyEhxwkPvatnhdJS
SsruPErFMWQtCbBywCHqaokDmmvBMytkfvCDrxQLcPbdQIBxMh
ZYKMxVMAHALZTwiyFMpQZXYJMusOlbpgiXfLRpeCMpiZihfKFk
TsnubPJPskJgUWVZDNByFASSkbMhDhzKjuAqcSaOTHQEMaWVrc
VPKQdNWBdguqUtLCuZngBBgnKbqLhZlbrgoEFuIwQMUgIAmMxq
xylaKJdscuhIFXHaLavmoygHXGiDtzSynqgUvouRkaGELydeMw
XhYxhdYsdzIPdwwHiQpiXddJtzgBcOYuJRHpAZthPnzFHbiyhL
NlKwQiucsfWXKmGmFdGjzUoPuONefQCbnUkANDMNByWQrWjJWO
iTMcNZwvFFsvXxUQHTNRKVvEHrXQHAjYZTilMwYDGBZdlFudWW
dCoIcTylHLAwnrnbBSCEYLTTvLeJpYZgBojFIOBzjwHPxvkYsT
rfpzfAYUZusnsyhmqUAUEyIeqYrGdKntFNzEVlLaEmngItOSGE
xVZVzvfUuvhhAOWuQPUpqNBCfbRrcztCwAbflJEQpAzFEAXzbg
kLnEjvuRSkHQAARCHGqMDuihfyATFBhcrHaBDGLSEeIEcwKytV
WsbOzyxDMHNWPobiFcQajwfOSMhMtILujhrybTNUiTZMZxHwVH
ujJGIvVYQpiinJnyFMjszoWBwBZuUREXawAmtAIKWRgfeyOofs
VhIfaEgalSaeCZCPWhCGgHinTVUXYEVzszISQVLSePazxflfyX
jiJVaqXedPsxnzwCoQZoBiHFbdqJNhIOmuXOEGJheDBCVmbPbF
juXMwcFxrbcAFdhUzVhMprgZVxmKGpyfGAXrUyMUvxXlwaZfep
NKYfzaLIsbwKAUfXiXzSJQgHppreADIFulsNXmSbZwHtBDShJB
VEOfuQwgQbJnilOWPIHMBNdKDTTjRylwkZLoIOaBuTaWehmHtL
KBvNmZEdelUZNnDkkgPHIBezOViXyfVJcaHPsmDZkPhvgFAZXs
TeUlbayPNfzirlXGwNPicvtrfAlnMIKMRqwhAEErieTWDGUdCg
pCceDfGXjNuXnLAKTmhigbQWXGYazjGIXAdIEWPBwKhDVjvbjH
wJBFXjhnQKzLkChUHIFuHpwMxZFMWwOUXwcFTnnrJsKqqENKZg
peajqtlEDxuSwoOmHnmVgMZZhwWThtvLWbpIJePmiVSLBjeJcQ
kqkUILdnqNtPQFixNJQbGnfhxowvudSKMiEUYtvBBsttRPcrbC
TpLCbrGimgTDrcyKFvKytcsHjLXWtuxgsHitJWtMUUPnQKfwsH
ayYXgKIGOIQWNxLxBoNZJYeeiQmnUvVzsjqKNPlcxHpmvqwVIT
lqdlXoUmYsNwephmVUMOcRgTnlfnXrvzZkDhloJoTOyJvSynRf
dOgLZCIWlGGWpzvWgMDVYwUOxdHSegpkCsjKxFKdAtVQmEwkaU
DOijLOyjnhYiHEeugcbAKeGWNEwaDwaJMyKTuHFImkUXhUaANF
HHRahrInzttMtRjofbyLyWvYoaHeCIBaDDzWRSwkWjLYJCctlp
yWrdPChpKiHmQOTyhrLWRBXvxZKaqGgATbIRCZTzYwCIxVEjAk
RDJfVNDcYWMTJHZLfYbskZIPjlihaTntlGtvPdNQmxhubUVJIs
vybEmCTDEezsUNXKfcbHfVVPvZpugYWhSnMlbbrPwitYpuAxXz
OqtNTvKyQQRnATfgbNiMaJTWzvBJEvkuaZHxqOgYCYTNrRDtdp
viLeKlRCdzBkbVSbbBTogvbURkGnbISgeXenexfluyqbdAtghm
TlQsqHQhHKrTBTZEOKCfiWvMngvusiaGljtUcoPtZpsDCPiIhC
PItskmISrTVfRpKcsNddSJxyKPCNVwWgreHhcNZsAmKyYCssLl
NaqDytsTIaQBbdpewGELaRLnrozNUCeuvYgKboqNHdOXiEjmNA
lohrPZizGdfjzsLMABdwQZImZcxzhNUThZDbhMeBbNOGXvEqRC
IOnQKBQZczBMLmsSXTVDotxGncZAseIqoppXSdhimcbAdbtUGq
yHPGhZgJVCgfkGJmFYllcXOcEmKzdwJMZcYwEoJbpjmFttWLUN
mpwIgPyOfRXUbtwdZhREbtPXinoIvdqTWyubTREICNeKIzlMeC
bfROnjSBSgUxTcXCtYOcTwtmCvfMxvjkENWRLlBCEhbtYZhMSV
iMxMtbjkxZAafiPyvcDmzQqZuMtnydRgbFsPMMilLEjinvXFma
BbqZCATbzvPgYsRPMLAkWMXVFXKnLfumxuQHeeoWUsbmjpGLfw
GtvtMrbRuybOhLsEiqMcTfQsoCnYdMHJJmJDmPhZTSheHemvcT
LmvFAGXsoRBqXYSKbMOVsnXkFxYmlfmuYMkopHoiAlBBduRNCj
rPIiyKrqHprXTpeMtFPCmZMviiGloGZrIuaktLSskidSXgdWap
rXTUtwhqlwLvWrFuLJPignhrtnKrIkvYTYAzVWvlwUdUWccknz
mILFIrmewUfkdiOEWRoABhvEJVIKnUjozAYOpTpiTORprVSExR
WNZiXJwewcVmUEyQvZuWGGOgpBbvHJpERcqJihZqZUcohNNfYp
voWpaXFMlXaAfNHfoPZibBnfkbkNmhKTfnjTrlxEfdZhLmTDdY
oTOjTvLUxNgSzvbgadCTQCLeyyNGLjkhGUQcJHlvMDoLdcsXQr
bSSvVexhmDqJvJtPYQIGNpxZNCohHspHcxyobjVSbKtwnKJtVO
LaMcwJbhkGDywNcAsDjZSviWKuaZhwiDwMPtnknHNnOqwNIpPS
NBqpSrCmxIRtudCtDpbUzLsVBlHraijeGImzKttLwsvKklugJr
oVeehbbTnNBtVrzjQGKJXObvNhBjUPOVewMVOgTdHvtpqKyjzJ
vMHkJuExdNgEGitYyoiXKYWNBelEmRlcpxfjKtszIRzTZnKUWB
ShjxRyJQyddCMrSTsDFpwVzSVIKfSSTsEXlhZzLdKeKOiycBHv
FLVgXqWSqgdxpiRmcExuJfFlBAqttHZyXYUIrAqHPPzqyPDaiv
DSOfWXPNNKkWwgvXcVAhiwteRlHnkhYsKFlWayQuzALQHyMSXA
MveDduPcmrYFRuKnEFOdWBEeAEpmjQdopsJXegDSMWovxOAMQJ
DkJMucCqryhsMXGGijrJtIAFYWhUvpUCbtAoGOagUxNcvjySkK
wzCUdDcyKFfNYmHFmsRxIuByHVFGtezdBHJcPTTQtjMoELhukA
pmodyJySqceRnnCbGSvxvTIxDzOGRYiBJxwiGDqQJqLtKSVWGv
FrEKZMxGdQMhmiPUSpGSApxDzzkFYpawtSbKpLJniexSeWugkt
aNZlqlSFYmmqcAgeEkxCxwWCiRncJoQZoKvBxlnnPFBghTOpqQ
NCiTYocsQDRzRSlNJdXMpTpGljoKGxGXFzjpcvPbpHecubyJBC
PaDGOsLSprQzPuHsMcYbmyFvYGjJQLpIkNdNuAbrPqfEAUNcMS
XDhxZvEksrrhmZSZHPNCgygDVvarHfKhtRftXVNEuplVuSzNSj
hBvxByvTRwvGSWIMzxpEamLZhINqPssyIEBDkUaooIRzfynPGP
ptGSxYlSPMutZlaqLlsGIxFEJAVRFXBhUkDAjbLyaOlfAyWvXF
fvWKrJHxzGpenMPbdNpCgUBPtIVveieIgWAiaUmTtzcVpwWJtq
GKUWEqNJuYWSRZXHAIWDSrnkDgwKzNzyAGHrNNXXVIGoUpsqDR
bXxgVCYJXkWfPkziVtxlpFnUqpKxQCBPhDvcDzulBOoNxJzjwZ
jWDtwkSAizEczGoNFObtaABMrFSSAtgAuJWFFFDKKiDxXpGWBh
zIMAHtKDKwBUxrilBxdnkCEksulaWBLXeHMzZbZujxUlOrlRvH
WHMMLjdOOOaEZDUarSldKPqEDJdimJpzdhBjeYqyCZviagWSDl
LkrrsEJGNVOUDFPcQTHeBNsyFRLtlnjCtHOBqVQggfgMLEWDMK
vLKEVIIDlSLxyTIMMiBhBMFnUlxuAhsVrMTadniMIznhyJxUiA
YSJYlmQuVvdGjSLCLQxEFLBlISyYKPeeypNRYOjntGMqLMUeSv
DgOFELdJmNAoDzzlxsCDmEEDYqwVecJzERrogTwmGjGhdxpdwA
lGhsJoWyspJCFjLEUYkdGYhKmPYnUxWbFxwBMTITDMKEQMnUeE
wGxXpOvuGYBFgHlfSwAYOQxrlRQKqOfxkQknzAlCkrZqssekBc
cMrkKlXQTMisxsIGKNAMMTqwFMcKYcWgOzAQGLxcpKrhDpwIRy
WAaVvYUksudMtWhfGeBkXxYtloTvrXwSqQVUXlrhzmCFrWvgnM
diWgGDMnfyLvvYULWxVkakTkOAMAxDSrPkqpPWNMijBeZfBOtT
jXXQpMujNVzAnpuaDByinkXruMzgLmQBGGsfxsmElSulxCvpKH
mJeQlKWBHWRQcQsaFtqQhbAeBxZcKEbiZOWAsAZIqOHhuZYowj
nPnmzzFIXFXEAxcAHnipnmvaBIqovEqIHUSCJEEnrtCKPhBszg
LaYjMWbDPJMfFYRwWGSaCWPcwAdKpaBFCFRtEhODBJppNSIoOT
nJbGYgzxxMprogmHmiZgnPAzyVlsWwAqIdIPthTHsZiGjBmOpv
aDujdKOQWHIWdMwInReVpUEuFuDhsotmSidwelFgBwrTueoLwv
uyAgQklPpEhqUkWugeXtQwuGrqFnPtvwLoYFSSDZlkqxgwMPvc
SxKMukKTQZrBJUEMZJQHEsFsPCVVJBqIDCZebVwiPaqakyORaH
MGvpuUaiIMFTIqJSMeqrkxvjSqqARWSJZspeHYumVyLkanbfsZ
ClZdMQicjMsxxEBjEptCoyHGVpsXfygsAaMIGtVwyLMWUlTDHi
qEXvehgzrjCpQgGyAHwCIsRgUdiTJYlgdRULKcFTsvJRkXiKJL
qtGvCGKSUelKViZpyDJerfbGkPmeKXJcFzpNtWFGzUbiKClRFK
JlfKUYTdZhpjxUbnoVlXOeIicMIutUNfPOgQVEqdRyvkiQiwlL
xxfqYJIURcTvOgUJCsLchvXFYMpUYuPhxOdmBfKUygkGviqpuD
xsahQTFaqYGDcNVJowviFWqIiVLGZeERBYTtuJLdvPwcSaDINI
EvLOhHbvIZSICbkXKBlXpHMNcQOwXQclXUmdrhZWOvngGceyvM
nfrwdJIiKXfYTmllmfWxteSSJzzBVEqbutymRchUnwNQZjbYra
CYRprckneRIebcPKynfBgkEBVJEqPfymOYYpnnVbHgboBdWTgF
wEntqhVPhTOSRwGWMxNuSVyRfAGCgmxeYKjTsFLEqgWguLzKHt
drUXDBjLMkxqIkCGqVNWXzVABkjQlVrtbCtTpDeBRWtsCxNqVm
oFIswGziEsvLNBWCuzmAzBqrGjFhRtqodZQqKSQifzyVOOnMFm
LwLtDWdYdwSTFVJPuGgHpgspYbDYOKxpejNqaIxrXdAvlxXVhP
veJddSbAVamwzDQGDqgmjaztStzEtDdHaxOFtInXUGDHOyFLHi
ZQmkLPbwwXKqLHFNxiOqrUnhNWpDIHjXTKbLKrCrtJcHnPDgVm
puKzEnCRHOkuaxGbCxNwbQFaJSMBpRWnjIYOLVSEUgEJeCKjnr
awQGFPpimpUhQPEvhgXhJYXAYMFfaMoMeylDvsrjlmHiJvFBeM
nUBLpodWzrSfhgwzhVABRWEgpISeqwlWgFzatMbfxlEXKOvnhv
NLQschPUNvBnNeiVvOlACcqWcwiCzRulupKLRPCFEdguFBpRup
YkevLpZUKyLfEgYLYMbwRHLiBgjUMgnBdnuutBmXzRpPVZLwXS
kAWLAxAoVHpfQMdXoZiZJbrCKNhBLSkZFNtKRTzzxxCbqyoooW
coZxrmtODpKydXmZbksuGyitipmgkNEjORwmovkgyaEkqKVzwl
GyhBVZmPAUuifMPYptMAaPOavpfUHoTXtqhkthqtNQABZFBIpF
OqvZaKygMFGfLUytHcQVPJeNGKsfrOHbMePZluIwLYRihZvjPk
ArNctlSNJXSpUYPyPvrJEksdZqPZvlDmezbBLQiLRxPXNFSyJi
IDTqXYvdyJSnOpbzkdjhMaMpYUbsEBsuwnZHnulqdzwvaqlIKM
HDYXiYpJckJepNvqsTUfKHRRRRWXTSjAKftGJApMkvJgkoUCoO
VLGziokaVWQQHGYsgvaARuvxOLCHMffqxXrxDZJCGnbWZNovaJ
VSvyOSKKGoiREAxMXCkLKRFLxEmLyEwNfqrkHTfmxptiOWBFzd
oyhKgibWkhhXZxtwLIIEpFLlqHFPCoDFtKyTFwkTNWXdoFTTzm
yzyrlehzEamXPoKzGkxeZLhqNyFsPLlFPlDfKTZzMEYKjuVvPr
tmwrIGIKYHiheWsatVvgiGftFuwQkhAYncWdoZiNKSpgJeEFCg
pwRRvgDPHoOCujohRVbwwtaNJmxbOTjpvSNpJdjPLTfNNlSWbH
uSGEwaxoEcvRQEdUrCmShfVvqwDJleptAXTrPOdRxbszFoekiG
citPNwVYuatFxWIFuOmeYCIIiYlwaoBSKObaCqHbteRBEWDury
UpPvsqNdVebCaRaGhigZPDEYnNnmHdQppzLikXOAwHLUQybXwf
EzmbptQklliSfVaUFpyUmRNqmKfoFCpBqKesFIBAFFihMOCydn
rKBuAEDmKehtYAOxjtXhEHQgUuktLNFFGIsDVKbbEyrAeKhgCq
bgkVxMZGSpsIEYbHxMlxUNzWkkCyTwLJHhznyCKbtjYMLuwgmS
XVhrpTdFjMMRnyESDEQWtUbJWAoqGcLrUTlVGgtbuUdtMHBfkX
CfAljyeycLZIfodjtbteyTkJHEnXYCxDaDRLYtvtPoLZYSYbJA
fLPxKWiTDlYpecjzjJgYfdhSzGsgBdDjxIZAdcfxcMiEsBcsDX
NXISJFWQRSfkOfyiZvQYESZbokggAWXCCsSIeerMUQFlAajjTl
zWapKyQtkVAjoOFKpTpsXYxaOsLcllBMzdPIHGqcbCdxYxVYDY
SmHilwAxHnOkiwXQaeCczEvxndZKwZKvAHDOocHVbPYoMSafNu
oTihSaYLpsTiKCbNxXQfxaZCTIYiROkPfmHjCIHzyuKPzdwrQr
