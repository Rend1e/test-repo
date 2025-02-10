﻿#pragma once

#include <stdint.h>
#include <string>

using Price = double;

struct Candle
{
public:
	Price open;
	Price high;
	Price low;
	Price close;

public:
	Candle() = default;
	Candle(Price _open, Price _high, Price _low, Price _close);

public:
	//находится ли цена внутри тела этой свечи
	bool body_contains1(const Price& price) const noexcept;
	bool body_contains2(const Price& price) const noexcept;
	bool body_contains3(const Price& price) const noexcept;

	//находится ли цена внутри тела и теней
	//другими словами, касается ли цена
	//тела или теней свечи
	bool contains1(const Price& price) const noexcept;
	bool contains2(const Price& price) const noexcept;
	bool contains3(const Price& price) const noexcept;

	//возвращает размер целой свечи, включая тени
	double full_size() const noexcept;

	//возвращает размер тела свечи
	double body_size() const noexcept;

	bool is_green() const noexcept;
	bool is_red() const noexcept;

};
