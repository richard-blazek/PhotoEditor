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
		for(int row=0; row<image.GetImage().Size().y; ++row)
		{
			for(int col=0; col<image.GetImage().Size().x; ++col)
			{
				image.GetImage().Draw(SDL::Point(col, row), image.GetImage()[SDL::Point(image.GetImage().Size().x-col-1, row)]);
			}
		}
		image.GetImage().Confirm();
		image.AreaChanged(image.GetImage().Size());
		return std::move(image);
	}
	virtual bool Again()const override
	{
		return false;
	}
};