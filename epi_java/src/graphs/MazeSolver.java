package graphs;

import edu.princeton.cs.algs4.BreadthFirstPaths;
import edu.princeton.cs.algs4.DepthFirstPaths;
import edu.princeton.cs.algs4.Graph;
import edu.princeton.cs.introcs.In;
import edu.princeton.cs.introcs.StdOut;

/**
 * Created by ilyarudyak on 7/5/15.
 */
public class MazeSolver {

    public static void main(String[] args) {

        In in = new In("data/graphs/graph_maze");
        Graph G = new Graph(in);
//        StdOut.println(G);

        DepthFirstPaths dfs = new DepthFirstPaths(G, 90);
        StdOut.println(dfs.pathTo(9));

        BreadthFirstPaths bfs = new BreadthFirstPaths(G, 90);
        StdOut.println(bfs.pathTo(9));
    }
}
