#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <bits/stdc++.h>
#define ReplacementFor_N 524289
#define ReplacementFor_uint unsigned int
#define ReplacementFor_uint64 unsigned long long
constexpr ReplacementFor_uint Max_size=(0x1394+3247-0x2042)<<
(0x1c30+1107-0x206e)|(0x8ef+6681-0x2303);constexpr ReplacementFor_uint 
ReplacementFor_g=(0x171d+573-0x1957),ReplacementFor_Mod=998244353;inline 
ReplacementFor_uint ReplacementFor_norm_2(const ReplacementFor_uint 
ReplacementFor_x){return ReplacementFor_x<ReplacementFor_Mod*(0x51f+1015-0x914)?
ReplacementFor_x:ReplacementFor_x-ReplacementFor_Mod*(0x4e0+7384-0x21b6);}inline
 ReplacementFor_uint norm(const ReplacementFor_uint ReplacementFor_x){return 
ReplacementFor_x<ReplacementFor_Mod?ReplacementFor_x:ReplacementFor_x-
ReplacementFor_Mod;}struct ReplacementFor_Z{ReplacementFor_uint ReplacementFor_v
;ReplacementFor_Z(){}ReplacementFor_Z(const ReplacementFor_uint 
ReplacementFor__v):ReplacementFor_v(ReplacementFor__v){}};inline 
ReplacementFor_Z operator+(const ReplacementFor_Z ReplacementFor_x1,const 
ReplacementFor_Z ReplacementFor_x2){return norm(ReplacementFor_x1.
ReplacementFor_v+ReplacementFor_x2.ReplacementFor_v);}inline ReplacementFor_Z 
operator-(const ReplacementFor_Z ReplacementFor_x1,const ReplacementFor_Z 
ReplacementFor_x2){return norm(ReplacementFor_x1.ReplacementFor_v+
ReplacementFor_Mod-ReplacementFor_x2.ReplacementFor_v);}inline ReplacementFor_Z 
operator-(const ReplacementFor_Z ReplacementFor_x){return ReplacementFor_x.
ReplacementFor_v?ReplacementFor_Mod-ReplacementFor_x.ReplacementFor_v:
(0x1237+1628-0x1893);}inline ReplacementFor_Z operator*(const ReplacementFor_Z 
ReplacementFor_x1,const ReplacementFor_Z ReplacementFor_x2){return static_cast<
ReplacementFor_uint64>(ReplacementFor_x1.ReplacementFor_v)*ReplacementFor_x2.
ReplacementFor_v%ReplacementFor_Mod;}inline ReplacementFor_Z&operator+=(
ReplacementFor_Z&ReplacementFor_x1,const ReplacementFor_Z ReplacementFor_x2){
return ReplacementFor_x1=ReplacementFor_x1+ReplacementFor_x2;}inline 
ReplacementFor_Z&operator-=(ReplacementFor_Z&ReplacementFor_x1,const 
ReplacementFor_Z ReplacementFor_x2){return ReplacementFor_x1=ReplacementFor_x1-
ReplacementFor_x2;}inline ReplacementFor_Z&operator*=(ReplacementFor_Z&
ReplacementFor_x1,const ReplacementFor_Z ReplacementFor_x2){return 
ReplacementFor_x1=ReplacementFor_x1*ReplacementFor_x2;}ReplacementFor_Z 
ReplacementFor_Power(ReplacementFor_Z Base,int Exp){ReplacementFor_Z 
ReplacementFor_res=(0x1f9d+1237-0x2471);for(;Exp;Base*=Base,Exp>>=
(0x11ca+1993-0x1992))if(Exp&(0x343+6471-0x1c89))ReplacementFor_res*=Base;return 
ReplacementFor_res;}inline ReplacementFor_uint ReplacementFor_mf(
ReplacementFor_uint ReplacementFor_x){return(static_cast<ReplacementFor_uint64>(
ReplacementFor_x)<<(0x11a0+3373-0x1ead))/ReplacementFor_Mod;}int size;
ReplacementFor_uint ReplacementFor_w[Max_size],ReplacementFor_w_q[Max_size];
inline ReplacementFor_uint ReplacementFor_mult_Shoup_2(const ReplacementFor_uint
 ReplacementFor_x,const ReplacementFor_uint ReplacementFor_y,const 
ReplacementFor_uint ReplacementFor_y_q){ReplacementFor_uint ReplacementFor_q=
static_cast<ReplacementFor_uint64>(ReplacementFor_x)*ReplacementFor_y_q>>
(0x1748+2851-0x224b);return ReplacementFor_x*ReplacementFor_y-ReplacementFor_q*
ReplacementFor_Mod;}inline ReplacementFor_uint ReplacementFor_mult_Shoup(const 
ReplacementFor_uint ReplacementFor_x,const ReplacementFor_uint ReplacementFor_y,
const ReplacementFor_uint ReplacementFor_y_q){return norm(
ReplacementFor_mult_Shoup_2(ReplacementFor_x,ReplacementFor_y,ReplacementFor_y_q
));}inline ReplacementFor_uint ReplacementFor_mult_Shoup_q(const 
ReplacementFor_uint ReplacementFor_x,const ReplacementFor_uint ReplacementFor_y,
const ReplacementFor_uint ReplacementFor_y_q){ReplacementFor_uint 
ReplacementFor_q=static_cast<ReplacementFor_uint64>(ReplacementFor_x)*
ReplacementFor_y_q>>(0x224+5687-0x183b);return ReplacementFor_q+(
ReplacementFor_x*ReplacementFor_y-ReplacementFor_q*ReplacementFor_Mod>=
ReplacementFor_Mod);}inline void init(int ReplacementFor_n){for(size=
(0xc41+5202-0x2091);size<ReplacementFor_n;size<<=(0x169c+328-0x17e3));
ReplacementFor_uint ReplacementFor_pr=ReplacementFor_Power(ReplacementFor_g,(
ReplacementFor_Mod-(0x1990+1135-0x1dfe))/size).ReplacementFor_v;
ReplacementFor_uint ReplacementFor_pr_q=(static_cast<ReplacementFor_uint64>(
ReplacementFor_pr)<<(0x822+3450-0x157c))/ReplacementFor_Mod;ReplacementFor_uint 
ReplacementFor_pr_r=(static_cast<ReplacementFor_uint64>(ReplacementFor_pr)<<
(0x321+6410-0x1c0b))%ReplacementFor_Mod;size>>=(0x6d8+7314-0x2369);
ReplacementFor_w[size]=(0x217f+139-0x2209),ReplacementFor_w_q[size]=(static_cast
<ReplacementFor_uint64>(ReplacementFor_w[size])<<(0x167a+3934-0x25b8))/
ReplacementFor_Mod;
#define ReplacementFor_compute(ReplacementFor_r, ReplacementFor_r_q, \
ReplacementFor_b, ReplacementFor_b_q)\
    do\
    {\
        ReplacementFor_uint ReplacementFor_x = ReplacementFor_b;\
        ReplacementFor_uint64 ReplacementFor_p = static_cast<\
ReplacementFor_uint64>(ReplacementFor_x) * ReplacementFor_pr_q;\
        ReplacementFor_uint ReplacementFor_q = ReplacementFor_p >> \
(0x1887+221-0x1944);\
        ReplacementFor_r = norm(ReplacementFor_x * ReplacementFor_pr - \
ReplacementFor_q * ReplacementFor_Mod);\
        ReplacementFor_r_q = static_cast<ReplacementFor_uint>(ReplacementFor_p) \
+ ReplacementFor_mult_Shoup_q(ReplacementFor_pr_r, ReplacementFor_b, \
ReplacementFor_b_q);\
    } while ((0x14bc+1512-0x1aa4))
