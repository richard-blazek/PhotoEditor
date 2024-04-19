#pragma once

class Output
{
private:
	SDL::Window screen;
	SDL::Renderer rend;
	int menu_height;

	int MakeDialog(const char *message, const char *options)
	{
		int btns_len = 1, options_len;
		for (options_len = 0; options[options_len] != 0; ++options_len)
		{
			btns_len += options[options_len] == '|';
		}
		char *buffer = (char*)malloc(options_len);
		strcpy(buffer, options);

		SDL_MessageBoxButtonData *btns = (SDL_MessageBoxButtonData*)malloc(sizeof(SDL_MessageBoxButtonData) * btns_len);
		char *buffer_ptr = buffer;
		for (int i = 0; i < btns_len; ++i)
		{
			btns[i].buttonid = i;
			btns[i].flags = 0;
			btns[i].text = buffer_ptr;
			if (i != btns_len - 1)
			{
				buffer_ptr = strchr(buffer_ptr, '|') + 1;
				buffer_ptr[-1] = '\0';
			}
		}

		SDL_MessageBoxData box;
		box.buttons = btns;
		box.colorScheme = 0;
		box.flags = 0;
		box.message = message;
		box.numbuttons = btns_len;
		box.title = message;
		box.window = 0;
		
		int selected = 0;
		SDL_ShowMessageBox(&box, &selected);
		free(buffer);
		free(btns);

		return selected >= 0 && selected < options_len ? selected : 0;
	}
public:
	Output(SDL::Point size, int menu_height)
		:screen("", SDL::Rect(40, 40, size), SDL::Window::Flags::Maximized|SDL::Window::Flags::Borderless), rend(screen), menu_height(menu_height)
	{
		rend.SetBlendMode(SDL::BlendMode::Blend);
	}
	void Draw(SelfDrawingImage& sdi, Actions& tool, Menu menu, SDL::Font& menu_font)
	{
		rend.Repaint(SDL::Color(30,200,0));
		rend.SetViewport(SDL::Rect(0, menu_height, rend.Size()-SDL::Point(0, menu_height)));
		sdi.DrawOn(rend);
		tool->DrawOn(sdi, rend);
		rend.SetViewportToDefault();
		menu.DrawOn(rend, SDL::Rect(0,0, rend.Size().x, menu_height), menu_font, SDL::Color(255,255,255), 4, SDL::Color(0,0,0));
		rend.Show();
	}
	SDL::Point ScreenSize()
	{
		return screen.Size()-SDL::Point(0, menu_height);
	}
	int MenuHeight()
	{
		return menu_height;
	}
	SelfDrawingImage MakeSDI(Image img)
	{
		return std::move(SelfDrawingImage(std::move(img), SDL::Rect(0, menu_height, ScreenSize()), rend));
	}

	int Dialog(std::string message, std::vector<std::string> options)
	{
		std::string cat;
		for (int i = 0; i < options.size(); ++i)
		{
			if (i > 0) cat.push_back('|');
			cat.append(options[i]);
		}
		return MakeDialog(message.c_str(), cat.c_str());
	}
};