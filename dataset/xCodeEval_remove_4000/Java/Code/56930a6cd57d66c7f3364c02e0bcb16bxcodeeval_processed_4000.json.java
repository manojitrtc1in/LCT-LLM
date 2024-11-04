

import com.sun.nio.sctp.SctpStandardSocketOptions;

import javax.swing.*;
import java.util.Calendar;
import java.net.StandardSocketOptions;
import java.util.*;
import java.util.Calendar;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Random;
import java.util.StringTokenizer;
import java.io.*;
import java.util.ArrayList;


public class Main {
      public static void main(String[]arg) {
          Scanner sc = new Scanner(System.in);
          int t = sc.nextInt();
          for (int p = 0; p < t; p++) {
              int n = sc.nextInt();
              int a = sc.nextInt();
              int b = sc.nextInt();
              String s = "abcdefghijklmnopqrstuvwxyz";
              String res = "";
              

              if (b < a) {
                  for (int i = 0; i < n; i += b) {
                      if (n - res.length() >= b) res += s.substring(0, b);
                      else res += s.substring(0, n - res.length());
                  }
                  System.out.println(res);
              } else {
                  if (n <= 26) {
                      res += s.substring(0, n);
                      System.out.println(res);
                  } else {
                      int v=n;
                      for( ;v>=26;v-=26){
                          res += s.substring(0, 26);
                      }
                          res+=s.substring(0,v);
                          System.out.println(res);
                  }

              }
          
          }
      }
    static int id0(int arr[], int n)
    {
    
        HashSet<Integer> S = new HashSet<Integer>();
        for (int i = 0; i < n; i++)
            S.add(arr[i]);

        

        

        int ans = 0;
        for (int i = 0; i < n; i++)
        {

            

            

            if(S.contains(arr[i]))
            {

                

                

                int j = arr[i];

                

                

                while (S.contains(j))
                    j++;

                

                

                

                ans = Math.max(ans, j - arr[i]);
            }
        }
        return ans;
    }

    static int id10(int n)
    {
        int count = 0;

        

        

        

        if (n > 0 && (n & (n - 1)) == 0)
            return n;

        while(n != 0)
        {
            n >>= 1;
            count += 1;
        }

        return 1 << count;
    }


    public static int id4(int n,int a[]){
          int max=Integer.MIN_VALUE;int maxIndex=0;
          for(int i=0;i<a.length;i++){
              if(a[i]>max){
                  max=a[i];maxIndex=i;
              }
          }
          

          int c1=0;
          for(int i=maxIndex;i>0;i--){
              int temp=a[maxIndex];
              a[maxIndex]=a[i-1];
              a[i-1]=temp;
              c1++;maxIndex--;
          }
          

          int min=Integer.MAX_VALUE;int minIndex=0;
          for(int i=0;i<a.length;i++){
              if(a[i]<=min){
                  min=a[i];minIndex=i;
              }
          }
          int c2=0;
          for(int i=minIndex;i<a.length-1;i++){
              int temp=a[minIndex];
              a[minIndex]=a[i+1];
              a[i+1]=temp;
              c2++;minIndex++;
          }
          return c1+c2;
      }
      public static String id7(int n,int x,int ax[],int y,int ay[]){

          ArrayList<Integer>ar=new ArrayList<>();
          for(int i=1;i<=n;i++)ar.add(i);
          for(int i=0;i<ax.length;i++){
              if(ar.contains(ax[i]))ar.remove(ar.indexOf(ax[i]));
          }
          for(int i=0;i<ay.length;i++){
              if(ar.contains(ay[i]))ar.remove(ar.indexOf(ay[i]));
          }
          if(ar.size()==0)return "I become the guy.";
          else  return "Oh, my keyboard!";

      }

      public static String id8(String s1,String s2){

          String res="";
          for(int i=0;i<s1.length();i++){
              if((s1.charAt(i)=='1'&&s2.charAt(i)=='1')||(
                  s1.charAt(i)=='0'&&s2.charAt(i)=='0'))
                   res+='0';
              else res+='1';
          }
          return res;
      }

