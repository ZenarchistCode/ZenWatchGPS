class ZenWatchGPS extends Clothing
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
	}

	override void OnWorkStart()
	{
		super.OnWorkStart();
		RegisterZenGpsDeviceToPlayer(true);

		SetObjectTexture(0, "ZenWatchGPS/data/watch/textures/gps_on_co.paa");
	}
	
	override void OnWorkStop()
	{
		super.OnWorkStop();
		RegisterZenGpsDeviceToPlayer(false);

		SetObjectTexture(0, "ZenWatchGPS/data/watch/textures/gps_off_co.paa");
	}

	bool IsZenWatchTurnedOn()
	{
		return GetCompEM() && GetCompEM().IsWorking();
	}

	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);

		string slot_name = InventorySlots.GetSlotName(slot_id);
		if (slot_name != "Armband")
			return;
		
		PlayerBase player = PlayerBase.Cast(parent);
		if (parent.GetHierarchyRoot())
		{
			player = PlayerBase.Cast(parent.GetHierarchyRoot());			
		}

		if (player)
		{
			if (IsZenWatchTurnedOn())
			{
				player.MapNavigationItemInPossession(this);
			}
		}
	}
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent, slot_id);

		string slot_name = InventorySlots.GetSlotName(slot_id);
		if (slot_name != "Armband")
			return;

		PlayerBase player = PlayerBase.Cast(parent);
		if (parent.GetHierarchyRoot())
		{
			player = PlayerBase.Cast(parent.GetHierarchyRoot());			
		}

		if (player)
		{
			player.MapNavigationItemNotInPossession(this);
		}
	}

	void RegisterZenGpsDeviceToPlayer(bool isTurnedOn)
	{
		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());

		if (player)
		{
			if (isTurnedOn)
			{
				player.MapNavigationItemInPossession(this);
			}
			else 
			{
				player.MapNavigationItemNotInPossession(this);
			}
		}
	}
}