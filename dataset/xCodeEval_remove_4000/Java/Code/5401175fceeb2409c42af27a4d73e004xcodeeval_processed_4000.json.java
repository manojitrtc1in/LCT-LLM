import java.io.*;
import java.math.*;
import java.security.KeyStore.Entry;
import java.util.*;

public class Main {
    private static InputStream stream;
    private static byte[] buf = new byte[1024];
    private static int curChar;
    private static int numChars;
    private static id3 filter;
    private static PrintWriter pw;
    private static long mod = 1000000000 + 7;
    private static long mod1 = 1000000000 + 9;
    private static int MAX=1000001;
    private static int block;
   

    private static long[] cost;
    private static long[] costm;
    private static int times;
    private static long ans;
    private static long max;
    private static boolean[] vis;
    private static long[] sa;
    private static long count;
    private static boolean ff;
    private static int odd;
    private static int even;
    private static ArrayList<Integer> ansa;
    private static boolean[] dp;
    private static long[][] dp2;
    private static int n;
    private static ArrayList<Integer>[] g;
    private static int[] ci;
    private static int[] par;
    private static int[] subs;
    private static int[] colors;
    private static int[] mindist;
    private static int[][] dist;
    private static int time;
    private static int[] di;
    private static int[] en;
    private static int[] level;
    private static boolean flag;
    public static void soln()
    {			
    	int n=ni();
    	g=new ArrayList[n+1];
    	ci=new int[n+1];int root=-1;
    	for(int i=0;i<=n;i++)	g[i]=new ArrayList<>();
    	int[] res=new int[n+1];Arrays.fill(res, 0);
    	for(int i=1;i<=n;i++)
    	{
    		int pi=ni();int c=ni();
    		if(pi==-1)
    		{
    			if(c==0)	{res[i]=1;}
    		}
    		else if(c==0)	{res[i]=1;res[pi]+=res[i];}
    	}
    	boolean f=false;
    	for(int i=1;i<=n;i++)
    	{
    		if(res[i]==0)	{p(i);f=true;}
    	}
    	if(!f)
    		p(-1);
    }
    public static void dfs(ArrayList<Integer>[] gr,int v)
    {
         vis[v]=true;
         ArrayList<Integer> arr=gr[v];
         for(int i=0;i<arr.size();i++)
         {
             if(!vis[arr.get(i)])
             {       	 
            	 dfs(gr,arr.get(i));
            	 if(gr[arr.get(i)].size()==0 && ci[arr.get(i)]==0)	dp[arr.get(i)]=false;	
            	 if(ci[v]==0 || ci[arr.get(i)]==0)	dp[v]=false;	
             }
         }
    }
    public static void dfsp(ArrayList<Pair>[] gr,int v,int[] a)
    {
        vis[v]=true;
        ArrayList<Pair> arr=gr[v];
        for(int i=0;i<arr.size();i++)
        {
            if(!vis[arr.get(i).v])
            {
            		dfsp(gr,arr.get(i).v,a);
           	}
        }
    }
    
    public static long[] reverse(long[] arr, int l, int r)
      {
          int d = (r-l+1)/2;
          for(int i=0;i<d;i++)
          {
             long t = arr[l+i];
             arr[l+i] = arr[r-i];
             arr[r-i] = t;
          }
          return arr;
      }
    
