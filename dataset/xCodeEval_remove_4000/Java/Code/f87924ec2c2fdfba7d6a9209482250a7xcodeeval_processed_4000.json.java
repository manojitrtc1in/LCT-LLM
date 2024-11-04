import java.awt.Container;
import java.awt.image.SampleModel;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.concurrent.CountDownLatch;

import javax.naming.TimeLimitExceededException;

import java.io.PrintStream;


public class Solution {

	static class Pair<T,V>{
		T first;
		V second;
		public Pair(T first, V second) {
			super();
			this.first = first;
			this.second = second;
		}

	}

	

	private static FastScanner fs=new FastScanner();
	private static Scanner sc=new Scanner(System.in);

	private static int uperBound(long[] arr, long val) {

		int start= 0; 
		int end=arr.length;
		while(start<end) {
			int mid=(start+end)/2;
			if( arr[mid]==val ) {
				return mid;
			}
			if( arr[mid]>val ) {
				end=mid-1;
			}else {
				start=mid+1;
			}
		}

		if( start >= arr.length || arr[start]>val) {
			return start;
		}else {
			return start+1;
		}

	}


	
	private static void solve(int TC) throws Exception{
		


		int n=fs.nextInt();
		long input[]=new long[n];
		for(int i=0;i<n;i++) {
			input[i]=fs.nextLong();
		}


		int even=0;
		for(int i=0;i<n;i++) {
			if( (input[i]&1) ==0 ) {
				even++;
			}
		}
		int odd=n-even;
		if( Math.abs(odd-even) > 1 ) {
			System.out.println(-1);
			return ;
		}
		
		for(int i=0;i<n;i++) {
			input[i]= ( (input[i]&1)==1 )?1 :0;
		}
		
		int ans=Integer.MAX_VALUE;
		if( (n&1)==0 ) {
			int output[]=new int[n];
			for(int i=0;i<n;i++) {
				output[i] = ( i&1 )==1 ? 1:0;
			}
			
			ArrayList<Integer> oddpos=new ArrayList<Integer>();
			ArrayList<Integer> evenpos=new ArrayList<Integer>();
			
			for(int i=0;i<n;i++) {
				if( input[i] != output[i] ) {
					if( (i&1)==1 ) oddpos.add(i); 
					else evenpos.add(i);
				}
			}
			int smallAns=0;
			for(int i=0;i<oddpos.size();i++) {
				smallAns+= Math.abs(oddpos.get(i)-evenpos.get(i));
			}
			
			ans=Math.min(ans, smallAns);
			
			output=new int[n];
			for(int i=0;i<n;i++) {
				output[i] = ( i&1 )==0 ? 1:0;
			}
			
			oddpos=new ArrayList<Integer>();
			evenpos=new ArrayList<Integer>();
			
			for(int i=0;i<n;i++) {
				if( input[i] != output[i] ) {
					if( (i&1)==1 ) oddpos.add(i); 
					else evenpos.add(i);
				}
			}
			smallAns=0;
			for(int i=0;i<oddpos.size();i++) {
				smallAns+= Math.abs(oddpos.get(i)-evenpos.get(i));
			}
			
			ans=Math.min(ans, smallAns);
		}else if( odd> even ) {
			int output[]=new int[n];
			for(int i=0;i<n;i++) {
				output[i] = ( i&1 )==0 ? 1:0;
			}
			
			ArrayList<Integer> oddpos=new ArrayList<Integer>();
			ArrayList<Integer> evenpos=new ArrayList<Integer>();
			
			for(int i=0;i<n;i++) {
				if( input[i] != output[i] ) {
					if( (i&1)==1 ) oddpos.add(i); 
					else evenpos.add(i);
				}
			}
			int smallAns=0;
			for(int i=0;i<oddpos.size();i++) {
				smallAns+= Math.abs(oddpos.get(i)-evenpos.get(i));
			}
			
			ans=Math.min(ans, smallAns);
		}else {
			int output[]=new int[n];
			for(int i=0;i<n;i++) {
				output[i] = ( i&1 )==1 ? 1:0;
			}
			
			ArrayList<Integer> oddpos=new ArrayList<Integer>();
			ArrayList<Integer> evenpos=new ArrayList<Integer>();
			
			for(int i=0;i<n;i++) {
				if( input[i] != output[i] ) {
					if( (i&1)==1 ) oddpos.add(i); 
					else evenpos.add(i);
				}
			}
			int smallAns=0;
			for(int i=0;i<oddpos.size();i++) {
				smallAns+= Math.abs(oddpos.get(i)-evenpos.get(i));
			}
			
			ans=Math.min(ans, smallAns);
		}
		
		
		System.out.println(ans);

		
		

	}

