

import java.io.*;
import java.util.*;
import java.util.Map.Entry;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import javafx.scene.layout.Priority;
import java.awt.Point;

   public class  easy18{
   public  static long[] BIT;
   public  static long[] tree;
   public  static long[] sum;
   public  static int mod=1000000007;
   public  static int[][] dp;
   public  static boolean[][] id5;
   public  static int max1=1000010;
   public  static int[][] g;
   public  static LinkedList<Pair> l[];
   public  static int n,m,q,k,t,arr[],b[],cnt[],chosen[],pos[],val[],blockSize,count;
   public  static long V[],low,high,min=Long.MAX_VALUE,cap[],has[],ans,max;
   public  static ArrayList<Integer> adj[],al;
   public  static TreeSet<Integer> ts;
   public  static   char[][] s;
   public  static int depth,mini,maxi;
   public  static boolean visit[][],isPrime[],used[];
   public  static int[][] dist;
   public  static ArrayList<Integer>prime;
   public  static int[] x={0,1};
   public  static int[] y={-1,0};
   public  static ArrayList<Integer> divisor[]=new ArrayList[1500005];
   public  static  int[][] subtree,parent,mat;
   public  static  TreeMap<Integer,Integer> tm;
   public  static LongPoint[] p;
   public  static int[][] grid,memo;
   public  static ArrayList<Pair> list;
   public  static TrieNode root;
   public  static  LinkedHashMap<String,Integer> map;
   public  static ArrayList<String> al1;
   public  static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
   public  static void main(String[] args) throws Exception
   {
   	   InputReader in = new InputReader(System.in);
	   PrintWriter pw=new PrintWriter(System.out);
	 long x1=in.il();
	 long y1=in.il();
	 long x2=in.il();
	 long y2=in.il();
	  n=in.ii();
	  long ans=0;
	  for(int i=0;i<n;i++)
	  {
		  long a=in.il();
		  long b=in.il();
		  long c=in.il();
		  long val1=a*x1+b*y1+c;
		  long val2=a*x2+b*y2+c;
		  if(Long.signum(val1)!=Long.signum(val2))ans++;
	  }
	  pw.println(ans);
	   pw.close();
}
static double dist(Point p1,Point p2)
{
	return Math.sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

static class coder {
	int indx;
	String name;
	coder(int indx,String name)
	{
		this.indx=indx;
		this.name=name;
	}
}
static class TrieNode
{
	int value;  

	int freq;
	TrieNode[] arr =  new TrieNode[2];
	public TrieNode() {
		value = 0;
		freq=0;
		arr[0] = null;
		arr[1] = null;
	}
}
static void insert(int id4,int add)
{
	TrieNode temp = root;
	
	

	

	for (int i=31; i>=0; i--)
	{
		

		int val = (id4 & (1<<i)) >=1 ? 1 : 0;
		
		

		if (temp.arr[val] == null)
			temp.arr[val] = new TrieNode();
		
		temp = temp.arr[val];
		temp.freq+=add;
	}
  
	

	

}

static long query(int id4)
{
	TrieNode temp = root;
	long ans=0;
	for (int i=31; i>=0; i--)
	{
		

		int val = (id4 & (1<<i)) >= 1 ? 1 : 0;
		
		if(temp.arr[1-val]!=null&&temp.arr[1-val].freq>0)
		{
			ans|=1l<<i;
			temp=temp.arr[1-val];
		}
        else if(temp.arr[val]!=null&&temp.arr[val].freq>0)
            temp=temp.arr[val];
		else break;
	}
	return ans;
}
static void update(int indx,long val)
   {
	   while(indx<max1)
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
   

static int gcd(int a, int b) 
{
	int res=0;
	while(a!=0)
	{
		res=a;
		a=b%a;
		b=res;
	}
	return b;
}
static slope getSlope(Point p, Point q)
	{
		int dx = q.x - p.x, dy = q.y - p.y;
		int g = gcd(dx, dy);
		return new slope(dy / g, dx / g);
	}
	
static class slope implements Comparable<slope>
{
	int x,y;
	public slope(int y,int x)
	{
		this.x=x;
		this.y=y;
	}
	public int compareTo(slope s)
	{
		if(s.y!=y)return y-s.y;
	return x-s.x;
	}
}

static class Ball implements Comparable
	{
		int r;
		int occ;
		public Ball(int r,int occ)
		{
			this.r = r;
			this.occ = occ;
		}
		@Override
		public int compareTo(Object o) {
			Ball b = (Ball) o;
			return b.occ-this.occ;
		}
	}
static int bs(ArrayList<Long> al,long x)
{
	int s=0;
	int e=al.size();
	while(s<e)
	{
		int mid=(s+e)/2;
		if(al.get(mid)==x)return mid;
		else if(al.get(mid)<x)
		{
			s=mid+1;
		}
		else e=mid;
	}
	return -1;
}
static class E implements Comparable<E>{
	int x,y;
	char c;
	E(int  x,int y,char c)
	{
		this.x=x;
		this.y=y;
		this.c=c;
	}
	public int compareTo(E o)
	{
		if(x!=o.x)return o.x-x;
		else return y-o.y;
		
	}
}

static ArrayList<String> dfs(String s,String[] sarr,HashMap<String, ArrayList<String>> map)
{
   if(map.containsKey(s))return map.get(s);
   ArrayList<String> res=new ArrayList<>();
   if(s.length()==0)
   {
	   res.add("");
	   return res;
   }

   for(String word:sarr)
   {
	   if(s.startsWith(word))
	   {
		   ArrayList<String > sub=dfs(s.substring(word.length()),sarr,map);
		   for(String s2:sub)
		   {
			   res.add(word+ (s2.isEmpty() ? "" : " ")+s2);
		   }
	   }
   }
   map.put(s,res);
   return res;
}
static class SegmentTree{
  
  int n;
  int max_bound;
 
  public SegmentTree(int n)
  {
	
	  this.n=n;
	  tree=new long[4*n+1];
	  build(1,0,n-1);
  }
void build(int c,int s,int e)
{
   if(s==e)
   {
	   tree[c]=arr[s];
	   return ;
   }

   int mid=(s+e)>>1;
   build(2*c,s,mid);
   build(2*c+1,mid+1,e);
   tree[c]=(tree[2*c]&tree[2*c+1]);
}
void put(int c,int s, int e,int l,int r,int  v) {
	if(l>e||r<s||s>e)return ;
	if (s == e) 
	{
		tree[c] = arr[s]^v;
		return;
	}
	int mid = (s + e) >> 1;
	if (l>mid) put(2*c+1,m+1, e , l,r, v);
	else if(r<=mid)put(2*c,s,m,l,r , v);
	else{
      
	}
	
}
long query(int c,int s,int e,int l,int r)
{
   if(e<l||s>r)return 0L;

   if(s>=l&&e<=r)
   {
	return tree[c];
   }

	int mid=(s+e)>>1;
	long ans=(1l<<30)-1;
	if(l>mid)return query(2*c+1,mid+1,e,l,r);
	else if(r<=mid)return query(2*c,s,mid,l,r);
	else{
		return query(2*c,s,mid,l,r)&query(2*c+1,mid+1,e,l,r);
	}

 }
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
  static long id3(long a,long b)
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
	
 
static int lcm(int a,int b)
{
	return (a*b)/(gcd(a,b));
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
	int x,y;
	Pair (int a,int b)
	{
		this.x=a;
		this.y=b;
	}

	public int compareTo(Pair o) {
		

		if(this.x!=o.x)
		return -Integer.compare(this.x,o.x);
		else
			return -Integer.compare(this.y, o.y);
		

	}
	public boolean equals(Object o) {
       if (o instanceof Pair) {
           Pair p = (Pair)o;
           return p.x == x && p.y == y;
       }
       return false;
   }
   public int hashCode() {
       return new Integer(x).hashCode() * 31 + new Integer(y).hashCode();
   }
}

static  class InputReader
{
   private InputStream stream;
   private byte[] buf = new byte[1024];

   private id6 filter;
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

   public interface id6
   {
       public boolean id0(int ch);
   }
   public boolean id2(int c) {
       return c == '\n' || c == '\r' || c == -1;
   }
}

}
