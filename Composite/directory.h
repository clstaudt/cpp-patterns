#ifndef A898ACC7_6F5D_490B_86AC_4D3666850FF9
#define A898ACC7_6F5D_490B_86AC_4D3666850FF9

#include "filesystemobject.h"
#include <string>
#include <vector>
#include <iterator>

class Directory : public FileSystemObject 
{
    private:
	    std::vector<FileSystemObject*> children;

    public:
        Directory(const std::string& name) 
            : FileSystemObject(name)
        {
            
        }

        ~Directory()
        {
            for (auto p : children)
                delete p;
        }

        std::vector<FileSystemObject*> getChildren() 
        {
            return children;
        }

	    void list(int level) override
        {
            printName(level);
            for(std::vector<FileSystemObject*>::iterator it = std::begin(children); 
                it != std::end(children); ++it) 
            {
                (*it)->list(level + 1);
            }
        }

        void addChild(FileSystemObject* fso) {
            children.push_back(fso);
        }


        void removeChild(FileSystemObject* fso) {
            //children.remove(fso);
        }

};

#endif /* A898ACC7_6F5D_490B_86AC_4D3666850FF9 */
