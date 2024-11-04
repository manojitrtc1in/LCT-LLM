import java.util.*;
import java.io.*;
import java.math.BigInteger;
 public class Solution
{
     static class Pair<A,B>{
        A parent;
        B rank;
        Pair(A parent,B rank)
        {
            this.rank=rank;
            this.parent=parent;
        }
    }






















































    static void swap(char ar[],int i,int j)
    {
        char f = ar[i];
        ar[i]=ar[j];
        ar[j]=f;
    }
    static ArrayList<Integer> graph[];
    static int ans=0;
     static long powers(long n) 
    { 
        int MOD=1000000007;
        if (n <= 1) { 
            return 1; 
        }
        n--;
  
        

        long res[][] = { { 1, 0 }, { 0, 1 } }; 
  
        

        long tMat[][] = { { 2, 2 }, { 1, 0 } };
        while (n > 0) { 
            if (n % 2 == 1) { 
                long tmp[][] = new long[2][2]; 
                tmp[0][0] = ((res[0][0] * tMat[0][0])%MOD 
                             + (res[0][1] * tMat[1][0])%MOD) 
                            %MOD;
                tmp[0][1] = ((res[0][0] * tMat[0][1])%MOD 
                             + (res[0][1] * tMat[1][1])%MOD) 
                            %MOD; 
                tmp[1][0] = ((res[1][0] * tMat[0][0])%MOD 
                             + (res[1][1] * tMat[1][0])%MOD) 
                            % MOD; 
                tmp[1][1] = ((res[1][0] * tMat[0][1])%MOD 
                             + (res[1][1] * tMat[1][1])%MOD) 
                            % MOD;
                res[0][0] = tmp[0][0]; 
                res[0][1] = tmp[0][1]; 
                res[1][0] = tmp[1][0]; 
                res[1][1] = tmp[1][1]; 
            } 
  
            n = n / 2; 
            long tmp[][] = new long[2][2]; 
            tmp[0][0] = ((tMat[0][0] * tMat[0][0])%MOD 
                         + (tMat[0][1] * tMat[1][0])%MOD) 
                        % MOD; 
            tmp[0][1] = ((tMat[0][0] * tMat[0][1])%MOD 
                         + (tMat[0][1] * tMat[1][1])%MOD) 
                        % MOD; 
            tmp[1][0] = ((tMat[1][0] * tMat[0][0])%MOD 
                         + (tMat[1][1] * tMat[1][0])%MOD) 
                        % MOD; 
            tmp[1][1] = ((tMat[1][0] * tMat[0][1])%MOD 
                         + (tMat[1][1] * tMat[1][1])%MOD) 
                        % MOD; 
            tMat[0][0] = tmp[0][0]; 
            tMat[0][1] = tmp[0][1]; 
            tMat[1][0] = tmp[1][0]; 
            tMat[1][1] = tmp[1][1]; 
        }
        return ((res[0][0]*6)%MOD + (res[0][1] * 2) % MOD)%MOD; 
    }
     static ArrayList<Integer> prime;
     static long a,b,c;
    public static void main (String[] args) throws IOException
    {
        StringBuilder sb = new StringBuilder();
        FastReader s1 = new FastReader();
        int t=s1.I();
        while(t--!=0)
        {
            int A=s1.I();
            int B=s1.I();
            int C=s1.I();
            TreeSet<Integer> ar = new TreeSet<>();
            TreeSet<Integer> br = new TreeSet<>();
            TreeSet<Integer> cr = new TreeSet<>();
            for(int i=0;i<A;i++)
                ar.add(s1.I());
            for(int i=0;i<B;i++)
                br.add(s1.I());
            for(int i=0;i<C;i++)
                cr.add(s1.I());
            long min=Long.MAX_VALUE;
            for(int i:ar)
            {
                Integer ceil1 = br.ceiling(i);
                Integer floor1=br.floor(i);
                Integer ceil2=cr.ceiling(i);
                Integer floor2=cr.floor(i);
                if(ceil1!=null)
                {
                    if(floor2!=null)
                    {
                        long temp1=Math.abs(ceil1-floor2);
                        long temp2=Math.abs(ceil1-i);
                        long temp3=Math.abs(i-floor2);
                        temp2=cal(temp1,temp2,temp3);
                        if(temp2<min)
                        {
                            min=temp2;
                        }
                    }
                    if(ceil2!=null)
                    {
                        long temp1=Math.abs(ceil1-ceil2);
                        long temp2=Math.abs(ceil1-i);
                        long temp3=Math.abs(i-ceil2);
                        temp2=cal(temp1,temp2,temp3);
                        if(temp2<min)
                        {
                            min=temp2;
                        }
                    }
                }
                if(floor1!=null)
                {
                    if(floor2!=null)
                    {
                        long temp1=Math.abs(floor1-floor2);
                        long temp2=Math.abs(floor1-i);
                        long temp3=Math.abs(i-floor2);
                        temp2=cal(temp1,temp2,temp3);
                        if(temp2<min)
                        {
                            min=temp2;
                        }
                    }
                    if(ceil2!=null)
                    {
                        long temp1=Math.abs(floor1-ceil2);
                        long temp2=Math.abs(floor1-i);
                        long temp3=Math.abs(i-ceil2);
                        temp2=cal(temp1,temp2,temp3);
                        if(temp2<min)
                        {
                            min=temp2;
                        }
                    }
                }
            }
            for(int i:br)
            {
                Integer ceil1 = ar.ceiling(i);
                Integer floor1=ar.floor(i);
                Integer ceil2=cr.ceiling(i);
                Integer floor2=cr.floor(i);
                if(ceil1!=null)
                {
                    if(floor2!=null)
                    {
                        long temp1=Math.abs(ceil1-floor2);
                        long temp2=Math.abs(ceil1-i);
                        long temp3=Math.abs(i-floor2);
                        temp2=cal(temp1,temp2,temp3);
                        if(temp2<min)
                        {
                            min=temp2;
                        }
                    }
                    if(ceil2!=null)
                    {
                        long temp1=Math.abs(ceil1-ceil2);
                        long temp2=Math.abs(ceil1-i);
                        long temp3=Math.abs(i-ceil2);
                        temp2=cal(temp1,temp2,temp3);
                        if(temp2<min)
                        {
                            min=temp2;
                        }
                    }
                }
                if(floor1!=null)
                {
                    if(floor2!=null)
                    {
                        long temp1=Math.abs(floor1-floor2);
                        long temp2=Math.abs(floor1-i);
                        long temp3=Math.abs(i-floor2);
                        temp2=cal(temp1,temp2,temp3);
                        if(temp2<min)
                        {
                            min=temp2;
                        }
                    }
                    if(ceil2!=null)
                    {
                        long temp1=Math.abs(floor1-ceil2);
                        long temp2=Math.abs(floor1-i);
                        long temp3=Math.abs(i-ceil2);
                        temp2=cal(temp1,temp2,temp3);
                        if(temp2<min)
                        {
                            min=temp2;
                        }
                    }
                }
            }
            for(int i:cr)
            {
                Integer ceil1 = ar.ceiling(i);
                Integer floor1=ar.floor(i);
                Integer ceil2=br.ceiling(i);
                Integer floor2=br.floor(i);
                if(ceil1!=null)
                {
                    if(floor2!=null)
                    {
                        long temp1=Math.abs(ceil1-floor2);
                        long temp2=Math.abs(ceil1-i);
                        long temp3=Math.abs(i-floor2);
                        temp2=cal(temp1,temp2,temp3);
                        if(temp2<min)
                        {
                            min=temp2;
                        }
                    }
                    if(ceil2!=null)
                    {
                        long temp1=Math.abs(ceil1-ceil2);
                        long temp2=Math.abs(ceil1-i);
                        long temp3=Math.abs(i-ceil2);
                        temp2=cal(temp1,temp2,temp3);
                        if(temp2<min)
                        {
                            min=temp2;
                        }
                    }
                }
                if(floor1!=null)
                {
                    if(floor2!=null)
                    {
                        long temp1=Math.abs(floor1-floor2);
                        long temp2=Math.abs(floor1-i);
                        long temp3=Math.abs(i-floor2);
                        temp2=cal(temp1,temp2,temp3);
                        if(temp2<min)
                        {
                            min=temp2;
                        }
                    }
                    if(ceil2!=null)
                    {
                        long temp1=Math.abs(floor1-ceil2);
                        long temp2=Math.abs(floor1-i);
                        long temp3=Math.abs(i-ceil2);
                        temp2=cal(temp1,temp2,temp3);
                        if(temp2<min)
                        {
                            min=temp2;
                        }
                    }
                }
            }
              sb.append((min)+"\n");
        }
        System.out.println(sb);
    }
    static long cal(long a,long b,long c)
    {
        return a*a+b*b+c*c;
    }
       static long computeXOR(long n) 
    { 
        

        if (n % 4 == 0) 
            return n; 
       
        

        if (n % 4 == 1) 
            return 1; 
       
        

        if (n % 4 == 2) 
            return n + 1; 
       
        

        return 0; 
    } 
     static void dfs(int index,int pc,int color[])
    {
        int c=0;
        BitSet bs= new BitSet(color.length+1);
        bs.set(color[index]);
        if(pc>=0)
        bs.set(pc);
        for(int i:graph[index])
        {
            if(color[i]==-1)
            {
                if(color[index]==c || pc==c)
                c=bs.nextClearBit(0);
                color[i]=c++;
                bs.set(c-1);
                dfs(i,color[index],color);
            }
        }
    }
    static void add1(TreeMap<Long,Integer> map,long key)
    {
        map.putIfAbsent(key, 0);
        map.replace(key, map.get(key)+1);
    }
    static void remove1(TreeMap<Long,Integer> map,long key)
    {
        map.replace(key, map.get(key)-1);
        if(map.get(key)==0)
            map.remove(key);
    }
    static void print(int h[])
    {
        for(int I:h)
            System.out.print(I+" ");
        System.out.println("");
    }
        static String preprocess(String s)
    {
        StringBuilder sb = new StringBuilder();
        sb.append("@#");
        for(int i=0;i<s.length();i++)
        {
            sb.append(s.charAt(i)).append("#");
        }
        sb.append("$");
        return sb.toString();
    }
    static String LPS(String s)
    {
        String snew = preprocess(s);
        int n = snew.length();


        int c = 0,r = 0;
        int maxlen = 0;
        int index=0;
        int len[] = new int[n];
        for(int i=1;i<n-1;i++)
        {
            int mirr = c-(i-c);
            if(i<r)
            {
                len[i]=Math.min(len[mirr],r-i);
            }
      

            while(snew.charAt(i+len[i])==snew.charAt(i-len[i]))
                len[i]++;
            if(i+len[i]>r)
            {
                c = i;
                r = i+len[i];
            }


            if(len[i]>maxlen)
            {


                maxlen = len[i];
                index = i;
            }
        }
        maxlen--;
        int left = (index-maxlen-1)/2;
        int right = left+maxlen;
        return s.substring(left, right);
    }
    static void phi(int n,HashMap<Integer,Integer> hm)
    {
        int large=0;
        for(int i=2;i<=Math.sqrt(n);i++)
        {
            if(n%i==0)
            {
                if(i>large)
                {
                    large=i;
                }
            }
            while(n%i==0)
            {
                n=n/i;
            }
        }
        if(n>1)
        {
            if(n>large)
                large=n;
        }
        hm.putIfAbsent(large, 0);
        hm.replace(large, hm.get(large)+1);
    }
    static ArrayList<Integer> primeFactor(int n)
    {
        ArrayList<Integer> ans = new ArrayList<>();
        if(n%2==0)
            ans.add(2);
        while (n%2==0)
        {   
            n /= 2;
        }
        for (int i = 3; i <= Math.sqrt(n); i+= 2)
        {
            if(n%i==0)
                ans.add(i);
            while (n%i == 0)
            {
                n /= i;
            }
        }
        if (n > 2)
            ans.add(n);
        return ans;
    }
    static int longestSubSeg(int a[], int n,int k)
    {
        int cnt0 = 0;
        int l = 0;
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0)
                cnt0++;
            while (cnt0 > k) {
                if (a[l] == 0)
                    cnt0--;
                l++;
            }
            max_len = Math.max(max_len, i - l + 1);
        }
        
        return max_len;
    }
    static int binary(int left,int right,long ar[],long no)
    {
        int mid=(left+right)/2;
        if(Math.abs(right-left)<=1)
        {
            if(no<=ar[left])
            {
                return left;
            }
            else
            {
                return right;
            }
        }
        if(ar[mid]==no)
            return mid;
        if(ar[mid]>no)
        {
            right=mid;
            return binary(left, right, ar, no);
        }
        else{
            left=mid;
            return binary(left, right, ar, no);
        }
    }
    static class FastReader{
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
        
        int I()
        {
            return Integer.parseInt(next());
        }
        
        long L()
        {
            return Long.parseLong(next());
        }
        
        double D()
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
    static long gcd(long a,long b)
    {
        if(a%b==0)
            return b;
        return gcd(b,a%b);
    }
    static float power(float x, int y)
    {
        float temp;
        if( y == 0)
            return 1;
        temp = power(x, y/2);
        
        if (y%2 == 0)
            return temp*temp;
        else
        {
            if(y > 0)
                return x * temp * temp;
            else
                return (temp * temp) / x;
        }
    }
    static long pow(long x, long y)
    {
        int p =  1000000007;
        long res = 1;
        x = x % p;
        if(x<0)
            x+=p;
        while (y > 0)
        {
            if((y & 1)==1){
                res = (res * x) % p;
                if(res<0)
                    res+=p;
            }
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }
    static void sieveOfEratosthenes(int n)
    {
        prime=new ArrayList<Integer>();
        boolean Prime[] = new boolean[n+1];
        for(int i=2;i<n;i++)
            Prime[i] = true;
        
        for(int p = 2; p*p <=n; p++)
        {
            if(Prime[p] == true)
            {
                prime.add(p);
                for(int i = p*p; i <= n; i += p)
                    Prime[i] = false;
            }
        }
    }
}