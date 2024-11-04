










using namespace std;
































class BN {
private:
    bt *ba;
    int bc;                                 

    int rbc;                                

    void GetMemory(int value=2);
    void FreeMemory();
    int Norm();                             


public:
    BN reduction_barrett_precomputation()const;
private:
    bt qCompute(bt,int,const BN&)const;
    bool lessorequal(const BN&,const int&)const;

    BN subequalshift(BN&,int)const;		

    BN mulMontgomery(const BN& bn, const BN& mod, bt m1) const;         

    BN transformationMontgomery(const BN & mod, bt m1) const;           

    BN karatsuba_add(const BN & bn, int id1, int id2, int id3, int id9) const;      

    BN add_appr(const BN & bn, int mul_bt);       

    BN karatsubaRecursive(const BN & bn, int start, int len) const;
public:
    BN();
    BN(ull basecount,const int &value);         

    BN(ull x);
    BN(const BN&);
    BN(const BN&, int start, int count=-1);
    BN(const string &,const int & base = 0);	

    BN   mulbt(const int&)const;		

    BN   divbt(const int&)const;		

    BN   modbt(const int&)const;		

    BN   mulbase(const bt&)const;
    BN   mulbaseappr(const bt&);
    BN   divbase(const bt&)const;
    BN   divbaseappr(const bt&);
    BN   modbase(const bt&)const;
    BN   modbaseappr(const bt&);
    BN   sub(const BN&)const;		

    BN & operator = (const BN&);
    BN   operator + (const BN&)const;
    BN & operator ++();
    BN   operator - (const BN&)const;	

    BN & operator --();
    BN   operator * (const BN&)const;
    BN   fast_mul (const BN&)const;	

    BN   karatsuba (const BN&)const;
    BN   karatsuba_old (const BN&)const;
    BN   operator / (const BN&)const;
    BN   operator % (const BN&)const;
    BN   operator >>(const int&)const;
    BN   operator <<(const int&)const;
    bool operator < (const BN&)const;
    bool operator <=(const BN&)const;
    bool operator > (const BN&)const;
    bool operator >=(const BN&)const;
    bool operator ==(const BN&)const;
    bool operator !=(const BN&)const;
    bt   operator [](const int)const;
    int basecount()const;
    int bitcount()const;


    BN reduction_montgomery (const BN& mod, bt m1, BN T ) const;
    BN reduction_barrett    (const BN&,const BN&	) const;
    BN reduction_special    (const BN&                  ) const;
    BN Pow(ull)const;
    BN PowMod(ull,BN)const;
    BN PowMod(BN,BN)const;
    BN PowModBarrett(BN, BN)const;
    BN expRightToLeft(BN, BN)const;
    BN expLeftToRight(BN, BN)const;
    vector <BN> expLeftToRightK_aryPrecomputation(BN)const;
    BN expLeftToRightK_ary(BN, BN, vector <BN>)const;
    vector <BN> expLeftToRightK_aryVarPrecomputation(BN, int K)const;
    BN expLeftToRightK_aryVar(BN, BN, vector <BN>, int K)const;
    vector <BN> expLeftToRightK_aryModifPrecomputation(BN)const;
    BN expLeftToRightK_aryMod(BN, BN, vector <BN> )const;
    vector <BN> expSlidingWindowPrecomputation(BN, int)const;
    BN expSlidingWindow(BN,BN, vector <BN>, int k)const;
    BN expMontgomery(BN exponent, BN mod) const;

    

    vector <BN> expBest_SlidePrecomp(BN mod) const;
    BN expBest_Slide(BN exponent, BN mod, vector <BN> g) const;

    BN Sqrt()const;
    BN Qrt()const;
    int countzeroright()const;
    bool bitI(unsigned int i)const;
    operator ull()const;
    bool is0()const;
    bool isEven()const;
    void Print(bool newstr=true)const;
    void PrintHex(bool newstr=true)const;
    void PrintDec(bool newstr=true)const;
    ~BN();
};










void BN::GetMemory(int value)
{
    ba=new bt [bc];
    for(int i=rbc;i<bc;i++)
        ba[i]=0;
    switch(value) {
        case 0:
            for(int i=0;i<rbc;i++)
                ba[i]=0;
            rbc=1;
            break;
        case 1:
            for(int i=0;i<rbc;i++)
                ba[i]=~((bt)0);
            break;
        case -1:
            for(int i=0;i<rbc;i++)
                ba[i]=rand()%bsize;
            Norm();
            break;
	case 2:
            break;
        default:
            throw "Unknow type (BN::BN)";
    }
}

void BN::FreeMemory()
{
	delete []ba;
}

int BN::Norm()
{
	for(rbc=bc-1;rbc>0&&ba[rbc]==0;rbc--);
	rbc++;
	return rbc;
}

BN::BN()
{
    rbc = 1;
    bc = 2;
    GetMemory(2);
}

BN::BN(ull basecount,const int &value)
{
	if(basecount<=0)
		throw "Base count <= 0";
	rbc=basecount;
	bc=rbc+1;
	GetMemory(value);
}

BN::BN(ull x)
{
	rbc=(sizeof(ull)+bz-1)/bz;		

	bc=rbc+1;
	GetMemory(2);
	for(int i=0;i<rbc;i++,x>>=bz8)
		ba[i]=(bt)x;
	Norm();
}

BN::BN(const BN& bn)
{
	if(this==&bn)
		throw "constructor copy: Tak ne Byvaet!!! Constructor copii ISTCHO ne sosdannogo classa!!";
	rbc=bn.rbc;
	bc=rbc+1;
	GetMemory(2);
	for(int i=0;i<rbc;i++)
		ba[i]=bn.ba[i];
}

