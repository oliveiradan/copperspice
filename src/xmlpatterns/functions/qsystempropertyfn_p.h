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

#ifndef Patternist_SystemPropertyFN_P_H
#define Patternist_SystemPropertyFN_P_H

#include "qstaticnamespacescontainer_p.h"

QT_BEGIN_NAMESPACE

namespace QPatternist
{   
    class SystemPropertyFN : public StaticNamespacesContainer
    {
    public:
        virtual Item evaluateSingleton(const DynamicContext::Ptr &context) const;

    private:
        /**
         * Returns a string representation for @p property as defined
         * for the system properties in "XSL Transformations (XSLT)
         * Version 2.0, 16.6.5 system-property". Hence, this function
         * handles only the properties specified in the XSL namespace, and returns
         * an empty string if an unrecognized property is asked for.
         */
        static QString retrieveProperty(const QXmlName name);
    };
}

QT_END_NAMESPACE

#endif