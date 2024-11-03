



using namespace std;int id59(int 
id21){int id64=0;for(int 
id50=0;id50<=
id21;id50++){int 
id8=id50;id64
+=id8;}return id64;}void 
id19(){cin.tie(0);int id18;cin
>>id18;int id10=1;while(
id10*id10<id18
){++id10;}vector<int>id41;if(
id10*(id10-1)>=
id18){id41.assign(
id10-1,id10-1);for(int 
id20=0;id20<
id18-(id10-1)*(
id10-1);id20++){
id41[id20]+=1;}}else{
id41.assign(id10,
id10);for(int id20=0;
id20<id10*id10
-id18;id20++){
id41[id20]-=1;}}int 
id24=(int)id41.size();vector<int>
id70(id24,0);for(int 
id20=0;id20<
id24-1;id20++){
id70[id20+1]=
id70[id20]+
id41[id20];}vector<int>
id65(id18,0);for(int 
id23:id70){
id65[id23]=2;}while(true){vector
<int>id29;for(int id20=0;
id20<id18;id20
++){if(id65[id20]==0){
id29.push_back(id20);}}if((int)
id29.size()<id10){cout<<0<<endl;
break;}cout<<id10;for(int id20=0;
id20<id10;id20
++){id65[id29[
id20]]=1;cout<<"\x20"<<id29[
id20]+1;}cout<<endl;int id23;cin>>
id23;--id23;for(int 
id20=0;id20<
id10;id20++){if(
id65[id23]==1){
id65[id23]=0;}
id23=(id23+1)%
id18;}}}void id58(){cin.tie(0
);int id18;cin>>id18;int 
id10=1;while(id10*
id10<id18){++
id10;}vector<int>id41;if(
id10*(id10-1)>=
id18){id41.assign(
id10-1,id10-1);for(int 
id20=0;id20<
id18-(id10-1)*(
id10-1);id20++){
id41[id20]+=1;}}else{
id41.assign(id10,
id10);for(int id20=0;
id20<id10*id10
-id18;id20++){
id41[id20]-=1;}}int 
id24=(int)id41.size();vector<int>
id70(id24,0);for(int 
id20=0;id20<
id24-1;id20++){
id70[id20+1]=
id70[id20]+
id41[id20];}vector<int>
id65(id18,0);for(int 
id23:id70){
id65[id23]=2;}while(true){vector
<int>id29;for(int id20=0;
id20<id18;id20
++){if(id65[id20]==0){
id29.push_back(id20);}}if((int)
id29.size()<id10){cout<<0<<endl;
break;}cout<<id10;for(int id20=0;
id20<id10;id20
++){id65[id29[
id20]]=1;cout<<"\x20"<<id29[
id20]+1;}cout<<endl;int id23;cin>>
id23;--id23;for(int 
id20=0;id20<
id10;id20++){if(
id65[id23]==1){
id65[id23]=0;}
id23=(id23+1)%
id18;}}}

int id5(int id21){int 
id64=0;for(int id50=0;
id50<=id21;
id50++){int id8=
id50;id64+=
id8;}return id64;}int 
id3(int id21){int 
id64=0;for(int id50=0;
id50<=id21;
id50++){int id8=
id50;id64+=
id8;}return id64;}

int id4(int id21){int 
id64=0;for(int id50=0;
id50<=id21;
id50++){int id8=
id50;id64+=
id8;}return id64;}

void id54(){cin.tie(0);int 
id18;cin>>id18;int 
id10=1;while(id10*
id10<id18){++
id10;}vector<int>id41;if(
id10*(id10-1)>=
id18){id41.assign(
id10-1,id10-1);for(int 
id20=0;id20<
id18-(id10-1)*(
id10-1);id20++){
id41[id20]+=1;}}else{
id41.assign(id10,
id10);for(int id20=0;
id20<id10*id10
-id18;id20++){
id41[id20]-=1;}}int 
id24=(int)id41.size();vector<int>
id70(id24,0);for(int 
id20=0;id20<
id24-1;id20++){
id70[id20+1]=
id70[id20]+
id41[id20];}vector<int>
id65(id18,0);for(int 
id23:id70){
id65[id23]=2;}while(true){vector
<int>id29;for(int id20=0;
id20<id18;id20
++){if(id65[id20]==0){
id29.push_back(id20);}}if((int)
id29.size()<id10){cout<<0<<endl;
break;}cout<<id10;for(int id20=0;
id20<id10;id20
++){id65[id29[
id20]]=1;cout<<"\x20"<<id29[
id20]+1;}cout<<endl;int id23;cin>>
id23;--id23;for(int 
id20=0;id20<
id10;id20++){if(
id65[id23]==1){
id65[id23]=0;}
id23=(id23+1)%
id18;}}}

