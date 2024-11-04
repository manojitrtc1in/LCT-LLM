



import java.io.*;

import java.math.BigInteger;
import java.util.*;




public class LoveJava {
    

    


    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        String arr[];
        String arr1[];


        try {

             int t = Integer.parseInt(br.readLine());
             while (t-->0) {
                

                  String s=br.readLine();

                  


                 pw.println(func(s));
             }
            pw.close();


        } catch (IOException ex) {
            System.out.println("input mismatch");
        }

    }
    public  static int func(String s) {
       int[]a=new int[2];
       Arrays.fill(a,0);

       int max=1000000;
       int min0=max,max0=-1,min1=max,max1=-1;
       for(int i=0;i<s.length();i++) {
           if (s.charAt(i) == '1') {
               a[1] = 1;
               min1 = Math.min(min1, i);
               max1 = Math.max(max1, i);
           } else {
               a[0] = 1;
               min0 = Math.min(min0, i);
               max0 = Math.max(max0, i);
           }
       }
           if(a[0]==0)
               return 0;
           else if(a[1]==0)
               return 1;
           else {
               for(int i=min0;i<=max0;i++){
                   if(s.charAt(i)=='1')
                       return 2;
               }

           }

       return 1;
    }
    

    public static int gcd(int a,int b){
        if(b==0)
            return a;
        else return gcd(b,a%b);
    }
    

    public static void fun(int[]a,int k){
        int max=-1,countpeaks=0;

        int[]peaks=new int[a.length];

        for(int i=0;i<peaks.length;i++){
            if(i==0||i==peaks.length-1)
                peaks[i]=0;
            else {
                if(a[i]>a[i-1]&&a[i]>a[i+1])
                    peaks[i]=1;
                else peaks[i]=0;
            }
        }
        int r=a.length-1,l=r-k+1,i=0;
        if(l<0){
            System.out.println(-1);
            return;}
        for(int j=r;l>=0;){
            if(i==r)
            for (i=r;i>=l;i--){
                if((i==r||i==l)&&peaks[i]==1)
                    ;
                else
                    countpeaks+=peaks[i];
            }
            max=max>countpeaks?max:countpeaks;
            r--;l--;

        }
    }
    
}
