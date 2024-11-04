

import java.io.*;
import java.util.*;
import java.util.Map.Entry;
import java.text.*;
import java.math.*;
import java.util.regex.*;


public class  id3{
   public  static long[] BIT;
   public  static int[] tree,lazy;
   public  static long[] S,a;
   public  static long[] sum;
   public  static long mod=1000000007;
   public  static int[][] dp;
   public  static boolean[][] id6;
   public  static int max1=500005;
   public  static int max2=5000005;
   public   static int[][] g;
   public  static LinkedList<Pair> l[];
   public  static int n,m,q,k,t,c,x,y,di,dj,val[],f[],b[],d=0;
   public  static ArrayList<Long>al[];
   public  static TreeSet<Integer> ts;
   public  static   char[] s;
   public  static int depth,mini,maxi,fib[];
   public  static long V[],low,high,phi[],phiSum[],arr[];
   public  static boolean visit[][],isPrime[],used[];
   public  static int[] dist;
   public  static ArrayList<Integer>prime;
   public static ArrayList<ArrayList<Integer>> ans;
   public  static ArrayList<Integer> divisor[]=new ArrayList[1500005];
   public  static  int[][] subtree,parent;
   public  static  TreeMap<Integer,Integer> tm;
   public  static LongPoint[] p;
   public  static boolean[][] grid;
   public  static ArrayList<Pair> adj[];
   public static TrieNode root;
   public static BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
   public  static void main(String[] args) throws Exception
   {
   	   InputReader in = new InputReader(System.in);
	   PrintWriter pw=new PrintWriter(System.out);
       n=in.ii();
       arr=new long[n+1];
       for(int i=1;i<=n;i++)arr[i]=in.il();
       SegmentTree[] st=new SegmentTree[20];
       for(int i=0;i<20;i++)st[i]=new SegmentTree(n,i);
       m=in.ii();
       while(m-->0)
       {
           int ty=in.ii();
           if(ty==1)
           {
               int x=in.ii();
               int y=in.ii();
               long ans=0;
               for(int i=0;i<20;i++)
                ans+=st[i].queryRange(1,1,n,x,y)*(1<<i);
                pw.println(ans);
           }
           else{
               int x=in.ii();
               int y=in.ii();
               int val=in.ii();
               for(int i=0;i<20;i++)
                if(((val>>i)&1)==1)
                  st[i].updateRange(1,1,n,x,y,val);

           }
       }
     pw.close();
   }
   static class SegmentTree{
    long tree[];
    long lazy[];
    int id;
    public SegmentTree(int n,int i) {
        tree = new long[4 * n];
        lazy = new long[4 * n];

        id = i;
        build(1, 1, n);


    }

