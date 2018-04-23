/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
* \addtogroup XMC_ESC XMC_ESC
* @{
*/

/**
\file XMC_ESCObjects
\author ET9300Utilities.ApplicationHandler (Version 1.5.0.0) | EthercatSSC@beckhoff.com

\brief XMC_ESC specific objects<br>
\brief NOTE : This file will be overwritten if a new object dictionary is generated!<br>
*/

#if defined(_XMC__ESC_) && (_XMC__ESC_ == 1)
#define PROTO
#else
#define PROTO extern
#endif
/******************************************************************************
*                    Object 0x1600 : OUT_GENERIC process data mapping
******************************************************************************/
/**
* \addtogroup 0x1600 0x1600 | OUT_GENERIC process data mapping
* @{
* \brief Object 0x1600 (OUT_GENERIC process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x7000.1<br>
* SubIndex 2 - Reference to 0x7000.2<br>
* SubIndex 3 - Reference to 0x7000.3<br>
* SubIndex 4 - Reference to 0x7000.4<br>
* SubIndex 5 - Reference to 0x7000.5<br>
* SubIndex 6 - Reference to 0x7000.6<br>
* SubIndex 7 - Reference to 0x7000.7<br>
* SubIndex 8 - Reference to 0x7000.8<br>
* SubIndex 9 - Reference to 0x7000.9<br>
* SubIndex 10 - Reference to 0x7000.10<br>
* SubIndex 11 - Reference to 0x7000.11<br>
* SubIndex 12 - Reference to 0x7000.12<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1600[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x7000.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Reference to 0x7000.2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Reference to 0x7000.3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 - Reference to 0x7000.4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex5 - Reference to 0x7000.5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex6 - Reference to 0x7000.6 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex7 - Reference to 0x7000.7 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex8 - Reference to 0x7000.8 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex9 - Reference to 0x7000.9 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex10 - Reference to 0x7000.10 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex11 - Reference to 0x7000.11 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex12 - Reference to 0x7000.12 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1600[] = "OUT_GENERIC process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000"
"SubIndex 006\000"
"SubIndex 007\000"
"SubIndex 008\000"
"SubIndex 009\000"
"SubIndex 010\000"
"SubIndex 011\000"
"SubIndex 012\000\377";
#endif //#ifdef _OBJD_

#ifndef _XMC__ESC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x7000.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x7000.2 */
UINT32 SI3; /* Subindex3 - Reference to 0x7000.3 */
UINT32 SI4; /* Subindex4 - Reference to 0x7000.4 */
UINT32 SI5; /* Subindex5 - Reference to 0x7000.5 */
UINT32 SI6; /* Subindex6 - Reference to 0x7000.6 */
UINT32 SI7; /* Subindex7 - Reference to 0x7000.7 */
UINT32 SI8; /* Subindex8 - Reference to 0x7000.8 */
UINT32 SI9; /* Subindex9 - Reference to 0x7000.9 */
UINT32 SI10; /* Subindex10 - Reference to 0x7000.10 */
UINT32 SI11; /* Subindex11 - Reference to 0x7000.11 */
UINT32 SI12; /* Subindex12 - Reference to 0x7000.12 */
} OBJ_STRUCT_PACKED_END
TOBJ1600;
#endif //#ifndef _XMC__ESC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1600 OUT_GENERICProcessDataMapping0x1600
#if defined(_XMC__ESC_) && (_XMC__ESC_ == 1)
={12,0x70000110,0x70000210,0x70000310,0x70000410,0x70000501,0x70000601,0x70000701,0x70000801,0x70000901,0x70000A01,0x70000B01,0x70000C01}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A00 : IN_GENERIC process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A00 0x1A00 | IN_GENERIC process data mapping
* @{
* \brief Object 0x1A00 (IN_GENERIC process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6000.1<br>
* SubIndex 2 - Reference to 0x6000.2<br>
* SubIndex 3 - Reference to 0x6000.3<br>
* SubIndex 4 - Reference to 0x6000.4<br>
* SubIndex 5 - Reference to 0x6000.5<br>
* SubIndex 6 - Reference to 0x6000.6<br>
* SubIndex 7 - Reference to 0x6000.7<br>
* SubIndex 8 - Reference to 0x6000.8<br>
* SubIndex 9 - Reference to 0x6000.9<br>
* SubIndex 10 - Reference to 0x6000.10<br>
* SubIndex 11 - Reference to 0x6000.11<br>
* SubIndex 12 - Reference to 0x6000.12<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A00[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x6000.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Reference to 0x6000.2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Reference to 0x6000.3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 - Reference to 0x6000.4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex5 - Reference to 0x6000.5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex6 - Reference to 0x6000.6 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex7 - Reference to 0x6000.7 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex8 - Reference to 0x6000.8 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex9 - Reference to 0x6000.9 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex10 - Reference to 0x6000.10 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex11 - Reference to 0x6000.11 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex12 - Reference to 0x6000.12 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A00[] = "IN_GENERIC process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000"
"SubIndex 006\000"
"SubIndex 007\000"
"SubIndex 008\000"
"SubIndex 009\000"
"SubIndex 010\000"
"SubIndex 011\000"
"SubIndex 012\000\377";
#endif //#ifdef _OBJD_

#ifndef _XMC__ESC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6000.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x6000.2 */
UINT32 SI3; /* Subindex3 - Reference to 0x6000.3 */
UINT32 SI4; /* Subindex4 - Reference to 0x6000.4 */
UINT32 SI5; /* Subindex5 - Reference to 0x6000.5 */
UINT32 SI6; /* Subindex6 - Reference to 0x6000.6 */
UINT32 SI7; /* Subindex7 - Reference to 0x6000.7 */
UINT32 SI8; /* Subindex8 - Reference to 0x6000.8 */
UINT32 SI9; /* Subindex9 - Reference to 0x6000.9 */
UINT32 SI10; /* Subindex10 - Reference to 0x6000.10 */
UINT32 SI11; /* Subindex11 - Reference to 0x6000.11 */
UINT32 SI12; /* Subindex12 - Reference to 0x6000.12 */
} OBJ_STRUCT_PACKED_END
TOBJ1A00;
#endif //#ifndef _XMC__ESC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A00 IN_GENERICProcessDataMapping0x1A00
#if defined(_XMC__ESC_) && (_XMC__ESC_ == 1)
={12,0x60000110,0x60000210,0x60000310,0x60000410,0x60000501,0x60000601,0x60000701,0x60000801,0x60000901,0x60000A01,0x60000B01,0x60000C01}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C12 : SyncManager 2 assignment
******************************************************************************/
/**
* \addtogroup 0x1C12 0x1C12 | SyncManager 2 assignment
* @{
* \brief Object 0x1C12 (SyncManager 2 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C12[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C12[] = "SyncManager 2 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _XMC__ESC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[1];  /**< \brief Subindex 1 - 1 */
} OBJ_STRUCT_PACKED_END
TOBJ1C12;
#endif //#ifndef _XMC__ESC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C12 sRxPDOassign
#if defined(_XMC__ESC_) && (_XMC__ESC_ == 1)
={1,{0x1600}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C13 : SyncManager 3 assignment
******************************************************************************/
/**
* \addtogroup 0x1C13 0x1C13 | SyncManager 3 assignment
* @{
* \brief Object 0x1C13 (SyncManager 3 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C13[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C13[] = "SyncManager 3 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _XMC__ESC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[1];  /**< \brief Subindex 1 - 1 */
} OBJ_STRUCT_PACKED_END
TOBJ1C13;
#endif //#ifndef _XMC__ESC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C13 sTxPDOassign
#if defined(_XMC__ESC_) && (_XMC__ESC_ == 1)
={1,{0x1A00}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6000 : IN_GENERIC
******************************************************************************/
/**
* \addtogroup 0x6000 0x6000 | IN_GENERIC
* @{
* \brief Object 0x6000 (IN_GENERIC) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - IN_GEN_INT1<br>
* SubIndex 2 - IN_GEN_INT2<br>
* SubIndex 3 - IN_GEN_INT3<br>
* SubIndex 4 - IN_GEN_INT4<br>
* SubIndex 5 - IN_GEN_Bit1<br>
* SubIndex 6 - IN_GEN_Bit2<br>
* SubIndex 7 - IN_GEN_Bit3<br>
* SubIndex 8 - IN_GEN_Bit4<br>
* SubIndex 9 - IN_GEN_Bit5<br>
* SubIndex 10 - IN_GEN_Bit6<br>
* SubIndex 11 - IN_GEN_Bit7<br>
* SubIndex 12 - IN_GEN_Bit8<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex1 - IN_GEN_INT1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex2 - IN_GEN_INT2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex3 - IN_GEN_INT3 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex4 - IN_GEN_INT4 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex5 - IN_GEN_Bit1 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex6 - IN_GEN_Bit2 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex7 - IN_GEN_Bit3 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex8 - IN_GEN_Bit4 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex9 - IN_GEN_Bit5 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex10 - IN_GEN_Bit6 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }, /* Subindex11 - IN_GEN_Bit7 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ }}; /* Subindex12 - IN_GEN_Bit8 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6000[] = "IN_GENERIC\000"
"IN_GEN_INT1\000"
"IN_GEN_INT2\000"
"IN_GEN_INT3\000"
"IN_GEN_INT4\000"
"IN_GEN_Bit1\000"
"IN_GEN_Bit2\000"
"IN_GEN_Bit3\000"
"IN_GEN_Bit4\000"
"IN_GEN_Bit5\000"
"IN_GEN_Bit6\000"
"IN_GEN_Bit7\000"
"IN_GEN_Bit8\000\377";
#endif //#ifdef _OBJD_

#ifndef _XMC__ESC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT16 IN_GEN_INT1; /* Subindex1 - IN_GEN_INT1 */
UINT16 IN_GEN_INT2; /* Subindex2 - IN_GEN_INT2 */
UINT16 IN_GEN_INT3; /* Subindex3 - IN_GEN_INT3 */
UINT16 IN_GEN_INT4; /* Subindex4 - IN_GEN_INT4 */
BOOLEAN(IN_GEN_Bit1); /* Subindex5 - IN_GEN_Bit1 */
BOOLEAN(IN_GEN_Bit2); /* Subindex6 - IN_GEN_Bit2 */
BOOLEAN(IN_GEN_Bit3); /* Subindex7 - IN_GEN_Bit3 */
BOOLEAN(IN_GEN_Bit4); /* Subindex8 - IN_GEN_Bit4 */
BOOLEAN(IN_GEN_Bit5); /* Subindex9 - IN_GEN_Bit5 */
BOOLEAN(IN_GEN_Bit6); /* Subindex10 - IN_GEN_Bit6 */
BOOLEAN(IN_GEN_Bit7); /* Subindex11 - IN_GEN_Bit7 */
BOOLEAN(IN_GEN_Bit8); /* Subindex12 - IN_GEN_Bit8 */
} OBJ_STRUCT_PACKED_END
TOBJ6000;
#endif //#ifndef _XMC__ESC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6000 IN_GENERIC0x6000
#if defined(_XMC__ESC_) && (_XMC__ESC_ == 1)
={12,0x0000,0x0000,0x0000,0x0000,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x7000 : OUT_GENERIC
******************************************************************************/
/**
* \addtogroup 0x7000 0x7000 | OUT_GENERIC
* @{
* \brief Object 0x7000 (OUT_GENERIC) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - OUT_GEN_INT1<br>
* SubIndex 2 - OUT_GEN_INT2<br>
* SubIndex 3 - OUT_GEN_INT3<br>
* SubIndex 4 - OUT_GEN_INT4<br>
* SubIndex 5 - OUT_GEN_Bit1<br>
* SubIndex 6 - OUT_GEN_Bit2<br>
* SubIndex 7 - OUT_GEN_Bit3<br>
* SubIndex 8 - OUT_GEN_Bit4<br>
* SubIndex 9 - OUT_GEN_Bit5<br>
* SubIndex 10 - OUT_GEN_Bit6<br>
* SubIndex 11 - OUT_GEN_Bit7<br>
* SubIndex 12 - OUT_GEN_Bit8<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex1 - OUT_GEN_INT1 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex2 - OUT_GEN_INT2 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex3 - OUT_GEN_INT3 */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE }, /* Subindex4 - OUT_GEN_INT4 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READWRITE }, /* Subindex5 - OUT_GEN_Bit1 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READWRITE }, /* Subindex6 - OUT_GEN_Bit2 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READWRITE }, /* Subindex7 - OUT_GEN_Bit3 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READWRITE }, /* Subindex8 - OUT_GEN_Bit4 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READWRITE }, /* Subindex9 - OUT_GEN_Bit5 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READWRITE }, /* Subindex10 - OUT_GEN_Bit6 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READWRITE }, /* Subindex11 - OUT_GEN_Bit7 */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READWRITE }}; /* Subindex12 - OUT_GEN_Bit8 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x7000[] = "OUT_GENERIC\000"
"OUT_GEN_INT1\000"
"OUT_GEN_INT2\000"
"OUT_GEN_INT3\000"
"OUT_GEN_INT4\000"
"OUT_GEN_Bit1\000"
"OUT_GEN_Bit2\000"
"OUT_GEN_Bit3\000"
"OUT_GEN_Bit4\000"
"OUT_GEN_Bit5\000"
"OUT_GEN_Bit6\000"
"OUT_GEN_Bit7\000"
"OUT_GEN_Bit8\000\377";
#endif //#ifdef _OBJD_

#ifndef _XMC__ESC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT16 OUT_GEN_INT1; /* Subindex1 - OUT_GEN_INT1 */
UINT16 OUT_GEN_INT2; /* Subindex2 - OUT_GEN_INT2 */
UINT16 OUT_GEN_INT3; /* Subindex3 - OUT_GEN_INT3 */
UINT16 OUT_GEN_INT4; /* Subindex4 - OUT_GEN_INT4 */
BOOLEAN(OUT_GEN_Bit1); /* Subindex5 - OUT_GEN_Bit1 */
BOOLEAN(OUT_GEN_Bit2); /* Subindex6 - OUT_GEN_Bit2 */
BOOLEAN(OUT_GEN_Bit3); /* Subindex7 - OUT_GEN_Bit3 */
BOOLEAN(OUT_GEN_Bit4); /* Subindex8 - OUT_GEN_Bit4 */
BOOLEAN(OUT_GEN_Bit5); /* Subindex9 - OUT_GEN_Bit5 */
BOOLEAN(OUT_GEN_Bit6); /* Subindex10 - OUT_GEN_Bit6 */
BOOLEAN(OUT_GEN_Bit7); /* Subindex11 - OUT_GEN_Bit7 */
BOOLEAN(OUT_GEN_Bit8); /* Subindex12 - OUT_GEN_Bit8 */
} OBJ_STRUCT_PACKED_END
TOBJ7000;
#endif //#ifndef _XMC__ESC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7000 OUT_GENERIC0x7000
#if defined(_XMC__ESC_) && (_XMC__ESC_ == 1)
={12,0x0000,0x0000,0x0000,0x0000,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0xF000 : Modular Device Profile
******************************************************************************/
/**
* \addtogroup 0xF000 0xF000 | Modular Device Profile
* @{
* \brief Object 0xF000 (Modular Device Profile) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Index distance <br>
* SubIndex 2 - Maximum number of modules <br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0xF000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }, /* Subindex1 - Index distance  */
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }}; /* Subindex2 - Maximum number of modules  */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0xF000[] = "Modular Device Profile\000"
"Index distance \000"
"Maximum number of modules \000\377";
#endif //#ifdef _OBJD_

