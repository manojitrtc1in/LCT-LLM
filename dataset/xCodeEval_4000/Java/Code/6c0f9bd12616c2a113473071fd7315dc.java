import java.util.*;
import java.io.*;

public class Main {
    static FastReader sc=new FastReader();
	static PrintWriter out=new PrintWriter(System.out);
	static int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
	static final double pi=3.1415926536;
	static long mod=1000000007;
	

	static int MAX=Integer.MAX_VALUE;
	static int MIN=Integer.MIN_VALUE;
	static long MAXL=Long.MAX_VALUE;
	static long MINL=Long.MIN_VALUE;
	static ArrayList<Integer> graph[];
	static long fact[];
	static long seg[];
	

	static long dp[][];
	public static void main (String[] args) throws java.lang.Exception
	{
		

		int t=I();
		outer:while(t-->0)
		{
			int n=2;
			int m=I();
			long a[][]=new long[n][m];
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					a[i][j]=L();
				}
			}
			long time[][]=new long[n][m];

			time[0][m-1]=a[0][m-1];
			if(a[0][m-1]>=a[1][m-1]){
				time[0][m-1]++;
			}else{
				time[0][m-1]+=a[1][m-1]-a[0][m-1];
				time[0][m-1]++;
			}
			

			time[1][m-1]=a[1][m-1];
			if(a[1][m-1]>=a[0][m-1]){
				time[1][m-1]++;
			}else{
				time[1][m-1]+=a[0][m-1]-a[1][m-1];
				time[1][m-1]++;
			}



