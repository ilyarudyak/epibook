package graphs;

import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.introcs.In;
import edu.princeton.cs.introcs.StdOut;

import java.util.*;

/**
 * Created by ilyarudyak on 7/4/15.
 */
public class StringTransform {

    private  int V;
    private boolean[] marked;
    private Map<String, Integer> distTo;
    private Map<String, Integer> words;

    public StringTransform(String filename) {

        String[] wordsArray = new In(filename).readAllLines();
        int index = 0;

        words = new HashMap<>();
        for (String word : wordsArray) {
            words.put(word, index++);
        }
        V = words.size();
        marked = new boolean[V];
        distTo = new HashMap<>();

    }

    ArrayList<String> adjWords(String word) {
        ArrayList<String> adj = new ArrayList<>();
        for (String w : words.keySet()) {
            if (isAdj(w, word)) {
                adj.add(w);
            }
        }
        return adj;
    }

    boolean isAdj(String word1, String word2) {
        if (word1.length() != word2.length()) {
            return false;
        }

        Set<String> set1 = new HashSet<>(Arrays.asList(word1.split("")));
        Set<String> set2 = new HashSet<>(Arrays.asList(word2.split("")));
        set1.removeAll(set2);
        return set1.size() == 1;
    }

    public void bfs(String s) {
        int i = words.get(s);
        Queue<String> q = new Queue<>();
        for (String v : words.keySet()) { distTo.put(v, -1); }
        distTo.put(s, 0);
        marked[i] = true;
        q.enqueue(s);

        int step = 0;
        while (!q.isEmpty()) {
            String v = q.dequeue();

            for (String w : adjWords(v)) {
                if (!marked[words.get(w)]) {
                    distTo.put(w, distTo.get(v) + 1);
                    marked[words.get(w)] = true;
                    q.enqueue(w);
                }
            }
            StdOut.println(step++);
        }
    }

    @Override
    public String toString() {
        return "V=" + V + "\n" +
                "marked=" + Arrays.toString(marked) + "\n" +
                "distTo=" + distTo + "\n" +
                "words=" + words.keySet() + "\n";
    }

    public static void main(String[] args) {

        StringTransform st = new StringTransform("data/words5_small");
        st.bfs("moral");
        StdOut.println(st.distTo);


    }
}
