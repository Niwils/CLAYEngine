/*
 * The <unnamed> factory builder project.
 *
 * \file /factory0/src/engine/production/ProductionPlanning.h/ProductionPlanning.h.h
 *
 * \brief
 */

/*
 * CHANGELOG:
 * 27 déc. 2019: File creation (niels)
 */

#ifndef SRC_ENGINE_PRODUCTION_PRODUCTIONPLANNING_H_
#define SRC_ENGINE_PRODUCTION_PRODUCTIONPLANNING_H_

#include <Recipe.h>

class ProductionPlanning
{
public:
	ProductionPlanning();
	~ProductionPlanning();

	void queueRecipe(Recipe *_recipe, s_ItemQuantity _qty);

	Recipe *iterateNextRecipe();
	Recipe *getCurrentRecipe();

private:
	ObjList<Recipe> *m_PlannedTasks;
};



#endif /* SRC_ENGINE_PRODUCTION_PRODUCTIONPLANNING_H_ */
