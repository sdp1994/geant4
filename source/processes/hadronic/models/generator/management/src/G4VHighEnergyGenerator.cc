// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VHighEnergyGenerator.cc,v 1.1.10.1 1999/12/07 20:51:46 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// G4VHighEnergyGenerator
#include "G4VHighEnergyGenerator.hh"

G4VHighEnergyGenerator::G4VHighEnergyGenerator()
{
}

G4VHighEnergyGenerator::G4VHighEnergyGenerator(const G4VHighEnergyGenerator &right)
{
}


G4VHighEnergyGenerator::~G4VHighEnergyGenerator()
{
}


const G4VHighEnergyGenerator & G4VHighEnergyGenerator::operator=(const G4VHighEnergyGenerator &right)
{
  G4Exception("G4VHighEnergyGenerator::operator= meant to not be accessable");
  return *this;
}


int G4VHighEnergyGenerator::operator==(const G4VHighEnergyGenerator &right) const
{
  return 0;
}

int G4VHighEnergyGenerator::operator!=(const G4VHighEnergyGenerator &right) const
{
  return 1;
}
