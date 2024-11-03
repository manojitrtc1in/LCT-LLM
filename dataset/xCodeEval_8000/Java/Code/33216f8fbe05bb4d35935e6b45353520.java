

import java.io.*;
import java.util.*;
import java.util.Map.Entry;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.awt.Point;

   public class  point4{
   public  static int[] BIT;
   public  static int[] tree,lazy;
   public  static long[] sum;
   public  static long mod=1000000007;
   public  static int[][] dp;
   public  static boolean[][] isPalin;
   public  static int max1=100005;
   public  static int[][] g;
   public  static LinkedList<Pair> l[],pp;
   public static Query[] query;
   public  static int n,m,q,k,t,x,y,a[],b[],arr[],chosen[],pos[],val[],blocksize,count,count1,size[],tin[],len=21,
                                                          tout[],discover[],cnt[],freq[],pre[],cnty[],cntZ[];
   public  static long V[],low,high,min=Long.MAX_VALUE,cap[],has[],max,ans;
   public  static ArrayList<Integer> adj[],al[];
   public  static TreeSet<Integer> ts;
   public static TreeSet<LinkedList<Integer>> tsl;
   public  static char s[][];
   public  static int depth[],mini,maxi,primeA[];
   public  static boolean visit[][],isPrime[],used[][];
   public  static int[][] dist;
   public  static ArrayList<Integer>prime;
   public  static int[] x1={0,0,-1,1};
   public  static int[] y1={-1,1,0,0};
   public  static ArrayList<Integer> divisor[]=new ArrayList[10000005];
   public  static  int[][] subtree,parent,mat;
   public  static  TreeMap<Integer,Integer> tm;
   public  static LongPoint[] p;
   public  static int[][] grid,memo;
   public  static ArrayList<Pair> list[];
   public  static TrieNode root,node[];
   public  static  LinkedHashMap<String,Integer> map;
   public  static ArrayList<String> al1;
   public static int upper=(int)(1e7);
   public  static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
   public  static void main(String[] args) throws Exception
   {
   	     InputReader in = new InputReader(System.in);
		 PrintWriter pw=new PrintWriter(System.out);
		 n=in.ii();q=in.ii();
		 arr=in.iia(n);
		 adj=new ArrayList[n];
		 for(int i=0;i<n;i++)adj[i]=new ArrayList<Integer>();
		 for(int i=0;i<n-1;i++)
		 {
			 int x=in.ii()-1;
			 int y=in.ii()-1;
			 adj[x].add(y); adj[y].add(x);
		 }
	parent=new int[n][len];
	size=new int[n];
	tin=new int[n+1];
	tout=new int[n+1];
	depth=new int[n];
	discover=new int[n+1];   

	count=0;
	dfs(0,-1);
	cnt=new int[1000005];
	freq=new int[1000005];
	blocksize=(int)Math.sqrt(n);
	
	   query=new Query[q];
	   for(int i=0;i<q;i++)
	   {
		   int u=in.ii()-1;
		   int kk=in.ii();
		 query[i]=new Query(tin[u],tout[u],kk,i);
	   }
	   Arrays.sort(query);
	 

		 
		int mol=0;  

	   int mor=-1;
	

	 

	   long[] answer=new long[q];
	   long cur=0;
	  

	   for(int i=0;i<q;i++)        
	   {
		 int l=query[i].L;
		 int r=query[i].R;
		 while(mor<r)
		 {
		   mor++;
		   add(discover[mor]);
		  
		 }
		 while(mol>l)
		 {
		   mol--;
		   add(discover[mol]);
		   
		 }
		 while(mor>r)
		 {
		   remove(discover[mor]);
			
		   mor--;
		 }
		 while(mol<l)
		 {
		  remove(discover[mol]);
		   
		   mol++;
		 }
		 
		 answer[query[i].index]=freq[query[i].k];
	   
	   }
	   for(int i=0;i<q;i++)
		   pw.println(answer[i]);
	  
		 
 	   pw.close();
}
static class Query implements Comparable<Query>{
	int index,k;
	int L;
	int R;
	public Query(){}
	public Query(int a,int b,int k,int index)
	{
	  this.L=a;
	  this.R=b;
	  this.k=k;
	  this.index=index;
	}
   public int compareTo(Query o)
   {
	  if(L/blocksize!=o.L/blocksize)return L/blocksize-o.L/blocksize;
	  else return R-o.R;
   }

 }

static void add(int x)
{
	cnt[x]++;
	freq[cnt[x]]++;
}
static void remove(int x)
{
	freq[cnt[x]]--;
	cnt[x]--;
}
static int get(int u, int d){

	for(int i = len - 1; i >= 0; i--){

		if(d >= 1 << i){
			d -= 1 << i;
			u = parent[u][i];
		}

	}

	return u;
}
 static void dfs(int u, int p) {
	discover[count1++]=arr[u];  

	tin[u] = count++;

	parent[u][0] = p==-1?0:p;
	size[u]++;
	for (int i = 1; i < len; i++)
		parent[u][i] = parent[parent[u][i-1]][i-1];
	for (int v :adj[u])
		if (v != p)
		{
			depth[v] = depth[u] + 1;
			dfs( v, u);
			size[u] += size[v];
		}

	tout[u] = count-1;
}


static boolean isParent(int parent, int child) {
	return tin[parent] <= tin[child] && tout[child] <= tout[parent];
}

static int lca(int a, int b) {
	if (isParent(a, b))
		return a;
	if (isParent(b, a))
		return b;
	for (int i = len - 1; i >= 0; i--)
		if (!isParent(parent[a][i], b))
			a = parent[a][i];
	return parent[a][0];
}
static void update(int indx,int val)
   {
	   while(indx<BIT.length)
	   {
		   BIT[indx]=Math.max(BIT[indx],val);
		   indx+=(indx&(-indx));
	   }

   }
static int query1(int indx)
   {
	   int sum=0;
	   while(indx>=1)
	   {
		  sum=Math.max(sum,(BIT[indx]));
		   indx-=(indx&(-indx));
	   }
	   return sum;
	}
static long nCk(int n,int k)
{
	if(k==0)return 1L;
	else return n*nCk(n-1,k-1)/k;
}
static long Seive2(int N)   

{
  long[]ptr = new long [N+2];
  if (N==1)
    return 9;
  ptr[1]=2;
  int num=1;
  for(int k=3;;k++)
  {
    boolean prime =true;
    for(int i=1;ptr[i]*ptr[i]<=k; i++)
    {
      if(k%ptr[i]==0)
      {
        prime=false;
        break;
      }  
    }
    if(prime)
	   ptr[++num]=k;
	   
    if(num==N+1)
    {
      long ret= (long)ptr[N+1]*(long)ptr[N+1];
      return ret;
    }
 
  }
  
}
static long gcd(long a,long b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}

public  static class DSU
{
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


static boolean isPrime(int x)
{
	if(x==0||x==1)return false;
	for(int i=2;i<=Math.sqrt(x);i++)
	{
		if(x%i==0)return false;
	}
	return true;
}
static void Seive()
{
	isPrime=new boolean[max1];
	Arrays.fill(isPrime,true);
	prime=new ArrayList<>();
	for(int i=1;i<max1;i++)divisor[i]=new ArrayList<Integer>();
    isPrime[0]=isPrime[1]=false;
	for(int i=2;i<(max1);i++)
	{
         if(isPrime[i]){
			 divisor[i].add(i);
			 prime.add(i);
			for(int j=2*i;j<max1;j+=i)
			{
				isPrime[j]=false;
				divisor[j].add(i);
			}
		}
	}
}
static int MinNumber(int[]x)
{
	int n=x.length;
	boolean[] visit=new boolean[2345678];
	for(int mask=0;mask<(1<<n);mask++)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			if((mask&(1<<i))>0)
			{
               sum+=x[i];
			}
		}
		visit[sum]=true;
	}
	for(int i=1;i<=2345677;i++)
	if(!visit[i])return i;
	return 0;
}
static int canwin(int u,int v,int k,int[][][]memo)
{
 if(memo[u][v][k]!=-1)return memo[u][v][k];
  else{
	  if(k==0||s[u][v]=='E')return 0;
	  else{
		  int res=0;
		  for(int i=0;i<4;i++)
		  {
			  int nx=u+x1[i];
			  int ny=v+y1[i];
			  if(valid(nx, ny)&&s[nx][ny]!='#')
			   {
				   if(canwin(nx,ny,k-1,memo)==0)
				    res=1;
			   }
		  }
		  memo[u][v][k]=res;
	  }
      return memo[u][v][k];
  }

}

