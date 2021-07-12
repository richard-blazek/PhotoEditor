#pragma once

class Turn: public Tool
{
public:
	using Tool::Tool;
	virtual std::string Name()const override
	{
		return "Otočení";
	}
	virtual SelfDrawingImage Enable(SelfDrawingImage image)override
	{
		image.Image().Resize(~image.Image().Size());
		for(int y=0; y<image.Image().Size().y; ++y)
		{
			for(int x=0; x<image.Image().Size().x; ++x)
			{
				image.Image().Draw(SDL::Point(image.Image().Size().y-y-1, x), image.Image()[SDL::Point(x, y)]);
			}
		}
		image.Image().Confirm();
		image.AreaChanged(image.Image().Size());
		image.Positioning().ResizeObject(image.Image().Size());
		return func::Move(image);
	}
	virtual bool Again()const override
	{
		return false;
	}
};