
#include <vector>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;int _siTDu7N8Z_sF9VBZWlQwxtydy1(int 
_siTDu7N8Z_sF9VBZWlQn){int _siTDu7N8Z_sF9VBZWlQa=0;for(int 
_siTDu7N8Z_sF9VBZWlQi=0;_siTDu7N8Z_sF9VBZWlQi<=
_siTDu7N8Z_sF9VBZWlQn;_siTDu7N8Z_sF9VBZWlQi++){int 
_siTDu7N8Z_sF9VBZWlQb=_siTDu7N8Z_sF9VBZWlQi;_siTDu7N8Z_sF9VBZWlQa
+=_siTDu7N8Z_sF9VBZWlQb;}return _siTDu7N8Z_sF9VBZWlQa;}void 
_siTDu7N8Z_sa5pJpLXoscramb3(){cin.tie(0);int _siTDu7N8Z_sa5pJpLXon;cin
>>_siTDu7N8Z_sa5pJpLXon;int _siTDu7N8Z_sa5pJpLXok=1;while(
_siTDu7N8Z_sa5pJpLXok*_siTDu7N8Z_sa5pJpLXok<_siTDu7N8Z_sa5pJpLXon
){++_siTDu7N8Z_sa5pJpLXok;}vector<int>_siTDu7N8Z_sa5pJpLXoa;if(
_siTDu7N8Z_sa5pJpLXok*(_siTDu7N8Z_sa5pJpLXok-1)>=
_siTDu7N8Z_sa5pJpLXon){_siTDu7N8Z_sa5pJpLXoa.assign(
_siTDu7N8Z_sa5pJpLXok-1,_siTDu7N8Z_sa5pJpLXok-1);for(int 
_siTDu7N8Z_sa5pJpLXoi=0;_siTDu7N8Z_sa5pJpLXoi<
_siTDu7N8Z_sa5pJpLXon-(_siTDu7N8Z_sa5pJpLXok-1)*(
_siTDu7N8Z_sa5pJpLXok-1);_siTDu7N8Z_sa5pJpLXoi++){
_siTDu7N8Z_sa5pJpLXoa[_siTDu7N8Z_sa5pJpLXoi]+=1;}}else{
_siTDu7N8Z_sa5pJpLXoa.assign(_siTDu7N8Z_sa5pJpLXok,
_siTDu7N8Z_sa5pJpLXok);for(int _siTDu7N8Z_sa5pJpLXoi=0;
_siTDu7N8Z_sa5pJpLXoi<_siTDu7N8Z_sa5pJpLXok*_siTDu7N8Z_sa5pJpLXok
-_siTDu7N8Z_sa5pJpLXon;_siTDu7N8Z_sa5pJpLXoi++){
_siTDu7N8Z_sa5pJpLXoa[_siTDu7N8Z_sa5pJpLXoi]-=1;}}int 
_siTDu7N8Z_sa5pJpLXoszz=(int)_siTDu7N8Z_sa5pJpLXoa.size();vector<int>
_siTDu7N8Z_sa5pJpLXopos(_siTDu7N8Z_sa5pJpLXoszz,0);for(int 
_siTDu7N8Z_sa5pJpLXoi=0;_siTDu7N8Z_sa5pJpLXoi<
_siTDu7N8Z_sa5pJpLXoszz-1;_siTDu7N8Z_sa5pJpLXoi++){
_siTDu7N8Z_sa5pJpLXopos[_siTDu7N8Z_sa5pJpLXoi+1]=
_siTDu7N8Z_sa5pJpLXopos[_siTDu7N8Z_sa5pJpLXoi]+
_siTDu7N8Z_sa5pJpLXoa[_siTDu7N8Z_sa5pJpLXoi];}vector<int>
_siTDu7N8Z_sa5pJpLXostate(_siTDu7N8Z_sa5pJpLXon,0);for(int 
_siTDu7N8Z_sa5pJpLXox:_siTDu7N8Z_sa5pJpLXopos){
_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXox]=2;}while(true){vector
<int>_siTDu7N8Z_sa5pJpLXoto;for(int _siTDu7N8Z_sa5pJpLXoi=0;
_siTDu7N8Z_sa5pJpLXoi<_siTDu7N8Z_sa5pJpLXon;_siTDu7N8Z_sa5pJpLXoi
++){if(_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXoi]==0){
_siTDu7N8Z_sa5pJpLXoto.push_back(_siTDu7N8Z_sa5pJpLXoi);}}if((int)
_siTDu7N8Z_sa5pJpLXoto.size()<_siTDu7N8Z_sa5pJpLXok){cout<<0<<endl;
break;}cout<<_siTDu7N8Z_sa5pJpLXok;for(int _siTDu7N8Z_sa5pJpLXoi=0;
_siTDu7N8Z_sa5pJpLXoi<_siTDu7N8Z_sa5pJpLXok;_siTDu7N8Z_sa5pJpLXoi
++){_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXoto[
_siTDu7N8Z_sa5pJpLXoi]]=1;cout<<"\x20"<<_siTDu7N8Z_sa5pJpLXoto[
_siTDu7N8Z_sa5pJpLXoi]+1;}cout<<endl;int _siTDu7N8Z_sa5pJpLXox;cin>>
_siTDu7N8Z_sa5pJpLXox;--_siTDu7N8Z_sa5pJpLXox;for(int 
_siTDu7N8Z_sa5pJpLXoi=0;_siTDu7N8Z_sa5pJpLXoi<
_siTDu7N8Z_sa5pJpLXok;_siTDu7N8Z_sa5pJpLXoi++){if(
_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXox]==1){
_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXox]=0;}
_siTDu7N8Z_sa5pJpLXox=(_siTDu7N8Z_sa5pJpLXox+1)%
_siTDu7N8Z_sa5pJpLXon;}}}void _siTDu7N8Z_sa5pJpLXoscram2wb(){cin.tie(0
);int _siTDu7N8Z_sa5pJpLXon;cin>>_siTDu7N8Z_sa5pJpLXon;int 
_siTDu7N8Z_sa5pJpLXok=1;while(_siTDu7N8Z_sa5pJpLXok*
_siTDu7N8Z_sa5pJpLXok<_siTDu7N8Z_sa5pJpLXon){++
_siTDu7N8Z_sa5pJpLXok;}vector<int>_siTDu7N8Z_sa5pJpLXoa;if(
_siTDu7N8Z_sa5pJpLXok*(_siTDu7N8Z_sa5pJpLXok-1)>=
_siTDu7N8Z_sa5pJpLXon){_siTDu7N8Z_sa5pJpLXoa.assign(
_siTDu7N8Z_sa5pJpLXok-1,_siTDu7N8Z_sa5pJpLXok-1);for(int 
_siTDu7N8Z_sa5pJpLXoi=0;_siTDu7N8Z_sa5pJpLXoi<
_siTDu7N8Z_sa5pJpLXon-(_siTDu7N8Z_sa5pJpLXok-1)*(
_siTDu7N8Z_sa5pJpLXok-1);_siTDu7N8Z_sa5pJpLXoi++){
_siTDu7N8Z_sa5pJpLXoa[_siTDu7N8Z_sa5pJpLXoi]+=1;}}else{
_siTDu7N8Z_sa5pJpLXoa.assign(_siTDu7N8Z_sa5pJpLXok,
_siTDu7N8Z_sa5pJpLXok);for(int _siTDu7N8Z_sa5pJpLXoi=0;
_siTDu7N8Z_sa5pJpLXoi<_siTDu7N8Z_sa5pJpLXok*_siTDu7N8Z_sa5pJpLXok
-_siTDu7N8Z_sa5pJpLXon;_siTDu7N8Z_sa5pJpLXoi++){
_siTDu7N8Z_sa5pJpLXoa[_siTDu7N8Z_sa5pJpLXoi]-=1;}}int 
_siTDu7N8Z_sa5pJpLXoszz=(int)_siTDu7N8Z_sa5pJpLXoa.size();vector<int>
_siTDu7N8Z_sa5pJpLXopos(_siTDu7N8Z_sa5pJpLXoszz,0);for(int 
_siTDu7N8Z_sa5pJpLXoi=0;_siTDu7N8Z_sa5pJpLXoi<
_siTDu7N8Z_sa5pJpLXoszz-1;_siTDu7N8Z_sa5pJpLXoi++){
_siTDu7N8Z_sa5pJpLXopos[_siTDu7N8Z_sa5pJpLXoi+1]=
_siTDu7N8Z_sa5pJpLXopos[_siTDu7N8Z_sa5pJpLXoi]+
_siTDu7N8Z_sa5pJpLXoa[_siTDu7N8Z_sa5pJpLXoi];}vector<int>
_siTDu7N8Z_sa5pJpLXostate(_siTDu7N8Z_sa5pJpLXon,0);for(int 
_siTDu7N8Z_sa5pJpLXox:_siTDu7N8Z_sa5pJpLXopos){
_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXox]=2;}while(true){vector
<int>_siTDu7N8Z_sa5pJpLXoto;for(int _siTDu7N8Z_sa5pJpLXoi=0;
_siTDu7N8Z_sa5pJpLXoi<_siTDu7N8Z_sa5pJpLXon;_siTDu7N8Z_sa5pJpLXoi
++){if(_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXoi]==0){
_siTDu7N8Z_sa5pJpLXoto.push_back(_siTDu7N8Z_sa5pJpLXoi);}}if((int)
_siTDu7N8Z_sa5pJpLXoto.size()<_siTDu7N8Z_sa5pJpLXok){cout<<0<<endl;
break;}cout<<_siTDu7N8Z_sa5pJpLXok;for(int _siTDu7N8Z_sa5pJpLXoi=0;
_siTDu7N8Z_sa5pJpLXoi<_siTDu7N8Z_sa5pJpLXok;_siTDu7N8Z_sa5pJpLXoi
++){_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXoto[
_siTDu7N8Z_sa5pJpLXoi]]=1;cout<<"\x20"<<_siTDu7N8Z_sa5pJpLXoto[
_siTDu7N8Z_sa5pJpLXoi]+1;}cout<<endl;int _siTDu7N8Z_sa5pJpLXox;cin>>
_siTDu7N8Z_sa5pJpLXox;--_siTDu7N8Z_sa5pJpLXox;for(int 
_siTDu7N8Z_sa5pJpLXoi=0;_siTDu7N8Z_sa5pJpLXoi<
_siTDu7N8Z_sa5pJpLXok;_siTDu7N8Z_sa5pJpLXoi++){if(
_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXox]==1){
_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXox]=0;}
_siTDu7N8Z_sa5pJpLXox=(_siTDu7N8Z_sa5pJpLXox+1)%
_siTDu7N8Z_sa5pJpLXon;}}}
#define int long long
int _siTDu7N8Z_sF9VBZWlQwxtydy21(int _siTDu7N8Z_sF9VBZWlQn){int 
_siTDu7N8Z_sF9VBZWlQa=0;for(int _siTDu7N8Z_sF9VBZWlQi=0;
_siTDu7N8Z_sF9VBZWlQi<=_siTDu7N8Z_sF9VBZWlQn;
_siTDu7N8Z_sF9VBZWlQi++){int _siTDu7N8Z_sF9VBZWlQb=
_siTDu7N8Z_sF9VBZWlQi;_siTDu7N8Z_sF9VBZWlQa+=
_siTDu7N8Z_sF9VBZWlQb;}return _siTDu7N8Z_sF9VBZWlQa;}int 
_siTDu7N8Z_sF9VBZWl2Qwxtydy1(int _siTDu7N8Z_sF9VBZWlQn){int 
_siTDu7N8Z_sF9VBZWlQa=0;for(int _siTDu7N8Z_sF9VBZWlQi=0;
_siTDu7N8Z_sF9VBZWlQi<=_siTDu7N8Z_sF9VBZWlQn;
_siTDu7N8Z_sF9VBZWlQi++){int _siTDu7N8Z_sF9VBZWlQb=
_siTDu7N8Z_sF9VBZWlQi;_siTDu7N8Z_sF9VBZWlQa+=
_siTDu7N8Z_sF9VBZWlQb;}return _siTDu7N8Z_sF9VBZWlQa;}
#define double long double
int _siTDu7N8Z_sF9VBZdWlQwxtydy1(int _siTDu7N8Z_sF9VBZWlQn){int 
_siTDu7N8Z_sF9VBZWlQa=0;for(int _siTDu7N8Z_sF9VBZWlQi=0;
_siTDu7N8Z_sF9VBZWlQi<=_siTDu7N8Z_sF9VBZWlQn;
_siTDu7N8Z_sF9VBZWlQi++){int _siTDu7N8Z_sF9VBZWlQb=
_siTDu7N8Z_sF9VBZWlQi;_siTDu7N8Z_sF9VBZWlQa+=
_siTDu7N8Z_sF9VBZWlQb;}return _siTDu7N8Z_sF9VBZWlQa;}
#define _siTDu7N8Zpii pair<int,int>
void _siTDu7N8Z_sa5pJpLXoscram2b(){cin.tie(0);int 
_siTDu7N8Z_sa5pJpLXon;cin>>_siTDu7N8Z_sa5pJpLXon;int 
_siTDu7N8Z_sa5pJpLXok=1;while(_siTDu7N8Z_sa5pJpLXok*
_siTDu7N8Z_sa5pJpLXok<_siTDu7N8Z_sa5pJpLXon){++
_siTDu7N8Z_sa5pJpLXok;}vector<int>_siTDu7N8Z_sa5pJpLXoa;if(
_siTDu7N8Z_sa5pJpLXok*(_siTDu7N8Z_sa5pJpLXok-1)>=
_siTDu7N8Z_sa5pJpLXon){_siTDu7N8Z_sa5pJpLXoa.assign(
_siTDu7N8Z_sa5pJpLXok-1,_siTDu7N8Z_sa5pJpLXok-1);for(int 
_siTDu7N8Z_sa5pJpLXoi=0;_siTDu7N8Z_sa5pJpLXoi<
_siTDu7N8Z_sa5pJpLXon-(_siTDu7N8Z_sa5pJpLXok-1)*(
_siTDu7N8Z_sa5pJpLXok-1);_siTDu7N8Z_sa5pJpLXoi++){
_siTDu7N8Z_sa5pJpLXoa[_siTDu7N8Z_sa5pJpLXoi]+=1;}}else{
_siTDu7N8Z_sa5pJpLXoa.assign(_siTDu7N8Z_sa5pJpLXok,
_siTDu7N8Z_sa5pJpLXok);for(int _siTDu7N8Z_sa5pJpLXoi=0;
_siTDu7N8Z_sa5pJpLXoi<_siTDu7N8Z_sa5pJpLXok*_siTDu7N8Z_sa5pJpLXok
-_siTDu7N8Z_sa5pJpLXon;_siTDu7N8Z_sa5pJpLXoi++){
_siTDu7N8Z_sa5pJpLXoa[_siTDu7N8Z_sa5pJpLXoi]-=1;}}int 
_siTDu7N8Z_sa5pJpLXoszz=(int)_siTDu7N8Z_sa5pJpLXoa.size();vector<int>
_siTDu7N8Z_sa5pJpLXopos(_siTDu7N8Z_sa5pJpLXoszz,0);for(int 
_siTDu7N8Z_sa5pJpLXoi=0;_siTDu7N8Z_sa5pJpLXoi<
_siTDu7N8Z_sa5pJpLXoszz-1;_siTDu7N8Z_sa5pJpLXoi++){
_siTDu7N8Z_sa5pJpLXopos[_siTDu7N8Z_sa5pJpLXoi+1]=
_siTDu7N8Z_sa5pJpLXopos[_siTDu7N8Z_sa5pJpLXoi]+
_siTDu7N8Z_sa5pJpLXoa[_siTDu7N8Z_sa5pJpLXoi];}vector<int>
_siTDu7N8Z_sa5pJpLXostate(_siTDu7N8Z_sa5pJpLXon,0);for(int 
_siTDu7N8Z_sa5pJpLXox:_siTDu7N8Z_sa5pJpLXopos){
_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXox]=2;}while(true){vector
<int>_siTDu7N8Z_sa5pJpLXoto;for(int _siTDu7N8Z_sa5pJpLXoi=0;
_siTDu7N8Z_sa5pJpLXoi<_siTDu7N8Z_sa5pJpLXon;_siTDu7N8Z_sa5pJpLXoi
++){if(_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXoi]==0){
_siTDu7N8Z_sa5pJpLXoto.push_back(_siTDu7N8Z_sa5pJpLXoi);}}if((int)
_siTDu7N8Z_sa5pJpLXoto.size()<_siTDu7N8Z_sa5pJpLXok){cout<<0<<endl;
break;}cout<<_siTDu7N8Z_sa5pJpLXok;for(int _siTDu7N8Z_sa5pJpLXoi=0;
_siTDu7N8Z_sa5pJpLXoi<_siTDu7N8Z_sa5pJpLXok;_siTDu7N8Z_sa5pJpLXoi
++){_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXoto[
_siTDu7N8Z_sa5pJpLXoi]]=1;cout<<"\x20"<<_siTDu7N8Z_sa5pJpLXoto[
_siTDu7N8Z_sa5pJpLXoi]+1;}cout<<endl;int _siTDu7N8Z_sa5pJpLXox;cin>>
_siTDu7N8Z_sa5pJpLXox;--_siTDu7N8Z_sa5pJpLXox;for(int 
_siTDu7N8Z_sa5pJpLXoi=0;_siTDu7N8Z_sa5pJpLXoi<
_siTDu7N8Z_sa5pJpLXok;_siTDu7N8Z_sa5pJpLXoi++){if(
_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXox]==1){
_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXox]=0;}
_siTDu7N8Z_sa5pJpLXox=(_siTDu7N8Z_sa5pJpLXox+1)%
_siTDu7N8Z_sa5pJpLXon;}}}
#define _siTDu7N8Zvi vector<int>
void _siTDu7N8Z_sa5pJpLXoscramb(){cin.tie(0);int _siTDu7N8Z_sa5pJpLXon
;cin>>_siTDu7N8Z_sa5pJpLXon;int _siTDu7N8Z_sa5pJpLXok=1;while(
_siTDu7N8Z_sa5pJpLXok*_siTDu7N8Z_sa5pJpLXok<_siTDu7N8Z_sa5pJpLXon
){++_siTDu7N8Z_sa5pJpLXok;}vector<int>_siTDu7N8Z_sa5pJpLXoa;if(
_siTDu7N8Z_sa5pJpLXok*(_siTDu7N8Z_sa5pJpLXok-1)>=
_siTDu7N8Z_sa5pJpLXon){_siTDu7N8Z_sa5pJpLXoa.assign(
_siTDu7N8Z_sa5pJpLXok-1,_siTDu7N8Z_sa5pJpLXok-1);for(int 
_siTDu7N8Z_sa5pJpLXoi=0;_siTDu7N8Z_sa5pJpLXoi<
_siTDu7N8Z_sa5pJpLXon-(_siTDu7N8Z_sa5pJpLXok-1)*(
_siTDu7N8Z_sa5pJpLXok-1);_siTDu7N8Z_sa5pJpLXoi++){
_siTDu7N8Z_sa5pJpLXoa[_siTDu7N8Z_sa5pJpLXoi]+=1;}}else{
_siTDu7N8Z_sa5pJpLXoa.assign(_siTDu7N8Z_sa5pJpLXok,
_siTDu7N8Z_sa5pJpLXok);for(int _siTDu7N8Z_sa5pJpLXoi=0;
_siTDu7N8Z_sa5pJpLXoi<_siTDu7N8Z_sa5pJpLXok*_siTDu7N8Z_sa5pJpLXok
-_siTDu7N8Z_sa5pJpLXon;_siTDu7N8Z_sa5pJpLXoi++){
_siTDu7N8Z_sa5pJpLXoa[_siTDu7N8Z_sa5pJpLXoi]-=1;}}int 
_siTDu7N8Z_sa5pJpLXoszz=(int)_siTDu7N8Z_sa5pJpLXoa.size();vector<int>
_siTDu7N8Z_sa5pJpLXopos(_siTDu7N8Z_sa5pJpLXoszz,0);for(int 
_siTDu7N8Z_sa5pJpLXoi=0;_siTDu7N8Z_sa5pJpLXoi<
_siTDu7N8Z_sa5pJpLXoszz-1;_siTDu7N8Z_sa5pJpLXoi++){
_siTDu7N8Z_sa5pJpLXopos[_siTDu7N8Z_sa5pJpLXoi+1]=
_siTDu7N8Z_sa5pJpLXopos[_siTDu7N8Z_sa5pJpLXoi]+
_siTDu7N8Z_sa5pJpLXoa[_siTDu7N8Z_sa5pJpLXoi];}vector<int>
_siTDu7N8Z_sa5pJpLXostate(_siTDu7N8Z_sa5pJpLXon,0);for(int 
_siTDu7N8Z_sa5pJpLXox:_siTDu7N8Z_sa5pJpLXopos){
_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXox]=2;}while(true){vector
<int>_siTDu7N8Z_sa5pJpLXoto;for(int _siTDu7N8Z_sa5pJpLXoi=0;
_siTDu7N8Z_sa5pJpLXoi<_siTDu7N8Z_sa5pJpLXon;_siTDu7N8Z_sa5pJpLXoi
++){if(_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXoi]==0){
_siTDu7N8Z_sa5pJpLXoto.push_back(_siTDu7N8Z_sa5pJpLXoi);}}if((int)
_siTDu7N8Z_sa5pJpLXoto.size()<_siTDu7N8Z_sa5pJpLXok){cout<<0<<endl;
break;}cout<<_siTDu7N8Z_sa5pJpLXok;for(int _siTDu7N8Z_sa5pJpLXoi=0;
_siTDu7N8Z_sa5pJpLXoi<_siTDu7N8Z_sa5pJpLXok;_siTDu7N8Z_sa5pJpLXoi
++){_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXoto[
_siTDu7N8Z_sa5pJpLXoi]]=1;cout<<"\x20"<<_siTDu7N8Z_sa5pJpLXoto[
_siTDu7N8Z_sa5pJpLXoi]+1;}cout<<endl;int _siTDu7N8Z_sa5pJpLXox;cin>>
_siTDu7N8Z_sa5pJpLXox;--_siTDu7N8Z_sa5pJpLXox;for(int 
_siTDu7N8Z_sa5pJpLXoi=0;_siTDu7N8Z_sa5pJpLXoi<
_siTDu7N8Z_sa5pJpLXok;_siTDu7N8Z_sa5pJpLXoi++){if(
_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXox]==1){
_siTDu7N8Z_sa5pJpLXostate[_siTDu7N8Z_sa5pJpLXox]=0;}
_siTDu7N8Z_sa5pJpLXox=(_siTDu7N8Z_sa5pJpLXox+1)%
_siTDu7N8Z_sa5pJpLXon;}}}
#define _siTDu7N8Zmii map<int,int>
void _siTDu7N8Z_sBnZuq8f8shit(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8ZADJ map<int,set<int>>
void _siTDu7N8Z_sBnZuq8f8sh32it(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Zvpii vector<_siTDu7N8Zpii>
void _siTDu7N8Z_sBnZuq8f8shsdgit(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Zpb push_back
void _siTDu7N8Z_sBasfas8shit(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Zed end()
#define _siTDu7N8Zbg begin()
#define _siTDu7N8Zsz size()
#define _siTDu7N8Zln length()
#define _siTDu7N8Zall(_siTDu7N8Zx) _siTDu7N8Zx.begin(),\
_siTDu7N8Zx.end()
void _siTDu7N8Z_sBnZuq8sgf8shit(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define endl "\n"
void _siTDu7N8Z_sBnZuq8f8dsgit(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8ZNL cout<<'\n';
void _siTDu7N8Z_sBnsdgsfhfdghit(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8ZF first
void _siTDu7N8Z_sBsdgsf8shit(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8ZS second
void _siTDu7N8Z_sBnZuqsdgt(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Zdisp(_siTDu7N8Zx) for(auto _siTDu7N8Zt : \
_siTDu7N8Zx )cout<<_siTDu7N8Zt<<"\x20";
void _siTDu7N8Z_sBnZsdgit(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Zfor0(_siTDu7N8Zn) for(int _siTDu7N8Zi=0;\
_siTDu7N8Zi<_siTDu7N8Zn;_siTDu7N8Zi++)
void _siTDu7N8Z_gmfgjmit(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Zfor0j(_siTDu7N8Zn) for(int _siTDu7N8Zj=0;\
_siTDu7N8Zj<_siTDu7N8Zn;_siTDu7N8Zj++)
void _siTDu7N8Z_sgfjfkmhmit(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8ZSS <<"\x20"<<
void _siTDu7N8Z_sBnZudsgsdgt(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Zarrin(_siTDu7N8Za,_siTDu7N8Zn) \
_siTDu7N8Zvi _siTDu7N8Za(_siTDu7N8Zn);_siTDu7N8Zfor0(\
_siTDu7N8Zn){cin>>_siTDu7N8Za[_siTDu7N8Zi];}
void _siTDu7N8Z_sBnZuq8fdhjndfgit(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Zpf(_siTDu7N8Zx) cout<<_siTDu7N8Zx<<endl;
void _siTDu7N8Z_sBnZuqgdsgnfghit(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8ZCheck _siTDu7N8Zpf("\x43\x68\x65\x63\x6b")
void _siTDu7N8Z_sBnZuq8f8sdfghfht(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Zgridin(_siTDu7N8Znum,_siTDu7N8Zn,\
_siTDu7N8Zm) _siTDu7N8Zfor0(_siTDu7N8Zn){_siTDu7N8Zfor0j(\
_siTDu7N8Zm) cin>>_siTDu7N8Znum[_siTDu7N8Zi][_siTDu7N8Zj];}
void _siTDu7N8Z_sBnZuq8f8dgbngt(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Zdispgrid(_siTDu7N8Znum,_siTDu7N8Zn,\
_siTDu7N8Zm) _siTDu7N8Zfor0(_siTDu7N8Zn){_siTDu7N8Zfor0j(\
_siTDu7N8Zm) cout<<_siTDu7N8Znum[_siTDu7N8Zi][_siTDu7N8Zj]<<\
"\x20"; cout<<endl;}
void _siTDu7N8Zfgfgfgfgf(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Ztk(_siTDu7N8Za) int _siTDu7N8Za;cin>>\
_siTDu7N8Za;
void _siTDu7N8Z_sBnZuq8gdgit(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Ztk2(_siTDu7N8Za,_siTDu7N8Zb)_siTDu7N8Ztk(\
_siTDu7N8Za)_siTDu7N8Ztk(_siTDu7N8Zb)
void _siTDu7N8Z_sBnZudsgdsgst(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Ztk3(_siTDu7N8Za,_siTDu7N8Zb,_siTDu7N8Zc)\
_siTDu7N8Ztk2(_siTDu7N8Za,_siTDu7N8Zb)_siTDu7N8Ztk(\
_siTDu7N8Zc)
void _siTDu7N8Z_ssdfdsffddfit(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Ztk4(_siTDu7N8Za,_siTDu7N8Zb,_siTDu7N8Zc,\
_siTDu7N8Zd)_siTDu7N8Ztk2(_siTDu7N8Za,_siTDu7N8Zb)\
_siTDu7N8Ztk2(_siTDu7N8Zc,_siTDu7N8Zd)
void _siTDu7N8Z_sBnZuq8f8sdsgsdgsdt(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Ztk5(_siTDu7N8Za,_siTDu7N8Zb,_siTDu7N8Zc,\
_siTDu7N8Zd,_siTDu7N8Ze)_siTDu7N8Ztk4(_siTDu7N8Za,\
_siTDu7N8Zb,_siTDu7N8Zc,_siTDu7N8Zd)_siTDu7N8Ztk(\
_siTDu7N8Ze)
void _siTDu7N8Z_sBnqwrqwr8shit(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Ztk6(_siTDu7N8Za,_siTDu7N8Zb,_siTDu7N8Zc,\
_siTDu7N8Zd,_siTDu7N8Ze,_siTDu7N8Zf)_siTDu7N8Ztk3(\
_siTDu7N8Za,_siTDu7N8Zb,_siTDu7N8Zc)_siTDu7N8Ztk3(\
_siTDu7N8Zd,_siTDu7N8Ze,_siTDu7N8Zf)
void _siTDu7N8Z_sBnfmngjfgjit(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8ZaddEdge(_siTDu7N8Zadj) _siTDu7N8Ztk2(\
_siTDu7N8Zu,_siTDu7N8Zv) _siTDu7N8Zadj[_siTDu7N8Zu].insert(\
_siTDu7N8Zv);_siTDu7N8Zadj[_siTDu7N8Zv].insert(_siTDu7N8Zu);
void _siTDu7N8Z_sBnZuq8fsdgt(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Ztest _siTDu7N8Ztk(_siTDu7N8Ztest)while(\
_siTDu7N8Ztest--)
void _siTDu7N8Z_sBnZuq8f8fhjkiht(){int _siTDu7N8Z_sBnZuq8f8n;cin>>
_siTDu7N8Z_sBnZuq8f8n;vector<int>_siTDu7N8Z_sBnZuq8f8a(
_siTDu7N8Z_sBnZuq8f8n);for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){cin>>_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}void _siTDu7N8Z_sBnZuq8f8suyoit(){int 
_siTDu7N8Z_sBnZuq8f8n;cin>>_siTDu7N8Z_sBnZuq8f8n;vector<int>
_siTDu7N8Z_sBnZuq8f8a(_siTDu7N8Z_sBnZuq8f8n);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){cin>>
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i];}vector<int>
_siTDu7N8Z_sBnZuq8f8pref(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=0;_siTDu7N8Z_sBnZuq8f8i<
_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i++){
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i+1]=__gcd(
_siTDu7N8Z_sBnZuq8f8pref[_siTDu7N8Z_sBnZuq8f8i],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}vector<int>
_siTDu7N8Z_sBnZuq8f8suf(_siTDu7N8Z_sBnZuq8f8n+1);for(int 
_siTDu7N8Z_sBnZuq8f8i=_siTDu7N8Z_sBnZuq8f8n-1;
_siTDu7N8Z_sBnZuq8f8i>=0;_siTDu7N8Z_sBnZuq8f8i--){
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i]=__gcd(
_siTDu7N8Z_sBnZuq8f8suf[_siTDu7N8Z_sBnZuq8f8i+1],
_siTDu7N8Z_sBnZuq8f8a[_siTDu7N8Z_sBnZuq8f8i]);}long long 
_siTDu7N8Z_sBnZuq8f8ans=1;for(int _siTDu7N8Z_sBnZuq8f8i=0;
_siTDu7N8Z_sBnZuq8f8i<_siTDu7N8Z_sBnZuq8f8n;_siTDu7N8Z_sBnZuq8f8i
++){int _siTDu7N8Z_sBnZuq8f8x=__gcd(_siTDu7N8Z_sBnZuq8f8pref[
_siTDu7N8Z_sBnZuq8f8i],_siTDu7N8Z_sBnZuq8f8suf[
_siTDu7N8Z_sBnZuq8f8i+1]);_siTDu7N8Z_sBnZuq8f8ans=
_siTDu7N8Z_sBnZuq8f8ans/__gcd(_siTDu7N8Z_sBnZuq8f8ans,(long long)
_siTDu7N8Z_sBnZuq8f8x)*_siTDu7N8Z_sBnZuq8f8x;}cout<<
_siTDu7N8Z_sBnZuq8f8ans<<'\n';}
#define _siTDu7N8Zaccuracy chrono::_siTDu7N8Zsteady_clock::now().\
time_since_epoch().count()
template<typename _siTDu7N8Z_sgvZaU5HKF,typename _siTDu7N8Z_sgvZaU5HKS
>ostream&operator<<(ostream&_siTDu7N8Z_sgvZaU5HKos,const pair<
_siTDu7N8Z_sgvZaU5HKF,_siTDu7N8Z_sgvZaU5HKS>&
_siTDu7N8Z_sgvZaU5HKp){return _siTDu7N8Z_sgvZaU5HKos<<"\x28"<<
_siTDu7N8Z_sgvZaU5HKp.first<<"\x2c\x20"<<_siTDu7N8Z_sgvZaU5HKp.second
<<"\x29";}template<typename _siTDu7N8Z_sgvZaU5HKT>ostream&operator<<(
ostream&_siTDu7N8Z_sgvZaU5HKos,const vector<_siTDu7N8Z_sgvZaU5HKT>&
_siTDu7N8Z_sgvZaU5HKv){_siTDu7N8Z_sgvZaU5HKos<<"\x7b";for(auto 
_siTDu7N8Z_sgvZaU5HKit=_siTDu7N8Z_sgvZaU5HKv.begin();
_siTDu7N8Z_sgvZaU5HKit!=_siTDu7N8Z_sgvZaU5HKv.end();++
_siTDu7N8Z_sgvZaU5HKit){if(_siTDu7N8Z_sgvZaU5HKit!=
_siTDu7N8Z_sgvZaU5HKv.begin())_siTDu7N8Z_sgvZaU5HKos<<"\x2c\x20";
_siTDu7N8Z_sgvZaU5HKos<<*_siTDu7N8Z_sgvZaU5HKit;}return 
_siTDu7N8Z_sgvZaU5HKos<<"\x7d";}template<typename 
_siTDu7N8Z_sgvZaU5HKT>ostream&operator<<(ostream&
_siTDu7N8Z_sgvZaU5HKos,const set<_siTDu7N8Z_sgvZaU5HKT>&
_siTDu7N8Z_sgvZaU5HKv){_siTDu7N8Z_sgvZaU5HKos<<"\x5b";for(auto 
_siTDu7N8Z_sgvZaU5HKit=_siTDu7N8Z_sgvZaU5HKv.begin();
_siTDu7N8Z_sgvZaU5HKit!=_siTDu7N8Z_sgvZaU5HKv.end();++
_siTDu7N8Z_sgvZaU5HKit){if(_siTDu7N8Z_sgvZaU5HKit!=
_siTDu7N8Z_sgvZaU5HKv.begin())_siTDu7N8Z_sgvZaU5HKos<<"\x2c\x20";
_siTDu7N8Z_sgvZaU5HKos<<*_siTDu7N8Z_sgvZaU5HKit;}return 
_siTDu7N8Z_sgvZaU5HKos<<"\x5d";}template<typename 
_siTDu7N8Z_sgvZaU5HKT>ostream&operator<<(ostream&
_siTDu7N8Z_sgvZaU5HKos,const multiset<_siTDu7N8Z_sgvZaU5HKT>&
_siTDu7N8Z_sgvZaU5HKv){_siTDu7N8Z_sgvZaU5HKos<<"\x5b";for(auto 
_siTDu7N8Z_sgvZaU5HKit=_siTDu7N8Z_sgvZaU5HKv.begin();
_siTDu7N8Z_sgvZaU5HKit!=_siTDu7N8Z_sgvZaU5HKv.end();++
_siTDu7N8Z_sgvZaU5HKit){if(_siTDu7N8Z_sgvZaU5HKit!=
_siTDu7N8Z_sgvZaU5HKv.begin())_siTDu7N8Z_sgvZaU5HKos<<"\x2c\x20";
_siTDu7N8Z_sgvZaU5HKos<<*_siTDu7N8Z_sgvZaU5HKit;}return 
_siTDu7N8Z_sgvZaU5HKos<<"\x5d";}template<typename 
_siTDu7N8Z_sgvZaU5HKF,typename _siTDu7N8Z_sgvZaU5HKS>ostream&operator
<<(ostream&_siTDu7N8Z_sgvZaU5HKos,const map<_siTDu7N8Z_sgvZaU5HKF,
_siTDu7N8Z_sgvZaU5HKS>&_siTDu7N8Z_sgvZaU5HKv){
_siTDu7N8Z_sgvZaU5HKos<<"\x5b";for(auto _siTDu7N8Z_sgvZaU5HKit=
_siTDu7N8Z_sgvZaU5HKv.begin();_siTDu7N8Z_sgvZaU5HKit!=
_siTDu7N8Z_sgvZaU5HKv.end();++_siTDu7N8Z_sgvZaU5HKit){if(
_siTDu7N8Z_sgvZaU5HKit!=_siTDu7N8Z_sgvZaU5HKv.begin())
_siTDu7N8Z_sgvZaU5HKos<<"\x2c\x20";_siTDu7N8Z_sgvZaU5HKos<<
_siTDu7N8Z_sgvZaU5HKit->first<<"\x20\x3d\x20"<<_siTDu7N8Z_sgvZaU5HKit
->second;}return _siTDu7N8Z_sgvZaU5HKos<<"\x5d";}int 
_siTDu7N8Z_sF9VBZWlQwxtydy(int _siTDu7N8Z_sF9VBZWlQn){int 
_siTDu7N8Z_sF9VBZWlQa=0;for(int _siTDu7N8Z_sF9VBZWlQi=0;
_siTDu7N8Z_sF9VBZWlQi<=_siTDu7N8Z_sF9VBZWlQn;
_siTDu7N8Z_sF9VBZWlQi++){int _siTDu7N8Z_sF9VBZWlQb=
_siTDu7N8Z_sF9VBZWlQi;_siTDu7N8Z_sF9VBZWlQa+=
_siTDu7N8Z_sF9VBZWlQb;}return _siTDu7N8Z_sF9VBZWlQa;}const int 
_siTDu7N8ZN=100000;const int _siTDu7N8ZMOD=1000000007;int32_t main(){
ios_base::sync_with_stdio(false);cin.tie(0);_siTDu7N8Z_sF9VBZWlQwxtydy(1000
);_siTDu7N8Z_sF9VBZWlQwxtydy(1000);_siTDu7N8Z_sF9VBZWlQwxtydy(1000);
_siTDu7N8Z_sF9VBZWlQwxtydy(1000);_siTDu7N8Z_sF9VBZWlQwxtydy(1000);
_siTDu7N8Z_sF9VBZWlQwxtydy(1000);_siTDu7N8Z_sF9VBZWlQwxtydy(1000);
_siTDu7N8Z_sF9VBZWlQwxtydy(1000);_siTDu7N8Z_sF9VBZWlQwxtydy(1000);
_siTDu7N8Ztest{_siTDu7N8Ztk2(_siTDu7N8Zn,_siTDu7N8Zm)int 
_siTDu7N8Zgrid[_siTDu7N8Zn][_siTDu7N8Zm];_siTDu7N8Zgridin(
_siTDu7N8Zgrid,_siTDu7N8Zn,_siTDu7N8Zm)bool _siTDu7N8Zhoga=
true;if(_siTDu7N8Zgrid[0][0]>2 or _siTDu7N8Zgrid[0][_siTDu7N8Zm-1
]>2 or _siTDu7N8Zgrid[_siTDu7N8Zn-1][0]>2 or _siTDu7N8Zgrid[
_siTDu7N8Zn-1][_siTDu7N8Zm-1]>2){_siTDu7N8Zhoga=false;}else{
_siTDu7N8Zgrid[0][0]=2;_siTDu7N8Zgrid[_siTDu7N8Zn-1][0]=2;
_siTDu7N8Zgrid[0][_siTDu7N8Zm-1]=2;_siTDu7N8Zgrid[
_siTDu7N8Zn-1][_siTDu7N8Zm-1]=2;}_siTDu7N8Zfor0(_siTDu7N8Zm)
{if(_siTDu7N8Zi==0 or _siTDu7N8Zi==_siTDu7N8Zm-1)continue;if(
_siTDu7N8Zgrid[0][_siTDu7N8Zi]>3){_siTDu7N8Zhoga=false;}else{
_siTDu7N8Zgrid[0][_siTDu7N8Zi]=3;}if(_siTDu7N8Zgrid[
_siTDu7N8Zn-1][_siTDu7N8Zi]>3){_siTDu7N8Zhoga=false;}else{
_siTDu7N8Zgrid[_siTDu7N8Zn-1][_siTDu7N8Zi]=3;}}
_siTDu7N8Zfor0(_siTDu7N8Zn){if(_siTDu7N8Zi==0 or _siTDu7N8Zi
==_siTDu7N8Zn-1)continue;if(_siTDu7N8Zgrid[_siTDu7N8Zi][0]>3){
_siTDu7N8Zhoga=false;}else{_siTDu7N8Zgrid[_siTDu7N8Zi][0]=3;}if(
_siTDu7N8Zgrid[_siTDu7N8Zi][_siTDu7N8Zm-1]>3){_siTDu7N8Zhoga
=false;}else{_siTDu7N8Zgrid[_siTDu7N8Zi][_siTDu7N8Zm-1]=3;}}for(
int _siTDu7N8Zi=1;_siTDu7N8Zi<_siTDu7N8Zn-1;_siTDu7N8Zi++){
for(int _siTDu7N8Zj=1;_siTDu7N8Zj<_siTDu7N8Zm-1;_siTDu7N8Zj
++){if(_siTDu7N8Zgrid[_siTDu7N8Zi][_siTDu7N8Zj]>4){
_siTDu7N8Zhoga=false;}else{_siTDu7N8Zgrid[_siTDu7N8Zi][
_siTDu7N8Zj]=4;}}}if(_siTDu7N8Zhoga){cout<<"\x59\x45\x53"<<endl;
_siTDu7N8Zdispgrid(_siTDu7N8Zgrid,_siTDu7N8Zn,_siTDu7N8Zm)}
else{cout<<"\x4e\x4f"<<endl;}}_siTDu7N8Z_sF9VBZWlQwxtydy(1000);
_siTDu7N8Z_sF9VBZWlQwxtydy(1000);_siTDu7N8Z_sF9VBZWlQwxtydy(1000);
_siTDu7N8Z_sF9VBZWlQwxtydy(1000);_siTDu7N8Z_sF9VBZWlQwxtydy(1000);
_siTDu7N8Z_sF9VBZWlQwxtydy(1000);_siTDu7N8Z_sF9VBZWlQwxtydy(1000);
return 0;}