BN::BN(const BN& bn, int start, int count) {
    if(this == &bn)
        throw "constructor copy with param: Tak ne Byvaet!!! Constructor copii ISTCHO ne sosdannogo classa!!";
    if(count == -1)
        count = bn.rbc;
    if(count <= 0)
        throw "constructor copy with param: count byte is not positive";
    if(start < 0)
        throw "constructor copy with param: start < 0";


    rbc = count;
    bc = rbc + 1;
    GetMemory(2);
    for(int i = 0; i < count && i + start < bn.rbc; i++)
        ba[i] = bn.ba[i + start];

    int bbstart = max(0, bn.rbc - start);
    for(int i = bbstart; i < bc; i++)
        ba[i] = 0;
    Norm();
}

BN::BN(const string &str,const int &status)
{
	if(status==1)
	{
		BN bn(1,0);
		BN bn10(10);
		for(unsigned int i=0;i<str.size();i++)
		{
			if(str[i]<'0'||str[i]>'9')
				continue;
			BN bnc(str[i]-'0');
			bn=bn*bn10+bnc;
		}
		rbc=bn.rbc;
		bc=rbc+1;
		GetMemory(2);
		for(int i=0;i<rbc;i++)
			ba[i]=bn.ba[i];

		return;
	}

	int length = str.size();
	rbc=(length+bz*2-1)/(bz*2);
	bc=rbc+1;
	GetMemory(0);
	bt z;
	for(int i=0;i<length;i++)
	{
		if(str[i]>='A'&&str[i]<='F')
		{
			int x=(length-i-1)/(bz*2);
			ba[x]<<=4;
			z=str[i]-'A'+10;
			ba[x]|=z;
		}
		if(str[i]>='a'&&str[i]<='f')
		{
			int x=(length-i-1)/(bz*2);
			ba[x]<<=4;
			z=str[i]-'a'+10;
			ba[x]|=z;
		}
		if(str[i]>='0'&&str[i]<='9')
		{
			int x=(length-i-1)/(bz*2);
			ba[x]<<=4;
			z=str[i]-'0';
			ba[x]|=z;
		}
	}
	Norm();
}

BN & BN::operator = (const BN&bn)
{
	if(this==&bn)
		return *this;
	if(bc<bn.rbc)
	{
		FreeMemory();
		rbc=bn.rbc;
		bc=rbc+1;
		GetMemory(2);
	}
	else
	{
		for(int i=bn.rbc;i<rbc;i++)
			ba[i]=0;
		rbc=bn.rbc;
	}
	for(int i=0;i<rbc;i++)
		ba[i]=bn.ba[i];
	return *this;
}

BN BN::operator + (const BN&bn)const {
    int result_len = max(rbc, bn.rbc);
    BN result(result_len + 1, 2);

    bt2 res = 0;
    int pos = 0;
    int m = min(rbc, bn.rbc);
    for(; pos < m; pos++) {
        res += (bt2) ba[pos] + (bt2) bn.ba[pos];
        result.ba[pos] = res;
        res >>= bz8;
    }

    for(; pos < rbc; pos++) {
        res += (bt2) ba[pos];
        result.ba[pos] = res;
        res >>= bz8;
    }

    for(; pos < bn.rbc; pos++) {
        res += (bt2) bn.ba[pos];
        result.ba[pos] = res;
        res >>= bz8;
    }

    result.ba[pos] = res;
    result.Norm();
    return result;
}

BN & BN::operator ++()
{
	bool overflag=0;
	bt2 res;
	int pos=1;
	if(rbc==bc&&bsize-(bt2)ba[rbc-1]==1)
	{
		BN result(rbc+1,2);
		if((bt)(ba[0]+1)<ba[0])
			overflag=1;
		ba[0]++;
		while(overflag&&pos<rbc)
		{
			res=(bt2)ba[pos]+(bt2)overflag;
			if(res>=bsize)
			{overflag=true;	result.ba[pos]=res;}
			else
			{overflag=false;result.ba[pos]=res;pos++;break;}
			pos++;
		}
		while(pos<rbc)
		{
			result.ba[pos]=ba[pos];
			pos++;
		}
		result.ba[pos]=overflag;
		result.rbc=rbc+1;
		return *this=result;
	}
	if((bt)(ba[0]+1)<ba[0])
		overflag=1;
	ba[0]++;
	while(overflag&&pos<rbc)
	{
		res=(bt2)ba[pos]+(bt2)overflag;
		if(res>=bsize)
		{overflag=true;	ba[pos]=res;}
		else
		{overflag=false;ba[pos]=res;pos++;break;}
		pos++;
	}
	ba[pos]+=overflag;
	Norm();
	return *this;
}

BN BN::operator - (const BN& bn)const
{
	if(*this >= bn)
		return this -> sub(bn);
	else
		return bn.sub(*this);
}



BN & BN::operator --()
{
	bool flag=0;
	int pos=1;
	if(rbc==1&&ba[0]==0)
		throw "It is minimal value... Decrementing not accept :)";
	if(ba[0]==0)
		flag=1;
	ba[0]--;
	while(flag)
	{
		flag=(ba[pos]==0);
		ba[pos]--;
		pos++;
	}
	Norm();
	return *this;
}

BN BN::mulbt(const int& t)const
{
	if(t<0)
		return divbt(-t);
	if(t==0)
		return *this;
	BN res(rbc + t,2);
	for(int i=0;i<rbc;i++)
		res.ba[i+t]=ba[i];
	for(int i=0;i<t;i++)
		res.ba[i]=0;
	res.Norm();
	return res;
}

