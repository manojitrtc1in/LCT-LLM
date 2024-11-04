



using namespace std;int id44(int 
id60){int id67=0;for(int 
id46=0;id46<=
id60;id46++){int 
id0=id46;id67
+=id0;}return id67;}void 
id4(){cin.tie(0);int id68;cin
>>id68;int id59=1;while(
id59*id59<id68
){++id59;}vector<int>id54;if(
id59*(id59-1)>=
id68){id54.assign(
id59-1,id59-1);for(int 
id47=0;id47<
id68-(id59-1)*(
id59-1);id47++){
id54[id47]+=1;}}else{
id54.assign(id59,
id59);for(int id47=0;
id47<id59*id59
-id68;id47++){
id54[id47]-=1;}}int 
id20=(int)id54.size();vector<int>
id21(id20,0);for(int 
id47=0;id47<
id20-1;id47++){
id21[id47+1]=
id21[id47]+
id54[id47];}vector<int>
id62(id68,0);for(int 
id14:id21){
id62[id14]=2;}while(true){vector
<int>id30;for(int id47=0;
id47<id68;id47
++){if(id62[id47]==0){
id30.push_back(id47);}}if((int)
id30.size()<id59){cout<<0<<endl;
break;}cout<<id59;for(int id47=0;
id47<id59;id47
++){id62[id30[
id47]]=1;cout<<"\x20"<<id30[
id47]+1;}cout<<endl;int id14;cin>>
id14;--id14;for(int 
id47=0;id47<
id59;id47++){if(
id62[id14]==1){
id62[id14]=0;}
id14=(id14+1)%
id68;}}}void id48(){cin.tie(0
);int id68;cin>>id68;int 
id59=1;while(id59*
id59<id68){++
id59;}vector<int>id54;if(
id59*(id59-1)>=
id68){id54.assign(
id59-1,id59-1);for(int 
id47=0;id47<
id68-(id59-1)*(
id59-1);id47++){
id54[id47]+=1;}}else{
id54.assign(id59,
id59);for(int id47=0;
id47<id59*id59
-id68;id47++){
id54[id47]-=1;}}int 
id20=(int)id54.size();vector<int>
id21(id20,0);for(int 
id47=0;id47<
id20-1;id47++){
id21[id47+1]=
id21[id47]+
id54[id47];}vector<int>
id62(id68,0);for(int 
id14:id21){
id62[id14]=2;}while(true){vector
<int>id30;for(int id47=0;
id47<id68;id47
++){if(id62[id47]==0){
id30.push_back(id47);}}if((int)
id30.size()<id59){cout<<0<<endl;
break;}cout<<id59;for(int id47=0;
id47<id59;id47
++){id62[id30[
id47]]=1;cout<<"\x20"<<id30[
id47]+1;}cout<<endl;int id14;cin>>
id14;--id14;for(int 
id47=0;id47<
id59;id47++){if(
id62[id14]==1){
id62[id14]=0;}
id14=(id14+1)%
id68;}}}

int id7(int id60){int 
id67=0;for(int id46=0;
id46<=id60;
id46++){int id0=
id46;id67+=
id0;}return id67;}int 
id55(int id60){int 
id67=0;for(int id46=0;
id46<=id60;
id46++){int id0=
id46;id67+=
id0;}return id67;}

int id39(int id60){int 
id67=0;for(int id46=0;
id46<=id60;
id46++){int id0=
id46;id67+=
id0;}return id67;}

void id16(){cin.tie(0);int 
id68;cin>>id68;int 
id59=1;while(id59*
id59<id68){++
id59;}vector<int>id54;if(
id59*(id59-1)>=
id68){id54.assign(
id59-1,id59-1);for(int 
id47=0;id47<
id68-(id59-1)*(
id59-1);id47++){
id54[id47]+=1;}}else{
id54.assign(id59,
id59);for(int id47=0;
id47<id59*id59
-id68;id47++){
id54[id47]-=1;}}int 
id20=(int)id54.size();vector<int>
id21(id20,0);for(int 
id47=0;id47<
id20-1;id47++){
id21[id47+1]=
id21[id47]+
id54[id47];}vector<int>
id62(id68,0);for(int 
id14:id21){
id62[id14]=2;}while(true){vector
<int>id30;for(int id47=0;
id47<id68;id47
++){if(id62[id47]==0){
id30.push_back(id47);}}if((int)
id30.size()<id59){cout<<0<<endl;
break;}cout<<id59;for(int id47=0;
id47<id59;id47
++){id62[id30[
id47]]=1;cout<<"\x20"<<id30[
id47]+1;}cout<<endl;int id14;cin>>
id14;--id14;for(int 
id47=0;id47<
id59;id47++){if(
id62[id14]==1){
id62[id14]=0;}
id14=(id14+1)%
id68;}}}

