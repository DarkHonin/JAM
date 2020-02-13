#ifndef JAM_RESOURCE_HPP
#define JAM_RESOURCE_HPP

#include <map>
#include <iostream>
#include <string>

namespace JAM::MODULE{
	struct Resource{};

	class ResourceContainer : public std::map<std::string, Resource *>, public Resource{
		public:
			Resource *operator[](std::string const &key);
			void registerResource(std::string key, Resource *e);

	};
}


#endif