BN BN::divbt(const int& t)const
{
	if(t<0)
		return mulbt(-t);
	if(t==0)
		return *this;
	if(t>=rbc)
		return (BN) 0;
	BN res(rbc-t,2);
	for(int i=0;i<rbc-t;i++)
		res.ba[i]=ba[i+t];
	res.Norm();
	return res;
}

BN BN::modbt(const int& t)const
{
	if(t<0)
		throw "Error in modbt: t<0";
	if(t==0)
		return BN(1,0);
	if(t>=rbc)
		return *this;
	BN res(t,2);
	for(int i=0;i<t;i++)
		res.ba[i]=ba[i];
	res.Norm();
	return res;
}

BN BN::mulbase(const bt &multiplier)const
{
	BN result(rbc+1,2);
	bt2 curr=0;
	for(int i=0;i<rbc;i++,curr>>=bz8)
		result.ba[i]=curr+=ba[i]*multiplier;
	result.ba[rbc]=curr;
	result.Norm();
	return result;
}

BN BN::mulbaseappr(const bt &multiplier)
{
	if(rbc+1>bc)
	{
		bt* ba_new=new bt [rbc+2];
		bt2 curr=0;
		for(int i=0;i<rbc;i++,curr>>=bz8)
			ba_new[i]=curr+=ba[i]*multiplier;
		ba_new[rbc]=curr;
		delete []ba;
		ba=ba_new;
	}
	else
	{
		bt2 curr=0;
		for(int i=0;i<rbc;i++,curr>>=bz8)
			ba[i]=curr+=ba[i]*multiplier;
		ba[rbc]=curr;
	}
	Norm();
	return *this;
}

BN BN::operator * (const BN&bn)const {
    BN result(rbc+bn.rbc+1,0);
    if(bn.rbc==1)
        return mulbase(bn.ba[0]);
    for(int i=0;i<bn.rbc;i++) {
        bt2 curr=0;
        bt2 x=bn.ba[i];
        for(int j=0;j<rbc;j++,curr>>=bz8)
            result.ba[i+j]=curr+=(bt2)ba[j]*x+result.ba[i+j];
        result.ba[i+rbc]=curr;
    }
    result.Norm();
    return result;
}

BN BN::fast_mul (const BN & bn) const {
    int n = rbc;
    int m = bn.rbc;

    BN result(n+m+1,2);

    bt4 t = 0;
    for(int s = 0; s < m+n; s++) {

        int end_index = min(n, s);
        for(int i = max(s-m+1, 0); i <= end_index; i++) {
                t += (bt2) ba[i] * bn.ba[s-i];
        }

        result.ba[s] = t;
        t = t >> bz8;
    }

    result.ba[m+n] = t;
    result.Norm();
    return result;
}

BN BN::karatsuba_add(const BN & bn, int id1, int id2, int id3, int id9) const {
    const BN & bn1 = *this;
    const BN & bn2 = bn;

    if(id2 == -1)
        id2 = bn1.rbc - id1;

    if(id9 == -1)
        id9 = bn2.rbc - id3;

    int result_len = max(id2, id9);
    BN result(result_len + 1, 2);

    int id5 = min(id2, bn1.rbc - id1);
    int id8 = min(id9, bn2.rbc - id3);
    int m_min = min(id5, id8);


    bt2 res = 0;
    int pos = 0;
    for(; pos < m_min; pos++) {
        res = res + (bt2) bn1.ba[id1 + pos] + (bt2) bn2.ba[id3 + pos];
        result.ba[pos] = res;
        res >>= bz8;
    }
    for(; pos < id5; pos++) {
        res = res + (bt2) bn1.ba[id1 + pos];
        result.ba[pos] = res;
        res >>= bz8;
    }

    for(; pos < id8;pos++) {
        res = res + (bt2) bn2.ba[id3 + pos];
        result.ba[pos] = res;
        res >>= bz8;
    }

    result.ba[pos] = res;
    for(pos++; pos <= result_len; pos++)
        result.ba[pos] = 0;

    result.Norm();
    return result;
}

BN BN::add_appr (const BN&bn, int mul_bt) {
    int result_len = max(rbc, bn.rbc + mul_bt);
    if(result_len < bc) {
        bt2 res = 0;
        int pos = 0;
        int m = min(rbc-mul_bt, bn.rbc);
        for(; pos < m; pos++) {
            res += (bt2) ba[pos + mul_bt] + (bt2) bn.ba[pos];
            ba[pos + mul_bt] = res;
            res >>= bz8;
        }

        for(; pos < bn.rbc; pos++) {
            res += (bt2) bn.ba[pos];
            ba[pos + mul_bt] = res;
            res >>= bz8;
        }

        while(res) {
            res += (bt2) ba[pos + mul_bt];
            ba[pos + mul_bt] = res;
            res >>= bz8;
            pos ++;
        }

        Norm();
        return *this;
    }
    *this = (*this) + bn.mulbt(mul_bt);
    return *this;
}