    void build(int node, int start, int end) {
        if (start == end) {
            

            tree[node] = (arr[start]>>id)&1;
        } else {
            int mid = (start + end) / 2;
            

            build(2 * node, start, mid);
            

            build(2 * node + 1, mid + 1, end);
            

            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        if (lazy[node] != 0) {
            

            tree[node] = (end - start + 1)-tree[node]; 

            if (start != end) {
                lazy[node * 2] ^= lazy[node]; 

                lazy[node * 2 + 1] ^= lazy[node]; 

            }
            lazy[node] = 0; 

        }
        if (start > end || start > r || end < l) 

            return;
        if (start >= l && end <= r) {      

            tree[node] = (end - start + 1)-tree[node];
            if (start != end) {
                

                lazy[node * 2] ^= 1;
                lazy[node * 2 + 1] ^= 1;
            }
            return;
        }
        int mid = (start + end) / 2;
        updateRange(node * 2, start, mid, l, r, val); 

        updateRange(node * 2 + 1, mid + 1, end, l, r, val); 

        tree[node] = tree[node * 2] + tree[node * 2 + 1]; 

    }

    long queryRange(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l)
            return 0; 

        if (lazy[node] != 0) {			
            tree[node] = (end - start + 1)-tree[node]; 

            if (start != end) {
                lazy[node * 2] ^= lazy[node]; 

                lazy[node * 2 + 1] ^= lazy[node]; 

            }
            lazy[node] = 0; 

        }
        if (start >= l && end <= r) 

            return tree[node];
        int mid = (start + end) / 2;
        long p1 = queryRange(node * 2, start, mid, l, r); 

        long p2 = queryRange(node * 2 + 1, mid + 1, end, l, r); 


        return (p1 + p2);
    }

}
   static long fib(int n)
   {
	   long[][] ans={{1,0},{0,1}};
	   long[][] M={{0,1},{1,1}};
	   while(n>0)
	   {
		   if(n%2==1)
			   mul(ans,M);
		   n>>=1;
		   mul(M,M);
	   }
	   return ans[0][1]%mod;
   }
   static void mul(long[][] ans,long[][] M2)
   {
   long[][] L=new long[2][2];
	  for(int i=0;i<2;i++)
	   {
		 for(int j=0;j<2;j++)
		 {
			 for(int k=0;k<2;k++)
			 {
				 L[i][j]=(L[i][j]+(ans[i][k]*M2[k][j])%mod)%mod;
				 
			 }
		 }
		 
	   }
	  for(int i=0;i<2;i++)
	  {
		  for(int j=0;j<2;j++)
			  ans[i][j]=L[i][j];
	  }
	  
	   
   }
   static void dfs(int cur,int par)
   {
   
    for(Pair p:adj[cur])
    {
        if(p.a!=par)
        {
           al[cur].add(p.b*1L);
           dfs(p.a,cur);
           for(long i:al[p.a])al[cur].add(i+p.b);
        }
    } 

   }
  static void precompute()
  {
      phi=new long[max1];
      for(int i=1;i<max1;i++)phi[i]=i;
      phiSum=new long[max1];
      for(int i=2;i<max1;i++)
      {
          if(phi[i]==i)
          {
              phi[i]=i-1;
              for(int j=i+i;j<max1;j+=i)
              {
                  phi[j]-=phi[j]/i;
              }
          }
      }

    for(int i=1;i<max1;i++)
    {
        for(int j=i;j<max1;j+=i)
        {
          phiSum[j]+=i*phi[j/i];
        }
    }

  }
  static class node  implements Comparable<node> {
      int i;
      int val;
   public  node(int i,int val)
      {
          this.i=i;
          this.val=val;
      }
    public int compareTo(node a)
    {
        return Integer.compare(this.val,a.val);
    }

  }
static void update(int indx,long val)
   {
	   while(indx<max2)
	   {
		   BIT[indx]+=val;
		   indx+=(indx&(-indx));
	   }
	   
   }
static long query1(int indx)
   {
	   long sum=0;
	   while(indx>0)
	   {
		   sum+=BIT[indx];
		 

		   indx-=(indx&(-indx));
	   }
	   return sum;
	}
   
   
   public static ListNode id1(ListNode a, int b) {
       
    int cnt=0;
	ListNode ra1=a;
	ListNode ra2=a;
	while(ra1!=null){ra1=ra1.next; cnt++;}
	
	if(b>cnt)return a.next;
	else if(b==1&&cnt==1)return null;
	else{
		int y=cnt-b+1;
		int u=0;
		ListNode prev=null;
		while(a!=null)
		{
			u++;
		   if(u==y)
		   {
			   if(a.next==null)prev.next=null;
			   else
			   {
				   if(prev==null)return ra2.next;
				   prev.next=a.next;
				   a.next=null;
			   }
			   break;
		   }
		   prev=a;
		   a=a.next;
		}
	}
	return ra2;
}
   static ListNode rev(ListNode a)
   {
       ListNode prev=null;
       ListNode cur=a;
       ListNode next=null;
       while(cur!=null)
       {
           next=cur.next;
           cur.next=prev;
           prev=cur;
           cur=next;
       }
       return prev;
   }
  
