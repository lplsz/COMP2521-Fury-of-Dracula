////////////////////////////////////////////////////////////////////////
// COMP2521 20T2 ... the Fury of Dracula
// hunter.c: your "Fury of Dracula" hunter AI.
//
// 2014-07-01	v1.0	Team Dracula <cs2521@cse.unsw.edu.au>
// 2017-12-01	v1.1	Team Dracula <cs2521@cse.unsw.edu.au>
// 2018-12-31	v2.0	Team Dracula <cs2521@cse.unsw.edu.au>
// 2020-07-10	v3.0	Team Dracula <cs2521@cse.unsw.edu.au>
//
////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "Game.h"
#include "hunter.h"
#include "HunterView.h"

void decideHunterMove(HunterView hv)
{
	Round round = HvGetRound(hv);
	Player name = HvGetPlayer(hv); // Which hunter?

	if (round == 0) { // FIRST ROUND
		char *location;
		// Depending on the hunter, move to a predetermined location
		// Best stratergy is to choose locations away from other hunters
		
		// I chose corners of the map - not sure if best choice
		// (need at least one hunter in middle)
		// Need to discuss this
		switch(name) {
			case PLAYER_LORD_GODALMING:
				location = "ED";
				break;
			case PLAYER_DR_SEWARD:
				location = "GA";
				break;
			case PLAYER_VAN_HELSING:
				location = "RO";
				break;
			case PLAYER_MINA_HARKER:
				location = "GR";
				break;
			default:
				break;
		}
		
		registerBestPlay(location, "");
		return;
	} 
	// for all other rounds
		PlaceId HunterLoc, DraculaLoc, VampireLoc;
		Round round = HvGetRound(hv);
		Player currHunter = HvGetPlayer(hv);
		char *play; // move to make -- this is sent to register best play
		Mesage message; // message -- this is sent to register best play

		// ---------------Get current location of the hunter--------------------
		switch(currHunter) {
			case PLAYER_LORD_GODALMING:
				HunterLoc = HvGetPlayerLocation(hv, currHunter);
				break;
			case PLAYER_DR_SEWARD:
				HunterLoc = HvGetPlayerLocation(hv, currHunter);
				break;
			case PLAYER_VAN_HELSING:
				HunterLoc = HvGetPlayerLocation(hv, currHunter);
				break;
			case PLAYER_MINA_HARKER:
				HunterLoc = HvGetPlayerLocation(hv, currHunter);
				break;
			default:
				break;
		}

		// --------------Get last known Dracula location------------------------
		/** Gets  Dracula's  last  known  real  location  as revealed in the 
		  * play string and sets *round to the number of the  latest  round  in  
		  * which Dracula moved there.*/
		Round LastDracRoundSeen = -1;
		DraculaLoc = HvGetLastKnownDraculaLocation(hv, &LastDracRoundSeen);

		if(DraculaLoc != NOWHERE && LastDracRoundSeen != -1) { 
			// Dracula's last real location is known
			
			// Depending on how far away the hunter is from Dracula,
			// take different cases.
			int pathLength = -1;
			PlaceId *path = HvGetShortestPathTo(hv, currHunter, DraculaLoc, &pathLength);
			// NOTE:: call to above function is expensive
			 

		} else {
			// If Dracula's location not know, perform collab research
			// This allows us to know the 6th move in Dracula's trail immediately
			// Note:: If the move was a HIDE/DOUBLE_BACK move, then the move that
			// the HIDE/DOUBLE_BACK refers to will be revealed (and so on
			// until LOCATIO is revealed)
			// Therefore, it might not exactly be the 6th last move
			registerBestPlay(HunterLoc, "Research"); // sends currLocofHunter back
		}

		// ---------------------If Dracula health <= x--------------------------
		if(HvGetHealth(hv, PLAYER_DRACULA) <= 15) {
			// If Dracula's health is less than x, move towards Castle Dracula
			// HOWEVER, if he is really far away, then try and kill him
		}

		// --------------If hunter health low, rest-----------------------------
		int currHunterHealth = HvGetHealth(hv, currHunter);
		if(currHunterHealth <= 3) {
			registerBestPlay(HunterLoc, "Resting");
		}

	registerBestPlay(play, mesasge);
}
