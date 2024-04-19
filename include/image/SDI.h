#pragma once

class SelfDrawingImage: public NonCopyable
{
private:
	Image image;
	ChangedArea area;
	Positioning<int, float> pos;
	SDL::Texture texture;
	void UpdateImage(SDL::Renderer& rend)
	{
		image.Convert(texture.Format());
		texture=image.Update(std::move(texture), rend, area.Area());
	}
public:
	SelfDrawingImage(Image img, SDL::Rect screen_area, SDL::Renderer& rend)
		:image(std::move(img)), area(), pos(image.Size(), screen_area), texture(image.MakeTexture(rend)) {}
	SelfDrawingImage(SelfDrawingImage&& init)
		:image(std::move(init.image)), area(init.area), pos(std::move(init.pos)), texture(std::move(init.texture)) {}
	SelfDrawingImage& operator=(SelfDrawingImage&& init)
	{
		image=std::move(init.image);
		area=init.area;
		pos=std::move(init.pos);
		texture=std::move(init.texture);
		return *this;
	}
	void DrawOn(SDL::Renderer& rend)
	{
		UpdateImage(rend);
		area.Clear();
		rend.Draw(texture, texture.Size(), pos.ObjectArea());
	}
	Positioning<int, float>& Position()
	{
		return pos;
	}
	Image& GetImage()
	{
		return image;
	}
	void AreaChanged(SDL::Rect new_area)
	{
		area.Add(new_area);
	}
};