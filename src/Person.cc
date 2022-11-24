/**
 *  Person.cc - Person Class Implementation - This class is
 *                  responsible for reading in the configuration file and
 *                  storing it's informtion within it's class members
 *
 *  Copyright 2007, 2008 Timothy Ringrose
 *
 *  This file is part of cursedmenu.
 *
 *  cursedmenu is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  cursedmenu is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with cursedmenu.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <string>
#include "Person.hh"

using namespace std;
typedef string String;

#define PROGRAM "libobjs"

Person::Person() {
}

/**
 * Housekeeping
 */
Person::~Person() {
}

/**
 * Method to try and show te object in string form.
 */
/*
String CursedMenu::toString() {

    if (debugFlag) cerr << "Entered CursedMenu::toString()" << endl;
    ostringstream sout;

    unsigned int itemCount = 0;

    sout << "Menu: ==================================================" << endl;
    sout << "Title: " << menuTitle << endl;

    vector<CursedMenuItem>::iterator it;
   
    for( it = menuItems.begin(); it != menuItems.end(); it++ ) {
        sout << "-----------------" << endl;
        sout << "Item Number: " << itemCount++ << endl;
        sout << it->toString();
    }

    sout << "========================================================" << endl;

    return(sout.str());
}*/

/*
CursedMenu& CursedMenu::operator=(const CursedMenu& cm) {
    if (this != &cm) // make sure not same object
    {
        menuName = cm.menuName;
        menuTitle = cm.menuTitle;
        foreMenuColor = cm.foreMenuColor;
        backMenuColor = cm.backMenuColor;
        debugFlag = cm.debugFlag;

        menuItems.clear();
        for (int x=0; x < cm.menuItems.size(); x++)
        {
            menuItems.push_back(cm.menuItems.at(x));
        }
    }
    return *this;    // Return ref for multiple assignment
}
*/