    public static class sieve{
        public static ArrayList<Integer> sieves(int n)
        {
            ArrayList<Integer> arr=new ArrayList<>();
            boolean[] bol=new boolean[n+1];
            Arrays.fill(bol, true);
            

            for(int i=2;i<=n;i++)
            {
                if(bol[i])
                {
                    arr.add(i);
                    for(int j=2;j*i<=n;j++)
                    {
                        bol[i*j]=false;
                    }
                }
            }
            return arr;
        }
    }
    public static class isprime{
        public static boolean check(int n)
        {
            if(n==2)
                return true;
            else if(n==3)
                return true;
            else if(n%2==0)
                return false;
            else if(n%3==0)
                return false;
            else
            {
                for(int i=6;;i+=6)
                {
                    if(i>Math.sqrt(n))
                        break;
                    if(n%(i-1)==0)
                    {
                        return false;
                    }
                    else if(n%(i+1)==0)
                        return false;
                                    }
                return true;
            }
        }
    }
    private static class DSU{
        int[] parent;
        int[] rank;
        int cnt;
        public DSU(int n){
            parent=new int[n];
            rank=new int[n];
            for(int i=0;i<n;i++){
                parent[i]=i;
                rank[i]=1;
            }
            cnt=n;
        }
        int find(int i){
            while(parent[i] !=i){
                parent[i]=parent[parent[i]];
                i=parent[i];
            }
            return i;
        }
        int Union(int x, int y){
            int xset = find(x);
            int yset = find(y);
            if(xset!=yset)
                cnt--;
            if(rank[xset]<rank[yset]){
                parent[xset] = yset;
                rank[yset]+=rank[xset];
                rank[xset]=0;
                return yset;
            }else{
                parent[yset]=xset;
                rank[xset]+=rank[yset];
                rank[yset]=0;
                return xset;
            }
        }
    }
    private static class Pair implements Comparable<Pair>{
        int v,i;Pair j;
        public Pair(int a,int b){
            v=a;
            i=b;
        }
        public Pair(int a,Pair b)
        {
            v=a;
            j=b;
        }
        @Override
        public int compareTo(Pair arg0) {
            {
            	return this.v-arg0.v;
            }
        }
    }
    private static class Pairl implements Comparable<Pairl>{
        long v,i;Pairl j;
        public Pairl(long a,long b){
            v=a;
            i=b;
        }
        public Pairl(long a,Pairl b)
        {
            v=a;
            j=b;
        }
        @Override
        public int compareTo(Pairl arg0) {
            {
                if(this.v>arg0.v)
                    return 1;
                else
                    return -1;
            }
        }
    }
    public static long f(long number,long m) {
          if (number <= 1) return 1;
          else return (number * f(number - 1,m))%m;
       }
    public static long mmi(long a, long m) 
    { 
        long m0 = m; 
        long y = 0, x = 1; 
      
        if (m == 1) 
          return 0; 
      
        while (a > 1) 
        { 
            

            long q = a / m; 
            long t = m; 
      
            

            

            m = a % m; a = t; 
            t = y; 
      
            

            y = x - q * y; 
            x = t; 
        } 
      
        

        if (x < 0) 
           x += m0; 
      
        return x; 
    } 
    public static class id2{ 
    	int ll=100000;
        int[] tree=new int[ll+1];
        int[] lazy=new int[ll+1];
        public id2()
        {
            Arrays.fill(lazy, 0);
        }
        public void build(int[] arr,int node,int l,int r)
        {
            if(l==r)
            {
                tree[node]=arr[l];
            }
            else
            {
                int m=(l+r)/2;
                build(arr,(2*node)+1,l,m);
                build(arr,(2*node)+2,m+1,r);
                tree[node]=Math.max(tree[2*node+1],tree[(2*node)+2]);
            }
        }
        public void updater(int[] arr,int node,int l,int r,int s,int e,int val)
        {
            if(lazy[node]!=0)
            {
                tree[node]+=lazy[node];
            }
            if(s<=l && e>=r)
            {
                tree[node]+=val;
                if(l!=r)
                {
                    lazy[2*node+1]+=val;
                    lazy[2*node+2]+=val;
                }
            }
            else if(!(e<l || r<s))
            {
                int m=(l+r)/2;
                updater(arr,2*node+1,l,m,s,e,val);
                updater(arr,2*node+2,m+1,r,s,e,val);
                tree[node]=Math.max(tree[2*node+1],tree[2*node+2]);
            }
        }
        public void update(int[] arr,int node,int l,int r,int ind,int val)
        {
            if(l==r)
            {
                arr[ind]+=val;
                tree[node]+=val;
            }
            else
            {
                int m=(l+r)/2;
                if(l<=ind && ind<=m)
                {
                    update(arr,(2*node+1),l,m,ind,val);
                }
                else
                {
                    update(arr,(2*node+2),m+1,r,ind,val);
                }
                tree[node]=tree[2*node+1]+tree[2*node+2];
            }
        }
        public int query(int node,int l,int r,int s,int e)
        {
            if(lazy[node]!=0)
            {
                tree[node]+=lazy[node];
            }
            if(e<l || r<s)
                return 0;
            if(s<=l && e>=r)
                return tree[node];
            int m=(l+r)/2;
            int p1=query((2*node+1),l,m,s,e);
            int p2=query((2*node+2),m+1,r,s,e);
            return Math.max(p1, p2);
        }
    }
    private static long pow(long a, long b, long c) {
        if (b == 0)
            return 1;
        long p = pow(a, b / 2, c);
        p = (p * p) % c;
        return (b % 2 == 0) ? p : (a * p) % c;
    }
    private static long gcd(long n, long l) {
        if (l == 0)
            return n;
        return gcd(l, n % l);
    }
    private static int gcd(int n, int l) {
        if (l == 0)
            return n;
        return gcd(l, n % l);
    }
    private static long max(long a, long b) {
        if (a > b)
            return a;
        return b;
    }
    private static long min(long a, long b) {
        if (a < b)
            return a;
        return b;
    }
    public static void merge(int arr[], int l, int m, int r) 
    { 
        

        int n1 = m - l + 1; 
        int n2 = r - m; 
  
        
        int L[] = new int [n1]; 
        int R[] = new int [n2]; 
  
        
        for (int i=0; i<n1; ++i) 
            L[i] = arr[l + i]; 
        for (int j=0; j<n2; ++j) 
            R[j] = arr[m + 1+ j]; 
  
  
        
  
        

        int i = 0, j = 0; 
  
        

        int k = l; 
        while (i < n1 && j < n2) 
        { 
            if (L[i] <= R[j]) 
            { 
                arr[k] = L[i]; 
                i++; 
            } 
            else
            { 
                arr[k] = R[j]; 
                j++; 
            } 
            k++; 
        } 
  
        
        while (i < n1) 
        { 
            arr[k] = L[i]; 
            i++; 
            k++; 
        } 
  
        
        while (j < n2) 
        { 
            arr[k] = R[j]; 
            j++; 
            k++; 
        } 
    } 
    public static void merge(long arr[], int l, int m, int r) 
    { 
        

        int n1 = m - l + 1; 
        int n2 = r - m; 
  
        
        long L[] = new long [n1]; 
        long R[] = new long [n2]; 
  
        
        for (int i=0; i<n1; ++i) 
            L[i] = arr[l + i]; 
        for (int j=0; j<n2; ++j) 
            R[j] = arr[m + 1+ j]; 
  
  
        
  
        

        int i = 0, j = 0; 
  
        

        int k = l; 
        while (i < n1 && j < n2) 
        { 
            if (L[i] <= R[j]) 
            { 
                arr[k] = L[i]; 
                i++; 
            } 
            else
            { 
                arr[k] = R[j]; 
                j++; 
            } 
            k++; 
        } 
  
        
        while (i < n1) 
        { 
            arr[k] = L[i]; 
            i++; 
            k++; 
        } 
  
        
        while (j < n2) 
        { 
            arr[k] = R[j]; 
            j++; 
            k++; 
        } 
    } 
    public static void sort(long arr[])
    {
    	sort(arr,0,arr.length-1);
    }
    public static void sort(int arr[])
    {
    	sort(arr,0,arr.length-1);
    }
    public static void sort(int arr[], int l, int r) 
    { 
        if (l < r) 
        { 
            

            int m = (l+r)/2; 
  
            

            sort(arr, l, m); 
            sort(arr , m+1, r); 
  
            

            merge(arr, l, m, r); 
        } 
    } 
    public static void sort(long arr[], int l, int r) 
    { 
        if (l < r) 
        { 
            

            int m = (l+r)/2; 
  
            

            sort(arr, l, m); 
            sort(arr , m+1, r); 
  
            

            merge(arr, l, m, r); 
        } 
    } 
    public static void main(String[] args) throws Exception {
        new Thread(null,new Runnable(){
            @Override
            public void run() {
            	
                InputReader(System.in);
                pw = new PrintWriter(System.out);
               
                soln(); 
                pw.close();
            }
        },"1",1<<26).start();
    }

