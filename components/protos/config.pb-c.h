/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: config.proto */

#ifndef PROTOBUF_C_config_2eproto__INCLUDED
#define PROTOBUF_C_config_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003003 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Hydroponics__Sampling Hydroponics__Sampling;
typedef struct _Hydroponics__Controller Hydroponics__Controller;
typedef struct _Hydroponics__Controller__Entry Hydroponics__Controller__Entry;
typedef struct _Hydroponics__Controller__Entry__Pid Hydroponics__Controller__Entry__Pid;
typedef struct _Hydroponics__Task Hydroponics__Task;
typedef struct _Hydroponics__Task__Cron Hydroponics__Task__Cron;
typedef struct _Hydroponics__Config Hydroponics__Config;


/* --- enums --- */

/*
 * Directly matches "ext_gpio_num_t" enumeration.
 */
typedef enum _Hydroponics__Task__Output {
  HYDROPONICS__TASK__OUTPUT__EXT_GPIO_A_0 = 0,
  HYDROPONICS__TASK__OUTPUT__EXT_GPIO_A_1 = 1,
  HYDROPONICS__TASK__OUTPUT__EXT_GPIO_A_2 = 2,
  HYDROPONICS__TASK__OUTPUT__EXT_GPIO_A_3 = 3,
  HYDROPONICS__TASK__OUTPUT__EXT_GPIO_A_4 = 4,
  HYDROPONICS__TASK__OUTPUT__EXT_GPIO_A_5 = 5,
  HYDROPONICS__TASK__OUTPUT__EXT_GPIO_A_6 = 6,
  HYDROPONICS__TASK__OUTPUT__EXT_GPIO_A_7 = 7,
  HYDROPONICS__TASK__OUTPUT__EXT_GPIO_B_0 = 8,
  HYDROPONICS__TASK__OUTPUT__EXT_GPIO_B_1 = 9,
  HYDROPONICS__TASK__OUTPUT__EXT_GPIO_B_2 = 10,
  HYDROPONICS__TASK__OUTPUT__EXT_GPIO_B_3 = 11,
  HYDROPONICS__TASK__OUTPUT__EXT_GPIO_B_4 = 12,
  HYDROPONICS__TASK__OUTPUT__EXT_GPIO_B_5 = 13,
  HYDROPONICS__TASK__OUTPUT__EXT_GPIO_B_6 = 14,
  HYDROPONICS__TASK__OUTPUT__EXT_GPIO_B_7 = 15
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(HYDROPONICS__TASK__OUTPUT)
} Hydroponics__Task__Output;
typedef enum _Hydroponics__Task__OutputAction {
  HYDROPONICS__TASK__OUTPUT_ACTION__OFF = 0,
  HYDROPONICS__TASK__OUTPUT_ACTION__ON = 1
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(HYDROPONICS__TASK__OUTPUT_ACTION)
} Hydroponics__Task__OutputAction;

/* --- messages --- */

struct  _Hydroponics__Sampling
{
  ProtobufCMessage base;
  int32_t humidity;
  int32_t temperature;
  int32_t ec_probe;
  int32_t ec_probe_temp;
  int32_t ph_probe;
};
#define HYDROPONICS__SAMPLING__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&hydroponics__sampling__descriptor) \
    , 0, 0, 0, 0, 0 }


struct  _Hydroponics__Controller__Entry__Pid
{
  ProtobufCMessage base;
  int32_t sampling;
  float p;
  float i;
  float d;
};
#define HYDROPONICS__CONTROLLER__ENTRY__PID__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&hydroponics__controller__entry__pid__descriptor) \
    , 0, 0, 0, 0 }


struct  _Hydroponics__Controller__Entry
{
  ProtobufCMessage base;
  float target;
  float min;
  float max;
  Hydroponics__Controller__Entry__Pid *pid;
};
#define HYDROPONICS__CONTROLLER__ENTRY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&hydroponics__controller__entry__descriptor) \
    , 0, 0, 0, NULL }


struct  _Hydroponics__Controller
{
  ProtobufCMessage base;
  Hydroponics__Controller__Entry *ec;
  Hydroponics__Controller__Entry *ph;
};
#define HYDROPONICS__CONTROLLER__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&hydroponics__controller__descriptor) \
    , NULL, NULL }


struct  _Hydroponics__Task__Cron
{
  ProtobufCMessage base;
  Hydroponics__Task__OutputAction action;
  size_t n_expression;
  char **expression;
};
#define HYDROPONICS__TASK__CRON__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&hydroponics__task__cron__descriptor) \
    , HYDROPONICS__TASK__OUTPUT_ACTION__OFF, 0,NULL }


struct  _Hydroponics__Task
{
  ProtobufCMessage base;
  char *name;
  size_t n_output;
  Hydroponics__Task__Output *output;
  size_t n_cron;
  Hydroponics__Task__Cron **cron;
};
#define HYDROPONICS__TASK__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&hydroponics__task__descriptor) \
    , (char *)protobuf_c_empty_string, 0,NULL, 0,NULL }


