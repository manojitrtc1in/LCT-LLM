import java.io.*;
import java.math.*;
import java.security.KeyStore.Entry;
import java.util.*;

public class yash {
    private static InputStream stream;
    private static byte[] buf = new byte[1024];
    private static int curChar;
    private static int numChars;
    private static SpaceCharFilter filter;
    private static PrintWriter pw;
    private static long mod = 1000000000 + 7;
    private static long mod1 = 1000000000 + 9;
    private static int MAX=1000001;
    private static int block;
    private static long[] suma;
    private static long[] cost;
    private static int times;
    private static int n,k;
    private static int max=51;
    private static boolean[] vis;
    private static boolean[] vis2;
    private static long[] sa;
    private static long count;
    private static boolean ff;
    private static ArrayList<Integer>[] ggc;
    

    public static void soln()
    {
    	int n=ni();
    	String[] ss=new String[n];
    	for(int i=0;i<n;i++)
    		ss[i]=nli();
    	int[] arr=new int[n];
    	

    	for(int i=0;i<n;i++)
    	{
    		String s=ss[i];
    		Stack<Integer> st=new Stack<>();
    		for(int j=0;j<s.length();j++)
    		{
    			int a=(s.charAt(j)=='(')?1:-1;
    			if(st.isEmpty())
    				st.push(a);
    			else if(st.peek()==1 && a==-1)
    				st.pop();
    			else
    				st.push(a);
    		}
    		if(!st.isEmpty())
    		{
	    		int c=st.peek();boolean flag=false;
	    		for(int j=0;j<st.size();j++)
	    		{
	    			if(st.get(j)!=c)	flag=true;
	    		}
	    		if(!flag && c==1)
	    			arr[i]=st.size();
	    		else if(!flag && c==-1)
	    			arr[i]=-st.size();
	    		else
	    			arr[i]=Integer.MAX_VALUE;
    		}
    		else
    			arr[i]=0;
    	}
    	HashMap<Integer,Integer> map=new HashMap<>();
    	for(int i=0;i<n;i++)
    	{
    		if(arr[i]!=Integer.MAX_VALUE)
    		{
    			if(!map.containsKey(arr[i]))
    			map.put(arr[i], 0);
    			map.put(arr[i],map.get(arr[i])+1);
    		}
    	}
    	long ans=0;
    	HashSet<Integer> set=new HashSet<>();
    	for(int i=0;i<n;i++)
    	{
    		if(arr[i]>0 && arr[i]!=Integer.MAX_VALUE)	set.add(arr[i]);
    	}
    	Iterator<Integer> it=set.iterator();
    	while(it.hasNext())
    	{
    		int o=it.next();
    		int p=map.get(o);int q=0;
    		if(map.containsKey(-o))
    			q=map.get(-o);
    		ans+=(Math.min(p, q));
    	}
    	int x=0;
    	if(map.containsKey(0))	x=(map.get(0))/2;
    	

    	pw.println(ans+x);
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
           		cost[v]+=(cost[arr.get(i)]);
           		ggc[v].add((int)cost[arr.get(i)]);
            }
        }
    }
    public static class lca{
    	int[] e;
    	int[] l;
    	int[] h;
    	int[] level;
    	boolean[] vis;
    	int time;
    	int[] tree=new int[10000000];
        int[] lazy=new int[10000000];
        int n;
    	public lca(ArrayList<Integer>[] g)
    	{
    		n=g.length-1;
    		pw.println(n);
    		e=new int[2*n];
    		l=new int[2*n];
    		h=new int[n+1];
    		vis=new boolean[n+1];
    		level=new int[n+1];
    		level[1]=0;
    		dfs(g,1);
    		Arrays.fill(lazy, 0);
    		build(l,0,0,2*n-1);
    	}
    	public int lf(int u,int v)
    	{
    		int a=h[u];int b=h[v];
    		if(h[u]>h[v])
    			{a=h[v];b=h[u];}
    		int p=query(l,0,0,2*n-1,a,b);
    		return e[p];
    	}
    	public void dfs(ArrayList<Integer>[] gr,int v)
        {
             vis[v]=true;
             time++;
             e[time]=v;
             l[time]=level[v];
             h[v]=time;
             ArrayList<Integer> arr=gr[v];
             for(int i=0;i<arr.size();i++)
             {
                 if(!vis[arr.get(i)])
                 {
                	 level[arr.get(i)]=level[v]+1;
                	 dfs(gr,arr.get(i));
                	 time++;e[time]=v;l[time]=level[v];
                 }
             }
         }
    	 public void build(int[] arr,int node,int l,int r)
         {
             if(l==r)
             {
                 tree[node]=l;
             }
             else
             {
                 int m=(l+r)/2;
                 build(arr,(2*node)+1,l,m);
                 build(arr,(2*node)+2,m+1,r);
                 if(arr[tree[2*node+1]]<arr[tree[2*node+2]])
                	 tree[node]=tree[2*node+1];
                 else
                	 tree[node]=tree[2*node+2];
             }
         }
    	 public int query(int[] arr,int node,int l,int r,int s,int e)
         {
             if(e<l || r<s)
                 return -1;
             if(s<=l && e>=r)
                 return tree[node];
             int m=(l+r)/2;
             int p1=query(arr,(2*node+1),l,m,s,e);
             int p2=query(arr,(2*node+2),m+1,r,s,e);
             if(p1==-1)
            	 return p2;
             else if(p2==-1)
            	 return p1;
             else
             {
            	 if(arr[p1]<arr[p2])
            		 return p1;
            	 else
            		 return p2;
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
    private static class graph{
        public static void arti(boolean[] ap,int[] parent,int[] disc,int[] low,ArrayList<Integer>[] gr,boolean[] vis,int ver)
        {
            int child=0;
            vis[ver]=true;
            ArrayList<Integer> arr=gr[ver];
            times++;
            disc[ver]=low[ver]=times;
            for(int i=0;i<arr.size();i++)
            {
                if(!vis[arr.get(i)])
                {
                    child++;
                    parent[arr.get(i)]=ver;
                    arti(ap,parent,disc,low,gr,vis,arr.get(i));
                    low[ver]=Math.min(low[ver], low[arr.get(i)]);
                    if(parent[ver]!=0 && low[arr.get(i)]>=disc[ver])
                        ap[ver]=true;
                    if(parent[ver]==0 && child>1)
                        ap[ver]=true;
                }
                else if(parent[ver]!=arr.get(i))
                    low[ver]=Math.min(low[ver], disc[arr.get(i)]);
            }
        }
        public static void floyd(Pair[] arr,int n,int m,int[][] dist)
        {
            for(int i=0;i<=n;i++)
            {
                Arrays.fill(dist[i], Integer.MAX_VALUE);
            }
            for(int c=0;c<m;c++)
            {
                int w=arr[c].v;
                int a=arr[c].j.v;
                int b=arr[c].j.i;
                dist[a][b]=w;
            }
            for(int i=0;i<=n;i++)
                dist[i][i]=0;
            for(int k=1;k<=n;k++)
            {
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(dist[i][k]!=Integer.MAX_VALUE && dist[k][j]!=Integer.MAX_VALUE)
                        dist[i][j]=Math.min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        public static boolean bfs(ArrayList<Integer>[] gr,int v,int n)
        {
            
            boolean[] vis=new boolean[n+1];
            int c2=0;
            Queue<Integer> q=new LinkedList<>();
            q.add(v);
            while(!q.isEmpty())
            {
                int x=q.poll();
                Iterator<Integer> it=gr[x].iterator();
                while(it.hasNext())
                {
                    int p=it.next();
                    if(!vis[p])
                    {
                        q.add(p);
                        c2++;
                        vis[p]=true;
                    }
                }
            }
            return c2==n;
        }
        public static ArrayList<Pair> MSTP(int n,int m,ArrayList<Pair>[] arr,int[][] arr2)
        {
            ArrayList<Pair> pp=new ArrayList<>();
            int[] par=new int[n+1];
            int[] key=new int[n+1];
            vis=new boolean[n+1];
            Arrays.fill(key, Integer.MAX_VALUE);
            key[1]=0;
            PriorityQueue<Integer> dis=new PriorityQueue<>(n+1,
                    new Comparator<Integer>()
                    {
                        public int compare(Integer p,Integer q)
                        {
                        return key[p]-key[q];
                        }
                    }
                    );
            dis.add(1);
            vis[1]=true;
            while(!dis.isEmpty())
            {
                

                int u=dis.poll();
                    ArrayList<Pair> p=arr[u];
                    for(int i=0;i<p.size();i++)
                    {
                        if(key[u]+p.get(i).i<key[p.get(i).v])
                        {
                            key[p.get(i).v]=key[u]+p.get(i).i;
                            par[p.get(i).v]=u;
                            if(!vis[p.get(i).v])
                            {
                                dis.add(p.get(i).v);
                                vis[p.get(i).v]=true;
                            }
                        }
                    }
            }
            for(int i=1;i<=n;i++)
                pp.add(new Pair(i,par[i]));
            return pp;
        }
        public static ArrayList<Pair> MSTK(int n,int m,Pair[] arr)
        {
            ArrayList<Pair> pp=new ArrayList<>();
            long sum=0;
            Arrays.sort(arr);
            DSU x=new DSU(n+1);
            for(int c=0;(c<m);c++)
            {
                Pair p=arr[c];
                

                

                int a=p.j.v;
                int b=p.j.i;
                int w=p.v;
                if(x.find(a)!=x.find(b))
                {
                    pp.add(new Pair(w,new Pair(a,b)));
                    x.Union(a, b);
                }
            }
            return pp;
        }
        public static int[] dijkstras(ArrayList<Pair>[] gr)
        {
            int n=gr.length-1;
            int[] dist=new int[n+1];
            Arrays.fill(dist, Integer.MAX_VALUE);
            
            PriorityQueue<Integer> dis=new PriorityQueue<>(n+1,
                    new Comparator<Integer>()
                    {
                        public int compare(Integer p,Integer q)
                        {
                        return dist[p]-dist[q];
                        }
                    }
                    );
            boolean[] vis=new boolean[n+1];
            Arrays.fill(vis, false);
            
            int s=1;
            dist[s]=0;
            dis.add(s);
            vis[s]=true;
            while(!dis.isEmpty())
            {
                int p=dis.poll();
                for(int i=0;i<gr[p].size();i++)
                {
                    int y=gr[p].get(i).v;
                    int w=gr[p].get(i).i;
                    if(!vis[y])
                    {
                        dist[y]=dist[p]+w;
                        dis.add(y);
                        vis[y]=true;
                    }
                    else
                    {
                        if(dist[p]+w<dist[y])
                        {
                            dist[y]=dist[p]+w;
                        }
                    }
                }
            }
            return dist;
        }
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
    public static class segtree{ 
        static int[] tree=new int[10000000];
        static int[] lazy=new int[10000000];
        public static void initial()
        {
            Arrays.fill(lazy, 0);
        }
        public static void build(int[] arr,int node,int l,int r)
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
                tree[node]=tree[2*node+1]+tree[(2*node)+2];
            }
        }
        public static void updater(int[] arr,int node,int l,int r,int s,int e,int val)
        {
            if(lazy[node]!=0)
            {
                tree[node]+=(r-l+1)*lazy[node];
                if(l!=r)
                {
                    lazy[2*node+1]+=lazy[node];
                    lazy[2*node+2]+=lazy[node];
                }
                lazy[node]=0;
            }
            if(s<=l && e>=r)
            {
                tree[node]+=(r-l+1)*val;
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
                tree[node]=tree[2*node+1]+tree[2*node+2];
            }
        }
        public static void update(int[] arr,int node,int l,int r,int ind,int val)
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
        public static int query(int node,int l,int r,int s,int e)
        {
            if(lazy[node]!=0)
            {
                tree[node]+=(r-l+1)*lazy[node];
                if(l!=r)
                {
                    lazy[2*node+1]+=lazy[node];
                    lazy[2*node+2]+=lazy[node];
                }
                lazy[node]=0;
            }
            if(e<l || r<s)
                return 0;
            if(s<=l && e>=r)
                return tree[node];
            int m=(l+r)/2;
            int p1=query((2*node+1),l,m,s,e);
            int p2=query((2*node+2),m+1,r,s,e);
            return (p1+p2);
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

    private static boolean isEndOfLine(int c) {
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
        while (isSpaceChar(c))
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
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    private static long nl() {
        int c = read();
        while (isSpaceChar(c))
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
        } while (!isSpaceChar(c));
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
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    private static String nli() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isEndOfLine(c));
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

    private static boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return isWhitespace(c);
    }
    private static char nc() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        char c1=(char)c;
        while(!isSpaceChar(c))
            c=read();
        return c1;
    }
    public String ns() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }
    private interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}