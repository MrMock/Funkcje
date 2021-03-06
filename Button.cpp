#include "Button.hpp"

Button::Button(sf::RenderWindow &window, int x, int y,bool plus_value)
{
    this->window = &window;
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
    if(plus_value)line[0].setFillColor(sf::Color::Black);


}

void Button::draw()
{
    window->draw(button);
    window->draw(line[0]);
    window->draw(line[1]);


}

bool Button::click()
{
    int mouse_x = sf::Mouse::getPosition(*window).x;
    int mouse_y = sf::Mouse::getPosition(*window).y;
    if(mouse_x >= button.getPosition().x && mouse_x <= button.getPosition().x +button.getSize().x)
        if(mouse_y >= button.getPosition().y && mouse_y <= button.getPosition().y +button.getSize().y)
            return 1;
    return 0;
}
