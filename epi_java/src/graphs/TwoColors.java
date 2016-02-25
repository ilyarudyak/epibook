package graphs;

import edu.princeton.cs.algs4.Graph;
import edu.princeton.cs.introcs.In;
import edu.princeton.cs.introcs.StdOut;

import java.util.Arrays;

/**
 * Created by ilyarudyak on 7/12/15.
 */
public class TwoColors {

    private boolean[] marked;    // marked[v] = is there an s-v path?
    private boolean[] color;
    private boolean isBipartite;
//    private int count;           // number of vertices connected to s

    public TwoColors(Graph G, int s) {
        marked = new boolean[G.V()];
        color = new boolean[G.V()];
        isBipartite = true;
        dfs(G, s);
    }

    // depth first search from v
    private void dfs(Graph G, int v) {
//        count++;
        marked[v] = true;
        for (int w : G.adj(v)) {
            if (!marked[w]) {
                color[w] = !color[v];
                dfs(G, w);
            }
            else if (color[w] == color[v]) isBipartite = false;
        }
    }

    public boolean isBipartite() {  return isBipartite;  }


    public static void main(String[] args) {

        In in = new In("data/graphs/graph_2colors_epi");
        Graph G = new Graph(in);
//        StdOut.println(G);

        TwoColors tc = new TwoColors(G, 0);
        StdOut.println(Arrays.toString(tc.color));

    }
}
