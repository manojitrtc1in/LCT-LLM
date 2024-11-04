

import java.util.*;
import java.lang.*;
import java.io.*;
public class Main
{ 
  

 

  static FastReader sc=new FastReader(System.in);
  
  static long mod = (long)(1e9)+ 7;
  static int max_num=(int)1e5+5;
  static boolean isPrime(long n)
    {
        

        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
  
        

        

        if (n % 2 == 0 || n % 3 == 0)
            return false;
  
        for (long i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
  
        return true;
    }
 public static void main (String[] args) throws java.lang.Exception
   {


	    
		  int t = sc.nextInt();
		  while(t-->0)
		    { 
		       int k=sc.nextInt();
		       String s=sc.next();
		       k=s.length();
		       long  a[]=new long[k];
		       
		       for(int i=0;i<k;i++)
		        a[i]=(long)s.charAt(i)-'0';
		       
		       int len=1;
		       boolean f=false;
		       long dig=0;
		       long ans=0;
		       while(true)
		        {
		          if(len==1)
		           {
		             for(int i=0;i<k;i++)
		               {
		                  
		                  long num=a[i];
		                  if(!isPrime(num))
		                   {
		                     f=true;
		                     dig=len;
		                     ans=num;
		                     break;
		                   }
		               }
		           }
		          if(f)
		           break;
		          
		          if(len==2)
		           {
		              for(int i=0;i<k;i++)
		                {
		                   long num=a[i];
		                   for(int j=i+1;j<k;j++)
		                     {
		                        if(i!=j)
		                         {
		                            long num2=num*10+a[j];
		                             if(!isPrime(num2))
		                              {
		                               f=true;
		                               dig=len;
		                               ans=num2;
		                               break;
		                              }
		                         }
		                     }
		                   if(f)
		                    break;
		                }
		           }
		          if(f)
		           break;
		          
		           if(len==3)
		           {
		              for(int i=0;i<k;i++)
		                {
		                   long num=a[i];
		                   for(int j=i+1;j<k;j++)
		                     {
		                        if(i!=j)
		                         {
		                            long num2=num*10l+a[j];
		                            for(int l=j+1;l<k;l++)
		                            {
		                               long max2=Math.max(Math.max(i,j),l);
		                               long min2=Math.min(Math.min(i,j),l);
		                               if(max2==min2)
		                                continue;
		                                
		                              long num3=num2*10l+a[l];
		                               if(!isPrime(num3))
		                              {
		                               f=true;
		                               dig=len;
		                               ans=num3;
		                               break;
		                              }
		                            }
		                         }
		                       if(f)
		                        break;
		                     }
		                   if(f)
		                    break;
		                }
		           }
		          if(f)
		           break;
		          
		           if(len==4)
		           {
		              for(int i=0;i<k;i++)
		                {
		                   long num=a[i];
		                   for(int j=i+1;j<k;j++)
		                     {
		                        if(i!=j)
		                         {
		                            long num2=num*10l+a[j];
		                            for(int l=j+1;l<k;l++)
		                            {
		                               long max=Math.max(Math.max(i,j),l);
		                               long min=Math.min(Math.min(i,j),l);
		                               if(max==min)
		                                continue;
		                                
		                              long num3=num2*10l+a[l];
		                              for(int m=l+1;m<k;m++)
		                               {
		                                  long max3=Math.max(Math.max(Math.max(i,j),l),m);
		                                  long min3=Math.min(Math.min(Math.min(i,j),l),m);
		                                  if(max3==min3)
		                                     continue;
		                                     
		                                  long num4=num3*10l+a[m];
		                                  if(!isPrime(num4))
		                                    {
		                                     f=true;
		                                    dig=len;
		                                    ans=num4;
		                                     break;
		                                    } 
		                                  
		                               }
		                              if(f)
		                                   break;
		                            }
		                         }
		                       if(f)
		                        break;
		                     }
		                   if(f)
		                    break;
		                }
		           }
		          if(f)
		           break;
		           
		           if(len==5)
		           {
		              for(int i=0;i<k;i++)
		                {
		                   long num=a[i];
		                   for(int j=i+1;j<k;j++)
		                     {
		                        if(i!=j)
		                         {
		                            long num2=num*10l+a[j];
		                            for(int l=j+1;l<k;l++)
		                            {
		                               long max=Math.max(Math.max(i,j),l);
		                               long min=Math.min(Math.min(i,j),l);
		                               if(max==min)
		                                continue;
		                                
		                              long num3=num2*10l+a[l];
		                              for(int m=l+1;m<k;m++)
		                               {
		                                  long max3=Math.max(Math.max(Math.max(i,j),l),m);
		                                  long min3=Math.min(Math.min(Math.min(i,j),l),m);
		                                  if(max3==min3)
		                                     continue;
		                                     
		                                  long num4=num3*10l+a[m];
		                                  for(int n=m+1;n<k;n++)
		                                 {
		                                  long max33=Math.max(Math.max(Math.max(Math.max(i,j),l),m),n);
		                                  long min33=Math.min(Math.min(Math.min(Math.min(i,j),l),m),n);
		                                  if(max33==min33)
		                                     continue;
		                                    long num5=num4*10l+a[n];
		                                    if(!isPrime(num5))
		                                    {
		                                     f=true;
		                                    dig=len;
		                                    ans=num5;
		                                     break;
		                                    } 
		                                 }
		                                if(f)
		                                 break;
		                                  
		                               }
		                              if(f)
		                                   break;
		                            }
		                         }
		                       if(f)
		                        break;
		                     }
		                   if(f)
		                    break;
		                }
		           }
		          if(f)
		           break;
		          
		           if(len==6)
		           {
		              for(int i=0;i<k;i++)
		                {
		                   long num=a[i];
		                   for(int j=i+1;j<k;j++)
		                     {
		                        if(i!=j)
		                         {
		                            long num2=num*10l+a[j];
		                            for(int l=j+1;l<k;l++)
		                            {
		                               long max=Math.max(Math.max(i,j),l);
		                               long min=Math.min(Math.min(i,j),l);
		                               if(max==min)
		                                continue;
		                                
		                              long num3=num2*10l+a[l];
		                              for(int m=l+1;m<k;m++)
		                               {
		                                  long max3=Math.max(Math.max(Math.max(i,j),l),m);
		                                  long min3=Math.min(Math.min(Math.min(i,j),l),m);
		                                  if(max3==min3)
		                                     continue;
		                                     
		                                  long num4=num3*10l+a[m];
		                                  for(int n=m+1;n<k;n++)
		                                 {
		                                  long max33=Math.max(Math.max(Math.max(Math.max(i,j),l),m),n);
		                                  long min33=Math.min(Math.min(Math.min(Math.min(i,j),l),m),n);
		                                  if(max33==min33)
		                                     continue;
		                                    long num5=num4*10l+a[n];
		                                    for(int o=n+1;o<k;o++)
		                                    {
		                                  long max32=Math.max(Math.max(Math.max(Math.max(Math.max(i,j),l),m),n),o);
		                                  long min32=Math.min(Math.min(Math.min(Math.min(Math.min(i,j),l),m),n),o);
		                                  if(max32==min32)
		                                     continue;
		                                  long num6=num5*10l+a[o];
		                                  if(!isPrime(num6))
		                                    {
		                                     f=true;
		                                    dig=len;
		                                    ans=num6;
		                                     break;
		                                    } 
		                                    }
		                                   if(f)
		                                    break;
		                                 }
		                                if(f)
		                                 break;
		                                  
		                               }
		                              if(f)
		                                   break;
		                            }
		                         }
		                       if(f)
		                        break;
		                     }
		                   if(f)
		                    break;
		                }
		           }
		          if(f)
		           break;
		          
		          
		          len++;
		        }
		      
		      out.println(dig);
		      out.println(ans);
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
static void print_int(ArrayList<Integer> al)
  {
     int si=al.size();
     for(int i=0;i<si;i++)
       {
          out.print(al.get(i)+" ");
       }
     out.println();
     out.flush();
  }
static void print_long(ArrayList<Long> al)
  {
     int si=al.size();
     for(int i=0;i<si;i++)
       {
          out.print(al.get(i)+" ");
       }
     out.println();
     out.flush();
  }
  
static int LowerBound(int a[], int x) 
 { 

  int l=-1,r=a.length;
  while(l+1<r) {
    int m=(l+r)>>>1;
    if(a[m]>=x) r=m;
    else l=m;
  }
  return r;
}

 static int UpperBound(int a[], int x)
  {

    int l=-1,r=a.length;
    while(l+1<r) {
       int m=(l+r)>>>1;
       if(a[m]<=x) l=m;
       else r=m;
    }
    return l+1;
 }
static void DFS(ArrayList<Integer> graph[],boolean[] visited, int u)
	{
        visited[u]=true;
        int v=0;
        for(int i=0;i<graph[u].size();i++)
        {
            v=graph[u].get(i);
            if(!visited[v])
               DFS(graph,visited,v);
        }
  } 
static boolean[] prime(int num)
 {
	      boolean[] bool = new boolean[num];
		     
		      for (int i = 0; i< bool.length; i++) {
		         bool[i] = true;
		      }
		      for (int i = 2; i< Math.sqrt(num); i++) {
		         if(bool[i] == true) {
		            for(int j = (i*i); j<num; j = j+i) {
		               bool[j] = false;
		            }
		         }
		      }
		      if(num >= 0) {
		    	  bool[0] = false;
		    	  bool[1] = false;
		      }
		      
		      return bool;
  }
static long nCr(long a,long b,long mod)
{
 return (((fact[(int)a] * modInverse(fact[(int)b],mod))%mod * modInverse(fact[(int)(a - b)],mod))%mod + mod)%mod;
}
static long fact[]=new long[max_num];
static void fact_fill()
 {
   long fact[]=new long[max_num];
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

