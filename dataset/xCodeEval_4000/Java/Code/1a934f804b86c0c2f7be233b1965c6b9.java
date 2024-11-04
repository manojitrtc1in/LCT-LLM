    

    import java.util.*;

    public class Ex3 {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            int q = in.nextInt();
            for (int t = 0; t < q; t++) {
                int n = in.nextInt();
                int m = in.nextInt();
                for(int i = 0; i < m;i++){
                    in.next();
                    in.next();
                }
                if(n > m){
                    System.out.println("YES");
                }else {
                    System.out.println("NO");
                }
            }
        }
    }


