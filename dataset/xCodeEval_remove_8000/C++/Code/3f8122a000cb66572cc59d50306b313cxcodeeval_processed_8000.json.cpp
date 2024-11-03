




constexpr ReplacementFor_uint Max_size=(0x1394+3247-0x2042)<<
(0x1c30+1107-0x206e)|(0x8ef+6681-0x2303);constexpr ReplacementFor_uint 
id34=(0x171d+573-0x1957),id29=998244353;inline 
ReplacementFor_uint id19(const ReplacementFor_uint 
id20){return id20<id29*(0x51f+1015-0x914)?
id20:id20-id29*(0x4e0+7384-0x21b6);}inline
 ReplacementFor_uint norm(const ReplacementFor_uint id20){return 
id20<id29?id20:id20-
id29;}struct id21{ReplacementFor_uint ReplacementFor_v
;id21(){}id21(const ReplacementFor_uint 
id5):ReplacementFor_v(id5){}};inline 
id21 operator+(const id21 id6,const 
id21 id7){return norm(id6.
ReplacementFor_v+id7.ReplacementFor_v);}inline id21 
operator-(const id21 id6,const id21 
id7){return norm(id6.ReplacementFor_v+
id29-id7.ReplacementFor_v);}inline id21 
operator-(const id21 id20){return id20.
ReplacementFor_v?id29-id20.ReplacementFor_v:
(0x1237+1628-0x1893);}inline id21 operator*(const id21 
id6,const id21 id7){return static_cast<
ReplacementFor_uint64>(id6.ReplacementFor_v)*id7.
ReplacementFor_v%id29;}inline id21&operator+=(
id21&id6,const id21 id7){
return id6=id6+id7;}inline 
id21&operator-=(id21&id6,const 
id21 id7){return id6=id6-
id7;}inline id21&operator*=(id21&
id6,const id21 id7){return 
id6=id6*id7;}id21 
id3(id21 Base,int Exp){id21 
id36=(0x1f9d+1237-0x2471);for(;Exp;Base*=Base,Exp>>=
(0x11ca+1993-0x1992))if(Exp&(0x343+6471-0x1c89))id36*=Base;return 
id36;}inline ReplacementFor_uint id12(
ReplacementFor_uint id20){return(static_cast<ReplacementFor_uint64>(
id20)<<(0x11a0+3373-0x1ead))/id29;}int size;
ReplacementFor_uint ReplacementFor_w[Max_size],ReplacementFor_w_q[Max_size];
inline ReplacementFor_uint id25(const ReplacementFor_uint
 id20,const ReplacementFor_uint id8,const 
ReplacementFor_uint id28){ReplacementFor_uint id0=
static_cast<ReplacementFor_uint64>(id20)*id28>>
(0x1748+2851-0x224b);return id20*id8-id0*
id29;}inline ReplacementFor_uint id22(const 
ReplacementFor_uint id20,const ReplacementFor_uint id8,
const ReplacementFor_uint id28){return norm(
id25(id20,id8,id28
));}inline ReplacementFor_uint id30(const 
ReplacementFor_uint id20,const ReplacementFor_uint id8,
const ReplacementFor_uint id28){ReplacementFor_uint 
id0=static_cast<ReplacementFor_uint64>(id20)*
id28>>(0x224+5687-0x183b);return id0+(
id20*id8-id0*id29>=
id29);}inline void init(int id17){for(size=
(0xc41+5202-0x2091);size<id17;size<<=(0x169c+328-0x17e3));
ReplacementFor_uint id14=id3(id34,(
id29-(0x1990+1135-0x1dfe))/size).ReplacementFor_v;
ReplacementFor_uint id23=(static_cast<ReplacementFor_uint64>(
id14)<<(0x822+3450-0x157c))/id29;ReplacementFor_uint 
id15=(static_cast<ReplacementFor_uint64>(id14)<<
(0x321+6410-0x1c0b))%id29;size>>=(0x6d8+7314-0x2369);
ReplacementFor_w[size]=(0x217f+139-0x2209),ReplacementFor_w_q[size]=(static_cast
<ReplacementFor_uint64>(ReplacementFor_w[size])<<(0x167a+3934-0x25b8))/
id29;

id11, ReplacementFor_b_q)\
    do\
    {\
        ReplacementFor_uint id20 = id11;\
        ReplacementFor_uint64 id27 = static_cast<\
ReplacementFor_uint64>(id20) * id23;\
        ReplacementFor_uint id0 = id27 >> \
(0x1887+221-0x1944);\
        id13 = norm(id20 * id14 - \
id0 * id29);\
        id16 = static_cast<ReplacementFor_uint>(id27) \
+ id30(id15, id11, \
ReplacementFor_b_q);\
    } while ((0x14bc+1512-0x1aa4))
