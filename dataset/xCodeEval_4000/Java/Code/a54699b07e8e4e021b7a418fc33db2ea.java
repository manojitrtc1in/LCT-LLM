import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;




public class two_pointers_method {
	static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
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
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        }
    }
	
	public static void main(String[] args) {
		OutputStream outputStream =System.out;
	    PrintWriter out =new PrintWriter(outputStream);
	FastReader s=new FastReader();
     int t=s.nextInt();
     while(t>0) {


    	 int n=s.nextInt();
    	 int[] a=new int[2*n];
    	 um.clear();
    	 for(int i=0;i<2*n;i++) {
    		 a[i]=s.nextInt();
    		 if(!um.containsKey(a[i])) {
    			 um.put(a[i],1);
    		 }else {
    			 um.put(a[i],um.get(a[i])+1);
    		 }
    	 }
    	 Arrays.sort(a);
    	 boolean p=false;
    	 int k=0;
    	 int max=a[2*n-1];
    	 for(int i=2*n-2;i>=0;i--) {
    		 HashMap<Integer,Integer> e1=new HashMap<>();
    		 e1=(HashMap<Integer, Integer>) um.clone();
    		 int sum=a[2*n-1]+a[i];
    		 int j=2*n-1;
    		 max=a[2*n-1];
    		 int count=2;
    		 boolean p1=true;


    		 e1.put(max, e1.get(max)-1);
    		 e1.put(a[i],e1.get(a[i])-1);




    		 out:while(count<(2*n)) {


    		 while((e1.get(a[j])==0) || (j==i)) {
    			 j--;
    		 }






    		 if(max-a[j]==0) {


    			 break out;
    		 }else if( !e1.containsKey(max-a[j])) {


    			 break out;
    		 }else if(e1.get(max-a[j])==0) {


    			 break out;
    		 }
    		 else if((max-a[j])==a[j]) {
    			 if(!e1.containsKey(max-a[j])) {


    				 break out;
    			 }else if(e1.get(a[j])<2) {
    				 break out;
    			 }else {


        			 e1.put(a[j], e1.get(a[j])-1);
        			 e1.put(max-a[j], e1.get(max-a[j])-1);
        			 max=a[j];
    			 }
    		 }
    		 else {




    			 e1.put(a[j], e1.get(a[j])-1);
    			 e1.put(max-a[j], e1.get(max-a[j])-1);
    			 max=a[j];
    		 }


    		 count+=2;








    		 }


    		 if(count==2*n) {
    			 k=i;
    			 p=true;
    			 break;
    		 }
    	 }
    	 
    	 if(!p) {
    		out.println("NO");
    	 }else {
    		 out.println("YES");




    		 int sum=a[2*n-1]+a[k];
    		 out.println(sum);
    		 out.println(a[2*n-1]+" "+a[k]);
    		 int j=2*n-1;
    		 max=a[2*n-1];
    		 int count=2;
    		 boolean p1=true;


    		 um.put(max, um.get(max)-1);
    		 um.put(a[k],um.get(a[k])-1);


    		 while(count<(2*n)) {


    		 while((um.get(a[j])==0) || (j==k) && j>=0) {
    			 j--;
    		 }








    			 um.put(a[j], um.get(a[j])-1);
    			 um.put(max-a[j], um.get(max-a[j])-1);


    			 out.println(a[j]+" "+(max-a[j]));
    			 max=a[j];
    			 
    		 
    		 count+=2;




    		 }


    		 
    		 
    	 }
    	 t--;
     }
	out.close();
	}
	static HashMap<Integer,Integer> um=new HashMap<>();
	




	


























	public static int lower_bound(long[] a ,int n,long x) {
		int l=0;
		int r=n+1;
		while(r>l+1) {
			int mid=(l+r)/2;
			if(a[mid]<=x) {
				l=mid;
			}else {
				r=mid;
			}
		}
		return l;
				
	}
	public static int upper_bound(int[] a ,int n,int x) {
		int l=-1;
		int r=n;
		while(r>l+1) {
			int mid=(l+r)/2;
			if(a[mid]<=x) {
				l=mid;
			}else {
				r=mid;
			}
		}
		return r;
				
	}

















	static class pair2 implements Comparable<pair2>{
		private long a;
		private int b;
		pair2(long a,int b){
			this.a=a;
			this.b=b;
		}
		public int compareTo(pair2 p) {
			return Long.compare(this.a,p.a);
		}
	}
	public static int longest_Common_Substring_using_top_down(String str1,String str2,int n,int m) {
		int[][] dp=new int[n+1][m+1];
		int max=Integer.MIN_VALUE;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(str1.charAt(i-1)==str2.charAt(j-1)) {
					dp[i][j]=1+dp[i-1][j-1];
					max=Math.max(max, dp[i][j]);
				}else {
					dp[i][j]=0;

				}
			}
		}
		
		return max;
	}








































































	static boolean ok(long n) {
		long sum=0;
		while(n>0) {
			sum+=n%10;
			n/=10;
		}
		return (sum==10);
	}
	static long get1(long n) {
		long f=0;


		while(n>0) {
			f=Math.max(f, n%10);
			n/=10;
		}
		return f;
	}
	static long get2(long n) {
		long f=9;


		while(n>0) {
			f=Math.min(f, n%10);
			n/=10;
		}
		return f;
	}
	static long get(long n,long k,long count) {
		if(count==k) {
			return n;
		}else {
			long t1=get1(n);
			long t2=get2(n);
			long y=n+t1*t2;
			return get(y,k,count+1);
		}
	}
	
	
	public static int lower_bound(ArrayList<Integer> a ,int n,int x) {
		int l=-1;
		int r=n;
		while(r>l+1) {
			int mid=(l+r)/2;
			if(a.get(mid)<=x) {
				l=mid;
			}else {
				r=mid;
			}
		}
		return l;
				
	}
	public static long longest_Segment_sum_less_than_equal_to_S(long[] a,long sum,int n) {
		int l=0;
		long x=0;
		long res=0;
		for(int r=0;r<n;r++) {
			x+=a[r];
			while(x>sum) {
				x-=a[l];
			l++;
			}
			res=Math.max(r-l+1,res);
		}
		return res;
	}
	public static long shortest_Segment_sum_greater_than_equal_to_S(long[] a,long sum,int n) {
		int l=0;
		long x=0;
		long res=Integer.MAX_VALUE;
		for(int r=0;r<n;r++) {
			x+=a[r];
			while(x-a[l]>=sum) {
				x-=a[l];
				l++;
			}
			if(x>=sum) {
				res=Math.min(res, r-l+1);
			}
		}
		return res;
	}
	public static long total_Segment_sum_less_than_equal_to_S(long[] a,long sum,int n) {
	
		int l=0;
		long x=0;
		long res=0;
		for(int r=0;r<n;r++) {
			x+=a[r];
			while(x>sum) {
				x-=a[l];
				l++;
			}
			res+=((r-l+1));
		}
		return res;
	}
	public static long total_Segment_sum_greater_than_equal_to_S(long[] a,long sum,int n) {
		
		int l=0;
		int l1=-1;
		int r1=-1;
		long x=0;
		long res=0;
		for(int r=0;r<n;r++) {
			x+=a[r];
			while(x-a[l]>=sum) {
				x-=a[l];
				l++;
			}
			if(x>=sum && l!=l1 && r!=r1) {
				res+=(long)(l-l1)*(n-r);
				l1=l;


			}
			r1=r;
		}
		return res;
	}
	public static long total_Segment_unique_elements_less_than_equal_to_S(long[] a,long k,int n) {
		int l=0;


		int count=0;
		long res=0;
		int[] ct=new int[100001];
		for(int r=0;r<n;r++) {
			ct[(int) a[r]]++;
			if(ct[(int) a[r]]==1) {
				count++;
			}
				while(count>k) {
					ct[(int) a[l]]--;
					if(ct[(int) a[l]]==0) {
						count--;
					}
					l++;
				}
				res+=(r-l+1);
			
		}
		return res;
		
	}
	public static long segment_with_maximum_spread(long[] a,int n,long k)
	{
		int l=0;
		long count=0;
	for(int r=0;r<n;r++) {
		add(a[r]);
		while(!good(k)) {
			remove();
			l++;
		}
		count+=r-l+1;


	}
		return count;
	}
	
