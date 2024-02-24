/*
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
*/

//#include "arduino.h"
#include "TFT_DDIG.h"

TFT_DDIG::TFT_DDIG() :
                    TFT_eSPI()
{
}

void TFT_DDIG::configDigit(int Width, int Height, int Depth)
    {
		digHeight = Height;
digWidth = Width;
digDepth = Depth;

}

void TFT_DDIG::drawDigit(int32_t num, int32_t setDigX, int32_t setDigY, uint32_t color, uint32_t bgcolor)
    {
      digX = setDigX;
      digY = setDigY;

      space = digDepth / 9;
      if(space < 2) space = 2;

      switch (num) {
        case 0:
          drawSegmentA(color);
          drawSegmentB(color);
          drawSegmentC(color);
          drawSegmentD(color);
          drawSegmentE(color);
          drawSegmentF(color);
          drawSegmentG(bgcolor);
          break;
        case 1:
          drawSegmentA(bgcolor);
          drawSegmentB(color);
          drawSegmentC(color);
          drawSegmentD(bgcolor);
          drawSegmentE(bgcolor);
          drawSegmentF(bgcolor);
          drawSegmentG(bgcolor);
          break;
        case 2:
          drawSegmentA(color);
          drawSegmentB(color);
          drawSegmentC(bgcolor);
          drawSegmentD(color);
          drawSegmentE(color);
          drawSegmentF(bgcolor);
          drawSegmentG(color);
          break;
        case 3:
          drawSegmentA(color);
          drawSegmentB(color);
          drawSegmentC(color);
          drawSegmentD(color);
          drawSegmentE(bgcolor);
          drawSegmentF(bgcolor);
          drawSegmentG(color);
          break;
        case 4:
          drawSegmentA(bgcolor);
          drawSegmentB(color);
          drawSegmentC(color);
          drawSegmentD(bgcolor);
          drawSegmentE(bgcolor);
          drawSegmentF(color);
          drawSegmentG(color);
          break;
        case 5:
          drawSegmentA(color);
          drawSegmentB(bgcolor);
          drawSegmentC(color);
          drawSegmentD(color);
          drawSegmentE(bgcolor);
          drawSegmentF(color);
          drawSegmentG(color);
          break;
        case 6:
          drawSegmentA(color);
          drawSegmentB(bgcolor);
          drawSegmentC(color);
          drawSegmentD(color);
          drawSegmentE(color);
          drawSegmentF(color);
          drawSegmentG(color);
          break;
        case 7:
          drawSegmentA(color);
          drawSegmentB(color);
          drawSegmentC(color);
          drawSegmentD(bgcolor);
          drawSegmentE(bgcolor);
          drawSegmentF(bgcolor);
          drawSegmentG(bgcolor);
          break;
        case 8:
          drawSegmentA(color);
          drawSegmentB(color);
          drawSegmentC(color);
          drawSegmentD(color);
          drawSegmentE(color);
          drawSegmentF(color);
          drawSegmentG(color);
          break;
        case 9:
          drawSegmentA(color);
          drawSegmentB(color);
          drawSegmentC(color);
          drawSegmentD(color);
          drawSegmentE(bgcolor);
          drawSegmentF(color);
          drawSegmentG(color);
          break;
        case 10:
          drawSegmentA(color);
          drawSegmentB(color);
          drawSegmentC(color);
          drawSegmentD(bgcolor);
          drawSegmentE(color);
          drawSegmentF(color);
          drawSegmentG(color);
          break;
        case 11:
          drawSegmentA(bgcolor);
          drawSegmentB(bgcolor);
          drawSegmentC(color);
          drawSegmentD(color);
          drawSegmentE(color);
          drawSegmentF(color);
          drawSegmentG(color);
          break;
        case 12:
          drawSegmentA(color);
          drawSegmentB(bgcolor);
          drawSegmentC(bgcolor);
          drawSegmentD(color);
          drawSegmentE(color);
          drawSegmentF(color);
          drawSegmentG(bgcolor);
          break;
        case 13:
          drawSegmentA(bgcolor);
          drawSegmentB(color);
          drawSegmentC(color);
          drawSegmentD(color);
          drawSegmentE(color);
          drawSegmentF(bgcolor);
          drawSegmentG(color);
          break;
        case 14:
          drawSegmentA(color);
          drawSegmentB(bgcolor);
          drawSegmentC(bgcolor);
          drawSegmentD(color);
          drawSegmentE(color);
          drawSegmentF(color);
          drawSegmentG(color);
          break;
        case 15:
          drawSegmentA(color);
          drawSegmentB(bgcolor);
          drawSegmentC(bgcolor);
          drawSegmentD(bgcolor);
          drawSegmentE(color);
          drawSegmentF(color);
          drawSegmentG(color);
          break;
        default:
          // if nothing else matches, do the default
          // default is optional
          break;
      }
    }

    void TFT_DDIG::drawSegHoriz(int x1, int y1, int x2, int y2, int segDepth, uint32_t color)
    {
      int i;

      for (i = 0; i < (segDepth / 2); i++)
      {
        drawL(x1 - i, y1 + i, x2 + i, y1 + i, color);
      }
      for (i = 0; i < (segDepth / 2); i++)
      {
        drawL(x1 - (segDepth / 2) + i, y1 + (segDepth / 2) + i, x2 + (segDepth / 2) - i, y1 + (segDepth / 2) + i, color);
      }
    }

    void TFT_DDIG::drawSegVert(int x1, int y1, int x2, int y2, int segDepth, uint32_t color)
    {
      int i;

      for (i = 0; i < (segDepth / 2); i++)
      {
        drawL(x1 + i, y1 - i, x1 + i, y2 + i, color);
      }
      for (i = 0; i < (segDepth / 2); i++)
      {
        drawL(x1 + (segDepth / 2) + i, y1 - (segDepth / 2) + i, x1 + (segDepth / 2) + i, y2 + (segDepth / 2) - i, color);
      }
    }

    void TFT_DDIG::drawSegmentA(uint32_t color)
    {
      int x1, x2, y1, y2;
      //setC(color);
      x1 = digX + digDepth + space;
      x2 = digX + digWidth - digDepth - space;
      y1 = digY;
      y2 = digY + digDepth;
      drawSegHoriz(x1, y1, x2, y2, digDepth, color); // a
    }

    void TFT_DDIG::drawSegmentB(uint32_t color)
    {
      int x1, x2, y1, y2;
      //setC(color);
      x1 = digX + digWidth - digDepth;
      x2 = digX + digWidth;
      y1 = digY + digDepth + space;
      y2 = digY + (digHeight / 2) - (digDepth / 2) - space;
      drawSegVert(x1, y1, x2, y2, digDepth, color); // b
    }

    void TFT_DDIG::drawSegmentC(uint32_t color)
    {
      int x1, x2, y1, y2;
      //setC(color);
      x1 = digX + digWidth - digDepth;
      x2 = digX + digWidth;
      y1 = digY + (digHeight / 2) + (digDepth / 2) + space;
      y2 = digY + digHeight - digDepth - space;
      drawSegVert(x1, y1, x2, y2, digDepth, color); // c
    }

    void TFT_DDIG::drawSegmentD(uint32_t color)
    {
      int x1, x2, y1, y2;
      //setC(color);
      x1 = digX + digDepth + space;
      x2 = digX + digWidth - digDepth - space;
      y1 = digY + digHeight - digDepth;
      y2 = digY + digHeight, digDepth;
      drawSegHoriz(x1, y1, x2, y2, digDepth, color); // d
    }

    void TFT_DDIG::drawSegmentE(uint32_t color)
    {
      int x1, x2, y1, y2;
      //setC(color);
      x1 = digX;
      x2 = digX + digDepth;
      y1 = digY + (digHeight / 2) + (digDepth / 2) + space;
      y2 = digY + digHeight - digDepth - space;
      drawSegVert(x1, y1, x2, y2, digDepth, color); // e
    }

    void TFT_DDIG::drawSegmentF(uint32_t color)
    {
      int x1, x2, y1, y2;
      //setC(color);
      x1 = digX;
      x2 = digX + digDepth;
      y1 = digY + digDepth + space;
      y2 = digY + (digHeight / 2) - (digDepth / 2) - space;
      drawSegVert(x1, y1, x2, y2, digDepth, color); // f
    }

    void TFT_DDIG::drawSegmentG(uint32_t color)
    {
      int x1, x2, y1, y2;
      //setC(color);
      x1 = digX + digDepth + space;
      x2 = digX + digWidth - digDepth - space;
      y1 = digY + (digHeight / 2) - (digDepth / 2);
      y2 = digY + (digHeight / 2) + (digDepth / 2), digDepth;
      drawSegHoriz(x1, y1, x2, y2, digDepth, color); // g
    }