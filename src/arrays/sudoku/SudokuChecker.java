package arrays.sudoku;

import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * This class tests Sudoku grid:
 * 1) no repetition in raw, column or 3x3 parts (except 0 -
 *    it is used for empty cells in a partially filled Sudoku)
 * 2) numbers are within 0,1,...,9 range
 * 
 * Created by ilyarudyak on 12/02/15.
 */
public class SudokuChecker {

    public static final String FILENAME = "data/sudoku";
    public static final String FILENAME_WRONG = "data/sudoku_wrong";
    public static final int SIZE = 9;
    public static final int SIZE_PART = 3;

    private Integer[][] grid = new Integer[SIZE][SIZE];

    public SudokuChecker(String fileName) {

        try {
            List<String> list = Files.readAllLines(Paths.get(fileName),
                    Charset.defaultCharset());

            int index = 0;
            for(String line: list) {
                if (!line.isEmpty() && !line.contains("//"))
                    fillLine(index++, line);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    private void fillLine(int i, String line) {

        int index = 0;
        for (String s: line.replaceAll("\\s+", "").split("(?!^)"))
            grid[i][index++] = Integer.parseInt(s);
    }

    @Override
    public String toString() {

        StringBuilder sb = new StringBuilder();
        for (Integer[] a: grid)
            sb.append(Arrays.toString(a)).append("\n");
        return sb.toString();
    }

    public boolean checkSudoku() {

        for(int k=0; k<SIZE; k++) {
            if (!checkRow(k) || !checkColumn(k)) return false;
        }

        if(!checkAllParts()) return false;

        return true;
    }

    /**  check row and column */
    boolean checkColumn(int j) {

        Set<Integer> set = new HashSet<>();
        for (int i=0; i<SIZE; i++) {
            if (!checkSet(set, grid[i][j])) return false;
        }
        return true;
    }
    boolean checkRow(int i) {

        Set<Integer> set = new HashSet<>();
        for (Integer n: grid[i]) {
            if (!checkSet(set, n)) return false;
        }
        return true;
    }
    boolean checkSet(Set<Integer> set, Integer n) {

        // n is out of range
        if (n < 0 || n > 9) return false;

        // n != 0 and n IS already in the set
        if (set.contains(n) && n != 0) { set.add(n); return false; }
        else { set.add(n); return true; }
    }

    /** check all 3x3 parts of the grid*/
    boolean checkAllParts() {

        for (int i=0; i<SIZE; i+=SIZE_PART) {
            for (int j=0; j<SIZE; j+=SIZE_PART) {
                if (!checkPart(i, j)) return false;
            }
        }
        return true;
    }

    /** check 3x3 parts of grid
     * @param i0 start raw index
     * @param j0 start column index */
    boolean checkPart(int i0, int j0) {

        Set<Integer> set = new HashSet<>();
        for(int i=i0; i<i0+SIZE_PART; i++) {
            for(int j=j0; j<j0+SIZE_PART; j++) {
                if (!checkSet(set, grid[i][j])) return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {

        SudokuChecker checker = new SudokuChecker(FILENAME);
        SudokuChecker checkerWrong = new SudokuChecker(FILENAME_WRONG);
        System.out.println(checker.checkSudoku());
        System.out.println(checkerWrong.checkSudoku());
    }
}






