/**
 *  SSN.cpp - libobjs Class Implementation - This class is
 *            responsible for defining a Social Security Number.
 *
 *  Copyright 2023 Timothy Ringrose
 *
 *  This file is part of libobjs.
 *
 *  libobjs is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  libobjs is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libobjs. If not, see <http://www.gnu.org/licenses/>.
 *
 *  SSN - ITIN - ATIN - Valid Ranges
 *  https://www.taxact.com/support/19057/2017/ssn-itin-atin-valid-ranges
 *
 *  Below are the valid ranges for a Social Security Number (SSN), Individual
 *    Taxpayer Identification Number (ITIN), or Adoption Taxpayer Identification Number (ATIN):
 *
 *  Social Security/Taxpayer Identification Numbers are broken down as follows:
 *  
 *  1 2 3 - 4 5 - 6 7 8 9
 *  
 *  Area - Group - Serial
 *  
 *  Valid Ranges for Social Security Number (SSN):
 *  001-01-0001 through 665-99-9999
 *  667-01-0001 through 899-99-9999
 *  750-01-0001 through 763-99-9999
 *  764-01-0001 through 899-99-9999
 *  
 *  When the SSN "Group" contains zeros, the SSN is a test SSN and the return will be rejected.
 *    When the SSN "Serial" contains all zeros, the return will be rejected.
 *  
 *  Valid Range for Individual Taxpayer Identification Number (ITIN):
 *  900-70-0000 through 999-88-9999
 *  900-90-0000 through 999-92-9999
 *  900-94-0000 through 999-99-9999
 *  
 *  An ITIN is a nine-digit number assigned by the Internal Revenue Service to taxpayers who
 *    are not eligible to obtain an SSN. It is used for tax purposes only.  See the IRS website
 *    General ITIN Information for additional details. 
 *  
 *  2017 Note: ITINs that have not been used on a tax return for Tax Year 2014, Tax Year 2015 or
 *    Tax Year 2016 will expire December 31, 2017.  All ITINs issued before 2013 with middle
 *    digits of 70, 71, 72 or 80 (Example: (9XX-70-XXXX) will also expire on December 31, 2017.
 *  
 *  Valid Range for Adoption Taxpayer Identification Number (ATIN):
 *  900-93-0000 through 999-93-9999
 *  
 *  An ATIN is issued by the Internal Revenue Service as a temporary taxpayer identification
 *    number for the child in a domestic adoption where the adopting taxpayers do not have and/or
 *    are unable to obtain the child's Social Security Number(SSN). It is to be used by the
 *    adopting taxpayers on their Federal Income Tax return to identify the child while final
 *    domestic adoption is pending.
 *  
 */

#include <string>
#include <stdexcept>
#include "SSN.hpp"

using namespace std;

#define PROGRAM "libobjs"

#define MIN_AREA1 001
#define MAX_AREA1 665

#define MIN_AREA2 667
#define MAX_AREA2 899

#define MIN_AREA3 750
#define MAX_AREA3 763

#define MIN_AREA4 764
#define MAX_AREA4 899

#define MIN_GROUP 01
#define MAX_GROUP 99

#define MIN_SERIAL 0001
#define MAX_SERIAL 9999

SSN::SSN(string areaNo, string groupNo, string serialNo) {
    set_areaNo(areaNo);

    this->set_groupNo(groupNo);
    this->set_serialNo(serialNo);
}

SSN::SSN() {
    this->areaNo = "000";
    this->groupNo = "00";
    this->serialNo = "0000";
}

/**
 * Housekeeping
 */
SSN::~SSN() {
}

string SSN::toString() {

    string retString = "";

    retString += this->areaNo;
    retString += "-";
    retString += this->groupNo;
    retString += "-";
    retString += this->serialNo;
    
    return(retString);
}

void SSN::set_areaNo(string areaNo) {
    bool isValid = false;

    if (atoi(areaNo.c_str()) >= MIN_AREA1 && atoi(areaNo.c_str()) <= MAX_AREA1)
        isValid = true;

    if (atoi(areaNo.c_str()) >= MIN_AREA2 && atoi(areaNo.c_str()) <= MAX_AREA2)
        isValid = true;

    if (atoi(areaNo.c_str()) >= MIN_AREA3 && atoi(areaNo.c_str()) <= MAX_AREA3)
        isValid = true;

    if ( isValid )
        this->areaNo = areaNo;
    else
        throw std::invalid_argument( "ERROR: received invalid value for areaNo" );
}

void SSN::set_groupNo(string groupNo) {
    bool isValid = false;

    if (atoi(groupNo.c_str()) >= MIN_GROUP && atoi(groupNo.c_str()) <= MAX_GROUP)
        isValid = true;

    if ( isValid )
        this->groupNo = groupNo;
    else
        throw std::invalid_argument( "ERROR: received invalid value for groupNo" );
}

void SSN::set_serialNo(string serialNo) {
    bool isValid = false;

    if (atoi(serialNo.c_str()) >= MIN_SERIAL && atoi(serialNo.c_str()) <= MAX_SERIAL)
        isValid = true;

    if ( isValid )
        this->serialNo = serialNo;
    else
        throw std::invalid_argument( "ERROR: received invalid value for serialNo" );
}

string SSN::get_areaNo() {
    return(this->areaNo);
}

string SSN::get_groupNo() {
    return(this->groupNo);
}

string SSN::get_serialNo() {
    return(this->serialNo);
}
