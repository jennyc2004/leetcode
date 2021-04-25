//============================================================================
// Name        : map_FileSystem.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>

struct Node{
    unordered_map<string, Node*> dir = {};
    vector<string> pathList = {};
    string content = "";
};
class FileSystem {
private:
    Node * root;
public:
    FileSystem() {
        root = new Node;
    }

    vector<string> ls(string path) {
        Node * temp = file(path);
        if(temp->content.size()) return {path.substr(path.find_last_of('/') + 1)};
        sort(temp->pathList.begin(), temp->pathList.end());
        return temp->pathList;
    }

    void mkdir(string path) {
        file(path);
    }

    void addContentToFile(string filePath, string content) {
        file(filePath)->content += content;
    }

    string readContentFromFile(string filePath) {
        return file(filePath)->content;
    }
    Node *file(string path){
        Node * temp = root;
        stringstream ss(path);
        string curPath = "";
        while(getline(ss, curPath, '/')){
            if(temp->dir[curPath] == nullptr){
                temp->dir[curPath] = new Node;
                temp->pathList.push_back(curPath);
            }
            temp = temp->dir[curPath];
        }
        return temp;
    }
};

int main()
{
	FileSystem f;
	f.mkdir("/a/b/c");
	f.addContentToFile("/a/b/c/d", "hello");
	cout<<f.readContentFromFile("/a/b/c/d")<<endl;
	return 0;
}
