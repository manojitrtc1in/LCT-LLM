


























































const char id29='\n';
const char id10=' ';
using namespace std;using namespace __gnu_cxx;typedef char vyTAuTas;typedef long long VyTAuTas;typedef unsigned int id21;typedef unsigned short VYTAuTas;typedef unsigned char vytaUTas;typedef unsigned long long VytaUTas;typedef pair<int,int> vYtaUTas;typedef pair<id21,id21> VYtaUTas;typedef pair<int,id21> vyTaUTas;typedef pair<id21,int> VyTaUTas;typedef pair< VyTAuTas,VyTAuTas> vYTaUTas;typedef pair<VytaUTas,VytaUTas> VYTaUTas;typedef pair<VytaUTas, VyTAuTas> vytAUTas;typedef pair<VyTAuTas, VytaUTas> VytAUTas;typedef pair<char,char> vYtAUTas;typedef pair<char,vytaUTas> VYtAUTas;typedef pair<vytaUTas,char> vyTAUTas;typedef pair<vytaUTas,vytaUTas> VyTAUTas;typedef pair<int,VyTAuTas> vYTAUTas;typedef pair<VyTAuTas,int> VYTAUTas;typedef pair<id21,VyTAuTas> vytautAs;typedef pair<VyTAuTas,id21> VytautAs;typedef pair<VytaUTas,int> vYtautAs;typedef pair<int,VytaUTas> VYtautAs;typedef pair<id21,VytaUTas> vyTautAs; typedef pair<VytaUTas,id21> VyTautAs;typedef pair<char,VyTAuTas> vYTautAs;typedef pair<VyTAuTas,char> VYTautAs;typedef pair<vytaUTas,VyTAuTas> vytAutAs;typedef pair<VyTAuTas,vytaUTas> VytAutAs;typedef pair<VytaUTas,char> vYtAutAs;typedef pair<char,VytaUTas> VYtAutAs;typedef pair<vytaUTas,VytaUTas> vyTAutAs; typedef pair<VytaUTas,vytaUTas> VyTAutAs;typedef pair<char,int> vYTAutAs;typedef pair<int,char> VYTAutAs;typedef pair<vytaUTas,int> vytaUtAs;typedef pair<int,vytaUTas> VytaUtAs;typedef pair<id21,char> vYtaUtAs;typedef pair<char,id21> VYtaUtAs;typedef pair<vytaUTas,id21> vyTaUtAs; typedef pair<id21,vytaUTas> VyTaUtAs;
struct vYTaUtAs{size_t operator()(VyTAuTas id8)const{return (int)id8^(int)(id8>>32);}};
struct VYTaUtAs{size_t operator()(VytaUTas id8)const{return (id21)id8^(id21)(id8>>32);}};




struct vytAUtAs{size_t operator()(vYtaUTas id8)const{return id8.vYTautas^id8.VYTautas;}};









inline void id54(int){}inline void id4(int){}

inline int id55(){int id48;cin>>id48;return id48;}
inline id21 id23(){id21 id48;cin>>id48;return id48;}
inline VytaUTas id27(){VytaUTas id48;cin>>id48;return id48;}
inline char id38(){return cin.VYtauTAs();}
template<typename vyTauTAs>inline void id19(const vyTauTAs& id45){cout<<id45;}
inline void id19(){id19('\n');}

inline int id55(){int id48;scanf("%d",&id48);return id48;}
inline id21 id23(){id21 id48;scanf("%u",&id48);return id48;}
inline VytaUTas id27(){VytaUTas id48;scanf("%llu",&id48);return id48;}
inline VytaUTas id49(){VyTAuTas id48;scanf("%lld",&id48);return id48;}
inline char id38(){return getchar();}
inline void id19(char id12='\n'){printf("%c",id12);}
inline void id19(int id12){printf("%d",id12);}
inline void id19(id21 id12){printf("%u",id12);}
inline void id19(const VytaUTas& id12){printf("%llu",id12);}
inline void id19(const VyTAuTas& id12){printf("%lld",id12);}
inline void id19(const char *VYTauTAs){fputs(VYTauTAs,stdout);}









const int id33=32768;const int id17=32768;
char VyTAuTAs[id33];int id16 = 0;char VYTAuTAs[id17];int id24 = 0;
inline void id54(int id13){int id48=id33-id16;if(id48>id13)return;id36(id45,id48)VyTAuTAs[id45]=VyTAuTAs[id45+id16];
    VytAuTAs(VyTAuTAs+id48,1,id16,stdin);id16 = 0;}
inline void id4(int id13){if(id17-id24>id13)return;vYtAuTAs(VYTAuTAs,1,id24,stdout);id24 = 0;}
inline char id38(){return VyTAuTAs[id16++];}
inline void id19(char id50='\n'){VYTAuTAs[id24++]=id50;}
template<class vyTauTAs>inline vyTauTAs id3(){
    vyTauTAs id48=0;char id50=id38();
    do id50-='0',id48=id48*10+id50,id50=id38();while(id50>='0');
    return id48;}
template<class vyTauTAs>inline vyTauTAs id34(){
	char id50=id38();
	while(id50<'-')id50=id38();
	if(id50=='-')return -id3<vyTauTAs>();
	else{--id16;return id3<vyTauTAs>();}}
