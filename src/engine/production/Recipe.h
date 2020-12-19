/*
 * The <unnamed> factory builder project.
 *
 * \file src/engine/production/Recipe.h
 *
 * \brief A Recipe is a list of ProcessStep an item shall go by.
 */

/*
 * CHANGELOG:
 * 23/11/2019: File creation (NG)
 */

#include <Types.h>
#include <ProcessStep.h>
#include <ObjList.h>

class Recipe
{
public:
	Recipe(s_RecipeUID _recipeID);
	~Recipe();

	s_RecipeUID getRecipeID();
	void addProcessStep(ProcessStep *_processStep);

	ObjList<ProcessStep> *getListOfProcesses();

private:
	s_RecipeUID m_RecipeID;
	ObjList<ProcessStep> *m_ProcessList; // Warning, only Recipe is allowed to directly modify
										// this ObjList
};

class RecipeFollower
{
public:
	RecipeFollower(Recipe *_recipe);
	~RecipeFollower();

	ProcessStep *getNextStep();
	ProcessStep *getCurrentStep();
	s_ItemTypeUUID getNextRawMaterial();
	s_ItemTypeUUID getCurrentRawMaterial();

private:
	Recipe *m_Recipe;
	ObjListIterator<ProcessStep> *m_CurrentStep;
	ObjListIterator<s_ItemTypeUUID> *m_CurrentRawMaterial;
};
