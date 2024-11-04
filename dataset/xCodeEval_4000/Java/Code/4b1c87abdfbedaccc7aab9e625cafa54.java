
import java.io.*;
import java.util.*;

public class Test {
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static PrintWriter writer;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
	static String nexts() throws IOException {
	  	  tokenizer = new StringTokenizer(reader.readLine());
	   	 String s="";
	   	 while (tokenizer.hasMoreTokens()) {
			s+=tokenizer.nextElement()+" ";
		}
		return s;
	}

	

	


	public static int gcd(int x, int y){
		if (y == 0) return x; else return gcd(y, x % y);
	}

	public static boolean isPrime(int n) 
	    { 
	        

	        if (n <= 1){
		 return false; }
	        if (n <= 3){
		 return true; }
	      
	        

	        

	        if (n % 2 == 0 || n % 3 == 0){
		 return false; }
	      
	        for (int i = 5; i * i <= n; i = i + 6) {    

	            if (n % i == 0 || n % (i + 2) == 0) {
	            	return false;  }
	            }
			

	        return true; 
	    } 

	 static class R implements Comparable<R>{
	        int x, y;
	        public  R(int x, int y) {
	            this.x = x;
	            this.y = y;
	        }
	        public int compareTo(R o) {
            		return x-o.x;     

        		}
	    }   

	public static void main(String[] args) throws IOException {
		reader = new BufferedReader(new InputStreamReader(System.in));
		tokenizer = null;
		writer = new PrintWriter(System.out);
		solve();
		reader.close();
		writer.close();
	}
	
	private static void solve() throws IOException {
		int t = nextInt();
		while(t-->0){
		    int n = nextInt();
		    if(n==1){
		        writer.println(0);
		        continue;
		    }
		    long ans=0;
		    int currmove=n/2;
		    int iterator=n/2;
		    
		    for(int i=0;i<iterator;i++){
		        long count=(2*n+2*(n-2));
		        ans=ans+count*(long)currmove;
		        currmove--;
		        n=n-2;
		    }
		    writer.println(ans);
		}
		
	}
}