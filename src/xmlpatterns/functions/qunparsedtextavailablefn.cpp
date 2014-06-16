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

#include "qanyuri_p.h"

#include "qunparsedtextavailablefn_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

bool UnparsedTextAvailableFN::evaluateEBV(const DynamicContext::Ptr &context) const
{
    Q_ASSERT(m_operands.count() == 1 || m_operands.count() == 2);
    const Item href(m_operands.first()->evaluateSingleton(context));
    if(!href)
        return Item();

    bool isValid = false;
    const QUrl mayRela(AnyURI::toQUrl<ReportContext::XTDE1170>(href.stringValue(),
                                                               context,
                                                               this,
                                                               &isValid));

    if(!isValid)
        return false;

    const QUrl uri(context->resolveURI(mayRela, staticBaseURI()));

    /* fn:unparsed-text() will raise an error on this. */
    if(uri.hasFragment())
        return false;

    QString encoding;

    if(m_operands.count() == 2)
    {
        const Item encodingArg(m_operands.at(1)->evaluateSingleton(context));
        if(encodingArg)
            encoding = encodingArg.stringValue();
    }

    Q_ASSERT(uri.isValid() && !uri.isRelative());
    return context->resourceLoader()->isUnparsedTextAvailable(uri, encoding);
}

QT_END_NAMESPACE