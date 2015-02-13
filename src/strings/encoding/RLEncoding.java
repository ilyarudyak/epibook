package strings.encoding;


/**
 * Created by ilyarudyak on 13/02/15.
 */
public class RLEncoding {

    private String plainString;
    private StringBuilder encodedString;
    private int index;

    public String getPlainString() {
        return plainString;
    }
    public StringBuilder getEncodedString() {
        return encodedString;
    }

    public RLEncoding(String s) {
        plainString = s;
        encodedString = new StringBuilder();
        index = 0;
    }

    public void encode() {

        while (index < plainString.length()) {
            encodeFirstLetter(plainString.substring(index));
//            System.out.println(encodedString);
        }

    }

    // encode only first letter in the string
    // and return index of first different letter
    void encodeFirstLetter(String s) {

        if (s.isEmpty())
            throw new IllegalArgumentException("empty string");

        char ch0 = s.charAt(0);
        int counter = 0;
        int i;
        for (i=0; i<s.length(); i++) {
            if (s.charAt(i) == ch0) counter++;
            else break;
        }
        encodedString.append(counter).append(ch0);
        index += i;
//        System.out.println(index);
    }

    public static void main(String[] args) {

        RLEncoding rle = new RLEncoding("aaaabcccaa");
        rle.encode();
    }

}
















