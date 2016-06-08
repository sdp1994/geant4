// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: ExN03EventAction.cc,v 1.8 2000/01/24 14:46:01 stesting Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#include "ExN03EventAction.hh"

#include "ExN03CalorHit.hh"
#include "ExN03EventActionMessenger.hh"

#include "g4rw/tvordvec.h"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4VHitsCollection.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4VVisManager.hh"
#include "G4SDManager.hh"
#include "G4UImanager.hh"
#include "G4ios.hh"
#include "G4UnitsTable.hh"
#include "Randomize.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

ExN03EventAction::ExN03EventAction()
:calorimeterCollID(-1),drawFlag("all"),eventMessenger(NULL),
 printModulo(10000)
{
  eventMessenger = new ExN03EventActionMessenger(this);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

ExN03EventAction::~ExN03EventAction()
{
  delete eventMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void ExN03EventAction::BeginOfEventAction(const G4Event* evt)
{
  
 G4int evtNb = evt->GetEventID();
 if (evtNb%printModulo == 0)
   { 
    G4cout << "\n---> Event: " << evtNb << G4endl;
    HepRandom::showEngineStatus();
   }
    
 if (calorimeterCollID==-1)
   {
    G4SDManager * SDman = G4SDManager::GetSDMpointer();
    calorimeterCollID = SDman->GetCollectionID("CalCollection");
   } 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void ExN03EventAction::EndOfEventAction(const G4Event* evt)
{
  G4int event_id = evt->GetEventID();

  G4TrajectoryContainer * trajectoryContainer = evt->GetTrajectoryContainer();
  G4int n_trajectories = 0;
  if (trajectoryContainer) n_trajectories = trajectoryContainer->entries();

  if (event_id < 100 || event_id%100 == 0) {

    G4cout << ">>> Event " << evt->GetEventID() << G4endl;

    G4cout << "    " << n_trajectories 
	   << " trajectories stored in this event." << G4endl;

    G4HCofThisEvent* HCE = evt->GetHCofThisEvent();
    ExN03CalorHitsCollection* CHC = NULL;
    if (HCE)
      CHC = (ExN03CalorHitsCollection*)(HCE->GetHC(calorimeterCollID));

    if (CHC)
      {
	int n_hit = CHC->entries();
	G4cout << "     " << n_hit
	       << " hits are stored in ExN03CalorHitsCollection." << G4endl;
	G4double totEAbs=0, totLAbs=0, totEGap=0, totLGap=0;
	for (int i=0;i<n_hit;i++)
	  {
	    totEAbs += (*CHC)[i]->GetEdepAbs(); 
	    totLAbs += (*CHC)[i]->GetTrakAbs();
	    totEGap += (*CHC)[i]->GetEdepGap(); 
	    totLGap += (*CHC)[i]->GetTrakGap();
	  }
	G4cout
	  << "   Absorber: total energy: " << G4std::setw(7) << G4BestUnit(totEAbs,"Energy")
	  << "       total track length: " << G4std::setw(7) << G4BestUnit(totLAbs,"Length")
	  << G4endl
	  << "        Gap: total energy: " << G4std::setw(7) << G4BestUnit(totEGap,"Energy")
	  << "       total track length: " << G4std::setw(7) << G4BestUnit(totLGap,"Length")
	  << G4endl;           
      }
  }

  if(G4VVisManager::GetConcreteInstance())
  {
    for(G4int i=0; i<n_trajectories; i++) 
         { G4Trajectory* trj = (G4Trajectory *)((*(evt->GetTrajectoryContainer()))[i]);
           if (drawFlag == "all") trj->DrawTrajectory(50);
           else if ((drawFlag == "charged")&&(trj->GetCharge() != 0.))
                                  trj->DrawTrajectory(50); 
         }
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....