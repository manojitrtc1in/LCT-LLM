import java.io.*; 
import java.util.*; 
import java.text.*; 
import java.math.*; 
import java.util.regex.*; 
import java.lang.*; 


public class Main{

    public static PrintWriter out;
    public static FastReader in;
    public static int mod = 1000003;
    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while(st==null || !st.hasMoreTokens()){
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){
            return Integer.parseInt(next());
        }
        long nextLong(){
            return Long.parseLong(next());
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str="";
            try {
                str=br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) {
        try {
            in = new FastReader();
            out = new PrintWriter(new BufferedOutputStream(System.out));
            int t = in.nextInt();
            while(t-->0){
                int n = in.nextInt();
                long[] a = new long[n];
                input(a);
                int l = 0; boolean ans = true;
                

                long min = 0,max = 0;
                for (int i=0;i<n-1;i++){
                    if(a[i]>a[i+1]){
                        ans = false;
                        break;
                    }
                }
                if(ans==true){
                    out.println("NO");
                    continue;
                }
                for (int i=1;i<n-1;i++){
                    max = findmax(a,i);
                    min = findmin(a,i);
                    if(max>min){
                        ans = false;
                        break;
                    }
                }

                if(ans==false){
                    out.println("YES");
                }else{
                    out.println("NO");
                }


            }
            out.flush();
            out.close();
        } catch (Exception e) {
            System.out.println("Exception");
            return;
        }
    }

    public static long findmax(long[] a,int l){
        long max = Integer.MIN_VALUE;
        for (int i=0;i<l;i++){
            max = Math.max(max,a[i]);
        }
        return max;
    }
    public static long findmin(long[] a,int l){
        long min = Integer.MAX_VALUE;
        for (int i=l;i<a.length;i++){
            min = Math.min(min,a[i]);
        }
        return min;
    }





    static boolean isPrime(int a){
        if (a == 1) return false;
        if (a == 2 || a == 3) return true;
        if (a%2==0 || a%3==0) return false;
        for (int i=5;i*i<=a;i+=6){
            if (a%i==0 || a%(i+2)==0) return false;
        }
        return true;
    }

    static void printAllPrime(int n){

        

        if(n <= 1)  return;

        boolean[] arr = new boolean[n+1];
        Arrays.fill(arr,true);
        for (int i=2;i*i<=n;i++){
            if (arr[i]){
                for (int j=i*i;j<=n;j+=i){
                    arr[j] = false;
                }
            }
        }
        for (int i=2;i<=n;i++){
            if (arr[i]){
                System.out.printf(i+" ");
            }
        }
    }

    static int highestPowerOf2(int x)
    {
       
        

        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
         
        

        

        

        

        return x ^ (x >> 1); 
     
    }

    static long pow(long a,long b){
        long ans = b;
        long res =1;
        if(b<0){
            ans = -1*b;
        }
        while(ans>0){
            if((ans&1)==1){
                res = (res*a)%mod;
            }
            a = (a*a)%mod;
            ans = ans>>1;
        }
        if(b<0){
            res = 1/res;
        }
        return res;
    }
    static double pow(double a,long b){
        long ans = b;
        double res =1;
        if(b<0){
            ans = -1*b;
        }
        while(ans>0){
            if((ans&1)==1){
                res = (res*a)%mod;
            }
            a = (a*a)%mod;
            ans = ans>>1;
        }
        if(b<0){
            res = 1/res;
        }
        return res;
    }

    static void sort(int[] arr)
    {
        ArrayList<Integer> ls = new ArrayList<Integer>();
        for(int x: arr)
            ls.add(x);
        Collections.sort(ls);
        for(int i=0; i < arr.length; i++)
            arr[i] = ls.get(i);
    }

    static void sort(long[] arr)
    {
        ArrayList<Long> ls = new ArrayList<Long>();
        for(long x: arr)
            ls.add(x);
        Collections.sort(ls);
        for(int i=0; i < arr.length; i++)
            arr[i] = ls.get(i);
    }

    static HashMap<Integer, Integer>  sortValue(HashMap<Integer,Integer> h){
        List<Map.Entry<Integer, Integer> > list = new ArrayList<>(h.entrySet());
 
        

        Collections.sort(list, new Comparator<Map.Entry<Integer, Integer> >() {
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2){
                int fp = o2.getValue().compareTo(o1.getValue());
                int sp = o2.getKey().compareTo(o1.getKey());
                return fp==0 ? sp : fp;
            }
        });
        

        

        HashMap<Integer, Integer> hm = new LinkedHashMap<>();
        for(Map.Entry<Integer, Integer> mp : list){
            hm.put(mp.getKey(),mp.getValue());
        }
        return hm;
    }
    static HashMap<Integer, Integer>  sortKey(HashMap<Integer,Integer> h){
        List<Map.Entry<Integer, Integer> > list = new ArrayList<>(h.entrySet());
 
        

        Collections.sort(list, new Comparator<Map.Entry<Integer, Integer> >() {
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2){
                int fp = o2.getValue().compareTo(o1.getValue());
                int sp = o2.getKey().compareTo(o1.getKey());
                return fp==0 ? fp : sp;
            }
        });
        

        

