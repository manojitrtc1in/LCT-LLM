


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Question {
    static long[] arr1;
    static long[] arr2;
    static int[] arr;
    static int[][] dp;
    static int n;
    static long MOD = (long) 1e9 + 7;
    static long ans = 0;
    static String str1 ;
    static String str2 ;
    static int[] primes = new int[]{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    static ArrayList<Integer> list;
    static int aa;




    public static void main (String[] args) throws IOException {
        Reader.init(System.in);
        System.out.println("YES");
        long l = Reader.nextLong();
        long r = Reader.nextLong();
        while (l <= r){
            System.out.println(l + " " + (l +1));
            l+=2;
        }


    }

    static int fun(int i , int mask){
        if (i < n){
            

        }
        if (i==n){
            return 0;
        }
        else if (dp[i][mask]!=-1){
            return dp[i][mask];
        }
        else{
            int flag = 0;
            for (int j = 0 ; j < 16 ; j++) {
                if (((mask>>j) &1 ) == 1  && ((list.get(i)>>j) &1 ) == 1) {
                    flag =1;
                }
            }
            if (flag==0){
                dp[i][mask] =Math.max(1 + fun(i + 1, (mask | (list.get(i)))), fun(i + 1, mask));
            }
            else{
                dp[i][mask] =  fun(i + 1, mask);
            }
            return dp[i][mask];
        }
    }

    




    


    

    



    static boolean id0(String str1, String str2, int m, int n)
    {
        

        if (m == 0)
            return true;
        if (n == 0)
            return false;

        

        if (str1.charAt(m-1) == str2.charAt(n-1))
            return id0(str1, str2, m-1, n-1);

        

        return id0(str1, str2, m, n-1);
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
    static long nextLong() throws IOException {
        return Long.parseLong( next() );
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }
}










        