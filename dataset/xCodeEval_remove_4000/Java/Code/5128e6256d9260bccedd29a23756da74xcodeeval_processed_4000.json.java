import java.io.*;
import java.lang.*;
import java.util.*;

public class id1 {
	
	public static boolean dp[][];
	public static char pp='0';
	public static void main(String[] args) throws Exception{
		

		FastReader sc=new FastReader();
		BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
		
		 
		 int t=sc.nextInt();
		 
	     while(t--!=0) {
	    	long n=sc.nextLong();
	        long k=sc.nextLong();
	        int bn[]=new int[50];
	        int i=0;
	        while(k!=0) {
	        	long temp=(long)(k&1);
	        	if(temp==1)bn[i]=1;
	        	i++;
	        	k/=(long)2;
	        }
	        long cnt=1;
	        long ans=0;
	        for(int j=0;j<i;j++) {
	        	if(bn[j]==1)ans=add(ans,cnt);
	        	cnt=mul(cnt,n);
	        }
	        log.write(ans+"\n");
	     log.flush();
	     }
		   
		        
		   }
		     
		     
		      
		       
	public static class cls{
		String s;
		public cls(String s) {
			this.s=s;
		}
		public int ct(cls q,char pp) {


			char p[]=this.s.toCharArray();
			char t[]=q.s.toCharArray();
			int cnt1=0,cnt2=0;
			for(int i=0;i<p.length;i++)if(p[i]==pp)cnt1++;
			for(int i=0;i<t.length;i++)if(t[i]==pp)cnt2++;
			int vl1=p.length-cnt1;
			int vl2=t.length-cnt2;
			int cont=cnt1-vl1;
			int cont2=cnt2-vl2;
			return cont2-cont;
			
		}
		public String toString() {
			return this.s;
		}
	}			   
		   
			
		
public static class clss{
	ArrayList<Integer> ad;
	int n;
	public  clss(ArrayList<Integer> ad,int n) {
		this.ad=ad;
		this.n=n;
	}
	public int compareTo(clss t) {
		long sum=0;
		long sum2=0;
		for(int i=0;i<this.ad.size();i++) {
			sum+=this.ad.get(i);
			sum2+=t.ad.get(i);
		}
		if(sum<sum2)return -1;
		else if(sum==sum2)return 0;
		else return 1;
		
	}
}
public static boolean ch(char a[],char b[], int i,int j) {
	if(i<0) {
		if(j<0)return true;
		return false;
	}
	if(j<0)return true;
	if(dp[i][j])return dp[i][j];
	if(a[i]==b[j])return dp[i][j]=ch(a,b,i-1,j-1) || ch(a,b,i-2,j);
	else return dp[i][j]=ch(a,b,i-2,j);
}	
public static void id4(int a[]) {
	int n=a.length;
	int res[]=new int[n];
	
	int p=1;

	for(int i=0;i<=8;i++) {
		int cnt[]=new int[10];
	     for(int j=0;j<n;j++) {
	    	 a[j]=res[j];
	    	 cnt[(a[j]/p)%10]++;
	    	
	     }
	     for(int j=1;j<=9;j++) {
	    	 cnt[j]+=cnt[j-1];
	     }
	     
	     for(int j=n-1;j>=0;j--) {
	        res[cnt[(a[j]/p)%10]-1]=a[j];
	        cnt[(a[j]/p)%10]--;
	     }
	     
	     p*=10;
		
	}
	
	
}
static void dfs(ArrayList<ArrayList<Integer>> ar,int src,int vis[],int col) {
	vis[src]=col;
	for(int i=0;i<ar.get(src).size();i++) {
		if(vis[ar.get(src).get(i)]==0) {
			dfs(ar,ar.get(src).get(i),vis,col);
		}
	}
}	
static ArrayList<ArrayList<Integer>> initGraph(int n){
	ArrayList<ArrayList<Integer>> ar=new ArrayList<>();
	for(int i=0;i<=n;i++) {
		ar.add(new ArrayList<>());
	}
	return ar;
}	
static void undirected(ArrayList<ArrayList<Integer>> a, int n) {
	FastReader sc=new FastReader();
	for(int i=0;i<n;i++) {


		int p=sc.nextInt();
		int q=sc.nextInt();
		a.get(p).add(q);
		a.get(q).add(p);
	}
}
static int eval(ArrayList<Long> ar, long n, int j) {
	if(j<0)return bits(n);
	if(n==0)return 0;
	if(n-ar.get(j)>=0) {
		return Math.min(eval(ar,n,j-1), 1+eval(ar,n-ar.get(j),j-1));
	}
	return eval(ar,n,j-1);
	
}	
static int bits(long n) {
	int ans=0;
	while(n!=0) {
		if((n&1)==1)ans++;
		n>>=1;
	}
	return ans;
}	
static long flor(ArrayList<Long> ar,long el) {
	int s=0;
	int e=ar.size()-1;
	while(s<=e) {
		int m=s+(e-s)/2;
		if(ar.get(m)==el)return ar.get(m);
		else if(ar.get(m)<el)s=m+1;
		else e=m-1;
	}
	return e>=0?e:-1;
}	
















public static int kadane(int a[]) {
	int sum=0,mx=Integer.MIN_VALUE;
	for(int i=0;i<a.length;i++) {
		sum+=a[i];
		mx=Math.max(mx, sum);
		if(sum<0) sum=0;
		 
	}
	return mx;
}	
public static int rec( int l,int[] dp) {
	if(l<=2)return 1;
	if(dp[l]!=0)return dp[l];
	int f=0,s=0;
	if(dp[l-1]!=0)f=dp[l-1];
	else f=rec(l-1,dp);
	if(dp[l-2]!=0)s=dp[l-2];
	else s=rec(l-2,dp);
	return dp[l]=add(f,s);
	
}	
public static int m=1000000007;	
public static int mul(int a, int b) {
	return ((a%m)*(b%m))%m;
}
public static long mul(long a, long b) {
	return ((a%m)*(b%m))%m;
}
public static int add(int a, int b) {
	return ((a%m)+(b%m))%m;
}
public static long add(long a, long b) {
	return ((a%m)+(b%m))%m;
}
public static String rever(String s) {
	char a[]=s.toCharArray();
	for(int i=0;i<a.length/2;i++) {
		char temp=a[i];
		a[i]=a[a.length-1-i];
		a[a.length-1-i]=temp;
	}
	return String.valueOf(a);
}	


























static int subset(int a[],int j,int dp[][], int sum) {
	if(j==0) {
		if(sum==0 || sum-a[j]==0)return 1;
		else return 0;
	}
	if(sum==0)return 1;
	if(dp[j][sum]>0)return dp[j][sum];


	if(sum-a[j]>=0) {
		int p=subset(a,j-1,dp,sum-a[j]);
		int q=subset(a,j-1,dp,sum);
		return dp[j][sum]=p+q;
	}
	else{
		return dp[j][sum]=subset(a,j-1,dp,sum);
	}

	
}
static long slv(int a[],int b[],long dp[][],int end,int k,int i) {
	if(i<1 ) {
		if(k==0) {
			return (end-a[0])*b[0];
		}
		else return Integer.MAX_VALUE;
	}
	if(k<0)return Integer.MAX_VALUE;
	if(k==0) {
		return (end-a[0])*b[0];
	}
	if(dp[i][k]!=0)return dp[i][k];
	long ans1=slv(a,b,dp,a[i],k-1,i-1);
	long ans2=slv(a,b,dp,end,k,i-1);
	long val=(end-a[i])*b[i];
	return dp[i][k]=Math.min(val+ans1,ans2);
}	
static int bss(int[] a,int s, long k) {
	int e=a.length-1;


	while(s<=e) {
		int m=s+(e-s)/2;
	
		if(a[m]==k) {
			
			return m;
		}
		else if(a[m]<k)s=m+1;
		else e=m-1;
	}
	return -1;
}
static int solv(int[] a,int len) {
	if(len%2==0) {
		int ans=0;
		for(int i=0;i<a.length;i++){
			if(a[i]>0){
				if(a[i]%2==0) {
					ans+=a[i];
				}
				else if(a[i]%2!=0) {
					ans+=(a[i]/2)*2;
				}
				
			}
			
		}
		int cnt=ans/len;
		return cnt;
	}
	else {
		int ans=0,one=0;
		for(int i=0;i<a.length;i++){
			if(a[i]>0){
				if(a[i]%2==0) {
					ans+=a[i];
				}
				else {
					ans+=(a[i]/2)*2;
					one++;
				}
				
			}
		}
		int n=len-1;
		int cnt=ans/n;
		int mod=cnt%n+one;
		if(cnt>=mod)return cnt;
		return mod;
		
		
		
	}
}


static pair bss(ArrayList<pair> a,int el,int ind) {
	int s=0;
	int e=a.size()-1;
	pair ans=new pair(-1,-1);
	while(s<=e) {
		int m=s+(e-s)/2;
		if(a.get(m).a==el) {
			ans=a.get(m);
			e=m-1;
		}
		if(a.get(m).a>el)e=m-1;
		else s=m+1;
	}
	return ans;
}
public static <E> void p(E[][] a,String s) {
	   System.out.println(s);
	   for(int i=0;i<a.length;i++) {
		   for(int j=0;j<a[0].length;j++) {
			   System.out.print(a[i][j]+" ");
		   }
		   System.out.println();
	   }
	  
}
public static  void p(int[] a,String s) {
	System.out.print(s+"=");
	for(int i=0;i<a.length;i++)System.out.print(a[i]+" ");
	System.out.println();
}
public static  void p(long[] a,String s) {
	System.out.print(s+"=");
	for(int i=0;i<a.length;i++)System.out.print(a[i]+" ");
	System.out.println();
}
public static <E> void p(E a,String s){
	System.out.println(s+"="+a);
}
public static <E> void p(ArrayList<E> a,String s){
	System.out.println(s+"="+a);
}
public static <E> void p(LinkedList<E> a,String s){
	System.out.println(s+"="+a);
}
public static <E> void p(HashSet<E> a,String s){
	System.out.println(s+"="+a);
}
public static <E> void p(Stack<E> a,String s){
  System.out.println(s+"="+a);
}
public static <E> void p(Queue<E> a,String s){
	System.out.println(s+"="+a);
}



static ArrayList<Integer> id0(int n){
	
	ArrayList<Integer> ar=new ArrayList<>();
     for (int i=2; i<=Math.sqrt(n); i++){
	        if (n%i == 0){
	            if (n/i == i) {
	            	ar.add(i);
	            }
	            else {
	               ar.add(i);
	               ar.add(n/i);
	            }
	         }
       }
	return ar;
}
static int id3(int n){
	ArrayList<Integer> ar=new ArrayList<>();
	int cnt=0;
	boolean pr=false;
	while(n%2==0) {
		pr=true;
		n/=2;
		
	}
	if(pr)ar.add(2);
	for(int i=3;i*i<=n;i+=2) {
		pr=false;
		while(n%i==0) {
			n/=i;
			pr=true;
		}
		if(pr)ar.add(i);
	}
	if(n>2) ar.add(n);
	return ar.size();
	
}
	
static char[] rev(char s[]) {
	char temp[]=s;
	for(int i=0;i<temp.length/2;i++) {
		char tp=temp[i];
		temp[i]=temp[temp.length-1-i];
		temp[temp.length-1-i]=tp;
		
	}
	return temp;
}	
	

static int bs(ArrayList<pair> arr,int el) {
	int start=0;
	int end=arr.size()-1;
	while(start<=end) {
		int mid=start+(end-start)/2;
		if(arr.get(mid).a==el)return mid;
		else if(arr.get(mid).a<el)start=mid+1;
		else end=mid-1;
	}
   if(start>arr.size()-1)return -2;
   return -1;
}	
	
	
static long find(int s,long a[]) {
	if(s>=a.length)return -1;
	long num=a[s];
	for(int i=s;i<a.length;i+=2) {
		num=gcd(num,a[i]);
		if(num==1 || num==0)return -1;
	}
	return  num;
}	
static long gcd(long a,long b) {
	if(b==0)return a;
	else return gcd(b,a%b);
}
static int gcd(int a,int b) {
	if(b==0)return a;
	else return gcd(b,a%b);
}
static long factmod(long n,long mod,long img) {
	if(n==0)return 1;
	long ans=1;
	long temp=1;
	while(n--!=0) {
		if(temp!=img) {
		ans=((ans%mod)*((temp)%mod))%mod;
		}
		temp++;
	}
	return ans%mod;
}	
	
static int bs(long a[] ,long num) {
	int start=0;
	int end=a.length-1;
    while(start<=end) {
    	int mid=start+(end-start)/2;
    	if(a[mid]==num) {
    		return mid;
    	}
    	else if(a[mid]<num)start=mid+1;
    	else end=mid-1;
    
    }
    return start;
}	
static int ncr(int n, int r){
    if(r>n-r)r=n-r;
    int ans=1;
    for(int i=0;i<r;i++){
          ans*=(n-i);
          ans/=(i+1);
    }
    return ans;
} 

public static class trip{
	int a,b;
	int c;
	public trip(int a,int b,int c) {
		this.a=a;
		this.b=b;
		this.c=c;
	}
	public int compareTo(trip q) {
		return  this.b-q.b;
	}
}	
static void id2(long[] a,int start,int end) {
		if(start>=end)return ;
		int mid=start+(end-start)/2;
		id2(a,start,mid);
		id2(a,mid+1,end);
		merge(a,start,mid,end);
		
	}
static void merge(long[] a, int start,int mid,int end) {
		int ptr1=start;
		int ptr2=mid+1;
		long b[]=new long[end-start+1];
		int i=0;
		while(ptr1<=mid && ptr2<=end) {
			if(a[ptr1]<=a[ptr2]) {
				b[i]=a[ptr1];
				ptr1++;
				i++;
			}
			else {
				b[i]=a[ptr2];
				ptr2++;
				i++;
			}
		}
		while(ptr1<=mid) {
			b[i]=a[ptr1];
			ptr1++;
			i++;
		}
		while(ptr2<=end) {
			b[i]=a[ptr2];
			ptr2++;
			i++;
		}
		for(int j=start;j<=end;j++) {
			a[j]=b[j-start];
		}
	}
public static class FastReader {

