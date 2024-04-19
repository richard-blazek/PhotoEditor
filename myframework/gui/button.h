#pragma once

class Button: public Label
{
public:
	enum class State {Normal, MouseOn, MouseDown};
private:
	State state=State::Normal;
public:
	using Label::Label;
	virtual void DrawOn(SDL::DrawBase& rend)override
	{
		rend.Draw(position, state==State::Normal?g.button_color:state==State::MouseOn?g.button_hover_color:g.button_clicked_color);
		rend.DrawBorder(position, g.border_color);
		Label::DrawOn(rend);
	}
	bool Catch(const SDL::events::Event& evt)
	{
		if(state==State::MouseOn&&evt.Type()==SDL::events::Type::MouseButtonDown)
		{
			state=State::MouseDown;
		}
		if(state==State::MouseDown&&evt.Type()==SDL::events::Type::MouseButtonUp)
		{
			state=State::MouseOn;
			return true;
		}
		if(evt.Type()==SDL::events::Type::MouseMotion)
		{
			if(state==State::Normal&&position.Encloses(evt.MouseMotion().Absolute))
			{
				state=State::MouseOn;
			}
			if(state!=State::Normal&&!position.Encloses(evt.MouseMotion().Absolute))
			{
				state=State::Normal;
			}
		}
		return false;
	}
};