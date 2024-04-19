#pragma once

size_t DialogSelect(Init& g, const std::string& question, const std::vector<std::string>& options, uint32 button_size=400)
{
	std::vector<std::unique_ptr<Button>> buttons(options.size());
	Label q_lab(g, question, SDL::Rect(10, 10, button_size, g.TextSize("").y+20));
	uint32 pos=q_lab.GetPosition().Down()+10;
	for(size_t i=0; i<options.size(); ++i)
	{
		buttons[i]=std::make_unique<Button>(g, options[i], SDL::Rect(10, pos, q_lab.GetPosition().Size()));
		pos+=buttons[i]->GetPosition().h+10;
	}
	SDL::Window screen("", SDL::Rect(40, 40, button_size+20, pos), SDL::Window::Flags::Borderless|SDL::Window::Flags::InputGrabbed);
	SDL::Renderer rend(screen);
	for(;;)
	{
		for(auto& event:SDL::events::Handler())
		{
			if(event.Type()==SDL::events::Type::Quit)
			{
				return options.size();
			}
			for(size_t i=0; i<options.size(); ++i)
			{
				if(buttons[i]->Catch(event))
				{
					return i;
				}
			}
		}
		rend.Repaint(g.bg_color);
		q_lab.DrawOn(rend);
		for(auto& button:buttons)
		{
			button->DrawOn(rend);
		}
		rend.Show();
		SDL::Wait(50);
	}
}