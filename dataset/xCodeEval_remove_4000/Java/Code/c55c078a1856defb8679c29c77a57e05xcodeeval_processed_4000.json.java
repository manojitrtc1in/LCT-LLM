import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.PI;
import static java.lang.System.in;
import static java.lang.System.out;

public class B {
    public static void main(String[] args) throws Exception {   
        Foster sc = new Foster();
        PrintWriter p = new PrintWriter(out);
        int t = sc.nextInt();
        while(t--!=0){
            int n = sc.nextInt();
            int m = sc.nextInt();
            int a[][] = new int[n][m];
            for(int i = 0; i < n; i++){
                char arr[] = sc.next().toCharArray();
                for(int j = 0; j < m; j++){
                    if(arr[j]=='1') a[i][j] = 1;
                    else    a[i][j] = 0;
                }
            }

            ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

            for(int i = 0; i < n-1; i++){
                for(int j = 0; j < m-1; j++){

                    ArrayList<Integer> inThis = new ArrayList<>();
                    int countOne = 0, countZero = 0;
                    for(int x = i; x < i+2; x++){
                        for(int y = j; y < j+2; y++){
                            if(a[x][y] == 0)    countZero++;
                            if(a[x][y] == 1)    countOne++;
                        }
                    }
                    int x1 = i, y1 = j;
                    int x2 = i, y2 = j+1;
                    int x3 = i+1, y3 = j;
                    int x4 = i+1, y4 = j+1;

                    if(countZero==4)    continue;

                    if(countOne==4){
                        inThis = new ArrayList<>();
                        inThis.add(x1);
                        inThis.add(y1);
                        inThis.add(x2);
                        inThis.add(y2);
                        inThis.add(x4);
                        inThis.add(y4);
                        a[x1][y1] = 0;
                        a[x2][y2] = 0;
                        a[x4][y4] = 0;
                        ans.add(inThis);

                        

                        inThis = new ArrayList<>();
                        int counter = 0;
                        for(int x = i; x < i+2; x++){
                            for(int y = j; y < j+2; y++){
                                if(a[x][y] == 0){
                                    a[x][y] = -1;
                                    inThis.add(x);
                                    inThis.add(y);
                                    counter++;
                                }
                                if(counter == 2)    break;
                            }
                            if(counter == 2)    break;
                        }
                        boolean got = false;
                        for(int x = i; x < i+2; x++){
                            for(int y = j; y < j+2; y++){
                                if(a[x][y] == 1){
                                    a[x][y] = -2;
                                    inThis.add(x);
                                    inThis.add(y);
                                    got = true;
                                    break;
                                }
                            }
                            if(got) break;
                        }
                        for(int x = i; x < i+2; x++){
                            for(int y = j; y < j+2; y++){
                                if(a[x][y] == -2){
                                    a[x][y] = 0;
                                }
                                if(a[x][y] == -1){
                                    a[x][y] = 1;
                                }
                            }
                        }
                        ans.add(inThis);
                        


                        

                        inThis = new ArrayList<>();
                        for(int x = i; x < i+2; x++){
                            for(int y = j; y < j+2; y++){
                                if(a[x][y] == 0){
                                    inThis.add(x);
                                    inThis.add(y);
                                    a[x][y] = -1;
                                }
                            }
                        }
                        got = false;
                        for(int x = i; x < i+2; x++){
                            for(int y = j; y < j+2; y++){
                                if(a[x][y] == 1){
                                    inThis.add(x);
                                    inThis.add(y);
                                    a[x][y] = -2;
                                    got = true;
                                    break;
                                }
                            }
                            if(got) break;
                        }
                        for(int x = i; x < i+2; x++){
                            for(int y = j; y < j+2; y++){
                                if(a[x][y] == -1){
                                    a[x][y] = 1;
                                }
                                if(a[x][y] == -2){
                                    a[x][y] = 0;
                                }
                            }
                        }
                        ans.add(inThis);
                        

                        
                        

                        inThis = new ArrayList<>();
                        if(a[x1][y1]==1){
                            inThis.add(x1);
                            inThis.add(y1);
                        }
                        if(a[x2][y2]==1){
                            inThis.add(x2);
                            inThis.add(y2);
                        }
                        if(a[x3][y3]==1){
                            inThis.add(x3);
                            inThis.add(y3);
                        }
                        if(a[x4][y4]==1){
                            inThis.add(x4);
                            inThis.add(y4);
                        }
                        a[x1][y1] = 0;
                        a[x2][y2] = 0;
                        a[x3][y3] = 0;
                        a[x4][y4] = 0;
                        ans.add(inThis);
                        

                        continue;
                    }

                    if(countOne==3){    

                        if(a[x1][y1]==1){
                            inThis.add(x1);
                            inThis.add(y1);
                        }
                        if(a[x2][y2]==1){
                            inThis.add(x2);
                            inThis.add(y2);
                        }
                        if(a[x3][y3]==1){
                            inThis.add(x3);
                            inThis.add(y3);
                        }
                        if(a[x4][y4]==1){
                            inThis.add(x4);
                            inThis.add(y4);
                        }
                        a[x1][y1] = 0;
                        a[x2][y2] = 0;
                        a[x3][y3] = 0;
                        a[x4][y4] = 0;
                        ans.add(inThis);
                        continue;
                    }

                    if(countOne==2){        

                        inThis = new ArrayList<>();
                        for(int x = i; x < i+2; x++){
                            for(int y = j; y < j+2; y++){
                                if(a[x][y] == 0){
                                    inThis.add(x);
                                    inThis.add(y);
                                    a[x][y] = -1;
                                }
                            }
                        }
                        boolean got = false;
                        for(int x = i; x < i+2; x++){
                            for(int y = j; y < j+2; y++){
                                if(a[x][y] == 1){
                                    inThis.add(x);
                                    inThis.add(y);
                                    a[x][y] = -2;
                                    got = true;
                                    break;
                                }
                            }
                            if(got) break;
                        }
                        for(int x = i; x < i+2; x++){
                            for(int y = j; y < j+2; y++){
                                if(a[x][y] == -1){
                                    a[x][y] = 1;
                                }
                                if(a[x][y] == -2){
                                    a[x][y] = 0;
                                }
                            }
                        }
                        ans.add(inThis);

                        

                        inThis = new ArrayList<>();
                        if(a[x1][y1]==1){
                            inThis.add(x1);
                            inThis.add(y1);
                        }
                        if(a[x2][y2]==1){
                            inThis.add(x2);
                            inThis.add(y2);
                        }
                        if(a[x3][y3]==1){
                            inThis.add(x3);
                            inThis.add(y3);
                        }
                        if(a[x4][y4]==1){
                            inThis.add(x4);
                            inThis.add(y4);
                        }
                        a[x1][y1] = 0;
                        a[x2][y2] = 0;
                        a[x3][y3] = 0;
                        a[x4][y4] = 0;
                        ans.add(inThis);
                        

                        continue;
                    }

                    if(countOne==1){
                        inThis = new ArrayList<>();
                        int counter = 0;
                        for(int x = i; x < i+2; x++){
                            for(int y = j; y < j+2; y++){
                                if(a[x][y] == 0){
                                    a[x][y] = -1;
                                    inThis.add(x);
                                    inThis.add(y);
                                    counter++;
                                }
                                if(counter == 2)    break;
                            }
                            if(counter == 2)    break;
                        }
                        boolean got = false;
                        for(int x = i; x < i+2; x++){
                            for(int y = j; y < j+2; y++){
                                if(a[x][y] == 1){
                                    a[x][y] = -2;
                                    inThis.add(x);
                                    inThis.add(y);
                                    got = true;
                                    break;
                                }
                            }
                            if(got) break;
                        }
                        for(int x = i; x < i+2; x++){
                            for(int y = j; y < j+2; y++){
                                if(a[x][y] == -2){
                                    a[x][y] = 0;
                                }
                                if(a[x][y] == -1){
                                    a[x][y] = 1;
                                }
                            }
                        }
                        ans.add(inThis);

                        

                        inThis = new ArrayList<>();
                        for(int x = i; x < i+2; x++){
                            for(int y = j; y < j+2; y++){
                                if(a[x][y] == 0){
                                    inThis.add(x);
                                    inThis.add(y);
                                    a[x][y] = -1;
                                }
                            }
                        }
                        got = false;
                        for(int x = i; x < i+2; x++){
                            for(int y = j; y < j+2; y++){
                                if(a[x][y] == 1){
                                    inThis.add(x);
                                    inThis.add(y);
                                    a[x][y] = -2;
                                    got = true;
                                    break;
                                }
                            }
                            if(got) break;
                        }
                        for(int x = i; x < i+2; x++){
                            for(int y = j; y < j+2; y++){
                                if(a[x][y] == -1){
                                    a[x][y] = 1;
                                }
                                if(a[x][y] == -2){
                                    a[x][y] = 0;
                                }
                            }
                        }
                        ans.add(inThis);
                        

                        
                        

                        inThis = new ArrayList<>();
                        if(a[x1][y1]==1){
                            inThis.add(x1);
                            inThis.add(y1);
                        }
                        if(a[x2][y2]==1){
                            inThis.add(x2);
                            inThis.add(y2);
                        }
                        if(a[x3][y3]==1){
                            inThis.add(x3);
                            inThis.add(y3);
                        }
                        if(a[x4][y4]==1){
                            inThis.add(x4);
                            inThis.add(y4);
                        }
                        a[x1][y1] = 0;
                        a[x2][y2] = 0;
                        a[x3][y3] = 0;
                        a[x4][y4] = 0;
                        ans.add(inThis);
                        

                        continue;
                    }
                    

                }
            }

            

            

            

            

            

            

            p.println(ans.size());
            for(int i = 0; i < ans.size(); i++){
                for(int j = 0; j < ans.get(i).size(); j++){
                    int now_one = ans.get(i).get(j);
                    p.print((now_one+1) + " ");
                }
                p.println();
            }
        }
        p.close();
    }

