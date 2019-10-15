#include "Fun.hpp"

Fun::Fun(sf::RenderWindow &w,int x, int y)
{
    this->window = &w;

    linemove[0]=0;
    linemove[1]=0;

    graph.setSize(sf::Vector2f(601,500));
    graph.setFillColor(sf::Color::Black);
    graph.setPosition(sf::Vector2f(x,y));
    graph.setOutlineColor(sf::Color::Red);
    graph.setOutlineThickness(1);

    for(int i=0; i < 600; i++)
    {
        point[i].setFillColor(sf::Color::Green);
        point[i].setPosition(sf::Vector2f(x+i,300+y));
        point[i].setRadius(1);

    }


    for(int i=0; i<8; i++)
    {
        linex[i].setSize(sf::Vector2f(600.f, 1.f));
        linex[i].setFillColor(sf::Color::Red);
        linex[i].setPosition(x,y+50+((i+1)*50));
    }

    for(int i=0; i<90; i++)
    {
        liney[i].setSize(sf::Vector2f(400.f, 1.f));
        liney[i].setFillColor(sf::Color::Red);
        liney[i].setPosition(x+600,y+100);
        liney[i].setRotation(90);
    }

    linex[4].setSize(sf::Vector2f(600.f, 2.f));


    font.loadFromFile("arial.ttf");

    for(int i=0;i<9;i++)
    {
        scalex[i].setFont(font);
        scalex[i].setCharacterSize(12);
        scalex[i].setFillColor(sf::Color::Black);
        scalex[i].setPosition(graph.getPosition().x -36,graph.getPosition().y + 450-(50*i));
    }

    for(int i=0;i<90;i++)
    {
        scaley[i].setFont(font);
        scaley[i].setCharacterSize(12);
        scaley[i].setFillColor(sf::Color::Black);
        scaley[i].setPosition(graph.getPosition().x +600, graph.getPosition().y + 500 );

    }

    gname.setCharacterSize(36);
    gname.setFont(font);
    gname.setFillColor(sf::Color::White);
    gname.setPosition(graph.getPosition().x +100, graph.getPosition().y + 30);
}

void Fun::draw()
{


    window->draw(graph);

    for(int i=0; i<9; i++)
    {
        window->draw(linex[i]);
    }

    for(int i=0; i<90; i++)
    {
        window->draw(liney[i]);
    }

    for(int i =0 ; i < 600 ; i++)
    {
            if( point[i].getPosition().y > graph.getPosition().y+100 && point[i].getPosition().y < graph.getPosition().y +500 )
            window->draw(point[i]);
    }

    for(int i=0; i<90; i++)
    {
        window->draw(scaley[i]);
        window->draw(scalex[i]);
    }

    window->draw(gname);

}

void Fun::addpoint(float p,float q)
{
    float y,x;

        lastadd = p;
        for(int i = 0; i< 599; i++)
        {
            y = point[i+1].getPosition().y - point[i].getPosition().y;
            point[i].move(0,y);
        }
        y = graph.getPosition().y + 300 - (p*sc);

        x = graph.getPosition().x + 600;
        point[599].setPosition(x,y);

    for(int i=0;i<90;i++)
    {
        if(liney[i].getPosition().x <= graph.getPosition().x) {
                liney[i].setPosition(graph.getPosition().x+600,graph.getPosition().y+100);
                scaley[i].setPosition(graph.getPosition().x +600, graph.getPosition().y + 500);
                scaley[i].setString("");
                };
    }

    for(int i=0;i<90;i++)
    {
        if(liney[i].getPosition().x != graph.getPosition().x+600){
                liney[i].move(-1,0);
                scaley[i].move(-1,0);
        }
    }

    if(linemove[0]==linemove[1])
    {
        linemove[0]=0;
        for(int i=0;i<90;i++)
        {
            if(liney[i].getPosition().x == graph.getPosition().x+600) {
                    liney[i].move(-1,0);
                    scaley[i].move(-1,0);
                    scaley[i].setString(to_string((int)q));
                    break;
            }
        }
    }



        linemove[0]++;
}

void Fun::line(int b)
{
    linemove[0] = b;
    linemove[1] = b;

}
void Fun::scale(int i)
{
    if(i>0)
    {
        sc = i;

        scalex[7].setString(to_string((50/sc)*4));
        scalex[6].setString(to_string((50/sc)*3));
        scalex[5].setString(to_string((50/sc)*2));
        scalex[4].setString(to_string((50/sc)*1));
        scalex[3].setString(to_string(0));
        scalex[2].setString(to_string(-(50/sc)*1));
        scalex[1].setString(to_string(-(50/sc)*2));
        scalex[0].setString(to_string(-(50/sc)*3));

        rnumbers();

        for(int i=0;i<600;i++)
            point[i].setPosition(sf::Vector2f(graph.getPosition().x+i,graph.getPosition().y+300));
    }

}

int Fun::getscale()
{
    return sc;
}

void Fun::rnumbers()
{
    string help,help2;
    for(int i = 0 ; i < 9; i++)
    {
        help="";
        help2 = scalex[i].getString();
        for(int j=0;j<help2.size() ; j++)
        {
            help += help2[j];
            if(help2[j] == '.')
            {
                help +=help2[j+1];
                break;
            }

        }
        scalex[i].setString(help);
    }
}

void Fun::name(string n)
{
    gname.setString(n);
}