if(size<=(0xdfc+4698-0x2052)){for(int id1=(0x1e4c+419-0x1fee);
id1!=size;++id1)ReplacementFor_compute(
ReplacementFor_w[size+id1],ReplacementFor_w_q[size+id1
],ReplacementFor_w[size+id1-(0x17f1+548-0x1a14)],ReplacementFor_w_q
[size+id1-(0xafb+457-0xcc3)]);}else{for(int id1=
(0xf9b+3935-0x1ef9);id1!=(0x141a+2736-0x1ec2);++id1)
ReplacementFor_compute(ReplacementFor_w[size+id1],
ReplacementFor_w_q[size+id1],ReplacementFor_w[size+id1
-(0x1a8c+3181-0x26f8)],ReplacementFor_w_q[size+id1-
(0x842+1552-0xe51)]);id14=ReplacementFor_w[size+(0x5ea+6858-0x20b0)
],id23=ReplacementFor_w_q[size+(0xb09+7001-0x265e)],
id15=-id23*id29;for(int 
id1=(0x18fa+2692-0x2376);id1!=size;id1+=
(0xa4d+4063-0x1a28)){ReplacementFor_compute(ReplacementFor_w[size+
id1+(0x1937+1496-0x1f0f)],ReplacementFor_w_q[size+id1+
(0x912+3971-0x1895)],ReplacementFor_w[size+id1-(0x1d09+1012-0x20f9)
],ReplacementFor_w_q[size+id1-(0xe56+2766-0x1920)]);
ReplacementFor_compute(ReplacementFor_w[size+id1+
(0x739+6313-0x1fe1)],ReplacementFor_w_q[size+id1+
(0x8ec+4848-0x1bdb)],ReplacementFor_w[size+id1-(0x1c2a+1666-0x22a9)
],ReplacementFor_w_q[size+id1-(0x1b3+5493-0x1725)]);
ReplacementFor_compute(ReplacementFor_w[size+id1+
(0x379+8603-0x2512)],ReplacementFor_w_q[size+id1+
(0x102d+2930-0x1b9d)],ReplacementFor_w[size+id1-(0x368+6591-0x1d25)
],ReplacementFor_w_q[size+id1-(0x21a+7641-0x1ff1)]);
ReplacementFor_compute(ReplacementFor_w[size+id1+(0x6d1+1696-0xd6e)
],ReplacementFor_w_q[size+id1+(0xe31+1762-0x1510)],ReplacementFor_w
[size+id1-(0xd2+9137-0x2482)],ReplacementFor_w_q[size+
id1-(0x776+1208-0xc2d)]);}}for(int id1=size-
(0x1762+2404-0x20c5);id1;--id1)ReplacementFor_w[
id1]=ReplacementFor_w[id1*(0x452+3198-0x10ce)],
ReplacementFor_w_q[id1]=ReplacementFor_w_q[id1*
(0x141+8788-0x2393)];size<<=(0xfd+2325-0xa11);}inline void 
id26(id21 ReplacementFor__A[],const int 
id31){if(id31==(0x12ba+404-0x144d))return;
ReplacementFor_uint*ReplacementFor_A=reinterpret_cast<ReplacementFor_uint*>(
ReplacementFor__A);

    do\
    {\
        ReplacementFor_uint id32 = id18, \
id2 = id11;\
        ReplacementFor_uint id20 = id19(\
id32 + id2), id8 = id19\
(id32 + id29 * (0x1cb+4993-0x154a) - \
id2);\
        id18 = id20, id11 = id8\
;\
    } while ((0x19b2+2275-0x2295))
if(id31==(0x756+2498-0x1116)){ReplacementFor_butterfly1(
ReplacementFor_A[(0xf15+572-0x1151)],ReplacementFor_A[(0x2b6+7068-0x1e51)]);
return;}

ReplacementFor__w, ReplacementFor__w_q)\
    do\
    {\
        ReplacementFor_uint id32 = id18, \
id2 = id11;\
        ReplacementFor_uint id20 = id19(\
id32 + id2), id8 = \
id25(id32 + id29 * \
(0x1243+2933-0x1db6) - id2, ReplacementFor__w, ReplacementFor__w_q\
);\
        id18 = id20, id11 = id8\
;\
    } while ((0x1e4b+982-0x2221))
