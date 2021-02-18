#ifndef Cantor_INCLUDED
#define Cantor_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Cantor : public sf::Drawable
{
	private:
		sf::Vector2f origin;
		sf::Vector2f leftEdge;
		sf::Vector2f rightEdge;
		int initialDepth;
		Cantor* child1;
		Cantor* child2;
		void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	public:
		Cantor(int length, int depth);
		Cantor(sf::Vector2f leftEdge, sf::Vector2f rightEdge, sf::Vector2f newOrigin, int length, int depth);
		~Cantor();
};

#endif
