    

    import java.util.*;

    public class Ex3 {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            int q = in.nextInt();
            for (int t = 0; t < q; t++) {
                int x = in.nextInt();
                int d = in.nextInt();
                int arr[] = new int[x];
                for(int i = 0; i < arr.length; i++){
                    arr[i] = in.nextInt();
                }
                int max = 0;
                Arrays.sort(arr);
                max = arr[x-1];
                if(arr[0]+arr[1] <= d||max<=d){
                    System.out.println("YES");
                }else {
                    System.out.println("NO");
                }
            }
        }
    }