      public static int id3(int k,int l,int m,int n,int d){
           int id9=0;
          for(int i=1;i<=d;i++){
              if(i%k==0||i%l==0||i%n==0||i%m==0)id9++;
          }
          return id9;
      }

    

    

    static int maximumSegments(int n, int a,
                               int b, int c)
    {
        

        

        int dp[] = new int[n + 10];

        

        Arrays.fill(dp, -1);

        

        

        dp[0] = 0;

        

        

        for (int i = 0; i < n; i++)
        {
            if (dp[i] != -1)
            {

                

                if(i + a <= n )    

                    dp[i + a] = Math.max(dp[i] + 1,
                            dp[i + a]);

                if(i + b <= n )    

                    dp[i + b] = Math.max(dp[i] + 1,
                            dp[i + b]);

                if(i + c <= n )    

                    dp[i + c] = Math.max(dp[i] + 1,
                            dp[i + c]);
            }
        }
        return dp[n];
    }





    

    static int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    

    static int lcm(int a, int b)
    {
        return (a*b)/gcd(a, b);
    }

    

    public static int id1(int a, int b)
    {
        int lar = Math.max(a, b);
        int small = Math.min(a, b);
        for (int i = lar; ; i += lar) {
            if (i % small == 0)
                return i;
        }
    }

    

    static int id5(int arr[], int n)
    {
        int result = arr[0];
        for (int i = 1; i < n; i++)
            result = gcd(arr[i], result);

        return result;
    }


    

    static void id6(int n)
    {
        TreeSet<Integer>t=new TreeSet<>();
        

        for (int i=1; i<=Math.sqrt(n); i++)
        {
            if (n%i==0)
            {
                

                if (n/i == i)
                    t.add(i);

                else 

                    t.add(i);t.add(n/i);
            }
        }
        

        Iterator<Integer> ir = t.iterator();
        while(ir.hasNext())System.out.println(ir.next());
    }

    

    

    public static void primeFactors(int n)
    {
        

        while (n%2==0)
        {
            System.out.print(2 + " ");
            n /= 2;
        }

        

        

        

        

        for (int i = 3; i <= Math.sqrt(n); i+= 2)
        {
            

            while (n%i == 0)
            {
                System.out.print(i + " ");
                n /= i;
            }
        }

        

        

        if (n > 2)
            System.out.print(n);
    }



    static int findIndex(int[] a, int item)
    {
        for(int i = 0; i < a.length; ++i)
            if(item == a[i])
                return i;
        return -1;
    }
    static boolean isPal(char[] s) {
        for (int i = 0; i < s.length / 2; i++)
            if (s[i] != s[s.length - i - 1])
                return false;
        return true;
    }
    static String get(int sec) {
        Calendar calendar = Calendar.getInstance();
        calendar.set(Calendar.HOUR_OF_DAY, 0);
        calendar.set(Calendar.MINUTE, 0);
        calendar.set(Calendar.MILLISECOND, 0);
        calendar.set(Calendar.SECOND, sec);
        return new SimpleDateFormat("HH:mm:ss").format(calendar.getTime());

    }
    static class Pair  {
        int idx;
        int first, second;

        Pair(int a, int b, int c) {
            first = a;
            second = b;
            idx = c;
        }

    }

    

    





    

    


    int equilibrium(int arr[], int n)
    {
        int sum = 0; 

        int leftsum = 0; 


        
        for (int i = 0; i < n; ++i)
            sum += arr[i];

        for (int i = 0; i < n; ++i) {
            sum -= arr[i]; 


            if (leftsum == sum)
                return i;

            leftsum += arr[i];
        }

        
        return -1;
    }


    static int id2(char X[], char Y[], int m, int n)
    {
        

        

        

        

        

        int LCStuff[][] = new int[m + 1][n + 1];
        int result = 0;  


        

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    LCStuff[i][j] = 0;
                else if (X[i - 1] == Y[j - 1])
                {
                    LCStuff[i][j] = LCStuff[i - 1][j - 1] + 1;
                    result = Integer.max(result, LCStuff[i][j]);
                }
                else
                    LCStuff[i][j] = 0;
            }
        }
        return result;
    }



}