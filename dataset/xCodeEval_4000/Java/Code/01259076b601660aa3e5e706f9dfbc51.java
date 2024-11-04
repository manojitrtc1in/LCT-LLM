import java.io.*;
import java.util.*;





public class Main
{    
	static PrintWriter out = new PrintWriter(System.out); 
	static StringBuilder ans=new StringBuilder();
	static FastReader in=new FastReader();
	static ArrayList<Integer> g[];
	

	static long mod=(long)(1e9+7);
	static boolean set[],post[][];   
	static int prime[],c[];
	static int par[];
	

	static HashMap<String,Long> mp;
	static long max=1;
	static boolean temp[][];
	static int K=0;
	static int size[],dp[][],iv_A[],iv_B[];
	static int b1[] = new int[200002];
	static int b2[] = new int[200002];
	static int B1 = 0;
	static int B2 = 0;
	public static void main(String args[])throws IOException
	{  
		

		int T=i();
		while(T-->0)
		{
			int n = i();
			int ans = 0;
			int[] arr = input(n);
			for(int i = 0;i < n;i++){
				long zero = 0;
				long cnt = 0;
				for(int j = i;j < n;j++){
					if(arr[j] == 0){
						zero++;
					}
					cnt += (j - i + 1);
					cnt += zero;
				}
				ans += cnt;
			}
			System.out.println(ans);
		}
	}
	static int getmax(ArrayList<Integer> arr){
		int n = arr.size();
		int max = Integer.MIN_VALUE;
		for(int i = 0;i < n;i++){
			max = Math.max(max,arr.get(i));
		}
		return max;
	}
	static boolean check(ArrayList<Integer> arr){
		int n = arr.size();
		boolean flag = true;
		for(int i = 0;i < n-1;i++){
			if(arr.get(i) != arr.get(i+1)){
				flag = false;
				break;
			}
		}
		return flag;
	}
	static int MinimumFlipsOdd(String s, int n)
    {
        int[] a = new int[n];
 
        for (int i = 0; i < n; i++) {
            a[i] = (s.charAt(i) == '1' ? 1 : 0);
        }
 
        

        

        

        int[] oddone = new int[n + 1];
        int[] evenone = new int[n + 1];
 
        oddone[0] = 0;
        evenone[0] = 0;
 
        for (int i = 0; i < n; i++) {
 
            

            if (i % 2 != 0) {
 
                

                

                oddone[i + 1]
                    = oddone[i]
                      + (a[i] == 1 ? 1 : 0);
                evenone[i + 1]
                    = evenone[i]
                      + (a[i] == 0 ? 1 : 0);
            }
 
            

            else {
 
                

                

                oddone[i + 1]
                    = oddone[i]
                      + (a[i] == 0 ? 1 : 0);
                evenone[i + 1]
                    = evenone[i]
                      + (a[i] == 1 ? 1 : 0);
            }
        }
 
        

        return oddone[n];
    }
    static int MinimumFlipsEven(String s, int n)
    {
        int[] a = new int[n];
 
        for (int i = 0; i < n; i++) {
            a[i] = (s.charAt(i) == '1' ? 1 : 0);
        }
 
        

        

        

        int[] oddone = new int[n + 1];
        int[] evenone = new int[n + 1];
 
        oddone[0] = 0;
        evenone[0] = 0;
 
        for (int i = 0; i < n; i++) {
 
            

            if (i % 2 != 0) {
 
                

                

                oddone[i + 1]
                    = oddone[i]
                      + (a[i] == 1 ? 1 : 0);
                evenone[i + 1]
                    = evenone[i]
                      + (a[i] == 0 ? 1 : 0);
            }
 
            

            else {
 
                

                

                oddone[i + 1]
                    = oddone[i]
                      + (a[i] == 0 ? 1 : 0);
                evenone[i + 1]
                    = evenone[i]
                      + (a[i] == 1 ? 1 : 0);
            }
        }
 
        

        return evenone[n];
    }
	static int nextPowerOf2(int n)
    {
        int count = 0;
 
        

        

        

        if (n > 0 && (n & (n - 1)) == 0){
            while(n != 1)
            {
                n >>= 1;
                count += 1;
            }
 
        return count;
        }else{
            while(n != 0)
        {
            n >>= 1;
            count += 1;
        }
 
        return count;
        }
    }
	static int length(int n){
		int count = 0;
		while(n > 0){
			n = n/10;
			count++;
		}
		return count;
	}
	static boolean isPrimeInt(int N)
	{
		if (N<=1)  return false; 
		if (N<=3)  return true; 
		if (N%2 == 0 || N%3 == 0) return false; 
		for (int i=5; i*i<=N; i=i+6) 
			if (N%i == 0 || N%(i+2) == 0) 
				return false; 
		return true; 
	}
	public static int lcs(int[] nums) {
	    int[] tails = new int[nums.length];
	    int size = 0;
	    for (int x : nums) {
	        int i = 0, j = size;
	        while (i != j) {
	            int m = (i + j) / 2;
	            if (tails[m] <= x)
	                i = m + 1;
	            else
	                j = m;
	        }
	        tails[i] = x;
	        if (i == size) ++size;
	    }
	    return size;
	}
	static int CeilIndex(int A[], int l, int r, int key)
    {
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (A[m] >= key)
                r = m;
            else
                l = m;
        }
 
