import java.io.BufferedReader;
import java.io.InputStream;
import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Map.Entry;
import java.util.StringTokenizer;
import java.util.concurrent.atomic.AtomicLongFieldUpdater;

public class Main {
    static Integer[][] ref;
    static boolean[] visited;
    static ArrayList<Integer>[] arrayList;
    static void SieveOfEratosthenes(int MAX_SIZE, ArrayList<Integer> list) {
        

        

        

        

        boolean[] IsPrime = new boolean[MAX_SIZE];

        for (int i = 2; i < MAX_SIZE; i++)
            IsPrime[i] = true;
        for (long p = 2; p * p < MAX_SIZE; p++) {
            if (IsPrime[(int) p]) {
                for (long i = p * p; i < MAX_SIZE; i += p)
                    IsPrime[(int) i] = false;
            }
        }
        for (int i = 0; i < MAX_SIZE; i++){
            if (    IsPrime[i]){list.add(i);}
        }
    }
        public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        long a = Reader.nextInt();
       

        ArrayList<Integer> listOfPrimes = new ArrayList<>();

            SieveOfEratosthenes(100000, listOfPrimes);
            int baby = listOfPrimes.size();
            for (int o = 1; o <= a; o++) {
            int b = Reader.nextInt();
            long s1 = 1;

            long s2 = findPosition(listOfPrimes, 1 + b, 0 , baby - 1); long s3 = findPosition(listOfPrimes, s2 + b,0, baby - 1);
          

            long k1 = s2*s3;
            System.out.println(k1);

        }

    }
    public static long findPosition(ArrayList<Integer> list, long r,int s, int e){
        if (s > e) return -1;
        int mid = (s + e)/2;
        if (list.get(mid) < r) return findPosition(list, r,mid + 1, e);
        if (list.get(mid) > r){
            long j = findPosition(list, r, s, mid - 1);
            if (j != -1) return j;
            return list.get(mid);
        }
        if (list.get(mid) == r) return list.get(mid);
        return -1;
    }
    public static long gcd(long a, long b){
        if (a == 0)
            return b;
        if (b == 0)
            return a;

        

        if (a == b)
            return a;

        

        if (a > b)
            return gcd(a-b, b);
        return gcd(a, b-a);
    }
    void merge(int[] arr, int l, int m, int r) {
        

        int n1 = m - l + 1;
        int n2 = r - m;

        
        int[] L = new int[n1];
        int[] R = new int[n2];

        
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];

        

        

        int i = 0, j = 0;

        

        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    

    

    void sort(int[] arr, int l, int r) {
        if (l < r) {
            

            int m = (l + r) / 2;

            

            sort(arr, l, m);
            sort(arr, m + 1, r);

            

            merge(arr, l, m, r);
        }
    }
}




class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    
    static void init(InputStream input) {
        reader = new BufferedReader(
                new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
    }

    
    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            

            tokenizer = new StringTokenizer(
                    reader.readLine() );
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }
}