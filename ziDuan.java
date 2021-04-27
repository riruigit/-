import java.util.Scanner;

public class ziDuan {

    static int i = 0, j = 0;

    public static void main(String[] args) {
        partsum1();
    }

    public static void partsum1() {
        int n, t;
        int[] a = new int[100];
        System.out.println("input number of data(<99)");
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        System.out.println("input    " + n + "    number");
        for (i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
        }
        i = 1;
        j = 1;
        t = max_sum1(a, n, i, j);
        System.out.println("the most sum of section is   "+t);
        System.out.println("starting point is  "+i);
        System.out.println("end point is  "+j);
    }

    public static int max_sum1(int[] a, int n, int c, int b) {
        int q, w, e, this_sum, sum = 0;
        for (q = 1; q <= n; q = q + 1) {
            for (w = q; w <= n; w++) {
                this_sum = 0;
                for (e = q; e <= w; e++) {
                    this_sum = this_sum + a[e];
                }
                if (this_sum > sum) {
                    sum = this_sum;
                    i = q;
                    j = w;
                }
            }
        }
        return sum;
    }
}
