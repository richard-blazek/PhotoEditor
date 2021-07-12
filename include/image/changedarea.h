#pragma once

class ChangedArea
{
private:
	SDL::Rect area;
public:
    ChangedArea():area(){}
    void Add(SDL::Rect new_area)
    {
    	area=area+new_area;
    }
    void Clear()
    {
    	area=SDL::Rect();
    }
    SDL::Rect Area()
    {
    	return area;
    }
};