    public static void InputReader(InputStream stream1) {
        stream = stream1;
    }

    private static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private static boolean id1(int c) {
        return c == '\n' || c == '\r' || c == -1;
    }

    private static int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    private static int ni() {
        int c = read();
        while (id0(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!id0(c));
        return res * sgn;
    }

    private static long nl() {
        int c = read();
        while (id0(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!id0(c));
        return res * sgn;
    }
    private static double nd()
    {
        double ret = 0, div = 1;
        int c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();

        do {
            ret = ret * 10 + c - '0';
        }
        while ((c = read()) >= '0' && c <= '9');

        if (c == '.')
        {
            while ((c = read()) >= '0' && c <= '9')
            {
                ret += (c - '0') / (div *= 10);
            }
        }

        if (neg)
            return -ret;
        return ret;
    }
    private static String nextToken() {
        int c = read();
        while (id0(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!id0(c));
        return res.toString();
    }

    private static String nli() {
        int c = read();
        while (id0(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!id1(c));
        return res.toString();
    }
    
    private static int[] nia(int n) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = ni();
        }
        return arr;
    }

    private static long[] nla(int n) {
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nl();
        }
        return arr;
    }

    private static void pa(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            pw.print(arr[i] + " ");
        }
        pw.println();
        return;
    }

    private static void pa(long[] arr) {
        for (int i = 0; i < arr.length; i++) {
            pw.print(arr[i] + " ");
        }
        pw.println();
        return;
    }
    private static void pl(int a)
    {
    	pw.println(a);
    }
    private static void pl(long a)
    {
    	pw.println(a);
    }
    private static void p(int a)
    {
    	pw.print(a+" ");
    }
    private static void p(long a)
    {
    	pw.print(a+" ");
    }
    private static boolean id0(int c) {
        if (filter != null)
            return filter.id0(c);
        return isWhitespace(c);
    }
    private static char nc() {
        int c = read();
        while (id0(c))
            c = read();
        char c1=(char)c;
        while(!id0(c))
            c=read();
        return c1;
    }
    public String ns() {
        int c = read();
        while (id0(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!id0(c));
        return res.toString();
    }
    private interface id3 {
        public boolean id0(int ch);
    }
}