BN BN::karatsubaRecursive(const BN & bn, int start, int len) const {
    int n = len / 2;
    if (len / 2 < caracuba_const) {
        BN U(*this, start, len);
        BN V(bn, start, len);
        return U.fast_mul(V);
    }

    const BN & U = *this;
    const BN & V = bn;

    BN A = U.karatsubaRecursive(V, start + n, n);   

    BN B = U.karatsubaRecursive(V, start, n);       

    BN C = U.karatsuba_add(U, start, n, start + n, n).
            karatsuba
            (V.karatsuba_add(V, start, n, start + n, n));   




    BN res(1,0);
    delete [] res.ba;
    res.rbc = A.rbc + 2*n;
    res.bc = A.bc + 2*n;
    res.ba = new bt [res.bc];
    for(int i = 0; i < B.rbc; i++)
        res.ba[i] = B.ba[i];                        

    for(int i = B.rbc; i < 2*n; i++)
        res.ba[i] = 0;
    for(int i = 2*n; i < A.rbc + 2*n; i++)
        res.ba[i] = A.ba[i - 2*n];
    for(int i = res.rbc; i < res.bc; i++)
        res.ba[i] = 0;

    return res.add_appr((C-A-B), n);
}

BN BN::karatsuba(const BN& bn)const {
    int x = rbc;
    int y = bn.rbc;
    int len = max(x,y);
    if(min(x,y) < caracuba_const)
        return this ->fast_mul(bn);

    const BN & U = *this;
    const BN & V = bn;
    return U.karatsubaRecursive(V, 0, len);
}

BN BN::karatsuba_old(const BN& bn)const {
    int x = rbc;
    int y = bn.rbc;

    int M = max(x,y);
    int n = (M+1)/2;
    if(min(x,y) < caracuba_const)
        return (*this).fast_mul (bn);

    const BN & U = *this;
    const BN & V = bn;

    BN u0(U, 0, n);
    BN v0(V, 0, n);

    BN u1(U, n, n);
    BN v1(V, n, n);

    BN A = u1.karatsuba_old(v1);
    BN B = u0.karatsuba_old(v0);
    BN C = (u0 + u1).karatsuba_old(v0+v1);
    return A.mulbt(2*n) + (C-A-B).mulbt(n) + B;
}
BN BN::divbase(const bt &diviser)const
{
	if(diviser==0)
		throw "Div by 0";
	BN result(rbc,2);
	bt2 curr=0;
	for(int i=rbc-1;i>=0;--i)
	{
		curr<<=bz8;
		curr+=(bt2)ba[i];
		result.ba[i]=curr/(bt2)diviser;
		curr%=(bt2)diviser;
	}
	result.Norm();
	return result;
}

BN BN::divbaseappr(const bt &diviser)
{
	if(diviser==0)
		throw "Div by 0";
	bt2 curr=0;
	for(int i=rbc-1;i>=0;--i)
	{
		curr<<=bz8;
		curr+=(bt2)ba[i];
		ba[i]=curr/(bt2)diviser;
		curr%=(bt2)diviser;
	}
	Norm();
	return *this;
}

BN BN::modbase(const bt &diviser)const
{
	if(diviser==0)
		throw "Div by 0";
	BN result(1,2);
	bt2 curr=0;
	for(int i=rbc-1;i>=0;--i)
	{
		curr<<=bz8;
		curr+=(bt2)ba[i];
		curr%=(bt2)diviser;
	}
	result.ba[0]=curr;
	

	return result;
}

BN BN::modbaseappr(const bt &diviser)
{
	if(diviser==0)
		throw "Div by 0";
	bt2 curr=0;
	for(int i=rbc-1;i>=0;--i)
	{
		curr<<=bz8;
		curr+=(bt2)ba[i];
		ba[i]=curr/(bt2)diviser;
		curr%=(bt2)diviser;
	}
	ba[0]=curr;
	for(int i=1;i<rbc;i++)
		ba[i]=0;
	rbc=1;
	return *this;
}

BN BN::sub(const BN& bn)const
{
	BN result(rbc,2);

	bool flag=0;
	bt2s res;
	int pos=0;
	for(;pos< bn.rbc;pos++)
	{
		res=(bt2s)ba[pos] - (bt2s)bn.ba[pos] - (bt2s)flag;
		result.ba[pos]=res;
		if(res<0)
			flag=true;
		else
			flag=false;
	}
	for(;flag&&pos<rbc;pos++)
	{
		result.ba[pos]=ba[pos] - flag;
		if(result.ba[pos] > ba[pos])
			flag=true;
		else
			flag=false;
	}
	for(;pos < rbc; pos++)
		result.ba[pos] = ba[pos];
	result.Norm();
	return result;
}

bool BN::lessorequal(const BN&bn,const int &shift)const        

{
	if(rbc>bn.rbc-shift)
		return false;
	if(rbc<bn.rbc-shift)
		return true;
	for(int i=rbc-1;i>=0;i--)
	{
		if(ba[i]>bn.ba[i+shift])
			return false;
		if(ba[i]<bn.ba[i+shift])
			return true;
	}
	return true;
}

bt BN::qCompute(bt q,int shift,const BN&bn)const
{
	if(q==0)		

		return q;
	

	BN temp=bn.mulbase(q);
	if(temp.lessorequal(*this,shift))	

		return q;

	q--;			

	if(q==0)		

		return 0;

	if((temp-bn).lessorequal(*this,shift))	

		return q;
	else
		return q-1;
}

