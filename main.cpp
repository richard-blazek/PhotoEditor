#include <iostream>
#include <iomanip>
#include <vector>
#include <tuple>
#include <string>
#include <memory>
#include "myframework/gui.h"
#include "myframework/utils/func.h"
#include "myframework/utils/chrono.h"
#include "myframework/utils/encoding.h"
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
#include "include/tools/text.h"
#include "include/tools/redeyefix.h"

#include "include/toolload/activetool.h"
#include "include/toolload/toollist.h"
#include "include/toolload/actions.h"
#include "include/loader.h"
#include "include/output.h"

using namespace std::chrono;

void Main(Path program, Path src)
{
	gui::Init i(program.Parent()/"font.ttf", 16);
	SDL::Font menu_font(program.Parent()/"font.ttf", 32);
	Loader load(src);
	Menu menu({"Upravit", "Zpět", "Uložit", "Smazat", "Zavřít"});
	Output out(SDL::Point(900,650), menu_font.TextSize("").y+10);
	auto sdi=out.MakeSDI(load.Load());
	Actions options={
		new Nothing(), new Cropping(), new Turn(), new Text(i, program.Parent()/"font.ttf"), new RedEyeFix(), new Ironing(), new Tilting()
	};
	LoopTime loop;
	bool repeat=true;
	while(repeat)
	{
		for(auto& evt:SDL::events::Handler())
		{
			if(evt.Type()==SDL::events::Type::WindowSizeChanged)
			{
				sdi.Positioning().ResizeArea(out.ScreenSize());
			}
			else if(evt.Type()==SDL::events::Type::Quit)
			{
				repeat=false;
			}
			else if(evt.Type()==SDL::events::Type::Keydown)
			{
				auto key=evt.Keyboard();
				if(key.Code==SDL::Scancode::Left)
				{
					load=load.Moved(-1);
					sdi=options.Select(0, func::Move(out.MakeSDI(load.Load())));
				}
				else if(key.Code==SDL::Scancode::Right)
				{
					load=load.Moved(1);
					sdi=options.Select(0, func::Move(out.MakeSDI(load.Load())));
				}
			}
			else if(evt.Type()==SDL::events::Type::MouseButtonDown)
			{
				try
				{
					switch(menu.ChosenButton(SDL::Rect(0,0, out.ScreenSize().x, out.MenuHeight()), evt.MouseButton().Position))
					{
					case 0:
						sdi=options.Select(gui::DialogSelect(i, "Co chceš použít k úpravě obrázku?", options.Options()), func::Move(sdi));
						break;
					case 1:
						sdi=options.Select(0, func::Move(out.MakeSDI(load.Load())));
						break;
					case 2:
						load.Save(sdi.Image());
						break;
					case 3:
						if(gui::DialogSelect(i, "Opravdu chceš smazat tento soubor?", {"Ano, smazat", "Ne, nemazat"})==0)
						{
							load.Delete();
							sdi=options.Select(0, func::Move(out.MakeSDI(load.Load())));
						}
						break;
					case 4:
						repeat=false;
						break;
					}
				}
				catch(SDL::Error& err)
				{
					gui::DialogSelect(i, "Jejda! Při otevírání souboru "+load.Path().substr(load.Path().find_last_of("/\\")+1)+" se něco pokazilo.", {"Ukončit program"}, 800);
					repeat=false;
				}
			}
			sdi=options->Reaction(func::Move(sdi), func::Move(evt));
		}
		sdi=options->Action(func::Move(sdi));
		if(!options->Again())
		{
			sdi=options.Select(0, func::Move(sdi));
		}
		out.Draw(sdi, options, menu, menu_font);
		loop.NextLoop(30ms);
	}
}
int main(int argc, const char* argv[])try
{
	if(argc<2)
	{
		SDL::MessageBox::Show("Error", "No file");
		return 0;
	}
	Main(Path(argv[0]), Path(argv[1]));
	return 0;
}
catch(std::exception& exc)
{
	SDL::MessageBox::Show("Chyba", "Stala se nějaká chyba. \n\nChybová hláška: '"+std::string(exc.what())+"'");
}