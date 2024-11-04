import java.io.*;
import java.math.BigInteger;
import java.util.*;



public class Main {

	static int[] dx = { 0, 1, 0, -1, -1, 1, 1, -1 };
	static int[] dy = { -1, 0, 1, 0, -1, -1, 1, 1 };

	static int[] kx = { 2, 1, -1, -2, -2, -1, 1, 2 };
	static int[] ky = { 1, 2, 2, 1, -1, -2, -2, -1 };

	static final int MOD = 10007;
	static final int MAX = 50000;
	static long INF = Long.MAX_VALUE;

	public static void main(String[] args) {

		InputReader in = new InputReader(System.in);

		








		


















		




		text = in.next();
		pattern = String.valueOf(text);
		
		String val = kmpSearch();
		if(val == null){
			System.out.println("Just a legend");
		}
		else{
			System.out.println(val);
		}
		
		System.exit(0);
	}

	static int[] prefixTable = new int[1000005];
	   
    static String text = "";
    static String pattern = "";
   
    
	 private static String  kmpSearch() {
	       
	        kmpPreprocess();
	       
	       
















	        
	        int n = text.length(); 
	        
	        

	        if (prefixTable[n - 1] == 0) 
	        { 


	            return null; 
	        } 
	        for (int i = 0; i < n - 1; i++)  
	        { 
	      
	            

	            if (prefixTable[i] == prefixTable[n - 1])  
	            { 


	                return text.substring(0, prefixTable[i]); 
	            } 
	        } 
	      
	        









	        if (prefixTable[prefixTable[n - 1] - 1] == 0) {


	        	return null;
	        }
	        else{


	       
	        	
	            return text.substring(0, prefixTable[prefixTable[n - 1] - 1]);
	        }
	    }
	 
	 private static void kmpPreprocess() {
	       




















		 
		 int n = pattern.length(); 
	      
	        



	      
	        

	        

	        int len = 0; 
	      
	        

	        prefixTable[0] = 0; 
	        int i = 1; 
	      
	        

	        while (i < n)  
	        { 
	            if (pattern.charAt(i) == pattern.charAt(len))  
	            { 
	                len++; 
	                prefixTable[i] = len; 
	                i++; 
	            } 
	      
	            

	            else 
	            { 
	                if (len != 0) 
	                    len = prefixTable[len - 1]; 
	                

	                

	      
	                

	                else
	                { 
	                    prefixTable[i] = 0; 
	                    i++; 
	                } 
	            } 
	        } 
	    }
	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	


	

	

	

	

	


	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	static int dp[][];

	

	

	

	

	

	

	


	

	

	


	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public String next() {
			try {
				while (tokenizer == null || !tokenizer.hasMoreTokens()) {
					tokenizer = new StringTokenizer(reader.readLine());

				}
			} catch (IOException e) {
				return null;
			}
			return tokenizer.nextToken();
		}

		public String nextLine() {
			String line = null;
			try {
				tokenizer = null;
				line = reader.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			return line;
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public boolean hasNext() {
			try {
				while (tokenizer == null || !tokenizer.hasMoreTokens()) {
					tokenizer = new StringTokenizer(reader.readLine());
				}
			} catch (Exception e) {
				return false;
			}
			return true;
		}
	}
}
