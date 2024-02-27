# TFT_DDIG
TFT_DDIG was adapted from the [UTFT_DDIG](https://github.com/rtek1000/UTFT_DDIG) library, to improve the display response time of seven-segment numbers, the accepted value is between 0-9 and 10-15 (A-F)

- It's very good for applications that have many characters being constantly updated.
- It's also great for reducing code size, for large numbers.

This library (TFT_DDIG) extends the TFT_eSPI library.

So both libraries are needed.

You can control:

- Position
- Width
- Height
- Thickness (Minimum segment thickness: 2 px)
- Color

TFT_eSPI: https://github.com/Bodmer/TFT_eSPI

----

Tested with 800x600 7 inch display SSD1963 controller, more details: [Display_TFT_800x480_7_inch_SSD1963](https://github.com/rtek1000/Display_TFT_800x480_7_inch_SSD1963) 
----

Note: As this library only uses the draw line function ("drawL()"), this code can be adapted to operate with other libraries that can draw a line.

----

This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

