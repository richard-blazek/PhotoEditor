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
		image.GetImage().Resize(~image.GetImage().Size());
		for(int y=0; y<image.GetImage().Size().y; ++y)
		{
			for(int x=0; x<image.GetImage().Size().x; ++x)
			{
				image.GetImage().Draw(SDL::Point(image.GetImage().Size().y-y-1, x), image.GetImage()[SDL::Point(x, y)]);
			}
		}
		image.GetImage().Confirm();
		image.AreaChanged(image.GetImage().Size());
		image.Position().ResizeObject(image.GetImage().Size());
		return std::move(image);
	}
	virtual bool Again()const override
	{
		return false;
	}
};