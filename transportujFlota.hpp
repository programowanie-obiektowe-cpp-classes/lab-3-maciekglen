#pragma once

#include "Statki.hpp"
#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{

    if (towar == 0) {
        return 0;
    }

    int      przewiezionytowar = 0;
    int      licznikzaglowcow  = 0;
    Stocznia stocznia{};

    while (przewiezionytowar < towar) {

        Statek* s1            = stocznia();
        int     chwilowytowar = s1->transportuj();

        przewiezionytowar += chwilowytowar;

        Statek* f = s1;

        Zaglowiec* zaglowiec = dynamic_cast< Zaglowiec* >(f);

        if (zaglowiec) {
            licznikzaglowcow++;
        }

        delete s1;
    }

    return licznikzaglowcow;
}