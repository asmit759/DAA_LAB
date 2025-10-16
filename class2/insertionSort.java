public class insertionSort {
    public static void printArr(int[] arr){
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+ " ");
        }
    }
    public static void insertionSort(int[] arr){
        double start=System.nanoTime();
        for(int i=1;i<arr.length;i++){
            int temp=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>temp){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=temp;
        }
        double end =System.nanoTime();
        printArr(arr);

        System.out.println("cpu_time: "+(end-start));
    }
    public static void main(String[] args) {
        int n=1000;
        int[] arr= new int[n];

        for(int i=0;i<arr.length;i++){
            arr[i]=(int)(Math.random() * 100);
        }
        
        insertionSort(arr);
       

    }
}
