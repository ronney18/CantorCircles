#include "Cantor.hpp"

int main(int argc, char *argv[])
{
	if (argc != 3) 
	{
        	std::cout << "Cantor Circles [side-length][recursion-depth]" << std::endl;
		return -1;
    	}

	else
	{
    		int side = atoi(argv[1]);
    		int depth = atoi(argv[2]);

    		sf::RenderWindow window(sf::VideoMode(side, side), "Cantor Circles");
    		Cantor circles(side, depth);

		while (window.isOpen()) 
		{
        		sf::Event event;

			while (window.pollEvent(event)) 
			{
            			if (event.type == sf::Event::Closed) 
				{
					window.close();
            			}	
        		}
        		window.clear();
        		window.draw(circles);
			window.display();
    		}
	}
	return 0;
}
