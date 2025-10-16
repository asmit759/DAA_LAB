import java.util.*;

public class rotate {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        System.out.println("pos to rotate");
        int k=sc.nextInt();

        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        rotateArr(arr,k);
    }

    public static void rotateArr(int[] arr,int k){
        Exchange(arr,3);
    }

    public static void Exchange(int[] arr,int k){
        int [] arr2=new int[arr.length];
        int a=arr[0];
        arr2[0]=arr[k];
        for(int i=1;i<arr.length;i++){
            if(i<k-1){
                arr2[i]=a;
                a=arr[i+1];
            }
            else{
                arr2[i]=arr[i-1];
            }
        }

        for(int i=0;i<arr2.length;i++){
            System.out.print(arr2[i]+" ");
            
        }
    }
}
