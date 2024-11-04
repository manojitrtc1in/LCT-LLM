

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

 
 public class CodeForces {
 
     
     static Pair getMinus(int twos,int n,int[]arr,int start,int end){
         int x=0;
         int y=0;
          long copy1 =twos+0;
                    for (int i=start;i<end;i++){
                         if(arr[i]==-2||arr[i]==2)copy1--;
                        if(arr[i]<0){
                            
                            x=i+1;
                            break;
                        }
                    }
                    
                     long copy2 =twos+0;
                     for (int i=end-1;i>=start;i--){
                            if(arr[i]==-2||arr[i]==2)copy2--;
                         if(arr[i]<0){
                          
                             y=n-i;
                             break;
                         }
                     }
                     
                     if(copy2>copy1)x=start;
                     else y=n-end;
                     
                     
               return new Pair(x,y,(int)Math.max(copy1,copy2));
     }
  
     
     
     public static void main(String[] args) throws InterruptedException {
    
 


     
 
 
 


 






 
         
         
        FastScanner fs = new FastScanner();


        PrintWriter out = new PrintWriter(System.out);
        
      
       int testNumber =fs.nextInt();
 
        
     

        for (int T =0;T<testNumber;T++){


              


 		
                int n= fs.nextInt();
                int arr [] =fs.readArray(n);
                boolean zero= false;
                boolean minus =false;
                
                int u=0;
                int twos=0;
                for (int i:arr){
                    if(i==2)twos++;
                    else if (i==-2)twos++;
                    
                    if(i<0)u++;
                    else if(i==0) zero=true;
                    
                    
                }
               
                
                if(u%2==1)minus=true;
                                
                int x =0;
                int y =0;
                
                
                
                if(zero){
                    ArrayList<Integer>zeros = new ArrayList<>();
                    zeros.add(-1);
                 for (int i=0;i<n;i++)if(arr[i]==0){
                     zeros.add(i);
                 }
                    zeros.add(n);
                 long max=0;
                 for (int i=0;i<zeros.size()-1;i++){
                    int res2=0;
                    
                    int total=0;
                    int times =0;
                    int mins =0;
                    for (int j=zeros.get(i)+1;j<zeros.get(i+1);j++){
                      if(arr[j]==2)res2++;
                      else if (arr[j]==-2)res2++;
                        times++;
                        if(arr[j]<0)mins++;
                    }
                    Pair p =getMinus(res2, n, arr,zeros.get(i)+1 , zeros.get(i+1));
                    if(mins%2==1){
                        total=p.extra;
                    }else total=res2;
                    
                   if(total>max){
                       max=total;
                       x=(mins%2==0?(zeros.get(i)+1):p.x);
                       y=(mins%2==0?(n-(zeros.get(i)+times)-1):p.y);
                   }
                }
                 
                 if(max<=0){
                     x=n;
                     y=0;
                 }
                }else if(minus){
                   Pair p = getMinus(twos, n, arr,0,n);
                   x=p.x;
                   y=p.y;
                }
                out.print(x+" "+y+"\n");
        }
        out.flush();
}
    
     
     
     
     
     
     
     
     
     static int[] factorials(int max,int mod){
         int [] ans = new int[max+1];
         ans[0]=1;
         
         for (int i=1;i<=max;i++){
             ans[i]=ans[i-1]*i;
             ans[i]%=mod;
         }
         return ans;
     }
     
     
     
     static String toBinary(int num,int bits){
         String res =Integer.toBinaryString(bits);
         while(res.length()<bits)res="0"+res;
         
         return res;
     }
     
     static String toBinary(long num,int bits){
         String res =Long.toBinaryString(bits);
         while(res.length()<bits)res="0"+res;
         
         return res;
     }
     
     
     
     static long LCM(long a,long b){
         return a*b/gcd(a,b);
     }
     
     
     static long FastPower(long x,long p){
         if(p==0)return 1;
          long ans =FastPower(x, p/2);
         ans*=ans;
         if(p%2==1)ans*=x;
         
         return ans;
     }
     
     
     static double FastPower(double x,int p){
         if(p==0)return 1.0;
          double ans =FastPower(x, p/2);
         ans*=ans;
         if(p%2==1)ans*=x;
         
         return ans;
     }
     
     static int FastPower(int x,int p){
         if(p==0)return 1;
          int ans =FastPower(x, p/2);
         ans*=ans;
         if(p%2==1)ans*=x;
         
         return ans;
     }
     
    
    
    static ArrayList<Vertex> vertices = new ArrayList<>();
    
    static class Vertex {
        public ArrayList<Integer>edges = new ArrayList<>();
        public boolean isEnd=false;
        public Vertex (){
            for(int i=0;i<26;i++){
                edges.set(i, -1);
            }
        }
    }
    
    
  static class Trie {
      
      private int root=0;
        public Trie(){
            vertices.add(new Vertex());
        }
        
        
        public void InsertWord(String s){
            int current = root;
            
            for(char c:s.toCharArray()){
                int pos = c-'a';
                
                if(vertices.get(current).edges.get(pos)==-1){
                    vertices.add(new Vertex());
                    Vertex x = vertices.get(current);
                    x.edges.set(pos,vertices.size()-1);
                    vertices.set(current, x);
                }
                
                current=vertices.get(current).edges.get(pos);
            }
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    static class FastScanner {
         BufferedReader br;
         StringTokenizer st;
        public FastScanner(){
            br=new BufferedReader(new InputStreamReader(System.in));
            st=new StringTokenizer("");
        }
        
        
        public FastScanner(File f){
            try {
            br=new BufferedReader(new FileReader(f));
            st=new StringTokenizer("");
            } catch(FileNotFoundException e){
                 br=new BufferedReader(new InputStreamReader(System.in));
                st=new StringTokenizer("");
            }
        }
        
        
		
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
                
                double nextDouble() {
			return Double.parseDouble(next());
		}
                
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
                
                long[] readLongArray(int n) {
			long[] a =new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
                
		long nextLong() {
			return Long.parseLong(next());
		}
	}
     
 
	
    
    public static long factorial(int n){
        if(n==0)return 1;
        
        return (long)n*factorial(n-1);
    }
    
   
    
    
    public static long gcd(long a, long b)
    {
        if (a == 0)
            return b;
          
        return gcd(b%a, a);
    }
    
    
    
    static void sort (int[]a){
        ArrayList<Integer> b = new ArrayList<>();
        for(int i:a)b.add(i);
        Collections.sort(b);
        for(int i=0;i<b.size();i++){
            a[i]=b.get(i);
        }
    }
    
    static void sortReversed (int[]a){
        ArrayList<Integer> b = new ArrayList<>();
        for(int i:a)b.add(i);
        Collections.sort(b,new Comparator<Integer>(){
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2-o1;
            }
        });
        for(int i=0;i<b.size();i++){
            a[i]=b.get(i);
        }
    }
    
    
    static void sort (long[]a){
        ArrayList<Long> b = new ArrayList<>();
        for(long i:a)b.add(i);
        Collections.sort(b);
        for(int i=0;i<b.size();i++){
            a[i]=b.get(i);
        }
    }
    
    
    
    
    static ArrayList<Integer> sieveOfEratosthenes(int n)
    {
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
 
        
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 2; i <= n; i++)
        {
            if (prime[i] == true)
                ans.add(i);
        }
        
        return ans;
    }
 
    
    
 
    
   
    static int binarySearchSmallerOrEqual(int arr[],  int key)
  {
    int n = arr.length;
    int left = 0, right = n;
 
    int mid = 0;
    while (left < right) {
      mid = (right + left) >> 1;
 
      if (arr[mid] == key) {
 
       
        while (mid + 1 < n && arr[mid + 1] == key)
          mid++;
        break;
      }
 
      else if (arr[mid] > key)
        right = mid;
 
      else
        left = mid + 1;
    }
 
    while (mid > -1 && arr[mid] > key)
      mid--;
 
    return mid;
  }
    
    
    static int binarySearchSmallerOrEqual(long arr[],  long key)
  {
    int n = arr.length;
    int left = 0, right = n;
 
    int mid = 0;
    while (left < right) {
      mid = (right + left) >> 1;
 
      if (arr[mid] == key) {
 
       
        while (mid + 1 < n && arr[mid + 1] == key)
          mid++;
        break;
      }
 
      else if (arr[mid] > key)
        right = mid;
 
      else
        left = mid + 1;
    }
 
    while (mid > -1 && arr[mid] > key)
      mid--;
 
    return mid;
  }
 
    
    public static int binarySearchStrictlySmaller(int[] arr, int target)
    {
           
        int start = 0, end = arr.length-1;
        if(end == 0) return -1;
      
        if (target > arr[end]) return end;
   
        int ans = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
   
            if (arr[mid] >= target) {
                end = mid - 1;
            }
   
            else {
                ans = mid;
                start = mid + 1;
            }
        }
        return ans;
    }
    
    
    
     public static int binarySearchStrictlySmaller(long[] arr, long target)
    {
           
        int start = 0, end = arr.length-1;
        if(end == 0) return -1;
      
        if (target > arr[end]) return end;
   
        int ans = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
   
            if (arr[mid] >= target) {
                end = mid - 1;
            }
   
            else {
                ans = mid;
                start = mid + 1;
            }
        }
        return ans;
    }
    
    
    
    
    static int binarySearch(int arr[], int x)
    {
        int l = 0, r = arr.length - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
             if (arr[m] == x)
                return m;
            if (arr[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
    
    
    static int binarySearch(long arr[], long x)
    {
        int l = 0, r = arr.length - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
             if (arr[m] == x)
                return m;
            if (arr[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
    static void init(int[]arr,int val){
        for(int i=0;i<arr.length;i++){
            arr[i]=val;
        }
    }
    
    
    static void init(int[][]arr,int val){
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr[i].length;j++){
            arr[i][j]=val;
        }
        }
    }
    
    static void init(long[]arr,long val){
        for(int i=0;i<arr.length;i++){
            arr[i]=val;
        }
    }
    
  
    static<T> void init(ArrayList<ArrayList<T>>arr,int n){
        for(int i=0;i<n;i++){
            arr.add(new ArrayList());
        }
    }
    
    
    
    
     static int binarySearchStrictlySmaller(ArrayList<Pair> arr, int target)
    {
           
        int start = 0, end = arr.size()-1;
        if(end == 0) return -1;
      
        if (target > arr.get(end).y) return end;
   
        int ans = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
   
            if (arr.get(mid).y >= target) {
                end = mid - 1;
            }
   
            else {
                ans = mid;
                start = mid + 1;
            }
        }
        return ans;
    }
    
    
    
    
    
    
    
    
    
    
    static int binarySearchStrictlyGreater(int[] arr, int target)
    {
        int start = 0, end = arr.length - 1;
   
        int ans = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
   
            if (arr[mid] <= target) {
                start = mid + 1;
            }
   
            else {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }
 
   
   
   
   
   
   
   public static long pow(long n, long pow) {
        if (pow == 0) {
            return 1;
        }
        long retval = n;
        for (long i = 2; i <= pow; i++) {
            retval *= n;
        }
        return retval;
    }
   
   
   
   static String reverse(String s){
       StringBuffer b = new StringBuffer(s);
       b.reverse();
       return b.toString();
 
   }
   
   static String charToString (char[] arr){
       String t="";
       
       for(char c :arr){
           t+=c;
       }
       return t;
   }
   
   
   int[] copy (int [] arr , int start){
       int[] res = new int[arr.length-start];
       for (int i=start;i<arr.length;i++)res[i-start]=arr[i];
       return res;
   }
   
   static int[] swap(int [] A,int l,int r){
       int[] B=new int[A.length];
       for (int i=0;i<l;i++){
           B[i]=A[i];
       }
       
       int k=0;
       for (int i=r;i>=l;i--){
           B[l+k]=A[i];
           k++;
       }
       
       for (int i=r+1;i<A.length;i++){
           B[i]=A[i];
       }
       
       return B;
       
   }
   
   static int mex (int[] d){
       int [] a = Arrays.copyOf(d, d.length);
       sort(a);
       if(a[0]!=0)return 0;
       
       int ans=1;
       for(int i=1;i<a.length;i++){
           if(a[i]==a[i-1])continue;
           if(a[i]==a[i-1]+1)ans++;
           else break;
       }
       return ans;
   }
   
   
   static int[] mexes(int[] arr){
       int[] freq = new int [100000+7]; 
       for (int i:arr)freq[i]++;
       
       int maxMex =0;
       for (int i=0;i<=100000+7;i++){
           if(freq[i]!=0)maxMex++;
           else break;
       }
       
       
       int []ans = new int[arr.length];
       ans[arr.length-1] = maxMex;
       for (int i=arr.length-2;i>=0;i--){
           freq[arr[i+1]]--;
           if(freq[arr[i+1]]<=0){
               if(arr[i+1]<maxMex)
               maxMex=arr[i+1];
               ans[i]=maxMex;
           } else {
               ans[i]=ans[i+1];
           }
       }
       
       return ans;
   }
   
   static int [] freq (int[]arr,int max){
         int []b = new int[max];
         for (int i:arr)b[i]++;
         return b;
     }
   
   
   static int[] prefixSum(int[] arr){
       int [] a = new int[arr.length];
       a[0]=arr[0];
       for (int i=1;i<arr.length;i++)a[i]=a[i-1]+arr[i];
       
       return a;
   }
   
   
   
  
   
   
 
    static class Pair {
        int x;
        int y;
        
        public int extra;
        public Pair(int x,int y){
            this.x=x;
            this.y=y;
        
        }
 
         public Pair(int x,int y,int extra){
            this.x=x;
            this.y=y;
            this.extra=extra;
        
        }
     
   
        
        
        
        @Override
  public boolean equals(Object o) {
     if(o instanceof Pair){
         if(o.hashCode()!=hashCode()){
             return false;
         } else {
             return x==((Pair)o).x&&y==((Pair)o).y;
         }
     } 
     
     return false;
 
  }
  
  
  
  
  
  @Override
  public int hashCode() {
    return x+2*y;
  }
 
       
    }
 
 
}