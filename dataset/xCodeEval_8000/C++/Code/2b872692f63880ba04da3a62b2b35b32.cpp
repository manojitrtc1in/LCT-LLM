
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdpii pair<int,int>
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdpb push_back
template<typename _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdT>ostream&
operator<<(ostream&_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos,const vector<
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdT>&
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdv){
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<"\x7b";for(auto 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit=
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdv.begin();
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit!=
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdv.end();++
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit){if(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit!=
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdv.begin())
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<"\x2c\x20";
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<*
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit;}return 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<"\x7d";}
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdvi vector<int>
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIded end()
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdbg begin()
template<typename _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdF,typename 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdS>ostream&operator<<(ostream&
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos,const pair<
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdF,
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdS>&
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdp){return 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<"\x28"<<
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdp.first<<"\x2c\x20"<<
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdp.second<<"\x29";}
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdsz size()
template<typename _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdT>ostream&
operator<<(ostream&_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos,const set<
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdT>&
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdv){
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<"\x5b";for(auto 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit=
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdv.begin();
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit!=
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdv.end();++
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit){if(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit!=
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdv.begin())
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<"\x2c\x20";
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<*
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit;}return 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<"\x5d";}
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdln length()
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdall(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdx) \
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdx.begin(),\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdx.end()
#define endl "\n"
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdNL cout<<'\n';
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdF first
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdS second
template<typename _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdT>ostream&
operator<<(ostream&_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos,const 
multiset<_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdT>&
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdv){
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<"\x5b";for(auto 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit=
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdv.begin();
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit!=
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdv.end();++
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit){if(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit!=
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdv.begin())
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<"\x2c\x20";
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<*
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit;}return 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<"\x5d";}
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIddisp(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdx) for(auto \
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdt : \
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdx )cout<<\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdt\
<<"\x20";
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdfor0(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdn) for(int \
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdi=0;\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdi<\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdn;\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdi\
++)
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdfor0j(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdn) for(int \
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdj=0;\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdj<\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdn;\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdj\
++)
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdSS <<"\x20"<<
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdarrin(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdn) \
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdvi \
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdn);\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdfor0(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdn){cin>>\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda[\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdi];}
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdpf(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdx) cout<<\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdx<<endl;
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdCheck \
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdpf(\
"\x43\x68\x65\x63\x6b")
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdgridin(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdnum,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdn,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdm) \
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdfor0(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdn){\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdfor0j(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdm) cin>>\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdnum[\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdi][\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdj];}
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIddispgrid(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdnum,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdn,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdm) \
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdfor0(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdn){\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdfor0j(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdm) cout<<\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdnum[\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdi][\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdj]<<\
"\x20"; cout<<endl;}
template<typename _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdF,typename 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdS>ostream&operator<<(ostream&
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos,const map<
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdF,
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdS>&
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdv){
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<"\x5b";for(auto 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit=
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdv.begin();
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit!=
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdv.end();++
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit){if(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit!=
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdv.begin())
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<"\x2c\x20";
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit->first<<"\x20\x3d\x20"<<
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit->second;}return 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdos<<"\x5d";}
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtkst(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdx) string \
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdx;cin >> \
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdx;
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda) int \
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda;cin>>\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda;
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk2(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdb)\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda)\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdb)
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk3(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdb,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdc)\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk2(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdb)\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdc)
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk4(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdb,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdc,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdd)\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk2(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdb)\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk2(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdc,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdd)
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk5(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdb,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdc,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdd,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIde)\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk4(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdb,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdc,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdd\
)_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIde)
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk6(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdb,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdc,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdd,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIde,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdf\
)_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk3(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdb,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdc\
)_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk3(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdd,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIde,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdf\
)
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk7(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdb,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdc,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdd,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIde,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdf\
,_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdg)\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk6(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdb,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdc,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdd,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIde,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdf\
)_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdg)
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk8(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdb,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdc,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdd,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIde,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdf\
,_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdg,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdh)\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk7(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdb,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdc,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdd,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIde\
,_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdf,\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdg)\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdh)
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdYES cout<<"\x59\x45\x53"<<\
endl;
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdYes cout<<"\x59\x65\x73"<<\
endl;
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdNO cout<<"\x4e\x4f"<<endl;
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdNo cout<<"\x4e\x6f"<<endl;
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdyes cout<<"\x79\x65\x73"<<\
endl;
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdno cout<<"\x6e\x6f"<<endl;
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdvpii vector<\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdpii>
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdacum accumulate
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdfmap \
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdgp_hash_table
#define LONG _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdLLONG
const int _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdMOD=1000000007;const int 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdN=100000;vector<string>
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdvec_splitter(string 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds){
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds+=((char)(0xdeb+1434-0x1359));
vector<string>_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdres;while(!
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds.empty()){
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdres.push_back(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds.substr(0,
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds.find(((char)(0x89+8262-0x20a3))))
);_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds=
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds.substr(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds.find(((char)(0x609+4823-0x18b4)))
+1);}return _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdres;}void 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIddebug_out(vector<string>
__attribute__((unused))_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdargs,
__attribute__((unused))int _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdidx,
__attribute__((unused))int _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdLINE_NUM
){cerr<<endl;}template<typename 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdHead,typename...
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdTail>void 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIddebug_out(vector<string>
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdargs,int 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdidx,int 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdLINE_NUM,
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdHead 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdH,
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdTail...
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdT){if(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdidx>0)cerr<<"\x2c\x20";else cerr<<
"\x4c\x69\x6e\x65\x28"<<_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdLINE_NUM<<
"\x29\x20\x3d\x20\x20";stringstream 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdss;
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdss<<
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdH;cerr<<
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdargs[
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdidx]<<"\x20\x3d\x20"<<
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdss.str();
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIddebug_out(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdargs,
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdidx+1,
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdLINE_NUM,
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdT...);}
#ifndef ONLINE_JUDGE
#define _sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIddb(...) \
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIddebug_out(\
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdvec_splitter(#__VA_ARGS__), 0, \
__LINE__, \
__VA_ARGS__)
#endif
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdvi 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdarrange(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdvi&
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda){set<int>
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdall(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda));multiset<int>
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds2(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdall(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda));
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdvi 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtemp;while(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds2.
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdsz>0){for(int 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdx:
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds){if(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds2.find(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdx)!=
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds2.end()){
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtemp.
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdpb(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdx);
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds2.erase(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds2.find(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdx));}else{continue;}}}return 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtemp;}int32_t main(){ios_base::
sync_with_stdio(false);cin.tie(0);
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdtk(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdn)
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdarrin(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda,
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdn)multiset<int>
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdall(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIda));int 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdcum=0;int 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdres=0;while(true){auto 
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit=
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds.lower_bound(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdcum);if(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit==
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds.
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIded)break;
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdcum+=(*
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit);
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIds.erase(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdit);
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdres++;}
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdpf(
_sEsibiZuR_s7VQLG6IE_s9fi0djDo_sl1GtJIIdres)return 0;}