void id5(){cin.tie(0);int id68
;cin>>id68;int id59=1;while(
id59*id59<id68
){++id59;}vector<int>id54;if(
id59*(id59-1)>=
id68){id54.assign(
id59-1,id59-1);for(int 
id47=0;id47<
id68-(id59-1)*(
id59-1);id47++){
id54[id47]+=1;}}else{
id54.assign(id59,
id59);for(int id47=0;
id47<id59*id59
-id68;id47++){
id54[id47]-=1;}}int 
id20=(int)id54.size();vector<int>
id21(id20,0);for(int 
id47=0;id47<
id20-1;id47++){
id21[id47+1]=
id21[id47]+
id54[id47];}vector<int>
id62(id68,0);for(int 
id14:id21){
id62[id14]=2;}while(true){vector
<int>id30;for(int id47=0;
id47<id68;id47
++){if(id62[id47]==0){
id30.push_back(id47);}}if((int)
id30.size()<id59){cout<<0<<endl;
break;}cout<<id59;for(int id47=0;
id47<id59;id47
++){id62[id30[
id47]]=1;cout<<"\x20"<<id30[
id47]+1;}cout<<endl;int id14;cin>>
id14;--id14;for(int 
id47=0;id47<
id59;id47++){if(
id62[id14]==1){
id62[id14]=0;}
id14=(id14+1)%
id68;}}}

