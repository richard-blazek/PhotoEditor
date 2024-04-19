#pragma once

class Text: public Tool
{
private:
	uint32 size;
	SDL::Font font;
	gui::Init& g;
	std::string text;
	bool active;
	const std::string font_path;
public:
	virtual std::string Name()const override
	{
		return "Vložení textu";
	}
    Text(gui::Init& g, std::string font_path)
		:size(70), font(font_path, size), g(g), text(), active(true), font_path(font_path) {}
	virtual SelfDrawingImage Reaction(SelfDrawingImage image, const SDL::events::Event& evt)override
	{
		if(evt.Type()==SDL::events::Type::MouseButtonDown)
		{
			auto mouse=evt.MouseButton();
			if(mouse.Button==SDL::MouseButton::Left)
			{
                image.GetImage().Draw(font, text, SDL::Color(0,0,0), image.Position().ToObject(mouse.Position)-font.TextSize(text)/2);
                image.GetImage().Confirm();
                image.AreaChanged(SDL::Rect(image.Position().ToObject(mouse.Position)-font.TextSize(text)/2, font.TextSize(text)));
                active=false;
			}
		}
		if(evt.Type()==SDL::events::Type::MouseWheel)
		{
			size+=evt.MouseWheel().Move.y;
			font=SDL::Font(font_path, size);
		}
		return std::move(image);
	}
	virtual void DrawOn(SelfDrawingImage& image, SDL::Renderer& w)override
	{
		auto textimg=font.Render(text, SDL::Color(0,160,0));
		w.Draw(textimg, textimg.Size(), image.Position().ToScreen(SDL::Rect(textimg.Size()).WithCenter(image.Position().ToObject(SDL::Cursor::Position()))));
	}
	virtual bool Again()const override
	{
		return active;
	}
	virtual SelfDrawingImage Enable(SelfDrawingImage image)override
	{
		auto answer=gui::Dialog(g, "Vkládání textu", {{"Text ", false}}, "Vložit", 250);
		text=answer[0];
		active=true;
		return std::move(image);
	}
};