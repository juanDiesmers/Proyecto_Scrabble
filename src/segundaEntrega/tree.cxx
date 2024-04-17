#include "trie.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cctype> // Para funciones de caracter como std::isalpha y std::tolower

// Constructor de TrieNode
TrieNode::TrieNode() : isEndOfWord(false) {
    for (int i = 0; i < 26; ++i) {
        children[i] = nullptr;
    }
}

// Destructor de TrieNode
TrieNode::~TrieNode() {
    for (int i = 0; i < 26; ++i) {
        if (children[i] != nullptr) {
            delete children[i];
            children[i] = nullptr;
        }
    }
}

// Constructor de Trie
Trie::Trie() {
    root = new TrieNode();
}

// Destructor de Trie
Trie::~Trie() {
    clear(root);
}

void Trie::clear(TrieNode* node) {
    for (int i = 0; i < 26; ++i) {
        if (node->children[i] != nullptr) {
            clear(node->children[i]);
        }
    }
    delete node;
}

void Trie::insert(const std::string& word) {
    TrieNode* currentNode = root;
    for (char ch : word) {
        if (!isalpha(ch)) continue;
        int index = tolower(ch) - 'a';
        if (currentNode->children[index] == nullptr) {
            currentNode->children[index] = new TrieNode();
        }
        currentNode = currentNode->children[index];
    }
    currentNode->isEndOfWord = true;
}

bool Trie::search(const std::string& word) const {
    TrieNode* currentNode = root;
    for (char ch : word) {
        int index = tolower(ch) - 'a';
        if (currentNode->children[index] == nullptr) {
            return false;
        }
        currentNode = currentNode->children[index];
    }
    return currentNode != nullptr && currentNode->isEndOfWord;
}

std::vector<std::string> Trie::wordsWithPrefix(const std::string& prefix) const {
    std::vector<std::string> results;
    TrieNode* currentNode = root;
    for (char ch : prefix) {
        int index = tolower(ch) - 'a';
        if (currentNode->children[index] == nullptr) {
            return results;
        }
        currentNode = currentNode->children[index];
    }
    collectAllWords(currentNode, prefix, results);
    return results;
}

void Trie::collectAllWords(TrieNode* node, const std::string& currentWord, std::vector<std::string>& results) const {
    if (node->isEndOfWord) {
        results.push_back(currentWord);
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) {
            collectAllWords(node->children[i], currentWord + char('a' + i), results);
        }
    }
}

void Trie::initializeFromDictionaryFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cout << "(Archivo no existe) El archivo " << filePath << " no existe o no puede ser leído." << std::endl;
        return;
    }
    std::string word;
    while (file >> word) {
        if (std::all_of(word.begin(), word.end(), [](unsigned char c) { return std::isalpha(c); })) {
            std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return std::tolower(c); });
            insert(word);
        }
    }
    std::cout << "(Resultado exitoso) El árbol del diccionario se ha inicializado correctamente." << std::endl;
}

// Constructor de ReverseTrie
ReverseTrie::ReverseTrie() : Trie() {}

// Función de inserción para ReverseTrie
void ReverseTrie::insert(const std::string& word) {
    std::string reversedWord = word;
    std::reverse(reversedWord.begin(), reversedWord.end());
    Trie::insert(reversedWord);
}