  static class ListNode {
	     public int val;
	     public ListNode next;
	     ListNode(int x) { val = x; next = null; }
	 }
   static class TrieNode
   {
	   int value;  

	   TrieNode[] arr =  new TrieNode[2];
	   public TrieNode() {
		   value = 0;
		   arr[0] = null;
		   arr[1] = null;
	   }
   }
   static void insert(int id5)
   {
	   TrieNode temp = root;
	   
	   

	   

	   for (int i=31; i>=0; i--)
	   {
		   

		   int val = (id5 & (1<<i)) >=1 ? 1 : 0;
		   
		   

		   if (temp.arr[val] == null)
			   temp.arr[val] = new TrieNode();
		   
		   temp = temp.arr[val];
	   }
	 
	   

	   temp.value = id5;
   }
   
   static int query(int id5)
   {
	   TrieNode temp = root;
	   for (int i=31; i>=0; i--)
	   {
		   

		   int val = (id5 & (1<<i)) >= 1 ? 1 : 0;
	 
		   

		   

		   if (temp.arr[val] != null)
			   temp = temp.arr[val];
	 
		   

		   

		   else if (temp.arr[1-val] != null)
			   temp = temp.arr[1-val];
	   }
	   return id5^(temp.value);
   }
 
   public static String add(String s1,String s2)
   {
	   int n=s1.length()-1;
	   int m=s2.length()-1;
	   int rem=0;
	   int carry=0;
	   int i=n;
	   int j=m;
	   String ans="";
	   while(i>=0&&j>=0)
	   {
		 int c1=(int)(s1.charAt(i)-'0');
		 int c2=(int)(s2.charAt(j)-'0');
		 int sum=c1+c2;
		 sum+=carry;
		 rem=sum%10;
		 carry=sum/10;
         ans=rem+ans;
		  i--; j--;
		  
	   }
	   while(i>=0)
	   {
		int c1=(int)(s1.charAt(i)-'0');
	
		int sum=c1;
		sum+=carry;
		rem=sum%10;
		carry=sum/10;
		ans=rem+ans;
		i--;
	   }
	   while(j>=0)
	   {
	
		int c2=(int)(s2.charAt(j)-'0');
		int sum=c2;
		sum+=carry;
		rem=sum%10;
		carry=sum/10;
		ans=rem+ans;
		j--;
	   }

	   if(carry>0)ans=carry+ans;
	   return ans;
   }
   public static String[] multiply(String A, String B) {
	int lb=B.length();
	char[] a=A.toCharArray();
	char[] b=B.toCharArray();
	String[] s=new String[lb];
	int cnt=0;
	int y=0;
	String s1="";
q=0;
	for(int i=b.length-1;i>=0;i--)
	{
		int rem=0;
		int carry=0;
		
	
		for(int j=a.length-1;j>=0;j--)
		{
			int mul=(int)(b[i]-'0')*(int)(a[j]-'0');
			mul+=carry;
			rem=mul%10;
			carry=mul/10;
			s1=rem+s1;
		}
		s1=carry+s1;
		s[y++]=s1;
		q=Math.max(q,s1.length());
		s1="";
		for(int i1=0;i1<y;i1++)s1+='0';
		
	}
	return s;
}
   public static long nCr(long total, long choose)
   {
	   if(total < choose)
		   return 0;
	   if(choose == 0 || choose == total)
		   return 1;
	   return nCr(total-1,choose-1)+nCr(total-1,choose);
   }
 
 
    
 static boolean validString(String s)
 {
	 int[] cnt=new int[300];
	 LinkedHashSet<Character> h=new LinkedHashSet<>();
	 HashMap<Character,Integer> map=new HashMap<>();
	 for(int i=0;i<s.length();i++)
	 {
		 char c=s.charAt(i);
		 h.add(c);
		 if(map.containsKey(c))
		 map.put(c,map.get(c)+1);
		 else map.put(c,1);
	    

	 }
     int cntOdd=0;
	 for(char c:h)
	 {
		 if(map.get(c)%2==1)
		 cntOdd++;
	 }
	 if(cntOdd==1||cntOdd==0)
	 return true;
	 else return false;
 }

