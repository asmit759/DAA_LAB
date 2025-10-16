import java.util.*;
public class q_one{
    public static void binary(){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        StringBuilder str=new StringBuilder("");

        while(n!=0){
            if(n==1){
                str.append(n);
                break;
            }
            int temp=n%2;
            str.append(temp);
            n/=2;
        }

        System.out.println(str.reverse());

        
    }
    public static void main(String[] args) {
        binary();
    }
}