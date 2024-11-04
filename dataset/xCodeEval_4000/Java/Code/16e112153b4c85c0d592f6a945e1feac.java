import java.sql.SQLSyntaxErrorException;
import java.util.*;
import java.io.*;
import java.util.stream.StreamSupport;
public class Solution {

    static int mod = 998244353;
    

    public static void main(String str[]) throws IOException{


        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-->0){
            int n = sc.nextInt();
            int[] arr = new int[n];
            Set<Integer> set = new HashSet<>();
            boolean bb = false;
            for(int i=0;i<n;i++){
                arr[i] = Math.abs(sc.nextInt());
                if(set.contains(arr[i])|| arr[i]==0){
                    bb = true;
                }
                set.add(arr[i]);
            }
            String ans = "NO";
            if(bb){
                ans = "YES";
            }
            else{
                boolean bool = false;
                Set<Integer> set2 = new HashSet<>();
                Map<Integer, Set<Integer>> map = new HashMap<>();
                set2.add(arr[0]);
                Set<Integer> tts = new HashSet<>();
                tts.add(arr[0]);
                map.put(arr[0], tts);
                for(int i=1;i<n;i++){
                    int x = arr[i];
                    ArrayList<Integer> al = new ArrayList<>(set2);
                    for(int j: al) {
                        int a = Math.abs(x - j);
                        int b = Math.abs(x + j);
                        if(set.contains(a)){
                            if(a!=x && !map.get(j).contains(a)){
                                bool = true;
                                ans = "YES";
                                break;
                            }

                        }
                        else{
                            set2.add(a);
                            Set<Integer> ss = new HashSet<>(map.get(j));
                            ss.add(x);
                            map.put(a, ss);
                        }
                        if(set.contains(b)){
                            if(b!=x && !map.get(j).contains(b)){
                                bool = true;
                                ans = "YES";
                                break;
                            }
                        }
                        else{
                            set2.add(b);
                            Set<Integer> ss = new HashSet<>(map.get(j));
                            ss.add(x);
                            map.put(b, ss);
                        }
                    }
                    if(bool)    break;
                    set2.add(arr[i]);
                    Set<Integer> tts2 = new HashSet<>(arr[i]);
                    tts2.add(arr[i]);
                    map.put(arr[i], tts2);
                }
            }
            System.out.println(ans);
        }

