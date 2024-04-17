#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>

class TrieNode {
public:
    bool isEndOfWord;
    TrieNode* children[26]; // Asumiendo solo letras de la 'a' a la 'z'

    TrieNode();
    ~TrieNode();
};

class Trie {
protected:
    TrieNode* root;
    void clear(TrieNode* node);
    void collectAllWords(TrieNode* node, const std::string& currentWord, std::vector<std::string>& results) const;

public:
    Trie();
    virtual ~Trie(); // Destructor virtual para garantizar una eliminación adecuada
    virtual void insert(const std::string& word);
    bool search(const std::string& word) const;
    std::vector<std::string> wordsWithPrefix(const std::string& prefix) const;
    void initializeFromDictionaryFile(const std::string& filePath);
};

class ReverseTrie : public Trie {
public:
    ReverseTrie();
    void insert(const std::string& word) override;
};

#endif // TRIE_H
