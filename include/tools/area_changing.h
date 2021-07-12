#pragma once

class AreaChanging: public Tool
{
private:
    uint32 size=40;
protected:
	SelfDrawingImage ChangeArea(SelfDrawingImage image, std::function<Image(Image, SDL::Point)> changer)
	{
		auto where=SDL::Rect(image.Positioning().ToObject(SDL::Cursor::Position())-SDL::Point(size, size), size*2, size*2);
		for(uint16 y=func::Max(0, where.y); y<where.Down()&&y<image.Image().Size().y;++y)
		{
			for(uint16 x=func::Max(0, where.x); x<where.Right()&&x<image.Image().Size().x;++x)
			{
				image.Image()=func::Move(changer(func::Move(image.Image()), SDL::Point(x,y)));
			}
		}
		image.AreaChanged(where);
		return func::Move(image);
	}
public:
    using Tool::Tool;
	virtual SelfDrawingImage Enable(SelfDrawingImage image)override
	{
		SDL::Cursor::Hide();
		return func::Move(image);
	}
	virtual SelfDrawingImage Disable(SelfDrawingImage image)override
	{
		SDL::Cursor::Show();
		image.Image().Confirm();
		return func::Move(image);
	}
	virtual void DrawOn(SelfDrawingImage& image, SDL::Renderer& w)override
	{
		w.Draw(image.Positioning().ToScreen(SDL::Rect(image.Positioning().ToObject(SDL::Cursor::Position())-SDL::Point(size,size), size*2)), SDL::Color(90,90,90,100));
	}
	virtual SelfDrawingImage Reaction(SelfDrawingImage image, const SDL::events::Event& evt)override
	{
		if(evt.Type()==SDL::events::Type::MouseButtonUp&&evt.MouseButton().Button==SDL::MouseButton::Left&&!SDL::Cursor::IsPressed())
		{
			image.Image().Confirm();
		}
		else if(evt.Type()==SDL::events::Type::MouseWheel&&-evt.MouseWheel().Move.y<int32(size))
		{
			size+=evt.MouseWheel().Move.y;
		}
		return func::Move(image);
	}
};