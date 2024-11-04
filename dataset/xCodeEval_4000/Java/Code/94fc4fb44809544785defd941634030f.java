


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Question {
    static long[] arr1;
    static long[] arr2;
    static int[] arr;
    static int[][] dp;
    static int n;
    static long MOD = 998244353 ;
    static long ans = 0;
    static String str1 ;
    static String str2 ;
    static int[] primes = new int[]{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    static ArrayList<Integer> list;
    static int aa;





    public static void main (String[] args) throws IOException {
        Reader.init(System.in);
        int n = Reader.nextInt();
        int[] arr = new int[n];
        int max = -1;
        int index = -1;
        for (int i = 0 ; i < n ; i++){
            arr[i] = Reader.nextInt();
            if (arr[i]>max){
                max = Math.max(max,arr[i]);
                index = i;
            }
        }
        

        for (int i = 0 ; i <= index-1 ; i++){
            

            if (arr[i]>=arr[i+1]){
                System.out.println("NO");
                System.exit(0);
            }
        }
        for (int i = index ; i < n-1; i++){
            if (arr[i]<=arr[i+1]){
                System.out.println("NO");
                System.exit(0);
            }
        }
        System.out.println("YES");





    }

    static long count(String a, String b)
    {
        int m = a.length();
        int n = b.length();

        

        

        long lookup[][] = new long[m + 1][n + 1];

        

        for (int i = 0; i <= n; ++i)
            lookup[0][i] = 0;

        

        for (int i = 0; i <= m; ++i)
            lookup[i][0] = 1;

        

        

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                

                

                

                

                

                

                if (a.charAt(i - 1) == b.charAt(j - 1))
                    lookup[i][j] = lookup[i - 1][j - 1] +
                            lookup[i - 1][j];

                else
                    

                    

                    

                    lookup[i][j] = lookup[i - 1][j];
            }
        }

        return lookup[m][n];
    }
    public static void sortbyColumn(int arr[][], int col)
    {
        

        Arrays.sort(arr, new Comparator<int[]>() {

            @Override
            

            public int compare(final int[] entry1,
                               final int[] entry2) {

                

                

                if (entry1[col] > entry2[col])
                    return 1;
                else
                    return -1;
            }
        });  

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

    




    


    

    



    static boolean isSubSequence(String str1, String str2, int m, int n)
    {
        

        if (m == 0)
            return true;
        if (n == 0)
            return false;

        

        if (str1.charAt(m-1) == str2.charAt(n-1))
            return isSubSequence(str1, str2, m-1, n-1);

        

        return isSubSequence(str1, str2, m, n-1);
    }

}

class Tnode{
    int lSub;
    int rSub;
    int left;
    int right;


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










        