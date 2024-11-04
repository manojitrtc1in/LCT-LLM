import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Polo {

    public static void main (String[]args) throws IOException {
        BufferedReader rdr = new BufferedReader(new InputStreamReader(System.in));
        String [] input = rdr.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        String all = "cdefghijklmnopqrstuvwxyz";
        

        if(k > n || ((n>1)&& (k == 1))) {
            System.out.println(-1);
        }
        else {










































































































            int distinct = k - 2;
            char [] strin = new char [n];
            if(n == 1 && k == 1)
                System.out.println("a");
            else { 
                for(int i = 0; i < n-distinct; i ++) {
                if(i%2 == 0)
                    System.out.print("a");
                else
                    System.out.print("b");
            }
            int cnt = 0;
            for(int i = n-distinct; i < n;i++) {
                System.out.print(all.charAt(cnt));
                cnt++;
            }
            }
            

            

            

            

        }
    }
}
