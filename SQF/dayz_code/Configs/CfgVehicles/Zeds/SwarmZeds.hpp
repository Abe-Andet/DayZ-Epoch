class Swarm_Base : Citizen1 {
	scope = public;
	class HitDamage {};
	glassesEnabled = 0;
	vehicleClass = "Zombie";
	displayName = $STR_ZNAME_INFECTED;
	fsmDanger = "";
	fsmFormation = "";
	zombieLoot = "civilian";
	moves = "CfgMovesZombie";
	isMan = false;
	weapons[] = {};
	magazines[] = {};
	sensitivity = 1;	// sensor sensitivity
	sensitivityEar = 1;
	identityTypes[] = {"zombie1", "zombie2"};
	class TalkTopics {};
	languages[] = {};
	armor = 1;
	damageScale = 200;
	sepsisChance = 10;
	forcedSpeed = 6;

	class Eventhandlers {
		init = "if (isNil 'dayz_clientPreload') then {dayz_clientPreload = false;}; _this execFSM ""\z\AddOns\dayz_code\system\zombie_agent.fsm""";
		//local = "if(_this select 1) then {[(position (_this select 0)),(_this select 0),true] execFSM '\z\AddOns\dayz_code\system\fn_swarmagent.fsm'};";
		local = "_z = _this select 0; if (!(_this select 1)) exitWith {}; if (isServer) exitWith { _z call sched_co_deleteVehicle; }; [(position _z), _z, true] execFSM '\z\AddOns\dayz_code\system\zombie_agent.fsm';";
		HandleDamage = "_this call local_zombieDamage;";
		Killed = "[_this,'zombieKills'] call local_eventKill;";
	};
	
	class HitPoints {
		class HitHead {
			armor = 0.3;
			material = -1;
			name = "head_hit";
			passThrough = true;
			memoryPoint = "pilot";
		};
		
		class HitBody : HitHead {
			armor = 2;
			name = "body";
			memoryPoint = "aimPoint";
		};
		
		class HitSpine : HitHead {
			armor = 2;
			name = "Spine2";
			memoryPoint = "aimPoint";
		};
		
		class HitHands : HitHead {
			armor = 0.5;
			material = -1;
			name = "hands";
			passThrough = true;
		};
		
		class HitLArm : HitHands {
			name = "LeftArm";
			memoryPoint = "lelbow";
		};
		
		class HitRArm : HitHands {
			name = "RightArm";
			memoryPoint = "relbow";
		};
		
		class HitLForeArm : HitHands {
			name = "LeftForeArm";
			memoryPoint = "lwrist";
		};
		
		class HitRForeArm : HitHands {
			name = "RightForeArm";
			memoryPoint = "rwrist";
		};
		
		class HitLHand : HitHands {
			name = "LeftHand";
			memoryPoint = "LeftHandMiddle1";
		};
		
		class HitRHand : HitHands {
			name = "RightHand";
			memoryPoint = "RightHandMiddle1";
		};
		
		class HitLegs : HitHands {
			name = "legs";
			memoryPoint = "pelvis";
		};
		
		class HitLLeg : HitHands {
			name = "LeftLeg";
			memoryPoint = "lknee";
		};
		
		class HitLLegUp : HitHands {
			name = "LeftUpLeg";
			memoryPoint = "lfemur";
		};
		
		class HitRLeg : HitHands {
			name = "RightLeg";
			memoryPoint = "rknee";
		};
		
		class HitRLegUp : HitHands {
			name = "RightUpLeg";
			memoryPoint = "rfemur";
		};
	};
};

class swarm_newBase : Swarm_Base {
	zombieLoot = "civilian";
	displayname = "swarm";
	//model = "\Ca\characters_E\Overall\Overall";
	//hiddenSelections[] = {"Camo"};
	//hiddenSelectionsTextures[] = {"\Ca\characters_E\Overall\Data\Overall_4_co.paa"};
	model = "\ca\characters2\civil\Woodlander\Woodlander";
	hiddenselectionstextures[] = {"\ca\characters2\civil\woodlander\data\woodlander_v2_co.paa"};
		
	//class Wounds {
	//	tex[] = {};
	//	mat[] = {"Ca\characters_E\Overall\Data\Overall.rvmat", "Ca\characters_E\Overall\Data\W1_Overall.rvmat", "Ca\characters_E\Overall\Data\W2_Overall.rvmat"};
	//};
};