			for(int j=m-2;j>=0;j--){
				long temp=0;
				if(a[0][j]<=a[0][j+1]){
					temp=a[0][j+1]+1;
				}else{
					temp=a[0][j]+1;
				}
				long time1=temp+(2*(m-j-1));
				long time2=time[0][j+1];
				

				

				

				

				

				

				if(time[0][j+1]>=a[1][j]){
					time2++;
				}else{
					time2+=a[1][j]-time[0][j+1];
					time2++;
				}
				time[0][j]=max(time1,time2);
				

				temp=0;
				if(a[1][j]<=a[1][j+1]){
					temp=a[1][j+1]+1;
				}else{
					temp=a[1][j]+1;
				}
				time1=temp+(2*(m-j-1));
				time2=time[1][j+1];
				if(time[1][j+1]>=a[0][j]){
					time2++;
				}else{
					time2+=a[0][j]-time[1][j+1];
					time2++;
				}
				time[1][j]=max(time1,time2);

			}
			long ans=MAXL;
			long timee=0;
			for(int j=0;j<m;j++){
				if(j%2==0){

					long time1=timee+(2*(m-j-1)+1);
					long time2=time[0][j];

					ans=min(ans,max(time1,time2));


					if(timee>=a[1][j]){
						timee++;
					}else{
						timee+=a[1][j]-timee;
						timee++;
					}
					if(j<m-1)
					if(timee>=a[1][j+1]){
						timee++;
					}else{
						timee+=a[1][j+1]-timee;
						timee++;
					}
				}else{

					long time1=timee+(2*(m-j-1)+1);
					long time2=time[1][j];

					ans=min(ans,max(time1,time2));

					
					if(timee>=a[0][j]){
						timee++;
					}else{
						timee+=a[0][j]-timee;
						timee++;
					}
					if(j<m-1)
					if(timee>=a[0][j+1]){
						timee++;
					}else{
						timee+=a[0][j+1]-timee;
						timee++;
					}
				}
			}
			out.println(ans);
		}
		out.close();
	}
	public static class pair
    {
    	int a;
    	int b;
    	public pair(int aa,int bb)
    	{
    	    a=aa;
    	    b=bb;
    	}
    }
	public static class myComp implements Comparator<pair>
	{
		

		

		

		

    	

    	

    	

    	

    	

		

		

		public int compare(pair p1,pair p2)
    	{
    	    if(p1.b==p2.b)
    	    return 0;
    	    else if(p1.b<p2.b)
    	    return 1;
    	    else
    	    return -1;
    	}
	}
	public static void setGraph(int n,int m)throws IOException
	{
		graph=new ArrayList[n+1];
		for(int i=0;i<=n;i++){
			graph[i]=new ArrayList<>();
		}
		for(int i=0;i<m;i++){
			int u=I(),v=I();
			graph[u].add(v);
			graph[v].add(u);
		}
	}
	
	


	

	public static int lower_bound(ArrayList<Long> arr,long X,int start, int end)   

	{
		if(start>end)return -1;
		if(arr.get(end)<X)return end;
		

		if(arr.get(start)>X)return -1;
		

		int left=start,right=end;
		while(left<right){
			int mid=(left+right)/2;

			

			if(arr.get(mid)==X){                                    

				

				if(mid<end && arr.get(mid+1)==X){
					left=mid+1;
				}else{
					return mid;
				}
			}

			

			

			

			

			

			

			

			

			


			

			else if(arr.get(mid)>X){
				

				if(mid>start && arr.get(mid-1)<X){
					return mid-1;
				}else{
					right=mid-1;
				}
			}else{
				

				if(mid<end && arr.get(mid+1)>X){
					return mid;
				}else{
					left=mid+1;
				}
			}
		}
		return left;
	}
	

	public static int upper_bound(ArrayList<Integer> arr,int X,int start,int end)			

	{
		if(arr.get(0)>=X)return start;
		if(arr.get(arr.size()-1)<X)return -1;
		int left=start,right=end;
		while(left<right){
			int mid=(left+right)/2;
			if(arr.get(mid)==X){                                   

				if(mid>start && arr.get(mid-1)==X){
					right=mid-1;
				}else{
					return mid;
				}
			}
			

			

			

			

			

			

			

			else if(arr.get(mid)>X){
				if(mid>start && arr.get(mid-1)<X){
					return mid;
				}else{
					right=mid-1;
				}
			}else{
				if(mid<end && arr.get(mid+1)>X){
					return mid+1;
				}else{
					left=mid+1;
				}
			}
		}
		return left;
	}

	


	

	public static void buildTree(long a[],int si,int ss,int se)
	{
		if(ss==se){
			seg[si]=a[ss];
			return;
		}
		int mid=(ss+se)/2;
		buildTree(a,2*si+1,ss,mid);
		buildTree(a,2*si+2,mid+1,se);
		seg[si]=max(seg[2*si+1],seg[2*si+2]);
	}
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	public static long query1(int si,int ss,int se,int qs,int qe)
	{
		if(qs>se || qe<ss)return 0;
		if(ss>=qs && se<=qe)return seg[si];
		int mid=(ss+se)/2;
		long p1=query1(2*si+1,ss,mid,qs,qe);
		long p2=query1(2*si+2,mid+1,se,qs,qe);
		return max(p1,p2);
		
	}
	
	public static void merge(ArrayList<Integer> f,ArrayList<Integer> a,ArrayList<Integer> b)
	{
		int i=0,j=0;
		while(i<a.size() && j<b.size()){
			if(a.get(i)<=b.get(j)){
				f.add(a.get(i));
				i++;
			}else{
				f.add(b.get(j));
				j++;
			}
		}
		while(i<a.size()){
			f.add(a.get(i));
			i++;
		}
		while(j<b.size()){
			f.add(b.get(j));
			j++;
		}
	}

	


	

	public static int[] KMP(char c[],int n)
	{
		int pi[]=new int[n];
		for(int i=1;i<n;i++){
			int j=pi[i-1];
			while(j>0 && c[i]!=c[j]){
				j=pi[j-1];
			}
			if(c[i]==c[j])j++;
			pi[i]=j;
		}
		return pi;
	}
	public static long kadane(long a[],int n)  

	{
		long max_sum=Long.MIN_VALUE,max_end=0;
		for(int i=0;i<n;i++){
			max_end+=a[i];
			if(max_sum<max_end){max_sum=max_end;}
			if(max_end<0){max_end=0;}
		}
		return max_sum;
	}
	
	public static long nPr(int n,int r)
	{
		long ans=divide(fact(n),fact(n-r),mod);
		return ans;
	}
	public static long nCr(int n,int r)
	{
		long ans=divide(fact[n],mul(fact[n-r],fact[r]),mod);
		return ans;
	}

	public static boolean isSorted(int a[])
	{
		int n=a.length;
		for(int i=0;i<n-1;i++){
			if(a[i]>a[i+1])return false;
		}
		return true;
	}
	public static boolean isSorted(long a[])
	{
		int n=a.length;
		for(int i=0;i<n-1;i++){
			if(a[i]>a[i+1])return false;
		}
		return true;
	}
	public static int computeXOR(int n) 

    {
        if (n % 4 == 0)
            return n;
        if (n % 4 == 1)
            return 1;
        if (n % 4 == 2)
            return n + 1;
        return 0;
    }
	public static int np2(int x)
	{
		x--;
		x |= x >> 1;
		x |= x >> 2;
		x |= x >> 4;
		x |= x >> 8;
		x |= x >> 16;
		x++;
		return x;
	}
	public static int hp2(int x)
	{
		x |= x >> 1;
		x |= x >> 2;
		x |= x >> 4;
		x |= x >> 8;
		x |= x >> 16;	
		return x ^ (x >> 1); 
	}
	public static long hp2(long x)
	{
		x |= x >> 1;
		x |= x >> 2;
		x |= x >> 4;
		x |= x >> 8;
		x |= x >> 16;
		return x ^ (x >> 1); 
	}
	public static ArrayList<Integer> primeSieve(int n)
	{
	    ArrayList<Integer> arr=new ArrayList<>();
	    boolean prime[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
        prime[i] = true;
        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n; i += p)
                prime[i] = false;
            }
        }
        for (int i = 2; i <= n; i++)
        {
            if (prime[i] == true)
            arr.add(i);
        }
        return arr;
	}
	
	

	public static class FenwickTree
	{
		int farr[];
		int n;
		public FenwickTree(int c)
		{
			n=c+1;
			farr=new int[n];
		}
		

		

		

		

		

		public void update(int x,int p)
		{
			for(;x<n;x+=x&(-x))
			{
				farr[x]+=p;
			}
		}
		public int get(int x)
		{
			int ans=0;
			for(;x>0;x-=x&(-x))
			{
				ans=ans+farr[x];
			}
			return ans;
		}
	}
	

	public static class DSU
	{
	    int par[],rank[];
	    public DSU(int c)
	    {
	        par=new int[c+1];
	        rank=new int[c+1];
	        for(int i=0;i<=c;i++)
	        {
	            par[i]=i;
	            rank[i]=0;
	        }
	    }
	    public int find(int a)
	    {
	        if(a==par[a])
	        return a;
	        return par[a]=find(par[a]);
	    }
	    public void union(int a,int b)
	    {
	        int a_rep=find(a),b_rep=find(b);
	        if(a_rep==b_rep)
	        return;
	        if(rank[a_rep]<rank[b_rep])
	        par[a_rep]=b_rep;
	        else if(rank[a_rep]>rank[b_rep])
	        par[b_rep]=a_rep;
	        else
	        {
	            par[b_rep]=a_rep;
	            rank[a_rep]++;
	        }
	    }
	}
	public static HashMap<Integer,Integer> primeFact(int a)
	{
	    

		HashMap<Integer,Integer> hm=new HashMap<>();
		int p=0;
	    while(a%2==0){
	        

			p++;
	        a=a/2;
	    }
		hm.put(2,hm.getOrDefault(2,0)+p);
	    for(int i=3;i*i<=a;i+=2){
			p=0;
	        while(a%i==0){
	            

				p++;
	            a=a/i;
	        }
			hm.put(i,hm.getOrDefault(i,0)+p);
	    }
	    if(a>2){
			

			hm.put(a,hm.getOrDefault(a,0)+1);
		}
	    

		return hm;
	}
	public static boolean isVowel(char c)
	{
		if(c=='a' || c=='e' || c=='i' || c=='u' || c=='o')return true;
		return false;
	}
	public static boolean isInteger(double N)
	{
		int X = (int)N;
		double temp2 = N - X;
		if (temp2 > 0)
		{
			return false;
		}
		return true;
	}
	public static boolean isPalindrome(String s)
	{
		int n=s.length();
		for(int i=0;i<=n/2;i++){
			if(s.charAt(i)!=s.charAt(n-i-1)){
				return false;
			}
		}
		return true;
	}
	public static int gcd(int a,int b)
	{
	    if(b==0)
	    return a;
	    else
	    return gcd(b,a%b);
	}
	public static long gcd(long a,long b)
	{
	    if(b==0)
	    return a;
	    else
	    return gcd(b,a%b);
	}
	public static long fact(long n)
	{
		long fact=1;
		for(long i=2;i<=n;i++){
			fact=((fact%mod)*(i%mod))%mod;
		}
		return fact;
	}
	public static long fact(int n)
	{
		long fact=1;
		for(int i=2;i<=n;i++){
			fact=((fact%mod)*(i%mod))%mod;
		}
		return fact;
	} 
	public static boolean isPrime(int n) 
	{ 
	    if (n <= 1) 
	        return false; 
	    if (n <= 3) 
	        return true; 
	    if (n % 2 == 0 || n % 3 == 0) 
	        return false; 
	    double sq=Math.sqrt(n);
	  
	    for (int i = 5; i <= sq; i = i + 6) 
	        if (n % i == 0 || n % (i + 2) == 0) 
	            return false; 
	    return true; 
	} 
    public static boolean isPrime(long n) 
	{ 
	    if (n <= 1) 
	        return false; 
	    if (n <= 3) 
	        return true; 
	    if (n % 2 == 0 || n % 3 == 0) 
	        return false; 
	    double sq=Math.sqrt(n);
	
	    for (int i = 5; i <= sq; i = i + 6) 
	        if (n % i == 0 || n % (i + 2) == 0) 
	            return false; 
	    return true; 
	}
	public static void printArray(long a[])
	{
		for(int i=0;i<a.length;i++){
			out.print(a[i]+" ");
		}
		out.println();
	}
	public static void printArray(int a[])
	{
		for(int i=0;i<a.length;i++){
			out.print(a[i]+" ");
		}
		out.println();
	}
	public static void printArray(char a[])
	{
		for(int i=0;i<a.length;i++){
			out.print(a[i]);
		}
		out.println();
	}
	public static void printArray(String a[])
	{
		for(int i=0;i<a.length;i++){
			out.print(a[i]+" ");
		}
		out.println();
	}
	public static void printArray(boolean a[])
	{
		for(int i=0;i<a.length;i++){
			out.print(a[i]+" ");
		}
		out.println();
	}
	public static void printArray(pair a[])
	{
		for(pair p:a){
			out.println(p.a+"->"+p.b);
		}
	}
	public static void printArray(int a[][])
	{
		for(int i=0;i<a.length;i++){
			for(int j=0;j<a[i].length;j++){
				out.print(a[i][j]+" ");
			}out.println();
		}
	}
	public static void printArray(boolean a[][])
	{
		for(int i=0;i<a.length;i++){
			for(int j=0;j<a[i].length;j++){
				out.print(a[i][j]+" ");
			}out.println();
		}
	}
	public static void printArray(long a[][])
	{
		for(int i=0;i<a.length;i++){
			for(int j=0;j<a[i].length;j++){
				out.print(a[i][j]+" ");
			}out.println();
		}
	}
	public static void printArray(char a[][])
	{
		for(int i=0;i<a.length;i++){
			for(int j=0;j<a[i].length;j++){
				out.print(a[i][j]+" ");
			}out.println();
		}
	}
	public static void printArray(ArrayList<?> arr)
	{
		for(int i=0;i<arr.size();i++){
			out.print(arr.get(i)+" ");
		}
		out.println();
	}
	public static void printMapI(HashMap<?,?> hm){
		for(Map.Entry<?,?> e:hm.entrySet()){
			out.println(e.getKey()+"->"+e.getValue());
		}out.println();
	}
	public static void printMap(HashMap<Long,ArrayList<Integer>> hm){
		for(Map.Entry<Long,ArrayList<Integer>> e:hm.entrySet()){
			out.print(e.getKey()+"->");
			ArrayList<Integer> arr=e.getValue();
			for(int i=0;i<arr.size();i++){
				out.print(arr.get(i)+" ");
			}out.println();
		}
	}
	public static void printGraph(ArrayList<Integer> graph[])
	{
		int n=graph.length;
		for(int i=0;i<n;i++){
			out.print(i+"->");
			for(int j:graph[i]){
				out.print(j+" ");
			}out.println();
		}
	}

	


	public static long add(long a,long b)
	{
		a+=b;
		if(a>=mod)a-=mod;
		return a;
	}
	public static long sub(long a,long b)
	{
		a-=b;
		if(a<0)a+=mod;
		return a;
	}
	public static long mul(long a,long b)
	{
		return ((a%mod)*(b%mod))%mod;
	}
	public static long divide(long a,long b,long m)
	{
		a=mul(a,modInverse(b,m));
		return a;
	}
	public static long modInverse(long a,long m)
	{
		int x=0,y=0;
		own p=new own(x,y);
		long g=gcdExt(a,m,p);
		if(g!=1){
			out.println("inverse does not exists");
			return -1;
		}else{
			long res=((p.a%m)+m)%m;
			return res;
		}
	}
	public static long gcdExt(long a,long b,own p)
	{
		if(b==0){
			p.a=1;
			p.b=0;
			return a;
		}
		int x1=0,y1=0;
		own p1=new own(x1,y1);
		long gcd=gcdExt(b,a%b,p1);
		p.b=p1.a - (a/b) * p1.b;
		p.a=p1.b;
		return gcd;
	}
	public static long pwr(long m,long n)
	{
		long res=1;
		if(m==0)
		return 0;
		while(n>0)
		{
			if((n&1)!=0)
			{
				res=(res*m);
			}
			n=n>>1;
			m=(m*m);
		}
		return res;
	}
	public static long modpwr(long m,long n)
	{
		long res=1;
		m=m%mod;
		if(m==0)
		return 0;
		while(n>0)
		{
			if((n&1)!=0)
			{
				res=(res*m)%mod;
			}
			n=n>>1;
			m=(m*m)%mod;
		}
		return res;
	}
	public static class own
    {
    	long a;
    	long b;
    	public own(long val,long index)
    	{
    	    a=val;
    	    b=index;
    	}
    }

	


	public static void sort(int[] A)
	{
        int n = A.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i)
		{
            int tmp = A[i];
            int randomPos = i + rnd.nextInt(n-i);
            A[i] = A[randomPos];
            A[randomPos] = tmp;
        }
        Arrays.sort(A);
    }
	public static void sort(char[] A)
	{
        int n = A.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i)
		{
            char tmp = A[i];
            int randomPos = i + rnd.nextInt(n-i);
            A[i] = A[randomPos];
            A[randomPos] = tmp;
        }
        Arrays.sort(A);
    }
    public static void sort(long[] A)
	{
	    int n = A.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i)
		{
            long tmp = A[i];
            int randomPos = i + rnd.nextInt(n-i);
            A[i] = A[randomPos];
            A[randomPos] = tmp;
        }
	    Arrays.sort(A);
	}

	

	public static int max(int a,int b){return Math.max(a,b);}
	public static int min(int a,int b){return Math.min(a,b);}
	public static int max(int a,int b,int c){return Math.max(a,Math.max(b,c));}
	public static int min(int a,int b,int c){return Math.min(a,Math.min(b,c));}
	public static long max(long a,long b){return Math.max(a,b);}
	public static long min(long a,long b){return Math.min(a,b);}
	public static long max(long a,long b,long c){return Math.max(a,Math.max(b,c));}
	public static long min(long a,long b,long c){return Math.min(a,Math.min(b,c));}
	public static int maxinA(int a[]){int n=a.length;int mx=a[0];for(int i=1;i<n;i++){mx=max(mx,a[i]);}return mx;}
	public static long maxinA(long a[]){int n=a.length;long mx=a[0];for(int i=1;i<n;i++){mx=max(mx,a[i]);}return mx;}
	public static int mininA(int a[]){int n=a.length;int mn=a[0];for(int i=1;i<n;i++){mn=min(mn,a[i]);}return mn;}
	public static long mininA(long a[]){int n=a.length;long mn=a[0];for(int i=1;i<n;i++){mn=min(mn,a[i]);}return mn;}
	public static long suminA(int a[]){int n=a.length;long sum=0;for(int i=0;i<n;i++){sum+=a[i];}return sum;}
	public static long suminA(long a[]){int n=a.length;long sum=0;for(int i=0;i<n;i++){sum+=a[i];}return sum;}
	


	public static int[] I(int n){int a[]=new int[n];for(int i=0;i<n;i++){a[i]=I();}return a;}
	public static long[] IL(int n){long a[]=new long[n];for(int i=0;i<n;i++){a[i]=L();}return a;}
	public static long[] prefix(int a[]){int n=a.length;long pre[]=new long[n];pre[0]=a[0];for(int i=1;i<n;i++){pre[i]=pre[i-1]+a[i];}return pre;}
	public static long[] prefix(long a[]){int n=a.length;long pre[]=new long[n];pre[0]=a[0];for(int i=1;i<n;i++){pre[i]=pre[i-1]+a[i];}return pre;}

	public static int I(){return sc.I();}
    public static long L(){return sc.L();}
    public static String S(){return sc.S();}
    public static double D(){return sc.D();}
}
class FastReader {  
    BufferedReader br;
    StringTokenizer st;
    public FastReader(){
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    String next(){
        while (st == null || !st.hasMoreElements()){
            try {
                st = new StringTokenizer(br.readLine());
            }
            catch (IOException e){
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }
    int I(){ return Integer.parseInt(next());}
    long L(){ return Long.parseLong(next());}
    double D(){return Double.parseDouble(next());}
    String S(){
        String str = "";
        try {
            str = br.readLine();
        }
        catch (IOException e){
            e.printStackTrace();
        }
        return str;
    }
}
