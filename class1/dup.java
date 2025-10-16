// Aim of the program: Write a program to read ‘n’ integers from a disc file that must contain
// some duplicate values and store them into an array. Perform the following operations on the
// array.

// a) Find out the total number of duplicate elements.
// b) Find out the most repeating element in the array.

import java.util.*;
public class dup {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();

        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }

        dup(arr);
    }

    public static void dup(int[] arr){
        int count = 0;
        HashMap <Integer,Boolean> map=new HashMap<>();
        for(int i=0;i<arr.length;i++){
            if(map.containsKey(arr[i])){
                map.put(arr[i], true);
            } else {
                count++;
                map.put(arr[i], false);
                
            }

        }
        System.out.println(count+1);
    }
}
