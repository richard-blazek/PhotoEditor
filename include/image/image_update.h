#pragma once

bool Writable(SDL::Texture& src, const SDL::Surface& img)
{
	return src.IsOpened()&&img.Size()==src.Size()&&img.Format()==src.Format();
}

SDL::Texture UpdateTexture(SDL::Texture src, const SDL::Surface& img, SDL::Renderer& rend, SDL::Rect where)
{
	if(!Writable(src, img))
	{
		src=rend.MakeTexture(img);
	}
	else if(!where.IsEmpty())
	{
		src.Update(img, where);
	}
	return std::move(src);
}