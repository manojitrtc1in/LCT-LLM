






















































const char id30='\n';
const char id6=' ';
using namespace std;using namespace __gnu_cxx;typedef char vytAuTas;typedef long long VytAuTas;typedef unsigned int id24;typedef unsigned short VYtAuTas;typedef unsigned char vyTAuTas;typedef unsigned long long VyTAuTas;typedef pair<int,int> vYTAuTas;typedef pair<id24,id24> VYTAuTas;typedef pair<int,id24> vytaUTas;typedef pair<id24,int> VytaUTas;typedef pair< VytAuTas,VytAuTas> vYtaUTas;typedef pair<VyTAuTas,VyTAuTas> VYtaUTas;typedef pair<VyTAuTas, VytAuTas> vyTaUTas;typedef pair<VytAuTas, VyTAuTas> VyTaUTas;typedef pair<char,char> vYTaUTas;typedef pair<char,vyTAuTas> VYTaUTas;typedef pair<vyTAuTas,char> vytAUTas;typedef pair<vyTAuTas,vyTAuTas> VytAUTas;typedef pair<int,VytAuTas> vYtAUTas;typedef pair<VytAuTas,int> VYtAUTas;typedef pair<id24,VytAuTas> vyTAUTas;typedef pair<VytAuTas,id24> VyTAUTas;typedef pair<VyTAuTas,int> vYTAUTas;typedef pair<int,VyTAuTas> VYTAUTas;typedef pair<id24,VyTAuTas> vytautAs; typedef pair<VyTAuTas,id24> VytautAs;typedef pair<char,VytAuTas> vYtautAs;typedef pair<VytAuTas,char> VYtautAs;typedef pair<vyTAuTas,VytAuTas> vyTautAs;typedef pair<VytAuTas,vyTAuTas> VyTautAs;typedef pair<VyTAuTas,char> vYTautAs;typedef pair<char,VyTAuTas> VYTautAs;typedef pair<vyTAuTas,VyTAuTas> vytAutAs; typedef pair<VyTAuTas,vyTAuTas> VytAutAs;typedef pair<char,int> vYtAutAs;typedef pair<int,char> VYtAutAs;typedef pair<vyTAuTas,int> vyTAutAs;typedef pair<int,vyTAuTas> VyTAutAs;typedef pair<id24,char> vYTAutAs;typedef pair<char,id24> VYTAutAs;typedef pair<vyTAuTas,id24> vytaUtAs; typedef pair<id24,vyTAuTas> VytaUtAs;

struct vYtaUtAs{size_t operator()(VytAuTas id34)const{return (int)id34^(int)(id34>>32);}};
struct VYtaUtAs{size_t operator()(VyTAuTas id34)const{return (id24)id34^(id24)(id34>>32);}};




struct vyTaUtAs{size_t operator()(vYTAuTas id34)const{return id34.vYTautas^id34.VYTautas;}};









inline void id31(int){}inline void id26(int){}

inline int id9(){int id41;cin>>id41;return id41;}
inline id24 id49(){id24 id41;cin>>id41;return id41;}
inline VyTAuTas id3(){VyTAuTas id41;cin>>id41;return id41;}
inline char id50(){return cin.id47();}
template<typename vytauTAs>inline void id20(const vytauTAs& id19){cout<<id19;}
inline void id20(){id20('\n');}

inline int id9(){int id41;scanf("%d",&id41);return id41;}
inline id24 id49(){id24 id41;scanf("%u",&id41);return id41;}
inline VyTAuTas id3(){VyTAuTas id41;scanf("%llu",&id41);return id41;}
inline VyTAuTas id33(){VytAuTas id41;scanf("%lld",&id41);return id41;}
inline char id50(){return getchar();}
inline void id20(char id21='\n'){printf("%c",id21);}
inline void id20(int id21){printf("%d",id21);}
inline void id20(id24 id21){printf("%u",id21);}
inline void id20(const VyTAuTas& id21){printf("%llu",id21);}
inline void id20(const VytAuTas& id21){printf("%lld",id21);}
inline void id20(const char *VYtauTAs){fputs(VYtauTAs,stdout);}









const int id42=32768;const int id37=32768;
char VytAuTAs[id42];int id10 = 0;char VYtAuTAs[id37];int id16 = 0;
inline void id31(int id36){int id41=id42-id10;if(id41>id36)return;id27(id19,id41)VytAuTAs[id19]=VytAuTAs[id19+id10];
    VyTauTAs(VytAuTAs+id41,1,id10,stdin);id10 = 0;}
inline void id26(int id36){if(id37-id16>id36)return;vYTauTAs(VYtAuTAs,1,id16,stdout);id16 = 0;}
inline char id50(){return VytAuTAs[id10++];}
inline void id20(char id35='\n'){VYtAuTAs[id16++]=id35;}
template<class vytauTAs>inline vytauTAs id15(){
    vytauTAs id41=0;char id35=id50();
    do id35-='0',id41=id41*10+id35,id35=id50();while(id35>='0');
    return id41;}
