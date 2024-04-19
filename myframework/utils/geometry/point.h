#pragma once

#include "base.h"

namespace geometry
{
	namespace coordinates
	{
		template<typename typ>
		struct Cartesian
		{
			typ x=0;
			typ y=0;
			constexpr Cartesian()=default;
			constexpr Cartesian(typ xpos, typ ypos)
				:x(xpos), y(ypos) {}

			template<typename T>
			constexpr Cartesian(const Cartesian<T>& second)
				:Cartesian(T(second.x), T(second.y)) {}
			constexpr double Distance()const noexcept
			{
				return std::sqrt(x*x+y*y);
			}
			constexpr bool operator==(const Cartesian& second)const noexcept
			{
				return x==second.x&&y==second.y;
			}
			constexpr bool operator!=(const Cartesian& second)const noexcept
			{
				return x!=second.x||y!=second.y;
			}
			constexpr Cartesian operator-()const noexcept
			{
				return Cartesian(-x, -y);
			}
			constexpr Cartesian operator~()const noexcept
			{
				return Cartesian(y, x);
			}
			constexpr Cartesian operator-(const Cartesian& second)const noexcept
			{
				return Cartesian(x-second.x, y-second.y);
			}
			constexpr Cartesian operator+(const Cartesian& second)const noexcept
			{
				return Cartesian(x+second.x, y+second.y);
			}
			constexpr Cartesian operator*(const Cartesian& second)const noexcept
			{
				return Cartesian(x*second.x, y*second.y);
			}
			constexpr Cartesian operator/(const Cartesian& second)const noexcept
			{
				return Cartesian(x/second.x, y/second.y);
			}
			template<typename T>
			constexpr Cartesian operator*(T second)const noexcept
			{
				return Cartesian(x*second, y*second);
			}
			template<typename T>
			constexpr Cartesian operator/(T second)const noexcept
			{
				return Cartesian(x/second, y/second);
			}
			//Prirazovani
			constexpr Cartesian operator-=(const Cartesian& second)noexcept
			{
				return *this=*this-second;
			}
			constexpr Cartesian operator+=(const Cartesian& second)noexcept
			{
				return *this=*this+second;
			}
			constexpr Cartesian operator*=(const Cartesian& second)noexcept
			{
				return *this=*this*second;
			}
			constexpr Cartesian operator/=(const Cartesian& second)noexcept
			{
				return *this=*this/second;
			}
			template<typename T>
			constexpr Cartesian operator*=(T second)noexcept
			{
				return *this=*this*second;
			}
			template<typename T>
			constexpr Cartesian operator/=(T second)noexcept
			{
				return *this=*this/second;
			}
		};
	}
	template<typename T>
	using Point=coordinates::Cartesian<T>;
}
namespace func
{
	template<typename T, typename T2>
	geometry::Point<T> Min(const geometry::Point<T>& p1, const geometry::Point<T2>& p2)
	{
		return geometry::Point<T>(Min(p1.x, p2.x), Min(p1.y, p2.y));
	}
	template<typename T, typename T2>
	geometry::Point<T> Max(const geometry::Point<T>& p1, const geometry::Point<T2>& p2)
	{
		return geometry::Point<T>(Max(p1.x, p2.x), Max(p1.y, p2.y));
	}
}