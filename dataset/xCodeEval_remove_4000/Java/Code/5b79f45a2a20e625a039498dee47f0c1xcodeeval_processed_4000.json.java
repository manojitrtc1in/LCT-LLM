
import com.sun.org.apache.bcel.internal.generic.IF_ACMPEQ;
import com.sun.scenario.effect.impl.prism.PrImage;
import com.sun.scenario.effect.impl.sw.sse.SSEBlend_SRC_OUTPeer;
import org.omg.CORBA.INTERNAL;
import org.omg.CORBA.MARSHAL;
import sun.nio.cs.ext.MacSymbol;
import sun.nio.cs.ext.MacThai;

import javax.swing.plaf.basic.BasicTreeUI;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;


public class Main {
    private static Scanner sc;
    private static Printer pr;
    static boolean []visited;
    static int []color;
    static int []pow=new int[(int)3e5+1];
    static int []count;
    static boolean check=true;
    static boolean id0=true;
    static TreeSet<Integer>[]list;
    private static long aLong=(long)(Math.pow(10,9)+7);
    static final long div=998244353;
    static  int answer=0;
    static int[]id4;
    static int[]colorNode;
    static boolean con=true;
    static ArrayList<Integer>dfsPath=new ArrayList<>();
    static ArrayList<Integer>ans=new ArrayList<>();
    static boolean[]rec;
    static int min=Integer.MAX_VALUE;
    static ArrayList<Task>tasks=new ArrayList<>();
    static  boolean []checkpath;
    static long []out;
    static TreeSet<Integer>[]dp;
    static long[]valVertex;
    static int anss=0;
    static long []poww=new long[40];
    static StringBuilder solve=new StringBuilder();
    private static void solve() throws IOException {
        int n=sc.nextInt();
        PriorityQueue<pairA>in=new PriorityQueue<>(new Comparator<pairA>() {
            @Override
            public int compare(pairA o1, pairA o2) {
                if (o1.val>o2.val)return -1;
                else if (o1.val<o2.val)return 1;
                else {
                    if (o2.idx>o1.idx)return -1;
                    else if (o2.idx<o1.idx)return 1;
                    else return 0;
                }
            }
        });
        for (int i=0;i<n;++i)
            in.add(new pairA(sc.nextLong(),i));
        int m=sc.nextInt();
        pairB[]req=new pairB[m];
        long []ansReq=new long[m];
        for (int i=0;i<m;++i){
            int k=sc.nextInt(),pos=sc.nextInt();
            req[i]=new pairB(k,pos,i);
        }
        Arrays.sort(req, new Comparator<pairB>() {
            @Override
            public int compare(pairB o1, pairB o2) {
                if (o1.k>o2.k)return 1;
                else if (o1.k<o2.k)return -1;
                else return 0;
            }
        });
        int countReq=0;
        TreeSet<pairA>pairAS=new TreeSet<>(new Comparator<pairA>() {
            @Override
            public int compare(pairA o1, pairA o2) {
                if (o1.idx>o2.idx)return 1;
                else return -1;
            }
        });
        for (int i=0;i<m;++i){
            while (countReq<req[i].k){
                pairA a=in.remove();
                pairAS.add(a);
                ++countReq;
            }
            pairA pairA= (Main.pairA) pairAS.toArray()[req[i].pos-1];
            ansReq[req[i].index]= pairA.val ;
        }
        for (int i=0;i<m;++i)
            pr.println(ansReq[i]);
        
    }
    static class pairB{
        int k,pos,index;

        public pairB(int k, int pos, int index) {
            this.k = k;
            this.pos = pos;
            this.index = index;
        }
    }
    static class pairA{
        long val;
        int idx;
        public pairA(long val, int idx) {
            this.val = val;
            this.idx = idx;
        }
    }
    public static void printPath(boolean ch,int i,int j,long[][][]dp){
        if (ch){
            if (i==0&&j==0) return;
            else if (i-1<0){
                solve.append("R");
                printPath(true,i,j-1,dp);
            }
            else if (j-1<0){
                solve.append("D");
                printPath(true,i-1,j,dp);
            }
            else {
                if (dp[i][j][0]>=dp[i-1][j][0]){
                    solve.append("D");
                    printPath(true,i-1,j,dp);
                }
                else {
                    solve.append("R");
                    printPath(true,i,j-1,dp);
                }
            }
        }else {
            if (i==0&&j==0) return;
            else if (i-1<0){
                solve.append("R");
                printPath(false,i,j-1,dp);
            }
            else if (j-1<0){
                solve.append("D");
                printPath(false,i-1,j,dp);
            }
            else {
                if (dp[i][j][1]>=dp[i-1][j][1]){
                    solve.append("D");
                    printPath(false,i-1,j,dp);
                }
                else{
                    solve.append("R");
                    printPath(false,i,j-1,dp);
                }
            }
        }
    }
    public static class dsu{
        int []rank;
        int[]parent;
        long []sum;
        int n;
        public dsu(int n) {
            this.n = n;
            parent=new int[n];
            rank=new int[n];
            sum=new long[n];
            for (int i=0;i<n;++i){
                rank[i]=1;
                parent[i]=i;
                sum[i]=0;
            }
        }
        public int dad(int child){
            if (parent[child]==child)return child;
            else return dad(parent[child]);
        }
        public void merge(int u,int v){
            int dadU=dad(u);
            int dadV=dad(v);
            if (dadU==dadV)return ;
            if (u!=v){
                if (rank[u]<rank[v]){
                    parent[u]=v;
                    rank[v]+=rank[u];
                }
                else if (rank[u]==rank[v]){
                    parent[u]=v;
                    rank[v]+=rank[u];
                }
                else{
                    parent[v]=u;
                    rank[u]+=rank[v];
                }
            }
        }
    }
    public static long power(long x,long y,long mods){
        if (y==0) return 1%mods;
        long u=power(x,y/2,mods);
        u=((u)*(u))%mods;
        if (y%2==1) u=(u*(x%mods))%mods;
        return u;
    }
    public static class Task implements Comparable<Task>{
        long l,r;
        public Task(long w,long v) {
            this.l=w;
            this.r=v;
        }

