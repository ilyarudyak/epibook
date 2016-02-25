package graphs;

import org.junit.*;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by ilyarudyak on 7/5/15.
 */
public class StringTransformTest {

    private StringTransform st;

    @Before
    public void setUp() throws Exception {
        st = new StringTransform("data/words_tiny");
    }

    @Test
    public void testAdjWords() throws Exception {
        assertEquals(5, st.adjWords("moral").size());
        assertEquals(3, st.adjWords("marli").size());
        assertEquals(1, st.adjWords("ultra").size());
    }

    @Test
    public void testIsAdj() {
        assertTrue(st.isAdj("moral", "marli"));
        assertTrue(st.isAdj("moral", "modal"));
        assertTrue(st.isAdj("moral", "marco"));

        assertFalse(st.isAdj("moral", "marl"));
        assertFalse(st.isAdj("moral", "marxy"));
        assertFalse(st.isAdj("moral", "marlo"));

    }
}