// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: meshdefs.hh,v 1.2 1999/12/15 14:49:52 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
//
// Tube/Cone Meshing constants for extent calculations
//
// History:
// 13.08.95 P.Kent Created separate file

#ifndef MESHDEFS_HH
#define MESHDEFS_HH

#include "globals.hh"

const G4double kMeshAngleDefault=(M_PI/4); // Angle for mesh `wedges' in rads
                                 // Works best when simple fraction of M_PI/2

const G4int kMinMeshSections=3;	 // Min wedges+1 to make
const G4int kMaxMeshSections=37; // max wedges+1 to make
                                 // =>10 degrees/wedge for complete tube

#endif




