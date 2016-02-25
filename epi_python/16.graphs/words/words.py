
# ------------ create list of adj words ---------------


def adj(word):
    return [w.strip() for w in open("words") if (len(word) == len(w.strip()))
            and (len(set(word) - set(w.strip())) == 1)]


def is_adj(word1, word2):
    return (len(word1) == len(word2) and
            (len(set(word1) - set(word2)) == 1 or
             len(set(word2) - set(word1)) == 1))


def test_is_adj():
    "Test cases for the is_adj function"

    word11, word12 = "moral", "modal"
    word21, word22 = "moral", "alarm"
    word31, word32 = "alarm", "moral"
    word41, word42 = "aaaaa", "aaaab"
    word51, word52 = "aaaab", "aaaaa"

    assert(is_adj(word11, word12))
    assert(is_adj(word21, word22))
    assert(is_adj(word31, word32))
    assert(is_adj(word41, word42))
    assert(is_adj(word51, word52))
    print 'tests pass'

# ----------------- create graph file ------------------


def graph():
    f = open('graph_words_tiny', 'w')

    words = {}
    index = 0
    for w in open("words_tiny"):
        words[w.strip()] = index
        index += 1

    # write number of vertices
    f.write(str(len(words)) + "\n")

    for word1 in words:
        for word2 in words:
            if (is_adj(word1, word2) and
                    word1 != word2 and
                    words[word1] < words[word2]):
                f.write(str(words[word1]) + " " + str(words[word2]) + "\n")

# ----------------- create words files -----------------


def only_five_letters():
    return [w for w in open("words") if len(w.strip()) == 5]


def create_words():
    f = open('words5_small', 'w')
    index = 0
    for w in only_five_letters():
        if index % 10 == 0:
            f.write(w.lower())
        index += 1


def main():
    # print adj("moral")
    test_is_adj()
    # graph()


if __name__ == '__main__':
    main()
