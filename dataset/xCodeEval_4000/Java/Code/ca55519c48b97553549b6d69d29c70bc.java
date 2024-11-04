

import java.util.*;
import java.lang.*;
import java.io.*;
@SuppressWarnings("unchecked")



public class C_1_Sheikh_Easy_version
{ 
  

  

   static FastReader sc=new FastReader(System.in);
  
  static long mod = (long)(1e9)+7;
  static int max_num=(int)1e5+5;
  static int MAXN=(int)1e5+5;
  static List<Integer> gr[];
  static long getSum(long a[],int l,int r) 
  {
    long ans=a[r];
    if(l!=0) ans-=a[l-1];
    return ans;
  }
  static long getXor(long a[],int l,int r) 
  {
    long ans=a[r];
    if(l!=0) ans^=a[l-1];
    return ans;
  }
 public static void main (String[] args) throws java.lang.Exception
   {
	    
		  int t = sc.nextInt();
		  for(int tt=1;tt<=t;tt++)
		    { 
		       int n=sc.nextInt();
		       int q=sc.nextInt();
          
		       long a[]=new long[n];
		       for(int i=0;i<n;i++)
		        {
		          a[i]=sc.nextLong();
		        }
               sc.nextInt(); sc.nextInt();
               long p1[]=new long[n]; p1[0]=a[0]; for(int i=1;i<n;i++) p1[i]=p1[i-1]+a[i];
               long p2[]=new long[n]; p2[0]=a[0]; for(int i=1;i<n;i++) p2[i]=p2[i-1]^a[i];
               long ans=p1[n-1]-p2[n-1];
            

               int x=1,y=n;
               int d=n;
               for(int i=0;i<n;i++)
                {
                    int l=i,r=n-1,max=r;
                    long sum=getSum(p1,l,r);
                    long xor=getXor(p2,l,r);
                    long cur=sum-xor;
                    if(cur!=ans) continue;
                    while(l<=r) 
                    {
                        int m=l+(r-l)/2;
                        long sum2=getSum(p1,i,m);
                        long xor2=getXor(p2,i,m);
                        long cur2=sum2-xor2;
                        if(cur2==ans)
                         {
                            max=m;
                            r=m-1;
                         }
                        else 
                         l=m+1;
                    }
                    long sum3=getSum(p1,i,max);
                    long xor3=getXor(p2,i,max);
                    long cur3=sum3-xor3;
                    if(cur3==ans)
                     {
                        int dif=max-i+1;
                        if(dif<d) 
                         {
                           d=dif;
                           x=i+1;
                           y=max+1;
                         }
                     }
                }
            
		       out.println(x+" "+y);
		     
		    }
	     out.flush();
	     out.close();
    }



static void flag(boolean flag)
   {
       out.println(flag ? "YES" : "NO");
       out.flush();
   }




















 

 
   
static void print(int a[])
  {
     int n=a.length;
     for(int i=0;i<n;i++)
       {
          out.print(a[i]+" ");
       }
     out.println();
     out.flush();
  }
static void print(long a[])
  {
     int n=a.length;
     for(int i=0;i<n;i++)
       {
          out.print(a[i]+" ");
       }
     out.println();
     out.flush();
  } 
static void print_int(List<Integer> al)
  {
     int si=al.size();
     for(int i=0;i<si;i++)
       {
          out.print(al.get(i)+" ");
       }
     out.println();
     out.flush();
  }
static void print_long(List<Long> al)
  {
     int si=al.size();
     for(int i=0;i<si;i++)
       {
          out.print(al.get(i)+" ");
       }
     out.println();
     out.flush();
  }
  static void pn(int x)
  {
     out.println(x);
     out.flush();
  }
 static void pn(long x)
  {
     out.println(x);
     out.flush();
  }
  static void pn(String x)
  {
     out.println(x);
     out.flush();
  }
static int LowerBound(int a[], int start,int end,int x) 
 {
    int l=start,r=end,ans=-1;
    while(l<=r) 
     {
        int m=l+(r-l)/2;
        if(a[m]<=x) 
         {
            ans=m;
            l=m+1;
         }
        else r=m-1;
     }
    return ans;
 }
 static int UpperBound(int a[], int start,int end,int x) 
 {
    int l=start,r=end,ans=a.length;
    while(l<=r) 
     {
        int m=l+(r-l)/2;
        if(a[m]>=x) 
         {
            ans=m;
            r=m-1;
         }
        else l=m+1;
     }
    return ans;
 }

static List<Integer> get_primes(int num)
 {
	 boolean[] bool = new boolean[num];
	 for (int i = 0; i< bool.length; i++) 
       {
		    bool[i] = true;
	   }
	 for(int i = 2; i< Math.sqrt(num); i++) 
       {
		   if(bool[i] == true) 
            {
		        for(int j = (i*i); j<num; j = j+i)
                    {
		               bool[j] = false;
		            }
		    }
		}
	   if(num >= 0) 
        {
		   bool[0] = false;
		   bool[1] = false;
		}
      List<Integer> al=new ArrayList<>();
      for(int i=0;i<bool.length;i++) if(bool[i]) al.add(i);
	  return al;
 }
static int spf[] = new int[MAXN];




static void sieve()
  {
        spf[1] = 1;
        for (int i=2; i<MAXN; i++)
      
            

            

            spf[i] = i;
      
        

        

        for (int i=4; i<MAXN; i+=2)
            spf[i] = 2;
      
        for (int i=3; i*i<MAXN; i++)
        {
            

            if (spf[i] == i)
            {
                

                for (int j=i*i; j<MAXN; j+=i)
      
                    

                    

                    if (spf[j]==j)
                        spf[j] = i;
            }
        }
  }




static List<Integer> getFactorization(int x)
    {
        List<Integer> ret = new ArrayList<>();
        while (x != 1)
        {
            ret.add(spf[x]);
            x = x / spf[x];
        }
        return ret;
    }
static long nCr(long a,long b,long mod)
 {
  return (((fact[(int)a] * modInverse(fact[(int)b],mod))%mod * modInverse(fact[(int)(a - b)],mod))%mod + mod)%mod;
 }
static long fact[]=new long[max_num];
static void fact_fill()
 {
   fact[0]=1l;
	for(int i=1;i<max_num;i++)
	  {
	    fact[i]=(fact[i-1]*(long)i);
	    if(fact[i]>=mod)
	      fact[i]%=mod;
	  } 
 }
static long modInverse(long a, long m)
	    {
	       return power(a, m - 2, m);
	    }
static long power(long x, long y, long m)
	    {
	        if (y == 0)
	            return 1;
	        long p = power(x, y / 2, m) % m;
	        p = (long)((p * (long)p) % m);
	        if (y % 2 == 0)
	            return p;
	        else
	            return (long)((x * (long)p) % m);
	    }
        static class UF 
        {
            int[] parents;
            int count;
            UF(int n) 
            {
                parents = new int[n];
                for (int i = 0; i < n; i++) 
                {
                    parents[i] = i;
                }
                count = n;
            }
            
