package graphs;

import edu.princeton.cs.algs4.BreadthFirstPaths;
import edu.princeton.cs.algs4.Graph;
import edu.princeton.cs.introcs.In;
import edu.princeton.cs.introcs.StdOut;

import java.util.Arrays;


/**
 * Created by ilyarudyak on 7/5/15.
 */
public class StringTransform2 {

    public static void main(String[] args) {
        In in = new In("data/graphs/graph_words_tiny");
        Graph G = new Graph(in);
//        StdOut.println(G);

        in = new In("data/graphs/words_tiny");
        String[] words = in.readAllLines();

        int s = Arrays.asList(words).indexOf("moral");
        int t = Arrays.asList(words).indexOf("rapid");
        StdOut.println(s + " " + t);

        BreadthFirstPaths bfp = new BreadthFirstPaths(G, s);
        StdOut.println(bfp.distTo(t));


        StdOut.print(words[s]);
        for (int w : bfp.pathTo(t)) {
            if (s != w) {
                StdOut.print(" -> " + words[w]);
            }
        }
        StdOut.println();
    }
}
