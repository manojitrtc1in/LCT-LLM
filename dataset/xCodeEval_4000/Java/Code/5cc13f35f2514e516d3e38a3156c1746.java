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
        sc.nextLine();
        while(t-->0){
            int n = sc.nextInt();
            int[] k = new int[n];
            int[] h = new int[n];
            for(int i=0;i<n;i++){
                k[i] = sc.nextInt();
            }
            for(int i=0;i<n;i++){
                h[i] = sc.nextInt();
            }
            long ans = 0;
            long curr = 0;
            long currstart = k[n-1]+1;
            for(int i=n-1;i>=0;i--){
                if(currstart>k[i]){
                    ans+=((curr)*(curr+1))/2;
                    currstart = k[i]-h[i]+1;
                    curr = h[i];
                }
                else{
                    if(k[i]-currstart+1<h[i]){
                        curr+=h[i]-(k[i]-currstart+1);
                        currstart = k[i]-h[i]+1;
                    }
                }
            }
            ans+=((curr)*(curr+1))/2;
            System.out.println(ans);

        }
        output.flush();
    }
    public static int fun(Node d, int k, Node head){
        if(d==null){
            int ans = 0;
            Node curr = head;
            while(curr!=null){
                ans+=(curr.time*curr.dis);
                curr = curr.next;
            }
            return ans;
        }
        int ret = fun(d.next,k, head);
        if(d!=head && k>0){
            int temp = d.pre.dis;
            Node pre = d.pre;
            Node next = d.next;
            pre.dis = pre.dis+d.dis;
            pre.next = next;
            if(next!=null){
                next.pre = pre;
            }
            ret = Math.min(ret,fun(d.next,k-1,head));
            pre.dis = temp;
            pre.next = d;
            if(next!=null){
                next.pre = d;
            }
        }
        return ret;

    }
    static class Node{
        int dis;
        int time;
        int val = -1;
        boolean b = true;
        Node pre = null;
        Node next = null;
        Node( int c, int b){
            dis = c;
            time = b;
        }
    }


    static int dp(ArrayList<Integer> arr, ArrayList<Integer> num, HashMap<Double, Integer> memo, double curr, int ans){
        if(memo.containsKey((Math.pow(ans,4)*Math.pow(curr,3))))  return memo.get(curr);
        int max = 0;
        int fin = 0;
        for(int i=0;i<arr.size();i++){
            int x = arr.get(i);
            arr.remove(i);
            int y = num.get(i);
            num.remove(i);
            int pp = x;
            if(ans!=-1) pp = (int)gcd(ans, x);
            if(pp==1){
                int temp = pp+arr.size();
                if(max<=temp){
                    max = temp;
                    fin = pp;
                }
                continue;
            }
            int temp = pp + dp(arr, num, memo, curr+(Math.pow(x,7)/Math.pow(x,4)), pp);
            if(max<=temp){
                max = temp;
                fin = pp;
            }
            num.add(i,y);
            arr.add(i,x);
        }
        memo.put(curr, max);
        return max+fin;
    }
    static void add(ArrayList<Pair> al, Pair x){
        int ind = Collections.binarySearch(al, x, new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                return o1.val-o2.val;
            }
        });
        if(ind<0){
            ind++;
            ind*=-1;
        }
        al.add(ind, x);

    }

    static int max(ArrayList<Integer> al){
        int i=0;
        int max =Integer.MIN_VALUE;
        for(int j=0;j<al.size();j++){
            int k = al.get(j);
            if(k>max){
                i = j;
                max = k;
            }
        }
        return i;
    }

    static class Pair {
        int val;
        int ind;
        

        Pair(int v, int ss) {
            val = v;
            ind = ss;
        }
    }

    

    

    

    

    

    


    

















































    static int maxHeight(List<Integer> wallPositions, List<Integer> wallHeights){
        int ans = 0;
        int n = wallHeights.size();
        for(int i=1;i<n;i++){
            int ind1 = wallPositions.get(i-1);
            int ind2 = wallPositions.get(i);
            if(ind2-ind1==1)    continue;
            int x = wallHeights.get(i-1);
            int y = wallHeights.get(i);
            int index = (y-x+ind1+ind2)/2;
            if(index<=ind1){
                index = ind1+1;
            }
            else if(index>=ind2){
                index = ind2-1;
            }
            ans = Math.max(ans, Math.min(x+(index-ind1),y+(ind2-index)));
        }
        return ans;
    }


















    public static ArrayList<Integer> primeFactors(int n)
    {
        

        ArrayList<Integer> al = new ArrayList<>();
        while (n%2==0)
        {
            al.add(2);
            n /= 2;
        }

        

        

        for (int i = 3; i <= Math.sqrt(n); i+= 2)
        {
            

            while (n%i == 0)
            {
                al.add(i);
                n /= i;
            }
        }

        

        

        if (n > 2)
            al.add(n);

        return al;
    }




    static void bfs(Graph[] g, int ind, boolean vis[], ArrayList<Node> al, Set<Integer> set){
        vis[ind] = true;
        set.add(ind);
        for(int i: g[ind].pq){
            if(!vis[i])     bfs(g,i,vis,al,set);
        }
        g[ind].set = set;
    }





















    static long divide(long p, long q, long mod)
    {
        long expo = mod - 2;

        while (expo != 0)
        {
            if ((expo & 1) == 1)
            {




                p = (p * q) % mod;






            }
            q = (q * q) % mod;







            expo >>= 1;
        }
        return p;
    }


    static class Graph{
        int ind;
        ArrayList<Integer> pq = new ArrayList<>();
        Set<Integer> set;
        boolean b = false;
        public Graph(int a){
            ind = a;
        }


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



    

    static long modInverse(long n, long p)
    {
        return (long)power(n, p - 2, p);
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