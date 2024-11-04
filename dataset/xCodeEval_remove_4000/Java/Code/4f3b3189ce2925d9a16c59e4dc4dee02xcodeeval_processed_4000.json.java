import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.TreeMap;
import java.util.Stack;
import java.util.Queue;
import java.util.LinkedList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.TreeSet;
public class id6 
{
    public static final int[] id13 = {1053818881, 1051721729, 1045430273, 1012924417, 1007681537, 1004535809, 998244353, 985661441, 976224257, 975175681};
    public static final int[] id5 = {7, 6, 3, 5, 3, 3, 3, 3, 3, 17};





    public static long[] id10(long[] a, long[] b, int P, int g) {
        int m = Math.max(2, Integer.highestOneBit(Math.max(a.length, b.length) - 1) << 2);
        long[] fa = id16(a, m, false, P, g);
        long[] fb = a == b ? fa : id16(b, m, false, P, g);
        for (int i = 0; i < m; i++) {
            fa[i] = fa[i] * fb[i] % P;
        }
        return id16(fa, m, true, P, g);
    }
    
    public static long[] id4(long[] a, long[] b) {
        int USE = 2;
        int m = Math.max(2, Integer.highestOneBit(Math.max(a.length, b.length) - 1) << 2);
        long[][] fs = new long[USE][];
        for (int k = 0; k < USE; k++) {
            int P = id13[k], g = id5[k];
            long[] fa = id16(a, m, false, P, g);
            long[] fb = a == b ? fa : id16(b, m, false, P, g);
            for (int i = 0; i < m; i++) {
                fa[i] = fa[i] * fb[i] % P;
            }
            fs[k] = id16(fa, m, true, P, g);
        }

        int[] mods = Arrays.copyOf(id13, USE);
        long[] gammas = id2(mods);
        int[] buf = new int[USE];
        for (int i = 0; i < fs[0].length; i++) {
            for (int j = 0; j < USE; j++) {
                buf[j] = (int) fs[j][i];
            }
            long[] res = id12(buf, mods, gammas);
            long ret = 0;
            for (int j = res.length - 1; j >= 0; j--) {
                ret = ret * mods[j] + res[j];
            }
            fs[0][i] = ret;
        }
        return fs[0];
    }

    public static long[] id14(long[] a, long[] b) {
        int m = Math.max(2, Integer.highestOneBit(Math.max(a.length, b.length) - 1) << 2);
        int P = id13[0], g = id5[0];
        long[] fa = id16(a, m, false, P, g);
        long[] fb = a == b ? fa : id16(b, m, false, P, g);
        for (int i = 0; i < m; i++) {
            fa[i] = fa[i] * fb[i] % P;
        }
        long[] f = id16(fa, m, true, P, g);
        return f;
    }
    static long[] multiply(long a[],long b[],int mod)
    {
        long v=mod;
        v*=mod;
        long ans[]=new long[a.length+b.length-1];
        for(int i=0;i<a.length;i++)
            for(int j=0;j<b.length;j++)
            {
                ans[i+j]+=a[i]*b[j];
                if(ans[i+j]>=v)
                    ans[i+j]-=v;
            }
        for(int i=0;i<ans.length;i++)
            ans[i]%=mod;
        return ans;
    }
    public static long[] id4(long[] a, long[] b, int USE, int mod) {
        if(a.length+b.length<=200)
            return multiply(a,b,mod);
        int m = Math.max(2, Integer.highestOneBit(Math.max(a.length, b.length) - 1) << 2);
        long[][] fs = new long[USE][];
        for (int k = 0; k < USE; k++) {
            int P = id13[k], g = id5[k];
            long[] fa = id16(a, m, false, P, g);
            long[] fb = a == b ? fa : id16(b, m, false, P, g);
            for (int i = 0; i < m; i++) {
                fa[i] = fa[i] * fb[i] % P;
            }
            fs[k] = id16(fa, m, true, P, g);
        }

        int[] mods = Arrays.copyOf(id13, USE);
        long[] gammas = id2(mods);
        int[] buf = new int[USE];
        for (int i = 0; i < fs[0].length; i++) {
            for (int j = 0; j < USE; j++) {
                buf[j] = (int) fs[j][i];
            }
            long[] res = id12(buf, mods, gammas);
            long ret = 0;
            for (int j = res.length - 1; j >= 0; j--) {
                ret = (ret * mods[j] + res[j]) % mod;
            }
            fs[0][i] = ret;
        }
        return fs[0];
    }

    

    

