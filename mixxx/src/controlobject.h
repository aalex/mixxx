/***************************************************************************
                          controlobject.h  -  description
                             -------------------
    begin                : Wed Feb 20 2002
    copyright            : (C) 2002 by Tue and Ken Haste Andersen
    email                : 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef CONTROLOBJECT_H
#define CONTROLOBJECT_H

#include <qobject.h>
#include "configobject.h"
//#include "midiobject.h"
class MidiObject;

/**
  *@author Tue and Ken Haste Andersen
  */

class ControlObject : public QObject
{
  Q_OBJECT
public:
  ControlObject();
  ControlObject(ConfigObject::ConfigKey *key);
  ~ControlObject();
  QString *print();

  ConfigObject::ConfigOption *cfgOption;

  static ConfigObject *config;
  static MidiObject *midi;
public slots:
  void slotSetPosition(int) {};
  void slotSetPositionMidi(int);
signals:
  void updateGUI(int);
};

#endif
