
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define xxsHSZV8JYVpii pair<int,int> 
#define xxsHSZV8JYVpb push_back
template<typename xxsHSZV8JYVT>ostream&operator<<(ostream&xxsHSZV8JYVos,
const vector<xxsHSZV8JYVT>&xxsHSZV8JYVv){xxsHSZV8JYVos<<"\x7b";for(
auto xxsHSZV8JYVit=xxsHSZV8JYVv.begin();xxsHSZV8JYVit!=
xxsHSZV8JYVv.end();++xxsHSZV8JYVit){if(xxsHSZV8JYVit!=
xxsHSZV8JYVv.begin())xxsHSZV8JYVos<<"\x2c\x20";xxsHSZV8JYVos<<*
xxsHSZV8JYVit;}return xxsHSZV8JYVos<<"\x7d";}
#define xxsHSZV8JYVvi vector<int>
#define xxsHSZV8JYVed end()
#define xxsHSZV8JYVbg begin()
template<typename xxsHSZV8JYVF,typename xxsHSZV8JYVS>ostream&operator<<(
ostream&xxsHSZV8JYVos,const pair<xxsHSZV8JYVF,xxsHSZV8JYVS>&
xxsHSZV8JYVp){return xxsHSZV8JYVos<<"\x28"<<xxsHSZV8JYVp.first<<
"\x2c\x20"<<xxsHSZV8JYVp.second<<"\x29";}
#define xxsHSZV8JYVsz size()
template<typename xxsHSZV8JYVT>ostream&operator<<(ostream&xxsHSZV8JYVos,
const set<xxsHSZV8JYVT>&xxsHSZV8JYVv){xxsHSZV8JYVos<<"\x5b";for(auto
 xxsHSZV8JYVit=xxsHSZV8JYVv.begin();xxsHSZV8JYVit!=xxsHSZV8JYVv.
end();++xxsHSZV8JYVit){if(xxsHSZV8JYVit!=xxsHSZV8JYVv.begin())
xxsHSZV8JYVos<<"\x2c\x20";xxsHSZV8JYVos<<*xxsHSZV8JYVit;}return 
xxsHSZV8JYVos<<"\x5d";}
#define xxsHSZV8JYVln length()
#define xxsHSZV8JYVall(xxsHSZV8JYVx) xxsHSZV8JYVx.begin(),\
xxsHSZV8JYVx.end()
#define endl "\n"
#define xxsHSZV8JYVNL cout<<'\n';
#define xxsHSZV8JYVF first
#define xxsHSZV8JYVS second
template<typename xxsHSZV8JYVT>ostream&operator<<(ostream&xxsHSZV8JYVos,
const multiset<xxsHSZV8JYVT>&xxsHSZV8JYVv){xxsHSZV8JYVos<<"\x5b";for
(auto xxsHSZV8JYVit=xxsHSZV8JYVv.begin();xxsHSZV8JYVit!=
xxsHSZV8JYVv.end();++xxsHSZV8JYVit){if(xxsHSZV8JYVit!=
xxsHSZV8JYVv.begin())xxsHSZV8JYVos<<"\x2c\x20";xxsHSZV8JYVos<<*
xxsHSZV8JYVit;}return xxsHSZV8JYVos<<"\x5d";}
#define xxsHSZV8JYVdisp(xxsHSZV8JYVx) for(auto xxsHSZV8JYVt : \
xxsHSZV8JYVx )cout<<xxsHSZV8JYVt<<"\x20";
#define xxsHSZV8JYVfor0(xxsHSZV8JYVn) for(int xxsHSZV8JYVi=0;\
xxsHSZV8JYVi<xxsHSZV8JYVn;xxsHSZV8JYVi++)
#define xxsHSZV8JYVfor0j(xxsHSZV8JYVn) for(int xxsHSZV8JYVj=0;\
xxsHSZV8JYVj<xxsHSZV8JYVn;xxsHSZV8JYVj++)
#define xxsHSZV8JYVSS <<"\x20"<<
#define xxsHSZV8JYVarrin(xxsHSZV8JYVa,xxsHSZV8JYVn) \
xxsHSZV8JYVvi xxsHSZV8JYVa(xxsHSZV8JYVn);xxsHSZV8JYVfor0(\
xxsHSZV8JYVn){cin>>xxsHSZV8JYVa[xxsHSZV8JYVi];}
#define xxsHSZV8JYVpf(xxsHSZV8JYVx) cout<<xxsHSZV8JYVx<<endl;
#define xxsHSZV8JYVCheck xxsHSZV8JYVpf("\x43\x68\x65\x63\x6b")
#define xxsHSZV8JYVgridin(xxsHSZV8JYVnum,xxsHSZV8JYVn,\
xxsHSZV8JYVm) xxsHSZV8JYVfor0(xxsHSZV8JYVn){xxsHSZV8JYVfor0j(\
xxsHSZV8JYVm) cin>>xxsHSZV8JYVnum[xxsHSZV8JYVi][xxsHSZV8JYVj];}
#define xxsHSZV8JYVdispgrid(xxsHSZV8JYVnum,xxsHSZV8JYVn,\
xxsHSZV8JYVm) xxsHSZV8JYVfor0(xxsHSZV8JYVn){xxsHSZV8JYVfor0j(\
xxsHSZV8JYVm) cout<<xxsHSZV8JYVnum[xxsHSZV8JYVi][xxsHSZV8JYVj]<<\
"\x20"; cout<<endl;}
template<typename xxsHSZV8JYVF,typename xxsHSZV8JYVS>ostream&operator<<(
ostream&xxsHSZV8JYVos,const map<xxsHSZV8JYVF,xxsHSZV8JYVS>&
xxsHSZV8JYVv){xxsHSZV8JYVos<<"\x5b";for(auto xxsHSZV8JYVit=
xxsHSZV8JYVv.begin();xxsHSZV8JYVit!=xxsHSZV8JYVv.end();++
xxsHSZV8JYVit){if(xxsHSZV8JYVit!=xxsHSZV8JYVv.begin())
xxsHSZV8JYVos<<"\x2c\x20";xxsHSZV8JYVos<<xxsHSZV8JYVit->first<<
"\x20\x3d\x20"<<xxsHSZV8JYVit->second;}return xxsHSZV8JYVos<<"\x5d";}
#define xxsHSZV8JYVtk(xxsHSZV8JYVa) int xxsHSZV8JYVa;cin>>\
xxsHSZV8JYVa;
#define xxsHSZV8JYVtk2(xxsHSZV8JYVa,xxsHSZV8JYVb)xxsHSZV8JYVtk(\
xxsHSZV8JYVa)xxsHSZV8JYVtk(xxsHSZV8JYVb)
#define xxsHSZV8JYVtk3(xxsHSZV8JYVa,xxsHSZV8JYVb,xxsHSZV8JYVc)\
xxsHSZV8JYVtk2(xxsHSZV8JYVa,xxsHSZV8JYVb)xxsHSZV8JYVtk(\
xxsHSZV8JYVc)
#define xxsHSZV8JYVtk4(xxsHSZV8JYVa,xxsHSZV8JYVb,xxsHSZV8JYVc,\
xxsHSZV8JYVd)xxsHSZV8JYVtk2(xxsHSZV8JYVa,xxsHSZV8JYVb)\
xxsHSZV8JYVtk2(xxsHSZV8JYVc,xxsHSZV8JYVd)
#define xxsHSZV8JYVtk5(xxsHSZV8JYVa,xxsHSZV8JYVb,xxsHSZV8JYVc,\
xxsHSZV8JYVd,xxsHSZV8JYVe)xxsHSZV8JYVtk4(xxsHSZV8JYVa,\
xxsHSZV8JYVb,xxsHSZV8JYVc,xxsHSZV8JYVd)xxsHSZV8JYVtk(\
xxsHSZV8JYVe)
#define xxsHSZV8JYVtk6(xxsHSZV8JYVa,xxsHSZV8JYVb,xxsHSZV8JYVc,\
xxsHSZV8JYVd,xxsHSZV8JYVe,xxsHSZV8JYVf)xxsHSZV8JYVtk3(\
xxsHSZV8JYVa,xxsHSZV8JYVb,xxsHSZV8JYVc)xxsHSZV8JYVtk3(\
xxsHSZV8JYVd,xxsHSZV8JYVe,xxsHSZV8JYVf)
#define xxsHSZV8JYVtk7(xxsHSZV8JYVa,xxsHSZV8JYVb,xxsHSZV8JYVc,\
xxsHSZV8JYVd,xxsHSZV8JYVe,xxsHSZV8JYVf,xxsHSZV8JYVg)\
xxsHSZV8JYVtk6(xxsHSZV8JYVa,xxsHSZV8JYVb,xxsHSZV8JYVc,\
xxsHSZV8JYVd,xxsHSZV8JYVe,xxsHSZV8JYVf)xxsHSZV8JYVtk(\
xxsHSZV8JYVg)
#define xxsHSZV8JYVtk8(xxsHSZV8JYVa,xxsHSZV8JYVb,xxsHSZV8JYVc,\
xxsHSZV8JYVd,xxsHSZV8JYVe,xxsHSZV8JYVf,xxsHSZV8JYVg,\
xxsHSZV8JYVh)xxsHSZV8JYVtk7(xxsHSZV8JYVa,xxsHSZV8JYVb,\
xxsHSZV8JYVc,xxsHSZV8JYVd,xxsHSZV8JYVe,xxsHSZV8JYVf,\
xxsHSZV8JYVg)xxsHSZV8JYVtk(xxsHSZV8JYVh)
#define xxsHSZV8JYVYES cout<<"\x59\x45\x53"<<endl;
#define xxsHSZV8JYVYes cout<<"\x59\x65\x73"<<endl;
#define xxsHSZV8JYVNO cout<<"\x4e\x4f"<<endl;
#define xxsHSZV8JYVNo cout<<"\x4e\x6f"<<endl;
#define xxsHSZV8JYVyes cout<<"\x79\x65\x73"<<endl;
#define xxsHSZV8JYVno cout<<"\x6e\x6f"<<endl;
#define xxsHSZV8JYVvpii vector<xxsHSZV8JYVpii>
#define xxsHSZV8JYVacum accumulate
#define xxsHSZV8JYVfmap xxsHSZV8JYVgp_hash_table
#define LONG xxsHSZV8JYVLLONG
const int xxsHSZV8JYVMOD=1000000007;const int xxsHSZV8JYVN=100000;bool 
xxsHSZV8JYVsolve(map<int,char>&xxsHSZV8JYVmapping,string&
xxsHSZV8JYVdir,vector<string>&xxsHSZV8JYVgrid,int xxsHSZV8JYVsx,int 
xxsHSZV8JYVsy,int xxsHSZV8JYVn,int xxsHSZV8JYVm){xxsHSZV8JYVfor0
(xxsHSZV8JYVdir.xxsHSZV8JYVln){char xxsHSZV8JYVcur=
xxsHSZV8JYVmapping[xxsHSZV8JYVdir[xxsHSZV8JYVi]-
((char)(0x15fb+2735-0x207a))];if(xxsHSZV8JYVgrid[xxsHSZV8JYVsy][
xxsHSZV8JYVsx]==((char)(0x1f23+2086-0x2704)))return true;if(
xxsHSZV8JYVgrid[xxsHSZV8JYVsy][xxsHSZV8JYVsx]==
((char)(0xa6d+3549-0x1827)))return false;if(xxsHSZV8JYVcur==
((char)(0x14f4+4240-0x252f))){if(xxsHSZV8JYVsy!=0){xxsHSZV8JYVsy--;}else
{return false;}}else if(xxsHSZV8JYVcur==((char)(0x1ad5+1028-0x1e8d))){if(
xxsHSZV8JYVsx!=0){xxsHSZV8JYVsx--;}else{return false;}}else if(
xxsHSZV8JYVcur==((char)(0x470+7668-0x2220))){if(xxsHSZV8JYVsy!=
xxsHSZV8JYVn-1){xxsHSZV8JYVsy++;}else{return false;}}else{if(
xxsHSZV8JYVsx!=xxsHSZV8JYVm-1){xxsHSZV8JYVsx++;}else{return false;}}
}if(xxsHSZV8JYVgrid[xxsHSZV8JYVsy][xxsHSZV8JYVsx]==
((char)(0x11c7+4822-0x2458)))return true;return false;}int32_t main(){ios_base::
sync_with_stdio(false);cin.tie(0);string xxsHSZV8JYVa="\x55\x44\x4c\x52";
sort(xxsHSZV8JYVall(xxsHSZV8JYVa));map<int,char>xxsHSZV8JYVmapping[
24];int xxsHSZV8JYVi=0;do{xxsHSZV8JYVfor0j(4){xxsHSZV8JYVmapping[
xxsHSZV8JYVi][xxsHSZV8JYVj]=xxsHSZV8JYVa[xxsHSZV8JYVj];}
xxsHSZV8JYVi++;}while(next_permutation(xxsHSZV8JYVall(xxsHSZV8JYVa))
);xxsHSZV8JYVtk2(xxsHSZV8JYVn,xxsHSZV8JYVm)vector<string>
xxsHSZV8JYVgrid(xxsHSZV8JYVn);xxsHSZV8JYVfor0(xxsHSZV8JYVn){cin
>>xxsHSZV8JYVgrid[xxsHSZV8JYVi];}string xxsHSZV8JYVdir;cin>>
xxsHSZV8JYVdir;int xxsHSZV8JYVsx=-1;int xxsHSZV8JYVsy=-1;
xxsHSZV8JYVi=0;bool xxsHSZV8JYVrun=true;for(int xxsHSZV8JYVii=0;
xxsHSZV8JYVrun&&xxsHSZV8JYVii<xxsHSZV8JYVn;xxsHSZV8JYVii++){
xxsHSZV8JYVfor0j(xxsHSZV8JYVm){if(xxsHSZV8JYVgrid[xxsHSZV8JYVii]
[xxsHSZV8JYVj]==((char)(0x22a+5983-0x1936))){xxsHSZV8JYVsy=
xxsHSZV8JYVii;xxsHSZV8JYVsx=xxsHSZV8JYVj;xxsHSZV8JYVrun=false;
break;}}}int xxsHSZV8JYVres=0;for(int xxsHSZV8JYVk=0;xxsHSZV8JYVk<24
;xxsHSZV8JYVk++){if(xxsHSZV8JYVsolve(xxsHSZV8JYVmapping[
xxsHSZV8JYVk],xxsHSZV8JYVdir,xxsHSZV8JYVgrid,xxsHSZV8JYVsx,
xxsHSZV8JYVsy,xxsHSZV8JYVn,xxsHSZV8JYVm)){xxsHSZV8JYVres++;}}
xxsHSZV8JYVpf(xxsHSZV8JYVres)return 0;}

