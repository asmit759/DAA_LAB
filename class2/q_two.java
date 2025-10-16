import java.util.*;


public class q_two {

    public static int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();

        System.out.println(gcd(Math.max(n, m),Math.min(n, m)));

    }
}