if(id31==(0x744+4058-0x171a)){ReplacementFor_butterfly1(
ReplacementFor_A[(0xcb+6114-0x18ad)],ReplacementFor_A[(0x396+2744-0xe4c)]);
ReplacementFor_butterfly(ReplacementFor_A[(0x7d6+2705-0x1266)],ReplacementFor_A[
(0x1993+2355-0x22c3)],ReplacementFor_w[(0x10b6+5355-0x259e)],ReplacementFor_w_q[
(0xb57+4832-0x1e34)]);ReplacementFor_butterfly1(ReplacementFor_A[
(0xa5a+4377-0x1b73)],ReplacementFor_A[(0x1f7a+1786-0x2673)]);
ReplacementFor_butterfly1(ReplacementFor_A[(0x1bd+4464-0x132b)],ReplacementFor_A
[(0xd66+5466-0x22bd)]);return;}for(int id4=id31>>
(0xb+5182-0x1448);id4!=(0xd50+3442-0x1abe);id4>>=
(0x1f81+1173-0x2415))for(int id1=(0x167d+359-0x17e4);
id1!=id31;id1+=id4<<
(0xc11+5164-0x203c))for(int id9=(0x1ae4+2899-0x2637);
id9!=id4;id9+=(0x1604+1567-0x1c1f)){
ReplacementFor_butterfly(ReplacementFor_A[id1+id9+
(0x77a+2349-0x10a7)],ReplacementFor_A[id1+id4+
id9+(0x11b1+3986-0x2143)],ReplacementFor_w[id4+
id9+(0x164a+2653-0x20a7)],ReplacementFor_w_q[id4+
id9+(0x21fa+1174-0x2690)]);ReplacementFor_butterfly(
ReplacementFor_A[id1+id9+(0xdc4+1297-0x12d4)],
ReplacementFor_A[id1+id4+id9+
(0x687+6221-0x1ed3)],ReplacementFor_w[id4+id9+
(0x1269+2676-0x1cdc)],ReplacementFor_w_q[id4+id9+
(0x1678+502-0x186d)]);ReplacementFor_butterfly(ReplacementFor_A[id1
+id9+(0xbcb+3627-0x19f4)],ReplacementFor_A[id1+
id4+id9+(0x640+1233-0xb0f)],ReplacementFor_w[
id4+id9+(0xaac+1075-0xedd)],ReplacementFor_w_q[
id4+id9+(0x738+3031-0x130d)]);ReplacementFor_butterfly
(ReplacementFor_A[id1+id9+(0x1946+1747-0x2016)],
ReplacementFor_A[id1+id4+id9+
(0xa97+4437-0x1be9)],ReplacementFor_w[id4+id9+
(0xe80+4802-0x213f)],ReplacementFor_w_q[id4+id9+
(0xcd2+5216-0x212f)]);}for(int id1=(0x1a32+1440-0x1fd2);
id1!=id31;id1+=(0xcb9+4423-0x1df8)){
ReplacementFor_butterfly1(ReplacementFor_A[id1+(0x13e3+2136-0x1c3b)
],ReplacementFor_A[id1+(0xcc9+2662-0x172b)]);
ReplacementFor_butterfly(ReplacementFor_A[id1+(0x1002+2061-0x180e)]
,ReplacementFor_A[id1+(0x105f+5465-0x25b3)],ReplacementFor_w[
(0xfdd+3774-0x1e96)],ReplacementFor_w_q[(0x1d70+2412-0x26d7)]);
ReplacementFor_butterfly(ReplacementFor_A[id1+(0x14a4+3305-0x218b)]
,ReplacementFor_A[id1+(0x1830+3512-0x25e2)],ReplacementFor_w[
(0xddb+3632-0x1c05)],ReplacementFor_w_q[(0x167c+1174-0x1b0c)]);
ReplacementFor_butterfly(ReplacementFor_A[id1+(0x1a6+1281-0x6a4)],
ReplacementFor_A[id1+(0xfe1+2238-0x1898)],ReplacementFor_w[
(0x9e9+2561-0x13e3)],ReplacementFor_w_q[(0xc3c+907-0xfc0)]);}for(int 
id1=(0xf86+4972-0x22f2);id1!=id31;
id1+=(0xa90+3568-0x1878)){ReplacementFor_butterfly1(
ReplacementFor_A[id1+(0x10c4+3675-0x1f1f)],ReplacementFor_A[
id1+(0x1906+2915-0x2467)]);ReplacementFor_butterfly(
ReplacementFor_A[id1+(0x110+688-0x3bf)],ReplacementFor_A[
id1+(0x14ff+1021-0x18f9)],ReplacementFor_w[(0x118a+5422-0x26b5)],
ReplacementFor_w_q[(0x2462+678-0x2705)]);ReplacementFor_butterfly1(
ReplacementFor_A[id1+(0xf9+1596-0x731)],ReplacementFor_A[
id1+(0x66b+7457-0x2386)]);ReplacementFor_butterfly(ReplacementFor_A
[id1+(0xacd+585-0xd11)],ReplacementFor_A[id1+
(0xabc+5679-0x20e4)],ReplacementFor_w[(0x484+1673-0xb0a)],ReplacementFor_w_q[
(0x105+8658-0x22d4)]);}for(int id1=(0x62c+7158-0x2222);
id1!=id31;id1+=(0x16c0+1176-0x1b50)){
ReplacementFor_butterfly1(ReplacementFor_A[id1+(0x142+8901-0x2407)]
,ReplacementFor_A[id1+(0x98f+5761-0x200f)]);
ReplacementFor_butterfly1(ReplacementFor_A[id1+(0xfa7+249-0x109e)],
ReplacementFor_A[id1+(0x2af+4236-0x1338)]);
ReplacementFor_butterfly1(ReplacementFor_A[id1+(0x1316+4200-0x237a)
],ReplacementFor_A[id1+(0xc1f+2212-0x14be)]);
ReplacementFor_butterfly1(ReplacementFor_A[id1+(0x896+7666-0x2682)]
,ReplacementFor_A[id1+(0x7d8+1398-0xd47)]);}


}inline void id10(id21 ReplacementFor__A[],const 
int id31){if(id31==(0xf84+2421-0x18f8))return;
ReplacementFor_uint*ReplacementFor_A=reinterpret_cast<ReplacementFor_uint*>(
ReplacementFor__A);

    do\
    {\
        ReplacementFor_uint id32 = id18, \
id2 = id11;\
        ReplacementFor_uint id20 = id19(\
id32), id35 = id19(id2);\
        id18 = id20 + id35, id11\
 = id20 + id29 * (0x26d+3549-0x1048) - \
id35;\
    } while ((0x8bb+6329-0x2174))
if(id31==(0x1b91+1756-0x226b)){ReplacementFor_butterfly1(
ReplacementFor_A[(0x11f+6670-0x1b2d)],ReplacementFor_A[(0x835+1345-0xd75)]);
ReplacementFor_A[(0x767+5474-0x1cc9)]=norm(id19(
ReplacementFor_A[(0xa49+1275-0xf44)])),ReplacementFor_A[(0x9f8+5807-0x20a7)]=
ReplacementFor_A[(0xf59+3780-0x1e1d)]&(0xf13+657-0x11a3)?ReplacementFor_A[
(0x16cd+3718-0x2553)]+id29:ReplacementFor_A[(0x1da+7576-0x1f72)],
ReplacementFor_A[(0x4f+7004-0x1bab)]/=(0x1b8c+2675-0x25fd);ReplacementFor_A[
(0x107d+1418-0x1606)]=norm(id19(ReplacementFor_A[
(0x5f+7227-0x1c99)])),ReplacementFor_A[(0xf85+4223-0x2003)]=ReplacementFor_A[
(0x14c1+2919-0x2027)]&(0x677+3967-0x15f5)?ReplacementFor_A[(0xb0c+3216-0x179b)]+
id29:ReplacementFor_A[(0x1d7+7081-0x1d7f)],ReplacementFor_A[
(0x673+4874-0x197c)]/=(0x1080+2780-0x1b5a);return;}

ReplacementFor__w, ReplacementFor__w_q)\
    do\
    {\
        ReplacementFor_uint id32 = id18, \
id2 = id11;\
        ReplacementFor_uint id20 = id19(\
id32), id35 = id25(\
id2, ReplacementFor__w, ReplacementFor__w_q);\
        id18 = id20 + id35, id11\
 = id20 + id29 * (0x196f+3391-0x26ac) - \
id35;\
    } while ((0x2f3+6371-0x1bd6))