        return r;
    }
 
    static int f(int A[], int size)
    {
        

 
        int[] tailTable = new int[size];
        int len; 

 
        tailTable[0] = A[0];
        len = 1;
        for (int i = 1; i < size; i++) {
            if (A[i] < tailTable[0])
                

                tailTable[0] = A[i];
 
            else if (A[i] > tailTable[len - 1])
                

                tailTable[len++] = A[i];
 
            else
                

                

                tailTable[CeilIndex(tailTable, -1, len - 1, A[i])] = A[i];
        }
 
        return len;
    }
	static int containsBoth(char X[],int N)
	{
		for(int i=1; i<N; i++)if(X[i]!=X[i-1])return i-1;
		return -1;
	}
	static void f(char X[],int N,int A[])
	{
		int c=0;
		for(int i=N-1; i>=0; i--)
		{
			if(X[i]=='1')
			{
				A[i]=c;
			}
			else c++;
			A[i]+=A[i+1];
		}
	}
	static int f(int i,int j,char X[],char Y[],int zero)
	{
		if(i==X.length && j==Y.length)return 0;
		if(i==X.length)return iv_B[j]; 

		if(j==Y.length)return iv_A[i];
		if(dp[i][j]==-1)
		{
			int cost_x=0,cost_y=0;
			if(X[i]=='1')
			{
				cost_x=zero+f(i+1,j,X,Y,zero);
			}
			else cost_x=f(i+1,j,X,Y,zero-1);
			if(Y[j]=='1')
			{
				cost_y=zero+f(i,j+1,X,Y,zero);
			}
			else cost_y=f(i,j+1,X,Y,zero-1);
			dp[i][j]=Math.min(cost_x, cost_y);
		}
		return dp[i][j];
	}
	static boolean f(long last,long next,long l,long r,long A,long B)
	{
		while(l<=r)
		{
			long m=(l+r)/2;
			long s=((m)*(m-1))/2;
			long l1=(A*m)+s,r1=(m*B)-s;
			if(Math.min(next, r1)<Math.max(last, l1))
			{
				if(l1>last)r=m-1;
				else l=m+1;
			}
			else return true;
		}
		return false;
	}
	static boolean isVowel(char x)
	{
		if(x=='a' || x=='e' || x=='i' ||x=='u' || x=='o')return true;
		return false;
	}
	static boolean f(int i,int j)
	{
		

		

		if(i==0 && j==0)return true; 


		if(dp[i][j]==-1)
		{
			boolean f=false;
			if(i>0)
			{
				if(!f(i-1,j))f=true;
			}
			if(j>0)
			{
				if(!f(i,j-1) && !f(i+1,j-1))f=true;
			}

			if(f)dp[i][j]=1;
			else dp[i][j]=0;
		}


		return dp[i][j]==1;

	}
	static int last=-1;
	static void dfs(int n,int p)
	{
		last=n;
		System.out.println("n--> "+n+" p--> "+p);
		for(int c:g[n])
		{
			if(c!=p)dfs(c,n);
		}
	}
	static long abs(long a,long b)
	{
		return Math.abs(a-b);
	}
	static int lower(long A[],long x)
	{
		int l=0,r=A.length;
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(A[m]<=x)l=m;
			else r=m;
		}
		return l;
	}


	static int f(int i,int s,int j,int N,int A[],HashMap<Integer,Integer> mp)
	{
		if(i==N) 
		{
			return s;
		}
		if(dp[i][j]==-1)
		{
			if(mp.containsKey(A[i]))
			{
				int f=mp.get(A[i]);
				int c=0;
				if(f==1)c++;
				mp.put(A[i], f+1);
				HashMap<Integer,Integer> temp=new HashMap<>();
				temp.put(A[i],1);
				return dp[i][j]=Math.min(f(i+1,s+1+c,j,N,A,mp), s+K+f(i+1,0,i,N,A,temp));			   
			}
			else 
			{
				mp.put(A[i],1);
				return dp[i][j]=f(i+1,s,j,N,A,mp);
			}
		}
		return dp[i][j];
	}

	static boolean inRange(int a,int l,int r)
	{
		if(l<=a && r>=a)return true;
		return false;
	}


	static long f(long a,long b)
	{
		if(a%b==0)return a/b;
		else return (a/b)+f(b,a%b);
	}
	static void f(int index,long A[],int i,long xor)
	{
		if(index+1==A.length)
		{
			if(valid(xor^A[index],i))
			{
				xor=xor^A[index];
				max=Math.max(max, i);

			}
			return;
		}
		if(dp[index][i]==0)
		{
			dp[index][i]=1;
			if(valid(xor^A[index],i))
			{
				f(index+1,A,i+1,0);
				f(index+1,A,i,xor^A[index]);							    
			}
			else
			{
				f(index+1,A,i,xor^A[index]);				 
			}
		}

	}
	static boolean valid(long xor,int i)
	{
		if(xor==0)return true;
		while(xor%2==0 )
		{
			xor/=2;
			i--;
		}
		return i<=0;
	}
	static int next(int i,long pre[],long S)
	{
		int l=i,r=pre.length;
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(pre[m]-pre[i-1]>S)r=m;
			else l=m;
		}
		return r;
	}
	static boolean lexo(long A[],long B[])
	{
		for(int i=0; i<A.length; i++)
		{
			if(B[i]>A[i])return true;
			if(A[i]>B[i])return false;
		}
		return false;
	}
	static long [] f(long A[],long B[],int j)
	{
		int N=A.length;
		long X[]=new long[N];
		for(int i=0; i<N; i++)
		{
			X[i]=(B[j]+A[i])%N;
			j++;
			j%=N;
		}
		return X;
	}
	static int find(int a)
	{
		if(par[a]<0)return a;
		return par[a]=find(par[a]);
	}
	static void union(int a,int b)
	{
		b=find(b);
		a=find(a);
		if(a!=b)
		{
			par[b]=a;
		}
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
	static void print(ArrayList<Integer> A)
	{
		for(int a:A)System.out.print(a+" ");
		System.out.println();
	}
	static long lower_Bound(long A[],int low,int high, long x) 
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
	static void sort(long[] a) 

	{
		ArrayList<Long> l=new ArrayList<>();
		for (long i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	static void setGraph(int N)
	{
		size=new int[N+1];
		

		g=new ArrayList[N+1];
		for(int i=0; i<=N; i++)
		{
			g[i]=new ArrayList<>();
		}
	}

	static  long pow(long a,long b)
	{
		long pow=1L;
		long x=a;
		while(b!=0)
		{
			if((b&1)!=0)pow=(pow*x)%mod;
			x=(x*x)%mod;
			b/=2;
		}
		return pow;
	}
	static long toggleBits(int x)

	{
		int n=(int)(Math.floor(Math.log(x)/Math.log(2)))+1;

		return ((1<<n)-1)^x;
	}
	static int countBits(long a)
	{
		return (int)(Math.log(a)/Math.log(2)+1);
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
		if (N%2 == 0 || N%3 == 0) return false; 
		for (int i=5; i*i<=N; i=i+6) 
			if (N%i == 0 || N%(i+2) == 0) 
				return false; 
		return true; 
	}
	static long GCD(long a,long b) 
	{
		if(b==0)
		{
			return a;
		}
		else return GCD(b,a%b );
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