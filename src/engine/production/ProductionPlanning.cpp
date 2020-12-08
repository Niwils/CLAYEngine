/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/src/engine/production/ProductionPlanning.cpp/ProductionPlanning.cpp.h
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 27 déc. 2019: File creation (niels)
 */

#include <ProductionPlanning.h>


ProductionPlanning::ProductionPlanning()
{
	m_PlannedTasks = new ObjList<Recipe>();
}
ProductionPlanning::~ProductionPlanning()
{
	// TODO delete tasks in progress
	delete m_PlannedTasks;
}

void ProductionPlanning::queueRecipe(Recipe *_recipe, s_ItemQuantity _qty)
{
	// TODO assert m_PlannedTasks != nullptr
	for(int icpt= 0; icpt < _qty; icpt++)
	{
		m_PlannedTasks->addObject(_recipe);
	}
}

Recipe *ProductionPlanning::iterateNextRecipe()
{
	// TODO assert m_PlannedTasks != nullptr
	Recipe *l_ret = m_PlannedTasks->removeFirst();

	if(nullptr != l_ret)
	{
		m_PlannedTasks->addObject(l_ret);
		l_ret = m_PlannedTasks->getFirst();
	}

	return l_ret;
}
Recipe *ProductionPlanning::getCurrentRecipe()
{
	// TODO assert m_PlannedTasks != nullptr
	return m_PlannedTasks->getFirst();
}
