#pragma once

class Cropping: public Tool
{
private:
	SDL::Rect selection;
	bool active;
public:
	Cropping():selection(), active(true){}
	virtual std::string Name()const override
	{
		return "Oříznutí";
	}
	virtual SelfDrawingImage Enable(SelfDrawingImage image)override
	{
		active=true;
		selection=image.Image().Size();
		return func::Move(image);
	}
	virtual bool Again()const override
	{
		return active;
	}
	virtual SelfDrawingImage Action(SelfDrawingImage image)
	{
		if(SDL::Cursor::IsPressed(SDL::MouseButtonMask::Left))
		{
			auto cur_pos=image.Positioning().ToObject(SDL::Cursor::Position());
			cur_pos.x=func::Limit(cur_pos.x, 0, image.Image().Size().x);
			cur_pos.y=func::Limit(cur_pos.y, 0, image.Image().Size().y);
            if(cur_pos.x<selection.Center().x)
			{
				selection.w-=(cur_pos.x-selection.x);
				selection.x=cur_pos.x;
			}
			else
			{
				selection.w=cur_pos.x-selection.x;
			}
			if(cur_pos.y<selection.Center().y)
			{
				selection.h-=(cur_pos.y-selection.y);
				selection.y=cur_pos.y;
			}
			else
			{
				selection.h=cur_pos.y-selection.y;
			}
		}
		return func::Move(image);
	}
	virtual SelfDrawingImage Reaction(SelfDrawingImage image, const SDL::events::Event& evt)
	{
		if(evt.Type()==SDL::events::Type::Keydown)
		{
			if(evt.Keyboard().Key==SDL::Keycode::Return)
			{
				image.Image().Resize(selection.Size());
				for(size_t y=0; y<selection.h; ++y)
				{
					for(size_t x=0; x<selection.w; ++x)
					{
						image.Image().Draw(SDL::Point(x,y), image.Image()[selection.Position()+SDL::Point(x,y)]);
					}
				}
				image.Image().Confirm();
				image.AreaChanged(image.Image().Size());
				image.Positioning().ResizeObject(image.Image().Size());
				selection=image.Image().Size();
				active=false;
			}

		}
		return func::Move(image);
	}
	virtual void DrawOn(SelfDrawingImage& image, SDL::Renderer& re)
	{
		re.Draw(image.Positioning().ToScreen(SDL::Rect(0,0, image.Image().Size().x, selection.y)), SDL::Color(0,0,0,100));
		re.Draw(image.Positioning().ToScreen(SDL::Rect(0,0, selection.x, image.Image().Size().y)), SDL::Color(0,0,0,100));

		re.Draw(image.Positioning().ToScreen(SDL::Rect(0, selection.Down(), image.Image().Size().x, image.Image().Size().y-selection.Down())), SDL::Color(0,0,0,100));
		re.Draw(image.Positioning().ToScreen(SDL::Rect(selection.Right(), 0, image.Image().Size().x-selection.Right(), image.Image().Size().y)), SDL::Color(0,0,0,100));
	}
};