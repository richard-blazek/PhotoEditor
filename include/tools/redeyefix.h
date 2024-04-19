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
		return std::move(image);
	};
public:
	using Ironing::Ironing;
	virtual SelfDrawingImage Action(SelfDrawingImage image)override
	{
		if(SDL::Cursor::IsPressed())
		{
			image=std::move(ChangeArea(std::move(image), ChangePixel));
			image.GetImage().Confirm();
			image=std::move(ChangeArea(std::move(image), Ironing::ChangePixel));
			active=false;
		}
		return std::move(image);
	}
	virtual SelfDrawingImage Enable(SelfDrawingImage image)override
	{
		active=true;
		return Ironing::Enable(std::move(image));
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