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
        UVa11287 solver = new UVa11287();
        solver.solve(1, in, out);
        out.close();
    }

    static class UVa11287 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int p, a;
            while (true) {
                p = in.nextInt();
                a = in.nextInt();
                if (p == 0 && a == 0) break;
                BigInteger bip = BigInteger.valueOf(p);
                BigInteger bia = BigInteger.valueOf(a);

                if (bia.modPow(bip, bip).equals(bia) && !bip.isProbablePrime(10))
                    out.println("yes");
                else
                    out.println("no");
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