        HashMap<Integer, Integer> hm = new LinkedHashMap<>();
        for(Map.Entry<Integer, Integer> mp : list){
            hm.put(mp.getKey(),mp.getValue());
        }
        return hm;
    }

    static long totient(long n)
    {
        long result = n;
        for (int p = 2; p*p <= n; ++p)
            if (n % p == 0)
            {
                while(n%p == 0)
                    n /= p;
                result -= result/p;
            }
        if (n > 1)
            result -= result/n;
        return result;
    }

    static int pow(int x,int y){
        return (int)Math.pow(x,y);
    }

    static void allDivisor(int a){
        int i=0;
        for (i=1;i*i<=a;i++){
            if (a%i==0){
                System.out.printf(i+" ");
            }
        }
        for (;i>=1;i--){
            if (a%i==0){
                System.out.printf(a/i+" ");
            }
        }
    }

    static int binaryToInt(String s){
        return Integer.parseInt(s,2);
    }
    static String toBinaryString(int s){
        return Integer.toBinaryString(s);
    }


    static void primeFactors(int a){
        if (a<=1) return;
        while (a%2==0) {System.out.printf(2+" "); a=a/2;}
        while (a%3==0) {System.out.printf(3+" "); a=a/3;}
        for (int i=5;i*i<=a;i+=6){
            while (a%i==0){
                System.out.printf(i+" ");
                a = a/i;
            }
            while (a%(i+2)==0){
                System.out.printf((i+2)+" ");
                a = a / (i+2);
            }
        }
        if (a>3){
            System.out.printf(a+" ");
        }
        System.out.println();
    }

    static int lcm(int a,int b){
        return a*b/gcd(a,b);
    }

    static int gcd(int a, int b){
        if (a==0) return b;
        return gcd(b%a,a);
    }

    static int countZeros(int f){
        int x = 0;
        for (int i=5;i<=f;i=i*5){
            x += f/i;
        }
        return x;
    }

    static int ExtendedGcd(int a, int b,int x,int y){
       if(b == 0){
           x = 1;
           y = 0;
           return a;
       }
        int x1=1,y1=1;
       int ans = ExtendedGcd(b, a%b,x1,y1);
       x = y1;
       y = x1 - (a/b)*y1;
       System.out.println(x+" "+y);
       return ans;
    }











    
    static void input(int[] a){
        for (int i=0;i<a.length;i++){
            a[i] = in.nextInt();
        }
    }
    static void input(long[] a){
        for (int i=0;i<a.length;i++){
            a[i] = in.nextLong();
        }
    }
    static void input(String[] a){
        for (int i=0;i<a.length;i++){
            a[i] = in.next();
        }
    }

    static void swap(char[] c,int i,int j){
        char t = c[i];
        c[i] = c[j];
        c[j] = t;
    }
    static void swap(int[] c,int i,int j){
        int t = c[i];
        c[i] = c[j];
        c[j] = t;
    }
    static void swap(long[] c,int i,int j){
        long t = c[i];
        c[i] = c[j];
        c[j] = t;
    }

    static void print(int[] a){
        for (int i=0;i<a.length;i++){
            out.printf(a[i]+" ");
        }
        out.println();
    }

    static void print(int[][] a){
        for (int i=0;i<a.length;i++){
            for(int j=0;j<a[i].length;j++){
                out.printf(a[i][j]+" ");
            }
            out.println();
        }
    }

    static void print(long[] a){
        for (int i=0;i<a.length;i++){
            out.printf(a[i]+" ");
        }
        out.println();
    }

    static void print(char[] a){
        for (int i=0;i<a.length;i++){
            out.printf(a[i]+" ");
        }
        out.println();
    }

    static void print(String s){
        for (int i=0;i<s.length();i++){
            out.printf(s.charAt(i)+" ");
        }
        out.println();
    }

    static void print(ArrayList<Integer> a){
        a.forEach(e -> out.printf(e+" "));
        out.println();
    }

    static void print(LinkedList<Integer> a){
        a.forEach(e -> out.printf(e+" "));
        out.println();
    }
    
    static void print(HashSet<Integer> a){
        a.forEach(e -> out.printf(e+" "));
        out.println();
    }

    static void print(HashMap<Integer,Integer> a){

        for(Map.Entry<Integer, Integer> mp : a.entrySet()){
           out.println(mp.getKey() + " "+ mp.getValue());
        } 
    }

    static void reverse(int[] a){
        int i=0,j=a.length-1;
        while(i<j){
            int t = a[i];
            a[i] = a[j];
            a[j]= t;
            i++;
            j--;
        }
    }
    static String reverse(String s){
        char[] a = s.toCharArray();
        int i=0,j=a.length-1;
        while(i<j){
            char t = a[i];
            a[i] = a[j];
            a[j]= t;
            i++;
            j--;
        }
        return String.valueOf(a);
    }
}
class CompareP implements Comparator<Pair> {
    public int compare(Pair a, Pair b){
        long dif = a.v - b.v;
        if (dif > 0) return 1;
        if (dif < 0) return -1;
        return 0; 
    }
}
class CompareT implements Comparator<Triplet> {
    public int compare(Triplet a, Triplet b){
        long dif = a.z - b.z;
        if (dif > 0) return 1;
        if (dif < 0) return -1;
        return 0; 
    }
}

