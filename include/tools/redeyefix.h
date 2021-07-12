#pragma once

class RedEyeFix: public Ironing
{
private:
	bool active=true;
	static bool IsRed(colors::HSL col)
	{
		return col.l<180&&col.l>80&&col.s>60&&(col.h+15)%256<30;
	}
protected:
	std::function<Image(Image, SDL::Point)> ChangePixel=[&](Image image, SDL::Point which)
	{
		if(IsRed(image[which]))
		{
			image.Draw(which, SDL::Color(80,80,80));
		}
		return func::Move(image);
	};
public:
	using Ironing::Ironing;
	virtual SelfDrawingImage Action(SelfDrawingImage image)override
	{
		if(SDL::Cursor::IsPressed())
		{
			image=func::Move(ChangeArea(func::Move(image), ChangePixel));
			image.Image().Confirm();
			image=func::Move(ChangeArea(func::Move(image), Ironing::ChangePixel));
			active=false;
		}
		return func::Move(image);
	}
	virtual SelfDrawingImage Enable(SelfDrawingImage image)override
	{
		active=true;
		return Ironing::Enable(func::Move(image));
	}
	virtual bool Again()const override
	{
		return active;
	}
	virtual std::string Name()const override
	{
		return "Červené oči";
	}
};