struct  _Hydroponics__Config
{
  ProtobufCMessage base;
  Hydroponics__Sampling *sampling;
  Hydroponics__Controller *controller;
  size_t n_task;
  Hydroponics__Task **task;
};
#define HYDROPONICS__CONFIG__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&hydroponics__config__descriptor) \
    , NULL, NULL, 0,NULL }


/* Hydroponics__Sampling methods */
void   hydroponics__sampling__init
                     (Hydroponics__Sampling         *message);
size_t hydroponics__sampling__get_packed_size
                     (const Hydroponics__Sampling   *message);
size_t hydroponics__sampling__pack
                     (const Hydroponics__Sampling   *message,
                      uint8_t             *out);
size_t hydroponics__sampling__pack_to_buffer
                     (const Hydroponics__Sampling   *message,
                      ProtobufCBuffer     *buffer);
Hydroponics__Sampling *
       hydroponics__sampling__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   hydroponics__sampling__free_unpacked
                     (Hydroponics__Sampling *message,
                      ProtobufCAllocator *allocator);
/* Hydroponics__Controller__Entry__Pid methods */
void   hydroponics__controller__entry__pid__init
                     (Hydroponics__Controller__Entry__Pid         *message);
/* Hydroponics__Controller__Entry methods */
void   hydroponics__controller__entry__init
                     (Hydroponics__Controller__Entry         *message);
/* Hydroponics__Controller methods */
void   hydroponics__controller__init
                     (Hydroponics__Controller         *message);
size_t hydroponics__controller__get_packed_size
                     (const Hydroponics__Controller   *message);
size_t hydroponics__controller__pack
                     (const Hydroponics__Controller   *message,
                      uint8_t             *out);
size_t hydroponics__controller__pack_to_buffer
                     (const Hydroponics__Controller   *message,
                      ProtobufCBuffer     *buffer);
Hydroponics__Controller *
       hydroponics__controller__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   hydroponics__controller__free_unpacked
                     (Hydroponics__Controller *message,
                      ProtobufCAllocator *allocator);
/* Hydroponics__Task__Cron methods */
void   hydroponics__task__cron__init
                     (Hydroponics__Task__Cron         *message);
/* Hydroponics__Task methods */
void   hydroponics__task__init
                     (Hydroponics__Task         *message);
size_t hydroponics__task__get_packed_size
                     (const Hydroponics__Task   *message);
size_t hydroponics__task__pack
                     (const Hydroponics__Task   *message,
                      uint8_t             *out);
size_t hydroponics__task__pack_to_buffer
                     (const Hydroponics__Task   *message,
                      ProtobufCBuffer     *buffer);
Hydroponics__Task *
       hydroponics__task__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   hydroponics__task__free_unpacked
                     (Hydroponics__Task *message,
                      ProtobufCAllocator *allocator);
/* Hydroponics__Config methods */
void   hydroponics__config__init
                     (Hydroponics__Config         *message);
size_t hydroponics__config__get_packed_size
                     (const Hydroponics__Config   *message);
size_t hydroponics__config__pack
                     (const Hydroponics__Config   *message,
                      uint8_t             *out);
size_t hydroponics__config__pack_to_buffer
                     (const Hydroponics__Config   *message,
                      ProtobufCBuffer     *buffer);
Hydroponics__Config *
       hydroponics__config__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   hydroponics__config__free_unpacked
                     (Hydroponics__Config *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Hydroponics__Sampling_Closure)
                 (const Hydroponics__Sampling *message,
                  void *closure_data);
typedef void (*Hydroponics__Controller__Entry__Pid_Closure)
                 (const Hydroponics__Controller__Entry__Pid *message,
                  void *closure_data);
typedef void (*Hydroponics__Controller__Entry_Closure)
                 (const Hydroponics__Controller__Entry *message,
                  void *closure_data);
typedef void (*Hydroponics__Controller_Closure)
                 (const Hydroponics__Controller *message,
                  void *closure_data);
typedef void (*Hydroponics__Task__Cron_Closure)
                 (const Hydroponics__Task__Cron *message,
                  void *closure_data);
typedef void (*Hydroponics__Task_Closure)
                 (const Hydroponics__Task *message,
                  void *closure_data);
typedef void (*Hydroponics__Config_Closure)
                 (const Hydroponics__Config *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor hydroponics__sampling__descriptor;
extern const ProtobufCMessageDescriptor hydroponics__controller__descriptor;
extern const ProtobufCMessageDescriptor hydroponics__controller__entry__descriptor;
extern const ProtobufCMessageDescriptor hydroponics__controller__entry__pid__descriptor;
extern const ProtobufCMessageDescriptor hydroponics__task__descriptor;
extern const ProtobufCMessageDescriptor hydroponics__task__cron__descriptor;
extern const ProtobufCEnumDescriptor    hydroponics__task__output__descriptor;
extern const ProtobufCEnumDescriptor    hydroponics__task__output_action__descriptor;
extern const ProtobufCMessageDescriptor hydroponics__config__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_config_2eproto__INCLUDED */