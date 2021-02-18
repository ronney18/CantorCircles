#include "Cantor.hpp"

Cantor::Cantor(int length, int depth)
	: initialDepth(depth)
{
	int newDepth = initialDepth - 1;
	leftEdge.x = 0;
	leftEdge.y = length / 2.0;
	rightEdge.x = length;
	rightEdge.y = length / 2.0;
	origin.x = length / 2.0;
	origin.y = length / 2.0;

	sf::Vector2f leftOrigin;
	sf::Vector2f rightOrigin;

	leftOrigin.x = origin.x / 2.0;
	leftOrigin.y = origin.y;

	rightOrigin.x = (origin.x + rightEdge.x) / 2.0;
	rightOrigin.y = origin.y;

	if(newDepth == 0)
	{
		child1 = NULL;
		child2 = NULL;
	}

	else
	{
		child1 = new Cantor(leftEdge, origin, leftOrigin, length/2.0, newDepth);
		child2 = new Cantor(origin, rightEdge, rightOrigin, length/2.0, newDepth);
	}
}

Cantor::Cantor(sf::Vector2f leftEdge, sf::Vector2f rightEdge, sf::Vector2f newOrigin, int length, int depth)
	: initialDepth(depth)
{
	int newDepth = initialDepth - 1;
	this->leftEdge = leftEdge;
        this->rightEdge = rightEdge;

	sf::Vector2f leftOrigin;
	sf::Vector2f rightOrigin;
	
	origin = newOrigin;
	leftOrigin.x = (leftEdge.x + origin.x) / 2.0;
	leftOrigin.y = origin.y;

	rightOrigin.x = (origin.x + rightEdge.x) / 2.0;
	rightOrigin.y = origin.y;

	if(newDepth == 0)
        {
                child1 = NULL;
                child2 = NULL;
        }

        else
        {
                child1 = new Cantor(leftEdge, origin, leftOrigin, length/2.0, newDepth);
                child2 = new Cantor(origin, rightEdge, rightOrigin, length/2.0, newDepth);
        }
}

Cantor::~Cantor()
{
	if(child1 != NULL)
	{
		delete (child1);
		delete (child2);
	}
}

void Cantor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Color myColor = sf::Color(255 - origin.x, 80 + origin.y, 110 + origin.x);
	sf::CircleShape circle;
	circle.setRadius(origin.x - leftEdge.x);
	sf::FloatRect circleRect = circle.getLocalBounds();
	circle.setOrigin(0, circleRect.height / 2.0);
	circle.setPosition(leftEdge.x, target.getSize().y / 2.0);
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineColor(myColor);
	circle.setOutlineThickness(2);
	
	target.draw(circle);

    	if(child1 != NULL)
    	{
        	child1->draw(target, states);
        	child2->draw(target, states);
    	}

}
