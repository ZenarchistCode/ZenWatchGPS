modded class MapNavigationBehaviour
{
	override void OnItemInPlayerPossession(EntityAI item)
	{
		super.OnItemInPlayerPossession(item);

		if (item.IsInherited(ZenWatchGPS))
		{
			if (m_GPSInPossessionArr.Find(item) == INDEX_NOT_FOUND)
			{
				m_GPSInPossessionArr.Insert(item);
				SetNavigationType(EMapNavigationType.GPS);
			}

			if (m_CompassInPossessionArr.Find(item) == INDEX_NOT_FOUND)
			{
				m_CompassInPossessionArr.Insert(item);
				SetNavigationType(EMapNavigationType.COMPASS);
			}
		}
	}
	
	override void OnItemNotInPlayerPossession(EntityAI item)
	{
		super.OnItemNotInPlayerPossession(item);

		if (item.IsInherited(ZenWatchGPS))
		{
			m_GPSInPossessionArr.RemoveItem(item);
			if (m_GPSInPossessionArr.Count() == 0)
			{
				UnsetNavigationType(EMapNavigationType.GPS);
			}

			m_CompassInPossessionArr.RemoveItem(item);
			if (m_CompassInPossessionArr.Count() == 0)
			{
				UnsetNavigationType(EMapNavigationType.COMPASS);
			}
		}
	}
}