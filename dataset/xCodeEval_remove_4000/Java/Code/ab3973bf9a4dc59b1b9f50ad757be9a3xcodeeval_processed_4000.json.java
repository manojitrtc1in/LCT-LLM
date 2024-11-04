


import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;


public class Q2 {
	static id5 sc;
	static int cnt=0;
	static boolean b[];
	static int[] arr,parent,color,sum;
	static ArrayList<Integer>[] amp;
	static ArrayList<Integer> ans;
	static StringBuilder s2;
	static HashSet<Integer> hs;
	static int MOD = 1000000007;
	
	public static void main(String args[] ) throws Exception {
        sc=  new id5();
        BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
        int arr[] = sc.id2(6);
        int brr[] = new int[6];
        ArrayList<String> amp = new ArrayList<>();
        int n = sc.nextInt();
        for(int i = 0; i <n ;i++){
        	amp.add(sc.nextLine());
        	String str[] = amp.get(i).split(",");
        	if(str.length==1) {
        		if(str[0].equals("S")) arr[0]--;
        		if(str[0].equals("M")) arr[1]--;
        		if(str[0].equals("L")) arr[2]--;
        		if(str[0].equals("XL")) arr[3]--;
        		if(str[0].equals("XXL")) arr[4]--;
        		if(str[0].equals("XXXL")) arr[5]--;
        	}
        	else{
        		if(str[0].equals("S")) {brr[0]++;brr[1]++;}
        		if(str[0].equals("M")) {brr[1]++;brr[2]++;}
        		if(str[0].equals("L")) {brr[2]++;brr[3]++;}
        		if(str[0].equals("XL")) {brr[3]++;brr[4]++;}
        		if(str[0].equals("XXL")) {brr[4]++;brr[5]++;}
        	}
        }
        if(arr[0]<0||arr[1]<0||arr[2]<0||arr[3]<0||arr[4]<0||arr[5]<0){
        	System.out.println("NO");
        }
        else{
        	int crr[] = new int[6];
        	for(int i =0 ;i<6;i++) crr[i] = brr[i];
        	crr[0] = Math.max(brr[0]-arr[0], 0);
        	crr[1] = Math.max(brr[1]-arr[0], 0);
        	for(int i =0 ;i<6;i++) brr[i] = arr[i];
        	for(int i = 1;i<5;i++){
        		

        		if(crr[i-1]>0){
        			int temp = crr[i-1];
        			crr[i-1]-=Math.min(arr[i], temp);
        			crr[i]-=Math.min(arr[i], temp);
        			arr[i]-=Math.min(arr[i], temp);
        			crr[i]=Math.max(crr[i]-arr[i], 0);
        			crr[i+1]=Math.max(crr[i+1]-arr[i], 0);
        		}
        		else{
        			crr[i]=Math.max(crr[i]-arr[i], 0);
        			crr[i+1]=Math.max(crr[i+1]-arr[i], 0);
        		}
        	}
        	crr[5]-=arr[5];
        	crr[4]-=arr[5];
        	if(crr[0]>0||crr[1]>0||crr[2]>0||crr[3]>0||crr[4]>0||crr[5]>0){
            	System.out.println("NO");
            }
        	else{
        		System.out.println("YES");
        		String[] ans = new String[n];
        		for(int i = 0; i<n;i++){
        			String s[] = amp.get(i).split(",");
        			if(s.length==1) {
        				ans[i] = s[0];
        			}
        		}
        		for(int j = 0;j<5;j++){
        		for(int i = 0;i<n;i++){
        			String s[] = amp.get(i).split(",");
        			if(j==0 && s.length>1){
        				if(s[0].equals("S")&&brr[0]>0) {
        					ans[i] = s[0];brr[0]--;
        				}
        				else if(s[0].equals("S")&&brr[0]<=0){
        					ans[i] = s[1];brr[1]--;
        				}
        			}
        			if(j==1&& s.length>1){
        				if(s[0].equals("M")&&brr[1]>0) {
        					ans[i] = s[0];brr[1]--;
        				}
        				else if(s[0].equals("M")&&brr[1]<=0){
        					ans[i] = s[1];brr[2]--;
        				}
        			}
        			if(j==2&& s.length>1){
        				if(s[0].equals("L")&&brr[2]>0) {
        					ans[i] = s[0];brr[2]--;
        				}
        				else if(s[0].equals("L")&&brr[2]<=0){
        					ans[i] = s[1];brr[3]--;
        				}
        			}
        			if(j==3&& s.length>1){
        				if(s[0].equals("XL")&&brr[3]>0) {
        					ans[i] = s[0];brr[3]--;
        				}
        				else if(s[0].equals("XL")&&brr[3]<=0){
        					ans[i] = s[1];brr[4]--;
        				}
        			}
        			if(j==4&& s.length>1){
        				if(s[0].equals("XXL")&&brr[4]>0) {
        					ans[i] = s[0];brr[4]--;
        				}
        				else if(s[0].equals("XXL")&&brr[4]<=0){
        					ans[i] = s[1];brr[5]--;
        				}
        			}
        		}
        		
        	}
        		for(String s : ans){
        			log.write(s+"\n");
        		}
        	}
        }
        log.close(); 
    }
	static int[] id4(int n){
		int arr[] = new int[2];
		int cnt = 0;
		for(int i = 0;(i<ans.size())&&(ans.get(i)*ans.get(i)<=n);i++){
				while(n>1 && n%ans.get(i)==0){
				n/=ans.get(i);
				cnt++;
			}
		if(cnt>0) {
			arr[0] = cnt;
			arr[1] = ans.get(i);
			break;
		}
		}
		return arr;
	}
	public static void seive(){
		Arrays.fill(b, true);
		for(int i = 2;i*i<=1000000;i++){
			if(b[i]){
				for(int p = 2*i;p<=1000000;p+=i){
					b[p]= false;
				}
			}
		}
		for(int i = 2;i<=1000000;i++){
			if(b[i]){
				ans.add(i);
				arr[i] = 2;
			}
		}
	}
	 static void id8(String pat, String txt)
	    {
	        int M = pat.length();
	        int N = txt.length();
	 
	        

	        

	        int lps[] = new int[M];
	        int j = 0;  

	 
	        

	        

	        id0(pat,M,lps);
	 
	        int i = 0;  

	        while (i < N)
	        {
	            if (pat.charAt(j) == txt.charAt(i))
	            {
	                j++;
	                i++;
	            }
	            if (j == M)
	            {
	                

	                  

	            	b[i-j] = true;
	                j = lps[j-1];
	            }
	 
	            

	            else if (i < N && pat.charAt(j) != txt.charAt(i))
	            {
	                

	                

	                if (j != 0)
	                    j = lps[j-1];
	                else
	                    i = i+1;
	            }
	        }
	    }
	static void id0(String pat, int M, int lps[])
    {
        

        int len = 0;
        int i = 1;
        lps[0] = 0;  

 
        

        while (i < M)
        {
            if (pat.charAt(i) == pat.charAt(len))
            {
                len++;
                lps[i] = len;
                i++;
            }
            else  

            {
                

                

                

                if (len != 0)
             	
                {
                    len = lps[len-1];
 
                    

                    

                }
                else  

                {
                    lps[i] = len;
                    i++;
                }
            }
        }
    }
	public static boolean id6(int x){
		b[x] = true;
		for(int i =0;i<amp[x].size();i++){
			int c = amp[x].get(i);
			if(b[c]){
				if(color[c] == color[x]) return false;
			}
			else{
				color[c] = -color[x];
				id6(c);
			}
		}
		return true;
	}
	public static int getParent(int x){
		if(parent[x] != x) 
		parent[x] = getParent(parent[x]);
		return parent[x];
	}
	 static class Pair implements Comparable<Pair> {
			long u;
			long v;
			double dist=0;
			public Pair(){
				
			}
			public Pair(long u, long v) {
				this.u = u;
				this.v = v;
			}
			
