import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        UVa893 solver = new UVa893();
        solver.solve(1, in, out);
        out.close();
    }

    static class UVa893 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            while (true) {

                int N, D, M, Y;
                N = in.nextInt();
                D = in.nextInt();
                M = in.nextInt();
                Y = in.nextInt();
                if (N == 0 && D == 0 && Y == 0 && M == 0)
                    break;
                GregorianCalendar gc = new GregorianCalendar(Y, M - 1, D);
                gc.add(Calendar.DAY_OF_YEAR, N);

                out.printf("%d %d %d", gc.get(Calendar.DATE), gc.get(Calendar.MONTH) + 1, gc.get(Calendar.YEAR));
                out.println();
            }
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