void id65(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

void id52(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

void id57(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

void id34(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}





_s1ad39xWYx.end()
void id53(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

void id41(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

void id63(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

void id61(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

void id3(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

_s1ad39xWYx )cout<<_s1ad39xWYt<<"\x20";
void id17(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

_s1ad39xWYi<_s1ad39xWYn;_s1ad39xWYi++)
void id9(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

_s1ad39xWYj<_s1ad39xWYn;_s1ad39xWYj++)
void id69(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

void id24(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

_s1ad39xWYvi id35(_s1ad39xWYn);id38(\
_s1ad39xWYn){cin>>id35[_s1ad39xWYi];}
void id33(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

void id12(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

void id40(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

_s1ad39xWYm) id38(_s1ad39xWYn){_s1ad39xWYfor0j(\
_s1ad39xWYm) cin>>_s1ad39xWYnum[_s1ad39xWYi][_s1ad39xWYj];}
void id42(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

_s1ad39xWYm) id38(_s1ad39xWYn){_s1ad39xWYfor0j(\
_s1ad39xWYm) cout<<_s1ad39xWYnum[_s1ad39xWYi][_s1ad39xWYj]<<\
"\x20"; cout<<endl;}
void id25(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

id35;
void id10(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

id35)id37(_s1ad39xWYb)
void id2(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

id31(id35,_s1ad39xWYb)id37(\
_s1ad39xWYc)
void id28(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

_s1ad39xWYd)id31(id35,_s1ad39xWYb)\
id31(_s1ad39xWYc,_s1ad39xWYd)
void id6(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

_s1ad39xWYd,_s1ad39xWYe)id26(id35,\
_s1ad39xWYb,_s1ad39xWYc,_s1ad39xWYd)id37(\
_s1ad39xWYe)
void id27(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

_s1ad39xWYd,_s1ad39xWYe,_s1ad39xWYf)id58(\
id35,_s1ad39xWYb,_s1ad39xWYc)id58(\
_s1ad39xWYd,_s1ad39xWYe,_s1ad39xWYf)
void id64(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

_s1ad39xWYu,_s1ad39xWYv) _s1ad39xWYadj[_s1ad39xWYu].insert(\
_s1ad39xWYv);_s1ad39xWYadj[_s1ad39xWYv].insert(_s1ad39xWYu);
void id49(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

_s1ad39xWYtest--)
void id11(){int id18;cin>>
id18;vector<int>id56(
id18);for(int id15=0;
id15<id18;id15
++){cin>>id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}void id22(){int 
id18;cin>>id18;vector<int>
id56(id18);for(int 
id15=0;id15<
id18;id15++){cin>>
id56[id15];}vector<int>
id43(id18+1);for(int 
id15=0;id15<
id18;id15++){
id43[id15+1]=__gcd(
id43[id15],
id56[id15]);}vector<int>
id19(id18+1);for(int 
id15=id18-1;
id15>=0;id15--){
id19[id15]=__gcd(
id19[id15+1],
id56[id15]);}long long 
id8=1;for(int id15=0;
id15<id18;id15
++){int id66=__gcd(id43[
id15],id19[
id15+1]);id8=
id8/__gcd(id8,(long long)
id66)*id66;}cout<<
id8<<'\n';}

time_since_epoch().count()
template<typename _s1ad39xWY_sgvZaU5HKF,typename _s1ad39xWY_sgvZaU5HKS
>ostream&operator<<(ostream&id32,const pair<
_s1ad39xWY_sgvZaU5HKF,_s1ad39xWY_sgvZaU5HKS>&
id50){return id32<<"\x28"<<
id50.first<<"\x2c\x20"<<id50.second
<<"\x29";}template<typename _s1ad39xWY_sgvZaU5HKT>ostream&operator<<(
ostream&id32,const vector<_s1ad39xWY_sgvZaU5HKT>&
id36){id32<<"\x7b";for(auto 
id45=id36.begin();
id45!=id36.end();++
id45){if(id45!=
id36.begin())id32<<"\x2c\x20";
id32<<*id45;}return 
id32<<"\x7d";}template<typename 
_s1ad39xWY_sgvZaU5HKT>ostream&operator<<(ostream&
id32,const set<_s1ad39xWY_sgvZaU5HKT>&
id36){id32<<"\x5b";for(auto 
id45=id36.begin();
id45!=id36.end();++
id45){if(id45!=
id36.begin())id32<<"\x2c\x20";
id32<<*id45;}return 
id32<<"\x5d";}template<typename 
_s1ad39xWY_sgvZaU5HKT>ostream&operator<<(ostream&
id32,const multiset<_s1ad39xWY_sgvZaU5HKT>&
id36){id32<<"\x5b";for(auto 
id45=id36.begin();
id45!=id36.end();++
id45){if(id45!=
id36.begin())id32<<"\x2c\x20";
id32<<*id45;}return 
id32<<"\x5d";}template<typename 
_s1ad39xWY_sgvZaU5HKF,typename _s1ad39xWY_sgvZaU5HKS>ostream&operator
<<(ostream&id32,const map<_s1ad39xWY_sgvZaU5HKF,
_s1ad39xWY_sgvZaU5HKS>&id36){
id32<<"\x5b";for(auto id45=
id36.begin();id45!=
id36.end();++id45){if(
id45!=id36.begin())
id32<<"\x2c\x20";id32<<
id45->first<<"\x20\x3d\x20"<<id45
->second;}return id32<<"\x5d";}int 
id1(int id60){int 
id67=0;for(int id46=0;
id46<=id60;
id46++){int id0=
id46;id67+=
id0;}return id67;}const int 
id13=100000;const int id51=1000000007;int32_t main(){
ios_base::sync_with_stdio(false);cin.tie(0);id1(1000
);id1(1000);id1(1000);
id1(1000);id1(1000);
id1(1000);id1(1000);
id1(1000);id1(1000);
_s1ad39xWYtest{id37(_s1ad39xWYn)_s1ad39xWYarrin(
id35,_s1ad39xWYn)id38(_s1ad39xWYn)
id35[_s1ad39xWYi]=abs(id35[_s1ad39xWYi]);int 
id23=0;int id29=0;id38(
_s1ad39xWYn){if(_s1ad39xWYi&1){id35[_s1ad39xWYi]*=-1;
}}_s1ad39xWYdisp(id35)_s1ad39xWYNL}
id1(1000);id1(1000);
id1(1000);id1(1000);
id1(1000);id1(1000);
id1(1000);return 0;}