BN BN::operator / (const BN&bn)const
{
	if(bn.is0())
		throw "Div by 0";
	if(bn.rbc==1)
		return this -> divbase(bn.ba[0]);
	if(*this<bn)
		return (BN) 0;

	bt d=bsize/(bt2)(bn.ba[bn.rbc-1]+1);

	BN id6 = this -> mulbase(d);
	BN delitel = bn.mulbase(d);

	


	int n=delitel.rbc;
	int m=id6.rbc-delitel.rbc;

        BN result(m+1,0);

	BN temp(n+m,2);
	for(int i=n+m;i>=n;i--)
	{
		bt q;
		if(i>id6.rbc)
			q=0;
		else if(i==id6.rbc)
			q=min((bt2)id6.ba[i-1]/delitel.ba[n-1],bsize-1);
		else 

			q=min((bt2)(id6.ba[i]*bsize+id6.ba[i-1])/delitel.ba[n-1],bsize-1);

		q=id6.qCompute(q,i-n,delitel);

        	bt2 x=0;
		for(int j=0;j<i-n;j++)
			temp.ba[j]=0;
		for(int j=i;j<n+m;j++)
			temp.ba[j]=0;
		for(int j=0;j<n;j++,x>>=bz8)
			temp.ba[j+i-n]=x+=q*delitel.ba[j];
		temp.ba[i]=x;
		temp.Norm();
		

		id6=id6-temp;
		result.ba[i-n]=q;
		

	}
	

	result.Norm();
	return result;
}

BN BN::operator % (const BN& bn)const
{
	if(bn.is0())
		throw "Div by 0";
	if(bn.rbc==1)
		return this->modbase(bn.ba[0]);
	if(*this < bn)
		return *this;

	bt d=bsize / (bt2)(bn.ba[bn.rbc-1]+1);

        BN id6 = this -> mulbase(d);
        BN delitel = bn.mulbase(d);

	int n=delitel.rbc;
	int m=id6.rbc-delitel.rbc;

	BN temp(n+m,2);
	for(int i=n+m;i>=n;i--)
	{
		bt q;
		if(i>id6.rbc)
			q=0;
		else if(i==id6.rbc)
			q=min((bt2)id6.ba[i-1]/delitel.ba[n-1],bsize-1);
		else 

			q=min((bt2)(id6.ba[i]*bsize+id6.ba[i-1])/delitel.ba[n-1],bsize-1);

		q=id6.qCompute(q,i-n,delitel);

		bt2 x=0;
		for(int j=0;j<i-n;j++)
			temp.ba[j]=0;
		for(int j=i;j<n+m;j++)
			temp.ba[j]=0;
		for(int j=0;j<n;j++,x>>=bz8)
			temp.ba[j+i-n]=x+=q*delitel.ba[j];
		temp.ba[i]=x;
		temp.Norm();
		id6=id6-temp;
	}
	return id6.divbase(d);
}

BN BN::operator >> (const int&shift)const {
    if(shift == 0)
        return *this;
    if(shift < 0)
        return (*this) >> (-shift);


	int baseshift=shift/(bz8);
	int realshift=shift-baseshift*bz8;
	if(baseshift>=rbc)
	{
		BN bn0(1,0);
		return BN(1,0);
	}

	BN result(rbc-baseshift,2);
	for(int i=0;i<rbc-baseshift;i++)
		result.ba[i]=ba[i+baseshift];

	bt x=0;
	bt oldx=0;
	for(int i=rbc-baseshift;i>=0;i--)
	{
		x=result.ba[i] << (bz8-realshift);
		result.ba[i]=(result.ba[i]>>realshift)|oldx;
		oldx=x;
	}

        


	
	result.Norm();
	return result;
}

BN BN::operator << (const int&shift)const {
    if(shift == 0)
        return *this;
    if(shift < 0)
        return (*this) >> (-shift);

    int baseshift=shift/(bz8);
	int realshift=shift-baseshift*bz8;
	if(realshift == 0)
		return mulbt(baseshift);
	BN result(rbc+baseshift+1,2);
	for(int i=0;i<baseshift;i++)
		result.ba[i]=0;
	for(int i=0;i<rbc;i++)
		result.ba[i+baseshift]=ba[i];

	bt x=0;
	bt oldx=0;
	for(int i=0;i<rbc+baseshift;i++)
	{
		x=result.ba[i] >> (bz8-realshift);
		result.ba[i]=(result.ba[i]<<realshift)|oldx;
		oldx=x;
	}
	result.ba[rbc+baseshift]=oldx;
	result.Norm();
	return result;
}

bool BN::operator < (const BN&bn)const
{
	if(rbc>bn.rbc)
		return false;
	if(rbc<bn.rbc)
		return true;
	for(int i=rbc-1;i>=0;i--)
	{
		if(ba[i]>bn.ba[i])
			return false;
		if(ba[i]<bn.ba[i])
			return true;
	}
	return false;
}

bool BN::operator <= (const BN&bn)const
{
	if(rbc>bn.rbc)
		return false;
	if(rbc<bn.rbc)
		return true;
	for(int i=rbc-1;i>=0;i--)
	{
		if(ba[i]>bn.ba[i])
			return false;
		if(ba[i]<bn.ba[i])
			return true;
	}
	return true;
}

bool BN::operator > (const BN&bn)const
{
	if(rbc>bn.rbc)
		return true;
	if(rbc<bn.rbc)
		return false;
	for(int i=rbc-1;i>=0;i--)
	{
		if(ba[i]>bn.ba[i])
			return true;
		if(ba[i]<bn.ba[i])
			return false;
	}
	return false;
}

bool BN::operator >= (const BN&bn)const
{
	if(rbc>bn.rbc)
		return true;
	if(rbc<bn.rbc)
		return false;
	for(int i=rbc-1;i>=0;i--)
	{
		if(ba[i]>bn.ba[i])
			return true;
		if(ba[i]<bn.ba[i])
			return false;
	}
	return true;
}

