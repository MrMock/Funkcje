#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

using namespace std;

class Button
{
public:
    Button(sf::RenderWindow &w, int x, int y,bool p = false);
    bool click();
    void draw();
private:
    sf::RenderWindow *window;
    sf::RectangleShape button;
    sf::RectangleShape line[2];

};

#endif // BUTTON_HPP