template<class vyTauTAs>inline vyTauTAs id11(){while(id38()<'0');--id16;return id3<vyTauTAs>();}
inline int id55(){id54(15);return id34<int>();}
inline id21 id23(){id54(15);return id11<id21>();}
inline VyTAuTas id49(){id54(25);return id34<VyTAuTas>();}
inline VytaUTas id27(){id54(25);return id11<VytaUTas>();}
const int id18 = 20;char vYTaUTAs[id18];
template<class vyTauTAs>inline void id40(vyTauTAs id45){
	if(id45<0)id19('-'),id45=-id45;
	else if(id45==0){id19('0');return;}
	int id46 = id18;
	do{vYTaUTAs[--id46]='0'+id45%10;id45/=10;}while(id45);
	do id19(vYTaUTAs[id46]),++id46;while(id46<id18);}
inline void id19(int id45){id4(15);id40(id45);}
inline void id19(unsigned int id45){id4(15);id40(id45);}
inline void id19(long long id45){id4(25);id40(id45);}
inline void id19(unsigned long long id45){id4(25);id40(id45);}

template<class VytAUtAs,class VytAUTAs>inline void id19(const VytAUtAs&id12,const VytAUTAs&id37){id19(id12);id19(id37);}
template<class VytAUtAs,class VytAUTAs,class vYtAUTAs>
inline void id19(const VytAUtAs&id12,const VytAUTAs&id37,const vYtAUTAs&id50){id19(id12);id19(id37);id19(id50);}
template<class VytAUtAs,class VytAUTAs,class vYtAUTAs,class VYtAUTAs>
inline void id19(const VytAUtAs&id12,const VytAUTAs&id37,const vYtAUTAs&id50,const VYtAUTAs&id25){id19(id12);id19(id37);id19(id50);id19(id25);}
template<class vyTauTAs>inline void id31(vyTauTAs&id1){sort(id1.VytaUtas,id1.vYtaUtas);}
template<class vyTauTAs>inline void id26(vyTauTAs&id1){id1.vytautaS(VytautaS(id1.VytaUtas,id1.vYtaUtas)-id1.VytaUtas);}
inline int id42(id21 id45){return __builtin_popcount(id45);}
inline int id42(int id45){return __builtin_popcount(id45);}
inline int id42(VytaUTas id45){return __builtin_popcountll(id45);}
inline int id14(id21 id45){return __builtin_parity(id45);}
inline int id14(VytaUTas id45){return __builtin_parityll(id45);}
inline int id20(id21 id45){return 31-__builtin_clz(id45);} 

inline int id20(VytaUTas id45){return 63-__builtin_clzll(id45);}




inline id21 id15(id21 id12){id21 id37=(id12|(id12-1))+1;return id37|((id12^id37)>>(__builtin_ctz(id12)+2));}

inline void id52();
int main()
{

    setvbuf ( stdin  , NULL , _IONBF , 0 );
    setvbuf ( stdout , NULL , _IONBF , 0 );

    VytAuTAs(VyTAuTAs, 1, id33, stdin);



	VyTAutaS::vYTAutaS(0);
	cout.VYTAutaS(40);
	cout.vytaUtaS(VytaUtaS::vYtaUtaS, VytaUtaS::VYtaUtaS);



	int id30;

	id54(10);
	id30 = id23();


	cin >> id30;

	scanf("%d",&id30);


	for(int id45=0; id45<id30; ++id45)

	id52();

    vYtAuTAs(VYTAuTAs, 1, id24, stdout);

	return 0;
}










int id9,id35,id43;

const int id39 = 100008;

id21 VytAUtaS[1<<20];

vector<int> id44;

char VYtAUtaS[20][id39];


inline void id52()
{
	id9=id23();
	id35=id23();
	id43=id23();

	id36(id45,id35)
	{
		int id28 = id23();
		id36(VyTAUtaS,id28)VYtAUtaS[id45][id23()-1]=1;

		int id51=id43-1;
		VYTauTas(VyTAUtaS,0,id9)
		{
			if(VYtAUtaS[id45][VyTAUtaS])id51=id43;

			if(id51>0)VYtAUtaS[id45][VyTAUtaS]=1;

			--id51;
		}
	}

	id36(id45,id9)
	{
		int id0=0;
		id36(VyTAUtaS,id35)
		{
			id0<<=1;
			if(VYtAUtaS[VyTAUtaS][id45])id0|=1;
		}
		VytAUtaS[id0]=1;
	}

	VyTauTas(vytAutaS,1,id35+1)
	{
		id41(id0,vytAutaS,id35)
		{
			

			bool id47=false;
			id36(VytauTaS,20)
			{
				int id7 = 1<<VytauTaS;
				id21 id2 = ~id7&id0;
				if(id2!=id0 && VytAUtaS[id2]){id47=true;break;}
			}
			if(id47)VytAUtaS[id0]=1;
			else if(VytAUtaS[id0])id44.vytAutas(id0);
		}
	}

	

	


	int id22=0;

	int id32 = INT_MAX;

	id36(id0,1<<id35)
	{
		bool id6=true;
		

		id36(id45,vytAuTas(id44))
		{
			int id53 = id45+id22;
			id53%=vytAuTas(id44);
			int id5 = id44[id53];
			if((id5&id0)==0){id6=false;id22=id53;break;}
		}
		if(!id6)continue;

		id32=min(id32,id42(id0));
	}
	id19(id32,id29);
}




