static void rotate(int[] x,int[] y)
{
	for(int i=0;i<x.length;i++)
	{
		int xx=x[i];
		x[i]=y[i];
		y[i]=n-xx+1;
	}
	int t=n;
	n=m;
	m=t;
}
static void hori(int[] y)
{
	for(int i=0;i<y.length;i++)
	{
       y[i]=m-y[i]+1;
	}
}
static int lcs(String s1,String s2)
{
	int n=s1.length();
	int m=s2.length();
	int[][] temp=new int[n+1][m+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0||j==0)temp[i][j]=0;
			else if(s1.charAt(i-1)==s2.charAt(j-1))temp[i][j]=temp[i-1][j-1]+1;
			else temp[i][j]=Math.max(temp[i-1][j],temp[i][j-1]);
		}
	}
	return temp[n][m];
}
static void mergeSort(int[] a, int p, int r)
{
	if( p < r )
	{
		int q = (p + r) / 2;
		mergeSort(a, p, q);
		mergeSort(a, q + 1, r);
		merge(a, p, q, r);
	}
}


static void merge(int[] a, int p, int q, int r)
{
   int n1 = q - p + 1;
   int n2 = r - q;
   int[] L = new int[n1+1], R = new int[n2+1];

   for(int i = 0; i < n1; i++)  L[i] = a[p + i];
   for(int i = 0; i < n2; i++)  R[i] = a[q + 1 + i];
   L[n1] = R[n2] = Integer.MAX_VALUE;

   for(int k = p, i = 0, j = 0; k <= r; k++)
	   if(L[i] <= R[j])
		   a[k] = L[i++];
	   else
		   a[k] = R[j++];
}

