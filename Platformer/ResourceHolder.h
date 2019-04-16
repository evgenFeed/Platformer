#pragma once
#include "SFML\Graphics.hpp"
#include <memory>

namespace Textures
{
	enum ID { Player, Landscape };
}

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
											ResourceHolder();
											~ResourceHolder();
	void									load(Identifier id, const std::string& filename);
	Resource&								get(Identifier id);
	const Resource&							get(Identifier id) const;
private:
	std::map<Identifier,
			 std::unique_ptr<Resource>>		mResourceMap;
};

