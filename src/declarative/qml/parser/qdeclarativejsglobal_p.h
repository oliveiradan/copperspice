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
#ifndef QDECLARATIVEJSGLOBAL_P_H
#define QDECLARATIVEJSGLOBAL_P_H

#include <QtCore/qglobal.h>

#ifdef QT_CREATOR
#  define QT_QML_BEGIN_NAMESPACE
#  define QT_QML_END_NAMESPACE

#  ifdef QDECLARATIVEJS_BUILD_DIR
#    define QML_PARSER_EXPORT Q_DECL_EXPORT
#  elif QML_BUILD_STATIC_LIB
#    define QML_PARSER_EXPORT
#  else
#    define QML_PARSER_EXPORT Q_DECL_IMPORT
#  endif // QDECLARATIVEJS_BUILD_DIR

#else // !QT_CREATOR
#  define QT_QML_BEGIN_NAMESPACE QT_BEGIN_NAMESPACE
#  define QT_QML_END_NAMESPACE QT_END_NAMESPACE
#  define QML_PARSER_EXPORT
#endif // QT_CREATOR

#endif // QDECLARATIVEJSGLOBAL_P_H