   static int get(long s)
   {
	  int ans=0;
	  for(int i=0;i<n;i++)
	  {
		  if(p[i].x<=s&&s<=p[i].y)ans++;
	  }
	  return ans;
   }
   static class LongPoint {
	public long x;
	public long y;

	public LongPoint(long x, long y) {
		this.x = x;
		this.y = y;
	}

	public LongPoint subtract(LongPoint o) {
		return new LongPoint(x - o.x, y - o.y);
	}

	public long cross(LongPoint o) {
		return x * o.y - y * o.x;
	}

}
    static int CountPs(String s,int n)
       {
    	boolean b=false;
    	     char[] S=s.toCharArray();
	       int[][] dp=new int[n][n];
	       boolean[][] p=new boolean[n][n];
	       for(int i=0;i<n;i++)p[i][i]=true;
	     
	       for(int i=0;i<n-1;i++)
	       {
	    	   if(S[i]==S[i+1])
	    	   {
	    		p[i][i+1]=true;
	    		dp[i][i+1]=0;
	    		b=true;
	    	   }
	       }
	    
	       for(int gap=2;gap<n;gap++)
	       {
	    	   for(int i=0;i<n-gap;i++)
	    	   {
	    		   int j=gap+i;
	    		   if(S[i]==S[j]&&p[i+1][j-1]){p[i][j]=true;}
	    		  
	    		  if(p[i][j])
	    			   dp[i][j]=dp[i][j-1]+dp[i+1][j]+1-dp[i+1][j-1];
	    		   
	    		   else if(!p[i][j]) dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
	    		  
	    		   

                             

	    	   }
	       }
	      
	   

    return dp[0][n-1];
	       
    }
  
  
  static void Seive()
  {
      isPrime=new boolean[1500005];
      Arrays.fill(isPrime,true);
	 for(int i=0;i<1500005;i++){divisor[i]=new ArrayList<>();}
	 int u=0;
	 prime=new ArrayList<>();
      for(int i=2;i<=(1500000);i++)
      {
         
          if(isPrime[i])
          {
			prime.add(i);
              for(int j=i;j<1500000;j+=i)
              {
                  
                  divisor[j].add(i);
                  
                  isPrime[j]=false;
              }
         
              
          }
      }
      
  }
  static long id4(long a,long b)
  {
      return (a+b-1)/b;
  }
  static long root(int pow, long x) {
        long candidate = (long)Math.exp(Math.log(x)/pow);
        candidate = Math.max(1, candidate);
        while (pow(candidate, pow) <= x) {
            candidate++;
        }
        return candidate-1;
    }
    
    static long pow(long x, int pow)
    {
        long result = 1;
        long p = x;
        while (pow > 0) {
            if ((pow&1) == 1) {
                if (result > Long.MAX_VALUE/p) return Long.MAX_VALUE;
                result *= p;
            }
            pow >>>= 1;
            if (pow > 0 && p >= 4294967296L) return Long.MAX_VALUE;
            p *= p;
        }
        return result;
    }
  