bool BN::operator ==(const BN&bn)const
{
	if (rbc!=bn.rbc)
		return false;
	for(int i=0;i<rbc;i++)
		if(ba[i]!=bn.ba[i])
			return false;
	return true;
}

bool BN::operator !=(const BN&bn)const
{
	if (rbc!=bn.rbc)
		return true;
	for(int i=0;i<rbc;i++)
		if(ba[i]!=bn.ba[i])
			return true;
	return false;
}

bt BN::operator [](const int index)const
{
	if(index>=rbc || index<0)
	{
		int buf_len=1000;
		char *buffer=new char [buf_len];
		snprintf(buffer,buf_len,"Error in index.\nIndex: %d\nAvailable range of index: 0 - %d\n",index,rbc-1);
		throw buffer;
	}
	return ba[index];
}

int BN::basecount()const
{
	return rbc;
}

int BN::bitcount()const
{
	bt mask=0x1;
	int x=1;
	int result=0;
	while(mask)
	{
		if(mask&ba[rbc-1])
			result=x;
		mask<<=1;
		x++;
	}
	return (rbc-1)*bz8+result;
}

BN BN::transformationMontgomery(const BN & mod, bt m1) const {
    int k = mod.rbc;
    BN y(rbc + k, 2);                     

    y = *this;
    for(int i = 0; i < k; i++) {
        bt u = y.ba[i] * m1;
        y.add_appr(mod.mulbase(u), i);
    }
    y = y.divbt(k);
    if(y >= mod)
        return y - mod;
    return y;
}


BN BN::reduction_barrett_precomputation()const {
    return ( (BN)1 ).mulbt(2*rbc) / *this;
}

BN BN::reduction_barrett(const BN& mod, const BN& mu)const {

    int k = mod.rbc;                      

    if(k*2 < this->rbc) {
        return (*this)%mod;
    }

    BN x = *this;
    BN q1 = x.divbt(k-1);
    BN q2 = q1*mu;
    BN q3 = q2.divbt(k+1);
    BN r1 = this->modbt(k+1);
    BN r2 = (q3 * mod).modbt(k+1);
    BN r;
    if(r1 >= r2)
            r = r1 - r2;
	else
            r = ((BN) 1).mulbt(k+1) + r1 - r2;
    while(r >= mod)
        r = r - mod;
    return r;
}



BN BN::reduction_special(const BN &mod)const {
    int t = mod.rbc;

    

    BN Bt(t+1,0);
    Bt.ba[t] = (bt) 1;
    Bt.rbc = t+1;

    BN c = Bt - mod;

    BN q = this -> divbt(t);
    BN r = *this - q.mulbt(t);

    BN r_sum = r;

    while(!q.is0()) {
        BN Q = (q*c).divbt(t);
        BN R = q*c - Q.mulbt(t);
        r_sum = r_sum + R;
        q = Q;
        r = R;
    }
    while(r_sum>=mod)
        r_sum=r_sum-mod;
    return r_sum;
}

BN BN::Pow(ull power)const
{
	BN Res(1);
	if(power==(ll)0)
		return Res;
	BN t=(*this);
	while(power)
	{
		if(power&(ll)1)
			Res=Res*t;
		t=t*t;
		power>>=(ll)1;
	}
	return Res;
}

BN BN::PowMod(ull power, BN mod)const
{
	BN Res(1);
	if(power==(ll)0)
		return Res;
	BN t=(*this)%mod;
	while(power)
	{
		if(power&(ll)1)
			Res=(Res*t)%mod;
		t=(t*t)%mod;
		power>>=(ll)1;
	}
	return Res%mod;
}

BN BN::PowMod(BN power, BN mod)const {

    if(power.is0())
        return (BN) 1;

    BN Res(1);
    BN t = (*this) % mod;

    int len = power.bitcount();
    bt mask = 1;
    bt *curr = power.ba;
    for(int i = 0; i < len; i++) {
        if(!mask) {
            mask = 1;
            ++curr;
        }
        if((*curr) & mask)
            Res = Res * t % mod;

        t=t.Qrt() % mod;
        mask <<= 1;
    }
    return Res % mod;
}

BN BN::PowModBarrett(BN power, BN mod)const {

    if(power.is0())
        return (BN) 1;

    BN mu = mod.reduction_barrett_precomputation();
    BN Res(1);
    BN t = (*this) % mod;

    int len = power.bitcount();
    bt mask = 1;
    bt *curr = power.ba;
    for(int i = 0; i < len; i++) {
        if(!mask) {
            mask = 1;
            ++curr;
        }
        if( (*curr) & mask)
            Res = (Res*t).reduction_barrett(mod, mu);

        t = t.Qrt().reduction_barrett(mod, mu);
        mask <<= 1;
    }
    return Res.reduction_barrett(mod, mu);
}


BN BN::expRightToLeft(BN exponent, BN mod)const {

    if(exponent.is0())
        return (BN) 1;

    BN A = 1;
    BN S = (*this) % mod;

    int id7 = exponent.bitcount();
    bt id4 = (bt)  1;
    bt *exponent_current_base = exponent.ba;

    for(int i=0;i<id7;i++) {
        if(!id4) {
            id4 = (bt) 1;
            ++exponent_current_base;
        }

        if( (*exponent_current_base) & id4) {
            A = A * S % mod;
        }


        S = S.Qrt() % mod;
        id4 <<= 1;
    }
    return A % mod;
}

