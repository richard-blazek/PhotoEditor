#pragma once

class Tool
{
public:
	Tool(){}
	virtual std::string Name()const=0;
	virtual SelfDrawingImage Reaction(SelfDrawingImage image, const SDL::events::Event& evt)
	{
		return func::Move(image);
	}
	virtual SelfDrawingImage Action(SelfDrawingImage image)
	{
		return func::Move(image);
	}
	virtual SelfDrawingImage Enable(SelfDrawingImage image)
	{
		return func::Move(image);
	}
	virtual SelfDrawingImage Disable(SelfDrawingImage image)
	{
		return func::Move(image);
	}
	virtual void DrawOn(SelfDrawingImage& image, SDL::Renderer& w){}
	virtual bool Again()const
	{
		return true;
	}
	virtual ~Tool() {}
};