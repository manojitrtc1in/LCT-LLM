
 
import java.util.*;
 
public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            int x = in.nextInt();
            int n = 0;
            int n1 = 0;
            if(x%2 == 0){
                n = x/2;
                n1 = x/2;
            }else {
                n = x/2+1;
                n1 = (x/2);
            }
            int chet[] = new int[n];
            int id0[] = new int[n1];
            for(int i = 1; i <= n; i++){
               chet[i-1] = i;
            }
            for(int i = n+1; i <= x; i++){
                id0[i-n-1] = i;
            }
            int ans[] = new int[x];
            int n2 = 0;
            int n3 = 0;
            for(int i = 0; i < x;i++){
                if(x%2 == 0){
                    if (i % 2 == 0 && n3 != n1) {
                        ans[i] = id0[n3];
                        n3++;
                    } else {
                        if (n2 != n)
                            ans[i] = chet[n2];
                        n2++;
                    }
                }else {
                    if (i % 2 == 0 && n2 != n) {
                        ans[i] = chet[n2];
                        n2++;
                    } else {
                        if (n3 != n1)
                            ans[i] = id0[n3];
                        n3++;
                    }
                }
            }
            for(int i = 0; i < x; i++){
                System.out.print(ans[i]+" ");
            }
            System.out.println();
        }
    }
}