BN BN::expLeftToRight(BN exponent, BN mod) const {
    if(exponent.is0())
        return (BN) 1;

    BN A = 1;
    BN g = *this % mod;

    int id7 = exponent.bitcount();
    bt id4 = (bt) 1;
    int id0 = (id7 - 1 ) % bz8;
    id4 <<= id0;
    bt * exponent_current_base = exponent.ba + (exponent.rbc - 1);
    for(int i = 0; i < id7; i++) {
        if(!id4) {
            id4 = (bt) 1 << (bz8 - 1);
            --exponent_current_base;
            

        }

        if( (*exponent_current_base) & id4) {
            A = A.Qrt() % mod * g % mod;
        }
        else {
            A = A.Qrt() % mod;
        }

        id4 >>= 1;
    }
    return A;

}

vector <BN> BN::expLeftToRightK_aryPrecomputation(BN mod) const {
    BN g = *this % mod;
    vector <BN> garr(bsize);
    garr[0] = BN(1);
    for(int i = 1; i < bsize; i++) {
        garr[i] = garr[i-1] * g % mod;
    }
    return garr;
}

BN BN::expLeftToRightK_ary(BN exponent, BN mod, vector <BN> g) const {
    if(exponent.is0())
        return (BN) 1;

    BN A = 1;
    for(int i = exponent.rbc - 1; i >= 0; i--) {
        for(int k = 0; k < (int)bz8; k++)
            A = A.Qrt() % mod;
        A = A * g[exponent.ba[i]] % mod;
    }
    return A;
}

vector <BN> BN::expLeftToRightK_aryVarPrecomputation(BN mod, int K) const {
    int Kmax = (1 << K);
    BN g = *this % mod;
    vector <BN> garr(Kmax);
    garr[0] = BN(1);
    for(int i = 1; i < Kmax; i++) {
        garr[i] = garr[i-1] * g % mod;
    }
    return garr;
}

BN BN::expLeftToRightK_aryVar(BN exponent, BN mod, vector <BN> g, int K) const {
    if(exponent.is0())
        return (BN) 1;

    BN A = 1;

    int x;
    for(int i = exponent.rbc * bz8 - 1; i >= K; i -= K) {
        x = i;
        for(int k = 0; k < K; k++)
            A = A.Qrt() % mod;
        int curr = 0;
        for(int k = 0; k < K; k++) {
            curr <<= 1;
            curr |= exponent.bitI(i-k);
        }
        A = A * g[curr] % mod;
    }

    int curr = 0;
    for(int i = x - K; i >= 0; i--) {
        A = A.Qrt();
        curr <<= 1;
        curr |= exponent.bitI(i);
    }
    A = A * g[curr] % mod;

    return A;
}

vector <BN> BN::expLeftToRightK_aryModifPrecomputation(BN mod) const {
    BN g = *this % mod;

    vector <BN> garr(bsize);

    garr[0] = (BN) 1;
    garr[1] = g;
    garr[2] = g.Qrt() % mod;
    for(int i = 1; i < bsize/2; i++)
        garr[2*i+1] = garr[2*i-1] * garr[2] % mod;
    return garr;
}

BN BN::expLeftToRightK_aryMod(BN exponent, BN mod, vector <BN> g) const {
    if(exponent.is0())
        return (BN) 1;

    BN A = (BN) 1;
    for(int i = exponent.rbc - 1; i >= 0; i--) {
        bt ei = exponent.ba[i];

        int hi = 0;
        if(ei != 0) {
            while(! (ei & 1)) {
                ei >>= 1;
                hi++;
            }
        }

        for(int k = 0; k < (int)bz8 - hi; k++)
            A = A.Qrt() % mod;
        A = A * g[ei] % mod;
        for(int k = 0; k < hi; k++)
            A = A.Qrt() % mod;
    }
    return A;

}

vector <BN> BN::expSlidingWindowPrecomputation(BN mod, int k) const {
    int k_pow = 2 << (k-1);
    vector <BN> garr (k_pow);
    BN g = *this % mod;
    garr[0] = (BN) 1;
    garr[1] = g;
    garr[2] = g.Qrt() % mod;
    for(int i = 1; i < k_pow/2; i++)
        garr[2*i+1] = garr[2*i-1] * garr[2] % mod;
    return garr;
}

BN BN::expSlidingWindow(BN exponent, BN mod, vector <BN> g, int k) const {
    BN A = (BN) 1;
    int i = exponent.bitcount() - 1;
    while (i >= 0) {
        if(exponent.bitI(i) == 0) {
            A = A.Qrt() % mod;
            i--;
            continue;
        }
        int l = max(i - k + 1, 0);
        while(exponent.bitI(l) == 0)
            l++;

        int gx = 0;
        for(int j = i; j >= l; j--)
            gx = (gx << 1) | exponent.bitI(j);
        for(int j = 0; j < i - l + 1; j++)
            A = A.Qrt() % mod;
        A = A * g[gx] % mod;
        i = l - 1;
    }
    return A;
}

vector <BN> BN::expBest_SlidePrecomp(BN mod) const {
    vector <BN> garr (bsize);
    BN mu = mod.reduction_barrett_precomputation();
    BN g = this -> reduction_barrett(mod, mu);
    garr[0] = (BN) 1;
    garr[1] = g;
    garr[2] = g.Qrt().reduction_barrett(mod,mu);
    for(int i = 1; i < bsize/2; i++)
        garr[2*i+1] = (garr[2*i-1] * garr[2]).reduction_barrett(mod,mu);
    return garr;

}



