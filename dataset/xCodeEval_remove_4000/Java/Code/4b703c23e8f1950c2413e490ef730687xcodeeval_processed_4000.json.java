    

    import java.util.*;

    public class Ex3 {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            int q = in.nextInt();
            for (int t = 0; t < q; t++) {
                int a = in.nextInt(),a1 = in.nextInt();
                int b = in.nextInt(),b1 = in.nextInt();
                int c = in.nextInt(),c1 = in.nextInt();
                int dx = Math.abs(b-a);
                int dy = Math.abs(b1-a1);
                if((dx == 0 && c == a) && (a1<c1&& c1<b1 || b1<c1&& c1<a1)){
                    System.out.println(dx+dy+2);
                }else if((dy == 0 && c1==a1)&& (a<c&& c<b || b<c&& c<a)){
                    System.out.println(dx+dy+2);
                }else {
                    System.out.println(dx+dy);
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


