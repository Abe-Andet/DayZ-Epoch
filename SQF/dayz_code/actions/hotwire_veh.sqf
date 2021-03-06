private ["_vehicle","_removed","_vehType"];
_vehicle = _this select 3;

if (dayz_actionInProgress) exitWith {localize "STR_EPOCH_PLAYER_32" call dayz_rollingMessages;};
dayz_actionInProgress = true;

{player removeAction _x} count s_player_lockunlock;s_player_lockunlock = [];
s_player_lockUnlock_crtl = 1;
{DZE_myVehicle removeAction _x} count s_player_lockUnlockInside;s_player_lockUnlockInside = [];
s_player_lockUnlockInside_ctrl = 1;

_removed = ([player,"ItemHotwireKit",1] call BIS_fnc_invRemove);

if (_removed == 1) then {
	player playActionNow "Medic";
	[player,"repair",0,false] call dayz_zombieSpeak;
	[player,50,true,(getPosATL player)] spawn player_alertZombies;
	uiSleep 8;
	
	_vehType = getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "displayName");
	if ((random 10) <= 7.5) then {
		PVDZE_veh_Lock = [_vehicle,false];
		if (local _vehicle) then {
			PVDZE_veh_Lock call local_lockUnlock
		} else {
			publicVariable "PVDZE_veh_Lock";
		};
		format [localize "STR_EPOCH_PLAYER_33_OK",_vehType] call dayz_rollingMessages;
	} else {
		format [localize "STR_EPOCH_PLAYER_33",_vehType] call dayz_rollingMessages;
	};
};

s_player_lockUnlock_crtl = -1;
s_player_lockUnlockInside_ctrl = -1;
dayz_actionInProgress = false;