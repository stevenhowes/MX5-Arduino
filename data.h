// MAP Sensor
const int     map_sensor_min_kpa        = 20;             // Physical minimum of the hardware
const int     map_sensor_max_kpa        = 250;            // Physical maximum of the hardware
const int     map_range_min             = 20;             // Index 0 (min we care about)
const int     map_range_max             = 100;            // Index 15 (max we care about, anything >100 can be atmospheric as far as we care)
byte          map_current_index         = 0;              // Index
byte          map_current_value         = 0;              // KPA value

// Rotation
byte            rpm_limited             = 0;
byte            rpm_limited_log         = 0;
const int       rpm_range_min           = 0;              // Index 0
const int       rpm_range_max           = 7200;           // Index 15
byte            rpm_current_index       = 0;              // Table index of current RPM
int             rpm_current_value       = 0;              // Current engine RPM
int             usec_per_degree         = 0;              // uSec per degree of rotation at current RPM
//unsigned long   usec_per_degree         = 0;

// Cam Angle Sensor
unsigned long   cas_sgt_lastrise        = 0;              // micros() of the last rise
unsigned long   cas_sgt_lastfall        = 0;              //    ""    of the last fall
byte            cas_sgt_lastvalue       = 0;              // The state of SGT on previous cycle

unsigned long   cas_sgc_lastrise        = 0;              // micros() of the last rise
unsigned long   cas_sgc_lastfall        = 0;              //    ""    of the last fall
byte            cas_sgc_lastvalue       = 0;              // The state of SGC on the previous cycle

byte            cas_sync_fail           = 0;
byte            cas_sync_fail_log       = 0;

// Cylinder sequencing
byte            cylinder_tdc            = 0;              // Most recent cylinder to hit TDC
byte            cylinder_next_fire      = 0;              // Next cylinder due a spark
//byte            cylinder_next_inject    = 0;            // Next cylinder due fuel
// Sequential and wasted spark
//byte            cylinder_next[]         = {0,3,1,4,2};    // For 1-3-4-2 Current cylinder as index returns next cylinder
byte            cylinder_next[]         = {0,2,1,2,1};    // For 1-3-4-2 Current cylinder as index returns next cylinder

// Ignition
const int       coil_dwell              = 4000;           // 5ms for stock coil
const int        ignition_offset = 0;

// Tachometer
const int       tach_pulse_length       = 5000;           // 5ms equiv to dwell time on old coil at sensible RPM (tach pulse length)

// O2 sensor
//const int       o2_min                  = 200;          // 200mV is lean
//const int       o2_target                = 450;          // 450mV is 14.7:1 apparently...
//const int       o2_max                  = 800;          // 800mv is rich
//int             o2_current_value        = 0;            // Curent milivolts

// Battery
byte              battery_voltage_value   = 13;
byte              battery_voltage_index   = 7;
const int         battery_cal_7v          = 252;
const int         battery_cal_16v         = 579;

