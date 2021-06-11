##==================================================================================================
##  EVE - Expressive Vector Engine
##  Copyright : EVE Contributors & Maintainers
##  SPDX-License-Identifier: MIT
##==================================================================================================

##==================================================================================================
## Find Boost
##==================================================================================================
find_package(Boost 1.75.0 QUIET)

if(Boost_FOUND)
  set(EVE_USE_BOOST 1)
  message( STATUS "[eve] Boost found in ${Boost_INCLUDE_DIRS} - Boost dependent tests activated")
else()
  set(Boost_INCLUDE_DIRS "")
endif()

##==================================================================================================
## Find Doxygen
##==================================================================================================
find_package(Doxygen QUIET)

if (DOXYGEN_FOUND)
  message( STATUS "[eve] Doxygen available")
else (DOXYGEN_FOUND)
  message( STATUS "[eve] Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