if(id31==(0xca8+4752-0x1f34)){ReplacementFor_butterfly1(
ReplacementFor_A[(0x1458+2534-0x1e3e)],ReplacementFor_A[(0x57c+8247-0x25b2)]);
ReplacementFor_butterfly1(ReplacementFor_A[(0x1d6a+1577-0x2391)],
ReplacementFor_A[(0x5b4+4267-0x165c)]);ReplacementFor_butterfly1(
ReplacementFor_A[(0x123a+4154-0x2274)],ReplacementFor_A[(0x2031+1394-0x25a1)]);
ReplacementFor_butterfly(ReplacementFor_A[(0x14fb+2406-0x1e60)],ReplacementFor_A
[(0x8d9+2260-0x11aa)],ReplacementFor_w[(0x1520+81-0x156e)],ReplacementFor_w_q[
(0x13f5+2811-0x1eed)]);std::swap(ReplacementFor_A[(0x1548+2423-0x1ebe)],
ReplacementFor_A[(0x1dd3+2032-0x25c0)]);for(int id1=
(0xaef+2924-0x165b);id1!=id31;++id1){
ReplacementFor_uint64 id33=-ReplacementFor_A[id1]&
(0x134b+4989-0x26c5);ReplacementFor_A[id1]=norm((ReplacementFor_A[
id1]+id33*id29)>>(0x196c+1597-0x1fa7));}
return;}for(int id1=(0x42c+2811-0xf27);id1!=
id31;id1+=(0x1a2+293-0x2bf)){ReplacementFor_butterfly1(
ReplacementFor_A[id1+(0x174c+1496-0x1d24)],ReplacementFor_A[
id1+(0x14e8+1961-0x1c90)]);ReplacementFor_butterfly1(
ReplacementFor_A[id1+(0x63f+4-0x641)],ReplacementFor_A[
id1+(0x1c9+7451-0x1ee1)]);ReplacementFor_butterfly1(
ReplacementFor_A[id1+(0x68b+612-0x8eb)],ReplacementFor_A[
id1+(0xfa3+1206-0x1454)]);ReplacementFor_butterfly1(
ReplacementFor_A[id1+(0x883+861-0xbda)],ReplacementFor_A[
id1+(0x3d1+7678-0x21c8)]);}for(int id1=
(0x113+5519-0x16a2);id1!=id31;id1+=
(0x1497+4603-0x268a)){ReplacementFor_butterfly1(ReplacementFor_A[
id1+(0xa95+2318-0x13a3)],ReplacementFor_A[id1+
(0x978+4824-0x1c4e)]);ReplacementFor_butterfly(ReplacementFor_A[id1
+(0x19ba+1031-0x1dc0)],ReplacementFor_A[id1+(0x3a6+5180-0x17df)],
ReplacementFor_w[(0xd76+3708-0x1bef)],ReplacementFor_w_q[(0xf1a+3253-0x1bcc)]);
ReplacementFor_butterfly1(ReplacementFor_A[id1+(0x659+5269-0x1aea)]
,ReplacementFor_A[id1+(0xebf+175-0xf68)]);ReplacementFor_butterfly(
ReplacementFor_A[id1+(0x22ef+295-0x2411)],ReplacementFor_A[
id1+(0x1a42+131-0x1abe)],ReplacementFor_w[(0x2cd+4654-0x14f8)],
ReplacementFor_w_q[(0x20b+8536-0x2360)]);}for(int id1=
(0x98c+4932-0x1cd0);id1!=id31;id1+=
(0x179d+2412-0x2101)){ReplacementFor_butterfly1(ReplacementFor_A[
id1+(0x1066+536-0x127e)],ReplacementFor_A[id1+
(0xf65+5266-0x23f3)]);ReplacementFor_butterfly(ReplacementFor_A[id1
+(0x81a+3601-0x162a)],ReplacementFor_A[id1+(0x129d+1148-0x1714)],
ReplacementFor_w[(0x9f6+2714-0x148b)],ReplacementFor_w_q[(0x2ff+7731-0x212d)]);
ReplacementFor_butterfly(ReplacementFor_A[id1+(0x16a7+2229-0x1f5a)]
,ReplacementFor_A[id1+(0xd71+38-0xd91)],ReplacementFor_w[
(0x6c6+4154-0x16fa)],ReplacementFor_w_q[(0x268+6368-0x1b42)]);
ReplacementFor_butterfly(ReplacementFor_A[id1+(0x12f6+4560-0x24c3)]
,ReplacementFor_A[id1+(0xcb6+5597-0x228c)],ReplacementFor_w[
(0x328+3461-0x10a6)],ReplacementFor_w_q[(0x618+8311-0x2688)]);}for(int 
id4=(0x221+4296-0x12e1);id4!=id31;
id4<<=(0x1608+2951-0x218e))for(int id1=
(0x1721+3835-0x261c);id1!=id31;id1+=
id4<<(0xf69+5190-0x23ae))for(int id9=
(0x1116+1078-0x154c);id9!=id4;id9+=
(0x1bd+8692-0x23ad)){ReplacementFor_butterfly(ReplacementFor_A[id1+
id9+(0xba8+2177-0x1429)],ReplacementFor_A[id1+
id4+id9+(0x114b+417-0x12ec)],ReplacementFor_w[
id4+id9+(0x6d5+149-0x76a)],ReplacementFor_w_q[
id4+id9+(0x1cd7+1738-0x23a1)]);
ReplacementFor_butterfly(ReplacementFor_A[id1+id9+
(0x65c+7336-0x2303)],ReplacementFor_A[id1+id4+
id9+(0x1b15+2683-0x258f)],ReplacementFor_w[id4+
id9+(0xdb1+1789-0x14ad)],ReplacementFor_w_q[id4+
id9+(0x228+8321-0x22a8)]);ReplacementFor_butterfly(ReplacementFor_A
[id1+id9+(0xedc+5482-0x2444)],ReplacementFor_A[
id1+id4+id9+(0x73d+6092-0x1f07)],
ReplacementFor_w[id4+id9+(0x317+5614-0x1903)],
ReplacementFor_w_q[id4+id9+(0x1e1c+1856-0x255a)]);
ReplacementFor_butterfly(ReplacementFor_A[id1+id9+
(0x9d9+6520-0x234e)],ReplacementFor_A[id1+id4+
id9+(0x15b3+412-0x174c)],ReplacementFor_w[id4+
id9+(0x14d5+3702-0x2348)],ReplacementFor_w_q[id4+
id9+(0x1a2c+3169-0x268a)]);}


