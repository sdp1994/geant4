// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VisCommandsDraw.hh,v 1.3 1999/12/15 14:54:21 gunter Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// 
// /vis~/draw/ commands
// John Allison  7th September 1997

#ifndef G4VISCOMMANDSDRAW_HH
#define G4VISCOMMANDSDRAW_HH

#include "globals.hh"
#include "G4VisManager.hh"
#include "G4ViewParameters.hh"

////////////////////////////////////////////////////  /vis~/draw/...  ////
//vis \hline
//vis /vis~/draw/ &&
//vis ...menu of drawing possibilities. \\%
class G4VisCommandDraw {
public:
  G4String GetCommandName () const {return "/vis~/draw/";}
  G4String GetGuidance () const {
    return "...menu of drawing possibilities.";
  }
};

///////////////////////////////////////////  /vis~/draw/current  ////
//draw \hline
//draw /vis~/draw/current &&
//draw Draws the current scene in the current view using the current
//draw view parameters. \\%
class G4VisCommandDrawCurrent {
public:
  G4String GetCommandName () const {return "/vis~/draw/current";}
  G4String GetGuidance () const {
    return "Draws the current scene in the current view using the current "
      "view parameters.";
  }
  void SetValue () {
    G4VisManager* pVMan = G4VisManager::GetInstance ();
    if (pVMan -> IsValidView ()) {
      if (pVMan -> GetVerboseLevel () > 1) {
	pVMan -> PrintCurrentView ();
      }
      pVMan -> Draw ();    
    }
  }
};

#endif