        @Override
        public int compareTo(Task o) {
            if (o.l<this.l)return 1;
            else if (o.l>this.l)return -1;
            else {
                if (o.r>this.r)return 1;
                else if (o.r<this.r)return -1;
            }
            return 0;
        }
    }
    public static void printSolve(StringBuilder str, int[] colors, int n,int color){
        for(int i = 1;i<=n;++i)
            if(colors[i] == color)
                str.append(i + " ");
        str.append('\n');
    }
    public static class pairTask{
        int  val;
        int size;
        public pairTask(int   x, int  y) {
            this.val = x;
            this.size = y;
        }
    }
    public static void subTree(int src,int parent,int x){
        id4[src]=1;
        if (src==x) {
            checkpath[src]=true;
            

        }
        else checkpath[src]=false;
        for (int v:list[src]){
            if (v==parent)
                continue;
            subTree(v,src,x);
            id4[src]+=id4[v];
            checkpath[src]|=checkpath[v];
        }
    }
    public static boolean prime(long src){
        for (int i=2;i*i<=src;i++){
            if (src%i==0)
                return false;
        }
        return true;
    }
    public static void id2(int src){
        Queue<Integer>queue = new ArrayDeque<>();
        queue.add(src);
        while (!queue.isEmpty()){
            boolean b=false;
            int vertex=-1,p=-1;
            int poll=queue.remove();
            for (int v:list[poll]){
                if (color [v]==0){
                    vertex=v;
                    break;
                }
            }
            for (int v:list[poll]){
                if (color [v]!=0&&v!=vertex){
                    p=v;
                    break;
                }
            }
            for (int v:list[p]){
                if (color [v]!=0){
                    color[vertex]=color[v];
                    b=true;
                    break;
                }
            }
            if (!b){
                color[vertex]=color[poll]+1;
            }
        }
    }
    static int add(int a,int b ){
        if (a+b>=div)
            return (int)(a+b-div);
        return (int)a+b;
    }
    public static int id1(ArrayList<Integer>[]list,int src){
        color[src]=0;
        Queue<Integer>queue=new LinkedList<>();
        int []ans={0,0};
        queue.add(src);
        while (!queue.isEmpty()){
            ans[color[src=queue.poll()]]++;
            for (int v:list[src]){
                if (color[v]==-1){
                    queue.add(v);
                    color[v]=color[src]^1;
                }else if (color[v]==color[src])
                    check=false;
            }
        }
        return add(pow[ans[0]],pow[ans[1]]);
    }
    public static int powerMod(long b, long e){
        long ans=1;
        while (e-->0){
            ans=ans*b%div;
        }
        return (int)ans;
    }
    public static int dfs(int s){
        int ans=1;
        visited[s]=true;
        for (int k:list[s]){
            if (!visited[k]){
                ans+=dfs(k);
            }
        }
        return ans;
    }
    public static int[] id6(int[] f) {
        int[] to = new int[f.length];
        {
            int[] b = new int[65537];
            for (int i = 0; i < f.length; i++) b[1 + (f[i] & 0xffff)]++;
            for (int i = 1; i <= 65536; i++) b[i] += b[i - 1];
            for (int i = 0; i < f.length; i++) to[b[f[i] & 0xffff]++] = f[i];
            int[] d = f;
            f = to;
            to = d;
        }
        {
            int[] b = new int[65537];
            for (int i = 0; i < f.length; i++) b[1 + (f[i] >>> 16)]++;
            for (int i = 1; i <= 65536; i++) b[i] += b[i - 1];
            for (int i = 0; i < f.length; i++) to[b[f[i] >>> 16]++] = f[i];
            int[] d = f;
            f = to;
            to = d;
        }
        return f;
    }
    public static long []primeFactor(int n){
        long []prime=new long[n+1];
        prime[1]=1;
        for (int i=2;i<=n;i++)
            prime[i]=((i&1)==0)?2:i;
        for (int i=3;i*i<=n;i++){
            if (prime[i]==i){
                for (int j=i*i;j<=n;j+=i){
                    if (prime[j]==j)
                        prime[j]=i;
                }
            }
        }
        return prime;
    }
    public static StringBuilder id5(long number){
        StringBuilder builder=new StringBuilder();
        long remainder;
        while (number!=0) {
            remainder = number % 2;
            number >>= 1;
            builder.append(remainder);
        }
        builder.reverse();
        return builder;
    }
    public static int binarySearch(long[] a, int index,long target) {
            int l = index;
            int h = a.length - 1;
            while (l<=h) {
                int med = l + (h-l)/2;
                if(a[med] - target <= target) {
                    l = med + 1;
                }
                else h = med  - 1;
            }
            return h;
    }
    public static int val(char c){
        return c-'0';
    }
    public static long gcd(long a,long b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
        private static class Pair implements Comparable<Pair> {
            long x;
            long y;

            Pair() {
                this.x = 0;
                this.y = 0;
            }

            Pair(long x, long y) {
                this.x = x;
                this.y = y;
            }

            @Override
            public boolean equals(Object obj) {
                if (this == obj) {
                    return true;
                }
                if (obj == null) return false;
                Pair other = (Pair) obj;
                if (this.x == other.x && this.y == other.y) {
                    return true;
                }
                return false;
            }

            @Override
            public int compareTo(Pair other) {
                if (this.x != other.x) return Long.compare(this.x, other.x);
                return Long.compare(this.y*other.x, this.x*other.y);
            }
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pr = new Printer(System.out);
        solve();

        pr.close();
       

    }
    private static class Scanner {
        BufferedReader br;

        Scanner (InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        private boolean isPrintable(int ch) {
            return ch >= '!' && ch <= '~';
        }

        private boolean id3(int ch) {
            return ch == '\n' || ch == '\r' || ch == -1;
        }

        private int nextPrintable() {
            try {
                int ch;
                while (!isPrintable(ch = br.read())) {
                    if (ch == -1) {
                        throw new NoSuchElementException();
                    }
                }

                return ch;
            } catch (IOException e) {
                throw new NoSuchElementException();
            }
        }

        String next() {
            try {
                int ch = nextPrintable();
                StringBuilder sb = new StringBuilder();
                do {
                    sb.appendCodePoint(ch);
                } while (isPrintable(ch = br.read()));

                return sb.toString();
            } catch (IOException e) {
                throw new NoSuchElementException();
            }
        }

        int nextInt() {
            try {
                

                boolean negative = false;
                int res = 0;
                int limit = -Integer.MAX_VALUE;
                int radix = 10;

                int fc = nextPrintable();
                if (fc < '0') {
                    if (fc == '-') {
                        negative = true;
                        limit = Integer.MIN_VALUE;
                    } else if (fc != '+') {
                        throw new NumberFormatException();
                    }
                    fc = br.read();
                }
                int multmin = limit / radix;

                int ch = fc;
                do {
                    int digit = ch - '0';
                    if (digit < 0 || digit >= radix) {
                        throw new NumberFormatException();
                    }
                    if (res < multmin) {
                        throw new NumberFormatException();
                    }
                    res *= radix;
                    if (res < limit + digit) {
                        throw new NumberFormatException();
                    }
                    res -= digit;

                } while (isPrintable(ch = br.read()));

                return negative ? res : -res;
            } catch (IOException e) {
                throw new NoSuchElementException();
            }
        }

        long nextLong() {
            try {
                

                boolean negative = false;
                long res = 0;
                long limit = -Long.MAX_VALUE;
                int radix = 10;

                int fc = nextPrintable();
                if (fc < '0') {
                    if (fc == '-') {
                        negative = true;
                        limit = Long.MIN_VALUE;
                    } else if (fc != '+') {
                        throw new NumberFormatException();
                    }
                    fc = br.read();
                }
                long multmin = limit / radix;

                int ch = fc;
                do {
                    int digit = ch - '0';
                    if (digit < 0 || digit >= radix) {
                        throw new NumberFormatException();
                    }
                    if (res < multmin) {
                        throw new NumberFormatException();
                    }
                    res *= radix;
                    if (res < limit + digit) {
                        throw new NumberFormatException();
                    }
                    res -= digit;

                } while (isPrintable(ch = br.read()));

                return negative ? res : -res;
            } catch (IOException e) {
                throw new NoSuchElementException();
            }
        }

        float nextFloat() {
            return Float.parseFloat(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            try {
                int ch;
                while (id3(ch = br.read())) {
                    if (ch == -1) {
                        throw new NoSuchElementException();
                    }
                }
                StringBuilder sb = new StringBuilder();
                do {
                    sb.appendCodePoint(ch);
                } while (!id3(ch = br.read()));

                return sb.toString();
            } catch (IOException e) {
                throw new NoSuchElementException();
            }
        }

        void close() {
            try {
                br.close();
            } catch (IOException e) {


            }
        }
    }
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }

    static class List {
        String Word;
        int length;

        List(String Word, int length) {
            this.Word = Word;
            this.length = length;
        }
    }
    private static class Printer extends PrintWriter {
        Printer(PrintStream out) {
            super(out);
        }
    }
}