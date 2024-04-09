#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    char ch;
    int f;
    Node* left;
    Node* right;
};

Node* getnode(char ch, int f, Node* left, Node* right) {
    Node* node = new Node();
    node->ch = ch;
    node->f = f;
    node->left = left;
    node->right = right;
    return node;
}

struct comp {
    bool operator()(Node* left, Node* right) {
        if (left->f == right->f)
            return left->ch > right->ch;
        return left->f > right->f;
    }
};

Node* buildhuffman(priority_queue<Node*, vector<Node*>, comp>& q) {
    while (q.size() > 1) {
        Node* z = getnode('\0', 0, nullptr, nullptr);
        Node* x = q.top(); q.pop();
        Node* y = q.top(); q.pop();
        z->left = x;
        z->right = y;
        z->f = x->f + y->f;
        q.push(z);
    }
    return q.top();
}

void encode(Node* root, string str, unordered_map<char, string>& huff) {
    if (root == nullptr)
        return;
    if (!root->left && !root->right) {
        huff[root->ch] = str;
    }
    encode(root->left, str + "0", huff);
    encode(root->right, str + "1", huff);
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;
    unordered_map<char, int> mp;
    char ch;
    int f;
    cout << "Enter characters and their frequencies: ";
    for (int i = 0; i < n; i++) {
        cin >> ch >> f;
        mp[ch] = f;
    }
    priority_queue<Node*, vector<Node*>, comp> pq;
    for (auto p : mp) {
        pq.push(getnode(p.first, p.second, nullptr, nullptr));
    }
    Node* root = buildhuffman(pq);
    unordered_map<char, string> huff;
    encode(root, "", huff);
    vector<pair<char, string>> sorted(huff.begin(), huff.end());
    sort(sorted.begin(), sorted.end());
    cout << "\nHuffman Codes are : " << endl;
    for (auto pair : sorted) {
        cout << pair.first << " - " << pair.second << endl;
    }
    return 0;
}