        output.flush();

    }




    long fun2(ArrayList<Integer> arr, int x){
        ArrayList<ArrayList> al = new ArrayList<>();
        ArrayList<Integer> curr = new ArrayList<>();
        fun(arr, x, al, curr, 0);
        if(al.size()==0)    return 0;
        int max = 0;
        for(ArrayList<Integer> i: al){
            if(i.size()>max)    max = i.size();
        }
        for(int i=0;i<al.size();i++){
            if(al.get(i).size()!=max){
                al.remove(i);
                i--;
            }
        }
        for(ArrayList<Integer> i: al){
            Collections.sort(al, Collections.reverseOrder());
        }
        long ans = 0;

        for(ArrayList<Integer> i: al){
            long temp = 0;
            for(int j: i){
                temp*=10;
                temp+=j;
            }
            if(ans<temp)    ans = temp;
        }
        return ans;

    }
    void fun(ArrayList<Integer> arr, int x, ArrayList<ArrayList> al, ArrayList<Integer> curr, int i){
        if(x<0) return ;
        if(x==0) {
            al.add(curr);
            return;
        }
        for(int j=i;j<arr.size();j++){
            ArrayList<Integer> temp = new ArrayList<>(curr);
            fun(arr, x-arr.get(j), al, temp, j);
        }
    }



    

    static int modInverse(long n, long p)
    {
        return (int)power(n, p - 2, p);
    }

    

    

    static long nCrModPFermat(int n, int r,
                              int p, long[] fac)
    {

        if (n<r)
            return 0;
        

        if (r == 0)
            return 1;

        

        

        

        long x = modInverse(fac[r], p);
        long y = modInverse(fac[n - r], p);

        return (fac[n] * x
                % p * y
                % p)
                % p;
    }

    static long[] sum(String[] str){
        int n = str[0].length();
        long ans[] = new long[n];
        for(String s: str){
            for(int i=0;i<n;i++)   ans[i]+=s.charAt(i);
        }
        return ans;
    }

    static class tSort implements Comparator<Pair>{

        public int compare(Pair s1, Pair s2) {
            if (s1.b < s2.b)
                return -1;
            else if (s1.b > s2.b)
                return 1;
            return 0;
        }
    }

    long ans = 0;





















    static ArrayList<String> fun( int curr, int n, char c){
        int len = n-curr;
        if(len==0)  return null;
        ArrayList<String> al = new ArrayList<>();
        if(len==1){
            al.add(c+"");
            return al;
        }
        String ss = "";
        for(int i=0;i<len/2;i++){
            ss+=c;
        }
        ArrayList<String> one = fun(len/2+curr, n, (char)(c+1));
        for(String str: one){
            al.add(str+ss);
            al.add(ss+str);
        }
        return al;
    }
    static ArrayList convert(int x, int k){
        ArrayList<Integer> al = new ArrayList<>();
        if(x>0) {
            while (x > 0) {
                al.add(x % k);
                x /= k;
            }
        }
        else    al.add(0);
        return al;
    }




    static int max(int x, int y, int z){
        int ans = Math.max(x,y);
        ans = Math.max(ans, z);
        return ans;
    }
    static int min(int x, int y, int z){
        int ans = Math.min(x,y);
        ans = Math.min(ans, z);
        return ans;
    }
























    public static int primeFactors(int n, int k)
    {
        int ans = 0;

        while (n%2==0)
        {
            ans++;
            if(ans>=k)  return k;
            n /= 2;
        }
        for (int i = 3; i <= Math.sqrt(n); i+= 2)
        {
            while (n%i == 0)
            {
                ans++;
                n /= i;
                if(ans>=k)  return k;
            }
        }

        if (n > 2)  ans++;
        return ans;
    }
    static int binaryLow(ArrayList<Integer> arr, int x, int s, int e){
        if(s>=e){
            if(arr.get(s)>=x)  return s;
            else    return s+1;
        }
        int m = (s+e)/2;
        if(arr.get(m)==x)  return m;
        if(arr.get(m)>x)   return binaryLow(arr,x,s,m);
        if(arr.get(m)<x)   return binaryLow(arr,x,m+1,e);
        return 0;
    }
    static int binaryLow(int[] arr, int x, int s, int e){
        if(s>=e){
            if(arr[s]>=x)  return s;
            else    return s+1;
        }
        int m = (s+e)/2;
        if(arr[m]==x)  return m;
        if(arr[m]>x)   return binaryLow(arr,x,s,m);
        if(arr[m]<x)   return binaryLow(arr,x,m+1,e);
        return 0;
    }
    static int binaryHigh(int[] arr, int x, int s, int e){
        if(s>=e){
            if(arr[s]<=x)  return s;
            else    return s-1;
        }
        int m = (s+e)/2;
        if(arr[m]==x)  return m;
        if(arr[m]>x)   return binaryHigh(arr,x,s,m-1);
        if(arr[m]<x)   return binaryHigh(arr,x,m+1,e);
        return 0;
    }


    static void arri(int arr[], int n, Reader sc) throws IOException{
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
    }
    static void arrl(long arr[], int n, Reader sc) throws IOException{
        for(int i=0;i<n;i++){
            arr[i] = sc.nextLong();
        }
    }

    static long gcd(long a, long b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    static long power(long x, long y, long p)
    {
        long res = 1; 


        x = x % p; 

        


        if (x == 0)
            return 0; 


        while (y > 0)
        {

            

            if ((y & 1) != 0)
                res = (res * x) % p;

            

            y = y >> 1; 

            x = (x * x) % p;
        }
        return res%p;
    }

























    static class Pair{
        

        long a=0;
        long b=0;
        












    }
    





















    static class SortbyI implements Comparator<Pair> {
        

        

        public int compare(Pair a, Pair b)
        {
            if(a.a>=b.a) return 1;
            else return -1;
        }
    }
    static class SortbyD implements Comparator<Pair> {
        

        

        public int compare(Pair a, Pair b)
        {
            if(a.a<b.a) return 1;
            else if(a.a==b.b && a.b>b.b)    return 1;
            else return -1;
        }
    }
    static int binarySearch(ArrayList<Pair> a, int x, int s, int e){
        if(s>=e){
            if(x<=a.get(s).b)  return s;
            else    return s+1;
        }
        int mid = (e+s)/2;
        if(a.get(mid).b<x){
            return binarySearch(a, x, mid+1, e);
        }
        else    return binarySearch(a,x,s, mid);
    }

    

























    static class Tree{
        int a;

        ArrayList<Tree> al = new ArrayList<>();
        Tree(int a){
            this.a = a;
        }


    }

    static class Reader {
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
            din = new DataInputStream(
                    new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException
        {
            byte[] buf = new byte[64]; 

            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
                buf[cnt++] = (byte)c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

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
            } while ((c = read()) >= '0' && c <= '9');
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
            } while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0,
                    BUFFER_SIZE);
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


    static boolean isPrime(int n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 ||
                n % 3 == 0)
            return false;

        for (int i = 5;
             i * i <= n; i = i + 6)
            if (n % i == 0 ||
                    n % (i + 2) == 0)
                return false;

        return true;
    }
    static ArrayList<Integer> sieveOfEratosthenes(int n)
    {
        ArrayList<Integer> al = new ArrayList<>();
        

        

        

        

        

        

        

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

        

        for (int i = 2; i <= n; i++)
        {
            if (prime[i] == true)
                al.add(i);
        }
        return al;
    }

}







