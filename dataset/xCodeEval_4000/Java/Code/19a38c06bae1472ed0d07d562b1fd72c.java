
import com.sun.scenario.effect.impl.sw.sse.SSEBlend_SRC_OUTPeer;
import org.omg.CORBA.INTERNAL;

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
    static boolean checkBip=true;
    static TreeSet<Integer>[]list;
    private static long aLong=(long)(Math.pow(10,9)+7);
    static final long div=998244353;
    static  int answer=0;
    static int[]countSubTree;
    static int[]colorNode;
    static boolean con=true;
    static ArrayList<Integer>dfsPath=new ArrayList<>();
    static ArrayList<Integer>ans=new ArrayList<>();
    static boolean[]rec;
    static int min=Integer.MAX_VALUE;
    static ArrayList<Task>tasks=new ArrayList<>();
    static  boolean []checkpath;
    static TreeSet<Long>cm=new TreeSet<>();
    static  long cnt=0;
    private static void solve() throws IOException {
        int n=sc.nextInt(),m=sc.nextInt();
        char[][]in=new char[n][m];
        int [][]size=new int[n][m];
        ArrayList<pp>pps=new ArrayList<>();
        ArrayList<pp>ppe=new ArrayList<>();
        ArrayList<pp>[]adj=new ArrayList[1000];
        for (int i=0;i<1000;++i)adj[i]=new ArrayList<>();
        for (int i=0;i<n;++i){
            String s=sc.next();
            for (int j=0;j<m;++j) {
                in[i][j]=s.charAt(j);
                if (in[i][j]=='*') pps.add(new pp(i,j));
                else ppe.add(new pp(i,j));
            }
        }
        boolean [][]vis=new boolean[n][m];
        int [][]grid=new int[n][m];
        TreeMap<Integer,Integer>map=new TreeMap<>();
        Queue<pp>queue=new ArrayDeque<>();
        StringBuilder builder=new StringBuilder();
        int cc=1;
        for (pp p:ppe){
            if (!vis[p.x][p.y]) {
                vis[p.x][p.y] = true;
                grid[p.x][p.y]=cc;
                queue.add(p);
                int len=1;
                while (!queue.isEmpty()) {
                    pp p1 = queue.remove();
                    if (p1.x - 1 >= 0 && !vis[p1.x - 1][p1.y] && in[p1.x - 1][p1.y] == '.') {
                        

                        queue.add(new pp(p1.x - 1, p1.y));
                        grid[p1.x-1][p1.y]=cc;
                        ++len;
                        vis[p1.x - 1][p1.y] = true;
                    }
                    if (p1.x + 1 < n && !vis[p1.x + 1][p1.y] && in[p1.x + 1][p1.y] == '.') {
                        

                        queue.add(new pp(p1.x + 1, p1.y));
                        grid[p1.x+1][p1.y]=cc;
                        ++len;
                        vis[p1.x + 1][p1.y] = true;
                    }
                    if (p1.y + 1 < m && !vis[p1.x][p1.y + 1] && in[p1.x][p1.y + 1] == '.') {
                        

                        queue.add(new pp(p1.x, p1.y + 1));
                        grid[p1.x][p1.y+1]=cc;
                        ++len;
                        vis[p1.x][p1.y + 1] = true;
                    }
                    if (p1.y - 1 >= 0 && !vis[p1.x][p1.y - 1] && in[p1.x][p1.y - 1] == '.') {
                        

                        queue.add(new pp(p1.x, p1.y - 1));
                        grid[p1.x][p1.y-1]=cc;
                        ++len;
                        vis[p1.x][p1.y - 1] = true;
                    }
                    

                    

                    

                    

                    

                }
                map.put(cc,len);
                ++cc;
            }
            

        }
        

        

        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                if (in[i][j]=='*'){
                    int cmp=1;
                    TreeSet<Integer>set=new TreeSet<>();
                    if (i+1<n&&grid[i+1][j]>0&&!set.contains(grid[i+1][j])){
                        set.add(grid[i+1][j]);
                        cmp+=(map.get(grid[i+1][j]));
                    }if (i-1>=0&&grid[i-1][j]>0&&!set.contains(grid[i-1][j])){
                        set.add(grid[i-1][j]);
                        cmp+=(map.get(grid[i-1][j]));
                    }if (j+1<m&&grid[i][j+1]>0&&!set.contains(grid[i][j+1])){
                        set.add(grid[i][j+1]);
                        cmp+=(map.get(grid[i][j+1]));
                    }if (j-1>=0&&grid[i][j-1]>0&&!set.contains(grid[i][j-1])){
                        set.add(grid[i][j-1]);
                        cmp+=(map.get(grid[i][j-1]));
                    }
                    builder.append(cmp%10);
                }else builder.append(".");
            }
            builder.append("\n");
        }
        pr.println(builder);
    }
    public static class pp{
        int x,y;
        public pp(int x, int y) {
            this.x = x;
            this.y = y;
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
                    sum[v]+=sum[u];
                }
                else if (rank[u]==rank[v]){
                    parent[u]=v;
                    sum[v]+=sum[u];
                }
                else{
                    parent[v]=u;
                    sum[u]+=sum[v];
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
        countSubTree[src]=1;
        if (src==x) {
            checkpath[src]=true;
            

        }
        else checkpath[src]=false;
        for (int v:list[src]){
            if (v==parent)
                continue;
            subTree(v,src,x);
            countSubTree[src]+=countSubTree[v];
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
    public static void bfsColor(int src){
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
    public static int isBipartite(ArrayList<Integer>[]list,int src){
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
    public static int[] radixSort(int[] f) {
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
    public static StringBuilder binaryradix(long number){
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

        private boolean isCRLF(int ch) {
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
                while (isCRLF(ch = br.read())) {
                    if (ch == -1) {
                        throw new NoSuchElementException();
                    }
                }
                StringBuilder sb = new StringBuilder();
                do {
                    sb.appendCodePoint(ch);
                } while (!isCRLF(ch = br.read()));

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