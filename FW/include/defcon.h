/*
 * HotelGuard
 * File: defcon.h
 *
 * Livelli di allarme HotelGuard.
 */

#pragma once

#include <stdint.h>

enum class Defcon : uint8_t
{
    Emergency = 1,
    Alarm = 2,
    Warning = 3,
    Notice = 4,
    Normal = 5
};
