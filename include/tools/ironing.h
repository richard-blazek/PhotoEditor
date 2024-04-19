#pragma once

class Ironing: public AreaChanging
{
private:
	SDL::Color AvgArea(const Image& image, SDL::Rect area)const
	{
		uint32 r=0, g=0, b=0, count=0;
		for(uint16 y=std::max(0, area.y), stop_y=std::min(image.Size().y, area.Down()); y<stop_y; ++y)
		{
			for(uint16 x=std::max(0, area.x), stop_x=std::min(area.Right(), image.Size().x); x<stop_x; ++x)
			{
				r+=image[SDL::Point(x,y)].r;
				g+=image[SDL::Point(x,y)].g;
				b+=image[SDL::Point(x,y)].b;
				++count;
			}
		}
		return SDL::Color(r/count, g/count, b/count);
	}
	SDL::Color MultiAvgArea(const Image& image, SDL::Point center, uint32 size)const
	{
        uint32 r=0, g=0, b=0;
        for(uint16 i=0; i<size; ++i)
		{
			auto col=AvgArea(image, SDL::Rect(center-SDL::Point(i,i), i*2+1, i*2+1));
			r+=col.r;
			g+=col.g;
			b+=col.b;
		}
		return SDL::Color(r/size, g/size, b/size);
	}
protected:
	std::function<Image(Image, SDL::Point)> ChangePixel=[&](Image image, SDL::Point which)
	{
		image.Draw(which, MultiAvgArea(image, which, 3));
		return std::move(image);
	};
public:
	using AreaChanging::AreaChanging;
	virtual SelfDrawingImage Action(SelfDrawingImage image)override
	{
		if(SDL::Cursor::IsPressed())
		{
			return std::move(ChangeArea(std::move(image), ChangePixel));
		}
		return std::move(image);
	}
	virtual std::string Name()const override
	{
		return "Vyhlazení";
	}
};