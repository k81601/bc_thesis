# Install script for directory: /home/jakub/src/git/SOEM

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/jakub/src/git/SOEM/build/libsoem.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/soem" TYPE FILE FILES
    "/home/jakub/src/git/SOEM/soem/ethercatprint.h"
    "/home/jakub/src/git/SOEM/soem/ethercatfoe.h"
    "/home/jakub/src/git/SOEM/soem/ethercatbase.h"
    "/home/jakub/src/git/SOEM/soem/ethercatcoe.h"
    "/home/jakub/src/git/SOEM/soem/ethercatmain.h"
    "/home/jakub/src/git/SOEM/soem/ethercatdc.h"
    "/home/jakub/src/git/SOEM/soem/ethercatconfiglist.h"
    "/home/jakub/src/git/SOEM/soem/ethercattype.h"
    "/home/jakub/src/git/SOEM/soem/ethercatconfig.h"
    "/home/jakub/src/git/SOEM/soem/ethercat.h"
    "/home/jakub/src/git/SOEM/soem/ethercatsoe.h"
    "/home/jakub/src/git/SOEM/osal/osal.h"
    "/home/jakub/src/git/SOEM/osal/linux/osal_defs.h"
    "/home/jakub/src/git/SOEM/oshw/linux/nicdrv.h"
    "/home/jakub/src/git/SOEM/oshw/linux/oshw.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/jakub/src/git/SOEM/build/test/linux/slaveinfo/cmake_install.cmake")
  include("/home/jakub/src/git/SOEM/build/test/linux/eepromtool/cmake_install.cmake")
  include("/home/jakub/src/git/SOEM/build/test/linux/simple_test/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/jakub/src/git/SOEM/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