    static int[] sort(int a[]){
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i : a){
            arr.add(i);
        }
        Collections.sort(arr);
        for(int i = 0; i < arr.size(); i++){
            a[i] = arr.get(i);
        }
        return a;
    }
    

    static class Foster {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        StringTokenizer st = new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } 
                catch (IOException e) {
                    e.printStackTrace();
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
        int[] intArray(int n) {                   

            int arr[] = new int[n];
            for(int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }
        long[] longArray(int n) {                 

            long arr[] = new long[n];
            for(int i = 0; i < n; i++) {
                arr[i] = nextLong();
            }
            return arr;
        }
        int[] getBits(int n) {                   

            int a[] = new int[31];
            for(int i = 0; i < 31; i++) {
                if(((1<<i) & n) != 0)
                    a[i] = 1;
            }
            return a;
        }
        static String reverse(String s){
            String temp = "";
            for(int i = s.length()-1; i >= 0; i--){
                temp += s.charAt(i);
            }
            return temp;
        }
        static long pow(long... a) {
            long mod = Long.MAX_VALUE;
            if(a.length == 3)   mod = a[2];
            long res = 1;
            while(a[1] > 0) {
                if((a[1] & 1) == 1)
                    res = (res * a[0]) % mod;
                a[1] /= 2;
                a[0] = (a[0] * a[0]) % mod;
            }
            return res;
        }
        static void print(Object... o) {
            for(Object next : o) {
                System.err.print(next + " ");
            }
        }
        static void println(Object... o) {
            for(Object next : o) {
                System.err.print(next + " ");
            }
            System.err.println();
        }
        static void watch(Object...a) throws Exception {
            int i = 1;
            for (Object o: a) {
                boolean found = false;
                if (o.getClass().isArray()) {
                    String type = o.getClass().getName().toString();
                    switch (type) {
                        case "[I": {
                            int[] test = (int[]) o;
                            println(i + " : " + Arrays.toString(test));
                            break;
                        }
                        case "[[I": {
                            int[][] obj = (int[][]) o;
                            println(i + " : " + Arrays.deepToString(obj));
                            break;
                        }
                        case "[J": {
                            long[] obj = (long[]) o;
                            println(i + " : " + Arrays.toString(obj));
                            break;
                        }
                        case "[[J": {
                            long[][] obj = (long[][]) o;
                            println(i + " : " + Arrays.deepToString(obj));
                            break;
                        }
                        case "[D": {
                            double[] obj = (double[]) o;
                            println(i + " : " + Arrays.toString(obj));
                            break;
                        }
                        case "[[D": {
                            double[][] obj = (double[][]) o;
                            println(i + " : " + Arrays.deepToString(obj));
                            break;
                        }
                        case "[Ljava.lang.String": {
                            String[] obj = (String[]) o;
                            println(i + " : " + Arrays.toString(obj));
                            break;
                        }
                        case "[[Ljava.lang.String": {
                            String[][] obj = (String[][]) o;
                            println(i + " : " + Arrays.deepToString(obj));
                            break;
                        }
                        case "[C": {
                            char[] obj = (char[]) o;
                            println(i + " : " + Arrays.toString(obj));
                            break;
                        }
                        case "[[C": {
                            char[][] obj = (char[][]) o;
                            println(i + " : " + Arrays.deepToString(obj));
                            break;
                        }
                        default: {
                            println(i + " : type not identified");
                            break;
                        }
                    }
                    found = true;
                }
                if (o.getClass() == ArrayList.class) {
                    println(i + " : LIST = " + o);
                    found = true;
                }
                if (o.getClass() == TreeSet.class) {
                    println(i + " : SET = " + o);
                    found = true;
                }
                if (o.getClass() == TreeMap.class) {
                    println(i + " : MAP = " + o);
                    found = true;
                }
                if (o.getClass() == HashMap.class) {
                    println(i + " : MAP = " + o);
                    found = true;
                }
                if (o.getClass() == LinkedList.class) {
                    println(i + " : LIST = " + o);
                    found = true;
                }
                if (o.getClass() == PriorityQueue.class) {
                    println(i + " : PQ = " + o);
                    found = true;
                }
                if (!found) {
                    println(i + " = " + o);
                }
                i++;
            }
        }
    }
}