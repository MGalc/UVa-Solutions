import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.regex.Matcher;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.regex.Pattern;
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
        UVa10058 solver = new UVa10058();
        solver.solve(1, in, out);
        out.close();
    }

    static class UVa10058 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            //String regex =
            String article = "(a)|(the)";
            String noun = "(tom)|(jerry)|(goofy)|(mickey)|(jimmy)|(dog)|(cat)|(mouse)";
            String verb = "(hates?)|(loves?)|(knows?)|(likes?)";
            String actor = "((" + article + ") +)?(" + noun + ")";
            String activelist = "(" + actor + " +and +)*(" + actor + ")";
            String action = "(" + activelist + ") +(" + verb + ") (" + activelist + ")";
            String statement = "((" + action + ") *, *)*(" + action + ") *";

            Pattern p = Pattern.compile(statement);

            String input = in.nextLine();
            while (input != null) {
                Matcher m = p.matcher(input);
                if (m.matches())
                    out.println("YES I WILL");
                else
                    out.println("NO I WON'T");

                input = in.nextLine();
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
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

    }
}

