#pragma once

#include "types.h"

namespace colors
{
    struct RGB
    {
        uint8 r=0, g=0, b=0;
        constexpr RGB()=default;
        constexpr RGB(uint8 r, uint8 g, uint8 b):r(r), g(g), b(b) {}
		constexpr uint16 Brightness()const
		{
			return uint16(r)+g+b;
		}
		constexpr bool operator==(const RGB& second)const
		{
			return r==second.r&&g==second.g&&b==second.b;
		}
		constexpr bool operator!=(const RGB& second)const
		{
			return r!=second.r||g!=second.g||b!=second.b;
		}
		constexpr RGB operator-(const RGB& second)const
		{
			return RGB(r-second.r, g-second.g, b-second.b);
		}
    };
    struct RGBA: public RGB
    {
		uint8 a=255;
        constexpr RGBA()=default;
        constexpr RGBA(uint8 r, uint8 g, uint8 b, uint8 a=255):RGB(r,g,b), a(a) {}
        constexpr RGBA(RGB rgb):RGBA(rgb.r, rgb.g, rgb.b) {}
		constexpr bool operator==(const RGBA& second)const
		{
			return RGB::operator==(second)&&a==second.a;
		}
		constexpr bool operator!=(const RGBA& second)const
		{
			return RGB::operator!=(second)||a!=second.a;
		}
    };
    struct HSL
    {
        uint8 h=0, s=0, l=0;
        constexpr HSL()=default;
        constexpr HSL(uint8 h, uint8 s, uint8 l):h(h), s(s), l(l) {}
        constexpr HSL(RGB rgb)
        {
            uint8 max=std::max(rgb.r, std::max(rgb.g, rgb.b));
            uint8 min=std::min(rgb.r, std::min(rgb.g, rgb.b));
            if(max==min)
			{
				h=0;
			}
            else if(max==rgb.r&&rgb.g>=rgb.b)
			{
                h=double(rgb.g-rgb.b)/(max-min)*256/6;
			}
			else if(max==rgb.r&&rgb.g<rgb.b)
			{
				h=double(rgb.g-rgb.b)/(max-min)*256/6+256;
			}
			else if(max==rgb.g)
			{
				h=double(rgb.b-rgb.r)/(max-min)*256/6+256.0/3;
			}
			else
			{
				h=double(rgb.r-rgb.g)/(max-min)*256/6+512.0/3;
			}
			l=(max+min)/2;
			s=(l==0?0:l<=128?(max-min)*l/2:128*(max-min)/(256-l));
        }
		constexpr bool operator==(const HSL& second)const
		{
			return h==second.h&&s==second.s&&l==second.l;
		}
		constexpr bool operator!=(const HSL& second)const
		{
			return h!=second.h||s!=second.s||l!=second.l;
		}
    };
    struct LYG
    {
    	uint8 l=0, y=0, g=0;
    	constexpr LYG()=default;
        constexpr LYG(uint8 l, uint8 y, uint8 g):l(l), y(y), g(g) {}
        constexpr LYG(RGB rgb):l((rgb.r+rgb.g+rgb.b)/3)
        {
        	y=(l>0?255*(rgb.r+rgb.g)/l:0);
        	g=(y>0?255*rgb.g/y:0);
        }
        constexpr operator RGB()const
        {
        	return RGB(3*l*y*(255-g)/255/255, 3*l*y*g, 3*l*(255-y)/255);
        }
    };
}