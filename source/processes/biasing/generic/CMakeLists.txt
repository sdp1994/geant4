#------------------------------------------------------------------------------
# CMakeLists.txt
# Module : G4biasing
# Package: Geant4.src.G4processes.G4biasing.G4biasing_gen
#
# CMakeLists.txt for building a single granular library.
#
# Generated on : 24/9/2010
#
# $Id: CMakeLists.txt 74802 2013-10-22 08:58:21Z gcosmo $
#
#------------------------------------------------------------------------------

if(GEANT4_BUILD_GRANULAR_LIBS)
    include(Geant4MacroLibraryTargets)
    GEANT4_GRANULAR_LIBRARY_TARGET(COMPONENT sources.cmake)
endif()