            int find(int i)
            {
                if (parents[i] == i) 
                    return i;
                parents[i] = find(parents[i]);
                return parents[i];
            }
            
           void union(int i, int j) 
           {
                int a = find(i);
                int b = find(j);
                if (a != b)
                {
                    parents[a] = b;
                    count--;
                }
            }
        }
static long sum_array(int a[])
 {
    int n=a.length;
    long sum=0;
    for(int i=0;i<n;i++)
     sum+=a[i];
    return sum;
 }
static long sum_array(long a[])
 {
    int n=a.length;
    long sum=0;
    for(int i=0;i<n;i++)
     sum+=a[i];
    return sum;
 }

static void sort(int[] a) 
   {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
static void sort(long[] a) 
   {
		ArrayList<Long> l=new ArrayList<>();
		for (long i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

static void reverse_array(int a[])
 {
    int n=a.length;
    int i,t; 
    for (i = 0; i < n / 2; i++) { 
            t = a[i]; 
            a[i] = a[n - i - 1]; 
            a[n - i - 1] = t; 
        } 
 }
static void reverse_array(long a[])
 {
    int n=a.length;
    int i; long t; 
    for (i = 0; i < n / 2; i++) { 
            t = a[i]; 
            a[i] = a[n - i - 1]; 
            a[n - i - 1] = t; 
        } 
 }

static long gcd(long a, long b) 
    { 
        if (a == 0) 
            return b; 
          
        return gcd(b%a, a); 
    } 
static int gcd(int a, int b) 
    { 
        if (a == 0) 
            return b; 
          
        return gcd(b%a, a); 
    } 

   static class FastReader{
 
        byte[] buf = new byte[2048];
        int index, total;
        InputStream in;
 
        FastReader(InputStream is) {
            in = is;
        }
 
        int scan() throws IOException {
            if (index >= total) {
                index = 0;
                total = in.read(buf);
                if (total <= 0) {
                    return -1;
                }
            }
            return buf[index++];
        }
 
        String next() throws IOException {
            int c;
            for (c = scan(); c <= 32; c = scan());
            StringBuilder sb = new StringBuilder();
            for (; c > 32; c = scan()) {
                sb.append((char) c);
            }
            return sb.toString();
        }
 
        int nextInt() throws IOException {
            int c, val = 0;
            for (c = scan(); c <= 32; c = scan());
            boolean neg = c == '-';
            if (c == '-' || c == '+') {
                c = scan();
            }
            for (; c >= '0' && c <= '9'; c = scan()) {
                val = (val << 3) + (val << 1) + (c & 15);
            }
            return neg ? -val : val;
        }
 
        long nextLong() throws IOException {
            int c;
            long val = 0;
            for (c = scan(); c <= 32; c = scan());
            boolean neg = c == '-';
            if (c == '-' || c == '+') {
                c = scan();
            }
            for (; c >= '0' && c <= '9'; c = scan()) {
                val = (val << 3) + (val << 1) + (c & 15);
            }
            return neg ? -val : val;
        }
    }
   
    static class Reader 
    { 
        final private int BUFFER_SIZE = 1 << 16; 
        private DataInputStream din; 
        private byte[] buffer; 
        private int bufferPointer, bytesRead; 
  
        public Reader() 
        { 
            din = new DataInputStream(System.in); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public Reader(String file_name) throws IOException 
        { 
            din = new DataInputStream(new FileInputStream(file_name)); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public String readLine() throws IOException 
        { 
            byte[] buf = new byte[64]; 

            int cnt = 0, c; 
            while ((c = read()) != -1) 
            { 
                if (c == '\n') 
                    break; 
                buf[cnt++] = (byte) c; 
            } 
            return new String(buf, 0, cnt); 
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
  static  PrintWriter out=new PrintWriter(System.out);
  static int int_max=Integer.MAX_VALUE;
  static int int_min=Integer.MIN_VALUE;
  static long long_max=Long.MAX_VALUE;
  static long long_min=Long.MIN_VALUE;
}