void id56(){cin.tie(0);int id18
;cin>>id18;int id10=1;while(
id10*id10<id18
){++id10;}vector<int>id41;if(
id10*(id10-1)>=
id18){id41.assign(
id10-1,id10-1);for(int 
id20=0;id20<
id18-(id10-1)*(
id10-1);id20++){
id41[id20]+=1;}}else{
id41.assign(id10,
id10);for(int id20=0;
id20<id10*id10
-id18;id20++){
id41[id20]-=1;}}int 
id24=(int)id41.size();vector<int>
id70(id24,0);for(int 
id20=0;id20<
id24-1;id20++){
id70[id20+1]=
id70[id20]+
id41[id20];}vector<int>
id65(id18,0);for(int 
id23:id70){
id65[id23]=2;}while(true){vector
<int>id29;for(int id20=0;
id20<id18;id20
++){if(id65[id20]==0){
id29.push_back(id20);}}if((int)
id29.size()<id10){cout<<0<<endl;
break;}cout<<id10;for(int id20=0;
id20<id10;id20
++){id65[id29[
id20]]=1;cout<<"\x20"<<id29[
id20]+1;}cout<<endl;int id23;cin>>
id23;--id23;for(int 
id20=0;id20<
id10;id20++){if(
id65[id23]==1){
id65[id23]=0;}
id23=(id23+1)%
id18;}}}

