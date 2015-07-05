package strings.reverse;

import java.util.Arrays;
import java.util.Stack;

/**
 * Created by ilyarudyak on 14/02/15.
 */
public class WordReverse {

    private char[] words;
    private Stack<String> bufferLeft;
    private Stack<String> bufferRight;

    private int leftPointer;
    private int rightPointer;

    public WordReverse(String s) {

        words = s.toCharArray();
        bufferLeft = new Stack<>();
        bufferRight = new Stack<>();

        leftPointer = 0;
        rightPointer = words.length - 1;
    }

    /** swap two words if array is big and empty
     * (contains only these 2 words)
     * @param start first symbol of left word
     * @param end last symbol of right word*/
    void swap(int start, int end) {

        pushLeftWord(start);
        pushRightWord(end);

        putRightWordToLeft(start);
        putLeftWordToRight(end);
    }

    /** get the word with last letter at end*/
    void pushRightWord(int end) {

        int index = end;
        while (true) {
            if (words[--index] == ' ') break;
        }

        bufferRight.push(new String(Arrays.copyOfRange(
                words, index+1, end+1)));

    }

    void pushLeftWord(int start) {

        int index = start;
        while (true) {
            if (words[++index] == ' ') break;
        }

        bufferLeft.push(new String(Arrays.copyOfRange(
                words, start, index)));
    }

    /** pop word from stack and put its last letter to end*/
    void putLeftWordToRight(int end) {

        String word = bufferLeft.pop();
        int index = end - word.length() + 1;
        System.arraycopy(word.toCharArray(), 0, words, index, word.length());
        words[index-1] = ' ';

    }

    void putRightWordToLeft(int start) {

        String word = bufferRight.pop();
        System.arraycopy(word.toCharArray(), 0, words, start, word.length());
        words[start+word.length()] = ' ';
    }

    public static void main(String[] args) {

        String s = "aaaaaa ............... bb";
        WordReverse wr = new WordReverse(s);

        System.out.println(wr.words);
        wr.swap(wr.leftPointer, wr.rightPointer);
        System.out.println(wr.words);

//        System.out.println(wr.words);
//        wr.swap(0, wr.words.length-1);
//        System.out.println(wr.words);
    }
}