  static boolean valid(int i,int j)
  {
	  if(i>=0&&i<n&&j>=0&&j<m)return true;
	  return false;
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
  public static int[][] packU(int n, int[] from, int[] to, int max) {
	    
	    int[][] g = new int[n][];
	    int[] p = new int[n];
	    for (int i = 0; i < max; i++) p[from[i]]++;
	    for (int i = 0; i < max; i++) p[to[i]]++;
	    for (int i = 0; i < n; i++) g[i] = new int[p[i]];
	    for (int i = 0; i < max; i++) {
	        g[from[i]][--p[from[i]]] = to[i];
	        g[to[i]][--p[to[i]]] = from[i];
	    }
	    return g;
	}
	public static int[][] parents3(int[][] g, int root) {
	    int n = g.length;
	    int[] par = new int[n];
	    Arrays.fill(par, -1);

	    int[] depth = new int[n];
	    depth[0] = 0;

	    int[] q = new int[n];
	    q[0] = root;
	    for (int p = 0, r = 1; p < r; p++) {
	        int cur = q[p];
	        for (int nex : g[cur]) {
	            if (par[cur] != nex) {
	                q[r++] = nex;
	                par[nex] = cur;
	                depth[nex] = depth[cur] + 1;
	            }
	        }
	    }
	    return new int[][]{par, q, depth};
	}
	public static int lower_bound(int[] nums, int target) {
        int low = 0, high = nums.length - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }
        return nums[low] == target ? low : -1;
    }

    public static int upper_bound(int[] nums, int target) {
        int low = 0, high = nums.length - 1;
        while (low < high) {
            int mid = low + (high + 1 - low) / 2;
            if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid;
        }
        return nums[low] == target ? low : -1;
    }
  public static boolean palin(String s)
	{
	   int i=0;
	   int j=s.length()-1;
	   while(i<j)
	   {
		   if(s.charAt(i)==s.charAt(j))
		   {
			   i++;
			   j--;
		   }
		   else return false;     
	   }
	   return true;
	}
	
  
  
  
 

public static long gcd(long a,long b)
{
	long res=1;
	while(a>0)
	{
		res=a;
		a=b%a;
		b=res;
	}
	return res;
}

public static long pow(long n,long p,long m)
{
	 long  result = 1;
	  if(p==0)
	    return 1;
	
	while(p!=0)
	{
	    if(p%2==1)
	        result *= n;
	    if(result>=m)
	    result%=m;
	    p >>=1;
	    n*=n;
	    if(n>=m)
	    n%=m;
	}
	return result;
}

    
    public static long pow(long n,long p)
     {
	long  result = 1;
	  if(p==0)
	    return 1;
	if (p==1)
	    return n;
	while(p!=0)
	{
	    if(p%2==1)
	        result *= n;
	    p >>=1;
	    n*=n;
	}
	return result;

     }




static class Edge implements Comparator<Edge> {
	private int u;
	private int v;
	private long w;
	public Edge() {
	}
	public Edge(int u, int v, long w) {
		this.u=u;
		this.v=v;
		this.w=w;
	}
	public int getU() {
		return u;
	}
	public void setU(int u) {
		this.u = u;
	}
	public int getV() {
		return v;
	}
	public void setV(int v) {
		this.v = v;
	}
	public long getW() {
		return w;
	}
	public void setW(int w) {
		this.w = w;
	      }
	public long compareTo(Edge e)
	  {
		return (this.getW() - e.getW());
	}

        @Override
        public int compare(Edge o1, Edge o2) {
            throw new UnsupportedOperationException("Not supported yet."); 

        }
	
}



static class Pair implements Comparable<Pair>
{
	int a,b;
	Pair (int a,int b)
	{
		this.a=a;
		this.b=b;
	}

	public int compareTo(Pair o) {
		

		if(this.a!=o.a)
		return -Integer.compare(this.a,o.a);
		else
			return -Integer.compare(this.b, o.b);
		

	}
	public boolean equals(Object o) {
       if (o instanceof Pair) {
           Pair p = (Pair)o;
           return p.a == a && p.b == b;
       }
       return false;
   }
   public int hashCode() {
       return new Integer(a).hashCode() * 31 + new Integer(b).hashCode();
   }
}

static  class InputReader
{
   private InputStream stream;
   private byte[] buf = new byte[1024];

   private id7 filter;
    byte inbuffer[] = new byte[1024];
   int lenbuffer = 0, ptrbuffer = 0;
    final int M = (int) 1e9 + 7;
   int md=(int)(1e7+1);
    int[] SMP=new int[md];
   final double eps = 1e-6;
   final double pi = Math.PI;

