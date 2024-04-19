#pragma once

class AreaChanging: public Tool
{
private:
    uint32 size=40;
protected:
	SelfDrawingImage ChangeArea(SelfDrawingImage image, std::function<Image(Image, SDL::Point)> changer)
	{
		auto where=SDL::Rect(image.Position().ToObject(SDL::Cursor::Position())-SDL::Point(size, size), size*2, size*2);
		for(uint16 y=std::max(0, where.y); y<where.Down()&&y<image.GetImage().Size().y;++y)
		{
			for(uint16 x=std::max(0, where.x); x<where.Right()&&x<image.GetImage().Size().x;++x)
			{
				image.GetImage()=std::move(changer(std::move(image.GetImage()), SDL::Point(x,y)));
			}
		}
		image.AreaChanged(where);
		return std::move(image);
	}
public:
    using Tool::Tool;
	virtual SelfDrawingImage Enable(SelfDrawingImage image)override
	{
		SDL::Cursor::Hide();
		return std::move(image);
	}
	virtual SelfDrawingImage Disable(SelfDrawingImage image)override
	{
		SDL::Cursor::Show();
		image.GetImage().Confirm();
		return std::move(image);
	}
	virtual void DrawOn(SelfDrawingImage& image, SDL::Renderer& w)override
	{
		w.Draw(image.Position().ToScreen(SDL::Rect(image.Position().ToObject(SDL::Cursor::Position())-SDL::Point(size,size), size*2)), SDL::Color(90,90,90,100));
	}
	virtual SelfDrawingImage Reaction(SelfDrawingImage image, const SDL::events::Event& evt)override
	{
		if(evt.Type()==SDL::events::Type::MouseButtonUp&&evt.MouseButton().Button==SDL::MouseButton::Left&&!SDL::Cursor::IsPressed())
		{
			image.GetImage().Confirm();
		}
		else if(evt.Type()==SDL::events::Type::MouseWheel&&-evt.MouseWheel().Move.y<int(size))
		{
			size+=evt.MouseWheel().Move.y;
		}
		return std::move(image);
	}
};