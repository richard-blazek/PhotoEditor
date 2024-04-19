#pragma once

void Message(const std::string& title, const std::string& message)
{
	Error::Condition(SDL_ShowSimpleMessageBox(0, title.c_str(), message.c_str(), 0)<0);
}