			public int hashCode() {
				int hu = (int) (u ^ (u >>> 32));
				int hv = (int) (v ^ (v >>> 32));
				return 31*hu + hv;
			}

			public boolean equals(Object o) {
				Pair other = (Pair) o;
				return (u == other.u && v == other.v);
			}

			public int compareTo(Pair other) {
				return Long.compare(u, other.u) != 0 ? (~Long.compare(u, other.u)) :0;
			}

			public String toString() {
				return "[u=" + u + ", v=" + v + "]";
			}
		}
	static class SegmentTree{
		int size;
		int amp[];
		public void size(int n){
			int x = (int)Math.ceil(Math.log(n)/Math.log(2));
			size = 2*(int)Math.pow(2, x)-1;
			amp = new int[size];
			Arrays.fill(amp,-1);
		}
		public int build(int arr[],int ss,int se,int si){
			if(ss==se) {
				amp[si] = arr[ss];
				return arr[ss];
			}
			int mid = (ss+se)/2;
			amp[si] = Math.max(build(arr,ss,mid,si*2+1),build(arr,mid+1,se,si*2+2));
			return amp[si];
		}
		public void update(int ss, int se, int i, long l, int si){
			if(i<ss||i>se) return;
			if(se==ss) {
				amp[si] = -1;
				return;
			}
			if(se!=ss){
				int mid = (ss+se)/2;
				update(ss,mid,i,l,2*si+1);
				update(mid+1,se,i,l,2*si+2);
			}
			amp[si] = Math.max(amp[si*2+1], amp[si*2+2]);
			
		}
		public int getSum(int ss,int se, int s, int e, int si){
			if(s<=ss && se<=e) return amp[si];
			if(s>se||e<ss) return -1;
			int mid = (ss+se)/2;
			return Math.max(getSum(ss,mid,s,e,2*si+1),getSum(mid+1,se,s,e,2*si+2));
		}
		public void print(){
			for(int i = 0;i<size;i++) System.out.print(amp[i]+" ");
		}
	}
	public static int ans(int x1,int x2, int y1, int y2){
		return (Math.abs(x1-x2)+Math.abs(y1-y2)+Math.abs(x1-y2)+Math.abs(y1-x2));
	}
	public static long gcd(long a, long b){
		if(b==0) return a;
		else return gcd(b,a%b);
	}
	
