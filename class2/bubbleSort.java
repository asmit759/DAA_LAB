public class bubbleSort {
     public static void printArr(int[] arr){
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+ " ");
        }
    }
    public static void bubbleSort(int[] arr){
        int n=arr.length;
        double start=System.nanoTime();
        for(int turns=0;turns<n-1;turns++){
            for(int i=0;i<n-1-turns;i++){
                if(arr[i]>arr[i+1]){
                    int temp=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                }
            }
        }
        double end =System.nanoTime();
        printArr(arr);

        System.out.println("cpu_time: "+(end-start));
    }
    public static void main(String[] args) {
        int n=6;
        int[] arr= new int[n];

        for(int i=0;i<arr.length;i++){
            arr[i]=(int)(Math.random() * 100);
        }
        
        bubbleSort(arr);
       

    }
}
