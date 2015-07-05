package graphs;

import edu.princeton.cs.algs4.BreadthFirstDirectedPaths;
import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.introcs.In;
import edu.princeton.cs.introcs.StdOut;

/**
 * Created by ilyarudyak on 7/5/15.
 */
public class WaterSolver {

    public static void main(String[] args) {

        In in = new In("data/graphs/graph_water");
        Digraph G = new Digraph(in);
//        StdOut.println(G);

        BreadthFirstDirectedPaths bfs = new BreadthFirstDirectedPaths(G, 0);
        for(int i=30; i<35; i++){
            if (bfs.hasPathTo(i)) {
                StdOut.println(bfs.pathTo(i));
            }
        }
    }
}
