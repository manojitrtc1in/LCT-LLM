import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class Main {
    public static void main(String[] args) throws Exception {
        new Main().run();}

    int n;
    int v[][];
    int lisan(int[][] arr,int idx){
        for(int i=0;i<n;++i){
            v[i][0] = arr[i][idx];
            v[i][1] = i;
        }
        Arrays.sort(v, new Comparator<int[]>() {
            @Override
            public int compare(int[] x, int[] y) {
                return x[0]-y[0];
            }
        });
        int tot = -1;
        for (int i = 0; i < n; ++i) {
            if(i==0||v[i][0]!=v[i-1][0]) tot++;
            arr[v[i][1]][idx] = tot;
        }
        

        return tot+1;
    }


    long inv(long a, long MOD) {
        

        return a==1?1:(long )(MOD-MOD/a)*inv(MOD%a, MOD)%MOD;
    }


    long C(long n,long m, long MOD) {
        if(m+m>n)m=n-m;
        long up=1,down=1;
        for(long i=0;i<m;i++)
        {
            up=up*(n-i)%MOD;
            down=down*(i+1)%MOD;
        }
        return up*inv(down, MOD)%MOD;
    }

    long[][] mult(long a[][],long b[][], long mod){
        int l1 = a.length;
        int l2 = b.length;
        int l3 = b[0].length;
        long r[][] = new long[l1][l3];
        for(int i=0;i<l1;++i){
            for(int j=0;j<l2;++j){
                for(int k=0;k<l3;++k){
                    r[i][k] = (r[i][k] + a[i][j] * b[j][k])%mod;
                }
            }
        }
        return r;
    }

    long[][] ones(int len){
        long r[][] = new long[len][len];
        for(int i=0;i<len;++i){
            r[i][i] = 1L;
        }
        return r;
    }

    long[][] quick(long a[][], long times,long mod){
        int len = a.length;
        long ans[][] = ones(len);

        while(times>0){
            if((times&1)==1) {
                ans = mult(ans, a, mod);
            }
            a = mult(a, a, mod);
            times >>= 1;
        }

        return ans;
    }


    int[] h,ne,to,q,dis,cur;
    long []val;
    int ct = 0;
    long INF = 233333333333333L;

    void graph(int n,int m){
        h = new int[n];
        Arrays.fill(h,-1);
        ne = new int[2 * m];
        to = new int[2 * m];
        val = new long[2 * m];
        q = new int[n];
        ct = 0;
        dis = new int[n];
    }

    void link(int u,int v,long w){
        to[ct] = v;
        ne[ct] = h[u];
        val[ct] = w;
        h[u] = ct++;

        to[ct] = u;
        ne[ct] = h[v];
        val[ct] = 0;
        h[v] = ct++;

    }

    boolean bfs(int st, int ed){
        int e = 0;
        int s = 0;
        Arrays.fill(dis,-1);
        dis[st] = 0;
        q[e++] = st;
        while(s<e){
            int x = q[s++];
            for(int i=h[x];i!=-1;i=ne[i]){
                int v = to[i];
                if(dis[v]==-1 && val[i]>0L){
                    dis[v] = dis[x] + 1;
                    q[e++] = v;
                }
            }
        }
        return dis[ed]!=-1;
    }

    long dfs(int x,int ed, long maxflow){
        if(x == ed) return maxflow;
        long ans = 0;

        for(int i= cur[x];i!=-1;i=ne[i]){
            if(ans >= maxflow){
                break;
            }
            int v = to[i];
            if(dis[v]!=dis[x]+1 || val[i]==0L ){
                continue;
            }
            cur[x] = i;
            long f = dfs(v, ed, Math.min(val[i], maxflow-ans));
            val[i] -= f;
            val[i^1] += f;
            ans += f;
        }
        if(ans==0) dis[x] = -1;
        return ans;
    }

    long dinic(int st,int ed){
        long ans = 0;
        while(bfs(st,ed)){
            cur = h.clone();
            long k;
            while((k = dfs(st,ed,INF))>0) ans += k;
        }
        return ans;
    }


    int dx[] = {0,1};
    int dy[] = {1,0};
    int res = 0;
    void dfs(int r,int c,int[][] a,int len,int ii)
    {
        int n = a.length;
        for(int d:new int[]{-1,1}){
            int i = (ii + d + 4) % 4;
            int x = r;
            int y = c;
            int sp = 0;
            while(x+dx[i]<n&&x+dx[i]>=0&&y+dy[i]>=0&&y+dy[i]<n&&a[x+dx[i]][y+dy[i]]!=1&&a[x+dx[i]][y+dy[i]]!=2){
                x += dx[i];
                y += dy[i];
                sp++;
                a[x][y] = 2;
            }

            if(x+dx[i]<n&&x+dx[i]>=0&&y+dy[i]>=0&&y+dy[i]<n&&a[x+dx[i]][y+dy[i]]==2){
                res = Math.max(len+sp,res);
            }else if(sp>0){
                dfs(x, y, a, len + sp, i);
            }

            while(!(x==r&&y==c)){
                a[x][y] = 0;
                x -= dx[i];
                y -= dy[i];
            }
        }


    }
    static long mul(long a, long b, long p)
    {
        long res=0,base=a;
        while(b>0)
        {
            if((b&1L)>0)
                res=(res+base)%p;
            base=(base+base)%p;
            b>>=1;
        }
        return res;
    }

    static long mod_pow(long k,long n,long p){
        long res = 1L;
        long temp = k%p;
        while(n!=0L){
            if((n&1L)==1L){
                res = mul(res,temp,p);
            }
            temp = mul(temp,temp,p);
            n = n>>1L;
        }
        return res%p;
    }


    int manacher(String s){
        StringBuilder sb  =new StringBuilder();
        sb.append('
        for(int i=0;i<s.length();++i){
            sb.append(s.charAt(i));
            sb.append('
        }
        char cs[] = sb.toString().toCharArray();
        int mx = 0; int id = 0;
        int p[] = new int[cs.length]; 

        p[0] = 1;
        for(int i=1;i<cs.length;++i){
            if(mx>i) p[i] = Math.min(p[id*2-i], mx-i);
            else p[i] = 1;
            for(;i+p[i]<cs.length&& i-p[i]>=0 &&cs[i+p[i]]==cs[i-p[i]];p[i]++);
            if(p[i]+i>mx) {
                mx = p[i] + i; id = i;
            }
        }
        int ans = 0;
        for(int i=0;i<cs.length;++i){
            ans = Math.max(ans,p[i]);
        }
        return ans-1;
    }


    boolean next_perm(int[] a){
        int len = a.length;
        for(int i=len-2,j = 0;i>=0;--i){
            if(a[i]<a[i+1]){
                j = len-1;
                for(;a[j]<=a[i];--j);
                int p = a[j];
                a[j] = a[i];
                a[i] = p;
                j = i+1;
                for(int ed = len-1;j<ed;--ed) {
                    p = a[ed];
                    a[ed] = a[j];
                    a[j++] = p;
                }
                return true;
            }
        }
        return false;
    }


    public static String roundS(double result, int scale){
        String fmt = String.format("%%.%df", scale);
        return String.format(fmt, result);
    }

    int zz = 0;
    int mx = 0;

    public static double id2(double num, int n) {
        if(num == 0) {
            return 0;
        }

        final double d = Math.ceil(Math.log10(num < 0 ? -num: num));
        final int power = n - (int) d;

        final double magnitude = Math.pow(10, power);
        final long shifted = Math.round(num*magnitude);
        return shifted/magnitude;
    }

    double dis(double x,double y,double x1,double y1){
        return Math.sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
    }

    int go(int u,int ch[][], int num[],int comp,int dp){
        if(num[u]<comp) return 0;

        int mx = 0;

        for(int i=0;i<26;++i){
            if(ch[u][i]!=0){
                int r = go(ch[u][i],ch,num,comp,dp+1);
                mx += r;
            }
        }
        mx += num[u]/comp;
        return mx;
    }

    int mid = 0;


    void id3(int step ,int x,int y,long st,long arr[][], HashMap<Long,Integer> map[][]){
        long cur = st ^ arr[x][y];
        int v = map[x][y].getOrDefault(cur,0);
        map[x][y].put(cur,v + 1);
        if(mid==step){
           return;
        }
        for(int i=0;i<2;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0&&ny>=0&&nx<n&&ny<m) {
                id3(step + 1, nx, ny, cur , arr,map );
            }
        }
    }

    long result = 0;
    long k  =0;
    void goabove(int step, int x,int y,long st,long arr[][],HashMap<Long,Integer> map[][]){
        if(step==(n+m-mid-2))
        {
            if(map[x][y].containsKey(st^k))
                result += map[x][y].get(st^k);
            return;
        }
        if(x-1>=0)
            goabove(step+1,x-1,y,st^arr[x][y],arr,map);
        if(y-1>=0)
            goabove(step+1, x,y-1,st^arr[x][y],arr,map);
    }

    int m = 0;
    void solve() {

















        n = ni();
        m = ni();
        k = nl();
        mid = (n+m-2)/2;
        long[][] arr = new long[n][m];
        HashMap<Long,Integer>[][] map = new HashMap[n][m];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                arr[i][j]= nl();
                map[i][j] = new HashMap();
            }
        }
        id3(0,0,0,0,arr,map);
        result = 0;
        goabove(0,n-1,m-1,0L,arr,map);
        print(result);

























































































































































































































































































        



































































































































































































































































































































        

        






























































































        






































































    }













    

    void update(long[] t,int i,long v){
        for(;i<t.length;i+=(i&-i)){
            t[i] += v;
        }
    }
    long get(long[] t,int i){
        long s = 0;
        for(;i>0;i-=(i&-i)){
            s += t[i];

        }
        return s;
    }

    int id0(long t[],long v){
        int s=0,p=0;
        for(int i=Integer.numberOfTrailingZeros(Integer.highestOneBit(t.length));i>=0;--i) {
            if(p+(1<<i)< t.length && s + t[p+(1<<i)] < v){
                v -= t[p+(1<<i)];
                p |= 1<<i;
            }
        }
        return p+1;
    }

    static class S{
        int l = 0;
        int r = 0 ;
        long tot = 0;
        long plus = 0;
        long multi = 1;


        public S(int l,int r) {
            this.l = l;
            this.r = r;
        }
    }

    static S a[];
    static long[] o;

    static void init(long[] f){
        o = f;
        int len = o.length;
        a = new S[len*4];
        build(1,0,len-1);
    }

    static void build(int num,int l,int r){
        S cur = new S(l,r);
        if(l==r){
            a[num] = cur;
            a[num].tot = o[l];
            

            return;
        }else{
            int m = (l+r)>>1;
            int le = num<<1;
            int ri = le|1;
            build(le, l,m);
            build(ri, m+1,r);
            a[num] = cur;
            pushup(num,le,ri);
        }
    }

    static long query(int num,int l,int r){
        if(a[num].l>=l&&a[num].r<=r){
            

            return a[num].tot;
        }else{
            int m = (a[num].l+a[num].r)>>1;
            int le = num<<1;
            int ri = le|1;
            

            long res = Long.MIN_VALUE;
            if(l<=m) {
                res = Math.max(res, query(le, l, r));
            }
            if(r>m){
                res = Math.max(res, query(ri, l, r));
            }
            

            return res;
        }
    }

    static void update(int num,int l,long v){
        if(a[num].l == a[num].r){
            a[num].tot  = v;
        }else{
            int m = (a[num].l+a[num].r)>>1;
            int le = num<<1;
            int ri = le|1;
            

            if(l<=m){
                update(le, l, v);
            }
            if(l>m){
                update(ri, l, v);
            }
            pushup(num,le,ri);
        }
    }

    static long p;
    static void update1(int num,int l,int r,long v){
        if(a[num].l>=l && a[num].r<=r){
            a[num].tot += v*(a[num].r-a[num].l+1);
            a[num].tot %= p;
            a[num].plus += v;
            a[num].plus %= p;
        }else{
            int m = (a[num].l+a[num].r)>>1;
            int le = num<<1;
            int ri = le|1;
            pushdown(num, le, ri);
            if(l<=m){
                update1(le, l, r, v);
            }
            if(r>m){
                update1(ri, l, r, v);
            }
            pushup(num,le,ri);
        }
    }

    static void update2(int num,int l,int r,long v){
        if(a[num].l>=l && a[num].r<=r){
            a[num].tot *= v;
            a[num].tot %= p;
            a[num].plus *= v;
            a[num].plus %= p;
            a[num].multi *= v;
            a[num].multi %= p;
        }else{
            int m = (a[num].l+a[num].r)>>1;
            int le = num<<1;
            int ri = le|1;
            pushdown(num, le, ri);
            if(l<=m){
                update2(le, l, r, v);
            }
            if(r>m){
                update2(ri, l, r, v);
            }
            pushup(num,le,ri);
        }
    }

    static void pushup(int num,int le,int ri){
        a[num].tot = Math.max(a[le].tot , a[ri].tot);
    }

    static void pushdown(int num,int le,int ri){
        if(a[num].multi!=1) {
            a[le].tot *= a[num].multi;
            a[le].tot %= p;
            a[ri].tot *= a[num].multi;
            a[ri].tot %= p;
            a[le].multi *= a[num].multi;
            a[ri].multi *= a[num].multi;
            a[le].multi %= p;
            a[ri].multi %= p;
            a[le].plus *= a[num].multi;
            a[ri].plus *= a[num].multi;
            a[le].plus %= p;
            a[ri].plus %= p;
            a[num].multi = 1;
        }
        if(a[num].plus!=0) {
            a[le].tot += (a[le].r-a[le].l+1)*a[num].plus;
            a[ri].tot += (a[ri].r-a[ri].l+1)*a[num].plus;
            a[le].tot %= p;
            a[ri].tot %= p;
            a[le].plus += a[num].plus;
            a[ri].plus += a[num].plus;
            a[le].plus %= p;
            a[ri].plus %= p;
            a[num].plus = 0;
        }
    }

    long gcd(long a,long b){ return b==0?a: gcd(b,a%b);}
    int gcd(int a,int b){ return b==0?a: gcd(b,a%b);}
    InputStream is;PrintWriter out;
    void run() throws Exception {is = System.in;
        

        out = new PrintWriter(System.out);solve();out.flush();}
    private byte[] inbuf = new byte[2];
    public int lenbuf = 0, ptrbuf = 0;
    private int readByte() {
        if (lenbuf == -1) throw new InputMismatchException();
        if (ptrbuf >= lenbuf) {
            ptrbuf = 0;
            try {lenbuf = is.read(inbuf);} catch (IOException e) {throw new InputMismatchException();}
            if (lenbuf <= 0) return -1;
        }
        return inbuf[ptrbuf++];}
    private boolean id1(int c) {return !(c >= 33 && c <= 126);}
    private int skip() {int b;while((b = readByte()) != -1 && id1(b));return b;}
    private double nd() {return Double.parseDouble(ns());}
    private char nc() {return (char) skip();}
    private char ncc() {int b;while((b = readByte()) != -1 && !(b >= 32 && b <= 126));return (char)b;}
    private String ns() {int b = skip();StringBuilder sb = new StringBuilder();
        while (!(id1(b))) { 

            sb.appendCodePoint(b);b = readByte(); }
        return sb.toString();}
    private char[] ns(int n) {char[] buf = new char[n];int b = skip(), p = 0;
        while (p < n && !(id1(b))) { buf[p++] = (char) b;b = readByte(); }
        return n == p ? buf : Arrays.copyOf(buf, p);}
    private String nline() {int b = skip();StringBuilder sb = new StringBuilder();
        while (!id1(b) || b == ' ') { sb.appendCodePoint(b);b = readByte(); }
        return sb.toString();}
    private char[][] nm(int n, int m) {char[][] a = new char[n][];for (int i = 0; i < n; i++) a[i] = ns(m);return a;}
    private int[] na(int n) {int[] a = new int[n];for (int i = 0; i < n; i++) a[i] = ni();return a;}
    private long[] nal(int n) { long[] a = new long[n];for (int i = 0; i < n; i++) a[i] = nl();return a;}
    private int ni() { int num = 0, b; boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')){};
        if (b == '-') { minus = true; b = readByte(); }
        while (true) {
            if (b >= '0' && b <= '9') num = (num << 3) + (num << 1) + (b - '0');
            else return minus ? -num : num;
            b = readByte();}}
    private long nl() { long num = 0; int b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')){};
        if (b == '-') { minus = true; b = readByte(); }
        while (true) {
            if (b >= '0' && b <= '9')  num = num * 10 + (b - '0');
            else return minus ? -num : num;
            b = readByte();}}
    void print(Object obj){out.print(obj);}
    void println(Object obj){out.println(obj);}
    void println(){out.println();}
}