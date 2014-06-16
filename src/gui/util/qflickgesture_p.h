/***********************************************************************
*
* Copyright (c) 2012-2014 Barbara Geller
* Copyright (c) 2012-2014 Ansel Sermersheim
* Copyright (c) 2012-2014 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
*
* This file is part of CopperSpice.
*
* CopperSpice is free software: you can redistribute it and/or 
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with CopperSpice.  If not, see 
* <http://www.gnu.org/licenses/>.
*
***********************************************************************/

#ifndef QFLICKGESTURE_P_H
#define QFLICKGESTURE_P_H

#include "qevent.h"
#include "qgesturerecognizer.h"
#include "qgesture_p.h"
#include "qscroller.h"
#include "qscopedpointer.h"

#ifndef QT_NO_GESTURES

QT_BEGIN_NAMESPACE

class QFlickGesturePrivate;
class QGraphicsItem;

class Q_GUI_EXPORT QFlickGesture : public QGesture
{
    CS_OBJECT(QFlickGesture)
    Q_DECLARE_PRIVATE(QFlickGesture)

public:
    QFlickGesture(QObject *receiver, Qt::MouseButton button, QObject *parent = 0);
    ~QFlickGesture();

    friend class QFlickGestureRecognizer;
};

class PressDelayHandler;

class QFlickGesturePrivate : public QGesturePrivate
{
    Q_DECLARE_PUBLIC(QFlickGesture)
public:
    QFlickGesturePrivate();

    QPointer<QObject> receiver;
    QScroller *receiverScroller;
    Qt::MouseButton button; // NoButton == Touch
    bool macIgnoreWheel;
    static PressDelayHandler *pressDelayHandler;
};

class QFlickGestureRecognizer : public QGestureRecognizer
{
public:
    QFlickGestureRecognizer(Qt::MouseButton button);

    QGesture *create(QObject *target);
    QGestureRecognizer::Result recognize(QGesture *state, QObject *watched, QEvent *event);
    void reset(QGesture *state);

private:
    Qt::MouseButton button; // NoButton == Touch
};

QT_END_NAMESPACE

#endif // QT_NO_GESTURES

#endif // QFLICKGESTURE_P_H