	public static void main(String[] args) throws Exception {

		int tcr=1; 
		

		tcr=fs.nextInt();

		while(tcr-->0) {
			solve(tcr);

		}

		System.gc();

	}


	static int id1(int n)
	{
		

		if (n % 4 == 0)
			return n;

		

		if (n % 4 == 1)
			return 1;

		

		if (n % 4 == 2)
			return n + 1;

		

		return 0;
	}

	static boolean isSorted (int[] nums) {

		for (int i = 0; i < nums.length - 1; i++) {

			if (nums[i] > nums[i + 1]) {

				return false;

			}

		}

		return true;

	}

	static void firstOperation (int[] nums) {

		for (int i = 1; i < nums.length; i += 2) {

			int temp = nums[i];
			nums[i] = nums[i - 1];
			nums[i - 1] = temp;

		}

	}

	static void secondOperation (int[] nums) {

		int n = nums.length / 2;

		for (int i = 0; i < n; i++) {

			int temp = nums[i];
			nums[i] = nums[i + n];
			nums[i + n] = temp;

		}

	}


	private static long id4(long a) {
		long ans=0;
		while(a!=0) {
			ans++;
			a/=10;
		}
		return ans;
	}

	private static String reverse(String s) {
		String ans="";
		for(int i=s.length()-1;i>=0;i--) {
			ans+=s.charAt(i);
		}
		return ans;
	}