template<class vytauTAs>inline vytauTAs id11(){
	char id35=id50();
	while(id35<'-')id35=id50();
	if(id35=='-')return -id15<vytauTAs>();
	else{--id10;return id15<vytauTAs>();}}
template<class vytauTAs>inline vytauTAs id18(){while(id50()<'0');--id10;return id15<vytauTAs>();}
inline int id9(){id31(15);return id11<int>();}
inline id24 id49(){id31(15);return id18<id24>();}
inline VytAuTas id33(){id31(25);return id11<VytAuTas>();}
inline VyTAuTas id3(){id31(25);return id18<VyTAuTas>();}
const int id12 = 20;char vYtaUTAs[id12];
template<class vytauTAs>inline void id29(vytauTAs id19){
	if(id19<0)id20('-'),id19=-id19;
	else if(id19==0){id20('0');return;}
	int id8 = id12;
	do{vYtaUTAs[--id8]='0'+id19%10;id19/=10;}while(id19);
	do id20(vYtaUTAs[id8]),++id8;while(id8<id12);}
inline void id20(int id19){id26(15);id29(id19);}
inline void id20(unsigned int id19){id26(15);id29(id19);}
inline void id20(long long id19){id26(25);id29(id19);}
inline void id20(unsigned long long id19){id26(25);id29(id19);}

template<class VyTaUtAs,class VyTaUTAs>inline void id20(const VyTaUtAs&id21,const VyTaUTAs&id43){id20(id21);id20(id43);}
template<class VyTaUtAs,class VyTaUTAs,class vYTaUTAs>
inline void id20(const VyTaUtAs&id21,const VyTaUTAs&id43,const vYTaUTAs&id35){id20(id21);id20(id43);id20(id35);}
template<class VyTaUtAs,class VyTaUTAs,class vYTaUTAs,class VYTaUTAs>
inline void id20(const VyTaUtAs&id21,const VyTaUTAs&id43,const vYTaUTAs&id35,const VYTaUTAs&id44){id20(id21);id20(id43);id20(id35);id20(id44);}
inline void id1();int main()
{

    setvbuf ( stdin  , NULL , _IONBF , 0 );
    setvbuf ( stdout , NULL , _IONBF , 0 );

    VyTauTAs(VytAuTAs, 1, id42, stdin);



	vYtAUTAs::VYtAUTAs(0);
	cout.vyTAUTAs(40);
	cout.VyTAUTAs(vYTAUTAs::VYTAUTAs, vYTAUTAs::vytautaS);



	int id39;

	id31(10);
	id39 = id49();


	cin >> id39;

	scanf("%d",&id39);


	for(int id19=0; id19<id39; ++id19)

	id1();

    vYTauTAs(VYtAuTAs, 1, id16, stdout);

	return 0;
}









		hash_map<int,int> id13;
		int id17 = 0;

int VyTautaS[200009];



hash_map<int,int> id40;

int id47(hash_map<int,int>& id0, int id2)
{
	if(id0.find(id2)==id0.end())return 0;
	else return id0[id2];
}

void id25(int id2)
{
	int id14 = id47(id40,id2);
	++id13[id2];

	if(id13[id2]==id14)++id17;
	else if(id13[id2]-1==id14 && id14)--id17;
}

void id38(int id2)
{
	int id14 = id47(id40,id2);
	int id48 = --id13[id2];

	if(id48==0) id13.erase(id2);
	if(id48==id14 && id14)++id17;
	else if(id48+1==id14)--id17;
}


inline void id1()
{
	int id4,id0,id32;
	id4=id49();
	id0=id49();
	id32=id49();

	id27(id19,id4)
	{
		VyTautaS[id19] = id49();
	}

	id27(id19,id0)
	{
		++id40[id49()];
	}

	vector<int> id5;

	id27(id23,id32)
	{
		

		int id45 = 0;
		id17 = 0;
		id13.clear();
		int id22;
		for(id22 = id23; id22<id4 && id45 < id0; id22+=id32)
		{
			int id2 = VyTautaS[id22];
			id25(id2);
			++id45;
		}
		if(id45<id0)continue;
		int id7 = id23;
		for(;;)
		{
			

			if(id17==vyTauTas(id40))id5.vytAutas(id7+1);
			if(id22>=id4)break;

			int id46 = VyTautaS[id22];
			int id28 = VyTautaS[id7];

			id25(id46);
			id38(id28);

			id7 += id32;
			id22 += id32;
		}
	}

	sort(id5.begin(),id5.end());

	id20(vyTauTas(id5),id30);
	id27(id19,vyTauTas(id5))id20(id5[id19],' ');
	id20();

}




