public static class Stack1{
	
	private  Stack<Long> st;
	private  Stack<Long> smin;
	private  Stack<Long> smax;
Stack1(){
	this.st=new Stack<>();
	this.smin=new Stack<>();
	this.smax=new Stack<>();
	this.smin.add(Long.MAX_VALUE);
	this.smax.add(Long.MIN_VALUE);
}	 
	
}
static Stack1 st1=new Stack1();
static Stack1 st2=new Stack1();
static void add(long d) {
	st2.st.add(d);
	st2.smin.add(Math.min(d, st2.smin.peek()));
	st2.smax.add(Math.max(st2.smax.peek(),d));
}
static void remove() {
	if(st1.st.isEmpty()) {
		while(!st2.st.isEmpty()) {
			st1.st.add(st2.st.pop());
			st2.smin.pop();
			st2.smax.pop();
			st1.smax.add(Math.max(st1.smax.peek(), st1.st.peek()));
			st1.smin.add(Math.min(st1.smin.peek(), st1.st.peek()));
		}}
		st1.st.pop();
		st1.smax.pop();
		st1.smin.pop();
	
}
static boolean good(long k) {
	long min=Math.min(st1.smin.peek(), st2.smin.peek());
	long max=Math.max(st1.smax.peek(), st2.smax.peek());
	return max-min<=k;
}