if(size<=(0xdfc+4698-0x2052)){for(int ReplacementFor_i=(0x1e4c+419-0x1fee);
ReplacementFor_i!=size;++ReplacementFor_i)ReplacementFor_compute(
ReplacementFor_w[size+ReplacementFor_i],ReplacementFor_w_q[size+ReplacementFor_i
],ReplacementFor_w[size+ReplacementFor_i-(0x17f1+548-0x1a14)],ReplacementFor_w_q
[size+ReplacementFor_i-(0xafb+457-0xcc3)]);}else{for(int ReplacementFor_i=
(0xf9b+3935-0x1ef9);ReplacementFor_i!=(0x141a+2736-0x1ec2);++ReplacementFor_i)
ReplacementFor_compute(ReplacementFor_w[size+ReplacementFor_i],
ReplacementFor_w_q[size+ReplacementFor_i],ReplacementFor_w[size+ReplacementFor_i
-(0x1a8c+3181-0x26f8)],ReplacementFor_w_q[size+ReplacementFor_i-
(0x842+1552-0xe51)]);ReplacementFor_pr=ReplacementFor_w[size+(0x5ea+6858-0x20b0)
],ReplacementFor_pr_q=ReplacementFor_w_q[size+(0xb09+7001-0x265e)],
ReplacementFor_pr_r=-ReplacementFor_pr_q*ReplacementFor_Mod;for(int 
ReplacementFor_i=(0x18fa+2692-0x2376);ReplacementFor_i!=size;ReplacementFor_i+=
(0xa4d+4063-0x1a28)){ReplacementFor_compute(ReplacementFor_w[size+
ReplacementFor_i+(0x1937+1496-0x1f0f)],ReplacementFor_w_q[size+ReplacementFor_i+
(0x912+3971-0x1895)],ReplacementFor_w[size+ReplacementFor_i-(0x1d09+1012-0x20f9)
],ReplacementFor_w_q[size+ReplacementFor_i-(0xe56+2766-0x1920)]);
ReplacementFor_compute(ReplacementFor_w[size+ReplacementFor_i+
(0x739+6313-0x1fe1)],ReplacementFor_w_q[size+ReplacementFor_i+
(0x8ec+4848-0x1bdb)],ReplacementFor_w[size+ReplacementFor_i-(0x1c2a+1666-0x22a9)
],ReplacementFor_w_q[size+ReplacementFor_i-(0x1b3+5493-0x1725)]);
ReplacementFor_compute(ReplacementFor_w[size+ReplacementFor_i+
(0x379+8603-0x2512)],ReplacementFor_w_q[size+ReplacementFor_i+
(0x102d+2930-0x1b9d)],ReplacementFor_w[size+ReplacementFor_i-(0x368+6591-0x1d25)
],ReplacementFor_w_q[size+ReplacementFor_i-(0x21a+7641-0x1ff1)]);
ReplacementFor_compute(ReplacementFor_w[size+ReplacementFor_i+(0x6d1+1696-0xd6e)
],ReplacementFor_w_q[size+ReplacementFor_i+(0xe31+1762-0x1510)],ReplacementFor_w
[size+ReplacementFor_i-(0xd2+9137-0x2482)],ReplacementFor_w_q[size+
ReplacementFor_i-(0x776+1208-0xc2d)]);}}for(int ReplacementFor_i=size-
(0x1762+2404-0x20c5);ReplacementFor_i;--ReplacementFor_i)ReplacementFor_w[
ReplacementFor_i]=ReplacementFor_w[ReplacementFor_i*(0x452+3198-0x10ce)],
ReplacementFor_w_q[ReplacementFor_i]=ReplacementFor_w_q[ReplacementFor_i*
(0x141+8788-0x2393)];size<<=(0xfd+2325-0xa11);}inline void 
ReplacementFor_DFT_fr_2(ReplacementFor_Z ReplacementFor__A[],const int 
ReplacementFor_L){if(ReplacementFor_L==(0x12ba+404-0x144d))return;
ReplacementFor_uint*ReplacementFor_A=reinterpret_cast<ReplacementFor_uint*>(
ReplacementFor__A);
#define ReplacementFor_butterfly1(ReplacementFor_a, ReplacementFor_b)\
    do\
    {\
        ReplacementFor_uint ReplacementFor__a = ReplacementFor_a, \
ReplacementFor__b = ReplacementFor_b;\
        ReplacementFor_uint ReplacementFor_x = ReplacementFor_norm_2(\
ReplacementFor__a + ReplacementFor__b), ReplacementFor_y = ReplacementFor_norm_2\
(ReplacementFor__a + ReplacementFor_Mod * (0x1cb+4993-0x154a) - \
ReplacementFor__b);\
        ReplacementFor_a = ReplacementFor_x, ReplacementFor_b = ReplacementFor_y\
;\
    } while ((0x19b2+2275-0x2295))
if(ReplacementFor_L==(0x756+2498-0x1116)){ReplacementFor_butterfly1(
ReplacementFor_A[(0xf15+572-0x1151)],ReplacementFor_A[(0x2b6+7068-0x1e51)]);
return;}
#define ReplacementFor_butterfly(ReplacementFor_a, ReplacementFor_b, \
ReplacementFor__w, ReplacementFor__w_q)\
    do\
    {\
        ReplacementFor_uint ReplacementFor__a = ReplacementFor_a, \
ReplacementFor__b = ReplacementFor_b;\
        ReplacementFor_uint ReplacementFor_x = ReplacementFor_norm_2(\
ReplacementFor__a + ReplacementFor__b), ReplacementFor_y = \
ReplacementFor_mult_Shoup_2(ReplacementFor__a + ReplacementFor_Mod * \
(0x1243+2933-0x1db6) - ReplacementFor__b, ReplacementFor__w, ReplacementFor__w_q\
);\
        ReplacementFor_a = ReplacementFor_x, ReplacementFor_b = ReplacementFor_y\
;\
    } while ((0x1e4b+982-0x2221))