#ifndef _XMC__ESC_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT16 IndexDistance; /* Subindex1 - Index distance  */
UINT16 MaximumNumberOfModules; /* Subindex2 - Maximum number of modules  */
} OBJ_STRUCT_PACKED_END
TOBJF000;
#endif //#ifndef _XMC__ESC_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJF000 ModularDeviceProfile0xF000
#if defined(_XMC__ESC_) && (_XMC__ESC_ == 1)
={2,0x0010,0}
#endif
;
/** @}*/







#ifdef _OBJD_
TOBJECT    OBJMEM ApplicationObjDic[] = {
/* Object 0x1600 */
{NULL , NULL ,  0x1600 , {DEFTYPE_PDOMAPPING , 12 | (OBJCODE_REC << 8)} , asEntryDesc0x1600 , aName0x1600 , &OUT_GENERICProcessDataMapping0x1600 , NULL , NULL , 0x0000 },
/* Object 0x1A00 */
{NULL , NULL ,  0x1A00 , {DEFTYPE_PDOMAPPING , 12 | (OBJCODE_REC << 8)} , asEntryDesc0x1A00 , aName0x1A00 , &IN_GENERICProcessDataMapping0x1A00 , NULL , NULL , 0x0000 },
/* Object 0x1C12 */
{NULL , NULL ,  0x1C12 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C12 , aName0x1C12 , &sRxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x1C13 */
{NULL , NULL ,  0x1C13 , {DEFTYPE_UNSIGNED16 , 1 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C13 , aName0x1C13 , &sTxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x6000 */
{NULL , NULL ,  0x6000 , {DEFTYPE_RECORD , 12 | (OBJCODE_REC << 8)} , asEntryDesc0x6000 , aName0x6000 , &IN_GENERIC0x6000 , NULL , NULL , 0x0000 },
/* Object 0x7000 */
{NULL , NULL ,  0x7000 , {DEFTYPE_RECORD , 12 | (OBJCODE_REC << 8)} , asEntryDesc0x7000 , aName0x7000 , &OUT_GENERIC0x7000 , NULL , NULL , 0x0000 },
/* Object 0xF000 */
{NULL , NULL ,  0xF000 , {DEFTYPE_RECORD , 2 | (OBJCODE_REC << 8)} , asEntryDesc0xF000 , aName0xF000 , &ModularDeviceProfile0xF000 , NULL , NULL , 0x0000 },
{NULL,NULL, 0xFFFF, {0, 0}, NULL, NULL, NULL, NULL}};
#endif    //#ifdef _OBJD_
#undef PROTO

/** @}*/
#define _XMC__ESC_OBJECTS_H_
