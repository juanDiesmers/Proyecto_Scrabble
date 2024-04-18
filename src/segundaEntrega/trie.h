#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

class TrieNode {
public:
    bool isEndOfWord;
    TrieNode* children[26];

    TrieNode();
    ~TrieNode();
};

class Trie {
protected:
    TrieNode* root;
    bool initialized;

    void clear(TrieNode* node);
    void collectAllWords(TrieNode* node, const std::string& currentWord, std::vector<std::string>& results) const;

public:
    Trie();
    virtual ~Trie();

    virtual void insert(const std::string& word);
    bool search(const std::string& word) const;
    bool wordsWithPrefix(const std::string& prefix, std::vector<std::string>& results) const;
    void initializeFromDictionaryFile(const std::string& filePath);
    bool isInitialized() const { return initialized; };
};

class ReverseTrie : public Trie {
public:
    ReverseTrie();
    void insert(const std::string& word) override;
};

#endif // TRIE_H
