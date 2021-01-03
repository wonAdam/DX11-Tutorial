#pragma once
#include <unordered_map>
#include <windows.h>

class WindowsMessageMap
{
public:
	WindowsMessageMap() noexcept;
	std::string operator()(DWORD msg, WPARAM lp, WPARAM wp) const noexcept;
private:
	std::unordered_map<DWORD, std::string> map;
};