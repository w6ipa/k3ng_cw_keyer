#define MAX_MENUS 4
typedef struct menu_item {
  const char *const label;
  const struct menu_item *submenu[MAX_MENUS];
  void (*command)();
};

// menu level 0
const char menu_level_00[] PROGMEM = " Settings";
const char menu_level_01[] PROGMEM = " Training";
const char menu_level_02[] PROGMEM = " Other";
const char menu_level_03[] PROGMEM = " Exit"; 

// menu level 0.0 Settings
const char menu_level_001[] PROGMEM = " Mode";
const char menu_level_002[] PROGMEM = " Exit"; 

// menu level 0.1 Training
const char menu_level_011[] PROGMEM = " Alphabet";
const char menu_level_012[] PROGMEM = " 5 Letters Interactive"; 


const menu_item setting_menu[2] = {
  {menu_level_001, NULL, NULL},
  {menu_level_002, NULL, NULL},
};

const menu_item training_menu[2] = {
  {menu_level_011, NULL, NULL},
  {menu_level_012, NULL, NULL},
};


const menu_item root_menu[4] = {
  {menu_level_00, setting_menu, NULL},
  {menu_level_01, training_menu, NULL},
  {menu_level_02, NULL, NULL},
  {menu_level_03, NULL, NULL}
};

