#include "strings_utils.h"
#include <iostream>

std::string extrac_name(const std::string dir)
{
	for (int i=0; i < dir.size(); i++)
	{
		if (dir[i] == '/')
		{
			return dir.substr(dir.find_last_of('/')+1);
		}
		if (dir[i] == '\\')
		{
			return dir.substr(dir.find_last_of('\\')+1);
		}
	}
	return dir;
}