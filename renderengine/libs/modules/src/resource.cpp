#include "modules/resource.hpp"

namespace JAM::MODULE{

	Resource *ResourceContainer::operator[](std::string const &key){
		if(find(key) == end()) return ((Resource *) NULL);
		return std::map<std::string, Resource *>::operator[](key);
	}


	void ResourceContainer::registerResource(std::string key, Resource *e){
		std::map<std::string, Resource *>::operator[](key) = e;
	}
}