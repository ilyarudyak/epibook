class Palindrome {


  def first(String string) {
    string.substring(0, 1)
  }

  def last(String string) {
    string.substring(string.length()-1)
  }

  def middle(String string) {
    string.substring(1, string.length()-1)
  }

  def isPalindrome(String string) {
    if (string.length() == 1) {
      return true
    } else if (string.length() == 2) {
      return first(string) == last(string)
    } else {
      isPalindrome(middle(string))
    }
  }

  def getPalindroms(String filename) {
    def words = new File(filename).readLines()
    words.each {word -> if (isPalindrome(strip(word))) 
      println word} 
  }

  def strip(String string) {
    string.replaceAll("[ :,.?!\"]", "").toLowerCase() 
  }


  static void main(String... args) {  
    Palindrome p = new Palindrome()
    p.getPalindroms('resources/test.txt')               
  }
}

