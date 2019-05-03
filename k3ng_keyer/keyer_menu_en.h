
typedef struct menu_item {
  char *const label;
  int item_count;
  struct menu_item *previous_menu;
  struct menu_item *submenu;
  long parameter;
  byte (*command)(long parameter);
};

// menu level 0
const char menu_level_0[] PROGMEM = "Menu";
// menu level 1
const char menu_level_00[] PROGMEM = "Settings";
const char menu_level_01[] PROGMEM = "Training";
const char menu_level_02[] PROGMEM = "Other";
const char menu_level_back[] PROGMEM = "..."; 

// menu level 0.0 Settings
const char menu_level_001[] PROGMEM = "Mode";

const char menu_level_002[] PROGMEM = "Revert Paddles";

// menu level 0.1 Training
const char menu_level_011[] PROGMEM = "Alphabet";
const char menu_level_012[] PROGMEM = "5 Letters Int"; 
const char menu_level_013[] PROGMEM = "Receive"; 
const char menu_level_014[] PROGMEM = "Receive/Transmit"; 

const char menu_level_01x1[] PROGMEM = "Int Calls"; 
const char menu_level_01x2[] PROGMEM = "US Calls"; 
const char menu_level_01x3[] PROGMEM = "European Calls"; 
const char menu_level_01x4[] PROGMEM = "Canadian Calls"; 
const char menu_level_01x5[] PROGMEM = "5 char progr."; 
const char menu_level_01x6[] PROGMEM = "2 ltrs words"; 


byte menu_cmd_back(long parameter);
byte menu_cmd_mode(long parameter);
byte menu_cmd_reverse(long parameter);
byte menu_cmd_noop(long parameter);
byte menu_cmd_alphabet_practice(long parameter);
byte menu_cmd_practice_receive(long parameter);
byte menu_cmd_practice_rcvtrans(long parameter);

 menu_item setting_menu[3] = {
    {menu_level_001, 0, NULL, NULL, 0, menu_cmd_mode},
    {menu_level_002, 0, NULL, NULL, 0, menu_cmd_reverse},
    {menu_level_back, 0, NULL, NULL, 0, menu_cmd_back}
  };
  menu_item receive_menu[6] = {
    {menu_level_01x1, 0, NULL, NULL, CALLSIGN_INTERNATIONAL, menu_cmd_practice_receive},
    {menu_level_01x2, 0, NULL, NULL, CALLSIGN_US, menu_cmd_practice_receive},
    {menu_level_01x3, 0, NULL, NULL, CALLSIGN_EUROPEAN, menu_cmd_practice_receive},
    {menu_level_01x4, 0, NULL, NULL, CALLSIGN_CANADA, menu_cmd_practice_receive},
    {menu_level_01x6, 0, NULL, NULL, PRACTICE_2_CHAR_WORDS, menu_cmd_practice_receive},
    {menu_level_back, 0, NULL, NULL, menu_cmd_back}
  };

  menu_item rcvtrans_menu[6] = {
    {menu_level_01x1, 0, NULL, NULL, CALLSIGN_INTERNATIONAL, menu_cmd_practice_rcvtrans},
    {menu_level_01x2, 0, NULL, NULL, CALLSIGN_US, menu_cmd_practice_rcvtrans},
    {menu_level_01x3, 0, NULL, NULL, CALLSIGN_EUROPEAN, menu_cmd_practice_rcvtrans},
    {menu_level_01x4, 0, NULL, NULL, CALLSIGN_CANADA, menu_cmd_practice_rcvtrans},
    {menu_level_01x5, 0, NULL, NULL, ECHO_PROGRESSIVE_5, menu_cmd_practice_rcvtrans},
    {menu_level_back, 0, NULL, NULL, menu_cmd_back}
  };

  menu_item training_menu[5] = {
    {menu_level_011, 0, NULL, NULL, 1000, menu_cmd_alphabet_practice},
    {menu_level_012, 0, NULL, NULL, 1001, menu_cmd_noop},
    {menu_level_013, 0, NULL, receive_menu, 0, NULL},
    {menu_level_014, 0, NULL, rcvtrans_menu, 0, NULL},
    {menu_level_back, 0, NULL, NULL, menu_cmd_back}
  };


  menu_item menu_l1[4] = {
    {menu_level_00, 3, NULL, setting_menu, 0, NULL},
    {menu_level_01, 3, NULL, training_menu, 0, NULL},
    {menu_level_02, 0, NULL, NULL, 0, menu_cmd_noop},
    {menu_level_back, 0, NULL, NULL, 0, menu_cmd_back}
  };

  menu_item menu_l0 = {
    menu_level_0, 4, NULL, menu_l1, 0, NULL
  };

