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

#include "qoptimizationpasses_p.h"

#include "qbooleanfns_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

bool TrueFN::evaluateEBV(const DynamicContext::Ptr &) const
{
    return true;
}

bool FalseFN::evaluateEBV(const DynamicContext::Ptr &) const
{
    return false;
}

bool NotFN::evaluateEBV(const DynamicContext::Ptr &context) const
{
    /* That little '!' is quite important in this function -- I forgot it ;-) */
    return !m_operands.first()->evaluateEBV(context);
}

OptimizationPass::List NotFN::optimizationPasses() const
{
    return OptimizationPasses::notFN;
}

QT_END_NAMESPACE