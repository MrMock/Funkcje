#include <SFML/Graphics.hpp>
#include <time.h>
#include <cmath>
#include "fun.hpp"
#include "Button.hpp"

#define WindowSizeX 1380
#define WindowSizeY 768



using namespace std;

int lGauss(int limit);

int main()
{
    ///Zmienne pomocnicze
    float act=0,odleglosc=0;
    int lastsec = 0;
    float lastpoint = 0;
    int limit = 80;
    time_t tm;
    struct tm * data;
    char sec[ 80 ];
    float x;
    string help="rozklad gaussa (";
    help += to_string(limit);
    help += ",-";
    help += to_string(limit);
    help += ")";

    sf::RenderWindow window(sf::VideoMode(WindowSizeX, WindowSizeY), "Funkcje");


    Fun sin_function(window, 50, 10);
    sin_function.line(60);
    sin_function.scale(100);
    sin_function.name("sin(t)");

    Fun gauss_function(window, 720 , 10);
    gauss_function.line(60);
    gauss_function.scale(3);
    gauss_function.name(help);

    Button button_plus_scale_sin_function(window,260,570, true);
    Button button_minus_scale_sin_function(window,460,570);
    Button button_plus_scale_gauss_function(window,920,570, true);
    Button button_minus_scale_gauss_function(window,1120,570);
    Button button_plus_value_gauss_function(window,920,650, true);
    Button button_minus_value_gauss_function(window,1120,650);

    while (window.isOpen())
    {


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.type != sf::Event::MouseMoved)
            {
                if(button_plus_scale_sin_function.click())sin_function.scale(sin_function.getscale()-10);
                if(button_minus_scale_sin_function.click())sin_function.scale(sin_function.getscale()+10);
                if(button_plus_scale_gauss_function.click())gauss_function.scale(gauss_function.getscale()-1);
                if(button_minus_scale_gauss_function.click())gauss_function.scale(gauss_function.getscale()+1);
                if(button_plus_value_gauss_function.click()) {
                        limit++;
                        help="rozklad gaussa (";
                        help += to_string(limit);
                        help += ",-";
                        help += to_string(limit);
                        help += ")";
                        gauss_function.name(help);
                    }
                if(button_minus_value_gauss_function.click()){if(limit>1)
                            {
                                limit--;
                                help="rozklad gaussa (";
                                help += to_string(limit);
                                help += ",-";
                                help += to_string(limit);
                                help += ")";
                                gauss_function.name(help);
                            }}
            }

        }

        time( &tm );
        data = localtime( &tm );
        strftime( sec, 80, "%S", data );

        x = atof(sec);
        if(x != lastsec){

        ///sin(t)
        lastsec = x;
            sin_function.addPoint(sin(x),x);
            for(float i =1;i<60; i++)
            {
                sin_function.addPoint(sin(x+(i/60)),(x+(i/60)));
            }

        ///rozklad gaussa
            act = lGauss(limit);
            odleglosc = sqrt((act*act)-(2*act*lastpoint)+(lastpoint*lastpoint));
            for(float i =1;i<60; i++)
            {
                if(lastpoint<act)
                gauss_function.addPoint(lastpoint + odleglosc*(i/60),(x+(i/60)));
                if(lastpoint>act)
                gauss_function.addPoint(lastpoint - odleglosc*(i/60),(x+(i/60)));
                if(lastpoint==act)
                gauss_function.addPoint(lastpoint,(x+(i/60)));
            }
            lastpoint = act;
            gauss_function.addPoint(act,x);
        }

        window.clear(sf::Color::White);
        
        sin_function.draw();
        gauss_function.draw();
        
        button_plus_scale_sin_function.draw();
        button_minus_scale_sin_function.draw();
        
        button_plus_scale_gauss_function.draw();
        button_minus_scale_gauss_function.draw();
        
        button_plus_value_gauss_function.draw();
        button_minus_value_gauss_function.draw();
        
        window.display();
    }

    return 0;
}

int lGauss(int limit)
{
    int x,p;
    srand( time( NULL ) );
    x = rand()%12;
    p = rand()%1;
    if(p==0)p=-1;

    if(x<6)
        return (rand()%(limit*6))/12*p;
    else if(x<10)
        return (rand()%(limit*10)/12)+(limit*(6/12))*p;
    else if(x<12)
        return (rand()%(limit*12)/12)+(limit*(10/12))*p;
    return 0;
}
