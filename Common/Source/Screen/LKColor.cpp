/*
 * LK8000 Tactical Flight Computer -  WWW.LK8000.IT
 * Released under GNU/GPL License v.2
 * See CREDITS.TXT file for authors and copyrights
 *
 * File:   LKColor.cpp
 * Author: Bruno de Lacheisserie
 * 
 * Created on 15 octobre 2014, 20:16
 */


#ifdef WIN32
#include <windows.h>
#else 
#warning "TODO: need to implement"
#endif

#include <utility>
#include "LKColor.h"
#include "RGB.h"

LKColor LKColor::ContrastTextColor() const {
    //  human eye brightness color factors
    //	Y=0.30 R + 0.59 G + 0.11 B.
   return ((0.30 * (double) Blue() + 0.59 * (double) Green() + 0.11 * (double) Red() > 127) ? RGB_BLACK : RGB_WHITE);
}

LKColor LKColor::ChangeBrightness(double fBrightFact) const {
    int red = (int) (fBrightFact * (double) Red());
    if (red > 255) red = 255;
    int blue = (int) (fBrightFact * (double) Blue());
    if (blue > 255) blue = 255;
    int green = (int) (fBrightFact * (double) Green());
    if (green > 255) green = 255;

    return LKColor((uint8_t) red, (uint8_t) green, (uint8_t) blue);
}

LKColor LKColor::MixColors(const LKColor& Color2, double fFact1) const {

    double fFact2 = 1.0f - fFact1;

    uint8_t red1 = Red();
    uint8_t green1 = Green();
    uint8_t blue1 = Blue();

    uint8_t red2 = Color2.Red();
    uint8_t green2 = Color2.Green();
    uint8_t blue2 = Color2.Blue();

    int red = (int) (fFact1 * (double) red1 + fFact2 * (double) red2);
    if (red > 255) red = 255;
    int green = (int) (fFact1 * (double) green1 + fFact2 * (double) green2);
    if (green > 255) green = 255;
    int blue = (int) (fFact1 * (double) blue1 + fFact2 * (double) blue2);
    if (blue > 255) blue = 255;
    
    return LKColor((uint8_t) red, (uint8_t) green, (uint8_t) blue);
}
