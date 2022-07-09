#ifndef C7A7A245_3971_4A8A_8D6F_CFAA787539D0
#define C7A7A245_3971_4A8A_8D6F_CFAA787539D0
#include "filesystemobject.h"
#include <string>

class File : public FileSystemObject 
{
	public:
		File(const std::string& name) 
			: FileSystemObject(name)
		{
			
		}

		void list(int level) override
		{
			printName(level);
		}

};

#endif /* C7A7A245_3971_4A8A_8D6F_CFAA787539D0 */
