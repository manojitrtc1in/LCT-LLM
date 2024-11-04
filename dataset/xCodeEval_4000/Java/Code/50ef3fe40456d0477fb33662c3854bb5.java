    

    import java.util.*;

    public class Ex3 {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            int q = in.nextInt();
            for (int t = 0; t < q; t++) {
                int arr[] = new int[3];
                for (int i = 0; i < arr.length; i++) {
                    arr[i] = in.nextInt();
                }
                int max = Math.max(0,Math.max(arr[1],arr[2])+1-arr[0]);
                int max1 =  Math.max(0,Math.max(arr[0],arr[2])+1-arr[1]);;
                int max2 =  Math.max(0,Math.max(arr[0],arr[1])+1-arr[2]);
                System.out.println(max+" "+max1+" "+max2);
            }
        }
    }


