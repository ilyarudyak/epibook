package arrays.sudoku;

import org.junit.Before;
import org.junit.Test;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

import static org.junit.Assert.*;

public class SudokuCheckerTest {

    private SudokuChecker checker;
    private SudokuChecker checkerWrong;

    @Before
    public void setUp() {
        checker = new SudokuChecker(SudokuChecker.FILENAME);
        checkerWrong = new SudokuChecker(SudokuChecker.FILENAME_WRONG);
    }

    @Test
    public void testCheckSet() {

        Set<Integer> set = new HashSet<>(Arrays.asList(0,1,2,3));

        assertEquals(true, checker.checkSet(set, 5));
        assertEquals(true, set.contains(5));
        assertEquals(true, checker.checkSet(set, 0));
        assertEquals(false, checker.checkSet(set, 1));
        assertEquals(false, checker.checkSet(set, 10));

    }

    @Test
    public void testCheckRaw() {

        for (int i=0; i<SudokuChecker.SIZE; i++)
            assertEquals(true, checker.checkRow(i));

        assertEquals(false, checkerWrong.checkRow(0));
    }

    @Test
    public void testCheckColumn() {

        for (int j=0; j<SudokuChecker.SIZE; j++)
            assertEquals(true, checker.checkColumn(j));
    }

    @Test
    public void testCheckPart() {

        assertEquals(true, checker.checkPart(0,0));
        assertEquals(false, checkerWrong.checkPart(3,0));
    }

    @Test
    public void testCheckAllParts() {

        assertEquals(true, checker.checkAllParts());
        assertEquals(false, checkerWrong.checkAllParts());
    }

    @Test
    public void testCheckSudoku() {

        assertEquals(true, checker.checkSudoku());
        assertEquals(false, checkerWrong.checkSudoku());
    }


}




















