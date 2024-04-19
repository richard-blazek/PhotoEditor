#pragma once

class DrawBase
{
public:
	virtual void Draw(Surface& surface, Rect source, Rect destination)=0;
	virtual void Draw(const Point& point, const Color& col)=0;
	virtual void Draw(const Rect& rectangle, const Color& col)=0;
	virtual void DrawBorder(const Rect& rectangle, const Color& col)=0;
	virtual void Repaint(const Color& col)=0;
	virtual ~DrawBase(){}
	//Draw text-----------------------------------------------------------------
	void Draw(Font& font, const std::string& u8text, const Color& textcolor, Point dst);
	void Draw(Font& font, const std::string& u8text, const Color& textcolor, Point dst, const Color& backgroundcolor);

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