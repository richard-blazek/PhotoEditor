#pragma once

class Nothing: public Tool
{
public:
	using Tool::Tool;
	virtual std::string Name()const override
	{
		return "Nic";
	}
	virtual SelfDrawingImage Reaction(SelfDrawingImage image, const SDL::events::Event& evt)override
	{
		if(evt.Type()==SDL::events::Type::MouseMotion&&(SDL::Cursor::PressedButtons()&SDL::MouseButtonMask::Left)!=SDL::MouseButtonMask::Nothing)
		{
			image.Position().Displace(evt.MouseMotion().Relative);
		}
		else if(evt.Type()==SDL::events::Type::MouseWheel)
		{
			image.Position().ChangeZoom(evt.MouseWheel().Move.y>0?1.2:1.0/1.2, SDL::Cursor::Position(), 0.1, 80.0);
		}
		return std::move(image);
	}
};