	public static void stringReverse(int s, int e){
		int i = s, j =e;
		char ch[] = s2.toString().toCharArray();
		while(i<j){
			char c = ch[i];
			ch[i] = ch[j];
			ch[j] = c;
			i++;j--;
		}
		s2.delete(0, s2.length());
		for(int x =0 ;x<ch.length;x++) s2.append(ch[x]);
	}
	public static void buildGraph(int m){
		for(int i = 0; i<m;i++){
			int x = sc.nextInt();
			int y = sc.nextInt();
			amp[--x].add(--y);
			amp[y].add(x);
		}
	}
	public static boolean isPalindrome(String str){
	    int cnt = 0;
	    int arr[] = new int[26];
		for(int i =0;i<str.length();i++){
	        arr[str.charAt(i)-'a']++;
	    }
		for(int i = 0;i<26;i++){
			if(arr[i]%2==0) continue;
			else cnt++;
		}
		if(cnt<2)
	    return true;
		return false;
	}
	public static void dfs(int x,HashMap<Integer,Integer> hm){
		b[x] = true;
		if(hm.containsKey(arr[x]-1)) hm.put(arr[x]-1, hm.get(arr[x]-1)+1);
		else{
			hm.put(arr[x]-1, 1);
		}
		cnt++;
		for(int i =0;i<amp[x].size();i++){
			if(!b[amp[x].get(i)]) dfs(amp[x].get(i),hm);
		}
	}
	
	public static void mergeSort(int[] arr, int start, int end){
		
		if(start<end){
			int mid = (start+end)/2;
			mergeSort(arr,start,mid);
			mergeSort(arr,mid+1,end);
		merge(arr,start,mid,end);
		}
	}
	public static void merge(int arr[],int start, int mid, int end){
		int left[] = new int[mid-start+1];
		int right[] = new int[end-mid];
		for(int i= 0;i<mid-start+1;i++){
			left[i] = arr[i+start];
			

		}
		for(int i = 0;i<end-mid;i++){
			right[i] = arr[i+mid+1];
			

		}
		int k = start, i =0, j = 0;
		while(i<mid-start+1 && j<end-mid){
			if(left[i]<right[j]){
				arr[k++] = left[i];
				i++;
			}
			else{
				arr[k++] = right[j];
				j++;
			}
			
		}
		while(i<mid-start+1) {
			arr[k++] = left[i];i++;
		}
		while(j<end-mid) {
			arr[k++] = right[j];j++;
		}
	}
	
	
		
	public static class id5 {
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = System.in.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public String nextLine() {
			int c = read();
			while (id1(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id3(c));
			return res.toString();
		}

		public String nextString() {
			int c = read();
			while (id1(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id1(c));
			return res.toString();
		}

		public long nextLong() {
			int c = read();
			while (id1(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!id1(c));
			return res * sgn;
		}

		public int nextInt() {
			int c = read();
			while (id1(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!id1(c));
			return res * sgn;
		}
	        
	    public int[] id2(int n) {
	        return id2(n, 0);
	    }
	    
	    public int[] id2(int n, int off) {
	    	int[] arr = new int[n + off];
	    	for (int i = 0; i < n; i++) {
	    		arr[i + off] = nextInt();
	    	}
	    	return arr;
	    }
	    
	    public long[] id7(int n) {
	    	return id7(n, 0);
	    }
        
		public long[] id7(int n, int off) {
		    long[] arr = new long[n + off];
		    for (int i = 0; i < n; i++) {
		        arr[i + off] = nextLong();
		    }
		    return arr;
		}

	    private boolean id1(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean id3(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
	}


}