	PrintWriter out;
   String check = "";
 InputStream   obj = check.isEmpty() ? System.in : new ByteArrayInputStream(check.getBytes());
   public InputReader(InputStream stream)
   {
       this.stream = stream;
   }

    int readByte() {
	        if (lenbuffer == -1) throw new InputMismatchException();
	        if (ptrbuffer >= lenbuffer) {
	            ptrbuffer = 0;
	            try {
	                lenbuffer = obj.read(inbuffer);
	            } catch (IOException e) {
	                throw new InputMismatchException();
	            }
	        }
	        if (lenbuffer <= 0) return -1;
	        return inbuffer[ptrbuffer++];
   }

   public  int read()
   {
       int c = read();
       while (id0(c))
           c = read();
       int sgn = 1;
       if (c == '-')
       {
           sgn = -1;
           c = read();
       }
       int res = 0;
       do
       {
           if (c < '0' || c > '9')
               throw new InputMismatchException();
           res *= 10;
           res += c - '0';
           c = read();
       } while (!id0(c));
       return res * sgn;
   }

   String is() {
	        int b = skip();
	        StringBuilder sb = new StringBuilder();
	        while (!(id0(b))) 

	        {
	            sb.appendCodePoint(b);
	            b = readByte();
	        }
	        return sb.toString();
   }
   public   int ii() {
	        int num = 0, b;
	        boolean minus = false;
	        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
	        if (b == '-') {
	            minus = true;
	            b = readByte();
	        }
	        while (true) {
	            if (b >= '0' && b <= '9') {
	                num = num * 10 + (b - '0');
	            } else {
	                return minus ? -num : num;
	            }
	            b = readByte();
	        }
   }
 public   long il() {
	        long num = 0;
	        int b;
	        boolean minus = false;
	        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
	        if (b == '-') {
	            minus = true;
	            b = readByte();
	        }
	        while (true) {
	            if (b >= '0' && b <= '9') {
	                num = num * 10 + (b - '0');
	            } else {
	                return minus ? -num : num;
	            }
	            b = readByte();
	        }
   }
   
	    boolean id0(int c) {
	        return (!(c >= 33 && c <= 126));
	       }

	      int skip()
	        {
	        int b;
	        while ((b = readByte()) != -1 && id0(b)) ;
	        return b;
	        }

	    float nf() {
	        return Float.parseFloat(is());
	    }

	    double id() {
	        return Double.parseDouble(is());
	    }

	    char ic() {
	        return (char) skip();
	    }

	    int[] iia(int n) {
	        int a[] = new int[n];
	        for (int i = 0; i<n; i++) a[i] = ii();
	        return a;
	    }

	    long[] ila(int n) {
	        long a[] = new long[n];
	        for (int i = 0; i <n; i++) a[i] = il();
	        return a;
	    }

	    String[] isa(int n) {
	        String a[] = new String[n];
	        for (int i = 0; i < n; i++) a[i] = is();
	        return a;
	    }


		 long mul(long a, long b) { return a * b % M; }

			long div(long a, long b)
				 {
					return mul(a, pow(b, M - 2));

		           }



	    double[][] idm(int n, int m) {
	        double a[][] = new double[n][m];
	        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = id();
	        return a;
	        }

	    int[][] iim(int n, int m) {
	        int a[][] = new int[n][m];
	        for (int i = 0; i < n; i++) for (int j = 0; j <m; j++) a[i][j] = ii();
	        return a;
          }


   public String readLine() {
       int c = read();
       while (id0(c))
           c = read();
       StringBuilder res = new StringBuilder();
       do {
           res.appendCodePoint(c);
           c = read();
       } while (!id2(c));
       return res.toString();
   }

   public interface id7
   {
       public boolean id0(int ch);
   }
   public boolean id2(int c) {
       return c == '\n' || c == '\r' || c == -1;
   }
}

}
