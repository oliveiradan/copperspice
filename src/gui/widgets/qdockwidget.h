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

#ifndef QDOCKWIDGET_H
#define QDOCKWIDGET_H

#include <QtGui/qwidget.h>

QT_BEGIN_NAMESPACE

#ifndef QT_NO_DOCKWIDGET

class QDockAreaLayout;
class QDockWidgetPrivate;
class QMainWindow;
class QStyleOptionDockWidget;

class Q_GUI_EXPORT QDockWidget : public QWidget
{
    CS_OBJECT(QDockWidget)

    GUI_CS_FLAG(DockWidgetFeature,DockWidgetFeatures)

    GUI_CS_PROPERTY_READ(floating, isFloating)
    GUI_CS_PROPERTY_WRITE(floating, setFloating)
    GUI_CS_PROPERTY_READ(features, features)
    GUI_CS_PROPERTY_WRITE(features, setFeatures)
    GUI_CS_PROPERTY_NOTIFY(features, featuresChanged)
    GUI_CS_PROPERTY_READ(allowedAreas, allowedAreas)
    GUI_CS_PROPERTY_WRITE(allowedAreas, setAllowedAreas)
    GUI_CS_PROPERTY_NOTIFY(allowedAreas, allowedAreasChanged)
    GUI_CS_PROPERTY_READ(windowTitle, windowTitle)
    GUI_CS_PROPERTY_WRITE(windowTitle, setWindowTitle)
    GUI_CS_PROPERTY_DESIGNABLE(windowTitle, true)

public:
    explicit QDockWidget(const QString &title, QWidget *parent = 0, Qt::WindowFlags flags = 0);
    explicit QDockWidget(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~QDockWidget();

    QWidget *widget() const;
    void setWidget(QWidget *widget);

    enum DockWidgetFeature {
        DockWidgetClosable    = 0x01,
        DockWidgetMovable     = 0x02,
        DockWidgetFloatable   = 0x04,
        DockWidgetVerticalTitleBar = 0x08,

        DockWidgetFeatureMask = 0x0f,
        AllDockWidgetFeatures = DockWidgetClosable|DockWidgetMovable|DockWidgetFloatable, // ### remove in 5.0
        NoDockWidgetFeatures  = 0x00,

        Reserved              = 0xff
    };
    using DockWidgetFeatures = QFlags<DockWidgetFeature>;

    void setFeatures(DockWidgetFeatures features);
    DockWidgetFeatures features() const;

    void setFloating(bool floating);
    inline bool isFloating() const;

    void setAllowedAreas(Qt::DockWidgetAreas areas);
    Qt::DockWidgetAreas allowedAreas() const;

    void setTitleBarWidget(QWidget *widget);
    QWidget *titleBarWidget() const;

    inline bool isAreaAllowed(Qt::DockWidgetArea area) const
       { return (allowedAreas() & area) == area; }

#ifndef QT_NO_ACTION
    QAction *toggleViewAction() const;
#endif

    GUI_CS_SIGNAL_1(Public, void featuresChanged(QDockWidget::DockWidgetFeatures features))
    GUI_CS_SIGNAL_2(featuresChanged,features) 
    GUI_CS_SIGNAL_1(Public, void topLevelChanged(bool topLevel))
    GUI_CS_SIGNAL_2(topLevelChanged,topLevel) 
    GUI_CS_SIGNAL_1(Public, void allowedAreasChanged(Qt::DockWidgetAreas allowedAreas))
    GUI_CS_SIGNAL_2(allowedAreasChanged,allowedAreas) 
    GUI_CS_SIGNAL_1(Public, void visibilityChanged(bool visible))
    GUI_CS_SIGNAL_2(visibilityChanged,visible) 
    GUI_CS_SIGNAL_1(Public, void dockLocationChanged(Qt::DockWidgetArea area))
    GUI_CS_SIGNAL_2(dockLocationChanged,area) 

protected:
    void changeEvent(QEvent *event);
    void closeEvent(QCloseEvent *event);
    void paintEvent(QPaintEvent *event);
    bool event(QEvent *event);
    void initStyleOption(QStyleOptionDockWidget *option) const;

private:
    Q_DECLARE_PRIVATE(QDockWidget)
    Q_DISABLE_COPY(QDockWidget)

    GUI_CS_SLOT_1(Private, void _q_toggleView(bool un_named_arg1))
    GUI_CS_SLOT_2(_q_toggleView)

    GUI_CS_SLOT_1(Private, void _q_toggleTopLevel())
    GUI_CS_SLOT_2(_q_toggleTopLevel)

    friend class QDockAreaLayout;
    friend class QDockWidgetItem;
    friend class QMainWindowLayout;
    friend class QDockWidgetLayout;
    friend class QDockAreaLayoutInfo;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(QDockWidget::DockWidgetFeatures)

bool QDockWidget::isFloating() const
{ 
   return isWindow();
}

#endif // QT_NO_DOCKWIDGET

QT_END_NAMESPACE

#endif // QDYNAMICDOCKWIDGET_H