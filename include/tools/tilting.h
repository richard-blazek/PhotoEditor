#pragma once

class Tilting: public Tool
{
public:
	using Tool::Tool;
	virtual std::string Name()const override
	{
        return "Překlopení";
	}
	virtual SelfDrawingImage Enable(SelfDrawingImage image)override
	{
		for(int row=0; row<image.Image().Size().y; ++row)
		{
			for(int col=0; col<image.Image().Size().x; ++col)
			{
				image.Image().Draw(SDL::Point(col, row), image.Image()[SDL::Point(image.Image().Size().x-col-1, row)]);
			}
		}
		image.Image().Confirm();
		image.AreaChanged(image.Image().Size());
		return func::Move(image);
	}
	virtual bool Again()const override
	{
		return false;
	}
};