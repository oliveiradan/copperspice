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

#include "private/qdeclarativeimplicitsizeitem_p.h"
#include "private/qdeclarativeimplicitsizeitem_p_p.h"

QT_BEGIN_NAMESPACE

void QDeclarativeImplicitSizeItemPrivate::implicitWidthChanged()
{
    Q_Q(QDeclarativeImplicitSizeItem);
    emit q->implicitWidthChanged();
}

void QDeclarativeImplicitSizeItemPrivate::implicitHeightChanged()
{
    Q_Q(QDeclarativeImplicitSizeItem);
    emit q->implicitHeightChanged();
}

QDeclarativeImplicitSizeItem::QDeclarativeImplicitSizeItem(QDeclarativeItem *parent)
    : QDeclarativeItem(*(new QDeclarativeImplicitSizeItemPrivate), parent)
{
}

QDeclarativeImplicitSizeItem::QDeclarativeImplicitSizeItem(QDeclarativeImplicitSizeItemPrivate &dd, QDeclarativeItem *parent)
    : QDeclarativeItem(dd, parent)
{
}


void QDeclarativeImplicitSizePaintedItemPrivate::implicitWidthChanged()
{
    Q_Q(QDeclarativeImplicitSizePaintedItem);
    emit q->implicitWidthChanged();
}

void QDeclarativeImplicitSizePaintedItemPrivate::implicitHeightChanged()
{
    Q_Q(QDeclarativeImplicitSizePaintedItem);
    emit q->implicitHeightChanged();
}

QDeclarativeImplicitSizePaintedItem::QDeclarativeImplicitSizePaintedItem(QDeclarativeItem *parent)
    : QDeclarativePaintedItem(*(new QDeclarativeImplicitSizePaintedItemPrivate), parent)
{
}

QDeclarativeImplicitSizePaintedItem::QDeclarativeImplicitSizePaintedItem(QDeclarativeImplicitSizePaintedItemPrivate &dd, QDeclarativeItem *parent)
    : QDeclarativePaintedItem(dd, parent)
{
}

QT_END_NAMESPACE