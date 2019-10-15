#ifndef FUN_HPP
#define FUN_HPP

#include <SFML/Graphics.hpp>

using namespace std;

class Fun
{
public:
    Fun(sf::RenderWindow &w,int x, int y);
    void addpoint(float p,float q);
    void draw();
    void line(int b);
    void scale(int scale);
    void name(string n);
    int getscale();
private:
    sf::CircleShape point[600];
    sf::RectangleShape linex[9];
    float sc = 1;
    sf::Text scalex[9];
    sf::Text scaley[90];
    sf::Text gname;
    sf::Font font;
    sf::RectangleShape liney[90];
    sf::RenderWindow *window;
    sf::RectangleShape graph;
    int linemove[2];
    float lastadd=0;
    void rnumbers();


};

#endif // FUN_HPP
