import java.io.*;
import java.util.*;



import java.math.*;
import java.math.BigInteger;


public final class B
{    
	static PrintWriter out = new PrintWriter(System.out); 
	static StringBuilder ans=new StringBuilder();
	static FastReader in=new FastReader();
	

	static	ArrayList<Integer> g[];
	static long mod=(long)998244353,INF=Long.MAX_VALUE;
	static boolean set[];
	static int max=0;
	static int lca[][];
	static int par[],col[],D[];
	static long fact[];
	static int size[],N;
	static long sum[][],f[],pow[];
	static int seg[],seg1[],seg2[],dp[][];
	public static void main(String args[])throws IOException
	{	
		
		
		int T=i();
		outer:while(T-->0)
		{
			int N=i();
			char X[]=in.next().toCharArray();			
			int f[]=new int[26];
			Arrays.fill(f, -1);
			boolean taken[]=new boolean[26];
			par=new int[30];
			Arrays.fill(par, -1);


			for(char x:X)
			{
				if(f[x-'a']==-1)
				{
					int c=x-'a';
					boolean all_same=true;
					for(int j=0; j<26; j++)
					{
						if(c==j || find(c+1)==find(j+1) || taken[j])continue;
						taken[j]=true;
						all_same=false;
						union(c+1,j+1);
						f[x-'a']=j;
						break;
					}
					if(all_same)
					{
						for(int j=0; j<26; j++)
						{
							if(c==j || taken[j])continue;
							f[x-'a']=j;
							break;
							
						}
					}
				}
				char ch=(char)(f[x-'a']+'a');
				ans.append(ch+"");
			}


			ans.append("\n");
		}
		out.println(ans);
		out.close();

	}
	static void dfs(int n,int p)
	{		
		for(int c:g[n])
		{
			if(c!=p)
			{
				dfs(c,n);
				D[n]=Math.max(D[n], 1+D[c]);
			}
		}


	}
	static long nCr(int n,int r)
	{
		long a=fact[n];
		long b=fact[r];
		long c=fact[n-r];
		b=pow(b,mod-2)%mod;
		c=pow(c,mod-2)%mod;
		b*=c;
		b%=mod;
		a*=b;
		a%=mod;
		return a;
	}
	static boolean move(int a,int b,int N,int M)
	{
		if(a<=0 || a>N)return false;
		if(b<=0 || b>M)return false;
		return true;
	}
	static int f(int i,int k,int dp[][],int N)
	{
		return 0;
	}
	static int f1212(int N,int l,int r)
	{
		int dp[][]=new int[N+1][r+1];

		for(int i=l; i<=r; i++)dp[1][i]=1;
		for(int len=2; len<=N; len++)
		{
			for(int val=l; val<=r; val++)
			{
				for(int j=val; j>=l; j--)dp[len][val]+=dp[len-1][j];
			}
		}
		int s=0;
		for(int a[]:dp)for(int x:a)s+=x;
		return s;
	}
	static int josephus(int n, int k)
	{
		if (n == 1)
			return 1;
		else
			
			return (josephus(n - 1, k) + k - 1) % n + 1;
	}
	static int f(char X[],int l,int r)
	{
		if(r-l==1)
		{
			if(X[l]==X[r])return 2;
			return 0;
		}
		if(dp[l][r]==-1)
		{
			dp[l][r]=0;
			if(X[l]==X[r])
			{
				int a=X[l]-'a',b=X[l+1]-'a',c=X[r-1]-'a';
				int max=Math.max(c, b);
				if(max<a)return 0;
				a=f(X,l+1,r-1); 

				dp[l][r]=a;
			}
			else
			{
				if((X[l]-'a')<(X[r]-'a'))
				{
					int a=X[l+1]-'a',b=X[l]-'a';
					if(a>b)return 1;
					if(b>a)return 0;
					dp[l][r]=f(X,l+2,r);

				}
				else
				{
					int a=X[r-1]-'a',b=X[r]-'a';
					if(b<a)return 1;
					else if(b>a)return 0;

					dp[l][r]=f(X,l,r-2);


				}
			}
		}

		return dp[l][r];
	}
	static long f1(List<Integer> A,int k)
	{
		long r=-1;
		if(A.size()<k)return -1;
		long s=0;
		HashMap<Integer,Integer> mp=new HashMap<>();
		for(int i=0; i<k; i++)
		{
			s+=A.get(i);
			mp.put(A.get(i),mp.getOrDefault(A.get(i), 0)+1);
		}
		if(mp.size()==k)r=Math.max(r, s);
		for(int i=k; i<A.size(); i++)
		{
			int a=A.get(i-k);
			s-=a;
			if(mp.get(a)==1)mp.remove(a);
			else mp.put(a, mp.get(a)-1);			
			s+=A.get(i);
			mp.put(A.get(i),mp.getOrDefault(A.get(i), 0)+1);
			if(mp.size()==k)r=Math.max(r, s);

		}
		return r;
	}
	static int func(String X)
	{
		int N=X.length();
		if(N<=1)return 1;
		if(N%2!=0)
		{
			if(X.substring(0,N/2).equals(X.substring(N/2,N)))
				if(func(X.substring(0,N/2))==1)
					return 1;
		}
		else 
		{
			if(func(X.substring(0,N-1))==1)return 1;	
		}
		return 0;
	}
	static boolean f(StringBuilder sb)
	{
		if(sb.length()<=1)return true;
		if(sb.length()%2==0)
		{
			String X=sb.substring(0,sb.length()/2),
					Y=sb.substring(sb.length()/2,sb.length());
			if(X.equals(Y))return f(new StringBuilder(X));
		}
		else
		{
			String X=sb.substring(0,(sb.length()-1));
			return f(new StringBuilder(X));
		}
		return false;
	}
	static long f(int N,int M,int i,int k)
	{
		if(k==M) 
		{
			

			return 1;
		}
		if(dp[i][k]==-1)
		{
			dp[i][k]=0;
			for(int j=i; j<=N; j++)dp[i][k]+=(f(N,M,j,k+1))%mod;
		}
		return dp[i][k]%mod;
	}
	static int[] ask(int l,int r)
	{
		out.println("? "+(l+1)+" "+(r+1));
		out.flush();
		int A[]=input(r-l+1);
		


		return A;
	}
	static long kadane(long A[])
	{
		long lsum=A[0],gsum=0;
		gsum=Math.max(gsum, lsum);
		for(int i=1; i<A.length; i++)
		{
			lsum=Math.max(lsum+A[i],A[i]);
			gsum=Math.max(gsum,lsum);
		}
		return gsum;
	}

