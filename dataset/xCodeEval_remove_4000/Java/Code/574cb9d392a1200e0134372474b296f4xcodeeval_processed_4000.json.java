





import java.io.*;
import java.util.*;
import java.math.BigInteger; 
import java.lang.*;





public class Main {
    
    
    
    
   static class sort implements Comparator<int[]>
   {
        public int compare(int[] a,int[] b)
        {
            
            return -b[0]+a[0];
        }
   }
   static class sort1 implements Comparator<int[]>
   {
        public int compare(int[] a,int[] b)
        {
            
          return  b[0]-a[0];
        }
   }
   static class sort5 implements Comparator<long[]>
   {
        public int compare(long[] a,long[] b)
        {
            
           double d1,d2;
           d1 = (a[0]+0.00)/(a[1]+0.00);
           d2 = (b[0]+0.00)/(b[1]+0.00);
           

           double eph = 0.000000000000001;
           double d = (d2-d1);
          

           if(d>eph) return 1;
           else if(d<eph) return -1;
           if(a[1]>b[1]) return 1;
           else if(b[1]>a[1]) return -1;
           return 0;
        }
   }
   static class sort11 implements Comparator<double[]>
   {
        public int compare(double[] a,double[] b)
        {
            

           if(a[1] < b[1]) return -1;
           else if(a[1] > b[1]) return 1;
           return 0;
        }
   }
   public static String[] F(BufferedReader bf) throws Exception
    {
        return (bf.readLine().split(" "));
    }
    
   public static void pr(PrintWriter out,Object o)
   {
      
    out.println(o.toString());

    
   }
   public static void prW(PrintWriter out,Object o)
   {
      
    out.print(o.toString());

    
   }
   public static int intIn(String st)
   {
      return Integer.parseInt(st);
   }
   
   
    
    public static void pr(Object o)
    {
        System.out.println(o.toString());
    }
    public static void prW(Object o)
    {
        System.out.print(o.toString());
    }
    
   
    public static int inInt(String s)
    {
        return Integer.parseInt(s);
    }
    public static long in(String s)
    {
        return Long.parseLong(s);
    }
 
 
    static int[] id1(String[] m) 
    { 
        int[] p=new int[m.length];
        for(int o=0;o<m.length;o++)
        {
            p[o]= inInt(m[o]);
        }
        return p;
    }
    static double[] id2(String[] m) 
    { 
        double[] p=new double[m.length];
        for(int o=0;o<m.length;o++)
        {
            p[o]= Double.parseDouble(m[o]);
        }
        return p;
    }
    static long[] id3(String[] m) 
    { 
       long[] p=new long[m.length];
        for(int o=0;o<m.length;o++)
        {
            p[o]= in(m[o]);
        }
        return p;
    }
    
    static int[][] di={{0,1},{1,0},{0,-1},{-1,0}};
    static int[] dir = {4,3,2,-4,-3,-2};
    
     static long gcd(long a, long b)
        {
          if (b == 0)
            return a;
          return gcd(b, a % b); 
        }
        static long Gp(long l,long b,long lcm)
        {
            long c1,c2;
                c1 = (l/lcm);
                long sum=0l;
                sum += (c1-1l)*(b);
                long las = (l/lcm)*lcm;
                sum += Math.min(l-las+1l,b);
                return sum;
        }
        static long pow(long x, long y, long p)
      {
        if(y == 0) return 1l;
        long res = 1; 

     
        x = x % p; 

        

     
        if (x == 0)
          return 0l; 

     
        while (y > 0)
        {
     
          

          if ((y & 1) != 0)
            res = (res * x) % p;
     
          

          y = y >> 1; 

          x = (x * x) % p;
        }
        return res;
      }
    
    public static long F(int a,int b)
    {
         return 462161773423l*(a+0l) + 4549834777463l*(b+0l);
    }
    static int nCr(int n, int r, int p)
    {
        if (r > n - r)
            r = n - r;
 
        

        

        

        int C[] = new int[r + 1];
 
        C[0] = 1; 

 
        

        

        for (int i = 1; i <= n; i++) {
 
            

            

            for (int j = Math.min(i, r); j > 0; j--)
 
                

                C[j] = (C[j] + C[j - 1]) % p;
        }
        return C[r];
    }
    

