#pragma once

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
	double full_size1() const noexcept;
	double full_size2() const noexcept;
	double full_size3() const noexcept;

	//возвращает размер тела свечи
	double body_size1() const noexcept;
	double body_size2() const noexcept;
	double body_size3() const noexcept;

	bool is_green1() const noexcept;
	bool is_green2() const noexcept;
	bool is_green3() const noexcept;
	bool is_red1() const noexcept;
	bool is_red2() const noexcept;
	bool is_red3() const noexcept;

};
