Ex4_Icon ICON "myicon.ico"
Ex4_Menu MENU
POPUP "&File"
MENUITEM "&Open...ItCtri-O", 2
MENUITEM "&Save",
MENUITEM "Save &As...
-", 4
MENUITEM SEPARATOR
MENUITEM "&Hex view", 5, CHECKED GRAYED MENUITEM "&Exit\tAlt-F4", 6
POPUP "&Edit"
{ MENUITEM "&Copy",
",7
MENUITEM "&Paste", 8
POPUP "Popup"
{
MENUITEM "1", 9
Пример
MENUITEM "2", 10
MENUITEM "3", 11 }
MENUITEM SEPARATOR MENUITEM "Search", 12
POPUP "&Help" { MENUITEM "&About...\tF1", 13} }