    private static long[] id16(long[] src, int n, boolean inverse, int P, int g) {
        long[] dst = Arrays.copyOf(src, n);

        int h = Integer.numberOfTrailingZeros(n);
        long K = Integer.highestOneBit(P) << 1;
        int H = Long.numberOfTrailingZeros(K) * 2;
        long M = K * K / P;

        int[] wws = new int[1 << h - 1];
        long dw = inverse ? pow(g, P - 1 - (P - 1) / n, P) : pow(g, (P - 1) / n, P);
        long w = (1L << 32) % P;
        for (int k = 0; k < 1 << h - 1; k++) {
            wws[k] = (int) w;
            w = modh(w * dw, M, H, P);
        }
        long J = invl(P, 1L << 32);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < 1 << i; j++) {
                for (int k = 0, s = j << h - i, t = s | 1 << h - i - 1; k < 1 << h - i - 1; k++, s++, t++) {
                    long u = (dst[s] - dst[t] + 2 * P) * wws[k];
                    dst[s] += dst[t];
                    if (dst[s] >= 2 * P) {
                        dst[s] -= 2 * P;
                    }


                    long Q = (u << 32) * J >>> 32;
                    dst[t] = (u >>> 32) - (Q * P >>> 32) + P;
                }
            }
            if (i < h - 1) {
                for (int k = 0; k < 1 << h - i - 2; k++) {
                    wws[k] = wws[k * 2];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (dst[i] >= P) {
                dst[i] -= P;
            }
        }
        for (int i = 0; i < n; i++) {
            int rev = Integer.reverse(i) >>> -h;
            if (i < rev) {
                long d = dst[i];
                dst[i] = dst[rev];
                dst[rev] = d;
            }
        }

        if (inverse) {
            long in = invl(n, P);
            for (int i = 0; i < n; i++) {
                dst[i] = modh(dst[i] * in, M, H, P);
            }
        }

        return dst;
    }

    

