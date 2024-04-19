#pragma once

void Wait(uint32 miliseconds)noexcept
{
    SDL_Delay(miliseconds);
}
uint32 RunTimeMs()noexcept
{
    return SDL_GetTicks();
}
