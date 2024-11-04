import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.*;
public class pcarp{
	static int max_value;
	static long mod = (long)1e9+7;
	static long ans = (long)1e15;
	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		int  t= sc.nextInt();
		while(t-->0){
			int n = sc.nextInt();
			int max=0;
			HashMap<Integer,Integer> map = new HashMap<>();
			for(int i=0;i<n;i++){
				int a = sc.nextInt();
				map.put(a,map.getOrDefault(a,0)+1);
				if(map.get(a)>max){
					max=map.get(a);
				}
			}
			

			

   

   

   

   

			if(max<=n/2){
				System.out.println(n%2);
			}
			else{
				System.out.println((2*max-n));
			}
		}
	}
	public static int fstr(String s1, String s2, HashMap<String,Integer> map){
		String s = s1+"$"+s2;
		if((s1.length()==0 && s2.length()!=0)||(s1.length()!=0 && s2.length()==0)){
			return 1000;
		}

		if(s1.equals(s2)){
			return 0;
		}
		if(map.containsKey(s)){
			return map.get(s);
		}
		int p =1+Math.min(fstr(s1,s2.substring(1,s2.length()),map),Math.min(fstr(s1,s2.substring(0,s2.length()-1),map),(Math.min(fstr(s1.substring(1,s1.length()),s2,map),fstr(s1.substring(0,s1.length()-1),s2,map)))));
		map.put(s,p);
		return p;
	}


	public static int binarySearch(Point[] arr, int i){
		int lo=0;
		int hi = arr.length-1;
		while(lo<=hi){
			int mid = lo+(hi-lo)/2;
			if(arr[mid].end<arr[i].start){
				if(arr[mid+1].end<arr[i].start){
					lo=mid+1;
				}
				else{
					return mid;
				}
			}
			else{
				hi = mid-1;
			}
		}
		return -1;
	}
	public static boolean fbool(int[][] a, int[][] b,int r, int c){
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(a[i][j]!=b[i][j]){
					return false;
				}
			}
		}
		return true;
	}
	public static long fmin(long n, long a, long b, long c, long e, long h){
		if(n<=0){
			return 0;
		}
		if(n<=e && n<=h){
			ans=Math.min(ans,n*c);
		}
		if(2*n<=e){
			ans=Math.min(ans,n*a);
		}
		if(3*n<=h){
			ans=Math.min(ans,n*b);
		}
		if((h-n)/2>=1 && (h-n)/2>=(n-e)){
			if(b<c){
				long k=Math.min(n-1,(h-n)/2);
				ans=Math.min(ans,(b-c)*k+n*c);
			}
			else{
				long k=Math.max(1,n-e);
				ans=Math.min(ans,(b-c)*k+n*c);
			}
		}
		if((e-n)>=1 && (e-n)>=(n-h)){
			if(a<c){
				long k=Math.min(n-1,(e-n));
				ans=Math.min(ans,(a-c)*k+n*c);
			}
			else{
				long k=Math.max(1,n-h);
				ans=Math.min(ans,(a-c)*k+n*c);
			}
		}
		if(e/2>=1 && e/2>=(3*n-h+2)/3){
			if(a<b){
				long k=Math.min(n-1,e/2);
				ans=Math.min(ans,(a-b)*k+n*b);
			}
			else{
				long k=Math.max(1,(3*n-h+2)/3);
				ans=Math.min(ans,(a-b)*k+n*b);
			}
		}
		if(e>=3 && h>=4 && n>=3){
			ans=Math.min(ans,(a+b+c)+fmin(n-3,a,b,c,e-3,h-4));
		}
		return ans;
	}
	public static ArrayList<Integer> digits(int n){
		ArrayList<Integer> arr = new ArrayList<>();
		while(n>0){
			arr.add(n%10);
			n/=10;
		}
		return arr;
	}
	public static void precompute(){
		for(int i=0;i<=1e5;i++){

		}
	}
	public static boolean valid(String s){
		Stack<Character> st  = new Stack<>();
		for(int i=0;i<s.length();i++){
			if(st.isEmpty() || s.charAt(i)=='('){
				st.push(s.charAt(i));
			}
			else if(st.peek()=='(' && s.charAt(i)==')'){
				st.pop();
			}
		}
		if(st.isEmpty()){
			return true;
		}
		return false;
	}
	public static int minswap(int[] A, int[] B, boolean swap, int pos, int n){
		if(pos>=n){
			return 0;
		}
		int prev_a = swap==true?B[pos-1]:A[pos-1];
		int prev_b = swap==true?A[pos-1]:B[pos-1];
		int ans=Integer.MAX_VALUE;
		if(prev_a<=A[pos] && prev_b<=B[pos]){
			ans=Math.min(ans,minswap(A,B,false,pos+1,n));
		}
		if(prev_a<=B[pos] && prev_b<=A[pos]){
			ans=Math.min(ans,1+minswap(A,B,true,pos+1,n));
		}
		return ans;
	}
	public static int lcs(int[] arr, int n, int pos, int last, HashMap<Integer,Integer> map){
			return 0;
	}

	public static int bg(int n, int pos, char last){

			return 0;
	}
    public static int maxheight(int[] arr, int n){
    	int[] right = new int[n];
    	int[] left= new int[n];
    	Stack<Integer> st = new Stack<>();
    	for(int i=0;i<n;i++){
    		while(!st.isEmpty() && arr[i]<arr[st.peek()]){
    			right[st.pop()]=i;
    		}
    		st.push(i);
    	}
    	while(!st.isEmpty()){
    		right[st.pop()]=n;
    	}
    	for(int i=n-1;i>=0;i--){
    		while(!st.isEmpty() && arr[i]<arr[st.peek()]){
    			left[st.pop()]=i;
    		}
    		st.push(i);
    	}
    	while(!st.isEmpty()){
    		left[st.pop()]=-1;
    	}
    	int max=0;
    	for(int i=0;i<n;i++){
    		max=Math.max(max,arr[i]*(right[i]-left[i]-1));
    	}
    	return max;

    }
    public static void show(int[] arr){
    	int n = arr.length;
    	for(int i=0;i<n;i++){
    		System.out.print(arr[i]+" ");
    	}
    	System.out.println();
    }
	public static String pd(String s){
		int start=0;
		int maxLength=1;
		int low,high;

		for(int i=1;i<s.length();i++){
			low=i-1;
			high=i;
			while(low>=0 && high<s.length() && s.charAt(low)==s.charAt(high)){
				if(high-low+1>maxLength){
					start=low;
					maxLength=high-low+1;
				}
				low--;
				high++;
			}
			low=i-1;
			high=i+1;
			while(low>=0 && high<s.length() && s.charAt(low)==s.charAt(high)){
				if(high-low+1>maxLength){
					start=low;
					maxLength=high-low+1;
				}
				low--;
				high++;
			}
		}
		return s.substring(start,start+maxLength);
		

	}

	static boolean isPrime1(int n)  
    {   
        if (n <= 1) return false;  
        if (n <= 3) return true;  
          
        if (n % 2 == 0 || n % 3 == 0) return false;  
          
        for (int i = 5; i * i <= n; i = i + 6)  
            if (n % i == 0 || n % (i + 2) == 0)  
            return false;  
          
        return true;  
    }  
        
    static int nextPrime(int N)  
    {  
      
          
        if (N <= 1)  
            return 2;  
      
        int prime = N;  
        boolean found = false;  
     
        while (!found)  
        {  
            prime++;  
      
            if (isPrime1(prime))  
                found = true;  
        }  
        return prime;  
    }

	

	public static int robber_house(int[] arr, int pos, int n, int[] dp){
		if(pos>=n){
			return 0;
		}
		if(dp[pos]!=-1){
			return dp[pos];
		}
		return dp[pos]=Math.max(arr[pos]+robber_house(arr,pos+2,n,dp),robber_house(arr,pos+1,n,dp));
	}

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	public static void permutation(char[] arr, int j){
		if(j==arr.length-1){
			print(arr);
			System.out.println();
		}
		for(int i=j;i<arr.length;i++){
			char temp = arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			permutation(arr,j+1);
			char temp1 = arr[i];
			arr[i]=arr[j];
			arr[j]=temp1;
		}
	}

	public static void print(char[] arr){
		for(char c : arr){
			System.out.print(c);
		}
	}

	public static long inc(String s){
		char[] arr = s.toCharArray();
		Arrays.sort(arr);
		String ans="";
		for(int i=0;i<s.length();i++){
			ans+=arr[i];
		}
		return Long.parseLong(ans);
	}

	public static long dec(String s){
		char[] arr = s.toCharArray();
		Arrays.sort(arr);
		String ans="";
		for(int i=s.length()-1;i>=0;i--){
			ans+=arr[i];
		}
		return Long.parseLong(ans);
	}
	public static long max(String n){
		long max=0;
		for(int i=0;i<n.length();i++){
			if(n.charAt(i)-'0'>max){
				max=n.charAt(i)-'0';
			}
		}
		return max;
	}

	public static long base(String n, long b){
		long ans=0;
		for(int i=0;i<n.length();i++){
			ans+=power(b,(long)(n.length()-1-i))*(n.charAt(i)-'0');
		}
		return ans;
	}

	public static long power(long a, long b){
		long res=1;
		while(b>0){
			if((b&1)==1){
				res=res*a;
			}
			b=b>>1;
			a=a*a;
		}
		return res;
	}

	public static long value(int[] arr){
		Arrays.sort(arr);
		return arr[arr.length/2]-arr[(arr.length-1)/2]+1;
	}

	static void function(int l, int r, int[] arr, int[] depth, int d){
		if(r<l){
			return;
		}
		if(r==l){
			depth[l]=d;
			return;
		}
		int m = l;
		for(int i=l+1;i<=r;i++){
			if(arr[m]<arr[i]){
				m=i;
			}
		}
		depth[m]=d;
		function(l,m-1,arr,depth,d+1);
		function(m+1,r,arr,depth,d+1);
	}

	static boolean perfectCube(long N)
    {
        long cube_root;
        cube_root = (long)Math.round(Math.cbrt(N));
     
        

        

        if (cube_root * cube_root * cube_root == N) {
            return true;
        }
        return false;
    }

	public static int value(int n){
		if(n==0){
			return 0;
		}
		int cnt=0;
		while(n>0){
			cnt++;
			n/=2;
		}
		return cnt;
	}

	public static int value1(int n){
		int cnt=0;
		while(n>1){
			cnt++;
			n/=2;
		}
		return cnt;
	}

	public static String function(String s){

		if(check(s)){
			return s;
		}
		if(s.length()==2 && s.charAt(0)==s.charAt(1)){
			return "";
		}
		if(s.charAt(0)==s.charAt(1)){
			return function(s.substring(2,s.length()));
		}
		else{
			return function(s.charAt(0)+function(s.substring(1,s.length())));
		}
	}
    
	static boolean isPowerOfTwo(int n){
    	if(n==0)
    		return false;
 
		return (int)(Math.ceil((Math.log(n) / Math.log(2)))) == 
       			(int)(Math.floor(((Math.log(n) / Math.log(2)))));
	}

	static boolean isPerfectSquare(double x)
    {
        if (x >= 0) {
            double sr = Math.sqrt(x);
            return ((sr * sr) == x);
        }
        return false;
    }

	public static boolean isPerfect(int n){
		int a = (int)Math.sqrt(n);
		if(a*a==n){
			return true;
		}
		return false;
	}

	public static boolean check(String s){
		if(s.length()==1){
			return true;
		}
		for(int i=1;i<s.length();i++){
			if(s.charAt(i)==s.charAt(i-1)){
				return false;
			}
		}
		return true;
	}

	public static boolean isPrime(int n){
		boolean flag=true;
		while(n%2==0){
			n=n/2;
			flag=false;
		}
		for(int i=3;i<=Math.sqrt(n);i+=2){
			if(n%i==0){
				flag=false;
				while(n%i==0){
					n=n/i;
				}
			}
		}
		return flag;
	}

	public static void dfst(ArrayList<ArrayList<Integer>> graph,int src, int deg,boolean ef, boolean of, boolean[] vis, boolean[] flip, int[] init, int[] goal){
		if(vis[src]){
			return;
		}
		vis[src]=true;
		if((deg%2==0 && ef) || (deg%2==1 && of)){
			init[src]=1-init[src];
		}
		if(init[src]!=goal[src]){
			flip[src]=true;
			if(deg%2==0){
				ef=!ef;
			}
			else{
				of=!of;
			}
		}
		for(int i=0;i<graph.get(src).size();i++){
			if(!vis[graph.get(src).get(i)]){
				dfst(graph,graph.get(src).get(i),deg+1,ef,of,vis,flip,init,goal);
			}
		}
	}

	public static void dfs(ArrayList<ArrayList<Integer>> graph, int src, int val, boolean[] vis){
		vis[src]=true;
		int cur_val =0;
		for(int i=0;i<graph.get(src).size();i++){
			if(!vis[graph.get(src).get(i)]){
				cur_val=val+1;
				dfs(graph,graph.get(src).get(i),cur_val,vis);
			}
			if(max_value<cur_val){
				max_value=cur_val;
			}
			cur_val=0;
		}
	}

	public static ArrayList<Integer> pf(int n){
		ArrayList<Integer> arr = new ArrayList<>();
		boolean flag=false;
		while(n%2==0){
			flag=true;
			n/=2;
		}
		if(flag){
			arr.add(2);
		}
		for(int i=3;i<=Math.sqrt(n);i++){
			if(n%i==0){
				arr.add(i);
				while(n%i==0){
					n/=i;
				}
			}
		}
		if(n>1){
			arr.add(n);
		}
		return arr;
	}

	static int gcd(int a, int b){
		if(b==0){
			return a;
		}
		else{
			return gcd(b,a%b);
		}
	}

	static boolean function(int n, int i, int[] arr, int sum){
		if(sum==0){
			return true;
		}
		if(i==n && sum!=0){
			return false;
		}
		if(sum<arr[i]){
			return function(n,i+1,arr,sum);
		}
		else{
			return function(n,i+1,arr,sum-arr[i]) || function(n,i+1,arr,sum);
		}
	}

	public static long fact( long n, long mod){
		long res =1;
		for(int i=1;i<=n;i++){
			res%=mod;
			i%=mod;
			res=(res*i)%mod;
		}
		return res;
	}

	public static long nCk(long n,long k, long mod){
		return (fact(n,mod)%mod*modular(fact(k,mod),mod-2,mod)%mod*modular(fact(n-k,mod),mod-2,mod)%mod)%mod;
	}

	public static long modular(long n, long e, long mod){
		long res = 1;
		n%=mod;
		if (n == 0) return 0;
		while(e>0){
			if((e&1)==1){
				res=(res*n)%mod;
			}
			e=e>>1;
			n=(n*n)%mod;
		}
		return res;
	}

	static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
 
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }
        long[] readLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        long[][] twoDArray(int n, int m){
        	long[][] arr = new long[n][m];
        	for(int i=0;i<n;i++){
        		for(int j=0;j<m;j++){
        			arr[i][j]=nextLong();
        		}
        	}
        	return arr;
        }
    }
}

class Point implements Comparable<Point>{
	long start;
	long end;
	long val;
	Point(long start, long end, long val){
		this.start=start;
		this.end=end;
		this.val=val;
	}
	

	

	

	

	

	

	

	

	

	@Override
	public int compareTo(Point p){
		if(this.end-p.end>0){
			return 1;
		}
		else if(this.end==p.end){
			return 0;
		}
		else{
			return -1;
		}
	}
}
class Node{
	int idx;
	int val;
	Node(int a,int b){
		idx=a;
		val=b;
	}
}