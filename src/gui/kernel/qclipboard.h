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

#ifndef QCLIPBOARD_H
#define QCLIPBOARD_H

#include <QtCore/qobject.h>
#include <QScopedPointer>

QT_BEGIN_NAMESPACE

#ifndef QT_NO_CLIPBOARD

class QMimeSource;
class QMimeData;
class QImage;
class QPixmap;
class QClipboardPrivate;

class Q_GUI_EXPORT QClipboard : public QObject
{
    CS_OBJECT(QClipboard)
    Q_DECLARE_PRIVATE(QClipboard)

private:
    QClipboard(QObject *parent);
    ~QClipboard();

public:
    enum Mode { Clipboard, Selection, FindBuffer, LastMode = FindBuffer };

    void clear(Mode mode = Clipboard);

    bool supportsSelection() const;
    bool supportsFindBuffer() const;

    bool ownsSelection() const;
    bool ownsClipboard() const;
    bool ownsFindBuffer() const;

    QString text(Mode mode = Clipboard) const;
    QString text(QString& subtype, Mode mode = Clipboard) const;
    void setText(const QString &, Mode mode = Clipboard);

    const QMimeData *mimeData(Mode mode = Clipboard ) const;
    void setMimeData(QMimeData *data, Mode mode = Clipboard);

    QImage image(Mode mode = Clipboard) const;
    QPixmap pixmap(Mode mode = Clipboard) const;
    void setImage(const QImage &, Mode mode  = Clipboard);
    void setPixmap(const QPixmap &, Mode mode  = Clipboard);

    GUI_CS_SIGNAL_1(Public, void changed(QClipboard::Mode mode))
    GUI_CS_SIGNAL_2(changed,mode) 
    GUI_CS_SIGNAL_1(Public, void selectionChanged())
    GUI_CS_SIGNAL_2(selectionChanged) 
    GUI_CS_SIGNAL_1(Public, void findBufferChanged())
    GUI_CS_SIGNAL_2(findBufferChanged) 
    GUI_CS_SIGNAL_1(Public, void dataChanged())
    GUI_CS_SIGNAL_2(dataChanged) 
    
protected:
    void connectNotify(const char *);
    bool event(QEvent *);

    QScopedPointer<QClipboardPrivate> d_ptr;

    friend class QApplication;
    friend class QApplicationPrivate;
    friend class QBaseApplication;
    friend class QDragManager;
    friend class QMimeSource;
    friend class QPlatformClipboard;

private:
    Q_DISABLE_COPY(QClipboard)

    bool supportsMode(Mode mode) const;
    bool ownsMode(Mode mode) const;
    void emitChanged(Mode mode);

    GUI_CS_SLOT_1(Private, void ownerDestroyed())
    GUI_CS_SLOT_2(ownerDestroyed) 


};

#endif // QT_NO_CLIPBOARD

QT_END_NAMESPACE

#endif // QCLIPBOARD_H