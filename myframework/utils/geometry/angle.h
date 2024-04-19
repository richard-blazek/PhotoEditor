#pragma once

#include "base.h"

namespace geometry
{
	template<typename Real>
	class Angle
	{
	private:
		constexpr static Real RadToDeg(Real x)noexcept
		{
			return x*180/pi<Real>;
		}
		constexpr static Real DegToRad(Real x)noexcept
		{
			return x*pi<Real>/180;
		}
		static constexpr Real max=pi<Real>*2;
		Real value=0;
	public:
		constexpr Angle()=default;
		constexpr Angle(Real angle):value(angle-max*int32(angle/max)) {}
		constexpr Angle& operator=(Real angle)noexcept
		{
			value=Angle(angle).value;
			return *this;
		}
		constexpr static Angle FromDeg(Real angle)noexcept
		{
			return Angle(DegToRad(angle));
		}
		//Porovnavani
		#define CMP_FUNC_DEF(op) \
			constexpr bool operator op(const Angle& second)const noexcept\
			{\
				return value op second.value;\
			}
		CMP_FUNC_DEF(==)
		CMP_FUNC_DEF(!=)
		CMP_FUNC_DEF(<)
		CMP_FUNC_DEF(>)
		CMP_FUNC_DEF(<=)
		CMP_FUNC_DEF(>=)
		#undef CMP
		//Scitani
		constexpr Angle operator-(const Angle& second)const noexcept
		{
			return Angle(value-second.value);
		}
		constexpr Angle operator+(const Angle& second)const noexcept
		{
			return Angle(value+second.value);
		}
		constexpr Angle operator-=(const Angle& second)noexcept
		{
			return *this=*this-second;
		}
		constexpr Angle operator+=(const Angle& second)noexcept
		{
			return *this=*this+second;
		}
		//Nasobeni
		constexpr Angle operator/(Real second)const noexcept
		{
			return Angle(value/second);
		}
		constexpr Angle operator*(Real second)const noexcept
		{
			return Angle(value*second);
		}
		constexpr Angle operator/=(Real second)noexcept
		{
			return *this=*this/second;
		}
		constexpr Angle operator*=(Real second)noexcept
		{
			return *this=*this*second;
		}
		//Ostatni
		constexpr Real sin()const
		{
			return std::sin(value);
		}
		constexpr Real cos()const
		{
			return std::cos(value);
		}
		constexpr Real InRadians()const noexcept
		{
			return value;
		}
		constexpr Real InDegrees()const noexcept
		{
			return RadToDeg(value);
		}
	};
}