BN BN::expBest_Slide(BN exponent, BN mod, vector <BN> g) const {
    BN A = (BN) 1;
    BN mu = mod.reduction_barrett_precomputation();
    int i = exponent.bitcount() - 1;
    int k = bz8;
    while (i >= 0) {
        if(exponent.bitI(i) == 0) {
            A = A.Qrt().reduction_barrett(mod, mu);
            i--;
            continue;
        }
        int l = max(i - k + 1, 0);
        while(exponent.bitI(l) == 0)
            l++;

        int gx = 0;
        for(int j = i; j >= l; j--)
            gx = (gx << 1) | exponent.bitI(j);
        for(int j = 0; j < i - l + 1; j++)
            A = A.Qrt().reduction_barrett(mod, mu);
        A = (A * (g[gx])).reduction_barrett(mod, mu);
        i = l - 1;
    }
    return A;

}


bt2 inverse(bt2 a, bt2 mod) {

    bt2 start_mod = mod;
    a = a % mod;
    if(a == 0)
        return 0;
    bt2s x0;
    bt2s x1 = 0;
    bt2s x2 = 1;
    while(mod % a) {
        bt2 q = mod/a;
        x0 = x1;
        x1 = x2;

        x2 = x0 - x1 * (bt2s) q;
        bt2 new_mod = a;
        a = mod % a;
        mod = new_mod;
    }

    if(a !=  1)
                return 0;
        if(x2 < 0)
                return start_mod + x2;
        return x2;
}



BN BN::Sqrt()const
{
    if(is0())
        return BN(1,0);
    BN x((this->rbc+1)/2,0);
    x.ba[(this->rbc+1)/2]=1;
    x.rbc=(this->rbc+1)/2+1;
    BN x0;
    do {
        x0=x;
        x=( (*this)/x+x )>>1;
    }
    while(x0>x);
    return x0;
}

BN BN::Qrt()const
{
	BN res(2*rbc+1,0);
	for(int i=0;i<rbc;i++)
	{
		bt4 cuv=res.ba[2*i]+((bt2)ba[i])*ba[i];
		res.ba[2*i]=cuv;
		for(int j=i+1;j<rbc;j++)
		{
			cuv=(bt4)res.ba[i+j]+((bt4)((bt2)ba[i]*ba[j])<<1)+(cuv>>bz8);
			res.ba[i+j]=cuv;
		}
		

		cuv=(res.ba[i+rbc+1]<<bz8)+res.ba[i+rbc]+(cuv>>bz8);
		res.ba[i+rbc]=cuv;
		res.ba[i+rbc+1]=(cuv>>bz8);
	}
	res.Norm();
	return res;
}

int BN::countzeroright()const
{
	if(ba[0] & (bt)1)
		return 0;
	int count=0;
	while(!ba[count])
		count++;
	bt mask=1;
	int d=0;
	while(!(mask&ba[count]))
	{
		mask<<=1;
		d++;
	}
	return count*bz8+d;
}

bool BN::bitI(unsigned int index)const {
    if(index < 0)
        throw "unknow index";
    if(index >= bz8 * rbc)
        return false;

    bt mask = (bt) 1;
    mask <<= (index % bz8);
    if(ba[index/bz8] & mask)
        return true;
    return false;
}

BN::operator ull ()const {
    ull result=0;
    

    for(
            int i = (unsigned)rbc-1 > sizeof(ull)/bz ? sizeof(ull)/bz-1:rbc-1;
            i>=0;
            i--) {
        result<<=bz8;
        result+=ba[i];
    }
    return result;
}

BN::~BN() {
    FreeMemory();
}

void BN::PrintHex(bool newstr)const
{
	for(int i=rbc-1;i>=0;i--)
		printf("%0*x",(int)bz*2,ba[i]);
	if(newstr)
		printf("\n");
}

void BN::PrintDec(bool newstr)const
{
	BN bn=*this;
	int slen=rbc*bz*4+1;		

	char *s=new char [slen];
	int count=0;
	if(bn.is0())
		s[count++]='0';
	while(!bn.is0())
	{
		s[count++]=(bn.modbase(10)).ba[0]+'0';
		bn.divbaseappr(10);
	}
	for(int i=count-1;i>=0;i--)
		printf("%c",s[i]);
	if(newstr)
		printf("\n");
	delete []s;
}

bool BN::is0()const
{
	if(rbc>1 || ba[0])
		return false;
	return true;
}

bool BN::isEven()const
{
    if(ba[0] & (bt)1)
        return false;
    return true;
}






namespace std {
    template <>
    class hash<pair<long long,long long>> {
    public:
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 32);
        }
    };
}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;
    vector<pair<bool, int>> v(n);
    vector<pair<int, size_t>> sells;
    for (size_t i = 0; i < n; ++i) {
        string s;
        int x;
        cin >> s >> x;
        v[i] = {s == "win", x};
        if (!v[i].first)
            sells.push_back({x, i});
    }
    sort(sells.begin(), sells.end());
    reverse(sells.begin(), sells.end());

    vector<bool> result(3001, false);
    vector<bool> used(n, false);
    for (auto i : sells) {
        if (used[i.second])
            continue;
        for (size_t j = i.second - 1; j < n; --j) {
            if (used[j])
                break;
            if (v[j].second == i.first) {
                result[i.first] = true;
                for (size_t k = j; k <= i.second; ++k)
                    used[k] = true;
                break;
            }
        }
    }


    string S = "";
    for (size_t i = 0; i < 2500; i += 4) {
        int value = 0;
        for (size_t j = 0; j < 4; ++j)
            value = (value << 1) | result[i + 3 - j];
        if (value > 9)
            S = char('a' + value - 10) + S;
        else
            S = char('0'+ value) + S;
    }
    BN bn(S, 0);
    bn.PrintDec();
    return 0;
}