static int ori(int x1,int y1,int x2,int y2,int x3,int y3)
{
	int X1=x3-x1;
	int Y1=y3-y1;
	int X2=x2-x1;
	int Y2=y2-y1;
  return (X1*Y2-X2*Y1);
}

static class Node{
	int gcd,cnt;
	public Node(int gcd,int cnt)
	{
		this.gcd=gcd;
		this.cnt=cnt;
	}
}

		static  void build(int node,int start,int end){
			if(start > end)return;
			if(start == end){
				tree[node] = arr[start];
				return;
			}
			build(2*node,start,(start + end)/2);
			build(2*node + 1,(start + end)/2 + 1,end);
			tree[node] = Math.min(tree[2*node],tree[2*node + 1]);
		}
		static  void update(int node,int start,int end,int i,int j,int val){
			if(lazy[node] != 0){
				tree[node] += lazy[node];
				if(start != end){
					lazy[2*node] += lazy[node];
					lazy[2*node + 1] += lazy[node];
				}
				lazy[node] = 0;
			}
			if(start > end || start > j || end < i)return;
			if(start >= i && end <= j){
				tree[node] += val;
				if(start != end){
				  lazy[2*node] += val;
				  lazy[2*node + 1] += val;
				}
				return;
			}
			update(2*node,start,(start + end)/2,i,j,val);
			update(2*node + 1,(start + end)/2 + 1,end,i,j,val);
			tree[node] = Math.min(tree[2*node],tree[2*node + 1]);
		}
		static int query(int node,int start,int end,int i,int j){
			if(start > end || start > j || end < i)return Integer.MAX_VALUE;
			if(lazy[node] != 0){
				tree[node] += lazy[node];
				if(start != end){
					lazy[2*node] += lazy[node];
					lazy[2*node + 1] += lazy[node];
				}
				lazy[node] = 0;
			}
			if(start >= i && end <= j)return tree[node];
			int q1 = query(2*node,start,(start + end)/2,i,j);
			int q2 = query(2*node + 1,(start + end)/2 + 1,end,i,j);
			return Math.min(q1,q2);
		}



static class TrieNode
{
	int value;  

	int freq;
	TrieNode[] arr =  new TrieNode[2];
	public TrieNode() {
		value = Integer.MAX_VALUE;
		freq=0;
		arr[0] = null;
		arr[1] = null;
	}
}
static void insert(int n,int num)
{
	TrieNode temp = node[n];
	temp.value=Math.min(temp.value,num);
	

	

	for (int i=19; i>=0; i--)
	{
		

		int val = (num & (1<<i)) >=1 ? 1 : 0;

		

		if (temp.arr[val] == null)
			temp.arr[val] = new TrieNode();

		temp = temp.arr[val];

		temp.value=Math.min(temp.value,num);
	}


	

	

}

