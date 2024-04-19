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
		selection=image.GetImage().Size();
		return std::move(image);
	}
	virtual bool Again()const override
	{
		return active;
	}
	virtual SelfDrawingImage Action(SelfDrawingImage image)
	{
		if(SDL::Cursor::IsPressed(SDL::MouseButtonMask::Left))
		{
			auto cur_pos=image.Position().ToObject(SDL::Cursor::Position());
			cur_pos.x=std::min(std::max(cur_pos.x, 0), image.GetImage().Size().x);
			cur_pos.y=std::min(std::max(cur_pos.y, 0), image.GetImage().Size().y);
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
		return std::move(image);
	}
	virtual SelfDrawingImage Reaction(SelfDrawingImage image, const SDL::events::Event& evt)
	{
		if(evt.Type()==SDL::events::Type::Keydown)
		{
			if(evt.Keyboard().Key==SDL::Keycode::Return)
			{
				image.GetImage().Resize(selection.Size());
				for(size_t y=0; y<selection.h; ++y)
				{
					for(size_t x=0; x<selection.w; ++x)
					{
						image.GetImage().Draw(SDL::Point(x,y), image.GetImage()[selection.Position()+SDL::Point(x,y)]);
					}
				}
				image.GetImage().Confirm();
				image.AreaChanged(image.GetImage().Size());
				image.Position().ResizeObject(image.GetImage().Size());
				selection=image.GetImage().Size();
				active=false;
			}

		}
		return std::move(image);
	}
	virtual void DrawOn(SelfDrawingImage& image, SDL::Renderer& re)
	{
		re.Draw(image.Position().ToScreen(SDL::Rect(0,0, image.GetImage().Size().x, selection.y)), SDL::Color(0,0,0,100));
		re.Draw(image.Position().ToScreen(SDL::Rect(0,0, selection.x, image.GetImage().Size().y)), SDL::Color(0,0,0,100));

		re.Draw(image.Position().ToScreen(SDL::Rect(0, selection.Down(), image.GetImage().Size().x, image.GetImage().Size().y-selection.Down())), SDL::Color(0,0,0,100));
		re.Draw(image.Position().ToScreen(SDL::Rect(selection.Right(), 0, image.GetImage().Size().x-selection.Right(), image.GetImage().Size().y)), SDL::Color(0,0,0,100));
	}
};