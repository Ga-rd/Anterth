#include <SFML/Graphics.hpp>
#include "Player.cpp"

using namespace sf;



int main()
{

    RenderWindow window(VideoMode(800, 600), "Anterh");

    window.setFramerateLimit(60);
    
    Clock clock;

    float time = clock.getElapsedTime().asMilliseconds();
    clock.restart();
    
    Player player;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMilliseconds();
        clock.restart();
        time = time / 999;

        Event event;
        while (window.pollEvent(event))
        {
            player.update(time, event);

            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(player.draw());
        window.display();
    };

    return 0;
}