static long query(int x,int k,int s)
{
	TrieNode temp = node[k];
	long ans=0;
	if(x%k!=0||temp.value+x>s)return -1;

	for (int i=19; i>=0; i--)
	{
		

		int val = (x & (1<<i)) >= 1 ? 1 : 0;

		if(temp.arr[1^val]!=null&&temp.arr[1^val].value+x<=s)
		{
			ans+=(1^val)<<i;
			temp=temp.arr[1^val];
		}
        else if(temp.arr[val]!=null){
			ans+=val<<i;
			temp=temp.arr[val];
			if(temp==null||temp.value+x>s)
			{
				return -1;
			}
		}
	}
	return ans;
}



static int orient(Point a,Point b,Point c)
{
	

	Point p1=c.minus(a);
	Point p2=b.minus(a);
	return (int)(p1.cross(p2));
}
public static class Polygon {

	static final double EPS = 1e-15;
	public int n;
	public Point p[];

	Polygon(int n, Point x[]) {
		this.n = n;
		p = Arrays.copyOf(x, n);
	}

	long area(){ 

		long ans = 0;
		for(int i = 1; i + 1 < n; i++)
			ans += p[i].minus(p[0]).cross(p[i + 1].minus(p[0]));
		return ans;
	}

	boolean PointInPolygon(Point q) {
		boolean c = false;
		for (int i = 0; i < n; i++){
			int j = (i+1)%n;
			if ((p[i].y <= q.y && q.y < p[j].y ||
					p[j].y <= q.y && q.y < p[i].y) &&
					q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
			c = !c;
		 }
		return c;
	}

		

	boolean PointOnPolygon(Point q) {
		 for (int i = 0; i < n; i++)
		 if (ProjectPointSegment(p[i], p[(i+1)%n], q).dist(q) < EPS)
			 return true;
		 return false;
	}

	

	Point ProjectPointSegment(Point a, Point b, Point c) {
	  double r = b.minus(a).dot(b.minus(a));
	  if (Math.abs(r) < EPS) return a;
	  r = c.minus(a).dot(b.minus(a))/r;
	  if (r < 0) return a;
	  if (r > 1) return b;
	  return a.plus(b.minus(a).mul(r));
	}
}

public static class Point {
	public double x, y;

	public Point(double x, double y) {
		this.x = x;
		this.y = y;
	}

	public Point minus(Point b) {
		return new Point(x - b.x, y - b.y);
	}

	public Point plus(Point a){
		return new Point(x + a.x, y + a.y);
	}

	public double cross(Point b) {
		return (double)x * b.y - (double)y * b.x;
	}

	public double dot(Point b) {
		return (double)x * b.x + (double)y * b.y;
	}

	public Point mul(double r){
		return new Point(x * r, y * r);
	}

	public double dist(Point p){
		return Math.sqrt(fastHypt( x - p.x , y - p.y));
	}

	public double fastHypt(double x, double y){
		return x * x + y * y;
	}
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
		int dx = (int)(q.x - p.x), dy = (int)(q.y - p.y);
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



   public static ListNode removeNthFromEnd(ListNode a, int b) {

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



  static long divCeil(long a,long b)
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



  static boolean valid(int i,int j)
  {
	  if(i>=0&&i<n&&j>=0&&j<m)return true;
	  return false;
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
		if(this.y!=o.y)return o.y-this.y;
		else return this.x-o.x;
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

   private SpaceCharFilter filter;
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
       while (isSpaceChar(c))
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
       } while (!isSpaceChar(c));
       return res * sgn;
   }

   String is() {
	        int b = skip();
	        StringBuilder sb = new StringBuilder();
	        while (!(isSpaceChar(b))) 

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

	    boolean isSpaceChar(int c) {
	        return (!(c >= 33 && c <= 126));
	       }

	      int skip()
	        {
	        int b;
	        while ((b = readByte()) != -1 && isSpaceChar(b)) ;
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
       while (isSpaceChar(c))
           c = read();
       StringBuilder res = new StringBuilder();
       do {
           res.appendCodePoint(c);
           c = read();
       } while (!isEndOfLine(c));
       return res.toString();
   }

   public interface SpaceCharFilter
   {
       public boolean isSpaceChar(int ch);
   }
   public boolean isEndOfLine(int c) {
       return c == '\n' || c == '\r' || c == -1;
   }
}

}
