    

    import java.util.*;

    public class Ex3 {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            int q = in.nextInt();
            for (int t = 0; t < q; t++) {
                int x = in.nextInt();
                String str = in.next();
                int arr[] = new int[x];
                int cout =0;
                int ans = 0;
                for(int i = 0; i < arr.length; i++){
                    arr[i] = in.nextInt();
                    if(str.charAt(i) == '1'){
                        cout++;
                    }
                    ans+=arr[i];
                }
                if(cout == 0){
                    System.out.println(0);
                }else if(cout == x){
                    System.out.println(ans);
                }else {
                    ans = 0;
                    int max = 0;
                    for(int i = 0; i < arr.length; i++){
                        if(str.charAt(i) == '1'){
                            ans+=Math.max(arr[i],max);
                        }
                        if(str.charAt(i)=='0'||arr[i]<=max){
                            max = arr[i];
                        }
                    }
                    System.out.println(ans);
                }
            }
        }
    }


