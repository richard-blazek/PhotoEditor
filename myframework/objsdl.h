#pragma once

#include <tuple>
#include <string>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <chrono>
#include <thread>
#include <vector>

#include "utils/optional.h"
#include "utils/geometry.h"
#include "utils/colors.h"
#include "utils/types.h"
#include "utils/nocopy.h"
#include "utils/ref_simulator.h"

#include "objsdl/oldsdl.h"

namespace SDL
{
#include "objsdl/shapes.h"
#include "objsdl/color.h"
#include "objsdl/sdl_base.h"
#include "objsdl/decl.h"
#include "objsdl/time.h"
#include "objsdl/keycode.h"
#include "objsdl/mousebutton.h"
#include "objsdl/event.h"
#include "objsdl/keyboard.h"
#include "objsdl/drawbase.h"
#include "objsdl/window.h"
#include "objsdl/surface.h"
#include "objsdl/renderer.h"
#include "objsdl/cursor.h"
#include "objsdl/messagebox.h"
}