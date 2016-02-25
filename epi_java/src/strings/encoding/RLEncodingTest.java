package strings.encoding;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

public class RLEncodingTest {

    private RLEncoding rle;

    @Before
    public void setUp() throws Exception {
        rle = new RLEncoding("aaaabcccaa");
    }

    @Test
    public void testEncodeFirstLetter() throws Exception {

        rle.encodeFirstLetter(rle.getPlainString());
        assertEquals("4a", rle.getEncodedString().toString());

    }

    @Test
    public void testRLEEncode() {
        rle.encode();
        assertEquals("4a1b3c2a", rle.getEncodedString().toString());
    }
}