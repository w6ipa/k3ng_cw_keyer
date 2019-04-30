#define MAX_MENUS 4

typedef struct menu_item {
  const char *const label;
  int item_count;
  struct menu_item *previous_menu;
  const struct menu_item *submenu[MAX_MENUS];
  byte (*command)();
};

// menu level 0
const char menu_level_0[] PROGMEM = " Menu";

// menu level 1
const char menu_level_00[] PROGMEM = " Settings";
const char menu_level_01[] PROGMEM = " Training";
const char menu_level_02[] PROGMEM = " Other";
const char menu_level_back[] PROGMEM = " ..."; 

// menu level 0.0 Settings
const char menu_level_001[] PROGMEM = " Mode";


// menu level 0.1 Training
const char menu_level_011[] PROGMEM = " Alphabet";
const char menu_level_012[] PROGMEM = " 5 Letters Int"; 

 menu_item setting_menu[2] = {
    {menu_level_001, 0, NULL, NULL, NULL},
    {menu_level_back, 0, NULL, NULL, NULL}
  };

  menu_item training_menu[3] = {
    {menu_level_011, 0, NULL, NULL, NULL},
    {menu_level_012, 0, NULL, NULL, NULL},
    {menu_level_back, 0, NULL, NULL, NULL}
  };


  menu_item menu_l1[4] = {
    {menu_level_00, 2, NULL, setting_menu, NULL},
    {menu_level_01, 3, NULL, training_menu, NULL},
    {menu_level_02, 0, NULL, NULL, NULL},
    {menu_level_back, 0, NULL, NULL, NULL}
  };

  menu_item menu_l0 = {
    menu_level_0, 4, NULL, menu_l1, NULL
  };

  