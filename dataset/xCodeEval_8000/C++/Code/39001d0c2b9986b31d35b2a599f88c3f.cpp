
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOpii pair<int,int>
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOpb push_back
template<typename _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOT>ostream&
operator<<(ostream&_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos,const vector<
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOT>&
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOv){
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<"\x7b";for(auto 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit=
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOv.begin();
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit!=
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOv.end();++
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit){if(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit!=
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOv.begin())
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<"\x2c\x20";
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<*
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit;}return 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<"\x7d";}
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOvi vector<int>
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOed end()
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAObg begin()
template<typename _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOF,typename 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOS>ostream&operator<<(ostream&
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos,const pair<
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOF,
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOS>&
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOp){return 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<"\x28"<<
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOp.first<<"\x2c\x20"<<
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOp.second<<"\x29";}
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOsz size()
template<typename _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOT>ostream&
operator<<(ostream&_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos,const set<
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOT>&
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOv){
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<"\x5b";for(auto 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit=
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOv.begin();
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit!=
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOv.end();++
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit){if(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit!=
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOv.begin())
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<"\x2c\x20";
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<*
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit;}return 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<"\x5d";}
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOln length()
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOall(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOx) \
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOx.begin(),\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOx.end()
#define endl "\n"
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAONL cout<<'\n';
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOF first
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOS second
template<typename _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOT>ostream&
operator<<(ostream&_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos,const 
multiset<_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOT>&
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOv){
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<"\x5b";for(auto 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit=
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOv.begin();
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit!=
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOv.end();++
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit){if(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit!=
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOv.begin())
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<"\x2c\x20";
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<*
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit;}return 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<"\x5d";}
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOdisp(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOx) for(auto \
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOt : \
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOx )cout<<\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOt\
<<"\x20";
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOfor0(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOn) for(int \
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOi=0;\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOi<\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOn;\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOi\
++)
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOfor0j(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOn) for(int \
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOj=0;\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOj<\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOn;\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOj\
++)
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOSS <<"\x20"<<
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOarrin(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOn) \
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOvi \
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOn);\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOfor0(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOn){cin>>\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa[\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOi];}
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOpf(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOx) cout<<\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOx<<endl;
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOCheck \
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOpf(\
"\x43\x68\x65\x63\x6b")
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOgridin(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOnum,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOn,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOm) \
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOfor0(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOn){\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOfor0j(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOm) cin>>\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOnum[\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOi][\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOj];}
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOdispgrid(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOnum,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOn,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOm) \
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOfor0(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOn){\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOfor0j(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOm) cout<<\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOnum[\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOi][\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOj]<<\
"\x20"; cout<<endl;}
template<typename _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOF,typename 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOS>ostream&operator<<(ostream&
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos,const map<
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOF,
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOS>&
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOv){
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<"\x5b";for(auto 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit=
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOv.begin();
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit!=
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOv.end();++
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit){if(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit!=
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOv.begin())
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<"\x2c\x20";
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit->first<<"\x20\x3d\x20"<<
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOit->second;}return 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOos<<"\x5d";}
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtkst(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOx) string \
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOx;cin >> \
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOx;
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa) int \
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa;cin>>\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa;
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk2(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOb)\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa)\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOb)
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk3(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOb,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOc)\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk2(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOb)\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOc)
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk4(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOb,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOc,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOd)\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk2(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOb)\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk2(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOc,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOd)
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk5(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOb,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOc,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOd,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOe)\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk4(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOb,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOc,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOd\
)_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOe)
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk6(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOb,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOc,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOd,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOe,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOf\
)_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk3(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOb,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOc\
)_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk3(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOd,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOe,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOf\
)
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk7(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOb,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOc,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOd,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOe,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOf\
,_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOg)\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk6(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOb,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOc,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOd,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOe,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOf\
)_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOg)
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk8(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOb,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOc,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOd,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOe,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOf\
,_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOg,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOh)\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk7(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOb,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOc,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOd,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOe\
,_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOf,\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOg)\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOh)
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOYES cout<<"\x59\x45\x53"<<\
endl;
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOYes cout<<"\x59\x65\x73"<<\
endl;
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAONO cout<<"\x4e\x4f"<<endl;
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAONo cout<<"\x4e\x6f"<<endl;
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOyes cout<<"\x79\x65\x73"<<\
endl;
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOno cout<<"\x6e\x6f"<<endl;
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOvpii vector<\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOpii>
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOacum accumulate
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOfmap \
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOgp_hash_table
#define LONG _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOLLONG
const int _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOMOD=1000000007;const int 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAON=100000;vector<string>
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOvec_splitter(string 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOs){
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOs+=((char)(0x1bf+8452-0x2297));
vector<string>_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOres;while(!
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOs.empty()){
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOres.push_back(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOs.substr(0,
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOs.find(((char)(0xb02+4469-0x1c4b)))
));_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOs=
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOs.substr(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOs.find(((char)(0xd1a+4364-0x1dfa)))
+1);}return _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOres;}void 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOdebug_out(vector<string>
__attribute__((unused))_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOargs,
__attribute__((unused))int _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOidx,
__attribute__((unused))int _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOLINE_NUM
){cerr<<endl;}template<typename 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOHead,typename...
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOTail>void 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOdebug_out(vector<string>
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOargs,int 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOidx,int 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOLINE_NUM,
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOHead 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOH,
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOTail...
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOT){if(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOidx>0)cerr<<"\x2c\x20";else cerr<<
"\x4c\x69\x6e\x65\x28"<<_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOLINE_NUM<<
"\x29\x20\x3d\x20\x20";stringstream 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOss;
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOss<<
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOH;cerr<<
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOargs[
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOidx]<<"\x20\x3d\x20"<<
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOss.str();
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOdebug_out(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOargs,
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOidx+1,
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOLINE_NUM,
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOT...);}
#ifndef ONLINE_JUDGE
#define _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOdb(...) \
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOdebug_out(\
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOvec_splitter(#__VA_ARGS__), 0, \
__LINE__, \
__VA_ARGS__)
#endif
bool _sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOcmp(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOpii 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa,
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOpii 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOb){return 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa.
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOF<
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOb.
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOF;}int32_t main(){ios_base::
sync_with_stdio(false);cin.tie(0);
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOtk2(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOn,
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOk)
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOarrin(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa,
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOn)bool 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOhoga=true;
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOfor0(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOn){
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOfor0j(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOn){if(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOi==
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOj)continue;int 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOdiff=abs(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa[
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOi]-
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa[
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOj]);if(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOdiff>
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOk){
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOhoga=false;}}}if(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOhoga){
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOYES 
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOfor0(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOn){
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOfor0j(
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOa[
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOi]){cout<<
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOj%
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAOk+1<<((char)(0x13b6+4580-0x257a));}
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAONL}}else{
_sbty4V6Ef_s3ESrumMi_sbsbfjPrY_sLr3M3oAONO}return 0;}

