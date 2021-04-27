public class monkey {
    public static void main(String[] args) {
        monkeyKing1();
    }

    public static void monkeyKing1() {
        int[] num = new int[17];
        int n = 17;
        int i;
        for (i = 0; i < n; i++) {
            num[i] = i;
        }
        game(num, n);
        for (i = 0; i < n; i++) {
            if (num[i] != -1) {
                System.out.println(num[i]);
            }
        }
    }

    public static void game(int p[], int n) {
        int i = 0, out = 0, count = 0, k = 3;
        while (out < n - 1) {
            if (p[i] != -1) {
                count = count + 1;
            }
            if (count == k) {
                p[i] = -1;
                count = 0;
                out = out + 1;
            }
            i = i + 1;
            if (i == n) {
                i = 0;
            }
        }
    }
}
