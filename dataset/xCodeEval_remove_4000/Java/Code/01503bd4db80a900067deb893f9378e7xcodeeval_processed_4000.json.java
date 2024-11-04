import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStreamReader; 
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.io.DataInputStream; 
import java.io.FileInputStream; 
import java.io.IOException; 
import java.util.ArrayList;
import java.util.Scanner; 
import java.util.StringTokenizer; 
import java.util.*;
import java.io.*;
import java.math.*;

public final class id0{ 
    static class FastReader { 
        final private int BUFFER_SIZE = 1 << 16; 
        private DataInputStream din; 
        private byte[] buffer; 
        private int bufferPointer, bytesRead; 
  
        public FastReader() 
        { 
            din = new DataInputStream(System.in); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public FastReader(String file_name) throws IOException 
        { 
            din = new DataInputStream(new FileInputStream(file_name)); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 

        

        public String nextLine() throws IOException 
        { 
            byte[] buf = new byte[1000000]; 

            int cnt = 0, c; 
            while ((c = read()) != -1) 
            { 
                if (c == '\n') 
                    break; 
                buf[cnt++] = (byte) c; 
            } 
            return new String(buf, 0, cnt).trim(); 
        } 

        

        public int nextInt() throws IOException 
        { 
            int ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do
            { 
                ret = ret * 10 + c - '0'; 
            }  while ((c = read()) >= '0' && c <= '9'); 
  
            if (neg) 
                return -ret; 
            return ret; 
        }

        

        public long nextLong() throws IOException 
        { 
            long ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
            if (neg) 
                return -ret; 
            return ret; 
        } 

        

        public double nextDouble() throws IOException 
        { 
            double ret = 0, div = 1; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
  
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
  
            if (c == '.') 
            { 
                while ((c = read()) >= '0' && c <= '9') 
                { 
                    ret += (c - '0') / (div *= 10); 
                } 
            } 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        private void fillBuffer() throws IOException 
        { 
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
            if (bytesRead == -1) 
                buffer[0] = -1; 
        } 
  
        private byte read() throws IOException 
        { 
            if (bufferPointer == bytesRead) 
                fillBuffer(); 
            return buffer[bufferPointer++]; 
        } 
  
        public void close() throws IOException 
        { 
            if (din == null) 
                return; 
            din.close(); 
        } 
    }
    int[] id7(int[] f){
        int[] to = new int[f.length];
        {
            int[] b = new int[65537];
            for(int i = 0;i < f.length;i++)b[1+(f[i]&0xffff)]++;
            for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
            for(int i = 0;i < f.length;i++)to[b[f[i]&0xffff]++] = f[i];
            int[] d = f; f = to;to = d;
        }
        {
            int[] b = new int[65537];
            for(int i = 0;i < f.length;i++)b[1+(f[i]>>>16)]++;
            for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
            for(int i = 0;i < f.length;i++)to[b[f[i]>>>16]++] = f[i];
            int[] d = f; f = to;to = d;
        }
        return f;
    }
    int phi(long n){ 
        long result = n;  
      
        

        for (long p = 2L; p * p <= n; ++p) { 
              
            

            if (n % p == 0)  { 
                  
                

                while (n % p == 0) 
                    n /= p; 
                result -= result / p; 
            } 
        } 
    
        

        if (n > 1) 
            result -= result / n; 
        return (int)result; 
    }
    void shuffleArray(int[] arr){
        int n = arr.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i){
            int tmp = arr[i];
            int randomPos = i + rnd.nextInt(n-i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }   
    }
    long modInverse(long a, long m) { 
        long g = gcd(a, m); 
        if (g != 1) 
            return -1; 
        else 
        { 
            

            return modpower(a, m - 2, m); 
        } 
        

    } 
    boolean id2 (long x) { 
        

        return x!=0 && ((x&(x-1)) == 0);     
    } 
    long id8(long n) { 
        n--; 
        n |= n >> 1; 
        n |= n >> 2; 
        n |= n >> 4; 
        n |= n >> 8; 
        n |= n >> 16; 
        n |= n >> 32;
        

        n++; 
        return n; 
    }
    public long id6(long[] element_array) 
    { 
        long id6 = 1; 
        long divisor = 2; 
          
        while (true) { 
            long counter = 0; 
            boolean divisible = false; 
              
            for (int i = 0; i < element_array.length; i++) { 
  
                

  
                if (element_array[i] == 0) { 
                    return 0; 
                } 
                else if (element_array[i] < 0) { 
                    element_array[i] = element_array[i] * (-1); 
                } 
                if (element_array[i] == 1) { 
                    counter++; 
                } 
  
                

                if (element_array[i] % divisor == 0) { 
                    divisible = true; 
                    element_array[i] = element_array[i] / divisor; 
                } 
            } 
  
            

            

            if (divisible) { 
                id6 = id6 * divisor; 
            } 
            else { 
                divisor++; 
            } 
  
            

            if (counter == element_array.length) { 
                return id6; 
            } 
        } 
    } 

    

    long gcd(long a, long b) 
    { 
        if (a == 0) 
            return b; 
        return gcd(b % a, a); 
    } 
  
    

    long id3(long arr[], long n) 
    { 
        long result = arr[0]; 
        for (int i = 1; i < n; i++) 
            result = gcd(arr[i], result); 
  
        return result; 
    }
    long lcm(long a, long b) 
    { 
        return (a*b)/gcd(a, b); 
    } 
    long modpower(long x, long y, long p) { 
        

        long res = 1;      
         
        

        x = x % p;  
      
        while (y > 0) 
        { 
            

            if((y & 1)==1) 
                res = (res * x) % p; 
      
            

            y = y >> 1;  
            x = (x * x) % p;  
        } 
        return res; 
    } 
    int binarySearch(int arr[], int x) 
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
    int id4(int arr[], int target){
        int l = 0;
        int r = arr.length;
        while(l<r){
            int mid = (l+r)/2;
            if(target<arr[mid])
                r = mid;
            else 
                l = mid+1;
        }
        return l;
    }
    int id1(long arr[], long target){
        int l = 0;
        int r = arr.length;
        while(l<r){
            int mid = (l+r)/2;
            if(arr[mid]<target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    HashMap<Integer,Integer> Counter(int arr[]){
        HashMap<Integer,Integer> hash = new HashMap<>();
        for(int i: arr){
            hash.put(i,hash.getOrDefault(i,0)+1);
        }
        return hash;
    }
    int[] id5(int n) 
    { 
        

        

        boolean prime[] = new boolean[n+1]; 
        for(int i=0;i<=n;i++) 
            prime[i] = true; 
        int cnt = 0;
        for(int p = 2; p*p <=n; p++) 
        { 
            

            if(prime[p] == true) 
            { 
                

                for(int i = p*p; i <= n; i += p) 
                    prime[i] = false; 
            } 
        } 
        

        for(int i = 2; i <= n; i++) 
        { 
            if(prime[i] == true) {
                cnt++;
                

            }
        }
        int arr[] = new int[cnt];
        int j = 0;
        System.out.println("cnt is = "+cnt);
        for(int i = 2; i <= n; i++) 
        { 
            if(prime[i] == true) {
                arr[j++]=i;
                

            }
        }
        return arr;
    }
    

    
    int tree[]; 

    
    

    void update(int arr[], int node, int index, int val, int start, int end){
        if(start == end){
            arr[start] += val; 

            tree[node] += val;
        }
        else{
            int mid = (start + end) / 2;
            if(start <= index && index <= mid)
                update(arr, 2*node+1, index, val, start, mid);
            else
                update(arr, 2*node+2, index, val, mid+1, end);
        }
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    

    void build(int arr[], int pos, int l, int r){
        if(l==r)
            tree[pos] = arr[l];
        else{
            int mid = (l+r)/2;
            build(arr, 2*pos+1, l, mid);
            build(arr, 2*pos+2, mid+1, r);
            tree[pos] = tree[2*pos+1] + tree[2*pos+2];
        }
    }
    

    

    

    int query(int node, int start, int end, int l, int r){
        if(r < start || l > end)
            return 0;
        if(l <= start && r >= end)
            return tree[node];
        int mid = (start + end) / 2;
        int ans1 = query(2*node+1, start, mid, l, r);
        int ans2 = query(2*node+2, mid+1, end, l, r);
        return ans1 + ans2;
    } 
    boolean isprime(long n){
        if(n==2 || n==3)
            return true;
        if(n%2==0 || n%3==0 || n<=1)
            return false;
        long x=5;
        while(x*x<=n){
            if(n%x==0 || n%(x+2)==0)
                return false;
            x+=6;
        }
        return true;
    }
    ArrayList<Long> fact(long n){
        ArrayList<Long> arr = new ArrayList<Long>();
        long x = 1;
        while(x*x<=n){
            if(n%x==0)
                arr.add(x);
            if(n/x!=x && n%(n/x)==0)
                arr.add(n/x);
            x+=1;
        }
        return arr;
    }
    
    void solve() throws Exception{
        int n = read.nextInt();
        int arr[] = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = read.nextInt();
        int m = read.nextInt();
        int girl[] = new int[m];
        for(int i = 0; i < m; i++)
            girl[i] = read.nextInt();
        

        

        Arrays.sort(arr);
        

        

        HashSet<Integer> girl_hash = new HashSet<Integer>();
        HashMap<Integer,Integer> dic = Counter(girl);
        

        

        for(int i = 0; i < m; i++)
            girl_hash.add(girl[i]);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(girl_hash.contains(arr[i]-1)&& dic.get(arr[i]-1)>0){
                ans++;
                dic.put(arr[i]-1,dic.get(arr[i]-1)-1);
                

            }
            else if(girl_hash.contains(arr[i]) && dic.get(arr[i])>0){
                ans++;
                dic.put(arr[i],dic.get(arr[i])-1);
                

            }
            else if(girl_hash.contains(arr[i]+1) && dic.get(arr[i]+1)>0){
                ans++;
                dic.put(arr[i]+1,dic.get(arr[i]+1)-1);
                

            }
            

        }
        System.out.println(ans);
    }
    
    FastReader read=new FastReader();
    public static void main(String[] args) throws Exception { 
    	new id0().solve();
    } 
} 