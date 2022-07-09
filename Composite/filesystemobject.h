#ifndef C375733E_1436_46E7_93DF_E1D86488763A
#define C375733E_1436_46E7_93DF_E1D86488763A

#include <string>
#include <iostream>

namespace 
{
std::string operator*(std::string const &s, size_t n)
{
    std::string r; 
    r.reserve(n * s.size());
    for (size_t i=0; i<n; i++)
        r += s;
    return r;
}
}

class FileSystemObject 
{	
	private:
        const std::string name;
	
	public:   
        FileSystemObject(const std::string& name) : name(name)
        {         
        }
        
        std::string getName() const
        {
            return name;
        }

        void printName(int level)
        {
		    std::cout << std::endl << getLevelPrefix(level) << getName() << std::endl;
	    }
	
	    virtual void list(int level) = 0;
	       
    private:
        std::string getLevelPrefix(int level)
        {
            return (std::string("-") * level);
        }

};


#endif /* C375733E_1436_46E7_93DF_E1D86488763A */
