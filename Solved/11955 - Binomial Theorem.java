import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
        Uva11955 solver = new Uva11955();
        solver.solve(1, in, out);
        out.close();
    }

    static class Uva11955 {
        public BigInteger comb(int n, int k) {
            if (k == 0 || k == n) return BigInteger.ONE;
            if (k > n - k) k = n - k;
            BigInteger top = BigInteger.ONE;
            BigInteger bot = BigInteger.ONE;

            for (int i = n - k + 1; i <= n; i++)
                top = top.multiply(BigInteger.valueOf(i));
            for (int i = 2; i <= k; i++)
                bot = bot.multiply(BigInteger.valueOf(i));

            return top.divide(bot);
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int T = in.nextInt();
            for (int tt = 1; tt <= T; tt++) {
                out.print("Case " + tt + ": ");

                String instr = in.nextLine();

                String var1 = instr.substring(1, instr.indexOf('+'));
                String var2 = instr.substring(instr.indexOf('+') + 1, instr.lastIndexOf(')'));

                int K = Integer.parseInt(instr.substring(instr.indexOf('^') + 1, instr.length()));

                StringBuilder sb = new StringBuilder();
                for (int i = 0; i <= K; i++) {
                    if (i != 0) sb.append('+');
                    BigInteger n = comb(K, i);
                    if (!n.equals(BigInteger.ONE)) {
                        sb.append(n.toString());
                        sb.append('*');
                    }

                    if (K - i != 0) {
                        sb.append(var1);
                        if (K - i != 1) {
                            sb.append('^');
                            sb.append(K - i);
                        }
                    }
                    if (i != 0) {
                        if (K - i != 0)
                            sb.append('*');
                        sb.append(var2);
                        if (i != 1) {
                            sb.append('^');
                            sb.append(i);
                        }
                    }
                }

                out.println(sb.toString());
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

        public String nextLine() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
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

