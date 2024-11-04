

import java.util.*;

public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
           int n = in.nextInt();
           int arr[] = new int[n];
           HashMap<Integer,Character> map = new HashMap<>();
           for(int i = 0; i < arr.length; i++){
               arr[i] = in.nextInt();
           }
           String str = in.next();
           char[] t1 = str.toCharArray();
            for (int i = 0; i < str.length(); i++) {
                if (!map.containsKey(arr[i])) {
                    map.put(arr[i], t1[i]);
                }
            }
            int cout = 0;
            for (int i = 0; i < n; i++) {
                if (map.get(arr[i]) != t1[i]) {
                    cout++;
                }
            }
            if(cout > 0){
                System.out.println("NO");
            }else {
                System.out.println("YES");
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