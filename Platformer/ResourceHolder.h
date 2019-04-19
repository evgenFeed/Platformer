#pragma once
#include "SFML\Graphics.hpp"
#include <memory>
#include <string>
#include <map>


namespace Textures
{
	enum ID { Player, Landscape, Background };
}


template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	
public:
											ResourceHolder();
											~ResourceHolder();
	void									load(Identifier id, const std::string & filename);
	Resource&								get(Identifier id);
	const Resource&							get(Identifier id) const;
private:
	std::map<Identifier,
			 std::unique_ptr<Resource>>		mResourceMap;
};

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
template<typename Resource, typename Identifier>
ResourceHolder<Resource, Identifier>::ResourceHolder()
{
}

template<typename Resource, typename Identifier>
ResourceHolder<Resource, Identifier>::~ResourceHolder()
{
}

template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string & filename)
{
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename))
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

	mResourceMap.insert(std::make_pair(id, std::move(resource)));
}

template<typename Resource, typename Identifier>
Resource & ResourceHolder<Resource, Identifier>::get(Identifier id)
{
	auto found = mResourceMap.find(id);
	return *found->second;
}

template<typename Resource, typename Identifier>
const Resource & ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
	auto found = mResourceMap.find(id);
	return *found->second;
}