public static class Stack2{
	
	private  Stack<Long> st;
	private  Stack<Long> gcd;
Stack2(){
	this.st=new Stack<>();
	this.gcd=new Stack<>();
	gcd.add((long) 0);
}	 
	
}
static Stack2 st3=new Stack2();
static Stack2 st4=new Stack2();
static void add2(long d) {
	st4.st.add(d);
	st4.gcd.add(GCD(st4.gcd.peek(),d));
}
static void remove2() {
	if(st3.st.isEmpty()) {
		while(!st4.st.isEmpty()) {
			st3.st.add(st4.st.pop());
			st4.gcd.pop();
			st3.gcd.add(GCD(st3.gcd.peek(),st3.st.peek()));
			
		}}
		st3.st.pop();
		st3.gcd.pop();
	
}
static boolean good2() {
	if(st3.st.isEmpty()) {
		while(!st4.st.isEmpty()) {
			st3.st.add(st4.st.pop());
			st4.gcd.pop();
			st3.gcd.add(GCD(st3.gcd.peek(),st3.st.peek()));
			
		}}
	long d=st3.gcd.pop();
	long g=st3.gcd.peek();
	st3.gcd.add(d);
	return GCD(g,st4.gcd.peek())==1;
}


public static long GCD(long a,long b) {
	if(b==(long)0) {
		return a;
	}
	return GCD(b , a%b);
}
public static boolean good3() {
	return GCD(st3.gcd.peek(),st4.gcd.peek())==1;
}
public static long shortest_Segment_gcd_equal_to_one(long[] a,int n) {
	int l=0;
	long x=0;
	long res=Integer.MAX_VALUE;
	for(int r=0;r<n;r++) {
		add2(a[r]);
		while(good2()) {
		remove2();
			l++;
		}
		if(good3()) {
			res=Math.min(res, r-l+1);
		}
	}
	return res;
}
public static long[] merge_sort(long[] A, int start, int end) {
	if (end > start) {
		int mid = (end + start) / 2;
		long[] v = merge_sort(A, start, mid);
		long[] o = merge_sort(A, mid + 1, end);
		return (merge(v, o));
	} else {
		long[] y = new long[1];
		y[0] = A[start];
		return y;
	}
}
public static long[] merge(long a[], long b[]) {


	long[] temp = new long[a.length + b.length];
	int m = a.length;
	int n = b.length;
	int i = 0;
	int j = 0;
	int c = 0;
	while (i < m && j < n) {
		if (a[i] < b[j]) {
			temp[c++] = a[i++];
		
		} else {
			temp[c++] = b[j++];
		}
	}
	while (i < m) {
		temp[c++] = a[i++];
	}
	while (j < n) {
		temp[c++] = b[j++];
	}
	return temp;
}






































































































}
