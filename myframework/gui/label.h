#pragma once

class Label: public Widget
{
protected:
	std::string text;
public:
	Label(Init& g, const std::string& text, const SDL::Point& position)
		:Widget(g, SDL::Rect(position, g.TextSize(text))), text(text) {}
	Label(Init& g, const std::string& text, const SDL::Rect& position)
		:Widget(g, position), text(text) {}
	std::string GetText()const
	{
		return text;
	}
	void SetText(const std::string& new_text)
	{
		text=new_text;
	}
	void RecalculateSize()
	{
		Widget::position=SDL::Rect(position.Position(), g.TextSize(text));
	}
	virtual void DrawOn(SDL::DrawBase& rend)override
	{
		g.Draw(rend, text, g.text_color, position);
	}
	virtual bool Catch(const SDL::events::Event& evt)override
	{
		return false;
	}
};