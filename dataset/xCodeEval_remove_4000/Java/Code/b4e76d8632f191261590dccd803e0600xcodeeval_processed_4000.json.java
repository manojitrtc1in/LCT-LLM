





import java.io.*;

import java.math.BigInteger;
import java.util.*;




public class LoveJava {
  

    


    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        

     try {

         int t = Integer.parseInt(br.readLine());
         while (t-->0) {
              String a=br.readLine();
             

             int countA=0,countB=0,countC=0;
            for(int i=0;i<a.length();i++){
             if(a.charAt(i)=='A')
                 countA++;
             else if(a.charAt(i)=='B')
                 countB++;
             else if(a.charAt(i)=='C')
                 countC++;
            }
            if((countA+countB+countC)<a.length())
                pw.println("NO");

              else {
                if ((countA + countC )== countB)
                    pw.println("YES");
                else
                    pw.println("NO");
            }
         }
        pw.close();



       }
        catch (IOException ex) {
            System.out.println("input mismatch");
        }




    }
}
