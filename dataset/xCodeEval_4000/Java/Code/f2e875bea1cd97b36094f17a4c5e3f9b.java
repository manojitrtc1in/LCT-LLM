    

    import java.util.*;

    public class Ex3 {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            int t = in.nextInt();
            for (int oo = 0; oo < t; oo++) {
                int n = in.nextInt();
                int count = 0;
                for(int i = 1; i <= n; i = i*10+1){
                    for(int j =1; j <= 9; j++){
                        if(i * j <= n){
                          count++;
                        }
                    }
                }
                System.out.println(count);
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
