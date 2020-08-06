class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = dict()
        self.is_end = False

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        if word == "":
            self.is_end = True
            return

        char = word[0]
        if char not in self.data.keys():
            self.data[char] = WordDictionary()
        self.data[char].addWord(word[1:])

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        if word == "":
            return self.is_end

        char = word[0]
        if char == ".":
            return any(v.search(word[1:]) for v in self.data.values())
        if char not in self.data.keys():
            return False

        return self.data[char].search(word[1:])


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
