#pragma once

using InputDescription=std::pair<std::string, bool>;

std::pair<std::vector<std::unique_ptr<Label>>, std::vector<std::unique_ptr<TextInputBox>>> MakeDialogLabelsAndEntries(Init& g, std::vector<InputDescription> label_names, uint32 input_size)
{
	std::vector<std::unique_ptr<Label>> labels(label_names.size());
	std::vector<std::unique_ptr<TextInputBox>> entries(label_names.size());
	labels[0]=std::make_unique<Label>(g, label_names[0].first, SDL::Point(20,10));
	auto entry_pos=labels[0]->GetPosition().w;
	for(size_t i=1;i<label_names.size();++i)
	{
        labels[i]=std::make_unique<Label>(g, label_names[i].first, labels[i-1]->GetPosition().LeftDown()+SDL::Point(0,12));
        if(labels[i]->GetPosition().w>entry_pos)
		{
			entry_pos=labels[i]->GetPosition().w;
		}
	}
	entry_pos+=30;
	for(size_t i=0;i<label_names.size();++i)
	{
		entries[i]=std::make_unique<TextInputBox>(g, SDL::Rect(entry_pos, labels[i]->GetPosition().y-4, input_size, 0), label_names[i].second);
	}
	return std::move(std::make_pair(std::move(labels), std::move(entries)));
}

std::vector<std::string> Dialog(Init& g, const std::string& title, const std::vector<InputDescription>& label_names, const std::string& confirm, uint32 input_size=250)
{
	if(label_names.size()==0)
	{
		throw std::invalid_argument("gui::Dialog requires at least 1 label name");
	}
	auto labels_entries=MakeDialogLabelsAndEntries(g, label_names, input_size);
	auto buttonsize=g.TextSize(confirm)+SDL::Point(100,20);
	SDL::Window screen(title, SDL::Rect(40, 40, labels_entries.second[0]->GetPosition().x+input_size+30, labels_entries.second.back()->GetPosition().Down()+buttonsize.y+15));
	SDL::Renderer rend(screen);
	Button submit(g, confirm, SDL::Rect((screen.Size().x-buttonsize.x)/2, labels_entries.second.back()->GetPosition().Down()+5, buttonsize));
	SDL::TextInput::Start();
	for(;;)
	{
		for(auto& event:SDL::events::Handler())
		{
			if(event.Type()==SDL::events::Type::Quit)
			{
				return std::vector<std::string>();
			}
			else
			{
				for(auto& entry:labels_entries.second)
				{
					entry->Catch(event);
				}
				if(submit.Catch(event))
				{
					std::vector<std::string> result(label_names.size());
					for(size_t i=0; i<result.size(); ++i)
					{
						result[i]=labels_entries.second[i]->GetText();
					}
					return std::move(result);
				}
			}
		}
		rend.Repaint(g.bg_color);
		for(size_t i=0; i<label_names.size(); ++i)
		{
			labels_entries.first[i]->DrawOn(rend);
			labels_entries.second[i]->DrawOn(rend);
		}
		submit.DrawOn(rend);
		rend.Show();
		SDL::Wait(50);
	}
}