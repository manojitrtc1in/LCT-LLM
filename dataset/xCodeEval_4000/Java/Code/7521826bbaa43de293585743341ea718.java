    

    import java.util.*;

    public class Ex3 {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            int q = in.nextInt();
            for (int t = 0; t < q; t++) {
                int x = in.nextInt();
                int arr[] = new int[x];
                HashSet<Integer> set = new HashSet<Integer>();
                for(int i = 0; i < arr.length; i++){
                    arr[i] = in.nextInt();
                    set.add(arr[i]);
                }
                Arrays.sort(arr);
                if(set.size() == 1 && arr.length !=1){
                    System.out.println("NO");
                }else if(set.size() == arr.length){
                    System.out.println("YES");
                }else {
                    System.out.println("NO");
                }
            }
        }


        public class ListNode<E> {
            private E value;
            private Ex3.ListNode next;

            public ListNode(E newVal, Ex3.ListNode<E> newNext) {
                this.value = newVal;
                this.next = newNext;
            }

            public E getValue() {
                return this.value;
            }

            public Ex3.ListNode<E> getNext() {
                return this.next;
            }

            public void setValue(E newValue) {
                this.value = newValue;
            }

            public void setNext(Ex3.ListNode<E> newNext) {
                this.next = newNext;
            }
        }
    }