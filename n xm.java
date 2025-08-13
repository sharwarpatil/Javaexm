import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt(); 
        int M = sc.nextInt(); 

        int[][] orders = new int[N][2];
        for (int i = 0; i < N; i++) {
            o[i][0] = sc.nextInt(); 
            o[i][1] = sc.nextInt(); 
        }

        int[] ft = new int[M];      
        boolean[] isFree = new boolean[M];
        Arrays.fill(isFree, true);        

        for (int i = 0; i < N; i++) {
            int ot = orders[i][0];
            int tt = orders[i][1];

         
            for (int j = 0; j < M; j++) {
                if (ft[j] <= ot) {
                    isFree[j] = true;
                } else {
                    isFree[j] = false;
                }
            }

       
            int k = -1;
            for (int j = 0; j < M; j++) {
                if (isFree[j]) {
                    k = j;
                    break;
                }
            }

            if (k != -1) {
                ft[k] = orderTime + tt;
                isFree[k] = false;
                System.out.println("C" + (i + 1) + " - D" + (k + 1));
            } else {
       
                System.out.println("C" + (i + 1) + " - No Food ");
            }
        }

        sc.close();
    }
}