	public static boolean  pal(int i)
	{
		StringBuilder sb=new StringBuilder();
		StringBuilder rev=new StringBuilder();
		int p=1;
		while(p<=i)
		{
			if((i&p)!=0)
			{
				sb.append("1");
			}
			else sb.append("0");
			p<<=1;
		}

		rev=new StringBuilder(sb.toString());
		rev.reverse();
		if(i==8)System.out.println(sb+" "+rev);

		return (sb.toString()).equals(rev.toString());

	}
	public static void reverse(int i,int j,int A[])
	{
		while(i<j)
		{
			int t=A[i];
			A[i]=A[j];
			A[j]=t;
			i++;
			j--;
		}
	}
	public  static int ask(int a,int b,int c)
	{
		System.out.println("? "+a+" "+b+" "+c);
		return i();
	}
	static int[] reverse(int A[],int N)
	{
		int B[]=new int[N];
		for(int i=N-1; i>=0; i--)
		{
			B[N-i-1]=A[i];
		}
		return B;	
	}
	static boolean isPalin(char X[])
	{
		int i=0,j=X.length-1;
		while(i<=j)
		{
			if(X[i]!=X[j])return false;
			i++;
			j--;
		}
		return true;
	}

	static  int distance(int a,int b)
	{
		int d=D[a]+D[b];
		int l=LCA(a,b);
		l=2*D[l];
		return d-l;
	}
	static int LCA(int a,int b)
	{
		if(D[a]<D[b])
		{
			int t=a;
			a=b;
			b=t;
		}
		int d=D[a]-D[b];
		int p=1;
		for(int i=0; i>=0 && p<=d; i++)
		{
			if((p&d)!=0)
			{
				a=lca[a][i];
			}
			p<<=1;
		}
		if(a==b)return a;
		for(int i=max-1; i>=0; i--)
		{
			if(lca[a][i]!=-1 && lca[a][i]!=lca[b][i])
			{
				a=lca[a][i];
				b=lca[b][i];
			}
		}
		return lca[a][0];

	}


	static int[] prefix_function(char X[])

	{
		int N=X.length;
		int pre[]=new int[N];
		for(int i=1; i<N; i++)
		{
			int j=pre[i-1];
			while(j>0 && X[i]!=X[j])
				j=pre[j-1];
			if(X[i]==X[j])j++;
			pre[i]=j;
		}
		return pre;
	}


	

	

	

	

	

	

	

	

	

	

	

	

	