class Triplet{
    long x;
    long y;
    long z;
    public Triplet(long x,long y,long z){
        this.x = x;
        this.y = y;
        this.z = z;
    }
}


class Pair {
    int k;
    int v;

    public Pair(int k, int v) {
        this.k = k;
        this.v = v;
    }
}
class ncr
{
    public int mod = 1000003;
    public long[] fact = new long[mod+1];
    public long[] ifact = new long[mod+1];
    public int nCr(long n, long r)
    {
        preFactFermat();
        long ans = 1;
        

        

        

        

        

        

        

        

        

        ans = lucas(n,r,ans);
        
        return (int)ans;
    }
    public long lucas(long n,long r,long ans){
        if(r==0)return 1;
        long ni=n%mod,ri=r%mod;
        return (lucas(n/mod,r/mod,ans)*(fermat(ni,ri,ans)%mod))%mod;
    }
    
    public long fermat(long n,long r,long ans){
        if(n<r){
            return 0;
        }
        ans = (ans* (fact[(int)n]*((ifact[(int)r]*ifact[(int)(n-r)])%mod)%mod))%mod;
        return ans;
    }
    
    public void preFactFermat(){
        fact[1] = 1;
        fact[0] = 1;
        ifact[0] = expo(1,mod-2);
        ifact[1] = expo(1,mod-2);
        for(int i=2;i<=mod;i++){
            fact[i] = (i*(fact[i-1]%mod))%mod;
            ifact[i] = expo(fact[i],mod-2);
        }
    }
    
    public long expo(long a,long b){
        long ans = b;
        long res =1;
        if(b<0){
            ans = -1*b;
        }
        while(ans>0){
            if((ans&1)==1){
                res = (res*a)%mod;
            }
            a = (a*a)%mod;
            ans = ans>>1;
        }
        if(b<0){
            res = 1/res;
        }
        return res;
    }
}
class FenwickTree{

    int[] ft;

    public void print(){
        for (int i=0;i<ft.length;i++){
            System.out.printf(ft[i]+" ");
        }
    }

    public FenwickTree(int[] a){
        ft = new int[a.length+1];
        for (int i=0;i<a.length;i++){
            this.update(i,a[i]);
        }
    }

    public int getSum(int i){
        int sum = 0;

        while(i>0){
            sum += ft[i];
            i = i - (i & (-i));
        }
        return sum;
    }

    public void update(int i,int d){
        i = i +1;
        while(i<ft.length){
            ft[i] += d;
            i = i + (i &(-i));
        }
    }
}

class SegmentTree{
    
    int[] st;

    
    public SegmentTree(int[] a){
        st = new int[a.length*4];
        construct(a,0,a.length-1,0);
    }

    void print(){
        for(int i=0;i<st.length;i++){
            System.out.printf(st[i]+" ");
        }
        System.out.println();
    }

    int construct(int[] a,int ss,int se,int si){
        if(ss==se){
            st[si] = a[ss];
            return a[ss];
        }
        int mid = (ss+se)/2;

        st[si] = construct(a,ss,mid,2*si+1) + construct(a,mid+1,se,2*si+2);
        return st[si];
    }
    
    int getSum(int qs,int qe,int ss,int se,int si){
        if(qe<ss || qs>se){
            return 0;
        }
        if(ss>=qs && se <= qe){
            return st[si];
        }
        int mid = (ss+se)/2;

        return getSum(qs,qe,ss,mid,2*si+1) + getSum(qs,qe,mid+1,se,2*si+2);
    }
    
    void update(int ss,int se,int si,int i,int diff){
        if(ss > i || i> se){
            return;
        }
        this.st[si] += diff;
        if(ss< se){
            int mid = (ss+se)/2;
            update(ss,mid,2*si+1,i,diff);
            update(mid+1,se,2*si+2,i,diff);
        }
    }
}
