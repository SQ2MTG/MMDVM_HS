/*
Serial fifo control - Copyright (C) KI6ZUM 2015
Copyright (C) 2015,2016 by Jonathan Naylor G4KLX
Copyright (C) 2016,2017 by Andy Uribe CA6JAU
 
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public
License along with this library; if not, write to the
Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
Boston, MA  02110-1301, USA.
*/

#if !defined(BITRB_H)
#define  BITRB_H

#if defined(STM32F10X_MD)
#include "stm32f10x.h"
#else
#include <Arduino.h>
#endif

class CBitRB {
public:
  CBitRB(uint16_t length);
  
  uint16_t getSpace() const;
  
  uint16_t getData() const;

  bool put(uint8_t bit, uint8_t control);

  bool get(uint8_t& bit, uint8_t& control);

  bool hasOverflowed();

private:
  uint16_t           m_length;
  volatile uint8_t*  m_bits;
  volatile uint8_t*  m_control;
  volatile uint16_t  m_head;
  volatile uint16_t  m_tail;
  volatile bool      m_full;
  bool               m_overflow;
};

#endif