    private static long[] id1(long[] src, int n, boolean inverse, int P, int g) {
        long[] dst = Arrays.copyOf(src, n);

        int h = Integer.numberOfTrailingZeros(n);
        long K = Integer.highestOneBit(P) << 1;
        int H = Long.numberOfTrailingZeros(K) * 2;
        long M = K * K / P;

        long dw = inverse ? pow(g, P - 1 - (P - 1) / n, P) : pow(g, (P - 1) / n, P);
        long[] wws = new long[1 << h - 1];
        long[] ws = new long[1 << h - 1];
        long w = 1;
        for (int k = 0; k < 1 << h - 1; k++) {
            wws[k] = (w << 32) / P;
            ws[k] = w;
            w = modh(w * dw, M, H, P);
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < 1 << i; j++) {
                for (int k = 0, s = j << h - i, t = s | 1 << h - i - 1; k < 1 << h - i - 1; k++, s++, t++) {
                    long ndsts = dst[s] + dst[t];
                    if (ndsts >= 2 * P) {
                        ndsts -= 2 * P;
                    }
                    long T = dst[s] - dst[t] + 2 * P;
                    long Q = wws[k] * T >>> 32;
                    dst[s] = ndsts;
                    dst[t] = ws[k] * T - Q * P & (1L << 32) - 1;
                }
            }


            if (i < h - 1) {
                for (int k = 0; k < 1 << h - i - 2; k++) {
                    wws[k] = wws[k * 2];
                    ws[k] = ws[k * 2];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (dst[i] >= P) {
                dst[i] -= P;
            }
        }
        for (int i = 0; i < n; i++) {
            int rev = Integer.reverse(i) >>> -h;
            if (i < rev) {
                long d = dst[i];
                dst[i] = dst[rev];
                dst[rev] = d;
            }
        }

        if (inverse) {
            long in = invl(n, P);
            for (int i = 0; i < n; i++) {
                dst[i] = modh(dst[i] * in, M, H, P);
            }
        }

        return dst;
    }

    static final long mask = (1L << 31) - 1;

    public static long modh(long a, long M, int h, int mod) {
        long r = a - ((M * (a & mask) >>> 31) + M * (a >>> 31) >>> h - 31) * mod;
        return r < mod ? r : r - mod;
    }

    private static long[] id2(int[] m) {
        int n = m.length;
        assert n == m.length;
        if (n == 0) {
            return new long[0];
        }
        long[] gamma = new long[n];
        for (int k = 1; k < n; k++) {
            long prod = 1;
            for (int i = 0; i < k; i++) {
                prod = prod * m[i] % m[k];
            }
            gamma[k] = invl(prod, m[k]);
        }
        return gamma;
    }

    private static long[] id12(int[] u, int[] m, long[] gamma) {
        int n = u.length;
        assert n == m.length;
        long[] v = new long[n];
        v[0] = u[0];
        for (int k = 1; k < n; k++) {
            long temp = v[k - 1];
            for (int j = k - 2; j >= 0; j--) {
                temp = (temp * m[j] + v[j]) % m[k];
            }
            v[k] = (u[k] - temp) * gamma[k] % m[k];
            if (v[k] < 0) {
                v[k] += m[k];
            }
        }
        return v;
    }

    private static long pow(long a, long n, long mod) {
        

        long ret = 1;
        int x = 63 - Long.numberOfLeadingZeros(n);
        for (; x >= 0; x--) {
            ret = ret * ret % mod;
            if (n << 63 - x < 0) {
                ret = ret * a % mod;
            }
        }
        return ret;
    }

    private static long invl(long a, long mod) {
        long b = mod;
        long p = 1, q = 0;
        while (b > 0) {
            long c = a / b;
            long d;
            d = a;
            a = b;
            b = d % b;
            d = p;
            p = q;
            q = d - c * q;
        }
        return p < 0 ? p + mod : p;
    }

    static class Scanner
    {
        BufferedReader br;
        StringTokenizer tk=new StringTokenizer("");
        public Scanner(InputStream is) 
        {
            br=new BufferedReader(new InputStreamReader(is));
        }
        public int nextInt() throws IOException
        {
            if(tk.hasMoreTokens())
                return Integer.parseInt(tk.nextToken());
            tk=new StringTokenizer(br.readLine());
            return nextInt();
        }
        public long nextLong() throws IOException
        {
            if(tk.hasMoreTokens())
                return Long.parseLong(tk.nextToken());
            tk=new StringTokenizer(br.readLine());
            return nextLong();
        }
        public String next() throws IOException
        {
            if(tk.hasMoreTokens())
                return (tk.nextToken());
            tk=new StringTokenizer(br.readLine());
            return next();
        }
        public String nextLine() throws IOException
        {
            tk=new StringTokenizer("");
            return br.readLine();
        }
        public double nextDouble() throws IOException
        {
            if(tk.hasMoreTokens())
                return Double.parseDouble(tk.nextToken());
            tk=new StringTokenizer(br.readLine());
            return nextDouble();
        }
        public char nextChar() throws IOException
        {
            if(tk.hasMoreTokens())
                return (tk.nextToken().charAt(0));
            tk=new StringTokenizer(br.readLine());
            return nextChar();
        }
        public int[] id8(int n) throws IOException
        {
            int a[]=new int[n];
            for(int i=0;i<n;i++)
                a[i]=nextInt();
            return a;
        }
        public long[] id15(int n) throws IOException
        {
            long a[]=new long[n];
            for(int i=0;i<n;i++)
                a[i]=nextLong();
            return a;
        }
        public int[] id7(int n) throws IOException
        {
            int a[]=new int[n+1];
            for(int i=1;i<=n;i++)
                a[i]=nextInt();
            return a;
        }
        public long[] id0(int n) throws IOException
        {
            long a[]=new long[n+1];
            for(int i=1;i<=n;i++)
                a[i]=nextLong();
            return a;
        }
    
    
    }
    static long fact[];
    static long ifact[];
    static long sum(long a[])
    {
        int n=a.length;
        long ans=0;
        for(int i=0;i<n;i++)
            ans+=a[i];
        return ans;
    }
    static long mod_exp(long base,long exp,long mod)
    {
        long ans=1;
        while(exp>0)
        {
            if(exp%2==1)
            {
                ans*=base;
                ans%=mod;
            }
            exp/=2;
            base*=base;
            base%=mod;
        }
        return ans;
    }
    
    static long modexp(long base,long exp)
    {
        long ans=1;
        while(exp>0)
        {
            if(exp%2==1)
            {
                ans*=base;
                
            }
            exp/=2;
            base*=base;
            
        }
        return ans;
    }
    static int[] id9(int n)
    {
        int e[]=new int[n+1];
        for(int i=0;i<=n;i++)
            e[i]=i;
        for(int i=2;i<=n;i++)
        {
            if(e[i]==i)
            {
                e[i]--;
                for(int j=2*i;j<=n;j+=i)
                    e[j]-=e[j]/i;
            }
        }
        return e;
    }
    static long[][] mat_mul(long a[][],long b[][],long mod)
    {
        int n=a.length;
        long c[][]=new long[n][n];
        long x=mod*mod;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    c[i][j]=(c[i][j]+(a[i][k]*b[k][j]));
                    if(c[i][j]>=x)
                        c[i][j]-=x;
                }
                c[i][j]%=mod;
            }
        return c;
    }
    static long[][] identity(int n)
    {
        long a[][]=new long[n][n];
        for(int i=0;i<n;i++)
            a[i][i]=1;
        return a;
    }
    static long[][] mat_exp(long a[][],long exp,long mod)
    {
        int n=a.length;
        long c[][]=identity(n);     
        while(exp>0)
        {
            if(exp%2==1)
            {
                c=mat_mul(c,a,mod);
            }
            exp/=2;
            a=mat_mul(a,a,mod);
        }
        return c;
    }
    static int[] id3(int n)
    {
        int p[]=new int[n+1];
        p[0]=p[1]=1;
        for(int i=2;i<=n;i+=2)
            p[i]=2;
        for(int i=3;i*i<=n;i+=2)
        {
            if(p[i]==0)
            {
                p[i]=i;
                for(int j=i*i;j<=n;j+=2*i)
                {
                    if(p[j]==0)
                        p[j]=i;
                }
            }
        }
        for(int i=3;i<=n;i++)
            if(p[i]==0)
                p[i]=i;
        return p;
    }
    static long[] mod_fact(int n,long mod)
    {
        long l[]=new long[n+1];
        l[0]=l[1]=1;
        for(int i=2;i<=n;i++)
            l[i]=(i*l[i-1])%mod;
        ifact=new long[n+1];
        ifact[n]=mod_inv(l[n],mod);
        for(int i=n-1;i>=0;i--)
            ifact[i]=((i+1)*(ifact[i+1]))%mod;
        
        return l;
    }
    static long mod_inv(long x,long mod)
    {
        return mod_exp(x,mod-2,mod);
    }
    static long ncr(int n,int r,long mod)
    {
        if(n<r)
            return 0;
        if(r<0)
            return 0;
        long ans=fact[n];
        ans*=((ifact[r]*ifact[n-r])%mod);
        return ans%mod;
    }
    static long id11(long n,long r,long fact[],int mod)
    {
        long ans=1;
        while(n>0)
        {
            int an=(int) (n%mod);
            int ar=(int) (r%mod);
            n/=mod;
            r/=mod;
            if(an<ar)
            {
                ans=0;
                break;
            }
            ans*=ncr(an,ar,mod);
        }
        return ans;
    }
    static long gcd(long a,long b)
    {
        if(a==0)
            return b;
        return gcd(b%a,a);
    }
    static class DSU
    {
        int n;
        int p[],r[];
        DSU(int y)
        {
            n=y+10;
            p=new int[n];
            r=new int[n];
            for(int i=0;i<n;i++)
            {
                p[i]=i;
            }
        }
        int find(int x)
        {
            if(p[x]==x)
                return x;
            return p[x]=find(p[x]);
        }
        boolean union(int a,int b)
        {
            a=find(a);
            b=find(b);
            if(a==b)
                return false;
            if(r[a]<r[b])
                p[a]=b;
            else if(r[b]<r[a])
                p[b]=a;
            else
            {
                p[b]=a;
                r[a]++;
            }
            return true;
        }
            
    }
    static class Multiset
    {
        TreeMap<Integer,Integer> map;
        public Multiset()
        {
            map=new TreeMap<>();
        }
        public void add(int x)
        {
            int c=1;
            if(map.containsKey(x))
                c+=map.get(x);
            map.put(x, c);
        }
        public void remove(int x)
        {
            int c=map.get(x);
            c--;
            if(c==0)
                map.remove(x);
            else
                map.put(x,c);
        }
        public boolean contains(int x)
        {
            return map.containsKey(x);
        }
        public boolean isEmpty()
        {
            return map.isEmpty();
        }
        public int max()
        {
            return map.lastKey();
        }
    }
    
    
    static class Pair<T1 extends Comparable, T2> implements Comparable<Pair<T1,T2>>
    {
        T1 f;
        T2 s;
        Pair(T1 a,T2 b)
        {
            f=a;
            s=b;
        }
        @Override
        public int compareTo(Pair<T1,T2> p)
        {
            return f.compareTo(p.f);
        }
    }
    static long[] dijkstra(ArrayList<Pair<Long,Integer>> g[],int s)
    {
        int n=g.length;
        long dist[]=new long[n];
        for(int i=0;i<n;i++)
            dist[i]=1000000000000000000l;
        dist[s]=0;
        PriorityQueue<Pair<Long,Integer>> pq=new PriorityQueue<>();
        pq.add(new Pair<>(0l,s));
        boolean visited[]=new boolean[n];
        while(!pq.isEmpty())
        {
            Pair<Long,Integer> p=pq.poll();
            if(visited[p.s])
                continue;
            visited[p.s]=true;
            for(int i=0;i<g[p.s].size();i++)
            {
                int node=g[p.s].get(i).s;
                long edgewt=g[p.s].get(i).f;
                if(dist[node]>p.f+edgewt)
                {
                    dist[node]=p.f+edgewt;
                    pq.add(new Pair<>(dist[node],node));
                }
            }
            
        }
        return dist;
    }
    public static int[] suffixArray(CharSequence S) 
    {
        int n = S.length();
        Integer[] order = new Integer[n];
        for (int i = 0; i < n; i++)
            order[i] = n - 1 - i;
        Arrays.sort(order, (a, b) -> Character.compare(S.charAt(a), S.charAt(b)));

        int[] sa = new int[n];
        int[] classes = new int[n];
        for (int i = 0; i < n; i++) 
        {
            sa[i] = order[i];
            classes[i] = S.charAt(i);
        }
        for (int len = 1; len < n; len *= 2) 
        {
            int[] c = classes.clone();
            for (int i = 0; i < n; i++) 
            {
                classes[sa[i]] = i > 0 && c[sa[i - 1]] == c[sa[i]] && sa[i - 1] + len < n && c[sa[i - 1] + len / 2] == c[sa[i] + len / 2] ? classes[sa[i - 1]] : i;
            }
            int[] cnt = new int[n];
            for (int i = 0; i < n; i++)
                cnt[i] = i;
            int[] s = sa.clone();
            for (int i = 0; i < n; i++) 
            {
                int s1 = s[i] - len;
                if (s1 >= 0)
                sa[cnt[classes[s1]]++] = s1;
            }
        }
        return sa;
    }
    static int[] lcp(int[] sa, CharSequence s) 
    {
        int n = sa.length;
        int[] rank = new int[n];
        for (int i = 0; i < n; i++)
        rank[sa[i]] = i;
        int[] lcp = new int[n-1];
        for (int i = 0, h = 0; i < n; i++) 
        {
            if (rank[i] < n - 1) 
            {
                for (int j = sa[rank[i] + 1]; Math.max(i, j) + h < s.length() && s.charAt(i + h) == s.charAt(j + h); ++h);
                lcp[rank[i]] = h;
                if (h > 0)
                    --h;
            }
        }
        int lcpp[]=new int[n];
        for(int i=1;i<n;i++)
            lcpp[i]=lcp[i-1];
        return lcpp;
    }
    static class query implements Comparable<query>
    {
        int l,r,block,index;
        query(int inde,int la,int ra,int lock)
        {
            index=inde;
            block=lock;
            l=la;
            r=ra;
        }
        @Override
        public int compareTo(query o) 
        {
            if(block!=o.block)
                return block<o.block?-1:block>o.block?1:0;
            int sgn=1;
            if(block%2==1)
                sgn=-1;
            return sgn*(r<o.r?-1:r>o.r?1:0);
        }
        
    }
    static class BIT1
    {
        int n;
        ArrayList<Integer> t[];
        TreeMap<Integer,Integer> tr[];
        BIT1(int x)
        {
            n=x;
            t=new ArrayList[x+5];
            tr=new TreeMap[x+5];
            for(int i=1;i<=n;i++)
            {
                t[i]=new ArrayList<>();
                tr[i]=new TreeMap<>();
            }
        }
        void add(int i,int x)
        {
            for(;i<=n;i+=i&-i)
                t[i].add(x);
        }
        void compact()
        {
            for(int i=1;i<=n;i++)
            {
                Collections.sort(t[i]);
                int sum=0;
                for(int j=t[i].size()-1;j>=0;j--)
                {
                    sum++;
                    tr[i].put(t[i].get(j), sum);
                }
            }
            
            
        }
        int query(int i,int v)
        {
           int ans=0;
           for(;i>0;i-=i&-i)
           {
               Map.Entry<Integer,Integer> e=tr[i].higherEntry(v);
               if(e!=null)
                   ans+=e.getValue();
           }
           return ans;
        }
    }
    static class BIT2
    {
        int n;
        ArrayList<Integer> t[];
        TreeMap<Integer,Integer> tr[];
        BIT2(int x)
        {
            n=x;
            t=new ArrayList[x+5];
            tr=new TreeMap[x+5];
            for(int i=1;i<=n;i++)
            {
                t[i]=new ArrayList<>();
                tr[i]=new TreeMap<>();
            }
        }
        void add(int i,int x)
        {
            for(;i<=n;i+=i&-i)
                t[i].add(x);
        }
        void compact()
        {
            for(int i=1;i<=n;i++)
            {
                Collections.sort(t[i]);
                int sum=0;
                for(int j:t[i])
                {
                    sum++;
                    tr[i].put(j, sum);
                }
            }
            
            
        }
        int query(int i,int v)
        {
           int ans=0;
           for(;i>0;i-=i&-i)
           {
               Map.Entry<Integer,Integer> e=tr[i].lowerEntry(v);
               if(e!=null)
                   ans+=e.getValue();
           }
           return ans;
        }
    }
    static long mod=998244352;
    static long[] solve(ArrayList<long[]> a)
    {
        if(a.size()==0)
            return new long[]{1};
        if(a.size()==1)
            return a.get(0);
        ArrayList<long[]> left=new ArrayList<>();
        ArrayList<long[]> right=new ArrayList<>();
        for(int i=0;i<a.size();i++)
            if(i%2==0)
                left.add(a.get(i));
            else
                right.add(a.get(i));
        return reduce(id4(solve(left),solve(right),3,1000000007));
    }
    static int k;
    static long[] reduce(long a[])
    {
        if(a.length<=k)
            return a;
        long b[]=new long[k+1];
        for(int i=0;i<=k;i++)
            b[i]=a[i];
        return b;
    }
    static void egcd(long a,long b,long x[]){
        if(b==0){
            x[0]=1;
            x[1]=0;
            return ;
        }
        long f[]=new long[2];
        egcd(b,a%b,f);
        x[0]=f[1];
        x[1]=f[0]-(a/b)*f[1];
    }
    public static void main(String args[]) throws IOException
    {
        Scanner in=new Scanner(System.in);
        PrintWriter out=new PrintWriter(System.out);
        int k=in.nextInt();
        long m[][]=new long[k][k];
        m[0]=in.id15(k);
        for(int i=1;i<k;i++)
            m[i][i-1]=1;
        int n=in.nextInt();
        long M=in.nextLong();
        m=mat_exp(m,n-k,mod);
        long v=m[0][0];
        if((v==0&&M==1)||M==1){
            out.println(1);
        }
        else if(mod_exp(M,mod/gcd(v,mod),mod+1)%(mod+1)!=1){
            out.println(-1);
        }
        else{
            {
                
                mod++;
                long vp=mod_exp(3,v,mod);
                long sqrt=31596;
                HashMap<Long,Integer> mp1=new HashMap<>();
                long vv=1;
                for(int i=0;i<=sqrt;i++){
                    mp1.put(vv,i);
                    vv*=vp;
                    vv%=mod;
                }
                vp=mod_inv(vp,mod);
                vp=mod_exp(vp,sqrt,mod);
                for(int i=0;i<sqrt;i++){
                    if(mp1.containsKey(M)){
                        out.println(mod_exp(3,i*sqrt+mp1.get(M),mod));
                        break;
                    }
                    M*=vp;
                    M%=mod;
                }
            }
        }
               
        out.close();
    }
    

}
