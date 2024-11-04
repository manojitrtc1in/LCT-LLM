    

    import java.util.*;

    public class Ex3 {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            int q = in.nextInt();
            for (int t = 0; t < q; t++) {
                String str = in.next();
                String str1 = in.next();
                int cout = 0;
                for(int i = 0; i < str.length(); i++){
                    if(str.charAt(i) == str1.charAt(0) && i %2 ==0){
                        cout++;
                    }
                }
                if(cout==0){
                    System.out.println("NO");
                }else {
                    System.out.println("YES");
                }
            }
        }
    }


