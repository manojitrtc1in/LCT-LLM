    

    import java.util.*;

    public class Ex3 {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            int t = in.nextInt();
            for(int oo = 0; oo < t; oo++){
                int n = in.nextInt();
                int arr[] = new int[n];
                boolean k = true;
                StringBuilder scc = new StringBuilder();
                for(int i = 0; i < n; i++){
                    arr[i] = in.nextInt();
                }
                for(int i = 1; i < arr.length; i++){
                    if(arr[i] <= arr[i-1] && arr[i] != 0){
                        k = false;
                        break;
                    }else {
                        arr[i] = arr[i]+arr[i-1];
                    }
                }
                if( k == false){
                    System.out.println(-1);
                }else {
                    for (int i = 0; i < arr.length; i++) {
                        scc.append(arr[i]+ " ");
                    }
                    System.out.println(scc.toString());
                }
            }

        }

        public class ListNode<E> {
            private E value;
            private ListNode next;

            public ListNode(E newVal, ListNode<E> newNext) {
                value = newVal;
                next = newNext;
            }

            public E getValue() {
                return value;
            }
            public ListNode<E> getNext() {
                return next;
            }

            public void setValue(E newValue) {
                value = newValue;
            }

            public void setNext(ListNode<E> newNext) {
                next = newNext;
            }
        }
    }