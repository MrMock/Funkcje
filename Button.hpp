#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

using namespace std;

class Button
{
public:
    Button(sf::RenderWindow &window, int x, int y,bool plus_value = false);
    bool click();
    void draw();
private:
    sf::RenderWindow *window;
    sf::RectangleShape button;
    sf::RectangleShape line[2];

};

#endif // BUTTON_HPP
