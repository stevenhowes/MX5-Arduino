unsigned long         task_map                =     1;              // Get initial figure
const unsigned long   task_map_interval       =     93000;          // 93ms

unsigned long         task_throttle           =     1;              // Get initial figure
const unsigned long   task_throttle_interval  =     88000;          // 88ms

unsigned long         task_rpm                =     1;              // Get initial figure
const unsigned long   task_rpm_interval       =     199000;         // 199ms

unsigned long         task_battery            =     1;              // Get initial figure
const unsigned long   task_battery_interval   =     265000;         // 265ms

unsigned long         task_debug              =     0;              // Triggers after init
const unsigned long   task_debug_interval     =     387000;         // 2s (eh?)

unsigned long         task_tach_high          =     0;              // Ilde
unsigned long         task_tach_low           =     0;              // Idle

unsigned long         task_coil1_charge       =     0;              // Idle
unsigned long         task_coil1_fire         =     1;              // Looks mad but stops us cooking coils
unsigned long         task_coil2_charge       =     0;              // Idle
unsigned long         task_coil2_fire         =     1;             // Looks mad but stops us cooking coils

unsigned long         task_injector1_open       =     0;              // Idle
unsigned long         task_injector1_close      =     1;              // Idle
unsigned long         task_injector2_open       =     0;              // Idle
unsigned long         task_injector2_close      =     1;              // Idle
unsigned long         task_injector3_open       =     0;              // Idle
unsigned long         task_injector3_close      =     1;              // Idle
unsigned long         task_injector4_open       =     0;              // Idle
unsigned long         task_injector4_close      =     1;              // Idle
