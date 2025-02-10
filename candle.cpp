﻿#include "candle.h"

#include <string>
#include <stdexcept>

Candle::Candle(Price _open, Price _high, Price _low, Price _close)
	: open(_open)
	, high(_high)
	, low(_low)
	, close(_close)
{
}

bool Candle::body_contains1(const Price &price) const noexcept
{
	if(is_green())
	{
		const Price &max = close;
		const Price &min = open;
		return price >= min && price <= max;
	}
	else
	{
		const Price &max = open;
		const Price &min = close;
		return price >= min && price <= max;
	}
}
bool Candle::body_contains2(const Price &price) const noexcept
{
	if(is_green())
	{
		const Price &max = close;
		const Price &min = open;
		return price >= min && price <= max;
	}
	else
	{
		const Price &max = open;
		const Price &min = close;
		return price >= min && price <= max;
	}
}

bool Candle::body_contains3(const Price &price) const noexcept
{
	if(is_green())
	{
		const Price &max = close;
		const Price &min = open;
		return price >= min && price <= max;
	}
	else
	{
		const Price &max = open;
		const Price &min = close;
		return price >= min && price <= max;
	}
}

bool Candle::contains1(const Price &price) const noexcept
{
	return price >= low && price <= high;
}
bool Candle::contains2(const Price &price) const noexcept
{
	return price >= low && price <= high;
}
bool Candle::contains3(const Price &price) const noexcept
{
	return price >= low && price <= high;
}

double Candle::full_size1() const noexcept
{
	return std::abs(low - high);
}
double Candle::full_size2() const noexcept
{
	return std::abs(low - high);
}
double Candle::full_size3() const noexcept
{
	return std::abs(low - high);
}

double Candle::body_size() const noexcept
{
	return std::abs(open - close);
}

bool Candle::is_green() const noexcept
{
	return close > open;
}

bool Candle::is_red() const noexcept
{
	return close < open;
}
