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
	Recipe(s_gameElementUUID _recipeID);
	~Recipe();

	s_gameElementUUID getRecipeID();
	void addProcessStep(ProcessStep *_processStep);

	ObjList<ProcessStep> *getListOfProcesses();

private:
	s_gameElementUUID m_RecipeID;
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
	s_gameElementUUID getNextRawMaterial();
	s_gameElementUUID getCurrentRawMaterial();

private:
	Recipe *m_Recipe;
	ObjListIterator<ProcessStep> *m_CurrentStep;
	ObjListIterator<s_gameElementUUID> *m_CurrentRawMaterial;
};
