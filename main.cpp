#include <SFML/Graphics.hpp>
#include <time.h>
#include <cmath>
#include "Fun.hpp"
#include "Button.hpp"

using namespace std;

int lgauss(int limit);

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

    sf::RenderWindow window(sf::VideoMode(1380, 768), "Funkcje");


    Fun fun_1(window, 50, 10);
    fun_1.line(60);
    fun_1.scale(100);
    fun_1.name("sin(t)");

    Fun fun_2(window, 720 , 10);
    fun_2.line(60);
    fun_2.scale(3);
    fun_2.name(help);

    Button b1(window,260,570, true);
    Button b2(window,460,570);
    Button b3(window,920,570, true);
    Button b4(window,1120,570);
    Button b5(window,920,650, true);
    Button b6(window,1120,650);

    while (window.isOpen())
    {


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.type != sf::Event::MouseMoved)
            {
                if(b1.click()) fun_1.scale(fun_1.getscale()-10);
                if(b2.click())fun_1.scale(fun_1.getscale()+10);
                if(b3.click())fun_2.scale(fun_2.getscale()-1);
                if(b4.click())fun_2.scale(fun_2.getscale()+1);
                if(b5.click()) {
                        limit++;
                        help="rozklad gaussa (";
                        help += to_string(limit);
                        help += ",-";
                        help += to_string(limit);
                        help += ")";
                        fun_2.name(help);
                    }
                if(b6.click()){if(limit>1)
                            {
                                limit--;
                                help="rozklad gaussa (";
                                help += to_string(limit);
                                help += ",-";
                                help += to_string(limit);
                                help += ")";
                                fun_2.name(help);
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
            fun_1.addpoint(sin(x),x);
            for(float i =1;i<60; i++)
            {
                fun_1.addpoint(sin(x+(i/60)),(x+(i/60)));
            }

        ///rozklad gaussa
            act = lgauss(limit);
            odleglosc = sqrt((act*act)-(2*act*lastpoint)+(lastpoint*lastpoint));
            for(float i =1;i<60; i++)
            {
                if(lastpoint<act)
                fun_2.addpoint(lastpoint + odleglosc*(i/60),(x+(i/60)));
                if(lastpoint>act)
                fun_2.addpoint(lastpoint - odleglosc*(i/60),(x+(i/60)));
                if(lastpoint==act)
                fun_2.addpoint(lastpoint,(x+(i/60)));
            }
            lastpoint = act;
            fun_2.addpoint(act,x);
        }

        window.clear(sf::Color::White);
        fun_1.draw();
        fun_2.draw();
        b1.draw();
        b2.draw();
        b3.draw();
        b4.draw();
        b5.draw();
        b6.draw();
        window.display();
    }

    return 0;
}

int lgauss(int limit)
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
