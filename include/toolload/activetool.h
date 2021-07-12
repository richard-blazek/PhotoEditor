#pragma once

class ActiveTool
{
private:
	Tool* tool;
public:
	ActiveTool(Tool* init):tool(init){}
	Tool* operator->()
	{
		return tool;
	}
	SelfDrawingImage Set(const ActiveTool& init, SelfDrawingImage image)
	{
		image=tool->Disable(func::Move(image));
		tool=init.tool;
		image=tool->Enable(func::Move(image));
		return image;
	}
};