if(ReplacementFor_L==(0x744+4058-0x171a)){ReplacementFor_butterfly1(
ReplacementFor_A[(0xcb+6114-0x18ad)],ReplacementFor_A[(0x396+2744-0xe4c)]);
ReplacementFor_butterfly(ReplacementFor_A[(0x7d6+2705-0x1266)],ReplacementFor_A[
(0x1993+2355-0x22c3)],ReplacementFor_w[(0x10b6+5355-0x259e)],ReplacementFor_w_q[
(0xb57+4832-0x1e34)]);ReplacementFor_butterfly1(ReplacementFor_A[
(0xa5a+4377-0x1b73)],ReplacementFor_A[(0x1f7a+1786-0x2673)]);
ReplacementFor_butterfly1(ReplacementFor_A[(0x1bd+4464-0x132b)],ReplacementFor_A
[(0xd66+5466-0x22bd)]);return;}for(int ReplacementFor_d=ReplacementFor_L>>
(0xb+5182-0x1448);ReplacementFor_d!=(0xd50+3442-0x1abe);ReplacementFor_d>>=
(0x1f81+1173-0x2415))for(int ReplacementFor_i=(0x167d+359-0x17e4);
ReplacementFor_i!=ReplacementFor_L;ReplacementFor_i+=ReplacementFor_d<<
(0xc11+5164-0x203c))for(int ReplacementFor_j=(0x1ae4+2899-0x2637);
ReplacementFor_j!=ReplacementFor_d;ReplacementFor_j+=(0x1604+1567-0x1c1f)){
ReplacementFor_butterfly(ReplacementFor_A[ReplacementFor_i+ReplacementFor_j+
(0x77a+2349-0x10a7)],ReplacementFor_A[ReplacementFor_i+ReplacementFor_d+
ReplacementFor_j+(0x11b1+3986-0x2143)],ReplacementFor_w[ReplacementFor_d+
ReplacementFor_j+(0x164a+2653-0x20a7)],ReplacementFor_w_q[ReplacementFor_d+
ReplacementFor_j+(0x21fa+1174-0x2690)]);ReplacementFor_butterfly(
ReplacementFor_A[ReplacementFor_i+ReplacementFor_j+(0xdc4+1297-0x12d4)],
ReplacementFor_A[ReplacementFor_i+ReplacementFor_d+ReplacementFor_j+
(0x687+6221-0x1ed3)],ReplacementFor_w[ReplacementFor_d+ReplacementFor_j+
(0x1269+2676-0x1cdc)],ReplacementFor_w_q[ReplacementFor_d+ReplacementFor_j+
(0x1678+502-0x186d)]);ReplacementFor_butterfly(ReplacementFor_A[ReplacementFor_i
+ReplacementFor_j+(0xbcb+3627-0x19f4)],ReplacementFor_A[ReplacementFor_i+
ReplacementFor_d+ReplacementFor_j+(0x640+1233-0xb0f)],ReplacementFor_w[
ReplacementFor_d+ReplacementFor_j+(0xaac+1075-0xedd)],ReplacementFor_w_q[
ReplacementFor_d+ReplacementFor_j+(0x738+3031-0x130d)]);ReplacementFor_butterfly
(ReplacementFor_A[ReplacementFor_i+ReplacementFor_j+(0x1946+1747-0x2016)],
ReplacementFor_A[ReplacementFor_i+ReplacementFor_d+ReplacementFor_j+
(0xa97+4437-0x1be9)],ReplacementFor_w[ReplacementFor_d+ReplacementFor_j+
(0xe80+4802-0x213f)],ReplacementFor_w_q[ReplacementFor_d+ReplacementFor_j+
(0xcd2+5216-0x212f)]);}for(int ReplacementFor_i=(0x1a32+1440-0x1fd2);
ReplacementFor_i!=ReplacementFor_L;ReplacementFor_i+=(0xcb9+4423-0x1df8)){
ReplacementFor_butterfly1(ReplacementFor_A[ReplacementFor_i+(0x13e3+2136-0x1c3b)
],ReplacementFor_A[ReplacementFor_i+(0xcc9+2662-0x172b)]);
ReplacementFor_butterfly(ReplacementFor_A[ReplacementFor_i+(0x1002+2061-0x180e)]
,ReplacementFor_A[ReplacementFor_i+(0x105f+5465-0x25b3)],ReplacementFor_w[
(0xfdd+3774-0x1e96)],ReplacementFor_w_q[(0x1d70+2412-0x26d7)]);
ReplacementFor_butterfly(ReplacementFor_A[ReplacementFor_i+(0x14a4+3305-0x218b)]
,ReplacementFor_A[ReplacementFor_i+(0x1830+3512-0x25e2)],ReplacementFor_w[
(0xddb+3632-0x1c05)],ReplacementFor_w_q[(0x167c+1174-0x1b0c)]);
ReplacementFor_butterfly(ReplacementFor_A[ReplacementFor_i+(0x1a6+1281-0x6a4)],
ReplacementFor_A[ReplacementFor_i+(0xfe1+2238-0x1898)],ReplacementFor_w[
(0x9e9+2561-0x13e3)],ReplacementFor_w_q[(0xc3c+907-0xfc0)]);}for(int 
ReplacementFor_i=(0xf86+4972-0x22f2);ReplacementFor_i!=ReplacementFor_L;
ReplacementFor_i+=(0xa90+3568-0x1878)){ReplacementFor_butterfly1(
ReplacementFor_A[ReplacementFor_i+(0x10c4+3675-0x1f1f)],ReplacementFor_A[
ReplacementFor_i+(0x1906+2915-0x2467)]);ReplacementFor_butterfly(
ReplacementFor_A[ReplacementFor_i+(0x110+688-0x3bf)],ReplacementFor_A[
ReplacementFor_i+(0x14ff+1021-0x18f9)],ReplacementFor_w[(0x118a+5422-0x26b5)],
ReplacementFor_w_q[(0x2462+678-0x2705)]);ReplacementFor_butterfly1(
ReplacementFor_A[ReplacementFor_i+(0xf9+1596-0x731)],ReplacementFor_A[
ReplacementFor_i+(0x66b+7457-0x2386)]);ReplacementFor_butterfly(ReplacementFor_A
[ReplacementFor_i+(0xacd+585-0xd11)],ReplacementFor_A[ReplacementFor_i+
(0xabc+5679-0x20e4)],ReplacementFor_w[(0x484+1673-0xb0a)],ReplacementFor_w_q[
(0x105+8658-0x22d4)]);}for(int ReplacementFor_i=(0x62c+7158-0x2222);
ReplacementFor_i!=ReplacementFor_L;ReplacementFor_i+=(0x16c0+1176-0x1b50)){
ReplacementFor_butterfly1(ReplacementFor_A[ReplacementFor_i+(0x142+8901-0x2407)]
,ReplacementFor_A[ReplacementFor_i+(0x98f+5761-0x200f)]);
ReplacementFor_butterfly1(ReplacementFor_A[ReplacementFor_i+(0xfa7+249-0x109e)],
ReplacementFor_A[ReplacementFor_i+(0x2af+4236-0x1338)]);
ReplacementFor_butterfly1(ReplacementFor_A[ReplacementFor_i+(0x1316+4200-0x237a)
],ReplacementFor_A[ReplacementFor_i+(0xc1f+2212-0x14be)]);
ReplacementFor_butterfly1(ReplacementFor_A[ReplacementFor_i+(0x896+7666-0x2682)]
,ReplacementFor_A[ReplacementFor_i+(0x7d8+1398-0xd47)]);}
#undef ReplacementFor_butterfly1
#undef ReplacementFor_butterfly
}inline void ReplacementFor_IDFT_fr(ReplacementFor_Z ReplacementFor__A[],const 
int ReplacementFor_L){if(ReplacementFor_L==(0xf84+2421-0x18f8))return;
ReplacementFor_uint*ReplacementFor_A=reinterpret_cast<ReplacementFor_uint*>(
ReplacementFor__A);
#define ReplacementFor_butterfly1(ReplacementFor_a, ReplacementFor_b)\
    do\
    {\
        ReplacementFor_uint ReplacementFor__a = ReplacementFor_a, \
ReplacementFor__b = ReplacementFor_b;\
        ReplacementFor_uint ReplacementFor_x = ReplacementFor_norm_2(\
ReplacementFor__a), ReplacementFor_t = ReplacementFor_norm_2(ReplacementFor__b);\
        ReplacementFor_a = ReplacementFor_x + ReplacementFor_t, ReplacementFor_b\
 = ReplacementFor_x + ReplacementFor_Mod * (0x26d+3549-0x1048) - \
ReplacementFor_t;\
    } while ((0x8bb+6329-0x2174))
if(ReplacementFor_L==(0x1b91+1756-0x226b)){ReplacementFor_butterfly1(
ReplacementFor_A[(0x11f+6670-0x1b2d)],ReplacementFor_A[(0x835+1345-0xd75)]);
ReplacementFor_A[(0x767+5474-0x1cc9)]=norm(ReplacementFor_norm_2(
ReplacementFor_A[(0xa49+1275-0xf44)])),ReplacementFor_A[(0x9f8+5807-0x20a7)]=
ReplacementFor_A[(0xf59+3780-0x1e1d)]&(0xf13+657-0x11a3)?ReplacementFor_A[
(0x16cd+3718-0x2553)]+ReplacementFor_Mod:ReplacementFor_A[(0x1da+7576-0x1f72)],
ReplacementFor_A[(0x4f+7004-0x1bab)]/=(0x1b8c+2675-0x25fd);ReplacementFor_A[
(0x107d+1418-0x1606)]=norm(ReplacementFor_norm_2(ReplacementFor_A[
(0x5f+7227-0x1c99)])),ReplacementFor_A[(0xf85+4223-0x2003)]=ReplacementFor_A[
(0x14c1+2919-0x2027)]&(0x677+3967-0x15f5)?ReplacementFor_A[(0xb0c+3216-0x179b)]+
ReplacementFor_Mod:ReplacementFor_A[(0x1d7+7081-0x1d7f)],ReplacementFor_A[
(0x673+4874-0x197c)]/=(0x1080+2780-0x1b5a);return;}
#define ReplacementFor_butterfly(ReplacementFor_a, ReplacementFor_b, \
ReplacementFor__w, ReplacementFor__w_q)\
    do\
    {\
        ReplacementFor_uint ReplacementFor__a = ReplacementFor_a, \
ReplacementFor__b = ReplacementFor_b;\
        ReplacementFor_uint ReplacementFor_x = ReplacementFor_norm_2(\
ReplacementFor__a), ReplacementFor_t = ReplacementFor_mult_Shoup_2(\
ReplacementFor__b, ReplacementFor__w, ReplacementFor__w_q);\
        ReplacementFor_a = ReplacementFor_x + ReplacementFor_t, ReplacementFor_b\
 = ReplacementFor_x + ReplacementFor_Mod * (0x196f+3391-0x26ac) - \
ReplacementFor_t;\
    } while ((0x2f3+6371-0x1bd6))
