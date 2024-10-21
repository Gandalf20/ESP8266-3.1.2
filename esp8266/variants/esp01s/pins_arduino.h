/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis
  Modified for ESP8266 platform by Ivan Grokhotkov, 2014-2015.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#define EXTERNAL_NUM_INTERRUPTS 2
#define NUM_DIGITAL_PINS        2
#define NUM_ANALOG_INPUTS       0

#define isFlashInterfacePin(p)\
    (esp_is_8285()\
     ? ((p) == 6 || (p) == 7 || (p) == 8 || (p) == 11)\
     : ((p) >= 6 && (p) <= 11))

#define analogInputToDigitalPin(p)  ((p > 0) ? NOT_A_PIN : 0)
#define digitalPinToInterrupt(p)    (((p) < EXTERNAL_NUM_INTERRUPTS)? (p) : NOT_AN_INTERRUPT)
#define digitalPinHasPWM(p)         (((p) < NUM_DIGITAL_PINS && !isFlashInterfacePin(p))? 1 : 0)

#define PIN_SPI_SS   (15)
#define PIN_SPI_MOSI (13)
#define PIN_SPI_MISO (12)
#define PIN_SPI_SCK  (14)

static const uint8_t SS    = PIN_SPI_SS;
static const uint8_t MOSI  = PIN_SPI_MOSI;
static const uint8_t MISO  = PIN_SPI_MISO;
static const uint8_t SCK   = PIN_SPI_SCK;

#define PIN_WIRE_SDA (0)
#define PIN_WIRE_SCL (2)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif

#define SERIAL_PORT_MONITOR        Serial
#define SERIAL_PORT_USBVIRTUAL     Serial
#define SERIAL_PORT_HARDWARE       Serial
#define SERIAL_PORT_HARDWARE_OPEN  Serial1

#ifdef LED_BUILTIN
#ifdef __cplusplus
extern "C"
#endif
const int BUILTIN_LED __attribute__((deprecated("use LED_BUILTIN"), weak)) = LED_BUILTIN;
#endif


#endif /* Pins_Arduino_h */
