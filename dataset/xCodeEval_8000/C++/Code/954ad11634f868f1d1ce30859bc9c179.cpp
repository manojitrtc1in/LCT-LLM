
#include <vector>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;int _s1ad39xWY_sF9VBZWlQwxtydy1(int 
_s1ad39xWY_sF9VBZWlQn){int _s1ad39xWY_sF9VBZWlQa=0;for(int 
_s1ad39xWY_sF9VBZWlQi=0;_s1ad39xWY_sF9VBZWlQi<=
_s1ad39xWY_sF9VBZWlQn;_s1ad39xWY_sF9VBZWlQi++){int 
_s1ad39xWY_sF9VBZWlQb=_s1ad39xWY_sF9VBZWlQi;_s1ad39xWY_sF9VBZWlQa
+=_s1ad39xWY_sF9VBZWlQb;}return _s1ad39xWY_sF9VBZWlQa;}void 
_s1ad39xWY_sa5pJpLXoscramb3(){cin.tie(0);int _s1ad39xWY_sa5pJpLXon;cin
>>_s1ad39xWY_sa5pJpLXon;int _s1ad39xWY_sa5pJpLXok=1;while(
_s1ad39xWY_sa5pJpLXok*_s1ad39xWY_sa5pJpLXok<_s1ad39xWY_sa5pJpLXon
){++_s1ad39xWY_sa5pJpLXok;}vector<int>_s1ad39xWY_sa5pJpLXoa;if(
_s1ad39xWY_sa5pJpLXok*(_s1ad39xWY_sa5pJpLXok-1)>=
_s1ad39xWY_sa5pJpLXon){_s1ad39xWY_sa5pJpLXoa.assign(
_s1ad39xWY_sa5pJpLXok-1,_s1ad39xWY_sa5pJpLXok-1);for(int 
_s1ad39xWY_sa5pJpLXoi=0;_s1ad39xWY_sa5pJpLXoi<
_s1ad39xWY_sa5pJpLXon-(_s1ad39xWY_sa5pJpLXok-1)*(
_s1ad39xWY_sa5pJpLXok-1);_s1ad39xWY_sa5pJpLXoi++){
_s1ad39xWY_sa5pJpLXoa[_s1ad39xWY_sa5pJpLXoi]+=1;}}else{
_s1ad39xWY_sa5pJpLXoa.assign(_s1ad39xWY_sa5pJpLXok,
_s1ad39xWY_sa5pJpLXok);for(int _s1ad39xWY_sa5pJpLXoi=0;
_s1ad39xWY_sa5pJpLXoi<_s1ad39xWY_sa5pJpLXok*_s1ad39xWY_sa5pJpLXok
-_s1ad39xWY_sa5pJpLXon;_s1ad39xWY_sa5pJpLXoi++){
_s1ad39xWY_sa5pJpLXoa[_s1ad39xWY_sa5pJpLXoi]-=1;}}int 
_s1ad39xWY_sa5pJpLXoszz=(int)_s1ad39xWY_sa5pJpLXoa.size();vector<int>
_s1ad39xWY_sa5pJpLXopos(_s1ad39xWY_sa5pJpLXoszz,0);for(int 
_s1ad39xWY_sa5pJpLXoi=0;_s1ad39xWY_sa5pJpLXoi<
_s1ad39xWY_sa5pJpLXoszz-1;_s1ad39xWY_sa5pJpLXoi++){
_s1ad39xWY_sa5pJpLXopos[_s1ad39xWY_sa5pJpLXoi+1]=
_s1ad39xWY_sa5pJpLXopos[_s1ad39xWY_sa5pJpLXoi]+
_s1ad39xWY_sa5pJpLXoa[_s1ad39xWY_sa5pJpLXoi];}vector<int>
_s1ad39xWY_sa5pJpLXostate(_s1ad39xWY_sa5pJpLXon,0);for(int 
_s1ad39xWY_sa5pJpLXox:_s1ad39xWY_sa5pJpLXopos){
_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXox]=2;}while(true){vector
<int>_s1ad39xWY_sa5pJpLXoto;for(int _s1ad39xWY_sa5pJpLXoi=0;
_s1ad39xWY_sa5pJpLXoi<_s1ad39xWY_sa5pJpLXon;_s1ad39xWY_sa5pJpLXoi
++){if(_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXoi]==0){
_s1ad39xWY_sa5pJpLXoto.push_back(_s1ad39xWY_sa5pJpLXoi);}}if((int)
_s1ad39xWY_sa5pJpLXoto.size()<_s1ad39xWY_sa5pJpLXok){cout<<0<<endl;
break;}cout<<_s1ad39xWY_sa5pJpLXok;for(int _s1ad39xWY_sa5pJpLXoi=0;
_s1ad39xWY_sa5pJpLXoi<_s1ad39xWY_sa5pJpLXok;_s1ad39xWY_sa5pJpLXoi
++){_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXoto[
_s1ad39xWY_sa5pJpLXoi]]=1;cout<<"\x20"<<_s1ad39xWY_sa5pJpLXoto[
_s1ad39xWY_sa5pJpLXoi]+1;}cout<<endl;int _s1ad39xWY_sa5pJpLXox;cin>>
_s1ad39xWY_sa5pJpLXox;--_s1ad39xWY_sa5pJpLXox;for(int 
_s1ad39xWY_sa5pJpLXoi=0;_s1ad39xWY_sa5pJpLXoi<
_s1ad39xWY_sa5pJpLXok;_s1ad39xWY_sa5pJpLXoi++){if(
_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXox]==1){
_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXox]=0;}
_s1ad39xWY_sa5pJpLXox=(_s1ad39xWY_sa5pJpLXox+1)%
_s1ad39xWY_sa5pJpLXon;}}}void _s1ad39xWY_sa5pJpLXoscram2wb(){cin.tie(0
);int _s1ad39xWY_sa5pJpLXon;cin>>_s1ad39xWY_sa5pJpLXon;int 
_s1ad39xWY_sa5pJpLXok=1;while(_s1ad39xWY_sa5pJpLXok*
_s1ad39xWY_sa5pJpLXok<_s1ad39xWY_sa5pJpLXon){++
_s1ad39xWY_sa5pJpLXok;}vector<int>_s1ad39xWY_sa5pJpLXoa;if(
_s1ad39xWY_sa5pJpLXok*(_s1ad39xWY_sa5pJpLXok-1)>=
_s1ad39xWY_sa5pJpLXon){_s1ad39xWY_sa5pJpLXoa.assign(
_s1ad39xWY_sa5pJpLXok-1,_s1ad39xWY_sa5pJpLXok-1);for(int 
_s1ad39xWY_sa5pJpLXoi=0;_s1ad39xWY_sa5pJpLXoi<
_s1ad39xWY_sa5pJpLXon-(_s1ad39xWY_sa5pJpLXok-1)*(
_s1ad39xWY_sa5pJpLXok-1);_s1ad39xWY_sa5pJpLXoi++){
_s1ad39xWY_sa5pJpLXoa[_s1ad39xWY_sa5pJpLXoi]+=1;}}else{
_s1ad39xWY_sa5pJpLXoa.assign(_s1ad39xWY_sa5pJpLXok,
_s1ad39xWY_sa5pJpLXok);for(int _s1ad39xWY_sa5pJpLXoi=0;
_s1ad39xWY_sa5pJpLXoi<_s1ad39xWY_sa5pJpLXok*_s1ad39xWY_sa5pJpLXok
-_s1ad39xWY_sa5pJpLXon;_s1ad39xWY_sa5pJpLXoi++){
_s1ad39xWY_sa5pJpLXoa[_s1ad39xWY_sa5pJpLXoi]-=1;}}int 
_s1ad39xWY_sa5pJpLXoszz=(int)_s1ad39xWY_sa5pJpLXoa.size();vector<int>
_s1ad39xWY_sa5pJpLXopos(_s1ad39xWY_sa5pJpLXoszz,0);for(int 
_s1ad39xWY_sa5pJpLXoi=0;_s1ad39xWY_sa5pJpLXoi<
_s1ad39xWY_sa5pJpLXoszz-1;_s1ad39xWY_sa5pJpLXoi++){
_s1ad39xWY_sa5pJpLXopos[_s1ad39xWY_sa5pJpLXoi+1]=
_s1ad39xWY_sa5pJpLXopos[_s1ad39xWY_sa5pJpLXoi]+
_s1ad39xWY_sa5pJpLXoa[_s1ad39xWY_sa5pJpLXoi];}vector<int>
_s1ad39xWY_sa5pJpLXostate(_s1ad39xWY_sa5pJpLXon,0);for(int 
_s1ad39xWY_sa5pJpLXox:_s1ad39xWY_sa5pJpLXopos){
_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXox]=2;}while(true){vector
<int>_s1ad39xWY_sa5pJpLXoto;for(int _s1ad39xWY_sa5pJpLXoi=0;
_s1ad39xWY_sa5pJpLXoi<_s1ad39xWY_sa5pJpLXon;_s1ad39xWY_sa5pJpLXoi
++){if(_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXoi]==0){
_s1ad39xWY_sa5pJpLXoto.push_back(_s1ad39xWY_sa5pJpLXoi);}}if((int)
_s1ad39xWY_sa5pJpLXoto.size()<_s1ad39xWY_sa5pJpLXok){cout<<0<<endl;
break;}cout<<_s1ad39xWY_sa5pJpLXok;for(int _s1ad39xWY_sa5pJpLXoi=0;
_s1ad39xWY_sa5pJpLXoi<_s1ad39xWY_sa5pJpLXok;_s1ad39xWY_sa5pJpLXoi
++){_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXoto[
_s1ad39xWY_sa5pJpLXoi]]=1;cout<<"\x20"<<_s1ad39xWY_sa5pJpLXoto[
_s1ad39xWY_sa5pJpLXoi]+1;}cout<<endl;int _s1ad39xWY_sa5pJpLXox;cin>>
_s1ad39xWY_sa5pJpLXox;--_s1ad39xWY_sa5pJpLXox;for(int 
_s1ad39xWY_sa5pJpLXoi=0;_s1ad39xWY_sa5pJpLXoi<
_s1ad39xWY_sa5pJpLXok;_s1ad39xWY_sa5pJpLXoi++){if(
_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXox]==1){
_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXox]=0;}
_s1ad39xWY_sa5pJpLXox=(_s1ad39xWY_sa5pJpLXox+1)%
_s1ad39xWY_sa5pJpLXon;}}}
#define int long long
int _s1ad39xWY_sF9VBZWlQwxtydy21(int _s1ad39xWY_sF9VBZWlQn){int 
_s1ad39xWY_sF9VBZWlQa=0;for(int _s1ad39xWY_sF9VBZWlQi=0;
_s1ad39xWY_sF9VBZWlQi<=_s1ad39xWY_sF9VBZWlQn;
_s1ad39xWY_sF9VBZWlQi++){int _s1ad39xWY_sF9VBZWlQb=
_s1ad39xWY_sF9VBZWlQi;_s1ad39xWY_sF9VBZWlQa+=
_s1ad39xWY_sF9VBZWlQb;}return _s1ad39xWY_sF9VBZWlQa;}int 
_s1ad39xWY_sF9VBZWl2Qwxtydy1(int _s1ad39xWY_sF9VBZWlQn){int 
_s1ad39xWY_sF9VBZWlQa=0;for(int _s1ad39xWY_sF9VBZWlQi=0;
_s1ad39xWY_sF9VBZWlQi<=_s1ad39xWY_sF9VBZWlQn;
_s1ad39xWY_sF9VBZWlQi++){int _s1ad39xWY_sF9VBZWlQb=
_s1ad39xWY_sF9VBZWlQi;_s1ad39xWY_sF9VBZWlQa+=
_s1ad39xWY_sF9VBZWlQb;}return _s1ad39xWY_sF9VBZWlQa;}
#define double long double
int _s1ad39xWY_sF9VBZdWlQwxtydy1(int _s1ad39xWY_sF9VBZWlQn){int 
_s1ad39xWY_sF9VBZWlQa=0;for(int _s1ad39xWY_sF9VBZWlQi=0;
_s1ad39xWY_sF9VBZWlQi<=_s1ad39xWY_sF9VBZWlQn;
_s1ad39xWY_sF9VBZWlQi++){int _s1ad39xWY_sF9VBZWlQb=
_s1ad39xWY_sF9VBZWlQi;_s1ad39xWY_sF9VBZWlQa+=
_s1ad39xWY_sF9VBZWlQb;}return _s1ad39xWY_sF9VBZWlQa;}
#define _s1ad39xWYpii pair<int,int>
void _s1ad39xWY_sa5pJpLXoscram2b(){cin.tie(0);int 
_s1ad39xWY_sa5pJpLXon;cin>>_s1ad39xWY_sa5pJpLXon;int 
_s1ad39xWY_sa5pJpLXok=1;while(_s1ad39xWY_sa5pJpLXok*
_s1ad39xWY_sa5pJpLXok<_s1ad39xWY_sa5pJpLXon){++
_s1ad39xWY_sa5pJpLXok;}vector<int>_s1ad39xWY_sa5pJpLXoa;if(
_s1ad39xWY_sa5pJpLXok*(_s1ad39xWY_sa5pJpLXok-1)>=
_s1ad39xWY_sa5pJpLXon){_s1ad39xWY_sa5pJpLXoa.assign(
_s1ad39xWY_sa5pJpLXok-1,_s1ad39xWY_sa5pJpLXok-1);for(int 
_s1ad39xWY_sa5pJpLXoi=0;_s1ad39xWY_sa5pJpLXoi<
_s1ad39xWY_sa5pJpLXon-(_s1ad39xWY_sa5pJpLXok-1)*(
_s1ad39xWY_sa5pJpLXok-1);_s1ad39xWY_sa5pJpLXoi++){
_s1ad39xWY_sa5pJpLXoa[_s1ad39xWY_sa5pJpLXoi]+=1;}}else{
_s1ad39xWY_sa5pJpLXoa.assign(_s1ad39xWY_sa5pJpLXok,
_s1ad39xWY_sa5pJpLXok);for(int _s1ad39xWY_sa5pJpLXoi=0;
_s1ad39xWY_sa5pJpLXoi<_s1ad39xWY_sa5pJpLXok*_s1ad39xWY_sa5pJpLXok
-_s1ad39xWY_sa5pJpLXon;_s1ad39xWY_sa5pJpLXoi++){
_s1ad39xWY_sa5pJpLXoa[_s1ad39xWY_sa5pJpLXoi]-=1;}}int 
_s1ad39xWY_sa5pJpLXoszz=(int)_s1ad39xWY_sa5pJpLXoa.size();vector<int>
_s1ad39xWY_sa5pJpLXopos(_s1ad39xWY_sa5pJpLXoszz,0);for(int 
_s1ad39xWY_sa5pJpLXoi=0;_s1ad39xWY_sa5pJpLXoi<
_s1ad39xWY_sa5pJpLXoszz-1;_s1ad39xWY_sa5pJpLXoi++){
_s1ad39xWY_sa5pJpLXopos[_s1ad39xWY_sa5pJpLXoi+1]=
_s1ad39xWY_sa5pJpLXopos[_s1ad39xWY_sa5pJpLXoi]+
_s1ad39xWY_sa5pJpLXoa[_s1ad39xWY_sa5pJpLXoi];}vector<int>
_s1ad39xWY_sa5pJpLXostate(_s1ad39xWY_sa5pJpLXon,0);for(int 
_s1ad39xWY_sa5pJpLXox:_s1ad39xWY_sa5pJpLXopos){
_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXox]=2;}while(true){vector
<int>_s1ad39xWY_sa5pJpLXoto;for(int _s1ad39xWY_sa5pJpLXoi=0;
_s1ad39xWY_sa5pJpLXoi<_s1ad39xWY_sa5pJpLXon;_s1ad39xWY_sa5pJpLXoi
++){if(_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXoi]==0){
_s1ad39xWY_sa5pJpLXoto.push_back(_s1ad39xWY_sa5pJpLXoi);}}if((int)
_s1ad39xWY_sa5pJpLXoto.size()<_s1ad39xWY_sa5pJpLXok){cout<<0<<endl;
break;}cout<<_s1ad39xWY_sa5pJpLXok;for(int _s1ad39xWY_sa5pJpLXoi=0;
_s1ad39xWY_sa5pJpLXoi<_s1ad39xWY_sa5pJpLXok;_s1ad39xWY_sa5pJpLXoi
++){_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXoto[
_s1ad39xWY_sa5pJpLXoi]]=1;cout<<"\x20"<<_s1ad39xWY_sa5pJpLXoto[
_s1ad39xWY_sa5pJpLXoi]+1;}cout<<endl;int _s1ad39xWY_sa5pJpLXox;cin>>
_s1ad39xWY_sa5pJpLXox;--_s1ad39xWY_sa5pJpLXox;for(int 
_s1ad39xWY_sa5pJpLXoi=0;_s1ad39xWY_sa5pJpLXoi<
_s1ad39xWY_sa5pJpLXok;_s1ad39xWY_sa5pJpLXoi++){if(
_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXox]==1){
_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXox]=0;}
_s1ad39xWY_sa5pJpLXox=(_s1ad39xWY_sa5pJpLXox+1)%
_s1ad39xWY_sa5pJpLXon;}}}
#define _s1ad39xWYvi vector<int>
void _s1ad39xWY_sa5pJpLXoscramb(){cin.tie(0);int _s1ad39xWY_sa5pJpLXon
;cin>>_s1ad39xWY_sa5pJpLXon;int _s1ad39xWY_sa5pJpLXok=1;while(
_s1ad39xWY_sa5pJpLXok*_s1ad39xWY_sa5pJpLXok<_s1ad39xWY_sa5pJpLXon
){++_s1ad39xWY_sa5pJpLXok;}vector<int>_s1ad39xWY_sa5pJpLXoa;if(
_s1ad39xWY_sa5pJpLXok*(_s1ad39xWY_sa5pJpLXok-1)>=
_s1ad39xWY_sa5pJpLXon){_s1ad39xWY_sa5pJpLXoa.assign(
_s1ad39xWY_sa5pJpLXok-1,_s1ad39xWY_sa5pJpLXok-1);for(int 
_s1ad39xWY_sa5pJpLXoi=0;_s1ad39xWY_sa5pJpLXoi<
_s1ad39xWY_sa5pJpLXon-(_s1ad39xWY_sa5pJpLXok-1)*(
_s1ad39xWY_sa5pJpLXok-1);_s1ad39xWY_sa5pJpLXoi++){
_s1ad39xWY_sa5pJpLXoa[_s1ad39xWY_sa5pJpLXoi]+=1;}}else{
_s1ad39xWY_sa5pJpLXoa.assign(_s1ad39xWY_sa5pJpLXok,
_s1ad39xWY_sa5pJpLXok);for(int _s1ad39xWY_sa5pJpLXoi=0;
_s1ad39xWY_sa5pJpLXoi<_s1ad39xWY_sa5pJpLXok*_s1ad39xWY_sa5pJpLXok
-_s1ad39xWY_sa5pJpLXon;_s1ad39xWY_sa5pJpLXoi++){
_s1ad39xWY_sa5pJpLXoa[_s1ad39xWY_sa5pJpLXoi]-=1;}}int 
_s1ad39xWY_sa5pJpLXoszz=(int)_s1ad39xWY_sa5pJpLXoa.size();vector<int>
_s1ad39xWY_sa5pJpLXopos(_s1ad39xWY_sa5pJpLXoszz,0);for(int 
_s1ad39xWY_sa5pJpLXoi=0;_s1ad39xWY_sa5pJpLXoi<
_s1ad39xWY_sa5pJpLXoszz-1;_s1ad39xWY_sa5pJpLXoi++){
_s1ad39xWY_sa5pJpLXopos[_s1ad39xWY_sa5pJpLXoi+1]=
_s1ad39xWY_sa5pJpLXopos[_s1ad39xWY_sa5pJpLXoi]+
_s1ad39xWY_sa5pJpLXoa[_s1ad39xWY_sa5pJpLXoi];}vector<int>
_s1ad39xWY_sa5pJpLXostate(_s1ad39xWY_sa5pJpLXon,0);for(int 
_s1ad39xWY_sa5pJpLXox:_s1ad39xWY_sa5pJpLXopos){
_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXox]=2;}while(true){vector
<int>_s1ad39xWY_sa5pJpLXoto;for(int _s1ad39xWY_sa5pJpLXoi=0;
_s1ad39xWY_sa5pJpLXoi<_s1ad39xWY_sa5pJpLXon;_s1ad39xWY_sa5pJpLXoi
++){if(_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXoi]==0){
_s1ad39xWY_sa5pJpLXoto.push_back(_s1ad39xWY_sa5pJpLXoi);}}if((int)
_s1ad39xWY_sa5pJpLXoto.size()<_s1ad39xWY_sa5pJpLXok){cout<<0<<endl;
break;}cout<<_s1ad39xWY_sa5pJpLXok;for(int _s1ad39xWY_sa5pJpLXoi=0;
_s1ad39xWY_sa5pJpLXoi<_s1ad39xWY_sa5pJpLXok;_s1ad39xWY_sa5pJpLXoi
++){_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXoto[
_s1ad39xWY_sa5pJpLXoi]]=1;cout<<"\x20"<<_s1ad39xWY_sa5pJpLXoto[
_s1ad39xWY_sa5pJpLXoi]+1;}cout<<endl;int _s1ad39xWY_sa5pJpLXox;cin>>
_s1ad39xWY_sa5pJpLXox;--_s1ad39xWY_sa5pJpLXox;for(int 
_s1ad39xWY_sa5pJpLXoi=0;_s1ad39xWY_sa5pJpLXoi<
_s1ad39xWY_sa5pJpLXok;_s1ad39xWY_sa5pJpLXoi++){if(
_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXox]==1){
_s1ad39xWY_sa5pJpLXostate[_s1ad39xWY_sa5pJpLXox]=0;}
_s1ad39xWY_sa5pJpLXox=(_s1ad39xWY_sa5pJpLXox+1)%
_s1ad39xWY_sa5pJpLXon;}}}
#define _s1ad39xWYmii map<int,int>
void _s1ad39xWY_sBnZuq8f8shit(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYADJ map<int,set<int>>
void _s1ad39xWY_sBnZuq8f8sh32it(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYvpii vector<_s1ad39xWYpii>
void _s1ad39xWY_sBnZuq8f8shsdgit(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYpb push_back
void _s1ad39xWY_sBasfas8shit(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYed end()
#define _s1ad39xWYbg begin()
#define _s1ad39xWYsz size()
#define _s1ad39xWYln length()
#define _s1ad39xWYall(_s1ad39xWYx) _s1ad39xWYx.begin(),\
_s1ad39xWYx.end()
void _s1ad39xWY_sBnZuq8sgf8shit(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define endl "\n"
void _s1ad39xWY_sBnZuq8f8dsgit(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYNL cout<<'\n';
void _s1ad39xWY_sBnsdgsfhfdghit(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYF first
void _s1ad39xWY_sBsdgsf8shit(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYS second
void _s1ad39xWY_sBnZuqsdgt(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYdisp(_s1ad39xWYx) for(auto _s1ad39xWYt : \
_s1ad39xWYx )cout<<_s1ad39xWYt<<"\x20";
void _s1ad39xWY_sBnZsdgit(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYfor0(_s1ad39xWYn) for(int _s1ad39xWYi=0;\
_s1ad39xWYi<_s1ad39xWYn;_s1ad39xWYi++)
void _s1ad39xWY_gmfgjmit(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYfor0j(_s1ad39xWYn) for(int _s1ad39xWYj=0;\
_s1ad39xWYj<_s1ad39xWYn;_s1ad39xWYj++)
void _s1ad39xWY_sgfjfkmhmit(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYSS <<"\x20"<<
void _s1ad39xWY_sBnZudsgsdgt(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYarrin(_s1ad39xWYa,_s1ad39xWYn) \
_s1ad39xWYvi _s1ad39xWYa(_s1ad39xWYn);_s1ad39xWYfor0(\
_s1ad39xWYn){cin>>_s1ad39xWYa[_s1ad39xWYi];}
void _s1ad39xWY_sBnZuq8fdhjndfgit(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYpf(_s1ad39xWYx) cout<<_s1ad39xWYx<<endl;
void _s1ad39xWY_sBnZuqgdsgnfghit(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYCheck _s1ad39xWYpf("\x43\x68\x65\x63\x6b")
void _s1ad39xWY_sBnZuq8f8sdfghfht(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYgridin(_s1ad39xWYnum,_s1ad39xWYn,\
_s1ad39xWYm) _s1ad39xWYfor0(_s1ad39xWYn){_s1ad39xWYfor0j(\
_s1ad39xWYm) cin>>_s1ad39xWYnum[_s1ad39xWYi][_s1ad39xWYj];}
void _s1ad39xWY_sBnZuq8f8dgbngt(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYdispgrid(_s1ad39xWYnum,_s1ad39xWYn,\
_s1ad39xWYm) _s1ad39xWYfor0(_s1ad39xWYn){_s1ad39xWYfor0j(\
_s1ad39xWYm) cout<<_s1ad39xWYnum[_s1ad39xWYi][_s1ad39xWYj]<<\
"\x20"; cout<<endl;}
void _s1ad39xWYfgfgfgfgf(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYtk(_s1ad39xWYa) int _s1ad39xWYa;cin>>\
_s1ad39xWYa;
void _s1ad39xWY_sBnZuq8gdgit(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYtk2(_s1ad39xWYa,_s1ad39xWYb)_s1ad39xWYtk(\
_s1ad39xWYa)_s1ad39xWYtk(_s1ad39xWYb)
void _s1ad39xWY_sBnZudsgdsgst(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYtk3(_s1ad39xWYa,_s1ad39xWYb,_s1ad39xWYc)\
_s1ad39xWYtk2(_s1ad39xWYa,_s1ad39xWYb)_s1ad39xWYtk(\
_s1ad39xWYc)
void _s1ad39xWY_ssdfdsffddfit(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYtk4(_s1ad39xWYa,_s1ad39xWYb,_s1ad39xWYc,\
_s1ad39xWYd)_s1ad39xWYtk2(_s1ad39xWYa,_s1ad39xWYb)\
_s1ad39xWYtk2(_s1ad39xWYc,_s1ad39xWYd)
void _s1ad39xWY_sBnZuq8f8sdsgsdgsdt(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYtk5(_s1ad39xWYa,_s1ad39xWYb,_s1ad39xWYc,\
_s1ad39xWYd,_s1ad39xWYe)_s1ad39xWYtk4(_s1ad39xWYa,\
_s1ad39xWYb,_s1ad39xWYc,_s1ad39xWYd)_s1ad39xWYtk(\
_s1ad39xWYe)
void _s1ad39xWY_sBnqwrqwr8shit(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYtk6(_s1ad39xWYa,_s1ad39xWYb,_s1ad39xWYc,\
_s1ad39xWYd,_s1ad39xWYe,_s1ad39xWYf)_s1ad39xWYtk3(\
_s1ad39xWYa,_s1ad39xWYb,_s1ad39xWYc)_s1ad39xWYtk3(\
_s1ad39xWYd,_s1ad39xWYe,_s1ad39xWYf)
void _s1ad39xWY_sBnfmngjfgjit(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYaddEdge(_s1ad39xWYadj) _s1ad39xWYtk2(\
_s1ad39xWYu,_s1ad39xWYv) _s1ad39xWYadj[_s1ad39xWYu].insert(\
_s1ad39xWYv);_s1ad39xWYadj[_s1ad39xWYv].insert(_s1ad39xWYu);
void _s1ad39xWY_sBnZuq8fsdgt(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYtest _s1ad39xWYtk(_s1ad39xWYtest)while(\
_s1ad39xWYtest--)
void _s1ad39xWY_sBnZuq8f8fhjkiht(){int _s1ad39xWY_sBnZuq8f8n;cin>>
_s1ad39xWY_sBnZuq8f8n;vector<int>_s1ad39xWY_sBnZuq8f8a(
_s1ad39xWY_sBnZuq8f8n);for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){cin>>_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}void _s1ad39xWY_sBnZuq8f8suyoit(){int 
_s1ad39xWY_sBnZuq8f8n;cin>>_s1ad39xWY_sBnZuq8f8n;vector<int>
_s1ad39xWY_sBnZuq8f8a(_s1ad39xWY_sBnZuq8f8n);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){cin>>
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i];}vector<int>
_s1ad39xWY_sBnZuq8f8pref(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=0;_s1ad39xWY_sBnZuq8f8i<
_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i++){
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i+1]=__gcd(
_s1ad39xWY_sBnZuq8f8pref[_s1ad39xWY_sBnZuq8f8i],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}vector<int>
_s1ad39xWY_sBnZuq8f8suf(_s1ad39xWY_sBnZuq8f8n+1);for(int 
_s1ad39xWY_sBnZuq8f8i=_s1ad39xWY_sBnZuq8f8n-1;
_s1ad39xWY_sBnZuq8f8i>=0;_s1ad39xWY_sBnZuq8f8i--){
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i]=__gcd(
_s1ad39xWY_sBnZuq8f8suf[_s1ad39xWY_sBnZuq8f8i+1],
_s1ad39xWY_sBnZuq8f8a[_s1ad39xWY_sBnZuq8f8i]);}long long 
_s1ad39xWY_sBnZuq8f8ans=1;for(int _s1ad39xWY_sBnZuq8f8i=0;
_s1ad39xWY_sBnZuq8f8i<_s1ad39xWY_sBnZuq8f8n;_s1ad39xWY_sBnZuq8f8i
++){int _s1ad39xWY_sBnZuq8f8x=__gcd(_s1ad39xWY_sBnZuq8f8pref[
_s1ad39xWY_sBnZuq8f8i],_s1ad39xWY_sBnZuq8f8suf[
_s1ad39xWY_sBnZuq8f8i+1]);_s1ad39xWY_sBnZuq8f8ans=
_s1ad39xWY_sBnZuq8f8ans/__gcd(_s1ad39xWY_sBnZuq8f8ans,(long long)
_s1ad39xWY_sBnZuq8f8x)*_s1ad39xWY_sBnZuq8f8x;}cout<<
_s1ad39xWY_sBnZuq8f8ans<<'\n';}
#define _s1ad39xWYaccuracy chrono::_s1ad39xWYsteady_clock::now().\
time_since_epoch().count()
template<typename _s1ad39xWY_sgvZaU5HKF,typename _s1ad39xWY_sgvZaU5HKS
>ostream&operator<<(ostream&_s1ad39xWY_sgvZaU5HKos,const pair<
_s1ad39xWY_sgvZaU5HKF,_s1ad39xWY_sgvZaU5HKS>&
_s1ad39xWY_sgvZaU5HKp){return _s1ad39xWY_sgvZaU5HKos<<"\x28"<<
_s1ad39xWY_sgvZaU5HKp.first<<"\x2c\x20"<<_s1ad39xWY_sgvZaU5HKp.second
<<"\x29";}template<typename _s1ad39xWY_sgvZaU5HKT>ostream&operator<<(
ostream&_s1ad39xWY_sgvZaU5HKos,const vector<_s1ad39xWY_sgvZaU5HKT>&
_s1ad39xWY_sgvZaU5HKv){_s1ad39xWY_sgvZaU5HKos<<"\x7b";for(auto 
_s1ad39xWY_sgvZaU5HKit=_s1ad39xWY_sgvZaU5HKv.begin();
_s1ad39xWY_sgvZaU5HKit!=_s1ad39xWY_sgvZaU5HKv.end();++
_s1ad39xWY_sgvZaU5HKit){if(_s1ad39xWY_sgvZaU5HKit!=
_s1ad39xWY_sgvZaU5HKv.begin())_s1ad39xWY_sgvZaU5HKos<<"\x2c\x20";
_s1ad39xWY_sgvZaU5HKos<<*_s1ad39xWY_sgvZaU5HKit;}return 
_s1ad39xWY_sgvZaU5HKos<<"\x7d";}template<typename 
_s1ad39xWY_sgvZaU5HKT>ostream&operator<<(ostream&
_s1ad39xWY_sgvZaU5HKos,const set<_s1ad39xWY_sgvZaU5HKT>&
_s1ad39xWY_sgvZaU5HKv){_s1ad39xWY_sgvZaU5HKos<<"\x5b";for(auto 
_s1ad39xWY_sgvZaU5HKit=_s1ad39xWY_sgvZaU5HKv.begin();
_s1ad39xWY_sgvZaU5HKit!=_s1ad39xWY_sgvZaU5HKv.end();++
_s1ad39xWY_sgvZaU5HKit){if(_s1ad39xWY_sgvZaU5HKit!=
_s1ad39xWY_sgvZaU5HKv.begin())_s1ad39xWY_sgvZaU5HKos<<"\x2c\x20";
_s1ad39xWY_sgvZaU5HKos<<*_s1ad39xWY_sgvZaU5HKit;}return 
_s1ad39xWY_sgvZaU5HKos<<"\x5d";}template<typename 
_s1ad39xWY_sgvZaU5HKT>ostream&operator<<(ostream&
_s1ad39xWY_sgvZaU5HKos,const multiset<_s1ad39xWY_sgvZaU5HKT>&
_s1ad39xWY_sgvZaU5HKv){_s1ad39xWY_sgvZaU5HKos<<"\x5b";for(auto 
_s1ad39xWY_sgvZaU5HKit=_s1ad39xWY_sgvZaU5HKv.begin();
_s1ad39xWY_sgvZaU5HKit!=_s1ad39xWY_sgvZaU5HKv.end();++
_s1ad39xWY_sgvZaU5HKit){if(_s1ad39xWY_sgvZaU5HKit!=
_s1ad39xWY_sgvZaU5HKv.begin())_s1ad39xWY_sgvZaU5HKos<<"\x2c\x20";
_s1ad39xWY_sgvZaU5HKos<<*_s1ad39xWY_sgvZaU5HKit;}return 
_s1ad39xWY_sgvZaU5HKos<<"\x5d";}template<typename 
_s1ad39xWY_sgvZaU5HKF,typename _s1ad39xWY_sgvZaU5HKS>ostream&operator
<<(ostream&_s1ad39xWY_sgvZaU5HKos,const map<_s1ad39xWY_sgvZaU5HKF,
_s1ad39xWY_sgvZaU5HKS>&_s1ad39xWY_sgvZaU5HKv){
_s1ad39xWY_sgvZaU5HKos<<"\x5b";for(auto _s1ad39xWY_sgvZaU5HKit=
_s1ad39xWY_sgvZaU5HKv.begin();_s1ad39xWY_sgvZaU5HKit!=
_s1ad39xWY_sgvZaU5HKv.end();++_s1ad39xWY_sgvZaU5HKit){if(
_s1ad39xWY_sgvZaU5HKit!=_s1ad39xWY_sgvZaU5HKv.begin())
_s1ad39xWY_sgvZaU5HKos<<"\x2c\x20";_s1ad39xWY_sgvZaU5HKos<<
_s1ad39xWY_sgvZaU5HKit->first<<"\x20\x3d\x20"<<_s1ad39xWY_sgvZaU5HKit
->second;}return _s1ad39xWY_sgvZaU5HKos<<"\x5d";}int 
_s1ad39xWY_sF9VBZWlQwxtydy(int _s1ad39xWY_sF9VBZWlQn){int 
_s1ad39xWY_sF9VBZWlQa=0;for(int _s1ad39xWY_sF9VBZWlQi=0;
_s1ad39xWY_sF9VBZWlQi<=_s1ad39xWY_sF9VBZWlQn;
_s1ad39xWY_sF9VBZWlQi++){int _s1ad39xWY_sF9VBZWlQb=
_s1ad39xWY_sF9VBZWlQi;_s1ad39xWY_sF9VBZWlQa+=
_s1ad39xWY_sF9VBZWlQb;}return _s1ad39xWY_sF9VBZWlQa;}const int 
_s1ad39xWYN=100000;const int _s1ad39xWYMOD=1000000007;int32_t main(){
ios_base::sync_with_stdio(false);cin.tie(0);_s1ad39xWY_sF9VBZWlQwxtydy(1000
);_s1ad39xWY_sF9VBZWlQwxtydy(1000);_s1ad39xWY_sF9VBZWlQwxtydy(1000);
_s1ad39xWY_sF9VBZWlQwxtydy(1000);_s1ad39xWY_sF9VBZWlQwxtydy(1000);
_s1ad39xWY_sF9VBZWlQwxtydy(1000);_s1ad39xWY_sF9VBZWlQwxtydy(1000);
_s1ad39xWY_sF9VBZWlQwxtydy(1000);_s1ad39xWY_sF9VBZWlQwxtydy(1000);
_s1ad39xWYtest{_s1ad39xWYtk(_s1ad39xWYn)_s1ad39xWYarrin(
_s1ad39xWYa,_s1ad39xWYn)_s1ad39xWYfor0(_s1ad39xWYn)
_s1ad39xWYa[_s1ad39xWYi]=abs(_s1ad39xWYa[_s1ad39xWYi]);int 
_s1ad39xWYcnt=0;int _s1ad39xWYcnt2=0;_s1ad39xWYfor0(
_s1ad39xWYn){if(_s1ad39xWYi&1){_s1ad39xWYa[_s1ad39xWYi]*=-1;
}}_s1ad39xWYdisp(_s1ad39xWYa)_s1ad39xWYNL}
_s1ad39xWY_sF9VBZWlQwxtydy(1000);_s1ad39xWY_sF9VBZWlQwxtydy(1000);
_s1ad39xWY_sF9VBZWlQwxtydy(1000);_s1ad39xWY_sF9VBZWlQwxtydy(1000);
_s1ad39xWY_sF9VBZWlQwxtydy(1000);_s1ad39xWY_sF9VBZWlQwxtydy(1000);
_s1ad39xWY_sF9VBZWlQwxtydy(1000);return 0;}

