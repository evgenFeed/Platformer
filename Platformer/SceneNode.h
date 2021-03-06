#pragma once
#include "SFML\Graphics.hpp"
#include <memory>

enum Layer
{
	Background,
	Ground,
	LayerCount
};

class SceneNode :	public sf::Transformable, public sf::Drawable,
					private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode>	Ptr;
public:
						SceneNode();
						~SceneNode();
	void				attachChild(Ptr child);
	Ptr					detachChild(const SceneNode& node);
	virtual void		draw(sf::RenderTarget& target,
							 sf::RenderStates states) const;
	virtual void		drawCurrent(sf::RenderTarget& target,
									sf::RenderStates states) const;
	void				update(sf::Time dt);
	sf::Transform		getWorldTransform() const;
	sf::Vector2f		getWorldPosition() const;
private:
	virtual void		updateCurrent(sf::Time dt);
	void				updateChildren(sf::Time dt);

private:
	std::vector<Ptr>	mChildren;
	SceneNode*			mParent;
};

