#include <bits/stdc++.h>
using namespace std;
//
//struct node {
//    bool endmark;
//    node* next[26 + 1];
//    node(){
//        endmark = false;
//        for (int i = 0; i < 26; i++)
//            next[i] = NULL;
//    }
//} * root;
//
//void insert(char* str, int len){
//    node* curr = root;
//    for (int i = 0; i < len; i++) {
//        int id = str[i] - 'a';
//        if (curr->next[id] == NULL)
//            curr->next[id] = new node();
//        curr = curr->next[id];
//    }
//    curr->endmark = true;
//}
//
//bool search(char* str, int len){
//    node* curr = root;
//    for (int i = 0; i < len; i++) {
//        int id = str[i] - 'a';
//        if (curr->next[id] == NULL) return false;
//        curr = curr->next[id];
//    }
//    return curr->endmark;
//}
//
//void del(node* cur){
//    for (int i = 0; i < 26; i++)
//        if (cur->next[i])
//            del(cur->next[i]);
//
//    delete (cur);
//}
//
//int main(){
//    puts("ENTER NUMBER OF WORDS: ");
//    root = new node();
//    int num_word;
//    cin >> num_word;
//    for (int i = 1; i <= num_word; i++) {
//        char str[50];
//        scanf("%s", str);
//        insert(str, strlen(str));
//    }
//    puts("ENTER NUMBER OF QUERY : ");
//    int query;
//    cin >> query;
//    for (int i = 1; i <= query; i++) {
//        char str[50];
//        scanf("%s", str);
//        if (search(str, strlen(str))) puts("FOUND");
//        else puts("NOT FOUND");
//    }
//    del(root); /// destroy trie
//    return 0;
//}

/// Memory efficient trie using map

struct Trie{
	bool isLeaf;
	unordered_map<char, Trie*> map;
};

Trie* getNewTrieNode(){
	Trie* node = new Trie;
	node->isLeaf = false;
	return node;
}

void insert(Trie*& head, char* str){
	if (head == nullptr)
		head = getNewTrieNode();
	Trie* curr = head;
	while (*str){
		if (curr->map.find(*str) == curr->map.end())
			curr->map[*str] = getNewTrieNode();
		curr = curr->map[*str];
		str++;
	}
	curr->isLeaf = true;
}

bool haveChildren(Trie const* curr){
	for (auto it : curr->map)
		if (it.second != nullptr)
			return true;

	return false;
}

bool deletion(Trie*& curr, char* str){
	if (curr == nullptr)
		return false;
	if (*str){
		if (curr != nullptr && curr->map.find(*str) != curr->map.end() &&
			deletion(curr->map[*str], str + 1) && curr->isLeaf == false){
			if (!haveChildren(curr)){
				delete curr;
				curr = nullptr;
				return true;
			}
			else {
				return false;
			}
		}
	}

	if (*str == '\0' && curr->isLeaf){
		if (!haveChildren(curr)){
			delete curr; // delete current node
			curr = nullptr;
			return true; // delete non-leaf parent nodes
		}
		else{
			curr->isLeaf = false;
			return false;		// don't delete its parent nodes
		}
	}
	return false;
}

bool search(Trie* head, char* str){
	if (head == nullptr)
		return false;
	Trie* curr = head;
	while (*str){
		curr = curr->map[*str];
		if (curr == nullptr)
			return false;
		str++;
	}
	return curr->isLeaf;
}

int main(){
	Trie* head = nullptr;
    puts("ENTER NUMBER OF WORDS: ");
    int num_word;
    cin >> num_word;
    for (int i = 1; i <= num_word; i++) {
        char str[50];
        scanf("%s", str);
        insert(head,str);
    }
    puts("ENTER NUMBER OF QUERY for search: ");
    int query;
    cin >> query;
    for (int i = 1; i <= query; i++) {
        char str[50];
        scanf("%s", str);
        if (search(head,str)) puts("FOUND");
        else puts("NOT FOUND");
    }

    puts("ENTER NUMBER OF QUERY for delete: ");
    cin >> query;
    for (int i = 1; i <= query; i++) {
        char str[50];
        scanf("%s", str);
        deletion(head,str);
    }

	return 0;
}
