class CfgPatches
{
    class ld3k_usmc2035_weapons_compat_ace3
    {
        requiredAddons[]=
        {
            "Weapons_F_USMC2035",
            "Weapons_F_USMC35_Rifles_HK416"
        };
        requiredversion=0.1;
        units[]={};
        weapons[]={};
    };
};
class Mode_SemiAuto;
class Mode_FullAuto;
class CfgWeapons
{
    class InventoryMuzzleItem_Base_F;
    class ItemCore;
    class Rifle;
    class Rifle_Base_F: Rifle
    {
        class WeaponSlotsInfo;
    };
    class USMC35_arifle_HK416_base_F: Rifle_Base_F
    {
        ACE_barrelTwist=177.8; // 1:7"
        ACE_barrelLength=419.1; // 16.5" https://mantadefense.com/wp-content/uploads/2017/11/m27_productsheet.pdf
        ACE_railHeightAboveBore=2.94595; // from ACE3 checkScopes.sqf
        initSpeed=-0.96752; // 896, 909, 958, 810, 919, 852, 274m/s according to ACE_muzzleVelocities at ICAO conditions (15°C, 1013.25hPa, 0%), USMC2035 800
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=81.6; // 3.7kg https://mantadefense.com/wp-content/uploads/2017/11/m27_productsheet.pdf, USMC2035 100
        };
        class Single: Mode_SemiAuto
        {
            dispersion=0.00052; // 3.18 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, USMC2035 0.00058 (1.99 MOA)
        };
        class FullAuto: Mode_FullAuto
        {
            dispersion=0.00052; // 3.18 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, USMC2035 0.00058 (1.99 MOA)
        };
    };
    class USMC35_arifle_HK416_short_base_F: USMC35_arifle_HK416_base_F
    {
        ACE_barrelLength=264.16; // 10.4" https://mantadefense.com/wp-content/uploads/2017/11/m27_productsheet.pdf
        initSpeed=-0.85753; // 794, 806, 849, 718, 814, 755, 243m/s according to ACE_muzzleVelocities at ICAO conditions (15°C, 1013.25hPa, 0%), USMC2035 800
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=70.5; // 3.2kg HK416 A5 https://www.heckler-koch.com/en/Products/Military%20and%20Law%20Enforcement/Assault%20rifles/HK416?section=variants&variant=1135&s=1, USMC2035 90
        };
        class Single: Single
        {
            dispersion=0.000631; // 3.86 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, USMC2035 0.00073 (2.51 MOA)
        };
        class FullAuto: FullAuto
        {
            dispersion=0.000631; // 3.86 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, USMC2035 0.00073 (2.51 MOA)
        };
    };
    class muzzle_snds_H: ItemCore // Sound Suppressor 6.5mm
    {
        class ItemInfo: InventoryMuzzleItem_Base_F
        {
        };
    };
    class muzzle_snds_M: muzzle_snds_H // Sound Suppressor 5.56mm
    {
        class ItemInfo: ItemInfo
        {
            // mass=8;
            class MagazineCoef
            {
                initSpeed=1; // ACE3, muzzle_snds_M 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, muzzle_snds_M 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_M 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_M 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        // inertia=0.1;
    };
};
