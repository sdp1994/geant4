// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4DynamicParticleVector.hh,v 1.1.8.1.2.1 1999/12/07 20:52:42 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
//
//	For information related to this code contact:
//	CERN, CN Division, ASD group
//	History: first implementation, alternative to G4FastVector
//               less fast, but it has variable array length and checks boundaries
//	26th September, Chr. Voelcker
// ------------------------------------------------------------

#ifndef G4DynamicParticleVector_h
#define G4DynamicParticleVector_h 1

#include "globals.hh"
#include "G4ios.hh"

class G4DynamicParticle;
#include "g4rw/tpordvec.h"

// #ifdef STL
// //in future use STL vector as container of dynamic particles ...
// typedef Vector<G4DynamicParticle> G4DynamicParticleVector;
// #elseifdef RWT

typedef G4RWTPtrOrderedVector<G4DynamicParticle> G4DynamicParticleVector;

// #endif

#endif