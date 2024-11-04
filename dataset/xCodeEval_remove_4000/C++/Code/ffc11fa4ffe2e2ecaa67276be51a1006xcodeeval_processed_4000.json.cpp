






























using namespace std;

































































































































template< class T, class X > inline bool checkbit(T a, X pos) { T t=1;return ((a&(t<<pos))>0);  }
template< class T, class X > inline T      setbit(T a, X pos) { T t=1;return (a|(t<<pos));      }
template< class T, class X > inline T    resetbit(T a, X pos) { T t=1;return (a&(~(t<<pos)));   }
template< class T, class X > inline T   togglebit(T a, X pos) { T t=1;return (a^(t<<pos));      }







































































































int ar[MX];

char ss[MX];


struct Manacher {
    char text[MX*2];
    int     p[MX*2];
    int lcp,id2;
    int tot;
    vector< pair<int,int> > pal;

    void init() {
        pal.clear();
        lcp=0;
        tot=0;
        memset(p,0,sizeof p);
    }

    void generate(char *s) {
        init();
        int len = 0 , i=0 ;
        text[len++] = '^';
        while(s[i]) text[len++]=  '
        text[len++]=  '
        text[len++]=  '$';
        int c = 0; 

        int r = 0; 

        for(i=1; i<len-1; i++) {
            int j = (c<<1)-i; 

            p[i] = (r>i)?min(r-i,p[j]):0;
            while(text[i+1+p[i]]==text[i-1-p[i]]) p[i]++;
            if(i+p[i]>r) c=i,r=i+p[i];
        }
        for(i=1; i<len-1; i++) {






            if(p[i]>lcp) {
                lcp     = p[i];
                id2 = i;
            }













        }

        for(int i=2;i<len-1;i+=2){


            ar[i/2] = p[i];
        }


    }

    void BUG(char *s) {
        for(int i=0; i<pal.size(); i++) {
            for(int j=pal[i].X; j<pal[i].Y; j++) {
                cout << s[j];
            }
            cout << endl;
        }
    }

}man;

char ms[MX];

int n;

int mil[MX];

void z_function(int *z,char *s) {
    int len = strlen(s);
    rep(i,0,len) z[i] = 0;
    for (int i = 1, l = 0, r = 0; i < len; ++i) {
        if (i <= r)  z[i] = min (r - i + 1, z[i - l]);
        while ( i + z[i] < len && s[z[i]] == s[i + z[i]] )   ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    z[0] = len;
    int id = 1;
    rep(i,n+1,len-1) {
        mil[id++] = z[i];
    }
}

int  zz[MX];

struct Seg_Point_update_range_Max {

    int tree[2*MX];
    int n;

    void init(int *ar) {
        rev(i,n,1)   tree[i-1+n] = ar[i];
        rev(i,n-1,1) tree[i]     = Max(tree[(i<<1)],tree[(i<<1)|1]);
    }

    void update(int idx,int val) {
        idx--;
        for(tree[idx+=n]=val; idx>1; idx>>=1) {
            tree[idx>>1] = Max(tree[idx],tree[idx^1]);
        }
    }


    int query(int x,int y) {
        int ret = 0;
        x--;
        for(x+=n,y+=n; x<y; x>>=1,y>>=1) {
            if(x&1) ret=Max(ret,tree[x]),x++;
            if(y&1) --y,ret=Max(ret,tree[y]);
        }
        return ret;
    }

} smax;


int main() {
    SS(ss);
    man.init();
    man.generate(ss);
    n=strlen(ss);
    rep(i,1,n) {
        if(ar[i]==n) {
            cout << 1 << endl;
            cout << 1 << " " << n << endl;
            return 0;
        }
    }

    int id=n-1;
    rep(i,0,n-1) {
        ms[i] = ss[id--];
    }
    ms[n] = '

    rep(i,0,n-1) {
        ms[n+1+i] = ss[i];
    }

    ms[n+1+n] = 0;

    z_function(zz,ms);

    smax.n = n;
    smax.init(mil);

    int ret = -1;
    int majpos  = -1;
    int id0 = -1;
    int majlen  = 0;

    rep(i,2,n-1) {
        int low  = i;
        int high = i+(ar[i]/2);
        if(high==n) high--;
        int pos = -1;
        while( low<=high ) {
            int mid = (low+high)>>1;
            int lt = (i-(mid-i));
            if(lt-1 < 1) {
                high = mid-1;
                continue;
            }
            

            int v = smax.query(1,lt-1);
            if(v>0) pos = mid, low = mid+1;
            else   high = mid-1;
        }


        if(pos==-1) continue; 

        

        int lpos = i-(pos-i);
        low = 1;
        high = Min( n-pos , lpos);
        int mxlen = 0;


        while(low<=high) {
            int mid = (low+high)>>1;
            if(lpos-mid<1) {
                high = mid-1;
                continue;
            }
            int mx = smax.query(1,lpos-mid);
            if(mx>=mid) mxlen = mid , low=mid+1;
            else   high =  mid-1;
        }


        if(mxlen) {
            int tot = (pos-i)*2+1 + mxlen*2;


            if(ret<tot) {
                ret = tot;
                majpos = i-(pos-i);
                majlen = (pos-i)*2+1;
                id0 = mxlen;
            }
        }


    }
    int flag = 0;
    int id1 = 0;
    int spos = -1;
    rep(i,1,n) {
        int e=i+(ar[i]/2);
        if(e==n && ar[i]>=ret) {
            if(id1<ar[i]) {
                id1=ar[i];
                spos = i;
            }
        }
    }

    int midmx = 0;

    rep(i,1,n)
    {
        if(ar[i]>=ret)
        {
            ret = ar[i];
            midmx = i;
        }
    }

    if(midmx)
    {


        cout << 1 << endl;
        cout << (midmx-(ret/2)) << " " << ret << endl;
        return 0;
    }


    if(spos!=-1) {
        cout << 1 << endl;
        cout << (spos-(n-spos)) << " " << id1 << endl;
        return 0;
    }








    cout << 3 << endl;
    rep(i,1,n) {
        if(mil[i]>=id0 ) {
            cout << i << " " << id0 << endl;
            break;
        }
    }
    cout << majpos << " " << majlen << endl;
    cout << (n-id0+1) << " " << id0 << endl;


    return 0;
}