	static int right(int A[],int Limit,int l,int r)
	{
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(A[m]<Limit)l=m;
			else r=m;
		}
		return l;
	}
	static int left(int A[],int a,int l,int r)
	{
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(A[m]<a)l=m;
			else r=m;
		}
		return l;
	}

	static void build1(int v,int tl,int tr,int A[])
	{
		if(tl==tr)
		{
			seg1[v]=A[tl];
			return;
		}
		int tm=(tl+tr)/2;
		build1(v*2,tl,tm,A);
		build1(v*2+1,tm+1,tr,A);
		seg1[v]=seg1[v*2]+seg1[v*2+1];
	}
	static void update1(int v,int tl,int tr,int index)
	{
		if(index==tl && index==tr)
		{
			seg1[v]++;
		}
		else
		{
			int tm=(tl+tr)/2;
			if(index<=tm)update1(v*2,tl,tm,index);
			else update1(v*2+1,tm+1,tr,index);
			seg1[v]=seg1[v*2]+seg1[v*2+1];
		}
	}
	static int ask1(int v,int tl,int tr,int l,int r)
	{

		if(l>r)return 0;
		if(tl==l && r==tr)
		{
			return seg1[v];
		}
		int tm=(tl+tr)/2;

		return ask1(v*2,tl,tm,l,Math.min(tm, r))+ask1(v*2+1,tm+1,tr,Math.max(tm+1, l),r);
	}
	static void build2(int v,int tl,int tr,int A[])
	{
		if(tl==tr)
		{
			seg2[v]=A[tl];
			return;
		}
		int tm=(tl+tr)/2;
		build2(v*2,tl,tm,A);
		build2(v*2+1,tm+1,tr,A);
		seg2[v]=seg2[v*2]+seg2[v*2+1];
	}
	static void update2(int v,int tl,int tr,int index)
	{
		if(index==tl && tl==tr)
		{
			seg2[v]-=1;
		}
		else
		{
			int tm=(tl+tr)/2;
			if(index<=tm)update2(v*2,tl,tm,index);
			else update2(v*2+1,tm+1,tr,index);
			seg2[v]=seg2[v*2]+seg2[v*2+1];
		}
	}
	static int ask2(int v,int tl,int tr,int l,int r)
	{

		if(l>r)return 0;
		if(tl==l && r==tr)
		{
			return seg2[v];
		}
		int tm=(tl+tr)/2;

		return ask2(v*2,tl,tm,l,Math.min(tm, r))+ask2(v*2+1,tm+1,tr,Math.max(tm+1, l),r);
	}
	static boolean f(long A[],long m,int N)
	{
		long B[]=new long[N];
		for(int i=0; i<N; i++)
		{
			B[i]=A[i];
		}
		for(int i=N-1; i>=0; i--)
		{
			if(B[i]<m)return false;
			if(i>=2)
			{
				long extra=Math.min(B[i]-m, A[i]);
				long x=extra/3L;
				B[i-2]+=2L*x;
				B[i-1]+=x;
			}
		}
		return true;
	}
	static int f(int l,int r,long A[],long x)
	{
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(A[m]>=x)l=m;
			else r=m;
		}
		return r;

	}
	static boolean f(long m,long H,long A[],int N)
	{
		long s=m;
		for(int i=0; i<N-1;i++)
		{
			s+=Math.min(m, A[i+1]-A[i]);
		}
		return s>=H;
	}

	static long ask(long l,long r)
	{
		System.out.println("? "+l+" "+r);
		return l();
	}
	static long f(long N,long M)
	{
		long s=0;
		if(N%3==0)
		{
			N/=3;
			s=N*M;
		}
		else
		{
			long b=N%3;
			N/=3;
			N++;
			s=N*M;
			N--;
			long a=N*M;
			if(M%3==0)
			{
				M/=3;
				a+=(b*M);
			}
			else
			{
				M/=3;
				M++;
				a+=(b*M);
			}
			s=Math.min(s, a);
		}
		return s;
	}
	static int ask(StringBuilder sb,int a)
	{
		System.out.println(sb+""+a);
		return i();
	}
	static void swap(char X[],int i,int j)
	{
		char x=X[i];
		X[i]=X[j];
		X[j]=x;
	}
	static int min(int a,int b,int c)
	{
		return Math.min(Math.min(a, b), c);
	}


	static long and(int i,int j)
	{
		System.out.println("and "+i+" "+j);
		return l();
	}
	static long or(int i,int j)
	{
		System.out.println("or "+i+" "+j);
		return l();
	}
	static int len=0,number=0;
	static void f(char X[],int i,int num,int l)
	{
		if(i==X.length)
		{
			if(num==0)return;
			

			if(isPrime(num))return;
			if(l<len)
			{
				len=l;
				number=num;				
			}
			return;
		}
		int a=X[i]-'0';
		f(X,i+1,num*10+a,l+1);
		f(X,i+1,num,l);
	}
	static boolean is_Sorted(int A[])
	{
		int N=A.length;
		for(int i=1; i<=N; i++)if(A[i-1]!=i)return false;
		return true;
	}
	static boolean f(StringBuilder sb,String Y,String order)
	{
		StringBuilder res=new StringBuilder(sb.toString());
		HashSet<Character> set=new HashSet<>();
		for(char ch:order.toCharArray())
		{
			set.add(ch);
			for(int i=0; i<sb.length(); i++)
			{
				char x=sb.charAt(i);
				if(set.contains(x))continue;
				res.append(x);
			}
		}

		String str=res.toString();
		return str.equals(Y);
	}
	static boolean all_Zero(int f[])
	{
		for(int a:f)if(a!=0)return false;
		return true;
	}
	static long form(int a,int l)
	{
		long x=0;
		while(l-->0)
		{
			x*=10;
			x+=a;
		}
		return x;
	}
	static int count(String X)
	{
		HashSet<Integer> set=new HashSet<>();
		for(char x:X.toCharArray())set.add(x-'0');
		return set.size();
	}

	static int f(long K)
	{
		long l=0,r=K;
		while(r-l>1)
		{
			long m=(l+r)/2;
			if(m*m<K)l=m;
			else r=m;
		}
		return (int)l;
	}
	

	

	

	

	

	

	

	

	

	

	

	

	

	


	static int [] sub(int A[],int B[])
	{
		int N=A.length;
		int f[]=new int[N];
		for(int i=N-1; i>=0; i--)
		{
			if(B[i]<A[i])
			{
				B[i]+=26;
				B[i-1]-=1;
			}
			f[i]=B[i]-A[i];
		}
		for(int i=0; i<N; i++)
		{
			if(f[i]%2!=0)f[i+1]+=26;
			f[i]/=2;
		}
		return f;
	}
	static int[] f(int  N)
	{
		char X[]=in.next().toCharArray();
		int A[]=new int[N];
		for(int i=0; i<N; i++)A[i]=X[i]-'a';
		return A;
	}




	static int max(int a ,int b,int c,int d)
	{
		a=Math.max(a, b);
		c=Math.max(c,d);
		return Math.max(a, c);
	}
	static int min(int a ,int b,int c,int d)
	{
		a=Math.min(a, b);
		c=Math.min(c,d);
		return Math.min(a, c);
	}



	static HashMap<Integer,Integer> Hash(int A[])
	{
		HashMap<Integer,Integer> mp=new HashMap<>();
		for(int a:A)
		{
			int f=mp.getOrDefault(a,0)+1;
			mp.put(a, f);
		}
		return mp;
	}
	static long mul(long a, long b)
	{
		return ( a %mod * 1L * b%mod )%mod;
	}
	static void swap(int A[],int a,int b)
	{
		int t=A[a];
		A[a]=A[b];
		A[b]=t;
	}


	static int find(int a)
	{
		if(par[a]<0)return a;
		return par[a]=find(par[a]);
	}
	static void union(int a,int b)
	{
		a=find(a);
		b=find(b);
		if(a!=b)
		{
			if(par[a]>par[b]) 

			{
				int t=b;
				b=a;
				a=t;
			}
			par[a]+=par[b];
			par[b]=a;
		}
	}
	static boolean isSorted(int A[])
	{
		for(int i=1; i<A.length; i++)
		{
			if(A[i]<A[i-1])return false;
		}
		return true;
	}

	static boolean isDivisible(StringBuilder X,int i,long num)
	{
		long r=0;
		for(; i<X.length(); i++)
		{
			r=r*10+(X.charAt(i)-'0');
			r=r%num;
		}
		return r==0;
	}    



	static int lower_Bound(int A[],int low,int high, int x) 
	{ 
		if (low > high) 
			if (x >= A[high]) 
				return A[high]; 

		int mid = (low + high) / 2; 

		if (A[mid] == x) 
			return A[mid]; 

		if (mid > 0 && A[mid - 1] <= x && x < A[mid]) 
			return A[mid - 1]; 

		if (x < A[mid]) 
			return lower_Bound( A, low, mid - 1, x); 

		return lower_Bound(A, mid + 1, high, x); 
	} 

	static String f(String A)
	{
		String X="";
		for(int i=A.length()-1; i>=0; i--)
		{
			int c=A.charAt(i)-'0';
			X+=(c+1)%2;
		}
		return X;
	}

	static void sort(long[] a) 

	{
		ArrayList<Long> l=new ArrayList<>();
		for (long i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

	static String swap(String X,int i,int j)
	{
		char ch[]=X.toCharArray();
		char a=ch[i];
		ch[i]=ch[j];
		ch[j]=a;
		return new String(ch);
	}

	static int sD(long n)  
	{  

		if (n % 2 == 0 )  
			return 2;  

		for (int i = 3; i * i <= n; i += 2) {  
			if (n % i == 0 )  
				return i;  
		}  

		return (int)n;  
	}  

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	




	static  long pow(long a,long b)
	{
		

		long pow=1;
		long x=a;
		while(b!=0)
		{
			if((b&1)!=0)pow=(pow*x)%mod;
			x=(x*x)%mod;
			b/=2;
		}
		return pow;
	}

	static long toggleBits(long x)

	{
		int n=(int)(Math.floor(Math.log(x)/Math.log(2)))+1;

		return ((1<<n)-1)^x;
	}

	static int countBits(long a)
	{
		return (int)(Math.log(a)/Math.log(2)+1);
	}

	static long fact(long N)
	{ 
		long n=2; 
		if(N<=1)return 1;
		else
		{
			for(int i=3; i<=N; i++)n=(n*i)%mod;
		}
		return n;
	}


	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

	static boolean isPrime(long N)
	{
		if (N<=1)  return false; 
		if (N<=3)  return true; 
		if (N%2L == 0 || N%3L == 0) return false; 
		for (long i=5; i*i<=N; i+=2) 
			if (N%i==0) 
				return false; 
		return true; 
	}
	static void print(char A[])
	{
		for(char c:A)System.out.print(c+" ");
		System.out.println();
	}
	static void print(boolean A[])
	{
		for(boolean c:A)System.out.print(c+" ");
		System.out.println();
	}
	static void print(int A[])
	{
		for(int a:A)System.out.print(a+" ");
		System.out.println();	
	}
	static void print(long A[])
	{
		for(long i:A)System.out.print(i+ " ");
		System.out.println();

	}
	static void print(boolean A[][])
	{
		for(boolean a[]:A)print(a);
	}
	static void print(long A[][])
	{
		for(long a[]:A)print(a);
	}
	static void print(int A[][])
	{
		for(int a[]:A)print(a);
	}
	static void print(ArrayList<Integer> A)
	{
		for(int a:A)System.out.print(a+" ");
		System.out.println();
	}

	static int i()
	{
		return in.nextInt();
	}

	static long l()
	{
		return in.nextLong();
	}

	static int[] input(int N){
		int A[]=new int[N];
		for(int i=0; i<N; i++)
		{
			A[i]=in.nextInt();
		}
		return A;
	}

	static long[] inputLong(int N)     {
		long A[]=new long[N];
		for(int i=0; i<A.length; i++)A[i]=in.nextLong();
		return A;
	}

	static long GCD(long a,long b) 
	{
		if(b==0)
		{
			return a;
		}
		else return GCD(b,a%b );
	}

}

class PairB implements Comparable<PairB>
{
	long x;
	int index;	
	PairB(long x,int i)
	{
		this.x=x;
		this.index=i;
	}
	public int compareTo(PairB X)
	{
		if(this.x==X.x)
		{
			return 0;
		}
		if(this.x>X.x)return 1;
		else return -1;
	}
}









class FastReader
{
	BufferedReader br;
	StringTokenizer st;
	public FastReader()
	{
		br=new BufferedReader(new InputStreamReader(System.in));
	}

	String next()
	{
		while(st==null || !st.hasMoreElements())
		{
			try
			{
				st=new StringTokenizer(br.readLine());
			}
			catch(IOException e)
			{
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	int nextInt()
	{
		return Integer.parseInt(next());
	}

	long nextLong()
	{
		return Long.parseLong(next());
	}

	double nextDouble()
	{
		return Double.parseDouble(next());
	}

	String nextLine()
	{
		String str="";
		try
		{
			str=br.readLine();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		return str;
	}

}