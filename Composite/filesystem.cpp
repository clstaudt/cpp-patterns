#include "filesystemobject.h"
#include "directory.h"
#include "file.h"

void list(FileSystemObject*);
FileSystemObject* createFileSystem();

int main()
{
    FileSystemObject* root = createFileSystem();
    list(root);

    if(root != nullptr)
    {
        delete root;
        root = nullptr;
    }

    return 0;
}

void list(FileSystemObject* root) 
{
	root->list(0);
}

FileSystemObject* createFileSystem()
{
    Directory* root = new Directory("root");
    root->addChild(new File("File A"));
    root->addChild(new File("File B"));

    Directory* dir1 = new Directory("Directory 1");
    dir1->addChild(new File("File 1A"));
    dir1->addChild(new File("File 1B"));

    root->addChild(dir1);
    return root;
}