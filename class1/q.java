import java.util.Scanner;

public class q {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();

        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }

        prefixArr(arr);
    }

    public static void prefixArr(int[] arr){
        int[] secArr=new int[arr.length];
        secArr[0]=arr[0];
        for(int i=1;i<arr.length;i++){
            secArr[i]=secArr[i-1]+arr[i];

        }

        for(int i=0;i<secArr.length;i++){
            System.out.print("arr : "+arr[i]+ " ");
            System.out.println();
        }

        for(int i=0;i<secArr.length;i++){
            System.out.print("secarr : "+secArr[i]+ " ");
        }
    }
}
