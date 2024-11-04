
import java.util.*;
import java.lang.*;
import java.lang.reflect.Array;
import java.io.*;
import java.util.HashMap;
import java.io.BufferedReader; 
import java.io.FileReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 
import java.io.DataInputStream; 
import java.io.FileInputStream; 
public class Prac {
    public static int min(int a,int b,int c){
        if(a<b){
            if(a<c)
                return a;
            
            else
                return c;
        }
        else{
            if(b<c)
                return b;
            else
                return c;
        }   
}
    public static int max(int a,int b,int c){
        if(a<b){
            if(b<c)
                return c;
            
            else
                return b;
        }
        else{
            if(a<c)
                return c;
            else
                return a;
        }   
}
    static class InputReader {
 
		private final InputStream stream;
		private final byte[] buf = new byte[8192];
		private int curChar, snumChars;
 
		public InputReader(InputStream st) {
			this.stream = st;
		}
 
		public int read() {
			if (snumChars == -1)
	 			throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}
 
		public int ni() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}
 
		public long nl() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}
 
		public int[] nia(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = ni();
			}
			return a;
		}
 
		public String rs() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}
 
		public String nextLine() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndOfLine(c));
			return res.toString();
		}
 
		public boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
 
		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
 
	}
    static abstract class MultiSetImpl<ValueType, MapType extends Map<ValueType, Integer>> implements MultiSet<ValueType> {
        protected final MapType map;
        protected int size;
        protected int distinctCount;

        protected MultiSetImpl(MapType map) {
            this.map = map;
            this.size = 0;
        }

        public void add(ValueType value) {
            int count = getCount(value);
            if (count == 0) ++distinctCount;
            map.put(value, count + 1);
            ++size;
        }

        public boolean remove(ValueType value) {
            int count = getCount(value);
            if (count == 0) return false;

            if (count == 1) map.remove(value);
            else map.put(value, count - 1);
            if (count == 1) --distinctCount;
            --size;
            return true;
        }

        public int getCount(ValueType value) {
            Integer count = map.get(value);
            return (count == null ? 0 : count);
        }

        @Override
        public String toString() {
            StringBuilder stringBuilder = new StringBuilder();
            for (ValueType key : map.keySet()) {
                stringBuilder.append("[" + key.toString() + " " + map.get(key).toString() + "] ");
            }
            return stringBuilder.toString();
        }

    }

    static interface MultiSet<ValueType> {
    }

    static class FastReader {
        private InputStream stream;
        private byte[] buf = new byte[8192];
        private int curChar;
        private int pnumChars;

        public FastReader(InputStream stream) {
            this.stream = stream;
        }

        private int pread() {
            if (pnumChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= pnumChars) {
                curChar = 0;
                try {
                    pnumChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (pnumChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = pread();
            while (isSpaceChar(c))
                c = pread();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = pread();
            }
            int res = 0;
            do {
                if (c == ',') {
                    c = pread();
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = pread();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class HashMultiSet<ValueType> extends MultiSetImpl<ValueType, Map<ValueType, Integer>> {
        public HashMultiSet(Map<ValueType, Integer> map) {
            super(map);
        }

    }

  static long modInverse(long a, long m){
      long num=m;
      long x=1;
      long power=a;
      while(num>0){
          if(num%2==1){
              x=(x*power)%mod;
          }
         num=num/2;
         power=(power*power)%mod;
         
      }
      return x;
  }
  static long mod=1000000007;
  public static long fact[]=new long[1000005];
   public static void findFact(){
         fact[0]=1;
         for(int i=1;i<=1000000;i++){
             fact[i]=(i*fact[i-1])%mod;
         }
     }
public static long nCr(int n,int r){
    return (fact[n]*modInverse((fact[r]*fact[n-r])%mod,1000000005))%mod;
}
public static long nPr(int n,int r){
    return (fact[n]*modInverse(fact[n-r],1000000005))%mod;
}
public static int stack[]=new int[200000];
public static int top=-1;
public static void push(int item){
    stack[++top]=item;
} 
public static int pop(){
    return stack[top--];
}
 public static int TwoDpartition(int arr[][], int low, int high,int n) 
    { 
        int pivot = Math.abs(arr[high][0]-arr[high][1]);  
        int i = (low-1); 

        for (int j=low; j<high; j++) 
        { 
            

            

            if (Math.abs(arr[j][0]-arr[j][1]) <= pivot&&arr[j][0]<=arr[j][1]) 
            { 
                i++; 
  
                

                int temp1 = arr[i][0]; 
                int temp2=arr[i][1];
                arr[i][0] = arr[j][0];
                 arr[i][1] = arr[j][1]; 
                arr[j][0] = temp1;
                arr[j][1]=temp2;
            }
            else if (n-arr[j][0]+arr[j][1] <= pivot&&arr[j][0]<arr[j][1]) 
            { 
                i++; 
  
                

                int temp1 = arr[i][0]; 
                int temp2=arr[i][1];
                arr[i][0] = arr[j][0];
                 arr[i][1] = arr[j][1]; 
                arr[j][0] = temp1;
                arr[j][1]=temp2;
            }
        } 
  
        

        int temp1 = arr[i+1][0];
        int temp2 = arr[i+1][1];
        arr[i+1][0] = arr[high][0];
        arr[i+1][1] = arr[high][1];
        arr[high][0] = temp1; 
        arr[high][1] = temp2; 
        return i+1; 
    } 
    public static void TwoDsort(int arr[][], int low, int high,int n) 
    { 
        if (low < high) 
        { 
            
            int pi = TwoDpartition(arr, low, high,n);
            TwoDsort(arr, low, pi-1,n); 
            TwoDsort(arr, pi+1, high,n); 
        } 
    } 

public static void merge(int arr[], int l, int m, int r){ 
        int n1 = m - l + 1; 
        int n2 = r - m; 
        int L[] = new int [n1]; 
        int R[] = new int [n2]; 
        for (int i=0; i<n1; ++i) 
            L[i] = arr[l + i]; 
        for (int j=0; j<n2; ++j) 
            R[j] = arr[m + 1+ j]; 
        int i = 0, j = 0; 
        int k = l; 
        while (i < n1 && j < n2) 
        { 
            if (L[i] <= R[j]) 
            { 
                arr[k] = L[i]; 
                i++; 
            } 
            else
            { 
                arr[k] = R[j]; 
                j++; 
            } 
            k++; 
        } 
        while (i < n1) 
        { 
            arr[k] = L[i]; 
            i++; 
            k++; 
        } 
        while (j < n2) 
        { 
            arr[k] = R[j]; 
            j++; 
            k++; 
        } 
    } 
    public static void sort(int arr[], int l, int r) 
    { 
        if (l < r) 
        { 
            int m = (l+r)/2; 
            sort(arr, l, m); 
            sort(arr , m+1, r); 
            merge(arr, l, m, r); 
        } 
    }
    static PrintWriter w = new PrintWriter(System.out);
     
     
    
    public static void main(String[] args) throws IOException {   
        InputReader sc=new InputReader(System.in);
        

        

       StringBuilder sb = new StringBuilder();
       

       
       int n=sc.ni();
      int dp[][]=new int[n+1][n+1];
      int i=0,j=0,k=0;
      for(i=1;i<=n;i++){
          String s=sc.nextLine();
          for(j=0;j<n/4;j++){
               k=1;
              if(s.charAt(j)=='0'){
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=0;
              }
              else if(s.charAt(j)=='1'){
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=1;
              }
              else if(s.charAt(j)=='2'){
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=0;
              }
              else if(s.charAt(j)=='3'){
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=1;
              }
               else if(s.charAt(j)=='4'){
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=0;
              }
               else if(s.charAt(j)=='5'){
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=1;
              }
               else if(s.charAt(j)=='6'){
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=0;
              }
               else if(s.charAt(j)=='7'){
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=1;
              }
               else if(s.charAt(j)=='8'){
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=0;
              }
               else if(s.charAt(j)=='9'){
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=1;
              }
               else if(s.charAt(j)=='A'){
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=0;
              }
               else if(s.charAt(j)=='B'){
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=1;
              }
               else if(s.charAt(j)=='C'){
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=0;
              }
               else if(s.charAt(j)=='D'){
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=0;
                  dp[i][4*j+k++]=1;
              }
               else if(s.charAt(j)=='E'){
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=0;
              }
               else if(s.charAt(j)=='F'){
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=1;
                  dp[i][4*j+k++]=1;
              }
              
              
              
          }
      }
     for(i=1;i<=n;i++){
         for(j=2;j<=n;j++){
             dp[i][j]+=dp[i][j-1];
         }
     }
     for(i=1;i<=n;i++){
         for(j=2;j<=n;j++){
             dp[j][i]+=dp[j-1][i];
         }
     }
     outer1:
     for(i=n;i>1;i--){
         if(n%i==0){
             int count=0;
             outer2:
             for(j=i;j<=n;j+=i){
                 for(k=i;k<=n;k+=i){
                    

                      

                             if(dp[j][k]-dp[j-i][k]-dp[j][k-i]+dp[j-i][k-i]!=i*i&&dp[j][k]-dp[j-i][k]-dp[j][k-i]+dp[j-i][k-i]!=0){
                                 break outer2;
                             }
                             else
                                count++;
                         }
                        
             }
             if(count==(n/i)*(n/i)){
                 break outer1;
             }
             
         }
     }
     w.println(i);
       w.close();
    }  
}