void id37(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

void id51(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

void id55(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

void id47(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}





_siTDu7N8Zx.end()
void id1(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

void id66(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

void id36(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

void id60(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

void id45(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

_siTDu7N8Zx )cout<<_siTDu7N8Zt<<"\x20";
void id49(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

id17<_siTDu7N8Zn;id17++)
void id22(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

id57<_siTDu7N8Zn;id57++)
void id34(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

void id2(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

_siTDu7N8Zvi id13(_siTDu7N8Zn);id67(\
_siTDu7N8Zn){cin>>id13[id17];}
void id44(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

void id39(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

void id53(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

_siTDu7N8Zm) id67(_siTDu7N8Zn){_siTDu7N8Zfor0j(\
_siTDu7N8Zm) cin>>_siTDu7N8Znum[id17][id57];}
void id0(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

_siTDu7N8Zm) id67(_siTDu7N8Zn){_siTDu7N8Zfor0j(\
_siTDu7N8Zm) cout<<_siTDu7N8Znum[id17][id57]<<\
"\x20"; cout<<endl;}
void id27(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

id13;
void id25(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

id13)id46(_siTDu7N8Zb)
void id40(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

id68(id13,_siTDu7N8Zb)id46(\
_siTDu7N8Zc)
void id62(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

_siTDu7N8Zd)id68(id13,_siTDu7N8Zb)\
id68(_siTDu7N8Zc,_siTDu7N8Zd)
void id12(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

_siTDu7N8Zd,_siTDu7N8Ze)id7(id13,\
_siTDu7N8Zb,_siTDu7N8Zc,_siTDu7N8Zd)id46(\
_siTDu7N8Ze)
void id14(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

_siTDu7N8Zd,_siTDu7N8Ze,_siTDu7N8Zf)id15(\
id13,_siTDu7N8Zb,_siTDu7N8Zc)id15(\
_siTDu7N8Zd,_siTDu7N8Ze,_siTDu7N8Zf)
void id28(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

_siTDu7N8Zu,_siTDu7N8Zv) _siTDu7N8Zadj[_siTDu7N8Zu].insert(\
_siTDu7N8Zv);_siTDu7N8Zadj[_siTDu7N8Zv].insert(_siTDu7N8Zu);
void id38(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

_siTDu7N8Ztest--)
void id43(){int id63;cin>>
id63;vector<int>id9(
id63);for(int id6=0;
id6<id63;id6
++){cin>>id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}void id61(){int 
id63;cin>>id63;vector<int>
id9(id63);for(int 
id6=0;id6<
id63;id6++){cin>>
id9[id6];}vector<int>
id11(id63+1);for(int 
id6=0;id6<
id63;id6++){
id11[id6+1]=__gcd(
id11[id6],
id9[id6]);}vector<int>
id32(id63+1);for(int 
id6=id63-1;
id6>=0;id6--){
id32[id6]=__gcd(
id32[id6+1],
id9[id6]);}long long 
id42=1;for(int id6=0;
id6<id63;id6
++){int id26=__gcd(id11[
id6],id32[
id6+1]);id42=
id42/__gcd(id42,(long long)
id26)*id26;}cout<<
id42<<'\n';}

time_since_epoch().count()
template<typename _siTDu7N8Z_sgvZaU5HKF,typename _siTDu7N8Z_sgvZaU5HKS
>ostream&operator<<(ostream&id33,const pair<
_siTDu7N8Z_sgvZaU5HKF,_siTDu7N8Z_sgvZaU5HKS>&
id31){return id33<<"\x28"<<
id31.first<<"\x2c\x20"<<id31.second
<<"\x29";}template<typename _siTDu7N8Z_sgvZaU5HKT>ostream&operator<<(
ostream&id33,const vector<_siTDu7N8Z_sgvZaU5HKT>&
id30){id33<<"\x7b";for(auto 
id35=id30.begin();
id35!=id30.end();++
id35){if(id35!=
id30.begin())id33<<"\x2c\x20";
id33<<*id35;}return 
id33<<"\x7d";}template<typename 
_siTDu7N8Z_sgvZaU5HKT>ostream&operator<<(ostream&
id33,const set<_siTDu7N8Z_sgvZaU5HKT>&
id30){id33<<"\x5b";for(auto 
id35=id30.begin();
id35!=id30.end();++
id35){if(id35!=
id30.begin())id33<<"\x2c\x20";
id33<<*id35;}return 
id33<<"\x5d";}template<typename 
_siTDu7N8Z_sgvZaU5HKT>ostream&operator<<(ostream&
id33,const multiset<_siTDu7N8Z_sgvZaU5HKT>&
id30){id33<<"\x5b";for(auto 
id35=id30.begin();
id35!=id30.end();++
id35){if(id35!=
id30.begin())id33<<"\x2c\x20";
id33<<*id35;}return 
id33<<"\x5d";}template<typename 
_siTDu7N8Z_sgvZaU5HKF,typename _siTDu7N8Z_sgvZaU5HKS>ostream&operator
<<(ostream&id33,const map<_siTDu7N8Z_sgvZaU5HKF,
_siTDu7N8Z_sgvZaU5HKS>&id30){
id33<<"\x5b";for(auto id35=
id30.begin();id35!=
id30.end();++id35){if(
id35!=id30.begin())
id33<<"\x2c\x20";id33<<
id35->first<<"\x20\x3d\x20"<<id35
->second;}return id33<<"\x5d";}int 
id69(int id21){int 
id64=0;for(int id50=0;
id50<=id21;
id50++){int id8=
id50;id64+=
id8;}return id64;}const int 
id52=100000;const int id48=1000000007;int32_t main(){
ios_base::sync_with_stdio(false);cin.tie(0);id69(1000
);id69(1000);id69(1000);
id69(1000);id69(1000);
id69(1000);id69(1000);
id69(1000);id69(1000);
_siTDu7N8Ztest{id68(_siTDu7N8Zn,_siTDu7N8Zm)int 
_siTDu7N8Zgrid[_siTDu7N8Zn][_siTDu7N8Zm];_siTDu7N8Zgridin(
_siTDu7N8Zgrid,_siTDu7N8Zn,_siTDu7N8Zm)bool id16=
true;if(_siTDu7N8Zgrid[0][0]>2 or _siTDu7N8Zgrid[0][_siTDu7N8Zm-1
]>2 or _siTDu7N8Zgrid[_siTDu7N8Zn-1][0]>2 or _siTDu7N8Zgrid[
_siTDu7N8Zn-1][_siTDu7N8Zm-1]>2){id16=false;}else{
_siTDu7N8Zgrid[0][0]=2;_siTDu7N8Zgrid[_siTDu7N8Zn-1][0]=2;
_siTDu7N8Zgrid[0][_siTDu7N8Zm-1]=2;_siTDu7N8Zgrid[
_siTDu7N8Zn-1][_siTDu7N8Zm-1]=2;}id67(_siTDu7N8Zm)
{if(id17==0 or id17==_siTDu7N8Zm-1)continue;if(
_siTDu7N8Zgrid[0][id17]>3){id16=false;}else{
_siTDu7N8Zgrid[0][id17]=3;}if(_siTDu7N8Zgrid[
_siTDu7N8Zn-1][id17]>3){id16=false;}else{
_siTDu7N8Zgrid[_siTDu7N8Zn-1][id17]=3;}}
id67(_siTDu7N8Zn){if(id17==0 or id17
==_siTDu7N8Zn-1)continue;if(_siTDu7N8Zgrid[id17][0]>3){
id16=false;}else{_siTDu7N8Zgrid[id17][0]=3;}if(
_siTDu7N8Zgrid[id17][_siTDu7N8Zm-1]>3){id16
=false;}else{_siTDu7N8Zgrid[id17][_siTDu7N8Zm-1]=3;}}for(
int id17=1;id17<_siTDu7N8Zn-1;id17++){
for(int id57=1;id57<_siTDu7N8Zm-1;id57
++){if(_siTDu7N8Zgrid[id17][id57]>4){
id16=false;}else{_siTDu7N8Zgrid[id17][
id57]=4;}}}if(id16){cout<<"\x59\x45\x53"<<endl;
_siTDu7N8Zdispgrid(_siTDu7N8Zgrid,_siTDu7N8Zn,_siTDu7N8Zm)}
else{cout<<"\x4e\x4f"<<endl;}}id69(1000);
id69(1000);id69(1000);
id69(1000);id69(1000);
id69(1000);id69(1000);
return 0;}

