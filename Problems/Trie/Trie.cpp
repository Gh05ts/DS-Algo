#include <iostream>
#include <vector>

using std::vector, std::string, std::cout;

struct TrieNode {
    bool isLeaf;
    vector<TrieNode*> arr;

    TrieNode() : isLeaf(false), arr(26, nullptr) {};
};

class Trie {
    private:
        TrieNode* root;

    public:
    Trie() : root(nullptr) {};
    ~Trie() { clear(); }

    void insert(const string &s) {
        if(!root) root = new TrieNode();
        TrieNode* crawl = root;
        for(const auto &i: s) {
            if(!crawl->arr[i - 'a']) crawl->arr[i - 'a'] = new TrieNode();
            crawl = crawl->arr[i - 'a'];
        }
        crawl->isLeaf = true;
    }

    bool search(const string &s) {
        TrieNode* crawl = root;
        for(const auto &i: s) {
            if(!crawl->arr[i - 'a']) return false;
            crawl = crawl->arr[i - 'a'];
        }
        return crawl->isLeaf;
    }

    void clear() {
        
    }        
};

int main() {
    Trie a;
    a.insert("hello");
    a.insert("lamelo");
    a.insert("hey");
    // cout << a.search("melo");
    cout << a.search("lamelo");
    cout << a.search("hay");
    return 0;
}