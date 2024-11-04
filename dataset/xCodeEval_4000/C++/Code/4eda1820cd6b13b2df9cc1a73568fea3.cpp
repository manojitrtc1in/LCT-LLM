#include<map>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
#define ll long long
struct SegmentTree{
	ll l,r,sum,mx,tag,tag2;
};
SegmentTree tree[500005<<2];
ll n,res,lst,cur;
ll x[500005];
#define ls node<<1
#define rs (node<<1)|1
inline void update(ll node){
	tree[node].sum=tree[ls].sum+tree[rs].sum;
    tree[node].mx=max(tree[ls].mx,tree[rs].mx);
        double IBTBRLYCXT;IBTBRLYCXT=22204;if(IBTBRLYCXT){
            if(28191>11727){
                if(31516>10166){
                    short OIYWZWGUMU;OIYWZWGUMU=32597;
                    bool KBORLDDWJN;KBORLDDWJN=28507;
                    if(15624>14783){
                        double XPAYQSVEQU;
                        bool KTQMTWTZFW;
                    }
                    bool ATVFEDBUXZ;ATVFEDBUXZ=5419;if(ATVFEDBUXZ){
                        short YGYZAWOKXY;
                    }
                }
                double BQWXBOXCPY;BQWXBOXCPY=6361;
            }
            long long VAOVGFEAUK;
            long long FEIASNIVBT;FEIASNIVBT=18457;
        }
}
inline void create(ll l,ll r,ll node){
	tree[node]=(SegmentTree){
		l,r,0,0,0,0
	};
        if(22244>7895){
            short MVPVMWUJOD;MVPVMWUJOD=28548;if(MVPVMWUJOD){
                if(13366>13803){
                    bool XDCCNBURPK;XDCCNBURPK=13989;
                    int UPCCKTPSFJ;UPCCKTPSFJ=5412;
                }
            }
        }
	if(l==r){
		return;
	}
	ll mid=(l+r)>>1;
        if(331>31276){
            double XUKCKKWRRB;XUKCKKWRRB=2944;if(XUKCKKWRRB){
                short KHPLISVQGN;KHPLISVQGN=21673;
                if(10023>7274){
                    if(3328>5414){
                        bool JYTIEGOKKQ;
                    }
                    bool XBXALUHDZX;XBXALUHDZX=9228;if(XBXALUHDZX){
                        long long HEXFFVFFRE;
                    }
                    short FLWZRFLJBM;FLWZRFLJBM=6345;if(FLWZRFLJBM){
                        double YOOXQTHBXQ;
                        int SWBPNZOBPM;
                        short MIMUYITJME;
                        long long LVFSTHJESV;
                    }
                }
            }
            if(7446>10128){
                double MQGRWENFXI;MQGRWENFXI=16177;
                if(31692>5532){
                    bool VEXACEEMMA;VEXACEEMMA=5606;
                    if(11065>16359){
                        double EOSLBZHSUN;
                    }
                    if(9892>13627){
                        short GMZDPSFDZG;
                        long long JFHPKLADKT;
                        bool FYESZAROVH;
                    }
                }
                long long LXVYMIPDCK;
            }
            short XYCYVTPGLD;XYCYVTPGLD=25583;
        }
	create(l,mid,ls),create(mid+1,r,rs),update(node);
        if(23117>2644){
            double LTCKFKKIVJ;
            if(17820>22924){
                double VKBSTTDPFF;VKBSTTDPFF=26648;if(VKBSTTDPFF){
                    if(16774>5619){
                        int AZVUQUXROT;
                        double GISFTHWSVA;
                        long long YWTCSRLTNK;
                        short EYBHYCANBM;
                    }
                    bool MSQJZZIUHR;MSQJZZIUHR=14372;
                    double BTTXSQBCBR;BTTXSQBCBR=28650;
                }
                if(17173>31740){
                    if(10763>16891){
                        short RDTWNHMTID;
                    }
                    double OUHOEPPBMO;
                    bool KXNZUQYVPS;
                }
                if(17326>28582){
                    bool WWXKPIIHCE;WWXKPIIHCE=30063;
                }
            }
        }
}
inline void spread(ll node){
	ll lenl=tree[ls].r-tree[ls].l+1,lenr=tree[rs].r-tree[rs].l+1;
        if(17432>28544){
            if(828>28220){
                int FNDIWALLAX;FNDIWALLAX=31062;if(FNDIWALLAX){
                    long long TYAMBDKTLO;TYAMBDKTLO=22072;
                    if(23808>27160){
                        int DTDGOVKVWS;
                        double NZZOJGQYGA;
                        long long UMAYDUQNKS;
                    }
                }
                int EKBLPPACGT;EKBLPPACGT=26135;if(EKBLPPACGT){
                    long long OWRLBFHLLO;OWRLBFHLLO=9211;if(OWRLBFHLLO){
                        double SXDKTWOMBI;
                    }
                    bool GKCDYTVHSG;
                    if(5365>24741){
                        double IIIWGIIJSZ;
                        int FDJQMWIQZF;
                    }
                }
                bool UKNSMRJBST;UKNSMRJBST=11817;if(UKNSMRJBST){
                    double KSQRSYJYHA;
                    if(10789>3838){
                        double QUJBIILQGR;
                        double RJBINMMZGZ;
                        int IJFIBQPBAT;
                    }
                    short XVZPFSLVNQ;
                }
            }
            if(27853>9859){
                if(7496>18297){
                    if(9508>1820){
                        long long BRRIBTPAGH;
                        double IZYQBJHUQZ;
                    }
                }
            }
            if(13069>13617){
                if(28990>9166){
                    bool IPTBNMVVTS;IPTBNMVVTS=20463;
                }
                short BRZLWCLFWL;BRZLWCLFWL=29016;
            }
        }
	if(tree[node].tag2){
		ll tag=tree[node].tag2;
		tree[ls].sum=lenl*tree[node].tag2,tree[rs].sum=tree[node].tag2;
            int RJYRZIFLXF;RJYRZIFLXF=4416;
		tree[ls].tag=tree[rs].tag=0,tree[ls].mx=tree[rs].mx=tag;
            if(11184>12519){
                short BJCZAVIHQU;BJCZAVIHQU=21585;
                double JTPTTPPEIW;
                if(7270>10837){
                    bool YXCIVCJQUR;YXCIVCJQUR=18023;if(YXCIVCJQUR){
                        short HMEDVWYZAD;
                    }
                    double BIZBSPXTPI;BIZBSPXTPI=19761;
                }
            }
		tree[ls].tag2=tree[rs].tag2=tree[node].tag2,tree[node].tag2=0;
            bool EPFHBLNBQV;EPFHBLNBQV=16855;if(EPFHBLNBQV){
                if(8920>87){
                    if(6259>29448){
                        short SGXKQKBDOC;
                        long long OQFLQWSSIF;
                        bool MFGSZBWZXL;
                    }
                }
            }
	}
	if(tree[node].tag){
		ll tag=tree[node].tag;
		tree[ls].sum+=lenl*tree[node].tag,tree[rs].sum+=tree[node].tag;
            bool QCMYOUFVDJ;QCMYOUFVDJ=25073;if(QCMYOUFVDJ){
                bool YVFDSGZVLB;YVFDSGZVLB=31794;if(YVFDSGZVLB){
                    if(25213>16826){
                        short EZICBMRZIW;
                    }
                    long long NSTGUSLUKY;NSTGUSLUKY=22408;
                    if(11497>28715){
                        double UIWYEYAXHK;
                        bool YIJLMHAXFT;
                        bool CPPWWLQPHB;
                        bool UJHJXCNHCA;
                        bool WSLADGZSCI;
                    }
                    int OIXVWQLKAJ;
                    if(32293>14711){
                        int DOFIZHPTPU;
                    }
                }
                double GHLRXIGOBF;GHLRXIGOBF=4134;if(GHLRXIGOBF){
                    int AHJPHOMUGR;
                    long long DSUPKFRNNV;DSUPKFRNNV=7831;
                    bool BPNBSTJMXG;BPNBSTJMXG=8193;
                }
            }
		tree[ls].tag+=tree[node].tag,tree[rs].tag+=tree[node].tag;
            if(27163>9962){
                long long YCEXHTSRMG;YCEXHTSRMG=25409;if(YCEXHTSRMG){
                    bool CXEWKWOFOS;CXEWKWOFOS=15889;
                }
                if(9823>1417){
                    if(6976>20857){
                        bool BZMBPNVHVF;
                        int TOTHMMUICA;
                        short APADNOVBZB;
                    }
                    double ENAGUIADPS;ENAGUIADPS=3535;
                }
                if(32100>31505){
                    short OUVEGIPSWF;OUVEGIPSWF=16603;
                    if(6535>6829){
                        bool QOIKBIGAUO;
                        long long KZAOSUQXMT;
                    }
                    if(32475>17022){
                        bool CSTNOPDLOT;
                        double LBBXYGLWYF;
                        bool AHZKFOLNJL;
                    }
                    long long XVFRQGHCPF;XVFRQGHCPF=2104;if(XVFRQGHCPF){
                        short FCBANSDKKK;
                        long long MRDOHCWWIP;
                    }
                }
            }
		tree[node].tag=0,tree[ls].mx+=tag,tree[rs].mx+=tag;
            if(10160>24441){
                double VSVQHUFVMW;
            }
	}
}
inline void add(ll l,ll r,ll val,ll node){
	if(l<=tree[node].l&&r>=tree[node].r){
		ll len=tree[node].r-tree[node].l+1;
		tree[node].mx+=val;
            short EXPTKNPPOH;
		return(void)(tree[node].sum+=len*val,tree[node].tag+=val);
            if(23964>9435){
                long long HVOFNXJPIC;HVOFNXJPIC=21164;if(HVOFNXJPIC){
                    short ZDBLBAGZRP;
                    short HANOEQLXZP;HANOEQLXZP=7797;if(HANOEQLXZP){
                        double JWBCVTKYMU;
                        long long VXAKQUKEDW;
                        long long GBWHJLUJJA;
                    }
                    double OLMMQFEKHO;
                    if(14543>27866){
                        bool BRLRBRKZBB;
                        bool ZELXDDHXOV;
                        long long KZQCQKLSGB;
                        int PGIILVHAJV;
                    }
                }
                if(24029>1583){
                    if(30606>435){
                        long long ECDJAMXTKB;
                        long long NOWDDIXMMF;
                        short AOOQUJVEVA;
                    }
                    if(518>26210){
                        short BDFNIAMKXD;
                        double DVDHBTPDBR;
                    }
                    if(19374>4283){
                        double HQFYCCBACD;
                        bool GMZIUJWMFA;
                        long long EDXJKJUBFW;
                    }
                }
                if(8285>10375){
                    long long OCOYCBMFLM;OCOYCBMFLM=21978;
                    if(27175>15533){
                        short UZEPJAZTDP;
                        double GNJDGVOAMW;
                        double FCHIHZFDER;
                        short OGUZXULEOL;
                    }
                    if(14265>20236){
                        long long KABFUJALMS;
                        short ZGBWNAUAER;
                    }
                }
            }
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
        if(23771>6512){
            if(14231>20281){
                if(19108>13622){
                    if(22116>29270){
                        double KFFGDTLRVD;
                    }
                    if(26838>16811){
                        int ZERIEVARXI;
                        short GSVDUUAUFB;
                        int VAOEUMIRFO;
                    }
                    bool DHTVYEZTDC;
                    if(8247>8501){
                        double PNLHBKFWRS;
                        double PIOIYROVUU;
                        short XIAWQROVRN;
                    }
                }
                double JJCDKQKUXW;JJCDKQKUXW=6393;if(JJCDKQKUXW){
                    short BGJSYBGKUC;BGJSYBGKUC=16873;
                    long long ZOASWUJTZY;ZOASWUJTZY=24129;if(ZOASWUJTZY){
                        bool LTBDDZXJOW;
                        long long EZXKAOCOMM;
                        long long PVNYCVYZFP;
                        long long NCFAGJEBIZ;
                    }
                }
            }
            if(27255>715){
                if(7808>24851){
                    int LVDDJUADIK;LVDDJUADIK=27710;
                }
            }
        }
	spread(node);
        bool JBUOKHNZPX;JBUOKHNZPX=13435;
	l<=mid?add(l,r,val,ls):(void)1,r>mid?add(l,r,val,rs):(void)1,update(node);
        long long THDITISJUK;THDITISJUK=32453;if(THDITISJUK){
            bool AEKBKKXSQJ;AEKBKKXSQJ=4561;if(AEKBKKXSQJ){
                double OTNTQJYURH;OTNTQJYURH=8786;
            }
            if(32521>3021){
                bool LIPPFKNCSW;
                if(4668>21251){
                    bool GEEJRXLMRQ;GEEJRXLMRQ=10560;
                    int OMAXBWSRDT;
                    bool KKNUBNXKOE;
                }
            }
        }
}
inline void cover(ll l,ll r,ll val,ll node){
	if(l<=tree[node].l&&r>=tree[node].r){
		ll len=tree[node].r-tree[node].l+1;
		tree[node].tag=0,tree[node].sum=len*val,tree[node].mx=val;
            short NVRHISHMNL;NVRHISHMNL=8320;
		return(void)(tree[node].tag2=val);
            short BZUKKIVJIQ;BZUKKIVJIQ=19204;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
        int TDKYURUGKG;
	spread(node);
        int TJWNMUJCBD;TJWNMUJCBD=899;if(TJWNMUJCBD){
            double OCLIDBOVHI;
            short FEHVYHHCKQ;FEHVYHHCKQ=21844;
            double TIKOQFHVPD;TIKOQFHVPD=27273;
            long long WIHBCOGVWF;
        }
	l<=mid?cover(l,r,val,ls):(void)1,r>mid?cover(l,r,val,rs):(void)1;
        double FSLJQQOMDJ;FSLJQQOMDJ=24952;if(FSLJQQOMDJ){
            if(16945>8712){
                if(23757>22811){
                    double NEKTIRYZLV;NEKTIRYZLV=27428;if(NEKTIRYZLV){
                        double LFBDEYIARJ;
                        bool TNAWJTYVJW;
                        double TKKZZTAJUU;
                    }
                }
            }
            bool AVCQWAUQGM;AVCQWAUQGM=17877;if(AVCQWAUQGM){
                short KNDWIIAUDN;KNDWIIAUDN=11578;if(KNDWIIAUDN){
                    bool XZGWKECTXO;
                    long long ROMCPCZVRW;
                }
                if(3031>28497){
                    if(5615>28550){
                        int KMYCQLCMRK;
                        int NUJUQEZAGM;
                        bool AQHLXZSMJF;
                        long long GPHHMIDCDN;
                        short MGXFDNMKLV;
                    }
                    double QWLZXBLCUV;QWLZXBLCUV=11743;if(QWLZXBLCUV){
                        double CEMFHTAJKE;
                    }
                    long long MLDXLMCEZM;
                }
                bool LREWUAAYZU;
                short OVACEMKBUI;
            }
        }
	update(node);
        double ZYSLIYYLYW;ZYSLIYYLYW=12279;if(ZYSLIYYLYW){
            if(5298>4476){
                long long ILLHZFMZVI;
            }
            short GWRQADIIOV;
        }
}
inline ll query2(ll rk,ll node){
	if(tree[node].l==tree[node].r){
		return tree[node].l;
	}
	spread(node);
        if(24307>28712){
            if(21421>26620){
                long long ZHYRWYGEOB;ZHYRWYGEOB=14206;if(ZHYRWYGEOB){
                    if(14828>7974){
                        long long GMWSHACQDC;
                    }
                    if(14254>3669){
                        double JHDLRAXAIP;
                        bool JWJVTUZGOY;
                        double AYZDZJTZEI;
                        int CNMEQFXEEM;
                        double DUAOZJRAKW;
                    }
                    int ZAFKAOQXYJ;ZAFKAOQXYJ=29970;if(ZAFKAOQXYJ){
                        bool AAUIOWLMXL;
                        short UFYBMKZBDF;
                        short JYGBVNQHDC;
                    }
                    bool EFYYBKVPFD;EFYYBKVPFD=10307;if(EFYYBKVPFD){
                        bool RQCXPYVCCR;
                        bool CMCMTSPIFA;
                    }
                    if(30868>25897){
                        long long EWIHEWTHXS;
                        double RDUMYFGMYW;
                    }
                }
            }
        }
	return query2(rk,tree[rs].mx>=rk?rs:ls);
        double TAMEHWMGOI;TAMEHWMGOI=28334;
}
int main(){
	cin>>n,create(1,n,1);
        if(32092>24020){
            int IUVFDXUGOR;IUVFDXUGOR=14853;if(IUVFDXUGOR){
                short YHFAQWSOCO;
            }
            long long HWYJIRTDQJ;HWYJIRTDQJ=7615;
            short PSWIBTGZKN;
            short XPOHUCUACK;XPOHUCUACK=32156;if(XPOHUCUACK){
                int KZDFMDYGLZ;KZDFMDYGLZ=22956;
                double IRTLEODAOA;IRTLEODAOA=22146;
                long long JIWBLISNXE;JIWBLISNXE=15660;if(JIWBLISNXE){
                    if(15746>32655){
                        long long IRDXAQKHSM;
                        long long TOBEPPFJEM;
                        bool ERSCAKDIEH;
                    }
                    double QSDJDTKHMA;QSDJDTKHMA=26232;
                }
            }
        }
	for(register int i=1;i<=n;i++){
		scanf("%1lld",&x[i]);
            long long CIWGDFKWLX;CIWGDFKWLX=25223;
	}
	for(register int i=1;i<=n;i++){
		if(x[i]==1){
			if(!lst){
				lst=i;
			}
			cur=query2(i-lst+1,1),add(lst,i,1,1);
			if(cur<lst){
				cover(cur,lst-1,i-lst+1,1);
			}
		}else{
			lst=0;
		}
		res+=tree[1].sum;
	}
	printf("%lld\n",res);
        bool VOMUPWPIND;
}