if(ReplacementFor_L==(0xca8+4752-0x1f34)){ReplacementFor_butterfly1(
ReplacementFor_A[(0x1458+2534-0x1e3e)],ReplacementFor_A[(0x57c+8247-0x25b2)]);
ReplacementFor_butterfly1(ReplacementFor_A[(0x1d6a+1577-0x2391)],
ReplacementFor_A[(0x5b4+4267-0x165c)]);ReplacementFor_butterfly1(
ReplacementFor_A[(0x123a+4154-0x2274)],ReplacementFor_A[(0x2031+1394-0x25a1)]);
ReplacementFor_butterfly(ReplacementFor_A[(0x14fb+2406-0x1e60)],ReplacementFor_A
[(0x8d9+2260-0x11aa)],ReplacementFor_w[(0x1520+81-0x156e)],ReplacementFor_w_q[
(0x13f5+2811-0x1eed)]);std::swap(ReplacementFor_A[(0x1548+2423-0x1ebe)],
ReplacementFor_A[(0x1dd3+2032-0x25c0)]);for(int ReplacementFor_i=
(0xaef+2924-0x165b);ReplacementFor_i!=ReplacementFor_L;++ReplacementFor_i){
ReplacementFor_uint64 ReplacementFor_m=-ReplacementFor_A[ReplacementFor_i]&
(0x134b+4989-0x26c5);ReplacementFor_A[ReplacementFor_i]=norm((ReplacementFor_A[
ReplacementFor_i]+ReplacementFor_m*ReplacementFor_Mod)>>(0x196c+1597-0x1fa7));}
return;}for(int ReplacementFor_i=(0x42c+2811-0xf27);ReplacementFor_i!=
ReplacementFor_L;ReplacementFor_i+=(0x1a2+293-0x2bf)){ReplacementFor_butterfly1(
ReplacementFor_A[ReplacementFor_i+(0x174c+1496-0x1d24)],ReplacementFor_A[
ReplacementFor_i+(0x14e8+1961-0x1c90)]);ReplacementFor_butterfly1(
ReplacementFor_A[ReplacementFor_i+(0x63f+4-0x641)],ReplacementFor_A[
ReplacementFor_i+(0x1c9+7451-0x1ee1)]);ReplacementFor_butterfly1(
ReplacementFor_A[ReplacementFor_i+(0x68b+612-0x8eb)],ReplacementFor_A[
ReplacementFor_i+(0xfa3+1206-0x1454)]);ReplacementFor_butterfly1(
ReplacementFor_A[ReplacementFor_i+(0x883+861-0xbda)],ReplacementFor_A[
ReplacementFor_i+(0x3d1+7678-0x21c8)]);}for(int ReplacementFor_i=
(0x113+5519-0x16a2);ReplacementFor_i!=ReplacementFor_L;ReplacementFor_i+=
(0x1497+4603-0x268a)){ReplacementFor_butterfly1(ReplacementFor_A[
ReplacementFor_i+(0xa95+2318-0x13a3)],ReplacementFor_A[ReplacementFor_i+
(0x978+4824-0x1c4e)]);ReplacementFor_butterfly(ReplacementFor_A[ReplacementFor_i
+(0x19ba+1031-0x1dc0)],ReplacementFor_A[ReplacementFor_i+(0x3a6+5180-0x17df)],
ReplacementFor_w[(0xd76+3708-0x1bef)],ReplacementFor_w_q[(0xf1a+3253-0x1bcc)]);
ReplacementFor_butterfly1(ReplacementFor_A[ReplacementFor_i+(0x659+5269-0x1aea)]
,ReplacementFor_A[ReplacementFor_i+(0xebf+175-0xf68)]);ReplacementFor_butterfly(
ReplacementFor_A[ReplacementFor_i+(0x22ef+295-0x2411)],ReplacementFor_A[
ReplacementFor_i+(0x1a42+131-0x1abe)],ReplacementFor_w[(0x2cd+4654-0x14f8)],
ReplacementFor_w_q[(0x20b+8536-0x2360)]);}for(int ReplacementFor_i=
(0x98c+4932-0x1cd0);ReplacementFor_i!=ReplacementFor_L;ReplacementFor_i+=
(0x179d+2412-0x2101)){ReplacementFor_butterfly1(ReplacementFor_A[
ReplacementFor_i+(0x1066+536-0x127e)],ReplacementFor_A[ReplacementFor_i+
(0xf65+5266-0x23f3)]);ReplacementFor_butterfly(ReplacementFor_A[ReplacementFor_i
+(0x81a+3601-0x162a)],ReplacementFor_A[ReplacementFor_i+(0x129d+1148-0x1714)],
ReplacementFor_w[(0x9f6+2714-0x148b)],ReplacementFor_w_q[(0x2ff+7731-0x212d)]);
ReplacementFor_butterfly(ReplacementFor_A[ReplacementFor_i+(0x16a7+2229-0x1f5a)]
,ReplacementFor_A[ReplacementFor_i+(0xd71+38-0xd91)],ReplacementFor_w[
(0x6c6+4154-0x16fa)],ReplacementFor_w_q[(0x268+6368-0x1b42)]);
ReplacementFor_butterfly(ReplacementFor_A[ReplacementFor_i+(0x12f6+4560-0x24c3)]
,ReplacementFor_A[ReplacementFor_i+(0xcb6+5597-0x228c)],ReplacementFor_w[
(0x328+3461-0x10a6)],ReplacementFor_w_q[(0x618+8311-0x2688)]);}for(int 
ReplacementFor_d=(0x221+4296-0x12e1);ReplacementFor_d!=ReplacementFor_L;
ReplacementFor_d<<=(0x1608+2951-0x218e))for(int ReplacementFor_i=
(0x1721+3835-0x261c);ReplacementFor_i!=ReplacementFor_L;ReplacementFor_i+=
ReplacementFor_d<<(0xf69+5190-0x23ae))for(int ReplacementFor_j=
(0x1116+1078-0x154c);ReplacementFor_j!=ReplacementFor_d;ReplacementFor_j+=
(0x1bd+8692-0x23ad)){ReplacementFor_butterfly(ReplacementFor_A[ReplacementFor_i+
ReplacementFor_j+(0xba8+2177-0x1429)],ReplacementFor_A[ReplacementFor_i+
ReplacementFor_d+ReplacementFor_j+(0x114b+417-0x12ec)],ReplacementFor_w[
ReplacementFor_d+ReplacementFor_j+(0x6d5+149-0x76a)],ReplacementFor_w_q[
ReplacementFor_d+ReplacementFor_j+(0x1cd7+1738-0x23a1)]);
ReplacementFor_butterfly(ReplacementFor_A[ReplacementFor_i+ReplacementFor_j+
(0x65c+7336-0x2303)],ReplacementFor_A[ReplacementFor_i+ReplacementFor_d+
ReplacementFor_j+(0x1b15+2683-0x258f)],ReplacementFor_w[ReplacementFor_d+
ReplacementFor_j+(0xdb1+1789-0x14ad)],ReplacementFor_w_q[ReplacementFor_d+
ReplacementFor_j+(0x228+8321-0x22a8)]);ReplacementFor_butterfly(ReplacementFor_A
[ReplacementFor_i+ReplacementFor_j+(0xedc+5482-0x2444)],ReplacementFor_A[
ReplacementFor_i+ReplacementFor_d+ReplacementFor_j+(0x73d+6092-0x1f07)],
ReplacementFor_w[ReplacementFor_d+ReplacementFor_j+(0x317+5614-0x1903)],
ReplacementFor_w_q[ReplacementFor_d+ReplacementFor_j+(0x1e1c+1856-0x255a)]);
ReplacementFor_butterfly(ReplacementFor_A[ReplacementFor_i+ReplacementFor_j+
(0x9d9+6520-0x234e)],ReplacementFor_A[ReplacementFor_i+ReplacementFor_d+
ReplacementFor_j+(0x15b3+412-0x174c)],ReplacementFor_w[ReplacementFor_d+
ReplacementFor_j+(0x14d5+3702-0x2348)],ReplacementFor_w_q[ReplacementFor_d+
ReplacementFor_j+(0x1a2c+3169-0x268a)]);}
#undef ReplacementFor_butterfly1
#undef ReplacementFor_butterfly
std::reverse(ReplacementFor_A+(0x1673+3695-0x24e1),ReplacementFor_A+
ReplacementFor_L);int ReplacementFor_k=__builtin_ctz(
ReplacementFor_L);for(int ReplacementFor_i=(0x2222+1165-0x26af);ReplacementFor_i
!=ReplacementFor_L;++ReplacementFor_i){ReplacementFor_uint64 ReplacementFor_m=-
ReplacementFor_A[ReplacementFor_i]&(ReplacementFor_L-(0x6d2+7148-0x22bd));
ReplacementFor_A[ReplacementFor_i]=norm((ReplacementFor_A[ReplacementFor_i]+
ReplacementFor_m*ReplacementFor_Mod)>>ReplacementFor_k);}}int ReplacementFor_p[
ReplacementFor_N];char ReplacementFor_a[ReplacementFor_N],ReplacementFor_b[
ReplacementFor_N];int ReplacementFor_o[ReplacementFor_N];ReplacementFor_Z 
ReplacementFor_f[ReplacementFor_N],ReplacementFor_ff[ReplacementFor_N];int main(
void){int ReplacementFor_m,ReplacementFor_n;int ReplacementFor_i,
ReplacementFor_t,c;for(ReplacementFor_i=(0x84c+7719-0x2673);ReplacementFor_i<
(0xd80+4503-0x1efd);ReplacementFor_i++){scanf("\x25\x64",&ReplacementFor_p[
ReplacementFor_i]);ReplacementFor_p[ReplacementFor_i]--;}scanf(
"\x25\x73\x20\x25\x73",ReplacementFor_a,ReplacementFor_b);ReplacementFor_m=(int)
strlen(ReplacementFor_a);ReplacementFor_n=(int)
strlen(ReplacementFor_b);for(c=(0x21b+5742-0x1889);(
(0x230+8689-0x2420)<<c)<ReplacementFor_n+ReplacementFor_m;c++);init(
(0x1650+2892-0x219b)<<c);for(ReplacementFor_t=(0xf40+268-0x104c);
ReplacementFor_t<(0x3da+292-0x4e4);ReplacementFor_t++){for(ReplacementFor_i=
(0x170+4562-0x1342);ReplacementFor_i<((0x531+3511-0x12e7)<<c);ReplacementFor_i++
)ReplacementFor_f[ReplacementFor_i]=ReplacementFor_Z((0x1a03+536-0x1c1b));for(
ReplacementFor_i=(0xb45+5019-0x1ee0);ReplacementFor_i<ReplacementFor_m;
ReplacementFor_i++)ReplacementFor_f[ReplacementFor_m-ReplacementFor_i-
(0x1002+5651-0x2614)]=ReplacementFor_Z(ReplacementFor_a[ReplacementFor_i]==(
ReplacementFor_t+((char)(0x4e4+2553-0xe7c))));for(ReplacementFor_i=
(0x1441+4813-0x270e);ReplacementFor_i<ReplacementFor_n;ReplacementFor_i++)
ReplacementFor_ff[ReplacementFor_i]=ReplacementFor_Z(ReplacementFor_b[
ReplacementFor_i]==(ReplacementFor_t+((char)(0x94b+574-0xb28)))||
ReplacementFor_b[ReplacementFor_i]==(ReplacementFor_p[ReplacementFor_t]+
((char)(0x5a5+3970-0x14c6))));ReplacementFor_DFT_fr_2(ReplacementFor_f,
(0x15ef+1824-0x1d0e)<<c);ReplacementFor_DFT_fr_2(ReplacementFor_ff,
(0xd59+4594-0x1f4a)<<c);for(ReplacementFor_i=(0xe4c+1426-0x13de);
ReplacementFor_i<((0x1cd+7204-0x1df0)<<c);ReplacementFor_i++)ReplacementFor_f[
ReplacementFor_i]*=ReplacementFor_ff[ReplacementFor_i];ReplacementFor_IDFT_fr(
ReplacementFor_f,(0xaab+1302-0xfc0)<<c);for(ReplacementFor_i=(0x230+6684-0x1c4c)
;ReplacementFor_i<ReplacementFor_n;ReplacementFor_i++)ReplacementFor_o[
ReplacementFor_i]+=ReplacementFor_f[ReplacementFor_m-(0x9c2+6917-0x24c6)+
ReplacementFor_i].ReplacementFor_v;}for(ReplacementFor_i=(0xf8+428-0x2a4);
ReplacementFor_i<ReplacementFor_n-ReplacementFor_m+(0x13c5+2409-0x1d2d);
ReplacementFor_i++)putchar((ReplacementFor_o[ReplacementFor_i]==
ReplacementFor_m)+(0x986+5722-0x1fb0));return(0x3f3+2693-0xe78);}
