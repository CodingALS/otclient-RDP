/*
 * Copyright (c) 2010-2025 OTClient <https://github.com/edubart/otclient>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#pragma once

#include "declarations.h"
#include <framework/ui/uianchorlayout.h>

#include <utility>

class UIPositionAnchor final : public UIAnchor
{
public:
    UIPositionAnchor(const Fw::AnchorEdge anchoredEdge, const Position& hookedPosition, const Fw::AnchorEdge hookedEdge) :
        UIAnchor(anchoredEdge, {}, hookedEdge), m_hookedPosition(hookedPosition)
    {
    }

    UIWidgetPtr getHookedWidget(const UIWidgetPtr& /*widget*/, const UIWidgetPtr& parentWidget) override { return parentWidget; }
    int getHookedPoint(const UIWidgetPtr& hookedWidget, const UIWidgetPtr& parentWidget) override;

private:
    Position m_hookedPosition;
};

class UIMapAnchorLayout final : public UIAnchorLayout
{
public:
    UIMapAnchorLayout(UIWidgetPtr parentWidget) : UIAnchorLayout(std::move(parentWidget)) {}

    void addPositionAnchor(const UIWidgetPtr& anchoredWidget, Fw::AnchorEdge anchoredEdge,
                           const Position& hookedPosition, Fw::AnchorEdge hookedEdge);
    void centerInPosition(const UIWidgetPtr& anchoredWidget, const Position& hookedPosition);
    void fillPosition(const UIWidgetPtr& anchoredWidget, const Position& hookedPosition);
};
