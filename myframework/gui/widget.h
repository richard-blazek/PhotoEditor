#pragma once

class Widget
{
protected:
	Init& g;
	SDL::Rect position;
public:
	virtual void DrawOn(SDL::DrawBase& rend)=0;
	virtual bool Catch(const SDL::events::Event& evt)=0;
	Widget(Init& g, SDL::Rect position=SDL::Rect()):g(g), position(position) {}
	virtual ~Widget(){}
	SDL::Rect GetPosition()const
	{
		return position;
	}
	virtual void SetPosition(const SDL::Rect& pos)
	{
		position=pos;
	}
};