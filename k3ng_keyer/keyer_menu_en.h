
typedef struct menu_item {
  const byte label_index;
  int item_count;
  struct menu_item *previous_menu;
  struct menu_item *submenu;
  byte (*command)();
};

// menu level 0
const char menu_level_0[] PROGMEM = " Menu";
#define MENU_0 1
// menu level 1
const char menu_level_00[] PROGMEM = " Settings";
#define MENU_00 2
const char menu_level_01[] PROGMEM = " Training";
#define MENU_01 3
const char menu_level_02[] PROGMEM = " Other";
#define MENU_02 4
const char menu_level_back[] PROGMEM = " ..."; 
#define MENU_BACK 0

// menu level 0.0 Settings
const char menu_level_001[] PROGMEM = " Mode";
#define MENU_001 5

const char menu_level_001[] PROGMEM = " Revert Paddles";
#define MENU_002 6

// menu level 0.1 Training
const char menu_level_011[] PROGMEM = " Alphabet";
#define MENU_011 7
const char menu_level_012[] PROGMEM = " 5 Letters Int"; 
#define MENU_012 8

const char *const menu_labels[] PROGMEM = {
  menu_level_back, // 0
  menu_level_0,    // 1
  menu_level_00,   // 2
  menu_level_01,   // 3
  menu_level_02,   // 4
  menu_level_001,  // 5
  menu_level_002,  // 6
  menu_level_011,  // 7
  menu_level_012   // 8
};


 menu_item setting_menu[2] = {
    {MENU_001, 0, NULL, NULL, NULL},
    {MENU_002, 0, NULL, NULL, NULL},
    {MENU_BACK, 0, NULL, NULL, NULL}
  };

  menu_item training_menu[3] = {
    {MENU_011, 0, NULL, NULL, NULL},
    {MENU_012, 0, NULL, NULL, NULL},
    {MENU_BACK, 0, NULL, NULL, NULL}
  };


  menu_item menu_l1[4] = {
    {MENU_00, 2, NULL, setting_menu, NULL},
    {MENU_01, 3, NULL, training_menu, NULL},
    {MENU_02, 0, NULL, NULL, NULL},
    {MENU_BACK, 0, NULL, NULL, NULL}
  };

  menu_item menu_l0 = {
    MENU_0, 4, NULL, menu_l1, NULL
  };

