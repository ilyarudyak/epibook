package arrays.spiral;

import java.util.Arrays;

/**
 * Created by ilyarudyak on 13/02/15.
 */
public class SpiralOrder {

    private int[][] grid;
    private int size;

    // create grid sizexsize and fill it
    public SpiralOrder(int size) {

        grid = new int[size][size];
        this.size = size;

        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                grid[i][j] = i * size + j + 11;
            }
        }
    }

    public static void show(int[][] input) {

        for (int[] a: input)
            System.out.println(Arrays.toString(a));
    }

    private void printEdge(int[][] input) {

        for (int j=0; j<input.length; j++) { System.out.print(input[0][j] + " "); }
        for (int i=1; i<input.length; i++) { System.out.print(input[i][input.length - 1] + " "); }
        for (int j=input.length-2; j>=0; j--) { System.out.print(input[input.length - 1][j] + " "); }
        for (int i=input.length-2; i>0; i--) { System.out.print(input[i][0] + " "); }
        System.out.println();
    }

    private int[][] removeEdge(int[][] input) {

        int[][] output = new int[input.length-2][input.length-2];
        for (int i=1; i<input.length-1; i++)
            output[i-1] = Arrays.copyOfRange(input[i], 1, input.length-1);
        return output;
    }

    public void printSpiral() {

        int[][] a = grid;
        while (true) {

            if (a.length == 0)
                return;

            if (a.length == 1) {
                System.out.println(a[0][0]);
                return;
            }

            show(a);
            System.out.println();

            printEdge(a);
            System.out.println();

            a = removeEdge(a);
        }
    }


    public static void main(String[] args) {

        SpiralOrder spiral = new SpiralOrder(7);
        spiral.printSpiral();


    }
}

















