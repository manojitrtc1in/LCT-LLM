    

    import java.util.*;

    public class Ex3 {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            int q = in.nextInt();
            for (int t = 0; t < q; t++) {
                int x = in.nextInt();
                if(x == 2){
                    System.out.println(7);
                }else {
                    if(x%2 == 1){
                        System.out.println((x%2)+2);
                    }else {
                        System.out.println((x%2)+1);
                    }
                }
                }
            }

        static long gcd(long a, long b) {
            return b == 0 ? a : gcd(b, a % b);
        }

        static long lcm(long a, long b) {
            return a * b / gcd(a, b);
        }
    }