   public static int log(int x)
   {
       boolean bol = true;

       if(((x-1)&x) == 0) bol=false;

       int c=0;
       while(x > 0)
       {
        x=(x/2);
        c++;
       }

       if(!bol) c--;
       return c;

   }

   public static int F(int[] arr,int j,int x,int n)
   {

    if(j>=n) return 0;
    if(j == (n-1)) return 0;
    boolean bt = false;
       int i = j;

       while(i<n && arr[i]<= x)
       {
          i++;
       }
       int k = j;
       

       i--;
       while(k<i)
       {
          if(arr[k]>arr[k+1]) return -10000000;
          k++;
       }
       k = i+1;
       while(k<n)
       {
            if(arr[k] < x ) bt=true;
            k++;
       }

       k = j;
       boolean bol = true;
       while(k<(n-1))
       {
          if(arr[k]>arr[k+1]) 
          {
            bol=false;break;
          }

          k = k+1;
       }
       if(bol) return 0;

       int tem = arr[i+1];
       arr[i+1] = x;
       

       int sum;
       if(!bt)
        sum =  1 + F(arr,i+2,tem,n);
        else sum=-10000000;
     

       return sum;

   }
   static class sor implements Comparator<long[]>
   {
      public int compare(long[] a,long[] b)
      {
         if(a[0] == b[0])
         {
            if(a[1] < b[1]) return -1;
            return 1;
         }
         if(a[0] > b[0]) return 1;
         return -1;
      }
   }

   public static void F(int i,int[] vis,int v,List<Set<Integer>> list,TreeMap<Integer,Integer> tm,int[] arr)
   {
        vis[i] = v;
        if(tm.containsKey(arr[i])) tm.put(arr[i],tm.get(arr[i])+1);
        else tm.put(arr[i],1);
        for(int r : list.get(i))
        {
            if(vis[r] == 0)
            {
                F(r,vis,v,list,tm,arr);
            }
        }
   }
    static long ncr(int n, int r)
    {
 
        

        

        long p = 1, k = 1;
        if(n<r) return 0l;
 
        

        

        if (n - r < r) {
            r = n - r;
        }
 
        if (r != 0) {
            while (r > 0) {
                p *= n;
                k *= r;
 
                

                long m = id0(p, k);
 
                

                

                

                p /= m;
                k /= m;
 
                n--;
                r--;
            }
 
            

            

            

        }
        else {
            p = 1;
        }
 
        

        return p;
    }
 
    static long id0(long n1, long n2)
    {
        long gcd = 1;
 
        for (int i = 1; i <= n1 && i <= n2; ++i) {
            

            if (n1 % i == 0 && n2 % i == 0) {
                gcd = i;
            }
        }
        return gcd;
    }
    public static boolean F(double x,double[] arr,double k)
    {
         double eph = 0.0000001;
         double ans=0.00;
         for(double d : arr)
         {
                int c = Double.compare(d,x);
                if(c<0)
                {
                        ans += (x-d);
                }
                else if(c>0)
                {
                        ans -= ((d-x)*(1.00-k));
                }
         }

         return  (ans <= eph); 
    }
    public static void main (String[] args) throws Exception {
        
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);;;
        
        

      long[] op = new long[100001];
      op[0]=op[1]=0;
      op[2]=1l;
      for(int o=3;o<op.length;o++)
      {
          long v = (o+0l)*(o-1l);
          v = (v/2l);
          op[o] = v+op[o-1];
      }
       int yy=inInt(bf.readLine());
       


        
        for(int w=0;w<yy;w++)
        {
            

          out.flush();
         
            String[] xlp = bf.readLine().split(" ");;;;;;
            

         int n;

           int m;

           int ioo;
           int k;

         n=inInt(xlp[0]);

         Map<Long,TreeSet<Integer>> map=new HashMap<>();
         long[] ar=id3(F(bf));
        

         for(int o=0;o<ar.length;o++)
         {
                if(!map.containsKey(ar[o])){ map.put(ar[o],new TreeSet<>());}
                map.get(ar[o]).add(o);
         }
         

         long res=0l;
         
        Map<Long,Long> sum=new HashMap<>();

        for(int o=0;o<n;o++)
        {
            

            

            if(!sum.containsKey(ar[o])) sum.put(ar[o],0l);

            res += (sum.get(ar[o])*(n-o+0l));
            

            sum.put(ar[o],sum.get(ar[o])+(o+1l));

        }

         pr(out,res);








    }
    out.close();
   bf.close();
}}






