	private static boolean isPalindrome(String s) {
		int i=0;
		int j=s.length()-1;

		while(i<j) {
			if(s.charAt(i)!=s.charAt(j)) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}

	static class FastScanner {

		BufferedReader br;
		StringTokenizer st ;

		FastScanner(){
			br =  new BufferedReader(new InputStreamReader(System.in));
			st = new StringTokenizer("");
		}

		FastScanner(String file) {

			try {
				br =  new BufferedReader(new InputStreamReader(new FileInputStream(file)));
				st = new StringTokenizer("");
			} catch (FileNotFoundException e) {
				

				System.out.println("file not found");
				e.printStackTrace();
			}

		}


		String next() {
			while (!st.hasMoreTokens())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}
		String readLine() throws IOException{
			return br.readLine();
		}
	}

	public static long[] sort(long arr[]){
		List<Long> list = new ArrayList<>();
		for(long n : arr){list.add(n);}
		Collections.sort(list);
		for(int i=0;i<arr.length;i++){
			arr[i] = list.get(i);
		}
		return arr;
	}
	public static int[] sort(int arr[]){
		List<Integer> list = new ArrayList<>();
		for(int n : arr){list.add(n);}
		Collections.sort(list);
		for(int i=0;i<arr.length;i++){
			arr[i] = list.get(i);
		}
		return arr;
	}

	

	

	

	public static int id0(long arr[],long num){
		

		int st = 0;
		int e = arr.length - 1;

		int ans = -1;

		while(st <= e){

			int mid = (st + e)/2;

			if(arr[mid] >= num){
				e = mid - 1;
			}else{
				ans = mid;
				st = mid + 1;
			}

		}


		return ans + 1;

	}

	

	


	public static int justGreater(long arr[],long num){
		int st = 0;
		int e = arr.length - 1;

		int ans = arr.length;

		while(st <= e){

			int mid = (st + e)/2;

			if(arr[mid] <= num){
				st = mid + 1;
			}else{
				ans = mid;
				e = mid - 1;
			}
		}

		return ans;

	}


	public static boolean isPrime(int n) {

		for(int i=2;i<n;i++) {
			if(n%i==0) {
				return false;
			}
		}
		return true;
	}

	public static void println(Object obj){
		System.out.println(obj.toString());
	}

	public static void print(Object obj){
		System.out.println(obj.toString());
	}

	public static long gcd(long a,long b){
		if(b == 0l){
			return a;
		}

		return gcd(b,a%b);
	}

	public static int find(int parent[],int v){
		if(parent[v] == v){
			return v;
		}

		return parent[v] = find(parent, parent[v]);
	}



	public static List<Integer> sieve(){

		List<Integer> prime = new ArrayList<>();

		int arr[] = new int[100001];

		Arrays.fill(arr,1);

		arr[1] = 0;
		arr[2] = 1;

		for(int i=2;i<=100000;i++){

			if(arr[i] == 1){

				prime.add(i);

				for(long j = (i*1l*i);j<100001;j+=i){
					arr[(int)j] = 0;
				}
			}
		}

		return prime;
	}

	static boolean isPower(long n,long a){

		long log = (long)(Math.log(n)/Math.log(a));

		long power = (long)Math.pow(a,log);

		if(power == n){return true;}

		return false;
	}


	private static int id2(int[] arr, int l,int m, int r)
	{

		

		int[] left =  Arrays.copyOfRange(arr, l, m + 1);

		

		int[] right = Arrays.copyOfRange(arr, m + 1, r + 1);

		int i = 0, j = 0, k = l, swaps = 0;

		while (i < left.length && j < right.length) {
			if (left[i] <= right[j])
				arr[k++] = left[i++];
			else {
				arr[k++] = right[j++];
				swaps += (m + 1) - (l + i);
			}
		}
		while (i < left.length)
			arr[k++] = left[i++];
		while (j < right.length)
			arr[k++] = right[j++];
		return swaps;
	}

	

	private static int id3(int[] arr, int l,int r)
	{

		

		

		int count = 0;

		if (l < r) {
			int m = (l + r) / 2;

			

			


			

			count += id3(arr, l, m);

			

			count += id3(arr, m + 1, r);

			

			count += id2(arr, l, m, r);
		}

		return count;
	}

	static class Debug {
		

		public static final boolean LOCAL = System.getProperty("ONLINE_JUDGE")==null;
		private static <T> String ts(T t) {
			if(t==null) {
				return "null";
			}
			try {
				return ts((Iterable) t);
			}catch(ClassCastException e) {
				if(t instanceof int[]) {
					String s = Arrays.toString((int[]) t);
					return "{"+s.substring(1, s.length()-1)+"}\n";
				}else if(t instanceof long[]) {
					String s = Arrays.toString((long[]) t);
					return "{"+s.substring(1, s.length()-1)+"}\n";
				}else if(t instanceof char[]) {
					String s = Arrays.toString((char[]) t);
					return "{"+s.substring(1, s.length()-1)+"}\n";
				}else if(t instanceof double[]) {
					String s = Arrays.toString((double[]) t);
					return "{"+s.substring(1, s.length()-1)+"}\n";
				}else if(t instanceof boolean[]) {
					String s = Arrays.toString((boolean[]) t);
					return "{"+s.substring(1, s.length()-1)+"}\n";
				}
				try {
					return ts((Object[]) t);
				}catch(ClassCastException e1) {
					return t.toString();
				}
			}
		}
		private static <T> String ts(T[] arr) {
			StringBuilder ret = new StringBuilder();
			ret.append("{");
			boolean first = true;
			for(T t: arr) {
				if(!first) {
					ret.append(", ");
				}
				first = false;
				ret.append(ts(t));
			}
			ret.append("}");
			return ret.toString();
		}
		private static <T> String ts(Iterable<T> iter) {
			StringBuilder ret = new StringBuilder();
			ret.append("{");
			boolean first = true;
			for(T t: iter) {
				if(!first) {
					ret.append(", ");
				}
				first = false;
				ret.append(ts(t));
			}
			ret.append("}");
			return ret.toString();
		}
		public static void dbg(Object... o) throws Exception {
			if(LOCAL) {
				PrintStream ps = new PrintStream("src/Debug.txt");
				System.setErr(ps);
				System.err.print("Line 
				for(int i = 0; i<o.length; i++) {
					if(i!=0) {
						System.err.print(", ");
					}
					System.err.print(ts(o[i]));
				}
				System.err.println("]");
			}
		}
	}

}
