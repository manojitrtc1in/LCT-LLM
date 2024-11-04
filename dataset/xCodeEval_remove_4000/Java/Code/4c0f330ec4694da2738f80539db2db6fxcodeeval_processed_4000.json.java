

import java.util.*;

public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            int x = in.nextInt();
            int q1 = in.nextInt();
            long arr[] = new long[x+1];
            long cout = 0,cout1=0,ans=0;
            for(int i = 1; i <= x; i++){
                arr[i] = in.nextInt();
                if(arr[i]%2==0){
                    cout++;
                }
                if(arr[i]%2!=0){
                    cout1++;
                }
                ans+=arr[i];
            }
            for(int i = 0; i < q1;i++){
                int w1 = in.nextInt(),w2 = in.nextInt();
                if(w1==0){
                    ans+= (w2*cout);
                    if (w2 % 2 != 0) {
                        cout1 += cout;
                        cout = 0;
                    }
                }else {
                    ans+= (w2*cout1);
                    if (w2 % 2 != 0) {
                        cout += cout1;
                        cout1 = 0;
                    }
                }
                System.out.println(ans);
            }

        }
    }


    public static class ListNode<E> {
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