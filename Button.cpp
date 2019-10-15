#include "Button.hpp"

Button::Button(sf::RenderWindow &w, int x, int y,bool p)
{
    window = &w;
    button.setSize(sf::Vector2f(50,50));
    button.setPosition(sf::Vector2f(x,y));
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(2);

    line[0].setSize(sf::Vector2f(40,5));
    line[0].setPosition(sf::Vector2f(x+27,y+5));
    line[0].rotate(90);

    line[1].setSize(sf::Vector2f(40,5));
    line[1].setPosition(sf::Vector2f(x+5,y+23));


    line[1].setFillColor(sf::Color::Black);
    if(p)line[0].setFillColor(sf::Color::Black);


}

void Button::draw()
{
    window->draw(button);
    window->draw(line[0]);
    window->draw(line[1]);


}

bool Button::click()
{
    int mx = sf::Mouse::getPosition(*window).x;
    int my = sf::Mouse::getPosition(*window).y;
    if(mx >= button.getPosition().x && mx <= button.getPosition().x +button.getSize().x)
        if(my >= button.getPosition().y && my <= button.getPosition().y +button.getSize().y)
            return 1;
    return 0;
}
