/***********************************************************************
*
* Copyright (c) 2012-2021 Barbara Geller
* Copyright (c) 2012-2021 Ansel Sermersheim
*
* This file is part of CopperSpice.
*
* CopperSpice is free software. You can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://www.gnu.org/licenses/
*
***********************************************************************/

#include <qstring8.h>
#include <qstringview.h>

#include <catch2/catch.hpp>

TEST_CASE("QStringView8 contains", "[qstringview]")
{
   QString8 str      = "A wacky fox and sizeable pig jumped halfway over a blue moon";
   QStringView8 view = str;

   REQUIRE(view.contains("jumped"));
   REQUIRE(! view.contains("lunch"));
}

TEST_CASE("QStringView8 count", "[qstringview]")
{
   QString8 str      = "A wacky fox and sizeable pig jumped halfway over a blue moon";
   QStringView8 view = str;

   REQUIRE(view.count('a') == 6);
   REQUIRE(view.count("a") == 6);

   REQUIRE(view.count('a', Qt::CaseInsensitive) == 7);
}

TEST_CASE("QStringView8 empty", "[qstringview]")
{
   QStringView8 view;

   REQUIRE(view.isEmpty());

   REQUIRE(view.constBegin() == view.constEnd());
   REQUIRE(view.cbegin() == view.cend());
   REQUIRE(view.begin() == view.end());
}

TEST_CASE("QStringView8 ends_with", "[qstringview]")
{
   QString8 str      = "On a clear day you can see forever";
   QStringView8 view = str;

   REQUIRE(view.endsWith("forever") == true);
   REQUIRE(view.endsWith("Forever") == false);

   REQUIRE(view.endsWith("ForEver", Qt::CaseInsensitive) == true);
}

TEST_CASE("QStringView8 left", "[qstringview]")
{
   QString8 str      = "A wacky fox and sizeable pig jumped halfway over a blue moon";
   QStringView8 view = str;

   REQUIRE(view.left(11) == "A wacky fox");
}

TEST_CASE("QStringView8 length", "[qstringview]")
{
   QString8 str      = "A wacky fox and sizeable pig jumped halfway over a blue moon";
   QStringView8 view = str;

   REQUIRE(view.length() == str.length());
}

TEST_CASE("QStringView8 mid", "[qstringview]")
{
   QString8 str      = "On a clear day you can see forever";
   QStringView8 view = str;

   REQUIRE(view.mid(11, 3) == "day");
}

TEST_CASE("QStringView8 operator_bracket", "[qstringview]")
{
   QString8 str      = "On a clear day you can see forever";
   QStringView8 view = str;

   REQUIRE(view[11] == "d");
}

TEST_CASE("QStringView8 right", "[qstringview]")
{
   QString8 str      = "A wacky fox and sizeable pig jumped halfway over a blue moon";
   QStringView8 view = str;

   REQUIRE(view.right(9) == "blue moon");
}

TEST_CASE("QStringView8 starts_with", "[qstringview]")
{
   QString8 str      = "On a clear day you can see forever";
   QStringView8 view = str;

   REQUIRE(view.startsWith("On a clear") == true);
   REQUIRE(view.startsWith("on a clear") == false);

   REQUIRE(view.startsWith("on a clear", Qt::CaseInsensitive) == true);
}

TEST_CASE("QStringView8 trimmed", "[qstringview]")
{
   QString8 str      = " orange  apple pear  quince  ";
   QStringView8 view = str;

   REQUIRE(view.trimmed() == "orange  apple pear  quince");
}



