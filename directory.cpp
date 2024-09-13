
#include <iostream>
#include <string>

using namespace std;

struct FileNode {
    string fileName;
    FileNode* next;

    FileNode(const string& name) : fileName(name), next(nullptr) {}
};

FileNode* fileSystem = nullptr;

void addFile(const string& fileName) {
    FileNode* newNode = new FileNode(fileName);
    newNode->next = fileSystem;
    fileSystem = newNode;
}

bool findFile(const string& fileName) {
    FileNode* temp = fileSystem;
    while (temp != nullptr) {
        if (temp->fileName == fileName) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void displayFileSystem() {
    cout << "Files in the file system:" << endl;
    FileNode* temp = fileSystem;
    while (temp != nullptr) {
        cout << temp->fileName << endl;
        temp = temp->next;
    }
}

int main() {
    addFile("document.txt");
    addFile("image.jpg");
    addFile("report.docx");

    cout << "File system created." << endl;
    displayFileSystem();

    string searchFileName;
    cout << "\nEnter a file name to search: ";
    cin >> searchFileName;

    if (findFile(searchFileName)) {
        cout << "File found!" << endl;
    } else {
        cout << "File not found." << endl;
    }

    return 0;
}