		BufferedReader b;
		StringTokenizer s;
		public FastReader() {
			b=new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {
			while(s==null ||!s.hasMoreElements()) {
				try {
					s=new StringTokenizer(b.readLine());
				}
				catch(IOException e) {
					e.printStackTrace();
				}
			}
			return s.nextToken();
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str="";
			try {
				str=b.readLine();
			}
			catch(IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		boolean hasNext() {
		    if (s != null && s.hasMoreTokens()) {
		        return true;
		    }
		    String tmp;
		    try {
		        b.mark(1000);
		        tmp = b.readLine();
		        if (tmp == null) {
		            return false;
		        }
		        b.reset();
		    } catch (IOException e) {
		        return false;
		    }
		    return true;
		}
}
public static class pair{
	int a;
	int b;
	public pair(int a,int b) {
		this.a=a;
		this.b=b;
	}
	
	public int compareTo(pair b) {
		return this.a-b.a;
		
	}






	@Override
	public String toString() {
		return "{"+this.a+" "+this.b+"}";
	}
}	
static long pow(long a, long pw) {
	long temp;
	if(pw==0)return 1;
	temp=pow(a,pw/2);
	if(pw%2==0)return temp*temp;
	return a*temp*temp;
	
}
static long mpow(long a, long pw) {
	long temp;
	if(pw==0)return 1;
	temp=pow(a,pw/2);
	if(pw%2==0)return mul(temp,temp);
	return mul(a,mul(temp,temp));
	
}
static int pow(int a, int pw) {
	int temp;
	if(pw==0)return 1;
	temp=pow(a,pw/2);
	if(pw%2==0)return temp*temp;
	return a*temp*temp;
	
}
}
