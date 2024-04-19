#pragma once

class DrawBase
{
public:
	virtual void Draw(Surface& surface, Rect source, Rect destination)=0;
	virtual void Draw(const Point& point, const Color& col)=0;
	virtual void Draw(const Line& line, const Color& col)=0;
	virtual void Draw(const Rect& rectangle, const Color& col)=0;
	virtual void DrawBorder(const Rect& rectangle, const Color& col)=0;
	virtual void Repaint(const Color& col)=0;
	virtual ~DrawBase(){}
	//Draw Circle---------------------------------------------------------------
	void DrawBorder(const Circle& circle, const Color& color)
	{
		constexpr float angle_stepsize=0.001;
		float angle=0;
		while(angle<2*pi)
		{
			Draw(circle.center+Point(SDL_cos(angle), SDL_sin(angle))*circle.radius, color);
			angle+=angle_stepsize;
		}
	}
	void Draw(const Circle& circle, const Color& color)
	{
		for(int32 y=-circle.radius; y<=circle.radius; ++y)
		{
			int32 width=sqrt(circle.radius*circle.radius-y*y);
			Draw(Rect(circle.center.x-width, circle.center.y+y, 2*width, 1), color);
		}
	}
	//Draw text-----------------------------------------------------------------
	void Draw(Font& font, const std::string& u8text, const Color& textcolor, Point dst);
	void Draw(Font& font, const std::u16string& u16text, const Color& textcolor, Point dst);
	void Draw(Font& font, char16_t character, const Color& textcolor, Point dst);

	void Draw(Font& font, const std::string& u8text, const Color& textcolor, Point dst, const Color& backgroundcolor);
	void Draw(Font& font, const std::u16string& u16text, const Color& textcolor, Point dst, const Color& backgroundcolor);
	void Draw(Font& font, char16_t character, const Color& textcolor, Point dst, const Color& backgroundcolor);

	void DrawFast(Font& font, const std::string& u8text, const Color& textcolor, Point dst);
	void DrawFast(Font& font, const std::u16string& u16text, const Color& textcolor, Point dst);
	void DrawFast(Font& font, char16_t character, const Color& textcolor, Point dst);

	///Centred text-----------------------------------------------------------------------------------------------
	void Draw(Font& font, const std::string& u8text, const Color& textcolor, Rect dst);
	void Draw(Font& font, const std::u16string& u16text, const Color& textcolor, Rect dst);
	void Draw(Font& font, char16_t character, const Color& textcolor, Rect dst);

	void Draw(Font& font, const std::string& u8text, const Color& textcolor, Rect dst, const Color& backgroundcolor);
	void Draw(Font& font, const std::u16string& u16text, const Color& textcolor, Rect dst, const Color& backgroundcolor);
	void Draw(Font& font, char16_t character, const Color& textcolor, Rect dst, const Color& backgroundcolor);

	void DrawFast(Font& font, const std::string& u8text, const Color& textcolor, Rect dst);
	void DrawFast(Font& font, const std::u16string& u16text, const Color& textcolor, Rect dst);
	void DrawFast(Font& font, char16_t character, const Color& textcolor, Rect dst);
};