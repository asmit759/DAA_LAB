
import java.util.*;

public class arr{
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();

        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        maxArr(arr);
        minArr(arr);
    }


    public static void maxArr(int[] arr){
        int max = Integer.MIN_VALUE;
        for(int i=0;i<arr.length;i++){
            if(max<arr[i]){
                max=arr[i];

            }
        }

        int secMax=max;
        for(int i=0;i<arr.length;i++){
            if(secMax>=arr[i] && max>arr[i]){
                secMax=arr[i];
            }
        }
        System.out.println( "Sec max : "+secMax);
    }

    public static void minArr(int[] arr){
        int min = Integer.MAX_VALUE;
        for(int i=0;i<arr.length;i++){
            if(min>arr[i]){
                min=arr[i];

            }
        }
        int secMin=min;
        for(int i=0;i<arr.length;i++){
            if(secMin>=arr[i] && arr[i]>min){
                secMin=arr[i];
            }
        }
        System.out.println( "Sec max : "+secMin);
        System.out.println(min);
    }
}