#include <iostream>
#include <iomanip>
#include <vector>
#include <tuple>
#include <string>
#include <memory>
#include "myframework/objsdl.h"
#include "myframework/utils/positioning.h"

#include "include/menu.h"
#include "include/files/files.h"
#include "include/image/image_update.h"
#include "include/image/image.h"
#include "include/image/changedarea.h"
#include "include/image/SDI.h"

#include "include/tools/tool.h"
#include "include/tools/area_changing.h"
#include "include/tools/nothing.h"
#include "include/tools/ironing.h"
#include "include/tools/tilting.h"
#include "include/tools/turn.h"
#include "include/tools/cropping.h"
#include "include/tools/redeyefix.h"

#include "include/toolload/activetool.h"
#include "include/toolload/toollist.h"
#include "include/toolload/actions.h"
#include "include/loader.h"
#include "include/output.h"

void Main(fs::path src)
{
	SDL::Init _;
	SDL::Font menu_font("font.ttf", 32);
	Loader load(src);
	Menu menu({"Upravit", "Zpět", "Uložit", "Smazat", "Zavřít"});
	Output out(SDL::Point(900,650), menu_font.TextSize("").y+10);
	auto sdi=out.MakeSDI(load.Load());
	Actions options={
		new Nothing(), new Cropping(), new Turn(),
		new RedEyeFix(), new Ironing(), new Tilting()
	};
	bool repeat=true;
	while(repeat)
	{
		for(auto& evt:SDL::events::Handler())
		{
			if(evt.Type()==SDL::events::Type::WindowSizeChanged)
			{
				sdi.Position().ResizeArea(out.ScreenSize());
			}
			else if(evt.Type()==SDL::events::Type::Quit)
			{
				repeat=false;
			}
			else if(evt.Type()==SDL::events::Type::Keydown)
			{
				auto key=evt.Keyboard();
				if(key==SDL::Keycode::Left)
				{
					load=load.Moved(-1);
					sdi=options.Select(0, std::move(out.MakeSDI(load.Load())));
				}
				else if(key==SDL::Keycode::Right)
				{
					load=load.Moved(1);
					sdi=options.Select(0, std::move(out.MakeSDI(load.Load())));
				}
			}
			else if(evt.Type()==SDL::events::Type::MouseButtonDown)
			{
				try
				{
					switch(menu.ChosenButton(SDL::Rect(0,0, out.ScreenSize().x, out.MenuHeight()), evt.MouseButton()))
					{
					case 0:
						sdi=options.Select(out.Dialog("Co chceš použít k úpravě obrázku?", options.Options()), std::move(sdi));
						break;
					case 1:
						sdi=options.Select(0, std::move(out.MakeSDI(load.Load())));
						break;
					case 2:
						load.Save(sdi.GetImage());
						break;
					case 3:
						if(out.Dialog("Opravdu chceš smazat tento soubor?", {"Ano, smazat", "Ne, nemazat"})==0)
						{
							load.Delete();
							sdi=options.Select(0, std::move(out.MakeSDI(load.Load())));
						}
						break;
					case 4:
						repeat=false;
						break;
					}
				}
				catch(SDL::Error& err)
				{
					SDL::Message("Chyba programy", "Jejda! Při otevírání souboru "+load.Path().substr(load.Path().find_last_of("/\\")+1)+" se něco pokazilo.");
					repeat=false;
				}
			}
			sdi=options->Reaction(std::move(sdi), std::move(evt));
		}
		sdi=options->Action(std::move(sdi));
		if(!options->Again())
		{
			sdi=options.Select(0, std::move(sdi));
		}
		out.Draw(sdi, options, menu, menu_font);
		SDL::Wait(20);
	}
}
int main(int argc, const char* argv[])try
{
	if(argc<2)
	{
		SDL::Message("Error", "No file");
		return 0;
	}
	Main(fs::absolute(fs::path(std::string(argv[1]))));
	return 0;
}
catch(std::exception& exc)
{
	SDL::Message("Chyba", "Stala se nějaká chyba. \n\nChybová hláška: '"+std::string(exc.what())+"'");
}