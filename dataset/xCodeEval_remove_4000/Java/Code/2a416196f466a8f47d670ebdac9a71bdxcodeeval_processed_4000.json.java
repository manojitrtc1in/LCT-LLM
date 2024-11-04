    import java.io.*;
    import java.math.BigDecimal;
    import java.math.BigInteger;
    import java.math.RoundingMode;
    import java.text.CollationElementIterator;
    import java.util.*;
    

    import javax.lang.model.type.IntersectionType;
    import javax.print.attribute.standard.PrinterResolution;
    import javax.swing.text.html.CSS;
    import javax.swing.tree.TreeNode;

    public class codeforces {
        static class FastReader {
            BufferedReader br;
            StringTokenizer st;

            public FastReader() {
                br = new BufferedReader(new InputStreamReader(System.in));
            }

            String next() {
                while (st == null || !st.hasMoreElements()) {
                    try {
                        st = new StringTokenizer(br.readLine());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
                return st.nextToken();
            }

            int nextInt() {
                return Integer.parseInt(next());
            }

            long nextLong() {
                return Long.parseLong(next());
            }

            double nextDouble() {
                return Double.parseDouble(next());
            }

            String nextLine() {
                String str = "";
                try {
                    str = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                return str;
            }
        }

        static boolean id10(int n,
                                   int k) {
            if (((n >> (k)) &
                    1) > 0)
                return true;
            return false;
        }

        static void move(char a[], int i) {
            int j = 0;
            int temp1 = i;
            while (j < i) {
                char temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                j++;
                i--;
            }
            for (int k = 0; k <= temp1; k++) {
                a[k] = (a[k] == '0') ? '1' : '0';
            }
        }

        static int fact(int a) {
            int f = 1;
            for (int i = 2; i <= a; i++)
                f *= i;
            return f;
        }

        static long gcd(long a, long b) {
            if (a == 0)
                return b;
            return gcd(b % a, a);

        }


        
        static int left;
        static int countIncreasing(int n,int arr[])
        {
            int cnt = 0;  


            

            

            int len = 1;

            

            for (int i=0; i < n-1; ++i)
            {
                

                

                if (arr[i + 1] > arr[i])
                    len++;

                    

                else
                {
                    cnt += (((len - 1) * len) / 2);
                    len = 1;
                }
            }

            

            if (len > 1) {
                left-=len;
                cnt += (((len - 1) * len) / 2);
            }

            return cnt;
        }
        public static class edge
        {
            int d,s,c;
            edge(int d,int s,int c)
            {
                this.d=d;
                this.s=s;
                this.c=c;
            }
        }
        
        static class Trie{


            boolean isFound;
            Map<Character,Trie> map;

            Trie(){

                map=new HashMap<Character, Trie>();
                for(char i='a';i<='z';i++) {

                    map.put(i,null);
                }
                isFound=false;
            }
        }

        public static boolean check(int x,int y,int A,int B)
        {
            if(x>=0 && x<A && y>=0 && y<B)
                return true;
            return false;
        }
        public static class pair
        {
            int x,y,cost;
            pair(int x,int y,int ans)
            {
                this.x=x;
                this.y=y;
                this.cost=ans;
            }
        }
        public static int minimumDistance(List<List<Integer>>area) {
            int X[]={0,0,1,-1};
            int Y[]={1,-1,0,0};
            int A=area.size();
            int B=area.get(0).size();
            boolean vis[][]=new boolean[A][B];
            Queue<pair> q=new LinkedList<>();
            q.add(new pair(0,0,0));
            vis[0][0]=true;
            while(q.size()>0)
            {
                pair t=q.poll();
                int x=t.x;
                int y=t.y;
                int cost=t.cost;
                if(area.get(x).get(y)==9)
                    return cost;
                for(int i=0;i<4;i++)
                {
                    int newx=x+X[i];
                    int newy=y+Y[i];
                    if(check(newx,newy,A,B) && area.get(newx).get(newy)==9)
                        return cost+1;
                    if(check(newx,newy,A,B) && area.get(newx).get(newy)==1 && !vis[newx][newy]) {
                        q.add(new pair(newx, newy, cost + 1));
                        vis[newx][newy]=true;
                    }
                }
            }
            return -1;

        }
        public static void main(String[] args) throws IOException {
            BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
            InputReader sc = new InputReader(System.in);
            int t=sc.nextInt();
            while(t-->0)
            {
                int n=sc.nextInt();
                long a[][]=new long[n][2];
                for(int i=0;i<n;i++) {
                    a[i][0] = sc.nextLong();
                    a[i][1]=i;
                }
                Arrays.sort(a,(x,y)->Long.compare(x[0],y[0]));
                long sum=0;
                int ans[]=new int[n+1];
                    long c=1;
                    int k=0;
                    for(int i=n-1;i>=0;i-=2) {
                        sum += ((a[i][0]) * (c++))*2;
                        ans[(int)a[i][1]+1]=(--k);
                    }
                    c=1;
                    k=0;
                    for(int i=n-2;i>=0;i-=2) {
                        sum += ((a[i][0]) * (c++))*2;
                        ans[(int)a[i][1]+1]=(++k);
                    }
                System.out.println(sum);
                for(int i=0;i<ans.length;i++)
                    System.out.print(ans[i]+" ");
                System.out.println();

            }
        }


        static class InputReader {
            private InputStream in;
            private byte[] buffer = new byte[1024];
            private int curbuf;
            private int lenbuf;
            public InputReader(InputStream in) {
                this.in = in;
                this.curbuf = this.lenbuf = 0;
            }
            public boolean id14() {
                if (curbuf >= lenbuf) {
                    curbuf = 0;
                    try {
                        lenbuf = in.read(buffer);
                    } catch (IOException e) {
                        throw new InputMismatchException();
                    }
                    if (lenbuf <= 0)
                        return false;
                }
                return true;
            }

            private int readByte() {
                if (id14())
                    return buffer[curbuf++];
                else
                    return -1;
            }

            private boolean id2(int c) {
                return !(c >= 33 && c <= 126);
            }

            private void skip() {
                while (id14() && id2(buffer[curbuf]))
                    curbuf++;
            }

            public boolean hasNext() {
                skip();
                return id14();
            }

            public String next() {
                if (!hasNext())
                    throw new NoSuchElementException();
                StringBuilder sb = new StringBuilder();
                int b = readByte();
                while (!id2(b)) {
                    sb.appendCodePoint(b);
                    b = readByte();
                }
                return sb.toString();
            }

            public int nextInt() {
                if (!hasNext())
                    throw new NoSuchElementException();
                int c = readByte();
                while (id2(c))
                    c = readByte();
                boolean minus = false;
                if (c == '-') {
                    minus = true;
                    c = readByte();
                }
                int res = 0;
                do {
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    res = res * 10 + c - '0';
                    c = readByte();
                } while (!id2(c));
                return (minus) ? -res : res;
            }

            public long nextLong() {
                if (!hasNext())
                    throw new NoSuchElementException();
                int c = readByte();
                while (id2(c))
                    c = readByte();
                boolean minus = false;
                if (c == '-') {
                    minus = true;
                    c = readByte();
                }
                long res = 0;
                do {
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    res = res * 10 + c - '0';
                    c = readByte();
                } while (!id2(c));
                return (minus) ? -res : res;
            }

            public double nextDouble() {
                return Double.parseDouble(next());
            }

            public int[] id4(int n) {
                int[] a = new int[n];
                for (int i = 0; i < n; i++)
                    a[i] = nextInt();
                return a;
            }

            public long[] id15(int n) {
                long[] a = new long[n];
                for (int i = 0; i < n; i++)
                    a[i] = nextLong();
                return a;
            }

            public char[][] id5(int n, int m) {
                char[][] map = new char[n][m];
                for (int i = 0; i < n; i++)
                    map[i] = next().toCharArray();
                return map;
            }
        }
    }
    class bs{
        public static boolean search(long arr[],long tar)
        {
            int i=0;
            int j=arr.length-1;
            while(j>=i)
            {
                int mid=i+(j-i)/2;
                if(arr[mid]==tar)
                    return true;
                else if(arr[mid]>tar)
                    j=mid-1;
                else
                    i=mid+1;
            }
            return false;
        }
        public static int closestleft(long arr[],long tar)
        {
            int l=-1;
            int r=arr.length;
            while(r>l+1)
            {
                int m=l+(r-l)/2;
                if(arr[m]<=tar)
                    l=m;
                else
                    r=m;
            }
            return l;
        }
        public static int id6(long arr[],long tar)
        {
            int l=-1;
            int r=arr.length;
            while(r>l+1)
            {
                int m=l+(r-l)/2;
                if(arr[m]<tar)
                    l=m;
                else
                    r=m;
            }
            return r;
        }
    }
    class MergeSort {
        

        

        

        static void  merge(long arr[], int l, int m, int r) {
            

            int n1 = m - l + 1;
            int n2 = r - m;

            
            long L[] = new long[n1];
            long R[] = new long[n2];

            
            for (int i = 0; i < n1; ++i)
                L[i] = arr[l + i];
            for (int j = 0; j < n2; ++j)
                R[j] = arr[m + 1 + j];


            

            

            int i = 0, j = 0;

            

            int k = l;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    arr[k] = L[i];
                    i++;
                } else {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }

            
            while (i < n1) {
                arr[k] = L[i];
                i++;
                k++;
            }

            
            while (j < n2) {
                arr[k] = R[j];
                j++;
                k++;
            }
        }

        

        

        static void sort(long arr[], int l, int r) {
            if (l < r) {
                

                int m = (l + r) / 2;

                

                sort(arr, l, m);
                sort(arr, m + 1, r);

                

                merge(arr, l, m, r);
            }
        }
    }
    class st {
        static int size;
        static long[][] sums;
        static long id8=0;
        public static void init(int n)
        {
            size=1;
            while(size<n)
                size*=2;
            sums=new long[2*size][27];
        }
        static int m;
        public static long single(long v)
        {
            return 1;
        }
        public static long[] merge(long a[],long b[])
        {
            if(a.length==0 && b.length==0)
                return new long[0];
            if(a.length==0)
                return b;
            if(b.length==0)
                return a;
            for(int i=0;i<27;i++)
                b[i]=b[i]+a[i];
            return b;
        }
        public static void build(long[] a,int x,int lx,int rx)
        {
            if(rx-lx==1)
            {
                long z=a[lx];
                sums[x][(int)z-96]=1;
                return;
            }
            int mid=(lx+rx)/2;
            build(a,2*x+1,lx,mid);
            build(a,2*x+2,mid,rx);
            sums[x]=merge(sums[2*x+1],sums[2*x+2]);
        }
        public static void build(long[] a)
        {
            build(a,0,0,size);
        }

        public static void set(int i,long v,int x,int lx,int rx,long a[],char c)
        {
            if(rx-lx==1)
            {
                long z=a[i];
                sums[x][(int)z-96]=0;
                sums[x][(int)c-96]=1;
                return;
            }
            int m=(lx+rx)/2;
            if(i<m)
                set(i,v,2*x+1,lx,m,a,c);
            else
                set(i,v,2*x+2,m,rx,a,c);
            sums[x]=merge(sums[2*x+1],sums[2*x+2]);
        }
        public static void set(int i,long v,long a[],char c)
        {
            set(i,v,0,0,size,a,c);
        }
        public static long[] calc(int l,int r)
        {
            return calc(l,r,0,0,size);
        }
        public static long[] calc(int l,int r,int x,int lx,int rx)
        {
            if(lx>=r || rx<=l)
                return new long[0];
            if(lx>=l && rx<=r)
                return sums[x];
            int mid=(lx+rx)/2;
            long s1[]=calc(l,r,2*x+1,lx,mid);
            long s2[]=calc(l,r,2*x+2,mid,rx);
            return merge(s1,s2);
        }
        
    }
    class MathLib{
        public static int[] id12(int n) {
            if (n <= 32) {
                int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
                for (int i = 0; i < primes.length; i++) {
                    if (n < primes[i]) {
                        return Arrays.copyOf(primes, i);
                    }
                }
                return primes;
            }

            int u = n + 32;
            double lu = Math.log(u);
            int[] ret = new int[(int) (u / lu + u / lu / lu * 1.5)];
            ret[0] = 2;
            int pos = 1;

            int[] isnp = new int[(n + 1) / 32 / 2 + 1];
            int sup = (n + 1) / 32 / 2 + 1;

            int[] id3 = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
            for (int tp : id3) {
                ret[pos++] = tp;
                int[] ptn = new int[tp];
                for (int i = (tp - 3) / 2; i < tp << 5; i += tp) ptn[i >> 5] |= 1 << (i & 31);
                for (int j = 0; j < sup; j += tp) {
                    for (int i = 0; i < tp && i + j < sup; i++) {
                        isnp[j + i] |= ptn[i];
                    }
                }
            }

            

            

            int[] magic = {0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14};
            int h = n / 2;
            for (int i = 0; i < sup; i++) {
                for (int j = ~isnp[i]; j != 0; j &= j - 1) {
                    int pp = i << 5 | magic[(j & -j) * 0x076be629 >>> 27];
                    int p = 2 * pp + 3;
                    if (p > n) break;
                    ret[pos++] = p;
                    if ((long) p * p > n) continue;
                    for (int q = (p * p - 3) / 2; q <= h; q += p) isnp[q >> 5] |= 1 << q;
                }
            }

            return Arrays.copyOf(ret, pos);
        }
        static boolean[] id9(int n) {
            

            

            

            

            

            

            

            boolean prime[] = new boolean[n + 1];
            for (int i = 0; i <= n; i++)
                prime[i] = true;

            for (int p = 2; p * p <= n; p++) {
                

                

                if (prime[p] == true) {
                    

                    for (int i = p * p; i <= n; i += p)
                        prime[i] = false;
                }
            }
            return prime;
        }
        public static int getMax(int[] inputArray){
            int maxValue = inputArray[0];
            for(int i=1;i < inputArray.length;i++){
                if(inputArray[i] > maxValue){
                    maxValue = inputArray[i];
                }
            }
            return maxValue;
        }

        

        public static int getMin(int[] inputArray){
            int minValue = inputArray[0];
            for(int i=1;i<inputArray.length;i++){
                if(inputArray[i] < minValue){
                    minValue = inputArray[i];
                }
            }
            return minValue;
        }
        static int id7(long n)
        {
            int count = 0;
            while (n > 0) {
                count += n & 1;
                n >>= 1;
            }
            return count;
        }
        static long binpow(long a, long b) {
            long res = 1;
            while (b > 0) {
                if ((b & 1)>0)
                    res = res * a;
                a = a * a;
                b >>= 1;
            }
            return res;
        }
        static ArrayList<Integer> id11(int n)
        {
            ArrayList<Integer> al=new ArrayList<>();
            for (int i=2; i<=Math.sqrt(n); i++)
            {
                if (n%i==0)
                {
                    

                    if (n/i == i)
                        al.add(i);

                    else 

                    {
                        al.add(i);
                        al.add(n/i);
                    }

                }
            }
            return al;
        }

        static long fastPow(long a, long b, long mod) {
            if(b == 0)
                return 1L;

            long val = fastPow(a, b/2, mod);
            if(b % 2 == 0)
                return val * val % mod;
            else
                return val * val % mod * a % mod;
        }
        static int LowerBound(int a[], int x) { 

            int l=-1,r=a.length;
            while(l+1<r) {
                int m=(l+r)>>>1;
                if(a[m]>=x) r=m;
                else l=m;
            }
            return r;
        }
        static int UpperBound(int a[], int x) {

            int l=-1,r=a.length;
            while(l+1<r) {
                int m=(l+r)>>>1;
                if(a[m]<=x) l=m;
                else r=m;
            }
            return l+1;
        }
        private static long safe_mod(long x, long m){
            x %= m;
            if(x<0) x += m;
            return x;
        }

        private static long[] id1(long a, long b){
            a = safe_mod(a, b);
            if(a==0) return new long[]{b,0};

            long s=b, t=a;
            long m0=0, m1=1;
            while(t>0){
                long u = s/t;
                s -= t*u;
                m0 -= m1*u;
                long tmp = s; s = t; t = tmp;
                tmp = m0; m0 = m1; m1 = tmp;
            }
            if(m0<0) m0 += b/s;
            return new long[]{s,m0};
        }

        public static long gcd(long a, long b){
            a = java.lang.Math.abs(a);
            b = java.lang.Math.abs(b);
            return id1(a, b)[0];
        }
        public static long lcm(long a, long b){
            a = java.lang.Math.abs(a);
            b = java.lang.Math.abs(b);
            return a / gcd(a,b) * b;
        }

        public static long pow_mod(long x, long n, int m){
            assert n >= 0;
            assert m >= 1;
            if(m == 1)return 0L;
            x = safe_mod(x, m);
            long ans = 1L;
            while(n > 0){
                if((n&1) == 1) ans = (ans * x) % m;
                x = (x*x) % m;
                n >>>= 1;
            }
            return ans;
        }
        static long fact[]=new long[1000001];
        static long inv_fact[]=new long[1000001];
        static int p=1000000007;
        public static void precomp()
        {
            fact[0]=fact[1]=1;
            for(int i=2;i<=fact.length-1;i++)
            {
                fact[i]=(fact[i-1]*i)%p;
            }
            inv_fact[(int)1e6]=modpow(fact[(int)1e6],p-2);
            for(int i=fact.length-2;i>=0;i--)
            {
                inv_fact[i]=(inv_fact[i+1]*(i+1))%p;
            }
        }
        public static boolean summ(int n,int a,int b)
        {
            while(n>0)
            {
                if(n%10!=a && n%10!=b)return false;
                n/=10;
            }
            return true;
        }
        public static long modpow(long x,long n)
        {
            long res=1;
            while(n>0)
            {
                if(n%2!=0)
                {
                    res=(res*x)%p;n--;
                }
                else
                {
                    x=(x*x)%p;n/=2;
                }
            }
            return res;
        }
        public static long ncr(int n,int r)
        {
            if(r>n || r<0 || n<0)return 0;
            return fact[n]*inv_fact[r]%p*inv_fact[n-r]%p;
        }
        public static void id13(int u,boolean vis[],int color[],ArrayList<Integer>[] al)
        {
            vis[u]=true;
            for(int v:al[u])
            {
                if(!vis[v])
                {
                    if(color[v]==-1) {
                        color[v]=1-color[u];
                        id13(v,vis,color,al);
                    }
                }

            }
        }

        public static long[] crt(long[] r, long[] m){
            assert(r.length == m.length);
            int n = r.length;

            long r0=0, m0=1;
            for(int i=0; i<n; i++){
                assert(1 <= m[i]);
                long r1 = safe_mod(r[i], m[i]), m1 = m[i];
                if(m0 < m1){
                    long tmp = r0; r0 = r1; r1 = tmp;
                    tmp = m0; m0 = m1; m1 = tmp;
                }
                if(m0%m1 == 0){
                    if(r0%m1 != r1) return new long[]{0,0};
                    continue;
                }

                long[] ig = id1(m0, m1);
                long g = ig[0], im = ig[1];

                long u1 = m1/g;
                if((r1-r0)%g != 0) return new long[]{0,0};

                long x = (r1-r0) / g % u1 * im % u1;

                r0 += x * m0;
                m0 *= u1;
                if(r0<0) r0 += m0;
                

            }
            return new long[]{r0, m0};
        }
        public static long floor_sum(long n, long m, long a, long b){
            long ans = 0;
            if(a >= m){
                ans += (n-1) * n * (a/m) / 2;
                a %= m;
            }
            if(b >= m){
                ans += n * (b/m);
                b %= m;
            }

            long y_max = (a*n+b) / m;
            long x_max = y_max * m - b;
            if(y_max == 0) return ans;
            ans += (n - (x_max+a-1)/a) * y_max;
            ans += floor_sum(y_max, a, m, (a-x_max%a)%a);
            return ans;
        }

        public static java.util.ArrayList<Long> id0(long n){
            java.util.ArrayList<Long> id0 = new ArrayList<>();
            java.util.ArrayList<Long> large = new ArrayList<>();

            for(long i=1; i*i<=n; i++) if(n%i==0){
                id0.add(i);
                if(i*i<n) large.add(n/i);
            }
            for(int p=large.size()-1; p>=0; p--){
                id0.add(large.get(p));
            }
            return id0;
        }
    }