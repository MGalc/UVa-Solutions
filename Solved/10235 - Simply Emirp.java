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
        UVa10235 solver = new UVa10235();
        solver.solve(1, in, out);
        out.close();
    }

    static class UVa10235 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            while (in.hasMore()) {
                String ins = in.next();
                String insr = new StringBuilder(ins).reverse().toString();

                BigInteger bi = new BigInteger(ins);
                BigInteger bir = new BigInteger(insr);
                if (bi.isProbablePrime(10)) {
                    if (bir.isProbablePrime(10) && !ins.equals(insr))
                        out.println(ins + " is emirp.");
                    else
                        out.println(ins + " is prime.");
                } else
                    out.println(ins + " is not prime.");
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

        public boolean hasMore() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    String s = reader.readLine();
                    if (s == null)
                        return false;
                    tokenizer = new StringTokenizer(s);
                } catch (IOException e) {
                    return false;
                }
            }
            return true;
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

    }
}

