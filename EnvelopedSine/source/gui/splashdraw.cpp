// (c) 2019-2020 Takamitsu Endo
//
// This file is part of EnvelopedSine.
//
// EnvelopedSine is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// EnvelopedSine is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with EnvelopedSine.  If not, see <https://www.gnu.org/licenses/>.

#include "../../../common/gui/splash.hpp"
#include "../version.hpp"

namespace Steinberg {
namespace Vst {

using namespace VSTGUI;

void CreditView::draw(CDrawContext *pContext)
{
  pContext->setDrawMode(CDrawMode(CDrawModeFlags::kAntiAliasing));
  CDrawContext::Transform t(
    *pContext, CGraphicsTransform().translate(getViewSize().getTopLeft()));

  const auto width = getWidth();
  const auto height = getHeight();
  const double borderWidth = 8.0;
  const double halfBorderWidth = borderWidth / 2.0;

  // Background.
  const auto bgColor = CColor(255, 255, 255, 255);
  pContext->setLineWidth(borderWidth);
  pContext->setFillColor(bgColor);
  pContext->drawRect(CRect(0.0, 0.0, width, height), kDrawFilled);

  pContext->setFont(fontIDTitle);
  pContext->setFontColor(CColor(0, 0, 0, 255));
  pContext->drawString("EnvelopedSine " VERSION_STR, CPoint(20.0, 50.0));

  pContext->setFont(fontIDText);
  pContext->setFontColor(CColor(0, 0, 0, 255));
  pContext->drawString(
    "© 2019-2020 Takamitsu Endo (ryukau@gmail.com)", CPoint(20.0, 90.0));

  pContext->drawString("- Knob -", CPoint(20.0f, 150.0f));
  pContext->drawString("Shift + Left Drag: Fine Adjustment", CPoint(20.0f, 180.0f));
  pContext->drawString("Ctrl + Left Click: Reset to Default", CPoint(20.0f, 210.0f));

  pContext->drawString("- Number -", CPoint(20.0f, 270.0f));
  pContext->drawString("Shares same controls with knob, and:", CPoint(20.0f, 300.0f));
  pContext->drawString("Right Click: Flip Minimum and Maximum", CPoint(20.0f, 330.0f));

  pContext->drawString("- Overtone -", CPoint(280.0f, 150.0f));

  pContext->drawString("Ctrl + Left Click", CPoint(280.0f, 180.0f));
  pContext->drawString("Right Drag", CPoint(280.0f, 210.0f));
  pContext->drawString("A", CPoint(280.0f, 240.0f));
  pContext->drawString("D", CPoint(280.0f, 270.0f));
  pContext->drawString("F", CPoint(280.0f, 300.0f));
  pContext->drawString("Shift + F", CPoint(280.0f, 330.0f));
  pContext->drawString("I", CPoint(280.0f, 360.0f));
  pContext->drawString("Shift + I", CPoint(280.0f, 390.0f));
  pContext->drawString("N", CPoint(280.0f, 420.0f));
  pContext->drawString("Shift + N", CPoint(280.0f, 450.0f));

  pContext->drawString("| Reset to Default", CPoint(380.0f, 180.0f));
  pContext->drawString("| Draw Line", CPoint(380.0f, 210.0f));
  pContext->drawString("| Sort Ascending Order", CPoint(380.0f, 240.0f));
  pContext->drawString("| Sort Decending Order", CPoint(380.0f, 270.0f));
  pContext->drawString("| Low-pass Filter", CPoint(380.0f, 300.0f));
  pContext->drawString("| High-pass Filter", CPoint(380.0f, 330.0f));
  pContext->drawString("| Invert Value", CPoint(380.0f, 360.0f));
  pContext->drawString("| Invert Value (Minimum to 0)", CPoint(380.0f, 390.0f));
  pContext->drawString("| Normalize", CPoint(380.0f, 420.0f));
  pContext->drawString("| Normalize (Minimum to 0)", CPoint(380.0f, 450.0f));

  pContext->drawString("H", CPoint(600.0f, 180.0f));
  pContext->drawString("L", CPoint(600.0f, 210.0f));
  pContext->drawString("P", CPoint(600.0f, 240.0f));
  pContext->drawString("R", CPoint(600.0f, 270.0f));
  pContext->drawString("Shift + R", CPoint(600.0f, 300.0f));
  pContext->drawString("S", CPoint(600.0f, 330.0f));
  pContext->drawString(", (Comma)", CPoint(600.0f, 360.0f));
  pContext->drawString(". (Period)", CPoint(600.0f, 390.0f));
  pContext->drawString("1", CPoint(600.0f, 420.0f));
  pContext->drawString("2-9", CPoint(600.0f, 450.0f));

  pContext->drawString("| Emphasize High", CPoint(680.0f, 180.0f));
  pContext->drawString("| Emphasize Low", CPoint(680.0f, 210.0f));
  pContext->drawString("| Permute", CPoint(680.0f, 240.0f));
  pContext->drawString("| Randomize", CPoint(680.0f, 270.0f));
  pContext->drawString("| Sparse Randomize", CPoint(680.0f, 300.0f));
  pContext->drawString("| Subtle Randomize", CPoint(680.0f, 330.0f));
  pContext->drawString("| Rotate Back", CPoint(680.0f, 360.0f));
  pContext->drawString("| Rotate Forward", CPoint(680.0f, 390.0f));
  pContext->drawString("| Decrease Odd", CPoint(680.0f, 420.0f));
  pContext->drawString("| Decrease 2n-9n", CPoint(680.0f, 450.0f));

  pContext->drawString("Have a nice day!", CPoint(740.0f, 510.0f));

  // Border.
  const auto borderColor = CColor(0, 0, 0, 255);
  pContext->setFrameColor(borderColor);
  pContext->drawRect(
    CRect(
      halfBorderWidth, halfBorderWidth, width - halfBorderWidth,
      height - halfBorderWidth),
    kDrawStroked);

  setDirty(false);
}

} // namespace Vst
} // namespace Steinberg
