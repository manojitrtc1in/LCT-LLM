


import java.io.*;
import java.util.*;
import java.util.LinkedList;

public class Main {

    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(
                    new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[64]; 

            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    } else {
                        continue;
                    }
                }
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
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

        public long nextLong() throws IOException {
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

        public double nextDouble() throws IOException {
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

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0,
                    BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }

        static class FastReader {
            BufferedReader br;
            StringTokenizer st;

            public FastReader() {
                br = new BufferedReader(
                        new InputStreamReader(System.in));
            }

            String next() {
                while (st == null || !st.hasMoreElements()) {
                    try {
                        st = new StringTokenizer(br.readLine());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
                return st.nextToken();
            }

            int nextInt() {
                return Integer.parseInt(next());
            }

            long nextLong() {
                return Long.parseLong(next());
            }

            double nextDouble() {
                return Double.parseDouble(next());
            }

            String nextLine() {
                String str = "";
                try {
                    str = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                return str;
            }
        }

    }


    public static void main(String[] args) {
        Reader.FastReader sc = new Reader.FastReader();
        int t = sc.nextInt();
        while (t-->0) {
            int n = sc.nextInt();
            long [] arr = new long [n];
            for(int i = 0; i<n; i++){
                arr[i] =sc.nextLong();
            }

            if(id4(arr, n))
                System.out.println("YES");
            else{
                System.out.println("NO");
            }

        }





    }

    public static int id3(int o, int to){
        if(o==0){
            return 1;
        }
        if(to==0){
            return o+1;
        }

        return o+to*2+1;
    }

    public static boolean id4(long [] arr, int n){
        if(n==1 && arr[0]>1){
            return false;
        }


        Arrays.sort(arr);
        boolean ans = true;
        if(n>=2)
        ans = arr[n - 1] - arr[n - 2] < 2;

        return ans;
    }

    public static void cos(String s, int n){
        int f = 0;
        int m = 0;

        int ans=  0;
        int prev = -1;
        for(int i = 0; i<n-1; i++){
            if(s.charAt(i)=='0' && s.charAt(i+1)=='1'){
                if(prev!=i)
                    ans+=1;
            }
            else if(s.charAt(i)=='0' && s.charAt(i+1)=='0'){
                ans+=2;
                prev = i+1;
            }

        }
        System.out.println(ans);
    }
    public static void ans(int x, int y){
        if(x==0 && y==0){
            System.out.println(0);
            return ;
        }
        double distance = Math.sqrt((x*x) + (y*y));

        if(distance-Math.floor(distance)==0){
            System.out.println(1);
        }
        else{
            if(x!=0 && y!=0){
                System.out.println(2);
            }
            else{
                System.out.println(1);
            }
        }
    }

    public static void ans2(int n, long b, long x, long y){
        long sum = 0;
        long currNum = 0;
        long prevNum = 0;
        for(int i = 1; i<=n; i++){
            currNum = prevNum+x;
            if(currNum>b){
                currNum -=(x+y);
            }
            sum+=currNum;
            prevNum = currNum;
        }
        System.out.println(sum);
    }

    public static void ans3(String s, int n){



        int count = 0;
        char o = s.charAt(0);
        int i = 1;
        int stop = 0;
        while(i<n){
            if(o=='(' && s.charAt(i)==')'){
                count++;
                if(i+1<n) {
                    o = s.charAt(i + 1);
                }
                stop = i+1;
                i+=2;
                continue;
            }
            while(i<n && s.charAt(i)!=o){
                i++;
            }
            if(i<n && s.charAt(i)==o) {
                count++;
                if(i+1<n) {
                    o = s.charAt(i + 1);

                }
                stop = i+1;
                i+=2;
            }

        }
        System.out.println(count+" "+ (n-stop));

    }



    public static boolean id1(ArrayList<String> arr, int n){
        HashSet<String> hash = new HashSet<>();
        for(int i = 0; i<n; i++){
            String curr  = arr.get(i);
            String [] id2 = id2(curr);
            if(curr.equals(reverse(curr))){
                return true;
            }
            for(int currSuffix= 0; currSuffix<id2.length; currSuffix++){
                if(hash.contains(id2[currSuffix])){
                    return true;
                }
            }

            hash.add(curr);
        }

        return false;
    }

    public static String [] id2(String s){
        String [] arr = new String[3];
        StringBuilder x = new StringBuilder();
        int pos = 0;
        for(int i = s.length()-1; i>=0; i--){
            x.append(s.charAt(i));
            arr[pos++] = x.toString();
        }
        return arr;
    }

    public static String reverse(String s)
    {


        StringBuilder ans = new StringBuilder();

        

        ans.append(s);

        

        ans.reverse();

        

       return ans.toString();
    }


















































    public static boolean isPoss(String s, int n){
        for(int i = 0; i<n; i++){
            boolean flag = true;
            for(int j = i+4;j<n ;j++){
                if(!id0(s, i, j)){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                return false;
            }
        }

        return true;
    }

    public static boolean id0(String s, int start, int end){
        while(start<=end){
            char st = s.charAt(start);
            char et = s.charAt(end);

            if(st!='?'&& et!='?'){
                if(st!=et){
                    return false;
                }
            }
            else{
                return false;
            }

            start++;
            end--;
        }

        return true;

    }
    public static long sum(long [] arr, int n){
        long sum = 0;
        for(long i : arr){
            sum+=i;
        }

        return sum;
    }
    public static void solve(int []arr, int n, int k){
        PriorityQueue<int []> pq = new PriorityQueue<>();
        for(int i = 0; i<n; i++){
            pq.add(new int []{arr[i],i});
        }

        while(k>0 && pq.size()>0){
            int [] rem = pq.poll();
            int i = rem[1];
            int l = -1;
            int r = -1;

            if(i-1>=0){
                l = rem[i-1];
            }
            if(i+1<n){
                r = rem[i+1];
            }
            int val = Math.max(rem[0], Math.max(rem[i-1],rem[i+1]));
            k--;
            pq.add(new int []{val, i});
        }
    }
    public static void math(int d) {
        int num2 = d / 2;
        int num1 = d % 2;

        if (num2 - num1 >= 2) {
            int diff = (int) Math.ceil(((float)num2) / 2);
            num1 += (num2 - diff) * 2;
            num2 = diff;

        }
        System.out.println(num2+" "+ num1);
        if (num2 > num1) {
            while (num2 > 0 && num1 > 0) {
                System.out.print("" + 2 + " " + 1 + " ");
                num2--;
                num1--;
            }
            if (num2 > 0) {
                System.out.print(2);
            }
        } else {
            while (num2 > 0 && num1 > 0) {
                System.out.print("" + 1 + " " + 2 + " ");
                num2--;
                num1--;
            }
            if (num1 > 0) {
                System.out.print(1);
            }
        }

        System.out.println();
    }
    public static int[] solve(String s, int n) {
        int[] one = new int[n];
        int[] zero = new int[n];
        one[0] = s.charAt(0) == '1' ? 1 : 0;
        zero[0] = s.charAt(0) == '0' ? 1 : 0;
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == '1') {
                one[i] = one[i - 1] + 1;
            } else {
                one[i] = one[i - 1];
            }
        }
        System.out.println(Arrays.toString(one));
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == '0') {
                zero[i] = zero[i - 1] + 1;
            } else {
                zero[i] = zero[i - 1];
            }
        }
        System.out.println(Arrays.toString(zero));
        int[] finalArr = new int[n];
        finalArr[0] = one[0];
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == '0') {
                finalArr[i] = finalArr[i - 1];
            } else {
                finalArr[i] = zero[i] + 1 + finalArr[i - 1] + one[i - 1];
            }

        }
        System.out.println(Arrays.toString(finalArr));
        return finalArr;
    }


    


















    






    


    

    

    

    

    

    

    

    


    







































    
























    


















    
















































































    


































































































































































































































    }
