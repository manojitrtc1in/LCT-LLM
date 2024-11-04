            

            import java.util.*;

            public class Ex3 {
                public static void main(String[] args) {
                    Scanner in = new Scanner(System.in);
                    int q = in.nextInt();
                    for (int t = 0; t < q; t++) {
                        int x = in.nextInt();
                        int n = x / 2;
                        int ans1[] = new int[x/2];
                        int h = 0;
                        if (x % 2 == 0) {
                            int ans[] = new int[x/2];
                            for (int i = n; i > 0; i--) {
                                ans[h] = i;
                                h++;
                            }
                            h = 0;
                            for (int i = x; i > n; i--) {
                                ans1[h] = i;
                                h++;
                            }
                            h = 0;
                            for(int i = 0; i < x/2; i++){
                                System.out.print(ans[i]+" ");
                                System.out.print(ans1[i]+" ");
                            }
                        } else {
                              h = 0;
                            int ans[] = new int[(x/2)+1];
                                for (int i = n+1; i > 0; i--) {
                                    ans[h] = i;
                                    h++;
                                }
                                h = 0;
                                for (int i = x; i > n+1; i--) {
                                    ans1[h] = i;
                                    h++;
                                }
                                int out[] = new int[x];
                                int a =0;
                                int h1 = 0;
                                int h2 = 0;
                                while (a < x){
                                    if(h1 < (x/2)+1){
                                        out[a] = ans[h1];
                                        h1++;
                                    }
                                    a++;
                                    if(h2 < x/2){
                                        out[a] = ans1[h2];
                                        h2++;
                                        a++;
                                    }
                                }
                            for (int i = 0; i < x; i++) {
                                System.out.print(out[i]+" ");
                            }
                            System.out.println();
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


