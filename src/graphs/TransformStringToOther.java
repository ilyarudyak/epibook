package graphs;

import edu.princeton.cs.introcs.In;
import edu.princeton.cs.introcs.StdOut;

import java.util.*;

/**
 * @author translated from c++ by Blazheev Alexander
 */
public class TransformStringToOther {
    private static String randString(int len) {
        Random r = new Random();
        StringBuilder ret = new StringBuilder(len);
        while (len-- > 0) {
            ret.append((char)(r.nextInt(26) + 'a'));
        }
        return ret.toString();
    }

    // @include
    // Uses BFS to find the least steps of transformation.
    public static int transformString(Set<String> D, String s, String t) {
        LinkedList<Pair<String, Integer>> q = new LinkedList<>();
        D.remove(s); // Marks s as visited by erasing it in D.
        q.push(new Pair<>(s, 0));

        while (!q.isEmpty()) {
            Pair<String, Integer> f = q.peek();
            // Returns if we find a match.
            if (f.getFirst().equals(t)) {
                return f.getSecond(); // Number of steps reaches t.
            }

            // Tries all possible transformations of f.first.
            String str = f.getFirst();
            for (int i = 0; i < str.length(); ++i) {
                String strStart = i == 0 ? "" : str.substring(0, i);
                String strEnd = i + 1 < str.length() ? str.substring(i + 1) : "";
                for (int j = 0; j < 26; ++j) { // Iterates through 'a' ~ 'z'.
                    String modStr = strStart + (char)('a' + j) + strEnd;
                    if (D.remove(modStr)) {
                        q.push(new Pair<>(modStr, f.getSecond() + 1));
                    }
                }
            }
            q.pop();
        }

        return -1; // Cannot find a possible transformations.
    }
    // @exclude

    public static void main(String[] args) {

        In in = new In("data/graphs/words_tiny");
        String[] words = in.readAllLines();
        StdOut.println(words.length);
        Set<String> D = new HashSet<>(Arrays.asList(words));
        StdOut.println(D);


        String s = "moral";
        String t = "modal";
        System.out.println(s + " " + t + " " + D.size());
        System.out.println(transformString(D, s, t));

        }

}
