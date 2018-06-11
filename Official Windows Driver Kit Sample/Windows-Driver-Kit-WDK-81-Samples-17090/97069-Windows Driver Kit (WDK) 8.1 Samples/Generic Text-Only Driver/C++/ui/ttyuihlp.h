//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//  ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//  PARTICULAR PURPOSE.
//
//  Copyright  1997-2003  Microsoft Corporation.  All Rights Reserved.
//
//  FILE:	ttyuihlp.H
//    
//  PURPOSE:	IDs for dialog elements
//
#pragma once

// Printer Commands dialog

#define IDH_TTYUI_BEGIN_PRINTJOB        1000 // IDC_EDIT10
#define IDH_TTYUI_END_PRINTJOB          1021 // IDC_EDIT11
#define IDH_TTYUI_PAPERSIZE_SELECT  1022 // IDC_EDIT12
#define IDH_TTYUI_PAPERFEED_SELECTION   1023 // IDC_EDIT13
#define IDH_TTYUI_CHECK_COMMANDS    1018 // IDC_BUTTON1
#define IDH_TTYUI_UNPRINTABLE_MARGINS_LEFT  1024 // IDC_EDIT14
#define IDH_TTYUI_UNPRINTABLE_MARGINS_TOP   1025 // IDC_EDIT15
#define IDH_TTYUI_UNPRINTABLE_MARGINS_RIGHT 1026 // IDC_EDIT16
#define IDH_TTYUI_UNPRINTABLE_MARGINS_BOTTOM    1027 // IDC_EDIT17
#define IDH_TTYUI_UNITS_10MM     1015 // IDC_RADIO1
#define IDH_TTYUI_UNITS_100INCH     1016 // IDC_RADIO2

// Font Selection dialog

#define IDH_TTYUI_SELECT_10CPI     1005 // IDC_EDIT1
#define IDH_TTYUI_SELECT_12CPI     1006 //IDC_EDIT2
#define IDH_TTYUI_SELECT_17CPI     1007 //IDC_EDIT3
#define IDH_TTYUI_DBLWIDE_ON     1008 //IDC_EDIT4
#define IDH_TTYUI_DBLWIDE_OFF     1009 // IDC_EDIT5
#define IDH_TTYUI_BOLD_ON     1011 // IDC_EDIT6
#define IDH_TTYUI_BOLD_OFF     1012 // IDC_EDIT7
#define IDH_TTYUI_UNDERLINE_ON     1013 // IDC_EDIT8
#define IDH_TTYUI_UNDERLINE_OFF     1014 // IDC_EDIT9
#define IDH_TTYUI_CODE_PAGE     1020 // IDC_COMBO1

const DWORD aHelpIDs[]=
{
    IDC_EDIT1,  IDH_TTYUI_SELECT_10CPI,
    IDC_EDIT2,  IDH_TTYUI_SELECT_12CPI,
    IDC_EDIT3,  IDH_TTYUI_SELECT_17CPI,
    IDC_EDIT4,  IDH_TTYUI_DBLWIDE_ON,
    IDC_EDIT5,  IDH_TTYUI_DBLWIDE_OFF,
    IDC_EDIT6,  IDH_TTYUI_BOLD_ON,
    IDC_EDIT7,  IDH_TTYUI_BOLD_OFF,
    IDC_EDIT8,  IDH_TTYUI_UNDERLINE_ON,
    IDC_EDIT9,  IDH_TTYUI_UNDERLINE_OFF,

    IDC_EDIT10,  IDH_TTYUI_BEGIN_PRINTJOB,
    IDC_EDIT11,  IDH_TTYUI_END_PRINTJOB,
    IDC_EDIT12,  IDH_TTYUI_PAPERSIZE_SELECT,
    IDC_EDIT13,  IDH_TTYUI_PAPERFEED_SELECTION,
    IDC_EDIT14,  IDH_TTYUI_UNPRINTABLE_MARGINS_LEFT,
    IDC_EDIT15,  IDH_TTYUI_UNPRINTABLE_MARGINS_TOP,
    IDC_EDIT16,  IDH_TTYUI_UNPRINTABLE_MARGINS_RIGHT,
    IDC_EDIT17,  IDH_TTYUI_UNPRINTABLE_MARGINS_BOTTOM,


    IDC_RADIO1, IDH_TTYUI_UNITS_10MM,
    IDC_BUTTON1,    IDH_TTYUI_CHECK_COMMANDS,
    IDC_COMBO1, IDH_TTYUI_CODE_PAGE,
    IDC_RADIO2, IDH_TTYUI_UNITS_100INCH,
    0, 0
};

