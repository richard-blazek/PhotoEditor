#pragma once

class SelfDrawingImage: public NonCopyable
{
private:
	Image image;
	ChangedArea area;
	Positioning<int32, float> pos;
	SDL::Texture texture;
	void UpdateImage(SDL::Renderer& rend)
	{
		image.Convert(texture.Format());
		texture=image.Update(func::Move(texture), rend, area.Area());
	}
public:
	SelfDrawingImage(Image img, SDL::Rect screen_area, SDL::Renderer& rend)
		:image(func::Move(img)), area(), pos(image.Size(), screen_area), texture(image.MakeTexture(rend)) {}
	SelfDrawingImage(SelfDrawingImage&& init)
		:image(func::Move(init.image)), area(init.area), pos(func::Move(init.pos)), texture(func::Move(init.texture)) {}
	SelfDrawingImage& operator=(SelfDrawingImage&& init)
	{
		image=func::Move(init.image);
		area=init.area;
		pos=func::Move(init.pos);
		texture=func::Move(init.texture);
		return *this;
	}
	void DrawOn(SDL::Renderer& rend)
	{
		UpdateImage(rend);
		area.Clear();
		rend.Draw(texture, texture.Size(), pos.ObjectArea());
	}
	Positioning<int32, float>& Positioning()
	{
		return pos;
	}
	Image& Image()
	{
		return image;
	}
	void AreaChanged(SDL::Rect new_area)
	{
		area.Add(new_area);
	}
};