std::reverse(ReplacementFor_A+(0x1673+3695-0x24e1),ReplacementFor_A+
id31);int id24=__builtin_ctz(
id31);for(int id1=(0x2222+1165-0x26af);id1
!=id31;++id1){ReplacementFor_uint64 id33=-
ReplacementFor_A[id1]&(id31-(0x6d2+7148-0x22bd));
ReplacementFor_A[id1]=norm((ReplacementFor_A[id1]+
id33*id29)>>id24);}}int id27[
ReplacementFor_N];char id18[ReplacementFor_N],id11[
ReplacementFor_N];int ReplacementFor_o[ReplacementFor_N];id21 
ReplacementFor_f[ReplacementFor_N],ReplacementFor_ff[ReplacementFor_N];int main(
void){int id33,id17;int id1,
id35,c;for(id1=(0x84c+7719-0x2673);id1<
(0xd80+4503-0x1efd);id1++){scanf("\x25\x64",&id27[
id1]);id27[id1]--;}scanf(
"\x25\x73\x20\x25\x73",id18,id11);id33=(int)
strlen(id18);id17=(int)
strlen(id11);for(c=(0x21b+5742-0x1889);(
(0x230+8689-0x2420)<<c)<id17+id33;c++);init(
(0x1650+2892-0x219b)<<c);for(id35=(0xf40+268-0x104c);
id35<(0x3da+292-0x4e4);id35++){for(id1=
(0x170+4562-0x1342);id1<((0x531+3511-0x12e7)<<c);id1++
)ReplacementFor_f[id1]=id21((0x1a03+536-0x1c1b));for(
id1=(0xb45+5019-0x1ee0);id1<id33;
id1++)ReplacementFor_f[id33-id1-
(0x1002+5651-0x2614)]=id21(id18[id1]==(
id35+((char)(0x4e4+2553-0xe7c))));for(id1=
(0x1441+4813-0x270e);id1<id17;id1++)
ReplacementFor_ff[id1]=id21(id11[
id1]==(id35+((char)(0x94b+574-0xb28)))||
id11[id1]==(id27[id35]+
((char)(0x5a5+3970-0x14c6))));id26(ReplacementFor_f,
(0x15ef+1824-0x1d0e)<<c);id26(ReplacementFor_ff,
(0xd59+4594-0x1f4a)<<c);for(id1=(0xe4c+1426-0x13de);
id1<((0x1cd+7204-0x1df0)<<c);id1++)ReplacementFor_f[
id1]*=ReplacementFor_ff[id1];id10(
ReplacementFor_f,(0xaab+1302-0xfc0)<<c);for(id1=(0x230+6684-0x1c4c)
;id1<id17;id1++)ReplacementFor_o[
id1]+=ReplacementFor_f[id33-(0x9c2+6917-0x24c6)+
id1].ReplacementFor_v;}for(id1=(0xf8+428-0x2a4);
id1<id17-id33+(0x13c5+2409-0x1d2d);
id1++)putchar((ReplacementFor_o[id1]==
id33)+(0x986+5722-0x1fb0));return(0x3f3+2693-0xe78);}