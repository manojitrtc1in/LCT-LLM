        

        import java.util.*;

        public class Ex3 {
            public static void main(String[] args) {
                Scanner in = new Scanner(System.in);
                int q = in.nextInt();
                for (int t = 0; t < q; t++) {
                    int x = in.nextInt();
                    String str = in.next();
                    int cout = 0;
                    int cout1 = 0;
                    for(int i = 0; i < str.length(); i++){
                        if(str.charAt(i)=='Q'){
                            cout++;
                        }
                        if(str.charAt(i)=='A'){
                            if(cout != 0){
                                cout--;
                            }
                        }
                    }
                    if(cout == 0){
                        System.out.println("YES");
                    }else {
                        System.out.println("NO");
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


