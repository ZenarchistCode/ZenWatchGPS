class CfgPatches
{
	class ZenWatchGPS
	{
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};

class CfgMods
{
	class ZenWatchGPS
	{
		dir = "ZenWatchGPS";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "ZenWatchGPS";
		credits = "";
		author = "Zenarchist";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "ZenWatchGPS/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "ZenWatchGPS/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "ZenWatchGPS/scripts/5_mission" };
			};
		};
	};
};

class CfgVehicles
{
    class Clothing;
	class ZenWatchGPS: Clothing
    {
        scope = 2;
        displayName = "$STR_CfgVehicles_ZenWatch0";
        descriptionShort = "$STR_CfgVehicles_ZenWatch1";
        model="ZenWatchGPS\data\watch\model\gpswatch_g.p3d";
        inventorySlot = "Armband";
        itemInfo[] = {"Clothing","Armband"};
        weight = 200;
        heatIsolation = 0.1;
        absorbency = 0;
        repairableWithKits[] = { 7 }; // electronic repair kit
		repairCosts[] = { 20 };
        itemSize[]={1,2};
		hiddenSelections[]=
		{
			"gps"
		};
		hiddenSelectionsTextures[]=
		{
			"ZenWatchGPS\data\watch\textures\gps_off_co.paa"
		};
        class ClothingTypes
        {
            male = "ZenWatchGPS\data\watch\model\gpswatch_worn.p3d";
            female = "ZenWatchGPS\data\watch\model\gpswatch_worn.p3d";
        };
        attachments[]=
        {
            "BatteryD"
        };
        class EnergyManager
        {
            hasIcon=1;
            autoSwitchOff=0;
            energyUsagePerSecond=0.0035; // ~4 hours of full 9v battery usage
            plugType=1;
            attachmentAction=1;
            wetnessExposure=0;
        };
        class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] =
					{

						{
							1,

							{
								"ZenWatchGPS\data\watch\textures\zenwatchgps.rvmat"
							}
						},

						{
							0.69999999,

							{
								"ZenWatchGPS\data\watch\textures\zenwatchgps.rvmat"
							}
						},

						{
							0.5,

							{
								"ZenWatchGPS\data\watch\textures\zenwatchgps_damage.rvmat"
							}
						},

						{
							0.30000001,

							{
								"ZenWatchGPS\data\watch\textures\zenwatchgps_damage.rvmat"
							}
						},

						{
							0,

							{
								"ZenWatchGPS\data\watch\textures\zenwatchgps_destruct.rvmat"
							}
						}
					};
				};
			};
		};
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickUpItem
                {
                    soundSet = "Shirt_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "Shirt_drop_SoundSet";
                    id = 898;
                };
            };
        };
		soundImpactType="plastic";
    };
};