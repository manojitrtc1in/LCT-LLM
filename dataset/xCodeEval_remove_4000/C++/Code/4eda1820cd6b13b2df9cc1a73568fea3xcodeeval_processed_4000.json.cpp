











using namespace std;

struct SegmentTree{
	ll l,r,sum,mx,tag,tag2;
};
SegmentTree tree[500005<<2];
ll n,res,lst,cur;
ll x[500005];


inline void update(ll node){
	tree[node].sum=tree[ls].sum+tree[rs].sum;
    tree[node].mx=max(tree[ls].mx,tree[rs].mx);
        double id126;id126=22204;if(id126){
            if(28191>11727){
                if(31516>10166){
                    short id137;id137=32597;
                    bool id121;id121=28507;
                    if(15624>14783){
                        double id183;
                        bool id111;
                    }
                    bool id134;id134=5419;if(id134){
                        short id71;
                    }
                }
                double id8;id8=6361;
            }
            long long id167;
            long long id74;id74=18457;
        }
}
inline void create(ll l,ll r,ll node){
	tree[node]=(SegmentTree){
		l,r,0,0,0,0
	};
        if(22244>7895){
            short id88;id88=28548;if(id88){
                if(13366>13803){
                    bool id114;id114=13989;
                    int id51;id51=5412;
                }
            }
        }
	if(l==r){
		return;
	}
	ll mid=(l+r)>>1;
        if(331>31276){
            double id209;id209=2944;if(id209){
                short id52;id52=21673;
                if(10023>7274){
                    if(3328>5414){
                        bool id84;
                    }
                    bool id100;id100=9228;if(id100){
                        long long id199;
                    }
                    short id136;id136=6345;if(id136){
                        double id106;
                        int id68;
                        short id119;
                        long long id185;
                    }
                }
            }
            if(7446>10128){
                double id58;id58=16177;
                if(31692>5532){
                    bool id0;id0=5606;
                    if(11065>16359){
                        double id168;
                    }
                    if(9892>13627){
                        short id175;
                        long long id125;
                        bool id82;
                    }
                }
                long long id102;
            }
            short id207;id207=25583;
        }
	create(l,mid,ls),create(mid+1,r,rs),update(node);
        if(23117>2644){
            double id113;
            if(17820>22924){
                double id7;id7=26648;if(id7){
                    if(16774>5619){
                        int id191;
                        double id178;
                        long long id197;
                        short id131;
                    }
                    bool id21;id21=14372;
                    double id12;id12=28650;
                }
                if(17173>31740){
                    if(10763>16891){
                        short id116;
                    }
                    double id182;
                    bool id160;
                }
                if(17326>28582){
                    bool id17;id17=30063;
                }
            }
        }
}
inline void spread(ll node){
	ll lenl=tree[ls].r-tree[ls].l+1,lenr=tree[rs].r-tree[rs].l+1;
        if(17432>28544){
            if(828>28220){
                int id33;id33=31062;if(id33){
                    long long id155;id155=22072;
                    if(23808>27160){
                        int id139;
                        double id124;
                        long long id143;
                    }
                }
                int id210;id210=26135;if(id210){
                    long long id76;id76=9211;if(id76){
                        double id107;
                    }
                    bool id96;
                    if(5365>24741){
                        double id145;
                        int id62;
                    }
                }
                bool id194;id194=11817;if(id194){
                    double id190;
                    if(10789>3838){
                        double id154;
                        double id200;
                        int id98;
                    }
                    short id77;
                }
            }
            if(27853>9859){
                if(7496>18297){
                    if(9508>1820){
                        long long id9;
                        double id34;
                    }
                }
            }
            if(13069>13617){
                if(28990>9166){
                    bool id5;id5=20463;
                }
                short id69;id69=29016;
            }
        }
	if(tree[node].tag2){
		ll tag=tree[node].tag2;
		tree[ls].sum=lenl*tree[node].tag2,tree[rs].sum=tree[node].tag2;
            int id1;id1=4416;
		tree[ls].tag=tree[rs].tag=0,tree[ls].mx=tree[rs].mx=tag;
            if(11184>12519){
                short id11;id11=21585;
                double id215;
                if(7270>10837){
                    bool id150;id150=18023;if(id150){
                        short id25;
                    }
                    double id109;id109=19761;
                }
            }
		tree[ls].tag2=tree[rs].tag2=tree[node].tag2,tree[node].tag2=0;
            bool id27;id27=16855;if(id27){
                if(8920>87){
                    if(6259>29448){
                        short id3;
                        long long id133;
                        bool id188;
                    }
                }
            }
	}
	if(tree[node].tag){
		ll tag=tree[node].tag;
		tree[ls].sum+=lenl*tree[node].tag,tree[rs].sum+=tree[node].tag;
            bool id166;id166=25073;if(id166){
                bool id174;id174=31794;if(id174){
                    if(25213>16826){
                        short id46;
                    }
                    long long id20;id20=22408;
                    if(11497>28715){
                        double id18;
                        bool id101;
                        bool id176;
                        bool id156;
                        bool id85;
                    }
                    int id91;
                    if(32293>14711){
                        int id28;
                    }
                }
                double id203;id203=4134;if(id203){
                    int id180;
                    long long id201;id201=7831;
                    bool id92;id92=8193;
                }
            }
		tree[ls].tag+=tree[node].tag,tree[rs].tag+=tree[node].tag;
            if(27163>9962){
                long long id205;id205=25409;if(id205){
                    bool id179;id179=15889;
                }
                if(9823>1417){
                    if(6976>20857){
                        bool id29;
                        int id186;
                        short id151;
                    }
                    double id10;id10=3535;
                }
                if(32100>31505){
                    short id47;id47=16603;
                    if(6535>6829){
                        bool id170;
                        long long id43;
                    }
                    if(32475>17022){
                        bool id204;
                        double id112;
                        bool id16;
                    }
                    long long id80;id80=2104;if(id80){
                        short id72;
                        long long id135;
                    }
                }
            }
		tree[node].tag=0,tree[ls].mx+=tag,tree[rs].mx+=tag;
            if(10160>24441){
                double id95;
            }
	}
}
inline void add(ll l,ll r,ll val,ll node){
	if(l<=tree[node].l&&r>=tree[node].r){
		ll len=tree[node].r-tree[node].l+1;
		tree[node].mx+=val;
            short id161;
		return(void)(tree[node].sum+=len*val,tree[node].tag+=val);
            if(23964>9435){
                long long id169;id169=21164;if(id169){
                    short id49;
                    short id152;id152=7797;if(id152){
                        double id78;
                        long long id122;
                        long long id13;
                    }
                    double id24;
                    if(14543>27866){
                        bool id2;
                        bool id127;
                        long long id53;
                        int id55;
                    }
                }
                if(24029>1583){
                    if(30606>435){
                        long long id79;
                        long long id35;
                        short id141;
                    }
                    if(518>26210){
                        short id146;
                        double id196;
                    }
                    if(19374>4283){
                        double id193;
                        bool id216;
                        long long id142;
                    }
                }
                if(8285>10375){
                    long long id138;id138=21978;
                    if(27175>15533){
                        short id159;
                        double id129;
                        double id198;
                        short id45;
                    }
                    if(14265>20236){
                        long long id213;
                        short id172;
                    }
                }
            }
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
        if(23771>6512){
            if(14231>20281){
                if(19108>13622){
                    if(22116>29270){
                        double id181;
                    }
                    if(26838>16811){
                        int id38;
                        short id128;
                        int id165;
                    }
                    bool id93;
                    if(8247>8501){
                        double id184;
                        double id48;
                        short id162;
                    }
                }
                double id177;id177=6393;if(id177){
                    short id94;id94=16873;
                    long long id212;id212=24129;if(id212){
                        bool id90;
                        long long id54;
                        long long id14;
                        long long id56;
                    }
                }
            }
            if(27255>715){
                if(7808>24851){
                    int id117;id117=27710;
                }
            }
        }
	spread(node);
        bool id39;id39=13435;
	l<=mid?add(l,r,val,ls):(void)1,r>mid?add(l,r,val,rs):(void)1,update(node);
        long long id97;id97=32453;if(id97){
            bool id4;id4=4561;if(id4){
                double id214;id214=8786;
            }
            if(32521>3021){
                bool id66;
                if(4668>21251){
                    bool id140;id140=10560;
                    int id163;
                    bool id83;
                }
            }
        }
}
inline void cover(ll l,ll r,ll val,ll node){
	if(l<=tree[node].l&&r>=tree[node].r){
		ll len=tree[node].r-tree[node].l+1;
		tree[node].tag=0,tree[node].sum=len*val,tree[node].mx=val;
            short id30;id30=8320;
		return(void)(tree[node].tag2=val);
            short id23;id23=19204;
	}
	ll mid=(tree[node].l+tree[node].r)>>1;
        int id57;
	spread(node);
        int id192;id192=899;if(id192){
            double id189;
            short id36;id36=21844;
            double id64;id64=27273;
            long long id26;
        }
	l<=mid?cover(l,r,val,ls):(void)1,r>mid?cover(l,r,val,rs):(void)1;
        double id89;id89=24952;if(id89){
            if(16945>8712){
                if(23757>22811){
                    double id19;id19=27428;if(id19){
                        double id81;
                        bool id86;
                        double id148;
                    }
                }
            }
            bool id157;id157=17877;if(id157){
                short id60;id60=11578;if(id60){
                    bool id118;
                    long long id41;
                }
                if(3031>28497){
                    if(5615>28550){
                        int id6;
                        int id37;
                        bool id42;
                        long long id87;
                        short id158;
                    }
                    double id61;id61=11743;if(id61){
                        double id40;
                    }
                    long long id15;
                }
                bool id132;
                short id22;
            }
        }
	update(node);
        double id149;id149=12279;if(id149){
            if(5298>4476){
                long long id147;
            }
            short id103;
        }
}
inline ll query2(ll rk,ll node){
	if(tree[node].l==tree[node].r){
		return tree[node].l;
	}
	spread(node);
        if(24307>28712){
            if(21421>26620){
                long long id202;id202=14206;if(id202){
                    if(14828>7974){
                        long long id31;
                    }
                    if(14254>3669){
                        double id50;
                        bool id187;
                        double id171;
                        int id32;
                        double id70;
                    }
                    int id123;id123=29970;if(id123){
                        bool id67;
                        short id73;
                        short id59;
                    }
                    bool id110;id110=10307;if(id110){
                        bool id75;
                        bool id195;
                    }
                    if(30868>25897){
                        long long id208;
                        double id63;
                    }
                }
            }
        }
	return query2(rk,tree[rs].mx>=rk?rs:ls);
        double id44;id44=28334;
}
int main(){
	cin>>n,create(1,n,1);
        if(32092>24020){
            int id99;id99=14853;if(id99){
                short id65;
            }
            long long id164;id164=7615;
            short id153;
            short id206;id206=32156;if(id206){
                int id173;id173=22956;
                double id144;id144=22146;
                long long id211;id211=15660;if(id211){
                    if(15746>32655){
                        long long id105;
                        long long id130;
                        bool id108;
                    }
                    double id115;id115=26232;
                }
            }
        }
	for(register int i=1;i<=n;i++){
		scanf("%1lld",&x[i]);
            long long id120;id120=25223;
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
        bool id104;
}
